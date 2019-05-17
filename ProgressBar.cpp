#include <utility>

#include "ProgressBar.h"

ProgressBar::ProgressBar(FileTransfer *s, sf::RenderWindow *w, std::string type,
                         unsigned int x, unsigned int y, sf::Color color) :
        window(w), subject(s), type(std::move(type)) {

    subject->addObserver(this);

    rectangleShape.setPosition(sf::Vector2f(x, y));
    rectangleShape.setFillColor(color);
}


ProgressBar::~ProgressBar() {
    subject->removeObserver(this);
}


void ProgressBar::update() {

    if (type == "overall") {
        rectangleShape.setSize(sf::Vector2f(subject->getNumFilesTransferred() * 10, 10));
    }

    if (type == "single") {
        rectangleShape.setPosition(sf::Vector2f(0, 20));
        rectangleShape.setSize(sf::Vector2f(300, 30));
        rectangleShape.setFillColor(sf::Color::Black);

        window->draw(rectangleShape);

        rectangleShape.setFillColor(sf::Color::Green);
        rectangleShape.setSize(sf::Vector2f(subject->getBytesTransferred(), 10));
    }

    window->draw(rectangleShape);
    window->display();
}