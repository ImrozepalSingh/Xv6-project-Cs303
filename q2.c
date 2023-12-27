#include "types.h"
#include "user.h"
#include "stat.h"

int main(int argc, char *argv[])
{

static char* enumStrings[] ={ "UNUSED", "EMBRYO", "SLEEPING","RUNNABLE", "RUNNING", "ZOMBIE" };


if(fork()==0) {
while(1);

}

if(fork()==0) {
while(1);

}
struct uproc u;
struct uproc *up=&u;
int pid=1;
while(pid<100000){
if(getprocinfo(pid,up)==1)
printf(1,"pid->%d\tname->%s\tppid->%d\tsize->%d\tstate->%s\tkilled->%d\t\n",up->pid,up->name,up->ppid,up->sz,enumStrings[up->state],up->killed); 
pid+=1;

}

exit();

}
