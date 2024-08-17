/*In any language program mostly syntax error occurs due to unbalancing delimiter such as (),{},[]. 
Write C++ program using stack to check whether given expression is well parenthesized or not*/

#include<iostream>
using namespace std;

class Stack
{
	private:
		int capacity;
		char *arr;
		int top;
	
	public:
	    Stack(int c);
	    void push(char data);
	    void pop();
	    char getTop();
	    bool isEmpty();
	    bool isFull();
	    int size();
	    bool check(char *c);
};

bool Stack::check(char *c)
{
	int i=0;
	while(c[i]!='\0')
	{
		if(c[i]=='(' || c[i]=='{' || c[i]=='[')
		{
			push(c[i]);
		}
		else if(c[i]==')' || c[i]=='}' || c[i]==']')
		{
			if(isEmpty())
			{
				return 0;
			}
			else if(c[i]==')' && getTop()=='(' || c[i]==']' && getTop()=='[' || c[i]=='}' && getTop()=='{')
			{
				pop();
			}
			else if(c[i]==')' && getTop()!='(' || c[i]==']' && getTop()!='[' || c[i]=='}' && getTop()!='{')
			{
				return 0;
			}						
		}
		i++;
	}
	if(isEmpty())
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

Stack::Stack(int c)
{
	this->capacity=c;
	arr=new char[c];
	this->top=-1;
}

void Stack::push(char data)
{
	if(top==capacity-1)
	{
		cout<<"\nStack overflow !"<<endl;
		return;
	}
	top++;
	arr[top]=data;
}

void Stack::pop()
{
	if(top==-1)
	{
		cout<<"\nStack underflow !"<<endl;
		return;
	}
	top--;	
}

char Stack::getTop()
{
	if(top==-1)
	{
		cout<<"\nStack underflow !"<<endl;
		return 0;
	}
	return arr[top];
}

bool Stack::isEmpty()
{
	return top==-1;
}

bool Stack::isFull()
{
	return top==capacity-1;
}

int Stack::size()
{
	return top+1;
}

int main()
{
	int size;
	cout<<"Enter the size of stack : ";
	cin>>size;
	Stack obj(size);
	char exp[20];
	cout<<"Enter the expression : ";
	cin.ignore(1);
	cin.getline(exp,20);
	if(obj.check(exp))
	{
		cout<<"Expression well Parenthesized !";
	}
	else
	{
		cout<<"Expression not well Parenthesized !";
	}
	return 0;
}