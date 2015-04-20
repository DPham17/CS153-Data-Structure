//Dzu Pham
//Section A
//graph.h 


#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <string>
#include "linkedlist.h"
using namespace std;

class Graph
{
	private:
		string m_name;
		bool m_visit;
		LinkedList<string> m_data;

		
	public:
		
		Graph() //constructor
		{
			m_visit = false;
			m_name = "";
		}
		
		~Graph()
		{
			m_data.clear();
		}
		
		Graph(const string& name, bool visit)
		{
			m_name = name;
			m_visit = visit;
		}
		
		void name(const string& name)
		{
			m_name = name;
			return;
		}
		
		void insert(const string& name)
		{
			m_data.insert_front(name);
		}
		
		void visit()
		{
			m_visit = true;
			return;
		}
		
		bool getVisit()
		{
			return m_visit;
		}
		
		string getName()
		{
			return m_name;
		}
		
		friend void Check(Graph& start, int loc, Graph graph[])
		{
			string place;
			if(start.m_visit == false)
			{
				start.m_visit = true;
				for(int i=0; i<start.m_data.size(); i++)
				{
					for(int z=0; z<loc; z++)
					{
						place = graph[z].getName();
						if(start.m_data.at(i) == place)
						  Check(graph[z], loc, graph); //recursive call
					}
				}
			}
			return;
		}

};
#endif
