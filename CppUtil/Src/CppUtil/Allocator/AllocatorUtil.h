#pragma once


#define STD_ALLOCATOR_BODY(__AllocatorType, __AllocatedType) \
public: \
    __AllocatorType() = default; \
 \
    template<typename __OtherAllocatedType> \
    __AllocatorType(const __AllocatorType<__OtherAllocatedType>& other) : std::allocator<__AllocatedType>(other) { } \
 \
    template<typename __OtherAllocatedType> \
    struct rebind { using other = __AllocatorType<__OtherAllocatedType>; }; \
private:
