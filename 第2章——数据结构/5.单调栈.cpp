// ����һ������Ϊ���������У����ÿ������ߵ�һ������С��������������������
#include<bits/stdc++.h>
using namespace std;

const int N = 100010;
int stk[N], n, tt = 0;

int main() {
    scanf("%d", &n);
    int x;
    for (int i = 0; i < n; i++) {
        scanf("%d" ,&x);
        // ��ջ��Ԫ�ش���������Ԫ��ʱ����ջ��Ԫ��
        while(tt&&stk[tt] >= x) tt--;
        // ��ʱջ����Ԫ�أ�����Ԫ�أ����������һ������С��
        if (tt) cout << stk[tt] << " ";
        else cout << "-1 ";
        stk[++tt] = x;
    }
    return 0;
}
