#include <Pixa/Pixa.hpp>

class PixaTest : public Pixa::Application
{};

int main()
{
    Pixa::Engine& engine = Pixa::Engine::GetInstance();
    PixaTest* pixaTest = new PixaTest();

    PIXA_TRACE("TRACE");
    PIXA_DEBUG("DEBUG");
    PIXA_INFO("INFO");
    PIXA_WARN("WARN");
    PIXA_ERROR("ERROR");
    PIXA_FATAL("FATAL");
    
    engine.Run(pixaTest);
    delete pixaTest;
    return 0;
}