vector<int> alls; // �洢���д���ɢ����ֵ
sort(alls.begin(), alls.end()); // ������ֵ����
alls.erase(unique(alls.begin(), alls.end()), alls.end()); // ȥ��

// �������x��Ӧ����ɢ����ֵ
// �ҵ���һ�����ڵ���x��λ��
int find(int x) {
    int l = 0, r = alls.size() - 1;
    while (l < r) {
        int mid = l + r >> 1;
        if (alls[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return r + 1; // ӳ�䵽1, 2, ...n
}
