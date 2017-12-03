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

/* 钩子 */
//注册的钩子
static struct nf_hook_ops nfhoForbidDefaultIP;
//钩子回调函数
unsigned int hf_ForbidDefaultIP(unsigned int hooknum, struct sk_buff *skb, const struct net_device *in, const struct net_device *out, int (*okfn)(struct sk_buff *))
{
    printk(KERN_INFO "packet dropped\n");   //log to var/log/messages
    return NF_DROP;                         //drops the packet
}


/* 定义初始化函数 + 退出函数 */
/**
 * wmk_init 初始化函数，当模块装载时被调用，如果成功装载返回0 否则返回非0值
 */
static int __init wmk_init(void)
{
    //printk("I bear a charmed life.\n");

    //注册禁止默认IP的钩子
    nfhoForbidDefaultIP.hook = hf_ForbidDefaultIP;              //function to call when conditions below met
    nfhoForbidDefaultIP.hooknum = NF_INET_PRE_ROUTING;          //called right after packet recieved, first hook in Netfilter
    nfhoForbidDefaultIP.pf = PF_INET;                           //IPV4 packets
    nfhoForbidDefaultIP.priority = NF_IP_PRI_FIRST;             //set to highest priority over all other hook functions
    nf_register_hook(&nfhoForbidDefaultIP);                     //register hook
    return 0;
}
/**
 * wmk_exit 退出函数，当模块卸载时被调用
 */
static void __exit wmk_exit(void)
{
    //取消禁止默认IP的钩子
    nf_unregister_hook(&nfhoForbidDefaultIP);
    //printk("Out, out, brief candle\n");
}

//注册加载启动函数
module_init(wmk_init);
//注册关闭回调函数
module_exit(wmk_exit);
//定义支持协议
MODULE_LICENSE("MIT");