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

//1차원배열의 포인터형은 ? 
//int* ptr;         파라미터선언시 int ptr[]
//2차원배열의 포인터형은 ? 
//int(*ptr)[열개수];파라미터선언시 int ptr[][열개수]
#include<stdio.h>
void disp(double arr[], int size)
{
	printf("arr포인터사이즈 : %d\n", sizeof(arr));
	for (int i = 0; i < size; i++)
	{
		printf("%.2f ", arr[i]);
	}
	puts("");//줄바꿈
}
int main()
{
	double arr[3] = { 1.1, 2.2, 3.3 };
	printf("arr배열사이즈 : %d\n", sizeof(arr));
	disp(arr, sizeof(arr)/sizeof(double) );

	return 0;
}

//*/


/*
//함수의 포인터
#include<stdio.h>
//함수이름도 함수가 저장된 메모리공간의 주소를 의미한다.
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
	//int       : 반환형이 int라는 정보
	//*ptr      : ptr은 포인터변수라는 정보
	//(int,int) : 매개변수 선언이 int,int 2개라는 정보

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
	int* arr[3] = {&a, &b, &c};//포인터배열
	//int포인터(int형변수의 주소) 집합

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
//파라미터 선언시에 예외허용하는 2차원배열의 포인터타입
//2차원배열의 포인터형은 행정보는 없다.
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
	//int pptr[][3] = arr2;//(x) 파라미터에서만 허용
	//arr : 2차원배열이름 : 포인터
	//포인터 배열
	//int a, b, c;
	//int* ptr[3] = {&a, &b, &c};//포인터 배열
	//2차원배열의 포인터타입
	//int(*ptr)[3]=arr;
	//포인터변수를이용해서 배열변수처럼사용해도 포인터연산을통해 데이터를 읽을수있다
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
	//2차원배열이 1차원배열 2개의 집합
	//포인터연산시 1차원배열크기만큼 연산한다.
	//arr[i] == *(arr+i)
	printf("%d %d \n", *( *(arr + 0) + 0), arr[0][0]);
	printf("%d %d \n", *( *(arr + 0) + 1), arr[0][1]);
	printf("%d %d \n", *( *(arr + 0) + 2), arr[0][2]);
	printf("%d %d \n", *(*(arr + 1) + 0), arr[1][0]);
	printf("%d %d \n", *(*(arr + 1) + 1), arr[1][1]);
	printf("%d %d \n", *(*(arr + 1) + 2), arr[1][2]);
	//2차원배열이 만들어주는 변수는 포인터연산을 통해서 데이터에 접근한다.
	
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
	// 1차원배열변수 생성 : arr[0], arr[1]
	// arr[0](배열이름) 각각 int 변수생성
	// arr[0][인덱스번호] : arr[0][0], arr[0][1], arr[0][2]
	// arr[1][인덱스번호] : arr[1][0], arr[1][1], arr[1][2]
	// 2행 3열의 총6개의 int형 변수을 만들어 준다.

	int rows = sizeof(arr) / sizeof(arr[0]);
	int columns = sizeof(arr[0]) / sizeof(int);


	for(int i=0; i< rows; i++)//i : 0,1
	{
		for (int j = 0; j < columns ; j++)//j:0,1,2
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");//줄바꿈
	}
	puts("---------------");

	printf("2차원배열 arr : %dbyte\n", sizeof(arr));
	printf("1차원배열 arr[0] : %dbyte\n", sizeof(arr[0]));
	printf("1차원배열 arr[1] : %dbyte\n", sizeof(arr[1]));

	

	printf("%d행 %d열\n", rows, columns);


	

	
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
//다차원배열
#include<stdio.h>
int main()
{
	int arr[3];

	int ar[2][3];
	//int 3짜리배열(1차원배열) 2개 집합
	// 2행 3열 개수만큼 변수를 만들어라..총2*3 6개
	int jum[3][3] = {
		{88,90,90}, //1번의 국,영,수
		{90,80,100},//2번의 국,영,수
		{95,85,88}  //3번의 국,영,수
	};

	return 0;
}
//*/


/*
#include<stdio.h>
// arr[i] == *(arr + i)
//1차원배열의 포인터형은 싱글포인터타입 입니다.

//void dispArr(int* arrPtr)
//파라미터공간에서만 예외적으로 허용한다. 배열의포인터는 int arrPtr[]
void dispArr(int arrPtr[])
{
	for (int i = 0; i < 3; i++)//i : 0,1,2
	{
		//printf("%d %d\n", *(arrPtr+i), arrPtr[i]);
		//배열이 만들어준 변수 : 포인터연산을 통해서 데이터에 접근합니다
		printf("%d \n", arrPtr[i]);
	}
}

int main()
{
	int arr[3] = { 10,20,30 };
	
	//배열을 출력하기 위한 함수
	dispArr(arr); 
	//arr == &arr[0] : int형변수의 주소값
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
	//int형공간 3개를 만들어주세요..
	//arr[0], arr[1], arr[2]

	for (int i = 0; i < 3; i++)//i: 0, 1, 2
	{
		printf("arr[%d] : %d : %p\n", i, arr[i], &arr[i]);
	}
	puts("-----------");
	//배열이름 arr은 포인터입니다.
	//printf("%p %p\n", &arr[0], arr);
	printf("%p %p\n", &arr[0], arr + 0);
	printf("%p %p\n", &arr[1], arr + 1);
	printf("%p %p\n", &arr[2], arr + 2);

	puts("-----------");
	for (int i = 0; i < 3; i++)//i : 0, 1, 2
	{
		printf("%d %d %d\n", *(&arr[i]), *(arr + i), arr[i]);		
	}
	//1차원배열의 데이터를 읽을때
	//아래표현만 기억합시다...
	// arr[i] == *(arr + i)
	// 배열이름은 포인터를 저장하고 있습니다.


	return 0;
}
//*/

/*
#include<stdio.h>

int main() 
{
	//모든포인터는 4byte로 동일

	void* ptr; //단지 포인터만 저장가능합니다.
	//사이즈 정보가 없어서 데이터는 읽을수 없다.

	int num = 10;

	ptr = &num; 

	//printf("%d\n", *ptr); //사이즈정보가 없어서 불가
	//사이즈정보가 있는 타입으로 캐스팅하면 해결
	printf("%d\n", *(int*)ptr);

	int* pointer=NULL;//포인터변수의 초기화

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
	//포인터변수의 포인터

	int num;
	char ch;

	//포인트 변수의 사이즈는 4byte입니다.
	//주소체계가 현재 4byte로 만들어졌습니다.
	int* ptr=&num;
	char* chptr=&ch;
	printf("int포인터변수의 사이즈 : %dbyte\n", sizeof(ptr));
	printf("char포인터변수의 사이즈 : %dbyte\n", sizeof(chptr));

	int** dptr=&ptr;//포인터변수의 포인터

	**dptr = 10;

	printf("num: %d , %d \n", num, **dptr);


	return 0;
}
//*/


/*
//포인터변수
#include<stdio.h>
int main()
{
	int num;
	//포인터변수
	int* ptr = &num; //&메모리 주소번지획득 : 포인터

	// =앞쪽에 *연산자가 있으면 포인터가위치한 공간에
	// 해당하는 사이즈 만큼 걸쳐 데이터를 넣어라.
	*ptr = 10;
	//* 해당하는 메모리주소 이동해서 데이터를 읽어라
	printf("num : %d , %d\n", num, *ptr);
	
	return 0;
}

//*/