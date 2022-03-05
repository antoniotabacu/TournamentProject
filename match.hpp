#include "list.hpp"

class match{

private:

    team team1;
    team team2;

    match* next_match;

public:

    team getTeam1(){

        return team1;

    }

    team getTeam2(){

        return team2;

    }

    match* getNextMatch(){

        return next_match;

    }

    void setTeam1(team);
    void setTeam2(team);

    void setNextMatch(match*);

    friend match generate_match(team, team);

};
