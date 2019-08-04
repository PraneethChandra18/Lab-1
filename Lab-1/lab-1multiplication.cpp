#include<bits/stdc++.h>
#include<string>
using namespace std;
string add(string p,string q);
string multiply(string p,char q);

int main(void)
{
  int i;
  string a,b,c;
  string s,r="0";
  int test;
  cin>>test;
  while(test--)
  {
  cin>>a;
  cin>>b;
  c="";
  int n1=a.length();
  int n2=b.length();

  if(n1<n2)
  {
   a.swap(b);
   int t;
   t=n1;
   n1=n2;
   n2=t;
  }
  reverse(b.begin(),b.end());

  for(i=0;i<n2;i++)
  {
    s=multiply(a,b[i]);
    for(int l=0;l<i;l++)
    {
      s.push_back('0');
    }
    r=add(s,r);
  }
  cout<<"\n";
  cout << r;
  cout<<"\n";
}

}


string add(string p,string q)
{
  int carry=0;
  int k,i;
  string r,s,res;

  int n1=p.length();
  int n2=q.length();
  reverse(p.begin(),p.end());
  reverse(q.begin(),q.end());
  if(n1<n2)
  {
   p.swap(q);
   int t;
   t=n1;
   n1=n2;
   n2=t;
  }
  if(n1!=n2){
  for(i=0;i<n2;i++)
  {
    k=carry+(p[i]-'0')+(q[i]-'0');
    carry=k/10;
    r.push_back(k%10+'0');
  }
  for(i=n2;i<n1;i++)
  {
    if(i!=n1-1)
    {
    k=carry+(p[i]-'0');
    carry=k/10;
    r.push_back(k%10+'0');
    }
    else
    {
      k=carry+(p[i]-'0');
      s = to_string(k);
    }
    }
  }
  else{
    for(i=0;i<n1;i++)
    {
      if(i!=n1-1)
      {
      k=carry+(p[i]-'0')+(q[i]-'0');
      carry=k/10;
      r.push_back(k%10+'0');
      }
      else
      {
        k=carry+(p[i]-'0')+(q[i]-'0');
        s = to_string(k);
      }
    }
  }
    reverse(r.begin(),r.end());
    res=s.append(r);
    return res;
}

string multiply(string p,char q)
{
  int k;
  string r,ss;
  int carry=0;
  int n1=p.length();
  reverse(p.begin(),p.end());
  for(int j=0;j<n1;j++)
  {
    if(j!=n1-1)
    {
    k=carry+(p[j]-'0')*(q-'0');
    r.push_back(k%10+'0');
    carry=k/10;
    }
    else
    {
      k=carry+(p[j]-'0')*(q-'0');
      ss=to_string(k);
    }
  }
  reverse(r.begin(),r.end());
  return ss.append(r);
}
