#include <bits/stdc++.h>

using namespace std;

string input;
int n,m,p,a,state,start,k;
map<int,bool> acc;
map< pair<int,int> ,int > table;

int main(){

	cout <<"Number of states : ";
	cin>>m;

	cout <<"Number of accepted states : ";
	cin >> p;
	
	cout <<"Enter accepted states : ";
	for(int i=0;i<p;i++){
		cin >> a;
		acc[a] = 1;
	}

	cout << "Number of input alphabets : ";
	cin >> n;



	// int table[m][n];

	for(int i=1;i<=m;i++){
		for(int j=0;j<n;j++){
			cin >> k;
			if(k<=0 || k>m)
				continue;
			table[make_pair(i,j)] = k;
		}
	}

	cout <<"Start state : ";
	cin >> start;

	while(true){

		state = start;
		cout <<"Enter the input string : ";
		cin >> input;

		if(input[0]=='-')
			break;

		bool hello = 1;

		for(int i=0;i<input.length();i++){
			int ch = input[i]-'0';
			
			state = table[make_pair(state,ch)];
			cout <<input[i]<< "->"<< state<<endl;
			if(state==0){
				hello = 0;
				break;
			}
			
		}

		if(acc[state] && hello)
			cout << "The string is accepted."<<endl;
		else
			cout << "The input string is rejected."<<endl;
	}

	return 0;
}