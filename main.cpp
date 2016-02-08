#include <cstdlib>
#include <iostream>

#include "MinesModel.hpp"
#include "MinesTerminal.hpp"
#include "MinesUI.hpp"

int main(int argc, char* argv[])
{
    int width    = 20;
    int height   = 20;
    int numBombs = 100;
    
    if (argc > 1)
    {
        width  = atoi(argv[2]);
        height = atoi(argv[3]);
        numBombs  = atoi(argv[4]);
        
        if (numBombs > width*height)
        {
            numBombs = width*height;
        }
    }
    
    MinesModel model(width, height, numBombs);
    
    if (argc < 2 || *argv[1] == 't')
    {
        MinesTerminal terminal(model);
        terminal.run();
    }
    else
    {
        MinesUI ui(model);
        ui.run();
    }

    return EXIT_SUCCESS;
}
