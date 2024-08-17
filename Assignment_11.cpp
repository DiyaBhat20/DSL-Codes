/*Queues are frequently used in computer programming, and a typical example is the creation 
of a job queue by an operating system. If the operating system does not use priorities, then
the jobs are processed in the order they enter the system. Write C++ program for simulating 
job queue. Write functions to add job and delete job from queue.*/

#include<iostream>
using namespace std;

class Node
{
	public:
		int data;
		Node *next;
};

class JobQueue
{
	private:
		Node *front;
		Node *rear;
		int current_size;
		int capacity;
	public:
	    JobQueue(int c)
		{
			this->front=NULL;
			this->rear=NULL;
			current_size=0;
			capacity=c;
		}
		void enqueue(int data);	
		void dequeue();
		bool isEmpty();
		int getFront();	
		void display();
};

void JobQueue::enqueue(int data)
{
	Node *newNode;
	newNode=new Node();
	newNode->data=data;
	newNode->next=NULL;
	if(this->front==NULL)
	{
		this->front=this->rear=newNode;
        this->current_size++;
	}
    else if(current_size==capacity)
    {
        cout<<"\nQueue is full...";
    }
	else
	{
		this->rear->next=newNode;
		this->rear=newNode;
        this->current_size++;
	}
}

void JobQueue::dequeue()
{
	if(this->front==NULL)
	{
		cout<<"\nQueue Empty!";
		return;
	}
	else
	{
		Node *new_front,*old_front;
		new_front=this->front->next;
		old_front=this->front;
		this->front=new_front;
		if(this->front==NULL)
        {
            this->rear=NULL;
        } 
		delete old_front;
        this->current_size--;
		cout<<"Deleted Successfully !!";
	}
}

void JobQueue::display()
{
	Node *ptr;
	ptr=front;
	if(ptr==NULL)
	{
		cout<<"\nQueue is empty...";
		return;
	}
	while(ptr->next!=NULL)
	{
		cout<<ptr->data<<" ";
		ptr=ptr->next;
	}
	cout<<ptr->data;	
}

int main()
{
    int size;
    cout<<"Enter the size of queue : ";
    cin>>size;
	JobQueue obj(size);
	int choice,data;
	while(true)
	{
		cout<<"\n***************MENU*****************";
	    cout<<"\n1.Enter Job"<<"\n2.Delete Job"<<"\n3.Display Job"<<"\n4.Exit";
	    cout<<"\n************************************";
	    cout<<"\nEnter your choice : ";
	    cin>>choice;
	    if(choice==1)
	    {
	    	cout<<"Enter job number : ";
	    	cin>>data;
	    	obj.enqueue(data);
		}
		else if(choice==2)
		{
			obj.dequeue();
		}
		else if(choice==3)
		{
			cout<<"Job Queue : ";
			obj.display();
		}
		else
		{
			break;
		}
	}
	return 0;
}