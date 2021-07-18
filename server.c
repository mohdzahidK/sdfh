#include<string.h>
#include<sys/shm.h>
#include<stdio.h>
main()
{
        int id1,id2,id3;
        char *x,*y,*z;
        id1=shmget(4066,1,IPC_CREAT|0660);
        id2=shmget(4098,1,IPC_CREAT|0660);
        id3=shmget(4076,1,IPC_CREAT|0660);
        x=shmat(id1,NULL,0);
        printf("\nThe value of x= %s",x);
        y=shmat(id2,NULL,0);
        printf("\nThe value of y = %s",y);
        z=shmat(id3,NULL,0);
        strcpy(z,x);
        strcat(z,y);
        shmdt(x);
        shmdt(y);
        shmdt(z);
        printf("\nConcatinated string sent to client");
}