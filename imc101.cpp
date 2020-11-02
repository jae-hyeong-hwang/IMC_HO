#include <IMC/Spec/Abort.hpp>
#include <IMC/Base/ByteBuffer.hpp>
#include <IMC/Spec/PlanSpecification.hpp>
#include <IMC/Spec/PlanManeuver.hpp>
#include <IMC/Spec/Loiter.hpp>
#include <IMC/Spec/SetEntityParameters.hpp>
#include <IMC/Spec/EntityParameter.hpp>
#include <IMC/Base/Packet.hpp>
#include <IMC/Base/ByteBuffer.hpp>
#include <UDP/DatagramSocket.h>
#define LAUVXPLORE1 (30)
using namespace IMC;

int main() 
	{
    char localhost[] = "127.0.0.1";
    
    SetEntityParameters setParam;
    SetParam.name = "LBL";

	
	EntityParameter entParam
	entParam.setAbbrev('EntityParameter');
	entParam.setName('Active');
	entParam.setValue('false');

    
 	Loiter loiter;
 	loiter.setTimeOut(10000);
	loiter.LAT(0.7188016469344056);
	loiter.LON(-0.15194250254286037);
	loiter.setZ(3);
	loiter.setZUnitsStr(1);
	loiter.setDuration(300);
	loiter.setSpeed(1000);
	loiter.setSpeedUnitsStr(1);
	loiter.setType(1);
	loiter.setRadius(20);
	loiter.seetLength(1);
	loiter.setBearing(0);
	loiter.setDirection(Loiter.DIRECTION 1);
	loiter.getCustom();

	PlanManeuver pManeuver
	pManeuver.getAbbrev();
	pManeuver.setManeuverId(1);
 	pManeuver.setData(sprintf('"abbrev":"Loiter"');
 

	PlanSpecification plansp; //create planspecification message
    plansp.setAbbrev(PlanSpecification);
    plansp.getTimeStamp();   // set timestamp to current time
    plansp.setDst(30);
    plansp.setDstEnt(255);
    plansp.setPlanId(cmd-lauv-xplore-1);
    plansp.setDescription();
    plansp.setVnamespace();
    plansp.setVariables();
    plansp.setStartManId(1);
    plansp.toJSON(ste::cout);
	plansp.setStartActions();
	plansp.setEndActions();



	plansp.toJSON(std::cout);



    
    int size = plansp.getSerializationSize();    // calculate bytes required for serialization
    char buffer[size];                          // allocate same number of bytes
    
    Packet::serialize(&plansp, (uint8_t *) buffer, size);
    std::cout << buffer;


}
