#ifndef UTILITY_HH
#define UTILITY_HH

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

#include <iostream>
#include <vector>

//  define max int range
#define HIGH 2147483647

using namespace std;

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

struct Edge {

    int v; //  first vertex
    int w; //  second vertex
    int o;          //  weight

    /*   *   *   *   *   *   *   *   *   *   */

    void operator = ( Edge );
    bool operator > ( Edge );
    bool operator < ( Edge );

    bool operator == ( Edge );
    bool operator >= ( Edge );
    bool operator <= ( Edge );
};

istream & operator >> ( istream &, Edge & );
ostream & operator << ( ostream &, Edge & );

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

template<typename T>
T getRand( int min, int max ) {

    T tmp = (rand() % ( max - min )) + min;
    return tmp;
}

template <typename T>
void heap( T *arr, int *args ) {

    int n = args[0];
    int i = args[1];

    int high = i;
    int l = 2*i + 1;
    int r = 2*i + 2;


    if(( l < n ) && ( arr[l] > arr[high] )) {
        high = l;
    }

    if(( r < n ) && ( arr[r] > arr[high] )) {
        high = r;
    }

    if( high != i ) {

        int new_args[] = { n, high };

        swap( arr[i], arr[high] );
        heap( arr, new_args );
    }
}

template <typename T>
void heapSort( T *arr, int n ) {

    for( int i = n / 2 - 1; i >= 0; i-- ) {
        int new_args[] = { n, i };
        heap( arr, new_args );
    }

    for( int i = n - 1; i >= 0; i-- ) {

        int new_args[] = { i, 0 };

        swap( arr[0], arr[i] );
        heap( arr, new_args );
    }
}

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

#endif