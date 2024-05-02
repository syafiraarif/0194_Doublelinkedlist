

#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int noMhs;
    string name;
    Node* next;
    Node* prev;
};

Node* START = NULL;

void addNode()
{
    Node* newNode = new Node();                                 // step 1 : create a new node
    cout << "\nEnter the roll number of the student: ";
    cin >> newNode->noMhs;                                      // Assign value to the data field of the new node
    cout << "\n Enter the name of the student: ";
    cin >> newNode->name;                                       //assign value to the data field of the new node

    //insert the new node in the list
    if (START == NULL || newNode->noMhs <= START->noMhs)        //step 2 : insert the new node
    {
        if (START != NULL && newNode->noMhs == START->noMhs) 
        {
            cout << "\033[31mDuplicate roll numbers not allowed\033[0m" << endl;
            return;
        }
        // if the list is empety, make the new node the START
        newNode->next = START;                                 //step 3 : make the new node point to the first node
        if (START != NULL)
        {
            START->prev = newNode;                             // step 4: make the first node point to the new node
        }
        newNode->prev = NULL;                                  //step 5: make the new node point to NULL
        START = newNode;                                       //step 6: make the new node the first node
    }
    else
    {
        //insert the new node in the middle or at the end
        Node* current = START;                                 //step 1.a: start from the first node
        Node* previous = NULL;                                 //step 1.b: previous node is NULL initially


        while (current != NULL && current->noMhs < newNode->noMhs)      //step 1.c: traverse
        {
            previous = current;                                         //step 1.d: move the previous to the current node
            current = current->next;                                    //step 1.e: move the current to the next node
        }

        newNode->next = current;                               //step 4: make the next field of the new node point
        newNode->prev = previous;                              //step 5: make the previous field of the new node point

        if (current != NULL)
        {
            current->prev = newNode;                           //step 6: make the previous field of the current
        }

        if (previous != NULL)
        {
            previous->next = newNode;                          //step 7: make the next field of the previous node
        }
        else
        {
            //if previous is still NULL, it means newNode is now the first node
            START = newNode;
        }

    }
}

bool search(int rollNo, Node **previous, Node **current)
{
    *previous = NULL;
    *current = START;
    while (*current != NULL && (*current)->noMhs != rollNo)
    {
        *previous = *current;
        *current = (*current)->next;
    }
    return (*current != NULL);
}

void deleteNode()
{
    Node* previous, * current;
    int rollNo;

    cout << "\nEnter the roll number of the student whose record is to be deleted: ";
    cin >> rollNo;                                                                  //step 3get the roll number to be deleted

    if (START == NULL)
    {
        cout << "List is empety" << endl;
        return;
    }

    current = START;                                                               //step 1:start from the first node
    previous = NULL;

    //locate the node to be deleted
    while (current != NULL && current->noMhs != rollNo)
    {
        previous = current;
        current = current->next;
    }

    if (current == NULL)
    {
        cout << "\033[31mThe record with roll number " << rollNo << "not found\033[0m" << endl;
        return;
    }

    //Node to be deleted is the firts node
    if (current == START)
    {
        START = START->next;                                            //step 2:update the START pointer
        if (START != NULL)
        {
            START->prev = NULL;                                         //step
        }
    }
    else 
    {   //Node to be deleted is not the first node
        previous->next = current->next;
        if (current->next != NULL)
        {   //if there's successor, update is prev pointer
            current->next->prev = previous;
        }
    }

    //release the memory of the node marked as current
    delete current;
    cout << "\x1b[32mRecord with roll number " << rollNo << "deleted\x1b[0m" << endl;
}

bool listempety()
{
    return (START == NULL);
}

void traverse()
{

}
int main()
{
    
}

