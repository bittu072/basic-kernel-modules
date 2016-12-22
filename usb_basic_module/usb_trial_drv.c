#include <linux/init.h>
#include <linux/module.h>
#include <linux/usb.h>
#include <linux/kernel.h>

#include <linux/fs.h> //for the character driver support//

static int pen_probe (struct usb_interface *interface, const struct usb_device_id *id)
	{
	printk(KERN_INFO "[**] BITTU'S (%04x:%04x) PENDRIVE_IS PLUGGED....\n", id->idVendor, id->idProduct);
	return 0;
	}


static struct usb_device_id pen_table[]={
	{USB_DEVICE(0x154b,0xfa0f) }, //this information is obtained from terminal using "lsusb"
	{}	//terminating entry
};
MODULE_DEVICE_TABLE (usb, pen_table);



static void pen_disconnect (struct usb_interface *interface)
	{
	printk(KERN_INFO "[*********] PENDRIVE_IS PLUGGED(removed)....____,__\n");
	}

static struct usb_driver pen_driver = {

	.name = "Bittu_usb driver",
	.id_table= pen_table,
	.probe= pen_probe,
	.disconnect = pen_disconnect,
	
};





static int __init pendrive_init(void)
	{
	int ret=-1;
	printk(KERN_ALERT "[**********]____USB driver init function running ____ %s__hey__inside init function ofbittuusb \n", __FUNCTION__);
	ret=usb_register(&pen_driver);
	printk(KERN_ALERT "registration complete \n\"\"\"BITTTU\"\"\"\"_____NOW VALUE:::::\n");
	
	return ret;
}

static void __exit pendrive_exit(void){
	printk(KERN_ALERT "[**********]bye \n");
	
	//unregister the character device driver//
	usb_deregister(&pen_driver);
	printk(KERN_ALERT "unregistered BITTU \n");

}

module_init(pendrive_init);
module_exit(pendrive_exit);

MODULE_LICENSE("GPL");
