#include<bits/stdc++.h>
#define ll long long
#define inf 100000000
using namespace std;

int hh,mm,H,D,C,N;

int main()
{
    std::cout << std::fixed;
    std::cout << std::setprecision(5);

    cin>>hh>>mm;
    cin>>H>>D>>C>>N;

    int wakeAt = hh*60 + mm + 1,current=wakeAt, startDisc = 20*60+1, totalMins = 24*60;
    double spent=inf, disPrice = C*.80,temp;

    if(wakeAt>= startDisc)
    {
        spent = ceil(H/(1.0*N)) * disPrice;
    }

    else
    {
        while(current<=totalMins)
        {
            //H = ((current - wakeAt)*D);

            if(current<startDisc)
            temp = ceil(H/(1.0*N)) * C;

            else
            temp = ceil(H/(1.0*N)) * disPrice;

            if(temp<spent)
            {
                spent = temp;
                //cout<<current/60<<" "<<current%60<<endl;
            }

            //cout<<H<<" "<<current<<" "<<", "<<temp<<endl;
            H += D;
            current++;
        }
    }

    cout<<spent<<endl;
}
