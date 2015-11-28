//Daniel Farley - dfarley@ucsc.edu
//CMPS 101 - Van Gelder

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "loadWgtGraph.h"

struct EdgeNode {
    int from, to;
    double weight;
};

Edge newECons()
{
    Edge newEdge = malloc(sizeof(struct EdgeNode));
    newEdge->from = 0;
    newEdge->to = 0;
    newEdge->weight = 0.0;
    return newEdge;
}

Edge parseEdge(char* line)
{
    Edge e = newECons();
    int n = sscanf(line, "%d %d %lf", &(e->from), &(e->to), &(e->weight));
//    printf("n=%d    from=%d    to=%d    weight=%f\n", 
//        n, e->from, e->to, e->weight);
    if (n < 2 || n > 3) {
        fprintf(stderr, "Bad edge: %s", line);
        exit(1);
    }
    return e;
}

EdgeList* initEdges(int n)
{
    EdgeList* adjInfo = malloc(sizeof(EdgeList)*(n+1));
    int i;
    for(i = 0; i <= n; i++) {
        adjInfo[i] = edgeNil;
    }
    return adjInfo;
}

int loadEdges(FILE* inbuff, EdgeList* adjInfo, int listMax, char task)
{
    int num = 0;
    char line[1024];
    
    while (fgets(line, 1024, inbuff) != NULL) {
        if (line[0] == ' ' || strcmp(line, "\n") == 0) {
            continue;
        }
        //printf("loadEdges: about to parse: %s", line);
        Edge e = parseEdge(line);
        
        if (e->from > listMax) {
            fprintf(stderr, "%d exceeds n=%d.\n", e->from, listMax);
            exit(1);
        }
        
        EdgeInfo wE;
        wE.to = e->to;
        wE.wgt = e->weight;
        
        adjInfo[e->from] = edgeCons(wE, adjInfo[e->from]);
        num++;
        
        if (task == 'P') {
            EdgeInfo revE;
            revE.to = e->from;
            revE.wgt = e->weight;
            adjInfo[e->to] = edgeCons(revE, adjInfo[e->to]);
            num++;
        }
    }
    return num;
}

/*
IntList* initEdges(int n)
{
    IntList* adjVertices = malloc(sizeof(IntList)*(n+1));
    int i;
    for(i = 0; i <= n; i++) {
        adjVertices[i] = intNil;
    }
    return adjVertices;
}

int loadEdges(FILE* inbuff, IntList* adjVertices, int listMax, int undirected)
{
    int num = 0;
    char line[1024];
    
    while (fgets(line, 1024, inbuff) != NULL) {
        if (line[0] == ' ' || strcmp(line, "\n") == 0) {
            continue;
        }
        //printf("loadEdges: about to parse: %s", line);
        Edge e = parseEdge(line);
        
        if (e->from > listMax) {
            fprintf(stderr, "%d exceeds n=%d.\n", e->from, listMax);
            exit(1);
        }
        
        adjVertices[e->from] = intCons(e->to, adjVertices[e->from]);
        num++;
        
        if (undirected == 1) {
            adjVertices[e->to] = intCons(e->from, adjVertices[e->to]);
            num++;
        }
    }
    return num;
}

*/
