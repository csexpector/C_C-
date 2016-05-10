#include "List.h"
#include <string>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

typedef struct President
{
    int position;
    string name;
    int age;
    int months;
    President() : name(""){};
    inline bool operator==(string strname)
    {
        if (name == strname) return true;
        else return false;
    }
} President;

List<President> readPresident();
void displayList(List<President> lstPresidents);
void search(List<President> lstPresidents, string pname);
int main()
{
    List<President> lstPresidents = readPresident();
    displayList(lstPresidents);
    string pname;
    while (true)
    {
        cout << "Enter a president name (enter to exit): ";
        getline(cin, pname);
        if (pname == "") break;
        else search(lstPresidents, pname);
    }


    return 0;
}


List<President> readPresident()
{
    List<President> lstPresidents;
    ifstream presidentsFile;
    presidentsFile.open("US_Presidents.csv");

    if(!presidentsFile){
        cout << "There was a problem reading the President File..." << endl;
        exit(99);
    }

    while (!presidentsFile.eof())
    {
        President p;
        //presidentsFile >> p.position;
        //presidentsFile.ignore();
        string s, position, name, age, months;
        getline(presidentsFile, s);
        std::stringstream ss(s);

        if (s == "") break;

        std::getline(ss, position, ',');
        stringstream(position) >> p.position;

        std::getline(ss, name, ',');
        p.name = name;

        std::getline(ss, age, ',');
        stringstream(age) >> p.age;

        std::getline(ss, months, ',');
        stringstream(months) >> p.months;

        lstPresidents.addMember(p);
    }
    presidentsFile.close();
    return lstPresidents;
}

void displayList(List<President> lstPresidents)
{
    int leastMonths = 200, mostMonths = 0, totalMonths = 0;
    float averageAge;
    string leastPresident, mostPresident;
    cout << "All presidents" << endl;
    for (int i = 0; i < lstPresidents.getNumber(); i++)
    {
        President p = lstPresidents.getNext();
        cout << "Position: " << p.position << " Name: " << p.name << " Age: " << p.age << " Months served: " << p.months << endl;
        averageAge += p.age;
        totalMonths += p.months;
        if (leastMonths > p.months)
        {
            leastMonths = p.months;
            leastPresident = p.name;
        }
        if (mostMonths < p.months)
        {
            mostMonths = p.months;
            mostPresident = p.name;
        }
    }

    cout << "Average age: " << averageAge / lstPresidents.getNumber() << endl;
    cout << "President that served least monts is " << leastPresident << " in " << leastMonths << endl;
    cout << "President that served most monts is " << mostPresident << " in " << mostMonths << endl;

    cout << "Total months served: " << totalMonths << " = ~" << totalMonths/12.0 << " years" << endl;
}
void search(List<President> lstPresidents, string pname)
{
    for (int i = 0; i < lstPresidents.getNumber(); i++)
    {
        President p = lstPresidents.getNext();
        if (p == pname)
        {
            cout << "Found president " << pname << " position: " << p.position 
                 << " age: " << p.age << " served " << p.months << " months" << endl;
            return;
        }
    }
    cout << "That person was not a president" << endl;
}
