//
// Created by tzx on 2022/1/31.
//
#include "Strings.h"

Text::Text() {
    version = "1.0 dev6 (220614)";
    defaultConfig = "autoSave=false\n"
                    "treeView=true\n"
                    "fontFamily=等线\n"
                    "chinese=true";
    title = "Notepad";
}

void Text::loadLanguage(bool chinese) {
    if (chinese) {
        file = "文件";
        open = "打开";
        openFolder = "打开文件夹";
        save = "保存";
        saveAs = "另存为";
        settings = "设置";
        exit = "退出";
        edit = "编辑";
        undo = "撤销";
        redo = "重做";
        copy = "复制";
        paste = "粘贴";
        cut = "剪切";
        find = "查找下一个";
        view = "视图";
        enableTreeView = "使用侧边栏";
        treeCollapseAll = "侧边栏全部折叠";
        treeExpandAll = "侧边栏全部展开";
        treeClear = "清除侧边栏";
        about = "关于";
        aboutNotepad = "关于Notepad";
        aboutNotepadText = QString::fromStdString("作者: EntityBug (entitybug.github.io)\n"
                                                  "邮箱: fmn_tzx@outlook.com\n"
                                                  "版本: " + this->version.toStdString() +
                                                  "\nCopyright (c) 2021 EntityBug. All rights reserved.");
        settingsWindowTitle = "Notepad设置";
        settingsLab1 = "设置";
        settingsTitle = "# 设置";
        settingsApply = "应用";
        settingsRestore = "恢复默认";
        settingsGuide = "如何设置";
        settingsLab2 = "关于";
        updateLog = "# 关于  \n"
                    "## 版本  \n"
                    "version 1.0 dev 6 (220604)  \n"
                    "## 免责声明  \n"
                    "使用本APP造成的任何损失，本APP概不负责。  \n"
                    "## 更新日志  \n"
                    "### Dev6 (220614)  \n"
                    "1.（正式地）新年快乐！  \n"
                    "2.更多资源分离，修改部分string  \n"
                    "3.添加部分更新日志  \n"
                    "4.优化部分UI  \n"
                    "5.添加了treeview的功能  \n"
                    "6.添加了设置中如何设置按钮的功能  \n"
                    "7.未完待续  \n"
                    "### Dev5 (220131)  \n"
                    "1.添加设置中的初次打开生成config.txt、恢复config.txt的功能  \n"
                    "2.汉化搜索框  \n"
                    "3.log全部改用qDebug()  \n"
                    "4.修改字体，默认为等线  \n"
                    "5.改用CMake  \n"
                    "6.独立更新日志  \n"
                    "7.资源分离，添加英语  \n"
                    "7.新年快乐！  \n"
                    "### Dev4 (211106)  \n"
                    "1.优化log、设置界面、关于界面  \n"
                    "2.增加从头搜索功能  \n"
                    "3.大量汉化  \n"
                    "### Dev2 & Dev3 (210101)  \n"
                    "1.暂时关闭设置的主标签，重新构思  \n"
                    "2.把所有QObject::connect()更新为已有定义的指针形式  \n"
                    "3.重命名部分部件  \n"
                    "4.编译器gcc qt6.0 64bit  \n"
                    "5.增加两个tree view操作  \n"
                    "6.删除一个无用变量  \n"
                    "7.完成treeview的剩余三个操作(展开、关闭、打开文件夹)，但未实现点击文件打开的功能  \n"
                    "8.给setting的两个按钮加了槽函数  \n"
                    "9.移除mainwindow的Tools菜单（主要是什么文字编码它都能打开）  \n"
                    "### Dev1 (201024)  \n"
                    "1.基于Qt C++重写NotePad（python版），代替VS C++版  \n"
                    "2.增加设置GUI，增加about和aboutQt功能。  \n"
                    "3.编辑菜单除Find外已完成功能。  \n"
                    "4.增加save saveAs的功能。  \n"
                    "5.修复open多加一个\\n的bug。  \n"
                    "6.快捷键：  \n"
                    "open ctrl+o  \n"
                    "openFolder ctrl+shift+o  \n"
                    "save ctrl+s  \n"
                    "saveAs ctrl+shift+o  \n"
                    "exit alt+q  \n"
                    "setting ctrl+,  \n"
                    "find ctrl+f  \n"
                    "redo ctrl+y  \n"
                    "undo ctrl+z  \n"
                    "cut ctrl+x  \n"
                    "copy ctrl+c  \n"
                    "paste ctrl+v  \n"
                    "Copyright 2021 EntityBug. All rights reserved.   ";
        findTitle = "查找下一个";
        findTip = "查找下一个\n"
                  "在输入框内输入要查找的内容";
        okButton = "确定";
        cancelButton = "取消";
        yesButton = "是";
        noButton = "否";
        settingsGuideText = "配置方法\n"
                            "1.格式：名称=配置，不能加空格\n"
                            "2.所有名称都在默认生成的config.txt中，误删可通过恢复默认按钮重置\n"
                            "3.配置一种为布尔值，可以填写true和false，注意true对应打开，false对应关闭，二者都只能用小写字母\n"
                            "4.另一种即字体配置，可以输入你在Word中看到的所有的字体名，不用加除名称外的其他信息。\n"
                            "5.chinese选项开启为中文（简体），关闭为英文";
        settingsGuideTitle = "配置方法";
        quitDialogTitle = "文件未保存";
        quitDialogText = "当前文件未保存，是否保存？";
        quitDialogNoSaveButton = "不保存";
    } else {
        file = "File";
        open = "Open";
        openFolder = "Open Folder";
        save = "Save";
        saveAs = "Save As";
        settings = "Settings";
        exit = "Quit";
        edit = "Edit";
        undo = "Undo";
        redo = "Redo";
        copy = "Copy";
        paste = "Paste";
        cut = "Cut";
        find = "Find Next";
        view = "View";
        enableTreeView = "Enable TreeView";
        treeCollapseAll = "Collapse All (TreeView)";
        treeExpandAll = "Expand All (TreeView)";
        treeClear = "Clear (TreeView)";
        about = "About";
        aboutNotepad = "About Notepad";
        aboutNotepadText = QString::fromStdString("author: EntityBug (entitybug.github.io)\n"
                                                  "Email: fmn_tzx@outlook.com\n"
                                                  "Version: " + this->version.toStdString() +
                                                  "\nCopyright (c) 2021 EntityBug. All rights reserved.");
        settingsWindowTitle = "Notepad Settings";
        settingsLab1 = "Settings";
        settingsTitle = "# Settings";
        settingsApply = "Apply";
        settingsRestore = "Restore";
        settingsGuide = "Guide";
        settingsLab2 = "About";
        updateLog = "# About  \n"
                    "## Version  \n"
                    "version 1.0 dev 6 (220614)  \n"
                    "## Disclaimers  \n"
                    "I am not responsible for any loss caused by using this app.  \n"
                    "## Update Log  \n"
                    "### Dev6 (220614)  \n"
                    "1.Happy lunar new year!  \n"
                    "2.Move more strings to strings.h & some string improvements.  \n"
                    "3.Add some update log.  \n"
                    "4.Improved UI.  \n"
                    "5.Add function of TreeView.  \n"
                    "6.Add function of Guide in Settings.  \n"
                    "7.And more things.  \n"
                    "### Dev5 (220131)  \n"
                    "1.Create config.txt when the first time open this app & add function \"restore config.txt\".  \n"
                    "2.Chinese improvement.  \n"
                    "3.Use qDebug() to print log.  \n"
                    "4.Change the default font to Arial.  \n"
                    "5.Use cmake instead of qmake.   \n"
                    "6.Move update log to strings.h  \n"
                    "7.Move some strings to strings.h & add some English strings.  \n"
                    "7.Happy lunar new year！  \n"
                    "### Dev4 (211106)  \n"
                    "1.UI & log improvements.  \n"
                    "2.Add function \"find next\".  \n"
                    "3.Chinese improvements.  \n"
                    "### Dev2 & Dev3 (210101)  \n"
                    "1.Disabled Settings.  \n"
                    "2.Use new QObject::connect format.  \n"
                    "3.Rename some controls.  \n"
                    "4.Use gcc 8.1.0 64bit to compile the project.  \n"
                    "5.Add some functions for TreeView.  \n"
                    "6.Delete a unused variable.  \n"
                    "7.TreeView improvements.  \n"
                    "8.Settings improvements.  \n"
                    "9.Delete unused Tool menu.  \n"
                    "### Dev1 (201024)  \n"
                    "1.This is a C++ version of my project \"Notepad\" which had been written in python3.  \n"
                    "2.Add Settings and About menu.  \n"
                    "3.Add Edit menu.  \n"
                    "4.Add functions \"save\" and \"save as\".  \n"
                    "5.Fix: There will be a new \\n after saving the file in the end line.  \n"
                    "6.Keys：  \n"
                    "open ctrl+o  \n"
                    "openFolder ctrl+shift+o  \n"
                    "save ctrl+s  \n"
                    "saveAs ctrl+shift+o  \n"
                    "exit alt+q  \n"
                    "setting ctrl+,  \n"
                    "find ctrl+f  \n"
                    "redo ctrl+y  \n"
                    "undo ctrl+z  \n"
                    "cut ctrl+x  \n"
                    "copy ctrl+c  \n"
                    "paste ctrl+v  \n"
                    "Copyright 2021 EntityBug. All rights reserved.   ";
        findTitle = "Find Next";
        findTip = "Find Next\n"
                  "Enter what you want to search in the TextEdit.";
        okButton = "Ok";
        cancelButton = "Cancel";
        yesButton = "Yes";
        noButton = "No";
        settingsGuideText = "Guide\n"
                            "1.Format: name=value, DO NOT ADD SPACE\n"
                            "2.config.txt includes all the names, if you deleted it, you can press \"restore\" button to restore it\n"
                            "3.There are 2 kinds of values, bool and string. For bool values, you can enter true or false, ONLY USE LOWERCASE LETTERS\n"
                            "4.For string values (font setting), you should enter the font name that you can see in Microsoft Word (or other office apps). You don't need to enter anything except the font name\n"
                            "5.If you set \"chinese\" to false, the language will be changed to English, or the language will be Chinese (Simplified)";
        settingsGuideTitle = "Guide";
        quitDialogTitle = "File is not saved";
        quitDialogText = "The file is not saved, are you going to save it?";
        quitDialogNoSaveButton = "Don't Save";
    }
}
