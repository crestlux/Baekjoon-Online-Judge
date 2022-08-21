//Reference:
//http://www.secmem.org/blog/2019/12/15/knuths-algorithm-x/
//https://velog.io/@jaehyeoksong0/Knuths-Algorithm-X
//https://en.wikipedia.org/wiki/Exact_cover
//Knuth X with Dancing Links & Exact cover
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
using ti = tuple<int, int, int>;
using vvi = vector<vector<int>>;
struct node {
    int row;
    int size;
    node *column;
    node *up;
    node *down;
    node *left;
    node *right;
};
void dlx_cover(node *c) {
    c->right->left = c->left;
    c->left->right = c->right;
    for (node *it = c->down; it != c; it = it->down) {
        for (node *jt = it->right; jt != it; jt = jt->right) {
            jt->down->up = jt->up;
            jt->up->down = jt->down;
            jt->column->size--;
        }
    }
}
void dlx_uncover(node *c) {
    for (node *it = c->up; it != c; it = it->up) {
        for (node *jt = it->left; jt != it; jt = jt->left) {
            jt->down->up = jt;
            jt->up->down = jt;
            jt->column->size++;
        }
    }
    c->right->left = c;
    c->left->right = c;
}
bool dlx_search(node *head, int depth, vector<int> &solution) {
    if (head->right == head) return true;
    node *ptr = nullptr;
    int low = INT_MAX;
    for (node *it = head->right; it != head; it = it->right) {
        if (it->size < low) {
            if (it->size == 0) return false;
            low = it->size;
            ptr = it;
        }
    }
    dlx_cover(ptr);
    for (node *it = ptr->down; it != ptr; it = it->down) {
        solution.push_back(it->row);
        for (node *jt = it->right; jt != it; jt = jt->right) {
            dlx_cover(jt->column);
        }
        if (dlx_search(head, depth + 1, solution)) return true;
        else {
            solution.pop_back();
            for (node *jt = it->left; jt != it; jt = jt->left) {
                dlx_uncover(jt->column);
            }
        }
    }
    dlx_uncover(ptr);
    return false;
}
vector<int> dlx_solve(vector<vector<int>> matrix) {
    int n = matrix[0].size();
    vector<node> column(n);
    node head;
    head.right = &column[0];
    head.left = &column[n - 1];
    for (int i = 0; i < n; ++i) {
        column[i].size = 0;
        column[i].up = &column[i];
        column[i].down = &column[i];
        if (i == 0) column[i].left = &head;
        else column[i].left = &column[i - 1];
        if (i == n - 1) column[i].right = &head;
        else column[i].right = &column[i + 1];
    }

    vector<node *> nodes;
    for (int i = 0; i < ssize(matrix); ++i) {
        node *last = nullptr;
        for (int j = 0; j < n; ++j) if (matrix[i][j]) {
            node *now = new node;
            now->row = i;
            now->column = &column[j];
            now->up = column[j].up;
            now->down = &column[j];
            if (last) {
                now->left = last;
                now->right = last->right;
                last->right->left = now;
                last->right = now;
            }
            else {
                now->left = now;
                now->right = now;
            }
            column[j].up->down = now;
            column[j].up = now;
            column[j].size++;
            last = now;
            nodes.push_back(now);
        }
    }
    vector<int> solution;
    dlx_search(&head, 0, solution);
    for (node *ptr : nodes) delete ptr;
    return solution;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    constexpr int bsize = 16;
    vvi board(bsize, vector<int>(bsize, 0)), mat;
    vector<ti> data;
    for (int i = 0; i < bsize; ++i) {
        for (int j = 0; j < bsize; ++j) {
            char c;
            cin >> c;
            if (c == '-') board[i][j] = 0;
            else board[i][j] = c - 'A' + 1;
            function<void(int)> buildrow = [&](const int &k) {
                vector<int> row(256 + 768, 0);
                row[i * 16 + j] = 1;
                row[256 + (i * 16) + k] = 1;
                row[256 * 2 + (j * 16) + k] = 1;
                row[256 * 3 + (i / 4 * 4 + j / 4) * 16 + k] = 1;
                mat.push_back(row);
                data.push_back({ i, j, k });
            };
            if (board[i][j]) {
                buildrow(board[i][j] - 1);
            }
            else {
                for (int k = 0; k < bsize; ++k) {
                    buildrow(k);
                }
            }
        }
    }
    for (const auto &e : dlx_solve(mat)) {
        board[get<0>(data[e])][get<1>(data[e])] = get<2>(data[e]) + 1;
    }
    for (int i = 0; i < bsize; ++i) {
        for (int j = 0; j < bsize; ++j) {
            cout << char(board[i][j] + 'A' - 1);
        }
        cout << "\n";
    }
    return 0;
}