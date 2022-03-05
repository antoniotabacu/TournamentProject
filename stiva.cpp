#include "stiva.hpp"

stiva* stiva::getNext(){

    return next;

}

team stiva::getWinnerTeam(){

    /*ofstream refileout("coada.txt",ios::app);
    refileout<<"|"<<winner_team.get_team_name()<<"|"<<endl;*/
    return winner_team;

}

void stiva::setWinnerTeam(team w){

    winner_team=w;

}

void push(stiva** top, team winner){

    stiva* newWinner=new stiva;

    newWinner->winner_team=winner;
    newWinner->next=*top;
    *top=newWinner;

}

void delete_stiva(stiva** top){

    stiva* aux;
    while((*top)!=NULL){
        aux=*top;
        *top=(*top)->next;
        free(aux);
    }

}

/*stiva* generate_winners_bracket(q* que, int* n){

    match *i;
    stiva *s=NULL;
    s=new stiva;

    for(i=que->getFirst();i!=NULL;i=i->getNextMatch()){

        if(i->getTeam1().getTeamPoints()>=i->getTeam2().getTeamPoints()){

            i->getTeam1().raiseTeamPoints();
            push(&s,i->getTeam1());
            (*n)++;

        }
        else{

            i->getTeam2().raiseTeamPoints();
            push(&s,i->getTeam2());
            (*n)++;
        }

    }

    return s;



}*/
