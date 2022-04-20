class Solution {
private:
    vector<vector<int>> neighbors = {{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
    int liveNeighbor(int row, int col, vector<vector<int>>& board, int& R, int &C) {
        int cnt = 0;
        for (auto nei : neighbors) {
            int r = row + nei[0];
            int c = col + nei[1];
            if (r >= 0 && r < R && c >= 0 && c < C && board[r][c] == 1)
                cnt++;
        }
        return cnt;
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        int R = board.size(), C = board[0].size();
        vector<vector<int>> tmp = board;
        for (int r = 0; r < R; ++r) {
            for (int c = 0; c < C; ++c) {
                int liveNei = liveNeighbor(r, c, tmp, R, C);
                if (board[r][c] == 1) {
                    if (liveNei < 2 || liveNei > 3) board[r][c] = 0;
                } else {
                    board[r][c] = liveNei == 3 ? 1 : 0;    
                }
            }
        }
    }
};