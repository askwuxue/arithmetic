#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
	// m ����Բ�ڵĴ���  n ����Բ��Ĵ��� 
	int m = 0 , n = 0;
	for(int i = 0; i < 100000000; i++) {
		// �����������С�ڵ���1��ֵ ��Ϊֱ�������ε����� ��б�� б�ߴ��� > 1 ������Բ�� 
		double x = 1.0 * rand() / RAND_MAX;
		double y = 1.0 * rand() / RAND_MAX;
		if (x  * x + y * y <= 1) m++;
		n++;
	}
	printf("�н��Ƶ���: %lf\n", 4.0 * m / n);
	return 0;
} 
