//Dzu Pham
//Section A
//ships.hpp  
//

#include <iostream>
using namespace std;

//---====Frigate====---

void Frigate1::status() const
{
  cout << "Frigate " << m_name;
	
  if (m_hull > 0)
  {
	cout << " survived!" << endl << "Status : " << m_name;
	cout << " : hull = " << m_hull << '\n' << endl;
  }
  return;
}

void Frigate1::hit(weapon s, int power)
{
	s = s;
	m_hull -= power;
	return;
}

//---====Destroyer====---

void Destroyer1::status() const
{
  cout << "Destroyer " << m_name;
	
  if (m_hull > 0)
  {
	cout << " survived!" << endl << "Status : " << m_name;
	cout << " : hull = " << m_hull << ", armor = " << m_armor 
	     << '\n' << endl;
  }
  return;
}

void Destroyer1::hit(weapon s, int power)
{
  if (m_armor > 0 && s == missile)
  {
	m_armor -= (power/2);
	if (m_armor < 0)
      m_armor = 0;
  }
  else
	m_hull -= power;
	  
  return;
}

//---====Battlecruiser====---

void Battlecruiser1::status() const
{
  cout << "Battlecruiser " << m_name;
	
  if (m_hull > 0)
  {
	cout << " survived!" << endl << "Status : " << m_name;
	cout << " : hull = " << m_hull << ", shield = " << m_shield 
	     << '\n' << endl;
  }
  return;
}

void Battlecruiser1::hit(weapon s, int power)
{
  if (s == laser && m_shield > 0)
  {
	m_shield -= (power/3);
	if (m_shield < 0)
      m_shield = 0;
  }
  else if (s == plasma && m_shield > 0)
  {
    m_shield -= power;
    if (m_shield < 0)
      m_shield = 0;
	m_hull -= (power/2);
  }
  else
	m_hull -= power;
}

//---====Dreadnought====---

void Dreadnought1::status() const
{
  cout << "Dreadnought " << m_name;
	
  if (m_hull > 0)
  {
	cout << " survived!" << endl << "Status : " << m_name;
	cout << " : hull = " << m_hull << ", shield = " << m_shield
	     << ", armor = " << m_armor << '\n' << endl;
  }
  return;
}

void Dreadnought1::hit(weapon s, int power)
{
  if (s == laser && m_shield > 0)
  {
    m_shield -= (power/3);
    if (m_shield < 0)
      m_shield = 0;
  }
  else if (s == missile && m_armor > 0)
  {
	m_armor -= (power/2);
	if (m_armor < 0)
      m_armor = 0;
  }
  else if (s == plasma && m_shield > 0)
  {
	m_shield -= power;
	if (m_shield < 0)
      m_shield = 0;
	m_hull -= (power/2);
  }
  else
   m_hull -= power;
   
  return;
}

//---====Dropship====---

void Dropship1::status() const
{
  cout << "Dropship " << m_name;
	
  if (m_hull > 0)
  {
	cout << " survived!" << endl << "Status : " << m_name;
	cout << " : hull = " << m_hull << ", armor = " << m_armor 
	     << ", personnel = " << m_men << '\n' << endl;
  }
  return;
}

void Dropship1::hit(weapon s, int power)
{
  if (m_armor > 0 && s == missile)
  {
	m_armor -= (power/2);
	if (m_armor< 0)
      m_armor = 0;
  }
  else
  {
	m_hull -= power;
	m_men -= (m_men/4);
  }
  
  return;
}



