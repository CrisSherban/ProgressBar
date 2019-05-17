#include <iostream>

#include "FileTransfer.h"

FileTransfer::FileTransfer(std::string directoryLocation) : directoryName(std::move(directoryLocation)),
                                                            bytesTransferred(0), numFilesTransferred(0),
                                                            filesTransferred("") {

    //default size of each file
    fileSize = 300;

    //reads files in the directory
    //by default the directory has 30 files
    for (int i = 0; i < 30; i++)
        fileNames.emplace_back(std::to_string(rand() % 1000) + ".bin");
    it = fileNames.begin();


}

void FileTransfer::addObserver(Observer *o) {
    obs.emplace_back(o);
}

void FileTransfer::removeObserver(Observer *o) {
    obs.remove(o);
}

void FileTransfer::notify() {
    for (auto o : obs)
        o->update();
};

bool FileTransfer::Transfer(const std::string &location, sf::RenderWindow &window) {

    //simulates the file transfer
    //10 bytes at a time
    for (int j = 0; j < fileNames.size(); j++, ++it) {
        bytesTransferred = 0;
        for (int i = 0; i < fileSize / 10; i++) {
            //this 'if' explains why progress bars get stuck at the end   \ (•◡•) /
            if (i > 27)
                sf::sleep(sf::seconds(0.07));
            else
                sf::sleep(sf::seconds(static_cast<float>(rand() % 10) / 250));
            bytesTransferred += 10;
            notify();
        }


        if (j % 10 == 0)
            filesTransferred.append("\n");
        filesTransferred.append((*it) + " ");

        numFilesTransferred++;
        notify();

        //handles the possibility of closing the window during the transfer
        sf::Event abort;
        while (window.pollEvent(abort)) {
            if (abort.type == sf::Event::Closed) {
                return false;
            }
        }
    }
    return true;
}

const unsigned long FileTransfer::getFileNamesSize() const {
    return fileNames.size();
}

const int FileTransfer::getNumFilesTransferred() const {
    return numFilesTransferred;
}

const std::string &FileTransfer::getFilesTransferred() const {
    return filesTransferred;
}

const int FileTransfer::getBytesTransferred() const {
    return bytesTransferred;
}

const std::string &FileTransfer::getFileTransferring() const {
    return *it;
}
