#include "Setting.h"
#include "ui_Setting.h"
#include "Dialog.h"

#include <iostream>
#include <QDialog>
#include <QAction>
#include <QObject>

using namespace std;

void Setting::apply()
{
    std::fstream fs;
    fs.open("config.txt", std::ios::out);
    if(!fs) return;
    fs << ui->textEdit->toPlainText().toStdString();
    fs.close();
    qDebug() << "Setting::apply-log:saved config\n";
}

void Setting::restore()
{
    this->fs.open("config.txt", std::ios::out);
    if (!this->fs) return;
    this->fs << T->defaultConfig.toStdString();
    this->fs.close();
    this->close();
    qDebug() << "Setting::restore-log:restored config\n";
}

void Setting::guide()
{
    auto *d = new Dialog(this, 2, isChinese);
    d->show();
    d->exec();
}

void Setting::init(bool chinese)
{
    string temp, cfg;
    std::fstream fs;
    this->isChinese = chinese;
    T = new Text();
    T->loadLanguage(chinese);
    setWindowTitle(T->settingsWindowTitle);
    ui->tabWidget->setTabText(0, T->settingsLab1);
    ui->label->setText(T->settingsTitle);
    ui->applyButton->setText(T->settingsApply);
    ui->cancelButton->setText(T->cancelButton);
    ui->restoreButton->setText(T->settingsRestore);
    ui->guideButton->setText(T->settingsGuide);
    ui->tabWidget->setTabText(1, T->settingsLab2);
    ui->aboutLabel->setText(T->updateLog);
    qDebug() << "Setting::init-log:set text from strings.h\n";

    fs.open("config.txt", std::ios::in);
    if(!fs) return;
    while(getline(fs, temp))
    {
        if(!(cfg.empty())) cfg.append("\n");
        cfg.append(temp);
    }
    ui->textEdit->setText(QString::fromStdString(cfg));
    fs.close();
    qDebug() << "Setting::init-log:successfully loaded config\n";
}

Setting::Setting(QWidget *parent, bool chinese) :
    QDialog(parent),
    ui(new Ui::Setting)
{
    ui->setupUi(this);
    this->init(chinese);
    QObject::connect((ui->applyButton), &QPushButton::clicked, this, &Setting::apply);
    QObject::connect((ui->cancelButton), &QPushButton::clicked, this, &QDialog::close);
    QObject::connect((ui->restoreButton), &QPushButton::clicked, this, &Setting::restore);
    QObject::connect((ui->guideButton), &QPushButton::clicked, this, &Setting::guide);
}

Setting::~Setting()
{
    delete ui;
    delete T;
}
