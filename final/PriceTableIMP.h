#ifndef PriceTableIMP_h
#define PriceTableIMP_h

#include "readonly/PriceTableADT.h"

class PriceTableIMP : public PriceTableADT
{
public:
    // Add your code here
    void calcAllPairsShortestPath(std::string mapFile);
    int calcPrice(int milageDiff, std::string bClass, std::string from, std::string toStation);
};

#endif
