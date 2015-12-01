//Daniel Farley - dfarley@ucsc.edu
//CMPS 101 - Van Gelder

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "minPQ.h"

struct MinPQNode {
    int numVertices, numPQ;
    int minVertex;
    double oo;
    int* status;
    int* parent;
    double* fringeWgt;
};

int isEmptyPQ(MinPQ pq)
{
    return (pq->numPQ == 0);
}

void findMin(MinPQ pq)
{
    int v;
    double minWgt;
    
    minWgt = pq->oo;
    for (v = 1; v <= pq->numVertices; v++) {
        if (pq->status[v] == FRINGE) {
            if (pq->fringeWgt[v] < minWgt) {
                pq->minVertex = v;
                minWgt = pq->fringeWgt[v];
            }
        }
    }
    return;
}

int getMin(MinPQ pq)
{
    if (pq->minVertex == -1) {
        findMin(pq);
    }
    return pq->minVertex;
}

int getStatus(MinPQ pq, int id)
{
    return pq->status[id];
}

int getParent(MinPQ pq, int id)
{
    return pq->parent[id];
}

double getPriority(MinPQ pq, int id)
{
    return pq->fringeWgt[id];
}

void delMin(MinPQ pq)
{
    int oldMin = getMin(pq);
    
    pq->status[oldMin] = INTREE;
    pq->minVertex = -1;
    pq->numPQ--;
    return;
}

void insertPQ(MinPQ pq, int id, double priority, int par)
{
    pq->parent[id] = par;
    pq->fringeWgt[id] = priority;
    pq->status[id] = FRINGE;
    pq->minVertex = -1;
    pq->numPQ++;
    return;
}

void decreaseKey(MinPQ pq, int id, double priority, int par)
{
    pq->parent[id] = par;
    pq->fringeWgt[id] = priority;
    pq->minVertex = -1;
    return;
}

MinPQ createPQ(int n, int status[], double priority[], int parent[])
{
    MinPQ pq = malloc(sizeof(struct MinPQNode));
    pq->parent = parent;
    pq->fringeWgt = priority;
    pq->status = status;
    for (int i = 1; i <= n; i++) {
        pq->status[i] = UNSEEN;
    }
    pq->numVertices = n;
    pq->numPQ = 0;
    pq->minVertex = -1;
    pq->oo = INFINITY;
    return pq;
}
