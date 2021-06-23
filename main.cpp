
//main.cpp, put your driver code here,

///////////////////////////////////////////
// Name       :     Divyam Sharma
// Student Id :     301372345
// Class      :     Ensc 251, D100, LA03
// Title      :     Assignment 3
//FileName    :     Main.cpp

//About:             
//This is the main file that helps read the files in the directory
//This program reads two types of files, international and national
//It uses getline, ifstream inside a while loop to split all the lines into separate variables
//Then its uses all the class function to access private variables as the assignment wants us to learn using classes and objects
//It also sorts all the functions and outputs that using overloaded operators
//

// It stores all the variables using the functions provided in the  implementation file   : Student.cpp
// And the variables are define in the                              header file           : student.hpp

////////////////////////////////////////////

//main.cpp, put your driver code here,
//you can manipulate your class objects here
#include <iostream> //cin and cout
#include <fstream> //file processing
#include <sstream> //formatted string processing
#include <cstdlib> //atof and atoi

#include <iomanip>//Formatting output
#include <stdio.h>
//Making sure string input with capital and non capital are not mixed
#include <cstring>
#include <cctype>

#include "student.hpp"




bool isFloat(string CGPA)
{
    istringstream iss(CGPA);
    float f;
    iss >> noskipws >> f;

    return iss.eof() && !iss.fail();
}
bool isInt(string CGPA)
{
    istringstream iss(CGPA);
    int f;
    iss >> noskipws >> f;

    return iss.eof() && !iss.fail();
}

