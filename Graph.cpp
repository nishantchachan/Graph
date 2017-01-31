//Author : Nishant Chachan
//Descrp : Source file for Graph

#include "Graph.hpp"

Graph :: ~Graph()
{
    vector < VerTex *> :: iterator it;
    
    for(it = m_Vertices.begin(); it != m_Vertices.end(); it++)
    {
      string a_name = (*it)->getName();
      m_VertexOfString.erase(a_name);
      delete (*it);
    }
}
/***********************************************************************************
 * Function : AddVerTex
 * Descrp   : This function creates VerTex object corresponding to input string
 *            and adds new object to graph's vertices vector
 * Argument : string
 * *********************************************************************************/
void Graph::AddVertex(string a_label)
{
  
  VerTex *vtx = new VerTex(a_label);
  
  m_VertexOfString.insert(pair< string, VerTex* >(a_label,vtx));
  
  m_Vertices.push_back(vtx);
  
}

/***********************************************************************************
 * Function : PrintGraph
 * Descrp   : This function Prints the current vertices in the graph and 
 *            corresponding adjacent vertices.
 * Argument : void
 * *********************************************************************************/

void Graph::PrintGraph()
{
  cout << "Printing Graph :" << endl;
  
  vector<VerTex *> :: iterator it = m_Vertices.begin();
  if(it == m_Vertices.end())
  {
    cout << "Graph is Empty" << endl;
    return;
  }
  for(; it != m_Vertices.end();it++)
  {
    cout << "Current Vertex is : " <<  (*it)->getName() << endl;
    (*it)->printAdjVertices();
    cout << endl;
    
  }
}
/*****************************************************************************************
 * Function : GetVertexFromString
 * Descrp   : it returns Vertex Object corresponding to input string object
 * Argument : string
 * ***************************************************************************************/

VerTex* Graph::GetVertexFromString(string a_String)
{
  
  map<string, VerTex*> :: iterator it;
  
  it = m_VertexOfString.find(a_String);
  if(it == m_VertexOfString.end())
  {
    return NULL;
  }
  else
  {
    return it->second;
  }
}
/***********************************************************************************
 * Function : PrintAdjacent
 * Descrp   : This function Prints the adjacent vertices in the graph
 *            corresponding to Vertex object of input string.
 * Argument : string
 * *********************************************************************************/


void Graph::PrintAdjacent(string a_String)
{
  VerTex *srcVtx = NULL;
  
  srcVtx = GetVertexFromString(a_String);
  
  if(srcVtx == NULL)
  {
    cout << "Vertex is not present in the graph" << endl;
    return;
  }
  
  srcVtx->printAdjVertices();
}
/***********************************************************************************
 * Function : DistanceInBetween
 * Descrp   : This function Prints the Edge weight bw VerTex objects of input strings
 * Argument : string, string
 * *********************************************************************************/

double Graph::DistanceInBetween(string src, string dest)
{
  VerTex *srcVtx = NULL;
  VerTex *destVtx = NULL;
  
  srcVtx = GetVertexFromString(src);
  
  if(srcVtx == NULL)
  {
    cout << "Vertex is not present in the graph" << endl;
    return 0;
  }
  
  destVtx = GetVertexFromString(dest);
  
  if(destVtx == NULL)
  {
    cout << "Vertex is not present in the graph" << endl;
    return 0;
  }
   
 return  srcVtx->Distance(destVtx);
  
}

/***********************************************************************************
 * Function : MinDistanceBetween
 * Descrp   : This function implements Dijekstra's Algorithm.
 *          : It only returns Minimum Distance bw VerTex objects of input strings
 * Argument : string, string
 * *********************************************************************************/

