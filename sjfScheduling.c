#include<stdlib.h>

struct process{                                            // Each process is denoted by a structure object.

	int arrival_time;
	int burst_time;
	int pId;
};

int n=5;
void sort_process(struct process pQueue[n]){               // Here sorting of processes w.r.t arrival time is being done.

	struct process temp;
	for(int i = 0; i<(n-1); i++){

		for(int j = 0; j<(n-i-1); j++){

			if(pQueue[j].arrival_time>pQueue[j+1].arrival_time){
			temp = pQueue[j];
			pQueue[j] = pQueue[j+1];
			pQueue[j+1] = temp;
			}
		}
	}
}

int main(){

	
	struct process p[5]= {{10,5,0},{4,3,1},{3,5,2},{5,4,3},{6,6,4}};   // Initialization of processes with default values of A.T W.T 
	
	int waitingTime[n], turnaroundTime[n], completionTime[n];          // Array to store W.T, T.T and C.T for each process.
	int orderOfExecution[n];                                           // Array to store the order of execution of processes.

	sort_process(p);
	
	printf("\nThe execution sequence of processes is: ");
	
	for(int i = 0; i<n; i++){

		orderOfExecution[i] = p[i].pId;
		printf("P%d (BT:%d),  ",orderOfExecution[i],p[i].burst_time);
	}
	
	printf("\n\n");
	
	completionTime[0] = p[0].arrival_time + p[0].burst_time;                       // Computing completion time for each process.
	
	for(int i = 1; i<n; i++){
		
		completionTime[i] = completionTime[i-1] + p[i].burst_time;
	}
	
	for(int i = 0; i<n; i++){
		
		printf("Completion time of P%d: %d\n",p[i].pId,completionTime[i]);
	}

	printf("\n");

	float avgWaitingTime, avgTurnaround;
	float waitSum = 0, turnaroundSum = 0;
	
	for(int i = 0; i<n; i++){                                                      // Computing turnaround and waiting time for each process.

		turnaroundTime[i] = completionTime[i] - p[i].arrival_time;
		turnaroundSum = turnaroundSum + turnaroundTime[i];
		waitingTime[i] = turnaroundTime[i] - p[i].burst_time;
		waitSum = waitSum + waitingTime[i];	
	}
	
	for(int i = 0; i<n; i++){

		printf("Waiting time for process P%d : %d \n",orderOfExecution[i],waitingTime[i]);
	}

	avgWaitingTime = waitSum/n;
	avgTurnaround = turnaroundSum/n;
	printf("\nAverage Waiting time is: %.2f\n",avgWaitingTime);
	printf("Average Turnaround time is: %.2f\n",avgTurnaround);
}
