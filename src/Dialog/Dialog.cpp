#include "Dialog.h"
#include "ui_Dialog.h"

#include <iostream>
#include <QDialogButtonBox>
#include <QObject>
#include <QPushButton>
#include <QMessageBox>

void Dialog::findFirst()
{
    qDebug() << "Dialog-find: find\n";
    findText = ui->lineEdit->text();
}

[[maybe_unused]] void Dialog::replace()
{

}

void Dialog::type3Yes() {
    returned = 0;
}

void Dialog::type3No() {
    returned = 1;
}

void Dialog::type3Cancel()
{
    returned = 2;
}

Dialog::Dialog(QWidget *parent, int id, bool chinese) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    T = new Text();
    T->loadLanguage(chinese);
    returned = 0;
    finished = false;
    qDebug() << "Dialog:init\n";
    qDebug() << ui->buttonBox->buttons().length() << "\n";
    for (int i = 0; i<4; i++) {
        qDebug() << ui->buttonBox->buttons()[i] << "\n";
    }
    // Button: 0 Yes 1 Ok 2 No 3 Cancel
    if (id == 0) {
        qDebug() << "Dialog:type 0\n";
        this->setWindowTitle(T->findTitle);
        ui->label->setText(T->findTip);
        ui->buttonBox->buttons()[1]->setText(T->okButton);
        ui->buttonBox->buttons()[3]->setText(T->cancelButton);
        ui->buttonBox->removeButton(ui->buttonBox->buttons()[0]);
        ui->buttonBox->removeButton(ui->buttonBox->buttons()[1]);
        QObject::connect((ui->buttonBox), &QDialogButtonBox::accepted, this, &Dialog::findFirst);
    } else if (id == 1) {
        qDebug() << "Dialog:type 1\n";
        this->setWindowTitle(T->about);
        ui->label->setText(T->aboutNotepadText);
        ui->buttonBox->buttons()[1]->setText(T->okButton);
        ui->buttonBox->removeButton(ui->buttonBox->buttons()[0]);
        ui->buttonBox->removeButton(ui->buttonBox->buttons()[1]);
        ui->buttonBox->removeButton(ui->buttonBox->buttons()[1]);
        ui->lineEdit->setVisible(false);
        QObject::connect((ui->buttonBox), &QDialogButtonBox::accepted, this, &Dialog::close);
    } else if(id == 2) {
        qDebug() << "Dialog:type 2\n";
        this->setWindowTitle(T->settingsGuideTitle);
        ui->label->setText(T->settingsGuideText);
        ui->buttonBox->buttons()[1]->setText(T->okButton);
        ui->buttonBox->removeButton(ui->buttonBox->buttons()[0]);
        ui->buttonBox->removeButton(ui->buttonBox->buttons()[1]);
        ui->buttonBox->removeButton(ui->buttonBox->buttons()[1]);
        ui->lineEdit->setVisible(false);
        QObject::connect((ui->buttonBox), &QDialogButtonBox::accepted, this, &Dialog::close);
    } else if(id == 3) {
        qDebug() << "Dialog:type 3\n";
        this->setWindowTitle(T->quitDialogTitle);
        ui->label->setText(T->quitDialogText);
        ui->buttonBox->buttons()[0]->setText(T->yesButton);
        ui->buttonBox->buttons()[2]->setText(T->noButton);
        ui->buttonBox->buttons()[3]->setText(T->cancelButton);
        ui->buttonBox->removeButton(ui->buttonBox->buttons()[1]);
        ui->lineEdit->setVisible(false);
        QObject::connect((ui->buttonBox), &QDialogButtonBox::accepted, this, &Dialog::type3Yes);
        QObject::connect((ui->buttonBox), &QDialogButtonBox::rejected, this, &Dialog::type3No);
    }
}

Dialog::~Dialog()
{
    delete ui;
    delete T;
}
