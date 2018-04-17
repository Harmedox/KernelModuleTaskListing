#include <linux/sched.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

//Descriptive information
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Task Listing");
MODULE_AUTHOR("AAA");

/*
Kernel module program to print out task lists, showing their parent tasks
(name, state, id)
*/
int simple_init(void)
{
	
	
	printk(KERN_INFO "Loading module...\n");

	//declare a task struct to represent the identity of each task
	struct task_struct *task;

	printk(KERN_INFO "NAME | STATE | PID | PPID ");
	//use the for_each_process macro to traverse through tasks
	for_each_process(task)
	{
		//print the current task information
		printk(KERN_INFO " %s | %d | %d | %ld | %d \n", task->comm,task->state,task->pid, task->parent->pid);


		printk("\n");
	}

	printk(KERN_INFO "Module Added!\n");

	return 0;
}

void simple_exit(void)
{
	printk(KERN_INFO "Module removed!\n");
}

module_init(simple_init);
module_exit(simple_exit);
