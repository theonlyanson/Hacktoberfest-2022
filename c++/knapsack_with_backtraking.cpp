#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back

int n,c;
vector<pii> v;
int res,aux;
double c2,aux2;
 
void bt(int i){
	if(i == n) return;
 
	aux2 = 0; c2 = c;
	for(int j=i; j<n && c2; j++){
		if(v[j].fi <= c2){
			c2 -= v[j].fi; aux2 += v[j].se;
		} else {
			aux2 += (v[j].se*c2)/v[j].fi;
			c2 = 0;
		}
	}
	if(aux2 + aux <= res) return;
 
	if(v[i].fi <= c){
		c -= v[i].fi;
		aux += v[i].se;
		if(aux > res) res = aux;
		bt(i+1);
		aux -= v[i].se;
		c += v[i].fi;
	}
	bt(i+1);
}
 
int32_t main(){
	ios::sync_with_stdio(false);cin.tie(0);
 
	cin>>n>>c;
	for(int i = 0; i < n; i++)
	{
		int wei,value; cin>>wei>>value;
		v.pb({wei,value});
	}
 
	sort(v.begin(), v.end(), [](pii a, pii b){
		return (a.se+0.0)/a.fi > (b.se+0.0)/b.fi;
	});
 
	bt(0);
	cout<<res<<endl;
 
	return 0;
}
