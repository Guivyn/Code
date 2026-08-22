#include<stdio.h>
#include<queue>
using namespace std;

queue<int> q;
int main()
{
	int n;
	scanf("%d", &n);
	
	for(int i=0;i<n;i++) q.push(i+1); //鍒濆鍖栭槦鍒?

	while(!q.empty())                 //褰撻槦鍒楅潪绌烘椂
	{
		printf("%d ", q.front());     //杈撳嚭闃熼鍏冪礌
		q.pop();                      //绉婚櫎杩欎竴鍏冪礌
		q.push(q.front());            //鎶婇槦棣栧厓绱犵Щ鍒伴槦灏?
		q.pop();                      //绉婚櫎杩欎竴鍏冪礌
	}
	printf("\n");
	return 0;
}