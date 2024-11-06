#include<iostream>
using namespace std;

int fibonaaci_rec(int n)
{
    if(n==1)
    {
        return 0;
    }
    if(n==2)
    {
        return 1;
    }
    return (fibonaaci_rec(n-1)+fibonaaci_rec(n-2));
}
int fibonaaci_nonrec(int n)
{
    if(n==1)
    {
        return 0;
    }
    if(n==2)
    {
        return 1;
    }
    int f1=0;
    int f2=1;
    int ans;
    for(int i=3;i<=n;i++)
    {
        ans=f1+f2;
        f1=f2;
        f2=ans;
    }
    return ans;
}
int main ()
{
    int n;
    cout<<"Enter the no :"<<endl;
    cin>>n;
    cout<< fibonaaci_rec(n)<<endl;
    cout<<fibonaaci_nonrec(n)<<endl;
}
