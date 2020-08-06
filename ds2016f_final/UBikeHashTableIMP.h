#ifndef UBikeHashTableIMP_h
#define UBikeHashTableIMP_h

#include "readonly/UBikeHashTableADT.h"

class UBikeHashTableIMP : public UBikeHashTableADT
{
public:
    // Add your code here
    void addUBikePtr(UBike* ubptr);
    UBike* findUBikePtr(std::string license, bool toRemove);
};

#endif
