//״̬ѹ��DP
//�ɵ��ﰲ������ |��ͨд��
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 12, M = 1 << N;
int n, m, f[N][M]; //�к��п��ܵ�״̬
bool st[M];

void solve() {
    memset(f, 0, sizeof(f));
    //Ԥ����ÿ��״̬
    for (int i = 0; i < 1 << n; i++) {
        int cnt = 0; //����0�ĸ���
        st[i] = true;
        for (int j = 0; j < n; j++) {
            if (i >> j & 1)  { //i��������ʽ�µĵ�jλ�Ƿ�Ϊ1
                //��ǰ������0�ĸ�������Ϊ�����򲻺Ϸ�
                if (cnt & 1) st[i] = false; cnt = 0; //��������
            }
            else cnt++;
        }
        //�ж��������һ�ε�����0�ĸ���
        if (cnt & 1) st[i] = false;
    }
    f[0][0] = 1;
    for (int i = 1; i <= m; i++)
        for (int j = 0; j < 1 << n; j++)
            for (int k = 0; k < 1 << n; k++) {
                //j&k==0�����ص����õ�
                //j|k�����ǵ�i�к�i-1,i-2�е�״̬�����о�û�������������ո�
                if (!(j & k) && st[j | k]) f[i][j] += f[i - 1][k];
            }

    cout << f[m][0] << endl;
}

signed main() {
    while (cin >> n >> m) {
        if (!(m || n)) break;
        solve();
    }
    return 0;
}

//�ɵ��ﰲ������ |ȥ����Ч״̬
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 12, M = 1 << N;
int n, m;
int f[N][M]; //�к��п��ܵ�״̬
bool st[M];
vector<int> state[M]; //�洢�Ϸ�״̬

void solve() {
    memset(f, 0, sizeof(f));
    //Ԥ����ÿ��״̬
    for (int i = 0; i < 1 << n; i++) {
        int cnt = 0; //����0�ĸ���
        st[i] = true;
        for (int j = 0; j < n; j++) {
            if (i >> j & 1) { //i��������ʽ�µĵ�jλ�Ƿ�Ϊ1
                //��ǰ������0�ĸ�������Ϊ�����򲻺Ϸ�
                if (cnt & 1) st[i] = false;
                cnt = 0; //��������
            }
            else cnt++;
        }
        //�ж��������һ�ε�����0�ĸ���
        if (cnt & 1) st[i] = false;
    }

    //Ԥ��������״̬��ֻ���ºϷ�״̬
    for (int j = 0; j < 1 << n; j++) {
        state[j].clear(); //����ϴν��
        for (int k = 0; k < 1 << n; k++) {
            //j&k==0�����ص����õ�
            //j|k�����ǵ�i�к�i-1,i-2�е�״̬�����о�û�������������ո�
            if (!(j & k) && st[j | k]) state[j].push_back(k);
        }
    }

    f[0][0] = 1;
    for (int i = 1; i <= m; i++)
        for (int j = 0; j < 1 << n; j++)
            for (auto k: state[j])
                f[i][j] += f[i - 1][k];

    cout << f[m][0] << endl;
}

signed main() {
    while (cin >> n >> m) {
        if (!(m || n)) break;
        solve();
    }
    return 0;
}


//���Hamilton·��
#include <bits/stdc++.h>
using namespace std;

const int N = 21, M = 1 << N, INF = 0x3f3f3f3f;
int n, d[N][N], f[M][N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> d[i][j];

    memset(f, INF, sizeof(f));
    f[1][0] = 0;
    for (int i = 0; i < 1 << n; i++)
        for (int j = 0; j < n; j++)
            if (i >> j & 1) {
                for (int k = 0; k < n; k++) {
                    if((i - (1 << j)) >> k & 1) //·���а���j��
                    f[i][j] = min(f[i][j], f[i - (1 << j)][k] + d[k][j]);
                }
            }

    cout << f[(1 << n) - 1][n - 1] << endl;
    return 0;
}
