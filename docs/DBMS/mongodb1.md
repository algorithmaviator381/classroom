---
layout: default
title: mongodb1
parent: DBMS
---

## Basic Commands

1. show database
```shell
show databases
```

2. switch database
```shell
use <database_name>
```

3. show collections
```shell
show collections
```

4, Create collection
```shell
db.createCollection('NewCollection')
```

5. insert document
```shell
db.<collection_name>.insertOne({<document>})
```

```shell
db.myCollection.insertMany([
  { name: "Charlie", profession: "Doctor" },
  { name: "Diana", hobby: "Photography" }
])
```

6. delete collection

```shell
db.exam_collection.deleteOne({ name: "Alice" })
```

```shell
db.<collection_name>.deleteMany({ name: "Alice" })
```

7. Drop collection (caution)

```shell
db.<collection_name>.drop()
```

## Curd operations

```shell
db.createCollection('students')
```

```shell
db.students.insertOne({ "rollno": 1, "name": "Ranchoddas Shamaldas Chanchad", "age": 21, "marks": 42, "dept": "AI&DS", "fees": 120000 })
```

```shell
db.students.insertMany([
  { "rollno": 2, "name": "Raju Rastoji", "age": 21, "marks": 56, "dept": "IT", "fees": 85000 },
  { "rollno": 3, "name": "Virus", "age": null, "marks": null, "dept": "IT", "fees": 85000 },
  { "rollno": 4, "name": "Milimeter", "age": null, "marks": null, "dept": "IT", "fees": 85000 },
  { "rollno": 5, "name": "Priya", "age": null, "marks": null, "dept": "AI&DS", "fees": 120000 }
])
```

```shell
db.students.find()
```

```shell
db.students.find({ "dept": "IT" })
```

```shell
db.students.find({ "age": { $gt: 20 } })
```

```shell
db.students.updateOne({ "rollno": 3 }, { $set: { "marks": 90 } })
```

```shell
db.students.updateMany({ "dept": "IT" }, { $set: { "age": 22 } })
```

```shell
db.students.deleteOne({ "rollno": 4 })
```

```shell
db.students.deleteMany({ "marks": null })
```