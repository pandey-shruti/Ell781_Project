/*
 ============================================================================
 Name        : project.c
 Author      : monika
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include"utils.h"
#include"krus.h"
#include <time.h>
int main()
{


	char * citylist[]={
				"Paschim Vihar",
				"Ashok Park",
				"Kirti Nagar",
				"Rajouri Garden",
				"Cannaught Place",
				"AIIMS",
				"Mayur Vihar",
				"Dhuala Kuan",
				"New Delhi",
				"Shahdara"
				};

	//int visit[16], path[16];
	int* p_index;
	p_index = malloc(sizeof(int));
	*p_index = 0;
	printf("Here are the different route to Manali from Delhi\n");

	Edge edges[] = {
	        { 0, 3,1 }, { 0, 1,2 },{ 2, 3,1 }, { 1, 2,2 },
	        { 2, 4, 4 }, { 4, 5,3 }, { 4, 6,1 }, {8,9,5},{ 5, 7,2},{4,8,2},{ 8, 7,5 },
			{ 6, 9,7 },

	    };
	     int e = sizeof(edges)/sizeof(edges[0]);
	     GRAPH * my_graph;
	     my_graph = make_graph(10, e);

	    create_adjacency(my_graph, edges,e, citylist);
	print_graph(my_graph);
	KruskalMST(my_graph,e,edges);
	return 0;

}
