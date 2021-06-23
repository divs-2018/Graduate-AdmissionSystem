//header file student.hpp to declare your classes

///////////////////////////////////////////
// Name       :     Divyam Sharma
// Student Id :     301372345
// Class      :     Ensc 251, D100, LA03
// Title      :     Assignment 3
// FileName   :     student.hpp

//About:             
//This is the header file that defines all the private variables
//And has set, get and constructors

// It stores all the variables using the functions provided in the  main file             : main.cpp
// And the variables can be accessed in the                         implementation file   : student.cpp

////////////////////////////////////////////

#ifndef student_h
#define student_h
//header file student.hpp to declare classes
using namespace std; //use namespace std
#include <string> //you will have to use string in C++




//Student Constructor
class Student
{
public:
    Student();
    //Default Constructor
    
    Student(string firstName, string lastName, float CGPA, int researchScore);
    //Construtctor with arguments
    
    string get_firstName() const;
    //precondition: initialized firstname 
    //postcondition: returns the firsname from student class
    
    string get_lastName() const;
    //precondition: initialized lastName
    //postcondition: returns the lastname 
    
    float get_CGPA() const;
    //precondition: 4.3 CGPA scale. CGPA is initialized
    //postcondition: CGPA returned
    
    int get_researchScore() const;
    //precondition: Initialized Research Score 
    //postcondition: returned researchScore
    
    void set_firstName(string temp_firstName);
    //precondition: setFirstName 
    //postcondition: The firstname has been setup
    
    void set_lastName(string temp_lastName);
    //precondition: set Last Name 
    //postcondition: Update the Last Name
    
    void set_CGPA(float temp_CGPA);
    //precondition: set CGPA
    //postcondition: Update the CGPA
    
    void set_researchScore(int temp_researchScore);
    //precondition: Set researchScore
    //postcondition: Update the research Score

    /* friend int compareCGPA(Student student1, Student student2);
    //PreCondition: Two int CGPA inputs from two objects
    //PostCondition: Returns the lower higher or equal too
    friend int compareResearchScore(Student student1, Student student2);
    //PreCondition: Two int CGPA inputs from two objects
    //PostCondition:Returns the lower higher or equal too
    friend int compareFirstName(Student student1, Student student2);
    //PreCondition: Two string first name
    //PostCondition:Returns the lower higher or equal too
    friend int compareLastName(Student student1, Student student2);
    //PreCondition:Two String last names  
    //PostCondition:Returns the lower higher or equal too
    */


    friend ostream& operator << (ostream& outs,  const Student &object);

    virtual void out() = 0;
    
private:
    string firstName;
    string lastName;
    float CGPA;
    int researchScore;
};


class ToeflScore
{
public:
    ToeflScore();
    //Default Constructor
    
    ToeflScore(int reading, int listening, int speaking, int writing);
    //ToeflScore constructor with  arguements.
    
    int get_readingScore() const;
    //precondition: reading has been initialized to an integer
    //postcondition: the value in reading is returned.
    
    int get_listeningScore() const;
    //precondition: listening has been initialized to an integer
    //postcondition: the value in listening is returned.
    
    int get_speakingScore() const;
    //precondition: speaking has been initialized to an integer
    //postcondition: the value in speaking is rreturned.
    
    int get_writingScore() const;
    //precondition: writing has been initialized to an integer
    //postcondition: the value in writing is returned.
    
    int get_totalScore() const;
    //precondition: the total TOEFL score has been set
    //postcondition: the value in totalScore is returned.
    
    void set_readingScore(int temp_reading);
    //precondition: readScore is an integer
    //postcondition: the value in reading has been set to readScore
    
    void set_listeningScore(int temp_listening);
    //precondition: listenScore is an integer 
    //postcondition: the value in listening has been set to listenScore
    
    void set_speakingScore(int temp_speaking);
    //precondition: speakScore is an integer 
    //postcondition: the value in speaking has been set to speakScore
    
    void set_writingScore(int temp_writing);
    //precondition: writeScore is an integer 
    //postcondition: the value in writing has been set to writeScore
    
    void set_totalScore();
    //precondition: reading, listening, speaking and writing have been initialized.
    //postcondition: the value in totalScore has been set to sum of reading, listening, speaking and writing.

    
    
private:
    int reading;
    int listening;
    int speaking;
    int writing;
    int totalScore;
};

class DomesticStudent : public Student
{
public:
    DomesticStudent();
    //DomesticStudent default constructor.
    
    DomesticStudent(string firstName, string lastName, float CGPA, int researchScore, string new_province);
    //DomesticStudent constructor with arguements.
    
    string get_province() const;
    //precondition: province has been initialized.
    //postcondition: the string in province is returned.
    
    void set_province(string temp_province);
    //precondition: new_province is of type string of two characters.
    //postcondition: province has been updated to new_province.

    friend ostream& operator << (ostream& outs,  const DomesticStudent &object);
    //PreCondition: Outputting the overloaded operators and the definition of an object after << statement
    //PostCondition: outputting multiple variables

