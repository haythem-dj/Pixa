#include "SandBox.hpp"

int main()
{
    Pixa::Engine& engine = Pixa::Engine::GetInstance();
    SandBox* sandbox = new SandBox();

    engine.Run(sandbox);
    
    delete sandbox;

    return 0;
}
