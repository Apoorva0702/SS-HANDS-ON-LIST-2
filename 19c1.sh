strace -o mknod_trace.txt mknod myfifo3 p

/*

execve("/usr/bin/mknod", ["mknod", "myfifo3", "p"], 0x7ffff46b7220 /* 47 vars */) = 0
brk(NULL)                               = 0x61967bd3f000
mmap(NULL, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7dbbb5d9f000
access("/etc/ld.so.preload", R_OK)      = -1 ENOENT (No such file or directory)
openat(AT_FDCWD, "/etc/ld.so.cache", O_RDONLY|O_CLOEXEC) = 3
fstat(3, {st_mode=S_IFREG|0644, st_size=59099, ...}) = 0
mmap(NULL, 59099, PROT_READ, MAP_PRIVATE, 3, 0) = 0x7dbbb5d90000
close(3)                                = 0
openat(AT_FDCWD, "/lib/x86_64-linux-gnu/libselinux.so.1", O_RDONLY|O_CLOEXEC) = 3
read(3, "\177ELF\2\1\1\0\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0\0\0\0\0\0\0\0\0"..., 832) = 832
fstat(3, {st_mode=S_IFREG|0644, st_size=174472, ...}) = 0
mmap(NULL, 181960, PROT_READ, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x7dbbb5d63000
mmap(0x7dbbb5d69000, 118784, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x6000) = 0x7dbbb5d69000
mmap(0x7dbbb5d86000, 24576, PROT_READ, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x23000) = 0x7dbbb5d86000
mmap(0x7dbbb5d8c000, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x29000) = 0x7dbbb5d8c000
mmap(0x7dbbb5d8e000, 5832, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0) = 0x7dbbb5d8e000
close(3)                                = 0
openat(AT_FDCWD, "/lib/x86_64-linux-gnu/libc.so.6", O_RDONLY|O_CLOEXEC) = 3
read(3, "\177ELF\2\1\1\3\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0\220\243\2\0\0\0\0\0"..., 832) = 832
pread64(3, "\6\0\0\0\4\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0"..., 784, 64) = 784
fstat(3, {st_mode=S_IFREG|0755, st_size=2125328, ...}) = 0
pread64(3, "\6\0\0\0\4\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0"..., 784, 64) = 784
mmap(NULL, 2170256, PROT_READ, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x7dbbb5a00000
mmap(0x7dbbb5a28000, 1605632, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x28000) = 0x7dbbb5a28000
mmap(0x7dbbb5bb0000, 323584, PROT_READ, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x1b0000) = 0x7dbbb5bb0000
mmap(0x7dbbb5bff000, 24576, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x1fe000) = 0x7dbbb5bff000
mmap(0x7dbbb5c05000, 52624, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0) = 0x7dbbb5c05000
close(3)                                = 0
openat(AT_FDCWD, "/lib/x86_64-linux-gnu/libpcre2-8.so.0", O_RDONLY|O_CLOEXEC) = 3
read(3, "\177ELF\2\1\1\0\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0\0\0\0\0\0\0\0\0"..., 832) = 832
fstat(3, {st_mode=S_IFREG|0644, st_size=625344, ...}) = 0
mmap(NULL, 627472, PROT_READ, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x7dbbb5cc9000
mmap(0x7dbbb5ccb000, 450560, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x2000) = 0x7dbbb5ccb000
mmap(0x7dbbb5d39000, 163840, PROT_READ, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x70000) = 0x7dbbb5d39000
mmap(0x7dbbb5d61000, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x97000) = 0x7dbbb5d61000
close(3)                                = 0
mmap(NULL, 12288, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7dbbb5cc6000
arch_prctl(ARCH_SET_FS, 0x7dbbb5cc6800) = 0
set_tid_address(0x7dbbb5cc6ad0)         = 5959
set_robust_list(0x7dbbb5cc6ae0, 24)     = 0
rseq(0x7dbbb5cc7120, 0x20, 0, 0x53053053) = 0
mprotect(0x7dbbb5bff000, 16384, PROT_READ) = 0
mprotect(0x7dbbb5d61000, 4096, PROT_READ) = 0
mprotect(0x7dbbb5d8c000, 4096, PROT_READ) = 0
mprotect(0x619675711000, 4096, PROT_READ) = 0
mprotect(0x7dbbb5ddd000, 8192, PROT_READ) = 0
prlimit64(0, RLIMIT_STACK, NULL, {rlim_cur=8192*1024, rlim_max=RLIM64_INFINITY}) = 0
munmap(0x7dbbb5d90000, 59099)           = 0
statfs("/sys/fs/selinux", 0x7ffce5517710) = -1 ENOENT (No such file or directory)
statfs("/selinux", 0x7ffce5517710)      = -1 ENOENT (No such file or directory)
getrandom("\x85\x65\x67\x55\x3c\xe7\x99\x5e", 8, GRND_NONBLOCK) = 8
brk(NULL)                               = 0x61967bd3f000
brk(0x61967bd60000)                     = 0x61967bd60000
openat(AT_FDCWD, "/proc/filesystems", O_RDONLY|O_CLOEXEC) = 3
fstat(3, {st_mode=S_IFREG|0444, st_size=0, ...}) = 0
read(3, "nodev\tsysfs\nnodev\ttmpfs\nnodev\tbd"..., 1024) = 406
read(3, "", 1024)                       = 0
close(3)                                = 0
access("/etc/selinux/config", F_OK)     = -1 ENOENT (No such file or directory)
openat(AT_FDCWD, "/usr/lib/locale/locale-archive", O_RDONLY|O_CLOEXEC) = 3
fstat(3, {st_mode=S_IFREG|0644, st_size=14596880, ...}) = 0
mmap(NULL, 14596880, PROT_READ, MAP_PRIVATE, 3, 0) = 0x7dbbb4c00000
close(3)                                = 0
mknodat(AT_FDCWD, "myfifo3", S_IFIFO|0666) = 0
close(1)                                = 0
close(2)                                = 0
exit_group(0)                           = ?
+++ exited with 0 +++

*/
