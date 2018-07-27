#include<iostream>
namespace yanzhao
{
	int count;
	int show()
	{
		return count;
	}
}
namespace yanzhao2
{
	int count;
	int show()
	{
		return count;
	}
}
int main()
{
	yanzhao::count=2017;
	std::cout<<yanzhao::show()<<std::endl;
	yanzhao2::count=222;
	std::cout<<std::endl;
	std::cout<<std::endl;
	std::cout<<yanzhao2::show()<<std::endl;
}