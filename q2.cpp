#include <iostream>
using namespace std;
class add{
	public:
		
		int result;
		add(int x,int y){
	 		  result=x+y;
		}	
};
class sub{
	public:		
		int result;
		sub(int x,int y){
	 		  result=x-y;
		}	
};
class prod:public add,public sub
{
	public:
		int p;
		prod(int x, int y):add(x, y), sub(x, y){
			p = add::result * sub::result;
		}		
};
class square:public prod
{
	public:
		int p_2;
		square(int x,int y):prod(x,y)
		{
			p_2=p*p;
		}
		int return_1()
		{
			return p_2;
		}
};
class cube:public prod
{
	public:
		int p_3;
		cube(int x,int y):prod(x,y)
		{
			p_3=p*p*p;
		}
		int return_2()
		{
			return p_3;
		}
};
int main()
{
	square s=square(5,2);
	cube c(5,2);
	cout<< s.p_2 <<endl;
	cout<< c.p_3;
}