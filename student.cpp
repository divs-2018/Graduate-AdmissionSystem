//student.cpp to implement your classes

///////////////////////////////////////////
// Name       :     Divyam Sharma
// Student Id :     301372345
// Class      :     Ensc 251, D100, LA03
// Title      :     Assignment 3
// FileName   :     Student.cpp

//About:             
//This is the Student file that implements all your classes and defines all the get, set, and constructor functions
//This program has all the public functions in the header file defined to access all the private variables
//Contructors have default constructors that set everything to be empty and contructors that use the set function to define the private variables
//The get functions are used to display all the variables and access all of them

// It stores all the variables using the functions provided in the  main file             : main.cpp
// And the variables are define in the                              header file           : student.hpp

////////////////////////////////////////////

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <fstream> //file processing
#include <sstream>
//student.cpp to implement your classes
#include "student.hpp"
#include <string>

#include <cstring>
#include <cctype>
#include <cstdlib>

using namespace std;


//Student member function definitions.
//Constructor
Student::Student() : firstName("Empty First Name"), lastName("Empty Last Name"), CGPA(0.0), researchScore(0) {  }
Student::Student(string temp_firstName, string temp_lastName, float temp_CGPA, int temp_researchScore) {
    set_firstName(temp_firstName);
    set_lastName(temp_lastName);
    set_CGPA(temp_CGPA);
    set_researchScore(temp_researchScore);
}
//Get Functions
string Student::get_firstName() const {return firstName;}
string Student::get_lastName() const {return lastName;}
float Student::get_CGPA() const {return CGPA;}
int Student::get_researchScore() const {return researchScore;}

//Set Functions
void Student::set_firstName(string temp_firstname)
{
    firstName = temp_firstname;
}
void Student::set_lastName(string temp_lastname)
{
    lastName = temp_lastname;
}
void Student::set_CGPA(float temp_CGPA)
{
    CGPA = temp_CGPA;
}
void Student::set_researchScore(int temp_researchScore)
{
    researchScore = temp_researchScore;
}


//class ToeflScore function definitions
//constructors
ToeflScore::ToeflScore() : reading(0), listening(0), speaking(0), writing(0), totalScore(0)  {   }
ToeflScore::ToeflScore(int temp_reading, int temp_listening, int temp_speaking, int temp_writing)  
{  
    set_readingScore(temp_reading);
    set_listeningScore(temp_listening);
    set_speakingScore(temp_speaking);
    set_writingScore(temp_writing);
    set_totalScore();
}
//Get toefl Scores
int ToeflScore::get_readingScore() const {return reading;}
int ToeflScore::get_listeningScore() const {return listening;}
int ToeflScore::get_speakingScore() const {return speaking;}
int ToeflScore::get_writingScore() const {return writing;}
int ToeflScore::get_totalScore() const {return totalScore;}
//Set Toefl Scores
void ToeflScore::set_readingScore(int temp_reading)
{
    reading = temp_reading;
}
void ToeflScore::set_listeningScore(int temp_listening)
{
    listening = temp_listening;
}
void ToeflScore::set_speakingScore(int temp_speaking)
{
    speaking = temp_speaking;
}
void ToeflScore::set_writingScore(int temp_writing)
{
    writing = temp_writing;
}
void ToeflScore::set_totalScore()
{
    totalScore = reading + listening + speaking + writing;
}

//DomesticStudent function definition.
//Constructors
DomesticStudent::DomesticStudent() : Student(), province("Empty Province") {   }
DomesticStudent::DomesticStudent(string temp_firstName, string temp_lastName, float temp_CGPA, int temp_researchScore, string temp_province) 
{   
    set_firstName(temp_firstName);
    set_lastName(temp_lastName);
    set_CGPA(temp_CGPA);
    set_researchScore(temp_researchScore);
    set_province(temp_province);
}

