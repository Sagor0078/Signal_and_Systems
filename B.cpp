#include<bits/stdc++.h>
using namespace std;
#define ll int64_t
void solve(){
	ll n,m;
	cin>>n>>m;
	vector<ll> a(n+1,0);
	for(ll i=1;i<=n;++i){
		cin>>a[i];
	}
	vector<ll> p(n+2,0);
	vector<ll> s(n+2,0);
	for(ll i=1;i<=n;i++){
		p[i] = p[i-1];
		if(a[i]<a[i-1]){
			p[i] +=(a[i-1]-a[i]);
		}
	}
	// x move to x + 1 and x - 1 if x < x - 1 then count diff otherwise zero
	for(ll i=n;i>=1;i--){
		s[i] = s[i+1];
		if(a[i]<a[i+1]){
			s[i] += (a[i+1] - a[i]);
		}
	}
	while(m--){
		ll a,b;
		cin>>a>>b;
		ll ans = 0;
		if(a<b){
			ans = p[b]-p[a]; 
		}else{
			ans = s[b] - s[a];
		}
		cout<<ans<<"\n";
	}
}
int main(){
	solve();
}