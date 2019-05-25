#include "gtest/gtest.h"
#include "../FileTransfer.h"
#include "SFML/Graphics.hpp"


class FileTransferSuite : public ::testing::Test {

protected:
    FileTransfer *fileTransfer;
    sf::RenderWindow *window;

    virtual void SetUp() {
        fileTransfer = new FileTransfer("testSource", "testDest");
        window = new sf::RenderWindow(sf::VideoMode(300, 300), "Testing", sf::Style::None);
    }

    virtual void TearDown() {
        delete fileTransfer;
        delete window;
    }
};


TEST_F(FileTransferSuite, Constructor) {
    EXPECT_EQ(0, fileTransfer->getBytesTransferred());
    EXPECT_EQ(0, fileTransfer->getNumFilesTransferred());
    ASSERT_EQ("", fileTransfer->getFilesTransferred());
    ASSERT_EQ(4, fileTransfer->getFilesSize());

}

TEST_F(FileTransferSuite, Transfer) {

    bool finished;
    finished = fileTransfer->Transfer(*window, fileTransfer->getSourceLocation(), fileTransfer->getDestLocation());

    if (fileTransfer->getNumFilesTransferred() < 4)
        EXPECT_EQ(false, finished);

}

TEST_F(FileTransferSuite, stringFilesTransferred) {

    ASSERT_EQ("", fileTransfer->getFilesTransferred());
    fileTransfer->Transfer(*window, fileTransfer->getSourceLocation(), fileTransfer->getDestLocation());
    std::cout << fileTransfer->getFilesTransferred();
}