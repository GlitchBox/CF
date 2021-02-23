#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll returnReq(ll p, ll time){

	if(p==time)
		return 0;

	if(p<time)
		return time-p;

	ll ret = p/time;
	if(p%time)
		ret++;
	// cout<<ret<<endl;
	// cout<<(ret*time)<<endl;
	// cout<<(ret*time)-p<<endl;
	return (ret*time - p);
}

int main(){

	int T;
	cin>>T;

	while(T){

		ll p,a,b,c;
		cin>>p>>a>>b>>c;

		ll req1,req2,req3,req;
		req1 = returnReq(p, a);
		req2 = returnReq(p, b);
		req3 = returnReq(p, c);

		req = req1;
		if(req2<req)
			req = req2;
		if(req3<req)
			req = req3;
		cout<<req<<endl;

		T--;
	}
}