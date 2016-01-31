#include <cstdlib>

#include "MinesModel.hpp"
#include "MinesTerminal.hpp"

int main(int argc, char* argv[])
{
    MinesModel model(20, 20, 10);
    MinesTerminal ui(model);
    
    ui.run();
    return EXIT_SUCCESS;
}
