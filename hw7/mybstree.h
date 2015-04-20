//Dzu Pham
//Section A
//mybstree.h  

#include <iostream>
#include <string>
#include "abstractbstree.h"
#ifndef MYBSTREE_H
#define MYBSTREE_H

using namespace std;


template<class T>
class MyBSTree : public AbstractBSTree <T>
{
	struct TreeNode
	{
	  T m_data;
	  TreeNode* m_right;
	  TreeNode* m_left;  

	  TreeNode(const T& x, TreeNode* pLeft = NULL, TreeNode* pRight = NULL)
    {
      m_data = x;
      m_left = pLeft;
      m_right = pRight;
    }

	};

    TreeNode* m_root;

// ----------------------------------------------------

  public:
	  
    MyBSTree() //CHECK THE DEAFULT CONSTRUCTOR
    {
      m_root = NULL;
    }
		
    ~MyBSTree() //Destructor
    {
      clear();
    }
		
    MyBSTree (const MyBSTree& hiMorales)
    {
      if(this != &hiMorales)
      {
        clear();
        m_root = clone(hiMorales.m_root);
      }
    }
		
    MyBSTree& operator = (const MyBSTree& hiMorales)
    {
      if(this != &hiMorales)
      {
        clear();
        m_root = clone(hiMorales.m_root);

        return *this;
      }
    }	
/*** ---- Accessor Operations ---- */
  
    int size() const
    {
	    return size(m_root);
    } 
    
    int size(const TreeNode* t) const
    {
    	int left = 0;
    	int right = 0;
    	
			if(t == NULL)
		    return 0;
		  else
		  {
		  	left = size(t -> m_left);
    	  right = size(t -> m_right);
      }
      return (left + right + 1);
	}


    bool isEmpty() const
    {
      if(m_root == NULL)
  	    return true;
      return false;
    }


    // Purpose: Returns the height of the tree
    // Returns: height the tree 
    int height() const
    {
      return height(m_root);
    }
    
    int height (const TreeNode* t) const
    {
      int hi = 0;
			int max =0;
  	  
  	  if(t == NULL)
		    return max;
      else
      {
        hi = height(t -> m_left);
        max = hi;
        hi = height(t -> m_right);

        if (hi > max)
  	      return (hi + 1);
  	    return (max + 1);
      }
    }

    // Purpose: finds the maximum element in the Tree
    // Returns: a const reference to the maximum element
  const T& findMax() const
  {
    findMax(m_root);
  }
  
  const T& findMax(const TreeNode* t) const
  {
  	if(isEmpty())
      throw string ("PANIC : Tree is Empty!!");
    const TreeNode* p = t;
    while(p -> m_right != NULL)
    {
      p = p -> m_right;
    };
    return(p -> m_data);
  }

  // Purpose: finds the minimum element in the Tree
  // Returns: a const reference to the minimum element
  const T& findMin() const
  {
    findMin(m_root);
  }
  
  const T& findMin(const TreeNode* t) const
  {
  	if(isEmpty())
      throw string ("PANIC : Tree is Empty!!");
    const TreeNode* p = t;
    while(p -> m_left != NULL)
    {
      p = p -> m_left;
    };
    return(p -> m_data); 
  }


// Purpose: finds an element in the Tree
// Parameters: x is value to be found 
// Returns: 
//     If The tree contains x then  
//         return N, the level of the node containing x
//     If The tree does not contains x then  
//         return -N, where N is the level of the tree reached in the search 
    int contains(const T& x) const 
    {
    	//return contains(m_root, x);
    	return 0;
    }
    
    int contains(TreeNode* &t, const T& x) const
    {
      if(t == NULL)
      {
      	return height(x);
      }
			if(x < t -> m_data)
      {
      	return contains(x -> m_right, x);
      }
      if(x > t -> m_data)
      {
      	return contains(x -> m_left, x);
      }
      return height(x);
    }
  /*** ---- Mutator Operations ---- */

  
// Purpose: Clears the Tree
// Postconditions: an empty Tree
    void clear()
    {
  	  clear(m_root);
  	  m_root = NULL;
  	  return;
    }
    
    void clear (TreeNode* &x) //gets called by the real clear!!
    {
    	if (x != NULL)
    	{
    	  clear(x -> m_left);
    	  clear(x -> m_right);
    	  delete x;
    	}
    	return;
    }


// Purpose: Inserts an element into a tree
// Parameters: x is value to be added to the tree
// Postconditions: The tree now contains x
//     if the tree already contains x, ignore insertion
  void insert(const T& x)
  {
	 insert(m_root, x);
  }

  void insert(TreeNode* &t,  const T& x)
  {
    if (t == NULL)
      t = new TreeNode(x);
    if (x > t -> m_data)
      insert(t->m_right, x);
    if (x < t -> m_data)
      insert(t->m_left, x);
    return;
  }




    
// Purpose: Removes an element from the tree
// Parameters: x, the element to remove
// Postconditions: the tree does not contains x
  void remove (const T& x)
  {
    remove(m_root, x);
  }  

  void remove(TreeNode* &t, const T& x)
  {
      if (t == NULL)
  	    return;
      if (x > t -> m_data) //Knows if its right or left
        return remove(t -> m_right,x);
      if (x < t -> m_data)
  	    return remove(t -> m_left,x);
      if (t->m_right != NULL && t->m_left != NULL) //two childs
      {
    	  t -> m_data = findMax(t -> m_left);
  	    remove(t -> m_left, t -> m_data);
      }
      else 
      {
        TreeNode* temp = t;
        if (t -> m_right != NULL)//left is NULL!!
        {
          t = t -> m_right; 
          delete temp;
        }
        else if(t -> m_left != NULL) //right is NULL!!!
        {
          t = t -> m_left;
          delete temp; 
        }
        else
        {
        	t = NULL;
					delete temp;
        }
      }
  }
          
     
  /*** ---- Output Operations ---- ***/
 
  void printPreOrder() const
	{
  	printPreOrder(m_root);
  }

  void printPreOrder(const TreeNode* t) const
  {
    if(t != NULL)
    {
      cout<<t->m_data<<endl;
      printPreOrder(t->m_left);
      printPreOrder(t->m_right);
  	}
  }
  
  void printPostOrder() const
  {
  	printPostOrder(m_root);
  }

  void printPostOrder(const TreeNode* t) const
  {
    if(t != NULL)
    {
      printPostOrder(t->m_left);
      printPostOrder(t->m_right);
			cout<<t->m_data<<endl;
  	}
  }

// Purpose: Prints the Tree In-Order with formatting
//     each level indented 4 spaces, one element per line    
  void print() const
  {
     if(m_root != NULL)
     {
		   prettyPrint(m_root,0);
     }
		 return;
  }

  void prettyPrint (const TreeNode* t, int pad) const
  {
    string s(pad, ' ');
    if (t == NULL)
      cout << endl;
    else
	{
      prettyPrint(t-> m_right, pad+4);
      cout << s << t-> m_data << endl;
      prettyPrint(t-> m_left, pad+4);
    }  
  }
  

  
  
  TreeNode* clone(const TreeNode* t)
  {
    if (t == NULL)
      return NULL;
    else
		{
      return new TreeNode(t->m_data, clone(t->m_left),clone(t->m_right));
    } 
  }

	  
};  // MyBSTree

#endif
