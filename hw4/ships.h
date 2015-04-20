//Dzu Pham
//Section A
//ships.h  
//Kitty Kats

#include <iostream>
#include <string>
#include "spaceship.h"
#ifndef SHIPS_H
#define SHIPS_H

using namespace std;

class Frigate1 : public Spaceship
{
  public: 

  Frigate1 (string n,int h) : Spaceship(n, h)
  {
    m_name = n;
    m_hull = h;
  }
   
  void status() const;
    
  void hit (weapon s, int power);
	
};

class Destroyer1 : public Spaceship
{
  private:
	int m_armor;
	  
  public:

	Destroyer1 (string n, int h, int a):Spaceship(n, h)
	{
	  m_armor = a;
	} 
	  
	void status() const;
    
    void hit (weapon s, int power);
};

class Battlecruiser1 : public Spaceship
{
  private:
	int m_shield;
	  
  public:
 
    Battlecruiser1 (string n, int h, int s):Spaceship(n, h)
    {
	  m_shield = s;
	}
	  
	void status() const;
    
    void hit (weapon s, int power);
};

class Dreadnought1 : public Spaceship
{
  private:
	int m_armor;
	int m_shield;
	  
  public:

    Dreadnought1 (string n, int h, int a, int s):Spaceship(n, h)
    {
	  m_armor = a;
	  m_shield = s;
	}
     
    void status()const;
    
    void hit (weapon s, int power);
};

class Dropship1 : public Spaceship
{
  private:
    int m_armor;
    int m_men;
	  
  public:

    Dropship1 (string n, int h, int a, int t):Spaceship(n, h)
	  {
		m_armor = a;
		m_men = t;
      }
	  
    void status() const;
    
    void hit (weapon s, int power);
};


#include "ships.hpp"
#endif
