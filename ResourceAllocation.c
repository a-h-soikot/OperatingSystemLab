#include <stdio.h>
#include <stdbool.h>

int alloc[20][20];
int max[20][20];
int need[20][20];
int available[20];
int request[20]; 
bool flag[20] = {false};
int n, m;

bool isSafe() { 

	int work[20];
	for(int j = 1; j <= m; j++) work[j] = available[j];
	for(int i = 1; i <= n; i++) flag[i] = false;
	
	for(int l = 1; l <= n; l++) {
		for(int i = 1; i <= n; i++) {
			if(flag[i]) continue;
			flag[i] = true;
			
			for(int j = 1; j <= m; j++) {
				if(need[i][j] > work[j]) {
					flag[i] = false;
				}
			}
			
			if(flag[i]) {
				for(int j = 1; j <= m; j++) {
					work[j] += alloc[i][j];
				}
			}
		}
	}
	
	for(int i = 1; i <= n; i++) {
		if(flag[i] == false) return false;
	}
	
	return true;
}

int main()
{
	printf("Enter number of processes: ");
	scanf("%d", &n);
	printf("Enter number of resources: ");
	scanf("%d", &m);
	
	printf("\nEnter Allocation Matrix:\n");
	
	for(int i = 1; i <= n; i++) {
		//printf("Allocation for process %d: ", i);
		for(int j = 1; j <= m; j++) {
			scanf("%d", &alloc[i][j]);
		}
	}
	
	printf("\nEnter Max Matrix:\n");
	
	for(int i = 1; i <= n; i++) {
		//printf("Max need for process %d: ", i);
		for(int j = 1; j <= m; j++) {
			scanf("%d", &max[i][j]);
		}
	}
	
	printf("\nEnter Available Matrix: ");
	
	for(int j = 1; j <= m; j++) {
		scanf("%d", &available[j]);
	}
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			need[i][j] = max[i][j] - alloc[i][j];
		}
	}
	
	
	while(true) {
		printf("\nEnter requesting process's id: ");
		int pid; scanf("%d", &pid);
	
		printf("Enter request matrix for process %d: ", pid);
	
		for(int j = 1; j <= m; j++) scanf("%d", &request[j]);
		
		int _case = 3;
	
		for(int j = 1; j <= m; j++) {
			if(request[j] > need[pid][j]) {
				_case = 1; break;
			}
		}
		
		for(int j = 1; j <= m && _case == 3; j++) {
			if(request[j] > available[j]) _case = 2;
		}
		
		switch(_case) {
			case 1: printf("Error: Process exceeded maximum claim.\n");
					break;
			
			case 2: printf("Error: Enough Resources are not available.\n");
					break;
			
			case 3: 
					for(int j = 1; j <= m; j++) {
						available[j] -= request[j];
						alloc[pid][j] += request[j];
						need[pid][j] -= request[j];
					}
					
					if(isSafe() == true) {
						printf("Process %d is successfully allocated resources.\n", pid);
					} else {
						printf("Resources can't be allocated, system is in unsafe state.\n");
						// Rollback allocation
						for(int j = 1; j <= m; j++) {
							available[j] += request[j];
							alloc[pid][j] -= request[j];
							need[pid][j] += request[j];
						}
						
					}
					
					break;		
		}
	}
	
	return 0;
}