#include <iostream>
#include <QVBoxLayout>
#include <QPushButton>
#include <QApplication>
#include "MainWindow.h"

using namespace std;

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);

    vector<Resources*> resourcesAddresses;
    int totfilesize;

    Resources* first = new Resources;
    first->setFilesize(12);
    first->setFilename("primo file");

    Resources* second = new Resources;
    second->setFilesize(24);
    second->setFilename("secondo file");

    totfilesize=first->getFilesize()+second->getFilesize();

    resourcesAddresses.push_back(first);
    resourcesAddresses.push_back(second);

    //chiama main window
    MainWindow mainWindow(totfilesize, resourcesAddresses);
    mainWindow.show();

    return app.exec();
}