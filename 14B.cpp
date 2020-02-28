#include<bits/stdc++.h>
using namespace std;

double C,F,X, current,spent;

int main()
{
    std::cout << std::fixed;
    std::cout << std::setprecision(7);
    freopen("B-large-practice.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    cin>>T;

    for(int i=1;i<=T;i++)
    {
        cin>>C>>F>>X;
        current = 2;
        spent = 0;

        while((X/current)>((C/current)+(X/(current+F))))
        {
            spent+= (C/current);
            current +=F;
        }

        spent += (X/current);

        cout<<"Case #"<<i<<": "<<spent<<endl;
    }
}

