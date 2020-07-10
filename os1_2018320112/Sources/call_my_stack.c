#include<unistd.h>
#include<stdio.h>

//push system call is 335, pop system call is 336
#define my_stack_push 335
#define my_stack_pop 336

int main(){
  int a;
//push 1 into stack
  a = syscall(my_stack_push,1);
  printf("Push: ");
  printf("%d\n",a);
//push 2 into stack
  a = syscall(my_stack_push,2);
  printf("Push: ");
  printf("%d\n",a);
//push 3 into stack
  a = syscall(my_stack_push,3);
  printf("Push: ");
  printf("%d\n",a);
//pop the most upper integer from stack
  a = syscall(my_stack_pop);
  printf("Pop: ");
  printf("%d\n",a);
//pop the most upper integer from stack
  a = syscall(my_stack_pop);
  printf("Pop: ");
  printf("%d\n",a);
//pop the most upper integer from stack
  a = syscall(my_stack_pop);
  printf("Pop: ");
  printf("%d\n",a);

 return 0;
}
