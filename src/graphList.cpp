#include <iostream>
#include <utility>

//  graph interface
#include "graphList.hh"

using namespace std;

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */
//  life cycle

GraphList::GraphList( int V ) {
    
    this->E = 0;
    this->V = V;

    //  list init
    this->list = new Node * [V];

    for( int i = 0; i < V; i++ ) {
        this->list[i] = NULL;
    }
}

GraphList::~GraphList() {

}

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */
//  usage

void GraphList::getAllEdgesTo( Edge * arr ) {

    int iterator = 0;

    for( int i = 0; i < this->V; i++ ) {
        for( int j = 0; j < this->V; j++ ) {

            if( i >= j ) { continue; }

            if( this->areAdjacent( i, j ) ) {
                arr[iterator++] = this->getEdge( i, j );
            }
        }
    }
}


/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */
//  update

void GraphList::insertEdge( int v, int w, int o ) {

    if( !this->areAdjacent( v, w ) ) {
        
        push( this->list[v], w, o );
        push( this->list[w], v, o );

        this->E++;
    }
}

void GraphList::removeEdge( int v, int w ) {

    if( this->areAdjacent( v, w ) ) {
        
        Node * head;
        Node * node;
        Node * prev;

        /*   *   *   *   *   */

        node = this->list[v];
        head = this->list[v];

        while( node ) {
            
            if( node->goal == w ) {
                //  node to delete

                if( node == head ) {    //  list head

                    head = node->next;

                } else {    //  list inner part

                    if( node->next != NULL ) {  //  list body
                        prev->next = node->next;
                    }

                    if( node->next == NULL ) {  //  list tail
                        prev->next = NULL;
                    }
                }

                break;
            }

            prev = node;
            node = node->next;
        }

        /*   *   *   *   *   */
        
        node = this->list[w];
        head = this->list[w];

        while( node ) {
            
            if( node->goal == v ) {
                //  node to delete

                if( node == head ) {    //  list head

                    head = node->next;

                } else {    //  list inner part

                    if( node->next != NULL ) {  //  list body
                        prev->next = node->next;
                    }

                    if( node->next == NULL ) {  //  list tail
                        prev->next = NULL;
                    }
                }

                break;
            }

            prev = node;
            node = node->next;
        }

        /*   *   *   *   *   */

        this->E--;
    }
}

bool GraphList::areAdjacent( int v, int w ) {

    Node * node;
    
    node = this->list[v];
    while( node ) {

        if( node->goal == w ) { return true; }
        node = node->next;
    }

    node = this->list[w];
    while( node ) {

        if( node->goal == v ) { return true; }
        node = node->next;
    }

    return false;
}

Edge GraphList::getEdge( int v, int w ) {

    if( !this->areAdjacent( v, w ) ) {
        throw runtime_error( "Access to unset edge is prohibited!" );
    }

    Node * node;
    int rank;

    /*   *   *   *   *   */


    node = this->list[v];
    while( node ) {

        if( node->goal == w ) {

            rank = node->rank;
            return { v, w, rank };
        }

        node = node->next;
    }

    /*   *   *   *   *   */

    node = this->list[w];
    while( node ) {

        if( node->goal == v ) {

            rank = node->rank;
            return { w, v, rank };
        }

        node = node->next;
    }


    /*   *   *   *   *   */

    throw runtime_error( "Edge cannot be found!" );
}

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */
//  maintenance

void GraphList::print() {

    for( int i = 0; i < this->V; i++ ) {

        cout << i;
        pout( this->list[i] );
        cout << endl;
    }
}

void GraphList::fill() {
    
    for( int i = 0; i < this->V; i++ ) {
        for( int j = 0; j < this->V; j++ ) {

            if( i == j ) { continue; }  //  prevents a loop in graph

            this->insertEdge( i, j, getRand<int>( 1, this->V ));
        }
    }
}

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

void push( Node * & head, int goal, int rank ) {

    Node * node = new Node;

    node->goal = goal;
    node->rank = rank;
    node->next = head;
    head = node;
}

void popf( Node * & head ) {
    
    Node * node;
    node = head;

    head = node->next;
    delete node;
}


void pout( Node * & head ) {

    Node * node;
    node = head;

    while( node ) {
        cout << (( node == head ) ? " :: " : " => ") << "( " << node->goal << " [ " << node->rank << " ] )";
        node = node->next;
    }
}