#include <SFML/Graphics.hpp>
#include "mainMenu.h"

MainMenu::MainMenu(sf::RenderWindow *window)
{
    this->window = window;
    value = 0;

    if(!image.loadFromFile("img/mainMenu_buttons.png"))
        value = -1;
    if(!value)
    {
        for(int i = 0; i <3; i++)
        {
            texture[i].loadFromImage(image, sf::IntRect(0, 250*i, 700, 250));
            texture[i].setSmooth(true);
            button[i].setTexture(texture[i]);
            button[i].setOrigin( button[i].getGlobalBounds().width/2, button[i].getGlobalBounds().height/2 );
            button[i].scale(sf::Vector2f(0.4, 0.4));
            button[i].setPosition( sf::Vector2f( window->getSize().x/2, (window->getSize().y/2)+(120*i) ) );
        }
    }
}

int MainMenu::run()
{
    while(window->isOpen() && !value)
    {
        //START------------------
        //CALL FUNCTIONS---------
        input();
        //CHECK COLLISIONS-------
        sf::Vector2i mouse = sf::Mouse::getPosition(*window);
        for(int i = 0; i<3; i++)
            if( sf::Mouse::isButtonPressed(sf::Mouse::Left) && button[i].getGlobalBounds().contains(mouse.x, mouse.y) )
                value = i+1;



        //DRAW-------------------
        window->clear(sf::Color(73, 33, 33));
        for(int i = 0; i < 3; i++)
            window->draw(button[i]);

        window->display();
    }
    return value;
}

void MainMenu::update(sf::RenderWindow *window )
{
    this->window = window;
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
