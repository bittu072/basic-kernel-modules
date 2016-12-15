#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>

int count=1;

module_param(count, int, 0644);

int ex06_simple_module_init(void)
	{
	int index=0;
	
	printk(KERN_ALERT "helloSdcnskchusocsc_Sdcskchscbsc_Scsdcvjsdcb ____ %s \n", __FUNCTION__);
	
	for(index = 0; index < count; index++){
		printk(KERN_ALERT "hello world: Index = %d\n", index);	

	}
	return 0;
}

void ex06_simple_module_exit(void){

	int index=0;
	printk(KERN_ALERT "bye \n");
	for(index = 0; index < count; index++){
		printk(KERN_ALERT "hello world: Index = %d\n", index);	

	}
}

module_init(ex06_simple_module_init);
module_exit(ex06_simple_module_exit);

