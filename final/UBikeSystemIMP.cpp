#include "UBikeSystemIMP.h"

// Add your code here
void UBikeSystemIMP::InitDistTable(std::string MapFile){
	priceTable.calcAllPairsShortestPath(MapFile);
}

void UBikeSystemIMP::NewBike(std::string classType, std::string license, int mile, std::string station){
	//set info
	UBike* ub=new UBike;
    ub->isRented=false;
    ub->mileage=mile;
    ub->license=license;
    ub->station=station;
    ub->classType=classType;
    
    //add to Hash Table
    ubHashTable.addUBikePtr(ub);
    
    //add to heap
    ubStations[station][classType].addUBikePtr(ub);
}

void UBikeSystemIMP::JunkIt(std::string license){
	//find the bike
	UBike *ub=ubHashTable.findUBikePtr(license,false);
	
	//found and not rented
	if(ub!=NULL&&ub->isRented!=true){
        ubHashTable.findUBikePtr(license,true);
		ubStations[ub->station][ub->classType].removeUBikePtr(ub->heapIndex);
		delete ub;
	}
}

void UBikeSystemIMP::Rent(std::string classType, std::string station){
	//if no bike
	if(ubStations[station][classType].isEmpty())
        return;
    
    //rented, remove root of heap
    UBike *ub=ubStations[station][classType].removeUBikePtr(1);
    if(ub==NULL)
    	return;
    
    //add to "Rented" Heap
	ubStations[station]["Rented"].addUBikePtr(ub);
	
	//update info
	ub->isRented = true;
}

void UBikeSystemIMP::Return(std::string station, std::string license, int returnMile){
	//find the bike
	UBike *ub=ubHashTable.findUBikePtr(license, false);
	
	//not rented or not found
	if(ub==NULL||ub->isRented==false)
		return;
	
	//earn money
	net+=priceTable.calcPrice(returnMile-(ub->mileage), ub->classType, ub->station, station);
	
	//remove from "Rented" Heap
	ubStations[ub->station]["Rented"].removeUBikePtr(ub->heapIndex);
	
	//update info
	ub->mileage=returnMile;
	ub->isRented=false;
	
	//add to station
	ubStations[ub->station][ub->classType].addUBikePtr(ub);
}

void UBikeSystemIMP::Trans(std::string station, std::string license){
	//find the bike
	UBike* ub=ubHashTable.findUBikePtr(license, false);
	
	//not found or is rented
	if(ub==NULL||ub->isRented==true)
		return;
		
	//remove from original station
	ubStations[ub->station][ub->classType].removeUBikePtr(ub->heapIndex);
	
	//add to new station
	ubStations[station][ub->classType].addUBikePtr(ub);
	
	//update info
	ub->station=station;
}

void UBikeSystemIMP::ShutDown(){
	//clean Hash Table
	for(int i=0;i<256;++i)
		ubHashTable[i].clear();
	
	//clean Heap
	for(int i=0;i<StationNum;++i){
        for(int j=0;j<HeapTypeNum;++j){
            int k=ubStations[StationNames[i]][StationNames[j]].number;
            while(k>0){
                delete ubStations[StationNames[i]][StationNames[j]][k];
                k--;
            }
        }
    }
}
