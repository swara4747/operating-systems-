//inter process communication 
//write a c program to implement inter process communication using pipes 

#include<stdio.h>
#include<unistd.h>
#include <string.h>

int main(){
int status[2];                 //status used for the file descritor which give single input telling which file is being accessed
char o[100];

pipe(status);





if (fork()==0){                              //child process is completed
close(status[1]);                    //here the process has ended



read (status[0], o, sizeof(o));
printf("child process completed  %s  \n", o);

close(status[0]);
}

else {
close(status[0]);

strcpy(o, "\nthis is the parent process  \n");



write (status[1], o, strlen(o)+1);

close (status[1]);
}


return 0;
}
