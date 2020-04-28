#include <linux/module.h> 
#include <linux/kernel.h>
#include <linux/proc_fs.h> 
#include <linux/string.h>
#include <linux/vmalloc.h> 
#include <asm/uaccess.h>

#define MAX_LEN 4096
int read_info(char *page, char **start, off_t off, int count, int *eof, 
             void *data);
ssize_t write_info(struct file *filp, const char __user *buff, unsigned 
             long len, void *data);

static struct proc_dir_entry *proc_entry;
static char *info;
static int write_index; 
static int read_index;

int init_module_(void) {
	printk(KERN_EMERG "init");
    int ret = 0;
    // allocated memory space for the proc entry
    info = (char *)vmalloc(MAX_LEN); 
    memset(info, 0, MAX_LEN);
    
    proc_entry = create_proc_entry("TheEntry5", 0777, NULL);
    
    write_index = 0;
    read_index = 0;
    
    //register the write and read callback functions 
    proc_entry->read_proc = read_info; 
    proc_entry->write_proc = write_info;
    printk(KERN_INFO "test_proc created .\n");
    return ret; 
}

void cleanup_module_(void){
    	remove_proc_entry("TheEntry5", NULL);
	printk(KERN_INFO "TheEntry5 removed");
	vfree(info);	
}

ssize_t write_info(struct file *filp, const char __user *buff,  
    unsigned long len, void * data){
	//printk(KERN_EMERG "write");

	int cap = (MAX_LEN - write_index) + 1;
	if (len > cap) {
		printk (KERN_INFO "ERROR: Not enough space to write");
		return -1;	
	}
	if (copy_from_user(&info[write_index],buff,len))
		return -EFAULT;

	write_index += len;
	info[write_index-1] = 0;
	return len; 
}

int read_info(char *buff, char **start, off_t offset, int count, 
    int *eof, void *data){
    	unsigned long len = 0;
	if (offset > 0){
		*eof = 1;
		return 0;
	}
	if (read_index >= write_index)
		read_index = 0;

	len = sprintf(buff, "%s\n", &info[read_index]);
	read_index += len;
	
	
    	return len; 
}

module_init(init_module_);
module_exit(cleanup_module_);

MODULE_LICENSE("GPL");


