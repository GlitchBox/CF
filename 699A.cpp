#include<bits/stdc++.h>
using namespace std;

int main(){

	int T;
	cin>>T;

	while(T){

		int px, py,finalX=0, finalY=0;
		cin>>px>>py;

		unordered_map<char, int> map;
		map['R'] = 0;
		map['L'] = 0;
		map['U'] = 0;
		map['D'] = 0;

		string s;
		cin>>s;

		for(int i=0;i<s.length();i++){
			map[s[i]]++;

			if(s[i]=='R')
				finalX += 1;
			else if(s[i]=='L')
				finalX -= 1;
			else if(s[i] == 'U')
				finalY += 1;
			else
				finalY -= 1;

		}

		if(finalX==px && finalY == py)
			cout<<"YES"<<endl;
		else{

			int moveX = px - finalX;
			int moveY = py - finalY;

			// cout<<moveX<<", "<<moveY<<endl;
			// cout<<"R"<<map['R']<<endl;
			// cout<<"L"<<map['L']<<endl;
			// cout<<"U"<<map['U']<<endl;
			// cout<<"D"<<map['D']<<endl;

			bool ifPossible = true;
			if(moveX>0){

				if(map['L']>= moveX)
					ifPossible &= true;
				else
					ifPossible &= false;
			}
			else if(moveX<0){
				
				if(map['R']>= -moveX)
					ifPossible &= true;
				else
					ifPossible &= false;
			}

			if(moveY>0){

				if( map['D']>=moveY)
					ifPossible &= true;

				else
					ifPossible &= false;
			}
			else if(moveY<0){

				if(map['U']>= -moveY)
					ifPossible &= true;
				else
					ifPossible &= false;
			}

			if(ifPossible)
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
		}

		T--;
	}
}