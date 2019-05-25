#ifndef BAR_SINGLEPROGRESS_H
#define BAR_SINGLEPROGRESS_H

#include <list>
#include <filesystem>
#include <fstream>

#include "SFML/Graphics.hpp"
#include "Subject.h"

namespace fs = std::filesystem;

//this is used as concrete subject to transfer the files
//from a directory to another one

class FileTransfer : public Subject {

public:
    explicit FileTransfer(const std::string &directoryLocation, std::string targetLocation);

    virtual void addObserver(Observer *o) override;

    virtual void removeObserver(Observer *o) override;

    virtual void notify() override;

    bool Transfer(sf::RenderWindow &window, const std::string &sourcePath, const std::string &destPath);

    virtual ~FileTransfer() {}

    //getters
    const std::string &getFilesTransferred() const;

    const unsigned long getFilesSize() const;

    const int getNumFilesTransferred() const;

    const int getBytesTransferred() const;

    const std::vector<std::pair<std::string, int>>::iterator &getFileTransferring() const;

    const std::string &getSourceLocation() const;

    const std::string &getDestLocation() const;

    const std::list<Observer *> &getObs() const;

    //setters
    void setFilesInfos(const std::vector<std::pair<std::string, int>> &filesInfos);

    void setSourceLocation(const std::string &sourceLocation);

    void setDestLocation(const std::string &destLocation);

    void setFilesTransferred(const std::string &filesTransferred);

    void setNumFilesTransferred(int numFilesTransferred);

    void setBytesTransferred(int bytesTransferred);


private:
    void scanDirectory(const std::string &directoryLocation);

private:
    std::list<Observer *> obs;
    std::vector<std::pair<std::string, int>> filesInfos;
    std::vector<std::pair<std::string, int>>::iterator file;
    std::string sourceLocation;
    std::string destLocation;
    std::string filesTransferred;
    int numFilesTransferred;
    int bytesTransferred;
};


#endif //BAR_SINGLEPROGRESS_H