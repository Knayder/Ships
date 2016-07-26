#include <SFML/Graphics.hpp>
#include "mainMenu.h"

MainMenu::MainMenu(sf::RenderWindow *window)
{
    this->window = window;
    value = 0;
}

int MainMenu::run()
{
    while(window->isOpen() && !value)
    {
        input();
        window->clear(sf::Color::Red);
        window->display();
    }
    return value;
}

void MainMenu::input()
{
    sf::Event event;
    while( window->pollEvent(event) )
    {
        if(event.type == sf::Event::Closed)
            value = 3;
    }
}
