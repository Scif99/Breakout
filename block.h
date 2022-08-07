#pragma once

#include <SFML/Graphics.hpp>

    static const std::array<sf::Color,5> cols {sf::Color::Blue, //make static?
                            sf::Color::Green,
                            sf::Color::Yellow,
                            sf::Color::Magenta,
                            sf::Color::Red};

class Ball;

class Block
{
public:
    Block(float x, float y, int i)
        : m_shape_{sf::Vector2f(80.f,20.f)}, m_hits_left_{i}
    {
        //m_shape_.setOrigin(40.f,10.f);
        m_shape_.setPosition(x,y);
        m_shape_.setFillColor(cols[i-1]);
        m_shape_.setOutlineColor(sf::Color::Black);
        m_shape_.setOutlineThickness(-1.f);
    }

    friend void handleCollisions(Ball& ball, Block& block);
    void update();
    void draw(sf::RenderWindow& window) {window.draw(m_shape_);}

    int get_hits() const {return m_hits_left_;}
private:
    sf::RectangleShape m_shape_;
    int m_hits_left_;

};

