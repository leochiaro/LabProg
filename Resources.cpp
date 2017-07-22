//
// Created by Leonardo on 22/07/2017.
//

#include "Resources.h"

void Resources::subscribeObserver(Observer *o) {
    observers.push_back(o);
}

void Resources::unsubscribeObserver(Observer *o) {
    observers.remove(o);
}

void Resources::notifyObservers() const {
    for (const auto &itr : observers) {
        itr->update();
    }
}

bool Resources::isLoaded() const {
    return loaded;
}

const QString &Resources::getFilename() const {
    return filename;
}

int Resources::getFilesize() const {
    return filesize;
}
