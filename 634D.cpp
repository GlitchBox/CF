#include<bits/stdc++.h>

using namespace std;

char sudoku[9][9];

int main(){

  int T;
  cin>>T;

  while(T){
    for(int i=0;i<9;i++){
      for(int j=0;j<9;j++)
        cin>>sudoku[i][j];
    }
    //cout<<"here"<<endl;
    int row = 0, col=0;
    while(row<9){
      int index = 0;
      while(index<3){
        if(sudoku[row][col+index*3]=='9')
          sudoku[row][col+index*3]='8';
        else
          sudoku[row][col+index*3]='9';
        row++;
        index++;
      }
      col++;

    }

    cout<<endl;
    for(int i=0;i<9;i++){
      for(int j=0;j<9;j++)
        cout<<sudoku[i][j];
      cout<<endl;
    }
    //cout<<endl;
    T--;
  }
}
