syscalls - kernel functions that can be called from userspace
- open
- read
- write
- close
- execve
- fork
- kill
- mkdir

syscall # is stored in rax register
File Descriptor is stored in rdi
Pointer to buffer is stored in rsi
# of Bytes to read is stored in rdx

Name - sys_read	
rax - 0x00	
rdi - unsigned int fd
rsi - char __user *buf
rdx - size_t count

mov rax, 0x0
mov rdi, 5
mov rsi, buf
mov rdx, 10
syscall
