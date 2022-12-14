#include <iostream>
using namespace std;
class Node
{
public:
    int ID;
    Node *Next;
    string Name;
    int Date;
    string RoomType;
    Node()
    {
        ID = 0;
        Next = NULL;
        Name='0';
        Date = 0;
        RoomType='0';
    }
    Node(int _id, string _name, int _date, string _roomtype)
    {
        ID = _id;
        Name = _name;
        Date = _date;
        RoomType = _roomtype;
    }
};
class SinglyLinkedList
{
public:
    Node *Head;
    SinglyLinkedList()
    {
        Head = NULL;
    }
    SinglyLinkedList(Node *_n)
    {
        Head = _n;
    }
    // Checks if room is available
    Node *NodeExist(int _id)
    {
        Node *Temp = NULL;
        Node *Ptr = Head;
        while (Ptr != NULL)
        {
            if (Ptr->ID == _id)
            {
                Temp = Ptr;
            }
            Ptr = Ptr->Next;
        }
        return Temp;
    }
    // Allocating a room
    void AllocateRoom(Node *_n)
    {
        if (NodeExist(_n->ID) != NULL)
        {
            cout << "This room is booked. Try new id" << endl;
        }
        else
        {
            if (Head == NULL)
            {
                Head = _n;
                cout << "Room allocated" << endl;
            }
            else
            {
                Node *Ptr = Head;
                while (Ptr->Next != NULL)
                {
                    Ptr = Ptr->Next;
                }
                Ptr->Next = _n;
                cout << "Room allocated" << endl;
            }
        }
    }
    // Searching of room
    void SearchRoom(int _id)
    {
        if (NodeExist(_id) == NULL)
        {
            cout << "the room with  id " << _id << " is not booked" << endl;
        }
        else
        {

            Node *Ptr = Head;
            while (Ptr->ID != _id)
            {
                Ptr = Ptr->Next;
            }
            cout << "\n Room ID: " << Ptr->ID << "\n Customer Name: " << Ptr->Name << "\n Room Allocated Date: " << Ptr->Date << "\n Room type: " << Ptr->RoomType << endl;
        }
    }
    void UpdateRoom(int _id, string _name, int _date, string _roomtype)
    {

        if (Head == NULL)
        {
            cout << "No registeration yet" << endl;
        }
        else
        {
            Node *Ptr = NodeExist(_id);
            if (Ptr != NULL)
            {
                Ptr->Name = _name;
                Ptr->Date = _date;
                Ptr->RoomType = _roomtype;
                cout<<"Room information updated"<<endl;
            }
            else
            {
                cout << "No registration yet" << endl;
            }
        }
    }
    // Deleting room information
    void DeleteRoom(int _id)
    {
        if (Head == NULL)
        {
            cout << "No room information" << endl;
        }
        else if (Head != NULL)
        {
            if (Head->ID == _id)
            {
                Head = Head->Next;
                cout << "Room information deleted" << endl;
            }
            else
            {
                Node *Temp = NULL;
                Node *PrevRoom = Head;
                Node *CurrRoom = Head->Next;
                while (CurrRoom != NULL)
                {
                    if (CurrRoom->ID == _id)
                    {
                        Temp = CurrRoom;
                        CurrRoom = NULL;
                    }
                    else
                    {
                        PrevRoom = PrevRoom->Next;
                        CurrRoom = CurrRoom->Next;
                    }
                    if (Temp != NULL)
                    {
                        PrevRoom->Next = Temp->Next;
                        cout << "Room information deleted" << endl;
                    }
                    else
                    {
                        cout << "No room information" << endl;
                    }
                }
            }
        }
    }
    void ShowRooms()
    {
        if (Head == NULL)
        {
            cout << "No registration yet" << endl;
        }
        else
        {
            Node *Ptr = Head;
            while (Ptr != NULL)
            {
                cout << "\n Room ID: " << Ptr->ID << "\n Customer Name: " << Ptr->Name << "\n Room Allocated Date: " << Ptr->Date << "\n Room type: " << Ptr->RoomType << endl;
                Ptr = Ptr->Next;
                cout<<endl;
            }
        }
    }
};
int main()
{
    SinglyLinkedList S;
    int Option;
    int ID1, I1, Date1;
    string Name1, Roomtype1;
    do
    {
        cout << endl;
        cout << "  Welcome to HA's Hotel Management System application \n"
             << endl;
        cout << "\t ____Hotel Management System____ \n"
             << endl;
        cout << "S.No \t\t Functions \t\t\t Description \n"
             << endl;
         cout << "0 \t\t EXit \t\t\t\t Press 0 for exit" << endl;
        cout << "1 \t\t Allocate Room \t\t\t Insert new room" << endl;
        cout << "2 \t\t Search Room \t\t\t Search room with roomID" << endl;
        cout << "3 \t\t Update Room \t\t\t Update room record" << endl;
        cout << "4 \t\t Delete Room \t\t\t Delete room with roomID" << endl;
        cout << "5 \t\t Show Room Records \t\t Show all room records" << endl;
        cout << "6 \t\t Clear Screen" << endl;
       
        cout << "Enter your choice" << endl
             << endl;
        cin >> Option;
        Node *N1 = new Node();
        switch (Option)
        {
        case 1:
            cout << "Enter room ID" << endl;
            cin >> ID1;
            cout<<"Customer name"<<endl;
            cin >> Name1;
            cout<<"Date of allocation"<<endl;
            cin >> Date1;
            cout<<"Room type"<<endl;
            cin >> Roomtype1;
            N1->ID = ID1;
            N1->Name = Name1;
            N1->Date = Date1;
            N1->RoomType = Roomtype1;
            S.AllocateRoom(N1);
            break;
        case 2:
            cout << "Enter room id to search the room" << endl;
            cin >> I1;
            S.SearchRoom(I1);
            break;
        case 3:
            cout << "Enter room id to update the room information" << endl;
            cin >> ID1;
            cout << "enter the new information" << endl;
            cout << "enter new name" << endl;
            cin >> Name1;
            cout << "enter new date of allocation" << endl;
            cin >> Date1;
            cout << "enter room type" << endl;
            cin >> Roomtype1;
            cout << endl;
            S.UpdateRoom(ID1, Name1, Date1, Roomtype1);
            break;
        case 4:
            cout << "Enter the id of room you want to delete" << endl;
            cin >> I1;
            S.DeleteRoom(I1);
            break;
        case 5:
            cout << "ROOM RECORDS" << endl;
            S.ShowRooms();
            break;
        case 6:
            system("cls");
            break;

        default:
            break;
        }

    } while (Option != 0);

    return 0;
}