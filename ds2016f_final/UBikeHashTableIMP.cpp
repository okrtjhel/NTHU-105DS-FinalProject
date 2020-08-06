#include "UBikeHashTableIMP.h"
#include<string>

using namespace std;
// Add your code here

int getAddress(string s);

void UBikeHashTableIMP::addUBikePtr(UBike* ubptr){
	//calculate address
	int addr=getAddress(ubptr->license);
	
	//put into Hash Table
	(*this)[addr].push_front(ubptr);
}

UBike* UBikeHashTableIMP::findUBikePtr(std::string license, bool toRemove){
	//calculate address
	int addr=getAddress(license);
	
	//search in Hash Table
	UBike* u;
	UBikePtrList::iterator it;	
	for(it=(*this)[addr].begin();it!=(*this)[addr].end();++it){
		if((*it)->license==license){
			u=(*it);
			if(toRemove)
				(*this)[addr].remove(*it);
			return u;
		}
	}
	return NULL;
}

int getAddress(string s){
	int num=0,sum=0;
	
	//get decimal	
	if(isdigit(s[0]))
		num=s[0]-'0';
	else
		num=s[0]-'A'+10;
	for(int i=1;i<5;++i){
		if(isdigit(s[i]))
			num=num*29+s[i]-'0';
		else
			num=num*29+s[i]-'A'+10;
	}
	
	//convert 6~13 bit to decimal
	for(int i=6;i<14;++i){
		sum+=(1<<(i-6))*(1&(num>>(i-1)));
	}
	return sum;	
}
