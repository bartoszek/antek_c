#include<stdio.h>

void suma(int *a , int b )
{
 *a=*a+b;
}


int main (){
	int a=4;
	int b=6;
	suma(&a,b);
	printf("%d",a);
	return 0;
}