//===================THE-EDITS-OF-THIS-FILE-WILL-BE-DISCARDED===================

#include "UBike.h"

std::string UBike::toString() const
{
    std::ostringstream oss;
    oss << std::setw(12) << this->license;
    oss << std::setw(12) << this->mileage;
    return oss.str();
}

//===================THE-EDITS-OF-THIS-FILE-WILL-BE-DISCARDED===================
