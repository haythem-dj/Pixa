#include <Pixa/Pixa.hpp>

#include <memory>

class PixaTest : public Pixa::Application
{
public:
    void Init() override
    {
        mEngine = &Pixa::Engine::GetInstance();
        mRenderer = &mEngine->GetRenderer();

        mShader = mEngine->GetResourceManager().LoadShader("basic", "res/shaders/default.vert.glsl", "res/shaders/default.frag.glsl");
        mTexture = mEngine->GetResourceManager().LoadTexture("brick", "res/textures/brick.png");

        std::vector<f32> verts = {
            -0.5f, -0.5f, 0.0f, 0.0f,
            -0.5f, 0.5f,  0.0f, 1.0f,
             0.5f, 0.5f,  1.0f, 1.0f,
             0.5f, -0.5f, 1.0f, 0.0f,
        };

        std::vector<u32> indis = {
            0, 1, 2, 0, 2, 3
        };
        
        mVAO = Pixa::VAO::Create();
        mVBO = Pixa::VBO::Create(sizeof(verts), verts.data());
        mIBO = Pixa::IBO::Create(indis.size(), indis.data());

        mMaterial.Textures["uDiffuse"] = { mTexture, 0};
        
        mCamera = Pixa::Camera::Create(mEngine->GetWidth(), mEngine->GetHeight());

        mShader->SetInt("uDiffuse", 0);
        
        mRenderer->SetClearColor({1.f, 1.f, 1.f, 1.f});
    }
    
    void Update(f32 dt) override
    {
        CheckExit();

        glm::vec2 direction{0.0f};
        if (Pixa::Input::IsKeyDown(Pixa::Key::D)) direction.x = 1.0f;
        else if (Pixa::Input::IsKeyDown(Pixa::Key::Q)) direction.x = -1.0f;
        else direction.x = 0.0f;

        if (Pixa::Input::IsKeyDown(Pixa::Key::Z)) direction.y = 1.0f;
        else if (Pixa::Input::IsKeyDown(Pixa::Key::S)) direction.y = -1.0f;
        else direction.y = 0.0f;

        if (glm::length(direction) != 0.f) direction = glm::normalize(direction);
        mCamera->SetPosition(mCamera->GetPosition() + 5.0f * direction * dt);

        mShader->SetMatrix4("uProjection", mCamera->GetProjection());
        mShader->SetMatrix4("uView", mCamera->GetView());
    }

    void Render() override
    {
        mRenderer->Clear();
    }

    void Resize(u32 width, u32 height) override
    {
        mCamera->Resize(width, height);
    }

private:
    void CheckExit()
    {
        if (Pixa::Input::IsKeyDown(Pixa::Key::ESCAPE))
            mEngine->Stop();
    }

private:
    Pixa::Engine* mEngine = nullptr;
    Pixa::Renderer* mRenderer = nullptr;

    std::unique_ptr<Pixa::Camera> mCamera;

    std::shared_ptr<Pixa::Shader> mShader;
    std::shared_ptr<Pixa::Texture> mTexture;

    std::shared_ptr<Pixa::VAO> mVAO;
    std::shared_ptr<Pixa::VBO> mVBO;
    std::shared_ptr<Pixa::IBO> mIBO;

    Pixa::MaterialComponent mMaterial;


};

int main()
{
    Pixa::Engine& engine = Pixa::Engine::GetInstance();
    PixaTest* pixaTest = new PixaTest();
    
    engine.Run(pixaTest);
    delete pixaTest;
    return 0;
}