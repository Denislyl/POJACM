#include <iostream>
int main()
{
	int times = 0;
	std::cin >> times;
	for ( ;times > 0 ; times--)
	{
		char line1[5] = {0};
		char line2[5] = {0};
		char line3[5] = {0};
		int result[12] = {0};
		bool lock[12] = {false};
		for(int it = 0; it < 3 ; ++it)
		{
			std::cin >> line1;
			std::cin >> line2;
			std::cin >> line3;
			int c = 0;
			if (0 == strcmp (line3 ,"down"))
			{
				for (int i = 0 ; i < strlen(line1) ; i++ )
				{
					c = line1[i] - 'A';
					if (lock[c])
					{
						continue;
					}
					result[c] --;
				}
				for (int i = 0 ; i < strlen(line2) ; i++ )
				{
					c = line2[i] - 'A';
					if (lock[c])
					{
						continue;
					}
					result[c] ++;
				}
			} 
			else if (0 == strcmp (line3 ,"up"))
			{
				for (int i = 0 ; i < strlen(line1) ; i++ )
				{
					c = line1[i] - 'A';
					if (lock[c])
					{
						continue;
					}
					result[c] ++;
				}
				for (int i = 0 ; i < strlen(line2) ; i++ )
				{
					c = line2[i] - 'A';
					if (lock[c])
					{
						continue;
					}
					result[c] --;
				}
			} 
			else
			{
				int c = 0;
				for (int i = 0 ; i < strlen(line1) ; i++ )
				{
					c = line1[i] - 'A';
					result[c] = 0;
					lock[c] = true;
				}
				for (int i = 0 ; i < strlen(line2) ; i++ )
				{
					c = line2[i] - 'A';
					result[c] = 0;
					lock[c] = true;
				}
			}//end if
		}//end for
		int answer = 0;
		int max = 0;
		bool isLight = false;
		for (int i = 0; i < 12; i ++)
		{
			if (!lock[i]) 
			{
				if (max<abs(result[i])) 
				{
					max=abs(result[i]);
					answer=i;
				}
			}
		}
		if (result[answer]>0) 
			isLight	= false;
		else
			isLight = true;
		if (isLight)
		{
			printf("%c is the counterfeit coin and it is light.\n", answer + 'A');
		} 
		else
		{
			printf("%c is the counterfeit coin and it is heavy.\n", answer + 'A');
		}
	}
	return 0;
}