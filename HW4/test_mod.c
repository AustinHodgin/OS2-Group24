#include <linux/module.h>
#include <linux/slab.h>
#include <linux/random.h>

/*
 * Testing module for slob module.
 */

static int __init malloc_init(void){
    void *tempa,*tempb;
    int i = 0,randa,randb;
    printk("Test: running");
    for(i = 0; i < 999999;i++){
        get_random_bytes(&randa, sizeof(randa));
        get_random_bytes(&randb, sizeof(randa));

        tempa = kmalloc(randa, GFP_KERNEL);
        kfree(tempa);

        tempb = kmalloc(randb, GFP_KERNEL);
        kfree(tempb);
    }

    return 0;
}

static void __exit malloc_exit(void){


}

module_init(malloc_init);
module_exit(malloc_exit);

MODULE_AUTHOR("Joshua Novak, Austin Hodgin");
MODULE_LICENSE("GPL");
