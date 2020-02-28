#include<bits/stdc++.h>
using namespace std;

int n,m;

int main()
{
    cin>>n>>m;

    if(n==1 || m == 0)
        cout<<n<<" "<<n<<endl;

    else {

        int q = n/m;

        if(q==2)
        {
            cout<<0<<" ";

            if(n-1 == n/2)
                cout<<0<<endl;
            else if(n-1>n/2)
                cout<<n/2<<endl;
        }

        else if(q<2)
        {
            double l = sqrt(1+8*m);
            int x = (int) l;

            x++;
            x = ceil(x/2.0);

            cout<<(n-m-1)<<" "<<x<<endl;
        }

        else
            cout<<(n-m*2)<<" "<<n-m<<endl;
    }
}
