#include <Pixa/Pixa.hpp>

#include <memory>

class PixaTest : public Pixa::Application
{
public:
    void Init() override
    {
        mEngine = &Pixa::Engine::GetInstance();
        mRenderer = &mEngine->GetRenderer();

        mShader = std::make_shared<Pixa::Shader>("res/shaders/default.vert.glsl", "res/shaders/default.frag.glsl");
        if (!*mShader)
        {
            mEngine->Stop();
        }
        mShader->Bind();
    }

private:
    Pixa::Engine* mEngine = nullptr;
    const Pixa::Renderer* mRenderer = nullptr;

    std::shared_ptr<Pixa::Shader> mShader;

};

int main()
{
    Pixa::Engine& engine = Pixa::Engine::GetInstance();
    PixaTest* pixaTest = new PixaTest();
    
    engine.Run(pixaTest);
    delete pixaTest;
    return 0;
}