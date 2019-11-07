#include<bits/stdc++.h>
#define ll long long
using namespace std;
int bits[32];
vector<int> output;

int first1(int x);
int lastOneBefore0(int x);

int main(){

    for(int i=0,j=2;i<32;i++,j*=2){
        bits[i] = j-1;
    }
    //for(int i=0;i<10;i++)
    //    cout<<bits[i]<<endl;

    int x;
    cin>>x;

    //cout<<first1(x)<<endl;
    //cout<<lastOneBefore0(x)<<endl;
    //while(1);
    int operations = 0;
    for(int i=1;i<=40;i++){
        //check if the number is already a perfect number
        int firstOne = first1(x);
        //cout<<firstOne<<endl;
        if(bits[firstOne] == x)
            break;

        //odd operation
        if(i%2){
            int firstZero = lastOneBefore0(x);
            output.push_back(firstZero+1);
            x = x^bits[firstZero];
        }
        else{
            x++;
        }
        operations++;
        //cout<<"operation: "<<operations<<" x: "<<x<<endl;

    }
    cout<<operations<<endl;

    for(int i=0;i<output.size();i++)
        cout<<output[i]<<" ";
    cout<<endl;

}

int first1(int x){
    int a = 1;
    a = a<<31;

    int i;
    for(i=0;i<32;i++){
        if(x&a)
            return 31-i;
        a = a>>1;
    }

    return -1;
}

int lastOneBefore0(int x){

    int firstOne = first1(x);

    int a = 1;
    a = a<<(firstOne - 1);
   // cout<<a<<endl;

    for(int i=firstOne-1;i>=0;i--){
        if(!(a&x))
            return i;
        a = a>>1;
    }

    return -1;
}

