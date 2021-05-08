#ifndef KRUSKAL_HH
#define KRUSKAL_HH

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

#include <iostream>
#include <vector>

#include "graphList.hh"
#include "graphMatrix.hh"

using namespace std;

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

class UniqueSet {

    private:

        int n;      //  size
        int * p;    //  parrent node
        int * r;    //  rank value

    /*   *   *   *   *   *   *   *   *   *   */

    public:

        UniqueSet( int n );

        void merge( int x, int y );
        int find( int v );
};

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

void Kruskal( GraphMatrix target, bool print );
void Kruskal( GraphList target, bool print );

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

#endif