//get functions
string DomesticStudent::get_province() const {return province;}
//Set functions
void DomesticStudent::set_province(string temp_province)
{
    province = temp_province;
}
void DomesticStudent::out() 
{
    cout << left <<setw(20) << "Dom student : " << setw(20) << this->get_firstName() << setw(20)
        << this->get_lastName() << setw(20) << this->province << " cgpa "<< setw(10)
        << this->get_CGPA() << "research score " << setw(10) << this->get_researchScore() << endl;
}


//InternationalStudent functon definitions.
//Constructors
InternationalStudent::InternationalStudent() : Student(), country("No Country") {   }
InternationalStudent::InternationalStudent(string temp_firstName, string temp_lastName, float temp_CGPA, int temp_researchScore, string temp_country, int temp_reading, int temp_listening, int temp_speaking, int temp_writing) : toeflScore(temp_reading,temp_listening,temp_speaking,temp_writing)
{ 
    set_firstName(temp_firstName);
    set_lastName(temp_lastName);
    set_CGPA(temp_CGPA);
    set_researchScore(temp_researchScore);
    set_country(temp_country);
    
}
//Get Functions
string InternationalStudent::get_country() const {return country;}
void InternationalStudent::set_country(string temp_country)
{
    country = temp_country;
}

//Set Scores
void InternationalStudent::set_reading(int temp_reading)
{
    toeflScore.set_readingScore(temp_reading);
}
void InternationalStudent::set_listening(int temp_listening)
{
    toeflScore.set_listeningScore(temp_listening);
}
void InternationalStudent::set_speaking(int temp_speaking)
{
    toeflScore.set_speakingScore(temp_speaking);
}
void InternationalStudent::set_writing(int temp_writing)
{
    toeflScore.set_writingScore(temp_writing);
}
int InternationalStudent::get_totalScore() const 
{
    return toeflScore.get_totalScore();
}
void InternationalStudent::set_totalScore()
{
    toeflScore.set_totalScore();
}

//Get Scores
int InternationalStudent::get_listening()
{
    return toeflScore.get_listeningScore();
}
int InternationalStudent::get_reading()
{
    return toeflScore.get_readingScore();
}
int InternationalStudent::get_speaking()
{
    return toeflScore.get_speakingScore();
}
int InternationalStudent::get_writing()
{
    return toeflScore.get_writingScore();
}

void InternationalStudent::out()
{
    cout << left <<setw(20)<< "Int student : " << setw(20) << left << this->get_firstName() << setw(20) 
        << this->get_lastName() << setw(20) << this->country << " cgpa " << setw(10)
          << this->get_CGPA() << "research score " << setw(10) << this->get_researchScore() << setw(10) <<" Toefl Score of " << this->get_totalScore() << endl;
}

///// LAB 2


//This function compares the CGPA 1 with CGPA 2 int based
/* int compareCGPA(Student student1, Student student2)
{
    if (student1.CGPA < student2.CGPA){return 0;}
    else if (student1.CGPA == student2.CGPA){return 1;}
    else {return 2;}
}
//This function compares the Researchscore 1 to research score 2 int based
int compareResearchScore(Student student1, Student student2)
{
    if (student1.researchScore < student2.researchScore){return 0;}
    else if (student1.researchScore == student2.researchScore){return 1;}
    else {return 2;}
}
//Compares first names String based
int compareFirstName(Student student1, Student student2)
{
    //Making sure lower case are sorted correctly
    if(islower(student1.firstName[0])) {student1.firstName[0] = toupper(student1.firstName[0]);}
    if(islower(student2.firstName[0])) {student2.firstName[0] = toupper(student2.firstName[0]);}
    //making sure upper case are sorted correctly
    if(isupper(student1.firstName[1])) {student1.firstName[1] = tolower(student1.firstName[1]);}
    if(isupper(student2.firstName[1])) {student2.firstName[1] = tolower(student2.firstName[1]);}

    //Compare function in built
    int i = student1.firstName.compare(student2.firstName);
    if (i > 0) {return 0;}
    else if (i == 0) {return 1;}
    else {return 2;}

}
//Compares the last names string based
int compareLastName(Student student1, Student student2)
{
    int i = student1.lastName.compare(student2.lastName);
    if (i > 0) {return 0;}
    else if (i == 0) {return 1;}
    else {return 2;}
}
//Compares provinces string based
int compareProvince(DomesticStudent student1, DomesticStudent student2)
{
    int i = student1.province.compare(student2.province);
    if (i > 0) {return 0;}
    else if (i == 0) {return 1;}
    else {return 2;}
}
//Compares the country string based
int compareCountry(InternationalStudent student1, InternationalStudent student2)
{

    int i = student1.country.compare(student2.country);
    
    if (i > 0) {return 0;}
    else if (i == 0) {return 1;}
    else {return 2;}
}*/


