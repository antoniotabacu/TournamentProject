#include "list.hpp"

int nr_teams_two(int n){

    int nr_teams;

    /*ifstream file("d.in");
    file>>nr_teams;
    file.close();*/

    nr_teams=n;

    int power_two=1;

    while(power_two<nr_teams){

        power_two=power_two*2;

    }

    return (power_two/2);

}

void nr_teams(ifstream& file, int *n){

    int nr_teams;

    //ifstream file("d.in");
    file>>nr_teams;
    //file.close();
    *n=nr_teams;

    //return nr_teams;

}

listt* generate_list(ifstream& file,int n){

    int nr_elements;
    listt *root, *p, *q;

    /*ifstream file("d.in");
    if(!file){
        cout<<"Eroare!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
    }*/

    //file>>nr_elements;
    //nr_elements=nr_teams();

    nr_elements=n;

    p=new listt;
    file>>p->list_element;

    p->next=NULL;

    root=p;

    /*for(int i=1;i<nr_elements;i++){

        q=new listt;
        file>>q->list_element;
        q->next=NULL;
        p->next=q;
        p=q;

    }*/

    for(int i=1;i<nr_elements;i++){

        q=new listt;
        file>>q->list_element;
        q->next=root;
        root=q;


    }



    return root;

}

void remove_element(listt **root,int *n){

    listt *p;

    //CALCUL MINIM
    p=*root;

    int iterations;
    //int old_nr_teams=nr_teams();
    int old_nr_teams=*n;
    int new_nr_teams=nr_teams_two(old_nr_teams);
    (*n)=new_nr_teams;

    if(old_nr_teams==new_nr_teams*2){
        iterations=0;
        (*n)=old_nr_teams;
    }
    else{
        iterations=old_nr_teams-new_nr_teams;
    }
    /*cout<<endl<<"Numar Total Echipe: "<<old_nr_teams<<endl;
    cout<<endl<<"Numar Echipe care trebuie sa ramana: "<<new_nr_teams<<endl;
    cout<<endl<<"Echipe de eliminat: "<<iterations<<endl;*/

    int i;

    for(i=0;i<iterations;i++){

    int ok=1;

        //cout<<endl<<"NU CRAPA "<<ok<<endl;
            ok++;

        //cout<<endl<<" INTRAREA"<<i+1<<endl;

        double minim=999;

        p=*root;

        while(p!=NULL){

            /*if(get_team_points(p->list_element)<minim){
                minim=get_team_points(p->list_element);
            }*/

            if(p->list_element.getTeamPoints()<minim){
                minim=p->list_element.getTeamPoints();
            }

            p=p->next;
        }

        //cout<<minim<<endl;
        ////////////////

        p=*root;
        //cout<<endl<<"NU CRAPA"<<endl;

        while(p!=NULL){


            if((p==*root)&&(p->list_element.getTeamPoints()==minim)){

                //cout<<endl<<"Este eliminata "<<p->list_element.get_team_name()<<" cu punctajul "<<p->list_element.getTeamPoints()<<endl;

                (*root)=p->next;

                break;

            }



            if((p->next)->list_element.getTeamPoints()==minim){

                //cout<<endl<<"Este eliminata "<<p->next->list_element.get_team_name()<<" cu punctajul "<<p->next->list_element.getTeamPoints()<<endl;
                p->next=(p->next)->next;



                break;

            }

            if(((p->next)->list_element.getTeamPoints()==minim)&&((p->next)->next==NULL)){

                //cout<<endl<<"Este eliminata "<<p->next->list_element.get_team_name()<<" cu punctajul "<<p->next->list_element.getTeamPoints()<<endl;
                p->next=NULL;
                break;
            }

            p=p->next;
        }

    }

}

void print_list(listt *p,ofstream& refileout){

    //listt *p;
    //p=root;

    //ofstream refileout("r.out",ios::app);

    while(p!=NULL){

        refileout<<(p->list_element.get_team_name())<<endl;
        //" -- Punctaj: "<<get_team_points(p->list_element)<<"\n";
        p=p->next;
    }

    //refileout<<endl;
}

void delete_list(listt **root){

    listt* rootcopy=*root;
    while(*root!=NULL){
        rootcopy=(*root)->next;
        free(*root);
        *root=rootcopy;
    }
}
