#include <iostream>
#include <vector>
#include <string>
struct resultNode
{
  std::string str;
	int count;
	resultNode* next;
	resultNode* prev;
};
class resultList
{
	resultNode *head;
	resultNode *tail;
public:
	resultList();
	void insert(std::string& str,int count);
	void output();
};
void resultList::insert(std::string& str,int count)		// from “most sorted” to “least sorted”
{
	if(head == NULL)		//empty list
	{
		head = new resultNode();
		head->next = tail;
		head->prev = NULL;
		head->str = str;
		head->count = count;
	}
	else
	{
		resultNode *cur = head;
		resultNode *pre = NULL;
		while (cur != tail)						//searching
		{
			if (count < cur->count)			//insert
			{
				resultNode * temp = new resultNode();
				temp->str = str;
				temp->count = count;
				if(cur->prev == NULL)
				{
					head =temp;
				}
				else
				{
					cur->prev->next = temp;
				}
				temp->next = cur;
				temp->prev = cur->prev;
				cur->prev = temp;
				return;			//
			}
			else
			{
				pre = cur;
				cur = cur->next;
			}//end if
		}//end while

		//extra tail
		cur = new resultNode();
		pre->next = cur;
		cur->next = tail;
		cur->prev = pre;
		cur->str = str;
		cur->count = count;
	}//end else
}
resultList::resultList()
{
	head = NULL;
	tail = NULL;
}
void resultList::output()
{
	if (head)
	{
		resultNode* p = head;
		while(p)
		{
			std::cout << p->str << std::endl;
			p = p->next;
		}
	}
}
int compute(std::string& str)
{
	int sum = 0;
	int countA = 0;
	int countC = 0;
	int countG = 0;
	int countT = 0;
	for (int i = 0; i < str.size(); ++i)
	{
		switch(str[i])
		{
		case 'A':
			++countA;
			sum = sum + countC + countG + countT;
			break;
		case 'C':
			++countC;
			sum = sum + countG + countT;
			break;
		case 'G':
			++countG;
			sum = sum + countT;
			break;
		case 'T':
			++countT;
			break;
		}
	}
	return sum;
}
int main()
{
	int length = 0, number = 0 ;
	std::cin >> length >> number;
	std::string str;
	resultList	result;
	for (;number>0;number--)
	{
		std::cin >> str;
		int count = compute(str);
		result.insert(str , count);
	}
	result.output();
	return 0;
}		
