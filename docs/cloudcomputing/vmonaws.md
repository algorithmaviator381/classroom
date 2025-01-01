---
layout: default
title: 1. Virtual Machine on AWS
parent: Cloud Computing
---

# How to Launch Your Virtual Machine (VM) on AWS

Before moving on with this, [here](https://aws.amazon.com/getting-started/launch-a-virtual-machine-B-0/) is a good tutorial by AWS with step-by-step guide that will help you successfully launch a Linux virtual machine on Amazon EC2 within their Free Usage Tier.

1. **Sign In to AWS**:
   - Open the AWS website and log in to your account. (If you don’t have one, you can create a free account).

2. **Find EC2 Service**:
   - After logging in, go to the **EC2 Dashboard**. EC2 is the part of AWS where you manage virtual machines.

3. **Launch a New EC2 Instance**:
   - Click on **"Launch Instance"**. This starts the process of creating your virtual machine.
   - Give your instance a name (e.g., "MyFirstVM").

4. **Choose Your Operating System**:
   - You need to choose an operating system for your virtual machine. You can select:
     - **Ubuntu** or **Amazon Linux 2** for Linux-based systems.
     - **Windows Server** if you want a Windows VM.

5. **Pick the Right Instance Type**:
   - For beginners, choose **t2.micro** or **t3.micro** as they are free to use with the AWS free tier.

6. **Configure Your Instance**:
   - Use the default settings for now (or you can change them if you know what you’re doing).
   - Make sure the "Auto-assign Public IP" option is turned on. This allows you to access your VM from the internet.

7. **Add Storage**:
   - You’ll be given 8 GB of storage by default, which is enough for basic tasks. You can increase the size if needed.

8. **Set Up Security Group**:
   - A **Security Group** is like a firewall. You need to set rules for what can connect to your VM.
   - For basic access, enable:
     - **SSH** (for Linux) on port 22.
     - **RDP** (for Windows) on port 3389.

9. **Review and Launch**:
   - Check everything one last time and click **"Launch"**.
   - You’ll be asked to create a **key pair** (a secure login file). Download this file and keep it safe.

---

### **Configuring Your Virtual Machine After Launch**

Once your VM is running, follow these steps to set it up:

#### 1. **Connect to Your VM**:
   - For Linux: Use **SSH** to connect from your terminal:
     ```
     ssh -i "your-key.pem" ec2-user@your-public-ip
     ```
   - For Windows: Use **RDP** (Remote Desktop) to connect.

#### 2. **Update the Operating System**:
   - For Linux (Ubuntu or Amazon Linux):
     ```
     sudo apt update && sudo apt upgrade -y  # For Ubuntu
     sudo yum update -y  # For Amazon Linux
     ```
   - For Windows, go to **Settings** and update the system.

#### 3. **Install Important Tools**:
   - For Linux:
     ```
     sudo apt install -y git curl wget  # Ubuntu
     sudo yum install -y git curl wget  # Amazon Linux
     ```
   - For Windows, download programs like Google Chrome or Visual Studio Code.

#### 4. **Add New Users and Set Permissions** (Optional):
   - You can create new users and give them specific permissions, like admin access:
     ```
     sudo adduser newuser
     sudo usermod -aG sudo newuser
     ```

#### 5. **Set Firewall Rules** (Optional):
   - You can change the security group settings to allow specific services like **HTTP** (for websites) or **HTTPS** (for secure websites).

#### 6. **Test Your Connection**:
   - Try **pinging** the VM or connect using SSH/RDP to ensure everything is working.

#### 7. **Install Optional Software**:
   - If you want to set up a **web server** (like Apache), run:
     ```
     sudo apt install apache2 -y  # Ubuntu
     sudo yum install httpd -y  # Amazon Linux
     ```
   - You can also install **MySQL** or other software as needed.

---

This experiment helps you learn the basics of using cloud virtual machines, which is important for more advanced cloud computing tasks.
