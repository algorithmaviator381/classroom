---
layout: default
title: sql1
parent: DBMS
---

## Types of SQL languages

### 1. Data defination language (DDL)
Purpose: DDL is used to define, modify, and manage the structure of database objects.

- CREATE: Used to create new database objects such as tables, views, indexes, etc.
- ALTER: Modifies the structure of existing database objects.
- DROP: Deletes database objects.
- TRUNCATE: Removes all records from a table while preserving its structure.
- RENAME: Renames a database object.

### 2. Data manipulation language (DML)
Purpose: DML is used to manipulate data within database objects.

- SELECT: Retrieves data from one or more tables.
- INSERT: Adds new rows of data into a table.
- UPDATE: Modifies existing data in a table.
- DELETE: Removes rows of data from a table.

### 3. Data control language (DCL)
Purpose: DCL is used to control access to data within the database.

- GRANT: Provides users with specific privileges to database objects.
- REVOKE: Revokes previously granted privileges from users.

### 4. Transaction control language (TCl)
Purpose: TCL is used to manage transactions within the database.

- COMMIT: Saves changes made during the current transaction.
- ROLLBACK: Reverts changes made during the current transaction.
- SAVEPOINT: Sets a point in the transaction to which you can later roll back.

## SQL vs NoSQL

| Aspect         | SQL Databases                 | NoSQL Databases                |
|----------------|-------------------------------|--------------------------------|
| Data Model     | Relational, organized in tables with predefined schemas | Non-relational, diverse data models such as document, key-value, columnar, or graph |
| Schema         | Fixed schema                   | Dynamic schema                 |
| Scalability    | Vertically scalable (scaling up by adding more resources to a single server) | Horizontally scalable (scaling out by adding more servers to a distributed system) |
| Consistency    | Strong consistency, ACID transactions | Flexible consistency models, eventual consistency, often sacrificing strong consistency for scalability |
| Query Language | Standardized SQL               | Not standardized; specific query languages or APIs depending on the database type |
| Examples       | MySQL, PostgreSQL, Oracle Database, Sqlite | MongoDB, Cassandra, Redis, DynamoDB, Firebase     |


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