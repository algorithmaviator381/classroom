---
layout: default
title: Cursor
parent: plsql
nav_order: 2
---

## Introduction

```sql
SET SERVEROUTPUT ON;
```

## Create table
```sql
CREATE TABLE Stud (
    Roll NUMBER PRIMARY KEY,
    Att NUMBER(5, 2),
    Status VARCHAR2(2)
);
```

## Insert Data into the Table

```sql
INSERT INTO Stud (Roll, Att, Status) VALUES (1, 80.00, NULL);
INSERT INTO Stud (Roll, Att, Status) VALUES (2, 70.00, NULL);
INSERT INTO Stud (Roll, Att, Status) VALUES (3, 90.00, NULL);
INSERT INTO Stud (Roll, Att, Status) VALUES (4, 65.00, NULL);

COMMIT;
```

## PL/SQL block

```sql
DECLARE
    v_roll Stud.Roll%TYPE;
    v_att Stud.Att%TYPE;
    v_status Stud.Status%TYPE;
BEGIN
    v_roll := &Enter_Roll_No;

    BEGIN
        SELECT Att INTO v_att
        FROM Stud
        WHERE Roll = v_roll;
        
        IF v_att < 75 THEN
            DBMS_OUTPUT.PUT_LINE('Term not granted');
            v_status := 'D';
        ELSE
            DBMS_OUTPUT.PUT_LINE('Term granted');
            v_status := 'ND';
        END IF;
        
        UPDATE Stud
        SET Status = v_status
        WHERE Roll = v_roll;
    EXCEPTION
        WHEN NO_DATA_FOUND THEN
            DBMS_OUTPUT.PUT_LINE('No student found with the given roll number');
    END;
EXCEPTION
    WHEN OTHERS THEN
        DBMS_OUTPUT.PUT_LINE('An unexpected error occurred: ' || SQLERRM);
END;
/
```