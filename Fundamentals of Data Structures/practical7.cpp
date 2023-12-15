#include <iostream>
using namespace std;
struct Student
{
    string name;
    long int PRN;
    Student* next;
};

class PinnacleList
{
    private:
    Student* head;
    Student* tail;
    public:
    PinnacleList()
    {
        head = NULL;
        tail = NULL;
    }
    void addMember()
    {
        cout << "Is the member a president (1), secretary (2) or a normal member (3)?" << endl;
        int choice;
        cin >> choice;
        if (choice==1)
            addPresident();
        else if (choice == 2)
            addSecretary();
        else
            addNormalMember();
    }
    void addPresident()
    {
        Student *tempStud = new Student();
        cout << "Adding President as first member." << endl;
        cout << "Enter name of president: " << endl;
        cin >> tempStud->name;
        cout << "Enter PRN of president: " << endl;
        cin >> tempStud->PRN;

        tempStud->next = head;

        // If the list is empty, set both head and tail to the new element
        if (head == NULL)
        {
            tail = tempStud;
        }

        head = tempStud;

        cout << "President Added." << endl;
    }
    void addSecretary()
    {
        Student *tempStud = new Student();
        cout << "Adding Secretary as last member." << endl;
        cout << "Enter name of Secretary: " << endl;
        cin >> tempStud->name;
        cout << "Enter PRN of Secretary: " << endl;
        cin >> tempStud->PRN;
        tempStud->next = NULL;
        // If the list is empty, set both head and tail to the new element
        if (head == NULL)
        {
            head = tail = tempStud;
        }
        else
        {
            tail->next = tempStud;
            tail = tempStud;
        }
    
        cout << "Secretary Added." << endl;
    }
    void addNormalMember()
    {
        cout << "Adding a new member to the list" << endl;
        Student* tempStud = new Student();
        cout << "Enter the member's name: " << endl;
        cin >> tempStud->name;
        cout << "Enter the member's PRN: " << endl;
        cin >> tempStud->PRN;
        tempStud->next = tail;
        Student* secondLast = head;
        while(secondLast->next->next!=NULL)
        {
            secondLast = secondLast->next;
        }
        secondLast->next = tempStud;
        cout << "Member added." << endl;
    }
    void deleteMember()
    {
        cout << "Is the member a president (1), secretary (2) or a normal member (3)?" << endl;
        int choice;
        cin >> choice;
        if (choice==1)
            deletePresident();
        else if (choice == 2)
            deleteSecretary();
        else
            deleteNormalMember();
    }
    void deletePresident()
    {
        Student* temp = head;
        head = head->next;
        delete temp;
        cout << "Member removed from list" << endl;
    }
    void deleteSecretary()
    {
        Student* temp = tail;
        Student* secondLast = head;
        while(secondLast->next->next!=NULL)
        {
            secondLast = secondLast->next;
        }
        secondLast->next = NULL;
        delete temp;
        cout << "Member removed from list." << endl;
    }
    void deleteNormalMember()
    {
        cout << "Enter PRN of Member you want to remove from list: " << endl;
        long int tempPRN;
        cin >> tempPRN;
        Student* temp = head; // finds the node before the one you want to delete.
        while (temp->next->PRN!=tempPRN)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        cout << "Member removed from list." << endl;
    }
    void displayList()
    {
        cout << "The students in the list are: " << endl;
        Student* tempStud = head;
        while (tempStud!=NULL)
        {
            cout << tempStud->name << " " << tempStud->PRN << endl;
            tempStud = tempStud->next;
        }
    }
    void findTotalMembers()
    {
        Student* tempStud = head;
        int memcount = 0;
        while (tempStud!=NULL)
        {
            memcount++;
            tempStud = tempStud->next;
        }
        cout << "Total Members are: " << memcount << endl;
    }
    void concatLists (PinnacleList &l1, PinnacleList &l2)
    {
        //add logic for if any 1 list is empty then simply copy the other list to it. also, in this logic, the updated, concatenated list will be saved in l1 but it can be rewritten to return a new list.
        l1.tail->next = l2.head;
        l1.tail = l2.tail;
    }
};

int main() {
    PinnacleList l1;
    PinnacleList l2;
    // add logic for 2 lists
    while (true)
    {
        int choice;
        cout << "1. Add Member" << endl;
        cout << "2. Delete a Member" << endl;
        cout << "3. Display All Members" << endl;
        cout << "4. Display Total Members of the club" << endl;
        cout << "5. Concatenate the 2 lists." << endl;
        cin >> choice;
        switch (choice)
        {
            case 1:
            l1.addMember();
            break;
            case 2:
            l1.deleteMember();
            break;
            case 3:
            l1.displayList();
            break;
            case 4:
            l1.findTotalMembers();
            break;
            default:
            cout << "Invalid Input." << endl;
        }
    }
    return 0;
}