/*Write C++ program for storing binary number using doubly linked lists. Write functions
a) To compute 1‘s and 2‘s complement
b) Add two binary numbers*/

#include<iostream>
using namespace std;

class Node
{
	public:
		int value;
		Node *next;
		Node *previous;
};

class LinkedList
{
    private:
    	Node *head;

    public:
    LinkedList()      
    {
        head=NULL;
    }
    void input();
    void appendNode(int n);
    void displayNode();
    void onescompliment();
    void insertNode_Start(int n);
    void binary(int n);
    void twoscomplement();
    int countNodes();
    void addition(LinkedList obj1,LinkedList obj2);
    void delete_node();
    
    void appendNode_start(int n)
    {
    	
        Node *newNode,*nodePtr;
        newNode=new Node;
        newNode->value=n;
        newNode->next=NULL;
        newNode->previous=NULL;   	
    	if(head==NULL)
    	{
    		head=newNode;
		}
		else
		{
			newNode->next=head;
			head->previous=newNode;
			head=newNode;
		}
	}
};

void LinkedList::delete_node()
{
	head=NULL;
}

void LinkedList::input()
{
    for(int i=0;i<4;i++)
     {
        int num;
        cout<<"Enter binary number (0/1) : ";
        cin>>num;
        appendNode(num);
    }
}

void LinkedList::appendNode(int n)
{
    Node *newNode,*nodePtr;
    newNode=new Node;
    newNode->value=n;
    newNode->next=NULL;
    newNode->previous=NULL;

    if(!head)
    {
        head=newNode;
    }
    else
    {
        nodePtr=head;
        while(nodePtr->next)
        {
            nodePtr=nodePtr->next;
        }
        nodePtr->next=newNode;
        newNode->previous=nodePtr;
    }
}

void LinkedList::displayNode()
{
    Node *nodePtr;
    nodePtr=head;
    while(nodePtr)
    {
        cout<<nodePtr->value<<" ";
        nodePtr=nodePtr->next;
    }
}

void LinkedList::onescompliment()
{
    Node *nodePtr;
    nodePtr=head;
    while(nodePtr)
    {
        if(nodePtr->value==0)
        {
            nodePtr->value=1;
        }
        else
        {
            nodePtr->value=0;
        }
        nodePtr=nodePtr->next;
    }
}

void LinkedList::insertNode_Start(int n)
{
    Node *newNode,*nodePtr;
    nodePtr=head;
    newNode =new Node;
    newNode->value=n;
    newNode->next=head;
    newNode->previous=NULL;
    head=newNode;
}

void LinkedList::twoscomplement()
{
    onescompliment();
    Node *ptr=NULL;
    ptr=head;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    if(ptr->value==0)
    {
        ptr->value=1;
    }
    else
    {
        ptr->value=0;
        if(ptr->previous->value==0)
        {
                ptr->previous->value=1;
        }
        else
        {
            ptr->previous->value=0;
            if(ptr->previous->previous->value==0)
            {
                ptr->previous->previous->value=1;
            }
            else
            {
                ptr->previous->previous->value=0;
                if(ptr->previous->previous->previous->value==0)
                    {
                        ptr->previous->previous->previous->value=1;
                    }
                    else
                    {
                        ptr->previous->previous->previous->value=0;
                        Node *newnode=new Node;
                        newnode->value=1;
                        newnode->previous=NULL;
                        newnode->next=head;
                        head=newnode;
                    }
                }
            }
        }
}

void LinkedList::binary(int n)
{
    if(n==0)
    {
        for(int i=0;i<4;i++)
        {
            appendNode(0);
        }
    }
    else
    {
        while(n>0)
        {
            int rem=n%2;
            appendNode_start(rem);
            n/=2;
        }
        while(countNodes()<4)
        {
            appendNode_start(0);
        }
    }
}

int LinkedList::countNodes()
{
    int count = 0;
    Node *nodePtr = head;
    while (nodePtr)
    {
        count++;
        nodePtr = nodePtr->next;
    }
    return count;
}

void LinkedList::addition(LinkedList obj1,LinkedList obj2)
{
    Node *ptr1 = obj1.head;
    Node *ptr2 = obj2.head;
    int carry = 0;

    while (ptr1->next != NULL && ptr2->next != NULL) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    while (ptr1 != NULL || ptr2 != NULL) {
        int sum = carry;
        if (ptr1 != NULL) 
		{
            sum += ptr1->value;          
            ptr1 = ptr1->previous;
        }
        if (ptr2 != NULL) {
            sum += ptr2->value;
            ptr2 = ptr2->previous;
        }

        if (sum == 2) {
            carry = 1;
            appendNode_start(0);
        } else if (sum == 3) {
            carry = 1;
            appendNode_start(1);
        } else {
            carry = 0;
            appendNode_start(sum);
        }
    }

    if (carry) {
        appendNode_start(1);
    }
}


int main()
{
    LinkedList list1,list2,list3,list4,list5,list6;
    int choice;
    while(1)
    {
	    cout<<"\n********************MENU**********************";
    	cout<<"\n1.Convert Decimal to Binary";
        cout<<"\n2.Ones Compliment";
	    cout<<"\n3.Twos Compliment";
    	cout<<"\n4.Addition of two binary numbers";
    	cout<<"\n5.Exit";
    	cout<<"\n**********************************************"<<endl;	
        cout<<"Enter your choice : ";
        cin>>choice;
        if (choice==1)
        {
            int num;
            cout<<"Enter number less than 16 : ";
            cin>>num;
            if(num>=16)
            {
                cout<<"Enter valid number!";
            }
            else
            {
	            list1.binary(num);
	            cout<<"\nBinary Conversion : ";
	            list1.displayNode();
	            list1.delete_node();
  		    }
	    }
	    else if(choice==2)
	    {
	        list2.input();
	        list2.onescompliment();
	        cout<<"\nOnes Compliment : ";
	        list2.displayNode();
	    }
	    else if(choice==3)
	    {
	        list3.input();
	        list3.twoscomplement();
	        cout<<endl;
	        list3.displayNode();
	    }
	    else if(choice==4)
	    {
	        cout<<"\nEnter first binary number : ";
	        list4.input();
	        cout<<"\nEnter second binary number : ";
	        list5.input();
	        cout<<"\nFirst binary number : ";
	        list4.displayNode();
	        cout<<"\nSecond binary number : ";
	        list5.displayNode();
	        cout<<"\nAddition of two binary numbers : ";
	        list6.addition(list4,list5);
	        list6.displayNode();
	    }
	    else if(choice==5)
	    {
		    cout<<"\nExiting...";
		    return 0;
     	}
	    else
	    {
		    cout<<"\nInvalid Choice !";
	    }
    }
	return 0;
}
