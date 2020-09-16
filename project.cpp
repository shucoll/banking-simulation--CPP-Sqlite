#include<iostream>
#include<string>

#include "LQueue.h"
#include "menus.h"

using namespace std;

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
        case 0:
            break;
        default:
            cout<<"Invalid input"<<endl;
        }

    }while(ipM != 0);
}

int clsMain::cusMenuCalc() {
    int ipC;
    do {
        Qrem=qe.size();
        ipC=mu.menu2(Qrem,SerCus);
        switch(ipC){
        case 1:
            if (Qrem==0 && SerCus==0) {
                SerCus = ++NewCus;
                break;
            }
            qe.enqueue(++NewCus);
            break;
        case 2:
            if(SerCus>0){
                SerCus=qe.dequeue();
            }
            else
                cout<<"No customer at service"<<endl;
            break;
        case 3:
            if(SerCus>0) {
                SerCus = qe.dequeue();
            }
            else
                cout<<"No customer at service"<<endl;
            break;
        case 0:
            break;
        default:
            cout<<"Invalid input"<<endl;
        }
        
    }while(ipC != 0);

    return ipC;
}

int main() {
    clsMain m;
    m.mainMenuCalc();

    return 0;
}

