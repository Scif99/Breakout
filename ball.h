#pragma once

#include <SFML/Graphics.hpp>

#include <random>
#include <math.h>

#include "block.h"

struct RNG
{
    RNG(int low, int high)
        : mt{rd()}, m_dist_{low,high} {} 

    int get() {return m_dist_(mt);}
    
    std::random_device rd;
    std::mt19937 mt;
    std::uniform_int_distribution<> m_dist_;
    int m_low;
    int m_high;

};



class Ball 
{
public:
    Ball()
        : m_shape_{10.f}, m_velocity_{0.f,-5.f}, m_rng_{60,120} //radius{10}
        {
            float theta = m_rng_.get();
            m_velocity_ = {5.f*cos(theta),-5.f*sin(theta)};
            m_shape_.setPosition(100.f,300.f);
            m_shape_.setOrigin(m_shape_.getRadius(), m_shape_.getRadius()); //Set the origin to be the centre of the ball (rather than the default top-left)
        }

    void update(sf::RenderWindow& window);
    void draw(sf::RenderWindow& window) {window.draw(m_shape_);}
    friend void handleCollisions(Ball& ball, Block& block);

private:
    sf::CircleShape m_shape_;
    sf::Vector2f m_velocity_;
    RNG m_rng_;
};
