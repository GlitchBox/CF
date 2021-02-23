#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll arra[110];

int main(){

	int T;
	cin>>T;

	while(T){

		int n;
		cin>>n;

		for(int i=0;i<n;i++)
			cin>>arra[i];

		for(int i=0;i<n-1;i++){
			// cout<<"\n\nbefore";
			// for(int j=0;j<n;j++)
			// 	cout<<arra[j]<<" ";
			// cout<<endl;

				if(arra[i] && arra[i]>=i){
					arra[i+1] += (arra[i]-i);
					arra[i] = i;
				}
			// cout<<"\n\nafter";
			// for(int j=0;j<n;j++)
			// 	cout<<arra[j]<<" ";
			// cout<<endl;
		}
		// for(int i=0;i<n;i++)
		// 	cout<<arra[i]<<" ";
		// cout<<endl;
		int ifIncreasing = true;
		for(int i=0;i<n-1;i++){
			if(arra[i]>=arra[i+1]){
				ifIncreasing = false;
				break;
			}
		}
		if(ifIncreasing)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;

		T--;
	}
}