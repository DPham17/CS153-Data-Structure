//Dzu Pham
//Section A
//zday.cpp

#include <iostream>
#include <string>
#include "linkedlist.h"
#include "graph.h"
using namespace std;

/*----==MAIN==----*/
int main ()
{
	
	int times, loc, con, places; //con is connections
	string city, point;
	bool reachable = false;
	
	cin >> times;
	
	do
	{
		//cout << "city" << endl;
		cin >> city;
		//cout << "locations" << endl;
		cin >> loc;
		
		Graph* citites = new Graph[loc];
		
		for(int i=0; i<loc; i++)
		{
			//cout << "Place" << endl;
			cin >> point;
			//cout << "connections" << endl;
			cin >> con;
			
			citites[i].name(point); 
			
			for(int k=0; k<con; k++) //takes the input of the next connections
			{
				//cout << "Connects to " << k << endl;
				cin >> point;
				citites[i].insert(point); 
			}
		}
		
		Check(citites[0], loc, citites);
		
		cout << "In " << city << ":" << endl;
		for(int z=0; z<loc; z++)
		{
			if(citites[z].getVisit() == false)
			{
				cout << citites[z].getName() << " unreachable from the airport." << endl;
				reachable = true;
			}
			else if(z == (loc-1) && !reachable)
			  cout << "All locations reachable from the airport." << endl;
		}
		
		
		times--;
		delete [] citites;
		reachable = false;
	}while(times > 0);
	
	return 0;
}



		
