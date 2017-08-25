#include <iostream>
#include <QVBoxLayout>
#include <QPushButton>
#include <QApplication>
#include "MainWindow.h"

using namespace std;

int main(int argc, char *argv[]) {

    //create qt application
    QApplication app(argc, argv);

    //vector to get all the subjects (class Resource)
    vector<Resource> resources;

    Resource::getResources(&resources);

    /*vector to register all the subject (class Resource) addresses
    to pass to the observer (class MainWindow)*/
    vector<Resource*> resourcesAddresses(resources.size());

    for(int i = 0; i<resources.size(); i++){
        resourcesAddresses[i] = &resources[i];
    }

    //create and show main window
    MainWindow mainWindow(Resource::totdim, resourcesAddresses);
    mainWindow.show();

    return app.exec();
}
