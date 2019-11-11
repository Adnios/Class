#include <iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
#include <fstream>
#include <iomanip>
using namespace std;
class Median
{
public:
	double getMedian() {
		if (big_queue.size()==small_queue.size())
		{
			return (double)(big_queue.top() + small_queue.top()) / 2;
		}
		else if (big_queue.size() > small_queue.size()) {
			return big_queue.top();
		}
		return small_queue.top();
	}
	void addNum(int num) {
		if (big_queue.empty())
		{
			big_queue.push(num);
			return;
		}
		if (big_queue.size() == small_queue.size()) {
			if (big_queue.top()>num)
			{
				big_queue.push(num);
			}
			else {
				small_queue.push(num);
			}
		}
		else if (big_queue.size() > small_queue.size())
		{
			if (big_queue.top()<num)
			{
				small_queue.push(num);
			}
			else {
				small_queue.push(big_queue.top());
				big_queue.pop();
				big_queue.push(num);
			}
		}
		else if (big_queue.size() < small_queue.size()) {
			if (small_queue.top() < num)
			{
				big_queue.push(small_queue.top());
				small_queue.pop();
				small_queue.push(num);
			}
			else {
				big_queue.push(num);
			}
		}
	}
private:
	priority_queue<int> big_queue;
	priority_queue<int, vector<int>, greater<int> > small_queue;
};
int main()
{
	Median median;
	int n,p,a[1010];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p;
		if(p==1){
			cin>>a[i];
			median.addNum(a[i]);
		}
		if(p==2){
			double m = median.getMedian();
			cout<<m<<endl;
		}
	}
	return 0;
}
