/****************************************************************************
 ****************************************************************************
 ***
 ***   This header was automatically generated from a Linux kernel header
 ***   of the same name, to make information necessary for userspace to
 ***   call into the kernel available to libc.  It contains only constants,
 ***   structures, and macros generated from the original header, and thus,
 ***   contains no copyrightable information.
 ***
 ***   To edit the content of this header, modify the corresponding
 ***   source file (e.g. under external/kernel-headers/original/) then
 ***   run bionic/libc/kernel/tools/update_all.py
 ***
 ***   Any manual change here will be lost the next time this script will
 ***   be run. You've been warned!
 ***
 ****************************************************************************
 ****************************************************************************/
#include <linux/types.h>
#ifndef _IPT_PORTTRIGGER_H_target
#define _IPT_PORTTRIGGER_H_target
#define TRIGGER_TIMEOUT 600
#define IPT_MULTI_PORTS 15
enum porttrigger_mode {
  MODE_TRIGGER_DNAT,
  MODE_TRIGGER_FORWARD_IN,
  MODE_TRIGGER_FORWARD_OUT
};
struct ipt_mport {
  unsigned short pflags;
  unsigned short ports[IPT_MULTI_PORTS];
};
struct ipt_porttrigger_info {
  enum porttrigger_mode mode;
  unsigned short trigger_proto;
  unsigned short forward_proto;
  unsigned int timer;
  struct ipt_mport trigger_ports;
  struct ipt_mport forward_ports;
};
#endif
