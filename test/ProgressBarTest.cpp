#include "gtest/gtest.h"
#include "../ProgressBar.h"
#include "SFML/Graphics.hpp"

TEST(ProgressBarSuite, Constructor) {

    sf::RenderWindow window(sf::VideoMode(300, 40), "Testing", sf::Style::None);

    FileTransfer fileTransfer("testSource", "testDest");
    ProgressBar pb(&fileTransfer, &window, "overall", 0, 0);

    //obs is a list of pointers to Observers,
    //with the dereference of the iterator to the first element we get an address
    //so it has to be compared with the address of the progress bar that the constructor adds
    ASSERT_EQ(*fileTransfer.getObs().begin(), &pb);
}

TEST(ProgressBarSuite, Update) {

    sf::RenderWindow window(sf::VideoMode(300, 40), "Testing", sf::Style::None);

    FileTransfer fileTransfer("testSource", "testDest");
    ProgressBar pb(&fileTransfer, &window, "overall", 0, 0);
    fileTransfer.Transfer(window, "testSource", "testDest");

    ASSERT_EQ((300 * 4) / (fileTransfer.getFilesSize()), pb.getRectangleShape().getSize().x);
}