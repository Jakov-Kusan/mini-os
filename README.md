# Description

MiniOS is a development environment for the linux kernel and applications using the QEMU virtual machine. Developers can easily clone it and develop based on it. You can turn your idea into a product very quickly using the MiniOS development environment. It is a good choice to verify your solutions on MiniOS before production.

# Install the environment

```
sudo ./install.sh
```
It will install compile toolchains of arm and arm64, and the qemu environment.

# Build MiniOS

To build MiniOS system:

```
./build.sh [-a][-m module][-p platform]
```
Options:

```
 -a: build all modules.
 -m: build expect module:kernel/rootfs/busybox/libc/initramfs.
 -p: build platform, support arm and arm64, default is arm64.
 -h: help informations.
```

# Build samples

 - Default platform arm64:

To build full MiniOS system [platform: arm64]:

```
./build.sh -a
```

To build MiniOS modules [platform:arm64]:

```
./build.sh -m {MODDULE}
```

The module has these values to choose: kernel, rootfs, busybox, libc, initramfs.
BTW, the rootfs module will include "libc", "initramfs" and "busybox" build.

eg:

```
./build.sh -m rootfs    #compile arm64 platform rootfs module
./build.sh -m kernel    #compile arm64 platform kernel module
```
 - arm platform

To build full MiniOS system [platform: arm]:

```
./build.sh -a -p arm
```

To build MiniOS modules [platform:arm]:

```
./build.sh -m {MODDULE} -p arm
```

The module has these values to choose: kernel, rootfs, busybox, libc, initramfs.
BTW, the rootfs module will include "libc", "initramfs" and "busybox" build.

eg:

```
./build.sh -m rootfs -p arm  #compile arm64 platform rootfs module
./build.sh -m kernel -p arm  #compile arm64 platform kernel module
```

# Run MiniOS

```
sudo ./run.sh
```
This command will run default arm64 minios system. If you build an arm platform minios,
you should add option to tell run.sh script:

```
sudo ./run.sh -p arm
```

# Stop MiniOS

```
sudo ./run.sh -s
```
This command will stop default arm64 minios system. If you want to stop an arm platform minios,
you should add option to tell run.sh script:

```
sudo ./run.sh -s -p arm
```
There is another important feature of minios, it supports NFS as rootfs to boot linux kernel.
Using this feature, we can easily debug our applications without rebuilding the whole system:
```
sudo ./run.sh -t nfs -p arm
```
or
```
sudo ./run.sh -t nfs
```
# Advanced info

MiniOS kernel support list: linux-4.0/linux-4.9.

MiniOS busybox support list: busybox-1.24.0/busybox-1.30.0.

If you want to build specific versions of the kernel or busybox, just export the env variables
to change the kernel and busybox versions to build, such as:

```
export BUSYBOX=busybox-1.30.0
export LINUX_KERNEL=linux-4.0
```
If no env variable is exported, the script will use default versions to build.
