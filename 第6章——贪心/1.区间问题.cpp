/*��������̰��*/
//����ѡ��|����ཻ��������
1 ÿ�����䰴�Ҷ˵�����
2 ö��ÿ������
	�����е㣬ֱ����һ��
	����ѡ���Ҷ˵�

#include <bits/stdc++.h>
#define l first
#define r second
using namespace std;

typedef pair<int,int> PII;

const int N = 100010;
int n;
PII p[N];

bool cmp(PII& a, PII &b) {
    return a.r < b.r;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].l >> p[i].r;
    }
    sort(p + 1, p + 1 + n, cmp);

    int tmp = -2e9;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if(tmp >= p[i].l && tmp <= p[i].r) continue;
        tmp = p[i].r;
        ans++;
    }
    cout << ans << endl;
    return 0;
}

//�������
1 ����������˵�����
2 ��ǰ������
	�ж��ܷ����Ŀǰ������
	(��ǰ������˵��Ƿ����ĳ���������������Ҷ˵�/*��������С�����Ҷ˵�*/)
		1. �����������飬������������С�����Ҷ˵�
		2. �����ڣ����½�һ����
#include <bits/stdc++.h>
#define l first
#define r second
using namespace std;

typedef pair<int,int> PII;

const int N = 100010;
int n;
PII p[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].l >> p[i].r;
    }

    sort(p + 1, p + 1 + n);
    priority_queue<int,vector<int>,greater<int>> hp;
    for (int i = 1; i <= n; i++) {
        if (!hp.size() || p[i].l <= hp.top()) hp.push(p[i].r);
        else {
            hp.pop();
            hp.push(p[i].r);
        }
    }
    cout << hp.size() << endl;
    return 0;
}

//���串��
1 ����������˵�����
2 ��ǰ������
	�������ܸ���start��������ѡ���Ҷ˵���������
	��start����Ϊ�Ҷ˵�����ֵ
#include <bits/stdc++.h>
#define l first
#define r second
using namespace std;

typedef pair<int,int> PII;

const int N = 100010;
int n, s, t;
PII p[N];

int main() {
    cin >> s >> t >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].l >> p[i].r;
    }

    sort(p + 1, p + 1 + n);
    int ans = 0;
    bool st = false;
    for (int i = 1; i <= n; i++) {
        int j = i , ed = -2e9;
        while (j <= n && p[j].l <= s) { //˫ָ���ҵ��ܸ����������
            ed = max(ed, p[j].r);
            j++;
        }
        if (ed < s) { //������յ�С�������
            st = false;
            break;
        }
        ans++;
        if (ed >= t) {
            st = true;
            break;
        }
        s = ed;
        i = j - 1;
    }
    if (!st) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}
