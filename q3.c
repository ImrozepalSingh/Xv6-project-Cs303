#include "types.h"
#include "user.h"
int main(int argc, char *argv[])
{

// your code to print the process information in any format
if(argc==0) exit();

int n=atoi(argv[1])+1;
char h[100];
if(history(h,n)<0) exit();
splash(h);
//printf(1,"%d",strlen(h));

exit();

}
