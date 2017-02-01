#include <bits/stdc++.h>

using namespace std;

char ch;
string input;

bool check(){

	int state = 0;

	for(int i=0;i<input.length();i++){
		int u = input[i]-'0';

		switch(state){
			case 0:
				if(u==0) state = 1;
				else if(u==1) state = 0;
				else if(u==2) state = 1;
				else return 0;
			case 1:
				if(u==0) state = 4;
				else if(u==1) state = 0;
				else if(u==2) state = 2;
				else return 0;
			case 2:
				if(u==0) state = 0;
				else if(u==1) state = 4;
				else if(u==2) state = 3;
				else return 0;
			case 3:
				if(u==0) state = 2;
				else if(u==1) state = 3;
				else if(u==2) state = 4;
				else return 0;
			case 4:
				if(u==0) state = 4;
				else if(u==1) state = 3;
				else if(u==2) state = 0;
				else return 0;
			default:
				break;
		}
	}

	if(state==4)
		return 1;
	else
		return 0;

}

int main(){

	while(true){
		cin >> input;
		if(input[0]=='-')
			break;

		if(check())
			cout << "String is accepted."<<endl;
		else
			cout << "String is rejected."<<endl;

	}


	return 0;
}