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

//main function
int main()
{
  char c;
  int t = 0;
  int flag = 0 ;
  int move  = 0 ;
  int c2 = 0 ;
  char c3 ;
  int choice = 0 ;
  int flag2 = 0 ;
  int t2 = 0 ;
  game laser_tag; //calling the game class
  laser_tag.build_course(); //building the course
  cout << endl << "          W   E   L   C   O   M   E  "<< endl << "           ---[ LAZER TAG GAME ]---    " << endl ;
  while (t == 0) //this loop would not stop until the user type 4
  {
    cout<<endl<<"Please choose one of the choices from below by typing the number of the choice:"<<endl<< "(1) Play the game  "<<endl<<"(2) Display The Course`s Map" <<endl<<"(3) Delete the whole course  "<<endl<<"(4) Quit the Program "<<endl;
    cin >> c; //choice char
    cin.ignore(100, '\n');
    if (c == '1')
    {
      flag = 0 ; //setting the flag 1 to 0
      if(flag2 != 0 ) //if the flag2 != 0 means there is no course
      {
        cout << "There is no course to play in!" << endl <<"Do you want to build new course? ( Y / N ) " << endl ;
        cin >> c3 ;
        cin.ignore(100,'\n');
        if(toupper(c3) == 'N' || toupper(c3) != 'Y')
          flag2 = 1 ;
        else
        {
          laser_tag.build_course(); // for new game
          laser_tag.set_start();//setting the starting position
          flag2 = 0 ;
        }
      }
      t2 = 0 ;
      while ( flag == 0  && flag2 == 0 ) //flag1 would stop the loop, flag2 check if there is a course to play in
      {
        while((cout << endl << " Choose the number of your movement" << endl << "          (1) forward" <<endl << "(2) left               (3)right" << endl << "          (4) back" << endl)&&(!(cin >> move) || move < 1 || move > 4)) //the user should enter the right number to stop the loop
        {
          cout <<"wrong input"<<endl ;
          cin.clear();
          cin.ignore(100, '\n');
        }
        laser_tag.traverse(move); //these would traverse to the user`s position
        if(move == 0 ) //means can not move there is a wall
        {
          cout << " Wall front of you. you need to turn " << endl ;
        }
        if(move == 1)//means you can not move  because there is an obstacle
        {
          //if you want shoot the obstacle
          cout << " < Obstcale > " << endl << "(1) Shoot " << endl << "(2) Change Direction" << endl ;
          cin >> c2 ;
          cin.ignore(100, '\n');
          if( c2 == 1)
            laser_tag.shoot();
          else
            cout << "continue" << endl ;
        }
        if( move == 2 ) //the user arrived to the base home
        {
          cout << "You arrived to the home base! Your laser gun have been reloaded" <<endl ;
        }
        if( move == 3 ) // the user confronting another player
        {
          cout << " " << endl ;
        }
        if( move == 4 ) // a free space the the user can go throw
        {
          cout << "The way is free" <<endl ;
        }
        if ( move == 5 ) //if the user got shoot by another player from the opposing team
        {
          flag = 1 ;
          cout << endl <<"The game is over! You are out of shot and you are front of a player from the opposing team! " << endl ;
          laser_tag.build_course(); // for new game
          laser_tag.set_start();
        }
        if( move == 6 ) //if the user win the game after shooting all the players from the opposing team
        {
          flag = 1 ;
          cout << endl <<"The game is over! You WIN the game after you tagged all the players" << endl ;
          laser_tag.build_course(); // for new game
          laser_tag.set_start();
        }
        if(flag == 0) //this if the player want to continue playing
        {
          cout << endl << "Do want to continue playing? (Y / N)" << endl ;
          cin >> c3 ;
          cin.ignore(100,'\n');
          if(toupper(c3) == 'N' || toupper(c3) != 'Y')
            flag = 1 ;
        }
      }
    }
    if ( c == '2') //for displaying the whole map of the course
    {
      if(flag2 == 0 )
        laser_tag.display_map();
      else
        cout << "Sorry! There is no map" << endl ;
    }
    if( c == '3') //for deleteing the whole course
    {
      if(flag2 == 0)
      {
        laser_tag.delete_course( choice );
        flag2 = 1 ;
      }
    }
    if ( c == '4' ) //exit
      t = 1;

  }
  cout<<endl<<"> We Hope You Enjoy The Game .. See You Later!! <"<<endl;
  return 0;
}

