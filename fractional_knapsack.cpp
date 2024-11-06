#include<bits/stdc++.h>
using namespace std;

struct compare
{
    bool operator()(pair<int,int>a,pair<int,int>b)
    {
        return (double)a.first/a.second < (double)b.first/b.second;
    }
};
int fractional_knapsack(vector<pair<int,int>>arr,int capacity)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,compare>pq;
    {
        for(auto p : arr)
        {
            pq.push(p);
        }
    }
    int profit =0;
    while (!pq.empty()&& capacity>pq.top().second)
    {
        capacity=capacity-pq.top().second;
        profit=profit+pq.top().first;
        pq.pop();
        
    }
    if(!pq.empty())
    {
        profit=profit + capacity * (pq.top().first/pq.top().second);
    }
    return profit;
}
int main()
{
    int n,m;
    cout<<"Enter the total no iteam:"<<endl;
    cin>>n;
    vector<pair<int,int>>arr(n);
    for(int i =0 ;i<n;i++)
    {
        cin>>arr[i].first>>arr[i].second;
    }
    cout<<"Enter the capcity of knapsack:"<<endl;
    cin>>m;
    int maxProfit=fractional_knapsack(arr,m);
    cout<<"the fractional knapsack capcity :"<<maxProfit<<endl;
    return 0;

}
