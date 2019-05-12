#include "OverallProgress.h"

OverallProgress::OverallProgress(SingleProgress *s, sf::RenderWindow *w) {
    subject = s;
    subject->addObserver(this);
    this->window = w;

    rectangleShape.setPosition(0, 0);
    rectangleShape.setFillColor(sf::Color::Green);
}

OverallProgress::~OverallProgress() {
    subject->removeObserver(this);
}

void OverallProgress::update(sf::RectangleShape &rs, int count) {

    rectangleShape.setSize(sf::Vector2f(count * 10, 10));

    window->pollEvent(event);
    if (event.type == sf::Event::Closed) {
        //we want to terminate the transfer if we close the window
        subject->removeObserver(this);
    } else {

        //rendering
        window->clear();

        window->draw(rectangleShape);
        window->draw(rs);

        window->display();
    }
}
