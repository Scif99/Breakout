#pragma once

#include <SFML/Graphics.hpp>

#include <array>
#include <vector>

#include "ball.h"
#include "block.h"


class Game
{
public:
 
    Game();

    void run();

    void handleInput();
    void update();
    void draw();

private:    
    sf::RenderWindow m_window_;
    std::vector<Block> m_blocks_;
    std::array<Ball,10> m_ball_s;
};

