//Daniel Farley - dfarley@ucsc.edu
//CMPS 101 - Van Gelder

/* minPQ.h - This file contains the Priority Queue ADT used in the MST and SSSP
             algorithms.  
*/

#ifndef C101MinPQ
#define C101MinPQ
/* Multiple typedefs for the same type are an error in C. */

typedef struct MinPQNode * MinPQ;

#define UNSEEN ('u')
#define FRINGE ('f')
#define INTREE ('t')

/* Access functions
*/

/** isEmpty
        Preconditions: pq is a valid MinPQ object.
        Postconditions: returns whether or not the PQ is empty:
                        1 = true, 0 = false.
*/
int isEmptyPQ(MinPQ pq);

/** getMin
        Preconditions: pq is a valid MinPQ object.
        Postconditions: returns the fringe vertex with minimum weight.
                        returns -1 if no fringe vertices remain.
*/
int getMin(MinPQ pq);

/** getStatus
        Preconditions: pq is a valid MinPQ object and 0 < id < n
        Postconditions: returns the status (UNSEEN, FRINGE, INTREE) of the 
                        vertex specified by id.
*/
int getStatus(MinPQ pq, int id);

/** getParent
        Preconditions: pq is a valid MinPQ object and 0 < id < n
        Postconditions: returns the parent of the vertex specified by id.
*/
int getParent(MinPQ pq, int id);

/** getPriority
        Preconditions: pq is a valid MinPQ object and 0 < id < n
        Postconditions: returns the weight (priority) of the vertex specified
                        by id.
*/
double getPriority(MinPQ pq, int id);

/* Manipulation procedures
*/

/** delMin
        Preconditions: pq is a valid MinPQ object
        Postconditions: fringe vertex with minimum weight is removed from pq.
*/
void delMin(MinPQ pq);

/** insertPQ
        Preconditions: pq is a valid MinPQ object
        Postconditions: records par, priority as parent, weight of id and 
                        makes status[id] = FRINGE.
*/
void insertPQ(MinPQ pq, int id, double priority, int par);

/** decreaseKey
        Preconditions: pq is a valid MinPQ object
        Postconditions: records par, priority as parent, weight of id. replaces
                        the previous priority if the new priority is less.
*/
void decreaseKey(MinPQ pq, int id, double priority, int par);

/* Constructors
*/

/** createPQ
        Preconditions: status, priority, and parent arrays are allocated with 
                       size n+1 and initialized to zero.
        Postconditions: returned MinPQ object is initialized and ready to use.
                        passed arrays should not be overwritten or free()'d 
                        until the object is not used any longer.
*/
MinPQ createPQ(int n, int status[], double priority[], int parent[]);


#endif

