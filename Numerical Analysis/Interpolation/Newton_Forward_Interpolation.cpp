#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  int a[n][n+1];
/// taking x values
  for(int i=0; i<n; i++)cin>>a[i][0];

/// taking y values
  for(int i=0; i<n; i++)cin>>a[i][1];

/// making forward difference table
   for(int j=1; j<n+1; j++){
        for(int i=0; i<n-j; i++){
            a[i][j+1] = a[i+1][j] - a[i][j];
        }
   }

   cout<<endl<<"Display forward diff. table"<<endl;
  for(int i=0; i<n; i++){
    for(int j=0; j<n+1-i; j++){
        cout<<a[i][j]<<" ";
    }
    cout<<endl;
  }


  int x;
  cout<<"Enter value of x for which you want to find value of y: "<<endl;
  cin>>x;
  double u = double(x-a[0][0]) / (a[1][0]-a[0][0]);
 // cout<<"u: "<<u<<endl;

  double y = a[0][1];
  int fact=1;
  for(int i=2; i<n+1; i++){
     y = y + (a[0][i]*u)/fact;
     fact = fact*i;
     u = u*(u-i+1);
  }

cout<<"Answer Y = "<<y<<endl;





return 0;
}

/**
5
1891 1901 1911 1921 1931
46 66 81 93 101
**/
