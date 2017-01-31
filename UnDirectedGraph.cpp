// Author : Nishant Chachan
// Descrp : Source File for Directed Graph

#include "UnDirectedGraph.hpp"

/**************************************************************************************
 * Function : AddEdge
 * Descrp   : This function adds EDGE b/w vertices of input strings with given weight w.
 *          : As this is UnDirectedGraph so Edge addition is done both ways i.e.
 *          : From Source to destination and from destination to Source with given weight.
 * Argument : string , string, double
 * *************************************************************************************/
void UnDirectedGraph::AddEdge(string src, string dest, double w)
{
  VerTex *srcVtx = NULL;
  VerTex *destVtx = NULL;
  
  srcVtx = GetVertexFromString(src);
  if(srcVtx == NULL)
  {
    cout << "Vertex is not present in the graph" << endl;
    return ;
  }
  
  destVtx = GetVertexFromString(dest);
  if(destVtx == NULL)
  {
    AddVertex(dest);
    destVtx = GetVertexFromString(dest);
    if(srcVtx->AddEdgeToVertex(destVtx, w))
    {
   
      destVtx->AddEdgeToVertex(srcVtx,w);
    }
    return ;
  }
  
  if(srcVtx->AddEdgeToVertex(destVtx, w))
  {
    destVtx->AddEdgeToVertex(srcVtx,w);
  }
  
}


/**************************************************************************************
 * Function : RemoveEdge
 * Descrp   : This function removes EDGE b/w vertices of input strings.
 *          : As this is UnDirectedGraph so Edge removal is done both ways i.e.
 *          : From Source to destination and from destination to Source.
 * Argument : string , string,
 * *************************************************************************************/

void UnDirectedGraph::RemoveEdge(string src, string dest)
{
  VerTex *srcVtx = NULL;
  VerTex *destVtx = NULL;
  
  srcVtx = GetVertexFromString(src);
  if(srcVtx == NULL)
  {
    cout << "Vertex is not present in the graph" << endl;
    return ;
  }
  
  destVtx = GetVertexFromString(dest);
  if(destVtx == NULL)
  {
    cout << "Vertex is not present in the graph" << endl;
    return ;
  }
  
  cout << "Removing Exisitng Edge b/w : " << srcVtx->getName() << " and " << destVtx->getName() << endl;
  
  if(srcVtx->RemoveAdjacentVertex(destVtx))
  {
    destVtx->RemoveAdjacentVertex(srcVtx);
  }
  
  return;

}
