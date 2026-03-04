//Name:Huzaifa Mujtaba
//Roll no:25P-0694
//section:BCS-2C
#include <iostream>
#include <string>
using namespace std;
struct employee{
    string emp;
    int empid;
    float salary;
    employee *highest(employee* arr){
        int max=arr[0].salary;
        employee* ind=&arr[0];
        for(int i=1;i<5;i++){
            if(arr[i].salary>max){
                max=arr[i].salary;
                ind=&arr[i];
            }
        }
        return ind;
    }
    employee *sort(employee* ptr){
        for(int i=0;i<4;i++){
            for(int j=0;j<4-i;j++){
                if(ptr[j].emp > ptr[j+1].emp){
                    employee tmp=ptr[j];
                    ptr[j]=ptr[j+1];
                    ptr[j+1]=tmp;

                }
            }
        }
        return ptr;
    }
};
int main(){
  employee* empl=new employee[5];
    for(int i=0;i<5;i++){
        cout<<"Enter EMPLOYEE "<<i+1<<" NAME: ";
        getline(cin>>ws,empl[i].emp);
        cout<<"Enter EMPLOYEE "<<i+1<<" ID: ";
        cin>>empl[i].empid;
        cout<<"Enter EMPLOYEE "<<i+1<<" salary: ";
        cin>>empl[i].salary;
    }
        employee *ret=empl[0].highest(empl);
        employee *sorArr=empl[0].sort(empl);
    cout<<"\nHighest Salary Employee:\n";
    cout<<"Name: "<<ret->emp<<endl;
    cout<<"ID: "<<ret->empid<<endl;
    cout<<"Salary: "<<ret->salary<<endl;
    cout<<"\nEmployees Sorted by Name:\n";
    for(int i=0;i<5;i++){
        cout<<"Name: "<<sorArr[i].emp<<endl;
        cout<<"ID: "<<sorArr[i].empid<<endl;
        cout<<"Salary: "<<sorArr[i].salary<<endl;
        cout<<endl;
    }
    delete[] empl;
    return 0;
}