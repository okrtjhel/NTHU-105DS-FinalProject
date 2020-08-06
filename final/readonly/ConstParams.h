//===================THE-EDITS-OF-THIS-FILE-WILL-BE-DISCARDED===================

#ifndef ConstParams_h
#define ConstParams_h

#include <string>
#include <map>

//===============================================================
// names of heaps
//===============================================================
const int HeapTypeNum = 5;
const std::string HeapNames[] =
{ "Rented", "Electric", "Lady", "Road", "Hybrid" };

//===============================================================
// names of stations
//===============================================================
const int StationNum = 12;
const std::string StationNames[] =
{
    "Danshui", "Hongshulin", "Beitou",
    "Shilin",  "Zhongshan", "Xinpu",
    "Ximen",   "Liuzhangli", "Muzha",
    "Guting",  "Gongguan", "Jingmei"
};

//===============================================================
// the original rate
//===============================================================
const std::map< std::string, int > oriRates =
{
    {"Electric", 40},
    {"Lady", 30},
    {"Road", 20},
    {"Hybrid", 25}
};

//===============================================================
// the discount rate
//===============================================================
const std::map< std::string, int > dscntRates =
{
    {"Electric", 25},
    {"Lady", 20},
    {"Road", 10},
    {"Hybrid", 15}
};

#endif

//===================THE-EDITS-OF-THIS-FILE-WILL-BE-DISCARDED===================
