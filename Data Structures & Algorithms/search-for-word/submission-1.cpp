class Solution {
public:
bool present=false;
void rec(int idx,int i,int j,string word,vector<vector<char>>& board,vector<vector<bool>>visited){
    if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]!=word[idx] || visited[i][j]==true)return ;
    if(idx==word.size()-1)present=true;

    visited[i][j]=true;
    rec(idx+1,i+1,j,word,board,visited);
    rec(idx+1,i-1,j,word,board,visited);
    rec(idx+1,i,j-1,word,board,visited);
    rec(idx+1,i,j+1,word,board,visited);
    //visited[i][j]=false;

}
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++)for(int j=0;j<n;j++)if(board[i][j]==word[0] && !present){
            vector<vector<bool>>visited(m+1,vector<bool>(n+1,0));
            rec(0,i,j,word,board,visited);
        }
        return present;
    }
};
