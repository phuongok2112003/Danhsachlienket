#include<iostream>
#include<iomanip>
using namespace std;
class hocsinh{
    private:
    string ten;
    int diem;
    public:
    friend istream &operator >>(istream &in,hocsinh &a){
        
        cout<<"Nhap ten hoc sinh "; getline(in,a.ten);
        cout<<"Nhap diem cua hoc sinh ";in>>a.diem;
        cin.ignore();
        return in;
    }
    friend ostream& operator <<(ostream&out,hocsinh a){
        out<<a.ten<<setw(10)<<a.diem<<endl;
        return out;
    }
    int getdiem(){
        return diem;
    }

};
//cách day code lại lần nữa
struct node{
    hocsinh data;
   struct node *next;

};
typedef node * Node;
void khoitaoList(Node &pHead){
    pHead=new node;
    pHead=nullptr;
    cout<<"Danh sach duoc khoi tao "<<endl;

}

Node khoitaoNode(){
    hocsinh a;
    cout<<"Nhap diem cua hoc sinh  \n"; cin>>a;
    Node create=new node;
    create->data=a;
    create->next=NULL;
    return create;
}
void themvaodau(Node &pHead){
    Node tam=khoitaoNode();
    if(pHead==nullptr){
        pHead=tam;
    }else{
        tam->next=pHead;
        pHead=tam;
    }
}
void themvaodit(Node &pHead){
    Node tam=khoitaoNode();
    if(pHead==nullptr){
        pHead=tam;
    }else{
        Node p=pHead;
        while(p->next!=nullptr){
            p=p->next;
        }
        p->next=tam;
    }
}
void inlist(Node pHead){
    for(Node p=pHead;p!=NULL;p=p->next){
        cout<<"Hoc sinh thu "<<endl;
        cout<<p->data;
    }
}
void sapxep(node* &pHead){
        for(Node p=pHead;p->next!=NULL;p=p->next){
            Node temp=p;
            for(Node q=p->next;q!=NULL;q=q->next){
                if(q->data.getdiem()>temp->data.getdiem()){
                    temp=q;
                }
            }
            swap(p->data,temp->data);

    }
}
int main(){
 node *list;
 khoitaoList(list);
 themvaodau(list);
 themvaodau(list);
 themvaodit(list);
 themvaodit(list);
 sapxep(list);
 inlist(list);
}