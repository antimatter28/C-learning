#include<iostream>
#include<climits>
#include<cstring>
using namespace std;
const int MAXP=10;
int N,P,E[MAXP],M[MAXP];
int who[MAXP],need[MAXP],take[MAXP],H[MAXP],minTake[MAXP],minH[MAXP];
int minP,minNeed;
void Init(){
	memset(need,0,MAXP);memset(take,0,MAXP);
	minP=INT_MAX,minNeed=INT_MAX;
	H[0]=N;
}
void ReadData(){
	cin>>N>>P;
	for(int i=1;i<=P;i++)cin>>E[i];
	for(int i=1;i<=P;i++)cin>>M[i];
}
void Search1(int k,int dayUse){
	if(k>=minP)return;
	if(k>P)return;
	for(int i=1;i<=P;i++){
		bool b=0;
		for(int j=1;j<k;j++)
			if(who[j]==i)b=1;
		if(b)continue;
		if(H[k-1]*E[i]>=M[i])continue;
		who[k]=i;
		need[k]=need[k-1]+2*H[k-1]*E[i];
		if(k>=minP&&need[k]>=minNeed)continue;
		take[k]=take[k-1]+M[i];
		if(need[k]<=take[k]){
			minNeed=need[k];
			minP=k;
			take[k]=need[k];
			for(int j=1;j<=k;j++){
				minTake[j]=take[j]-take[j-1];
				minH[j]=H[j-1];
			}
		}
		else{
			int d=need[k]-take[k];
			int dayUseNow=dayUse+E[i];
			int w=d/dayUseNow;
			if(w*dayUseNow==d)H[k]=w;
			else H[k]=w+1;
			Search1(k+1,dayUseNow);
		}
	}
}
void Search2(int k,int dayUse){
	if(k>P)return;
	for(int i=1;i<=P;i++){
		bool b=0;
		for(int j=1;j<k;j++)
			if(who[j]==i)b=1;
		if(b)continue;
		if(H[k-1]*E[i]>=M[i])continue;
		who[k]=i;
		need[k]=need[k-1]+2*H[k-1]*E[i];
		if(need[k]>=minNeed)continue;
		take[k]=take[k-1]+M[i];
		if(need[k]<=take[k]){
			minNeed=need[k];
			minP=k;
			take[k]=need[k];
			for(int j=1;j<=k;j++){
				minTake[j]=take[j]-take[j-1];
				minH[j]=H[j-1];
			}
		}
		else{
			int d=need[k]-take[k];
			int dayUseNow=dayUse+E[i];
			int w=d/dayUseNow;
			if(w*dayUseNow==d)H[k]=w;
			else H[k]=w+1;
			Search2(k+1,dayUseNow);
		}
	}
}
int main(){
	ReadData();
	Init();
	Search1(1,0);
	cout<<minP<<" "<<minNeed<<endl;
	for(int i=1;i<=minP;i++)cout<<minTake[i]<<" ";
	cout<<endl;
	for(int i=1;i<=minP;i++)cout<<minH[i]<<" ";
	cout<<endl;
	Init();
	Search2(1,0);
	cout<<minP<<" "<<minNeed<<endl;
	for(int i=1;i<=minP;i++)cout<<minTake[i]<<" ";
	cout<<endl;
	for(int i=1;i<=minP;i++)cout<<minH[i]<<" ";
	return 0;
}
/*
Input:
6 6
1 2 2 2 3 3
7 8 17 18 22 25

Output:
2 42
18 24
6 3
3 38
18 7 13
6 3 2
*/
