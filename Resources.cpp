//
// Created by Leonardo on 22/07/2017.
//

#include "Resources.h"
#include <QTime>
#include <QtCore/QCoreApplication>



void Resources::subscribeObserver(Observer *o) {
    observers.push_back(o);
}

void Resources::unsubscribeObserver(Observer *o) {
    observers.remove(o);
}

void Resources::notifyObservers(int filesize, QString filename) const {
    for (const auto &itr : observers)
        itr->update(filesize, filename);
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

void Resources::setLoaded(bool loaded) {
    Resources::loaded = loaded;
}

void Resources::setFilename(const QString &filename) {
    Resources::filename = filename;
}

void Resources::setFilesize(int filesize) {
    Resources::filesize = filesize;
}