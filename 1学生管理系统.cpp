#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

struct Node{
	char name[30];
	int number;
	int chengji;
	struct Node *next;
};
typedef struct Node *node;
int count=0;
node creat(){
	node phead,pend,pnew;
	phead=(node)malloc(sizeof(struct Node));
	phead->next=NULL;
	pend=phead;
	printf("输入要录入学生的个数\n");
	scanf("%d",&phead->number);
	printf("接下来请依次输入%d个学生信息\n",phead->number);
	printf("请输入学生以下信息:\n");
	for(int i=1;i<=phead->number;i++){
		pnew=(node)malloc(sizeof(struct Node));
		printf("\t姓名:");
		scanf("%s",pnew->name);
		printf("\t学号:");
		scanf("%d",&pnew->number);
		printf("\t成绩:");
		scanf("%d",&pnew->chengji);
		printf("    ________________\n");		
		pnew->next=NULL;
		pend->next=pnew;
		pend=pnew;
		count++;
	} 
	return phead;
}
node print(node phead){
	node temp=NULL;
	temp=phead->next;
	int k=1;
	printf("一共有%d个学生\n",count);
	for(int i=1;i<=count;i++){ 
	printf("第%d个学生\n",k++);
	printf("姓名:%s\n",temp->name);
	printf("学号:%d\n",temp->number);
	printf("成绩:%d\n",temp->chengji);
	printf("________________\n");
	temp=temp->next;
	} 
}
node insert(node phead){
	node pre,pnew;
	pre=phead;
	int k;
	printf("输入你要插入到第几个的序号\n");
	scanf("%d",&k);
	for(int i=0;i<k;i++)
	pre=pre->next;
	pnew=(node)malloc(sizeof(struct Node));
	pnew->next=NULL;
	printf("请输入该学生信息:\n");
		printf("姓名:");
		scanf("%s",pnew->name);
		printf("学号:");
		scanf("%d",&pnew->number);
		printf("成绩:");
		scanf("%d",&pnew->chengji);
	count++;
	pnew->next=pre->next;
	pre->next=pnew;
	return phead;
}
node find(node phead){
	node temp=phead->next;
	int number;
	printf("请输入要查找的学生的学号:\n");
	scanf("%d",&number);
	while(temp->number!=number&&temp)
	temp=temp->next;
	if(temp==NULL)
	printf("你查找的学生不在，请从新输入!\n");
	else
	{printf("这个学生的信息如下\n");
	printf("姓名:%s\n",temp->name);
	printf("学号:%d\n",temp->number);
	printf("成绩:%d\n",temp->chengji);
	printf("________________\n");
	}
}
node delet(node phead){
	node pre,pd;
	int l;
	pre=phead;
	printf("想删第几个？说:\n");
	scanf("%d",&l);
	for(int i=1;i<l;i++)
	pre=pre->next;
	pd=pre->next;
	pre->next=pd->next;
	free(pd);
	count--;
	return phead;
}
int menu1(){
	int choice; 
	printf("\n\n\n\t\t\t\t  ------------\n");
	printf("\t\t\t\t丨学生管理系统丨\n");
	printf("\t\t\t\t  ------------\n");
	printf("\t\t丨\t\t1.学生信息录入\t  \t丨\n");
	printf("\t\t丨\t\t2.学生信息插入\t  \t丨\n");
	printf("\t\t丨\t\t3.学生信息删除\t  \t丨\n");
	printf("\t\t丨\t\t4.学生信息查询\t  \t丨\n");
	printf("\t\t丨\t\t0.退出        \t  \t丨\n");
	scanf("%d",&choice);
	return choice;
}
int menu2(){
	printf("\n\n\n\t\t\t\t  ------------\n");
	printf("\t\t\t\t丨学生管理系统丨\n");
	printf("\t\t\t\t  ------------\n");
	
} 
int main(){
	int choice=1;
	node phead;
	while(choice){
	choice=menu1();
	switch(choice){
		case 1:phead=creat();print(phead);system("pause");break;
		case 2:phead=insert(phead);print(phead);system("pause");break;
		case 3:phead=delet(phead);print(phead);system("pause");break;
		case 4:find(phead);system("pause");break;
		case 0:break;
	}
	} 
}
