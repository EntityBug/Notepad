#ifndef DIALOG_H
#define DIALOG_H

#include <QAbstractButton>
#include <QDialog>
#include <QString>

#include "src/Strings/Strings.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr, int id = 0, bool chinese = true);
    ~Dialog() override;
    QString findText;
    bool finished;
    int returned;

public slots:
    void findFirst();
    void type3Clicked(QAbstractButton * btn);

private:
    Ui::Dialog *ui;
    Text * T;
};

#endif // DIALOG_H
