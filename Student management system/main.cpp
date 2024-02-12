// Student Record Management System

#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <conio.h> 


using namespace std;

// methods
void adminVerf();
void mainMenu();
void adminFunc();
void addStudent_details();
void deleteStudent();
void viewTable();





void mainMenu(){

     int choice;

    // Will appear
    cout << "Login as:" << endl;
    cout << "1. Admin" << endl;
    cout << "2. Student" << endl;
    cout << "3. Exit" << endl;

    cout << "Enter your choice: ";
    cin >> choice;

    //Select verification based on choice

    switch (choice)
    {
    case 1:
        adminVerf ();
        break;
    
    case 2:
     
        break;

    case 3:
      
        break;
    }

}


// Admin verification process

void adminVerf () {
    string password;

    cout << "Enter your password:";

    do
    {
        cin >> password;

        if (password != "pass") {
            cout << "Wrong passcode! try again or type q to quit the program." << endl;
            cout << "Enter your password:";
        }

        if (password == "q") {
            cout << "Quiting the program..." << endl;

            for (int i = 0; i < 3; i++)
            {
                // 1 second pause
                Sleep(1000); 
                cout << ".";
            }
            
            exit (0);
        }

        if (password == "pass") {
            adminFunc ();
        }

    } while (password != "pass");

    mainMenu(); //call if user quit
}


// Admin function: admin can do all

void adminFunc () {
    int adminFunc_Select;
    cout << "Welcome Admin!" << endl;
    
    cout << "1. Add student details" << endl;
    cout << "2. Delete student" << endl;
    cout << "3. View table" << endl;
    cout << "5. Exit" << endl;

    cout << "Enter your choice: ";
    cin >> adminFunc_Select;

    switch (adminFunc_Select)
    {
    case 1:
        addStudent_details ();
        break;

    case 2:
        deleteStudent ();
        break;

    case 3:
        viewTable ();
        break;

    case 4:
        mainMenu ();
        break;

    case 5:
        mainMenu ();
        break;

    }

    
}


// Admin func: add student details

void addStudent_details () {
    //open file and add data at the end
   fstream fs;
   fs.open("test.txt", fstream::out | fstream::app);

    if(!fs.is_open ()) {
        
        char switch_to_back;

        cout << "Failed to open / file does not exist!" << endl;
        cout << "Write b to go Admin Function list or m to go Main menu: ";
        cin >> switch_to_back;
        
        // Go back and start again
        switch (switch_to_back)
        {
        case 'b':
            adminFunc ();
            break;

        case 'm':
            mainMenu ();
            break;
        
        default: 
            cout << "Choose between b or m"; 
            break;
        }  

    } else {
        cout << "\t\t\t | Enter Data |" << endl << endl;

        struct
        {
            int studentRoll, attdPerc;
            string stdName;
        } studentDataVar;


        cout << "Enter student's roll number: ";
        cin >> studentDataVar.studentRoll;
        fs << studentDataVar.studentRoll << "," << "\t";
        
        cout << "Enter student's name: ";
        cin >> studentDataVar.stdName;
        fs << studentDataVar.stdName << "," << "\t";

        cout << "Enter student's attendence percentage: ";
        cin >> studentDataVar.attdPerc;
        fs << studentDataVar.attdPerc << endl;
        

            
        //File close
        fs.close ();
        cout << "Data entered and file closed." << endl << endl << endl;

        // Return to admin funtion list
        adminFunc();
    }

}



 // Admin func: delete student details

void deleteStudent () {

    fstream fs;
    fs.open("test.txt");

  
}



 
 // Admin func: view student details

void viewTable () {

    fstream fs;
    fs.open("test.txt", fstream::in);

    if(!fs.is_open ()) {

        cout << "Failed to open the file!" << endl;

    } else {


        string myData;

        cout << "\t\t\t | Students records |" << endl << endl;
        cout << "-------------------------------------------------------------------------------" << endl;

        while (getline(fs, myData)) // loop work till end-of-file reached
        {
            cout << myData << endl;
            cout << endl;
        }

        cout << "-------------------------------------------------------------------------------" << endl;

        //File close
        fs.close ();

        //Call admin function list  
        adminFunc ();
    }
  
}



int main() {
    mainMenu();
   
    return 0;
}