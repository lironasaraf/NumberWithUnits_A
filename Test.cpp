#include "doctest.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "NumberWithUnits.hpp"
using namespace ariel;



TEST_CASE("Good Tests") {
	ifstream units_file{"units.txt"};
    CHECK_NOTHROW(NumberWithUnits::read_units(units_file));
    NumberWithUnits a{2, "km"};   // 2 kilometers
    std::ostringstream streamA;
    streamA << a;
    CHECK(streamA.str() == "2[km]");
    CHECK((-a).getNumber() == -2);
    CHECK((-a).getUnit() == "km");
    CHECK((3*a).getNumber() == 6);
    CHECK((3*a).getUnit() == "km");
    CHECK((5*a).getNumber() == 10);
    CHECK((5*a).getUnit() == "km");
      CHECK((0.5*a).getNumber() == 1);
 
    NumberWithUnits b{300, "m"};  // 300 meters
    CHECK((a+b).getNumber() == 2.3);
    CHECK((a+b).getUnit() == "km");
    CHECK((b-a).getUnit() == "m");
    CHECK((b-a).getNumber() == -1700);
 
    CHECK((a>b) == true);
    CHECK((a<=b )== false);
     NumberWithUnits c{2000,"m"};
    CHECK((a== c) == true);
	


    istringstream sample_input{"700 [ kg ]"};
    sample_input >> a;
    std::ostringstream streamB;
    streamB << a;
    CHECK(streamB.str() == "700[kg]");



   
}



TEST_CASE("Negative test") {
    NumberWithUnits a{2, "km"}; 
    NumberWithUnits b{300, "m"};  // 300 meters
     CHECK_THROWS(a+b);
     CHECK_THROWS(a-b);
     
     CHECK_THROWS(new NumberWithUnits(300,"asdasd"));
    CHECK_THROWS(new NumberWithUnits(300,"kmkmkm"));

   
}
