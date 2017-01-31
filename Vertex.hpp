// Author : Nishant Chachan
// Descrp : Header file for Vertex object 

#ifndef _VERTEX_H
#define _VERTEX_H

using namespace std;

#include "Edge.hpp"
#include "Header.hpp"

class VerTex
{

public:
	
	inline VerTex(){}
	
	inline VerTex( string a_name) {
	
	  m_Label = a_name;
	}
	inline VerTex(const VerTex &a_vertex)
	{
	  m_Label = a_vertex.m_Label;
	}
	
	virtual ~VerTex();
	
	bool AddEdgeToVertex(VerTex *a_vertex, double w);
	
	bool RemoveAdjacentVertex(VerTex *a_vertex);
	
	double Distance(VerTex * a_adjVtx);
	
	void printAdjVertices();
	
	inline string getName(){ return m_Label;}
	
	inline list<Edge *> & adjVerticesList()
	{
	  return m_AdjVertices;
	}
	
private:
	
	string m_Label;  // Unique Identity of a Vertex
	
	list<Edge *> m_AdjVertices; 	// Adjacency List for a Vertex
};
#endif