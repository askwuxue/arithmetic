#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
	// ���һ��ѭ�����̣�ѭ�� 100 �Σ��Բ�̫���ԵĹ������ 1��100 �е�ÿ�����֡� 
	for(int i = 0; i < 100; i++) {
		// ����������� ���������Ӳ��� ���ɵ���������� �ǳ���  
		//srand(time(0));
		if (i < 100) { 
			printf("%d\t", rand());
		}
	
	}
	return 0;
} 
