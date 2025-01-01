---
layout: default
title: 3. Database Configuration
parent: Cloud Computing
---

# How to Configure and Use Databases on AWS

AWS provides a wide range of database services to manage, store, and analyze your data. Two of the most popular databases you can use within the AWS free tier are **Amazon DynamoDB** and **Amazon Aurora**. This guide will walk you through configuring and using both databases, explaining everything in simple terms, and showing how you can use them within the free tier limits.

![alt text](../../../assets/images/aws/database-services.png)

---

### 1. **Sign In to AWS**
   - **Step 1**: Open the AWS website at [https://aws.amazon.com](https://aws.amazon.com).
   - **Step 2**: Log in with your AWS credentials. If you don’t have an account, you can create a free one.
   - **Step 3**: After logging in, you will be directed to the **AWS Management Console**, where you can access all AWS services.

---

### 2. **Navigate to the Database Services**

   - **Step 1**: In the AWS Management Console, search for **DynamoDB** or **Aurora** in the search bar at the top.
   - **Step 2**: Click on **DynamoDB** or **RDS** (for Aurora) under the **Database** section to start configuring your database.

---

## **Configuring and Using Amazon DynamoDB**

### What is DynamoDB?

DynamoDB is a fully managed NoSQL database service provided by AWS. It’s designed for applications that need consistent, low-latency access to data, such as mobile apps, web apps, and gaming applications. DynamoDB stores data in key-value pairs and is highly scalable, which means you can store large amounts of data and scale it easily.

DynamoDB is particularly useful for applications that require fast and predictable performance at any scale, and it works seamlessly with other AWS services.

### **Step 1: Create a DynamoDB Table**

1. **Go to the DynamoDB Console**:
   - In the **AWS Management Console**, search for **DynamoDB** and select it from the list.

2. **Create a New Table**:
   - Click on **"Create table"** in the DynamoDB dashboard.

3. **Configure Table Details**:
   - **Table Name**: Give your table a name (e.g., `MyTable`).
   - **Primary Key**: Choose a primary key for your table. The primary key can either be:
     - **Partition Key** (simple key), or
     - **Partition Key + Sort Key** (composite key).
     - For example, if you are storing user data, you might use `UserID` as the Partition Key and `Timestamp` as the Sort Key.

4. **Set Provisioned or On-demand Capacity Mode**:
   - **On-demand**: Best for beginners, as it automatically scales based on usage. You don't need to worry about setting the read and write capacity.
   - **Provisioned**: Allows you to set the read and write capacity manually, which can be useful for predictable workloads.

5. **Create Table**:
   - After entering the details, click **"Create"**. DynamoDB will create your table within seconds.

---

### **Step 2: Add Data to DynamoDB**

You can add data manually or through your application using the AWS SDKs.

1. **Manual Data Entry**:
   - Go to the **"Items"** tab of your table.
   - Click **"Create item"** to add a new record.
   - Add attributes to the item. For example:
     - **UserID**: `22610032`
     - **Name**: `Aditya Godse`
     - **Email**: `adimail2404@gmail.com`

2. **Using SDK**:
   - To add items using the AWS SDK, you can write code in Python, JavaScript, or other supported languages. Here’s an example using Python and `boto3`:
     ```python
     import boto3

     dynamodb = boto3.resource('dynamodb')
     table = dynamodb.Table('MyTable')
     table.put_item(
         Item={
             'UserID': '22610032',
             'Name': 'Aditya Godse',
             'Email': 'adimail2404@gmail.com'
         }
     )
     ```

---

### **Step 3: Retrieve Data from DynamoDB**

1. **Get Item**:
   - In the **"Items"** tab, click on the **"Get item"** button.
   - Enter the primary key (e.g., `UserID = 22610032`) to retrieve the record.

2. **Using SDK**:
   - Here’s how you can fetch a record using Python:
     ```python
     response = table.get_item(
         Key={
             'UserID': '22610032'
         }
     )
     print(response['Item'])
     ```

---

### **Step 4: Delete Data from DynamoDB**

1. **Delete Item Manually**:
   - In the **"Items"** tab, select the item you want to delete and click **"Delete"**.

2. **Using SDK**:
   - Here’s how you can delete an item using Python:
     ```python
     table.delete_item(
         Key={
             'UserID': '22610032'
         }
     )
     ```

---

### Free Tier Usage for DynamoDB

- **Free Tier Limits**: DynamoDB offers 25 GB of storage and up to 25 read and 25 write capacity units per month for free. This is sufficient for small-scale applications, and you can use it without worrying about extra costs if your usage is low.

---

## **Configuring and Using Amazon Aurora (with MySQL/PostgreSQL)**

### What is Amazon Aurora?

Amazon Aurora is a fully managed relational database service compatible with MySQL and PostgreSQL. It offers the performance and availability of high-end commercial databases, but at a lower cost. Aurora is highly scalable, reliable, and designed for demanding applications that need to process large amounts of transactional data.

### **Step 1: Create an Aurora DB Cluster**

1. **Go to the RDS Console**:
   - In the **AWS Management Console**, search for **RDS** (Relational Database Service) and select it from the list.

2. **Create a Database**:
   - Click **"Create database"** in the RDS dashboard.
   - Select **Amazon Aurora** as the database engine.

3. **Choose Database Edition**:
   - **MySQL-Compatible Edition** or **PostgreSQL-Compatible Edition**. Choose the one based on your application needs.

4. **Configure DB Cluster**:
   - **DB Cluster Identifier**: Give your Aurora DB cluster a name (e.g., `my-aurora-cluster`).
   - **Master Username**: Choose the username for your database administrator account.
   - **Master Password**: Set a password for the administrator account.
   - **Instance Type**: Choose the **db.t3.small** instance for the free trial, which offers 20 GB of storage and 750 hours of usage per month.

5. **Free Tier Usage**:
   - Aurora comes with 750 hours of free usage for db.t3.small instances and 20 GB of storage per month for the first 12 months under the AWS free tier.

6. **Launch DB Cluster**:
   - Click **"Create database"** to launch your Aurora DB cluster.

---

### **Step 2: Connect to Aurora Database**

1. **Get Database Endpoint**:
   - After the DB cluster is created, go to the **"Connectivity & security"** tab.
   - Copy the **endpoint** (hostname) of the Aurora database.

2. **Connect to the Database**:
   - Use MySQL Workbench (for MySQL) or any other database client to connect to your Aurora instance. Here’s an example of how to connect using MySQL command line:
     ```bash
     mysql -h <endpoint> -u <master_user> -p
     ```

---

### **Step 3: Use Aurora Database**

1. **Create a Database**:
   - Once connected, create a database:
     ```sql
     CREATE DATABASE mydatabase;
     ```

2. **Create Tables**:
   - Create a table to store data:
     ```sql
     CREATE TABLE users (
         UserID INT PRIMARY KEY,
         Name VARCHAR(100),
         Email VARCHAR(100)
     );
     ```

3. **Insert Data**:
   - Insert some data into the table:
     ```sql
     INSERT INTO users (UserID, Name, Email) VALUES (1, 'Aditya Godse', 'adimail2404@gmail.com');
     ```

4. **Query Data**:
   - Retrieve data from the table:
     ```sql
     SELECT * FROM users;
     ```

---

### **Step 4: Delete Data from Aurora**

1. **Delete Table**:
   - Drop the table to remove all its data:
     ```sql
     DROP TABLE users;
     ```

2. **Delete DB Cluster**:
   - If you no longer need the database, you can delete the entire DB cluster from the RDS console to stop any ongoing charges.

---

### Free Tier Usage for Aurora

- **Free Tier Limits**: Amazon Aurora offers 750 hours per month of db.t3.small instances for MySQL or PostgreSQL, along with 20 GB of storage, for the first 12 months under the free tier.

---

### Conclusion

Both **Amazon DynamoDB** and **Amazon Aurora** offer powerful, fully managed database solutions that are easy to configure and use within the AWS free tier. DynamoDB is perfect for NoSQL workloads, while Aurora is ideal for relational database applications requiring high availability and performance. By following this guide, you can start using these databases effectively without exceeding the free tier limits.
