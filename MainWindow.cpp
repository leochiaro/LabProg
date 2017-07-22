//
// Created by Leonardo on 22/07/2017.
//
#include <QPainter>
#include <QDesktopWidget>

#include "MainWindow.h"


MainWindow::MainWindow(int totdim, vector<Resources*> resourcesAddresses, QWidget *parent) : totdim(totdim), resources(resourcesAddresses), QMainWindow(parent){

    for(const auto &itr : resources)
        itr->subscribeObserver(this);

    this->setWindowTitle("Elaborato Laboratorio di Programmazione - A.A. 2016/17");
    this->setFixedSize(QSize(600, 400));

    title = new QLabel("Inizia a caricare i file premendo qui sotto.", this);
    title->setGeometry(QRect(QPoint(100, 60), QSize(400, 100)));
    title->setWordWrap(true);
    title->setAlignment(Qt::AlignCenter);
    QFont font = title->font();
    font.setPointSize(16);
    title->setFont(font);

    startbutton = new QPushButton("Load Resources!", this);
    startbutton->setGeometry(QRect(QPoint(215, 200), QSize(170, 30)));

    progressBar = new QProgressBar(this);
    progressBar->setGeometry(QRect(QPoint(150, 170), QSize(300, 30)));

    text = new QTextEdit(this);
    text->setGeometry(QRect(QPoint(50, 240), QSize(500, 140)));
    text->setText("Ready to load resources!\n");
    text->setReadOnly(true);

    QTextCursor c =  text->textCursor();
    c.movePosition(QTextCursor::End);
    text->setTextCursor(c);

    progressBar->setMinimum(0);
    progressBar->setMaximum(100);
    progressBar->setValue(0);

    //Cnnette il tasto all'azione correlata
    connect(startbutton, SIGNAL (released()), this, SLOT (loadResources()));
}

void MainWindow::update(int filesize, QString filename) {

        int perc = (filesize*100)/totdim;

        //Update Progress Bar Percentage
        progressBar->setValue(progressBar->value() + perc);

        //Update text
        QString update = "✅ " + QString(filename) + QString("' loaded successfully (") + QString::number(filesize) + QString(" bytes).") + "\n";
        text->append(update);

        //Update Button Text
        update = QString::number(progressBar->value()) + QString("% resources loaded!");
        text->append(update);

        if(progressBar->value()==progressBar->maximum()) {
            update = QString("All resources loaded");
            text->append(update);
        }

    //TODO da lanciare se mai con un eccezione se il caricamento non va a buon fine
    /*
        //Update text log
        QString log = "❌ Could not load file '" + resources->getFilename();
        text->append(log);
    */

};

void MainWindow::loadResources() {

    //controllare il contenuto della cartella

    //inserire ogni file in un vettore di resources

    //un ciclo for per caricare tutti i file, con cntrollo di avvenuto caricamento


}