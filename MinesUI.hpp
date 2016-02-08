#ifndef _MINES_UI_H
#define _MINES_UI_H

#include <SFML/Graphics.hpp>

#include "MinesModel.hpp"

const char* const FONT_PATH = "/usr/share/fonts/truetype/ubuntu-font-family/Ubuntu-B.ttf";

const int SQUARE_SIZE = 30;
const int GRID_OFFSET = 20;

const sf::Color BACKGROUND_COLOR = sf::Color(191, 212, 219);
const sf::Color WM_COLOR        = sf::Color(51, 153, 102);
const sf::Color LM_COLOR      = sf::Color::Red; 
const sf::Color GRID_COLOR       = sf::Color::Black;
const sf::Color SEVEN_COLOR      = sf::Color::Yellow;
const sf::Color FOUR_COLOR       = sf::Color::Magenta; 
const sf::Color FIVE_COLOR       = sf::Color(48, 150, 145);
const sf::Color THREE_COLOR      = sf::Color::Red; 
const sf::Color TWO_COLOR        = sf::Color::Blue;
const sf::Color ONE_COLOR        = sf::Color(51, 153, 102);
const sf::Color SIX_COLOR        = sf::Color(255, 132, 0);
const sf::Color SELECTED_COLOR   = sf::Color::Yellow;

class MinesUI
{
    private:
    MinesModel& m_model;
    
    public:
    MinesUI(MinesModel& newModel);
    void run();
};

#endif
