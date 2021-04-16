#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <cstring>
using namespace std;

const int MAX = 10000;

int hashFunction(string str){
	
   int seed = 123; 
   unsigned long hash = 0;
   for(int i = 0; i < str.length(); i++)
   {
      hash = (hash * seed) + str[i];
   }
   return hash % MAX;

}
// define structure for hash items
typedef struct hashItem hashItem;
struct hashItem{
	string key;
	int value;
};
 
 // define structure for hash table
 typedef struct hashTable hashTable;
struct hashTable{
	hashItem items[MAX];
	int size;
	int count;
};

//function to create a hash item
hashItem createHashItem(string key, int value){
	hashItem item; 
	// put key and value parameters, then return item
	item.key = key;
	item.value = value;
	return item;
}

//function to create a hash table
hashTable createHashTable(int size){
	hashTable table; 
	table.size = size; //initialize size with passed parameter
	table.count = 0; //count set at 0
	table.items[size];
	
	// iterate through table items and set to NULL
	for (int i = 0; i<table.size;i++){
		table.items[i].key = "";
		table.items[i].value = 0;
	}
	return table;
}

// function to swap two elements
void swap(hashItem *a, hashItem *b){
	hashItem t = *a;
	*a = *b;
	*b = t;
}

   // partition function for sort
int partition(hashTable table, int low, int high){
	int pivot = table.items[high].value; //pivot
	int i = (low - 1); // smaller element
	
	for(int j = low ; j <=high-1;j++){
		
		//check if current is smaller or equal to pivot
		if (table.items[j].value <= pivot){
			i++;
			swap(&table.items[i],&table.items[j]);
		}
	}
	swap(&table.items[i+1],&table.items[high]);
	return (i+1); // return index
}
 
  // quick sort function: low = start index, high = end index
void quickSort(hashTable table, int low, int high){
	if (low < high){
		// index of partition from partition func
		int partIndex = partition(table, low, high);
		
		// recursively sort sub-array on either side of piviot
		quickSort(table, low, partIndex-1);
		quickSort(table, partIndex+1, high);
	}
}
 
// print array function for testing;
void printArray(int arr[], int size){
	for (int i = 0 ; i < size;i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

void handleCollision(hashTable table, hashItem item){

}
void insertHashTable(hashTable &table, string key, int value){
	hashItem item = createHashItem(key, value);
	int index = hashFunction(key);
	
	hashItem current = table.items[index];
	if (current.key == ""){ //key doesn't yet exist
		
		if (table.count == table.size){ //table full
			cout << "Insertion error: full table" << endl;
			//freeItem(item);
			return;
		}
	//insert into table
	
	table.items[index] = item;
	table.count++; //added to items
	return;
	}
	else{
		
		//just to update the value, e.g. increment word count
		if (current.key == key){ 
			table.items[index].value++;
			return;
		}
	else{ //must be collision to handle
		handleCollision(table, item);
		return;
	}

	}
}

int search(string key, hashTable table){
	int index = hashFunction(key);

	if (table.items[index].key != ""){
		if (table.items[index].key== key){
			return table.items[index].value;
		}

	}
	return -1;
}

void printSearch(hashTable table, string key) {
    int val;
    if ((val = search(key, table)) == -1) {
    cout << "Key: " << key << endl;
        return;
    }
    else {
    	cout << "Key: " << key << " | Value: " << val << endl;
    }
}
 
 
 //
void printTable(hashTable table) {
    cout << "\nHash Table: "<< endl;
    cout << "-------------------------" << endl;
  
    for (int i=0; i<table.size; i++) {
        if (table.items[i].key != "") {
        	cout << "Index: "<< i << " | Key: " << table.items[i].key << " | Value: "<< table.items[i].value << endl;

        }
    }
    cout << "-------------------------" << endl;
}


int main(int argc, char* argv[]){


	hashTable Table = createHashTable(MAX);
	string input;
	while (cin){
		cin >> input;
		insertHashTable(Table, input, 1);
	}
	
	
	//quickSort(keyArr, 0, MAX);
	quickSort(Table, 0, MAX);
	//printTable(Table);

return 0;
}
