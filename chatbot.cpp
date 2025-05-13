#include <iostream>
#include <string>
#include <queue>
#include <list>
#include <fstream>
#include <ctime>

using namespace std;



// User class
class User {
protected:
    int user_id;
    string user_name;

public:
    User() : user_id(0), user_name("") {}

    User(int id, const string& name) : user_id(id), user_name(name) {}

    void setId(int id) { user_id = id; }
    void setName(const string& name) { user_name = name; }

    int getId() const { return user_id; }
    string getName() const { return user_name; }
    
    // Add this inside the User class (public section)
  static void addUsers(list<User>& users, int& nextUserId) {
    while (true) {
        cout << "Enter user name to add (or type 'done' to finish adding users): ";
        string name;
        getline(cin, name);

        if (name == "done") {
            if (users.empty()) {
                cout << "You must add at least one user." << endl;
                continue;
            }
            break;
        }

        if (name.empty()) {
            cout << "User name cannot be empty. Try again." << endl;
            continue;
        }

        User newUser;
        newUser.setId(nextUserId++);
        newUser.setName(name);
        users.push_back(newUser);

        cout << "User '" << name << "' added with ID " << newUser.getId() << "." << endl;
    }
}

};

// Admin class inherits User
class Admin : public User {
private:
    const int Admin_ID = 911;                // Hardcoded admin ID 
    const string Admin_Name = "bruski"; // Hardcoded admin username  

public:
    Admin() : User() {}

    // Function to verify admin credentials
    bool login(int id, const string& name) {
        return (id == Admin_ID && name == Admin_Name);
    }

};

// Message class
class Message {
private:
    int sender_id;
    string sender_name;
    string content;
    time_t timestamp = time(NULL);  //current time
public:
    Message() : sender_id(0), sender_name(""), content("") {}

    Message(int id, const string& name, const string& msg)
        : sender_id(id), sender_name(name), content(msg) {}

    string getFormattedMessage() const {
        return sender_name + ": " + content + "\t\t\t" + ctime(&timestamp);
    }
    
static    string newChat(queue<Message> &messageQueue){
    	cout << "\n--- New Chat Messages ---" << endl;
        queue<Message> tempQueue = messageQueue; // copy to preserve original queue
        string chat="";
        while (!tempQueue.empty()) {
            Message msg = tempQueue.front();
            tempQueue.pop();
            chat+= msg.getFormattedMessage() +"\n";
        }
        
        return chat;
	}
};

// Back up Class
class BackUp {
    fstream File;
    string line;

public:
    BackUp() {
        File.open("backup.csv", ios::in | ios::out | ios::app);
        if (!File.is_open()) {
            cout << "\nError Accessing Backup. Please Retry!" << endl;
        }
        File.flush();
        File.seekg(0);

        if (!getline(File, line))
            File << "USER_IDs,USER_NAMES,MESSAGES,TIMESTAMPS\n";
    }

    string showBackup(list<User>& users) {
        cout << "---Old Chat Messages ---\n";
        string chathistory = "";
        // Reset file read position to beginning after header
        File.clear();
        File.seekg(0);
        // Skip header line
        getline(File, line);

        while (getline(File, line)) {
            if (line.length() <= 5) {
                cerr << "Line too short: " << line << "\n";
                continue;
            }
            
         // 1. Extract first 4 chars as id
            int id = stoi(line.substr(0, 4));   //stoi converts str into int
            string processed = line.substr(5);
        
        // chars till 2nd comma are string name
        // Extract name before processing commas
        size_t commaPos = processed.find(',');
        string name ;
		if (commaPos != string::npos) 
		   name = processed.substr(0, commaPos) ;
		else
		   name = processed;
		   
		   
	// Check if id exists in users
        bool exists = false;
        for (const auto& user : users) {
            if (user.getId() == id) {
                exists = true;
                break;
            }
        }
        // 5. If not, add to users
        if (!exists) {
            users.push_back(User(id, name));
        }
   //show bavckup:
            int commaCount = 1;  // as 1st ',' is handled already above
            for (size_t i = 0; i < processed.length(); ++i) {
                if (processed[i] == ',') {
                    ++commaCount;
                    if (commaCount == 2) {
                        processed.replace(i, 1, " : ");
                        i += 2;
                    }
                    else if (commaCount == 3) {
                        processed.replace(i, 1, "\t\t\t");
                        i += 2;
                    }
                }
            }
            chathistory += processed + "\n";
        }
        return chathistory;
    }

