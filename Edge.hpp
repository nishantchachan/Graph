// Author : Nishant Chachan
// Descrp : Header file for Edge object
//        : It contains adjacent Vertex to a given Vertex and weight corresponding to this Edge.

#ifndef _EDGE_H
#define _EDGE_H

#include "Vertex.hpp"

class VerTex;

class Edge
{
public:
  inline Edge(){}
  
  inline Edge(VerTex *a_vertex, double w = 0)
  {
    adjVertex = a_vertex;
    weight = w;
  }

  inline VerTex* get_adJVertex()
  {
    return adjVertex;
  }
  
  inline double get_weight()
  {
    return weight;
  }

private:
  VerTex *adjVertex;
  double weight;
};

#endif
