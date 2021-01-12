

#include"utils_Shruti.h"
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
	printf("Here are the list of locations that the Travelling Salesman wants to travel in Delhi\n");


	/*struct Edge edges[] =
	    {
	        { 0, 3,1 }, { 0, 1,2 }, { 1, 2,2 }, { 2, 3,3 },
	        { 2, 4, 4 }, { 4, 5,3 }, { 4, 6,1 },{ 5, 7,6 },
			{ 6, 9,7 },{ 7, 8,4 },{ 9, 8,5 },

	    };
	     int e = sizeof(edges)/sizeof(edges[0]);*/
		//time_t begin = time(NULL);
		
	     GRAPH * my_graph;
	     my_graph = make_graph(10);
	    create_adjacency(my_graph,0,3,1, citylist);
		create_adjacency(my_graph,0,1,2, citylist);
		create_adjacency(my_graph, 1, 2,2, citylist);
		create_adjacency(my_graph,2, 3,1, citylist);
		create_adjacency(my_graph,2, 4, 4, citylist);
		create_adjacency(my_graph,4, 5,3, citylist);
		create_adjacency(my_graph,4, 6,1, citylist);
		create_adjacency(my_graph,5, 7,2, citylist);
		create_adjacency(my_graph,6, 9,7 , citylist);
		create_adjacency(my_graph,7, 8,5, citylist);
		create_adjacency(my_graph, 8,4,2, citylist);
		create_adjacency(my_graph,9, 8,5, citylist);
	
	print_graph(my_graph,citylist);
	printf("\n");
	printf("The edges in the MST and their cost are \n");
	
 
    // do some stuff here
    prims_array(my_graph);
 
    //time_t end = time(NULL);
 
    // calculate elapsed time by finding difference (end - begin)
    //printf("Time elpased is %d seconds", (end - begin));
 
	/*clock_t begin = clock();
	prims_array(my_graph);
	clock_t end = clock();
	double time_spent; 
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
	
  
    printf("prims_array(my_graph); took %f seconds to execute \n", time_spent); */
	
	return 0;

}
