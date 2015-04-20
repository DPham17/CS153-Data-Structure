//Dzu Pham
//Section A
//ships.h  
//Kitty Kats

#include <iostream>
#include <string>
#include "abstractqueue.h"
#ifndef QUEUE_H
#define QUEUE_H

using namespace std;

template <class T>
struct Node
{
  Node<T>* pNext;
  T m_data;
};


template<class T>
class LL_Queue : public AbstractQueue <T>
{
  private:
    Node<T>* m_head; //front
    Node<T>* m_tail; //tail
    int m_size;
		
  public:
    LL_Queue() 
    { 
      m_size = 0;
      m_head = NULL;
      m_tail = NULL;
    }
	
    const T& front ()const;

    void enqueue(const T& x);

    void dequeue();

    bool isEmpty()const;

    void clear();

    int size()const ;
    
    ~LL_Queue() 
    {
      clear();
    }
};

#include "queue.hpp"

#endif
