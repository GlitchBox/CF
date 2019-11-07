#include<bits/stdc++.h>


using namespace std;

int q;
map<int,int> m;

int main()
{
    std::map<int,int>::iterator it;
    int left=100001,right=100001,id;
    string s;
    cin>>q;

    for(int i=0;i<q;i++)
    {
        cin>>s;
        cin>>id;
        if(s=="L")
        {
            m[id] = left;

            if(left == right)
                right++;

            left--;

        }

        else if(s=="R")
        {
            m[id] = right;

            if(left == right)
                left--;

            right++;

        }

        else{

           //it = m.find(id);
            int l = (m.find(id)->second - left)-1;
            int r = (right - m.find(id)->second)-1;

            cout<<min(l,r)<<endl;

        }

    }
}
