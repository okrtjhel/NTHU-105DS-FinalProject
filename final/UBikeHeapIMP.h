#ifndef UBikeHeapIMP_h
#define UBikeHeapIMP_h

#include "readonly/UBikeHeapADT.h"

class UBikeHeapIMP : public UBikeHeapADT
{
public:
    // Add your code here
    void addUBikePtr(UBike* ubptr);
    UBike* removeUBikePtr(int heapIndex);
};

#endif
