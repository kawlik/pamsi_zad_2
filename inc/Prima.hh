#ifndef PRIMA_HH
#define PRIMA_HH

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

#include <iostream>
#include <vector>

#include "graphList.hh"
#include "graphMatrix.hh"

using namespace std;

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

bool isInMST( int v, int w, bool * inMST );

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

void Prima( GraphMatrix target, bool print );
void Prima( GraphList target, bool print );

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

#endif