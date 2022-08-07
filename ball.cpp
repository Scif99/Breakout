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

void handleCollisions(Ball& ball, Block& block)
{
    if (ball.m_shape_.getGlobalBounds().intersects(block.m_shape_.getGlobalBounds()))
    {
        assert(block.m_hits_left_!=0); //A ball should not hit a block that has 0 left. 0 left implies that the block should be destroyed.

        ball.m_velocity_.y *= -1.f;
        --block.m_hits_left_;
    }
}