#include<stdio.h>
//  ���ȶ����������� n �� m��n �Ĵ�С���ᳬ�� 10��m �Ĵ�С�����ᳬ�� 10000��
// ���������� n ��������ͬ������������� 1 �� m �У�����Щ�����޷����� n ���������������һ��������
int main()  {
	int n, m;
	scanf("%d%d", &n,&m);
	// �洢n����ͬ�������� 
	int arr1[n];
	// �洢��� 
	int arr2[m];
	// ��¼�ж��ٸ���� 
	int x = 0;
	// ��ȡ n �����ɹ� 
	for(int i = 0; i < n; i++) {
		scanf("%d", &arr1[i]);
	}
	// m����ѭ��һ�� 
	for(int k = 0; k < m; k++) {
		// n��������ȡ�� 
		for(int i = 0; i < n; i++) {
			if((k + 1) % arr1[i] != 0) {
				//printf("%d", k + 1);
				arr2[x] = k + 1; 
				x++;
				i = n;
			} 
		}
	}
	for(int i = 0; i < x; i++) {
		printf("%d\n",arr2[i]);
	}
	//printf("%d", x);
	return 0; 
} 
