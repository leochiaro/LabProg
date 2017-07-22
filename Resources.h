//
// Created by Leonardo on 22/07/2017.
//

#ifndef PROVAQT_RESOURCES_H
#define PROVAQT_RESOURCES_H

#include <list>
#include <QTextEdit>
#include "Subject.h"

using namespace std;

class Resources : public Subject{
public:
    Resources(){}

    virtual void subscribeObserver(Observer* o) override ;
    virtual void unsubscribeObserver(Observer* o) override ;
    virtual void notifyObservers() const override ;

    bool isLoaded() const;

    const QString &getFilename() const;

    int getFilesize() const;


private:
    list<Observer *> observers;
    bool loaded;
    QString filename;
    int filesize;

};


#endif //PROVAQT_RESOURCES_H
