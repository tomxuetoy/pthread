#include <pthread.h>   
#include <stdio.h>   
#include <sys/time.h>   
#include <string.h>   
#include <unistd.h>  
 
#define MAX 30

pthread_t thread[2];   
pthread_mutex_t mut;   
int number=0, i;   

void *thread1()   
{   
       printf ("thread1 : I'm thread 1, my thread id is %lu\n", pthread_self());   
       for (i = 0; i < MAX; i++)   
       {   
               printf("thread1 : number = %d_______________\n",number);   
               pthread_mutex_lock(&mut);   
                       number++;   
               pthread_mutex_unlock(&mut);   
               usleep(100000);   
        }   
        printf("thread1 :the main function is waiting for me?\n");   
        pthread_exit(NULL);   
}   

void *thread2()   
{   
        printf ("thread2 : I'm thread 2, my thread id is %lu\n", pthread_self());   
        for (i = 0; i < MAX; i++)   
        {   
                printf("thread2 : number = %d\n",number);   
                pthread_mutex_lock(&mut);   
                        number++;   
                pthread_mutex_unlock(&mut);   
                usleep(200000);   
         }   
         printf("thread2 :the main function is waiting for me? \n");   
         pthread_exit(NULL);   
}   

void thread_create(void)   
{   
        int temp;  
		printf("thread address is %p...%p\n",thread, &thread); 
        memset(thread, 0, sizeof(thread));          //initialize  
 
        /*Create thread*/  
        if((temp = pthread_create(&thread[0], NULL, thread1, NULL)) != 0)  //return thread id to thread[0]   
                printf("Thread 1 fail to create!\n");   
        else  
                printf("Thread 1 created!\n");   
        if((temp = pthread_create(&thread[1], NULL, thread2, NULL)) != 0)  //return thread id to thread[1]   
                printf("Thread 2 fail to create!");   
        else  
                printf("Thread 2 created!\n");   
}   

void thread_wait(void)   
{   
        /*Wait thread end*/  
        if(thread[0] != 0) {                		//if thread id is effective   
                pthread_join(thread[0],NULL);  		//will be blocked here untill the target thread terminates
                printf("Thread 1 completed\n");   
        }   
        printf("between pthread_join(), if print something, where will it be shown?\n");
        if(thread[1] != 0) {                		//if thread id is effective
                pthread_join(thread[1],NULL);   	//will be blocked here untill the target thread terminates
                printf("Thread 2 completed.\n");   
        }   
        printf("after pthread_join(), if print something, where will it be shown?\n");
}   

int main()   
{   
        /*init mutex*/  
        pthread_mutex_init(&mut,NULL);   
        printf("Main function,creating thread...\n");  
 
        thread_create();   
        printf("Main function,waiting for thread end....\n");   

        thread_wait();   
        return 0;
}
