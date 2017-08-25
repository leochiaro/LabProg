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
    Resource(const char *filename, double filesize);

    virtual void subscribeObserver(Observer *o) override;

    virtual void unsubscribeObserver(Observer *o) override;

    virtual void notifyObservers() override;

    bool isLoaded() const;

    void setLoaded(bool loaded);

    const char *getFilename() const;

    void setFilename(const char *filename);

    double getFilesize() const;

    void setFilesize(int filesize);

    //TODO metodo load
    void loadResource() throw(runtime_error);

    /*static variables to know the number of resource to load (totRisources)
    and to know the total size of the resources*/
    static int totRisources;
    static double totdim;

    static void getResources(vector<Resource> * resources);

private:
    const char* filename;//path of the resources
    double filesize;//size of the resource
    list<Observer *> observers;//list that contains the addresses of the subscribed observer
    bool loaded;//boolean variables to know if the resource is loaded

    FILE *resource;//FILE pointer to have access about the resource info like the size
};

#endif //PROVAQT_RESOURCES_H
