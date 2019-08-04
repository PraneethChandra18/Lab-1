#include<bits/stdc++.h>
#include<string>
using namespace std;

int comparison(string p,string q);
string substract(string p,string q);
int main(void)
{
  int i,j=0;
  int count;
  string a,b,c,t;

  int test;
  cin>>test;
  while(test--)
  {
  cin >> a;
  cin >> b;
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

if(comparison(a.substr(0,n2),b)==1)
{
  t = a.substr(0,n2);
  while(comparison(t,b)==1)
  {
    while(comparison(t,b)==1)
    {
      count=0;
      while(comparison(t,b)==1)
      {

        t=substract(t,b);
        count++;
      }
      c.push_back(count+'0');
    }
    for(i=j;a[n2+i]!='\0';i++)
    {
  if(comparison(t.append(a.substr(n2+i,1)),b)==1)
  {
    j=i+1;
    break;
  }
  else
   {
    c.push_back('0');
   }
  }
 }
}else
{
  t=a.substr(0,n2+1);
    while(comparison(t,b)==1)
  {
    while(comparison(t,b)==1)
    {
      count=0;
      while(comparison(t,b)==1)
      {
        t=substract(t,b);
        count++;
      }
      c.push_back(count+'0');
    }
    for(i=j;a[n2+i+1]!='\0';i++)
    {
  if(comparison(t.append(a.substr(n2+i+1,1)),b)==1)
  {
    j=i+1;
    break;
  }
  else
   {
    c.push_back('0');
   }
  }
 }
}

cout << c << "\n";
cout << t << "\n";
  }
}


int comparison(string p,string q)
{
  int d=0;
  while(p[d]=='0'&&p.size()>1)
  {
    p.erase(p.begin());
  }
  d=0;
  while(q[d]=='0'&&q.size()>1)
  {
    q.erase(q.begin());
  }

  int m1=p.length();
  int m2=q.length();
  if(m1==m2)
  {
  for(int j=0;j<m1;j++)
  {
    if(p[j]==q[j])
    {
      if(j==m1-1)
      {
        return 1;
      }
      continue;
    }
    if(p[j]<q[j])
    {
      return 0;
    }
    if(p[j]>q[j])
    {
      return 1;
    }
   }
  }
  if(m1>m2)
  return 1;
  if(m1<m2)
  return 0;
}
string substract(string p,string q)
{
  int i,k;
  string c;

  int d=0;
  while(p[d]=='0')
  {
    p.replace(d,1,"");
    d++;
    if(p[d]!=0){
      break;
    }
  }
  d=0;
  while(q[d]=='0')
  {
    q.replace(d,1,"");
    d++;
    if(q[d]!=0){
      break;
    }
  }
  int n1=p.length();
  int n2=q.length();

  if(n1==n2)
  {
    for(int j=0;j<n1;j++)
    {
      if(p[j]==q[j])
      {
        continue;
      }
      if(p[j]<q[j])
      {
        p.swap(q);
        break;
      }
      if(p[j]>q[j])
      {
        break;
      }
    }
  }
  if(n1<n2)
  {
   p.swap(q);
   int t;
   t=n1;
   n1=n2;
   n2=t;
  }

  reverse(p.begin(),p.end());
  reverse(q.begin(),q.end());

  if(n1!=n2){
  for(i=0;i<n2;i++)
  {
    if(p[i]>=q[i])
    {
      k=p[i]-q[i];
    }
    else
    {
      int l;
      for(l=i+1;l<n1;l++)
      {
        if(p[l]!='0')
        {
          p[l]--;
          break;
        }else
        {
          p.replace(l,1,"9");
          continue;
        }
      }
      k=10+p[i]-q[i];
    }
    c.push_back(k+'0');
  }
    for(i=n2;i<n1;i++)
    {
      k=p[i]-'0';
      c.push_back(k+'0');
    }
 }
 else
 {
   for(i=0;i<n1;i++)
   {
     if(p[i]>=q[i])
     {
       k=p[i]-q[i];
     }
     else
     {
       p[i+1]--;
       k=10+p[i]-q[i];
     }
     c.push_back(k+'0');
  }
 }
  reverse(c.begin(),c.end());
  return c;
}
