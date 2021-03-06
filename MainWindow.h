//
// Created by Leonardo on 22/07/2017.
//

#ifndef PROVAQT_MAINWINDOW_H
#define PROVAQT_MAINWINDOW_H

#include <iostream>
#include <QMainWindow>
#include <QPushButton>
#include <QProgressBar>
#include <QTextEdit>
#include <QLabel>
#include "Observer.h"
#include "Resource.h"

class MainWindow : public QMainWindow, public Observer {
Q_OBJECT
public:
    MainWindow(double totdim, vector<Resource *> resourcesAddresses, QWidget *parent = 0);

    virtual ~MainWindow() {
        //before destroying the observer, unsubscribe al the subjects
        for (const auto &itr : resources) {
            itr->unsubscribeObserver(this);
        }
    }

    double getTotdim() const;

    QProgressBar *getProgressBar() const;

    virtual void update() override;

    static Resource *resource;

private slots: //what happens on click button
    void loadResources();

private:
    vector<Resource *> resources; //vector the contains the addresses of all subjects subscribed
    double totdim; //total dimension of the resources

    QPushButton *startbutton; //button to start loading resources
    QProgressBar *progressBar; //the progress bar
    QTextEdit *text; //the text
};

#endif //PROVAQT_MAINWINDOW_H
