#include<stdio.h>
#include<stdlib.h>

struct process{

	int burst_time;
	int waiting_time;
};

void sort_process(int pQueue[], int n){

	int temp;
	for(int i = 0; i<(n-1); i++){

		for(int j = 0; j<(n-i-1); j++){

			if(pQueue[j]>pQueue[j+1]){
			temp = pQueue[j];
			pQueue[j] = pQueue[j+1];
			pQueue[j+1] = temp;
			}
		}
	}
}

int main(){

	int n;
	
	struct process *p;

	printf("Enter the number of processes\n");
	scanf("%d",&n);
	p = (struct process*) malloc (n*sizeof(struct process));
	for(int i = 0; i<n; i++){

		printf("Enter the burst time of process P%d: ",i);
		scanf("%d",&(p+i)->burst_time);
	}
	int pQueue[n];
	for(int i = 0; i<n; i++){

		pQueue[i] = (p+i)->burst_time;
	}
	sort_process(pQueue,n);
	for(int i = 0; i<n; i++){

		printf("%d ",pQueue[i]);
	}
}
