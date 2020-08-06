#include "PriceTableIMP.h"
#include<iostream>
#include<fstream>
#include<sstream>

using namespace std;

// Add your code here

std::map< std::string, int > new_oriRates =
{
    {"Electric", 40},
    {"Lady", 30},
    {"Road", 20},
    {"Hybrid", 25}
};

std::map< std::string, int > new_dscntRates =
{
    {"Electric", 25},
    {"Lady", 20},
    {"Road", 10},
    {"Hybrid", 15}
};

void PriceTableIMP::calcAllPairsShortestPath(std::string mapFile){
	//initialize
	for(int i=0;i<StationNum;++i){
		for(int j=0;j<StationNum;++j){
			distTable[StationNames[i]][StationNames[j]]=999999;
		}
	}
	for(int i=0;i<StationNum;++i){
		distTable[StationNames[i]][StationNames[i]]=0;
	}
	
	//read info
	ifstream ifs(mapFile);
	string start,end;
	int dist;
	while(ifs>>start>>end>>dist){
		distTable[start][end]=min(distTable[start][end],dist);
		distTable[end][start]=min(distTable[start][end],dist);
	}
	
	//check
	for(int i=0;i<StationNum;++i){
		for(int j=0;j<StationNum;++j){
			for(int k=0;k<StationNum;++k){
				if(distTable[StationNames[j]][StationNames[k]]>
				(distTable[StationNames[j]][StationNames[i]]+distTable[StationNames[i]][StationNames[k]])){
					distTable[StationNames[j]][StationNames[k]]=
					(distTable[StationNames[j]][StationNames[i]]+distTable[StationNames[i]][StationNames[k]]);
				}
			}
		}
	}
}

int PriceTableIMP::calcPrice(int milageDiff, std::string bClass, std::string from, std::string toStation){
	//calculate price
	int price;
	if(milageDiff<=distTable[from][toStation]){
		price=milageDiff*new_dscntRates[bClass];
		return price;
	}
	else{
		price=milageDiff*new_oriRates[bClass];
		return price;
	}
}
