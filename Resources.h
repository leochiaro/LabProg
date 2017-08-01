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
    virtual void notifyObservers(int filesize, QString filename) const override ;

    bool isLoaded() const;
    void setLoaded(bool loaded);

    const QString &getFilename() const;
    void setFilename(const QString &filename);

    int getFilesize() const;
    void setFilesize(int filesize);

private:
    QString filename;
    int filesize;
    list<Observer *> observers;
    bool loaded=false;
};

#endif //PROVAQT_RESOURCES_H
