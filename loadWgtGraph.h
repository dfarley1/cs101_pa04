//Daniel Farley - dfarley@ucsc.edu
//CMPS 101 - Van Gelder

#ifndef C101LoadWgtGraph
#define C101LoadWgtGraph

//#include "intList.h"
#include "edgeList.h"

/* loadGraph.h
 * This header defines the Edge struct and its functions.  The Edge struct
 * contains two integers and a double that are read in from an input buffer
 * in the format "2 3 0.4".  The first integer (from) is used as the array 
 * index for the IntList that the second value (to) is stored at.  
 * The double (weight) is unused as of yet.
 */

typedef struct EdgeNode* Edge;


/* edgeCons: 
 * Preconditions: 
 * Postconditions: 
 */
Edge newECons();

/* parseEdge: Reads two integers (and optionally a double) from line and puts
 *     them in an Edge struct.
 * Preconditions: line points to a valid string consisting of two integers (and
 *     optionally a double) delimited by spaces.
 * Postconditions: The returned Edge's values contain numerical representations
 *     of the numbers in the passed string.
 */
Edge parseEdge(char* line);

/* initEdges: 
 * Preconditions: 
 * Postconditions: 
 */

EdgeList* initEdges(int n);

/* loadEdges: 
 * Preconditions: 
 * Postconditions: 
 */

int loadEdges(FILE* inbuff, EdgeList* adjInfo, int listMax, char task);

//IntList* initEdges(int n);
//int loadEdges(FILE* inbuff, IntList* adjVertices, int listMax, int undirected);

#endif

