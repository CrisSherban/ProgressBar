#include <utility>

#include "ProgressBar.h"

ProgressBar::ProgressBar(FileTransfer *s, sf::RenderWindow *w, std::string type,
                         unsigned int x, unsigned int y, sf::Color color) :
        window(w), subject(s), type(std::move(type)), maxWidth(300), maxHeight(10) {

    subject->addObserver(this);
    rectangleShape.setPosition(sf::Vector2f(x, y));
    rectangleShape.setFillColor(color);
}


ProgressBar::~ProgressBar() {
    subject->removeObserver(this);
}


void ProgressBar::update() {

    if (type == "overall") {
        rectangleShape.setSize(sf::Vector2f((maxWidth * subject->getNumFilesTransferred()) /
                                            subject->getFilesSize(), maxHeight));
    }

    if (type == "single") {
        rectangleShape.setPosition(sf::Vector2f(0, 30));
        rectangleShape.setSize(sf::Vector2f(300, 40));
        rectangleShape.setFillColor(sf::Color::Black);

        window->draw(rectangleShape);

        rectangleShape.setFillColor(sf::Color::Green);
        rectangleShape.setSize(sf::Vector2f((maxWidth * subject->getBytesTransferred())
                                            / subject->getFileTransferring()->second, maxHeight));
    }

    window->draw(rectangleShape);
    window->display();
}

const sf::RectangleShape &ProgressBar::getRectangleShape() const {
    return rectangleShape;
}

const std::string &ProgressBar::getType() const {
    return type;
}

void ProgressBar::setType(const std::string &type) {
    ProgressBar::type = type;
}

unsigned int ProgressBar::getMaxWidth() const {
    return maxWidth;
}

void ProgressBar::setMaxWidth(unsigned int maxWidth) {
    ProgressBar::maxWidth = maxWidth;
}

unsigned int ProgressBar::getMaxHeight() const {
    return maxHeight;
}

void ProgressBar::setMaxHeight(unsigned int maxHeight) {
    ProgressBar::maxHeight = maxHeight;
}
