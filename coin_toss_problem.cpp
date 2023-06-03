
/*
 * Abstract: This program implements the basic idea of the coin collecting problem
 * from lecture. The output displays the maximum coins and the path to obtain them.
 * Name: Saul Mendoza-Loera
 * Date: 12/11/2022
 */

#include <iostream>
#include <vector>
using namespace std;

int row, column, max_coins;
string path;

int main()
{
    int value;
    cin >> row >> column;

    int boardArr[row][column];

    for(int i=0; i < row; i++){
      for(int j = 0; j < column; j++){
        cin >> value;
        boardArr[i][j] = value;
      }
    }


    for(int i = 0; i < row; i++){
      for(int j = 0; j < column; j ++){
        if(i == 0){
          boardArr[i][j] += boardArr[i][j-1];
        }
        else{
          if(j == 0){
            boardArr[i][j] += boardArr[i-1][j];
          }
          else{
            if(boardArr[i-1][j] == boardArr[i][j-1])
            {
              boardArr[i][j] += boardArr[i-1][j];
            }
            else if(boardArr[i-1][j] > boardArr[i][j-1]){
              boardArr[i][j] += boardArr[i-1][j];
            }
            else{
              boardArr[i][j] += boardArr[i][j-1];
            }
          }
        }
      }
    }

    max_coins = boardArr[row-1][column-1];
    vector<pair<int,int>> vec_path;



    int i = row-1, j = column-1;
    vec_path.push_back(make_pair(i,j));
    while( i >= 0 && j >= 0){
      if(j == 0 && i != 0){
        vec_path.push_back(make_pair(i-1, j));
        i--;
      }
      else if(boardArr[i][j-1] == boardArr[i-1][j]){
        vec_path.push_back(make_pair(i, j-1));
        j --;
      }
      else if(boardArr[i][j-1] > boardArr[i-1][j]){
        vec_path.push_back(make_pair(i, j-1));
        j--;
      }
      else{
        vec_path.push_back(make_pair(i-1, j));
        i--;
      }
    }

    for(int i = vec_path.size()-2; i >= 0; i--){
      path.append("("+ to_string(vec_path[i].first+1) + "," + to_string(vec_path[i].second+1) + ")");
      path.append("->");
    }
    path.pop_back();
    path.pop_back();
    cout << "Max coins:" << max_coins << endl;
    cout << "Path:" << path << endl;

}
