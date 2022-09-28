#include<iostream>
#include<stdlib.h>
#include<stack>

using  namespace std;

int main(void ){

    stack <int> mystack;
    int sum =0 ;
    for (int i=0;i<=10;i++){
        mystack.push(i*i+1);
    }
    cout<< "size is "<<mystack.size()<<endl;
    while (!mystack.empty()){
    cout << " " << mystack.top();
    mystack.pop();
    }
    cout<<endl;
    system("pause");
    return 0;

}
