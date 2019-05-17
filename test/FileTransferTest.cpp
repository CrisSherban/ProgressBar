#include "gtest/gtest.h"
#include "../FileTransfer.h"
#include "SFML/Graphics.hpp"


TEST(FileTransfer, Constructor) {
    FileTransfer fileTransfer("/...");
    EXPECT_EQ(0, fileTransfer.getBytesTransferred());
    EXPECT_EQ(0, fileTransfer.getNumFilesTransferred());
    ASSERT_EQ("", fileTransfer.getFilesTransferred());
    ASSERT_EQ(30, fileTransfer.getFileNamesSize());
}


//this test is slow due to the sleep in Transfer method
TEST(FileTransfer, Transfer) {

    FileTransfer fileTransfer("/...");
    sf::RenderWindow window(sf::VideoMode(10, 10), "");

    bool finished;
    finished = fileTransfer.Transfer("/...", window);

    if (fileTransfer.getNumFilesTransferred() < 30)
        EXPECT_EQ(false, finished);
}
