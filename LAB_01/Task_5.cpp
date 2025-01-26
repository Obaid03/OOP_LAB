#include <iostream>
using namespace std;

struct event {
    char name[50];
    char date[11];
    char venue[50];
    char organizer[50];
};

int main() {
    int n,i,j,choice,found=0;
    cout << "Enter the total number of events: ";
    cin >> n;
    event* events = new event[n];

    for (i = 0; i < n; i++) {
        cout << "\nEnter details for event " << i + 1 << ":\n";

        cout << "Event Name (max 50 characters): ";         cin >> events[i].name;
        cout << "Date (DD-MM-YYYY): ";                      cin >> events[i].date;
        cout << "Venue (max 50 characters): ";              cin >> events[i].venue;
        cout << "Organizer (max 50 characters): ";          cin >> events[i].organizer;
    }

    while (1) {
        cout << "\nEvent Management System Menu:\n";
        cout << "1. Display all events\n";
        cout << "2. Search for events by date\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "\nAll Events:\n";
            for (i = 0; i < n; i++) {
                cout <<"\nEvent "<<i+1<<":\n";
                cout <<"Name: "<<events[i].name<<endl;
                cout <<"Date: "<<events[i].date<<endl;
                cout <<"Venue: "<<events[i].venue<<endl;
                cout <<"Organizer: "<<events[i].organizer<<endl;
            }
            break;
        } else if (choice == 2){
            char search[11];
            cout << "\nEnter the date to search for events (DD-MM-YYYY): ";
            cin >> search;
            cout << "\nEvents on " << search<< ":\n";
            for (i = 0; i < n; i++) {
                int equal = 1;
                for (j = 0; j < 10; j++) {
                    if (events[i].date[j] != search[j]) {
                        equal = 0;
                        break;
                    }
                }
                if (equal) {
                    found = 1;
                    cout << "\nEvent " << i + 1 << ":\n";
                    cout << "Name: " << events[i].name << endl;
                    cout << "Venue: " << events[i].venue << endl;
                    cout << "Organizer: " << events[i].organizer << endl;
                }
            }
            if (!found) {
                cout << "No events found on this date.\n";
                break;
            }
        }
        else {
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    }
delete[] events;

    return 0;
}
