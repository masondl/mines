#ifndef _MINES_STATE_H
#define _MINES_STATE_H

class MinesState
{
    public:
    bool selected;
    bool flagged;
    bool isBomb;
    int numNearby;
    
    MinesState() { reset(); }
    void reset()
    {
        selected = false;
        flagged = false;
        isBomb = false;
        numNearby = 0;
    }
};

#endif
