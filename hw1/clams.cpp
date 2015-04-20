//Dzu Pham
//Class: CS 153
//clams.cpp
//Description: Dr. Zoidberg is fishing for clams, because clams are delicious!

#include <iostream>
#include <fstream>
using namespace std;

/*Calculates the points on the data*/
/*Pre: The alots in the array must be an int*/
/*Post: Outputs the Calculations of the resultes*/
void calc(int** p, int w, int h, int t);

int main()
{
  int t, w, h, x, time = 0;
  int ** p;
  
  cin >> t;
  
  do //reading the input file
  {
    time++;
    cin >> w;
    cin >> h;
    p = new int* [w];
    for (int k=0; k<w; k++)  //Allocating
    {
      p[k] = new int[h];
    }
	
    for (int i=0; i<h; i++) //setting each slot of the array
    {
      for (int k=0; k<w; k++)
      {
         cin >> x;
         p[k][i] = x;
      }
    }
	
    calc(p, w, h, time);
	
    for (int k=0; k<w; k++) //De-allocating
    {
      delete[] p[k];
    }
    delete[] p;
    p = NULL;
	
  }while(time != t);
  
  
  return 0; 
}

void calc(int** p, int w, int h, int t)
{
  int clams=0, maxClams=0, xcoord=0, ycoord=0;
  for (int j=1; j<(h-1); j++) //for looking for the points in the array
    {
    for (int m=1; m<(w-1); m++)
    {
      clams += p[m-1][j-1];
      clams += p[m-1][j];
      clams += p[m-1][j+1];
      clams += p[m][j-1];
      clams += p[m][j];
      clams += p[m][j+1];
      clams += p[m+1][j-1];
      clams += p[m+1][j];
      clams += p[m+1][j+1];
		
      if (clams > maxClams)
      {
        maxClams = clams;
        xcoord = m;
        ycoord = j;
      }
      clams = 0;
    }
  }
  cout << "#" << t-1 << ": (" << xcoord << "," << ycoord << ") " << maxClams << endl;
  return;
}
