#include "block.h"
#include <cassert>

void Block::update()
{
    assert(m_hits_left_>=0);
    m_shape_.setFillColor(cols[m_hits_left_-1]);
}