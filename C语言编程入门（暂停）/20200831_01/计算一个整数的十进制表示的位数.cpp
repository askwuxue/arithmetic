#include<stdio.h>
int main() {
	int a;
	int number = 2;
	scanf("%d", &a);
	// ��Ĭ��������������� 
	if(a < 10) {
		printf("�������Ϊ1λ��");
	} else {
		
		 for(int i = 0; i< a; i++) {
		 	if (a/10 >= 10) {
		 		a = a/10;
		 		number++;
			 } else {
			 	break;
			 }
			
		 }
		 printf("%d",number);
	}
}
