#include "AllocatorExample.h"


template<typename T>
class ArrayAllocator : public std::allocator<T>
{
    STD_ALLOCATOR_BODY(ArrayAllocator, T)

public:

    T* allocate(size_t len)
    {
        std::cout << "Allocate" << std::endl;
        return (T*)malloc(sizeof(T) * len);
    }

    void deallocate(T* arr, size_t len)
    {
        std::cout << "Deallocate" << std::endl;
        free(arr);
    }

};


void AllocatorExample::main()
{
    std::vector<float, ArrayAllocator<float>> arr;
    arr.push_back(1.0f);
    arr.push_back(1.1f);
    arr.push_back(1.2f);
}
