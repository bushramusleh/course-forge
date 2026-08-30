#include <iostream>
using namespace std;
long long nextrandom(long long x)
{
    return (1103515245 * x + 12345) % 2147483648;
}
struct course
{
    string code;
    string name;
    int credits;
    int value;
    string prerequisites;
};
struct student
{
    int id;
    string name;
    double gpa;
};
int main()
{
    const int seed = 7245;
    long long randomvalue = nextrandom(seed);
    int numberofcourses = 12 + (seed % 6);
    int numberofrecords = 40 + (seed % 20);
    int creditcap = 15 + (seed % 4);
    course courses[15];
    student students[60];
    for (int i = 0; i < numberofrecords; i++)
    {
        students[i].id = 2021000 + i;
        students[i].name = "Student " + to_string(i + 1);
        students[i].gpa = 2.0 + (randomvalue % 201) / 100.0;
        randomvalue = nextrandom(randomvalue);
    }
    for (int i = 0; i < numberofrecords; i++)
    {
        cout << "Student ID: " << students[i].id << endl;
        cout << "Student Name: " << students[i].name << endl;
        cout << "GPA: " << students[i].gpa << endl;
        cout << endl;
    }

    for (int i = 0; i < numberofcourses; i++)
    {

        courses[i].code = "CSE" + to_string(i + 1);
        courses[i].name = "Course " + to_string(i + 1);
        courses[i].credits = 3 + (i % 3);
        courses[i].value = 10 + (i % 5);
        if (i > 0)
        {
            courses[i].prerequisites = courses[i - 1].code;
        }
        else
        {
            courses[i].prerequisites = "None";
        }
    }
    for (int i = 0; i < numberofcourses; i++)
    {
        cout << "course Code: " << courses[i].code << endl;
        cout << "course Name: " << courses[i].name << endl;
        cout << "credits: " << courses[i].credits << endl;
        cout << "Value: " << courses[i].value << endl;
        cout << "Prerequisites: " << courses[i].prerequisites << endl;
        cout << endl;
    }

    cout << "seed:" << seed << endl;
    cout << "number of courses:" << numberofcourses << endl;
    cout << "number of records:" << numberofrecords << endl;
    cout << "credit cap:" << creditcap << endl;
    cout << "first random value:" << randomvalue << endl;
    randomvalue = nextrandom(randomvalue);
    cout << "second random value:" << randomvalue << endl;
    return 0;
}