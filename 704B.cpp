#include<bits/stdc++.h>
#define pii pair<int, int>

using namespace std;

int arra[100010];

int main(){

	int T;
	cin>>T;

	while(T){

		int n;
		cin>>n;
		priority_queue<pii> pq;

		for(int i=0;i<n;i++){
			cin>>arra[i];
			pq.push(make_pair(arra[i], i)); 
		}

		// cout<<pq.size()<<endl;
		int frontMost = n;
		for(int i=0;i<n;i++){

			int tempFront = pq.top().second;
			if(tempFront<frontMost){
				for(int j = tempFront; j<frontMost; j++)
					cout<<arra[j]<<" ";
				frontMost = tempFront;
			}
			pq.pop();
		}
		cout<<endl;

		T--;
	}
}