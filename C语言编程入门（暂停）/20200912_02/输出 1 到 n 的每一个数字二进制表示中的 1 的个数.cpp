#include<stdio.h>

int main() {
	// ����һ������ n ������1000 
	int n;
	scanf("%d",&n);
	int arr[n];
	// 0 �Ķ����Ʊ�ʾ��1�ĸ���Ϊ0 
	arr[0] = 0;
	for(int i = 1; i <= n; i++) {
		// ����������1�ĸ�ʽ���� �������������������Ķ�������1�ĸ�����1
		// arr[1] = arr[1 & 0] + 1 ==> arr[0] +  1 ������������ 
		// y = x & (x - 1) ==> f[y] = f[x & (x - 1)] + 1
		arr[i] = arr[i & (i -1)] + 1; 
	}
	for(int i = 0; i <= n; i++) {
		if( i != 0) printf(" ");
		printf("%d", arr[i]);
	} 
	return 0; 
}
