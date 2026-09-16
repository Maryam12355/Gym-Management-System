#include<iostream>
using namespace std;

struct Member
{
    int ID = 1;
    char name[50];
    int age;
    char membershipType[20];
    char joinDate[11];
};

struct Gym
{
    Member members[100];
    int memberCount = 0;

    void addMember()
    {
        if (memberCount < 100)
        {
            members[memberCount].ID = memberCount + 1;

            cout << "ID is = " << members[memberCount].ID << endl;
            cout << "Enter the name: ";
            cin >> members[memberCount].name;
            cout << "Enter the age: ";
            cin >> members[memberCount].age;
            cout << "Enter membership type (Gold/Silver/Platinum): ";
            cin >> members[memberCount].membershipType;
            cout << "Enter the join date (YYYY-MM-DD): ";
            cin >> members[memberCount].joinDate;

            memberCount++;
            cout << "Member added successfully" << endl;
        }
        else
        {
            cout << "Gym is at full capacity" << endl;
        }
    }

    void viewMembers()
    {
        if (memberCount == 0)
        {
            cout << "No members in the gym" << endl;
        }
        else
        {
            cout << "\nList of Members:" << endl;
            cout << "-------------------------------------------------" << endl;
            cout << "ID\tName\t\tAge\tMembership\tJoin Date" << endl;
            cout << "-------------------------------------------------" << endl;

            for (int i = 0; i < memberCount; i++)
            {
                cout << members[i].ID << "\t";
                cout << members[i].name << "\t\t";
                cout << members[i].age << "\t";
                cout << members[i].membershipType << "\t\t";
                cout << members[i].joinDate << "\t";
                cout << endl;
            }
            cout << endl;
        }
    }

    void updateMember()
    {
        int id;
        cout << "Enter ID: ";
        cin >> id;

        for (int i = 0; i < memberCount; i++)
        {
            if (members[i].ID == id)
            {
                cout << "Enter new name: ";
                cin >> members[i].name;
                cout << "Enter new age: ";
                cin >> members[i].age;
                cout << "Enter new membership type: ";
                cin >> members[i].membershipType;
                cout << "Enter new join date (YYYY-MM-DD): ";
                cin >> members[i].joinDate;

                cout << "Member updated successfully" << endl;
                return;
            }
        }
        cout << "Member not found" << endl;
    }

    void removeMember()
    {
        int id;
        cout << "Enter ID: ";
        cin >> id;

        if (memberCount == 0)
        {
            cout << "No members exist in the gym" << endl;
            return;
        }

        for (int i = 0; i < memberCount; i++)
        {
            if (members[i].ID == id)
            {
                for (int j = i; j < memberCount - 1; j++)
                {
                    members[j] = members[j + 1];
                }
                memberCount--;
                cout << "Member has been removed" << endl;
                return;
            }
        }
        cout << "Member not found" << endl;
    }

    void searchMember()
    {
        char searchName[50];
        cout << "Enter the name of the member to be searched: ";
        cin >> searchName;

        for (int i = 0; i < memberCount; i++)
        {
            bool match = true;
            for (int j = 0; j < 50; j++)
            {
                if (members[i].name[j] != searchName[j])
                {
                    match = false;
                    break;
                }
                if (members[i].name[j] == '\0' || searchName[j] == '\0')
                    break;
            }

            if (match)
            {
                cout << "Member found" << endl;
                cout << "ID: " << members[i].ID << endl;
                cout << "Name: " << members[i].name << endl;
                cout << "Age: " << members[i].age << endl;
                cout << "Membership Type: " << members[i].membershipType << endl;
                cout << "Join Date: " << members[i].joinDate << endl;
                return;
            }
        }
        cout << "Member not found" << endl;
    }

    void displayMenu()
    {
        cout << "\t\t\t**Gym Membership Management System\n\n\n" << endl;
        cout << "1. Add Member" << endl;
        cout << "2. View Members" << endl;
        cout << "3. Update Member" << endl;
        cout << "4. Remove Member" << endl;
        cout << "5. Search Member" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
    }
};

int main()
{
    Gym gym;
    int choice;

    while (true)
    {
        gym.displayMenu();
        cin >> choice;

        if (choice == 1)         
        {
            system("cls");
            gym.addMember();
        }
        else if (choice == 2)
        {
            system("cls");
            gym.viewMembers();
        }
        else if (choice == 3)
        {
            system("cls");
            gym.updateMember();
        }
        else if (choice == 4)
        {
            system("cls");
            gym.removeMember();
        }
        else if (choice == 5)
        {
            system("cls");
            gym.searchMember();
        }
        else if (choice == 6)
        {
            cout << "Exiting the program" << endl;
            break;
        }
        else
        {
            cout << "Invalid choice" << endl;
        }
    }
    
}