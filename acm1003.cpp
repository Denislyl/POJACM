#include <iostream>
#include <map>
std::map<int, float>g_table;
void BuildUpMap()
{
	const float MAX	= 5.20f;
	int	n	= 2;
	float sum = 0.f;
	for (;sum < MAX; ++n)
	{
		sum += 1.f/n;
		g_table[ n-1] = sum;
	}
}
int main()
{
	char s[5] = {0};
	double num = 0.f;
	while(scanf("%s",s))
	{
		if (strcmp(s,"0.00")!=0)
		{
			num = atof(s);
			std::map<int,float>::iterator it = g_table.begin();
			for (;it !=g_table.end();++it )
			{
				if (it->second > num)
				{
					break;
				}
			}
			printf("%d card(s)\n",it->first);
		}
		else
		{
			break;
		}
	}
	return 0;
}