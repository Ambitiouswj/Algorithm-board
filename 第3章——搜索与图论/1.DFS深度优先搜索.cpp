�������֣�����DFS��
����һ���������������ų�һ�ţ������кܶ������з�����
���ڣ����㰴���ֵ������е����з������
#include <bits/stdc++.h>
using namespace std;

const int N = 10;
int n, a[N];
bool st[N];

void dfs(int u) {
//�ﵽ���������
    if (u == n) {
        for (int i = 0; i < n; i++) cout << a[i] << ' ';
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!st[i]) {
            a[u] = i;
            st[i] = true;
            dfs(u + 1);
            st[i] = false;//��ԭ
        }
    }
}

int main() {
    cin >> n;
    dfs(0);
    return 0;
}
n�ʺ�DFS+��֦��
n�ʺ�������ָ��n���ʺ���ڵĹ������������ϣ�ʹ�ûʺ����໥�������������������ʺ󶼲��ܴ���ͬһ�С�ͬһ�л�ͬһб���ϡ�

���ڸ�������������������е��������������Ӱڷ���
#include <bits/stdc++.h>
using namespace std;

const int N = 15;
int n;
bool p[N][N];

bool check(int x, int y) {
    for (int i = 0; i < x; i++) { //�ж����Ϸ�
        if (p[i][y]) return false;
    }
    for (int i = x, j = y; i >= 0 && j >= 0; i--, j--) { //�ж�����
        if (p[i][j]) return false;
    }
    for (int i = x, j = y; i >= 0 && j < n; i--, j++) { //�ж�����
        if (p[i][j]) return false;
    }
    return true;
}

void dfs(int u) {
    if (u == n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (p[i][j]) cout << 'Q';
                else cout << '.';
            }
            cout << endl;
        }
        cout << endl;
        return;
    }
    for (int j = 0; j < n; j++) {
        if (check(u, j)) { //��֦�����������ż�������
            p[u][j] = true;
            dfs(u + 1);
            p[u][j] = false;
        }
    }
}

int main() {
    cin >> n;
    dfs(0);
    return 0;
}
