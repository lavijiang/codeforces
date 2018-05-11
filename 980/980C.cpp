#include <bits/stdc++.h>  
using namespace std;
bool used[260];
int map1[260];

int main(){
	int n, k,nu,tmp;
	cin >> n >> k;
	for (int i = 0; i < 260; i++) map1[i] = i;
	for (int i = 0; i < n; i++){
		cin >> nu;
		if (!used[nu]){
			int tmp = nu;
			while (tmp >= 0 && nu-map1[tmp]<k)
				tmp--;
			tmp++;
			for (int j = tmp; j <= nu; j++){
				used[j] = true;
				map1[j] = map1[tmp];
			}
		}
		cout << map1[nu] << " ";
	}
	
	return 0;
}