#include<stdio.h>
#include<iostream>
#include<queue>
using namespace std;

void queueOp(queue<int> q)
{
	
	for (int i = 0; i < 5; i++)
	{
		q.push(i);
		
	}
	while(!q.empty())
	{
		
		int r = q.front();
		cout << r << "\n";
		q.pop();
		
	}
	
	

}
int main()
{
	queue<int> test;
	queueOp(test);
}