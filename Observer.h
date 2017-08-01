//
// Created by Leonardo on 21/07/2017.
//

#ifndef PROVAQT_OBSERVER_H
#define PROVAQT_OBSERVER_H

class Observer {
public:
    virtual ~Observer() {}

    virtual void update(bool loaded, double filesize, QString filename) = 0;
};

#endif //PROVAQT_OBSERVER_H
