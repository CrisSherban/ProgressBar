#ifndef BAR_DIALOGBOX_H
#define BAR_DIALOGBOX_H

#include <iostream>

#include "SFML/Graphics.hpp"
#include "FileTransfer.h"

class DialogBox {
public:
    explicit DialogBox(FileTransfer *fileTransfer, unsigned int width = 300, unsigned int height = 40);

    int init();

    int run();

    int canceled();

    sf::RenderWindow &getWindow();

    sf::Font &getFont();

    void printTransferredFiles();

    virtual ~DialogBox() {}

private:
    FileTransfer *fileTransfer;
    sf::RenderWindow window;
    sf::Font DroidSans;
    sf::Text text;
};


#endif //BAR_DIALOGBOX_H
