//===================THE-EDITS-OF-THIS-FILE-WILL-BE-DISCARDED===================

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "../UBikeSystemIMP.h"

static void basicTest
(std::string TransFile, std::string MapFile, std::string AnsFile)
{
    try
    {
        UBikeSystemIMP ubSystem;
        
        //init the distance table
        ubSystem.InitDistTable(MapFile);
        
        //parse the transaction file
        std::ifstream ifs(TransFile);
        
        //process each command
        std::string trs;
        while( ifs >> trs )
        {
            if( trs=="NewBike" )
            {
                std::string classType, license, station;
                int mile;
                ifs >> classType >> license >> mile >> station ;
                ubSystem.NewBike( classType, license, mile, station );
            }
            else if( trs=="JunkIt" )
            {
                std::string license;
                ifs >> license;
                ubSystem.JunkIt( license );
            }
            else if( trs=="Rent" )
            {
                std::string classType, station;
                ifs >> station >> classType;
                ubSystem.Rent( classType, station );
            }
            else if( trs=="Return" )
            {
                std::string station, license;
                int returnMile;
                ifs >> station >> license >> returnMile;
                ubSystem.Return( station, license, returnMile );
            }
            else if( trs=="Trans" )
            {
                std::string station, license;
                ifs >> station >> license;
                ubSystem.Trans( station, license );
            }
        }
        
        ifs.close();
            
        //read the answer texts
        std::ifstream ifsAns( AnsFile );
        std::string ansText( (std::istreambuf_iterator<char>(ifsAns)),
                             (std::istreambuf_iterator<char>()      ) );
        ifsAns.close();

        //your output
        std::ostringstream oss;
        oss << ubSystem.toString();
        std::cout << ubSystem.toString() << std::endl;

        //release the allocated memory
        ubSystem.ShutDown();
        
        //compare the results
        if( oss.str() == ansText )
            std::cout << "PASS!" << std::endl;
        else
            std::cout << "FAIL." << std::endl;
    }
    catch(const char* str)
    {
        std::cout << "The implementation is not done. : [" << str << "]" << std::endl;
    }
}

int main(int argc, char *argv[])
{
// Public Test Cases
    std::cout << "test case 1: ";
    basicTest( "tc1/cm.in", "tc1/map.in", "tc1/ans.out" );
    
    std::cout << "test case 2: ";
    basicTest( "tc2/cm.in", "tc2/map.in", "tc2/ans.out" );
    
    std::cout << "test case 3: ";
    basicTest( "tc3/cm.in", "tc3/map.in", "tc3/ans.out" );

// Hidden Test Cases
    std::cout << "test case 4: ";
    basicTest( "tc4/testCase", "tc4/testMap", "tc4/output" );
//
    std::cout << "test case 5: ";
    basicTest( "tc5/testCase", "tc5/testMap", "tc5/output" );
//
//    std::cout << "test case 6: ";
//    basicTest( "tc6/cm.in", "tc6/map.in", "tc6/ans.out" );
//
//    std::cout << "test case 7: ";
//    basicTest( "tc7/cm.in", "tc7/map.in", "tc7/ans.out" );

	return 0;
}

//===================THE-EDITS-OF-THIS-FILE-WILL-BE-DISCARDED===================
