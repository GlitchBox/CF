#include<bits/stdc++.h>
using namespace std;

int h[110];

/*
Theory: maximum height of a mountain is 100, there could be at most 100 mountains
*/

int main(){

	int T;
	cin>>T;
	
	while(T){

		int n,k;
		cin>>n>>k;

		for(int i=0;i<n;i++)
			cin>>h[i];

		if(n==1)
			cout<<-1<<endl;
		else{
			int mountain;
			for(int i=0;i<k;i++){
				mountain = 0;
				while(mountain<n-1 && h[mountain]>=h[mountain+1])
					mountain++;
				if(mountain==n-1)
					break;
				h[mountain]++;
			}

			if(mountain==n-1)
				cout<<-1<<endl;
			else
				cout<<mountain+1<<endl;
		}

		T--;
	}
}