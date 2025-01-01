---
layout: default
title: Deploy an app on AWS
parent: Cloud Computing
nav_order: 1
has_children: true
---

# Web Application for Managing Study Materials

## **Overview**
We are building a web application designed for students to manage their study materials. This app will allow users to create, organize, and manage lists of resources they want to revisit, such as website URLs, notes, or topics they plan to study. Users will also be able to tag their resources, set due dates, and categorize them for better organization.

This application will be built using **Flask**, a lightweight Python web framework, and will integrate with multiple **AWS services** to leverage cloud functionalities.

---

## **Core Features**

1. **User Features**:
   - Create, read, update, and delete (CRUD) study material lists.
   - Add metadata to each resource (tags, due dates, notes, etc.).
   - Store and retrieve website URLs or general notes.
   - Upload images or files as part of their study material.

2. **Backend Features**:
   - Flask will handle user requests, manage the application logic, and provide RESTful APIs.

3. **Storage**:
   - Files and images uploaded by users will be stored in **AWS S3**.
   - All lists and metadata will be stored in a relational database managed by **Amazon RDS**.

---

## **AWS Services Integration**

1. **Amazon Relational Database Service (RDS)**:
   - **Purpose**: Store user data, such as lists, tags, and metadata.
   - **Details**:
     - Database: MySQL/PostgreSQL.
     - Free Tier: 750 hours of db.t2.micro instance and 20 GB of storage.
     - Integration: Flask will connect to the RDS instance using an ORM like `SQLAlchemy`.

2. **AWS S3**:
   - **Purpose**: Store user-uploaded images and files.
   - **Details**:
     - Free Tier: 5 GB of storage.
     - Integration: Flask will use the Boto3 library to upload and retrieve files.
     - Security: Set up proper IAM roles to secure file access.

---

## **Architecture**

1. **Frontend**:
   - Flask will serve HTML templates or integrate with a modern frontend framework (React, optionally).

2. **Backend**:
   - Flask will handle API requests and server-side logic.

3. **Database**:
   - Amazon RDS will store structured data (lists, tags, metadata).

4. **Storage**:
   - AWS S3 will handle static file storage (images, documents).

5. **Deployment**:
   - Deploy Flask on **AWS Elastic Beanstalk** or **AWS Lambda**.
   - Use **AWS CloudWatch** for monitoring.

---

## **Work**

### **Storage Configuration**
- **Task**: Store and retrieve files using Amazon S3 and EBS.
- **Free Tier**: Includes 5 GB of S3 storage and 30 GB of EBS.

### **Database Configuration**
- **Task**: Configure and use a database on Amazon RDS.
- **Free Tier**: 750 hours of db.t2.micro instance and 20 GB of storage.

### **Networking and Security Services**
- **Task**: Configure Security Groups, VPC, and other networking settings.
- **Free Tier**: Basic configurations are covered under the free tier.

### **High Availability and Scalability**
- **Task**: Experiment with Elastic Load Balancer and Auto Scaling.
- **Free Tier**: Limited resources are available for these features.

---

## **Conclusion**
Using Flask, you can build a robust web app integrated with AWS services like RDS & S3 to meet the requirements of your project. Additionally, you can explore optional AWS tasks like setting up virtual machines, configuring storage, and experimenting with networking features, all within the free tier.
