
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

## 📁 Project Structure

```

khatoonintech-terbot/
├── backup.csv         # Stores all chat history (ID, Name, Message, Timestamp)
├── chatbot.cpp        # Main source code file
└── chatbot.exe        # Compiled executable (Windows only)

````

---

## 🚀 Features

- 👤 **User Management**  
  - Add multiple users dynamically.
  - Unique ID assignment for each user.
  
- 🛡️ **Admin Control**  
  - Secure login using hardcoded credentials (`ID: 911`, `Name: bruski`).
  - Admin can view previous chat history and add users.

- 💬 **Real-time Chat**  
  - Users can send messages to the terminal.
  - Chat displayed live in queue format.

- 💾 **Persistent Backup**  
  - All messages are saved in `backup.csv`.
  - On re-launch, TerBot loads and displays previous conversations.

---

## 🛠️ How to Use

### 🧱 Compile (Linux/macOS)
```bash
g++ chatbot.cpp -o chatbot
./chatbot
````

### 🧱 Compile (Windows)

```cmd
g++ chatbot.cpp -o chatbot.exe
chatbot.exe
```

### ✅ Run

1. Launch the executable.
2. Log in as admin using:

   ```
   User_ID: 911
   User_Name: bruski
   ```
3. Choose an action:

   * View old chats and add users.
   * Directly add users.
4. Begin the chat session.

---

## 🧑‍💻 Code Overview

* **`User`**: Base class for all users.
* **`Admin`**: Derived class with fixed credentials.
* **`Message`**: Handles content and formatting of chat.
* **`BackUp`**: Stores and retrieves message history from `backup.csv`.

---

## 🗃️ Sample Backup File (backup.csv)

```
1769,Ayesha,Assalam O Alaikum,Tue May 13 23:06:01 2025
1770,Abeeha,Walaikum Assalam,Tue May 13 23:07:04 2025
...
```

---

## 📌 Future Improvements

* Add encryption for message and credential security.
* Support multiple chatrooms.
* GUI integration with Qt/GTK.

---

## 🧾 License

This project is open-source and available under the MIT License.

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

