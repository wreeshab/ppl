#include <iostream>
using namespace std;

class string1{
	public:
	string s;
	string1(string s1)
	{
		s=s1;
	}
};
class string2{
	public:
	string s;
	string2(string s1)
	{
		s=s1;
	}
};
class concat:public string1,public string2
{
	public:
		string result;
		concat(string s1,string s2):string1(s1),string2(s2)
		{
			result=s1+s2;
		}
};
class palindrome:public concat
{
	public:
		int isp;
		palindrome(string s1,string s2):concat(s1,s2)
		{
			int i;
			for(i=0;i<result.length();i++)
			{
				if(result[i]!=result[result.length()-i-1])
				{
					isp=0;
					break;
				}
			}
			if(i==result.length())
			{
				isp=1;
			}
		}
};
int main()
{
	palindrome p("race","car");
	if(p.isp)
	{
		cout<<"Palindrome";
	}
	else
	{
		cout<<"Not a palindrome";
	}
	
}