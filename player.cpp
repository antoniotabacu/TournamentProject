#include "player.hpp"

istream& operator>> (istream& input, player& p){

	char buf[100];

	input.getline(buf, 100, ' ');
	p.first_name=buf;

	input.getline(buf, 100, ' ');
	p.second_name=buf;

	input>>p.nr_points;

	return input;

}

ostream& operator<< (ostream& output, const player& p){

	output<<p.first_name<<" ";
	output<<p.second_name<<" ";
	if(p.nr_points!=1){
        output<<p.nr_points<<" puncte\n";
	}
	else{
        output<<p.nr_points<<" punct\n";
	}

    return output;

}

int player::get_nr_points(){

    return nr_points;

}

void player::raisePoints(){

    nr_points++;

}

