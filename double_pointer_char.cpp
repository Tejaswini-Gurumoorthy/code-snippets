#include <iostream>
using namespace std;
 
int main()
{
    // Initialize array of pointer
 char **A=new char*[5];
 cout<<"Enter 5 words ";
 for(int i=0;i<5;i++)
 {
     A[i]=new char[10];
     
     cin>>A[i];
 }

 cout<<"The words you entered are : "<<endl;

 for(int i =0;i<5;i++)
 {

     cout<<A[i]<<" ";
 }
cout<<endl;
 
    return 0;
}
