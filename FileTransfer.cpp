#include <iostream>
#include "FileTransfer.h"

FileTransfer::FileTransfer(std::string directoryLocation) : directoryName(std::move(directoryLocation)),
                                                            bytesTransferred(0), filesTransferred(0) {

    //default size of each file
    fileSize = 300;

    //reads files in the directory
    //by default the directory has 30 files
    for (int i = 0; i < 30; i++)
        fileNames.emplace_back(std::to_string(rand() % 1000) + ".bin");
}

void FileTransfer::addObserver(Observer *o) {
    obs.emplace_back(o);
}

void FileTransfer::removeObserver(Observer *o) {
    obs.remove(o);
}

void FileTransfer::notify() {
    for (auto o : obs)
        o->update(filesTransferred, bytesTransferred);
};

void FileTransfer::Transfer(std::string location) {

    //simulates the file transfer
    //10 bytes at a time
    bytesTransferred = 0;
    this->location = std::move(location);
    for (int i = 0; i < fileSize / 10; i++) {
        //this 'if' explains why progress bars get stuck at the end   \ (•◡•) /
        if (i > 27)
            sf::sleep(sf::seconds(0.07));
        else
            sf::sleep(sf::seconds(static_cast<float >(rand() % 10) / 250));
        bytesTransferred += 10;
        notify();
    }
    filesTransferred++;
    notify();
}


const unsigned long FileTransfer::getFileNamesSize() const {
    return fileNames.size();
}

int FileTransfer::getFilesTransferred() const {
    return filesTransferred;
}

void FileTransfer::Transferred() const {
    std::cout << "Files transferred: " << std::endl;
    int index = 0;
    auto it = fileNames.begin();

    while (index < filesTransferred) {
        std::cout << *it << " ";
        index++;
        it++;
        if (index % 10 == 0)
            std::cout << std::endl;
    }
}
