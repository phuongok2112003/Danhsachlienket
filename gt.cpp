#include<iostream>
using namespace std;
class VienChuc
{
	private:
		int ma, tuoi;
		string hoten;
		double hsl;

	public:
		VienChuc(int ma=0, string hoten="", int tuoi=0, double hsl=0)
		{
			this->ma = ma;
			this->hoten = hoten;
			this->tuoi = tuoi;
			this->hsl= hsl;
			this->next = NULL;
		}
		
		~VienChuc()
		{}
		
		void Nhap()
		{
			cout<<"Nhap ma: "; cin>>ma;
			cin.ignore();
			cout<<"Nhap ho ten: "; getline(cin, hoten);
			cout<<"Nhap tuoi: "; cin>>tuoi;
			cout<<"Nhap he so luong: "; cin>>hsl;
			
		}
		friend istream& operator >>(istream&in ,VienChuc* &a){
			cout<<"Nhap ma: "; cin>>a->ma;
			cin.ignore();
			cout<<"Nhap ho ten: "; getline(cin, a->hoten);
			cout<<"Nhap tuoi: "; cin>>a->tuoi;
			cout<<"Nhap he so luong: "; cin>>a->hsl;
			return in;
		}
		void In()
		{
			cout << "Ma: "<<ma<<endl<<"Ho ten: "<<hoten<<endl<<"Tuoi: "<<tuoi<<endl<<"He so luong: "<<hsl<<endl;
		}
		
		int get_ma()
		{
			return ma;
		}
		VienChuc *next;

		
};

typedef VienChuc* Node;
void khoitaoList(Node &phead){
	phead=new VienChuc;
	phead=NULL;

	cout<<"khoi tao danh sach\n";
}
void themvaodau(Node &phead){
	Node a=new VienChuc;
	// a->Nhap();
	// a.Nhap();
	cin>>a;
	if(phead==NULL){
		phead=a;
	}
	else{
		a->next=phead;
		phead=a;
	}
}
void themvaodit(Node &phead){
	Node a=new VienChuc;
	a->Nhap();
	if(phead==NULL){
		phead=a;
	}
	else{
		Node p=phead;
		while(p->next!=NULL){
			p=p->next;
		}
		p->next=a;

	}

}
void inlist(Node pHead){
    for(Node p=pHead;p!=NULL;p=p->next){
        cout<<"Hoc sinh thu "<<endl;
        p->In();
    }
}
int main()
{    Node list;
     khoitaoList(list);
	int m; cout<<"-> Nhap so vien chuc: "; cin>>m;
	for(int i=0;i<m;i++){
		themvaodau(list);
	}
	inlist(list);

}