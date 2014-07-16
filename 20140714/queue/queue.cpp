/*************************************************************************
	> File Name: queue.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月12日 星期六 23时56分41秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class  LIST 
{
	public:

		friend class QUEUE;

	private:
		int data_;
		LIST *next_;
};


class QUEUE
{
	public:

		void init()
		{
			head = tail = NULL;
		}

		void enqueue(int data);

		int dequeue();

		void print();
		



	private:
		LIST *head;
		LIST *tail;
		
};

void QUEUE::enqueue(int data)
{
	LIST *node = new LIST;
	node->data_ = data;
	node->next_ = NULL;
	if(tail == NULL)
	{
		head = tail = node;
	}
	else
	{
		tail->next_ = node;
		tail = node;

	}
}

int QUEUE::dequeue()
{
	LIST *node;
	int data;
	if(head != NULL)
	{
		node = head;
		head = head->next_;
	}
	data = node->data_;
	delete node;
	return data;
}

void QUEUE::print()
{
	LIST *l;
	l = head;
	while(l != NULL)
	{
		cout << l->data_ << " ";
		l = l->next_;
	}
	cout << endl;
}


int main(int argc, const char *argv[])
{
	QUEUE q;
	q.init();
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);

	q.print();

	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.print();
	return 0;
}
