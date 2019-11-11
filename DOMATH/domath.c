#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
int main(int argc, char *argv[]){
    
	int x = atoi(argv[1]);	
	int y = atoi(argv[2]);	
	
	pid_t z1 = fork();
	
	if (z1 == 0) {
		printf("child1: %d * %d = %d \n", x, y, x * y);
		exit(0);
	}    
	pid_t z2 = fork();
	
	if (z2 == 0) {
		printf("child2: %d + %d = %d \n", x, y, x + y);
		exit(0);
	} 
	pid_t z3 = fork();

	if (z3 == 0) {
		printf("child3: %d - %d = %d \n", x, y, x - y);
		exit(0);
	}    

	pid_t z4 = fork();
	
	if (z4 == 0) {
		printf("child4: %d / %d = %d \n", x, y, x / y);
		exit(0);
	} 
    	waitpid(z1, NULL, 0);
    	waitpid(z2, NULL, 0);
    	waitpid(z3, NULL, 0);
    	waitpid(z4, NULL, 0);

	printf("parent: done.\n");
	



}

