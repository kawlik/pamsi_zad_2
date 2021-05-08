#include <ctime>
#include <iostream>

#include "Kruskal.hh"
#include "Prima.hh"

using namespace std;

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

int main() {

    srand( time(NULL) );

    /*   *   *   *   *   *   *   *   *   *   */
    /*/
    GraphList test( 9 );
    // GraphMatrix test( 9 );
    
    test.insertEdge( 0, 1, 4 );
    test.insertEdge( 0, 7, 8 );
    test.insertEdge( 1, 2, 8 );
    test.insertEdge( 1, 7, 11 );
    test.insertEdge( 2, 3, 7 );

    test.insertEdge( 2, 8, 2 );
    test.insertEdge( 2, 5, 4 );
    test.insertEdge( 3, 4, 9 );
    test.insertEdge( 3, 5, 14 );
    test.insertEdge( 4, 5, 10 );

    test.insertEdge( 5, 6, 2 );
    test.insertEdge( 6, 7, 1 );
    test.insertEdge( 6, 8, 6 );
    test.insertEdge( 7, 8, 7 );
    /*/
    /*/
    
    test.print();

    cout << endl << endl;

    Edge * arr = new Edge [ test.getE() ];
    test.getAllEdgesTo( arr );

    heapSort<Edge>( arr, test.getE() );

    for( int i = 0 ; i < test.getE(); i++ ) {
        cout << " ( " << arr[i].v << " -> " << arr[i].w << " | [ " << arr[i].o << " ] ) " << endl;
    }

    /*/
    /*
        Prawidłowy wynik to

            6 -> 7
            2 -> 8
            5 -> 6
            0 -> 1
            2 -> 5
            2 -> 3
            0 -> 7
            3 -> 4
    /*/
    /**/

    GraphList test( 200 );
    // GraphMatrix test( 1000 );

    test.fill();

    cout << " Kruskal :: " << endl;
    Kruskal( test, true );

    cout << endl << endl;

    cout << " Prima :: " << endl;
    Prima( test, true );

    /**/
    /*
    GraphList test( 9 );
    // GraphMatrix test( 9 );
    
    test.insertEdge( 0, 1, 4 );
    test.insertEdge( 0, 7, 8 );
    test.insertEdge( 1, 2, 8 );
    test.insertEdge( 1, 7, 11 );
    test.insertEdge( 2, 3, 7 );

    test.insertEdge( 2, 8, 2 );    
    test.insertEdge( 2, 5, 4 );
    test.insertEdge( 3, 4, 9 );
    test.insertEdge( 3, 5, 14 );
    test.insertEdge( 4, 5, 10 );

    test.insertEdge( 5, 6, 2 );
    test.insertEdge( 6, 7, 1 );
    test.insertEdge( 6, 8, 6 );
    test.insertEdge( 7, 8, 7 );

    // test.removeEdge( 2, 8 );

    test.print();

    */
    /*   *   *   *   *   *   *   *   *   *   */

    cin.ignore();
}