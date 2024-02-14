#include <iostream>
#include <iomanip>
#include <stdlib.h>

using namespace std;



void menu (int Qrooms, int Qpasta, int Qburger, int Qnoodles, int Qshake)
{
    int quwant, choice;
    // Sold items
    int Srooms = 0, Spasta = 0, Sburger = 0, Snoodles = 0, Sshake = 0;
    // Total number of items price
    int Trooms = 0, Tpasta = 0, Tburger = 0, Tnoodles = 0, Tshake= 0;


    do
    {
        system ("cls");
        cout << "Please select from the menu options" << endl;
        cout << "1. Rooms" << endl;
        cout << "2. Pasta" << endl;
        cout << "3. Burger" << endl;
        cout << "4. Noodles" << endl;
        cout << "5. Shake" << endl;
        cout << "6. Information regarding sales and collection" << endl;
        cout << "7. Exit" << endl << endl;

        cout << "Please enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter number of rooms you want: ";
            cin >> quwant;
            
            if (Qrooms - Srooms >= quwant)      
            {   
                Srooms += quwant;
                Trooms += quwant * 1200; //1200 is the price of single room
                cout << "Room/rooms have been alloted to you!" << endl;
            }
            else
            {
                cout << Qrooms - Srooms << " " << "Rooms remaining in hotel." << endl;
            }
    
            break;
        
        case 2:
            cout << "Enter pasta quantity: ";
            cin >> quwant;
            
            if (Qpasta - Spasta >= quwant)      
            {   
                Spasta += quwant;
                Tpasta += quwant * 200; 
                cout << quwant << "Pasta ordered!" << endl;
            }
            else
            {
                cout << Qpasta - Spasta << " " << "Pasta remaining in kitchen." << endl;
            }
    
            break;

        case 3:
            cout << "Enter burger quantity: ";
            cin >> quwant;
            
            if (Qburger - Sburger >= quwant)      
            {   
                Sburger += quwant;
                Tburger += quwant * 150; 
                cout << quwant << "Burger ordered!" << endl;
            }
            else
            {
                cout << Qburger - Sburger << " " << "Burger remaining in kitchen." << endl;
            }
    
            break;

        case 4:
            cout << "Enter noodles quantity: ";
            cin >> quwant;
            
            if (Qnoodles - Snoodles >= quwant)      
            {   
                Snoodles += quwant;
                Tnoodles += quwant * 300; 
                cout << quwant << "Noodles ordered!" << endl;
            }
            else
            {
                cout << Qnoodles - Snoodles << " " << "Noodles remaining in hotel." << endl;
            }

            break;

        case 5:
            cout << "Enter shake quantity: ";
            cin >> quwant;
            
            if (Qshake - Sshake >= quwant)      
            {   
                Sshake += quwant;
                Tshake += quwant * 50;
                cout << "Shake ordered!" << endl;
            }
            else
            {
                cout << Qshake - Sshake << " " << "Shake remaining in hotel." << endl;
            }

            break;

        case 6:
            cout << "Details of sales and collection: " << endl;

            cout << "Collection of remaining quantity: " << endl;
            cout << "Rooms: " << Qrooms << endl;
            cout << "Pasta: " << Qpasta << endl;
            cout << "Burger: " << Qburger << endl;
            cout << "Noodles: " << Qnoodles << endl;
            cout << "Shake: " << Qshake << endl;

            cout << "Collection of sales: " << endl;
            cout << "Rooms: " << Srooms << endl;
            cout << "Pasta: " << Spasta << endl;
            cout << "Burger: " << Sburger << endl;
            cout << "Noodles: " << Snoodles << endl;
            cout << "Shake: " << Sshake << endl;

            cout << "Total amount of each item: " << endl;
            cout << "Rooms: " << Trooms << endl;
            cout << "Pasta: " << Tpasta << endl;
            cout << "Burger: " << Tburger << endl;
            cout << "Noodles: " << Tnoodles << endl;
            cout << "Shake: " << Tshake << endl;

            cout << "Total amount: " << endl;
            cout << Trooms + Tpasta + Tburger + Tnoodles + Tshake << endl;

            break;

        case 7:
            exit(0);

        default:
            cout << "Please select the numbers mentioned above!" << endl;
        }
    } while (true);
   
}



int main () 
{
   
    // Quantity
    int Qrooms = 0, Qpasta = 0, Qburger = 0, Qnoodles = 0, Qshake = 0;
 
    cout << setw (55) << "Quantity of items we have" << endl;
    cout << setfill ('-') << setw (100);
    cout << "\nRooms avaiable: ";
    cin >> Qrooms;
    cout << "Quantity of pasta: ";
    cin >> Qpasta;
    cout << "\nQuantity of burger: ";
    cin >> Qburger;
    cout << "\nQuantity of noodles: ";
    cin >> Qnoodles;
    cout << "\nQuantity of shake: ";
    cin >> Qshake;

    menu (Qrooms, Qpasta, Qburger, Qnoodles, Qshake);

    

    return 0;

}



