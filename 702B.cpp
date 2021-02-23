#include<bits/stdc++.h>
using namespace std;

int arra[30010];

int main(){

	int T;
	cin>>T;

	while(T){

		int n;
		cin>>n;

		for(int i=0;i<n;i++)
			cin>>arra[i];

		int cs[3] = {0,0,0};
		for(int i=0;i<n;i++)
			cs[arra[i]%3]++;

		int steps = 0;
		while(cs[0] != cs[1] || cs[1] != cs[2]){
			for(int i=0;i<3;i++){

				if(cs[i] > n/3){
					cs[i] -= 1;
					cs[(i+1)%3] += 1;
					steps++;
					break;
				}
			}
		}
		cout<<steps<<endl;

		T--;
	}
}