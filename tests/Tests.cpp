//
// Created by Leonardo on 01/09/2017.
//

#include <QtTest/QtTest>
#include "../Resource.h"
#include "../MainWindow.h"

class Tests: public QObject {
Q_OBJECT
private slots:
    void updateProgressBar();
    void resourceConstructor();
    void getResource();
    void loadResourceThrow();
};

void Tests::updateProgressBar() {
    vector<Resource> resources;
    Resource::getResources(&resources);

    vector<Resource*> resourcesAddresses(resources.size());
    for(int i = 0; i<resources.size(); i++){
        resourcesAddresses[i] = &resources[i];
    }

    MainWindow mainWindow(Resource::totdim, resourcesAddresses);

    int barValue=0;

    QCOMPARE(mainWindow.getProgressBar()->value(),barValue);

    for (int i=0;i<resourcesAddresses.size();i++) {
        resourcesAddresses[i]->notifyObservers();
        barValue += floor(((resourcesAddresses[i]->getFilesize() * 100) / mainWindow.getTotdim()) + 0.5);
        QCOMPARE(mainWindow.getProgressBar()->value(), barValue);
    }

}

void Tests::resourceConstructor()
{
    Resource a("filename");
    QCOMPARE(a.getFilename(),"filename");
    QCOMPARE(a.isLoaded(),false);
}

void Tests::getResource() {
    Resource::totdim = 0;
    vector<Resource> resources;
    Resource::getResources(&resources);
    QCOMPARE(Resource::totdim, resources[0].getFilesize()+resources[1].getFilesize()+resources[2].getFilesize()+resources[3].getFilesize());

    for(int i=0;i<resources.size();i++) {
        if(i!=2)
            QCOMPARE(resources[i].isLoaded(), true);
        else
            QCOMPARE(resources[i].isLoaded(), false);
    }
}

void Tests::loadResourceThrow() {
    Resource a("filename");
    QVERIFY_EXCEPTION_THROWN(a.loadResource(),runtime_error);
}

QTEST_MAIN(Tests)
#include "../cmake-build-debug/Tests.moc"