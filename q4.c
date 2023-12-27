#include "types.h"
#include "user.h"
int main(int argc, char *argv[])
{

int t1,t2,t3;
t1=t2=t3=0;
if(fork()==0){

if(fork()==0){
sleep(2);
exit();

}
wait();

for(int i=0;i<10000000;++i){
for(int j=0;j<10000000;++j){

for(int k=0;k<10000000;++k);
}
}
	sleep(2);


exit();
}
else{
int pid;
if((pid=wait2(&t1,&t2,&t3))<0) exit();

printf(1,"pid->%d:(\t%d,\t%d\t,%d)\n",pid,t1,t2,t3);

}

exit();

}
