#include "stiva.hpp"

class q{

private:

    match *first;
    match *last;

public:

    friend q* generate_q(listt *);
    friend void add_in_q(q* , match);
    friend void print_queue(q*,ofstream&);
    friend void print_winners(stiva*,ofstream&);

    match* getFirst();
    match* getLast();

    friend stiva* generate_stiva(q*, int*);
    friend stiva* generate_stiva_loosers(q*);
    friend q* regenerate_q(stiva*);
    friend void delete_q(q*);
    friend int isEmpty(q*);
};
