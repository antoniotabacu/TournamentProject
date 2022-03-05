#include "team.hpp"

class listt{

//public:

private:

    team list_element;
    listt *next;

public:

    friend listt* generate_list(ifstream&,int);
    friend void nr_teams(ifstream&,int *);
    friend int nr_teams_two(int);
    friend void remove_element(listt **,int*);
    friend void print_list(listt *,ofstream&);

    friend void delete_list(listt **);

    listt* getNext(){

        return next;

    }

    team getTeam(){

        return list_element;

    }


};

