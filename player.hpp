#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cctype>
#include <algorithm>

using namespace std;

class player{

private:

    string first_name;

    string second_name;

    int nr_points;

public:

    void raisePoints();

    int get_nr_points();

	friend istream & operator >> (istream &, player &);
	friend ostream & operator << (ostream &, const player &);

};
