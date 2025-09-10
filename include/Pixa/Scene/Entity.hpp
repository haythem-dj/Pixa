#pragma once

#include "Pixa/Common/Defines.hpp"

#include "Pixa/Core/Assert.hpp"

#include "Pixa/Scene/Scene.hpp"

namespace Pixa
{
    class PIXA_API Entity
    {
        friend class Scene;
    public:
        Entity(Scene& scene);
        ~Entity() = default;

        b8 IsValid();
    
        template<typename T>
        b8 HasComponent()
        {
            if (!IsValid())
            {
                PIXA_WARN("Entity {} does not exist in this scene.", mID);
                return false;
            }

            return mParentScene.mRegistry.all_of<T>((entt::entity)mID);
        }

        template<typename T, typename... Args>
        T& AddComponent(Args&&... args)
        {
            if (HasComponent<T>())
            {
                PIXA_WARN("Component already exist for this entity: {}.", mID);
                return mParentScene.mRegistry.get<T>((entt::entity)mID);
            }

            return mParentScene.mRegistry.emplace<T>((entt::entity)mID, std::forward<Args>(args)...);
        }

        template<typename T>
        void RemoveComponent()
        {
            if (!HasComponent<T>())
            {
                PIXA_WARN("entity: {} does not have this component.", mID);
                return;
            }

            mParentScene.mRegistry.remove<T>((entt::entity)mID);
        }

        template<typename T>
        T& GetComponent()
        {
            PIXA_ASSERT(HasComponent<T>(), "entity: {} does not have this component.", mID);

            return mParentScene.mRegistry.get<T>((entt::entity)mID);
        }

        u32 GetID() const { return mID; }

    private:
        u32 mID;

        Scene& mParentScene;
    
    };
}