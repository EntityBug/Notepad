#include "Dialog.h"
#include "ui_Dialog.h"

#include <iostream>
#include <QDialogButtonBox>
#include <QObject>
#include <QMessageBox>

void Dialog::findFirst()
{
    qDebug() << "Dialog-find: find\n";
    findText = ui->lineEdit->text();
}

void Dialog::type3Clicked(QAbstractButton * btn) {
    if (btn == (QAbstractButton *)ui->buttonBox->button(QDialogButtonBox::Yes)) {
        returned = 0;
    } else if(btn == (QAbstractButton *)ui->buttonBox->button(QDialogButtonBox::No)) {
        returned = 1;
    } else {
        returned = 2;
    }
    finished = true;
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
    QAbstractButton * yesBtn = (QAbstractButton *)ui->buttonBox->button(QDialogButtonBox::Yes);
    QAbstractButton * noBtn = (QAbstractButton *)ui->buttonBox->button(QDialogButtonBox::No);
    QAbstractButton * okBtn = (QAbstractButton *)ui->buttonBox->button(QDialogButtonBox::Ok);
    QAbstractButton * cancelBtn = (QAbstractButton *)ui->buttonBox->button(QDialogButtonBox::Cancel);

    if (id == 0) {
        qDebug() << "Dialog:type 0\n";
        this->setWindowTitle(T->findTitle);
        ui->label->setText(T->findTip);
        okBtn->setText(T->okButton);
        cancelBtn->setText(T->cancelButton);
        ui->buttonBox->removeButton(yesBtn);
        ui->buttonBox->removeButton(noBtn);
        QObject::connect((ui->buttonBox), &QDialogButtonBox::accepted, this, &Dialog::findFirst);
    } else if (id == 1) {
        qDebug() << "Dialog:type 1\n";
        this->setWindowTitle(T->about);
        ui->label->setText(T->aboutNotepadText);
        okBtn->setText(T->okButton);
        ui->buttonBox->removeButton(yesBtn);
        ui->buttonBox->removeButton(noBtn);
        ui->buttonBox->removeButton(cancelBtn);
        ui->lineEdit->setVisible(false);
        QObject::connect((ui->buttonBox), &QDialogButtonBox::accepted, this, &Dialog::close);
    } else if(id == 2) {
        qDebug() << "Dialog:type 2\n";
        this->setWindowTitle(T->settingsGuideTitle);
        ui->label->setText(T->settingsGuideText);
        okBtn->setText(T->okButton);
        ui->buttonBox->removeButton(yesBtn);
        ui->buttonBox->removeButton(noBtn);
        ui->buttonBox->removeButton(cancelBtn);
        ui->lineEdit->setVisible(false);
        QObject::connect((ui->buttonBox), &QDialogButtonBox::accepted, this, &Dialog::close);
    } else if(id == 3) {
        qDebug() << "Dialog:type 3\n";
        this->setWindowTitle(T->quitDialogTitle);
        ui->label->setText(T->quitDialogText);
        yesBtn->setText(T->yesButton);
        noBtn->setText(T->noButton);
        cancelBtn->setText(T->cancelButton);
        ui->buttonBox->removeButton(okBtn);
        ui->lineEdit->setVisible(false);
        QObject::connect(ui->buttonBox, &QDialogButtonBox::clicked, this, &Dialog::type3Clicked);
    } else if(id == 4) {
        qDebug() << "Dialog:type 4\n";
        this->setWindowTitle(T->errorTitle);
        ui->label->setText(T->cannotSaveText);
        yesBtn->setText(T->okButton);
        ui->buttonBox->removeButton(okBtn);
        ui->buttonBox->removeButton(noBtn);
        ui->buttonBox->removeButton(cancelBtn);
        ui->lineEdit->setVisible(false);
        QObject::connect((ui->buttonBox), &QDialogButtonBox::accepted, this, &Dialog::close);
    } else if(id == 5) {
        qDebug() << "Dialog:type 4\n";
        this->setWindowTitle(T->errorTitle);
        ui->label->setText(T->cannotFindText);
        yesBtn->setText(T->okButton);
        ui->buttonBox->removeButton(okBtn);
        ui->buttonBox->removeButton(noBtn);
        ui->buttonBox->removeButton(cancelBtn);
        ui->lineEdit->setVisible(false);
        QObject::connect((ui->buttonBox), &QDialogButtonBox::accepted, this, &Dialog::close);
    }
}

Dialog::~Dialog()
{
    delete ui;
    delete T;
}