double Graph::MinDistanceBetween(string src, string dest)
{
  VerTex *srcVtx = NULL;
  VerTex *destVtx = NULL;
  
  srcVtx = GetVertexFromString(src);
  if(srcVtx == NULL)
  {
    cout << "Vertex is not present in the graph" << endl;
    return 0;
  }
  
  destVtx = GetVertexFromString(dest);
  if(destVtx == NULL)
  {
    cout << "Vertex is not present in the graph" << endl;
    return 0;
  }
  
  set<VerTex *> MarkedVertices;   // Vertice which we have already processed.
  
  set<VerTex *> ActiveVertices;   // Vertices which are in queue and will get processed.
  
  // Below map is very important part of this Algorithm.
  // this map contains distance of every Vertex from Source VerTex.
  // Initially we set distance of every VerTex from Source VerTex MAXIMUM.
  // than we update distance of each vertices from Source Vertex as we process them.
  // At any time , if we look into the key value pair of this map than Value corresponding to 
  // Vertex(key) represent min distance identified till now from Input Source Vertex to this VerTex.
  
  map<VerTex * , double> DistanceFromSrcVtx;
  
  for (vector<VerTex *> :: iterator it = m_Vertices.begin(); it != m_Vertices.end();it++)
  {
    if((*it) == srcVtx)
    {
      DistanceFromSrcVtx[srcVtx] = 0;
    }
    else
    {
      DistanceFromSrcVtx[(*it)] = DISTANCE_RANGE;
    }
  }
  
  MinHeap *VerticesMinHeap = NULL;    // Priority Queue Data Structure
  
  VerticesMinHeap = new MinHeap();
  
  VerticesMinHeap->AddVerTex(srcVtx,DistanceFromSrcVtx); // Adding First Element to our Priority Queue Data Structure.
  
  VerTex *currVtx = NULL;
  
  // Taking top Element of our Priority Queue DS to process.
  currVtx = VerticesMinHeap->Top();
  
  while(VerticesMinHeap->size() && currVtx != destVtx)
  {
  
    cout << "Processing Vrtex : " << currVtx->getName() << endl;
    
    VerticesMinHeap->ExtractTop(DistanceFromSrcVtx);
    
    // Adding Current VerTex to list of MarkedVertices which means we are done with current VerTex.
    // We need its adjacent vertices. Also , if there is an Edge from Current VerTex to itself than
    // it is safe to mark it done here to avoid infinte loop.
    
    MarkedVertices.insert(currVtx);
    
    // identifying adjacent Vertices of Current VerTex
    list<Edge *> adjVerEdgeList = currVtx->adjVerticesList();
    
    for (list<Edge *> :: iterator adjVerEdgeit = adjVerEdgeList.begin(); adjVerEdgeit != adjVerEdgeList.end(); adjVerEdgeit++)
    {
      
      VerTex *adjVtx = (*adjVerEdgeit)->get_adJVertex();
      double EdgeWeight = (*adjVerEdgeit)->get_weight();
      
      cout << "     Processing Adjacent VerTex : " << adjVtx->getName() << endl;
      
      // Check if this adjacent vertex is alread processed or not.
      set <VerTex *> :: iterator MarkedVerticesIterator;
      MarkedVerticesIterator = MarkedVertices.find(adjVtx);
      
      if(MarkedVerticesIterator != MarkedVertices.end())
      {
	// if current adjacent vertex is already marked than we need to work with next adjacent vertex.
	continue;
      }
      
      // Check if this adjacent vertex is already encountered or not.
      set <VerTex *> :: iterator ActiveVerticesIterator;
      ActiveVerticesIterator = ActiveVertices.find(adjVtx);
      
      if(ActiveVerticesIterator == ActiveVertices.end())
      {
	// If Not than update its distance from Source Vertex and add it to Priority Queue which in our case is Min Heap.
	// It keeps Vertex at top whose distance is Minimum from Source Vertex at any moment.
	
	DistanceFromSrcVtx[adjVtx] = DistanceFromSrcVtx[currVtx] + EdgeWeight;
	
	VerticesMinHeap->AddVerTex(adjVtx,DistanceFromSrcVtx);
	
	ActiveVertices.insert(adjVtx);
	
      }
      else
      {
	// If yes than check whether we need to update its distance from Source Vtx or Not.
	// if we need to update this than we update our Priority Queue also to have Min
	// Distance VerTex at top.
	if(DistanceFromSrcVtx[currVtx]+EdgeWeight < DistanceFromSrcVtx[adjVtx])
	{
	  DistanceFromSrcVtx[adjVtx] = DistanceFromSrcVtx[currVtx]+EdgeWeight;
	  VerticesMinHeap->UpdateHeap(DistanceFromSrcVtx);
	}
      }
    }
    
    currVtx = VerticesMinHeap->Top();
    if(currVtx == NULL)
    {
      cout << " Curr Vertex is NULL" << endl;
      return 0;
    }
    
  }
  
  return DistanceFromSrcVtx[destVtx];
}


