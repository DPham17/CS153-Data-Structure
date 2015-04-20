//Dzu Pham
//Section A
//mystringmap.h 

#include <iostream>
#include <string>
#include "abstractstringmap.h"
#ifndef MYSTRINGMAP_H
#define MYSTRINGMAP_H

using namespace std;

template < typename T >
class MyStringMap : public AbstractStringMap <T>
{
	
	int m_max;
  int m_size;
  string* m_keyH;
  T* m_valH;

public:
      
  MyStringMap() //CHECK THE DEAFULT CONSTRUCTOR
  {
	m_size = 0;
    m_max = 10;
	m_keyH = new string[m_max];
    m_valH = new T[m_max];
  }
  
  ~MyStringMap() //Destructor
  {
  	clear();
  }
	
	 /*** ---- Accessor Operations ---- */

// Purpose: Size
  int size() const
  {
	  return m_size;
  }

// Purpose: if its empty
  bool isEmpty() const
  {
      if(m_size == 0)
  	    return true;
      return false;
  }


// Purpose: Returns the value associated with a key.
  const T& valueOf(const string& key) const
  {
		for (int z=0; z<m_max; z++)
		{
			if (m_keyH[z] == key)
				return m_valH[z];
		}
		throw string ("Key Not Found!!");
  }


    
  /*** ---- Mutator Operations ---- */

// Purpose: Clears the Map
  void clear()
  {
	  m_size = 0;
	  m_max = 10;
	  delete [] m_keyH;
	  delete [] m_valH;
  }


// Purpose: Inserts an element into a Map
  void insert(const string& key, const T& val) 
  {
	  int i= hash(key);
		if (check(key) == true)
		{
			for (int z=0; z<m_max; z++)
			{
			  if(key == m_keyH[z])
				  m_valH[z] = val;
			}
		}
		else
		{
	    while(m_keyH[i] != "")
		    i = (i+1) % m_max;
		  m_keyH[i] = key;
	    m_valH[i] = val;
	    m_size++;
	  }
	  if (m_size > (m_max/2))
	  {
			resize();
	  }
	  return;
  }
  
// Purpose: Double the Max size of the array
  void resize()
  {
  	string *temp1 = m_keyH;
  	T *temp2 = m_valH;
  	int Zu;
	m_max *= 2;
	m_keyH = new string[m_max];
    m_valH = new T[m_max];
    
    for(int i=0; i<(m_max/2); i++)
    {
      if (temp1[i] != "")
      {
    	Zu = hash(temp1[i]);
    	while(m_keyH[Zu] != "")
	      Zu = (Zu+1) % m_max;
		m_keyH[Zu] = temp1[i];
    	m_valH[Zu] = temp2[i];
      }
    }
    delete [] temp1;
	delete [] temp2;
  }
  
// Purpose: Check if the array already contains the Key value
  bool check (const string& key)
  {
  	for (int i=0; i<m_max; i++)
  	{
  		if (key == m_keyH[i])
  		  return true;
  	}
  	return false;
  }
  
    
// Purpose: Removes an element from the Map
  void remove(const string& k)
  {
	  if(check(k) == true)
	  {
		  m_size--;
	    for (int i=0; i<m_max; i++)
	    {
	    	if (k == m_keyH[i])
	  	  {
				  m_keyH[i] = "";
	  	  }
	    }
	  }
  }
          
     
  /*** ---- Output Operations ---- */

// Purpose: Prints the Map with pretty formatting
  void print() const
  {
	  for (int i=0; i<m_max; i++)
	  {
	    if (m_keyH[i] != "")
			  cout << "< " << m_keyH[i] << " , " << m_valH[i] << " >" << endl;
	  }
  }
          
          
  /*** ---- Utility Functions Operations ---- */

// Purpose: Hashes a string into an integer.
private:
  int hash(const string &s) const
  { 
		unsigned long hash = 5381;
    int c;
    const char* str = s.c_str();
    while (c = *str++)
      hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash % m_max;
  }
          
};


#endif
