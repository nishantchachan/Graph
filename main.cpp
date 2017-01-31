// I have used Adjacency List implementation of Graph

#include "Header.hpp"

#include "UnDirectedGraph.hpp"

using namespace std;


#define EDGE_DENSITY 2147483647 // MAX POSITIVE VALUE FOR AN 4 BYTE INTEGER

#define ALPHBET_RANGE 6        // Considering 26 Alphabets from A to Z as our vertices

int main(int argc, char **argv) 
{  
  
    /* Intializes random number generator */
    srand((unsigned) time(0));
   
    Graph *graph = new UnDirectedGraph();
    
    // I am taking "A" to "Z" as 26 vertices of my graph;
    for(int ch = 0; ch < ALPHBET_RANGE; ch++)
    {
      char c = ch+65; 			// Here 65 is ASCII VALUE for "A"
      
      string s(1,c);			// Convert Char to string	
      
      graph->AddVertex(s);
    }
    
    // Below is a loop used for creating edges b/w Vertices of our graph.
    
    for(int ix = 0; ix < graph->NumberOfVertices(); ix++)
    {
      for(int jx = 0; jx<graph->NumberOfVertices(); jx++)
      {
	if(ix != jx)
	{
	  if((rand()) < (EDGE_DENSITY/10))
	  {
	    char c = ix+65;
	    string firstVertex(1,c);
	    c = jx+65;
	    string secondVertex(1,c);
	    
	    cout << "First Vertex is : " << firstVertex << " and Second Vertex is : "<< secondVertex << endl;
	    graph->AddEdge(firstVertex, secondVertex, rand()%DISTANCE_RANGE);
	    
	  }
	}
      }
    }
    
    graph->PrintGraph();
    
    cout << graph->MinDistanceBetween("A","F");
    
    cout << endl;
    
    return 0;
}
