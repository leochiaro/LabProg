//
// Created by Leonardo on 22/07/2017.
//

#include <QTime>
#include <QtCore/QCoreApplication>
#include <cstdio>
#include <iostream>
#include "Resources.h"
#include "MainWindow.h"

//initialization of static variables
int Resources::totRisources = 0;
double Resources::totdim = 0;

Resources::Resources(const char *filename)  throw(runtime_error) : filename(filename) {
    Resources::totRisources++;//increment the number of resource to load
    try {
        /*open in read mode the resource. fopen return a FILE pointer then used to know the file size,
        if return nullptr, this means that file doesn't exist*/
        resource = fopen(filename, "r");
        fseek(resource, 0, SEEK_END);
        if (resource == nullptr) {
            throw runtime_error("File not found");
        }
        filesize = ftell(resource);//ftell return the file size
        Resources::totdim += filesize;//increment the total size of the resources

        if (fclose(resource) == 0)
            fclose(resource);
        else {
            throw runtime_error("Error closing file.");
        }
        loaded = true;


    } catch (runtime_error &e) {
        //if something goes wrong in the previous statement, an exception is thrown

        cerr << e.what() << " " << filename << endl << endl;

        filesize = 0;
        loaded = false;


    } catch (...) {
        //if there is an unknown problem an exception is thrown
        cerr << "Unknown exception caught!" << endl;
    }

}

void Resources::subscribeObserver(Observer *o) {
    observers.push_back(o);
}

void Resources::unsubscribeObserver(Observer *o) {
    observers.remove(o);
}

void Resources::notifyObservers() {
    //with this function every time the status of a file changes, every subscribed observer is updated
    for (const auto &itr : observers) {
        MainWindow::resource = this;
        itr->update();
    }
}

bool Resources::isLoaded() const {
    return loaded;
}

const QString &Resources::getFilename() const {
    return filename;
}

double Resources::getFilesize() const {
    return filesize;
}

void Resources::setLoaded(bool loaded) {
    Resources::loaded = loaded;
}

void Resources::setFilename(const QString &filename) {
    Resources::filename = filename;
}

void Resources::setFilesize(int filesize) {
    Resources::filesize = filesize;
}
