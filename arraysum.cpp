#include <bits/stdc++.h>

using namespace std;

int simpleArraySum(vector<int> ar) {
    
    
    int sum=0,n;
    n=ar.size();
     for(int i=0;i<n;i++){
        
         sum=sum+ar[i];
     }
     return sum;

     

}

int main()
{

vector<int>ar;
int n;
cin>>n;

for(int i=0;i<n;i++){
         int x;
         cin>>x;
         ar.push_back(x);
        
     }
cout<<simpleArraySum(ar);
return 0;
}
