#include<unistd.h>
#include<stdio.h>

#define my_stack_push 335
#define my_stack_pop 336

int main(){
//push 1, 1, 2 as overlap, to check if stack inform overlap and unaccept overlap integer
  int a;
//push 1
  a = syscall(my_stack_push,1);
  printf("Push: ");
  printf("%d\n", a);
//push 1 (overlap)
  a = syscall(my_stack_push,1);
  printf("Push: ");
  printf("%d\n", a);
//push 2
  a = syscall(my_stack_push,2);
  printf("Push: ");
  printf("%d\n", a);
//pop top of the stack
  a = syscall(my_stack_pop);
  printf("Pop: ");
  printf("%d\n", a);
//pop top of the stack
  a = syscall(my_stack_pop);
  printf("Pop: ");
  printf("%d\n", a);
}
