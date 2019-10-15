//
//  main.cpp
//  minesweeper
//
//  Created by 王子昱 on 2019/10/13.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

//class Solution {
//public:
//    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
//        int click_x = click[0];
//        int click_y = click[1];
//        updateBoard(board, click_x, click_y);
//        return board;
//    }
//
//    void updateBoard(vector<vector<char>>& board, int click_x, int click_y)
//    {
//        if (board[click_x][click_y] == 'M') {
//            board[click_x][click_y] = 'X';
//            return;
//        }
//        else
//        {
//            int c = 0;
//            if (click_x > 0) {
//                if (board[click_x-1][click_y] == 'M') {
//                    c += 1;
//                }
//                if (click_y > 0) {
//                    if (board[click_x-1][click_y-1] == 'M') {
//                        c += 1;
//                    }
//                    if (board[click_x][click_y-1] == 'M') {
//                        c += 1;
//                    }
//                }
//                if (click_y < board[0].size() - 1) {
//                    if (board[click_x-1][click_y+1] == 'M') {
//                        c += 1;
//                    }
//                    if (board[click_x][click_y+1] == 'M') {
//                        c += 1;
//                    }
//                }
//            }
//            else if(click_x < board.size()-1)
//            {
//                if (board[click_x+1][click_y] == 'M') {
//                    c += 1;
//                }
//                if (click_y > 0) {
//                    if (board[click_x+1][click_y-1] == 'M') {
//                        c += 1;
//                    }
//                    if (board[click_x][click_y-1] == 'M') {
//                        c += 1;
//                    }
//                }
//                if (click_y < board[0].size() - 1) {
//                    if (board[click_x+1][click_y+1] == 'M') {
//                        c += 1;
//                    }
//                    if (board[click_x][click_y+1] == 'M') {
//                        c += 1;
//                    }
//                }
//            }
//            char aChar = '0' + c;
//            board[click_x][click_y] = aChar;
//
////
//            if (click_x > 0) {
//                if (board[click_x-1][click_y] == 'M') {
//                    updateBoard(board, click_x-1, click_y);
//                }
//                if (click_y > 0) {
//                    if (board[click_x-1][click_y-1] == 'M') {
//                        updateBoard(board, click_x-1, click_y-1);
//                    }
//                    if (board[click_x][click_y-1] == 'M') {
//                        updateBoard(board, click_x, click_y-1);
//                    }
//                }
//                if (click_y < board[0].size() - 1) {
//                    if (board[click_x-1][click_y+1] == 'M') {
//                        updateBoard(board, click_x-1, click_y+1);
//                    }
//                    if (board[click_x][click_y+1] == 'M') {
//                        updateBoard(board, click_x, click_y+1);
//                    }
//                }
//            }
//            else if(click_x < board.size()-1)
//            {
//                if (board[click_x+1][click_y] == 'M') {
//                    updateBoard(board, click_x+1, click_y);
//                }
//                if (click_y > 0) {
//                    if (board[click_x+1][click_y-1] == 'M') {
//                        updateBoard(board, click_x+1, click_y-1);
//                    }
//
//                }
//                if (click_y < board[0].size() - 1) {
//                    if (board[click_x+1][click_y+1] == 'M') {
//                        updateBoard(board, click_x+1, click_y+1);
//                    }
//
//                }
//            }
//
//        }
//    }
//};

class Solution {
public:
    
    int dr[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    int dc[8] = {1, 1, 0, -1, -1, -1, 0, 1};
    int stat[50][50];
    typedef pair<int, int> Point;
    
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int r_size = board.size();
        int c_size = board[0].size();
        queue<Point> que;
        if (board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        }
        memset(stat, 0, sizeof(stat));
        que.push({click[0], click[1]});
        stat[click[0]][click[1]] = 1;
        
        while (!que.empty()) {
            Point p = que.front();
            que.pop();
            int count = 0, r = p.first, l = p.second;
            for (int i = 0; i < 8; i ++) {
                int nnr = r + dr[i];
                int nnc = l + dc[i];
                if (nnr >= 0 && nnr < r_size && nnc >= 0 && nnc < c_size && (board[nnr][nnc] == 'M' || board[nnr][nnc]=='X')) {
                    count += 1;
                }
            }
            if (count > 0) {
                board[r][l] = '0' + count;
            }
            else
            {
                board[r][l] = 'B';
                for (int i = 0; i < 8; i ++) {
                    int nnr = r + dr[i];
                    int nnc = l + dc[i];
                    if (nnr >= 0 && nnr < r_size && nnc >= 0 && nnc < c_size && stat[nnr][nnc] == 0 && stat[nnr][nnc] == 'E') {
                        que.push({nnr, nnc});
                        stat[nnr][nnc] = 1;
                    }
                }
            }
        }
        return board;
    }
};

class Solution2
{
public:
    //右 -> 右下 -> 下 -> 左下 -> 左 -> 左上 -> 上 -> 右上
    int dr[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    int dc[8] = {1, 1, 0, -1, -1, -1, 0, 1};
    int stat[50][50];                               //状态
    typedef pair<int, int> Point;
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click)
    {
        int rsize = board.size(), csize = board[0].size();
        queue<Point> que;
        
        //点击到地雷
        if(board[click[0]][click[1]] == 'M')
        {
            board[click[0]][click[1]] = 'X';
            return board;
        }
        
        //初始化状态
        memset(stat, 0, sizeof(stat));
        que.push({click[0], click[1]});
        stat[click[0]][click[1]] = 1;
        
        while(!que.empty())
        {
            Point p = que.front(); que.pop();
            
            //计算相邻的地雷的数量
            int cnt = 0, r = p.first, c = p.second;
            for(int i = 0; i != 8; ++i)
            {
                int nnr = r + dr[i], nnc = c + dc[i];
                //没有越界, 并且为地雷的情况。
                if(nnr >= 0 && nnr < rsize && nnc >= 0 && nnc < csize
                   && (board[nnr][nnc] == 'M' || board[nnr][nnc] == 'X'))
                    ++cnt;
            }
            
            // 如果有地雷, 直接揭露。
            if(cnt > 0)
                board[r][c] = cnt + '0';
            
            // 否则揭露为B, 并增广其相邻的元素
            else
            {
                board[r][c] = 'B';
                for(int i = 0; i != 8; ++i)
                {
                    int nnr = r + dr[i], nnc = c + dc[i];
                    //相邻的顶点没有越界, 并且没有被增加到增广队列当中, 且没有被翻过为E
                    if(nnr >= 0 && nnr < rsize && nnc >= 0 && nnc < csize  && stat[nnr][nnc] == 0 && board[nnr][nnc] == 'E')
                    {
                        que.push({nnr, nnc});
                        stat[nnr][nnc] = 1;
                    }
                }
            }
        }
        return board;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
