#pragma once
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <utility>
#include <vector>
#include "point.h"

class snake{
private:
    std::vector<sf::CircleShape> snakeShapes;
    std::vector<point> snakeCords;
    double speed;
    int thickness;
    void cordAndShapeConnaction() {
        for (int i = 0; i < getSize(); ++i) {
            snakeShapes[i].setPosition(snakeCords[i].x, snakeCords[i].y);
        }
    }
public:
    snake() {
        speed = 0.2;
        thickness = 7;
        for (int i = 250; i >= 0; --i) {
            snakeCords.push_back(point(0, 0));
            snakeShapes.push_back(sf::CircleShape(thickness));
        }
        cordAndShapeConnaction();
    }
    snake(double _speed, int _thickness) {
        speed = _speed;
        thickness = _thickness;
        for (int i = 15; i >= 0; --i) {
            snakeCords.push_back(point(0, 0));
            snakeShapes.push_back(sf::CircleShape(thickness));
        }
        cordAndShapeConnaction();
    }
    snake(const snake& other) {
        for (int i = 0; i < other.getSize(); ++i) {
            snakeCords[i] = other.getSnakePosition(i);
            snakeShapes[i] = other.getSnakeShape(i);
        }
        cordAndShapeConnaction();
    }

    sf::CircleShape getSnakeShape(int pos) const{
        return snakeShapes[pos];
    }
    
    point getSnakePosition(int pos ) const{
        return snakeCords[pos];
    }

    std::size_t getSize() const {
        return snakeCords.size();
    }

    void setSnakeSpeed(double _speed) {
        speed = _speed;
    }

    void setSnakeThickness(int _thickness) {
        thickness = _thickness;
    }

    void SnakeIsGoingToCoursor() {
        for (std::size_t i = getSize() - 1; i > 0;  --i) {
            snakeCords[i] = snakeCords[i - 1];
        }
        sf::Vector2f snakeHead = sf::Vector2f(snakeCords[0].x, snakeCords[0].y);
        sf::Vector2i mousePosition = sf::Mouse::getPosition();

        double distanceOfMouseAndSnakeHead = sqrt(pow(snakeHead.x - mousePosition.x, 2) +
            pow(snakeHead.y - mousePosition.y, 2));

        snakeCords[0].x -= static_cast<double>(snakeCords[0].x - sf::Mouse::getPosition().x) *
            (static_cast<double>(speed) / distanceOfMouseAndSnakeHead);

        snakeCords[0].y -= static_cast<double>(snakeCords[0].y - sf::Mouse::getPosition().y) *
            (static_cast<double>(speed) / distanceOfMouseAndSnakeHead);

        cordAndShapeConnaction();
    }
    
};

