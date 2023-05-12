#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    int a[100],c[1000],f[100][100],M;
    int n;
    cout<<"Nhap so luong do vat "; cin>>n;
    cout<<"Nhap C va A "<<endl;
    a[0]=c[0]=0;
    for(int i=1;i<=n;i++){
        
        cin>>c[i];
        cin>>a[i];
    }
    cout<<"Nhap trong luong cua balo la "; cin>>M;
    for(int v=0;v<=M;v++) f[0][v]=0;
    for(int i=1;i<=n;i++){
        for(int v=1;v<=M;v++){
            f[i][v]=f[i-1][v];
            if(a[i]<=v and f[i][v]<(f[i-1][v-a[i]])+c[i]){
                f[i][v]=f[i-1][v-a[i]]+c[i];
            }
        }
    }
    cout<<"Bang gia tri la "<<endl;
    cout<<setfill('-');
    cout<<right<<"+"<<setw(100)<<"+"<<endl;
    cout<<setfill(' ');
    cout<<right<<setw(3)<<"C"<<setw(3)<<"|"<<setw(3)<<"A"<<setw(3)<<"|"<<setw(4)<<"i\\v"<<setw(3)<<"|";
    for(int i=0;i<=M;i++){
        cout<<setw(3)<<i<<setw(3)<<"|";
    }
    cout<<endl;
    for(int i=0;i<=n;i++){
            cout<<setfill('-');
            cout<<right<<"+"<<setw(100)<<"+"<<endl;
            cout<<setfill(' ');
            cout<<right<<setw(3)<<c[i]<<setw(3)<<"|"<<setw(3)<<a[i]<<setw(3)<<"|"<<setw(4)<<i<<setw(3)<<"|";
        for(int v=0;v<=M;v++){

           cout<<setw(3)<<f[i][v]<<setw(3)<<"|";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"Truy vet "<<endl;
    int v=M;
    for(int i=n;i>0;i--){
        if(f[i][v]!=f[i-1][v]){
           
            cout<<"Mon hang thu "<<i<<" duoc chon "<<endl;
             cout<<"dong "<<i<<" cot "<<v<<endl;
            v=v-a[i];
        } else{
            cout<<"Mon hang thu "<<i<<" khong duoc chon"<<endl;
              cout<<"dong "<<i<<" cot "<<v<<endl;
        }
    }
}