

#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int noMhs;
    string name;
    Node *next;
    Node * prev;
};

Node* START = NULL;

void addNode()
{
    Node* newNode = new Node();
    cout << "\nEnter the roll number of the student: ";
    cin >> newNode->noMhs;
    cout << "\n Enter the name of the student: ";
    cin >> newNode->name;
}
int main()
{
    
}

