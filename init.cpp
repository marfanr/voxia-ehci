#include "voxia/ioforge_pci.hpp"
// #include ""

#define CONSOLE_FILE_DESCRIPTOR 1

typedef __UINT8_TYPE__  uint8_t;
typedef __UINT16_TYPE__ uint16_t;
typedef __UINT32_TYPE__ uint32_t;
typedef __UINT64_TYPE__ uint64_t;

extern "C" uint8_t *ioforge_get_pci_device(uint16_t vendor_id, uint16_t device_id);
extern "C" void     serial_printf(const char *fmt, ...);

__thread int my_tls_var = 42; // compiler akan buat .tdata/.tbss

class EHCI
{
};

extern "C" void
module_init()
{
    // my_tls_var = 2;
    serial_printf("hello from kernel module\n");
    IoForgePCI *pci = (IoForgePCI *)ioforge_get_pci_device(0x8086, 0x24cd);
    if (pci)
    {
        serial_printf("found ehci device \n");
    }
    // const char   *str = "$ > \n";
    // unsigned long len = syscall(4, SYS_WRITE, CONSOLE_FILE_DESCRIPTOR,
    //                             (unsigned long)str, 5);

    // // test sys open
    // char *path = "/dev/hid0/asci";
    // // unsigned long fd   = syscall(3, 3, path, 0);
    // // // serial_print_string("fd ok\n");
    // // if (fd == 0) {
    // //     serial_print_string("open file failed\n");
    // //     return 1;
    // // }

    // // struct stat file_stat;
    // // sys_fstat(fd, &file_stat);

    // char buff[34];
    // memset(buff, 0, 32);
    // // while (1) {
    // //     syscall(4, 2, fd, buff, 2);
    // //     if (buff[0] != 0) {
    // //         buff[1]           = '\0';
    // //         unsigned long len = syscall(4, SYS_WRITE, 1,
    // //                                     (unsigned long)buff, 2);
    // //         //         // if (len < 0) {
    // //         //         //     serial_print_string("write failed\n");
    // //         //         //     return 1;
    // //         //         // }
    // //         // memset(buff, 0, 32);
    // //     }
    // // }
    // for (;;)
    //     ;

    // return 0;
}
