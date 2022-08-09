#include "ball.h"
#include <cassert>

void Ball::update(sf::RenderWindow& window)
{
    if(m_shape_.getPosition().x - m_shape_.getRadius() <= 0 || m_shape_.getPosition().x + m_shape_.getRadius() >= window.getSize().x)
    {
        m_velocity_.x *= -1.f;
    }
    if(m_shape_.getPosition().y - m_shape_.getRadius() <= 0 || m_shape_.getPosition().y + m_shape_.getRadius() >= window.getSize().y)
    {
        m_velocity_.y *=-1.f;
    }

    m_shape_.move(m_velocity_);
}

void handleCollisions(Ball& ball, Block& block) noexcept
{
    if (ball.m_shape_.getGlobalBounds().intersects(block.m_shape_.getGlobalBounds())) //THIS ONLY CHECKS VERTICAL COLLISIONS!
    {
        ball.m_velocity_.y *= -1.f;

        if(block.m_hits_left_>0)--block.m_hits_left_; //Note that in the main loop, we handle all collisions before updating.
    }
}