//overloading the output operator if the syntax has an international or national student
ostream& operator << (ostream& outs,  const InternationalStudent &object)
{
   cout << left <<setw(20)<< "Int student : " << setw(20) << left << object.get_firstName() << setw(20) 
        << object.get_lastName() << setw(20) << object.country << " cgpa " << setw(10)
        << object.get_CGPA() << "research score " << setw(10) << object.get_researchScore() << setw(10) <<" Toefl Score of " << object.get_totalScore() << endl;
    return outs;
}

ostream& operator << (ostream& outs,  const DomesticStudent &object)
{
    cout << left <<setw(20) << "Dom student : " << setw(20) << object.get_firstName() << setw(20)
        << object.get_lastName() << setw(20) << object.province << " cgpa "<< setw(10)
        << object.get_CGPA() << "research score " << setw(10) << object.get_researchScore() << endl;
    return outs;
}





//Lab 3
//Domestic Linked List
domesticnode::domesticnode() : data(), link(NULL)
{
    //Deliberately Empty
}
domesticnode::domesticnode(DomesticStudent temp_data, domesticnode* next)
{
    data = temp_data;
    link = next;
}

DomesticStudent domesticnode::getData() const
{
    return data;
}
domesticnode* domesticnode::getlink() const
{
    return link;
}

void domesticnode::setData(DomesticStudent temp_data)
{
    data = temp_data;
}
void domesticnode::setLink(domesticnode* next)
{
    link = next;
}

//International Linked list
internationalnode::internationalnode() : data(), link(NULL)
{
    //Deliberately Empty
}
internationalnode::internationalnode(InternationalStudent temp_data, internationalnode* next)
{
    data = temp_data;
    link = next;
}
//Get and Set Functions
InternationalStudent internationalnode::getData() const
{
    return data;
}
internationalnode* internationalnode::getlink() const
{
    return link;
}

void internationalnode::setData(InternationalStudent temp_data)
{
    data = temp_data;
}
void internationalnode::setLink(internationalnode* next)
{
    link = next;
}

//Merged node Linked lise
//Default Constructor

mergenode::mergenode() : data(), link(NULL)
{

}
//Two types of objects
mergenode::mergenode(Student *temp_data, mergenode* next)
{
    data = temp_data;
    link = next;
}




// Functions


