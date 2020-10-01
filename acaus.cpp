/*

        /////////  /////      ////      ///
        //        //   //    //  //  // //
        //////   //    //   //    //   //
            //  // /// //  //         //
      //////// //      // //         //
*/

#include<bits/stdc++.h>
#include<assert.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long ull;
#define Fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define fo(i,s,n) for(int i=s;i<n;i++)
#define mod 1000000007
#define umap unordered_map
#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()
#define lb() lower_bound()
#define ub() upper_bound() 
//fill(all(vec), 1);to fill vector with a number
//if (S.count(key)) returns 1 if set or map contain key else return 0
ll power(ll a,ll b) {
	if(b == 1) return a;
	if(b == 0) return 1;
	ll m1 = power(a,b/2);
	if(b%2) return m1*m1*a;
	return m1*m1;
}


bool isprime(ll a)
{
    if(a<=1)
        return false;
    if(a==2||a==3)
        return true;
    if(a%2==0||a%3==0)
        return false;
    for(ll i=5;i*i<=a;i=i+6)
    {
        if(a%i==0||a%(i+2)==0)
            return false;
    }
    return true;

}
/*********************//*********************///*********************///*********************//
ll t;

void solve()
{
    ll n;
    cin>>n;
    string s;

    cin>>s;
    string p;
    //strcpy(p,s);
    string t="abacaba",a="abacaba";

    size_t found = s.find(t); 
    int flag=0,f=0;
    if (found != string::npos) 
        flag=1;

    char arr[] = "abacaba"; 
    found = s.find(arr, found+1); 
    if (found != string::npos) 
        f=1;
    if(flag==1&&f==1)
    {
        cout<<"No"<<endl;
        return;
    }
    if(flag==1)
    {
        cout<<"Yes"<<endl;
        fo(i,0,s.size())
        {
            if(s[i]=='?')
            {
                cout<<'z';
            }
            else
            {
                cout<<s[i];
            }
            
        }
        cout<<endl;
        return;

    }
    f=0;
    flag=0;
    int pos;
    for(int mask = 0; mask < (1 << 7); mask++) 
    {
	    long long sum_of_this_subset = 0;
        for(int i = 0; i < 7; i++) 
        {
            if(mask & (1 << i)) 
            {
                t[i]='?';
            }
        }
        size_t found = s.find(t); 
        if (found != string::npos) 
        {
            flag=1;
            pos=found;
        }
        char arr[] = "abacaba"; 
        p.replace(pos,7,a);
        found = p.find(arr, found+1); 
        if (found != string::npos) 
        {
            f=1;
            p=s;
            continue;

        }

        if(flag==1&&f==1)
        {
            cout<<"No"<<endl;
            return;
        }
        if(flag==1)
        {
            cout<<"Yes"<<endl;
            int c=1;
            //cout<<"flag="<<pos<<endl;
            fo(i,0,s.size())
            {
                if(i==pos&&c==1)
                {
                    c=0;
                    cout<<"abacaba";
                    i+=7;
                }
                else if(s[i]=='?')
                {
                    cout<<'z';
                }
                else
                {
                    cout<<s[i];
                }
                
            }
            cout<<endl;
            return;

        }
        
    }
    //t="???????";
    
    cout<<"No"<<endl;
    return;
        
	
}
    

     




int main()
{
    Fast
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin>>t;
    for(ll i=1;i<=t;i++)
    {
      solve();
    }

    
    return 0;
}