#include <iostream>
#include <map>
int main()
{
	std::map<int,int>result;
	const double erosion = 1.f / (50 * 2);
	const double PI = 3.1415926;
	int count = 0;
	double x = 0 , y = 0;
	double area = 0;
	std::cin >>  count;
	for (int i = 1; i <= count ; ++i)
	{
		std::cin >> x >> y;
		area = (x*x+y*y) * PI * erosion;
		result[i] = (int)area+1;
	}
	for (std::map<int,int>::iterator it = result.begin(); it != result.end() ; ++it )
	{
		printf("Property %d: This property will begin eroding in year %d.\n", it->first , it->second);
	}
	printf("END OF OUTPUT.");
	return 0;
}