#include "types.h"
#include "user.h"
int main(int argc, char *argv[])
{

// your code to print the process information in any format
if(argc==0) exit();


char h[100];
for(int i=1;i<=16;++i){
for(int j=0;j<100;++j) h[j]=0;

if(history(h,i)<0) continue;
//splash(h);
printf(1,"%s\n",h);
}




//printf(1,"%d",strlen(h));

exit();

}
