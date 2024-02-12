// Simple clock maker
// Clock start based on user time input

#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <string>

using namespace std;

// Function declaration




int main () {

    //Variables
    int hour, minute, second, userInErr, clock;

    //Initial condition value
    userInErr = 0;
    const int lineLength = 50;

    // Styling clock area
    string lineStyle (lineLength, '/'); //"-" does not work
    string spaceStyle (lineLength, ' '); 
    string clockSpaceStyle (((lineLength / 2) - 6), ' '); 

    

 
    while (userInErr == 0) {   
        cout << "Enter hour: ";
        cin >> hour;
        cout << "Enter minute: ";
        cin >> minute;
        cout << "Enter second: ";
        cin >> second;

        // if input correct then userInErr++
        // User input ask will be closed
        if (hour < 24 && minute < 60 && second < 60)
        {
        userInErr++;
        } else {
            cout << "Enter time correctly.";
        }
    }
  


    while (userInErr != 0) {
        system ("cls");

        cout << lineStyle << endl;
        cout << spaceStyle << endl;
        cout << clockSpaceStyle << hour << " : " << minute << " : " << second << endl;
        cout << spaceStyle << endl;
        cout << lineStyle << endl;
        

        // take 1 second to change and increase
        Sleep (1000);
        second++;

        if(second > 59) {
            second = 0;
            minute++;
        } 
        
        if (minute > 59) {
            minute = 0;
            hour++;
        }

        if (hour > 24) {
            hour = 0;
        }
    }


    return 0;
}



