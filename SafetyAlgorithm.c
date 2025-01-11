#include <stdio.h>
#include <stdbool.h>

int alloc[20][20];
int max[20][20];
int need[20][20];
int available[20];
bool flag[20] = {false};
int n, m;

int main()
{
	printf("Enter number of processes: ");
	scanf("%d", &n);
	printf("Enter number of resources: ");
	scanf("%d", &m);
	
	printf("\nEnter Allocation Matrix:\n");
	
	for(int i = 1; i <= n; i++) {
		printf("Allocation for process %d: ", i);
		for(int j = 1; j <= m; j++) {
			scanf("%d", &alloc[i][j]);
		}
	}
	
	printf("\nEnter Max Matrix:\n");
	
	for(int i = 1; i <= n; i++) {
		printf("Max need for process %d: ", i);
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
	
	int sequence[20], idx = 1;
	
	for(int l = 1; l <= n; l++) {
		for(int i = 1; i <= n; i++) {
			if(flag[i]) continue;
			flag[i] = true;
			
			for(int j = 1; j <= m; j++) {
				if(need[i][j] > available[j]) {
					flag[i] = false;
				}
			}
			
			if(flag[i]) {
				for(int j = 1; j <= m; j++) {
					available[j] += alloc[i][j];
				}
				sequence[idx] = i; idx++;
			}
		}
	}
	
	if(idx > n) {
		printf("\nProcesses are in safe state.\nSafe execution sequence:");
		for(int i = 1; i <= n; i++) {
			printf(" Process %d,", sequence[i]);
		}
	} else {
		printf("\nProcesses are in deadlock");
	}
	
	return 0;
}