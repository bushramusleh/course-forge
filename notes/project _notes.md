# CourseForge - Project Notes

## 1. Dataset Seed

The last 4 digits of my student ID are:

7245

Therefore:

Seed = 7245


## 2. Number of Courses

Formula:

n = 12 + (seed % 6)

Calculation:

n = 12 + (7245 % 6)

7245 % 6 = 3

Therefore:

n = 12 + 3 = 15

Number of courses = 15


## 3. Number of Student Records

Formula:

m = 40 + (seed % 20)

Calculation:

m = 40 + (7245 % 20)

7245 % 20 = 5

Therefore:

m = 40 + 5 = 45

Number of student records = 45


## 4. Credit Cap

Formula:

C = 15 + (seed % 4)

Calculation:

C = 15 + (7245 % 4)

7245 % 4 = 1

Therefore:

C = 15 + 1 = 16

Credit Cap = 16
# step 1 :
 i made a folder in the  desktop "courseforge"
then i opend the github and i made repository 
# step 2:
i copied the https link for the repository to conect the project with github 
# step 3:
i choose visual studio code to write and run the project with the necessary tools setup to run c++ programs ...including (git , c++ compiler )and chick if g++ work well 
so now everything ready to write and run the code 
# step 4 :
i opend the folder courseforge in vs code after connected it with repository so now i can handle with git inside the vs code 
# step 5 :
i made it a file to make  notes " project_notes.md"
# step 6:
when i tried to make commit to the first time i had  a problem because the git inside the terminal didnt have the user name and the user email so i put "git config user.name , git config user. email" and the opreation sucssed i saw "no changed files"
then "sync changes"
# step 7:
i made the main file project "main .cpp"
then i wrote the basic program of c++
# step 8:
in the terminal i put this stetmant" g++ main.cpp -o main.exe" isaw new file "main.exe"
then i wrote "./main.exe" then enter i saw seed 7245 so that mean the first test sucssed
i did same thing for all numbers  same test
# step9 :
i use a funcation to random number generator and then test it and give me the first number 2033824514
and the second number
note: chatgpt helped me in some points for example when i used the terminal , aslo in git, and in MSYS2(g++)
-----------------> first  three days 
# step one :
 i made struct course then made an array for 15 courses
 # step 2:
 i made struct student then made array for student have the id and gpa between (2-4), name ...
 # step 3:
 i made switch to let the program work accordaing to user input
 # step 4:
 now  make the main menu pregram
 # step 5: 
 i  implement the selection sort with comparisons and swaps 
 and commit it with git hup 
 # step 6:
 module one ready 
 selection sort
 comarisons 
 swaps 
 insertion sort into same data
 count comparisons 
 count shifts 
 print the result for two ways
   make sure if both list match or not
   trace mode for array have 10 index
   --------> second 3 days done


