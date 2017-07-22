//
// Created by Leonardo on 21/07/2017.
//

#ifndef PROVAQT_OBSERVER_H
#define PROVAQT_OBSERVER_H

class Observer {
public:
    virtual ~Observer() {}

    virtual void update(int filesize, QString filename) = 0;

    //TODO attach/detach
    /*
    potrebbero servire per annullare temporanemente l'aggancio
    virtual void attach() = 0;
    virtual void detach() = 0;
    */

};

#endif //PROVAQT_OBSERVER_H
