//Daniel Farley - dfarley@ucsc.edu
//CMPS 101 - Van Gelder

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "edgeList.h"

const EdgeList edgeNil = NULL;

struct EdgeListNode {
    EdgeInfo info;
    EdgeList next;
};

EdgeInfo edgeFirst (EdgeList oldL) {
	return oldL->info;
}

EdgeList edgeRest (EdgeList oldL) {
	return oldL->next;
}

EdgeList edgeCons (EdgeInfo newE, EdgeList oldL) {
	EdgeList newEdgeList = malloc(sizeof(struct EdgeListNode));
	newEdgeList->info = newE;
	newEdgeList->next = oldL;
	return newEdgeList;
}

char* toString(EdgeList aList)
{
    if (aList == edgeNil) return "[]";
    
    char *s = calloc(1024, sizeof(char));
    s[0] = '[';
    
    while (aList != edgeNil){
        sprintf(s+strlen(s), "%d@%.1f, ", edgeFirst(aList).to, edgeFirst(aList).wgt);
        aList = edgeRest(aList);
    }
    s[strlen(s)-2] = ']';
    
    //toWeightedStringR(s, "", aList);
    return s;
}
