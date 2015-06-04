obj-m := kobj_demo.o
KERNELDIR := /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

default:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
	@rm -f *.o *.mod.* *.order *.symvers

clean:
	rm -f *.o *.ko *.mod.*

test: 
	echo "/sbin/hotplug" > /proc/sys/kernel/hotplug 
	insmod kobj_demo.ko
	tail -10 /var/log/syslog |grep hotplug
	echo "0" > /sys/pa_obj/cld_obj/cldatt
	tail -10 /var/log/syslog |grep hotplug
	echo "1" > /sys/pa_obj/cld_obj/cldatt
	tail -10 /var/log/syslog |grep hotplug
	echo "2" > /sys/pa_obj/cld_obj/cldatt
	tail -10 /var/log/syslog |grep hotplug
	echo "3" > /sys/pa_obj/cld_obj/cldatt
	tail -10 /var/log/syslog |grep hotplug
	echo "4" > /sys/pa_obj/cld_obj/cldatt
	tail -10 /var/log/syslog |grep hotplug
	echo "5" > /sys/pa_obj/cld_obj/cldatt
	tail -10 /var/log/syslog |grep hotplug
	rmmod kobj_demo.ko

