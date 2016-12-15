#include <linux/init.h>
#include <linux/module.h>

void ex03_simple_module_exit(void){
	printk(KERN_ALERT "bye \n");
}


module_exit(ex03_simple_module_exit);