//Insert nodes in domestic list
void head_insert_dom(Nodeptr& head, DomesticStudent temp_data, int temp_count)
{
    if (head == NULL) {return;}
    Nodeptr temp_ptr;
    if (temp_count == 0)
    {
        head->setData(temp_data);
        head->setLink(NULL);   
    }
    else
    {
        temp_ptr = new domesticnode(temp_data, head);
        head = temp_ptr;
    }
    //Making sure to bubble sort
    bubble_sort_dom(head, temp_count);

}
void display_nodes_dom(Nodeptr& head)
{
  // Displaying nodes in a format
    Nodeptr temp_ptr;
    temp_ptr = head;
    int temp = 1;
    while(temp_ptr != NULL)
    {
        cout << left << setw(5) << temp << temp_ptr->getData();
        temp_ptr = temp_ptr->getlink();
        temp++;
    }
}
//Sorting everytime a node is inserted
void bubble_sort_dom(Nodeptr& head, int temp_count)
{
    if (temp_count < 2){return;}
    if (head == NULL) {return;}

    Nodeptr i, j;
    //Bubble Sort
    for(i = head; i->getlink() != NULL; i=i->getlink())
    {
        for(j = i->getlink(); j != NULL; j = j->getlink())
        {
            if(i->getData().get_CGPA() > j->getData().get_CGPA())
            {
                swap(i, j);
            }
            else if(i->getData().get_CGPA() == j->getData().get_CGPA())
            {
                if(i->getData().get_researchScore() > j->getData().get_researchScore())
                {
                    swap(i, j);
                }
                else if(i->getData().get_researchScore() == j->getData().get_researchScore())
                {
                    if(i->getData().get_province().compare(j->getData().get_province()) < 0)
                    {
                        swap(i, j);
                    }
                }
            }
        }
    }
}
//Swapping two nodes
void swap(Nodeptr& a, Nodeptr& b)
{
    DomesticStudent data;
    data = a->getData();
    a->setData(b->getData());
    b->setData(data);
}
//User manipulation input
void actions_dom(Nodeptr& head, int stu_count)
{
    int action = 0;
    cout    << endl <<"How do you want to proceed? " << endl
                << "1. Search the displayed nodes (CGPA and ResearchScore)? (Type 1 and press enter)" << endl
                << "2. Search the displayed nodes (FirstName and LastName)? (Type 2 and press enter)" << endl
                << "3. Add Students to the List (Type 3 and press enter)" << endl
                << "4. Delete Students from the List (Type 4 and press enter)" << endl << endl;
        cin >> action;

        int numofstu = 0;
        if(action == 1) {
            search_domestic_gpa(head);
        }
        else if(action == 2) {
            search_domestic_name(head);
        }
        else if(action == 3) {
            cout << "How many student do you want to add?" << endl;
            cin >> numofstu;

            for (int i = 0; i < numofstu; i++)
            {
                cout << endl <<"Student " << i << endl;
                insert_node_dom(head, stu_count);
                //display_nodes_dom(head);
                
            }
        }
        else if(action == 4) {
            delete_node_dom(head, stu_count);
            
        }
        else {cout << "Number entered is entered incorrectly please rerun the program and try again" << endl;}
    
    string cont;
    cout << "Do you wish to continue? " << endl
         << "If yes (press Y and enter) " << endl
         << "If no (press N and enter)" << endl;
    cin >> cont;

    if (cont == "Y" or cont == "y")
    {
        actions_dom(head, stu_count);
    }
    else if (cont == "N" or cont == "n")
    {
        
    }
    else
    {
        cout << "Wrong input rerun the program" << endl;
    }
}

//Searching for gpa and research score
void search_domestic_gpa(Nodeptr& head)
{
    float gpa;
    int researchScore;
    cout << "Enter the GPA and press Enter: " << endl;
    cin >> gpa;
    cout << "Enter the ResearchScore and press Enter: " << endl;
    cin >> researchScore;

    Nodeptr temp_ptr;
    temp_ptr = head;
    int found = 0;
    while(temp_ptr != NULL)
    {
        if(temp_ptr->getData().get_CGPA() == gpa && temp_ptr->getData().get_researchScore() == researchScore)
        {
            cout << temp_ptr->getData();
            found = 1;
        }
        temp_ptr = temp_ptr->getlink();
    }
    if (found == 0){cout << "No nodes match the input" << endl
                         << "Rerun the program to input new nodes" << endl;}
}

void search_domestic_name(Nodeptr& head)
{
    string firstname, lastname;
    cout << "Enter the first name and press Enter: " << endl;
    cin >> firstname;
    cout << "Enter the last name and press Enter: " << endl;
    cin >> lastname;

    if(islower(firstname[0])) {firstname[0] = toupper(firstname[0]);}
    if(islower(lastname[0]))  {lastname[0] = toupper(lastname[0]);}
    //making sure upper case are sorted correctly
    if(isupper(firstname[1])) {firstname[1] = tolower(lastname[1]);}
    if(isupper(lastname[1])) {lastname[1] = tolower(lastname[1]);}

    Nodeptr temp_ptr;
    temp_ptr = head;
    int found = 0;
    while(temp_ptr != NULL)
    {
        if(temp_ptr->getData().get_firstName() == firstname && temp_ptr->getData().get_lastName() == lastname)
        {
            cout << temp_ptr->getData();
            found = 1;
        }
        temp_ptr = temp_ptr->getlink();
    }
    if (found == 0){cout << "No nodes match the input" << endl
                         << "Rerun the program to input new nodes" << endl;
                        }
}


