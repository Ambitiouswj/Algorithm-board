// �����������һλ1��Ȩ��
int lowbit(int x) {
    return x & -x;
}

// ��������1������
int pop_count(int x) {
    int cnt = 0;
    while (x) {
        cnt++;
        x = x & (x - 1);
    }
    return cnt;
}
