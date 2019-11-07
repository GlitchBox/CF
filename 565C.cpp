#include<bits/stdc++.h>
#define maxSize 1000000
using namespace std;

int numbers[maxSize];
int originalAra[6] = {4,8,15,16,23,42};
queue<int> positions;

int leastDeleted(int n);

int main(){

    int n;
    cin>>n;

    for(int i=0;i<n;i++)
        cin>>numbers[i];
    cout<<leastDeleted(n)<<endl;


}

int leastDeleted(int n){
    int ret = 0;

    //count the number of 4s and put their positions in the stack
    for(int i=0;i<n;i++){
        if(numbers[i] == 4){
            positions.push(i);
            ret++;
        }
    }


    for(int i=1;i<6;i++){

        int temp = 0,prevNumberPopped = 0, index = 0, currentPrevPos = positions.front();
        positions.pop();
        prevNumberPopped++;

        while(index<n && prevNumberPopped<=ret){
               // cout<<originalAra[i-1]<<currentPrevPos<<" "<<numbers[index]<<endl;
                if(numbers[index] == originalAra[i] && index> currentPrevPos){
                    temp++;
                    if(prevNumberPopped<ret){
                        currentPrevPos = positions.front();
                        positions.pop();
                        prevNumberPopped++;
                    }

                    positions.push(index);
                }
                index++;

        }

        while(prevNumberPopped<ret){
            positions.pop();
            prevNumberPopped++;
        }

        if(temp<ret)
            ret = temp;

        //cout<<index<<" "<<ret<<endl;
    }

    ret = n - ret*6;

    return ret;
}
