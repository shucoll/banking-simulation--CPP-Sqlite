#include <iostream> 
#include <sqlite3.h> 
#include<string>

using namespace std; 

static int callback(void* data, int argc, char** argv, char** azColName) 
{ 
	int i; 
	fprintf(stderr, "%s: ", (const char*)data); 

	for (i = 0; i < argc; i++) { 
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL"); 
	} 

	printf("\n"); 
	return 0; 
} 

int main() 
{ 	
	int id;
	cout<<"Enter ID"<<endl;
	cin>>id;

	sqlite3* DB; 
	sqlite3_stmt* st;
	int exit = 0; 
	exit = sqlite3_open("example.db", &DB); 
	string data("CALLBACK FUNCTION"); 

	string sql= "SELECT * FROM PERSON WHERE ID = ?;"; 

	exit=sqlite3_prepare_v2(DB, sql.c_str(), -1, &st, 0);

	if (exit == SQLITE_OK) {
        sqlite3_bind_int(st, 1, id);
    } else {
        
        fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(DB));
    }
	
	
	int step = sqlite3_step(st);
    
    if (step == SQLITE_ROW) {
        
        printf("ID:      %d\n", sqlite3_column_int(st, 0));
        printf("Name:    %s\n", sqlite3_column_text(st, 1));
		printf("Surname: %s\n", sqlite3_column_text(st, 2));
		printf("Age:     %d\n", sqlite3_column_int(st, 3));
		printf("Address: %s\n", sqlite3_column_text(st, 4));

	}
	else cout<<"Record not found";
	
	sqlite3_finalize(st);
	sqlite3_close(DB); 
	return 0; 
} 
