//
// Created by Leonardo on 22/07/2017.
//
#include <QPainter>
#include <QDesktopWidget>
#include "MainWindow.h"

Resource * MainWindow::resource = nullptr;

MainWindow::MainWindow(double totdim, vector<Resource *> resourcesAddresses, QWidget *parent) :
        totdim(totdim), resources(resourcesAddresses), QMainWindow(parent) {

    //register all the resource in the resourcesAddresses vector to this observer
    for (const auto &itr : resources)
        itr->subscribeObserver(this);

    //create title
    this->setWindowTitle("Elaborato Laboratorio di Programmazione - A.A. 2016/17");
    this->setFixedSize(QSize(1000, 800));

    //create button
    startbutton = new QPushButton("Start", this);
    startbutton->setGeometry(QRect(QPoint(410, 40), QSize(180, 50)));

    //create progress bar
    progressBar = new QProgressBar(this);
    progressBar->setGeometry(QRect(QPoint(225, 100), QSize(550, 30)));

    //create text box
    text = new QTextEdit(this);
    text->setGeometry(QRect(QPoint(50, 180), QSize(900, 570)));
    text->setText("Click on the 'Start' button to start loading resources\n");
    text->setReadOnly(true);

    //set progress bar values
    progressBar->setMinimum(0);
    progressBar->setMaximum(100);
    progressBar->setValue(0);

    //connect the button to the function to call on click
    connect(startbutton, SIGNAL (released()), this, SLOT (loadResources()));
}

void MainWindow::update() {

    if (resource->isLoaded()) {//if the file has been loaded

        //calculation of the increment of the progress bar
        double perc = (resource->getFilesize() * 100) / totdim;

        //approximation of the increment to a integer value //approximation of the increment to a integer value
        perc = floor(perc + 0.5);

        //updateProgressBar progress bar value
        progressBar->setValue(progressBar->value() + static_cast<int>(perc));

        //updateProgressBar text
        QString update = QString(resource->getFilename()) + QString(" loaded successfully (") + QString::number(resource->getFilesize()) +
                         QString(" bytes).") + "\n";
        text->append(update);

        //updateProgressBar text
        update = QString::number(progressBar->value()) + QString("% avaible resources loaded!\n");
        text->append(update);

    } else {//if the file has not been loaded

        //Update text
        QString unpdate = QString(resource->getFilename()) + " not loaded\n";
        text->append(unpdate);
    }

};

void MainWindow::loadResources() {
    //when the button was clicked, it is disabled and the observer is notified
    startbutton->setEnabled(false);
    for (const auto &itr : resources) {
        itr->notifyObservers();
    }
}

double MainWindow::getTotdim() const {
    return totdim;
}

QProgressBar *MainWindow::getProgressBar() const {
    return progressBar;
}
