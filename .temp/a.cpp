#ifndef HEADER__
#define HEADER__
#include<bits/stdc++.h>
#define all(x)(x).begin(),(x).end()
using uint128=unsigned __int128;
using uint64=unsigned long long;
using double128=long double;
using uint=unsigned int;
using int128=__int128;
using int64=long long;
const int dic[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
const char dir[4]={'R','L','D','U'};
const int rev[4]={1,0,3,2};
const double eps=1e-6;
const int64 inf=1e18;
template<typename T>
std::vector<T>& operator+=(std::vector<T>& a,const std::vector<T>& b)
{
	a.insert(a.end(),all(b));
	return a;
}
template<typename T>
std::vector<T> operator+(std::vector<T> a,const std::vector<T>& b)
{
	a+=b;
	return a;
}
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
int64 rnd(int64 l,int64 r)
{
	static std::uniform_int_distribution<int64> dis;
	using param_t=std::uniform_int_distribution<int64>::param_type;
	return dis(rng,param_t(l,r));
}
int64 power(int64 a,int64 b,int64 p)
{
	a%=p;
	int64 res=1%p;
	while (b)
	{
		if (b&1)
		{
			res=(int128)res*a%p;
		}
		a=(int128)a*a%p;
		b>>=1;
	}
	return res;
}
#endif
#ifndef FASTIO__
#define FASTIO__
namespace FastIO
{
	const int BUFFER_SIZE=1<<20;
	char ibuf[BUFFER_SIZE],*p1=ibuf,*p2=ibuf;
	char gc()
	{
		if (p1==p2)
		{
			p2=(p1=ibuf)+fread(ibuf,1,BUFFER_SIZE,stdin);
			if (p1==p2)
			{
				return EOF;
			}
		}
		return *p1++;
	}
	struct SetPrec
	{
		int p;
	};
	SetPrec setp(int p)
	{
		return {p};
	}
	struct FastIn
	{
		bool flag=true;
		operator bool()const
		{
			return flag;
		}
		void tie(int){}
		FastIn& operator>>(char& c)
		{
			do
			{
				c=gc();
			}while (c<=32&&c!=EOF);
			if (c==EOF)
			{
				flag=false;
			}
			return *this;
		}
		FastIn& operator>>(char* s)
		{
			char c;
			do
			{
				c=gc();
			}while (c<=32&&c!=EOF);
			if (c==EOF)
			{
				flag=false;
				return *this;
			}
			while (c>32&&c!=EOF)
			{
				*s++=c;
				c=gc();
			}
			*s=0;
			return *this;
		}
		FastIn& operator>>(std::string& s)
		{
			s.clear();
			char c;
			do
			{
				c=gc();
			}while (c<=32&&c!=EOF);
			if (c==EOF)
			{
				flag=false;
				return *this;
			}
			while (c>32&&c!=EOF)
			{
				s.push_back(c);
				c=gc();
			}
			return *this;
		}
		template<typename T,typename std::enable_if<std::is_integral<T>::value||std::is_same<T,int128>::value||std::is_same<T,uint128>::value,int>::type=0>
		FastIn& operator>>(T& x)
		{
			x=0;
			bool f=false;
			char c=gc();
			while ((c<'0'||c>'9')&&c!=EOF)
			{
				if (c=='-')
				{
					f=true;
				}
				c=gc();
			}
			if (c==EOF)
			{
				flag=false;
				return *this;
			}
			uint128 ux=0;
			while (c>='0'&&c<='9')
			{
				ux=ux*10+(c-'0');
				c=gc();
			}
			x=f?-static_cast<T>(ux):static_cast<T>(ux);
			return *this;
		}
		template<typename T,typename std::enable_if<std::is_floating_point<T>::value,int>::type=0>
		FastIn& operator>>(T& x)
		{
			x=0;
			bool f=false;
			char c=gc();
			while ((c<'0'||c>'9')&&c!=EOF)
			{
				if (c=='-')
				{
					f=true;
				}
				c=gc();
			}
			if (c==EOF)
			{
				flag=false;
				return *this;
			}
			while (c>='0'&&c<='9')
			{
				x=x*10+(c-'0');
				c=gc();
			}
			if (c=='.')
			{
				T base=1;
				c=gc();
				while (c>='0'&&c<='9')
				{
					base/=10;
					x+=(c-'0')*base;
					c=gc();
				}
			}
			if (f)
			{
				x=-x;
			}
			return *this;
		}
#ifdef MODINT__
		template<int64 Mod>
		FastIn& operator>>(modint<Mod>& a)
		{
			int64 x=0;
			bool f=false;
			char c=gc();
			while ((c<'0'||c>'9')&&c!=EOF)
			{
				if (c=='-')
				{
					f=true;
				}
				c=gc();
			}
			if (c==EOF)
			{
				flag=false;
				return *this;
			}
			while (c>='0'&&c<='9')
			{
				x=(x*10+(c-'0'))%Mod;
				c=gc();
			}
			a=modint<Mod>::raw(f?(x==0?0:Mod-x):x);
			return *this;
		}
#endif
		template<typename T,typename std::enable_if<std::is_class<T>::value&&!std::is_same<T,std::string>::value,int>::type=0>
		auto operator>>(T& a)->decltype(a.from_string(""),*this)
		{
			std::string s;
			*this>>s;
			a.from_string(s);
			return *this;
		}
	}fin;
	struct FastOut
	{
		FILE* fp;
		std::vector<char> obuf;
		int p3;
		int precision=6;
		FastOut(FILE* fp,int sz):fp(fp),obuf(sz),p3(0){}
		~FastOut()
		{
			flush();
		}
		void flush()
		{
			if (p3)
			{
				fwrite(obuf.data(),1,p3,fp);
				p3=0;
			}
		}
		void pc(char c)
		{
			if (p3==(int)obuf.size())
			{
				flush();
			}
			obuf[p3++]=c;
		}
		FastOut& operator<<(SetPrec sp)
		{
			precision=sp.p;
			return *this;
		}
		FastOut& operator<<(char c)
		{
			pc(c);
			return *this;
		}
		FastOut& operator<<(const char* s)
		{
			while (*s)
			{
				pc(*s++);
			}
			return *this;
		}
		FastOut& operator<<(const std::string& s)
		{
			for (char c:s)
			{
				pc(c);
			}
			return *this;
		}
		template<typename T,typename std::enable_if<(std::is_integral<T>::value&&std::is_signed<T>::value)||std::is_same<T,int128>::value,int>::type=0>
		FastOut& operator<<(T x)
		{
			if (x==0)
			{
				pc('0');
				return *this;
			}
			uint128 ux=x;
			if (x<0)
			{
				pc('-');
				ux=-static_cast<uint128>(x);
			}
			static char stk[64];
			int top=0;
			while (ux)
			{
				stk[++top]=ux%10+'0';
				ux/=10;
			}
			while (top)
			{
				pc(stk[top--]);
			}
			return *this;
		}
		template<typename T,typename std::enable_if<(std::is_integral<T>::value&&std::is_unsigned<T>::value)||std::is_same<T,uint128>::value,int>::type=0>
		FastOut& operator<<(T x)
		{
			if (x==0)
			{
				pc('0');
				return *this;
			}
			static char stk[64];
			int top=0;
			while (x)
			{
				stk[++top]=x%10+'0';
				x/=10;
			}
			while (top)
			{
				pc(stk[top--]);
			}
			return *this;
		}
		template<typename T,typename std::enable_if<std::is_floating_point<T>::value,int>::type=0>
		FastOut& operator<<(T x)
		{
			static char buf[512];
			int len=0;
			if (std::is_same<T,long double>::value)
			{
				len=snprintf(buf,512,"%.*Lf",precision,(long double)x);
			}
			else
			{
				len=snprintf(buf,512,"%.*f",precision,(double)x);
			}
			for (int i=0;i<len;i++)
			{
				pc(buf[i]);
			}
			return *this;
		}
#ifdef MODINT__
		template<int64 Mod>
		FastOut& operator<<(const modint<Mod>& a)
		{
			return *this<<a.val();
		}
#endif
		template<typename T,typename std::enable_if<std::is_class<T>::value&&!std::is_same<T,std::string>::value,int>::type=0>
		auto operator<<(const T& a)->decltype(a.to_string(),*this)
		{
			return *this<<a.to_string();
		}
	};
	FastOut fout(stdout,BUFFER_SIZE);
	FastOut ferr(stderr,1<<12);
}
using FastIO::setp;
#endif
using namespace std;
#ifndef DEBUG
#ifdef FASTIO__
#define cin FastIO::fin
#define cout FastIO::fout
#define cerr FastIO::ferr
#endif
#ifdef ALGORITHM__
#define bitset Bitset
#define deque Deque
#endif
#define endl '\n'
#endif
#define int int64
vector<vector<int>> a,dp;
vector<int> d;
int n,m;
void solve()
{
	a.clear();
	d.clear();
	dp.clear();
	cin>>n>>m;
	d.resize(m+1);
	a.resize(m+1,vector<int>(n+1));
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			cin>>a[j][i];
		}
	}
	for (int i=1;i<=m;i++)
	{
		cin>>d[i];
	}
	if (m>n)
	{
		dp.resize(m+1,vector<int>(1<<n,inf));
		dp[0][0]=0;
		for (int i=1;i<=m;i++)
		{
			for (int j=0;j<(1<<n);j++)
			{
				dp[i][j]=dp[i-1][j];
			}
			for (int j=0;j<n;j++)
			{
				for (int k=0;k<(1<<n);k++)
				{
					if (k>>j&1)
					{
						continue;
					}
					dp[i][k|(1<<j)]=min(dp[i][k]+a[i][j+1],dp[i][k|(1<<j)]);
				}
			}
			for (int j=0;j<1<<n;j++)
			{
				dp[i][j]=min(dp[i][j]+d[i],dp[i-1][j]);
			}
		}
		cout<<dp[m][(1<<n)-1]<<'\n';
	}
	else
	{
		dp.resize(n+1,vector<int>(1<<m,inf));
		dp[0][0]=0;
		for (int i=1;i<=n;i++)
		{
			for (int j=0;j<(1<<m);j++)
			{
				for (int k=0;k<m;k++)
				{
					if (j>>k&1)
					{
						dp[i][j]=min(dp[i][j],dp[i-1][j]+a[k+1][i]);
					}
					else
					{
						dp[i][j|(1<<k)]=min(dp[i][j|(1<<k)],dp[i-1][j]+a[k+1][i]+d[k+1]);
					}
				}
			}
		}
		int ans=inf;
		for (int i=1;i<1<<m;i++)
		{
			ans=min(ans,dp[n][i]);
		}
		cout<<ans<<'\n';
	}
	return;
}
signed main()
{
#ifndef LOCAL_cph
#endif
#ifndef FASTIO__
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
#ifdef DEBUG
#ifdef FASTIO__
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	cout<<'\n';
#endif
	int Testcase=1;
	cin>>Testcase;
	while (Testcase--)
	{
		solve();
	}
	return 0;
}