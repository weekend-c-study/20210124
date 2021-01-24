#include<stdio.h>
//void display(double arr[][3])
void display(double (*arr)[3])
{
	printf("size: %d\n", sizeof(arr));
}
int main()
{
	double arr[3][3] = {
		1,2,3,4,5,6,7,8
	};
	display(arr);

	return 0;
}


/*

//1�����迭�� ���������� ? 
//int* ptr;         �Ķ���ͼ���� int ptr[]
//2�����迭�� ���������� ? 
//int(*ptr)[������];�Ķ���ͼ���� int ptr[][������]
#include<stdio.h>
void disp(double arr[], int size)
{
	printf("arr�����ͻ����� : %d\n", sizeof(arr));
	for (int i = 0; i < size; i++)
	{
		printf("%.2f ", arr[i]);
	}
	puts("");//�ٹٲ�
}
int main()
{
	double arr[3] = { 1.1, 2.2, 3.3 };
	printf("arr�迭������ : %d\n", sizeof(arr));
	disp(arr, sizeof(arr)/sizeof(double) );

	return 0;
}

//*/


/*
//�Լ��� ������
#include<stdio.h>
//�Լ��̸��� �Լ��� ����� �޸𸮰����� �ּҸ� �ǹ��Ѵ�.
int add(int n, int m) 
{
	return n + m;
}
double func(int n, double m) 
{
	return n / m;
}

int main()
{
	printf("%p\n", add);
	int(*ptr)(int,int)=add;
	//int       : ��ȯ���� int��� ����
	//*ptr      : ptr�� �����ͺ������ ����
	//(int,int) : �Ű����� ������ int,int 2����� ����

	printf("%d\n", ptr(10,20) );

	double(*fptr)(int,double)=func;
	printf("%f\n", fptr(10, 20));

	return 0;
}
//*/

/*
#include<stdio.h>
int main()
{
	int arr1[3];

	//arr1==&arr1[0]
	int* ptr1=arr1;
	ptr1[0] = 10;
	ptr1[1] = 20;
	ptr1[2] = 30;

	printf("%d\n", arr1[0]);
	printf("%d\n", arr1[1]);
	printf("%d\n", arr1[2]);

	int arr2[3][4];
	int(*ptr)[4] = arr2;
	dispArr2(arr2);

	int arr3[5][4];
	int(*ptr1)[4]=arr3;
	return 0;
}
//void dispArr2(int(*ptr)[4])
void dispArr2(int ptr[][4]) 
{

}
//*/

/*
#include<stdio.h>
int main()
{
	int a=10, b=20, c=30;
	int* arr[3] = {&a, &b, &c};//�����͹迭
	//int������(int�������� �ּ�) ����

	//arr[0],arr[1],arr[2]
	int** ptr = arr;
	printf("%d\n", *ptr[0]);
	printf("%d\n", *ptr[1]);
	printf("%d\n", *ptr[2]);	

	return 0;
}
//*/



/*
#include<stdio.h>

//void dispArr2(int(*ptr)[3])
//�Ķ���� ����ÿ� ��������ϴ� 2�����迭�� ������Ÿ��
//2�����迭�� ���������� �������� ����.
void dispArr2(int ptr[][3],int size)
{
	printf("ptr: %dbyte\n", sizeof(ptr));
	for(int i=0; i<size; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d ", ptr[i][j]);
		}
		puts("");
	}
	puts("----------------------");
}
	

int main()
{
	int arr[2][3] = { 1,2,3,4,5,6 };
	int arr2[4][3] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	int rows = sizeof(arr2) / sizeof(arr2[0]);
	dispArr2(arr2, rows);

	rows = sizeof(arr) / sizeof(arr[0]);
	dispArr2(arr, rows);
	//int pptr[][3] = arr2;//(x) �Ķ���Ϳ����� ���
	//arr : 2�����迭�̸� : ������
	//������ �迭
	//int a, b, c;
	//int* ptr[3] = {&a, &b, &c};//������ �迭
	//2�����迭�� ������Ÿ��
	//int(*ptr)[3]=arr;
	//�����ͺ������̿��ؼ� �迭����ó������ص� �����Ϳ��������� �����͸� �������ִ�
	//printf("%d , %d\n", *(*(ptr + 0) + 0), ptr[0][0] );// ptr[0][0]
	//printf("%d , %d\n", *(*(ptr + 0) + 1), ptr[0][1]);// ptr[0][0]
	//printf("%d , %d\n", *(*(ptr + 0) + 2), ptr[0][2]);// ptr[0][0]
	//printf("%d , %d\n", *(*(ptr + 1) + 0), ptr[1][0]);// ptr[0][0]
	//printf("%d , %d\n", *(*(ptr + 1) + 1), ptr[1][1]);// ptr[0][0]
	//printf("%d , %d\n", *(*(ptr + 1) + 2), ptr[1][2]);// ptr[0][0]

	return 0;
}
//*/

