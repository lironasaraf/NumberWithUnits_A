#ifndef NUMBER_WITH_UNITS 
#define NUMBER_WITH_UNITS
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
#include <stdexcept>
using namespace std;
namespace ariel {


	class NumberWithUnits {
		    private:
        static map<string, map<string, double>> unit;
        string type;
        int size;

    public:

        NumberWithUnits(double num, string unit)

        {
            this->size = num;	
            this->type = unit;
        }
        double getNumber(){
			return this->size;
		}
		string getUnit(){
			return this->type;
		}		
		public:	
			static void read_units(ifstream& stream);
			NumberWithUnits(int, string);
			//in/out
			friend ostream& operator<<(ostream& os, const NumberWithUnits& f1);
				
			
			friend istream& operator>>(istream& os, NumberWithUnits& f1);
				
			
			//+-
			NumberWithUnits operator-();
			friend NumberWithUnits operator*(double f1, NumberWithUnits f2);
			friend NumberWithUnits operator+(const NumberWithUnits& f1, const NumberWithUnits& f2);
			friend NumberWithUnits operator-(const NumberWithUnits& f1, const NumberWithUnits& f2);
			//equals
			friend bool operator>(const NumberWithUnits& f1, const NumberWithUnits& f2);
			bool operator <(NumberWithUnits const& f1);
			bool operator <=(NumberWithUnits const& f1);
			bool operator ==(NumberWithUnits const& f1);
			NumberWithUnits operator +=(NumberWithUnits const& f1);

	
	};
	

}



#endif