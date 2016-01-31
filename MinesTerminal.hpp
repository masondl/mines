#ifndef _MINES_TERMINAL_H
#define _MINES_TERMINAL_H

#include "MinesModel.hpp"

class MinesTerminal
{
    private:
    MinesModel& m_model;
    
    public:
    MinesTerminal(MinesModel& newModel);
    void run();
};

#endif
