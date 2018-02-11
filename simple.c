// insert libraries
#include <linux/sched.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>


//software license information
MODULE_LICENSE("GPL");
//module descripton
MODULE_DESCRIPTION("Task Listing - Project");
//Module Author
MODULE_AUTHOR("AAA");

//define module entry point
int simple_init(void)
{
	struct task_struct *task;

	printk(KERN_INFO "loading module...\n");

	for_each_process(task)
	{
		printk(KERN_INFO "pid: %d \t pname: %s \t state %ld\n", task->pid,task->comm, task->state);
	}

	printk(KERN_INFO "Module Added\n");

	return 0;
}

//define module exit point
void simple_exit(void)
{	
	printk(KERN_INFO "Module removed \n");
}

//register module entry and exit points with kernel
module_init(simple_init);
module_exit(simple_exit);


