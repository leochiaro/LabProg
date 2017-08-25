//
// Created by Leonardo on 22/07/2017.
//

#ifndef PROVAQT_RESOURCES_H
#define PROVAQT_RESOURCES_H

#include <list>
#include <QTextEdit>
#include "Subject.h"

using namespace std;

class Resource : public Subject {
public:
    Resource(const char *filename, bool loaded=false);

    virtual void subscribeObserver(Observer *o) override;

    virtual void unsubscribeObserver(Observer *o) override;

    virtual void notifyObservers() override;

    bool isLoaded() const;

    void setLoaded(bool loaded);

    const char *getFilename() const;

    void setFilename(const char *filename);

    double getFilesize() const;

    void setFilesize(int filesize);

    //static methods to get and load resources
    static void getResources(vector<Resource> * resources);
    void loadResource() throw(runtime_error);

    //static variable to know the total size of the resources
    static double totdim;

private:
    const char* filename;//path of the resources
    double filesize;//size of the resource
    list<Observer *> observers;//list that contains the addresses of the subscribed observer
    bool loaded;//boolean variables to know if the resource is loaded

    FILE *resource;//FILE pointer to have access about the resource info like the size
};

#endif //PROVAQT_RESOURCES_H
