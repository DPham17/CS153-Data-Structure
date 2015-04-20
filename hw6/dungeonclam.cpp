//Dzu Pham
//Section A
//dungeonclam.cpp  
//Zoidberg is trapped!!!

#include <iostream>
#include <string>
using namespace std;

/*----==FUNCTIONS==----*/
char** input(int width, int height);

bool path(int nx, int ny, char** map);

bool valid (int x, int y, char** map);

void output(int width, int height, char** map);

/*----==MAIN==----*/
int main()
{
  int width, height, nx, ny, count = 0;
  char **map;
  
  do
  {
    cin >> width >> height;
    if (width > 3 && height > 3)
    {
      map = input(width, height); //generate the map
	    
      for (int i=0; i<height; i++) 
      {
        for (int k=0; k<width; k++) //this is for finding the position of Dr. Zoidberg
        {
          if (map[k][i] == 'Z')
          {
            nx = k;
      	    ny = i;
          }
        }
      }
	    path(nx, ny, map);//caculation of the path	
      
      cout << "Map : " << count << endl;
      output(width, height, map);
      cout << endl;
  
      for (int k=0; k<width; k++) // de-allocating 2d array
      {
        delete [] map[k];
      }
      delete [] map;
    }
    count ++;
  }while(width != 0 && height != 0);
  return 0;
}

/*----==FUNCTIONS==----*/
char** input(int width, int height)
{
  char **map;
  string tee;
  cin.ignore(500, '\n');
  map = new char* [width];
  for (int i=0; i<width; i++)  //Alocating a 2D Array with Row and Col
  {
    map[i] = new char[height];
  }
  
  for (int i=0; i<height; i++)  //inserting in the characters
  {
  	getline(cin, tee, '\n');
  	for (int k=0; k<width; k++)
  	{
  		map[k][i] =  tee.at(k);
  	}
  }
  return map;
}

bool path(int x, int y, char** map)
{
  int xmove[4];
  int ymove[4];
  bool ask;
  int nx, ny;	

  xmove[0]= 0;  //North
  ymove[0]= -1;
  
  xmove[1]= 1;  //East
  ymove[1]= 0;

  xmove[2]= -1; //South
  ymove[2]= 0;

  xmove[3]= 0;  //West
  ymove[3]= 1;

  for (int i=0; i<4; i++)
  {
    nx = x + xmove[i];
    ny = y + ymove[i];
    if(valid(nx, ny, map))
    {
      if(map[nx][ny] == 'E')
        return true;
      else
      {
      	map[nx][ny] = '.';
      	ask = path(nx, ny, map);
        if (ask)
 	         return true;
    	  else
    	    map[nx][ny] = ' ';
      }
    }
  }
  return false;    
}


bool valid (int x, int y, char** map)
{
  if ((map[x][y] == 'C') || (map[x][y] == '#') || (map[x][y] == 'Z') || (map[x][y] == '.'))
    return false;
  else
    return true; 
}

void output(int width, int height, char** map)
{
	for (int i=0; i<height; i++)
  {
    for(int k = 0; k<width; k++)
		{
		  cout << map[k][i];
		}
		cout << endl;
  }
}
