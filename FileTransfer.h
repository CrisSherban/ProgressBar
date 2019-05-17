#ifndef BAR_SINGLEPROGRESS_H
#define BAR_SINGLEPROGRESS_H

#include <list>

#include "SFML/Graphics.hpp"
#include "Subject.h"

//this is used as concrete subject to transfer the files
//from a directory to another one

class FileTransfer : public Subject {

public:

    explicit FileTransfer(std::string directoryLocation);

    virtual void addObserver(Observer *o) override;

    virtual void removeObserver(Observer *o) override;

    virtual void notify() override;

    bool Transfer(const std::string &location, sf::RenderWindow &window);

    virtual ~FileTransfer() {}


    //getters
    const std::string &getFilesTransferred() const;

    const unsigned long getFileNamesSize() const;

    const int getNumFilesTransferred() const;

    const int getBytesTransferred() const;

    const std::string &getFileTransferring() const;


private:
    std::list<Observer *> obs;
    std::list<std::string> fileNames;
    std::list<std::string>::iterator it;
    std::string directoryName;
    std::string location;
    std::string filesTransferred;
    int numFilesTransferred;
    int bytesTransferred;

private:
    int fileSize;
};


#endif //BAR_SINGLEPROGRESS_H