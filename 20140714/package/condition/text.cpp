/*************************************************************************
	> File Name: text.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月14日 星期一 20时52分42秒
 ************************************************************************/


#include "my_condition.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

using namespace std;

pthread_mutex_t mutex; //互斥锁，保护队列
Condition full;    //同步量，代表有产品可拿
Condition empty;  //同步量，代表可以放入
int num = 0;
void *producer(void *arg){
    while(1){
        pthread_mutex_lock(&mutex);
        /*
         *  这段代码存在缺陷。
         *
         */
        if(num >= 10){
            //队列满
			empty.wait(mutex);
        }
        //生产操作
		num++;
        printf("procuder now : %d\n", num);
		full.signal();	
        pthread_mutex_unlock(&mutex);


        sleep(3);
    }
}

void *consumer(void *arg){
    while(1){
        pthread_mutex_lock(&mutex);
        if(num == 0){
            printf("wait producer\n");
			full.wait(mutex);
        }
        //消费操作
		num--;
        printf("consume now: %d\n", num);

		empty.signal();
        pthread_mutex_unlock(&mutex);
    }
}


int main(int argc, const char *argv[])
{
    pthread_mutex_init(&mutex, NULL);


    pthread_t t1, t2;
    pthread_create(&t1, NULL, producer, NULL);
    pthread_create(&t2, NULL, consumer, NULL);


    pthread_join(t1, NULL);
    pthread_join(t2, NULL);



    pthread_mutex_destroy(&mutex);
    return 0;
}
