#include <iostream>
using namespace std;

struct nodeLinkedList{
	int data;
	nodeLinkedList *next;
};

nodeLinkedList *head, *tail;

void operasiLinkedList(){
	head = NULL;
	tail = NULL;
}
		
int tailKosong(){
	if(tail == NULL)
		return 1;
	else
		return 0;
}
void buatNodeDepan(int dataBaru){
	nodeLinkedList *nodeBaru = new nodeLinkedList;
	nodeBaru->data = dataBaru;
	nodeBaru->next = nodeBaru;
	if(tailKosong()==1){
		head = nodeBaru;
		tail = nodeBaru;
		head->next = head;
		tail->next = tail;
	}
	else{
		nodeBaru->next = head;
		head = nodeBaru;
		tail->next = head;
	}
	cout << "Data Baru Masuk Dari Depan";
}

void buatNodeBelakang(int dataBaru){
	nodeLinkedList *nodeBaru = new nodeLinkedList;
	nodeBaru->data = dataBaru;
	nodeBaru->next = nodeBaru;
	if(tailKosong()==1){
		head = nodeBaru;
		tail = nodeBaru;
		head->next = head;
		tail->next = tail;
	}
	else{
		tail->next = nodeBaru;
		tail = nodeBaru;
		tail->next = head;
	}
	cout << "Data Baru Masuk Dari Belakang";
}
int main(){
	return 0;

	
	
}
