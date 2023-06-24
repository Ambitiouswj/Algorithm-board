//����д�� | �ο���ȫ�������� O(n*v*s)
#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int n, m;
int v[N], w[N], s[N], f[N][N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i] >> s[i];

    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= m; j++)
            for (int k = 0; k <= s[i] && k * v[i] <= j; k++)
                f[i][j] = max(f[i][j], f[i - 1][j - k * v[i]] + k * w[i]);

    cout << f[n][m] << endl;
    return 0;
}

//�������Ż���ת��Ϊ01����|O(n*v*log s)
#include <bits/stdc++.h>
using namespace std;

const int N = 12010, M = 2010;
int n, m;
int v[N], w[N], f[M];

int main() {
    cin >> n >> m;
    int a, b, s;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b >> s;
        int k = 1;
        //����1,2,4,8,16,...,2^k��
        while (k < s) {
            cnt++;
            v[cnt] = k * a;
            w[cnt] = k * b;
            s -= k;
            k *= 2;
        }
        //�����ʣһ�ѵ�������1,2,4,8,16,32,64,73
        if (s > 0) {
            cnt++;
            v[cnt] = s * a;
            w[cnt] = s * b;
        }
    }
    //ת��Ϊ01��������
    for (int i = 1; i <= cnt; i++)
        for (int j = m; j >= v[i]; j--)
            f[j] = max(f[j], f[j - v[i]] + w[i]);

    cout << f[m] << endl;
    return 0;
}
