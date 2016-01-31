#ifndef _MINES_MODEL_H
#define _MINES_MODEL_H

#include <vector>
#include "MinesState.hpp"

typedef std::vector< std::vector<MinesState> > MinesGrid_t;

class MinesModel
{
    private:
    MinesGrid_t m_grid;
    bool m_gameOver;
    int m_width;
    int m_height;
    int m_numBombs;
    int m_numCorrectFlags;
    int m_numIncorrectFlags;
    
    public:
    MinesModel(int width, int height, int numBombs);
    
    const MinesGrid_t& getGrid() const;
    bool hasWon() const;
    bool isGameOver() const;
    void reset();
    
    /** Have no effect if x or y are out of range */
    void selectGrid(int x, int y);
    void flagGrid(int x, int y);
};

#endif
