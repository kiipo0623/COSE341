#include<linux/syscalls.h>
#include<linux/kernel.h>
#include<linux/linkage.h>

#define MAXSIZE 500

int stack[MAXSIZE];
int top=-1;

SYSCALL_DEFINE1(oslab_push,int,a){
//i for for loop
int i;

//to check if stack is full
if(top>=MAXSIZE-1){
  printk("Stack is full\n");
  return 0;
}

//to check if new value is already in stack
for(i=top;i>-1;i--){
  if(a==stack[i]){
    printk(KERN_INFO "Overlap value\n");
    return a;  
   }   
 }

//if no overlap in stack, push in stack of top
 stack[++top]=a;



printk(KERN_INFO "[System call] Oslab_push() : %d",stack[top]);
printk("------Stack Top---------\n");
//to show stack from top to bottom
for(i=top;i>-1;i--){
    printk("%d\n",stack[i]);
}

printk("-------Stack Bottom-------\n");

return stack[top];
}


SYSCALL_DEFINE0(oslab_pop){
int i;
//to check if stack is empty
if(top<0){
  printk("Stack is empty\n");
}

printk(KERN_INFO "[System call] Oslab_pop() : %d",stack[top]);
printk("--------Stack Top-------------\n");
//to show stack from top to bottom
for(i=top-1;i>-1;i--){
    printk("%d\n",stack[i]);
}

printk("----------Stack Bottom------------\n");
//return top of the stack for pop
return stack[top--];
}

