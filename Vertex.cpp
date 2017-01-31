// Author : Nishant Chachan
// Descrp : Source File for Vertex

#include "Vertex.hpp"

VerTex :: ~ VerTex()
{
  m_AdjVertices.clear();
}

/*********************************************************************************
 * Name    : AddEdgeToVertex
 * Descrp  : This function will add a new edge to current Vertex with get_weight
 * Argument: a_vertex(adjacent vertex)
 *           w(weight)
 * *******************************************************************************/
bool VerTex::AddEdgeToVertex(VerTex* a_vertex,double w)
{
  list < Edge* > :: iterator it;
  
  for(it = m_AdjVertices.begin(); it != m_AdjVertices.end();it++)
  {
    if(((*it)->get_adJVertex() ) == a_vertex)
    {
      return false;
    }
  }
  
  Edge *Edgeptr = new Edge(a_vertex,w);
  
  m_AdjVertices.push_back(Edgeptr);
  
  return true;
  
}

/*****************************************************************************************
 * Name    : RemoveAdjacentVertex
 * Descrp  : This function will remove edge b/w input adjacent vertex and current vertex 
 *           if it is present
 * Argument: a_vertex(adjacent vertex)
 * ***************************************************************************************/

bool VerTex::RemoveAdjacentVertex(VerTex* a_vertex)
{
  list < Edge* > :: iterator it;
  for(it = m_AdjVertices.begin(); it != m_AdjVertices.end();it++)
  {
    if(((*it)->get_adJVertex() ) == a_vertex)
    {
      m_AdjVertices.erase(it);
      
      return true;
    }
  }
  if(it == m_AdjVertices.end())
  {
    cout << a_vertex->getName() << " is not adjacent to " << this->getName() << endl;
    return false;
  }
}

/*****************************************************************************************
 * Name    : printAdjVertices
 * Descrp  : This function will print all adjacent vertices to current VerTex
 * Argument: void
 * ***************************************************************************************/

void VerTex::printAdjVertices()
{
  list < Edge* > :: iterator it;
  
  cout << "Adjacent Vertices to " << this->getName() << " are : " ;
  
  it = m_AdjVertices.begin();
  
  if(it != m_AdjVertices.end())
  {
    cout << (*it)->get_adJVertex()->getName() << "(" << (*it)->get_weight() << ")";
    it++;
  }
  for(; it != m_AdjVertices.end();it++)
  {
    cout << ", ";
    cout << (*it)->get_adJVertex()->getName()<< "(" << (*it)->get_weight() << ")";
  }
}

/*****************************************************************************************
 * Name    : RemoveAdjacentVertex
 * Descrp  : This function will provide edge weight b/w current VerTex and input adjacent
 *           Vertex
 * Argument: a_vertex(adjacent vertex)
 * ***************************************************************************************/
double VerTex::Distance(VerTex* a_adjVtx)
{
  list < Edge* > :: iterator it;
  for(it = m_AdjVertices.begin(); it != m_AdjVertices.end();it++)
  {
    if(((*it)->get_adJVertex() ) == a_adjVtx)
    {
      return (*it)->get_weight(); 
    }
  }
  if(it == m_AdjVertices.end())
  {
    cout << a_adjVtx->getName() << " is not adjacent to " << this->getName() << endl;
    return 0;
  }
}




