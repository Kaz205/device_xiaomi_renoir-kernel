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
#ifndef __EAVB_SHARED_H__
#define __EAVB_SHARED_H__
#include <linux/types.h>
#define EAVB_IOCTL_MAGIC 'B'
#define EAVB_IOCTL_CREATE_STREAM _IOWR(EAVB_IOCTL_MAGIC, 1, struct eavb_ioctl_create_stream)
#define EAVB_IOCTL_GET_STREAM_INFO _IOWR(EAVB_IOCTL_MAGIC, 2, struct eavb_ioctl_get_stream_info)
#define EAVB_IOCTL_CONNECT_STREAM _IOWR(EAVB_IOCTL_MAGIC, 3, struct eavb_ioctl_connect_stream)
#define EAVB_IOCTL_RECEIVE _IOWR(EAVB_IOCTL_MAGIC, 4, struct eavb_ioctl_receive)
#define EAVB_IOCTL_RECV_DONE _IOWR(EAVB_IOCTL_MAGIC, 5, struct eavb_ioctl_recv_done)
#define EAVB_IOCTL_TRANSMIT _IOWR(EAVB_IOCTL_MAGIC, 6, struct eavb_ioctl_transmit)
#define EAVB_IOCTL_DISCONNECT_STREAM _IOW(EAVB_IOCTL_MAGIC, 9, struct eavb_ioctl_disconnect_stream)
#define EAVB_IOCTL_DESTROY_STREAM _IOW(EAVB_IOCTL_MAGIC, 10, struct eavb_ioctl_destroy_stream)
#define EAVB_IOCTL_CREATE_STREAM_WITH_PATH _IOWR(EAVB_IOCTL_MAGIC, 11, struct eavb_ioctl_create_stream_with_path)
#define EAVB_IOCTL_GET_CRF_TS _IOWR(EAVB_IOCTL_MAGIC, 12, __u64)
#define STATION_ADDR_SIZE 8
#define IF_NAMESIZE 16
#define MAX_CONFIG_FILE_PATH 512
#define AVB_INVALID_ADDR (0xFF)
#define AVB_INVALID_INTEGER (- 1)
#define AVB_INVALID_UINT (- 1)
enum avb_role {
  AVB_ROLE_TALKER = 0,
  AVB_ROLE_LISTENER,
  AVB_ROLE_CRF_TALKER,
  AVB_ROLE_INVALID = - 1
};
enum stream_mapping_type {
  NONE = 0,
  PCM,
  H264,
  MPEG2TS,
  MJPEG,
  CRF,
  MAPPING_TYPE_INVALID = - 1
};
enum ring_buffer_mode {
  RING_BUFFER_MODE_FILL = 0,
  RING_BUFFER_MODE_DROP_OLD = 1,
  RING_BUFFER_MODE_INVALID = - 1
};
enum avb_class {
  CLASS_A = 0,
  CLASS_B = 1,
  CLASS_AAF = 2,
  CLASS_INVALID = - 1
};
enum data_endianness {
  ENDIAN_BIG = 0,
  ENDIAN_LITTLE = 1,
  ENDIAN_INVALID = - 1
};
enum avb_ieee1722_version {
  QAVB_IEEE_1722_ver_2010 = 0,
  QAVB_IEEE_1722_ver_2016,
  QAVB_IEEE_1722_ver_INVALID = - 1,
};
enum avtp_crf_mode {
  QAVB_AVTP_CRF_MODE_DISABLED = 0,
  QAVB_AVTP_CRF_MODE_TALKER,
  QAVB_AVTP_CRF_MODE_LISTENER,
  QAVB_AVTP_CRF_MODE_LISTENER_NOMINAL,
  QAVB_AVTP_CRF_MODE_MAX
};
enum avtp_crf_type {
  QAVB_AVTP_CRF_TYPE_USER = 0,
  QAVB_AVTP_CRF_TYPE_AUDIO_SAMPLE,
  QAVB_AVTP_CRF_TYPE_VIDEO_FRAME,
  QAVB_AVTP_CRF_TYPE_VIDEO_LINE,
  QAVB_AVTP_CRF_TYPE_MACHINE_CYCLE,
  QAVB_AVTP_CRF_TYPE_MAX
};
enum avtp_crf_pull {
  QAVB_AVTP_CRF_PULL_1_DIV_1_0 = 0,
  QAVB_AVTP_CRF_PULL_1_DIV_1_DOT_1001,
  QAVB_AVTP_CRF_PULL_1_DOT_1001,
  QAVB_AVTP_CRF_PULL_24_DIV_25,
  QAVB_AVTP_CRF_PULL_25_DIV_24,
  QAVB_AVTP_CRF_PULL_8,
  QAVB_AVTP_CRF_PULL_MAX
};
struct eavb_ioctl_hdr {
  __u64 streamCtx;
};
struct eavb_ioctl_stream_config {
  __u16 stream_id;
  char eth_interface[IF_NAMESIZE];
  __u16 vlan_id;
  __u16 ring_buffer_elem_count;
  enum ring_buffer_mode ring_buffer_mode;
  enum avb_role avb_role;
  __u8 dest_macaddr[STATION_ADDR_SIZE];
  __u8 stream_addr[STATION_ADDR_SIZE];
  __u8 crf_dest_macaddr[STATION_ADDR_SIZE];
  __u8 crf_stream_addr[STATION_ADDR_SIZE];
  enum stream_mapping_type mapping_type;
  int wakeup_interval;
  int tx_pkts_per_sec;
  int max_stale_ms;
  int presentation_time_ms;
  int enforce_presentation_time;
  int sr_class_type;
  int packing_factor;
  int bandwidth;
  int max_payload;
  int mrp_enabled;
  int pcm_bit_depth;
  int pcm_channels;
  int sample_rate;
  unsigned char endianness;
  int ieee1722_standard;
  int talker_priority;
  int listener_priority;
  int crf_priority;
  int crf_mode;
  int crf_type;
  int crf_timestamping_interval;
  int crf_timestamping_interval_remote;
  int crf_timestamping_interval_local;
  int crf_allow_dynamic_tx_adjust;
  int crf_num_timestamps_per_pkt;
  __s64 crf_mcr_adjust_min_ppm;
  __s64 crf_mcr_adjust_max_ppm;
  __u16 crf_stream_id;
  __s32 crf_base_frequency;
  __s32 crf_listener_ts_smoothing;
  __s32 crf_talker_ts_smoothing;
  int crf_pull;
  int crf_event_callback_interval;
  int crf_dynamic_tx_adjust_interval;
  __s32 enable_stats_reporting;
  __s32 stats_reporting_interval;
  __s32 stats_reporting_samples;
  __s32 enable_packet_tracking;
  __s32 packet_tracking_interval;
  int blocking_write_enabled;
  double blocking_write_fill_level;
  int app_tx_block_enabled;
  int stream_interleaving_enabled;
  int create_talker_thread;
  int create_crf_threads;
  int listener_bpf_pkts_per_buff;
} __packed;
struct eavb_ioctl_create_stream {
  struct eavb_ioctl_stream_config config;
  struct eavb_ioctl_hdr hdr;
};
struct eavb_ioctl_create_stream_with_path {
  char path[MAX_CONFIG_FILE_PATH];
  struct eavb_ioctl_hdr hdr;
};
struct eavb_ioctl_stream_info {
  enum avb_role role;
  enum stream_mapping_type mapping_type;
  unsigned int max_payload;
  unsigned int pkts_per_wake;
  unsigned int wakeup_period_us;
  int pcm_bit_depth;
  int num_pcm_channels;
  int sample_rate;
  unsigned char endianness;
  unsigned int max_buffer_size;
} __packed;
struct eavb_ioctl_get_stream_info {
  struct eavb_ioctl_hdr hdr;
  struct eavb_ioctl_stream_info info;
};
struct eavb_ioctl_connect_stream {
  struct eavb_ioctl_hdr hdr;
};
struct eavb_ioctl_buf_hdr {
  __u32 flag_end_of_frame : 1;
  __u32 flag_end_of_file : 1;
  __u32 flag_reserved : 30;
  __u32 event;
  __u32 reserved;
  __u32 payload_size;
} __packed;
struct eavb_ioctl_buf_data {
  struct eavb_ioctl_buf_hdr hdr;
  __u64 pbuf;
} __packed;
struct eavb_ioctl_receive {
  struct eavb_ioctl_hdr hdr;
  struct eavb_ioctl_buf_data data;
  __s32 received;
};
struct eavb_ioctl_recv_done {
  struct eavb_ioctl_hdr hdr;
  struct eavb_ioctl_buf_data data;
};
struct eavb_ioctl_transmit {
  struct eavb_ioctl_hdr hdr;
  struct eavb_ioctl_buf_data data;
  __s32 written;
};
struct eavb_ioctl_disconnect_stream {
  struct eavb_ioctl_hdr hdr;
};
struct eavb_ioctl_destroy_stream {
  struct eavb_ioctl_hdr hdr;
};
#endif
