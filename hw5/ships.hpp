//Dzu Pham
//Section A
//ships.hpp  
//

#include <iostream>
using namespace std;

//---====Frigate====---

void Frigate::status() const
{	
  cout << m_name << " : hull = " << m_hull << " : laser = " << m_laser 
       << "." << endl;
  return;
}

void Frigate::hit(weapon s, int power)
{
  m_hull -= power;
  return;
}

void Frigate::fire(weapon& s, int& power)
{
  s = LASER;
  power = m_laser;
  return;
}

//---====Destroyer====---

void Destroyer::status() const
{
  cout << m_name << " : hull = " << m_hull << ", armor = " << m_armor 
       <<" : laser = " << m_laser << " missiles = " << m_missile 
			 << "," << m_missPow << "." << '\n' << endl;
  return;
}

void Destroyer::hit(weapon s, int power)
{
  if (m_armor > 0 && s == MISSILE)
  {
    m_armor -= static_cast<int>(power/2.0);
    if (m_armor < 0)
      m_armor = 0;
  }
  else
	m_hull -= power;
	  
  return;
}

void Destroyer::fire(weapon& s, int& power)
{
  if (m_missile > 0)
  {
    s = MISSILE;
    power = m_missPow;
		m_missile -= 1;
  }	
  else 
  {
    s = LASER;
    power = m_laser;
  }
  return;
}

//---====Battlecruiser====---

void Battlecruiser::status() const
{
  cout << m_name << " : hull = " << m_hull << ", shield = " << m_shield 
       << '\n' << endl;
  return;
}

void Battlecruiser::hit(weapon s, int power)
{
  if (s == LASER && m_shield > 0)
  {
    m_shield -= static_cast<int>(power/3.0);
    if (m_shield < 0)
      m_shield = 0;
  }
  else if (s == PLASMA && m_shield > 0)
  {
    m_shield -= power;
    if (m_shield < 0)
      m_shield = 0;
    m_hull -= static_cast<int>(power/2.0);
  }
  else
    m_hull -= power;
}

void Battlecruiser::fire(weapon& s, int& power)
{
  if (m_hull <= 10 || m_shield <= 0)
  {
    s = PLASMA;
    power = m_plasma;
    m_shield -= static_cast<int>(power/2.0);
    if (m_shield <= 0)
      m_shield = 0;
  }
  else
  {
    s = LASER;
    power = m_laser;
  }
  return;
}

//---====Dreadnought====---

void Dreadnought::status() const
{
  cout << m_name << " : hull = " << m_hull << ", shield = " << m_shield
       << ", armor = " << m_armor <<  " : laser = " << m_laser  
       << " missile = " << m_missile << "," << m_missPow 
	     << " plasma = " << m_plasma << "." << '\n' << endl;
  return;
}

void Dreadnought::hit(weapon s, int power)
{
  if (s == LASER && m_shield > 0)
  {
    m_shield -= static_cast<int>(power/3.0);
    if (m_shield < 0)
      m_shield = 0;
  }
  else if (s == MISSILE && m_armor > 0)
  {
    m_armor -= static_cast<int>(power/2.0);
    if (m_armor < 0)
      m_armor = 0;
  }
  else if (s == PLASMA && m_shield > 0)
  {
    m_shield -= power;
    if (m_shield < 0)
      m_shield = 0;
    m_hull -= static_cast<int>(power/2.0);
  }
  else
    m_hull -= power;
   
  return;
}

void Dreadnought::fire(weapon& s, int& power)
{
  if (m_missile > 0)
  {
    s = MISSILE;
    power = m_missPow;
    m_missile -= 1;
  }
  else if (m_shield > 15)
  {
    s = PLASMA;
    power = m_plasma;
    m_shield -= static_cast<int>(power/2.0);
    if (m_shield <= 0)
      m_shield =0;
  }
  else
  {
    s = LASER;
    power = m_laser;
  }
 return;  
}

//---====Dropship====---

void Dropship::status() const
{
  cout << m_name << " : hull = " << m_hull << ", armor = " 
       << m_armor << ", personnel = " << m_men << " missiles = " 
       << m_missile << "," << m_missPow << '\n' << endl;
  return;
}

void Dropship::hit(weapon s, int power)
{
  if (m_armor > 0 && s == MISSILE)
  {
    m_armor -= static_cast<int>(power/2.0);
    if (m_armor< 0)
      m_armor = 0;
  }
  else
  {
    m_hull -= power;
    m_men -= static_cast<int>(m_men/4.0);
  }
  
  return;
}

void Dropship::fire(weapon& s, int& power)
{
  if (m_missile > 0)
  {
    s = MISSILE;
    power = m_missPow;
    m_missile -= 1;
  }
  else 
  {
    s = LASER;
    power = 0;
  }
  return;
}



