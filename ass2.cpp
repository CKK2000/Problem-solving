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

    cm.addComplaint("101", "Lucknow", "91687594");
    cm.addComplaint("102", "Agra", "566685");
    cm.addComplaint("103", "Hyderabad", "556655");
    cm.addComplaint("104", "Indore", "6565645");
    cm.addComplaint("105", "Banglore", "849");
    cm.addComplaint("106", "Delhi", "656");
    

    cm.checkComplaintsAlert();
    cm.removeComplaint(3);
    cm.displayAllComplaints();

    cm.searchComplaintById(5);

    return 0;
}
