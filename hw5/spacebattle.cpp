//Dzu Pham
//Section A
//spacebattle.cpp  
//he wants you to write the simulation program again

#include <iostream>
#include <string>
#include "spaceship.h"
#include "abstractqueue.h"
#include "ships.h"
#include "queue.h"
using namespace std;

void fight(LL_Queue<Spaceship*>&);

int main()
{
  LL_Queue<Spaceship*> LL;
  int times, type, hull, armor, shield, men, laser, plasma, missiles, missPow;
  string name;
  Spaceship *ship;
	
  cin >> times;
  cout << endl;
	
  for (int k=0; k<times; k++)
  {	
		cin >> type;

    switch (type)
    {
      case FRIGATE:
        cin >> name;
        cin >> hull;
        cin >> laser;
        ship = new Frigate(name, hull, laser);
        LL.enqueue(ship);
        break;
				
      case DESTROYER:
        cin >> name;
        cin >> hull;
        cin >> armor;
        cin >> laser;
        cin >> missiles;
        cin >> missPow;
        ship = new Destroyer(name, hull, armor, laser, missiles, missPow);
        LL.enqueue(ship);
        break;
				
      case BATTLECRUISER:
        cin >> name;
        cin >> hull;
        cin >> shield;
        cin >> laser;
        cin >> plasma;
        ship = new Battlecruiser(name, hull, shield, laser, plasma);
        LL.enqueue(ship);
        break;
				
      case DREADNOUGHT:
        cin >> name;
        cin >> hull;
        cin >> armor;
        cin >> shield;
        cin >> laser;
        cin >> missiles;
        cin >> missPow;
        cin >> plasma;
        ship = new Dreadnought(name, hull, armor, shield, laser, missiles, missPow, plasma);
        LL.enqueue(ship);
        break;
				
      case DROPSHIP:
        cin >> name;
        cin >> hull;
        cin >> armor;
        cin >> men;
        cin >> missiles;
        cin >> missPow;
        ship = new Dropship(name, hull, armor, men, missiles, missPow);
        LL.enqueue(ship);
        break;
				
      default:
        cout << "Error" << endl; 
    }
  }
	try
	{
    fight(LL);
	}
	catch (string)
	{
	  cout << "Error" << endl;
	}
	LL.clear();
  return 0;
}
	
	
void fight(LL_Queue<Spaceship*>& LL)
{
  Spaceship* Player1;
  Spaceship* Player2;
  Spaceship* winner;
  bool alive = true;
  
  weapon w;
  int count = 1, p;
  
  while (LL.size() > 1)
  {
    Player1 = LL.front();
    LL.dequeue();
    Player2 = LL.front();
    LL.dequeue();
    alive = true;

    cout << "Battle #" << count << " : ";
    cout << Player1->getName() << " vs. " << Player2->getName() << "." << endl;
    
    do
    {
      Player1->fire(w,p);
      //cout << Player1->getName() << " Player 1 fire weapon "<< w << " power " << p << endl;
      //Player2->status();
			Player2->hit(w,p);
      //cout << Player2->getName() << " Player 2 hit weapon " << w << " power " << p << endl;
      //Player2->status();
      
      if (Player2->getHull() <= 0)
      {
        LL.enqueue(Player1);
    	  cout << "Winner! : " << Player1->getName() << "." << endl;
	      Player1->status();
	      winner = Player1;
	      delete Player2;
	      alive = false;
      }
      else
      {
    	  Player2->fire(w,p);
    	  //cout <<Player2->getName() <<  " Player 2 fire weapon " << w << " power " << p << endl;
    	  //Player1->status();
			  Player1->hit(w,p);
    	  //cout <<Player1->getName() <<  " Player 1 hit weapon " << w << " power " << p << endl;
    	  //Player1->status();
    	  if (Player1->getHull() <= 0)
    	  {
          LL.enqueue(Player2);
    	    cout << "Winner! : " << Player2->getName() << "." << endl;
	        Player2->status();
	        winner = Player2;
	        delete Player1;
	        alive = false;
    	  }
      }  
    }while (alive == true);
    count++;  
  }
  cout << "*** CHAMPION!!! : " << winner->getName() << "." << endl;
  winner->status();
  delete winner;
  return;
}	
	
