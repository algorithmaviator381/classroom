---
layout: default
title: sql1
parent: DBMS
nav_order: 1
---

Create a table named `Departments`

```sql
CREATE TABLE Departments (
    dept VARCHAR(50) PRIMARY KEY,
    dept_name VARCHAR(100) NOT NULL
);
```

Create Students Table

```sql
CREATE TABLE Students (
    rollno INT PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    age INT NOT NULL,
    marks INT NOT NULL,
    dept VARCHAR(50),
    fees DECIMAL(10, 2) NOT NULL,
    FOREIGN KEY (dept) REFERENCES Departments(dept)
);
```


Insert Data into Departments Table

```sql
INSERT INTO Departments (dept, dept_name)
VALUES 
('AI&DS', 'Artificial Intelligence and Data Science'),
('IT', 'Information Technology');
```

Insert Data into Students Table
```sql
INSERT INTO Students (rollno, name, age, marks, dept, fees)
VALUES
(1, 'Ranchoddas Shamaldas Chanchad', 21, 42, 'AI&DS', 120000),
(2, 'Raju Rastoji', 21, 56, 'IT', 85000),
(3, 'Virus', 21, 43, 'IT', 85000),
(4, 'Milimeter', 21, 85, 'IT', 85000),
(5, 'Priya', 21, 97, 'AI&DS', 120000);
```

Rename table

```sql
ALTER TABLE Students RENAME TO "student"
```

Group By to get minimum marks

```sql
SELECT dept, min(marks) as LowestMarks
FROM Students
GROUP BY dept;
```


Add column

```sql
ALTER TABLE students
ADD fees INT DEFAULT 45000;
```

Join tables

```sql
SELECT rollno,name,dept_name
FROM students
INNER JOIN departments ON students.dept = departments.dept;
```