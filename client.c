#include<sys/shm.h>
#include<string.h>
#include<stdio.h>
main()
{
        char *a,*b,*c;
        int id1,id2,id3;
        id1=shmget(4066,1,IPC_CREAT|0660);
        id2=shmget(4098,1,IPC_CREAT|0660);
        id3=shmget(4076,1,IPC_CREAT|0660);
        a=shmat(id1,NULL,0); //Attaching((NULL takes next free space and flag set to zero.
        b=shmat(id2,NULL,0);
        c=shmat(id3,NULL,0);
        strcpy(a,"shega");
        strcpy(b,"mariyam");
        shmdt(a);//detaching
        shmdt(b);
        sleep(5);
        printf("String after concatination is , c= %s",c);
        shmdt(c);
}