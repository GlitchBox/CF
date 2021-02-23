#include<bits/stdc++.h>
using namespace std;

int levels[110];

int main(){

	int T, n;
	cin>>T;

	while(T){

		cin>>n;
		for(int i=0;i<n;i++)
			cin>>levels[i];

		int smallestCount = 0, smallest = levels[0];
		for(int i=1;i<n;i++){

			if(levels[i]<smallest)
				smallest = levels[i];
		}

		for(int i=0;i<n;i++){

			if(levels[i] == smallest)
				smallestCount++;
		}

		cout<<n-smallestCount<<endl;

		T--;
	}
}