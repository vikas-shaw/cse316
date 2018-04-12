#include<stdio.h>
#include<stdlib.h>

struct process{

	int burst_time;
	int waiting_time;
	int pId;
};

int n;
void sort_process(struct process pQueue[n], int n){

	struct process temp;
	for(int i = 0; i<(n-1); i++){

		for(int j = 0; j<(n-i-1); j++){

			if(pQueue[j].burst_time>pQueue[j+1].burst_time){
			temp = pQueue[j];
			pQueue[j] = pQueue[j+1];
			pQueue[j+1] = temp;
			}
		}
	}
}

int main(){

	struct process *p;

	printf("Enter the number of processes: ");
	scanf("%d",&n);
	printf("\n");
	
	p = (struct process*) malloc (n*sizeof(struct process));
	
	for(int i = 0; i<n; i++){

		(p+i)->pId = i;
	}
	
	for(int i = 0; i<n; i++){

		printf("Enter the burst time of process P%d: ",(p+i)->pId);
		scanf("%d",&(p+i)->burst_time);
	}
	
	int waitTime[n];
	int orderOfExecution[n];
	int turnAround, sum = 0;
	
	sort_process(p,n);
	
	printf("\nThe sequence of process according to brust time is: ");
	
	for(int i = 0; i<n; i++){

		orderOfExecution[i] = (p+i)->pId;
		printf("P%d ",orderOfExecution[i]);
	}
	printf("\n\n");
	
	waitTime[0]=0;
	for(int i = 1; i<=n; i++){

		waitTime[i] = sum + p[i-1].burst_time;
		sum = sum + p[i-1].burst_time;	
	}
	
	for(int i = 0; i<n; i++){

		printf("Waiting time for process P%d : %d \n",orderOfExecution[i],waitTime[i]);
	}
	int avgWaitingTime, avgTurnaround;
	int waitSum = 0, turnaroundSum = 0;
	for(int i = 0; i<n; i++){

		waitSum = waitSum + waitTime[i];
		turnaroundSum = turnaroundSum + (p+i)->burst_time;
	}
	avgWaitingTime = waitSum/n;
	avgTurnaround = turnaroundSum/n;
	printf("\nAverage Waiting time is: %d\n",avgWaitingTime);
	printf("Average Turnaround time is: %d\n",avgTurnaround);
}
