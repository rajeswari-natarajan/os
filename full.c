#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
//#include<sys/types.h>
int main()
{
        int x,y,l1,l2,p1[2],p2[2];
        long int cid;
        char s1[20],s2[20];
        x=pipe(p1);
        y=pipe(p2);
        cid=fork();
        if(cid<0)
                printf("\n\nError");
        else if(cid>0)
        {
                printf("\n\n.......**.PARENT BLOCK.**.........");
                close(p1[0]);
                printf("\n\nEnter your first string... ");
                scanf("%s",s1);
                l1=strlen(s1);
                write(p1[1],s1,l1);
                sleep(5);
                close(p2[1]);
                read(p2[0],s2,l2);
                printf("\n\n.........**PARENT BLOCK**..........");
                printf("\n\nThe second string from child s2 = %s",s2);

        }
        else
        {
                sleep(4);
                printf("\n\n........CHILD BLOCK...........");
                close(p1[1]);
                read(p1[0],s1,l1);
                printf("%s",s1);
                printf("\n\nString1 from parent is s1 = %s",s1);
                close(p2[0]);
                printf("\n\nEnter your second string.. ");
                scanf("%s",s2);
                l2=strlen(s2);
                write(p2[1],s2,l2);
        }
        return(0);
}
