
#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h> 

#define INF 9999999

typedef struct node{
    char *name;
    struct node * next;
    int weight;
    int value;
}NODE;

int p_index = 0;

NODE * make_node(int ,char **,int w);

NODE * make_node(int i, char ** l,int w){   // function to make a new node of the graph
    NODE * s;
    s = (NODE *) malloc (sizeof(NODE));

    s->name = l[i];
    s->value = i;
    s->weight = w;
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
/*struct Edge {
    int src, dest, cost;
};*/

void create_adjacency(GRAPH * g, int ps,int ns,int cost,char **l){  // function to add ns in the adjacenecy list of ps
	//printf(" %s\n", l[s]);
	/*for (int i = 0; i < e; i++){
		int s =ed[i].src;
		int n =ed[i].dest;
		int cost = ed[i].cost;*/

   NODE * v = make_node(ns, l,cost);
   v->next = g->adj[ps]; //v pointing to itself
   //v->weight = cost;
   g->adj[ps] = v;  //allowed ns added to adj_list of ps

    NODE * u = make_node(ps, l,cost);
    u->next = g->adj[ns]; //v pointing to itself
    //u->weight = cost;
    g->adj[ns] = u;  //allowed ns added to adj_list of ps
	}

void print_graph(GRAPH * g,char ** l){  // function to print the graph
    int i;
    NODE * adj_node;
    for (i=0 ; i < g->vertices ; i++){
        adj_node = g->adj[i];
        //char * source = l[i];
        printf("\n");
        printf("adjacency list of vertex %s (vertex no.= %d)\n", l[i],i);
        while(adj_node){
            printf("%s (vertex no.= %d, cost = %d)---> ", adj_node->name,adj_node->value,adj_node->weight);
            adj_node = adj_node->next;
        }
        printf("\n");
    }
}


void prims_array(GRAPH *g) {
  int edges;  // number of edges in MST
  edges = 0; //initially no edge in MST
  int minimum_cost = 0;

  int V = g->vertices;  
  NODE ** adj = g->adj;

  int setS[20]={false}; // An array to store whether a vertex is in MST or not
  
  setS[0] = true; // start with the 0th vertex

  int x;  //  source vertex
  int y;  //  destination vertex


  while (edges < V - 1) //MST will always have edges less than or equal to V-1
  {
    
    int min = INF;
    int x = 0;
    int y = 0;

    for(int i = 0; i < V; i++)
    {
      if (setS[i]) //the vertex in S
      {
        NODE * adjacent = adj[i];
        
        while(adjacent)
       {
          int j = adjacent->value; 
          if (!setS[j]) // check for the edges across the cut
          {
            int price = adjacent->weight;
            //printf("The cost of edge from vertex %d in set S to vertex %d in V-S is %d\n",i,j,price); 
            if (min > price) {
              
              min = price;
              x = i;
              y = j;
            }
          }
          adjacent = adjacent->next;
        }
      }
    }
    
    //printf("The minimum weight edge (light/safe edge) included in MST is %d -> %d having cost of %d\n", x, y, min);
    printf("%d -> %d,cost = %d",x, y, min);
    minimum_cost += min;
    printf("\n");
    setS[y] = true; //include vertex y in S
    edges++;
  }
  printf("The cost of the Minimum Spanning Tree obtained is %d\n",minimum_cost);
  return ;
}
