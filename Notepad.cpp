#include "Dialog.h"
#include "Notepad.h"
#include "Setting.h"
#include "ui_Notepad.h"
#include "strings.h"

#include <iostream>
#include <QAction>
#include <QFileDialog>
#include <QFileSystemModel>
#include <QFontDatabase>
#include <QMessageBox>
#include <QObject>
#include <QPalette>
#include <QString>
#include <vector>

using std::string;
using std::vector;

void Notepad::about()
{
    qDebug() << "Notepad::about: start.\n";
    auto *d = new Dialog(this, 1, cfg.chinese);
    d->show();
    d->exec();
}

//void Notepad::closeEvent(QCloseEvent * event) {
//    if (this->path.empty() || file == ui->textEdit->toPlainText().toStdString()) {
//        event->accept();
//    }
//}

void Notepad::find()
{
    qDebug() << "Notepad::find(): start.\n";
    auto *d = new Dialog(this, 0, cfg.chinese);
    d->show();
    d->exec();
    QString fText = d->findText;
    if (ui->textEdit->find(fText)) {
        QPalette p = ui->textEdit->palette();
        p.setColor(QPalette::Highlight, p.color(QPalette::Active, QPalette::Highlight));
        ui->textEdit->setPalette(p);
    } else {
        QMessageBox::warning(this, "错误", "找不到字符", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    }

}

QString Notepad::getFontCfg() const
{
    return cfg.font;
}

void Notepad::init()
{
    qDebug() << "Notepad::init: start.\n";
    T = new Text();

    cfg.autoSave = false;
    cfg.treeView = true;
    cfg.font = QString("等线");
    cfg.chinese = true;

    this->fs.open("config.txt", std::ios::in);

    if (!this->fs) {
        qDebug() << "Notepad::init-log:config.txt is not exist\n";
        this->fs.close();
        this->fs.open("config.txt", std::ios::out);
        if(!this->fs) {
            qDebug() << "Notepad::init-log:create config.txt failed.";
        } else {
            this->fs << T->defaultConfig.toStdString();
        }
        this->fs.close();
    } else {
        string text;
        string temp;

        vector<string> cfgArr;
        while(getline(this->fs, temp))
        {
            if (temp.empty()) continue;
            text.append(temp);
            const string& c = "=";
            const string& s = temp;
            vector<string>& v = cfgArr;
            this->splitString(s, v, c);
            if (cfgArr[0] == "autoSave") {
                if (cfgArr[1] == "true") cfg.autoSave = true;
            } else if (cfgArr[0] == "treeView") {
                if (cfgArr[1] == "false") cfg.treeView = false;
            } else if (cfgArr[0] == "fontFamily") {
                QFontDatabase fdb;
                QStringList list = QFontDatabase::families();
                if(cfgArr[1] != "default") {
                    for (const auto & i : list) {
                        if (cfgArr[1] == i.toStdString()) cfg.font = QString(cfgArr[1].c_str());
                    }
                }
            } else if (cfgArr[0] == "chinese") {
                if (cfgArr[1] == "false") cfg.chinese = false;
            }
            cfgArr.clear();
        }
        this->fs.close();
        if (text.empty()) {
            qDebug() << "Notepad::init-log:config.txt is empty\n";
            this->fs.open("config.txt", std::ios::out);
            if (!this->fs) return;
            this->fs << T->defaultConfig.toStdString();
            this->fs.close();
        }
    }

    ui->treeView->setVisible(cfg.treeView);
    ui->actionTreeViewEnable->setChecked(cfg.treeView);

    T->loadLanguage(cfg.chinese);

    setWindowTitle(T->title);
    ui->menuFile->setTitle(T->file);
    ui->actionOpen->setText(T->open);
    ui->actionOpenFolder->setText(T->openFolder);
    ui->actionSave->setText(T->save);
    ui->actionSaveAs->setText(T->saveAs);
    ui->actionSetting->setText(T->settings);
    ui->actionExit->setText(T->exit);
    ui->menu->setTitle(T->edit);  // edit menu
    ui->actionUndo->setText(T->undo);
    ui->actionRedo->setText(T->redo);
    ui->actionCut->setText(T->cut);
    ui->actionCopy->setText(T->copy);
    ui->actionPaste->setText(T->paste);
    ui->actionFind->setText(T->find);
    ui->menuView->setTitle(T->view);
    ui->actionTreeViewEnable->setText(T->enableTreeView);
    ui->actionTreeViewShowAll->setText(T->treeExpandAll);
    ui->actionTreeViewCloseAll->setText(T->treeCollapseAll);
    ui->actionTreeViewClean->setText(T->treeClear);
    ui->menuHelp->setTitle(T->about);
    ui->actionAbout->setText(T->aboutNotepad);
}

void Notepad::onClickTreeView(const QModelIndex &index)
{
    if (!model) return;

    string text;
    string temp;
    this->path = model->filePath(index).toStdString();

    this->fs.open(this->path, std::ios::in);
    if(!this->fs) return;
    while(getline(this->fs, temp))
    {
        if(!(text.empty())) text.append("\n");
        text.append(temp);
    }
    ui->textEdit->setText(QString::fromStdString(text));
    this->fs.close();
}

void Notepad::openFile()
{
    string text;
    string temp;
    qDebug() << "Notepad::openFile: start.\n";
    this->path = QFileDialog::getOpenFileName(this, "", ".", "*.*").toStdString();
    qDebug() << "Notepad::openFile: path:" << this->path.c_str() << ".\n";
    this->fs.open(this->path, std::ios::in);
    if(!this->fs) return;
    while(getline(this->fs, temp))
    {
        if(!(text.empty())) text.append("\n");
        text.append(temp);
    }
    qDebug() << "Notepad::openFile: text:\n" << text.c_str() << "\n---end---\n";
    ui->textEdit->setText(QString::fromStdString(text));
    file = text;
    this->fs.close();
}

void Notepad::openFolder()
{
    qDebug() << "Notepad::openFolder: start.\n";
    QString folder = QFileDialog::getExistingDirectory();
    qDebug() << "Notepad::openFolder: path:" << folder.toStdString().c_str() << ".\n";
    model = new QFileSystemModel();
    model->setRootPath(folder);
    ui->treeView->setModel(model);
    ui->treeView->setRootIndex(model->index(folder));
    ui->treeView->setSortingEnabled(true);
    ui->treeView->setColumnHidden(1, true);
    ui->treeView->setColumnHidden(2, true);
    ui->treeView->setColumnHidden(3, true);
}

void Notepad::openSetting()
{
    qDebug() << "Notepad::openSetting: start.\n";
    auto * setting = new Setting(this, cfg.chinese);
    setting->show();
    setting->exec();
}

void Notepad::saveAs()
{
    qDebug() << "Notepad::saveAs: start.\n";
    this->path = QFileDialog::getSaveFileName(this, "", ".", "*.*").toStdString();
    qDebug() << "Notepad::saveAs: path:" << this->path.c_str() << ".\n";
    saveFile();
}

bool Notepad::saveFile()
{
    qDebug() << "Notepad::saveFile: start.\n";
    this->fs.open(this->path, std::ios::out);
    if(!this->fs) return false;
    file = ui->textEdit->toPlainText().toStdString();
    this->fs << file;
    this->fs.close();
    return true;
}

void Notepad::splitString(const string& s, vector<string>& v, const string& c)
{
    std::string::size_type pos1, pos2;
    pos2 = s.find(c);
    pos1 = 0;
    while(std::string::npos != pos2)
    {
        v.push_back(s.substr(pos1, pos2-pos1));
        pos1 = pos2 + c.size();
        pos2 = s.find(c, pos1);
    }
    if(pos1 != s.length())
    v.push_back(s.substr(pos1));
}

Notepad::Notepad(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Notepad)
{   
    ui->setupUi(this);

    init();
    QObject::connect((ui->actionExit), &QAction::triggered, this, &QWidget::close);  // close the window
    QObject::connect((ui->actionOpen), &QAction::triggered, this, &Notepad::openFile);  // open file
    QObject::connect((ui->actionSave), &QAction::triggered, this, &Notepad::saveAs);  // save file
    QObject::connect((ui->actionSaveAs), &QAction::triggered, this, &Notepad::saveAs);  // save file as
    QObject::connect((ui->actionSetting), &QAction::triggered, this, &Notepad::openSetting);  // open the dialog of settings
    QObject::connect((ui->actionAbout), &QAction::triggered, this, &Notepad::about);  // show the information of the program
    QObject::connect((ui->actionUndo), &QAction::triggered, ui->textEdit, &QTextEdit::undo);  // undo
    QObject::connect((ui->actionRedo), &QAction::triggered, ui->textEdit, &QTextEdit::redo);  // redo
    QObject::connect((ui->actionCut), &QAction::triggered, ui->textEdit, &QTextEdit::cut);  // cut some text
    QObject::connect((ui->actionCopy), &QAction::triggered, ui->textEdit, &QTextEdit::copy);  // copy some text
    QObject::connect((ui->actionPaste), &QAction::triggered, ui->textEdit, &QTextEdit::paste);  // paste some text
    QObject::connect(ui->actionTreeViewEnable, &QAction::toggled, ui->treeView, &QTreeView::setVisible);  // show or not show the tree view
    // QObject::connect((ui->actionTreeViewClean), &QAction::triggered, ui->treeView, &QTreeView::);  // clear the tree view
    QObject::connect((ui->actionTreeViewCloseAll), &QAction::triggered, ui->treeView, &QTreeView::collapseAll);  // close all selection
    QObject::connect((ui->actionTreeViewShowAll), &QAction::triggered, ui->treeView, &QTreeView::expandAll);
    QObject::connect((ui->actionOpenFolder), &QAction::triggered, this, &Notepad::openFolder);
    QObject::connect((ui->actionFind), &QAction::triggered, this, &Notepad::find);
    QObject::connect((ui->treeView), &QAbstractItemView::doubleClicked, this, &Notepad::onClickTreeView);
}

Notepad::~Notepad()
{
    delete ui;
}
