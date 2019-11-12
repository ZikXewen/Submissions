#include <stdio.h>

#define UNINITIALIZED 0
#define INITIALIZED 1
#define INVALID 2

int __r1, __c1, __r2, __c2, __p1, __q1, __p2, __q2;
int __size = 0;
int __call_count = 0;
int __state = UNINITIALIZED;

int gridsize()
{
	if (__state == UNINITIALIZED)
	{
		scanf("%d", &__size);
		scanf("%d %d %d %d", &__r1, &__c1, &__r2, &__c2);
		scanf("%d %d %d %d", &__p1, &__q1, &__p2, &__q2);
		__state = INITIALIZED;
		return __size;
	}
	else
	{
		__state = INVALID;
		return 0;
	}
}

int rect(int a, int b, int c, int d)
{
	if (__state != INITIALIZED)
	{
		__state = INVALID;
		return -1;
	}
	else if (__call_count >= 400)
	{
		__state = INVALID;
		return -1;
	}
	else
	{
		__call_count++;
		if ((a <= __r1) && (b >= __r1) && !((d < __c1) || (c > __c2)))
			return 1;
		else if ((c <= __q1) && (d >= __q1) && !((b < __p1) || (a > __p2)))
			return 1;
		else
			return 0;
	}
}

void report(int r1, int c1, int r2, int c2, int p1, int q1, int p2, int q2)
{
	if (__state != INITIALIZED)
	{
		printf("invalid\n");
		__state = INVALID;
	}
	else
	{
		printf("%d %d %d %d\n", r1, c1, r2, c2);
		printf("%d %d %d %d\n", p1, q1, p2, q2);
		printf("%d\n", __call_count);
		__state = INVALID;
	}
}
