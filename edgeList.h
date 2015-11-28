//Daniel Farley - dfarley@ucsc.edu
//CMPS 101 - Van Gelder

/* edgeList.h
 * This file provides an adjacency lists implementation that support weighted
 * edges.
 */

#ifndef C101EdgeList
#define C101EdgeList
/* Multiple typedefs for the same type are an error in C. */

typedef struct EdgeListNode * EdgeList;

typedef struct EdgeInfoStruct {
    int to;
    double wgt;
} EdgeInfo;

/** edgeNil denotes the empty EdgeList */
extern const EdgeList edgeNil;

/* Access functions
 * Preconditions: oldL points to a valid EdgeListNode struct and is not NULL.
 */

/** first
*/
EdgeInfo edgeFirst(EdgeList oldL);

/** rest
*/
EdgeList edgeRest(EdgeList oldL);

/* Constructors
 * Preconditions: newE is a valid EdgeInfo object.  oldL must either be a valid
 *     EdgeList or NULL, indicating an empty list.
 * Postconditions: edgeListCons returns a new EdgeList whose first node is
 *     newE followed by the list specified by oldL
 */

/** cons
*/
EdgeList edgeCons(EdgeInfo newE, EdgeList oldL);

char* toString(EdgeList aList);

#endif

