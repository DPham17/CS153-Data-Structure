//Dzu Pham
//Section A
//linkedlist.hpp  
//For Dr. Zoidberg to license Arraylist to his home planet of Decapod-10 

#include <iostream>
using namespace std;


// Purpose: performs a deep copy of the data 
template <class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rhs)
{
  if(this != &rhs)
  {
     LinkedList<T> p( rhs );
     LinkedList* pTemp = p.m_next;
     p.m_next = m_next;
     m_next = pTemp;
     m_data = rhs.m_data;
  } 
  return *this;	
}

// Purpose: copy constructor
template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& cpy)
{
  const LinkedList* pCpy = &cpy;
  LinkedList* p = this;
	
  while (pCpy -> m_next != NULL)
  {
    LinkedList* ptr = new LinkedList<T>;
    p -> m_data = pCpy -> m_data;
    p -> m_next = ptr;
    p = p -> m_next;
    pCpy = pCpy -> m_next;
  }
}


// Purpose: accessor function for the current # data values in the list
template <class T>
int LinkedList<T>:: size() const
{
  int count = 0;
  LinkedList* p = m_next;
  while (p != NULL)
  {
    count++;
    p = p -> m_next;
  }
  return count;
}
    
// Purpose: determines whether the list is empty
template <class T>
bool LinkedList<T>:: isEmpty() const
{
  bool check = false;
  if (m_next == NULL)
    check = true;
  return check;
}

// Purpose: Get a pointer to the first element node
template <class T>
LinkedList<T>* LinkedList<T>::getFirstPtr()
{
  if(m_next != NULL)
    return this;
  else
    return NULL;
}

// Purpose: accessor function for last element node
template <class T>
LinkedList<T>* LinkedList<T>::getLastPtr()
{
  LinkedList* p = this;
  if(p->m_next != NULL)
  {
    while(p->m_next->m_next != NULL)
    {
      p = p->m_next;
    }
    return p;
  }
  else
  {
    cout << "Error in getLastPtr" <<endl;
    return NULL;
  }

}

// Purpose: accessor function for a node in the list
template <class T>
LinkedList<T>* LinkedList<T>::getAtPtr(int i)
{
  LinkedList<T>* p = this;
  if(p -> m_next != NULL)
  {
    for(int k=0; k < i; k++)
    {
       if(p -> m_next == NULL)
       {
         cout << "Error" <<  endl;
         return NULL;
       }
       else
         p = p -> m_next;  
       }
       return p;
    }
  else
    return NULL;
}

// Purpose: accessor function for the first element of the list
template <class T>
T* LinkedList<T>::first()
{
  if (m_next != NULL)
    return &m_data;
  else
  {
    cout << "PANIC in LinkedList.first() - empty list" << endl;
    return NULL;
  }
}
  
// Purpose: accessor function for the last element of the list
template <class T>
T* LinkedList<T>::last()
{
	LinkedList* p = this;
  if(m_next != NULL)
  {
    while(p -> m_next != NULL)
    {
      p = p -> m_next;
    }
    return &p -> m_data; 
  }
  else
  {
    cout << "PANIC in LinkedList.last() - empty list" << endl;
      return NULL;
	  
  }
}

// Purpose: accessor function for an element of the list
template <class T>
T LinkedList<T>::at(int i)
{
  int count = 0;
  LinkedList* p = this;
  if(i<(*this).size())
  {
    while(count < i)
    {
      p = p -> m_next;
      count++;
    }
    return p-> m_data;
  }
  else
  {
    cout << "PANIC in LinkedList.at() - invalid index" << endl;
      return NULL;
  }
}

// Purpose: effectively "empties" the list
template <class T>
void LinkedList<T>:: clear()
{
  LinkedList* p = this;

  while(m_next != NULL)
  {
    LinkedList* temp = p->m_next;
    m_next = p -> m_next -> m_next;
    delete temp;
  }
  return;
}


// Purpose: puts the data x in the front of the list 
template <typename T> 
void LinkedList<T>:: insert_front(const T& x)
{
    LinkedList* p = this;
    LinkedList* temp = new LinkedList<T>;
    temp ->  m_data = p -> m_data;
    temp -> m_next = p -> m_next;
    p -> m_data = x;
   	p -> m_next = temp;
   	return;
}

