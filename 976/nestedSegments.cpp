/*
*greedy
*使用struct类型进行排序
*/
#include<iostream>
#include<algorithm>
#include<utility>
using namespace std;
const int N = 3e5 + 10;
struct seg
{
	int l, r, se;
}lr[N];

bool cmp(const seg &a, const seg &b)
{
	if (a.l == b.l)
		return a.r>b.r;
	else return a.l<b.l;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> lr[i].l >> lr[i].r;
		lr[i].se = i + 1;
	}
	sort(lr, lr + n, cmp);
	for (int i = 0; i < n - 1; i++){
		if (lr[i + 1].r <= lr[i].r){
			cout << lr[i + 1].se << " " << lr[i].se;
			return 0;
		}
	}
	cout << -1 << " " << -1;
	return 0;

}