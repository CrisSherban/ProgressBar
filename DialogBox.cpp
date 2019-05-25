#include "DialogBox.h"

DialogBox::DialogBox(FileTransfer *fileTransfer, unsigned int width, unsigned int height) :
        window(sf::VideoMode(width, height), "", sf::Style::Close), fileTransfer(fileTransfer) {

    text.setFont(DroidSans);
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::Green);

    auto desktop = sf::VideoMode::getDesktopMode();
    window.setPosition(sf::Vector2i(desktop.width / 2 - window.getSize().x / 2,
                                    desktop.height / 2 - window.getSize().y / 2));

    if (!DroidSans.loadFromFile("DroidSans.ttf"))
        throw std::invalid_argument("Font can't load, or not found!");
}

int DialogBox::init() {

    window.setTitle("Transfer");
    text.setString("Press Enter to transfer directory");

    window.clear();
    window.draw(text);
    window.display();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed)
                if (event.key.code == sf::Keyboard::Enter)
                    return run();
        }
    }
    return 0;
}

int DialogBox::run() {

    window.clear();
    window.setTitle("Progress Bar");

    if (fileTransfer->Transfer(window, fileTransfer->getSourceLocation(), fileTransfer->getDestLocation())) {

        window.setTitle("");
        text.setString("Transfer completed!");

        window.clear();
        window.draw(text);
        window.display();

        printTransferredFiles();
        window.close();
        return 0;
    } else
        return canceled();
}

int DialogBox::canceled() {

    window.setTitle("");
    text.setString("Transfer canceled!");

    window.clear();
    window.draw(text);
    window.display();

    printTransferredFiles();
    window.close();
    return 1;
}

void DialogBox::printTransferredFiles() {

    sf::RenderWindow transferredFiles(sf::VideoMode(500, 300), "", sf::Style::Close);
    transferredFiles.setTitle("Transferred Files");

    auto desktop = sf::VideoMode::getDesktopMode();
    transferredFiles.setPosition(sf::Vector2i((desktop.width / 2 - transferredFiles.getSize().x / 2), 0));

    text.setCharacterSize(13);
    text.setString(fileTransfer->getFilesTransferred());

    transferredFiles.clear();
    transferredFiles.draw(text);
    transferredFiles.display();

    while (transferredFiles.isOpen() && window.isOpen()) {
        sf::Event event;
        while (transferredFiles.pollEvent(event) || window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                transferredFiles.close();

    }
}

sf::RenderWindow &DialogBox::getWindow() {
    return window;
}

sf::Font &DialogBox::getFont() {
    return DroidSans;
}

