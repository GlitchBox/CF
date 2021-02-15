#include<bits/stdc++.h>
using namespace std;

int arr[110];

int main(){

	int t,n;
	cin>>t;

	while(t){

		cin>>n;
		for(int i=0;i<n;i++)
			cin>>arr[i];

		int curr = arr[0], count = 1, largest = 0;
		for(int i=1;i<n;i++){

			if(arr[i] == curr)
				count++;
			else{

				curr = arr[i];
				if(count>largest)
					largest = count;
				count = 1;
			}
		}

		largest = count>largest?count:largest;
		cout<<largest<<endl;

		t--;
	}
}