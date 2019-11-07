#include<bits/stdc++.h>

using namespace std;
int n,r;
int house[1010];
vector<int> heater;
int warm[1010];

void turnAllOn(){

    int b,e;

    for(std::vector<int>::iterator it = heater.begin(); it != heater.end(); it++)
    {
        b = max(((*it) - r + 1),1);
        e = min(((*it) + r - 1),n);

        for(int i = b;i<=e;i++)
            warm[i]++;
    }

}

int onHeater()
{
    int ret,b,e;

    for(int i=1;i<=n;i++)
    {
        if(!warm[i])
            return -1;
    }

    ret = heater.size();
    for(std::vector<int>::iterator it = heater.begin(); it != heater.end(); it++)
    {
             b = max(((*it) - r + 1),1);
             e = min(((*it) + r - 1),n);
             int f = 0;
             for(int i = b;i<=e;i++){

                    if(warm[i]<2){

                        f = 1;
                        break;
                    }
                }

                if(!f){

                    for(int i = b;i<=e;i++){

                        warm[i]--;
                    }
                    ret--;
                }
        }
        return ret;
}





int main()
{
    memset(warm,0,sizeof(warm));
    cin>>n>>r;

    for(int i=1;i<=n;i++)
    {
        cin>>house[i];

        if(house[i])
            heater.push_back(i);
    }

    turnAllOn();
    cout<<onHeater()<<endl;
}
