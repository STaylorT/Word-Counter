#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <cstring>
using namespace std;

// define structure for hash items
typedef struct hashItem hashItem;
struct hashItem{
	char* key;
	char* value;
};
 
 // define structure for hash table
typedef struct hashTable hashTable;
struct hashTable{
	hashItem** items;
	int size;
	int count;
};

//function to create a hash item
hashItem* createHashItem(char* key, char* value){
	hashItem* item = (hashItem*) malloc(sizeof(hashItem)); //allocate space for hashItem
	item->key = (char*) malloc(strlen(key)+1); //allocate space in new hashitem for key
	item->value = (char*) malloc(strlen(value)+1); //allocate space in new item for value
	// put key and value parameters in allocated space, then return item
	strcpy(item->key, key); 
    	strcpy(item->value, value);
	return item;
}

//function to create a hash table
hashTable* createHashTable(int size){
	hashTable* table = (hashTable*) malloc(sizeof(hashTable)); //allocate space for table
	table->size = size; //initialize size with passed parameter
	table->count = 0; //count set at 0
	table->items = (hashItem**) calloc(table->size, sizeof(hashItem*)); //allocate items in table and set to 0
	
	// iterate through table items and set to NULL
	for (int i = 0; i<table->size;i++){
		table->items[i] = NULL;
	}
	return table;
}

int main(int argc, char* argv[]){
//char* file = argv[1];

char input[100] = "";
while (cin){
	cin >> input;
	}
return 0;
}
