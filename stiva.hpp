#include "match.hpp"

class stiva{

private:

    team winner_team;
    stiva* next;

public:

    friend void push(stiva** , team);
    friend void delete_stiva(stiva**);
    //friend stiva* generate_winners_bracket(q*,int*);
    stiva* getNext();
    team getWinnerTeam();
    void setWinnerTeam(team);

};
