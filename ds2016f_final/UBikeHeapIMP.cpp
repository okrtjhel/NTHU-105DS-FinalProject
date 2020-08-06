#include "UBikeHeapIMP.h"
#include<algorithm>

// Add your code here

void UBikeHeapIMP::addUBikePtr(UBike* ubptr){
	//add to the end
	number++;
	(*this)[number]=ubptr;
    int cur=number;
    ubptr->heapIndex=cur;
	
	//if parent is greater, swap
    while(cur>1){
        if((*this)[cur/2]->mileage>(*this)[cur]->mileage){
        	(*this)[cur/2]->heapIndex=ubptr->heapIndex;
			ubptr->heapIndex=cur/2;
			UBike* tmp=(*this)[cur/2];
        	(*this)[cur/2]=(*this)[cur];
        	(*this)[cur]=tmp;
        	cur/=2;
		}
		else
			break;
    }
}

UBike* UBikeHeapIMP::removeUBikePtr(int heapIndex){
	//out of range
	if(heapIndex>number)
		return NULL;
	
	UBike* ub=(*this)[heapIndex];
	int cur=heapIndex;
	
	//End
	if(heapIndex==number){
    	(*this)[number]=NULL;
    	number--;
    	return ub;
    }
    
    //move last to fill the space
    (*this)[number]->heapIndex=heapIndex;
	(*this)[heapIndex]=(*this)[number];
	(*this)[number]=NULL;
	number--;
	
	//if parent is greater, swap
	//bubble-up
    while(true){
    	if(cur==1)
    		break;
        if((*this)[cur/2]->mileage>(*this)[cur]->mileage){
        	(*this)[cur/2]->heapIndex=cur;
			(*this)[cur]->heapIndex=cur/2;

			UBike* tmp=(*this)[cur/2];
			(*this)[cur/2]=(*this)[cur];
			(*this)[cur]=tmp;
			cur/=2;
		}
		else
			break;
    }
    
    //if the smallest child is smaller, swap
    //bubble-down
    while(true){
    	int lc=cur*2, rc=cur*2+1;
    	int sc;
    	if(rc<=number){
    		if((*this)[lc]->mileage<=(*this)[rc]->mileage)
				sc=lc;
			else
				sc=rc;
		}
		else if(lc<=number)
			sc=lc;
		else
			break;
		if((*this)[sc]->mileage<(*this)[cur]->mileage){
			(*this)[sc]->heapIndex=cur;
			(*this)[cur]->heapIndex=sc;

			UBike* tmp=(*this)[sc];
			(*this)[sc]=(*this)[cur];
			(*this)[cur]=tmp;
			cur=sc;
		}
		else break;
	}

    return ub;
}
