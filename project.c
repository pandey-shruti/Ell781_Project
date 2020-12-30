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

int main()
{
	GRAPH * my_graph;
	my_graph = make_graph(14);

	char * citylist[]={
				"Delhi",
				"Narela",
				"Kashmere Gate",
				"Shahdara",
				"Delhi Border",
				"Panipat",
				"Ambala",
				"Chandigarh",
				"Bilaspur",
				"Shimla",
				"Ludhiana",
				"Palam Pur",
				"Mandi",
				"Manali"};

	//int visit[16], path[16];
	int* p_index;
	p_index = malloc(sizeof(int));
	*p_index = 0;
	printf("Here are the different route to Manali from Delhi\n");


	struct Edge edges[] =
	    {
	        { 0, 1,5 }, { 0, 2,2 }, { 1, 4,3 }, { 2, 3,1 },
	        { 3, 4, 7 }, { 4, 5,2 }, { 5, 6,3 },{ 5, 9,8 },
			{ 6, 7,2 },{ 6, 10,5 },{ 7, 8,2 },{ 9, 8,2 },
			{ 8, 12,1 },{ 10, 11,3 },{ 11, 12,2 },{ 12, 13,2 }
	    };
	     int e = sizeof(edges)/sizeof(edges[0]);
	    create_adjacency(my_graph, edges,e, citylist);
	print_graph(my_graph);
	return 0;

}
