
#include <SFML/Graphics.hpp>
#include <iostream>

#include "mainMenu.h"

sf::RenderWindow *window;
sf::ContextSettings settings;


int main()
{
    settings.antialiasingLevel = 8;
    window = new sf::RenderWindow( sf::VideoMode(1280, 720, 32), "Ships", sf::Style::Close | sf::Style::Titlebar, settings );
    window->setFramerateLimit(60);

    MainMenu mainMenu(window);

    switch(mainMenu.run())
    {
    case 1:
        std::cout << "Start" << std::endl;
        break;
    case 2:
        std::cout << "Something" << std::endl;
        break;
    case 3:
        std::cout << "Exit" << std::endl;
        window->close();
        break;
    }


    return 0;
}


