#include<iostream>
using namespace std;
void phuongan(int f[][100],int M,int k,int a[],int n){
    for(int v=0;v<=M; v++){
        f[1][v]=(a[1]%k==v)?1:0;
        for(int i=2;i<=n;i++){
            for(int v=0;v<=k-1;v++){
                int r=a[i]%k;f[i][v]=f[i-1][v];
                if(v==r and f[i][v]<=f[i-1][0]){
                    f[i][v]=f[i-1][0]+1;
                }
                else if(f[i-1][(v-r+k)%k]>0 and f[i][v]<=f[i-1][(v-r+k)%k]){
                    f[i][v]=f[i-1][(v-r+k)%k]+1;
                }
            }
        }
    
}}
int main(){
int f[100][100],M,k,a[100],n;
cout<<"Nhap so luong A "; cin>>n;
for(int i=1;i<=n;i++){
    cin>>a[i];
}
cout<<"Nhap so chia het "; cin>>k;
phuongan(f,k-1,k,a,n);
for(int i=1;i<=n;i++){
    for(int j=0;j<k;j++){
        cout<<f[i][j]<<"  ";
    }
    cout<<endl;
}

}