    void storeBackup(int id, const string& name, const string& msg, time_t timestamp = time(NULL)) {
        if (msg.empty()) {
            cerr << "No msg found" << endl;
            return;
        }
        if (File.is_open()) {
            File.clear();
            File.seekp(0, ios::end); // Move write pointer to end
            File << id << "," << name << "," << msg << "," << ctime(&timestamp);
            // ctime adds a newline already
        }
        else {
            cerr << "Error: File not open" << endl;
        }
    }

    ~BackUp() {
        if (File.is_open())
            File.close();
    }
};

int main() {
    list<User> users;
    queue<Message> messageQueue;
    bool running = true;
    Admin admin;
    BackUp backup;
    int nextUserId;
    if (!users.empty()){
    	for (const auto& user : users) 
          nextUserId = user.getId();
	} else {
	     nextUserId = 1769; // To assign unique user IDs

	}

    cout << "\t\t\t\tWelcome to the TerBot\n\t\t\tYour handy candy Terminal Chat System!" << endl;

    // Admin login
    cout << "\n\n\nHello my friend, are u my Admin??\n Login and add your buddies!\n" << endl;

    int uid;
    string u_name;

    cout << "\t\t\tUser_ID=  ";
    cin >> uid;
    cout << "\t\t\tUser_Name=  ";
    cin >> u_name;
    cin.ignore(); // clear newline

    if (!admin.login(uid, u_name)) {
        cout << "Invalid admin credentials! Access denied." << endl;
        return 0; // Exit program if login fails
    }

    //  clear screen to maintain scecrecy of admin credentials from other members
    system("cls");

    int adm_choice;
    cout << "\t\t\t\tWelcome to the TerBot\n\t\t\tYour handy candy Terminal Chat System!\n" << endl;

    cout << "Welcome, " << u_name << "! How would you like to cherish your power?" << endl;
    cout << "\t\t1. Show me all previous chats??\n\t\t2. Add to my Family ??\n\t\t3. Exit.\n\nPlease, select the desired index: ";
    cin >> adm_choice;
    cin.ignore();

    switch (adm_choice) {
    case 1: {
        string chatHistory = backup.showBackup(users);
        if (chatHistory=="") 
		cout <<endl<< "No backup found!"  <<endl ;
		// If no users added yet (and admin chose to show chats), prompt to add users anyway
         if (users.empty()) {
              cout << "\nNo users found. You need to add users to chat.\n" << endl;
              User::addUsers(users,nextUserId);
    }else{
		cout << chatHistory<<endl;
        cout << "\nUsers from ChatHistory are:" << endl;
        for (const auto& user : users) {
            cout <<user.getId() << ". " << user.getName() << endl;
        }
        
        cout<<"\nDo you want to add more users\n\t\t1. Yes\n\t\t2. No\n Please select a valid index"<<endl;
        int case2;
        cin>>case2;
        if (case2==1)
         // Admin adds users
        User::addUsers(users,nextUserId) ;
        
        else if (case2==2){
        	cout<<"As u order bruski !\nContinuing to Chat Room ...."<<endl;
		}}
        break;
    }
    case 2: {
        // Admin adds users
       User::addUsers(users,nextUserId) ;
	    
        break;
    }
    case 3:
        cout << "Exiting program. Goodbye!" << endl;
        return 0;
    default:
        cout << "Invalid choice. Exiting." << endl;
        return 0;
    }

    

    // Main chat loop
    while (running) {
        cout << "\nUsers:" << endl;
        for (const auto& user : users) {
            cout << user.getId() << ". " << user.getName() << endl;
        }
        cout << "0. Exit\n";

        cout << "Select user by ID to send a message: ";
        int userChoice;
        cin >> userChoice;
        cin.ignore(); // clear newline character from input buffer

        if (userChoice == 0) {
            running = false;
            cout << "Exiting chat. Goodbye!" << endl;
            break;
        }

        // Find user by ID in the list
        User* currentUser = nullptr;
        for (auto& user : users) {
            if (user.getId() == userChoice) {
                currentUser = &user;
                break;
            }
        }

        if (currentUser == nullptr) {
            cout << "Invalid user ID. Try again." << endl;
            continue;
        }

        cout << currentUser->getName() << ", enter your message: ";
        string messageText;
        getline(cin, messageText);

        if (messageText.empty()) {
            cout << "Empty message. Try again." << endl;
            continue;
        }

        // Add message to backup
        backup.storeBackup(currentUser->getId(), currentUser->getName(), messageText);

        // Add message to queue
        messageQueue.push(Message(currentUser->getId(), currentUser->getName(), messageText));

        // Display all messages in the queue
        Message::newChat(messageQueue);
        cout << "---------------------" << endl;
    }

    return 0;
}