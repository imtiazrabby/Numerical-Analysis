#include<bits/stdc++.h>
using namespace std;
const int n=3;

void print(double mat[n][n+1]){
    for(int i=0; i<n; i++){
        for(int j=0; j<n+1; j++){
            cout << mat[i][j] <<"  ";
        }
      cout<<endl;
    }
}

int main(){

 double mat[n][n+1];

 cout<<"\n Enter value: \n";
 for(int i=0; i<n; i++){
    for(int j=0; j<n+1; j++){
        cout<<"mat["<< i <<"]["<< j <<"]=";
        cin>>mat[i][j];
    }
    cout<<endl;
 }

/// Convert to upper triangular matrix
double ratioo;
for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
        if(j>i){
            ratioo = double(mat[j][i]) / mat[i][i];

            for(int k=0; k<n+1; k++){
                mat[j][k] = mat[j][k] - (ratioo * mat[i][k]);
            }
        }
    }
}

cout<<"Upper triangular matrix: "<<endl;
print(mat);

return 0;
}
