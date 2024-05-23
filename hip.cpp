#include <bits/stdc++.h>
#define nn "\n"
#define ll long long
#define pb push_back
#define pll pair<ll, ll>
#define vll vector<ll>
#define all(_obj) _obj.begin(), _obj.end()
#define fr(x, y) for (ll x = 0; x < y; x++)
#define nach_basanti                  \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define inp(x) \
    ll x;      \
    cin >> x;
#define inpv(v, n) \
    vll v(n);      \
    fr(i, n) cin >> v[i];
#define printv(v) fr(i, v.size()) cout << v[i] << " ";
#define yes cout << "YES"
#define no cout << "NO"
#define home return;
const ll mod = 1e9 + 7;
using namespace std;
ll n=-1;
void heapify(vector<ll> &vec, ll n, ll i)
{
    ll largest = i;
    ll left = 2 * i + 1;
    ll right = 2 * i + 2;

    if (left < n && vec[left] > vec[largest])
    {
        largest = left;
    }
    if (right < n && vec[right] > vec[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(vec[largest], vec[i]);
        heapify(vec, n, largest);
    }
}
void uparJakeHeapify(vll &vec, ll n, ll i)
{
    ll parent = (i - 1) / 2;
    if (parent >= 0 && vec[parent] < vec[i])
    {
        swap(vec[parent], vec[i]);
        uparJakeHeapify(vec, vec.size(), parent);
    }
}
void insertHeap(ll val, vector<ll> &vec)
{
    n = vec.size();
    n += 1;
    vec.resize(n, val);
    uparJakeHeapify(vec, n, n - 1);
}
int32_t main()
{
    cin>>n;
    inpv(vec, n);
    // for insertion queries
    ll insSize = 0;
    cin >> insSize;
    vll query;
    for (int i = 0; i < insSize; i++)
    {
        ll x;
        cin >> x;
        query.emplace_back(x);
    }
    for (ll i = vec.size() / 2 - 1; i >= 0; i--)
    {
        heapify(vec, vec.size(), i);
    }
    // heapified vector ready for insertion
    printv(vec);
    cout << nn;
    // insertion is done over here   
    for (auto &it : query)
    {
        insertHeap(it, vec);
        printv(vec);
        cout << nn;
    }

    cout<<"Deletion Begins and thus the sorting"<<nn;
    n=vec.size();
    for(int i=0;i<n;i++){
        swap(vec[0],vec[n-1-i]);
        heapify(vec,n-i-1,0);
    }
    // sorted vector i believe it to be
    printv(vec);cout<<nn;
    return 0;
}