//
// Created by Leonardo on 22/07/2017.
//

#include <QTime>
#include <QtCore/QCoreApplication>
#include <cstdio>
#include <iostream>
#include "Resource.h"
#include "MainWindow.h"

//initialization of static variables
double Resource::totdim = 0;

Resource::Resource(const char *filename, bool loaded) : filename(filename), loaded(loaded) {}

void Resource::subscribeObserver(Observer *o) {
    observers.push_back(o);
}

void Resource::unsubscribeObserver(Observer *o) {
    observers.remove(o);
}

void Resource::notifyObservers() {
    //with this function every time the status of a file changes, every subscribed observer is updated
    for (const auto &itr : observers) {
        if(dynamic_cast<MainWindow*>(itr))
            MainWindow::resource = this;
        itr->update();
    }
}

bool Resource::isLoaded() const {
    return loaded;
}

double Resource::getFilesize() const {
    return filesize;
}

void Resource::setLoaded(bool loaded) {
    Resource::loaded = loaded;
}

void Resource::setFilesize(int filesize) {
    Resource::filesize = filesize;
}

void Resource::getResources(vector<Resource> * resources) {
    //create resource objects
    Resource a("C:\\Users\\User\\CLionProjects\\LabProgram\\LabProg\\resources\\first_file.txt");
    Resource b("C:\\Users\\User\\CLionProjects\\LabProgram\\LabProg\\resources\\second_file.txt");
    Resource c("C:\\Users\\User\\CLionProjects\\LabProgram\\LabProg\\resources\\third_file.txt");
    Resource d("C:\\Users\\User\\CLionProjects\\LabProgram\\LabProg\\resources\\fourth_file.txt");


    //push back all the addresses in the vector
    resources->push_back(a);
    resources->push_back(b);
    resources->push_back(c);
    resources->push_back(d);


    for(int i=0; i<resources->size(); i++) {
        try {
            (*resources)[i].loadResource();
        }
        catch (runtime_error &e) {
            //if something goes wrong in the previous statement, an exception is thrown

            cerr << e.what() <<(*resources)[i].getFilename()<<endl << endl;
            (*resources)[i].setFilesize(0);
            (*resources)[i].loaded = false;


        } catch (...) {
            //if there is an unknown problem an exception is thrown
            cerr << "Unknown exception caught!" << endl;
            (*resources)[i].setFilesize(0);
            (*resources)[i].loaded = false;
        }

    }
}

void Resource::loadResource() throw(runtime_error) {

    /*open in read mode the resource. fopen return a FILE pointer then used to know the file size,
    if return nullptr, this means that file doesn't exist*/
    resource = fopen(filename, "r");
    fseek(resource, 0, SEEK_END);
    if (resource == nullptr) {
        throw runtime_error("Not loaded: ");
    }
    filesize = ftell(resource);//ftell return the file size
    Resource::totdim += filesize;//increment the total size of the resources

    if (fclose(resource) == 0)
        fclose(resource);
    else {
        throw runtime_error("Error closing: ");
    }
    loaded = true;
}

const char *Resource::getFilename() const {
    return filename;
}

void Resource::setFilename(const char *filename) {
    Resource::filename = filename;
}
