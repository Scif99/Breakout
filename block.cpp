#include "block.h"
#include <cassert>

Block::Block(float x, float y, int i)
        : m_shape_{sf::Vector2f(80.f,20.f)}, m_hits_left_{i} //dim{80.f,20.f}
{
    m_shape_.setPosition(x,y);
    m_shape_.setFillColor(Block::s_colors_[i-1]);
    m_shape_.setOutlineColor(sf::Color::Black);
    m_shape_.setOutlineThickness(-1.f);
}

void Block::update()
{
    assert(m_hits_left_>=0);
    m_shape_.setFillColor(Block::s_colors_[m_hits_left_-1]);
}