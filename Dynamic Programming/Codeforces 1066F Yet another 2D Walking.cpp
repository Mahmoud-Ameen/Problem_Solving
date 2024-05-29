/*
 * Problem link: https://codeforces.com/problemset/problem/1066/F
 * */

#include <bits/stdc++.h>
#define int ll

// Data types/structures
#define ll long long
#define ull unsigned long long
#define V vector
#define VI vector<int>
#define VLL vector<ll>
#define PII pair<int,int>
#define PLL pair<ll,ll>

// Loops/ iterators
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define fr(a,target) for (int a=0;a<target;a++)
#define frl(a,target) for (ll a=0;a<target;a++)
#define frr(a,start,target) for (int a=start;a<target;a++)

// input/output
#define cin(vec) for(auto& ____ : vec) cin >> ____
#define cout(vec) for(auto& ____ : vec) cout << ____ <<" "
#define in(i) int i;cin>>i
#define inl(i) ll i;cin>>i
#define ins(i) string i;cin>>i
#define cyes cout << "YES\n"
#define cno cout << "NO\n"

int dx[] = { 0,1,-1,0 };
int dy[] = { 1,0,0,-1 };

using namespace std;

///////// In the name of Allah the Almighty ////////
////////////////////// Mahmoud /////////////////////

/*
 * levelRange: map<int,pair<point,point>>
 * while nextLevel doesn't exist
 *      option 1 = distance(currPoint, levelRange[nextLevel].first) + solve(levelRange[nextLevel].second)
 *      option 2 = distance(currPoint, levelRange[nextLevel].second) + solve(levelRange[nextLevel].first)
 * */

VI levels;
map<int,pair<PII,PII>> levelRange;

map<PII,int> dp;

int dist (const PII& a, const PII& b) {
    return abs(a.first - b.first) + abs(a.second-b.second);
}

int solve(const PII& point){

    if(dp.find(point) != dp.end()) return dp[point];

    int lvl = max(point.first, point.second);
    auto next = upper_bound(all(levels),lvl);
    if(next == levels.end()) return 0;

    int levelLength = dist(levelRange[*next].first,levelRange[*next].second);
    int option1 = dist(point,levelRange[*next].first) + solve(levelRange[*next].second);
    int option2 = dist(point,levelRange[*next].second) + solve(levelRange[*next].first);

    return dp[point] = min(option1, option2) + levelLength;
}

void Ma7moud() {
    in(n);

    fr(i,n){
        in(x);
        in(y);

        int lvl = max(x,y);
        if(levelRange.find(lvl) == levelRange.end())
            levelRange[lvl] = {{x,y},{x,y}}, levels.push_back(lvl);

        PII st = {0,lvl};
        PII point = {x,y};
        if(dist(st, levelRange[lvl].first) > dist(st,point))
            levelRange[lvl].first = point;
        if(dist(st, levelRange[lvl].second) < dist(st,point))
            levelRange[lvl].second = point;
    }

    sort(all(levels));
//    for(auto& p:levelRange)
//        cout << "LEVEl " << p.first << ": " << p.second.first.first <<", " << p.second.first.second <<" -> " <<
//                             p.second.second.first <<", " << p.second.second.second  <<endl;

    PII origin = {0,0};
    cout << solve(origin);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Ma7moud();
}