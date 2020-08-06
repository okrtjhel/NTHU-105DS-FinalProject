#ifndef UBikeSystemIMP_h
#define UBikeSystemIMP_h

#include "readonly/UBikeSystemADT.h"

class UBikeSystemIMP : public UBikeSystemADT
{
public:
    // Add your code here
    void InitDistTable(std::string MapFile);
    void NewBike(std::string classType, std::string license, int mile, std::string station);
    void JunkIt(std::string license);
    void Rent(std::string classType, std::string station);
    void Return(std::string station, std::string license, int returnMile);
    void Trans(std::string station, std::string license);
    void ShutDown();
};

#endif
