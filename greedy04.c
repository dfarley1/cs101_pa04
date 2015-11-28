//Daniel Farley - dfarley@ucsc.edu
//CMPS 101 - Van Gelder

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "loadWgtGraph.h"
//#include "dfsTrace.h"

int main (int argc, char **argv) 
{
    int m = 0, n = 0, s = 0;
    char task = '\0';
    FILE* inbuff = NULL;
    char linebuff[1024];

    //check arg count
    if (argc != 4) {
        fprintf(stderr, "Usage: [-P/D] start_vertex FILE\n");
        exit(1);
    }
    
    //get task
    task = argv[1][1];
    if (strlen(argv[1]) != 2 || (task != 'P' && task != 'D')){
        fprintf(stderr, "  Error: Invalid first argument.\n  Usage: [-P/D] start_vertex FILE\n");
        exit(1);
    }
    
    //get startvertex
    ;
    if ((sscanf(argv[2], "%d", &s) != 1) || (s < 1)) {
        fprintf(stderr, "  Error: Invalid second argument.\n  Usage: [-P/D] start_vertex FILE\n");
        exit(1);
    }
    
    //open file/stdin
    if (strcmp(argv[3], "-") != 0) {
        inbuff = fopen(argv[3], "r");
        if (inbuff == NULL) {
            fprintf(stderr, "  Error: Invalid file.\n  Usage: [-P/D] start_vertex FILE\n");
            exit(1);
        }
        printf("Opened %s for input.\n", argv[3]);
    } else {
        inbuff = stdin;
        printf("Opened stdin for input.\n");
    }
    
    //make intlist array
    //print "n="
    if (fgets(linebuff, 1024, inbuff) == NULL) {
        printf("  Error: Empty file.\n  Usage: [-P/D] start_vertex FILE\n");
        exit(0);
    }
    if ((sscanf(linebuff, "%d", &n) != 1) || (n < 1)) {
        fprintf(stderr, "  Error: Bad line 1: %s\n", linebuff);
        exit(1);
    }
    if (s > n) {
        fprintf(stderr, "  Error: start_vertex (%d)> n (%d).\n", s, n);
        exit(1);
    }
    printf("n = %d\n", n);
    
    //load graph
    EdgeList* adjInfo = initEdges(n);
    m = loadEdges(inbuff, adjInfo, n, task);
    fclose(inbuff);
    printf("m = %d\n", m);
        
    //print table
    int i;
    for(i = 1; i <= n; i++) {
        printf("%d\t%s\n", i, toString(adjInfo[i]));
    }

    int* status = calloc(n+1, sizeof(int));
    int* parent = calloc(n+1, sizeof(int));
    double* fringeWgt = calloc(n+1, sizeof(double));
    

    /*
    if (weighted) {
        //Initialize the table
        printf("n = %d\n", n);
        EdgeList* adjWeightedVertices = initWeightedEdges(n);
        
        m = loadWeightedEdges(inbuff, adjWeightedVertices, n, undirected);
        fclose(inbuff);
        printf("m = %d\n", m);
        
        //print table
        int i;
        for(i = 1; i <= n; i++) {
            printf("%d\t%s\n", i, toWeightedString(adjWeightedVertices[i]));
        }
        
        
    } else {
        //Initialize the table
        printf("n = %d\n", n);
        adjVertices = initEdges(n);
        
        //load table
        m = loadEdges(inbuff, adjVertices, n, undirected);
        fclose(inbuff);
        printf("m = %d\n", m);
        
        //print table
        int i;
        for(i = 1; i <= n; i++) {
            printf("%d\t%s\n", i, toString(adjVertices[i]));
        }
        
        int* color = calloc(n+1, sizeof(int));
        int* dTime = calloc(n+1, sizeof(int));
        int* fTime = calloc(n+1, sizeof(int));
        int* parent = calloc(n+1, sizeof(int));
        
        dfsTrace(adjVertices, n, color, dTime, fTime, parent);
    }
    */
    
    exit(0);
}

//TODO: updateFringe()
//TODO: calcPriority()
//TODO: printOutput()