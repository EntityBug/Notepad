#ifndef SETTING_H
#define SETTING_H

#include <QDialog>
#include <QObject>
#include <fstream>
#include "strings.h"

namespace Ui {
class Setting;
}

class Setting : public QDialog
{
    Q_OBJECT

public slots:
    void apply();
    void restore();
    void guide();
public:
    explicit Setting(QWidget *parent = nullptr, bool chinese = true);
    ~Setting() override;

private:
    Ui::Setting *ui;
protected:
    std::fstream fs;
    void init(bool chinese);
    Text * T{};
    bool isChinese;
};

#endif // SETTING_H
