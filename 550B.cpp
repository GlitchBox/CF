#include<bits/stdc++.h>
#define ll long long
#define ifEven 0
#define ifOdd 1
using namespace std;

int a[2010];

ll leastSum(int n);

int main(){

    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    cout<<leastSum(n);

}

ll leastSum(int n){

    ll totalSum = 0;
    for(int i=0;i<n;i++)
        totalSum += a[i];

    //count number of even and number of odd numbers
    int odd = 0, even = 0;

    for(int i=0;i<n;i++){
        if(a[i]%2)
            odd++;
        else
            even++;
    }

    //if there are either no odd or no even number
    if(!even || !odd){
        ll largest = a[0];

        for(int i=1;i<n;i++){
            if(a[i]>largest)
                largest = a[i];
        }

        totalSum -= largest;
    }

    else{

        int diffInNum = abs(odd - even);

        //if difference between number of odd numbers and number of even number is either 0 or 1
        if(diffInNum<2)
            totalSum = 0;

        else{
            priority_queue<int> pq;
            //if there are fewer number of odd numbers, delete all of the odd numbers first
            if(even>odd){

                for(int i=0;i<n;i++){
                    if(a[i]%2)
                        totalSum -= a[i];
                    else
                        pq.push(a[i]);
                }

                for(int i=0;i<=odd;i++){

                    totalSum -= pq.top();
                    pq.pop();
                }
            }
            else{
                for(int i=0;i<n;i++){
                    if(!(a[i]%2))
                        totalSum -= a[i];
                    else
                        pq.push(a[i]);
                }

                for(int i=0;i<=even;i++){
                    totalSum -= pq.top();
                    pq.pop();
                }
            }
        }

    }

    return totalSum;

}
