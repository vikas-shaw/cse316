#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
int main(){
	
	int i;
	scanf("%d",&i);
	if(i<0){

		printf("Negative value not accepted!\n");
		exit(0);
	}
	if(fork()== 0){

		while(i>=1){

			printf("%d ",i);
			i/=2;
		}

	}
	else{

		wait(NULL);

	}
	return 0;
}
