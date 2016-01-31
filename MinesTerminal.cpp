#include "MinesTerminal.hpp"

#include <iostream>

MinesTerminal::MinesTerminal(MinesModel& newModel)
    : m_model(newModel)
{
}

void MinesTerminal::run()
{
    const MinesGrid_t& grid = m_model.getGrid();
    
    int height = grid.size();
    int width = grid[0].size();
    
    while (!m_model.isGameOver() && !m_model.hasWon())
    {
        for (int y = 0; y < height; ++y)
        {
            for (int x = 0; x < width; ++x)
            {
                if (grid[y][x].selected)
                {
                    if (grid[y][x].isBomb)
                    {
                        std::cout << "* ";
                    }
                    else if (grid[y][x].numNearby == 0)
                    {
                        std::cout << "- ";
                    }
                    else
                    {
                        std::cout << grid[y][x].numNearby << " ";
                    }
                }
                else if (grid[y][x].flagged)
                {
                    std::cout << "< ";
                }
                else
                {
                    std::cout << "O ";
                }
            }
            
            std::cout << "\n";
        }
        
        char option;
        int x;
        int y;
    
        std::cin >> option; 
        
        if (option == 'f')
        {
            std::cin >> x >> y;
            m_model.flagGrid(x+1, y+1);
        }
        else if (option == 's')
        {
            std::cin >> x >> y;
            m_model.selectGrid(x-1, y-1);
        }
        else if (option == 'q')
        {
            break;
        }
        else
        {
            std::cout << "Unknown option\n";
        }
    }
    
    if (m_model.isGameOver())
        std::cout << "BOOM!!!\n";
    else if (m_model.hasWon())
        std::cout << "winner! :)\n";
}
