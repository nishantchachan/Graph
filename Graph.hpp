// Author : Nishant Chachan
// Descrp : Header file for Graph

#ifndef _GRAPH_H
#define _GRAPH_H

#include "Vertex.hpp"
#include "MinHeap.hpp"

#define DISTANCE_RANGE 500      // MAX VALUE FOR AN EDGE WEIGHT

class VerTex;

class Graph {
  
public :
  
  inline Graph(){
    m_Vertices.clear();
  }
  
  virtual ~Graph();
  
  void AddVertex(string a_label);
  
  virtual void AddEdge(string src, string dest, double w =0) = 0 ;
  
  virtual void RemoveEdge(string src, string dest) = 0;
  
  void PrintAdjacent(string src);
  
  void PrintGraph();
  
  double DistanceInBetween(string src, string dest);
  
  double MinDistanceBetween(string src, string dest);
  
  void   PathforMinDistanceBetween(string src, string dest);
  
  VerTex * GetVertexFromString(string src);
  
  inline int NumberOfVertices(){
    return m_Vertices.size();
  }
  
  
protected : 
  vector< VerTex * > m_Vertices;
  
  map< string, VerTex * > m_VertexOfString; // map which is a key value pair for input string and VerTex object corresponding to this string
  
};

#endif