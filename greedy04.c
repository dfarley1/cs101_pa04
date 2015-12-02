//Daniel Farley - dfarley@ucsc.edu
//CMPS 101 - Van Gelder

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "loadWgtGraph.h"
#include "minPQ.h"

int checkArgs(int argc, char **argv, char *task);
FILE* openFile(int argc, char **argv, char *task, int *s);
int parseN(FILE* inbuff, int s);

void greedyTree(EdgeList* adjInfo, int n, int s, int* parent, int* status, double* fringeWgt, char task);
void updateFringe(MinPQ pq, EdgeList adjInfoOfV, int v, char task);
double calcPriority(MinPQ pq, EdgeInfo wInfo, int v,char task);
int PrintArrays(int* parent, int* status, double* fringeWgt, char task, int s, int n);

int main (int argc, char **argv) 
{
    int m = 0;
    char task = '\0';
    
    int s = checkArgs(argc, argv, &task);
    FILE* inbuff = openFile(argc, argv, &task, &s);
    int n = parseN(inbuff, s);

    //load graph
    EdgeList* adjInfo = initEdges(n);
    m = loadEdges(inbuff, adjInfo, n, task);
    fclose(inbuff);
        
    //print table
    printf("n = %d\n", n);
    printf("m = %d\n", m);
    int i;
    for(i = 1; i <= n; i++) {
        printf("%d\t%s\n", i, toString(adjInfo[i]));
    }

    int* status = calloc(n+1, sizeof(int));
    int* parent = calloc(n+1, sizeof(int));
    double* fringeWgt = calloc(n+1, sizeof(double));
    
    greedyTree(adjInfo, n, s, parent, status, fringeWgt, task);
    
    PrintArrays(parent, status, fringeWgt, task, s, n);
    
    exit(0);
}

int checkArgs(int argc, char **argv, char *task)
{
    if (argc != 4) {
        fprintf(stderr, "Usage: [-P/D] start_vertex FILE\n");
        exit(1);
    }
    
    *task = argv[1][1];
    if (strlen(argv[1]) != 2 || (*task != 'P' && *task != 'D')){
        fprintf(stderr, "  Error: Invalid first argument.\n  Usage: [-P/D] start_vertex FILE\n");
        exit(1);
    }
    
    int s = 0;
    if ((sscanf(argv[2], "%d", &s) != 1) || (s < 1)) {
        fprintf(stderr, "  Error: Invalid second argument.\n  Usage: [-P/D] start_vertex FILE\n");
        exit(1);
    }
    
    return s;
}

FILE* openFile(int argc, char **argv, char *task, int *s)
{
    FILE* inbuff = NULL;
    
    if (strcmp(argv[3], "-") != 0) {
        inbuff = fopen(argv[3], "r");
        if (inbuff == NULL) {
            fprintf(stderr, "  Error: Invalid file.\n  Usage: [-P/D] start_vertex FILE\n");
            exit(1);
        }
    } else {
        inbuff = stdin;
    }
    
    return inbuff;
}

int parseN(FILE* inbuff, int s)
{
    int n = 0;
    char linebuff[1024];
    
    if (fgets(linebuff, 1024, inbuff) == NULL) {
        printf("  Error: Empty file.\n  Usage: [-P/D] start_vertex FILE\n");
        exit(0);
    }
    if ((sscanf(linebuff, "%d", &n) != 1) || (n < 1)) {
        fprintf(stderr, "  Error: Bad line 1: %s\n", linebuff);
        exit(1);
    }
    if (s > n) {
        fprintf(stderr, "  Error: start_vertex(%d) > n(%d).\n", s, n);
        exit(1);
    }
    
    return n;
}

void greedyTree(EdgeList* adjInfo, int n, int s, int* parent, int* status, double* fringeWgt, char task)
{
    MinPQ pq = createPQ(n, status, fringeWgt, parent);
    
    insertPQ(pq, s, 0, -1);
    while (!isEmptyPQ(pq)) {
        int v = getMin(pq);
        delMin(pq);
        updateFringe(pq, adjInfo[v], v, task);
    }
}

void updateFringe(MinPQ pq, EdgeList adjInfoOfV, int v, char task)
{
    //double myDist = pq.fringeWgt[v];
    EdgeList remAdj = adjInfoOfV;
    while (remAdj != edgeNil) {
        EdgeInfo wInfo = edgeFirst(remAdj);
        int w = wInfo.to;
        double newWgt = calcPriority(pq, wInfo, v, task);
        if (getStatus(pq, w) == UNSEEN) {
            insertPQ(pq, w, newWgt, v);
        } else if (getStatus(pq, w) == FRINGE) {
            if (newWgt < getPriority(pq, w)) {
                decreaseKey(pq, w, newWgt, v);
            }
        }
        remAdj = edgeRest(remAdj);
    }
}

double calcPriority(MinPQ pq, EdgeInfo wInfo, int v, char task)
{
    if (task == 'P') {
        return wInfo.wgt;
    } else if (task == 'D') {
        return getPriority(pq, v) + wInfo.wgt;
    } else {
        fprintf(stderr, "  Error: Invalid task!");
        exit(1);
    }
    return 0.0; //Stupid compiler warning
}

int PrintArrays(int* parent, int* status, double* fringeWgt, char task, int s, int n)
{
    printf("Running %s algorithm starting at vertex %d.\n", 
            (task == 'P')?("Prim's"):("Dijkstra's"), s);
    printf("  V | status | priority | parent\n");
    printf("--------------------------------\n");
    for (int i = 1; i <= n; i++) {
        printf("  %d |   %c    |   %4.1f   |   %d\n", 
                i, status[i], fringeWgt[i], parent[i]);
    }
    return 0;
}