#include <iostream>
#include <dirent.h>
#include <list>
#include <cstdio>
#include <iostream>
#include <QVBoxLayout>
#include <QPushButton>
#include <QApplication>
#include "MainWindow.h"
#include "Resources.h"

using namespace std;

int main(int argc, char *argv[]) {
    //http://www.devx.com/cplus/10MinuteSolution/26748/0/page/2

    QApplication app(argc, argv);

    //controllare il contenuto della cartella
    DIR *directory;
    struct dirent *resource;

    directory=opendir("resources"); //"." refers to the current dir
    //TODO se opendir ritorna NULL c'è un errore (eccezione e messaggio a testo)

    vector<Resources*> resourcesAddresses;

    char* filename;
    FILE* file;
    int filesize;
    int totfilesize=0;

    errno=0;
    resource=readdir(directory);//search the first file in the directory

    if (errno){
        //TODO errore nella lettura della cartella
    }

    if(resource==nullptr) {
        //TODO lancia eccezione, impossibile leggere cartella
    }

    while (resource!=nullptr){//TODO eccezioni sul funzionamento delle funzioni dei file
        filename = resource->d_name;
        file  = fopen(filename, "r");
        fseek(file, 0, SEEK_END);
        filesize = static_cast<int>(ftell(file));
        totfilesize+=filesize;
        Resources fileinfo;
        fileinfo.setFilesize(filesize);
        fileinfo.setFilename(filename);
        resourcesAddresses.push_back(&fileinfo);
        fclose(file);

        resource=readdir(directory);//search the next file in the directory
        if (errno){
            //TODO errore nella lettura della cartella
        }
    }

    closedir(directory); //chiudo lettura cartella

    //chiama main window
    MainWindow mainWindow(totfilesize, resourcesAddresses);
    mainWindow.show();

    return 0;
}