// Purpose: puts the data value x in the list at position i
template <typename T> 
void LinkedList<T>:: insert(const T& x, int i)
{
  //variables
  LinkedList<T>* p = this;

  //go to desired cell i
  for(int k = 0; k < i; k++)
  {
      //if the next cell is sentinel, panic
      if(p->m_next == NULL)
      {
          cout << "PANIC in LinkedList.insert(int i) -- invalid index" << endl;
          return;
      }
      //if not, go to the next cell
      else
      {
          p = p->m_next;
      }
  }

  insert(x,p);
  return;
}


template <typename T> 
void LinkedList<T>:: insert(const T& x, LinkedList<T>* pos)
{
  LinkedList* p = this;
  while (p -> m_data != pos -> m_data)
  {
    p = p -> m_next;
  }
	
  if ((p -> m_data == pos -> m_data)&& (p -> m_next != NULL))
  {
    LinkedList* temp = new LinkedList<T>;
    temp -> m_data = p -> m_data;
    temp -> m_next = p -> m_next;
    p -> m_data = x;
    p -> m_next = temp;
  }
  else
    cout << "PANIC in LinkedList.insert(pos) -- invalid index" << endl;
  return;
}

// Purpose: removes the element at position i
template <typename T> 
void LinkedList<T>:: remove(int i)
{
  LinkedList* p = this;
  for(int k=0; k<i; k++)
  {
    if(p -> m_next == NULL)
    {
      cout << "PANIC in LinkedList.remove(int i) - invalid index" << endl;
      return;
    }
    else
    {
      p = p -> m_next;
    }
  }
  LinkedList* temp = p -> m_next;
  p -> m_data = temp -> m_data;
  p -> m_next = temp -> m_next;
  delete temp;
	
  return;
}

// Purpose: removed the element in the position pointed by pos
template <typename T> 
void LinkedList<T>:: remove(LinkedList<T>* pos)
{
  LinkedList* p = this;
  while (p -> m_data != pos -> m_data || (p->m_next != pos->m_next))
  {
    p = p -> m_next;
  }
	
  if ((p -> m_data == pos -> m_data)&& (p -> m_next != NULL))
  {
    LinkedList* temp = p -> m_next;
    p -> m_data = temp -> m_data;
    p -> m_next = temp -> m_next;
    delete temp;
  }
  return;
}


// Purpose: determines whether this list is identical to rhs list in
template <typename T>
bool LinkedList<T>::operator== (const LinkedList<T>& rhs) const
{
  bool check = false;
  bool checkSwitch = false;

  if(this->size() == rhs.size())
  {
    const LinkedList* p = &rhs;
    const LinkedList* q = this;
    while(p->m_next != NULL)
    {
      if((q->m_data == p->m_data)&&(!checkSwitch))
      {
        check = true;
      }
      else
      {
        check = false;
        checkSwitch = true;
      }
      q = q->m_next;
      p = p->m_next;
    }
  }

  return check;	
}

// Purpose: determines whether x is in the list
template <typename T>
LinkedList<T>* LinkedList<T>::find(const T& x)
{
  LinkedList* p = this;
  int count = size();

  for(int k = 0; k < count; k++)
  {
    if(p -> m_data == x && p -> m_next != NULL)
      return p;
    else
      p = p -> m_next;
  }

  cout << "PANIC, NOT FOUND!" << endl;
  return NULL;
}

    
// Purpose: removes all duplicates from the lost
template <class T>
void LinkedList<T>:: purge()
{
  LinkedList* p = this;
  LinkedList* q;
	
  while (p -> m_next != NULL)
  {
    q = p -> m_next;
    while (q -> m_next != NULL)
    {
       if(p -> m_data == q->m_data)
         remove(q);    
       else
         q = q->m_next;
    }
    p = p -> m_next;
  }
  return;
}

// Purpose: appends two lists
template <typename T> 
void LinkedList<T>::append(const LinkedList<T>& xlist)
{
  LinkedList* p = this;
  const LinkedList* f = &xlist;

  while(p->m_next->m_next != NULL)
  {
    p = p->m_next;
  }
  while(f->m_next != NULL)
  {
    p->m_next->m_data = f->m_data;
    LinkedList* temp = new LinkedList<T>;
    p->m_next->m_next = temp;
    p = p->m_next;
    f = f->m_next;
  }
  return;

  /* __This works too, which is correct?___
  LinkedList<T>* temp = getLastPtr();
  temp = temp->m_next;
  *temp = xlist;
  return;*/
}


