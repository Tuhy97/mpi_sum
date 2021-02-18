#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
 
using namespace std;
 
class Solution
{
public:
	void generate_nums()
	{
		srand(time(NULL));
		for (auto &r : nums_)
			r = rand();
	}
 
	void save_nums(string file_name)
	{
		ofstream ofs(file_name);
 
		for (auto &r : nums_)
			ofs << &r << '\n';
		
		ofs.close();
	}
 
	void sort_nums()
	{
		sort(nums_.begin(), nums_.end());
	}
private:
	vector<int> nums_ = vector<int>(1000000);
};
 
int main()
{
	Solution s;
 
	s.generate_nums();		//generate 1 million nums
	s.save_nums("nums");	//save to file "nums"
	s.sort_nums();			//sort
	s.save_nums("nums2");	//save to file "nums2"
 
	return 0;
}
//https://blog.csdn.net/timberwolf_2012/article/details/39398505?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-16.baidujs&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-16.baidujs