/*
#include<stdio.h>
int main()
{
	int arr[2][3] = { 1,2,3,4,5,6 };
	//arr[0], arr[1]
	//arr[0][0],arr[0][1], arr[0][2]
	//arr[1][0],arr[1][1], arr[1][2]
	printf("%p %p \n", *(arr + 0), arr[0]);
	printf("%p %p \n", *(arr + 1), arr[1]);
	//2�����迭�� 1�����迭 2���� ����
	//�����Ϳ���� 1�����迭ũ�⸸ŭ �����Ѵ�.
	//arr[i] == *(arr+i)
	printf("%d %d \n", *( *(arr + 0) + 0), arr[0][0]);
	printf("%d %d \n", *( *(arr + 0) + 1), arr[0][1]);
	printf("%d %d \n", *( *(arr + 0) + 2), arr[0][2]);
	printf("%d %d \n", *(*(arr + 1) + 0), arr[1][0]);
	printf("%d %d \n", *(*(arr + 1) + 1), arr[1][1]);
	printf("%d %d \n", *(*(arr + 1) + 2), arr[1][2]);
	//2�����迭�� ������ִ� ������ �����Ϳ����� ���ؼ� �����Ϳ� �����Ѵ�.
	
	return 0;
}
//*/

/*
#include<stdio.h>
int main()
{
	int arr[2][3] = { 1,2,3,4,5,6 };
	//arr[0], arr[1]
	//arr[0][0],arr[0][1], arr[0][2]
	//arr[1][0],arr[1][1], arr[1][2]
	printf("%p \n", arr);
	printf("%p \n", arr[0]);
	printf("%p \n", &arr[0][0]);
	printf("%p \n", &arr[0][1]);
	printf("%p \n", &arr[0][2]);
	printf("%p \n", arr[1]);
	printf("%p \n", &arr[1][0]);
	printf("%p \n", &arr[1][1]);
	printf("%p \n", &arr[1][2]);


	return 0;
}
//*/

/*
#include<stdio.h>
int main()
{
	int arr[3][3] = { {1,2,3},{4,5,6} };
	// 1�����迭���� ���� : arr[0], arr[1]
	// arr[0](�迭�̸�) ���� int ��������
	// arr[0][�ε�����ȣ] : arr[0][0], arr[0][1], arr[0][2]
	// arr[1][�ε�����ȣ] : arr[1][0], arr[1][1], arr[1][2]
	// 2�� 3���� ��6���� int�� ������ ����� �ش�.

	int rows = sizeof(arr) / sizeof(arr[0]);
	int columns = sizeof(arr[0]) / sizeof(int);


	for(int i=0; i< rows; i++)//i : 0,1
	{
		for (int j = 0; j < columns ; j++)//j:0,1,2
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");//�ٹٲ�
	}
	puts("---------------");

	printf("2�����迭 arr : %dbyte\n", sizeof(arr));
	printf("1�����迭 arr[0] : %dbyte\n", sizeof(arr[0]));
	printf("1�����迭 arr[1] : %dbyte\n", sizeof(arr[1]));

	

	printf("%d�� %d��\n", rows, columns);


	

	
	return 0;
}
//*/

/*
#include<stdio.h>
int main()
{
	int ar[3][3] = {1,2,3,4,5,6,7,8,9};
	int ar2[][3] = { 1,2,3,4,5,6,7,8,9,0 };
	int ar3[][3] = { {1},{4,5},{7,8,9} };
		// 1, 0 , 0
		// 4, 5 , 0
		// 7, 8 , 9
	return 0;
}
//*/

/*
//�������迭
#include<stdio.h>
int main()
{
	int arr[3];

	int ar[2][3];
	//int 3¥���迭(1�����迭) 2�� ����
	// 2�� 3�� ������ŭ ������ ������..��2*3 6��
	int jum[3][3] = {
		{88,90,90}, //1���� ��,��,��
		{90,80,100},//2���� ��,��,��
		{95,85,88}  //3���� ��,��,��
	};

	return 0;
}
//*/


