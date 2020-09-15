#include<iostream>
#include<stdlib.h>

using namespace std;

int main() {

    cout<<"Before running"<<endl;

    for (int i=0;i<2;i++) {
        system("g++ in.cpp -l sqlite3");
        system("./a.out ");
    }

    for (int i=0;i<3;i++) {
        system("g++ se.cpp -l sqlite3");
        system("./a.out ");
    }
    

    cout<<"After running"<<endl;
    return 0; 
}
