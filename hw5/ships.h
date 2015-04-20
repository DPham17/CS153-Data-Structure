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

class Frigate : public Spaceship
{
  public: 
    int m_laser;
  
  Frigate (string n,int h, int l) : Spaceship(n, h)
  {
    m_name = n;
    m_hull = h;
    m_laser = l;
  }
   
  void status() const;
    
  void hit (weapon s, int power);
  
  void fire(weapon& s, int& power);
	
};

class Destroyer : public Spaceship
{
  private:
    int m_armor;
    int m_laser, m_missile, m_missPow;
	  
  public:

    Destroyer (string n, int h, int a, int l, int m, int mp):Spaceship(n, h)
    {
      m_armor = a;
      m_laser = l;
      m_missile = m;
      m_missPow = mp;
    } 
	  
    void status() const;
    
    void hit (weapon s, int power);
  
    void fire(weapon& s, int& power);
  
};

class Battlecruiser : public Spaceship
{
  private:
    int m_shield;
    int m_laser, m_plasma;
	  
  public:
 
    Battlecruiser (string n, int h, int s, int l, int p):Spaceship(n, h)
    {
      m_shield = s;
      m_laser = l;
      m_plasma = p;
    }
	  
    void status() const;
  
    void hit (weapon s, int power);
    
    void fire(weapon& s, int& power);
};

class Dreadnought : public Spaceship
{
  private:
    int m_armor;
    int m_shield;
    int m_laser, m_missile, m_missPow, m_plasma;
	  
  public:

    Dreadnought (string n, int h, int a, int s, int l, int m, int mp, int p):Spaceship(n, h)
    {
      m_armor = a;
      m_shield = s;
      m_laser = l;
      m_missile = m;
      m_missPow = mp;
      m_plasma = p;
    }
     
    void status()const;
    
    void hit (weapon s, int power);
    
    void fire(weapon& s, int& power);
};

class Dropship : public Spaceship
{
  private:
    int m_armor;
    int m_men;
    int m_missile, m_missPow;
	  
  public:

    Dropship (string n, int h, int a, int t, int m, int mp):Spaceship(n, h)
    {
      m_armor = a;
      m_men = t;
      m_missile = m;
      m_missPow = mp;
    }
	  
    void status() const;
    
    void hit (weapon s, int power);
    
    void fire(weapon& s, int& power);
};


#include "ships.hpp"
#endif
