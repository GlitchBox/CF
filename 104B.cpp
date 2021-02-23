/*
	Theory: if n is even, they will never meet. 
			if n is odd, find out the number of collisions B will have to face
						answer would be (k+collision)%n
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){

	int T;
	cin>>T;

	while(T){

		int n,k;
		cin>>n>>k;
		int answer = 0;

		if(!(n%2)){

			if(!(k%n))
				answer = n;
			else
				answer = k%n;
		}
		else{

			int hours = k;
			int firstCollision = (n+1)/2;
			int collisionPeriod = n/2;
			int totalCollisions = 0;

			if(k<firstCollision)
				answer = k;
			else{
				totalCollisions++;
				hours-= firstCollision;
				totalCollisions += (hours/collisionPeriod);
				k += totalCollisions;

				if(!(k%n))
					answer = n;
				else
					answer = k%n;
			}
		}
		cout<<answer<<endl;

		T--;
	}
}