int main()
{
    Nodeptr head = new domesticnode();

    //Read the domestic-stu.txt file and exit if failed
    string line;
    ifstream domesticFile("domestic-stu.txt");
    if(!domesticFile.is_open()) {
        cout << "Unable to open file domestic-stu.txt" << endl;
        return -1;
    }

    //Read the first line of domestic-stu.txt, which specifies
    //the file format. And then print it out to the screen
    getline(domesticFile, line);
    cout << "File format for domestic: " << line << endl;

    int stu_count = 0;
    DomesticStudent *Test1 = new DomesticStudent[100];

    while( getline(domesticFile, line) ) {
        if (domesticFile.eof())
        {
            domesticFile.close();
            break;
        }
        
        /*process each line, get each field separated by a comma.
        *We use istringstream to handle it.
        */
        istringstream ss(line);
        
        //Initialize a DomesticStudent object for each line
        
        string firstName, lastName, province, s_cgpa, s_researchScore, s_extra;
        float cgpa;
        int researchScore;

        //get firstName separated by comma 
        getline(ss, firstName, ',');
        Test1[stu_count].set_firstName(firstName);
        
        //get lastName separated by comma 
        getline(ss, lastName, ',');
        Test1[stu_count].set_lastName(lastName);
        
        //get province separated by comma 
        getline(ss, province, ',');
        if (province == "NL" || province == "PE" || province == "NS" || province == "NB" ||
        province == "QC" || province == "ON" || province == "MB" || province == "SK" ||
        province == "AB" || province == "BC" || province == "YT" || province == "NT" || province == "NU")
        {
            Test1[stu_count].set_province(province);
        }
        else
        {
            cout << "The province is incorrect. Rerun the program " <<  stu_count <<endl;
            exit(2);
        }
        
        
        //get cpga separated by comma, and convert string to float. 
        getline(ss, s_cgpa, ',');
        if(isFloat(s_cgpa) == 0)
        {
            cout << "The CGPA is wrong out of file " <<  stu_count << endl;
            exit(3);
        }
        
    
        cgpa = atof(s_cgpa.c_str());
        if(cgpa < 0 || cgpa > 4.33)
        {
            cout << "CGPA out of range in file "<< stu_count << endl;
            exit(3);
        }
        
        Test1[stu_count].set_CGPA(cgpa);
    
        if(!getline(ss, s_researchScore, ','))
        {
            cout << "Line number " << stu_count << " is missing fields in Domestic Students" << endl;
            exit(1);
        }
        if(isInt(s_researchScore) == 0)
        {
            cout << "The ResearchScore is wrong out of file " << stu_count<< endl;
            exit(4);
        }

        //get researchScore separated by comma, and convert it to int. 

        researchScore = atoi(s_researchScore.c_str());
        if(researchScore < 0 || researchScore > 100)
        {
            cout << "Research Score is out of range in file " << stu_count<< endl;
            exit(4);
        }
        Test1[stu_count].set_researchScore(researchScore);
        
        head_insert_dom(head, Test1[stu_count], stu_count);
        stu_count++;
        
    }
    

    //Read the international-stu.txt file and exit if failed
    Nodeptr_int headint = new internationalnode();
    string line2;
    ifstream internationalFile("international-stu.txt");
    if(!internationalFile.is_open()) {
        cout << "Unable to open file international-stu.txt" << endl;
        return -1;
    }
    
    getline(internationalFile, line2);
    cout << "File format for International: " << line2 << endl;
    
    int stu_count2 = 0;
    //Making a variable to pass in the function
    InternationalStudent *Test2 = new InternationalStudent[100];
    while(getline(internationalFile, line2) ) {
        if (internationalFile.eof())
        {
            internationalFile.close();
            break;
        }
        istringstream ss(line2);
        
        //Initialize an InternationalStudent Object for each line
        string firstName, lastName, country, s_cgpa, s_researchScore, s_reading, s_listening, s_speaking, s_writing;
        float cgpa;
        int researchScore, reading, listening, speaking, writing;
        
        //get firstName separated by comma
        getline(ss, firstName, ',');
        Test2[stu_count2].set_firstName(firstName);
        
        //get lastName separated by comma
        getline(ss, lastName, ',');
        Test2[stu_count2].set_lastName(lastName);
        
        //get country separated by comma
        getline(ss, country, ',');
        Test2[stu_count2].set_country(country);
        
        //get cpga separated by comma, and convert string to float
        getline(ss, s_cgpa, ',');
        if(isFloat(s_cgpa) == 0)
        {
            cout << "The CGPA is wrong out of file " << stu_count2 << endl;
            exit(3);
        }
        cgpa = atof(s_cgpa.c_str());
        if(cgpa < 0 || cgpa > 4.33)
        {
            cout << "CGPA out of range in file " << stu_count2 << endl;
            exit(3);
        }
        Test2[stu_count2].set_CGPA(cgpa);
        
        //get researchScore separated by comma, and convert it to int. Store it in Test2
        getline(ss, s_researchScore, ',');
        if(isInt(s_researchScore) == 0)
        {
            cout << "The ResearchScore is wrong out of file " << stu_count2<< endl;
            exit(4);
        }
        researchScore = atoi(s_researchScore.c_str());
        if(researchScore < 0 || researchScore > 100)
        {
            cout << "Research Score is out of range in file " << stu_count2 << endl;
            exit(4);
        }
        Test2[stu_count2].set_researchScore(researchScore);
        
        //get readScore separated by comma, and convert it to int. Store it in Test2.
        getline(ss, s_reading, ',');
        reading = atoi(s_reading.c_str());
        Test2[stu_count2].set_reading(reading);
    
        //get listenScore separated by comma, and convert it to int. Store it in Test2.
        getline(ss, s_listening, ',');
        listening = atoi(s_listening.c_str());
        Test2[stu_count2].set_listening(listening);
        
        //get speakScore separated by comma, convert it to int and update Test2's speaking Score.
        getline(ss, s_speaking, ',');
        speaking = atoi(s_speaking.c_str());
        Test2[stu_count2].set_speaking(speaking);
        
        //get writeScore separated by comma, and convert it to int. Store it in Test2.
        if(!getline(ss, s_writing, ','))
        {
            cout << "Line number " << stu_count2 << " is missing fields in International Students" << endl;
            exit(1);
        
        }

        writing = atoi(s_writing.c_str());

        if((   reading < 0 || reading > 30 || isInt(s_reading) == false||
                writing < 0 || writing > 30 || isInt(s_writing) == false||
                listening < 0 || listening > 30 || isInt(s_listening)== false ||
                speaking <0 || speaking > 30 || isInt(s_speaking)== false))
        {
            cout << "Error is toefl score on line " << stu_count2<<endl;
            exit(5);
        }
        Test2[stu_count2].set_writing(writing);
        Test2[stu_count2].set_totalScore();

        //print out International students information
        //cout << stu_count2 << ". " << Test2[stu_count2];
        head_insert_int(headint, Test2[stu_count2], stu_count2);
        stu_count2++;
    } 

    //Taking input from user of what type of student
    int typeofstu;
    Node both_head = new mergenode();
    bool select = false;
    do
    {
    typeofstu = 0;
    cout    << "What Type of Students do you want? " << endl 
            << "1. Domestic(Type 1 and press enter)" << endl 
            << "2. International(Type 2 and press enter)" << endl
            << "3. Merge the two lists(Type 3 and press enter)" << endl;
    cin >> typeofstu;
    //Actions for the user selected input
    if(typeofstu == 1)
    {
        cout << "These are the sorted nodes for domestic student: " << endl << endl;
        display_nodes_dom(head);
        actions_dom(head, stu_count);
        select = true;
    }
    else if (typeofstu == 2)
    {
        cout << "These are the sorted nodes for International student: " << endl << endl;
        display_nodes_int(headint);
        actions_int(headint, stu_count);
        select = true;
    }
    else if (typeofstu == 3)
    {
        head_insert(head, headint, both_head);
        select = true;
    }
    else
    {
        cout << "Wrong type of input please enter a valid input" << endl;
        select = false;
    }
    }while(select == false);

    //Deleting All the nodes lists at the end after the whole program
    while(head != NULL)
    {
        Nodeptr todelete = head;
        head = head->getlink();
        delete todelete;
    }
    while(headint != NULL)
    {
        Nodeptr_int todelete = headint;
        headint = headint->getlink();
        delete todelete;
    }
    while(both_head != NULL)
    {
        Node todelete = both_head;
        both_head = both_head->link;
        delete todelete;
    }

            
    return 0;
}















