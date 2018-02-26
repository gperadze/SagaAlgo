#include <iostream>
#include <string>
#include <boost/archive/tmpdir.hpp>

#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>

#include "SerializationDemo.h"
#include "Quarks.h"

void save_gps(const gps_position &s, const char * filename){
    // make an archive
    std::ofstream ofs(filename);
    assert(ofs.good());
    boost::archive::xml_oarchive oa(ofs);
    oa << BOOST_SERIALIZATION_NVP(s);
}



void save_schedule(const bus_schedule &s, const char * filename){
    // make an archive
    std::ofstream ofs(filename);
    assert(ofs.good());
    boost::archive::xml_oarchive oa(ofs);
    oa << BOOST_SERIALIZATION_NVP(s);
}


void
restore_schedule(bus_schedule &s, const char * filename)
{
    // open the archive
    std::ifstream ifs(filename);
    assert(ifs.good());
    boost::archive::xml_iarchive ia(ifs);

    // restore the schedule from the archive
    ia >> BOOST_SERIALIZATION_NVP(s);
}


void
restore_gps(gps_position &s, const char * filename)
{
    // open the archive
    std::ifstream ifs(filename);
    assert(ifs.good());
    boost::archive::xml_iarchive ia(ifs);

    // restore the schedule from the archive
    ia >> BOOST_SERIALIZATION_NVP(s);
}




int main(int argc, char *argv[])
{   
	gps_position gps(34, 135, 52.560f);

    std::string f("C:\\Saga\\Algo\\Algo\\Data\\GPS.xvl"); 

    // save the schedule
    save_gps(gps, f.c_str());
	gps_position new_gps;
	restore_gps(new_gps, f.c_str());


    // make the schedule
    bus_schedule original_schedule;

    // fill in the data
    // make a few stops
    bus_stop *bs0 = new bus_stop_corner(
        gps_position(34, 135, 52.560f),
        gps_position(134, 22, 78.30f),
        "24th Street", "10th Avenue"
    );
    bus_stop *bs1 = new bus_stop_corner(
        gps_position(35, 137, 23.456f),
        gps_position(133, 35, 54.12f),
        "State street", "Cathedral Vista Lane"
    );
    bus_stop *bs2 = new bus_stop_destination(
        gps_position(35, 136, 15.456f),
        gps_position(133, 32, 15.300f),
        "White House"
    );
    bus_stop *bs3 = new bus_stop_destination(
        gps_position(35, 134, 48.789f),
        gps_position(133, 32, 16.230f),
        "Lincoln Memorial"
    );

    // make a  routes
    bus_route route0;
    route0.append(bs0);
    route0.append(bs1);
    route0.append(bs2);

    // add trips to schedule
    original_schedule.append("bob", 6, 24, &route0);
    original_schedule.append("bob", 9, 57, &route0);
    original_schedule.append("alice", 11, 02, &route0);

    // make aother routes
    bus_route route1;
    route1.append(bs3);
    route1.append(bs2);
    route1.append(bs1);

    // add trips to schedule
    original_schedule.append("ted", 7, 17, &route1);
    original_schedule.append("ted", 9, 38, &route1);
    original_schedule.append("alice", 11, 47, &route1);

    // display the complete schedule
    std::cout << "original schedule";
//    std::cout << original_schedule;
    std::string filename("C:\\Saga\\Algo\\Algo\\Data\\GPX.xvl"); 

    // save the schedule
    save_schedule(original_schedule, filename.c_str());

    // make  a new schedule
    bus_schedule new_schedule;

	restore_schedule(new_schedule, filename.c_str());

    delete bs0;
    delete bs1;
    delete bs2;
    delete bs3;


	std::string fn("C:\\Saga\\Algo\\Algo\\Data\\Quark.xvl"); 
	GQuarks::BQuark* q = new GQuarks::BQuark( GQuarks::EShape::kSCircle,
											 GQuarks::ESize::kSzLarge, 
		                                     GQuarks::EColor::kCGreen);

	GQuarks::save_quark(*q,fn.c_str() );

	GQuarks::BQuark q1;
	GQuarks::restore_quark( q1, fn.c_str());


    return 0;
}