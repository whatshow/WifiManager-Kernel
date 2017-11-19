/*** linux内核模块 ***/
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kernel.h>

/*** 导入linux网络包 ***/
#include <skbuff.h>
#include <linux/ip.h>

/*** 导入netfilter框架 ***/
#include <netinet/in.h>
#include <linux/netfilter.h>
#include <linux/netfilter_ipv4.h>

/*** 文件操作 ***/
#include <sys/stat.h>
#include <sys/types.h>

/* hello_init ---- 初始化函数，当模块装载时被调用，如果成功装载返回0 否则返回非0值 */
static int __init hello_init(void)
{
    printk("I bear a charmed life.\n");
    return 0;
}
/* hello_exit ---- 退出函数，当模块卸载时被调用 */
static int __exit hello_exit(void)
{
    printk("Out, out, brief candle\n");
    return 0;
}
module_init(hello_init);
module_exit(hello_exit);
MODULE_LICENSE("GPL");
