#include <iostream>
#include <queue>

using namespace std;

int BFS();

struct Node {
    int x, y, step;
    Node(int _x, int _y, int _step) : x(_x), y(_y), step(_step) {}
    Node() : step(-1) {}
};

char map[22][22];
int n, m;
int direction[4][2] = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> map[i];
    cout << BFS() << endl;
    system("pause");
}

int BFS() {
    Node start, end;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 'S') {
                start.x = i;
                start.y = j;
                start.step = 0;
            }
            if (map[i][j] == 'E') {
                end.x = i;
                end.y = j;
            }
        }
    }
    queue<Node>    q;
    q.push(start);
    while (!q.empty()) {
        Node node = q.front();
        q.pop();
        map[node.x][node.y] = '!';
        if (node.x == end.x && node.y == end.y)
            return node.step;
        for (int i = 0; i < 4; i++) {
            int x = node.x + direction[i][0];
            int y = node.y + direction[i][1];
            if (x >= 0 && y >= 0 && x < n && y < m && map[x][y] != '#' && map[x][y] != '!') {
                map[x][y] = '!';
                q.push(Node(x, y, node.step + 1));
            }
        }
    }
    return -1;
}
