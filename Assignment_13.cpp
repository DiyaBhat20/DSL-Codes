/*A double-ended queue (deque) is a linear list in which additions and deletions may be made at either end. 
Obtain a data representation mapping a deque into a onedimensional array. Write C++ program to simulate deque
with functions to add and delete elements from either end of the deque*/

#include<iostream>
using namespace std;

class Dequeue
{
	int *dequeue;
	int front,rear;
	int current_size,capacity;
	
	public:
		Dequeue(int n)
		{
			dequeue=new int[n];
			front=rear=-1;
			current_size=0;
			capacity=n;
		}
		
		void enqueue(int data)
		{
			if(front==-1)
			{
				front=rear=0;
				dequeue[rear]=data;
				current_size++;
                cout<<"\nData added successfully...";
			}
			else if(current_size==capacity)
			{
				cout<<"\nOverflow !";
			}
			else
			{
				rear++;
		        dequeue[rear]=data;
		        current_size++;
                cout<<"\nData added successfully...";
			}
		}
		
		void enqueue_front(int data)
		{
            int i=0;
			if(front==-1)
			{
				front=rear=0;
				dequeue[rear]=data;
				current_size++;
                cout<<"\nData added successfully...";
			}            
			else if(current_size==capacity)
			{
				cout<<"\nOverflow !";
			}
			else
			{
				for(int i=current_size;i>0;i--)
				{
					dequeue[i]=dequeue[i-1];
				}
				dequeue[0]=data;
				current_size++;
				rear++;
                cout<<"\nData added successfully...";
			}
		}
		
		void dequeue_front()
		{
			if(front==-1)
			{
				cout<<"Dequeue empty !";
			}
			else
			{
				if(front<rear)
				{
					front++;
					current_size--;
				}
				else if(front==rear)
				{
					front=rear=-1;
				}
                cout<<"\nData deleted successfully...";
			}
		}
		
		void dequeue_back()
		{
			if(front==-1)
			{
				cout<<"Dequeue empty !";
			}
			else
			{
				if(rear>front)
				{
					rear--;
					current_size--;
				}
				else if(front==rear)
				{
					front=rear=-1;
				}
                cout<<"\nData deleted successfully...";
			}
		}
		
		void display()
		{
			int temp;
			temp=front;
			if(temp==-1)
			{
				cout<<"Dequeue Empty !";
			}
			else
			{
                cout<<"\nDequeue : ";
				while(temp<=rear)
				{
					cout<<dequeue[temp]<<" ";
		            temp++;	
				}
			}
		}
};

int main()
{
	int size;
	cout<<"Enter size of dequeue : ";
	cin>>size;
	Dequeue obj(size);
    int choice;
    int data;
    while(true)
    {
        cout<<"\n**********************MENU**********************";
        cout<<"\n1.Enqueue from front";
        cout<<"\n2.Enqueue from back";
        cout<<"\n3.Dequeue from front";
        cout<<"\n4.Dequeue from back";
        cout<<"\n5.Display dequeue";
        cout<<"\n6.Exit";
        cout<<"\n************************************************"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        if(choice==1)
        {
            cout<<"\nEnter the data you want to enqueue : ";
            cin>>data;
            obj.enqueue_front(data);
        }
        else if(choice==2)
        {
            cout<<"\nEnter the data you want to enqueue : ";
            cin>>data;
            obj.enqueue(data);
        }
        else if(choice==3)
        {
            obj.dequeue_front();
        }
        else if(choice==4)
        {
            obj.dequeue_back();
        }
        else if(choice==5)
        {
            obj.display();
        }
        else if(choice==6)
        {
            cout<<"\nExiting...";
            return 0;            
        }
        else
        {
            cout<<"\nInvalid Choice...";
        }
    }
	return 0;
}
