#pragma once
#include <SFML/Graphics.hpp>


class Paddle
{
public:
    Paddle()
    {
        m_shape_.setSize(sf::Vector2f(50.f,20.f));
        m_shape_.setPosition(400.f,500.f-50.f);
    }


    void handleInput();
    void update();
    void draw(sf::RenderWindow& window) {window.draw(m_shape_);}

private:
    sf::RectangleShape m_shape_;
    float m_velocity_{0.f};
};

