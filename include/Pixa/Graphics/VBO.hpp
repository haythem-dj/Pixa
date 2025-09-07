#pragma once

#include "Pixa/Common/Defines.hpp"

#include <memory>

namespace Pixa
{
    class PIXA_API VBO
    {
    public:
        ~VBO();

        explicit operator bool() const { return mID != 0; }

        void Bind() const;
        void Unbind() const;

        u32 GetID() const { return mID; }

        static std::shared_ptr<VBO> Create(u32 size, f32* data);
        
    private:
        VBO(u32 size, f32* data);

    private:
        u32 mID = 0;
    
    };
}