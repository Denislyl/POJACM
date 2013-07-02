#include <iostream>
#include <string>
#include <map>
std::map<std::string, int>g_table;
void compute(std::string& s)
{
	//format to standard form
	int i = 0;
	while ( s[i]!='\0' )
	{
		if ( s[i] == '-'  )
		{
			s.erase( i, 1 );
		}
		else
		{
			switch(s[i])
			{
			case 'A':
			case 'B':
			case 'C':
				s[i] = '2';
				break;
			case 'D':
			case 'E':
			case 'F':
				s[i] = '3';
				break;
			case 'G':
			case 'H':
			case 'I':
				s[i] = '4';
				break;
			case 'J':
			case 'K':
			case 'L':
				s[i] = '5';
				break;
			case 'M':
			case 'N':
			case 'O':
				s[i] = '6';
				break;
			case 'P':
			case 'R':
			case 'S':
				s[i] = '7';
				break;
			case 'T':
			case 'U':
			case 'V':
				s[i] = '8';
				break;
			case 'W':
			case 'X':
			case 'Y':
				s[i] = '9';
				break;
			default:
				//	ASSERT(FALSE);
				break;
			}
			++i;
		}
	}
	s.insert(3,1,'-');
	std::map<std::string, int>::iterator it = g_table.find(s); 
	if(it != g_table.end()) 
	{
		it->second++;
	}
	else
	{
		g_table[s] = 1;
	}
}
void Output()
{
	std::map<std::string, int>::iterator it = g_table.begin(); 
	bool isDplicate = false;
	for (;it != g_table.end();++it)
	{
		if (it->second > 1)
		{
			isDplicate = true;
			printf("%s %d\n",it->first.c_str(),it->second);
		}
	}
	if (!isDplicate)
	{
		printf("No duplicates.");
	}
}
int main()
{
	std::string s("");
	int count = 0;
	std::cin >>  count;
	for (; count > 0 ; --count)
	{
		std::cin >> s;
		compute(s);
	}
	Output();
	return 0;
}