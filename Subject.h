//
// Created by Leonardo on 21/07/2017.
//

#ifndef PROVAQT_SUBJECT_H
#define PROVAQT_SUBJECT_H

#include "Observer.h"

class Subject {
public:
    virtual void subscribe(Observer* observerAddress) = 0;
    virtual void unsubscribe(Observer* observerAddress) = 0;
    virtual void notify() = 0;
};


#endif //PROVAQT_SUBJECT_H
