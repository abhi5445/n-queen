#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
        void solve(vector<vector<string>>&ans,vector<string>&board,int col,int n,vector<int>curr_row,vector<int>down_diagnol,vector<int>up_diagnol)
        {
            if(col==n)
            {
                ans.push_back(board);
                return;
            }
            for(int row=0;row<n;row++)
            {
                if(curr_row[row]==1)
                {
                    continue;
                }
                if(down_diagnol[row+col]==1)
                {
                    continue;
                }
                if(up_diagnol[n-1+row-col]==1)
                {
                    continue;
                }

                board[row][col]='Q';
                curr_row[row]=1;
                down_diagnol[row+col]=1;
                up_diagnol[n-1+row-col]=1;

                solve(ans,board,col+1,n,curr_row,down_diagnol,up_diagnol);

                board[row][col]='.';
                curr_row[row]=0;
                down_diagnol[row+col]=0;
                up_diagnol[n-1+row-col]=0;
            }
        }

        vector<vector<string>>solveNqueen(int n)
        {
            vector<vector<string>>ans;
            vector<string>board(n,string(n ,'.'));
            vector<int>curr_row(n,0);
            vector<int>down_diagnol(2* n - 1,0);
            vector<int>up_diagnol(2* n - 1,0);
            solve(ans, board, 0, n, curr_row,down_diagnol,up_diagnol);
            return ans;
        }

};
int main()
{
    Solution solution;
    int n;
    cout<<"Enter the no of queen :"<<endl;
    cin>>n;
    vector<vector<string>>solutions = solution.solveNqueen(n);
    cout<<"The possible solution for"<<n<<"queen:"<<endl4;
    for(const auto& board : solutions)
    {
        for(const auto& row :board)
        {
            cout<<row<<endl;
        }
        cout<<endl;
    }
    return 0;
}
