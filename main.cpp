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
void selectionsort(student students[],int size,int& comparisons,int& swaps){
    comparisons = 0;
    swaps = 0;
    for(int i=0;i<size-1;i++){
        int minindex=i;
        for(int j=i+1;j<size;j++){
            comparisons++;
            if(students[j].gpa<students[minindex].gpa){
                minindex=j;
            }
        }
        if(minindex!=i){
            student temp=students[i];
            students[i]=students[minindex];
            students[minindex]=temp;
            swaps++;
        }
    }
}
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
    cout<<"\n--main menu--\n";
    cout<<"1 sort students by records\n";
cout<<"2  course  study   order\n";
cout<<"3  best course load\n";
cout<<"4 search and gcd\n";
cout<<"5 exit\n";
int choise;
cout<<"enter your choise:";
cin>>choise;
switch(choise)
{
    case 1:
    {
    int comparisons=0,swaps=0;
        selectionsort(students, numberofrecords,comparisons,swaps);
        cout<<"\n students sorted by gpa:\n";
        for (int i = 0; i < numberofrecords; i++)
        {
            cout << "Student ID: " << students[i].id << endl;
            cout << "Student Name: " << students[i].name << endl;
            cout << "GPA: " << students[i].gpa << endl;
            cout << endl;
        }
        cout << "\nComparisons: " << comparisons << endl;
        cout << "Swaps: " << swaps << endl;
        break;
    }
        case 2:
        
            cout<<"course study order not implemented yet\n";
            break;
            case 3:
                
                cout<<"best course load not implemented yet\n";
                break;
            case 4:
            
                cout<<"search and gcd not implemented yet\n";
                break;
                case 5:
                
                    cout<<"exit\n";
                    break;
                    default:
                        cout<<"invalid choise\n";
            
        
    
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