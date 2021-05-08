#include <iostream>
#include <vector>

#include "Prima.hh"

using namespace std;

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

bool isInMST( int v, int w, bool * inMST ) {

    if( v == w ) { return false; }

    if( inMST[v] && inMST[w] ) { return false; }

    if( !inMST[v] && !inMST[w] ) { return false; }

    return true;
}

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

void Prima( GraphList target, bool print ) {

    bool * inMST;

    inMST = new bool [ target.getV() ];
    for( int i = 0; i < target.getV(); i++ ) {
        inMST[i] = false;
    }

    inMST[0] = true;

    int index = 0;
    int weight = 0;

    /*   *   *   *   *   *   *   *   *   *   */

    while( index < target.getV() - 1 ) {

        int min = HIGH;
        int v = -1;
        int w = -1;

        for( int i = 0; i < target.getV(); i++ ) {
            for( int j = 0; j < target.getV(); j++ ) {
                
                if( !target.areAdjacent( i, j ) ) { continue; }

                if( target.getEdge( i, j ).o < min ) {

                    if( isInMST( i, j, inMST )) {

                        min = target.getEdge( i, j ).o;
                        v = i;
                        w = j;
                    }
                }
            }
        }

        if( v != -1 && w != -1 ) {

            index++;
            weight += min;

            inMST[v] = true;
            inMST[w] = true;

            if( print ) {
                cout << v << " -> " << w << " | [ " << min << " ]"<< endl;
            }
        }
    }

    if( print ) {
        cout << "MST weight = " << weight << endl;
    }

    /*   *   *   *   *   *   *   *   *   *   */
    
    delete [] inMST;
}

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

void Prima( GraphMatrix target, bool print ) {

    bool * inMST;

    inMST = new bool [ target.getV() ];
    for( int i = 0; i < target.getV(); i++ ) {
        inMST[i] = false;
    }

    inMST[0] = true;

    int index = 0;
    int weight = 0;

    /*   *   *   *   *   *   *   *   *   *   */

    while( index < target.getV() - 1 ) {

        int min = HIGH;
        int v = -1;
        int w = -1;

        for( int i = 0; i < target.getV(); i++ ) {
            for( int j = 0; j < target.getV(); j++ ) {
                
                if( !target.areAdjacent( i, j ) ) { continue; }

                if( target.getEdge( i, j ).o < min ) {

                    if( isInMST( i, j, inMST )) {

                        min = target.getEdge( i, j ).o;
                        v = i;
                        w = j;
                    }
                }
            }
        }

        if( v != -1 && w != -1 ) {

            index++;
            weight += min;

            inMST[v] = true;
            inMST[w] = true;

            if( print ) {
                cout << v << " -> " << w << " | [ " << min << " ]"<< endl;
            }
        }
    }

    if( print ) {
        cout << "MST weight = " << weight << endl;
    }

    /*   *   *   *   *   *   *   *   *   *   */
    
    delete [] inMST;
}