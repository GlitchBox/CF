#include<bits/stdc++.h>
using namespace std;

int arr[10010];
int dp[110];


//with this function I find all the numbers which can be sum of all the lucky numbers.
//I set the corresponding indexes in the dp array to be 1
void recursion(int idx, int currNum, int maxNum, vector<int> &lucky){

	if(idx == lucky.size())
		return;

	int nextNum = currNum;
	while(lucky[idx]+nextNum < maxNum){

		nextNum += lucky[idx];
		dp[nextNum] |= 1;
		recursion(idx+1, nextNum, maxNum, lucky);
	}

	recursion( idx+1, currNum, maxNum, lucky);
}

int main(){

	int t,q,d;
	cin>>t;

	while(t){

		cin>>q>>d;

		for(int i=0;i<q;i++)
			cin>>arr[i];
		
		int maxNum = 10*d;
		vector<int> lucky;
		for(int i=0;i<d;i++)
			lucky.push_back(i*10+d);

		// cout<<"\nlucky numbers: "<<endl;
		// for(int i=0;i<lucky.size();i++)
		// 	cout<<lucky[i]<<" ";
		// cout<<endl;

		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		recursion(0, 0, maxNum, lucky);

		// cout<<"\n\nafter dp: "<<endl;
		// for(int i=0;i<70;i++)
		// 	cout<<"dp["<<i<<"] == "<<dp[i]<<endl;

		for(int i=0;i<q;i++){

			if(arr[i]>=maxNum || dp[arr[i]])
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
		}

		t--;
	}
}