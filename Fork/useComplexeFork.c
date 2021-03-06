#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include "complexe.h"

int main()
{
Complexe z1, z2, z3;
pid_t pid_fils;

do{
        pid_fils = fork(); // run the fork() function
	z1 = nouveauComplexe(1.,0.);
	z2 = nouveauComplexe(0.,1.);
	z3 = plus(z1,z2);

	printf("Module de Z3 : %f\n",module(z3));
	printf("Argument de z3 : %f\n",argument(z3));
	fprintf(stdout, "Mon PID est : %ld\n", (long) getpid());
}while((pid_fils == -1) && (errno == EAGAIN));

if(pid_fils == -1){
	fprintf(stderr, "fork() impossible, errno=%d\n", errno);
	return 1;
}

if(pid_fils == 0){
   /*this is a child Process*/
   printf("\n======================Child Process=========================\n");
   fprintf(stdout, "CHILD PROCESS : PID=%ld, PPID=%ld\n", (long)getpid(), (long)getppid());
   return 0;
}
else{

 	/* Parent Process */
 	printf("\n===================Parent Process===========================\n");
 	fprintf(stdout, "Pere : PID=%ld, PPID=%ld, PID fils=%ld\n",(long)getpid(), (long)getppid(), (long)pid_fils);
 	return 0;

}
return EXIT_SUCCESS;

}
