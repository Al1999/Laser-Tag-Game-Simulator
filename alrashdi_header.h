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

#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>

using namespace std;

class LTOC //Laser Tag Obstacles Course Class
{
  public:
    LTOC(); // the class constructor 
    virtual ~LTOC(); // the virtual class destructor 
    virtual void stop_player() = 0; //pure virtual stop player function prototype 
    virtual void reduce_am( int & n_amm )=0; //pure virtual reduce ammunition function prototype 
    virtual void reload(int & n_amm) = 0; //pure virtual reload ammunition function prototype  
    virtual void display_tagged() = 0; //pure virtual display the tagged player function prototype 
    virtual void display_rshots() = 0 ; //pure virtual display the remaining ammunition function prototype 
    virtual void display() = 0 ; //pure virtual display the object function prototype 
    void reload2(); //Reload the ammunition in LOTC function prototype
  protected:
    int n_am1 ; //the original number of ammunition  
    int n_am2 ; //the changeable number of ammunition
};

class obstcal : public LTOC //the obstacle derived class 
{
  public:
    obstcal(); // the class constructor 
    ~obstcal(); //class destructor
    void stop_player(); //stop player function prototype 
    void display_rshots();// display the remaining ammunition function prototype 
    void reduce_am( int & n_amm); //reduce ammunition function prototype 
    void reload(int & n_amm) {}; //reload ammunition function prototype  
    void display_tagged(){}; //display the tagged player function prototype 
    void display(); //display the object function prototype 
  protected:
    int num_amm;
};

class home_base : public LTOC //Home base derived class 
{
  public:
    home_base(); // the class constructor 
    ~home_base(); //class destructor
    void reload(int & n_amm); //reload ammunition function prototype
    void display_rshots(); // display the remaining ammunition function prototype 
    void stop_player(){}; //stop player function prototype 
    void reduce_am( int & n_amm){}; //reduce ammunition function prototype 
    void display_tagged(){};  //display the tagged player function prototype 
    void display(); //display the object function prototype 
  protected:
    int num_amm ;
};

class player : public LTOC
{
  public:
    player(); // the class constructor 
    ~player(); //class destructor
    void display_tagged();//display the tagged player function prototype  
    void stop_player() {};//stop player function prototype
    void display_rshots(); // display the remaining ammunition function prototype
    void reduce_am( int & n_amm); //reduce ammunition function prototype
    void reload(int & n_amm) {};//reload ammunition function prototype
    void display(); //display the object function prototype 
  protected:
    int num_amm ;
};

class node //DLL class 
{
  public:
    node (); // the class constructor 
    void setnext( node * next1 ) ; //set next function prototype
    void setprevious( node * previous1 ) ; //set previous function prototype
    void setcourse1(); //set obtscale function prototype ( upcasting )  
    void setcourse2(); //set home base function prototype ( upcasting )
    void setcourse3(); //set player function prototype ( upcasting )
    void delete_c(); //delete course function prototype
    void setnum( int nm ); //set course object function prototype
    node * & next1(); //next node function prototype
    node * & previous1(); // previous node function prototype
    LTOC * & get_course(); // course node function prototype 
    int get_n(); // get the number of the object function prototype
  protected:
    int n ; //object number 
    LTOC * course ; //LOTC pointer
    node * next ; //next pointer
    node * previous ; //previous pointer
    
};

class game //game class 
{
  public:
    game(int size = 5 ); //the class constructor
    ~game(); //the class destructor
    void build_course(); //build new course function prototype
    void delete_course( int choice ); //delete the whole course function prototype
    void traverse( int & move  ) ; //move the player in the course function prototype
    void track_mov(int & move); //track the movement and the direction the player takes function prototype
    void shoot(); //shooting function prototype
    void display_pos(); //display the position of the player function prototype 
    void display_map(); // display the map of the course function prototype
    void set_start(); //setting the starting position function prototype
  private:
    int delete_course( node *  head ); //delete the whole course function prototype
    int shoot(node * head ,  int i, int i2 ); //shooting function prototype
    int traverse( node * head , int move, int i, int i2 );  //move the player in the course function prototype
    int delete_player(node *  head, int i, int i2  ); // deleteing the tagged player function prototype 
    int display(node * head , int i, int i2 ); // display the map of the course function prototype
    void build1(); //build the first Horizontal line of the course`s objects function prototype
    void build2(); //build the 2nd Horizontal line of the course`s objects function prototype
    void build3(); //build the 3rd Horizontal line of the course`s objects function prototype
    void build4(); //build the 4th Horizontal line of the course`s objects function prototype
    int v ; //Vertical position
    int h ; //Horizontal position
    int n_amm ; //number of ammunition 
    int list_size ; //the list of DLL size
    int w; //  
    node ** head ; //double head pointer 
};