/*
#include<stdio.h>
// arr[i] == *(arr + i)
//1�����迭�� ���������� �̱�������Ÿ�� �Դϴ�.

//void dispArr(int* arrPtr)
//�Ķ���Ͱ��������� ���������� ����Ѵ�. �迭�������ʹ� int arrPtr[]
void dispArr(int arrPtr[])
{
	for (int i = 0; i < 3; i++)//i : 0,1,2
	{
		//printf("%d %d\n", *(arrPtr+i), arrPtr[i]);
		//�迭�� ������� ���� : �����Ϳ����� ���ؼ� �����Ϳ� �����մϴ�
		printf("%d \n", arrPtr[i]);
	}
}

int main()
{
	int arr[3] = { 10,20,30 };
	
	//�迭�� ����ϱ� ���� �Լ�
	dispArr(arr); 
	//arr == &arr[0] : int�������� �ּҰ�
	//int* ptr = &arr[0];
	//int* arrPtr = arr;
	//printf("%d %d\n", *ptr, *arrPtr);
	//ptr = &arr[1];
	//printf("%d %d\n", *ptr, *(arrPtr+1));
	//ptr = &arr[2];
	//printf("%d %d\n", *ptr, *(arrPtr+2));

	return 0;
}
//*/

/*
#include<stdio.h>
int main()
{
	int arr[] = { 1,2,3 };
	//int������ 3���� ������ּ���..
	//arr[0], arr[1], arr[2]

	for (int i = 0; i < 3; i++)//i: 0, 1, 2
	{
		printf("arr[%d] : %d : %p\n", i, arr[i], &arr[i]);
	}
	puts("-----------");
	//�迭�̸� arr�� �������Դϴ�.
	//printf("%p %p\n", &arr[0], arr);
	printf("%p %p\n", &arr[0], arr + 0);
	printf("%p %p\n", &arr[1], arr + 1);
	printf("%p %p\n", &arr[2], arr + 2);

	puts("-----------");
	for (int i = 0; i < 3; i++)//i : 0, 1, 2
	{
		printf("%d %d %d\n", *(&arr[i]), *(arr + i), arr[i]);		
	}
	//1�����迭�� �����͸� ������
	//�Ʒ�ǥ���� ����սô�...
	// arr[i] == *(arr + i)
	// �迭�̸��� �����͸� �����ϰ� �ֽ��ϴ�.


	return 0;
}
//*/

/*
#include<stdio.h>

int main() 
{
	//��������ʹ� 4byte�� ����

	void* ptr; //���� �����͸� ���尡���մϴ�.
	//������ ������ ��� �����ʹ� ������ ����.

	int num = 10;

	ptr = &num; 

	//printf("%d\n", *ptr); //������������ ��� �Ұ�
	//������������ �ִ� Ÿ������ ĳ�����ϸ� �ذ�
	printf("%d\n", *(int*)ptr);

	int* pointer=NULL;//�����ͺ����� �ʱ�ȭ

}
//*/

/*
#include<stdio.h>

void input(int* ptr) 
{
	*ptr = 10;
}

int main()
{
	int num;

	scanf_s("%d", &num);
	//input(&num);

	printf("num : %d\n", num);
	return 0;
}
//*/

/*
#include<stdio.h>
int main()
{
	//�����ͺ����� ������

	int num;
	char ch;

	//����Ʈ ������ ������� 4byte�Դϴ�.
	//�ּ�ü�谡 ���� 4byte�� ����������ϴ�.
	int* ptr=&num;
	char* chptr=&ch;
	printf("int�����ͺ����� ������ : %dbyte\n", sizeof(ptr));
	printf("char�����ͺ����� ������ : %dbyte\n", sizeof(chptr));

	int** dptr=&ptr;//�����ͺ����� ������

	**dptr = 10;

	printf("num: %d , %d \n", num, **dptr);


	return 0;
}
//*/


/*
//�����ͺ���
#include<stdio.h>
int main()
{
	int num;
	//�����ͺ���
	int* ptr = &num; //&�޸� �ּҹ���ȹ�� : ������

	// =���ʿ� *�����ڰ� ������ �����Ͱ���ġ�� ������
	// �ش��ϴ� ������ ��ŭ ���� �����͸� �־��.
	*ptr = 10;
	//* �ش��ϴ� �޸��ּ� �̵��ؼ� �����͸� �о��
	printf("num : %d , %d\n", num, *ptr);
	
	return 0;
}

//*/