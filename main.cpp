//Progress bar that simulates a file transfer
//using Design Pattern Observer PULL

#include <iostream>

#include "SFML/Graphics.hpp"
#include "FileTransfer.h"
#include "DialogBox.h"
#include "ProgressBar.h"
#include "Text.h"


int main() {

    FileTransfer fileTransfer("/home/cris/Pictures", "/home/cris/Desktop/Project");

    DialogBox dialogBox(&fileTransfer);

    ProgressBar overall(&fileTransfer, &dialogBox.getWindow(), "overall", 0, 0, sf::Color::Green);
    Text currentFile(&fileTransfer, &dialogBox.getWindow(), dialogBox.getFont(), sf::Color::White);
    ProgressBar single(&fileTransfer, &dialogBox.getWindow(), "single", 0, 30, sf::Color::Green);

    return dialogBox.init();
}