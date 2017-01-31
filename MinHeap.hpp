// Author : Nishant Chachan
// Descrp : header file for Min Heap
//        : I have intentionaly not made Heap as a base class and than MinHeap drived from it.

#ifndef _MIN_HEAP_H
#define _MIN_HEAP_H

#include "Header.hpp"
#include "Vertex.hpp"

class VerTex;

class MinHeap{
public:
  
  inline MinHeap (){}
  
  inline ~MinHeap(){
    MinHeapVertices.clear();
  }
  
  void AddVerTex(VerTex * a_vertex,map<VerTex *, double> &a_distance);
  
  VerTex * Top();
  
  void ExtractTop(map<VerTex *, double> &a_distance);
  
  void UpdateHeap(map<VerTex *, double> &a_distance);
  
  inline int size(){
    return MinHeapVertices.size();
  }
protected :
  
  int parent(int ix);
  
  int left(int ix);
  
  int right(int ix);
  
  void swapElement(int p_ix , int c_ix);
  
  void Heapify(int p_ix, map<VerTex *, double> &a_distance);
  
private:
  
  vector <VerTex *> MinHeapVertices;
};


#endif