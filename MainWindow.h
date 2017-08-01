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
#include "Resources.h"
#include <iostream>
#include "Observer.h"

class MainWindow : public QMainWindow, public Observer {
Q_OBJECT
public:
    MainWindow(double totdim, vector<Resources*> resourcesAddresses, QWidget *parent=0);

    virtual ~MainWindow() {
        for(const auto &itr : resources){
            itr->unsubscribeObserver(this);
        }
    }

    virtual void update(int filesize, QString filename) override;

private slots:
    void loadResources();

private:
    vector<Resources*> resources;
    double totdim;

    QPushButton * startbutton;
    QProgressBar * progressBar;
    QTextEdit * text;

    QLabel * title;
};

#endif //PROVAQT_MAINWINDOW_H
