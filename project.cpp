#include<iostream>
#include<string>
#include<fstream>

#include "LQueue.h"
#include "menus.h"

using namespace std;

class userInfo {
    public:
    string fname;
    string lname;
    int age;
    string phNo;
    int uId;
    string occup;

};

class server {
    public:
    void getInfo();
    void putInfo();
};

class clsMain {
    int Qrem;
    int SerCus;
    int NewCus;
    Queue qe;
    Menus mu;

    public:
    void mainMenuCalc();
    int cusMenuCalc();

};

void server::putInfo() {
    userInfo ufo;
    ofstream ouf;
    ouf.open("uinfo.txt");
    cout<<"Enter User first name"<<endl;
    //ufo.getFName();
    cin>>ufo.fname;
    cout<<"Enter age"<<endl;
    cin>>ufo.age;
    ouf<<ufo.fname<<endl;
    ouf<<ufo.age<<endl;

}

void clsMain:: mainMenuCalc() {
    Qrem=0;
    SerCus=0;
    NewCus=0; 
    int ipM;
    
    do{
        Qrem=qe.size();
        ipM = mu.menu1(Qrem,SerCus);

        switch (ipM){
        case 1:
            qe.enqueue(++NewCus);
            break;
        case 2:
            if(NewCus>0){
                SerCus=qe.dequeue();
                ipM=cusMenuCalc();
            }
            else
                cout<<"No customer available"<<endl;
            break;
        case 3:
            break;
        default:
            cout<<"Invalid input"<<endl;
        }

    }while(ipM != 3);
}

int clsMain:: cusMenuCalc() {
    int ipC;
    do {
        Qrem=qe.size();
        ipC=mu.menu2(Qrem,SerCus);
        switch(ipC){
            case 1:
            qe.enqueue(++NewCus);
            break;
        case 2:
            cout<<"Service unavailable"<<endl;
            break;
        case 4:
            cout<<"Service unavailable"<<endl;
            break;
        case 3:
            break;
        default:
            cout<<"Invalid input"<<endl;
        }
    }while(ipC != 3);

    return ipC;
}

int main() {
    clsMain m;
    m.mainMenuCalc();

    return 0;
}

