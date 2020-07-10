# COSE341
korea university operating system homework

os1_

Unbuntu 18.04.02 (64bit), Linux kernel 4.20.11 (가상머신 환경)

1. 목적
이번 과제의 목적은 일반 배포판 리눅스에 새로운 Kernel을 컴파일하고 수정해서 새로운 System Call을 추가하
는 것이다. System Call은 Kernel이 시스템이나 하드웨어에 특권이 있어야만 하는 동작들을 지정해둔 함수로써
User-Space에서 Kernel-Space로 전환하기 위해서 특별히 지정된 Trap Instruction을 거쳐야 한다. 본 과제에서는
Kernel을 직접 컴파일하고, 이후 기존의 Kernel에 새로운 System Call을 추가한 후에 이를 호출할 수 있는 UserApplication까지를 구현하도록 한다.
새로 추가한 system call은 내부적으로 Stack 자료구조를 갖도록 한다. 그리고 이 Stack에 integer값을 Push하
거나 Pop하는 역할을 수행하도록 작성한다. 단, 중복된 integer값을 저장 할 수 없다. 그 밖에 정해진 Stack의 구
현 방법은 없으며 자유롭게 구현할 수 있다. 기본적인 Push와 Pop가 가능하면 된다. Stack에 저장 할 수 있는
entry의 개수 또한 고정적으로 하여도 무관하다.

2. 수정
A. (linux)/arch/x86/entry/syscalls/syscall_64.tbl (64비트 머신)
→ 시스템 콜 함수들의 이름에 대한 심볼 정보를 모아 놓은 파일
B. (kernel)/include/linux/syscalls.h
→ 추가한 시스템 콜 함수들의 prototype 정의
C. (kernel)/my_stack_syscall.c
→ 새로 추가할 시스템 콜의 소스
D. (kernel)/Makefile
→ my_stack_syscall.o 오브젝트 추가


os2_

1. 목적
본 과제는 리눅스의 프로세스 및 프로세스 스케줄러를 이해하기 위해, 프로세스의 CPU 점유 시간 (burst)을 살
펴본다. 리눅스 프로세스 스케줄러는 각 프로세스에 CPU를 점유하는 프로세스 점유 시간을 할당하는데, 점유 시
간의 할당 방식은 프로세스의 종류, 컴퓨터의 종류, 스케줄러의 종류에 따라 그 특성이 다르게 나타난다. 이에
본 과제에서는 실제 리눅스 운영체제에서 스케줄러가 프로세스에 어떻게 CPU 점유 시간을 할당하는지, 그리고
현대의 프로세스와 시스템에서 프로세스의 CPU 점유 시간이 어떠한 분포를 나타내는 지 실제로 조사해본다. 

2. 과제 목표
A. CPU burst 측정을 위한 리눅스 스케줄러 수정
 리눅스 기본 스케줄러에서 할당되는 CPU burst 값을 측정할 수 있도록 스케줄러를 수정한다.
 CPU burst 값의 측정 방식(e.g., printk, proc 파일 시스템 등)은 어떠한 방식을 사용해도 무방하다.
 CPU burst 값은 burst값이 1,000회 바뀔 때 1회 기록한다.
B. CPU burst 측정 실험 수행
 30분 동안의 전체 프로세스의 CPU burst 측정
i. 단, 기본 커널 데몬 및 쓰레드 외에 CPU 사이클을 소모하는 프로세스를 실행하고
분석 시 구동한 프로세스의 대한 설명을 쓴다.
ii. 프로세스별 burst값을 구분하여 분석하지 않아도 무방하다.
C. 프로세스 및 스케줄러에 대한 이해
 2.B에서 실험한 항목에 대해 Figure 1과 같은 형태의 그래프를 작성한다.
 그래프를 통해 프로세스 및 스케줄러의 동작에 대해 이해하고 분석하여, 보고서를 작성한다.
