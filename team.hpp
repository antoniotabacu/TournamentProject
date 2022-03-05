#include "player.hpp"

class team{

private:

    int nr_players;
    string team_name;
    player *players;

public:

    string get_team_name();
    double getTeamPoints();
    void raiseTeamPoints();
    void deletePlayers();

    friend double get_team_points(team);

	friend istream & operator >> (istream &, team &);
	friend ostream & operator << (ostream &, const team &);
    //void generate_players_vector();
    team & operator=(const team &);

    //~team();

};