void insert_node_dom(Nodeptr& head, int temp_count)
{
    string firstname, lastname, province;
    float gpa;
    int researchScore;

    cout << "Enter the first name and press Enter: " << endl;
    cin >> firstname;
    cout << "Enter the last name and press Enter: " << endl;
    cin >> lastname;
    cout << "Enter the GPA and press Enter: " << endl;
    cin >> gpa;
    if (gpa < 0 || gpa > 4.33)
    {
        cout << "The gpa is entered incorrectly" << endl;
        exit(3);
    }
    cout << "Enter the ResearchScore and press Enter: " << endl;
    cin >> researchScore;
    if (researchScore < 0 || researchScore > 100)
    {
        cout << "The researchScore is entered incorrectly" << endl;
        exit(4);
    }
    cout << "Enter the province(Abbreviated and capital 2 Letters) and press Enter: " << endl;
    cin >> province;
    if (province != "NL" && province != "PE" &&province != "NS" && province != "NB" &&
        province != "QC" && province != "ON" && province != "MB" && province != "SK" &&
        province != "AB" && province != "BC" && province != "YT" && province != "NT" && province != "NU")
    {
        cout << "The province is incorrect. Rerun the program " <<endl;
        exit(2);    
    }

    DomesticStudent temp_data(firstname, lastname, gpa, researchScore, province);

    head_insert_dom(head, temp_data, temp_count);
    display_nodes_dom(head);

}
//Deleting the node
void delete_node_dom(Nodeptr& head, int temp_count)
{
    string firstname, lastname;
    cout << "Enter the first name and press Enter: " << endl;
    cin >> firstname;
    cout << "Enter the last name and press Enter: " << endl;
    cin >> lastname;

    if(islower(firstname[0])) {firstname[0] = toupper(firstname[0]);}
    if(islower(lastname[0]))  {lastname[0] = toupper(lastname[0]);}
    //making sure upper case are sorted correctly
    if(isupper(firstname[1])) {firstname[1] = tolower(lastname[1]);}
    if(isupper(lastname[1])) {lastname[1] = tolower(lastname[1]);}

    Nodeptr temp_ptr = head;
    Nodeptr before = head;
    int found = 0;
    while(temp_ptr != NULL)
    {
        
        if(temp_ptr->getData().get_firstName() == firstname && temp_ptr->getData().get_lastName() == lastname)
        {
            cout << "The node/s to be deleted are " << endl <<temp_ptr->getData() ;
            Nodeptr discard = temp_ptr;            
            if (discard->getlink() == NULL)
            {
                before->setLink(NULL);
            }
            else if (discard == before)
            {
                head = head->getlink();
                temp_ptr = temp_ptr->getlink();
		before = before->getlink();
		delete discard;
		continue;
            }
            else
            {
                before->setLink(discard->getlink());
                
            }
            temp_ptr = temp_ptr->getlink();
            delete discard;

            cout << "The value is deleted " << endl;
            found = 1;
        }
        else
        {
            before = temp_ptr;
            temp_ptr = temp_ptr->getlink();
        }
        
        
    }
    if (found == 0){cout << "No nodes match the input" << endl
                         << "Rerun the program to input new nodes" << endl;
                        }
    display_nodes_dom(head);

}



