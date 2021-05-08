#include <iostream>
#include <vector>

#include "Kruskal.hh"

using namespace std;

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

UniqueSet::UniqueSet( int n ) {
    this->n = n;

    this->p = new int [ n + 1 ];
    this->r = new int [ n + 1 ];

    for( int i = 0; i < n + 1; i++ ) {
        this->p[i] = i;
        this->r[i] = 0;
    }
}

int UniqueSet::find( int v ) {

    if( v != this->p[v] ) {
        this->p[v] = this->find( this->p[v] );
    }

    return this->p[v];
}

void UniqueSet::merge( int x, int y ) {

    x = this->find( x );
    y = this->find( y );

    if( this->r[x] > this->r[y] ) {
        this->p[y] = x;

    } else {
        this->p[x] = y;
    }

    if( this->r[x] == this->r[y] ) {
        this->r[x] ++;
    }
}

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

void Kruskal( GraphList target, bool print ) {

    int size = target.getE();
    
    Edge * arr = new Edge [size];
    target.getAllEdgesTo( arr );

    heapSort< Edge >( arr, size );

    /*   *   *   *   *   *   *   *   *   *   */

    int weight = 0; //  MST weight
    vector<Edge> M; //  MST vector

    UniqueSet set( size );

    for( int i = 0; i < size; i++ ) {

        int v = arr[i].v;
        int w = arr[i].w;

        int V = set.find( v );
        int W = set.find( w );

        if( V != W ) {

            weight += arr[i].o;

            if( print ) {
                cout << v << " -> " << w << " | [ " << arr[i].o << " ]"<< endl;
            }

            M.push_back( { v, w, arr[i].o } );            
            set.merge( V, W );
        }
    }

    cout << "MST weight = " << weight << endl;

    /*   *   *   *   *   *   *   *   *   *   */

    delete [] arr;
}

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

void Kruskal( GraphMatrix target, bool print ) {

    int size = target.getE();
    
    Edge * arr = new Edge [size];
    target.getAllEdgesTo( arr );

    heapSort< Edge >( arr, size );

    /*   *   *   *   *   *   *   *   *   *   */

    int weight = 0; //  MST weight
    vector<Edge> M; //  MST vector

    UniqueSet set( size );

    for( int i = 0; i < size; i++ ) {

        int v = arr[i].v;
        int w = arr[i].w;

        int V = set.find( v );
        int W = set.find( w );

        if( V != W ) {

            weight += arr[i].o;

            if( print ) {
                cout << v << " -> " << w << " | [ " << arr[i].o << " ]"<< endl;
            }

            M.push_back( { v, w, arr[i].o } );            
            set.merge( V, W );
        }
    }

    cout << "MST weight = " << weight << endl;

    /*   *   *   *   *   *   *   *   *   *   */

    delete [] arr;
}