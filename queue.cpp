#include "queue.hpp"

match generate_match(team team1, team team2);

match* q::getFirst(){

    return first;

}

match* q::getLast(){

    return last;

}

void add_in_q(q *que, match m){

    //cout<<endl<<"aici nu crapa---add in q"<<endl;

    match *new_match;
    new_match=new match;

    new_match->setTeam1(m.getTeam1());
    new_match->setTeam2(m.getTeam2());
    new_match->setNextMatch(NULL);



    if(que->last==NULL){

         que->last=new_match;

    }
    else{
        (que->last)->setNextMatch(new_match);
        que->last=new_match;
        //cout<<endl<<"aici nu crapa---add in q"<<endl;
    }

    if(que->first==NULL){
        que->first=que->last;
    }

    //cout<<endl<<"aici nu crapa---FINAL DE add in q"<<endl;
}

q* generate_q(listt *p){

    //cout<<endl<<"aici nu crapa---generate inainte de while"<<endl;

    q *que;
    que=new q;

    que->first=que->last=NULL;

    while(p!=NULL){

        //cout<<endl<<"aici nu crapa---in while"<<endl;

        match aux;
        aux=generate_match(p->getTeam(),(p->getNext())->getTeam());
        add_in_q(que,aux);

        /*ofstream refileout("rezultat.txt",ios::app);
        refileout<<p->getTeam().get_team_name()<<" cu punctajul "<<p->getTeam().getTeamPoints()<<"--VS--"<<p->getNext()->getTeam().get_team_name()<<" cu punctajul "<<p->getNext()->getTeam().getTeamPoints()<<endl;
        */
        p=(p->getNext())->getNext();

    }

    return que;

}

stiva* generate_stiva(q* que, int* n){

    (*n)=0;
    match* i;
    stiva* winners=NULL;
    for(i=que->first;i!=NULL;i=i->getNextMatch()){
        if(i->getTeam1().getTeamPoints()>i->getTeam2().getTeamPoints()){

            i->getTeam1().raiseTeamPoints();
            push(&winners,i->getTeam1());
            (*n)++;

            /*ofstream refileout("coada.txt",ios::app);
            refileout<<i->getTeam1().get_team_name()<<endl;*/

        }
        else{
            i->getTeam2().raiseTeamPoints();
            push(&winners,i->getTeam2());
            (*n)++;

            /*ofstream refileout("coada.txt",ios::app);
            refileout<<i->getTeam2().get_team_name()<<endl;*/
        }
    }

    return winners;

}

stiva* generate_stiva_loosers(q* que){

    //(*n)=0;
    match* i;
    stiva* loosers=NULL;
    for(i=que->first;i!=NULL;i=i->getNextMatch()){
        if(i->getTeam1().getTeamPoints()<i->getTeam2().getTeamPoints()){

            i->getTeam1().raiseTeamPoints();
            push(&loosers,i->getTeam1());
            //(*n)++;

        }
        else{
            i->getTeam2().raiseTeamPoints();
            push(&loosers,i->getTeam2());
            //(*n)++;
        }
    }

    return loosers;

}

q* regenerate_q(stiva* s){

    q *que;
    que=new q;

    que->first=que->last=NULL;

    while(s!=NULL){

        team team1, team2;
        match match;

        team1=s->getWinnerTeam();
        team2=s->getNext()->getWinnerTeam();

        /*ofstream refileout("rezultat.txt",ios::app);
        refileout<<team1.get_team_name()<<" cu punctajul "<<team1.getTeamPoints()<<"--VS--"<<team2.get_team_name()<<" cu punctajul "<<team2.getTeamPoints()<<endl;
        */

        match=generate_match(team1,team2);

        add_in_q(que,match);
        s=s->getNext()->getNext();
    }

    return que;

}

void print_queue(q* que,ofstream& refileout){

    match* i;

    //ofstream refileout("r.out",ios::app);

    for(i=que->first;i!=NULL;i=i->getNextMatch()){

        refileout<<i->getTeam1().get_team_name();

        for(int j=0;j<33-(i->getTeam1().get_team_name().length());j++){
            refileout<<" ";
        }

        refileout<<"-";

        for(int j=0;j<33-(i->getTeam2().get_team_name().length());j++){
            refileout<<" ";
        }

        refileout<<i->getTeam2().get_team_name()<<endl;

    }

}

void print_winners(stiva* s,ofstream& refileout){

    //ofstream refileout("r.out",ios::app);

    while(s!=NULL){

        string crtName = s->getWinnerTeam().get_team_name();
        refileout<<s->getWinnerTeam().get_team_name();
        for(int j=0;j<34-(s->getWinnerTeam().get_team_name().length());j++){
            refileout<<" ";
        }
        refileout<<"-  ";
        refileout<<setprecision (2)<<fixed<<s->getWinnerTeam().getTeamPoints()<<endl;

        s=s->getNext();
    }


}

void delete_q(q* q){

    match *aux;
    while(!isEmpty(q)){
        aux=q->first;
        q->first=q->first->getNextMatch();
        free(aux);
    }
    free(q);

}


int isEmpty(q* q){

    return (q->first==NULL);

}

