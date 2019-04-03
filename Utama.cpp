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
void hapusNodeDepan(){
	nodeLinkedList *hapus;
	if(tailKosong()==0){
		int dta;
		hapus = head;
		dta = head->data;
		if(head != tail){
			hapus = head;
			head = head->next;
			tail->next = head;
			delete hapus;
		}
		else{
			head = NULL;
			tail = NULL;
		}
		cout << "Node Depan Terhapus";
		}
		else
			cout << "Linked List Masih Kosong";
}

void hapusNodeBelakang(){
	nodeLinkedList *hapus, *bantu;
	if(tailKosong()==0){
		int dta;
		if(head==tail){
			dta = tail->data;
			head = NULL;
			tail = NULL;
		}
		else{
			bantu = head;
			while(bantu->next != tail){
				bantu = bantu->next;
			}
			hapus = tail;
			tail = bantu;
			dta = hapus->data;
			tail->next = head;
			delete hapus;
		}
		cout << "Node Belakang Terhapus";
		}
		else
			cout << "Linked List Masih Kosong";
}
void tambahNode(int dataBaru, int dataSebelum){
	nodeLinkedList *nodeBaru, *bantu, *batas;
	int cek = 1;
	nodeBaru = new nodeLinkedList;
	nodeBaru->data = dataBaru;
	nodeBaru->next = nodeBaru;
	bantu = head;
	if(head->data==dataSebelum){
		nodeBaru->next = head;
		head = nodeBaru;
		tail->next = head;
		cout << "Data Baru Masuk";
	}
	else{
		while((bantu->next)->data!=dataSebelum){
			bantu = bantu->next;
			if(bantu==tail){
				cek = 0;
				break;
			}
		}
		if(cek==0)
			cout << "Angka tidak ditemukan dalam linked list";
		else{
			batas = bantu->next;
			bantu->next = nodeBaru;
			nodeBaru->next = batas;
			cout << "Data Baru Masuk";
		}
	}
}
void hapusNode(int data){
	nodeLinkedList *hapus = new nodeLinkedList;
	nodeLinkedList *bantu = new nodeLinkedList;
	hapus = head;
	for(int i=1; i<data; i++){
		bantu = hapus;
		hapus = hapus->next;
	}
	bantu->next = hapus->next;
}
int main(){
	return 0;

	
	
}
