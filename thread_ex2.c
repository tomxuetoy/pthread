#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

pthread_t ntid;

void err_sys(const char *s)
{
        printf("%s\n", s);
        exit(1);
}

void printids(const char *s)
{
        pid_t pid;
        pthread_t tid;

        pid = getpid();
        tid = pthread_self();
        printf("%s pid %u tid %u (0x%x) \n", s,
                (unsigned int)pid,
                (unsigned int)tid,
                (unsigned int)tid);
}

void *thr_fn(void *arg)
{
        printids("new thread:");
        return ((void *)0);
}

int main(void)
{
        int err;

        err = pthread_create(&ntid, NULL, thr_fn, NULL);
        if (err != 0)
                err_sys("pthread_create error\n");
        printids("main thread:");
        sleep(1);   // comment it or not gives different result

        exit(0);
}

/*
If sleep(1), then the result is below:
./example_pthread
main thread: pid 26029 tid 3078232896 (0xb77a1b40) 
new thread: pid 26029 tid 3078224752 (0xb779fb70) 

If no sleep(1), then the result is below:
./example_pthread
main thread: pid 26070 tid 3078568768 (0xb77f3b40) 
*/
