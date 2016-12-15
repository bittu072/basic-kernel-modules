#include <linux/init.h>
#include <linux/module.h>

int ex05_simple_module_function(void){
	printk(KERN_ALERT "EXAMPLE 5 OF EXPORTING FROM ONE MODULE TO OTHER MODULES %s \n", __FUNCTION__);
	return 0;
}
EXPORT_SYMBOL(ex05_simple_module_function);

int ex05_simple_module_init(void)
	{
	printk(KERN_ALERT "helloSdcnskchusocsc_Sdcskchscbsc_Scsdcvjsdcb ____ %s \n", __FUNCTION__);
	return 0;
}

void ex05_simple_module_exit(void){
	printk(KERN_ALERT "bye \n");
}

module_init(ex05_simple_module_init);
module_exit(ex05_simple_module_exit);

