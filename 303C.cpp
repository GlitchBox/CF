#include<bits/stdc++.h>
#define ll long long
#define inf 100000007
#define maxSize 100010
using namespace std;

int position[maxSize], height[maxSize];

int maxTrees(int n);

int main(){

    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>position[i];
        cin>>height[i];
    }

    cout<<maxTrees(n)<<endl;

}

int maxTrees(int n){

    int ret=0,lastPoint=0;
    if(n==1)
        return 1;
    else{
        ret = 2;
        lastPoint = position[0];
    }
    for(int i=1;i<n-1;i++){
            int leftPoint = position[i] - height[i];
            int rightPoint = position[i] + height[i];

            //I have space on both sides
            if(leftPoint>lastPoint){
                    lastPoint = position[i];
                    ret++;
            }
            else if(rightPoint<position[i+1]){
                lastPoint = rightPoint;
                ret++;
            }
            else
                lastPoint = position[i];

    }

    return ret;
}
