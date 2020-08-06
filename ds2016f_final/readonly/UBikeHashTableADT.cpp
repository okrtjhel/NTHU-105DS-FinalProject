//===================THE-EDITS-OF-THIS-FILE-WILL-BE-DISCARDED===================
#include "UBikeHashTableADT.h"

void UBikeHashTableADT::addUBikePtr(UBike* ubptr)
{
    throw "UBikeHashTableADT::addUBikePtr";
}

UBike* UBikeHashTableADT::findUBikePtr(std::string license, bool toRemove)
{
    throw "UBikeHashTableADT::findUBikePtr";
}

std::string UBikeHashTableADT::toString() const
{
    std::ostringstream oss;
    for(int i=0; i<256; i++)
    {
        const UBikePtrList &curList = (*this)[i];
        if( curList.empty() )
            continue;
        
        oss << std::setw(4) << i << ": ";
        for( const auto &it : curList )
            oss << it->license << " -> ";
        oss << "End" << std::endl;
    }
    
    return oss.str();
}
//===================THE-EDITS-OF-THIS-FILE-WILL-BE-DISCARDED===================
