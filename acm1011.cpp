#include<stdio.h>  
#include<algorithm>  
#define M 64 

int length,curStickLength,sticks[M],used[M];  

int cmp(int a,int b)
{  
	return a>b;  
}  

int dfs(int stickNum,int stickRemainder)
{  
	int i;  
	if(stickNum==0 && stickRemainder==0)	//finished
	{  
		return 1;  
	}  
	if(stickRemainder==0)	//next
	{  
		stickRemainder = curStickLength;  
	}  
	for(i=0;i<length;i++)
	{  
		if(!used[i] && sticks[i]<=stickRemainder)
		{  
			if(i>0)
			{  
				if(!used[i-1] && sticks[i-1]==sticks[i]) continue;//  
			}     
			used[i]=1;  
			if(dfs(stickNum-1,stickRemainder-sticks[i]))
			{
				return 1;//  
			}
			else 
			{  
				used[i]=0;  
				if(sticks[i]==stickRemainder || stickRemainder==curStickLength) 
				{
					return 0;  
				}
			}  
		}  // end if
	}  //end for
	return 0;  
}  

int main()
{  
	int i,j,sum;  
	while(scanf("%d",&length),length)
	{  
		sum=0;  
		for(i=0;i<length;i++)
		{  
			scanf("%d",&sticks[i]);  
			sum+=sticks[i];  
		}  
		std::sort(sticks,sticks+length,cmp);  
		for(i=sticks[0];i<=sum/2;i++)
		{  
			if(sum%i==0)
			{  
				for(j=0;j<length;j++)
				{  
					used[j]=0;  
				}  
				curStickLength=i;  
				if(dfs(length,curStickLength)){  
					printf("%d\n",curStickLength);  
					break;  
				}  
			}             
		}  
		if(i>sum/2)printf("%d\n",sum);  
	}  
	return 0;  
}   