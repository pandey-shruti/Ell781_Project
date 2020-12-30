/*
 * utils.h
 *
 *  Created on: 29-Dec-2020
 *      Author: monik
 */

#ifndef UTILS_H_
#define UTILS_H_



#endif /* UTILS_H_ */
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    char *name;
    struct node * next;
}NODE;

int p_index = 0;

NODE * make_node(int ,char **);

NODE * make_node(int i, char ** l){   // function to make a new node of the graph
    NODE * s;
    s = (NODE *) malloc (sizeof(NODE));

    s->name = l[i];
    s->next = (NODE *) NULL;
    return s;
}

typedef struct GRAPH{
    int vertices;
    NODE ** adj;
}GRAPH;

GRAPH * make_graph(int v){  // function to make a new graph with v number of vertices
    GRAPH *g;
    g = (GRAPH *) malloc(sizeof(GRAPH));
    g -> vertices = v;
    g -> adj = malloc(v * sizeof(NODE*));
    for (int i=0; i<v; i++)
        g->adj[i] = (NODE*) NULL;
    return g;
}
struct Edge {
    int src, dest, cost;
};

void create_adjacency(GRAPH * g,struct Edge ed[],int e,char **l){  // function to add ns in the adjacenecy list of ps
	//printf(" %s\n", l[s]);
	for (int i = 0; i < e; i++){
		int s =ed[i].src;
		int n =ed[i].dest;
		int cost = ed[i].cost;
   NODE * v = make_node(n, l );
   v->next = g->adj[s]; //v pointing to itself
    g->adj[s] = v;  //allowed ns added to adj_list of ps
	}
}
void print_graph(GRAPH * g){  // funtion to print the graph
    int i;
    NODE * adj_node;
    for (i=0 ; i < g->vertices ; i++){
        adj_node = g->adj[i];

        printf("adjacency list of vertex (%d)\n", i);
        while(adj_node){
            printf("%s ---> ", adj_node->name);
            adj_node = adj_node->next;
        }
        printf("\n");
    }
}
