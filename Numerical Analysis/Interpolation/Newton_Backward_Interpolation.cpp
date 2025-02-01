#include<bits/stdc++.h>
using namespace std;
int main(){
 int n;cin>>n;
 int a[n][n+1];
 
 for(int i=0; i<n; i++)cin>>a[i][0];

 for(int i=0; i<n; i++)cin>>a[i][1];

 
 for(int j=2; j<n+1; j++){
    for(int i=0; i<n-j+1; i++){
        a[i][j] = a[i+1][j-1] - a[i][j-1];
    }
 }

  for(int i=0; i<n; i++){
     for(int j=0; j<n+1-i; j++){
        cout<<a[i][j]<<" ";
     }
     cout<<endl;
  }

    cout<<endl<<"Enter year value: ";
     int yval; cin>>yval;

    double y = a[n-1][1];

    double u = double(yval-a[n-1][0]) / (a[1][0]-a[0][0]);
    cout<<"u: "<<u<<endl;
    double fact = 1;

    for(int i=2; i<=n; i++){
        y = y + (u * a[n-i][i])/fact;
        fact = fact*i;
        u = u*(u+i-1);
    }


  cout<<y<<endl;

   return 0;
}
