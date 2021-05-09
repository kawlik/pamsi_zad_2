#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include <ctime>

#include "Kruskal.hh"
#include "Prima.hh"

using namespace std;

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

void test( int density, int repeats, int size );

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

int main( int argc, char * argv[] ) {

    srand( time(NULL) );

    /*   *   *   *   *   *   *   *   *   *   */

    if( argc < 2 ) {
        throw runtime_error( "Size has not been specify!" );
    }

    int size = atoi( argv[1] );

    /*   *   *   *   *   *   *   *   *   *   */

    int density[4] = { 25, 50, 75, 100 };
    int repeats;

    cout << " Ilość powtórzeń N : ";
    cin >> repeats;

    /*   *   *   *   *   *   *   *   *   *   */

    for( int i = 0; i < 4; i++ ) {
        test( density[i], repeats, size );
    }

    /*   *   *   *   *   *   *   *   *   *   */

    cin.ignore();
}

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

void test( int density, int repeats, int size ) {


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

        GL.fill( density );
        GM.fill( density );

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

    cout << endl << endl << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << " Testy dla gęstości :: " << density << " %" << endl;

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
}