#include<stdio.h>

int main() {
	char str[12] = "123.45";
	char str1[100];
	double sum;
	// sscanf �������ַ���ת���� ���ͣ������͵�����  ��һ������ �ַ����� �ڶ������� Ҫת�������� ����������
	// �����洢ת����ı����� Ҫ��Ӧ���� 
	sscanf(str, "%lf", &sum);
	// sprintf ������������������ת��Ϊ�ַ������� 
	sprintf(str1, "123");
	
	// ���������λС�� ��ʹ�á�%.xlf�� 
	printf("%.1lf\n", sum);
	
	printf("%s",str1);
	return 0;
}

 