    friend int compareProvince(DomesticStudent student1, DomesticStudent student2);
    //PreCondition: Two input provinces that compares two strings
    //PostCondition: Outputs the lower ones
    
    void out();
private:
    string province;

};



class InternationalStudent : public Student
{
public:
    InternationalStudent();
    //InternationalStudent default constructor.
    
    InternationalStudent(string firstName, string lastName, float CGPA, int researchScore, string country, int reading, int listening, int speaking, int writing);
    //InternationalStudent constructor with arguements.
    
    virtual string get_country() const;
    //precondition: country has already been initialized.
    //postcondition: the value in country is returned.
    
    void set_country(string temp_country);
    //precondition: ctry is of type string with no whitespace.
    //postcondition: the string in country is updated to ctry.
    
    void set_listening(int temp_listening);
    //precondition: listenScr is an integer
    //postcondition: the value in listening of object toeflScore has been set to listenScr

    void set_reading(int temp_reading);
    //precondition: readScr is an integer 
    //postcondition: the value in reading of object toeflScore has been set to readScr

    void set_speaking(int temp_speaking);
    //precondition: speakScr is an integer 
    //postcondition: the value in speaking of object toeflScore has been set to speakScr

    void set_writing(int temp_writing);
    //precondition: writeScr is an integer 
    //postcondition: the value in writing of object toeflScore has been set to writeScr

    //Set all the 4 types of scores
    int get_listening();
    int get_reading();
    int get_speaking();
    int get_writing();

    void out();

    int get_totalScore() const;
    //precondition: he total TOEFL score has been set
    //postcondition: the value in totalScore of toeflScore is returned

    void set_totalScore();
    //precondition: reading, listening, speaking and writing of the toeflScore obect has been initialized.
    //postcondition: the value in totalScore of object toeflScore has been set to sum of reading, listening, speaking and writing.

    friend ostream& operator << (ostream& outs,  const InternationalStudent &object);
    //PreCondition: Overloading operator function
    //PostCondition: It will output statements based on the definition

    friend int compareCountry(InternationalStudent student1, InternationalStudent student2);
    //PreCondition: Two countries from the objects
    //PostCondition: It will compare two countries

    
private:
    string country;
    ToeflScore toeflScore;

    

};

//Lab la03
//Domestic Node Manipulation and all the functions
class domesticnode
{
    public:
  //Constructor
    domesticnode();
    domesticnode(DomesticStudent temp_data, domesticnode* next);

    DomesticStudent getData() const;
    domesticnode *getlink() const;

    void setData(DomesticStudent temp_data);
    void setLink(domesticnode* next);

    private:
    DomesticStudent data;
    domesticnode* link;

    
};
//Defining a pointer type for the program
typedef domesticnode* Nodeptr;

//International Node
class internationalnode
{
    public:
  //Constructor
    internationalnode();
    internationalnode(InternationalStudent temp_data, internationalnode* next);
  //Get and set functions
    InternationalStudent getData() const;
    internationalnode *getlink() const;

    void setData(InternationalStudent temp_data);
    void setLink(internationalnode* next);

    private:
    InternationalStudent data;
    internationalnode* link;

    
};
typedef internationalnode* Nodeptr_int;

//Merged Nodes
class mergenode
{
    public:
    Student *data;
    mergenode* link;
  //Constructor
    mergenode();
    mergenode(Student *temp_data, mergenode* next);
};
typedef mergenode* Node;


	//All the functions for domesctic linked list
void actions_dom(Nodeptr& head, int stu_count);
void head_insert_dom(Nodeptr& head, DomesticStudent temp_data, int temp_count);
void display_nodes_dom(Nodeptr& head);
void bubble_sort_dom(Nodeptr& head, int temp_count);
void swap(Nodeptr& a, Nodeptr& b);
void search_domestic_gpa(Nodeptr& head);
void search_domestic_name(Nodeptr& head);
void insert_node_dom(Nodeptr& head, int temp_count);
void delete_node_dom(Nodeptr& head, int temp_count);

//All the functions for international linked list
void actions_int(Nodeptr_int& head, int stu_count);
void head_insert_int(Nodeptr_int& head, InternationalStudent temp_data, int temp_count);
void display_nodes_int(Nodeptr_int& head);
void bubble_sort_int(Nodeptr_int& head, int temp_count);
void swap_int(Nodeptr_int& a, Nodeptr_int& b);
void search_int_gpa(Nodeptr_int& head);
void search_int_name(Nodeptr_int& head);
void insert_node_int(Nodeptr_int& head, int temp_count);
void delete_node_int(Nodeptr_int& head, int temp_count);

//The function for co jointed linked list
void head_insert(Nodeptr& head1,Nodeptr_int& head2, Node& head);
void delete_dom(Nodeptr& head1);
void delete_int(Nodeptr_int& head2);
void push_dom(Nodeptr& head1, Node& head);
void push_int(Nodeptr_int& head2, Node& head);



#endif /* student_h */
