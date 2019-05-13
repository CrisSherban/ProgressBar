#include <utility>

#include "FileTransfer.h"

FileTransfer::FileTransfer(std::string directoryLocation, sf::RenderWindow *w) : directoryName(
        std::move(directoryLocation)), bytesTransferred(0), filesTransferred(0), window(w), canceled(false) {

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

bool FileTransfer::TransferFile(std::string location) {

    //if the window is closed we have to remove the observers and terminate the transfer
    if (!canceled) {
        window->pollEvent(event);
        if (event.type == sf::Event::Closed) {
            obs.clear();
            canceled = true;
        }

        //simulates the file transfer
        //10 bytes at a time
        bytesTransferred = 0;
        for (int i = 0; i < fileSize / 10; i++) {
            //this 'if' explains why progress bars get stuck at the end   \ (•◡•) /
            if (i > 27)
                sf::sleep(sf::seconds(0.07));
            else
                sf::sleep(sf::seconds(static_cast<float >(rand() % 10) / 250));
            bytesTransferred += 10;
            this->notify();
        }

        if (filesTransferred < fileNames.size()) {
            filesTransferred++;
            this->TransferFile(std::move(location)); //transfers the next file
        }
    }
    return !canceled;
}