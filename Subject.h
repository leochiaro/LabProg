//
// Created by Leonardo on 21/07/2017.
//

#ifndef PROVAQT_SUBJECT_H
#define PROVAQT_SUBJECT_H

#include "Observer.h"

class Subject {
public:
    virtual void subscribeObserver(Observer* observerAddress) = 0; //TODO const?
    virtual void unsubscribeObserver(Observer* observerAddress) = 0;
    virtual void notifyObservers(int filesize, QString filename) const = 0;
};


#endif //PROVAQT_SUBJECT_H
