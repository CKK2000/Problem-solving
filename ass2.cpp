// Problem Statement#2:  

// State Electricity Board has started automation of their working and in first phase of development they want to automate following task: 

// Create a list of complaints with “unique complaint Id”. 

// Add a new complaint if the call centre receives a new complaint with the details like unique complaint id, service number, address, contact number, etc. 

// Search for complaint by complaint id. 

// Display the list of all complaints.  

// Remove complaints, if a complaint has been resolved by the service team.  

// Send a message to the superintendent if there are more than 5 complaints.




#include <iostream>
#include <string>
#include <vector>

using namespace std;

//this struct will hold complaint details
struct Complaint {
    int complaintId;
    
    string serviceno;
    string address;
    string contactno;

 // Constructor to initialize the complaint
    Complaint(int id, const string& sn, const string& addr, const string& cn)
        : complaintId(id), serviceno(sn), address(addr), contactno(cn) {}
};

class ComplaintManagement {
private:
    vector<Complaint> complaints;

public:
    // Fn to generate unique complaint ID
    int generateUniqueId() {
        static int id = 1;
        return id++;
    }

    // Fn to add a new complaint
    void addComplaint(const string& serviceno, const string& address, const string& contactno) {
        int complaintId = generateUniqueId();
        complaints.push_back(Complaint(complaintId, serviceno, address, contactno));
        cout << "Yahooo! Complained add successful"<<endl;
    }

    // Fn to search for a complaint by ID
    void searchComplaintById(int id) {
        for (const auto& complaint : complaints) {
            if (complaint.complaintId == id) {
                cout << "Complaint no: " << complaint.complaintId << ", Service no: " << complaint.serviceno
                     << ", Address: " << complaint.address << ", Contact no: " << complaint.contactno << endl;
                return;
            }
        }
        cout << "Complaint not found!" << endl;
    }

    // Fn to display all complaints
    void displayAllComplaints() {
        for (const auto& complaint : complaints) {
            cout << "Complaint no: " << complaint.complaintId << ", Service no: " << complaint.serviceno
                 << ", Address: " << complaint.address << ", Contact no: " << complaint.contactno << endl;
        }
    }

    // Fn to remove a complaint by ID (assuming complaint is resolved)
    void removeComplaint(int id) {
        for (auto it = complaints.begin(); it != complaints.end();) {
            if (it->complaintId == id) {
                cout << "Removing complaint with ID: " << it->complaintId << endl;
                it = complaints.erase(it);
            } else {
                ++it;
            }
        }
    }

    // Fn to check if there are more than 5 complaints and send alert
    void checkComplaintsAlert() {
        if (complaints.size() > 5) {
            cout << "More than 5 complaints. Inform to superintendent!" << endl;
        }
    }
};

int main() {
    ComplaintManagement cm;
    int choice;

    do {
        // Display menu options
        cout << "\nState Electricity Board Complaint Management System" << endl;
        cout << "--------------------------------------------------" << endl;
        cout << "1. Register a New Complaint" << endl;
        cout << "2. Display All Complaints" << endl;
        cout << "3. Search Complaint by ID" << endl;
        cout << "4. Remove Resolved Complaint by ID" << endl;
        cout << "5. Check Complaint Alerts" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string serviceno, address, contactno;
                cout << "Enter service number: ";
                cin >> serviceno;

                cout << "Enter address: ";
                cin.ignore(); // To clear the buffer
                getline(cin, address);

                cout << "Enter contact number: ";
                cin >> contactno;

                cm.addComplaint(serviceno, address, contactno);
                break;
            }
            case 2:
                cm.displayAllComplaints();
                break;
            case 3: {
                int id;
                cout << "Enter complaint ID to search: ";
                cin >> id;
                cm.searchComplaintById(id);
                break;
            }
            case 4: {
                int id;
                cout << "Enter complaint ID to remove: ";
                cin >> id;
                cm.removeComplaint(id);
                break;
            }
            case 5:
                cm.checkComplaintsAlert();
                break;
            case 6:
                cout << "Exiting program... Thank you!" << endl;
                break;
            default:
                cout << "Invalid choice! Please choose a valid option." << endl;
                break;
        }

    } while (choice != 6); // Continue the loop until user chooses to exit

    return 0;
}
