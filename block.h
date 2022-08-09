#pragma once

#include <SFML/Graphics.hpp>


class Ball;

class Block
{
public:
    Block(float x, float y, int i);

    friend void handleCollisions(Ball& ball, Block& block) noexcept;
    void update();
    void draw(sf::RenderWindow& window) {window.draw(m_shape_);}
    int get_hits() const noexcept{return m_hits_left_;}

private:
    sf::RectangleShape m_shape_;
    int m_hits_left_;
    inline static const std::array<sf::Color,5> s_colors_ {  //In c++17, we can define a static member variable inside the class definition
        sf::Color::Blue,
        sf::Color::Green,
        sf::Color::Yellow,
        sf::Color::Magenta,
        sf::Color::Red};

};

