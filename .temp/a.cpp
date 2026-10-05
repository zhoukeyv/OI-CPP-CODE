#include<bits/stdc++.h>
using namespace std;
#define maxn 1000005
#define mod 1000000007
#define int long long
int n,m,a[maxn],b[maxn],fa[maxn],sza[maxn],szb[maxn],dp[maxn]={1},cnt,num[maxn],id[maxn];
bool used[maxn];
bitset<10005> bs[10005];
set<int> s;
int get(int x){
    if(fa[x]==x){
        return x;
    }
    fa[x]=get(fa[x]);
    return fa[x];
}
void merge(int x,int y){
    x=get(x);
    y=get(y);
    if(x==y){
        return;
    }
    if(sza[x]+szb[x]>sza[y]+szb[y]){
        swap(x,y);
    }
    fa[x]=y;
    sza[y]+=sza[x];
    szb[y]+=szb[x];
    return;
}
void add(int x){
    if(x==0){
        return;
    }
    cnt+=(x>>1);
    for(int j=(n<<1);j>=x;j--){
        dp[j]+=dp[j-x];
        dp[j]%=mod;
    }
    return;
}
void withdraw(int x){
    if(!x){
        return;
    }
    cnt-=(x>>1);
    for(int j=x;j<=(n<<1);j++){
        dp[j]+=mod-dp[j-x];
        dp[j]%=mod;
    }
    return;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=(n<<1);i++){
        fa[i]=i;
        sza[i]=1;
    }
    for(int i=((n<<1)|1);i<=(n<<2);i++){
        fa[i]=i;
        szb[i]=1;
    }
    for(int i=1;i<=(n<<1);i++){
        add(2);
    }
    for(int i=1;i<=m;i++){
        cin>>a[i]>>b[i];
    }
    for(int i=m;i;i--){
        if(get(a[i])==get(b[i])||get(a[i])==get(b[i]+(n<<1))){
            continue;
        }
        withdraw(abs(sza[get(a[i])]-szb[get(a[i])])<<1);
        withdraw(abs(sza[get(b[i]+(n<<1))]-szb[get(b[i]+(n<<1))])<<1);
        add(abs(sza[get(a[i])]-szb[get(a[i])]+sza[get(b[i]+(n<<1))]-szb[get(b[i]+(n<<1))])<<1);
        if(dp[cnt]){
            merge(a[i],b[i]+(n<<1));
            merge(a[i]+(n<<1),b[i]);
        }
        else{
            withdraw(abs(sza[get(a[i])]-szb[get(a[i])]+sza[get(b[i]+(n<<1))]-szb[get(b[i]+(n<<1))])<<1);
            add(abs(sza[get(a[i])]-szb[get(a[i])]+sza[get(b[i])]-szb[get(b[i])])<<1);
            merge(a[i]+(n<<1),b[i]+(n<<1));
            merge(a[i],b[i]);
        }
    }
    bs[0][0]=1;
    for(int i=1;i<=(n<<1);i++){
        if((!s.count(get(i)))&&(!s.count(get(i+(n<<1))))){
            num[++num[0]]=get(i);
            bs[num[0]]=bs[num[0]-1]|(bs[num[0]-1]<<(abs(sza[get(i)]-szb[get(i)])<<1));
            s.insert(get(i));
        }
        if(s.count(get(i))){
            id[i]=get(i);
        }
        else{
            id[i]=get(i+(n<<1));
        }
    }
    int cnt2=cnt;
    for(int i=num[0];i;i--){
        if(bs[i-1][cnt2]){
            continue;
        }
        used[num[i]]=true;
        cnt2-=abs(sza[get(num[i])]-szb[get(num[i])])<<1;
    }
    for(int i=1;i<=(n<<1);i++){
        if(s.count(get(i))^((bool)(used[get(i)]||used[get(i+(n<<1))]))^1^(sza[id[i]]>szb[id[i]])){
            cout<<1;
        }
        else{
            cout<<0;
        }
    }
    return 0;
}