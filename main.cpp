// Write a function that simulates someone’s two-dimensional random walk along an M by N grid where M and N are function parameters. This program is a generalization of the one-dimensional random walk. The walker moves in one of four directions. The walker chooses the direction randomly. The walker cannot move off the grid. The function ends when the walker visits every grid position at least once. The function returns a dynamic structure that is an ordered record of the walker’s positions over time. The first element of the structure is the walker’s first position. The last element is the walker’s last position.



#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
using namespace std;


int get_walk(int N)
{
    int walk = 0;
    int toss;
    for (int i = 0; i < N-1; i++)
    {
        toss = rand() % 2;
        if (toss == 0)
        {
            // head
            walk += 1;
        }
        else
        {
            walk += -1;
        }
    }
    return walk;
}
vector<pair<int, int>> random_walk(int M, int N)
{
    vector<pair<int, int>> moves;
    // int max = N*N;
    int iter = 0;
    vector<vector<int>> walk_m(M, vector<int>(N, -1));
    int move, walk, walk_i, walk_j;
    int i, j;
    moves.push_back(make_pair(0, 0));
    iter++;
    walk_m[0][0] = 1;

    int curr = 0;
    int curr_i = 0;
    int curr_j = 0;

    while (iter != M * N)
    {
        move = rand() % 3;
        if (move == 0)
        {
            // pick x axis
            walk = get_walk(M);

            if (curr_i + walk < M && curr_i + walk >= 0)
            {
                curr_i = curr_i + walk;
                if (walk_m[curr_i][curr_j] == -1)
                    iter++;

                walk_m[curr_i][0] = 1;
                // cout << "curr: " << curr_i << ", " << curr_j << endl;
                moves.push_back(make_pair(curr_i, curr_j));
            }
        }
        else if (move == 1)
        {
            // pick y axis
            walk = get_walk(N);
            if (curr_j + walk < N && curr_j + walk >= 0)
            {
                curr_j = curr_j + walk;
                if (walk_m[curr_i][curr_j] == -1)
                    iter++;
                walk_m[curr_i][curr_j] = 1;
                // cout << "curr: " << curr_i << ", " << curr_j << endl;
                moves.push_back(make_pair(curr_i, curr_j));
            }
        }
        else
        {
            // pick both
            walk_i = get_walk(M);
            walk_j = get_walk(N);
            if ((curr_i + walk_i < M && curr_i + walk_i >= 0) && (curr_j + walk_j < N && curr_j + walk_j >= 0))
            {
                curr_i = curr_i + walk_i;
                curr_j = curr_j + walk_j;
                if (walk_m[curr_i][curr_j] == -1)
                    iter++;
                walk_m[curr_i][curr_j] = 1;
                // cout << "curr: " << curr_i << ", " << curr_j << endl;
                moves.push_back(make_pair(curr_i, curr_j));
            }
        }
    }
    
    return moves;
}
int main()
{
    int M, N;
    vector<pair<int, int>> moves;
    cout << "Enter M: ";
    cin >> M; 
    cout << "Enter N: ";
    cin >> N;
    moves = random_walk(M, N);
    for (auto &i : moves)
    {
        cout << "Move: " << i.first << ", " << i.second << endl;
    }
}