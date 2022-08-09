#pragma once

#include <SFML/Graphics.hpp>

#include <random>
#include <math.h>

#include "block.h"

struct RNG //TODO should this be static? Need to make sure its safe when threads are added...
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

    static constexpr float s_radius{10.f};

    Ball()
        : m_shape_{s_radius}, m_velocity_{0.f,-5.f}, m_rng_{60,120} //radius{10}
        {
            const float theta = m_rng_.get();
            m_velocity_ = {5.f*cos(theta),-5.f*sin(theta)};
            m_shape_.setPosition(100.f,300.f); //TODO maybe randomise the x coordinate too?
            m_shape_.setOrigin(m_shape_.getRadius(), m_shape_.getRadius());
        }

    void update(sf::RenderWindow& window);
    void draw(sf::RenderWindow& window) {window.draw(m_shape_);}
    friend void handleCollisions(Ball& ball, Block& block) noexcept;

private:
    sf::CircleShape m_shape_;
    sf::Vector2f m_velocity_;
    RNG m_rng_;
};
