// The Shape Shifting Hostel

#include <iostream>

using namespace std;

struct student{


    string roll_num;

    string name;


};

struct room{


    int room_no;
    int tot_cap;
    int curr_std;
    student* std;

};


//resize number of rooms;

room* resizeRoom(room* ptr, int& n){
    int newsize;
    cout<<"Enter Number of new rooms you want to add: ";
    int x;
    cin>>x;
    int newsize=n+x;

    room* newptr=new room[newsize];
    
    for(int i=0;i<n;i++){
        *(newptr+i)=*(ptr+i);
    }
    n=newsize;


    for(int i=n;i<newsize;i++){
        cin>>newptr[i].room_no;
        cin>>newptr[i].tot_cap;
        cin>>newptr[i].curr_std;

        newptr[i].std=new student[newptr[i].tot_cap];
        for(int j=0; j<newptr[i].curr_std; j++)
        {
            getline(cin>>ws, newptr[i].std[j].name);
            getline(cin>>ws, newptr[i].std[j].roll_num);
        }
    }
    return newptr;
}

void addstd(room* ptr, int n){
    int roomno;
    cout<<"Enter room number you want to add student to: ";
    cin>>roomno;

    bool added = false;

    // First, try the requested room
    for(int i=0;i<n;i++){
        if(ptr[i].room_no == roomno){
            if(ptr[i].curr_std < ptr[i].tot_cap){
                int ind = ptr[i].curr_std;
                cout<<"Enter Student name: ";
                getline(cin>>ws, ptr[i].std[ind].name);
                cout << "Enter Roll Number: ";
                getline(cin>>ws, ptr[i].std[ind].roll_num);
                ptr[i].curr_std++;
                cout<<"Student added to Room "<<roomno<<endl;
                added = true;
                return;
            } 
            else{
                cout<<"Room "<<roomno<<" is full, searching nearest available room..."<<endl;
                break; // stop looking at requested room
            }
        }
    }

    // If requested room is full, find first room with space
    if(!added){
        for(int i=0;i<n;i++){
            if(ptr[i].curr_std < ptr[i].tot_cap){
                int ind = ptr[i].curr_std;
                cout<<"Enter Student name: ";
                getline(cin>>ws, ptr[i].std[ind].name);
                cout << "Enter Roll Number: ";
                getline(cin>>ws, ptr[i].std[ind].roll_num);
                ptr[i].curr_std++;
                cout<<"Student added to Room "<<ptr[i].room_no<<endl;
                added = true;
                return;
            }
        }
    }

    if(!added)
        cout<<"All rooms are full! Cannot add student."<<endl;
}
// Need to understand yet
void removeStudent(room* ptr, int n)
{
    int roomno;
    cout << "Enter Room Number to remove student: ";
    cin >> roomno;

    string roll;
    cout << "Enter Roll Number of student to remove: ";
    cin >> roll;

    for(int i=0;i<n;i++)
    {
        if(ptr[i].room_no == roomno)
        {
            for(int j=0;j<ptr[i].curr_std;j++)
            {
                if(ptr[i].std[j].roll_num == roll)
                {
                    // shift students left
                    for(int k=j;k<ptr[i].curr_std-1;k++)
                        ptr[i].std[k] = ptr[i].std[k+1];

                    ptr[i].curr_std--;
                    cout << "Student removed!" << endl;
                    return;
                }
            }
            cout << "Student not found!" << endl;
            return;
        }
    }
    cout << "Room not found!" << endl;
}

void display(room* ptr, int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<"\nRoom Number: " << ptr[i].room_no;
        cout << "\nCapacity: " << ptr[i].tot_cap;
        cout << "\nCurrent Students: " << ptr[i].curr_std;

        for(int j=0;j<ptr[i].curr_std;j++)
        {
            cout << "\n   Name: " << ptr[i].std[j].name;
            cout << "  Roll: " << ptr[i].std[j].roll_num;
        }
        cout << "\n";
    }
}


void mostCrowded(room* ptr, int n)
{
    if(n==0) return;

    int maxIndex = 0;
    int maxCount = ptr[0].curr_std;

    for(int i=1;i<n;i++)
    {
        if(ptr[i].curr_std > maxCount)
        {
            maxCount = ptr[i].curr_std;
            maxIndex = i;
        }
    }

    cout << "\nMost Crowded Room: " << ptr[maxIndex].room_no;
    cout << " with " << ptr[maxIndex].curr_std << " students\n";
}
int main(){

    cout<<"------------------------------ Hostel Management System ------------------------------"<<endl;
    cout<<"Enter Total Number of Rooms: ";
    int n;
    cin>>n;
    room* ptr=new room[n];

    for(int i=0;i<n;i++){
        cout<<"Enter Room Number: ";
        cin>>ptr[i].room_no;
        cout<<"Enter Capacity of "<<i+1<<" room: ";
        cin>>ptr[i].tot_cap;
        cout<<"Enter Current Student in This Room: ";
        cin>>ptr[i].curr_std;

        ptr[i].std=new student[ptr[i].tot_cap];

        for(int j=0;j<ptr[i].curr_std;j++){
            cout<<"Enter Student "<<j+1<<" Name: ";
            getline(cin>>ws,ptr[i].std[j].name);
            cout<<"Enter Student "<<j+1<<" Roll Num: ";
            getline(cin>>ws,ptr[i].std[j].roll_num);
        }
    }

    int choice;
    do {
        cout<<"\nAny operation you want to perform? "<<endl;
        cout<<"1. Add a new room\n2. Add Student to a room\n3. Remove Student from a room\n4. Display all rooms with students\n5. Most crowded Room\n6. Exit\n";
        cin>>choice;

        switch(choice){
            case 1:
                ptr = resizeRoom(ptr,n); // update ptr to new array
                break;
            case 2:
                addstd(ptr,n);
                break;
            case 3:
                removeStudent(ptr,n);
                break;
            case 4:
                display(ptr,n);
                break;
            case 5:
                mostCrowded(ptr,n);
                break;
            case 6:
                cout<<"Exiting..."<<endl;
                break;
            default:
                cout<<"Invalid choice!"<<endl;
        }

    } while(choice != 6);

    for(int i=0;i<n;i++){
        delete[] ptr[i].std;
    }
    delete[] ptr;

    return 0;
}