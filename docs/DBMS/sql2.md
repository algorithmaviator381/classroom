---
layout: default
title: sql2
parent: DBMS
---

## Problem statement

Design and develop SQL Data Definition Language (DDL) commands for creating, modifying, and deleting base tables and views in a relational database management system (RDBMS). Utilize various DDL commands such as `CREATE`, `ALTER`, `DROP`, `RENAME`, and `TRUNCATE` to define the structure of base tables and views effectively.


### 1. Create the `Client_master` table

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

2. Find the names of clients whose `bal_due > 5000`

```sql
SELECT Name
FROM Client_master
WHERE bal_due > 5000;
```

3. Change the bal_due of ClientNO 'C123' to Rs. 5100

```sql
UPDATE Client_master
SET bal_due = 5100
WHERE ClientNO = 'C123';
```

4. Change the name of Client_master to Client12

```sql
ALTER TABLE Client_master
RENAME TO Client12;
```

5. Display the bal_due heading as "BALANCE" in Client12 table

```sql
SELECT ClientNO, Name, Address, City, State, bal_due AS BALANCE
FROM Client12;
```

6. Delete all records but keep the table structure

```sql
TRUNCATE TABLE Customer_info;
```

7. Add the column Pin_code to the table

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