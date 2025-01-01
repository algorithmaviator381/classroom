---
layout: default
title: 4. Networking and Security Services
parent: Cloud Computing
---

# Networking and Security Services Configuration for EC2 on AWS


In this guide, we will focus on how to configure networking and security services specifically for your **EC2 instance**. Networking and security are crucial to ensure that your EC2 instance is properly connected, secure, and accessible only by authorized users. This will build upon the **EC2 instance** we created in the previous assignment.

![alt text](../../../assets/images/aws/ec2-security-groups.png)

---

### **1. Setting Up Networking for EC2 with Virtual Private Cloud (VPC)**

Your EC2 instance resides within a **VPC (Virtual Private Cloud)**, which is essentially a private network in AWS. Understanding how to configure networking ensures that your EC2 instance can communicate both internally and externally (if needed).

#### **What is a VPC?**
- A **VPC** is a private network within AWS that lets you isolate and control network resources such as EC2 instances, databases, and storage.

#### **Steps to Set Up Networking for EC2**

1. **Access VPC Dashboard**:
   - Go to the **AWS Management Console** and search for **VPC**. Open the **VPC Dashboard** to manage your network settings.

2. **Create a VPC**:
   - If you don’t already have a VPC, you’ll need to create one. AWS automatically creates a default VPC when you sign up for an account, but you can create your own if needed. To do so:
     - Click **Create VPC**.
     - Choose a **CIDR Block** like `10.0.0.0/16`, which allows for a large number of IP addresses.
     - Optionally, choose **IPv6 CIDR Block** for IPv6 support.
     - After creating the VPC, you can proceed to configure subnets.

3. **Create Subnets**:
   - **Public Subnet**: This is where your EC2 instance will reside if it needs to be publicly accessible (e.g., for a web server). Create a subnet with an IP range like `10.0.1.0/24`.
   - **Private Subnet**: This subnet is for resources that should not be directly accessed from the internet (e.g., databases or backend services). Create a subnet like `10.0.2.0/24`.

4. **Create an Internet Gateway (IGW)**:
   - An **Internet Gateway** allows EC2 instances in the public subnet to access the internet.
   - Go to the **Internet Gateways** section, click **Create Internet Gateway**, and attach it to your VPC. This allows traffic to flow from your EC2 instance to the internet.

5. **Configure Route Tables**:
   - Go to **Route Tables** and configure a route for the **public subnet** to the **Internet Gateway**. This ensures that instances in the public subnet can access the internet.
   - Select the **public subnet**, click on **Edit routes**, and add a route for **0.0.0.0/0** with the target as your **Internet Gateway**.

---

### **2. Configuring Security Groups for EC2**

A **Security Group** acts as a firewall for your EC2 instance. It defines which inbound and outbound traffic is allowed to reach your instance. Security Groups are essential for ensuring that only authorized traffic can interact with your EC2 instance.

#### **What is a Security Group?**
- **Security Groups** control access to EC2 instances. They are stateful, meaning if you allow inbound traffic, the corresponding outbound response is automatically allowed.
- You can define rules for **SSH**, **HTTP**, **HTTPS**, and other protocols depending on your use case.

#### **Steps to Set Up Security Groups**

1. **Create a Security Group**:
   - In the **EC2 Dashboard**, go to **Network & Security** > **Security Groups**.
   - Click **Create Security Group** and provide:
     - **Name**: Give the group a meaningful name (e.g., `MyEC2SecurityGroup`).
     - **Description**: Briefly describe the group (e.g., "Security group for EC2 web server").

2. **Add Inbound Rules**:
   - You need to define which traffic is allowed to access your EC2 instance. For example:
     - **SSH (port 22)** for Linux EC2 instances (allows terminal access).
     - **HTTP (port 80)** if you are running a web server.
     - **HTTPS (port 443)** if your web server should support secure traffic.
     - For Windows EC2 instances, you would configure **RDP (port 3389)**.
     - **Source**: Set the **source** to `0.0.0.0/0` (any IP) for public access or limit it to specific IP ranges for security.

3. **Add Outbound Rules**:
   - By default, Security Groups allow all outbound traffic, so you don’t typically need to modify this unless you want to restrict outbound access (e.g., if you want to control which IP addresses can be reached from your EC2 instance).

4. **Associate the Security Group with EC2**:
   - When launching your EC2 instance (referencing the steps from the previous assignment), choose the **Security Group** you just created.
   - This ensures that only traffic defined in your security group rules will be allowed to reach the instance.

---

### **3. Network Access Control Lists (NACLs)**

While **Security Groups** act at the instance level, **NACLs** operate at the subnet level and provide an additional layer of security. They are stateless, meaning both inbound and outbound rules need to be configured separately.

#### **What is a NACL?**
- **NACLs** provide a second layer of defense by controlling traffic to and from subnets within your VPC.
- Unlike Security Groups, NACLs are stateless, meaning that if you allow inbound traffic, you must also allow the corresponding outbound traffic.

#### **Steps to Set Up NACLs**

1. **Access NACLs**:
   - In the **VPC Dashboard**, go to **Network ACLs** and click **Create Network ACL**.

2. **Add Inbound and Outbound Rules**:
   - Inbound Rules: You might allow HTTP (port 80) or SSH (port 22) from a specific IP address or a range of IPs.
   - Outbound Rules: You can allow outbound traffic to the internet or restrict it if you want to control which external resources can be accessed from your EC2 instance.
     - Example: Allow **HTTP** (port 80) from **0.0.0.0/0** (any source IP).
     - Example: Allow **SSH** (port 22) from a specific IP (e.g., `192.168.1.0/24`).

3. **Associate NACL with Subnet**:
   - After creating your NACL, you need to associate it with the **subnet** where your EC2 instance resides.
   - For example, you might associate it with the **public subnet** that houses your EC2 instance.

---

### **4. Using EC2 Security and Networking Together**

Now that we’ve covered networking and security configurations, let’s apply these concepts to the EC2 instance you created earlier.

#### **Steps to Apply Networking and Security to EC2**

1. **Launch EC2 Instance**:
   - Follow the steps from the previous assignment to launch your EC2 instance. Make sure to place it in the **public subnet** of the VPC, so it can access the internet.
   - Ensure that you choose the **Security Group** that you configured earlier during the instance launch.

2. **Testing Connectivity**:
   - After the instance is running, connect to it using **SSH** (for Linux-based instances):
     ```bash
     ssh -i "your-key.pem" ec2-user@your-public-ip
     ```
   - If you have a Windows EC2 instance, connect using **RDP**.

3. **Verify Security Rules**:
   - Ensure that you can access the EC2 instance only through the ports you allowed in the **Security Group** (e.g., SSH on port 22, HTTP on port 80).

4. **Monitor and Troubleshoot**:
   - If you face issues connecting, double-check your **Security Group** rules, **NACL** settings, and ensure your instance is in the correct subnet.

---

### **Conclusion**

In this guide, we focused on configuring the **networking and security** for your EC2 instance on AWS. By setting up **VPCs**, **Security Groups**, and **NACLs**, we ensure that your EC2 instance is properly isolated, secure, and accessible only by authorized users. These configurations are essential for maintaining control over your EC2 instance’s connectivity and security, making it a fundamental skill for managing cloud infrastructure.
