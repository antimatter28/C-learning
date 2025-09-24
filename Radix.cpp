#include<iostream>
using namespace std;
int tran(string s,int r){  //r进制->10进制 
	int ans=0;
	for(int i=0;i<s.size();i++){
		char t=s[i];
		if(t>='0'&&t<='9')ans=ans*r+t-'0';
		else ans=ans*r+t-'A'+10;
	}
	return ans;
}
string _tran(int a,int r){   //10进制->r进制 
	string ans="",ans1="";
	while(a){
		int t=a%r;
		ans+=t+'0';
		a/=r;
	}
	for(int i=ans.size();i<4;i++)ans+='0';
	for(int i=0;i<4;i++)ans1+=ans[3-i];
	return ans1;
}
int main(){
	string s;
	cin>>s;
	cout<<_tran(tran(s,15),7);
	return 0;
}
