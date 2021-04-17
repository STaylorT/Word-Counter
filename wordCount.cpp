#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
#include <cstring>
using namespace std;

const int MAX = 10007;

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
	hashItem* items[MAX];
	int size;
	int count;
};

//function to create a hash item
hashItem* createHashItem(string key, int value){
	hashItem* item = new hashItem(); 
	// put key and value parameters, then return item
	item->key = key;
	item->value = value;
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
		table.items[i] = createHashItem("", 0);
	
	}
	
	return table;
}


   // partition function for sort
int partition(hashItem* table[], int low, int high){
	int pivot = table[high]->value; //pivot
	int i = (low - 1); // smaller element
	
	for(int j = low ; j <high;j++){
		
		//check if current is smaller or equal to pivot
		if (table[j]->value >= pivot){
			i++;
			hashItem* temp = table[i];
			table[i] = table[j];
			table[j] = temp;

		}
	}
	hashItem* temp = table[i+1];
			table[i+1] = table[high];
			table[high] = temp;
	return (i+1); // return index
}
 
  // quick sort function: low = start index, high = end index
void quickSort(hashItem* table[], int low, int high){
	//hashTable hashTab =createHashTable(MAX);
	if (low < high){
		// index of partition from partition func
		int partIndex = partition(table, low, high);
		
		// recursively sort sub-array on either side of piviot
		quickSort(table, low, partIndex-1);
		quickSort(table, partIndex+1, high);
	}
}

//SORT #2 FOR KEY


// partition function for sort
int partition2(hashItem* table[], int low, int high){
	string pivot = table[high]->key; //pivot
	int i = (low - 1); // smaller element
	
	for(int j = low ; j <high;j++){
		
		//check if current is smaller or equal to pivot
		if (table[j]->key.compare(pivot)<=0){
			i++;
			hashItem* temp = table[i];
			table[i] = table[j];
			table[j] = temp;
		}
	}
	hashItem* temp = table[i+1];
			table[i+1] = table[high];
			table[high] = temp;
	return (i+1); // return index
}
 
  // quick sort function: low = start index, high = end index
void quickSort2(hashItem* table[], int low, int high){
	int pl = hashFunction("nevermore");
	table[pl]->value --;
	//hashTable hashTab =createHashTable(MAX);
	if (low < high){
		// index of partition from partition func
		int partIndex = partition2(table, low, high);
		
		// recursively sort sub-array on either side of piviot
		quickSort2(table, low, partIndex-1);
		quickSort2(table, partIndex+1, high);
	}
}


//END SORT #2 FOR KEY
 
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
	hashItem* item = createHashItem(key, value);
	int index = hashFunction(key);
	
	hashItem* current = table.items[index];
	if (current->key == ""){ //key doesn't yet exist
		
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
		if (current->key == key){ 
			table.items[index]->value++;
			return;
		}
		else{ //must be collision to handle
			for (int i = index + 1; i < MAX ; i++){
				if (table.items[i]->key == item->key){
					table.items[i]->value++;
					break;
				}
				else if (table.items[i]->key == ""){
					table.items[i]=item;
					table.count++;
					break;
				}
				

			}
			return;
		}

	}
}

int search(string key, hashTable table){
	int index = hashFunction(key);

	if (table.items[index]->key != ""){
		if (table.items[index]->key== key){
			return table.items[index]->value;
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
        if (table.items[i]->key != "") {
        	cout << "Index: "<< i << " | Key: " << table.items[i]->key << " | Value: "<< table.items[i]->value << endl;

        }
    }
    cout << "-------------------------" << endl;
}

// Print Function to meet output requirements
void printOut(hashTable table) {
    for (int i=0; i<table.size; i++) {
        if (table.items[i]->key != "") {
        	cout << table.items[i]->key << " "<< table.items[i]->value << endl;

        }
    }

}

void addWord(string str){
	//insertHashTable(Table, str, 1);
	}
	
//parse string;get rid of non a-z characters + _
string parse(string input, hashTable &Table){	

	int i =0;
	int j = input.size();
	/*while (((int)input[i] < 65 || ((int)input[i] > 90 && ((int)input[i]<97)) 
		|| (int)input[i] > 122) && (int)input[i] !=95){
			newString = input.erase(i, 1);
			
		}
		*/
		
	while ((input.length() >0) &&((int)input[0] < 65 || ((int)input[0] > 90 && ((int)input[0]<97)) 
		|| (int)input[0] > 122) && (int)input[0] !=95){
			input = input.substr(1);

	}
		
		while ((input.length() >0) &&((int)input[input.size()-1] < 65 || ((int)input[input.size()-1] > 90 && ((int)input[input.size()-1]<97)) || (int)input[input.size()-1] > 122) && (int)input[input.size()-1] !=95){
			input = input.substr(0,input.size()-1);
	}
	
	int Index = -1;
	if (input.length() >0){
		for (int i = 0; i<input.length();i++){
			if (((int)input[i] < 65 || ((int)input[i] > 90 && ((int)input[i]<97)) 
		|| (int)input[i] > 122) && (int)input[i] !=95){
			Index = i;
			break;
			}
		}
		if (Index>=0){

			insertHashTable(Table,parse(input.substr(Index), Table) ,1);
			return input.substr(0, Index);
			}
		}
	return input;
}


int main(int argc, char* argv[]){
	hashTable Table = createHashTable(MAX);
	hashTable copyTable = createHashTable(MAX);
	string input;
	string parsed;

	
	while (cin){
		cin >> input;
		parsed = parse(input, Table); //exclude punctuation, etc.

		insertHashTable(Table, parsed, 1);
	}

	copyTable = Table;

	quickSort2(Table.items, 0, MAX-1); //quickSort2 sorts key lexigraphically
	printOut(Table);
	cout << endl;
	quickSort(copyTable.items,0,MAX-1); //quickSort sorts value | low -> high
	printOut(copyTable);
	


return 0;
}
