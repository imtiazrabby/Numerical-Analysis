#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
     cin>>n;

    double a[n][n+1];
/// taking value of x
    for(int i=0; i<n; i++){
            cin>>a[i][0];
    }
/// taking value of y
    for(int i=0; i<n; i++) cin>>a[i][1];

/// difference table
cout<<endl;
   for(int j=2; j<n+1; j++){
    for(int i=0; i<n-j+1; i++){
        a[i][j] = a[i+1][j-1] - a[i][j-1];
    }
   }
/// print diff. table
    for(int i=0; i<n; i++){
        for(int j=0; j<n+1-i; j++){
           cout<<a[i][j]<<"  ";
        }
      cout<<endl;
    }

/// Calculating y for given x;
    cout<<endl;
double h = a[1][0]-a[0][0];
double val=0;
double div=1;

   for(int i=2; i<n; i++){
     val = val + ( pow(-1,i) *a[1][i] ) / div;
     div++;
     cout<<( pow(-1,i) *a[1][i] )<<endl;
   }

   cout<<"x="<<a[1][0] <<" y="<< val/h <<endl;


  return 0;
}

/**
7
1.0 1.2 1.4 1.6 1.8 2.0 2.2
2.7183 3.3201 4.0552 4.9530 6.0496 7.3891 9.0250
**/
