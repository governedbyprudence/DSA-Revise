//Priority Queue using Binary Heap
#include<iostream>
#include<cmath>
using namespace std;

int H[50];
int length = -1;

int parent(int i){
    return (i-1)/2;
}
int leftchild(int i){
    return 2*i+1;
}
int rightchild(int i){
    return 2*i+2;
}

void swap(int *a,int *b){
     int c = *a;
    *a = *b;
    *b = c;
}
void shift_up(int i){
    while(i>0 && H[parent(i)]<H[i]){
        swap(H[parent(i)],H[i]);
        i=parent(i);
    }
}

void shift_down(int i){
    int max_index = i;

    int l = leftchild(i);

    if(l<length && H[l]>H[max_index]){
        max_index = l ;
    }
     int r = rightchild(i);

    if(l<length && H[r]>H[max_index]){
        max_index = r ;
    }

    if(max_index!=i){
        swap(H[i],H[max_index]);
        shift_down(max_index);
    }
}

void insert(int n){
    length = length +1 ;
    H[length] = n;
    shift_up(length);
}
int pop(){
    int p = H[0];

    H[0]=H[length];
    length=length - 1;
    shift_down(0);
    return p;
}

int display(){
    int i = 0,j,k,l=0;
    for(i=0;l<=length;i++){
        for(j=0;j<=length-i;j++){
            cout<<"   ";
            }
        for(k=1;k<=pow(2,i)&&l<=length;k++){
            cout<<H[l++];
            cout<<"  ";
            
        }
        cout<<endl;
    }
    cout<<endl;
}
 /*            45
            /      \
           31      14
          /  \    /  \
         13  20  7   11
        /  \
       12   7
       */

int main(){
    insert(45);
    insert(20);
    insert(14);
    insert(12);
    insert(31);
    insert(7);
    insert(11);
    insert(13);
    insert(7);
    display();
}