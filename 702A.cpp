#include<bits/stdc++.h>
using namespace std;

// bool ifPower2(double mult){

// 	if(ceil(mult) != floor(mult))
// 		return false;

// 	double power = log(mult)/log(2);
// 	if(ceil(power) != floor(power))
// 		return false;

// 	return true;
// }

int arra[60];
int main(){

	int T;
	cin>>T;

	while(T){
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>arra[i];

		int additions = 0;
		for(int i=0;i<n-1;i++){

			int maxNum = max(arra[i], arra[i+1]);
			int minNum = min(arra[i], arra[i+1]);
			// cout<<"maxNum,minNum: "<<maxNum<<", "<<minNum<<endl;

			double mult = (maxNum*1.0)/minNum;
			// cout<<"mult: "<<mult<<endl;

			if(mult>2.0){


				int tempAdditions = 0;
				int tempMin = minNum;

				while(mult>2.0){
					tempAdditions++;
					tempMin*=2;
					mult = (maxNum*1.0)/tempMin;
				}
				additions += tempAdditions;
			}
		}

		cout<<additions<<endl;

		T--;
	}
}