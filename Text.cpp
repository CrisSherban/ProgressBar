#include "Text.h"

Text::Text(FileTransfer *subject, sf::RenderWindow *window, sf::Font &font,
           sf::Color color, unsigned int x, unsigned int y) : subject(subject), window(window) {

    subject->addObserver(this);
    text.setPosition(x, y);
    text.setFillColor(color);
    text.setCharacterSize(14);
    text.setFont(font);
    rectangleShape.setPosition(sf::Vector2f(0, 10));
    rectangleShape.setSize(sf::Vector2f(300, 20));
    rectangleShape.setFillColor(sf::Color::Black);

}

void Text::update() {

    text.setString(subject->getFileTransferring()->first);
    window->draw(rectangleShape);
    window->draw(text);
}

Text::~Text() {
    subject->removeObserver(this);
}
