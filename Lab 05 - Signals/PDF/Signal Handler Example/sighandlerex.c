#include  <signal.h>

static void sig_handler(int);

int main (void) {
	int i, parent_pid, child_pid, status;
	
	/*Prepare the sig_handler routine to catch SIGUUSR1 and SIGUSR2 */
	if (signal(SIGUSR1, sig_handler)==SIG_ERR)
		printf(“parent:Unable to create handler for SIGUSR1\n”);
	if (signal(SIGUSR2, sig_handler)==SIG_ERR
			printf(“Parent: unable to create handler for SIGUSR2\n”);
  
	parent_pid = getpid();
	
	if ((child_pid = fork())==0) {
		/*Raise the SIGUSR1 signal */
		kill(parent_pid, SIGUSR1);
		/*Child process begins busy-wait for a signal */
		for (;;) pause ();
	}
	else {
			/*Parent raising SIGUSR2 signal*/
			kill(child_pid, SIGUSR2);
			printf(“Parent: Terminating child ...”);
			/*Parent raising SIGTERM signal */
			kill(child_pid, SIGTERM);
			/* Parent waiting for child termination */
			wait(&status);
			printf(“done\n”);
	}
}

static void sig_handler(int signo) {
	switch (signo) {
	
		/*Incoming SIGUSR1 signal */
		case SIGUSR1:
				printf(“Parent: Received SIGUSR1\n”);
				break;

		/*Incoming SIGUSR2 signal */
		case SIGUSR2:
			printf(“Child: Received SIGUSR2\n”);
			break;
  
		/* Should never get this case */
		default: break;
		
	}
	return;
}