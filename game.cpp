#include "game.h"
#include <iostream>

Game::Game()
    : m_window_{sf::VideoMode(800, 500), "Breakout!"} //dim{800,500}
    {
        m_window_.setFramerateLimit(200);
        m_blocks_.reserve(50); //num_blocks{50}

        for(int row = 0; row< 5; ++row)
        {
            for(int i =0;i<10;++i)
            {
                m_blocks_.emplace_back(i*80.f,row*20.f,5-row);        //row 0 has 5 hits... row 4 has 1 hit.
            }
        }
    }

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
    auto it = std::remove_if(std::begin(m_blocks_),std::end(m_blocks_),[](const Block& b){return b.get_hits()==0;});
    m_blocks_.erase(it,std::end(m_blocks_)); 
    for(auto& block : m_blocks_)
    {
        block.update();
    }
}

void Game::draw()
{
    m_window_.clear();
    for(auto& block : m_blocks_) {block.draw(m_window_);}
    for(auto& b : m_ball_s) {b.draw(m_window_);}
    m_window_.display();
}