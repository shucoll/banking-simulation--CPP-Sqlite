#include<iostream>
#include<stdlib.h>

using namespace std;

int main() {

    cout<<"Before running"<<endl;

        system("g++ Database.cpp -l sqlite3");
        system("./a.out ");

        system("g++ Table.cpp -l sqlite3");
        system("./a.out ");
    

    cout<<"After running"<<endl;
    return 0; 
}