//Progress bar that simulates a file transfer
//using Design Pattern Observer PUSH

#include <iostream>
#include "SFML/Graphics.hpp"

#include "FileTransfer.h"
#include "ProgressBar.h"

int main() {

    sf::RenderWindow window(sf::VideoMode(300, 30), "", sf::Style::Close);
    sf::Font DroidSans;
    sf::Text text;
    bool transferred;

    //centers the screen
    auto desktop = sf::VideoMode::getDesktopMode();
    window.setPosition(sf::Vector2i(desktop.width / 2 - window.getSize().x / 2,
                                    desktop.height / 2 - window.getSize().y / 2));

    if (!DroidSans.loadFromFile("DroidSans.ttf"))
        std::cout << ("Font can't load") << std::endl;

    text.setFont(DroidSans);
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::Green);

    FileTransfer fileTransfer("/home/Project", &window);
    ProgressBar overall(&fileTransfer, &window, "overall");
    ProgressBar single(&fileTransfer, &window, "single");


    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {

            window.setTitle("Transfer");
            text.setString("Press Enter to transfer directory");

            window.clear();
            window.draw(text);
            window.display();

            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed)
                if (event.key.code == sf::Keyboard::Enter) {
                    window.setTitle("Progress Bar");

                    transferred = fileTransfer.TransferFile("/home/Important");
                    if (!transferred) {
                        window.setTitle("");
                        text.setString("Transfer canceled!");
                        window.clear();
                        window.draw(text);
                        window.display();
                        sf::sleep(sf::seconds(2));
                        window.close();
                        return 1;
                    }

                    window.setTitle("");
                    text.setString("Transfer completed!");

                    window.clear();
                    window.draw(text);
                    window.display();
                    sf::sleep(sf::seconds(2));
                    return 0;
                }
        }
    }
    return 0;
}