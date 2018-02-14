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

	//use the for_each_process macro to traverse through tasks
	for_each_process(task)
	{
		//print the current task information
		printk(KERN_INFO "name: %s, state: %ld,  pid: [%d]\n", task->comm, task->state, task->pid);

		//print parent processes information
		//if the parent process is the init_task, then don't print as a parent since all processes have it as their parent. the init_task has a pid = 0
		if(task->parent != &init_task)
			printk(KERN_INFO "parent name: %s, parent state: %ld, parent pid: [%d]\n", task->parent->comm, task->parent->state, task->parent->pid);
		if(task->parent->parent != &init_task)
			printk(KERN_INFO "grandparent name: %s, grandparent state: %ld, grandparent pid: [%d] \n",task->parent->parent->comm, task->parent->parent->state,task->parent->parent->pid);
		if(task->parent->parent->parent != &init_task)
			printk(KERN_INFO "great grandparent name: %s, great grandparent state: %ld, great grandparent pid: [%d] \n", task->parent->parent->parent->comm, task->parent->parent->parent->state,task->parent->parent->parent->pid);
		if(task->parent->parent->parent->parent != &init_task)
			printk(KERN_INFO "great great grandparent name: %s, great great grandparent state: %ld, great great grandparent pid: [%d] \n", task->parent->parent->parent->parent->comm, task->parent->parent->parent->parent->state,task->parent->parent->parent->parent->pid);


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
