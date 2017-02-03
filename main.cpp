// I have used Adjacency List implementation of Graph

#include "Header.hpp"

#include "UnDirectedGraph.hpp"

using namespace std;


#define ALPHBET_RANGE 26        // Considering 26 Alphabets from A to Z as our vertices

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
    
    graph->RandomGraph(100,10);
    
    graph->PrintGraph();
    
    double AvgPathLength = 0.0;
    int VerticeToConsiderInShortesPathCalculation = graph->NumberOfVertices();
    
    // below is calculation for average shortest path length from Vertex "A" to rest of vertices
    for(int ix = 1 ; ix < graph->NumberOfVertices();ix++)
    {  
      double ShortestPathLength = 0;
      char c = ix+65;
      string secondVertex(1,c);
      
      ShortestPathLength = graph->MinDistanceBetween("A",secondVertex);
      AvgPathLength += ShortestPathLength;
      
      cout << "Shortest path Length B/w Vertex A and Vetex " << secondVertex << " is :" << ShortestPathLength << endl;
      cout << "And path for this Shortest length is : " ; 
      if(graph->PathforMinDistanceBetween("A",secondVertex) == false)
      {
	VerticeToConsiderInShortesPathCalculation--;
      }
      cout << endl;
    }
    cout << "Total Length is : " << AvgPathLength << endl;
    cout << " vertices to Consider : " << VerticeToConsiderInShortesPathCalculation << endl;
    cout << "Avg Shortest path length is : "<< (AvgPathLength)/VerticeToConsiderInShortesPathCalculation << endl;
 
    return 0;
}
