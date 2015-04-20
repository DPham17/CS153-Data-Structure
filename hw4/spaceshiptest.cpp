//Dzu Pham
//Section A
//spaceshiptest.cpp  
//he wants you to write the simulation program.

#include <iostream>
#include <string>
#include "spaceship.h"
#include "ships.h"
using namespace std;

//Simulate the program for the big ball attack
//Pre: Have the pointer pointing to something
//Post: Calculates the hit and outputs the results
void attack(Spaceship* ship);

int main()
{

  int times, type, hull, armor, shield, men;
  string name;
  Spaceship *ship;

	
  cin >> times;
  cout << endl;
	
  for (int k=0; k<times; k++)
  {	
    cin >> type;
		
    switch (type)
    {
      case frigate:
        cin >> name;
        cin >> hull;
        ship = new Frigate1(name, hull);
        break;
				
      case destroyer:
        cin >> name;
        cin >> hull;
        cin >> armor;
        ship = new Destroyer1(name, hull, armor);
        break;
				
      case battlecruiser:
        cin >> name;
        cin >> hull;
        cin >> shield;
        ship = new Battlecruiser1(name, hull, shield);
        break;
				
      case dreadnought:
        cin >> name;
        cin >> hull;
        cin >> armor;
        cin >> shield;
        ship = new Dreadnought1(name, hull, armor, shield);
        break;
				
     case dropship:
        cin >> name;
        cin >> hull;
        cin >> armor;
        cin >> men;
        ship = new Dropship1(name, hull, armor, men);
        break;
				
     default:
       cout << "Invalid ship" << endl; 
    }
    cout << endl << "#" << k << endl;
    attack(ship);
    delete ship;
  }
  return 0;
}

void attack(Spaceship* ship)
{
  int shots = 0, power;
  string weapon;
  while ((ship -> isAlive()) && (shots < 5))
  {
    switch (shots)
    {
	  case 0:
	    ship -> hit(laser, 5);
            power = 5;
            break;
	  case 1:
            ship -> hit(laser, 10);
            power = 10;
            break;
	  case 2:
	    ship -> hit(laser, 15);
            power = 15;
            break;
	  case 3:
            ship -> hit(missile, 20);
            power = 20;
            break;
        case 4:
          ship -> hit(plasma, 25);
          power = 25;
          break;
	}
    shots++; 
  }
  ship -> status();
  shots--;
  if (ship -> isAlive())
    return;
  else if (shots < 3)
    cout << " destroyed after laser power " << power << '\n' << endl;
  else if (shots == 3)
    cout << " destroyed after missile power " << power << '\n' <<  endl;
  else if (shots == 4)
    cout << " destroyed after plasma power " << power << '\n' <<  endl;
		
  return;
}
