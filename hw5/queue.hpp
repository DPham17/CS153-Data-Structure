//Dzu Pham
//Section A
//queue.hpp  
//

#include <iostream>
using namespace std;

template <typename T>
const T& LL_Queue<T>::front()const
{
  if (!isEmpty())
  {
	return m_head -> m_data;
  }
  
  else 
    throw string("queue front is out of bounds");
}

template <typename T>
void LL_Queue<T>::enqueue (const T& x)
{
  Node<T>* pNode = new Node<T>;
  pNode -> m_data = x;
  pNode -> pNext = NULL;
  if (isEmpty())
  {
    m_head = m_tail = pNode;
  }
  else
  {
    m_tail-> pNext = pNode;
    m_tail = pNode;
  }
  m_size++;
  return;
}

template <typename T>
void LL_Queue<T>::dequeue()
{
  if(!isEmpty())
  {
    Node<T>* p = m_head;
    m_head = m_head -> pNext;
    delete p;
    m_size--;
  }
  else 
	throw (666);
  return;
}

template<typename T>
bool LL_Queue<T>::isEmpty() const
{
  return (m_size == 0);
}

template <typename T>
void LL_Queue<T>::clear()
{
  while(!isEmpty())
  {
    dequeue();
  }
}

template <typename T>
int LL_Queue<T>::size() const
{
  return m_size;
}
