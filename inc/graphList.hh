#ifndef GRAPH_LIST_HH
#define GRAPH_LIST_HH

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

#include <iostream>
#include <utility>
#include <vector>

//  parrent
#include "utility.hh"

using namespace std;

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

struct Node {

    Node * next;
    
    int goal;
    int rank;
};

void push( Node * & head, int goal, int rank );
void popf( Node * & head );
void pout( Node * & head );


/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

class GraphList {

    private:

        int E;
        int V;

        Node ** list;

    public:

        //  life cycle
        GraphList( int V );
        ~GraphList();

        //  usage
        void getAllEdgesTo( Edge * arr );

        //  update
        void insertEdge( int v, int w, int o );
        void removeEdge( int v, int w );

        bool areAdjacent( int v, int w );
        Edge getEdge( int v, int w );

        inline int getE() { return this->E; }
        inline int getV() { return this->V; }

        //  maintenance
        void print();
        void fill();
};

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

#endif