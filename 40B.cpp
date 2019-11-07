#include<bits/stdc++.h>
using namespace std;

string s;
bool findMatch(int s1, int s2)
{
    int len = s2-s1;

    for(int i=0; i<len; i++)
    {
        if(s[s1+i] != s[s2+i])
            return false;
    }

    return true;
}

int main()
{
    int n,mid ,tempMid,start = 0,operation;
    cin>>n;
    //string s;
    cin>>s;
    mid = n/2;
    operation = n;
    while(mid <= n-2)
    {
        tempMid = mid;

        while(tempMid>start+1)
        {
            if(findMatch(start, tempMid))
            {

                cout<<operation-(tempMid-start)+1<<endl;
                return 0;
            }

            tempMid--;
        }
        start++;
        mid++;
    }
    cout<<operation<<endl;
}
