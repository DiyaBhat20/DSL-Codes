/*Write program to implement a priority queue in C++ using an inorder list to store the items in the queue. 
Create a class that includes the data items (which should be template) and the priority (which should be int). 
The inorder list should contain these objects, with operator <= overloaded so that the items with highest 
priority appear at the start of the list (which will make it relatively easy to retrieve the highest item.)*/


#include<iostream>
using namespace std;

template<class T>
class Item
{
    public:
        T data;
        int priority;

        bool operator <=(Item<T> obj)
        {
            if(priority<=obj.priority)
            {
                return 1;
            }
            return 0;
        }
};

template<class T>
class PriorityQueue
{
    public:
	Item<T>*arr;
	int front,rear;
    int current_size,capacity;
	
	public:
		PriorityQueue(int n)
		{
			arr=new Item<T>[n];
			front=rear=-1;
			current_size=0;
			capacity=n;
		}
		
		void enqueue(T d,int p)
		{
            Item<T>temp;
            temp.data=d;
            temp.priority=p;
			if(front==-1)
			{
				front=rear=0;
				arr[rear]=temp;
				current_size++;
                cout<<"\nData added successfully...";
			}
			else if(current_size==capacity)
			{
				cout<<"Overflow !";
			}
			else
			{
                int i = front;
                while (i <= rear && arr[i] <= temp) 
                {
                    i++;
                }
                for (int j =rear+1; j > i; j--) 
                {
                    arr[j] = arr[j - 1];
                }
                arr[i] = temp;
                rear++;
                current_size++;
                cout << "\nData added successfully...";
			}
		}
		
		void dequeue()
		{
			if(front==-1)
			{
				cout<<"\nDequeue empty !";
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
                    current_size=0;
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
					cout<<"\nDATA : "<<arr[temp].data<<"     PRIORITY : "<<arr[temp].priority;
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
	PriorityQueue <string>obj(size);
    int choice;
    string d;
    int p;
    while(true)
    {
        cout<<"\n****************************MENU****************************";
        cout<<"\n1.Enqueue data";
        cout<<"\n2.Dequeue data";
        cout<<"\n3.Display Dequeue";
        cout<<"\n4.Exit";
        cout<<"\n************************************************************";
        cout<<"\nEnter your choice : ";
        cin>>choice;
        if(choice==1)
        {
            cin.ignore(1);
            cout<<"\nEnter data : ";
            getline(cin,d);
            cout<<"Enter priority : ";
            cin>>p;
            obj.enqueue(d,p);
        }
        else if(choice==2)
        {
            obj.dequeue();
        }
        else if(choice==3)
        {
            obj.display();
        }
        else if(choice==4)
        {
            cout<<"\nExiting...";
            return 0;
        }
        else
        {
            cout<<"\nInvalid choice !";
        }
    }
	return 0;
}