void head_insert_int(Nodeptr_int& head, InternationalStudent temp_data, int temp_count)
{
    if (head == NULL) {return;}
    Nodeptr_int temp_ptr;
    if (temp_count == 0)
    {
        head->setData(temp_data);
        head->setLink(NULL);
    }
    else
    {
        temp_ptr = new internationalnode(temp_data, head);
        head = temp_ptr;
    }
    bubble_sort_int(head, temp_count);
}
void bubble_sort_int(Nodeptr_int& head, int temp_count)
{
    if (temp_count < 2){return;}
    if (head == NULL) {return;}

    Nodeptr_int i, j;
    for(i = head; i->getlink() != NULL; i=i->getlink())
    {
        for(j = i->getlink(); j != NULL; j = j->getlink())
        {
            if(i->getData().get_CGPA() > j->getData().get_CGPA())
            {
                swap_int(i, j);
            }
            else if(i->getData().get_CGPA() == j->getData().get_CGPA())
            {
                if(i->getData().get_researchScore() > j->getData().get_researchScore())
                {
                    swap_int(i, j);
                }
                else if(i->getData().get_researchScore() == j->getData().get_researchScore())
                {
                    if(i->getData().get_country().compare(j->getData().get_country()) < 0)
                    {
                        swap_int(i, j);
                    }
                }
            }
        }
    }
}
void display_nodes_int(Nodeptr_int& head)
{
    Nodeptr_int temp_ptr;
    temp_ptr = head;
    int temp = 1;
    while(temp_ptr != NULL)
    {
        if(temp_ptr->getData().get_reading() < 20 ||
            temp_ptr->getData().get_listening() < 20 ||
            temp_ptr->getData().get_speaking() < 20 ||
            temp_ptr->getData().get_writing() < 20 || 
            temp_ptr->getData().get_totalScore() <93){
                temp_ptr = temp_ptr->getlink();
                continue;}
        else
        {
            cout << left << setw(5) << temp << temp_ptr->getData();
            temp_ptr = temp_ptr->getlink();
            temp++;
        }

    }
}
void swap_int(Nodeptr_int& a, Nodeptr_int& b)
{
    InternationalStudent data;
    data = a->getData();
    a->setData(b->getData());
    b->setData(data);
}
void actions_int(Nodeptr_int& head, int stu_count)
{
    int action = 0;
    cout    << endl <<"How do you want to proceed? " << endl
                << "1. Search the displayed nodes (CGPA and ResearchScore)? (Type 1 and press enter)" << endl
                << "2. Search the displayed nodes (FirstName and LastName)? (Type 2 and press enter)" << endl
                << "3. Add Students to the List (Type 3 and press enter)" << endl
                << "4. Delete Students from the List (Type 4 and press enter)" << endl << endl;
        cin >> action;

        int numofstu = 0;
        if(action == 1) {
            search_int_gpa(head);
        }
        else if(action == 2) {
            search_int_name(head);
        }
        else if(action == 3) {
            cout << "How many student do you want to add?" << endl;
            cin >> numofstu;

            for (int i = 0; i < numofstu; i++)
            {
                cout << endl <<"Student " << i << endl;
                insert_node_int(head, stu_count);
                display_nodes_int(head);
                
            }
        }
        else if(action == 4) {  
           delete_node_int(head, stu_count);
           
        }
        else {cout << "Number entered is entered incorrectly please rerun the program and try again" << endl;}
    
    string cont;
    cout << "Do you wish to continue? " << endl
         << "If yes (press Y and enter) " << endl
         << "If no (press N and enter)" << endl;
    cin >> cont;

    if (cont == "Y" or cont == "y")
    {
        actions_int(head, stu_count);
    }
    else if (cont == "N" or cont == "n")
    {
        
    }
    else
    {
        cout << "Wrong input rerun the program" << endl;
    }
}

