#include <iostream>
#include <string>

std::string Power(std::string str,const int power);
std::string StringMultiply(std::string dest, std::string src);
std::string DigitalMultiply(std::string dest,const char src);
std::string StringAdd(std::string dest, std::string src);

int main()
{
	std::string str;
	int powerNum = 0;
	int point = 0;
	while (std::cin>> str >>powerNum)
	{
		if(str.find(".") != std::string::npos )
		{
			for (int i = str.size()-1 ; str[i]=='0' ; --i)		//remove back zeros
			{
				str.erase(i,1);
			}
			point = str.size() - str.find(".") -1;
			str.erase( str.find('.'), 1 );				//remove point
		}
		for (int i = 0 ; str[i]=='0' ; )				//remove front zeros
		{
			str.erase(i,1);
		}
		str = Power( str, powerNum );
		if (point > 0 )
		{
			point *= powerNum;
			if ( str.size() >= point )							//length enough
			{
				str.insert(str.size()-point, 1 , '.' );		//add point
			}
			else
			{
				std::string temp(point - str.size() ,'0');			//fill zeros
				temp = "."+temp;
				str = temp + str;
			}
		}
		std::cout<<  str << std::endl;
	}
	return 0;
}
std::string Power(std::string str,const int powerNum)
{
	if (1 == powerNum)
	{
		return str;
	}
	if (powerNum % 2 == 0)
	{
		return StringMultiply( Power(str,powerNum/2) , Power(str,powerNum/2) );
	} 
	else
	{
		std::string temp = str;
		str = StringMultiply( Power(str,(powerNum-1)/2) , Power(str, (powerNum-1)/2) );
		return StringMultiply(str , temp);
	}
}

std::string StringMultiply(std::string dest, std::string src)
{
	if (dest=="0" || src=="0")
	{
		return "0";
	}
	if (dest=="1")
	{
		return src;
	}
	if (src=="1")
	{
		return dest;
	}
	std::string sum("0");
	std::string temp("");
	int indexSrc = src.size() - 1;
	for (int i = 0; indexSrc > -1; ++i, --indexSrc )
	{
		temp = DigitalMultiply(dest, src[indexSrc]) + std::string(i,'0');
		sum = StringAdd(sum , temp);
	}
	return sum;
}

std::string DigitalMultiply(std::string dest,const char src)
{
	if (src == '1')
	{
		return dest;
	}
	if (src == '0')
	{
		return std::string("0");
	}
	int carryBit = 0;
	int indexDest = dest.size() - 1;
	int n = src - '0';
	for (; indexDest > -1; --indexDest )
	{
		int num = ( dest[indexDest] - '0' ) * n  + carryBit;
		carryBit = num/10;
		num = num%10;
		dest[indexDest] = num + '0';
	}
	if ( carryBit > 0 )			//final carry
	{
		char c = carryBit + '0';
		dest = c + dest;
	}
	return dest;
}

std::string StringAdd(std::string dest, std::string src)
{
	if (dest.size() < src.size())
	{
		return StringAdd(src , dest);
	}
	int carryBit = 0;
	int indexDest = dest.size() - 1;
	int indexSrc = src.size() - 1;
	for (; indexSrc > -1; --indexDest, --indexSrc )
	{
		int num = dest[indexDest] - '0' + src[indexSrc] - '0' + carryBit;
		carryBit = num/10;
		num = num%10;
		dest[indexDest] = num + '0';
	}
	if (carryBit > 0)			//extra carry
	{
		for (; indexDest > -1; --indexDest)
		{
			int num = dest[indexDest] - '0' + carryBit;
			carryBit = num / 10;
			num = num%10;
			dest[indexDest] = num + '0';
			if (carryBit == 0)
			{
				break;
			}
		}
	}
	if ( carryBit > 0 )			//final carry
	{
		char c = carryBit + '0';
		dest = c + dest;
	}
	return dest;
}