---
layout: default
title: sql2
parent: DBMS
---

# Problem statement 1

Design and develop SQL Data Definition Language (DDL) commands for creating, modifying, and deleting base tables and views in a relational database management system (RDBMS). Utilize various DDL commands such as `CREATE`, `ALTER`, `DROP`, `RENAME`, and `TRUNCATE` to define the structure of base tables and views effectively.


Create the `Client_master` table

```sql
CREATE TABLE Client_master (
    ClientNO VARCHAR(10) PRIMARY KEY,
    Name VARCHAR(100),
    Address VARCHAR(255),
    City VARCHAR(50),
    State VARCHAR(50),
    bal_due DECIMAL(10, 2)
);
```

```sql
INSERT INTO Client_master (ClientNO, Name, Address, City, State, bal_due) VALUES
('C101', 'Aditya Godse', '123 Elm St', 'Pune', 'MH', 6000.00),
('C102', 'Sakshi Mane', '456 Oak St', 'Mumbai', 'MH', 4500.00),
('C103', 'Jaydeep Tayshete', '789 Pine St', 'Pune', 'MH', 7000.00),
('C104', 'Ana de armas', '321 Maple St', 'Delhi', 'DL', 8000.00),
('C105', 'Tom Clark', '654 Birch St', 'Chennai', 'TN', 3000.00),
('C106', 'Tom Hanks', '987 Cedar St', 'Pune', 'MH', 5000.00),
('C107', 'Robert downey Jr.', '213 Spruce St', 'Bangalore', 'KA', 2000.00),
```

Find the names of clients whose `bal_due > 5000`

```sql
SELECT Name
FROM Client_master
WHERE bal_due > 5000;
```

Change the bal_due of ClientNO 'C123' to Rs. 5100

```sql
UPDATE Client_master
SET bal_due = 5100
WHERE ClientNO = 'C123';
```

Change the name of Client_master to Client12

```sql
ALTER TABLE Client_master
RENAME TO Client12;
```

Display the bal_due heading as "BALANCE" in Client12 table

```sql
SELECT ClientNO, Name, Address, City, State, bal_due AS BALANCE
FROM Client12;
```

Delete all records but keep the table structure

```sql
TRUNCATE TABLE Customer_info;
```

Add the column Pin_code to the table

```sql
ALTER TABLE Customer_info
ADD COLUMN Pin_code VARCHAR(10) DEFAULT 414141;
```

Display the list of clients whose city is Pune

```sql
SELECT ClientNO, Name, Address, State, bal_due AS Balance, Pin_code
FROM Customer_info
WHERE City = 'Pune';
```




# Problem statement 2

- Create a "Teacher" table with specified fields.
- Insert ten records into the table.
- Increase the salary by 25% for teachers in the Mathematics department.
- Rollback the changes made in step 3.
- Increase the salary by 15% for teachers in the Commerce department.
- Commit the changes made in step 5.
- Add a constraint to enforce that the "Date of Joining" field cannot be null.
- Change the datatype of the "JOB_ID" field from char to varchar2.
- Add a new column named "HIREDATE" to the table and enforce that it cannot be null.
- Modify the column width of the "job" field in the table.
- Delete records of teachers belonging to the Commerce department.

Create Teacher table

```sql
CREATE TABLE Teacher (
    Name VARCHAR2(50),
    DeptNo INT,
    Date_of_joining DATE NOT NULL,
    DeptName VARCHAR2(50),
    Location VARCHAR2(50),
    Salary NUMBER
);
```

Insert Ten records

```sql
INSERT INTO Teacher (Name, DeptNo, Date_of_joining, DeptName, Location, Salary)
VALUES
('Aditya Godse', 101, '2020-01-15', 'Mathematics', 'Building A', 50000),
('Sakshi Mane', 102, '2019-05-20', 'Physics', 'Building B', 55000),
('Jaydeep tayshete', 103, '2018-08-10', 'Chemistry', 'Building C', 52000),
('Prajyot Barsing', 104, '2021-02-28', 'Biology', 'Building D', 48000),
('A.S. Neill', 105, '2017-11-12', 'English', 'Building E', 60000),
('Neil D. Tyson', 106, '2022-04-03', 'Commerce', 'Building F', 53000),
('Bill Nile', 107, '2016-09-25', 'History', 'Building G', 51000),
('Alexender Grambhell', 108, '2015-03-17', 'Geography', 'Building H', 54000),
('Sir Issac Newton', 109, '2023-06-30', 'Computer Science', 'Building I', 57000),
('Daniel Garcia', 110, '2014-12-05', 'Economics', 'Building J', 59000);
```

Give Increment of 25% salary for Mathematics Department

```sql
UPDATE Teacher SET Salary = Salary * 1.25 WHERE DeptName = 'Mathematics';
```

Give Increment of 15% salary for Commerce Department

```sql
UPDATE Teacher SET Salary = Salary * 1.15 WHERE DeptName = 'Commerce';
```

Add the constraint not null on the Date of Joining

```sql
ALTER TABLE Teacher MODIFY (Date_of_joining DATE NOT NULL);
```

Change the datatype of JOB_ID from char to varchar2

```sql
ALTER TABLE Teacher MODIFY (JOB_ID VARCHAR2(50));
```

Add a new column; HIREDATE to the existing relation and add the constraint not null on it

```sql
ALTER TABLE Teacher ADD (HIREDATE DATE NOT NULL);
```

Modify the column width of the job field of Teacher table (assuming Teacher table has a job column)

```sql
ALTER TABLE Teacher MODIFY (job VARCHAR2(100));
```

Delete the record of the commerce department

```sql
DELETE FROM Teacher WHERE DeptName = 'Commerce';
```