#pragma once

#include <SFML/Graphics.hpp>

#include <array>
#include <vector>

#include "ball.h"
#include "block.h"


class Game
{
public:
    Game()
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

    void run();

    void handleInput();
    void update();
    void draw();

private:    
    sf::RenderWindow m_window_;
    std::vector<Block> m_blocks_;
    std::array<Ball,10> m_ball_s;
};

