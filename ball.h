#pragma once

#include <SFML/Graphics.hpp>
#include "block.h"

class Ball 
{
public:
    Ball()
        : m_shape_{10.f}, m_velocity_{0.f,-5.f}
        {
            m_shape_.setPosition(100.f,300.f);
            m_shape_.setOrigin(m_shape_.getRadius(), m_shape_.getRadius()); //Set the origin to be the centre of the ball (rather than the default top-left)
        }

    void update(sf::RenderWindow& window);
    void draw(sf::RenderWindow& window) {window.draw(m_shape_);}
    friend void handleCollisions(Ball& ball, Block& block);

private:
    sf::CircleShape m_shape_;
    sf::Vector2f m_velocity_;
};
