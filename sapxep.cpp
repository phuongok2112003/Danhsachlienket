#include<iostream>
using namespace std;
void inds(int a[],int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void selection_sort(int a[],int n){
    for(int i=0;i<n-1;i++){
        int min=a[i];
        for(int j=i+1;j<n;j++){
            if(a[j]<a[min])
            min=j;
        }
        swap(a[min],a[i]);
        inds(a,n);
    }
}
void bubble_sort(int a[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=n-1;j>i;j--){
            if(a[j]<a[j-1])
            swap(a[j],a[j-1]);
             inds(a,n);
        }
       
    }
}
void insertion_sort(int a[],int n){
    for(int i=1;i<n;i++){
        int x=a[i]; int pos=i-1;
        while(pos>=0 and a[pos]>x){
            a[pos+1]=a[pos];
            pos--;
        }
        a[pos+1]=x;
        inds(a,n);
    }
}
// quick sort đúng rồi nhưng khôngbt in như nào thì đúng 
void quick_sort(int a[],int left,int right){
    int i,j,x;
    x=a[(left+right)/2];
    i=left;
    j=right;
    do{
        while(a[i]<x) i++;
        while(a[j]>x) j--;
        if(i<=j){
            swap(a[i],a[j]);
            inds(a,5);
            i++;
            j--;
        }
    }while(i<j);
    
    if(left<j){
        quick_sort(a,left,j);
    }
    if(right>i){
        quick_sort(a,i,right);
    } 

}
int main(){
    int a[5]={7,5,4,1,6};
    // cout<<"Selection_sort"<<endl;
    // selection_sort(a,5);
   
    // cout<<"Bubble sort"<<endl;
    // bubble_sort(a,5);
    
    // cout<<"insertion_sort"<<endl;
    // insertion_sort(a,5);
    
    cout<<"Quick sort"<<endl;
    quick_sort(a,0,4);
}