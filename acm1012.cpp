#include<stdio.h>
int result[14];
int findout(int round,int mod)
{
	int length,s = 0;
	length=2 * round;
	for(int i=0;i<round;i++)
	{
		s=(s+mod-1)%(length-i);
		if(s<round) return 0;//wrong number
	}
	return 1;
}
int main()
{
	int index = 0,num = 0;
	for(num=1;num<=14;num++)
	{
		index=num+1;
		while(1)
		{
			if(findout(num,index))//t(k+1)
			{
				result[num]=index;
				break;
			}
			else if(findout(num,index+1))//t(k+1)+1
			{
				result[num]=index+1;
				break;
			}
			index+=num+1;
		}
	}
	int answer;
	while(scanf_s("%d",&answer) && answer)
	{
		printf("%d\n",result[answer]);
	}
	return 0;
}