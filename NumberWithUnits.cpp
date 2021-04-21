#include "NumberWithUnits.hpp"

namespace ariel {


	void NumberWithUnits::read_units(ifstream& stream)
	{
		    //     fstream my_file;
	//     my_file.open("units.txt", ios::in);
	//     if (!my_file) {
	// 	    cout << "No such file";
	//     }
	//     else {
	// 	    char ch;


    //         //
    //         string s1, s2, equal;
    //         double d1, d2;


	// 	    while (!my_file.eof())
    //         my_file >> d1 >> s1 >> equal >> d2 >> s2;
            
    //         map<string, double> temp = unit[s1];
    //         for(auto a : temp)
    //         {
    //             string key = a.first;
    //             double value = a.second;
    //         }

    //         unit[s1][s2] = d2;
    //         unit[s2][s1] = 1/d2;


            

	//     }
	//     my_file.close();
    string line;
    ifstream myfile ("units.txt");
    if (myfile.is_open())
    {
    while ( getline (myfile,line) )
    {
      cout << line << '\n';
    }
    myfile.close();
    }

    else cout << "Unable to open file"; 

	
	}

	NumberWithUnits::NumberWithUnits(int number, string type) {
	}

	NumberWithUnits  NumberWithUnits::operator-()
	{
		return *this;
	}
	ostream& operator<<(std::ostream& os, const NumberWithUnits& f1)
	{
		return os <<f1.size <<"["<< f1.type<<"]"<<"\n";;
	}
	istream& operator >> (istream& is, NumberWithUnits& f1)
	{
		return is;
	}


	NumberWithUnits operator*(double lhs, NumberWithUnits rhs) {

		return NumberWithUnits(1,"km");
	}

	NumberWithUnits operator+(const NumberWithUnits& a, const NumberWithUnits& b) {
			
		return NumberWithUnits(1,"km");
	}

	NumberWithUnits operator-(const NumberWithUnits& a, const NumberWithUnits& b) {
	
		return NumberWithUnits(1,"km");
	}

	bool operator>(const NumberWithUnits& a, const NumberWithUnits& b) {
		return true;
	}
	bool NumberWithUnits::operator<(NumberWithUnits const& rhs)
	{
		return true;
	}
	bool  NumberWithUnits::operator <=(NumberWithUnits const& rhs) {

		return true;
	}
	bool NumberWithUnits:: operator ==(NumberWithUnits const& rhs) {
		return true;
	}
	NumberWithUnits NumberWithUnits::operator +=(NumberWithUnits const& rhs) {
	
		return NumberWithUnits(1,"km");
	}

	

}