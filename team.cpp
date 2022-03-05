#include "team.hpp"

/*void team::generate_players_vector(){

    int i;

    players=new player[nr_players+1];

    for(i=0;i<nr_players;i++){

    }

}

*/

/*team::~team(){

    delete []players;

}*/

void team::deletePlayers(){

    delete []players;

}

istream& operator>> (istream& input, team& t){

	char buf[100];

	input>>t.nr_players;
	input.getline(buf, 100, ' ');
	input.getline(buf, 100, '\n');
    t.team_name=buf;
    //t.team_name.erase(" ");
    t.team_name.erase(remove_if(t.team_name.end()-1, t.team_name.end(), ::isspace), t.team_name.end());
	t.players=new player[t.nr_players+1];

	for(int i=0;i<t.nr_players;i++){
		input>>(player &)t.players[i];
	}
	input.getline(buf, 100, '\n');

	return input;

}

ostream& operator<< (ostream& output, const team& t){

	output<<t.nr_players;
	output<<"|"<<t.team_name<<"|";
	output<<"\n";
	for(int i=0; i<t.nr_players;i++){
        output<<(player &)t.players[i];
	}

    //cout<<endl;
    return output;
}

double get_team_points(team t){

    double r=0;

    for(int i=0;i<t.nr_players;i++){
        r=r+t.players[i].get_nr_points();
    }

    return (r/t.nr_players);

}

string team::get_team_name(){
    return team_name;
}

double team::getTeamPoints(){

    double r=0;

    for(int i=0;i<nr_players;i++){
        r=r+players[i].get_nr_points();
    }

    //return (float)(r/nr_players);

    r=r/nr_players;
    return r;
    /*float value = (int)(r * 100 + 0.5);
    return (float)value / 100;*/

}

void team::raiseTeamPoints(){

    for(int i=0;i<nr_players;i++){
        players[i].raisePoints();
    }

}

team & team::operator=(const team & t){

    nr_players=t.nr_players;
    team_name=t.team_name;

    players=new player[nr_players];
    for(int i=0;i<nr_players;i++){
        players[i]=t.players[i];
    }

    return *this;

}
