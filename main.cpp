#include <iostream>

#include <string>
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
void selectionsort(student students[], int size, int &comparisons, int &swaps)
{
    comparisons = 0;
    swaps = 0;
    for (int i = 0; i < size - 1; i++)
    {
        int minindex = i;
        for (int j = i + 1; j < size; j++)
        {
            comparisons++;
            if (students[j].gpa < students[minindex].gpa)
            {
                minindex = j;
            }
        }
        if (minindex != i)
        {
            student temp = students[i];
            students[i] = students[minindex];
            students[minindex] = temp;
            swaps++;
        }
    }
}
void insertionSort(student students[], int size, int &comparisons, int &shifts)
{
    comparisons = 0;
    shifts = 0;
    for (int i = 1; i < size; i++)
    {
        student key = students[i];
        int j = i - 1;
        while (j >= 0 && students[j].gpa > key.gpa)
        {
            comparisons++;
            students[j + 1] = students[j];
            j--;
            shifts++;
        }
        if (j >= 0)
        {
            comparisons++;
        }

        students[j + 1] = key;
    }
}
void insertionSorttrace(int arr[], int size)
{
    cout << "input:";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        
        for (int k = 0; k < size; k++)
        {
            cout << arr[k] << " ";
            if (k == i)
            {
                cout << "|";
            }
        }
        cout << endl;
    }
}
void courseStudyOrder(course courses[], int numberofcourses)
{
    bool removed[100] = {false};
    int order[100];
    int count = 0;
    while (count < numberofcourses)
    {
        bool found = false;
        for (int i = 0; i < numberofcourses; i++)
        {
            if (!removed[i])
            {
                bool canstudy = false;
                if (courses[i].prerequisites == "None")
                {
                    canstudy = true;
                }
                else
                {
                    for (int j = 0; j < numberofcourses; j++)
                    {
                        if (courses[j].code == courses[i].prerequisites && removed[j])
                        {
                            canstudy = true;
                            break;
                        }
                    }
                }
                
                
                    
                
                if (canstudy)
                {

                    order[count] = i;
                    removed[i] = true;
                    count++;
                    found = true;
                    break;
                }
            }
        }
        if (!found)
        {
            cout << "Error: Circular dependency detected among courses." << endl;
            return;
        }
    }
    cout << "Course Study Order:\n";
    for (int i = 0; i < numberofcourses; i++)
    {
        cout << "Course Code: " << courses[order[i]].code << endl;
        cout << "Course Name: " << courses[order[i]].name << endl;
        cout << "Credits: " << courses[order[i]].credits << endl;
        cout << "Value: " << courses[order[i]].value << endl;
        cout << "Prerequisites: " << courses[order[i]].prerequisites << endl;
        cout << endl;
    }
}
void bestcourseload(course courses[], int numberofcourses, int creditcap)
{
    cout << "Best Course Load:\n";
    int bestvalue = 0;
    int bestcredits = 0;

    bool selected[100] = {false};
    int k = 10;
    int legal =0;
    if (numberofcourses < k)
    {
        k = numberofcourses;
    }
    int totalcombinations = 1 << k;
    for (int mask = 0; mask < totalcombinations; mask++)
    {
        int currentcredits = 0;
        int currentvalue = 0;
        for (int i = 0; i < k; i++)
        {
            if (mask & (1 << i))
            {
                currentcredits += courses[i].credits;
                currentvalue += courses[i].value;
            }
        }
        if (currentcredits <= creditcap)
        {
            legal++;
        }
        if (currentcredits <= creditcap && currentvalue > bestvalue)
        {
            bestvalue = currentvalue;
            bestcredits = currentcredits;
            for (int i = 0; i < k; i++)
            {
                selected[i] = (mask & (1 << i));
            }
        }
    }
    cout << "\n best course load:\n";

    for (int i = 0; i < numberofcourses; i++)
    {
        if (selected[i])
        {
            cout << "Course Code: " << courses[i].code << endl;
            cout << "Course Name: " << courses[i].name << endl;
            cout << "Credits: " << courses[i].credits << endl;
            cout << "Value: " << courses[i].value << endl;

            cout << endl;
        }
    }
    cout << "Total Credits: " << bestcredits << endl;
    cout << "Total Value: " << bestvalue << endl;
    cout << "checked subsets:" << totalcombinations << endl;
    cout << "legal subsets:" << legal << endl;
}
int gcd(int a, int b, int &modOperations)
{
    modOperations = 0;

    while (b != 0)
    {
        int temp = b;

        b = a % b;
        modOperations++;

        a = temp;
    }

    return a;
}
int lcm(int a, int b, int gcdValue)
{
    if (gcdValue == 0)
    
        return 0;
    
    return (a * b) / gcdValue;
}

