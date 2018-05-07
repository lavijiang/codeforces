/*
*greedy sort
*/
#include<bits/stdc++.h>
using namespace std;
int n,a,b;
struct item{int h,d;bool operator<(const item&it)const{return h-d>it.h-it.d;}}S[200010];
int main(){
	ios::sync_with_stdio(0);//取消cin与stdin的同步
	cin>>n>>a>>b;
	if(b>n)b=n;
	for(int i=0;i<n;i++)cin>>S[i].h>>S[i].d;
	sort(S,S+n);
	long long mx=0,sum=0;
	for(int i=0;i<n;i++)sum+=i<b&&S[i].h>S[i].d?S[i].h:S[i].d;
	//将所有的第一种操作给一个生物
	for(int i=0;i<n&&b;i++){
		long long tmp=S[i].h;
		tmp<<=a;
		tmp-=S[i].d;
		if(i>=b&&S[b-1].h>S[b-1].d)tmp-=S[b-1].h-S[b-1].d;//把区间内最后一个赋值操作给区间外
		if(i<b&&S[i].h>S[i].d)tmp-=S[i].h-S[i].d;
		if(tmp>mx)mx=tmp;
	}
	cout<<mx+sum;
	return 0;
}