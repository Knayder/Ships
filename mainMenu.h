


class MainMenu
{
public:

    sf::RenderWindow *window;

    int value;

    sf::Image image;
    sf::Texture texture[3];
    sf::Sprite button[3];


    MainMenu( sf::RenderWindow *window );

    int run();

    void update( sf::RenderWindow *window );

    void input();
};

