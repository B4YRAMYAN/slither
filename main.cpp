#include <iostream>
#include <SFML/Graphics.hpp>
#include <random>
#include <algorithm>
#include <vector>
#include "snake.h"

const int WIDTH = 1600;
const int HIGHT = 900;

int xfrt;
int yfrt;

bool gameOver;

snake Snake;
void setup() {
    gameOver = false;

    xfrt = rand() % WIDTH;
    yfrt = rand() % HIGHT;

}

void logic() {
    Snake.SnakeIsGoingToCoursor();
}



int main()
{   
    sf::RenderWindow window(sf::VideoMode(WIDTH, HIGHT), "Snake!");
    window.setPosition(sf::Vector2i(0, 0));
    sf::Event event;
    setup();
    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear();
        logic();
        for (int i = 0; i < Snake.getSize(); ++i) {
            window.draw(Snake.getSnakeShape(i));
        }
        window.setMouseCursorVisible(true);
        window.display();

    }

    return 0;
}