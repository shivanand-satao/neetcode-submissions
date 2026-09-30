class Solution {
public:
// bool check_in_row(int i,int j,char val,vector<vector<char>>& b){
// for(int col=0;col<9;col++)if(col!=j && b[i][col]==val)return 1;return 0;
// }
// bool check_in_col(int i,int j,char val,vector<vector<char>>& b){
// for(int row=0;row<9;row++)if(row!=i && b[row][j]==val)return 1;return 0;
// }
//  bool check_in_box(int i,int j,char val,vector<vector<char>>& b){
//         int startRow = (i/3) * 3;
//         int startCol = (j/3) * 3;
//         for(int r=startRow; r<startRow+3; r++){for(int c=startCol; c<startCol+3; c++){
//                 if((r!=i || c!=j) && b[r][c]==val) return true;
//             }
//         }
//         return false;
//     }
  bool isValidSudoku(vector<vector<char>>& b) {
// for(int i=0;i<9;i++)for(int j=0;j<9;j++)if(b[i][j]!='.' && (check_in_row(i,j,b[i][j],b) || check_in_col(i,j,b[i][j],b) || check_in_box(i,j,b[i][j],b)))return 0;return 1;
//     }


vector<vector<bool>>row(9,vector<bool>(9,0));
vector<vector<bool>>col(9,vector<bool>(9,0));
vector<vector<bool>>box(9,vector<bool>(9,0));
for(int i=0;i<9;i++)for(int j=0;j<9;j++){if(b[i][j]!='.' && (row[i][(b[i][j]-'0')-1] || col[j][(b[i][j]-'0')-1] || box[(i/3)*3+(j/3)][(b[i][j]-'0')-1]))return 0;if(b[i][j]!='.'){row[i][(b[i][j]-'0')-1]=true;col[j][(b[i][j]-'0')-1]=true;box[(i/3)*3+(j/3)][(b[i][j]-'0')-1]=true;}}return 1;

  }
};
