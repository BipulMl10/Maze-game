 
#include<iostream>
#include<conio.h>
using namespace std;
struct node{
	int i,j;
	struct node *next;
};struct node *start=NULL,*start1=NULL;
void print(struct node *start)
{
	node *ptr=start;
	while(ptr!=NULL)
	{
		cout<<ptr->i<<","<<ptr->j<<" ";
		ptr=ptr->next;
	}
	cout<<endl;
}
struct node *InsertB(struct node *start,int si,int sj)
{
	node *n;
	n=new node;
	n->i=si;
	n->j=sj;
	n->next=start;
	start=n;
	return start;
}
int check(struct node *start,int di,int dj)
{
	int f=0;
	if(start==NULL)
	return 0;
	node *ptr=start;
	while(ptr!=NULL)
	{
		if(ptr->i==di && ptr->j==dj)
		{
			f=1;
			break;
		}
		ptr=ptr->next;
	}
	return f;
}
struct node * InsertE(struct node *start,int si,int sj)
{
  node *n,*ptr;
  n=new node;
  n->i=si;
  n->j=sj;
  n->next=NULL;	
  if(start==NULL)
  {
  	start=n;
  }
  else{
  	ptr=start;
  	while(ptr->next!=NULL)
  	{
  		ptr=ptr->next;
	  }
	  ptr->next=n;
}
return start;
}
int possiableq(char a[][100],int r,int c,int di,int dj)
{
  int f=0,count=0,max=r*c,p,q;
  while(1)
   {
   	if(count>max)
   	{
   		f=0;
   		break;
	   }
   	if(check(start,di,dj)!=1)
   	{
   		p=start->i;
   		q=start->j;
   		a[p][q]='*';
   		if(start->next==NULL)
		start=NULL;
		else
		start=start->next;
   		if(a[p][q+1]!='|' && a[p][q+1]!='#' && a[p][q+1]!='*' && (q+1)<c )
   		{
   			a[p][q+1]='#';
   			start=InsertB(start,p,q+1);
		}
		if(a[p][q-1]!='|' && a[p][q-11]!='#' && a[p][q-1]!='*' && (q-1)>=0 )
   		{
   			a[p][q-1]='#';
   				start=InsertB(start,p,q-1);
		}
		if(a[p+1][q]!='|' && a[p+1][q+1]!='#' && a[p+1][q+1]!='*' && (p+1)<r)
   		{
   			a[p+1][q]='#';
   				start=InsertB(start,p+1,q);
		}
		if(a[p-1][q]!='|' && a[p-1][q]!='#' && a[p-1][q]!='*' && (p-1)>=0 )
   		{
   			a[p-1][q]='#';
   				start=InsertB(start,p-1,q);
		}
	}
	else
	{
		f=1;
		break;
	}
	count++;
   }
   return f;
}
int possiablee(char a[][100],int r,int c,int di,int dj)
{
	int f=0,count=0,max=r*c,p,q;
	while(1)
   {
   		if(count>max)
   	{
   		f=0;
   		break;
	   }
   	if(check(start,di,dj)!=1)
   	{
   		p=start->i;
   		q=start->j;
   		a[p][q]='*';
   		if(a[p][q+1]!='|' && a[p][q+1]!='#' && a[p][q+1]!='*' && (q+1)<c )
   		{
   			a[p][q+1]='#';
   			start=InsertE(start,p,q+1);
		}
		if(a[p][q-1]!='|' && a[p][q-11]!='#' && a[p][q-1]!='*' && (q-1)>=0 )
   		{
   			a[p][q-1]='#';
   				start=InsertE(start,p,q-1);
		}
		if(a[p+1][q]!='|' && a[p+1][q+1]!='#' && a[p+1][q+1]!='*' && (p+1)<r)
   		{
   			a[p+1][q]='#';
   				start=InsertE(start,p+1,q);
		}
		if(a[p-1][q]!='|' && a[p-1][q]!='#' && a[p-1][q]!='*' && (p-1)>=0 )
   		{
   			a[p-1][q]='#';
   				start=InsertE(start,p-1,q);
		}
		start=start->next;
	}
	else
	{
		f=1;
		break;
	}
		count++;
   }
   return f;
}
void printc(char b[][100],int r,int c)
{
	for(int i=0;i<r;i++)
            	{
	            	for(int j=0;j<c;j++)
	        	{
	         		cout<<b[i][j]<<"     ";
	        	}
	        	cout<<endl<<endl<<endl<<endl;
            	}
            	
}
struct node* newstart(struct node* start1,char b[][100],int p,int q,int si,int sj){
	int count=0;
	while(count<3 && start1!=NULL){
		b[start1->i][start1->j]='_';
		start1=start1->next;
		count++;
	}
	if(start1==NULL){
		start1=NULL;
			start1=InsertB(start1,si,sj);
	}
	return start1;
}
void game(char a[][100],char b[][100],int r,int c,int di,int dj,int p,int q,int si,int sj)
{
	int life=3;
	int point=0;
	char d;
		b[p][q]='@';
	do{
		if(p==di && q==dj)
		{
			system("cls");
			a[p][q]='O';
			point=point+2;
			printc(b,r,c);
			break;
		}
	   cin>>d;
	   system("cls");
		if(d=='w')
		{
			if((p-1)<0 || a[p-1][q]=='|')
			{
				if(life==0){
					cout<<"Game Over\n";
					break;
				}
				else
				{
					cout<<"life lost\n";
					life--;
					start1=newstart(start1,b,p,q,si,sj);
					p=start1->i;
					q=start1->j;
					point=0;
				}
				printc(b,r,c);
			}
			else if(a[p-1][q]=='#')
			{
				p--;
				start1=InsertB(start1,p,q);
				cout<<"points gets decrease by 4 points\n";
				point=point-4;
				printc(b,r,c);
			}
			else if(a[p-1][q]=='*')
			{
				p--;
				start1=InsertB(start1,p,q);
					b[p][q]='@';
				cout<<"HURRAY correct step!(- -)\n";
				point=point+2;
				printc(b,r,c);
			}
		}
		else if(d=='a')
		{
		if((q-1)<0 || a[p][q-1]=='|')
			{
				if(life==0){
					cout<<"Game Over\n";
					break;
				}
				else
				{
					cout<<"life lost\n";
					life--;
					start1=newstart(start1,b,p,q,si,sj);
					p=start1->i;
					q=start1->j;
					point=0;
			}
			printc(b,r,c);
		}
			else if(a[p][q-1]=='#')
			{
				q--;
				start1=InsertB(start1,p,q);
				cout<<"points gets decrease by 4 points\n";
				point=point-4;
				printc(b,r,c);
			}
			else if(a[p][q-1]=='*')
			{
				q--;
				start1=InsertB(start1,p,q);
					b[p][q]='@';
				cout<<"HURRAY correct step!(- -)\n";
				point=point+2;
				printc(b,r,c);
			}	
		}
		else if(d=='s')
		{	
		if((p+1)>=r || a[p+1][q]=='|'){
		if(life==0){
					cout<<"Game Over\n";
					break;
				}
				else
				{
					cout<<"life lost\n";
					life--;
					start1=newstart(start1,b,p,q,si,sj);
					p=start1->i;
					q=start1->j;
					point=0;
				}
				printc(b,r,c);
		}
			else if(a[p+1][q]=='#')
			{
				p++;
				start1=InsertB(start1,p,q);
				cout<<"points gets decrease by 4 points\n";
				point=point-4;
				printc(b,r,c);
			}
			else if(a[p+1][q]=='*')
			{
				p++;
				start1=InsertB(start1,p,q);
					b[p][q]='@';
				cout<<"HURRAY correct step!(- -)\n";
				point=point+2;
				printc(b,r,c);
			}
		}
		else if(d=='d')
		{
	               	if((q+1)>=c || a[p][q+1]=='|')
           {
					if(life==0){
					cout<<"Game Over\n";
					break;
				}
				else
				{
					cout<<"life lost\n";
					life--;
				start1=newstart(start1,b,p,q,si,sj);
					p=start1->i;
					q=start1->j;
					point=0;
				}
				printc(b,r,c);
			}
			else if(a[p][q+1]=='#')
			{
				q++;
				start1=InsertB(start1,p,q);
				cout<<"points gets decrease by 4 points\n";
				point=point-4;
				printc(b,r,c);
			}
			else if(a[p][q+1]=='*')
			{
				q++;
				start1=InsertB(start1,p,q);
					b[p][q]='@';
				cout<<"HURRAY correct step!(- -)\n";
				point=point+2;
				printc(b,r,c);
			}
		}
	}while(d=='w' || d=='a' || d=='s' || d=='d');
	cout<<"YOU SCORE "<<point<<" POINTS\n";
}
int main()

