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
int Resource::totRisources = 0;
double Resource::totdim = 0;

Resource::Resource(const char *filename, double filesize) : filename(filename), filesize(filesize) {
    Resource::totRisources++;//increment the number of resources to load
    Resource::totdim+=filesize;
    loaded = false;
}

void Resource::subscribeObserver(Observer *o) {
    observers.push_back(o);
}

void Resource::unsubscribeObserver(Observer *o) {
    observers.remove(o);
}

void Resource::notifyObservers() {
    //with this function every time the status of a file changes, every subscribed observer is updated
    for (const auto &itr : observers) {
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
    Resource a("C:\\Users\\leona\\CLionProjects\\LabProgram\\resources\\first_file.txt", 10);
    Resource b("C:\\Users\\leona\\CLionProjects\\LabProgram\\resources\\second_file.txt", 20);
    Resource c("C:\\Users\\leona\\CLionProjects\\LabProgram\\resources\\third_file.txt", 30);
    Resource d("C:\\Users\\leona\\CLionProjects\\LabProgram\\resources\\fourth_file.txt", 40);


    //push back all the addresses in the vector
    resources->push_back(a);
    resources->push_back(b);
    resources->push_back(c);
    resources->push_back(d);


    for(int i=0; i<resources->size(); i++) {
        try {
            (*resources)[i].loadResource();
        }
        catch (runtime_error e) {
            //if something goes wrong in the previous statement, an exception is thrown

            cerr << e.what() <<" has not been loaded!"<< endl << endl;

            Resource::totdim-=(*resources)[i].filesize;
            (*resources)[i].loaded = false;


        } catch (...) {
            //if there is an unknown problem an exception is thrown
            cerr << "Unknown exception caught!" << endl;
        }

    }
}

void Resource::loadResource() throw(runtime_error) {

    this->setLoaded(false);

    if(!this->loaded){
        throw runtime_error(this->getFilename());
    }

    /*open in read mode the resource. fopen return a FILE pointer then used to know the file size,
    if return nullptr, this means that file doesn't exist*/
    /*resource = fopen(filename, "r");
    fseek(resource, 0, SEEK_END);
    if (resource == nullptr) {
        throw runtime_error("File not found.");
    }
    filesize = ftell(resource);//ftell return the file size
    Resource::totdim += filesize;//increment the total size of the resources

    if (fclose(resource) == 0)
        fclose(resource);
    else {
        throw runtime_error("Error closing file.");
    }
    loaded = true;*/
}

const char *Resource::getFilename() const {
    return filename;
}

void Resource::setFilename(const char *filename) {
    Resource::filename = filename;
}
