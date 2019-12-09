#include "my.h"

#define PROMPT "DO you want terminateprogram ?"
char* prompt=PROMPT;
 
void ctrl_c(signo){
	fprintf(stderr,prompt);
	//write(STD_FILENO,prompt,strlen(prompt));
}

int main()
{
	struct sigaction act;
	act.sa_handler=ctrl_c;
	sigemptyset(&act.sa_mask);
	act.sa_flags=0;
	if(sigaction(SIGINT,&act,NULL)<0)
	{
		fprintf(stderr,"Install Signal Action Error:%s\n",strerror(perror));
		exit(1);
	}
	printf("process id is %d\n",getpid());
	while(1);
	//signal(SIGHUP,sigtoutine);
	//signal(SIGINT,sigtoutine);
	//signal(SIGQUIT,sigtoutine);

}











