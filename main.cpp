
// Write a function that simulates someone’s two-dimensional random walk along an M by N grid where M and N are function parameters. This program is a
// generalization of the one-dimensional random walk. The walker moves in one of four directions. The walker chooses the direction randomly. The walker cannot move off the grid. 
// The function ends when the walker visits every grid position at least once. The function returns a dynamic structure that is an ordered record of the walker’s positions over time. 
// The first element of the structure is the walker’s first position. The last element is the walker’s last position.


#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
using namespace std;

vector<pair<int, int>> random_walk(int M, int N)
{
    vector<pair<int, int>> moves;
    // int max = N*N;
    int iter = 0;
    vector<vector<int>> walk_m(M, vector<int>(N, 0));
    int move, walk, walk_i, walk_j;
    int i, j;
    moves.push_back(make_pair(0, 0));
    iter++;
    walk_m[0][0] = 1;

    int curr_i = 0;
    int curr_j = 0;

    while (iter != M * N)
    {

        move = rand() % 8;
        switch (move)
        {
        case 0:
            /* north */
            i = curr_i - 1;
            j = curr_j;
            if (i >= 0)
            {
                curr_i = i;
                if (walk_m[curr_i][curr_j] == 0)
                    iter++;

                walk_m[curr_i][curr_j] = 1;
                moves.push_back(make_pair(curr_i, curr_j));
            }

            break;
        case 1:
            /* south */
            i = curr_i;
            j = curr_j - 1;
            if (j >= 0)
            {
                curr_j = j;
                if (walk_m[curr_i][curr_j] == 0)
                    iter++;

                walk_m[curr_i][curr_j] = 1;
                moves.push_back(make_pair(curr_i, curr_j));
            }

            break;
        case 2:
            /* east */
            i = curr_i;
            j = curr_j + 1;
            if (j < N)
            {
                curr_j = j;
                if (walk_m[curr_i][curr_j] == 0)
                    iter++;

                walk_m[curr_i][curr_j] = 1;
                moves.push_back(make_pair(curr_i, curr_j));
            }

            break;
        case 3:
            /* west */
            i = curr_i + 1;
            j = curr_j;
            if (i < M)
            {
                curr_i = i;
                if (walk_m[curr_i][curr_j] == 0)
                    iter++;

                walk_m[curr_i][curr_j] = 1;
                moves.push_back(make_pair(curr_i, curr_j));
            }

            break;
        case 4:
            /* NE */
            i = curr_i - 1;
            j = curr_j + 1;
            if (i >= 0 && j < N)
            {
                curr_j = j;
                curr_i = i;
                if (walk_m[curr_i][curr_j] == 0)
                    iter++;

                walk_m[curr_i][curr_j] = 1;
                moves.push_back(make_pair(curr_i, curr_j));
            }
            break;
        case 5:
            /* NW */
            i = curr_i - 1;
            j = curr_j - 1;
            if (i >= 0 && j >= 0)
            {
                curr_j = j;
                curr_i = i;
                if (walk_m[curr_i][curr_j] == 0)
                    iter++;

                walk_m[curr_i][curr_j] = 1;
                moves.push_back(make_pair(curr_i, curr_j));
            }

            break;
        case 6:
            /* SW */
            i = curr_i + 1;
            j = curr_j - 1;
            if (j >= 0 && i < M)
            {
                curr_j = j;
                curr_i = i;
                if (walk_m[curr_i][curr_j] == 0)
                    iter++;

                walk_m[curr_i][curr_j] = 1;
                moves.push_back(make_pair(curr_i, curr_j));
            }

            break;
        case 7:
            /* SE */
            i = curr_i + 1;
            j = curr_j + 1;
            if (i < M && j < N)
            {
                curr_j = j;
                curr_i = i;
                if (walk_m[curr_i][curr_j] == 0)
                    iter++;

                walk_m[curr_i][curr_j] = 1;
                moves.push_back(make_pair(curr_i, curr_j));
            }
            break;
        default:
            break;
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
	
	system("pause");
	return 0;
}