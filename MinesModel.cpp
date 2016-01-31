/* typedef std::vector< std::vector<MinesState> > MinesGrid_t;

    private:
    MinesGrid_t m_grid;
    bool gameOver;
    int m_width;
    int m_height;
    int m_numBombs;
    int m_numCorrectFlags;
    int m_numIncorrectFlags;
*/
#include <cstdlib>
#include <ctime>
#include <utility>

#include "MinesModel.hpp"
 
MinesModel::MinesModel(int width, int height, int numBombs) :
    m_grid()
{
    m_width = width;
    m_height = height;
    m_numBombs = numBombs;
    srand( time(NULL) );
    reset();
}

const MinesGrid_t& MinesModel::getGrid() const
{
    return m_grid;
}

bool MinesModel::hasWon() const
{
    return m_numCorrectFlags == m_numBombs;
}

bool MinesModel::isGameOver() const
{
    return m_gameOver;
}

void MinesModel::reset()
{
    m_grid.clear();
    m_gameOver = false;
    
    std::vector<MinesState> row(m_width);
    for (int i = 0; i < m_height; ++i)
    {
        m_grid.push_back(row);
    }
    
    // Place bombs randomly
    for (int placedBombs = 0; placedBombs < m_numBombs; ++placedBombs)
    {
        int x = rand() % m_width;
        int y = rand() % m_height;
        
        if (m_grid[y][x].isBomb)
        {
            // Try again...
            --placedBombs;
        }
        else
        {
            m_grid[y][x].isBomb = true;
        }
    }
    
    // Add nearby counts
    for (int y = 0; y < m_height; ++y)
    {
        for (int x = 0; x < m_width; ++x)
        {
            if (m_grid[y][x].isBomb)
            {
                ++m_grid[y][x].numNearby;
                // Increment count of all adjacent spaces
                if (x-1 >= 0)
                {
                    if (y+1 < m_height) ++m_grid[y+1][x-1].numNearby;
                                        ++m_grid[y  ][x-1].numNearby;
                    if (y-1 >= 0)       ++m_grid[y-1][x-1].numNearby;
                }
                
                if (y+1 < m_height)     ++m_grid[y+1][x].numNearby;
                if (y-1 >= 0)           ++m_grid[y-1][x].numNearby;
                
                if (x+1 < m_width)
                {
                    if (y+1 < m_height) ++m_grid[y+1][x+1].numNearby;
                                        ++m_grid[y  ][x+1].numNearby;
                    if (y-1 >= 0)       ++m_grid[y-1][x+1].numNearby; 
                }
            }
        }
    }
}

/** Have no effect if x or y are out of range */
void MinesModel::selectGrid(int x, int y)
{
    if (x <= m_width && y <= m_height && 
        !m_grid[y][x].flagged && !m_grid[y][x].selected)
    {
        if (m_grid[y][x].isBomb)
        {
            m_gameOver = true;
        }

        // Select any adjacent 0s
        m_grid[y][x].selected = true;
            
        if (m_grid[y][x].numNearby == 0)
        {
            if (y-1 >= 0)
            {
                if (x+1 < m_width) selectGrid(x+1, y-1);
                                    selectGrid(x  , y-1);
                if (x-1 >= 0)       selectGrid(x-1, y-1);
            }
            
            if (x+1 < m_width)     selectGrid(x+1, y);
            if (x-1 >= 0)           selectGrid(x-1, y);
            
            if (y+1 < m_height)
            {
                if (x+1 < m_width) selectGrid(x+1, y+1);
                                    selectGrid(x  , y+1);
                if (x-1 >= 0)       selectGrid(x-1, y+1);
            }           
        }
    }
}

void MinesModel::flagGrid(int x, int y)
{
    if ((x <= m_width && y <= m_height) && 
       ((m_numCorrectFlags + m_numIncorrectFlags) < m_numBombs))
    {
        if (!m_grid[y][x].flagged)
        {
            m_grid[y][x].flagged = true;
            if (m_grid[y][x].isBomb)
            {
                m_numCorrectFlags++;
            }
            else
            {
                m_numIncorrectFlags++;
            }
        }
    }    
}

