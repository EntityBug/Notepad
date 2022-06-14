#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QString>

#include "strings.h"

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
    int returned;

public slots:
    void findFirst();
    void save();
    void cancel();
    [[maybe_unused]] void replace();

private:
    Ui::Dialog *ui;
    Text * T;
};

#endif // DIALOG_H
