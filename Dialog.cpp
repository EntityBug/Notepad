#include "Dialog.h"
#include "ui_Dialog.h"

#include <iostream>
#include <QDialogButtonBox>
#include <QObject>

void Dialog::findFirst()
{
    qDebug() << "Dialog-find: find\n";
    findText = ui->lineEdit->text();
}

[[maybe_unused]] void Dialog::replace()
{

}

Dialog::Dialog(QWidget *parent, int id, bool chinese) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    T = new Text();
    T->loadLanguage(chinese);
    qDebug() << "Dialog:init\n";
    if (id == 0) {
        qDebug() << "Dialog:type 0\n";
        this->setWindowTitle(T->findTitle);
        ui->label->setText(T->findTip);
        ui->buttonBox->buttons()[0]->setText(T->okButton);
        ui->buttonBox->buttons()[1]->setText(T->cancelButton);
        QObject::connect((ui->buttonBox), &QDialogButtonBox::accepted, this, &Dialog::findFirst);
    } else if (id == 1) {
        qDebug() << "Dialog:type 1\n";
        this->setWindowTitle(T->about);
        ui->label->setText(T->aboutNotepadText);
        ui->buttonBox->buttons()[0]->setText(T->okButton);
        ui->buttonBox->removeButton(ui->buttonBox->buttons()[1]);
        ui->lineEdit->setVisible(false);
        QObject::connect((ui->buttonBox), &QDialogButtonBox::accepted, this, &Dialog::close);
    } else if(id == 2) {
        qDebug() << "Dialog:type 2\n";
        this->setWindowTitle(T->settingsGuideTitle);
        ui->label->setText(T->settingsGuideText);
        ui->buttonBox->buttons()[0]->setText(T->okButton);
        ui->buttonBox->removeButton(ui->buttonBox->buttons()[1]);
        ui->lineEdit->setVisible(false);
        QObject::connect((ui->buttonBox), &QDialogButtonBox::accepted, this, &Dialog::close);
    }
}

Dialog::~Dialog()
{
    delete ui;
    delete T;
}
