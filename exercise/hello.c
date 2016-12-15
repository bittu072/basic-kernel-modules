#include <linux/init.h>
#include <linux/module.h>

int ex01_simple_module_init(void)
	{
	printk(KERN_ALERT "helloSdcnskchusocsc_Sdcskchscbsc_Scsdcvjsdcb ____ %s \n", __FUNCTION__);
	return 0;
}

void ex01_simple_module_exit(void){
	printk(KERN_ALERT "bye \n");
}

module_init(ex01_simple_module_init);
module_exit(ex01_simple_module_exit);

