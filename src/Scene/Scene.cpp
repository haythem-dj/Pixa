#include "Pixa/pch.hpp"

#include "Pixa/Scene/Scene.hpp"
#include "Pixa/Scene/Entity.hpp"

namespace Pixa
{
    Entity Scene::CreateEntity()
    {
        u32 id = (u32)mRegistry.create();
        Entity entity(*this);
        entity.mID = id;
        return entity;
    }

    void Scene::DestroyEntity(Entity entity)
    {
        if (entity.IsValid())
            mRegistry.destroy((entt::entity)entity.GetID());
    }
}