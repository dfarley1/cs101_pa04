//Daniel Farley - dfarley@ucsc.edu
//CMPS 101 - Van Gelder

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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
    return 0;
}

int getMin(MinPQ pq)
{
    return 0;
}

int getStatus(MinPQ pq, int id)
{
    return 0;
}

int getParent(MinPQ pq, int id)
{
    return 0;
}

double getPriority(MinPQ pq, int id)
{
    return 0.0;
}

void delMin(MinPQ pq)
{
    return;
}

void insertPQ(MinPQ pq, int id, double priority, int par)
{
    return;
}

void decreaseKey(MinPQ pq, int id, double priority, int par)
{
    return;
}

MinPQ createPQ(int n, int status[], double priority[], int parent[])
{
    return NULL;
}
