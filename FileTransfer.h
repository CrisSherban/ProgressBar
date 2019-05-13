#ifndef BAR_SINGLEPROGRESS_H
#define BAR_SINGLEPROGRESS_H

#include <list>
#include "Subject.h"
#include "SFML/Graphics.hpp"


//this is used as concrete subject

//usually a directory contains multiple files
//FileTransfer represents the transfer progress of a file of the directory

class FileTransfer : public Subject {

public:
    explicit FileTransfer(std::string directoryLocation, sf::RenderWindow *w);

    virtual void addObserver(Observer *o) override;

    virtual void removeObserver(Observer *o) override;

    virtual void notify() override;

    bool TransferFile(std::string location);

    virtual ~FileTransfer() {}

private:
    std::list<Observer *> obs;
    std::list<std::string> fileNames;
    std::string directoryName;
    sf::RenderWindow *window;
    sf::Event event;
    int filesTransferred;
    int bytesTransferred;
    int fileSize;
    bool canceled;
};


#endif //BAR_SINGLEPROGRESS_H