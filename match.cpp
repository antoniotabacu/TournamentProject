#include "match.hpp"

match generate_match(team team1, team team2){

    match matchh;

    matchh.team1=team1;
    matchh.team2=team2;
    matchh.next_match=NULL;

    return matchh;

}

void match::setNextMatch(match *m){

    this->next_match=m;

}

void match::setTeam1(team t){

    this->team1=t;

}

void match::setTeam2(team t){

    this->team2=t;

}
