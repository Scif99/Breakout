#include "paddle.h"

void Paddle::handleInput()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        m_velocity_ = -10.f;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        m_velocity_ = 10.f;
    }
    else m_velocity_ = 0.f;
}

void Paddle::update()
{
    m_shape_.move(m_velocity_,0.f);
}