#pragma once

#include "Pixa/Common/Defines.hpp"

#include <memory>
#include <glm/glm.hpp>

namespace Pixa
{
    class PIXA_API Camera
    {
    public:
        ~Camera();
        
        void Resize(u32 width, u32 height);
        
        void SetPosition(const glm::vec2& position);
        void SetRotation(f32 rotation);
        
        const glm::vec2& GetPosition() const { return mPosition; }
        f32 GetRotation() const { return mRotation; }
        
        const glm::mat4& GetProjection() const { return mProjection; }
        const glm::mat4& GetView() const { return mView; }

        static std::unique_ptr<Camera> Create(u32 width, u32 height);
    
    private:
        Camera(u32 width, u32 height);
        void CalculateProjection();
        void CalculateView();

    private:
        glm::vec2 mPosition{ 0.0f };
        f32 mRotation = 0.0f;

        glm::mat4 mProjection{1.0f};
        glm::mat4 mView{1.0f};

        f32 mAspectRatio = 1.0f;
    
    };
}