#include<stdio.h>

int main(){
	int i, k;
	// �������� 
	for(i = 1; i < 10; i++) {
		// �������� 
		for(k = 1; k <= i; k++) {
			// ����ĸ�ʽ 
			printf("%d * %d = %d\t", k, i, k*i);
		}
		// ���� 
		printf("\n");
	}
	return 0;
}
