//枚举法
#include <iostream>
#include <vector>
std::vector<int>g_result;
int main()
{
	const int physicalDays = 23;
	const int emotionalDays = 28;
	const int intellectualDay = 33;
	const int MAX = 23*28*33;
	int physical = 0, emotional = 0, intellectual = 0 , totalDayRemainder = 0;
	int physicalRemainder = 0, emotionalRemainder = 0, intellectualRemainder = 0 ;
	while (true)
	{
		std::cin >> physical >> emotional >> intellectual >> totalDayRemainder;
		if ( (physical == -1 ) &&
			(emotional == -1) &&
			(intellectual == -1) &&
			(totalDayRemainder == -1) )
		{	
			break;		
		}
		physicalRemainder = physical%physicalDays;
		emotionalRemainder = emotional%emotionalDays;
		intellectualRemainder = intellectual%intellectualDay;
		int sum = 1;
		for(;sum <= MAX;)
		{
			if (sum%physicalDays == physicalRemainder)
			{
				if (sum%emotionalDays == emotionalRemainder)
				{
					if (sum%intellectualDay == intellectualRemainder)
					{
						int x = sum-totalDayRemainder;
						if(x<=0) x += MAX;   
						g_result.push_back(x);
						break;
					}
					else
					{
						sum += physicalDays*emotionalDays;
					}
				}
				else
				{
					sum += physicalDays;
				}
			}
			else
			{
				sum++;
			}
		}
	}
	std::vector<int>::iterator it = g_result.begin();
	for (int i = 1;it != g_result.end(); ++it, ++i)
	{
		printf("Case %d: the next triple peak occurs in %d days.\n",i , *it);
	}
	return 0;
}

//同余定理
//#include<iostream>
//#include <vector>
//std::vector<int>g_result;
//int main()
//{
//	int p,e,i,d,a,t=0;
//	while(true)
//	{
//		std::cin>>p>>e>>i>>d;
//		if(p==-1 && e==-1 && i==-1 && d==-1)
//			break;
//		a=(5544*p+14421*e+1288*i-d+21252)%21252;
//		if(!a)
//			a=21252;
//		g_result.push_back(a);
//	}
//	std::vector<int>::iterator it = g_result.begin();
//	for (int i = 1;it != g_result.end(); ++it, ++i)
//	{
//		printf("Case %d: the next triple peak occurs in %d days.\n",i , *it);
//	}
//	return 0;
//}