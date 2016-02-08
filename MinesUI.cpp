#include <sstream>

#include "MinesUI.hpp"

MinesUI::MinesUI(MinesModel& newModel)
    : m_model(newModel)
{
}

void MinesUI::run()
{
    MinesGrid_t grid = m_model.getGrid();
    
    int window_width  = (grid[0].size()*SQUARE_SIZE) + (2*GRID_OFFSET);
    int window_height = (grid.size()*SQUARE_SIZE) + (2*GRID_OFFSET);
    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "Mines");
    
    sf::Font font;
    font.loadFromFile(FONT_PATH);
    
    while (window.isOpen())
    {
        grid = m_model.getGrid();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (!m_model.isGameOver() && !m_model.hasWon())
            {
                if (event.type == sf::Event::MouseButtonPressed)
                {
                    int col = (event.mouseButton.x - GRID_OFFSET) / SQUARE_SIZE;
                    int row = (event.mouseButton.y - GRID_OFFSET) / SQUARE_SIZE;
                    
                    if (event.mouseButton.button == sf::Mouse::Left)
                    {
                        m_model.selectGrid(col,row);
                    }
                    
                    if (event.mouseButton.button == sf::Mouse::Right)
                    {
                        m_model.flagGrid(col,row);
                    }
                }
            }
            
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        
        window.clear(BACKGROUND_COLOR);
        
        sf::Text overlay;
        if (m_model.isGameOver())
        {
            overlay.setCharacterSize(45);
            overlay.setFont(font);
            overlay.setColor(LM_COLOR);
            overlay.setString("BOOM!");
        }
        if (m_model.hasWon())
        {
            overlay.setCharacterSize(45);
            overlay.setFont(font);
            overlay.setColor(WM_COLOR);
            overlay.setString("WINNER! :)");
        }
        
        // Draw grid
        for (int row = 0; row < grid.size(); ++row)
        {
            for (int col = 0; col < grid[0].size(); ++col)
            {
                sf::RectangleShape rect(sf::Vector2f(SQUARE_SIZE, SQUARE_SIZE));
                sf::Text num;
                if (grid[row][col].selected)
                {
                    int numNearby = grid[row][col].numNearby;
                    
                    if (grid[row][col].isBomb)
                    {
                        rect.setFillColor(sf::Color::Black);
                    }
                    else if (numNearby == 0)
                    {
                        rect.setFillColor(BACKGROUND_COLOR);
                    }
                    else
                    {
                        rect.setFillColor(BACKGROUND_COLOR);
                        num.setCharacterSize(25);
                        num.setFont(font);
                        switch(numNearby)
                        {
                            case 1: num.setColor(ONE_COLOR);   break;
                            case 2: num.setColor(TWO_COLOR);   break;
                            case 3: num.setColor(THREE_COLOR); break;
                            case 4: num.setColor(FOUR_COLOR);  break;
                            case 5: num.setColor(FIVE_COLOR);  break;
                            case 6: num.setColor(SIX_COLOR);   break;
                            case 7: num.setColor(SEVEN_COLOR); break;
                            case 8:
                            default: num.setColor(GRID_COLOR); break;
                        }
                        
                        
                        num.setPosition(GRID_OFFSET + 5 + (col * SQUARE_SIZE), 
                                        GRID_OFFSET + (row * SQUARE_SIZE));
                                       
                        std::stringstream ss;
                        
                        ss << numNearby;
                        num.setString(ss.str());
                    }
                }
                else if (grid[row][col].flagged)
                {
                    rect.setFillColor(SELECTED_COLOR);
                }
                
                rect.setOutlineThickness(1);
                rect.setOutlineColor(GRID_COLOR);
                rect.setPosition(GRID_OFFSET + (col * SQUARE_SIZE), 
                                 GRID_OFFSET + (row * SQUARE_SIZE));
                window.draw(rect);
                window.draw(num);
                window.draw(overlay);
            }
        }
        
        window.display();
    }
}
