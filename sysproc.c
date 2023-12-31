#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"
#include "stat.h"
#include "spinlock.h"
#include "sleeplock.h"
#include "fs.h"
#include "buf.h"
#include "file.h"
//# include "string.h"
int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}
////////////////////////// >_< /////////////////////////////////////////////////////////////////


int sys_getprocinfo(void)
{

 int pid;
  if(argint(0, &pid) < 0)
    return -1;
struct uproc *up;
if(argptr(1, (void*)&up, sizeof(*up)) < 0)
    return -1;
return getprocinfo(pid,up);


}
int sys_splash(void)
{
char* str;
if(argstr(0,&str)<0) return -1;

return splash(str);

}

int sys_history(void)
{
char* str;
if(argstr(0,&str)<0) return -1;
int i;
 if(argint(1, &i) < 0)
    return -1;

return history(str,i);

}
int sys_wait2(void){

int *re,*ru,*sl;
if(argptr(0, (void*)&re, sizeof(int)) < 0)
    {return -1;}
    if(argptr(1, (void*)&ru, sizeof(int)) < 0)
   { return -1;}
    if(argptr(2, (void*)&sl, sizeof(int)) < 0)
   { return -1;}
    return wait2(re,ru,sl);

}