void search_int_gpa(Nodeptr_int& head)
{
    float gpa;
    int researchScore;
    cout << "Enter the GPA and press Enter: " << endl;
    cin >> gpa;
    cout << "Enter the ResearchScore and press Enter: " << endl;
    cin >> researchScore;

    Nodeptr_int temp_ptr;
    temp_ptr = head;
    int found = 0;
    while(temp_ptr != NULL)
    {
        if(temp_ptr->getData().get_CGPA() == gpa && temp_ptr->getData().get_researchScore() == researchScore)
        {
            cout << temp_ptr->getData();
            found = 1;
        }
        temp_ptr = temp_ptr->getlink();
    }
    if (found == 0){cout << "No nodes match the input" << endl
                         << "Rerun the program to input new nodes" << endl;}
}
void search_int_name(Nodeptr_int& head)
{
    string firstname, lastname;
    cout << "Enter the first name and press Enter: " << endl;
    cin >> firstname;
    cout << "Enter the last name and press Enter: " << endl;
    cin >> lastname;

    if(islower(firstname[0])) {firstname[0] = toupper(firstname[0]);}
    if(islower(lastname[0]))  {lastname[0] = toupper(lastname[0]);}
    //making sure upper case are sorted correctly
    if(isupper(firstname[1])) {firstname[1] = tolower(lastname[1]);}
    if(isupper(lastname[1])) {lastname[1] = tolower(lastname[1]);}

    Nodeptr_int temp_ptr;
    temp_ptr = head;
    int found = 0;
    while(temp_ptr != NULL)
    {
        if(temp_ptr->getData().get_firstName() == firstname && temp_ptr->getData().get_lastName() == lastname)
        {
            cout << temp_ptr->getData();
            found = 1;
        }
        temp_ptr = temp_ptr->getlink();
    }
    if (found == 0){cout << "No nodes match the input" << endl
                         << "Rerun the program to input new nodes" << endl;
                        }
}
void insert_node_int(Nodeptr_int& head, int temp_count)
{
    string firstname, lastname, country;
    float gpa;
    int researchScore, reading , listening, speaking, writing = 0;

    cout << "Enter the first name and press Enter: " << endl;
    cin >> firstname;
    cout << "Enter the last name and press Enter: " << endl;
    cin >> lastname;
    cout << "Enter the GPA and press Enter: " << endl;
    cin >> gpa;
    if (gpa < 0 || gpa > 4.33)
    {
        cout << "The Gpa is entered incorrectly" << endl;
        exit(3);
    }
    cout << "Enter the ResearchScore and press Enter: " << endl;
    cin >> researchScore;
    if (researchScore < 0 || researchScore > 100)
    {
        cout << "The researchScore is entered incorrectly" << endl;
        exit(4);
    }
    cout << "Enter the Country and press Enter: " << endl;
    cin >> country;
    cout << "Enter reading toefl Score : " << endl;
    cin >> reading;
    if (reading < 0 || reading > 30)
    {
        cout << "The readingscore is entered incorrectly" << endl;
        exit(4);
    }
    cout << "Enter listening toefl Score : " << endl;
    cin >> listening;
    if (listening < 0 || listening > 30)
    {
        cout << "The listeningscore is entered incorrectly" << endl;
        exit(4);
    }
    cout << "Enter speaking toefl Score : " << endl;
    cin >> speaking;
    if (speaking < 0 || speaking > 30)
    {
        cout << "The speakingscore is entered incorrectly" << endl;
        exit(4);
    }
    cout << "Enter writing toefl Score : " << endl;
    cin >> writing;
    if (writing < 0 || writing > 30)
    {
        cout << "The writingscore is entered incorrectly" << endl;
        exit(4);
    }


    InternationalStudent temp_data(firstname, lastname, gpa, researchScore, country, reading, listening, speaking, writing);

    head_insert_int(head, temp_data, temp_count);
}
void delete_node_int(Nodeptr_int& head, int temp_count)
{
    string firstname, lastname;
    cout << "Enter the first name and press Enter: " << endl;
    cin >> firstname;
    cout << "Enter the last name and press Enter: " << endl;
    cin >> lastname;

    if(islower(firstname[0])) {firstname[0] = toupper(firstname[0]);}
    if(islower(lastname[0]))  {lastname[0] = toupper(lastname[0]);}
    //making sure upper case are sorted correctly
    if(isupper(firstname[1])) {firstname[1] = tolower(lastname[1]);}
    if(isupper(lastname[1])) {lastname[1] = tolower(lastname[1]);}

    Nodeptr_int temp_ptr = head;
    Nodeptr_int before = head;
    int found = 0;
    while(temp_ptr != NULL)
    {
        if(temp_ptr->getData().get_firstName() == firstname && temp_ptr->getData().get_lastName() == lastname)
        {
            cout << "The node/s to be deleted are " << endl <<temp_ptr->getData() ;
            Nodeptr_int discard = temp_ptr;
            if (discard->getlink() == NULL)
            {
                before->setLink(NULL);
            }
            else if (discard == before)
            {
                head = head->getlink();
                temp_ptr = temp_ptr->getlink();
		before = before->getlink();
		delete discard;
		continue;
            }
            else
            {
                before->setLink(discard->getlink());
            }
            temp_ptr = temp_ptr->getlink();
            delete discard;
            

            cout << "The value is deleted " << endl;
            found = 1;
        }
        else
        {   
            before = temp_ptr;
            temp_ptr = temp_ptr->getlink();
        }
        
        
    }
    if (found == 0){cout << "No nodes match the input" << endl
                         << "Rerun the program to input new nodes" << endl;
                        }
    display_nodes_int(head);
}


