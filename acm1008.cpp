#include <iostream>
#include <string>
#include <vector>
struct result
{
	int day;
	int month;
	int year;
	result(int d, int str, int y)
	{
		day = d;
		month = str;
		year = y;
	}
};
std::vector<result>g_result;
std::string tzolkinDay[20]={"imix","ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat",
	"muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};
std::string haabMonth[19]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac",
	"ceh","mac","kankin", "muan","pax","koyab","cumhu","uayet"};
int HaabMonthTrans(const char* str)
{
	for(int i=0;i<19;i++)
	{
		if(str == haabMonth[i])
			return i;
	}
	return -1;
}
void TransToTzolkin(int day)
{
	int year = day/260;
	int TzolkinDay = day%260;
	if(year!=0 && TzolkinDay==0){
		result re(13,19,year-1);	//last day in a year
		g_result.push_back(re);
		return;
	}
	int periods = ((TzolkinDay-1) % 13) +1;
	int curMonth = (TzolkinDay-1)  %20;
	
	result re(periods,curMonth,year);
	g_result.push_back(re);
}
void Output()
{
	std::cout << g_result.size() << std::endl;
	for (std::vector<result>::iterator it = g_result.begin(); it!= g_result.end(); ++it)
	{
		std::cout<<it->day<<" "<<tzolkinDay[it->month]<<" "<<it->year<<std::endl;
	}
}
int main()
{
	int length = 0 ;
	std::cin >> length ;
	std::string monthStr("");
	int month;
	char dot;	//
	int day = 0;
	int year = 0;
	for (;length>0;length--)
	{
		std::cin >> day >> dot >> monthStr >> year;
		month = HaabMonthTrans(monthStr.c_str());
		int totalDays = year*365 + month*20 + day + 1;
		TransToTzolkin(totalDays);
	}
	Output();
	return 0;
}		