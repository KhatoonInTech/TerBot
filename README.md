
<div align="center">
  <h1>TerBot - A Robust Terminal Chat System</h1>
  <a class="header-badge" target="_blank" href="https://www.linkedin.com/in/khatoonintech/">
  <img src="https://img.shields.io/badge/style--5eba00.svg?label=LinkedIn&logo=linkedin&style=social">
  </a>
  

<sub>Author:
<a href="https://www.linkedin.com/in/Khatoonintech/" target="_blank">Ayesha Noreen</a><br>
<small> <i>#KhatoonInTech CE' 27 @BZU |Agentic AI & Automation Engr @ DevRolin | ByteWise Certified ML/DL Engineer|GSoC Contributor | SWEfellow: Confiniti. ,HeadStarterAI</i> </small>
</sub>
<br>
<br>
<br>

 ![portal ](../main/images/portal.png)

</div>

---


# 🤖 TerBot - Terminal Chat System

TerBot is a terminal-based chat system written in C++. It simulates a basic chatroom where an admin can manage users and maintain a persistent message history using a backup CSV file. This system demonstrates object-oriented programming with classes like `User`, `Admin`, `Message`, and `BackUp`.

---
## Table of Contents

1. [Overview](#overview)
2. [Features](#features)
3. [Installation & Running Locally](#installation--running-locally)
4. [Class and Function Descriptions](#class-and-function-descriptions)

   * [User Class](#user-class)
   * [Admin Class](#admin-class)
   * [BackUp Class](#backup-class)
5. [File Structure](#file-structure)
6. [Backup File Format](#backup-file-format)
7. [Error Handling](#error-handling)
8. [Author](#author)

---

## Overview

This C++ program implements a **terminal-based chatbot system** that simulates a chatroom. It includes a simple user management system (admin + users), message backup functionality, and chat history retrieval. Data is persisted via a CSV file.

## Features

* User registration and editing
* Admin login with hardcoded credentials
* Chatroom functionality (not fully visible in provided snippet)
* Persistent message storage (`backup.csv`)
* View, edit, and delete messages and users
---

## Installation & Running Locally

1. **Clone or download** this repository to your local machine.

2. **Open terminal** and navigate to the folder containing `chatbot.cpp`

3. **Compile the code** using any C++ compiler like `g++`:

   ```bash
   g++ -o chatbot chatbot.cpp
   ```

4. **Run the executable**:

   ```bash
   ./chatbot
   ```

> **Note:** Ensure the program can create or access a file named `backup.csv` in the same directory.

---
## Class and Function Descriptions

### User Class

**Purpose**: Handles user attributes and user-related operations.

#### Attributes:

* `user_id`: Unique identifier for the user.
* `user_name`: Name of the user.

#### Methods:

* `setId(int id)`, `setName(string name)`: Set user details.
* `getId()`, `getName()`: Retrieve user details.
* `addUsers(list<User>&, int&)`: Prompts and adds users.
* `viewUsers(list<User>&)`: Displays active users.
* `deleteUser(list<User>&)`: Deletes user and associated backup data.
* `editUser(list<User>&)`: Edits username and updates backup.

---

### Admin Class

**Inherits From**: `User`

#### Purpose:

Represents the admin account with elevated permissions.

#### Attributes:

* `Admin_ID = 911`: Hardcoded admin ID
* `Admin_Name = "bruski"`: Hardcoded admin name

#### Methods:

* `login(int, string)`: Verifies admin login.
* `AdminPermissions(string)`: Displays admin control panel menu (UI only).

---

### BackUp Class

**Purpose**: Responsible for reading, writing, deleting, and editing chat backups.

#### Static Members:

* `File`: File stream for `backup.csv`
* `file`: Temporary file stream for editing/deleting
* `line`: Used for reading line-by-line from CSV

#### Constructor:

* Opens the `backup.csv` file. Adds a header if it's empty.

#### Methods:

* `showBackup(list<User>&)`: Reads all chat history and reconstructs missing users.
* `storeBackup(int, string, string, time_t)`: Saves chat/message to CSV.
* `deleteBackup(int)`: Removes all rows associated with a given `user_id`.
* `editBackup(int, string)`: Updates username in backup.
* Destructor: Closes file.

---

## File Structure

```
project-root/
├── chatbot.cpp         # Source file
├── backup.csv          # Auto-generated CSV log
└── chatbot             # Output binary after compilation
```

---

## Backup File Format

The `backup.csv` contains chat log entries with the format:

```
USER_IDs,USER_NAMES,MESSAGES,TIMESTAMPS
0001,John Doe,Hello!,Thu May 15 11:13:20 2025
```

> The system will recreate missing users if their ID and name appear in this file.

---

## Error Handling

* Validates input for user creation (no empty names).
* Checks for malformed or short lines in CSV.
* Handles file access failures with error messages.
* Uses try-catch blocks for parsing safety (especially in `deleteBackup()` and `editBackup()`).

---

## Author

Built by an aspiring C++ developer as part of a terminal-based chatbot management system.

---

**Tip**: If you wish to expand the system, consider:

* Adding chat functionality between users.
* Password protection for admin login.
* Encrypting the backup file or switching to a database.

---


## License

This project is licensed under the [MIT License](LICENSE).


---

<div align="center">
<h3>For any query/help ,please contact our developer:</h3>  
Developer : <a href="https://www.linkedin.com/in/Khatoonintech/" target="_blank">Ayesha Noreen</a><br>
   <small> ByteWise Certified ML/DL Engineer|GSoC Contributor | SWEfellow: Confiniti. ,HeadStarterAI </small>
<br> <a href="https://www.github.com/Khatoonintech/" target="_blank"> Don't forget to ⭐ our repo </a><br>


</div>

