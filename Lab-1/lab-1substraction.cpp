#include<bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;


int main(void)
{
  int i,k;
  string a,b,c;
  int test;
  cin>>test;
  while(test--)
  {
  cin>>a;
  cin>>b;
  c="";
  int d=0;
  while(a[d]=='0'&&a.size()>1)
  {
    a.erase(a.begin());
  }
  d=0;
  while(b[d]=='0'&&b.size()>1)
  {
    b.erase(b.begin());
  }
  int n1=a.length();
  int n2=b.length();

  if(n1==n2)
  {
    for(int j=0;j<n1;j++)
    {
      if(a[j]==b[j])
      {
        continue;
      }
      if(a[j]<b[j])
      {
        a.swap(b);
        break;
      }
      if(a[j]>b[j])
      {
        break;
      }
    }
  }
  if(n1<n2)
  {
   a.swap(b);
   int t;
   t=n1;
   n1=n2;
   n2=t;
  }

  reverse(a.begin(),a.end());
  reverse(b.begin(),b.end());

  if(n1!=n2){
  for(i=0;i<n2;i++)
  {
    if(a[i]>=b[i])
    {
      k=a[i]-b[i];
    }
    else
    {
      int l;
      for(l=i+1;l<n1;l++)
      {
        if(a[l]!='0')
        {
          a[l]--;
          break;
        }else
        {
          a.replace(l,1,"9");
          continue;
        }
      }
      k=10+a[i]-b[i];
    }
    c.push_back(k+'0');
  }
    for(i=n2;i<n1;i++)
    {
      k=a[i]-'0';
      c.push_back(k+'0');
    }
 }
 else
 {
   for(i=0;i<n1;i++)
   {
     if(a[i]>=b[i])
     {
       k=a[i]-b[i];
     }
     else
     {
       a[i+1]--;
       k=10+a[i]-b[i];
     }
     c.push_back(k+'0');
  }
 }
  reverse(c.begin(),c.end());
  cout << c<<endl;
}
}
