#include "Pixa/pch.hpp"

#include "Pixa/Scene/Entity.hpp"

namespace Pixa
{
    Entity::Entity(Scene& scene)
        :mParentScene(scene)
    {}

    b8 Entity::IsValid()
    {
        return mParentScene.mRegistry.valid((entt::entity)mID);
    }
}