#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include<stdlib.h>
#define SHMSZ 27
main()
{
       char c;
        int shmid;
        key_t key;
        char *shm, *s;
        key = 4009;
        if ((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0)
        {
                perror("shmget");
                exit(1);
        }
        if ((shm = shmat(shmid, NULL, 0)) == (char *) -1)
        {
                perror("shmat");
                exit(1);
        }
        printf("server writing the content of shared memory\n");
	s=shm;
	for ( c='a';c<='z';c++)
	     *s++=c;
	     *s='\0';
	      while(*shm!='*')
		      sleep(1);
	      printf("client modified the content as \n");
	printf("%s",shm);

        exit(0);
}

