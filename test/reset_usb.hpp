#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/ioctl.h>

#include <linux/usbdevice_fs.h>

void reset(char *device)
{
    int file_descriptor;
    int rc;


    file_descriptor = open(device, O_WRONLY);
    if (file_descriptor < 0) {
        perror("Error opening output file");
    }

    printf("Resetting USB device %s\n", device);
    rc = ioctl(file_descriptor, USBDEVFS_RESET, 0);
    if (rc < 0) {
        perror("Error in ioctl");
    }
    printf("Reset successful\n");

    close(file_descriptor);
}
