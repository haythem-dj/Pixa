#include <Pixa/Pixa.hpp>

class PixaTest : public Pixa::Application
{};

int main()
{
    Pixa::Engine& engine = Pixa::Engine::GetInstance();
    PixaTest* pixaTest = new PixaTest();
    engine.Run(pixaTest);
    delete pixaTest;
    return 0;
}