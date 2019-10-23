#include <stdio.h>

struct process
{
  int pid;
  struct process *link[5];
};
typedef struct process *process;

process root1,root2,root3;

process forkpro(int a,int b);
process link(process root,process x,int b);
void display(process root);
void execution(process root,int c_num);
void termination(process root,int c_num);

process forkpro(int a,int b)
{
 int c;
 process x;
 x=(process)malloc(sizeof(struct process)); 
 c=a*10+b;
 x->pid=c; 
 return x;
}

process link(process root,process x,int b)
{
 root->link[b]=x;
 return root;
}

void display(process root)
{
 int i=1;
 process x;
 x=root->link[i];
 printf("The process with process id %d has following child processes\n",root->pid);
 while(x!=NULL)
 {
  printf("%d  ",x->pid);
  i++;
  x=root->link[i];
 }
 printf("\n");
}

void execution(process root,int c_num)
{
 int i=1,id;
 for(i=1;i<=c_num;i++)
 {
 id=root->link[i]->pid;
 if(id<0)
 {
  printf("FORK FAILED\n");
 }
 else if(id==0)
 {
  printf("NULL\n");
 }
 else
 {
 printf("CHILD COMPLETE\n");
 }
 root->link[i]->pid=0;
 }
}

void termination(process root,int c_num)
{
 int i,id,counter=0;
 for(i=1;i<=c_num;i++)
 {
  if(root->link[i]->pid==0)
  {
   counter++;
  }
 }
 if(counter==c_num)
 {
  printf("Process with pid %d is terminated\n",root->pid);
  root->pid=0;
 }
 else
 {
  printf("Process with pid %d is not terminated\n",root->pid);
 }
}
int main()
{
 process temp;
 int id,r1=0,r2=0,r3=0,c=1;
 root1=forkpro(1,0);
 root2=forkpro(2,0);
 root3=forkpro(3,0);
 printf("Three process are present with process id's 10 ,20 ,30\n");
 while(c==1)
{
 //printf("\nEnter the process id for which a child process has to be created: \n");
 scanf("%d",&id);
 if(id==10||id==20||id==30)
 {
 printf("The entered id is %d\n",id);
 if(id==10)
 {
  r1++;
  temp=forkpro(id,r1);
  root1=link(root1,temp,r1);
 }
 else if(id==20)
 {
  r2++;
  temp=forkpro(id,r2);
  root2=link(root2,temp,r2);
 }
 else if(id==30)
 {
  r3++;
  temp=forkpro(id,r3);
  root3=link(root3,temp,r3);
 }
}
 else
 {
 printf("process with entered id is not present\n");
  break;
 }
 printf("Enter 1 to continue 0 to exit\n");
 scanf("%d",&c);
 }
printf("\n-----------------------------\n");
printf("PROCESS CREATION\n");
display(root1);
display(root2);
display(root3);
printf("\n-----------------------------\n");
printf("PROCESS EXECUTION\n");
printf("PROCESS 1\n");
execution(root1,r1);
printf("\nPROCESS 2\n");
execution(root2,r2);
printf("\nPROCESS 3\n");
execution(root3,r3);
printf("\n-----------------------------\n");
printf("PROCESS TERMINATION\n");
termination(root1,r1);
termination(root2,r2);
termination(root3,r3);
return 0;
}
