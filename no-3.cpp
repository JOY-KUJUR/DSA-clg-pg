#include <iostream>
#include <string>
#include <cstdlib> // For malloc and free functions

using namespace std;

struct node {
    int PRN;
    string name;
    string year;
    node* next;
};

// Function to add a new node to the linked list
void add(node** head, int a, string b, string c) {
    node* newnode = (node*)malloc(sizeof(node));

    newnode->PRN = a;
    newnode->name = b;
    newnode->year = c;

    newnode->next = *head;
    *head = newnode;
}

// Function to count the number of nodes in the list
int countNodes(node* head) {
    int count = 0;
    node* current = head;

    while (current != nullptr) {
        count++;
        current = current->next;
    }

    return count;
}

// Function to display the list and count the number of nodes
void display(node* head) {
    node* co = head; // Save the original head for counting nodes

    while (head != nullptr) {
        cout << "PRN: " << head->PRN << endl;
        cout << "Name: " << head->name << endl;
        cout << "Year: " << head->year << endl;
        cout << endl;
        head = head->next;
    }

    int numNodes = countNodes(co); // Call countNodes after displaying
    cout << "Number of nodes in the list: " << numNodes << endl;
}

// Function to delete a node by PRN
void deleteNode(node** head, int key) {
    node* temp = *head;
    node* prev = nullptr;

    // The node to be deleted is the head node
    if (temp != nullptr && temp->PRN == key) {
        *head = temp->next; // Update the head to point to the next node
        free(temp);         // Free the old head
        cout << "Node with PRN " << key << " deleted (head node)." << endl;
        return;
    }

    //Find the node to be deleted (non-head node)
    while (temp != nullptr && temp->PRN != key) {
        prev = temp;
        temp = temp->next;
    }

    // If the node was not found
    if (temp == nullptr) {
        cout << "Node with PRN " << key << " not found." << endl;
        return;
    }

    // Unlink the node from the list and free memory
    prev->next = temp->next;
    free(temp);
    cout << "Node with PRN " << key << " deleted." << endl;
}

// Function to handle menu actions
void swi(node** head) {
    int n;
     cout << "----------------------------------" << endl;
        cout << "Press 1 for viewing the list:" << endl;
        cout << "Press 2 for adding a new student:" << endl;
        cout << "Press 3 for deleting a student:" << endl;
        cout << "Press 4 to exit:" << endl;
    while (true) { // Loop for continuous menu display
       
        cout << "Enter your choice: ";
        cin >> n;

        switch (n) {
            case 1:
                cout << "----------------------------------" << endl;
                display(*head);
                break;
            case 2: {
                cout << "----------------------------------" << endl;
                int x;
                string y, z;
                cout << "Enter the PRN: ";
                cin >> x;
                cout << "Enter the name: ";
                cin >> y;
                cout << "Enter the year: ";
                cin >> z;

                add(head, x, y, z);
                break;
            }
            case 3: {
                cout << "----------------------------------" << endl;
                int choice;
                cout << "Enter the PRN of the student you want to delete: ";
                cin >> choice;

                deleteNode(head, choice);
                break;
            }
            case 4:
                return; // Exit the loop
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
}

int main() {
    node* divA = nullptr;
    node* divB = nullptr;
    int num;

    while (true) {
        cout << "----------------------------------" << endl;
        cout << "Select division:" << endl;
        cout << "Press 1 for Division A" << endl;
        cout << "Press 2 for Division B" << endl;
        cout << "Press 3 to exit" << endl; // Added option 3 to exit
        cout << "Enter your choice: ";
        cin >> num;
        cout << "----------------------------------" << endl;

        switch (num) {
            case 1:
                cout<<"DIV A";
                swi(&divA);
                break;
            case 2:
            cout<<"DIV B";
                swi(&divB);
                break;
            case 3:
                return 0; // Exit the program
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
