#include<stdio.h>

//�����и����� 1989 �� 11 �� 20 ��������ڣ�Ȼ������ 20 ���������Ƕ���
int main() {
	// �洢����������ռ� N ��� 
	int y, m, d, n;
	scanf("%d%d%d", &y,&m,&d);
	scanf("%d", &n);
	// while ѭ�����
	for(int i = 0; i < n; i++) {
		// ѭ��n�죬ÿ��һ�죬������1 
		d++;
		switch(m) {
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12: {
				if(d > 31) d = 1, m++;
				if(m == 13) m = 1, y++;
				break;
			}
			case 4:
			case 6:
			case 9:
			case 11: {
				if(d > 30) d = 1, m++;
				break;
			}
			case 2:
				// �ж����� 
				if((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) {
					if ( d > 29) d = 1, m++;
				}
				else {
					if(d > 28) d = 1, m++;
				}
		}
	}
	printf("%d���������ǣ�%d��%d��%d��",n,y,m,d); 
	return 0;
} 
