#include <bits/stdc++.h>

using namespace std;

int lenSubarr(int A[],  int N, int K) 
   { 
       unordered_map<int,vector<int>>m;
       vector<int>b;
       b.push_back(-1);
       m[0]=b;
       int sum=0;
       int mx=INT_MIN;
       for(int i=0;i<N;i++)
       {
           sum=sum+A[i];
           if(m.find(sum-K)!=m.end())
           {
               vector<int>a=m[sum-K];
               mx=max(mx,i-a[0]);
           }
           
               m[sum].push_back(i);

       }
       if(mx==INT_MIN)
       {
           return 0;
       }
       else
       {
           return mx;
       }
   } 
int main()
{
    int n;
    cout<<"No of elm:";
    cin>>n;
    int arr[n];
    cout<<"input elm:";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int sum;
    cout<<"input sum:";
    cin>>sum;
    
    cout<<lenSubarr(arr,n,sum);

    return 0;
}
