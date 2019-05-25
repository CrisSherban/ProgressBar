#include "FileTransfer.h"

FileTransfer::FileTransfer(const std::string &directoryLocation, std::string targetLocation) :
        bytesTransferred(0), numFilesTransferred(0), destLocation(std::move(targetLocation)),
        filesTransferred(""), sourceLocation(directoryLocation) {

    //reads files infos in the directory
    scanDirectory(directoryLocation);
    file = filesInfos.begin();
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
}

bool FileTransfer::Transfer(sf::RenderWindow &window, const std::string &sourcePath, const std::string &destPath) {

    fs::create_directory(destPath);

    for (const auto &entry : std::filesystem::directory_iterator(sourcePath))
        if (entry.is_directory()) {

            //recursive call to open every subdirectory if present
            Transfer(window, entry.path().string(), destPath + "/" + entry.path().filename().string());
        } else {

            bytesTransferred = 0;

            std::ifstream source(entry.path(), std::ios::binary);
            std::ofstream dest(destPath + "/" + entry.path().filename().string(), std::ios::binary);

            // setting file size
            int size = file->second;

            // reading source and filling buffer
            std::vector<char> buffer((std::istreambuf_iterator<char>(source)), std::istreambuf_iterator<char>());
            //it's not the best way because it has to save a buffer that
            //has a size equal to the number of bytes of the file, so it's not good for big files

            //writes to file 1 byte at a time
            for (size_t i = 0; i < size; i++) {
                dest.write(static_cast<char *> (&buffer[i]), 1);

                //makes debug easier
                sf::sleep(sf::microseconds(1));

                bytesTransferred++;

                //handles the possibility of closing the window during the transfer
                sf::Event abort;
                while (window.pollEvent(abort))
                    if (abort.type == sf::Event::Closed)
                        return false;

                notify();
            }

            // clean up
            source.close();
            dest.close();

            //updates the files transferred up until this iteration
            filesTransferred.append((file->first) + "\n");
            numFilesTransferred++;
            notify();
            ++file;

        }
    return true;
}

void FileTransfer::scanDirectory(const std::string &directoryLocation) {

    for (const auto &entry : fs::directory_iterator(directoryLocation))
        if (entry.is_directory())
            scanDirectory(entry.path());
        else
            filesInfos.emplace_back(entry.path().filename(), entry.file_size());

}

const unsigned long FileTransfer::getFilesSize() const {
    return filesInfos.size();
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

const std::vector<std::pair<std::string, int>>::iterator &FileTransfer::getFileTransferring() const {
    return file;
}

const std::string &FileTransfer::getSourceLocation() const {
    return sourceLocation;
}

const std::string &FileTransfer::getDestLocation() const {
    return destLocation;
}

void FileTransfer::setFilesInfos(const std::vector<std::pair<std::string, int>> &filesInfos) {
    FileTransfer::filesInfos = filesInfos;
}

void FileTransfer::setSourceLocation(const std::string &sourceLocation) {
    FileTransfer::sourceLocation = sourceLocation;
}

void FileTransfer::setDestLocation(const std::string &destLocation) {
    FileTransfer::destLocation = destLocation;
}

void FileTransfer::setFilesTransferred(const std::string &filesTransferred) {
    FileTransfer::filesTransferred = filesTransferred;
}

void FileTransfer::setNumFilesTransferred(int numFilesTransferred) {
    FileTransfer::numFilesTransferred = numFilesTransferred;
}

void FileTransfer::setBytesTransferred(int bytesTransferred) {
    FileTransfer::bytesTransferred = bytesTransferred;
}

const std::list<Observer *> &FileTransfer::getObs() const {
    return obs;
}

