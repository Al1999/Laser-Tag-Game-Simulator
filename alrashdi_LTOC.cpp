// Alkhatab Alrashdi - CS202-001
// Program #2 - November 4th, 2019

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

//node class constructor
node :: node (): next(NULL) ,previous(NULL), n(0)
{
}
//set next node function
void node::setnext( node * next1 )
{
    if(next1 == NULL)
        next = NULL;
    else
        next = next1;
}
//next node function
node * & node :: next1()
{
  return next ;
}
//set previous node function
void node::setprevious(node * previous1)
{
    if(previous1 == NULL)
        previous = NULL;
    else
        previous = previous1 ;
}
//previous node function
node * & node :: previous1()
{
  return previous ;
}
//obstacle class constructor
obstcal::obstcal(): num_amm(0)
{
}
//home base class constructor
home_base::home_base(): num_amm(0)
{
}
//player class constructor
player::player(): num_amm(0)
{
}
//LTOC class constructor
LTOC::LTOC(): n_am1(0),n_am2(0)
{
}
//the visual class destructor
LTOC::~LTOC()
{
}
//the obstacle destructor
obstcal::~obstcal()
{
}
//the player destructor
player::~player()
{
}
//the home base class destructor
home_base::~home_base()
{}
//note the player that there is obstacle a head function
void obstcal::stop_player()
{
  cout << "Obstcale! you need to turn" << endl ;
}
//reducing the ammunition function
void obstcal::reduce_am(int & n_amm)
{
  if(!n_amm)
    return;
  else
  {
    n_am2 = n_amm - 1 ; //ammunition would be reduced by 1
    n_amm = n_am2 ;
  }
  num_amm = n_amm;
}
//reducing the ammunition function
void player::reduce_am( int & n_amm)
{
  if(!n_amm)
    return ;
  else
  {
    n_am2 = n_amm - 1 ; //ammunition would be reduced by 1
    n_amm = n_am2 ;
  }
  num_amm = n_amm ;
}
void node::setnum( int nm )
{
  n = nm ;
}
//getting the course function 
LTOC * & node :: get_course()
{
  return course ;
}
//setting the obstacle function
void node::setcourse1()
{
  course = new obstcal ; //upcasting 
}
//setting the home base function 
void node::setcourse2()
{
  course = new home_base ; //upcasting
}
//setting the player function 
void node::setcourse3()
{
  course = new player ; //upcasting
}
//home base reload ammunition function 
void home_base::reload(int & n_amm)
{
  reload2(); //calling the function of reloading from the LTOC and setting n_am2 to 5 
  n_amm = n_am1 ; 
  num_amm = n_amm ;
}
//display number of ammunition after reloading function
void home_base::display_rshots() 
{
  cout << "number of shots = " << num_amm << endl ;
}
//displaying a note that the player got tagged after shooting it function 
void player::display_tagged()
{
  cout << endl << "The player of the opposing team got tagged by you" << endl ;
}
//get the number of the object function 
int node::get_n()
{
  return n ;
}
//reloading function 
void LTOC::reload2()
{
  n_am1= 5 ;
  n_am2 = 5 ;
}
//displaying the remaining ammunition function
void player::display_rshots()
{
  cout << "The shot in your lazer gun = " << num_amm << endl ;
}
//displaying the remaining ammunition function
void obstcal::display_rshots()
{
  cout << "The shot in your lazer gun = " << num_amm << endl ;
}
//deleting the course function
void node::delete_c()
{
  delete course ;
}
//display obstacle function
void obstcal::display()
{
  cout << " Obstcal " ;
}
//display home base function
void home_base::display()
{
  cout << " Home Base " ;
}
//display player function
void player::display()
{
  cout << " Player ";
}
