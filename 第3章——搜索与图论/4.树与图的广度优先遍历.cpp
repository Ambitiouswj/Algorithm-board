����ͼ�Ĺ�����ȱ���
ʱ�临�Ӷ�O(n+m)��n:������m:����
*��ܣ�
int bfs()
{
	queue<T> que;
	que.push(��ʼ״̬);
	//��ʼ��
	while (que.size())
	{
		auto t = que.front();//ȡ��ͷ
		que.pop();
		for (int i = h[t]; i != -1; i = ne[i])//����
		{
			T j = e[i];
			if (!st[j])
			{
				st[j] = true;
				/*�����Ŀ�߼�*/
				que.push(j); //���
			}
		}
	}
	return ��Ŀ��Ҫ����;
}

