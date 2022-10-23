#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
#define gc getchar_unlocked
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, arr) for (auto it = arr.begin(); it != arr.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

const ll mod = 1e9+7;
long long power(long long n, long long m)
{
  if (m == 0)
    return 1;
  if (m == 1)
    return n;
  if (m % 2 == 1)
    return power(n, m - 1) * n % mod;
  else
  {
    long long temp = power(n, m / 2) % mod;
    return temp * temp % mod;
  }
}

void solve()
{
    ll n,k;
    cin>>n>>k;
    vl po(k+3, 0);
    vl fact(k+3, 1);
    for(int i = 1; i<=k+2; i++) po[i] = (po[i-1]+power(i,k))%mod,fact[i] = (fact[i-1]*i)%mod;
    ll ans =  0;
    if(n<=k+2) {
      cout<<po[n]<<"\n";
      return;
    }
    vl ifac(k+3, 0);
    ifac[k+2]=power(fact[k+2],mod-2);
	  for(int i=k+2;i;i--) ifac[i-1]=1ll*ifac[i]*i%mod;
    vl mul(k+3, 1);
    for(int i = 1; i<=k+2; i++) mul[i] = (mul[i-1]*(n-i)) % mod;
    ans = 0;
    for(int i = 1; i<=k+2; i++) {
      ll temp = po[i];
      ll temp2 = power(n-i,mod-2);
      temp2 %= mod;
      temp2 = (mul[k+2] * temp2) % mod;
      temp = (temp * temp2) % mod;
      temp2 = ifac[i-1];
      ll temp3 = ifac[k+2-i];
      temp = (temp*temp2) % mod;
      temp = (temp*temp3) % mod;
      if((k+2-i)%2) ans = (((ans-temp)%mod) + mod) % mod;
      else ans=(ans+temp)%mod;
    }
    cout<<ans<<"\n";
}

int main()
{
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  solve();
  return 0;
}
