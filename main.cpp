#include <iostream>
#include <QVBoxLayout>
#include <QPushButton>
#include <QApplication>
#include "MainWindow.h"

using namespace std;

int main(int argc, char *argv[]) {

    //create qt application
    QApplication app(argc, argv);

    //create resource objects
    Resources a("C:\\Users\\leona\\CLionProjects\\LabProgram\\resources\\first_file.txt");
    Resources b("C:\\Users\\leona\\CLionProjects\\LabProgram\\resources\\second_file.txt");
    Resources c("C:\\Users\\leona\\CLionProjects\\LabProgram\\resources\\third_file.txt");
    Resources d("C:\\Users\\leona\\CLionProjects\\LabProgram\\resources\\fourth_file.txt");

    /*vector to register all the subject (class Resources) addresses
    to pass to the observer (class MainWindow)*/
    vector<Resources *> resourcesAddresses;

    //push back all the addresses in the vector
    resourcesAddresses.push_back(&a);
    resourcesAddresses.push_back(&b);
    resourcesAddresses.push_back(&c);
    resourcesAddresses.push_back(&d);

    //create and call main window
    MainWindow mainWindow(Resources::totdim, resourcesAddresses);
    mainWindow.show();

    return app.exec();
}
