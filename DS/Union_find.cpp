// Union Find Data Structure using 1D array

#include<iostream>
#define size 10 
#define NULL -9999
using namespace std;
int set[size];

int Find(int n){
    int f = n;
    while(set[f]!=NULL){
        f=set[f];
    }

    return f;
}
void Union(int m,int n){
    if(set[n]!=NULL){
        cout<<"Not a parent node";
    }
    else{
        set[n]=m;
    }
}


/*   There are two sets (Disjoint) 
   Set 1  is 0 , 1 , 2
 Set 2 is 3,4 
 Tree for set 1 
          0
            \
            1
            \
            2

 Tree for set 2
     3
      \
       4

Assuming no -1 in set
*/      

int main(){
    set[0] = NULL;   // Root element set 1  
    set[1] = 0;     
    set[2] = 1;     
    set[3] = NULL; // Root element set 2     
    set[4] = 3;           
    cout<<Find(2)<<endl;
    Union(0,3);
    cout<<Find(4);
}