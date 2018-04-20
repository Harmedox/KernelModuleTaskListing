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
	struct task_struct *task, *task_parent;

	printk(KERN_INFO "NAME | STATE | PID ");
	//use the for_each_process macro to traverse through tasks
	for_each_process(task)
	{
		//print the current task information
		printk(KERN_INFO " %s | %ld | %d \n", task->comm,task->state,task->pid);

		//check if task has at least one parent. If yes, print the parents.
		if(task->parent)
		{
			task_parent=task->parent;

			while(task_parent != &init_task)
			{
				//print the parent tasks information starting from the most immediate parent
				printk(KERN_INFO " %s | %ld | %d  \n", task_parent->comm,task_parent->state,task_parent->pid);
				task_parent = task_parent->parent;
			}

			printk("\n");
		}
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
