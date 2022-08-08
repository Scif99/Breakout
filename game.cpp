#include "game.h"
#include <iostream>

void Game::run()
{
    while(m_window_.isOpen())
    {
        handleInput();
        update();
        draw();
    }
}

void Game::handleInput()
{

    sf::Event event;
    while (m_window_.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            m_window_.close();
    }
}

void Game::update()
{
    for(auto& block: m_blocks_)
    {
        for(auto& b : m_ball_s)
        {
            handleCollisions(b,block);
        }
    }

    for(auto& b : m_ball_s) {b.update(m_window_);}

    //Erase any blocks that have 0 left using the erase-remove idiom
    auto it = std::remove_if(std::begin(m_blocks_),std::end(m_blocks_),[](Block b){return b.get_hits()==0;});
    m_blocks_.erase(it,std::end(m_blocks_)); 
    for(auto& block : m_blocks_)
    {
        block.update();
    }
}

void Game::draw()
{
    m_window_.clear();
    for(auto& block : m_blocks_) 
    {
        block.draw(m_window_);
    }
    for(auto& b : m_ball_s) {b.draw(m_window_);}
    m_window_.display();
}