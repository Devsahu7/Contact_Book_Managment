#include <iostream>
#include <vector>
using namespace std;

struct detail {
    string name;
    string phone;
    string email;
};

vector<detail> datatype;

void addContact() {
    detail d;

    cout << "Enter Name: ";
    cin >> d.name;

    cout << "Enter Phone: ";
    cin >> d.phone;

    cout << "Enter Email: ";
    cin >> d.email;

    datatype.push_back(d);
    cout << "Contact added successfully!\n\n";
}

void viewContacts() {
    if (datatype.empty()) {
        cout << "No contacts found.\n\n";
        return;
    }

    cout << "\nContact List:\n";
    for (int i = 0; i < datatype.size(); i++) {
        cout << i + 1 << ". "
             << datatype[i].name << " | "
             << datatype[i].phone << " | "
             << datatype[i].email << endl;
    }
    cout << endl;
}

void searchContact() {
    string searchName;
    cout << "Enter name to search: ";
    cin >> searchName;

    bool found = false;

    for (auto &d : datatype) {
        if (d.name == searchName) {
            cout << "Found: "<< d.name << " | "<< d.phone << " | "<< d.email << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Contact not found.\n";
    }
    cout << endl;
}

void deleteContact() {
    string name;
    cout << "Enter name to delete: ";
    cin >> name;

    for (int i = 0; i < datatype.size(); i++) {
        if (datatype[i].name == name) {
            datatype.erase(datatype.begin() + i);
            cout << "Contact deleted successfully!\n\n";
            return;
        }
    }
    cout << "Contact not found.\n\n";
}
int main() {
    int choice;

    while (true) {
        cout << "==== Contact Book ===="<<endl;
        cout << "1. Add Contact"<<endl;
        cout << "2. View Contacts"<<endl;
        cout << "3. Search Contact"<<endl;
        cout << "4. Delete Contact"<<endl;
        cout << "5. Exit"<<endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addContact(); break;
            case 2: viewContacts(); break;
            case 3: searchContact(); break;
            case 4: deleteContact(); break;
            case 5:cout << "Exiting..."<<endl;
                   return 0;
            default:
                cout << "Invalid choice!"<<endl<<endl;
        }
    }

    return 0;
}
