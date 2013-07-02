#include <iostream>
#include <string>
int main()
{
	std::string s("");
	double num = 0.f;
	const int count = 12;		//twelve lines
	for(int i = 0;i < count; ++i)			
	{
		std::cin >> s;
		num += atof(s.c_str());
	}
	printf("$%.2f\n",num/count);
	return 0;
}