#include <sys/time.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>

long unsigned int fibonacci(unsigned int n);

static long p_realt_secs = 0, c1_realt_secs = 0, c2_realt_secs = 0;
static long p_virtt_secs = 0, c1_virtt_secs = 0, c2_virtt_secs = 0;
static long p_proft_secs = 0, c1_proft_secs = 0, c2_proft_secs = 0;
static struct itimerval p_realt, c1_realt, c2_realt;
static struct itimerval p_virtt, c1_virtt, c2_virtt;
static struct itimerval p_proft, c1_proft, c2_proft;

main(int argc, char**argv) {
	long unsigned fib = 0;
	int pid1, pid2;
	unsigned int fibarg;
	int status;

	// Get command line arugment, fibarg
	...
	// Initialize parent, cild1, and child 2 timer values
	...
	// Enable your signal handlers for the parent
	signal(SIGALRM, ...);
	signal(SIGVTALRM, ...);
	signal(SIGPROF, ...);

	// Set the parent's itimers
	...
	pid1 = fork();

	if(pid1 == 0) {
		// Enable child 1 signal handlers (disable parent handlers)

		// Set the child 1 itimers

		// Start child 1 on the Fibonacci program
		fib = fibonacci)fibarg);

		// Read the child 1 itimer values, and report them
		getitimer(ITIMER_PROF, ...);
		getitimer(ITIMER_REAL, ...);
		getitimer(ITIMER_VIRTUAL, ...);
		printf("\n");
		printf("Child 1 fib = %ld, real time = %ld sec, %ld msec\n",
				fib, c1_realt_secs,
				elasped_usecs(c1_realt.it_value.tv_sec,
						c1_realt.it_value.tv_usec) / 1000);
		printf("Child 1 fib = %ld, cpu time = %ld sec, %ld msec\n",
				fib, c1_proft_secs,
				elapsed_usecs(c1_proft.it_value.tv_sec,
						c1_proft.it_value.tv_usec) / 1000);
		printf("Child 1 fib = =%ld, user time = %ld sec, %ld msec\n",
				fib, c1_virtt_secs,
				elapsed_usecs(c1_virtt.it_value.tv_sec,
						c1_virtt.it_value.tv_usec) / 1000);
		printf("Child 1 ib  = %ld, kernel time = %ld sec, %ld msec\n",
				fib, c1_proft_secs – c1_virtt_secs,
				(elaspsed_usecs(c1_proft.it_value.tv_sec,
						c1_proft.it_value.tv_usec) / 1000) -
						(elapsed_usecs(c1-virtt.it_value.tv_sec,
								c1_virtt.it_value.tv_usec) / 1000));
		fflush(stdout);
		exit(0);
	}
	else {
		pid2 = fork();
		if(pid2 == 0) {
			// Enable the child 2 signal handlers (disable parent handlers)
			...
			// Set the child 2 itimers
			...
			// Start the child 2 on the Fibonacci program
			fib = fibonacci(fibarg);
			// Read the child 2 itimer values and report them
			...
		}
		else { /* This is the parent */
			//Start the parent on the Fibonacci program 
			fib = fibonacci(fibarg);

			// Wait for the children to terminate
			waitpid(0, &status, 0);
			waitpid(0, &status, 0);

			// Read the parent itimer values, and report them
			...
		}
		printf("this line should never be printed\n");
	}
}

long unsigned int fibonacci(unsigned int n) {
	if(n ==0)
		return 0;
	else if (n == 1 || n ==2)
		return 1;
	else 
		return (fibonacci(n-1_ + fibonacci(n-2))
}