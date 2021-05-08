#include <iostream>

using namespace std;

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

struct Node {

    Node * next;
    

    int data;
};

void print( Node * node );
void push( Node * & head, int data);

int pop( Node * & head );
int pop( Node * & head );

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

int main() {

    Node * list = new Node;

    for( int i = 0; i < 8; i++ ) { push( list, i ); }

    print( list );
    cout << endl;

    for( int i = 0; i < 4; i++ ) { cout << (i ? " -> " : " ") << pop( list );}
    cout << endl;

    print( list );
    cout << endl;

    /*  delete node 1   */
    Node * node;
    node = list;

    if( node->data == 1 ) {
        node
    }

    while( node ) {

        node = node->next;
    }
}

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

void push( Node * &head, int data) {

    Node * node = new Node;

    node->data = data;
    node->next = head;
    head = node;
}

void print( Node * node ) {

    while( node ) {
        cout << " ( data :: " << node->data << " )";
        node = node->next;
    }
}

int pop( Node * &head ) {

    Node * node = new Node;
    node = head;

    int data;

    if( node ) {
        data = node->data;
        head = node->next;
        delete node;
    }

    return data;
}

int get( Node * head ) {

    Node * node = new Node;
    node = head;

    int data;

    if( node ) { data = node->data; }

    return data;
}