{
	char a[100][100],b[100][100],a1[100][100],b1[100][100];
	char c1;
	int r,c,i,j,si,sj,di,dj,p,q,max=-1,count=0;
	cin>>r>>c;
	max=r*c;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			a[i][j]='_';
		}
	}
	do{
		cin>>i>>j;
		a[i][j]='|';
		cin>>c1;
	}while(c1=='y');
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			b[i][j]=a[i][j];
			a1[i][j]=a[i][j];
			b1[i][j]=a[i][j];
		}
	}
	cout<<"ENTER THE START Co-ordinates\n";
	cin>>si>>sj;
	start=InsertE(start,si,sj);
	cout<<"enter destination co-.ordinates\n";
	cin>>di>>dj;
	p=si;
	q=sj;
	system("cls");
	cout<<"STAZE 1\nBY STACK\n";
	{
			b[p][q]='@';
		printc(b,r,c);
		if(possiableq(a,r,c,di,dj))
		{
		game(a,b,r,c,di,dj,p,q,si,sj);
		}
	}
cout<<"DO YOU WANTS TO CONTIONUE\n";
char ch;
cin>>ch;
system("cls");
if(ch=='y')
{
	cout<<"queue\n";
	b1[p][q]='@';
	printc(b1,r,c);
	start=NULL;
		start=InsertE(start,si,sj);
		if(possiablee(a1,r,c,di,dj))
		{
			start1=NULL;
			game(a1,b1,r,c,di,dj,p,q,si,sj);	
		}
}
}
