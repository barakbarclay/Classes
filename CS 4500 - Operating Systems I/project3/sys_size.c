#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/module.h>
#include <linux/pid.h>
#include <linux/mm_types.h>
#include <linux/mm.h>
#include <linux/fs.h>
#include <asm/page.h>
#include <asm/mman.h>

asmlinkage int sys_size (int targetPID){

	struct task_struct *task;
	struct pid *pid_struct;
	struct mm_struct *curr_mem;
	struct vm_area_struct *all_vmas;
	struct vm_area_struct curr_vma;

	int total_vmas;
	int count = 0;
	int total_size = 0;

	pid_struct = find_get_pid(targetPID);
	task = pid_task(pid_struct, PIDTYPE_PID);
	curr_mem = task->active_mm;
	all_vmas = curr_mem->mmap;
	total_vmas = curr_mem->map_count; //Gets # of VMAs
	curr_vma = *all_vmas; //Initializes curr_vma to first address in mmap
	
	printk(KERN_EMERG "Print Size of Virtual Address");

	while(count < total_vmas){
		total_size += curr_vma.vm_end - curr_vma.vm_start;//Adds current VMA size to total size
		if (count != total_vmas - 1)//Deals with out of bounds error
			curr_vma = *(curr_vma.vm_next);//Gets next VMA
		count++;
	}
	total_size /= 1024;//Convert to KB
	printk(KERN_EMERG "Program Name: %s \nVirtual Address Size: %iK", task->comm, total_size);
	printk(KERN_EMERG "");//Added b/c last kern_emerg doesn't print
	return 0;
}
