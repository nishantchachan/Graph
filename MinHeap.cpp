// Author : Nishant Chachan
// Descrp : Source File for Min Heap which is specifically used in Dijkstra Algorithm
//        : This is A Min Heap Priority queue with assumption that everyone is aware about
//        : meaning of Functions Like Heapify, parent, left, right.
//        : Please refer Heap Data Structure if anyone is not aware about this concept.

#include "MinHeap.hpp"

int MinHeap::parent(int ix)
{
  if(ix == 0)
  {
    return -1;
  }
  
  return ((ix-1)/2);
}

int MinHeap::left(int ix)
{
  int l_ix = (2 * ix) +1;
  if(l_ix >= MinHeapVertices.size())
  {
    return 0;
  }
  else
  {
    return l_ix;
  }
}

int MinHeap::right(int ix)
{
  int r_ix = (2 * ix) +2;
  if(r_ix >= MinHeapVertices.size())
  {
    return 0;
  }
  else
  {
    return r_ix;
  }
}

void MinHeap::swapElement(int p_ix, int c_ix)
{
  VerTex* temp = MinHeapVertices[p_ix];
  
  MinHeapVertices[p_ix] = MinHeapVertices[c_ix];
  MinHeapVertices[c_ix] = temp;
  
}

void MinHeap::Heapify(int p_ix, std::map< VerTex*, double >& a_distance)
{
  int currIx = -1;
  
  while(1)
  {
    currIx = p_ix;
    int l_ix = left(currIx);
    int r_ix = right(currIx);
    
    if(l_ix)
    {
      if(a_distance[MinHeapVertices[l_ix]] < a_distance[MinHeapVertices[currIx]])
      {
	currIx = l_ix;
      }
    }
    
    if(r_ix)
    {
      if(a_distance[MinHeapVertices[r_ix]] < a_distance[MinHeapVertices[currIx]])
      {
	currIx = r_ix;
      }
    }
    if(currIx != p_ix)
    {
      swapElement(p_ix,currIx);
      p_ix = currIx;
    }
    else
    {
      break;
    }
  }
}


void MinHeap::AddVerTex(VerTex* a_vertex, std::map< VerTex*, double >& a_distance)
{
  if(a_vertex == NULL)
  {
    return;
  }
  
  MinHeapVertices.push_back(a_vertex);
  
  if(MinHeapVertices.size() == 1)
  {  
    return;
  }
  
  int ix = (MinHeapVertices.size() -1);
  
  int p_ix = parent(ix);
  
  bool swapped = true;
  
  while((p_ix != -1) && (swapped == true))
  {
    VerTex *PVtx = MinHeapVertices[p_ix];
    VerTex *CVtx = MinHeapVertices[ix];
    
    if(a_distance[CVtx] < a_distance[PVtx])
    {
      swapElement(p_ix, ix);
      ix = p_ix;
      p_ix = parent(ix);
    }
    else{
      swapped = false;
    }
    
  }
  VerTex *top = Top();
  cout << "     At Top :" << top->getName() << endl;
}


VerTex* MinHeap::Top()
{
  if(MinHeapVertices.size())
  {
    return MinHeapVertices[0];
  }
  else
  {
    return NULL;
  }
}

void MinHeap::ExtractTop(std::map< VerTex*, double >& a_distance)
{
  if(MinHeapVertices.size() == 0)
  {
    return;
  }
  if(MinHeapVertices.size() == 1)
  {
    MinHeapVertices.pop_back();
    return;
  }
  
  int LastIx = MinHeapVertices.size() -1;
  
  MinHeapVertices[0] = MinHeapVertices[LastIx];
  
  MinHeapVertices.pop_back();
  
  if(MinHeapVertices.size() == 1)
  {
    return;
  }
  
  Heapify(0, a_distance); 
  
  VerTex *top = Top();
  cout << "     At Top :" << top->getName() << endl;
  
}

void MinHeap::UpdateHeap(std::map< VerTex*, double >& a_distance)
{
  
  if(MinHeapVertices.size() <= 1)
  {
    return;
  }
  
  int currSize = MinHeapVertices.size();
  
  for (int ix = (currSize-1)/2; ix >= 0 ; ix--)
  {
    Heapify(ix, a_distance);
  }
  VerTex *top = Top();
  cout << "     At Top :" << top->getName() << endl;
}
