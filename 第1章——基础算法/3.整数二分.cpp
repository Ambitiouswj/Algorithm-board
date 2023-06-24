// ������[l, r]��Ϊ[l, mid]��[mid + 1, r]
// �����������е�һ��>=x��ֵ
int bsearch_1(int l, int r) {
    while (l < r) {
        int mid = l + r >> 1;

        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    return l;
}
// ����[l, r]��Ϊ[l, mid - 1]��[mid, r] |ע���ʱmid��ѡȡ
// ���������������һ��<=x��ֵ
int bsearch_2(int l, int r) {
    while (l < r) {
        int mid = l + r + 1 >> 1;

        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    return l;
}
