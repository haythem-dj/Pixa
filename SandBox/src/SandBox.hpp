#include <Pixa/Pixa.hpp>

#include <memory>

class SandBox : public Pixa::Application
{
public:
    void Init() override;
    void Update(f32 dt) override;
    void Render() override;
    void Resize(u32 width, u32 height) override;

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
