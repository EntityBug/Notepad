//
// Created by tzx on 2022/1/31.
//

#ifndef NOTEPAD_STRINGS_H
#define NOTEPAD_STRINGS_H

#include <iostream>
#include <QString>
using namespace std;
typedef QString s;

class Text {
public:
    s title;
    s version;
    s file;
    s open;
    s openFolder;
    s save;
    s saveAs;
    s settings;
    s exit;
    s edit;
    s undo;
    s redo;
    s copy;
    s paste;
    s cut;
    s find;
    s view;
    s enableTreeView;
    s treeCollapseAll;
    s treeExpandAll;
    s treeClear;
    s about;
    s aboutNotepad;
    s aboutNotepadText;
    s settingsWindowTitle;
    s settingsLab1;
    s settingsTitle;
    s settingsApply;
    s settingsRestore;
    s settingsGuide;
    s settingsLab2;
    s updateLog;
    s findTitle;
    s findTip;
    s defaultConfig;
    s okButton;
    s cancelButton;
    s settingsGuideTitle;
    s settingsGuideText;
    s quitDialogTitle;
    s quitDialogText;
    s quitDialogNoSaveButton;
    void loadLanguage(bool chinese);
    explicit Text();
};

#endif //NOTEPAD_STRINGS_H
