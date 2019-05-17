#ifndef BAR_TRANSFERRINGFILE_H
#define BAR_TRANSFERRINGFILE_H


#include "Observer.h"
#include "FileTransfer.h"

//this is an observer that displays the current transferring file name and extension
class Text : public Observer {

public:
    Text(FileTransfer *subject, sf::RenderWindow *window, sf::Font &font, sf::Color color,
         unsigned int x = 10, unsigned int y = 10);

    virtual void update() override;

    virtual ~Text();

private:
    FileTransfer *subject;
    sf::RenderWindow *window;
    sf::RectangleShape rectangleShape;
    sf::Text text;
};


#endif //BAR_TRANSFERRINGFILE_H
