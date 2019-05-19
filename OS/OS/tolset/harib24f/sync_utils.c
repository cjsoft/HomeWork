#include "bootpack.h"
void avoid_sleep() {
	struct TASK *now_task;
	now_task = task_now();
	now_task->flags = 2;
}

int test_and_set(int *target) {
	io_cli();
	int tmp = *target;
	*target = 0xff;
	io_sti();
	return tmp;
}
void Swap(int *a, int *b) {
	io_cli();
	int tmp = *a;
	*a = *b;
	*b = tmp;
	io_sti();
}
void sem_signal(int *x) {
    io_cli();
    (*x)++;
    io_sti();
}
void sem_wait(int *x) {
	while ((*x) <= 0)
		io_hlt();
	io_cli();
	(*x)--;
	io_sti();
}

struct TASK *create_task(struct MEMMAN *man, void (*f)(void *), void *args) {
    struct TASK *tst = task_alloc();
    tst->cons_stack = memman_alloc_4k(man, 64 * 1024);
    tst->tss.esp = tst->cons_stack + 64 * 1024 - 8;
    tst->tss.eip = (int)f;
    tst->tss.es = 1 * 8;
    tst->tss.cs = 2 * 8;
    tst->tss.ss = 1 * 8;
    tst->tss.ds = 1 * 8;
    tst->tss.fs = 1 * 8;
    tst->tss.gs = 1 * 8;
    *((int *)(tst->tss.esp + 4)) = (int)args;
    return tst;
}