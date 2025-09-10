#pragma once

#include "Pixa/Common/Defines.hpp"

#include "Pixa/Core/Engine.hpp"

#include <entt/entt.hpp>

namespace Pixa
{
    class Entity;

    class PIXA_API Scene
    {
        friend class Entity;
    public:
        Scene() = default;
        ~Scene() = default;

        Entity CreateEntity();
        void DestroyEntity(Entity entity);

        template<typename... Ts>
        auto Get()
        {
            return mRegistry.view<Ts...>().each();
        }
    
    private:
        entt::registry mRegistry;

    };
}