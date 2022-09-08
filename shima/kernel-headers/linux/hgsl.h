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
#ifndef _UAPI_MSM_HGSL_H
#define _UAPI_MSM_HGSL_H
#include <linux/types.h>
#include <linux/ioctl.h>
struct hgsl_ibdesc {
  __u64 gpuaddr;
  __u64 sizedwords;
};
struct hgsl_mem_object {
  __u64 gpuaddr;
  __u64 sizedwords;
};
#define HGSL_IOCTL_BASE 'h'
#define HGSL_IORW(n,t) _IOWR(HGSL_IOCTL_BASE, n, t)
#define HGSL_IOW(n,t) _IOW(HGSL_IOCTL_BASE, n, t)
#define DB_STATE_Q_MASK 0xffff
#define DB_STATE_Q_UNINIT 1
#define DB_STATE_Q_INIT_DONE 2
#define DB_STATE_Q_FAULT 3
#define HGSL_IOCTL_DBQ_GETSTATE HGSL_IORW(0x01, __s32)
struct hgsl_db_queue_inf {
  __s32 fd;
  __u32 head_dwords;
  __s32 head_off_dwords;
  __u32 queue_dwords;
  __s32 queue_off_dwords;
  __u32 db_signal;
};
#define DB_SIGNAL_INVALID 0
#define DB_SIGNAL_GLOBAL_0 1
#define DB_SIGNAL_GLOBAL_1 2
#define DB_SIGNAL_LOCAL 3
#define DB_SIGNAL_MAX DB_SIGNAL_LOCAL
#define HGSL_IOCTL_DBQ_INIT HGSL_IORW(0x02, struct hgsl_db_queue_inf)
#define HGSL_IOCTL_DBQ_ASSIGN HGSL_IORW(0x03, __u32)
struct hgsl_dbq_release_info {
  __u32 ref_count;
  __u32 ctxt_id;
};
#define HGSL_IOCTL_DBQ_RELEASE HGSL_IORW(0x04, struct hgsl_dbq_release_info)
struct hgsl_fhi_issud_cmds {
  __u64 ibs;
  __u32 num_ibs;
  __u64 bos;
  __u32 num_bos;
  __u32 context_id;
  __u32 flags;
  __u32 timestamp;
  __u32 padding;
};
#define HGSL_IOCTL_ISSUE_CMDS HGSL_IORW(0x05, struct hgsl_fhi_issud_cmds)
struct hgsl_ctxt_create_info {
  __u32 context_id;
  __s32 shadow_fd;
  __u32 shadow_sop_offset;
  __u32 shadow_eop_offset;
};
#define HGSL_IOCTL_CTXT_CREATE HGSL_IOW(0x10, struct hgsl_ctxt_create_info)
#define HGSL_IOCTL_CTXT_DESTROY HGSL_IOW(0x11, __u32)
struct hgsl_wait_ts_info {
  __u32 context_id;
  __u32 timestamp;
  __u32 timeout;
  __u32 padding;
};
#define HGSL_IOCTL_WAIT_TIMESTAMP HGSL_IOW(0x12, struct hgsl_wait_ts_info)
struct hgsl_hsync_fence_create {
  __u32 timestamp;
  __u32 padding;
  __s32 context_id;
  __s32 fence_fd;
};
#define HGSL_IOCTL_HSYNC_FENCE_CREATE HGSL_IOW(0x13, struct hgsl_hsync_fence_create)
#define HGSL_IOCTL_ISYNC_TIMELINE_CREATE HGSL_IOW(0x14, __u32)
#define HGSL_IOCTL_ISYNC_TIMELINE_DESTROY HGSL_IOW(0x15, __u32)
struct hgsl_isync_create_fence {
  __u32 timeline_id;
  __s32 fence_id;
  __u32 ts;
  __u32 padding;
};
#define HGSL_IOCTL_ISYNC_FENCE_CREATE HGSL_IOW(0x16, struct hgsl_isync_create_fence)
struct hgsl_isync_signal_fence {
  __u32 timeline_id;
  __s32 fence_id;
};
#define HGSL_IOCTL_ISYNC_FENCE_SIGNAL HGSL_IOW(0x17, struct hgsl_isync_signal_fence)
struct hgsl_isync_forward {
  __u32 timeline_id;
  __s32 ts;
};
#define HGSL_IOCTL_ISYNC_FORWARD HGSL_IOW(0x18, struct hgsl_isync_forward)
#endif
