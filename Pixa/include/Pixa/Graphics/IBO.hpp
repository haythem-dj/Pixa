#pragma once

#include "Pixa/Common/Defines.hpp"

#include <memory>

namespace Pixa
{
    class PIXA_API IBO
    {
    public:
        ~IBO();

        explicit operator bool() const { return mID != 0; }

        void Bind() const;
        void Unbind() const;

        u32 GetID() const { return mID; }
        u32 GetCount() const { return mCount; }

        static std::shared_ptr<IBO> Create(u32 count, u32* data);
        
    private:
        IBO(u32 count, u32* data);

    private:
        u32 mID = 0;
        u32 mCount = 0;
    
    };
}