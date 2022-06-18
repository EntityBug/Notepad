#ifndef NOTEPAD_H
#define NOTEPAD_H
#include "strings.h"

#include <QMainWindow>
#include <fstream>
#include <iostream>
#include <QFont>
#include <QFileSystemModel>

QT_BEGIN_NAMESPACE
namespace Ui { class Notepad; }
QT_END_NAMESPACE

using namespace std;

class Notepad : public QWidget
{
    Q_OBJECT
public slots:
    void openFile();
    void saveAs();
    void openFolder();
    void openSetting();
    void about();
    void find();
    void onClickTreeView(const QModelIndex &index);
protected:
    void init();
    static void splitString(const std::string&, std::vector<std::string>&, const std::string&);
    bool saveFile();
    string path;
    string file;
    fstream fs;
    struct Config {
        bool autoSave;
        bool treeView;
        QString font;
        bool chinese;
    };
    Config cfg;
    QFileSystemModel * model;

public:
    explicit Notepad(QWidget * parent = nullptr);

    ~Notepad() override;
    QString getFontCfg() const;
    Text * T{};

private:
    Ui::Notepad *ui;

protected:
    void closeEvent(QCloseEvent * event) override;

};
#endif // NOTEPAD_H
