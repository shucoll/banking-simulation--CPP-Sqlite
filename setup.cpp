#include<iostream>
#include<stdlib.h>

using namespace std;

int main() {

    system("g++ Database.cpp -l sqlite3");
    system("./a.out ");

    system("g++ Table.cpp -l sqlite3");
    system("./a.out ");
    
    return 0; 
}