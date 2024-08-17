/*Implement C++ program for expression conversion as infix to postfix and its evaluation using stack based on given conditions: 
1. Operands and operator, both must be single character. 
2. Input Postfix expression must be in a desired format.
3. Only '+', '-', '*' and '/ ' operators are expected*/

#include<iostream>
#include<string.h>
using namespace std;

class Stack
{
	private:
		int capacity;
		char *input_stack;
		char *infix_to_postfix;
		char *stack;
		char *data;
		int top;
		int *eval;
	public:
	    Stack(int c);
	    void infix_postfix();
		void get_data_for_evaluation();
		float evaluate();
		void input();
		void display();
};

Stack::Stack(int c)
{
	this->capacity=c;
	input_stack=new char[c];
	infix_to_postfix=new char[c];
	stack=new char[c];
	eval=new int[c];
	data=new char[c];
	this->top=-1;
}

void Stack::display()
{
	cout<<"\nInput Stack : "<<input_stack;
	cout<<"\nInfix to postfix : "<<infix_to_postfix;
	cout<<"\nExpression : "<<data;
}

void Stack::input()
{
	cout<<"\nEnter the infix expression : ";
	cin.getline(input_stack,capacity);
}

void Stack::infix_postfix()
{
	top=-1;
	int i=0;
	int j=0;
	while(input_stack[i]!='\0')
	{
		if(input_stack[i]=='+'||input_stack[i]=='-'||input_stack[i]=='*'||input_stack[i]=='/')
		{
			if(input_stack[i]=='+'||input_stack[i]=='-')
			{
				if(top==-1)
				{
					top++;
					stack[top]=input_stack[i];
				}
				else if(stack[top]=='+'||stack[top]=='-')
				{
					infix_to_postfix[j]=stack[top];
					stack[top]=input_stack[i];	
					j++;
				}
				else if(stack[top]=='*'||stack[top]=='/')
		    	{
				    infix_to_postfix[j]=stack[top];
					stack[top]=input_stack[i];	
					j++;
			    }
			}
			else
			{
				if(top==-1)
				{
					top++;
					stack[top]=input_stack[i];
				}
				else if(stack[top]=='+'||stack[top]=='-')
				{
					top++;
					stack[top]=input_stack[i];
				}
				else if(stack[top]=='*'||stack[top]=='/')
		    	{
				    infix_to_postfix[j]=stack[top];
				    stack[top]=input_stack[i];
				    j++;
			    }												
			}
		}
		else
		{
			infix_to_postfix[j]=input_stack[i];
			j++;
		}
		i++;
	}
	while(top!=-1)
	{
		char temp;
		temp=stack[top];
		top--;
		infix_to_postfix[j]=temp;
		j++;
	}
	infix_to_postfix[j]='\0';
}

void Stack::get_data_for_evaluation()
{
	int i=0;
	int j=0;
	int x;
	while(infix_to_postfix[i]!='\0')
	{
		if(infix_to_postfix[i]>='a'&& infix_to_postfix[i]<='z' || infix_to_postfix[i]>='A'&&infix_to_postfix[i]<='Z')
		{
			cout<<"\nEnter data for "<<infix_to_postfix[i]<<" : ";
			cin>>x;
			data[j]=x+'0';
			//cout<<"\ndata[j] = "<<data[j];
			j++;
		}
		else
		{
			data[j]=infix_to_postfix[i];
			//cout<<"\ndata[j] = "<<data[j];
			j++;
		}
		i++;
	}
	data[j]='\0';
}

float Stack::evaluate()
{
	int i=0;
	int j=0;
	while(data[i]!='\0')
	{
		cout<<"\ndata[i] = "<<data[i];
		if(data[i]=='+'||data[i]=='-'||data[i]=='*'||data[i]=='/')
		{
			int ans=0;
			j--;
			int t1=eval[j];
			j--;
			int t2=eval[j];				
			if(data[i]=='+')
			{
				ans=t2+t1;
				eval[j]=ans;
				j++;
			}
			else if(data[i]=='-')
			{
				ans=t2-t1;
				eval[j]=ans;
				j++;			
			}
			else if(data[i]=='*')
			{
                ans=t2*t1;
				eval[j]=ans;
				j++;
			}
			else if(data[i]=='/')
			{
				ans=t2/t1;
				eval[j]=ans;
				j++;
			}	
		}
		else
		{
			eval[j]=data[i]-'0';
			j++;
		}
		i++;
	}
	j--;
	return (eval[j]);
}


int main()
{
	Stack obj(10);
	obj.input();
	obj.infix_postfix();
	obj.get_data_for_evaluation();
	float ans=obj.evaluate();
	obj.display();
	cout<<"\nValue : "<<ans;
	return 0;
}