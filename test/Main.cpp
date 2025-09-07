#include <Pixa/Pixa.hpp>

#include <memory>

class PixaTest : public Pixa::Application
{
public:
    void Init() override
    {
        mEngine = &Pixa::Engine::GetInstance();
        mRenderer = &mEngine->GetRenderer();

        f32 verts[] = {
            -0.7f, 0.5f, 0.f, 1.f,
            0.7f, 0.5f, 1.f, 1.f,
            0.7f, -0.5f, 1.f, 0.f,
            -0.7f, -0.5f, 0.f, 0.f,
        };

        u32 indes[] = {
            0, 1, 2, 0, 2, 3
        };
        
        mShader = Pixa::Shader::Create("res/shaders/default.vert.glsl", "res/shaders/default.frag.glsl");
        mVAO = Pixa::VAO::Create();
        mVBO = Pixa::VBO::Create(sizeof(verts), verts);
        mIBO = Pixa::IBO::Create(6, indes);
        mTexture = Pixa::Texture::Create("res/textures/brick.png");
        mCamera = Pixa::Camera::Create(mEngine->GetWidth(), mEngine->GetHeight());

        if (mShader == nullptr ||
            mVAO == nullptr ||
            mVBO == nullptr ||
            mIBO == nullptr ||
            mTexture == nullptr) mEngine->Stop();

        mVAO->AddVertexBuffer(mVBO, { 2, 2 });
        mVAO->SetIndexBuffer(mIBO);

        mShader->SetInt("uDiffuse", 0);
        
        mRenderer->SetClearColor({1.f, 1.f, 1.f, 1.f});
    }
    
    void Update(f32 dt) override
    {
        (void) dt;
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
        Pixa::ScopedTimer("Rendering");
        mRenderer->RenderBegin();
        mRenderer->Clear();
        mRenderer->DrawTextured(mVAO, mShader, mTexture);
        mRenderer->RenderEnd();
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
    const Pixa::Renderer* mRenderer = nullptr;

    std::unique_ptr<Pixa::Camera> mCamera;

    std::shared_ptr<Pixa::Shader> mShader;
    std::shared_ptr<Pixa::VAO> mVAO;
    std::shared_ptr<Pixa::VBO> mVBO;
    std::shared_ptr<Pixa::IBO> mIBO;
    std::shared_ptr<Pixa::Texture> mTexture;

};

int main()
{
    Pixa::Engine& engine = Pixa::Engine::GetInstance();
    PixaTest* pixaTest = new PixaTest();
    
    engine.Run(pixaTest);
    delete pixaTest;
    return 0;
}