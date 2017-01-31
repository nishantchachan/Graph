// Author : Nishant Chachan
// Descrp : Header File for Directed Graph
#ifndef _UD_GRAPH_H
#define _UD_GRAPH_H

#include "Graph.hpp"

class UnDirectedGraph : public Graph{
  
public : 
  inline UnDirectedGraph():Graph(){}
  
  
  
  void AddEdge(string src, string dest, double w =0);
  
  void RemoveEdge(string src, string dest);
  
};

#endif