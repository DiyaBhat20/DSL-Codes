/*Second year Computer Engineering class, set A of students like Vanilla Ice-cream and set B of students like 
butterscotch ice-cream. Write C++ program to store two sets using linked list. compute and display
a) Set of students who like both vanilla and butterscotch 
b) Set of students who like either vanilla or butterscotch or not both 
c) Number of students who like neither vanilla nor butterscotch*/

#include<iostream>
using namespace std;

class Node
{
    public:
        int value;
        Node *next; 
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
    void either_vanillaorbutterscotch(LinkedList,LinkedList);
    void intersectionNode(LinkedList,LinkedList);
    void notBoth(LinkedList,LinkedList);
};

void LinkedList::input()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int num;
        cout<<"Enter roll number : ";
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

void LinkedList::either_vanillaorbutterscotch(LinkedList obj1, LinkedList obj2)
{
    Node *nodeptr1 = obj1.head;
    Node *nodeptr2 = obj2.head;

    while (nodeptr1 != NULL)
    {
        int data = nodeptr1->value;
        int found = 0;
        Node *temp = obj2.head;

        while (temp != NULL)
        {
            if (temp->value == data)
            {
                found = 1;
                break;
            }
            temp = temp->next;
        }

        if (found == 0)
        {
            appendNode(data);
        }

        nodeptr1 = nodeptr1->next;
    }

    while (nodeptr2 != NULL)
    {
        int data = nodeptr2->value;
        int found = 0;
        Node *temp = obj1.head;

        while (temp != NULL)
        {
            if (temp->value == data)
            {
                found = 1;
                break;
            }
            temp = temp->next;
        }

        if (found == 0)
        {
            appendNode(data);
        }

        nodeptr2 = nodeptr2->next;
    }
}


void LinkedList::intersectionNode(LinkedList obj1,LinkedList obj2)
{
    Node *nodeptr1,*nodeptr2;
    nodeptr1=obj1.head;	
    while(nodeptr1!=NULL)
    {
    	int data = nodeptr1->value;
    	nodeptr2=obj2.head;
    	while(nodeptr2!=NULL)
    	{
    		if(nodeptr2->value==data)
    		{
    			appendNode(data);
    			break;
			}
    		nodeptr2=nodeptr2->next;
		}
		nodeptr1=nodeptr1->next;
	}
}

void LinkedList::notBoth(LinkedList obj1,LinkedList obj2)
{
    Node *nodeptr1,*nodeptr2;
	nodeptr1=obj1.head;
	while(nodeptr1!=NULL)
	{
		int data=nodeptr1->value;
		nodeptr2=obj2.head;
		int found=0;
		while(nodeptr2!=NULL)
		{
			if(nodeptr2->value==data)
			{
				found++;
			}
			nodeptr2=nodeptr2->next;
		}
		if(found==0)
		{
			appendNode(data);
		}
		nodeptr1=nodeptr1->next;		
	}	
}

int main()
{
    LinkedList List,List1,List2,List3,List4,List5;
    cout<<"Enter total number of students : ";
    List.input();
    cout<<"Enter number of students who like vanilla ice cream : ";
    List1.input();
    cout<<"Enter number of students who like butterscotch ice cream : ";
    List2.input();
    cout<<"\nTotal Students : [";
    List.displayNode();
    cout<<"]";
    cout<<"\nStudents who like vanilla ice cream : [";
    List1.displayNode();
    cout<<"]";
    cout<<"\nStudents who like butterscotch ice cream : [";
    List2.displayNode();
    cout<<"]";   
    int choice;
    while(true)
    {
        cout<<"\n*************************MENU******************************";
        cout<<"\n1.Students who like both vanilla and butterscotch";
        cout<<"\n2.Students who like either vanilla or butterscotch or not both";
        cout<<"\n3.Number of students who like neither vanilla nor butterscotch";
        cout<<"\n4.Exit";
        cout<<"\n***********************************************************";
        cout<<"\nEnter your choice : ";
        cin>>choice;
        if(choice==1)
        { 
            List4.intersectionNode(List1,List2);
            cout<<"\nStudents who like both vanilla and butterscotch : [";
            List4.displayNode();
            cout<<"]";            
        }
        else if(choice==2)
        {
            List3.either_vanillaorbutterscotch(List1,List2);
            cout<<"\nStudents who like either vanilla or butterscotch but not both : [";
            List3.displayNode();
            cout<<"]";
        }
        else if(choice==3)
        {
            List5.notBoth(List,List3);
            cout<<"\nStudents who like neither vanilla nor butterscotch : [";
            List5.displayNode();
            cout<<"]";
        }
        else if(choice==4)
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