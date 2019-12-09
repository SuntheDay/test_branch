#include "my.h"

static int sig_cnt[NSIG];
static int number=0;
int sigorder[128]={0};

#define MSG "#%d:reciever signal %d\n"

void handler(int signo)
{
	sigorder[number++]=signo;
}

int main(int argc,char* argv[])
{
	int i=0;
	int k=0;
	sigset_t blockmask;
	sigset_t emptymask;
	sigset_t pendmask;
	struct sigaction sa;

	sigfillset(&blockmask);
#ifdef USE_SIGACTION
	sa.sa_handler=handler;
	sa.sa_mask=blockmask;
	sa.sa_flags=SARESTART;
#endif





}
