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


int main()
{
    int stu_count = 0;
    Nodeptr head1 = new domesticnode();


    DomesticStudent Test1a("Bob","Davison", 4.33, 99, "AB");
    stu_count = 0;
    head_insert_dom(head1, Test1a, stu_count);
    display_nodes_dom(head1);
    cout << endl;


    DomesticStudent Test2("Mark", "Cheng", 2.0, 65, "BC");
    stu_count = 1;
    head_insert_dom(head1, Test2, stu_count);
    display_nodes_dom(head1);
        cout << endl;


    DomesticStudent Test3("Kate", "Wang", 3.65, 65, "QC");
    stu_count = 3;
    head_insert_dom(head1, Test3, stu_count);
    display_nodes_dom(head1);
        cout << endl;


    DomesticStudent Test4("Judd", "Foster",4.33,32 ,"NL");    
    stu_count = 4;
    head_insert_dom(head1, Test4, stu_count);
    display_nodes_dom(head1);
        cout << endl;


    DomesticStudent Test5("Aeli", "Planas",4.20,69,"ON");
    stu_count = 5;
    head_insert_dom(head1, Test5, stu_count);
    display_nodes_dom(head1);
        cout << endl;


    int howmanytimes = 0;
    cout << "How many thing do you want to check" << endl;
    cin >> howmanytimes;
    for (int i = 0; i < howmanytimes; i++)
    {
    cout << "Check GPA and ResearchScore" << endl;
    search_domestic_gpa(head1);
    cout << "Check firstName and Lastname" << endl;
    search_domestic_name(head1);
    }

    howmanytimes = 0;
    cout << "How many thing do you want to delete" << endl;
    cin >> howmanytimes;
    for (int i = 0; i < howmanytimes; i++)
    {
        cout << "Enter name to be deleted" << endl;
        delete_node_dom(head1, stu_count);
//display_nodes_dom(head1);
            cout << endl;

    }

    while(head1 != NULL)
    {
        Nodeptr todelete = head1;
        head1 = head1->getlink();
        delete todelete;
    }



    Nodeptr_int headint1 = new internationalnode();
    InternationalStudent int_Test1("Divyam", "Sharma",3.45, 80, "Indian", 30, 27, 25, 25);
    stu_count = 6;
    head_insert_int(headint1, int_Test1, stu_count);
    display_nodes_int(headint1);
    cout << endl;

    InternationalStudent int_Test2("Maxim", "Farhat",3.0, 95, "Lebanon", 25,23,23,25);
    stu_count = 6;
    head_insert_int(headint1, int_Test2, stu_count);
    display_nodes_int(headint1);
        cout << endl;

    InternationalStudent int_Test3("Sunghyun", "Jang",2.5, 60, "Korean", 20,20,20,20);
    stu_count = 6;
    head_insert_int(headint1, int_Test3, stu_count);
    display_nodes_int(headint1);
    cout << endl;

    InternationalStudent int_Test4("Arjun", "Singha",1.0, 20, "Ukraine", 20,20,20,20);
    stu_count = 6;
    head_insert_int(headint1, int_Test4, stu_count);
    display_nodes_int(headint1);
    cout << endl;

    InternationalStudent int_Test5("Filip", "Zapeca",4.30, 80, "Czech Republic", 30,30,30,29);
    stu_count = 6;
    head_insert_int(headint1, int_Test5, stu_count);
    display_nodes_int(headint1);
    cout << endl;

    howmanytimes = 0;
    cout << "How many thing do you want to check" << endl;
    cin >> howmanytimes;
    for (int i = 0; i < howmanytimes; i++)
    {
        cout << "Check GPA and ResearchScore" << endl;
        search_int_gpa(headint1);
        cout << "Check firstName and Lastname" << endl;
        search_int_name(headint1);
    }
    howmanytimes = 0;
    cout << "How many thing do you want to delete" << endl;
    cin >> howmanytimes;
    for (int i = 0; i < howmanytimes; i++)
    {
        cout << "Enter name to be deleted" << endl;
        delete_node_int(headint1, stu_count);
// display_nodes_int(headint1);
            cout << endl;

    }
}
