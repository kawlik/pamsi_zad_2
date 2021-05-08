#include <iostream>
#include <utility>

//  graph interface
#include "graphMatrix.hh"

using namespace std;

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */
//  life cycle

GraphMatrix::GraphMatrix( int V ) {

    this->E = 0;
    this->V = V;

    //  matrix init
    this->matrix = new mEdge * [V];
    for( int i = 0; i < V; i++ ) {
        this->matrix[i] = new mEdge [V];
    }

    for( int i = 0; i < V; i++ ) {
        for( int j = 0; j < V; j++ ) {
            this->matrix[i][j] = { false, 0 };
        }
    }
}

GraphMatrix::~GraphMatrix() {

}

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */
//  usage

void GraphMatrix::getAllEdgesTo( Edge * arr ) {

    int iterator = 0;

    for( int i = 0; i < this->V; i++ ) {
        for( int j = i; j > -1; j-- ) {

            if( this->matrix[i][j].isSet ) {
                arr[iterator++] = this->getEdge( i, j );
            }
        }
    }
}

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */
//  update

void GraphMatrix::insertEdge( int v, int w, int o ) {

    if( !this->areAdjacent( v, w ) ) {

        this->matrix[v][w] = { true, o };
        this->matrix[w][v] = { true, o };

        this->E++;
    }
}

void GraphMatrix::removeEdge( int v, int w ) {

    if( this->areAdjacent( v, w ) ) {

        this->matrix[v][w] = { false, 0 };
        this->matrix[w][v] = { false, 0 };

        this->E--;
    }
}

bool GraphMatrix::areAdjacent( int v, int w ) {

    if( this->matrix[w][v].isSet ) { return true; }
    if( this->matrix[v][w].isSet ) { return true; }

    return false;
}

Edge GraphMatrix::getEdge( int v, int w ) {

    if( !this->areAdjacent( v, w ) ) {
        throw runtime_error( "Access to unset edge is prohibited!" );
    }

    if( this->matrix[v][w].isSet ) { return { v, w, this->matrix[v][w].value }; };
    if( this->matrix[w][v].isSet ) { return { w, v, this->matrix[w][v].value }; };

    throw runtime_error( "Edge cannot be found!" );
}

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */
//  maintenance

void GraphMatrix::print() {

    for( int i = 0; i < this->V; i++ ) {
        for( int j = 0; j < this->V; j++ ) {

            if( this->matrix[i][j].isSet == true ) {
                cout << " ( " << i << " -> " << j << " | [ " << this->matrix[i][j].value << " ] ) ";
            }
        }

        cout << endl;
    }
}

void GraphMatrix::fill( int density ) {

    for( int i = 0; i < this->V; i++ ) {
        for( int j = 0; j < this->V; j++ ) {
            this->removeEdge( i, j );
        }
    }
    
    for( int i = 0; i < this->V; i++ ) {
        for( int j = 0; j < this->V; j++ ) {

            if( i >= j ) { continue; }  //  prevents a loop in graph

            if( getRand<int>( 1, 100 ) < (100 - density) ) { continue; }    //  density check

            this->insertEdge( i, j, getRand<int>( 1, this->V ));
        }
    }
}