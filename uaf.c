#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

void *pfunc1()
{
	printf("test\n");
}

typedef struct Object1_struct{
	int flag;
	void (*pfunc1)();
	char message[4];
}OBJECT1;

typedef struct Object2_struct{
	int flag;
	int flag2;
	char *welcome;
}OBJECT2;

int main()
{
	int i;
	OBJECT1 *pObject1;
	OBJECT2 *pObject2;
	pObject1 = (OBJECT1 *)malloc(sizeof(OBJECT1));//init struct
	pObject1->flag = 1;
	//pObject1->pfunc1();
	//pObject1->message = "this is first create!";
	
	free(pObject1);
	/*forget pObject1 = NULL*/
	for(i=0;i<1000;i++)
	{
		pObject2 = (OBJECT2 *)malloc(sizeof(OBJECT2));//heap spray
		pObject2->flag=2;
		pObject2->flag2=4;
		pObject2->welcome = "AAAA";
	}
	/*fill pointer*/

	if(pObject1 != NULL)
		pObject1->pfunc1();
	return 0;
}