int binarySearch(student students[], int size, double target, int &comparisons)
{
    int left = 0;
    int right = size - 1;
    comparisons = 0;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        comparisons++;

        if (students[mid].gpa == target)
        {
            return mid;
        }
        else if (students[mid].gpa < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1;
}

void runExperiments()
{
    int sizes[5] = {100, 200, 400, 800, 1600};
    int selectionresults[5] ;
    int insertionresults[5] ;
    int binaryresults[5] ;
    
double selectionratio[4];
double insertionratio[4];
double binaryratio[4];
    cout << "\n--Experiments results--\n";
    

    for (int s = 0; s < 5; s++)
    {
        int n = sizes[s];

        student original[1600];
        student selectionStudents[1600];
        student insertionStudents[1600];

        long long randomvalue = 7245;

        for (int i = 0; i < n; i++)
        {
            original[i].id = 2021000 + i;
            original[i].name = "Student " + to_string(i + 1);
            original[i].gpa = 2.0 + (randomvalue % 201) / 100.0;

            randomvalue = nextrandom(randomvalue);
        }

        long long totalSelection = 0;
        long long totalInsertion = 0;
        long long totalBinary = 0;

        for (int run = 0; run < 3; run++)
        {
            for (int i = 0; i < n; i++)
            {
                selectionStudents[i] = original[i];
                insertionStudents[i] = original[i];
            }

            int selectionComparisons = 0;
            int selectionSwaps = 0;

            selectionsort(
                selectionStudents,
                n,
                selectionComparisons,
                selectionSwaps);

            totalSelection += selectionComparisons;

            int insertionComparisons = 0;
            int insertionShifts = 0;

            insertionSort(
                insertionStudents,
                n,
                insertionComparisons,
                insertionShifts);

            totalInsertion += insertionComparisons;

            int binaryComparisons = 0;

            binarySearch(
                selectionStudents,
                n,
                3.50,
                binaryComparisons);

            totalBinary += binaryComparisons;
        }
        selectionresults[s] = totalSelection / 3;
        insertionresults[s] = totalInsertion / 3;
        binaryresults[s] = totalBinary / 3;

    }
        
           cout<<"size\tselection\tinsertion\tbinary\n";
             cout << "----------------------------------------\n";

for(int i=0;i<5;i++)
{
    
    cout << sizes[i] << "\t" << selectionresults[i] << "\t\t" << insertionresults[i] << "\t\t" << binaryresults[i] << endl;
}
for(int i=0;i<4;i++)
{
    selectionratio[i] = (double)selectionresults[i + 1] / selectionresults[i];
    insertionratio[i] = (double)insertionresults[i + 1] / insertionresults[i];
    binaryratio[i] = (double)binaryresults[i + 1] / binaryresults[i];
    cout<<"\n--Ratios--\n";
    cout<<"selectionsotr:\n";
    for(int i=0;i<4;i++)
    {
        cout<<"size:"<<sizes[i]<<" -> "<<sizes[i+1]<<":"<<selectionratio[i]<<endl;
}
        cout<<"\ninsertionsort:\n";
    for(int i=0;i<4;i++)
    {
        cout<<"size:"<<sizes[i]<<" -> "<<sizes[i+1]<<":"<<insertionratio[i]<<endl;
    }
        cout<<"\nbinarysearch:\n";
    for(int i=0;i<4;i++)
    {
        cout<<"size:"<<sizes[i]<<" -> "<<sizes[i+1]<<":"<<binaryratio[i]<<endl;
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
    cout << "seed:" << seed << endl;
            cout << "number of courses:" << numberofcourses << endl;
            cout << "number of records:" << numberofrecords << endl;
            cout << "credit cap:" << creditcap << endl;
            

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
    cout << "\n--main menu--\n";
    runExperiments();

    int choise;
    do
    {
        cout << "1 sort students by records\n";
        cout << "2  course  study   order\n";
        cout << "3  best course load\n";
        cout << "4 search and gcd\n";
        cout << "5 exit\n";

        

        cout << "enter your choise:";
        cin >> choise;
        switch (choise)
                
    {
        case 1:
        {
            student selectedstudents[100];
            student insertionstudents[100];
            for (int i = 0; i < numberofrecords; i++)
            {
                selectedstudents[i] = students[i];
                insertionstudents[i] = students[i];
            }
            int comparisons = 0, swaps = 0;
            selectionsort(selectedstudents, numberofrecords, comparisons, swaps);
            int insertioncomparisons = 0, insertionshifts = 0;
            insertionSort(insertionstudents, numberofrecords, insertioncomparisons, insertionshifts);
            cout << "\n students sorted by gpa:\n";
            for (int i = 0; i < numberofrecords; i++)
            {
                cout << "Student ID: " << selectedstudents[i].id << endl;
                cout << "Student Name: " << selectedstudents[i].name << endl;
                cout << "GPA: " << selectedstudents[i].gpa << endl;
                cout << endl;
            }
            cout << "\nSelection Sort Comparisons: " << comparisons << endl;
            cout << "Selection Sort Swaps: " << swaps << endl;
            cout << "\ninsertion Sort Comparisons: " << insertioncomparisons << endl;
            cout << "Insertion Sort shifts: " << insertionshifts << endl;
            cout << " insertion sort shifts:\n";
            bool same = true;
            for (int i = 0; i < numberofrecords; i++)
            {
                if (selectedstudents[i].id != insertionstudents[i].id || selectedstudents[i].name != insertionstudents[i].name || selectedstudents[i].gpa != insertionstudents[i].gpa)
                {
                    same = false;
                    break;
                }
            }

                if (same)
                {
                    cout << "\nThe two sorting algorithms produced the same results.\n";
                }
                else
                {
                    cout << "\nThe two sorting algorithms produced different results.\n";
                }
                int tracearray[10] = {5, 2, 9, 1, 5, 6, 3, 8, 7, 4};
                cout << "\nInsertion Sort Trace:\n";
                insertionSorttrace(tracearray, 10);
                break;
            
        }
        case 2:
        {


            courseStudyOrder(courses, numberofcourses);
            break;
        }   
        case 3:
        {

            bestcourseload(courses, numberofcourses, creditcap);
            break;
        }
        case 4:
        {
            student sortedstudents[60];

            for (int i = 0; i < numberofrecords; i++)
            {
                sortedstudents[i] = students[i];
            }

            int sortcomparisons = 0;
            int sortswaps = 0;

            selectionsort(sortedstudents, numberofrecords, sortcomparisons, sortswaps);

            double targetGPA;

            cout << "Enter GPA to search: ";
            cin >> targetGPA;

            int searchcomparisons = 0;

            int result = binarySearch(
                sortedstudents,
                numberofrecords,
                targetGPA,
                searchcomparisons);

            if (result != -1)
            {
                cout << "Student found at index: " << result << endl;
                cout << "Student ID: " << sortedstudents[result].id << endl;
                cout << "Student Name: " << sortedstudents[result].name << endl;
                cout << "GPA: " << sortedstudents[result].gpa << endl;
            }
            else
            {
                cout << "Student not found." << endl;
            }

            cout << "Binary Search Comparisons: "
                 << searchcomparisons << endl;
                 int a, b;

cout << "Enter two numbers: ";
cin >> a >> b;

int modOperations;

int gcdValue = gcd(a, b, modOperations);
int lcmValue = lcm(a, b, gcdValue);

cout << "GCD: " << gcdValue << endl;
cout << "LCM: " << lcmValue << endl;
cout << "Modulo operations: " << modOperations << endl;

            break;
        }
        case 5:
        {

            cout << "exit\n";
            break;
        }
        default:
        {

            cout << "invalid choise\n";
            break;
        }
        
    
    
        
            
    
    
        
        
 } ;
 
 } while (choise != 5);
 return 0;
 }
