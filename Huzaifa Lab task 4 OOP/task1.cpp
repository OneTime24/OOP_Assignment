//Name:Huzaifa Mujtaba
//Roll no:25P-0694
//section:BCS-2C
#include<iostream>
#include<string>
using namespace std;
struct Timess{
int hurs;
int minuts;
int secs;
string changeformat(){
    int h=hurs;
    string period;
    if(h==0){
        h=12;
        period="AM";
    }
    else if (h<12)
    {
        period="AM";
    }
    else if (h==12)
    {
        period="PM";
    }
    else{
        h=h-12;
        period="PM";
    }
    return to_string(h)+":"+(minuts<10?"0":" ")+to_string(minuts)+":"+(secs<10?"0":" ")+to_string(secs)+" "+period;
}
int convertTosecs() {
        return hurs * 3600 + minuts * 60 + secs;
    }    
};
int main(){
    Timess t;
    cout<<"Enter hurs in 24 hurs format: ";
    cin>>t.hurs;
    cout<<"Enter minuts: ";
    cin>>t.minuts;
    cout<<"Enter secs: ";
    cin>>t.secs;
    cout <<"12-hour format: "<< t.changeformat() << endl;
    cout <<"Total secs: "<< t.convertTosecs() << endl;
    return 0;
}