void head_insert(Nodeptr& head1,Nodeptr_int& head2, Node& head)
{
    int temp1 =0;
    while (head1->getlink() != NULL || head2->getlink() != NULL)
    {
        if(head1->getlink() != NULL && head2->getlink() == NULL)
        {
            push_dom(head1, head);
            delete_dom(head1);
        }
        else if(head2->getlink() != NULL && head1->getlink() == NULL)
        {
            
            push_int(head2, head);
            delete_int(head2);
        }
        else
        {
            if(head1->getData().get_CGPA() <  head2->getData().get_CGPA())
            {
                push_dom(head1, head);
                delete_dom(head1);
            }
            else if (head1->getData().get_CGPA() ==  head2->getData().get_CGPA())
            {
                if(head1->getData().get_researchScore() <  head2->getData().get_researchScore())
                {
                    push_dom(head1, head);
                    delete_dom(head1);
                    continue;
                }
                else if (head1->getData().get_researchScore() ==  head2->getData().get_researchScore())
                {
                    
                    push_int(head2, head);
                    delete_int(head2);
                    if(head2->getData().get_CGPA() == head1->getData().get_CGPA() &&
                        head2->getData().get_researchScore() == head1->getData().get_researchScore())
                    {
                        head_insert(head1, head2, head);
                    }
                    else
                    {
                    push_dom(head1, head);
                    delete_dom(head1);
                    }
                }
                else
                {
                    push_int(head2, head);
                    delete_int(head2);
                }
            }
            else
            {
                push_int(head2, head);
                delete_int(head2);
            }
        }
    }

}

void push_dom(Nodeptr& head1, Node& head)
{
    Node temp_ptr;
    Student *temp_Stu;
    DomesticStudent temp_stu2(head1->getData());
    temp_Stu = &temp_stu2;
    temp_ptr = new mergenode(temp_Stu, head);
    head = temp_ptr;
    temp_Stu->out();

}
void push_int(Nodeptr_int& head2, Node& head)
{
    Node temp_ptr;
    
    if(head2->getData().get_reading() < 20 ||
        head2->getData().get_listening() < 20 ||
        head2->getData().get_speaking() < 20 ||
        head2->getData().get_writing() < 20 || 
        head2->getData().get_totalScore() <93)
        {return;}

    else
    {
        Student *temp_Stu_int;
        InternationalStudent temp_stu1(head2->getData());
        temp_Stu_int = &temp_stu1;
        temp_ptr = new mergenode(temp_Stu_int, head);
        head = temp_ptr;  
	    temp_Stu_int->out();
    }
    
}
void delete_dom(Nodeptr& head1)
{
    Nodeptr temp_ptr;
    temp_ptr = head1;
    head1 = head1->getlink();
    delete temp_ptr;
    if(head1->getlink() == NULL)
    {
        cout  << head1->getData();
    }
    
}
void delete_int(Nodeptr_int& head2)
{
    Nodeptr_int temp_ptr;
    temp_ptr = head2;
    head2 = head2->getlink();
    delete temp_ptr;
    
}
    




