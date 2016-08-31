#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/err.h>
#include <linux/errno.h>
#include <linux/string.h>
#include <linux/mm.h>
#include <linux/slab.h>
#include <linux/delay.h>
#include <linux/fb.h>
#include <linux/init.h>
#include <linux/dma-mapping.h>
#include <linux/interrupt.h>
#include <linux/platform_device.h>
#include <linux/clk.h>
#include <linux/cpufreq.h>
#include <linux/io.h>

#include <asm/div64.h>

#include <asm/mach/map.h>
#include <mach/regs-lcd.h>
#include <mach/regs-gpio.h>
#include <mach/fb.h>

struct ili9320_info {
	struct device 	*dev;
	u32 			palette_buffer[256];
	u32 			pseudo_pal[16];
};

static int ili9320_probe(struct platform_driver *pdev)
{
	struct fb_info *fbinfo;
	int ret;
	fbinfo = framebuffer_alloc(0 , NULL);

	return ret;
}

static int ili9320_remove(struct platform_device *pdev)
{	
	int ret;
	return ret;
}

static int ili9320_suspend(struct platform_device *dev, pm_message_t state)
{
	int ret ;
	return ret;
}

static struct platform_driver ili9320_driver = {
	.probe		= ili9320_probe,
	.remove		= ili9320_remove,
	.suspend	= ili9320_suspend,
	.driver		= {
		.name	= "ili9320-lcd",
	},
};



int __init ili9320_init(void)
{
	int ret = platform_driver_register(&ili9320_driver);
	return ret;
}

static void __exit ili9320_cleanup(void)
{
	platform_driver_unregister(&ili9320_driver);
}

module_init(ili9320_init);
module_exit(ili9320_cleanup);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("shilin.guo");


