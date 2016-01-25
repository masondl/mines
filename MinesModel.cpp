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
#include <utility>
#include "MinesModel.hpp"
 
MinesModel::MinesModel(int width, int height, int numBombs) :
    m_grid();
{
    m_width = width;
    m_height = height;
    m_numBombs = numBombs;
    reset();
}

const MinesGrid_t& MinesModel::getGrid() const
{
    return grid;
}

bool MinesModel::hasWon() const
{
    return m_numCorrectFlags == m_numBombs;
}

void MinesModel::reset()
{
    m_grid.reset();
    m_gameOver = false;
    
    // Initialize grid
    std::vector<MinesState> row(m_width);
    for (int i = 0; i < m_height, ++i)
    {
        m_grid.insert(row);
    }
    
    // Place bombs randomly
    for (int placedBombs = 0; placedBombs < numBombs; ++placedBombs)
    {
        
    }
    
    // Add nearby counts
}

/** Have no effect if x or y are out of range */
void MinesModel::selectGrid(int x, int y)
{
    std::vector< std::pair<int, int> > workList();
    
    if (x <= width && y <= height)
    {
        workList.insert( std::pair<int, int>(x, y) );
    }
    
    while (!workList.empty())
    {
        int x = workList[0].first;
        int y = workList[0].second;
        
        if (!m_grid[y][x].selected)
        {
            m_grid[y][x].selected = true;
        
            if (m_grid[y][x].isBomb)
            {
                m_gameOver = true;
                
            }
            else if (m_grid[y][x].numNearby == 0)
            {
                // Add adjacent places to work list
            }
        }
        
        workList.erase(workList.first());
    }
}

void MinesModel::flagGrid(int x, int y)
{
    if ((x <= width && y <= height) && 
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

