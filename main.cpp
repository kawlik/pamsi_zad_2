#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include <ctime>

#include "Kruskal.hh"
#include "Prima.hh"

using namespace std;

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

int main( int argc, char * argv[] ) {

    srand( time(NULL) );

    /*   *   *   *   *   *   *   *   *   *   */

    if( argc < 3 ) {
        throw runtime_error( "Size ore output has not been specify!" );
    }

    int size;
    string fileOutput;

    size = atoi(argv[1]);
    fileOutput = argv[2];

    /*   *   *   *   *   *   *   *   *   *   */

    int density;
    int repeats;

    cout << " Gęstość grafu w % : ";
    cin >> density;

    cout << " Ilość powtórzeń N : ";
    cin >> repeats;

    clock_t start, stop;

    long unsigned int timeGLK = 0;
    long unsigned int timeGMK = 0;

    long unsigned int timeGLP = 0;
    long unsigned int timeGMP = 0;

    /*   *   *   *   *   *   *   *   *   *   */

    //  Testy algorytmu Kruskala
    for( int i = 0; i < repeats; i++ ) {

        GraphList GL( size );
        GraphMatrix GM( size );

        GM.fill( density );
        GL.fill( density );

        /*   *   *   *   *   */

        start = clock();

        Kruskal( GL, false );

        stop = clock();

        timeGLK += stop - start;

        /*   *   *   *   *   */

        start = clock();

        Kruskal( GM, false );

        stop = clock();

        timeGMK += stop - start;
    }

    //  Testy algorytmu Prima
    for( int i = 0; i < repeats; i++ ) {

        GraphList GL( size );
        GraphMatrix GM( size );

        GL.fill( density );
        GM.fill( density );

        /*   *   *   *   *   */

        start = clock();

        Prima( GL, false );

        stop = clock();

        timeGLP += stop - start;

        /*   *   *   *   *   */

        start = clock();

        Prima( GM, false );

        stop = clock();

        timeGMP += stop - start;
    }

    cout << endl << endl;
    cout << " Graf zaimplementowany na liście sąsiedzctwa :: " << endl;
    cout << " -> całkowity czas wykonywania algorytmu Kruskala: " << 1000000 * timeGLK / CLOCKS_PER_SEC << " us" << endl;
    cout << " -> całkowity czas wykonywania algorytmu Prima: " << 1000000 * timeGLK / CLOCKS_PER_SEC << " us" << endl;
    cout << endl;
    cout << " -> średni czas wykonywania algorytmu Kruskala: " << ( 1000000 / repeats ) * timeGLK / CLOCKS_PER_SEC << " us" << endl;
    cout << " -> średni czas wykonywania algorytmu Prima: " << ( 1000000 / repeats ) * timeGLK / CLOCKS_PER_SEC << " us" << endl;

    cout << endl << endl;
    cout << " Graf zaimplementowany na macierzy sąsiedzctwa :: " << endl;
    cout << " -> całkowity czas wykonywania algorytmu Kruskala: " << 1000000 * timeGMK / CLOCKS_PER_SEC << " us" << endl;
    cout << " -> całkowity czas wykonywania algorytmu Prima: " << 1000000 * timeGMP / CLOCKS_PER_SEC << " us" << endl;
    cout << endl;
    cout << " -> średni czas wykonywania algorytmu Kruskala: " << ( 1000000 / repeats ) * timeGMK / CLOCKS_PER_SEC << " us" << endl;
    cout << " -> średni czas wykonywania algorytmu Prima: " << ( 1000000 / repeats ) * timeGMP / CLOCKS_PER_SEC << " us" << endl;

    /*   *   *   *   *   *   *   *   *   *   */
    /*/
    GraphList test( 20 );
    // GraphMatrix test( 20 );

    test.fill( 25 );

    cout << " Kruskal :: " << endl;
    Kruskal( test, true );

    cout << endl << endl;

    cout << " Prima :: " << endl;
    Prima( test, true );

    test.print();
    /*/
    /*   *   *   *   *   *   *   *   *   *   */

    cin.ignore();
}