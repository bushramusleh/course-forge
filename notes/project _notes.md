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