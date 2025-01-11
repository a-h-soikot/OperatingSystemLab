#include<iostream>
#include<queue>
using namespace std;

struct process {
	int pno, bt, ct;
};

int main() 
{	
	printf("Enter number of processes: ");
	int n; scanf("%d", &n);
	process p[n+1];
	
	queue<int> ready_queue;
	
	printf("Enter time quantum: ");
	int t = 0, tq; scanf("%d", &tq);
	
	printf("Enter the burst time:\n");
	
	for(int i = 1; i <= n; i++) {
		p[i].pno = i;
		printf("process %d: ", i);
		scanf("%d", &p[i].bt);
		ready_queue.push(i);
	}
	
	while(!ready_queue.empty()) {
		int pno = ready_queue.front(); 
		ready_queue.pop();
		
		int time_executed = min(p[pno].bt, tq);
		
		printf("\nprocess %d: from %d ", pno, t);
		
		t += time_executed;
		
		printf("to %d", t);
		
		p[pno].bt -= time_executed;
		
		if(p[pno].bt > 0) ready_queue.push(pno);
		else p[pno].ct = t;
	}
	
	return 0;
}