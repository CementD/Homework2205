#include "BusPark.h"
#include <conio.h>
#include <Windows.h>

int main() {
    BusPark park;
    while (true) {
        system("cls");
        showMenu();
        cout << "Enter your choice";
        char choice = _getch();
        switch (choice) {
        case '1': {
            system("cls");
            Bus bus;
            cout << "Enter bus number: ";
            cin >> bus.busNumber;
            cout << "Enter driver's last name: ";
            cin >> bus.driverLastName;
            cout << "Enter driver's first name: ";
            cin >> bus.driverFirstName;
            cout << "Enter route number: ";
            cin >> bus.routeNumber;
            cout << "Enter seat count: ";
            cin >> bus.seatCount;
            park.insertBus(bus);
            system("pause");
            break;
        }
        case '2': {
            system("cls");
            int busNumber;
            cout << "Enter bus number to search: ";
            cin >> busNumber;
            TreeNode* foundBus = park.searchBus(busNumber);
            if (foundBus) {
                cout << "Bus found: " << endl;
                cout << "Bus Number: " << foundBus->bus.busNumber << ", Driver: " << foundBus->bus.driverLastName << " " << foundBus->bus.driverFirstName
                    << ", Route Number: " << foundBus->bus.routeNumber << ", Seat Count: " << foundBus->bus.seatCount << endl;
            }
            else {
                cout << "Bus not found." << endl;
            }
            system("pause");
            break;
        }
        case '3': {
            system("cls");
            cout << "Displaying all buses: " << endl;
            park.displayBuses();
            system("pause");
            break;
        }
        case '4': {
            system("cls");
            string filename;
            cout << "Enter filename to save to: ";
            cin >> filename;
            park.saveToFile(filename);
            cout << "Buses saved to file." << endl;
            break;
        }
        case '5':
            system("cls");
            cout << "Exiting..." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
            Sleep(1000);
        }
    }

    return 0;
}


