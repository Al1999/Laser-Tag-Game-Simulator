// Alkhatab Alrashdi
// November 4th, 2019

// *************************************************************
// The purpose of this program is to play the lazer tag game in 
// a course that contains obtscals, players, and the home base 
// where the player can reload their lazer gun. The users can 
// play in the course and move to 4 directions, if they shoot an 
// obstcal their ammunition would decrease. Also, the game would be over
// , if they meet a player from the opposing team and their ammunition
// is 0. The home base is in one location in the course. The users can 
// delete the current course and start over. Their position on the course 
// will be available for them in each move they take in the game. 
// *************************************************************

#include "alrashdi_header.h"

using namespace std;

// game class constructor
game::game( int size )
{
  list_size = size ;
  head = new node * [list_size];
  for (int i = 0 ; i < list_size ; ++i )
  {
    head[i] = NULL ;
  }
  v = 0 ;
  h = 0 ;
  w = 0 ;
  n_amm = 0 ;
}
//game class destructor
game::~game()
{
  int i = 0 ;

  for (int i = 0 ; i < list_size ; ++i )
  {
    if(head[i])
    {
      delete_course( head[i] ); //recursive function to delete all the nodes
      head[i] = NULL ; 
    }
    else 
    {
      delete head[i];
    }
  }


  delete []  head ; //deleteing the head pointer
}
//building the lazer tag obstcals course function
void game::build_course()
{
  n_amm = 5 ; //setting the ammunition to 5
  build1();
  build2();
  build3();
  build4();
}
//Building the first Horizontal line function
void game::build1()
{
  //3 objects in this line:
  node * current ;
  head[0] = new node ;
  head[0] -> setnum(4); //free space
  head[0] -> setprevious(NULL);
  head[0] -> setnext(NULL);
  current = new node ;
  current -> setcourse3();
  current -> setnum(3); //player
  head[0] -> setnext(current);
  current -> setprevious(head[0]);
  current -> setnext (NULL);
  node * temp = new node ;
  temp -> setcourse1();
  temp -> setnum(1); //obstacle
  current -> setnext(temp);
  temp -> setprevious(current);
  temp -> setnext (NULL);
}
//Building the 2nd Horizontal line function
void game::build2()
{
  //3 objects in this line:
  node * current ;
  head[1] = new node ;
  head[1] -> setnum(4); //free space
  head[1] -> setprevious(NULL);
  head[1] -> setnext(NULL);
  current = new node ;
  current -> setcourse2();
  current -> setnum(2); //home base
  head[1] -> setnext(current);
  current -> setprevious(head[1]);
  current -> setnext (NULL);
  node * temp = new node ;
  temp -> setcourse1();
  temp -> setnum(1); //obstacle
  current -> setnext(temp);
  temp -> setprevious(current);
  temp -> setnext (NULL);
}
//Building the 3rd Horizontal line function
void game::build3()
{
  //2 objects in this line:
  node * current ;
  head[2] = new node ;
  head[2]  -> setcourse3(); //player
  head[2] -> setnum(3);
  head[2] -> setprevious(NULL);
  head[2] -> setnext(NULL);
  current = new node ;
  current -> setnum(4); //free space
  head[2] -> setnext(current);
  current -> setprevious(head[2]);
  current -> setnext (NULL);
}
//Building the 4th Horizontal line function
void game::build4()
{
  //3 objects in this line:
  node * current ;
  head[3] = new node ;
  head[3] -> setcourse1();
  head[3] -> setnum(1); //obstacle
  head[3] -> setprevious(NULL);
  head[3] -> setnext(NULL);
  current = new node ;
  current -> setnum(4); //free space
  head[3] -> setnext(current);
  current -> setprevious(head[3]);
  current -> setnext (NULL);
  node * temp = new node ;
  temp -> setcourse3();
  temp -> setnum(3); //player
  current -> setnext(temp);
  temp -> setprevious(current);
  temp -> setnext (NULL);
}
//traversing position function
void game::traverse( int & move ) //it would change the move intger
{
  move = move - 1 ;
  track_mov(move); //tracking the location of the player
  int i = h ;
  int i2 = 0 ;
  if( w == 3 )//all players from the opposing team got tagged by the user
  {
    move = 6 ; //winning sign
  }
  else if(!head[move]) //if there is nothing there
  {
    move = 0 ;
    return ;
  }
  else if ( move == -1 ) //if there is nothing (wall)
  {
    move = 0 ;
  }

  else
  {
    display_pos();
    if(move == 0) //the first Vertical line
    {
      move = traverse( head[move] , move ,i,i2);
    }
    else if( move == 1 ) //the 2nd Vertical line
    {
      move = traverse( head[move] , move ,i,i2);
    }
    else if( move == 2 ) //the 3rd Vertical line
    {
      move = traverse( head[move] , move ,i,i2);
    }
    else if( move == 3 ) //the 4th Vertical line
    {
      move = traverse( head[move] , move ,i,i2);
    }
    else //wall
      move = 0 ;
  }
}
//traversing position function (recursive)
int game::traverse( node * head , int move, int i , int i2)
{
  if(!head) //base case
  {
    return 0 ;
  }
  else
  {
    if( i2 < i ) //traversing to the location Horizontally
    {
      return traverse( head -> next1() , move,  i ,++i2 );
    }
    if(!head) // base case or wall
      return 0 ;
    else
    {
      if(head -> get_n() == 1) //obstacle
      {
        head -> get_course() -> stop_player(); //upcasting
        move = 1 ;
      }
      else if (head -> get_n() == 2) //home base
      {
        head -> get_course() -> reload(n_amm); //upcasting
        move = 2 ;
      }
      else if (head -> get_n() == 3) //player
      {

        if(n_amm == 0) //if there is no ammunition
          move = 5 ;
        else
        {
          head -> get_course() -> display_tagged();
          head -> get_course() -> reduce_am(n_amm);
          head -> get_course() -> display_rshots();
          delete_player(head ,i, i2 );
          if( w == 3 )//all players from the opposing team got tagged by the user
          {
            move = 6 ; //winning sign
          }
          else
            move = 3 ;
        }
      }
      else if (head -> get_n() == 4) //free space
        move = 4 ;
    }

  }
  return move ;
}
//displaying the current position of the user function
void game::display_pos()
{
  cout << "- Vertical position = " << v << endl << "- Horizontal position = " << h << endl ;
}
//tracking the player movement function 
void game::track_mov(int & move)
{
  if( move == 0 ) //forward choice 
  {
    ++v;
    move = v ;
  }
  else if(move == 1 ) //left choice 
  {
    if(h == 0 )
    {
      move = -1 ;
    }
    else
    {
      --h;
      move = v ;
    }
  }
  else if(move == 2 ) //right choice 
  {
    ++h;
    move = v ;
  }
  else if ( move == 3 ) //back choice 
  {
    if( v == 0 )
    {
      move = -1 ;
    }
    else
    {
      --v ;
      move = v ;
    }
  }
}
//setting the position to the starting point function 
void game::set_start()
{
  v = 0 ;
  h = 0 ;
  w = 0 ;
}
//shooting function (wrapper function) 
void game::shoot()
{
  int i = h ;
  int i2 = 0 ;
  if(!head[v])
    return ;
  else 
    shoot(  head[v], i,  i2);
}
//shooting function (recursive function)
int game::shoot( node * head , int i, int i2)
{
  if( i2 < i )
  { 
    return shoot( head -> next1(), i ,++i2 );
  }
  if(n_amm == 0 )
  {
    return 0; 
  }
  else 
    head -> get_course() -> reduce_am(n_amm); 
  head -> get_course() -> display_rshots();
  return 1 ;
}
//removing the tagged player from the course and replacing it to be a free space function (recursive function)
int game::delete_player(node * head ,int i, int i2 )
{
  if(!head)
    return 0 ;
  if( i2 < i ) //finding the player
  {
    return shoot( head -> next1(), i ,++i2 );
  }
  head -> delete_c() ;
  head -> setnum(4); //replacing it to a free space
  ++w; //increasing the number of the tagged players
  return 1 ;

}
//displaying the course map function (wrapper function)
void game::display_map()
{
  int move = 0 ;
  int i = 0 ;
  int i2 = 0 ;
  while ( move < 4 )
  {
    display( head[move] , i,  i2 );
    cout << endl ;
    ++move ;
  }
}
//displaying the course map function (recursive function)
int game::display(node * head ,int i, int i2 )
{
  if(!head)
    return 0 ;
  else
  {
    if( head )
    {
      if(head -> get_n() == 4) //if there is a free space
      {
        cout << " Free Space " ;
        return display( head -> next1() , i , i2 );
      }
      else
      {
        head -> get_course() -> display() ;
        return display( head -> next1() , i , i2 );
      }
    }
  }
  return 1 ;
}
//deleting the whole course function (wrapper function)
void game::delete_course( int choice )
{
  for (int i = 0 ; i < list_size ; ++i )
  {
    if(head[i])
    {
      delete_course( head[i] ); //recursive function to delete all the nodes
      head[i] = NULL ; 
    }
    else 
    {
      delete head[i];
    }
  }
}
//deleteing the whole course function (recursive function)
int game::delete_course( node * head )
{
  if(!head)
    return 0 ;
  else
  {
    if( head -> get_n() == 4) //if there is a free space of objects
    {
      node * current = head ;
      head = head -> next1();
      delete [] current ;
      current = NULL ;
    }
    else
    {
      node * current = head ;
      head = head -> next1();

      current -> delete_c() ;
      delete [] current ;
      current = NULL ;
    }
    return delete_course(head);
  }
  return 1;
}
