#ifndef GRAPH_MATRIX_HH
#define GRAPH_MATRIX_HH

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

#include <iostream>
#include <utility>

//  define unser param
#define UNSET -1

//  parrent
#include "utility.hh"

using namespace std;

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

struct mEdge {

    bool isSet;
    int value;
};

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

class GraphMatrix {

    private:

        int E;
        int V;

        mEdge **matrix;

    public:

        //  life cycle
        GraphMatrix( int V );
        ~GraphMatrix();

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
        void fill( int density );
        void print();
};

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

#endif