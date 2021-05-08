#include <iostream>

#include "utility.hh"

using namespace std;

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

void Edge::operator = ( Edge data ) {
    this->v = data.v;
    this->w = data.w;
    this->o = data.o;
}

bool Edge::operator > ( Edge data ) { if( this->o > data.o ) { return true; } else { return false; } }

bool Edge::operator < ( Edge data ) { if( this->o > data.o ) { return true; } else { return false; } }

bool Edge::operator == ( Edge data ) { if( this->o > data.o ) { return true; } else { return false; } }

bool Edge::operator >= ( Edge data ) { if( this->o > data.o ) { return true; } else { return false; } }

bool Edge::operator <= ( Edge data ) { if( this->o > data.o ) { return true; } else { return false; } }

istream & operator >> ( istream & str, Edge & data ) {
    str >> data.v >> data.w >> data.o;
    return str;
}

ostream & operator << ( ostream & str, Edge & data ) {
    str << " ( " << data.v << " -> " << data.w << " | [ " << data.o << " ] ) ";
    return str;
}

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */