//
// Created by Leonardo on 22/07/2017.
//

#ifndef PROVAQT_MAINWINDOW_H
#define PROVAQT_MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QProgressBar>
#include <QTextEdit>
#include <QLabel>
#include "Observer.h"
#include "Resources.h"
#include <iostream>

class MainWindow : public QMainWindow, public Observer {
    Q_OBJECT
public:
    MainWindow(int totdim, vector<Resources*> resourcesAddresses, QWidget *parent);

    virtual ~MainWindow() {
        for(const auto &itr : resources){
            itr->unsubscribeObserver(this);
        }
    }

    virtual void update(int filesize, QString filename) override;

private slots: //what happend on click button
    void loadResources();

private:
    vector<Resources*> resources;
    int totdim;

    QPushButton * startbutton;
    QProgressBar * progressBar;
    QTextEdit * text;

    QLabel * title;
};


#endif //PROVAQT_MAINWINDOW_H
