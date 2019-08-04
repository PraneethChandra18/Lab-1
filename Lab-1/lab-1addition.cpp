#include<bits/stdc++.h>
#include<string>
using namespace std;

int main(void)
{
  int carry=0;
  int k,i;
  string a,b,c,s,r;

  int test;
  cin>>test;
  while(test--)
  {
    cin >> a;
    cin >> b;
    c="";
  int n1=a.length();
  int n2=b.length();
  reverse(a.begin(),a.end());
  reverse(b.begin(),b.end());
  if(n1<n2)
  {
   a.swap(b);
   int t;
   t=n1;
   n1=n2;
   n2=t;
  }
  if(n1!=n2){
  for(i=0;i<n2;i++)
  {
    k=carry+(a[i]-'0')+(b[i]-'0');
    carry=k/10;
    c.push_back(k%10+'0');
  }
  for(i=n2;i<n1;i++)
  {
    if(i!=n1-1)
    {
    k=carry+(a[i]-'0');
    carry=k/10;
    c.push_back(k%10+'0');
    }
    else
    {
      k=carry+(a[i]-'0');
      s = to_string(k);
    }
    }
  }
  else{
    for(i=0;i<n1;i++)
    {
      if(i!=n1-1)
      {
      k=carry+(a[i]-'0')+(b[i]-'0');
      carry=k/10;
      c.push_back(k%10+'0');
      }
      else
      {
        k=carry+(a[i]-'0')+(b[i]-'0');
        s = to_string(k);
      }
    }
  }
    reverse(c.begin(),c.end());
    r=s.append(c);
    cout<<r<<'\n';
  }
}
