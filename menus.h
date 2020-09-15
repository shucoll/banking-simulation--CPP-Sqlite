#include<iostream>
#include<sstream>
#include<string>

using namespace std;


class Menus {
    public:
    int checkInput(string chM);
    int menu1(int,int);
    int menu2(int,int);

};

int Menus::checkInput(string chM) {
    for (int i = 0; i < chM.length(); i++) {
        if (isdigit(chM[i]) == false) 
            return -1;
    }

    int ipM = 0;     
    stringstream ss(chM);
    ss >> ipM;
    return ipM; 
}


int Menus:: menu2(int Qrem, int SerCus) {
    string chC;
    cout<<"           *----Customer Service Menu----*"<<endl;
    cout<<"           Total customer remaining "<<Qrem<<endl;
    cout<<"           Customer at service "<<SerCus<<endl;
    cout<<"           1. New Customer?"<<endl;
    cout<<"           For service to customer "<<SerCus<<endl;
    cout<<"                   2. To add data"<<endl;
    cout<<"                   4. To retrive data"<<endl;
    cout<<"           3. End Services for now(Terminate program)"<<endl;
    cout<<"           Enter your choice 1/2/3/4"<<endl;
    cin>>chC;
    int ipC=checkInput(chC);
    return ipC;
}

int Menus:: menu1(int Qrem,int SerCus) {
    string chM;
    cout<<"           *----Main Menu----*"<<endl;
    cout<<"           Total customer remaining "<<Qrem<<endl;
    cout<<"           Customer at service "<<SerCus<<endl;
    cout<<"           1. New Customer?"<<endl;
    cout<<"           2. Service to customer"<<endl;
    cout<<"           3. End Services for now(Terminate program)"<<endl;
    cout<<"           Enter your choice 1/2/3"<<endl;
    cin>>chM;
    int ipM=checkInput(chM);
    return ipM;
}

