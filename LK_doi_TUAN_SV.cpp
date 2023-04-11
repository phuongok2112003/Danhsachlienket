#include <iostream>
#include <stdio.h> 
#include <stdlib.h> 
using namespace std;  
 
struct Nut 
{ 
  int data; 
  struct Nut *prev;
  struct Nut *next;
}; 
typedef struct Nut Node;

void listInit(Node* &pHead)			//list initialization
{
	pHead = new Node;
	pHead = NULL;
	cout<<"Danh sach duoc khoi tao! \n";
}

void printList(Node* pHead) 
{ 
    if (pHead == NULL ) 
	{
		cout<<"Danh sach TRONG!\n";
		return;
	}
	
	Node *p = pHead;
	do 
	{						
		cout<< p->data; cout<<"\t";		//In p -> data cua nut p
        p = p->next;						//chuyen nut sau
	} while (p != NULL);
}

void printReverse(Node* pHead) 
{ 
    if (pHead == NULL ) 
	{
		cout<<"Danh sach trong!\n";
		return;
	}
	cout<<"\t";	
	
	Node *p = pHead;
	while (p -> next != NULL) 
		p = p -> next;

	do 
	{						
		cout<< p->data; cout<<"\t";		//In pTail -> data
        p = p->prev;					//chuyen nut sau
	}while (p != NULL);
}
 
Node* creatNode(int x)
{	
	Node* new_node;
	new_node = new Node;
	new_node->data = x;
	new_node->prev = NULL;
	new_node->next = NULL;
	return new_node;
}

void addFirst(Node* &pHead, int x)			//Add the first element into the list
{
	Node *new_node;
	new_node = creatNode(x);
	pHead = new_node; 
}

void insertBegin(Node* &pHead, int x) 
{	
	if (pHead == NULL)
		addFirst(pHead, x);
	else
	{
		Node *new_node;
		new_node = creatNode(x);
		
		new_node->next = pHead;
		pHead->prev = new_node;
		pHead = new_node;			
	}
}

int main() 
{ 
	//Khai báo con trỏ quản lý danh sách
	Node *danh_Sach;
	
	//Khởi tạo danh sách
	listInit(danh_Sach);
	
	//Kiểm tra danh sách rỗng
	if(danh_Sach == NULL)
		cout<<"Danh sach TRONG! \n";
	else
		cout<<"Danh sach da co phan tu! \n";
	
	addFirst(danh_Sach, 9); 
  	cout<<"Phan tu dau tien duoc dua vao danh sach: \t";	
  	printList(danh_Sach);

	cout<<"\nDanh sach khi chen them phan tu thu 2 vao dau: ";	cout<<"\t";
  	insertBegin(danh_Sach, 28);
  	printList(danh_Sach);

  	cout<<"\nDanh sach khi chen them phan tu thu 3 vao dau: ";	cout<<"\t";
  	insertBegin(danh_Sach, -15);
  	printList(danh_Sach);
	
  	cout<<"\n\nDanh sach tu cuoi len dau: ";	cout<<"\t\t";
  	printReverse(danh_Sach);	cout<<"\n";
/*
  	cout<<"\nDanh sach khi chen them phan tu thu 4 vao cuoi: ";
  	insertEnd(danh_Sach, 67);
  	printList(danh_Sach);
	
  	cout<<"\nDanh sach khi chen them phan tu thu 5 (After): ";	cout<<"\t";
  	insertAfter(danh_Sach, danh_Sach->next, 16);		//danh_Sach->next la doi so the cho vao p
  	printList(danh_Sach);
 
  	cout<<"\nDanh sach khi chen them phan tu thu 6 (After): ";	cout<<"\t";
  	insertAfter(danh_Sach, danh_Sach->next->next->next, 128);
  	printList(danh_Sach);
	
  	cout<<"\nDanh sach khi chen them phan tu thu 7 (Before): ";	
  	insertBefore(danh_Sach, danh_Sach->next, 567);
  	printList(danh_Sach);
	
  	cout<<"\nDanh sach khi chen them phan tu thu 8 (Before): ";	
  	insertBefore(danh_Sach, danh_Sach->next->next->next, 1024);
  	printList(danh_Sach);

	cout<<"\n\nDanh sach tu cuoi len dau: ";	cout<<"\t\t\t";
  	printReverse(danh_Sach);
 
 	cout<<"\n\nSo luong phan tu trong danh sach: ";		cout<<"\t\t";
  	cout<<countNode(danh_Sach);
	
//  	cout<<"\n\nCHEN THEM PHAN TU MOI VAO VI TRI XAC DINH:";	cout<<"\t\t";
//  	insertNode(danh_Sach);
//  	cout<<"-> Danh sach sau khi chen: \t\t\t";	
//  	printList(danh_Sach);
 		
	cout<<"\n\n********************************************\n";
  	cout<<"Danh sach sau khi xoa phan tu dau: ";	cout<<"\t\t";
  	deleteFirst(danh_Sach);
  	printList(danh_Sach);
	
  	cout<<"\nDanh sach sau khi xoa phan tu cuoi: ";	cout<<"\t\t";
 	deleteLast(danh_Sach);
  	printList(danh_Sach);
 
	cout<<"\nDanh sach sau khi xoa nut p: ";		cout<<"\t\t\t";
 	deleteNodeP(danh_Sach, danh_Sach->next->next->next);
  	printList(danh_Sach);				cout<<"\n";
  	
//  	cout<<"\n\n********************************************\n";
//  	cout<<"XOA PHAN TU TAI VI TRI XAC DINH:";	cout<<"\t\t";
//  	deleteNode(danh_Sach);
//  	cout<<"-> Danh sach sau khi xoa: \t\t\t";	
//  	printList(danh_Sach);
 	
	cout<<"\n\n********************************************\n";
	cout<<"\nDanh sach sap xep theo thu tu tang dan: \t";		
 	sortList(danh_Sach);		
  	printList(danh_Sach);
 	
	cout<<"\n\n********************************************\n";    	
  	cout<<"TIM KIEM 1 GIA TRI NHAP TU BAN PHIM: \n";
	searchResults(danh_Sach);
 	
	cout<<"\n\n********************************************\n";
	cout<<"XOA 1 NUT CO GIA TRI NHAP TU BAN PHIM: \n";
	deleteDataX(danh_Sach);
	cout<<"\n-> Danh sach sau khi xoa: \t\t\t";
 	printList(danh_Sach);
*/
  	cout<<"\n";
	return 0; 
} 
