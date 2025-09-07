#include "Pixa/pch.hpp"

#include "Pixa/Scene/Camera.hpp"

namespace Pixa
{
    Camera::Camera(u32 width, u32 height)
    {
        Resize(width, height);
        CalculateView();
    }

    Camera::~Camera()
    {}

    void Camera::Resize(u32 width, u32 height)
    {
        mAspectRatio = (f32)width / (f32) height;
        CalculateProjection();
    }

    void Camera::SetPosition(const glm::vec2& position)
    {
        mPosition = position;
        CalculateView();
    }

    void Camera::SetRotation(f32 rotation)
    {
        mRotation = rotation;
        CalculateView();
    }

    void Camera::CalculateProjection()
    {
        mProjection = glm::ortho(-mAspectRatio, mAspectRatio, -1.0f, 1.0f, -1.0f, 1.0f);
    }

    void Camera::CalculateView()
    {
        mView = glm::mat4(1.f);
        mView = glm::translate(mView, glm::vec3{-mPosition, 0.0f});
        mView = glm::rotate(mView, -glm::radians(mRotation), {0.0f, 0.0f, 1.0f});
    }

    std::unique_ptr<Camera> Camera::Create(u32 width, u32 height)
    {
        std::unique_ptr<Camera> camera(new Camera(width, height));
        return camera;
    }
}