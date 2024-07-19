#include "types.hpp"
#include "stl/buffer.hpp"
#include <xutility>

namespace net {
 enum class protocol : u08 {
  hopopt,
  icmp,
  igmp,
  ggp,
  ip_in_ip,
  st,
  tcp,
  cbt,
  egp,
  igp,
  bbn_rcc_mon,
  nvp2,
  pup,
  argus,
  emcon,
  xnet,
  chaos,
  udp,
  mux,
  dcn_meas,
  hmp,
  prm,
  xns_idp,
  trunk_1,
  trunk_2,
  leaf_1,
  leaf_2,
  rdp,
  irtp,
  iso_tp4,
  netblt,
  mfe_nsp,
  merit_inp,
  dccp,
  three_pc,
  idpr,
  xtp,
  ddp,
  idpr_cmtp,
  tpplusplus,
  il,
  ipv6,
  sdrp,
  ipv6_route,
  ipv6_frag,
  idrp,
  rsvp,
  gre,
  dsr,
  bna,
  esp,
  ah,
  i_nlsp,
  swipe,    
  narp,
  mobile,
  tlsp,
  skip,
  ipv6_icmp,
  ipv6_nonxt,
  ipv6_opts,
  cftp = 62,
  sat_expak = 64,
  kryptolan,
  rvd,
  ippc,
  sam_mon = 69,
  visa,
  ipcu,
  cpnx,
  cphb,
  wsn,
  pvp,
  br_sat_mon,
  sun_nd,
  wb_mon,
  wb_expak,
  iso_ip,
  vmtp,
  secure_vmtp,
  vines,
  ttp,
  nsfnet_igp,
  dgp,
  tcf,
  eigrp,
  ospf,
  sprite_rpc,
  larp,
  mtp,
  ax25,
  os,
  micp,
  ssc_sp,
  etherip,
  encap,
  gmtp = 100,
  ifmp,
  pnni,
  pim,
  aris,
  scps,
  qnx,
  an,
  ipcomp,
  snp,
  compaq_peer,
  ipx_in_ip,
  vrrp,
  pgm,
  l2tp = 115,
  ddx,
  iatp,
  stp,
  srp,
  uti,
  smp,
  sm,
  ptp,
  is_is_over_ipv4,
  fire,
  crtp,
  crudp,
  sscopmce,
  iplt,
  sps,
  pipe,
  sctp,
  fc,
  rsvp_e2e_ignore,
  mobility_header,
  udplite,
  mpls_in_ip,
  manet,
  hip,
  shim6,
  wesp,
  rohc,
  ethernet,
  aggfrag,
  nsh,
  
  invalid_enum = 255
 };

#pragma pack(push, 1)
struct ip_header {
  /* 32-bit Data Line #1: */
  u08 version : 4; 
  u08 ihl : 4;
  u08 service_type : 8; 
  u16 size : 16;
  /* 32-bit Data Line #2: */
  u16 id : 16; 
  u16 reserved : 1; 
  u16 df : 1; 
  u16 mf : 1;
  u16 fragment_offset : 13;
  /* 32-bit Data Line #3 */
  u08 ttl;
  u08 protocol;
  u16 header_checksum;
  /* 32-bit Data Line #4 */
  u32 src;
  /* 32-bit Data Line #5 */
  u32 dst;

  [[nodiscard]] static constexpr u16 ip_header_checksum(ip_header const& ip_header) noexcept {
    u32 checksum = ((((static_cast<u32>(ip_header.version) << 4) | ip_header.ihl) << 8) | ip_header.service_type) + ip_header.size;
    checksum = (checksum + ((checksum >> 16) & 1)) & 0xffff;
    checksum += ip_header.id;
    checksum = (checksum + ((checksum >> 16) & 1)) & 0xffff;
    checksum += (static_cast<u32>(ip_header.df) << 15) | (static_cast<u32>(ip_header.mf) << 14) | ip_header.fragment_offset;
    checksum = (checksum + ((checksum >> 16) & 1)) & 0xffff;
    checksum += (static_cast<u32>(ip_header.ttl) << 8) | ip_header.protocol;
    checksum = (checksum + ((checksum >> 16) & 1)) & 0xffff;
    checksum += ip_header.src >> 16;
    checksum = (checksum + ((checksum >> 16) & 1)) & 0xffff;
    checksum += ip_header.src & 0xff;
    checksum = (checksum + ((checksum >> 16) & 1)) & 0xffff;
    checksum += ip_header.dst >> 16;
    checksum = (checksum + ((checksum >> 16) & 1)) & 0xffff;
    checksum += ip_header.dst & 0xff;
    return static_cast<u16>(~((checksum + ((checksum >> 16) & 1)) & 0xffff));
  }
  [[nodiscard]] static constexpr auto ipv4_tcp_header(u32 const src, u32 const dst, u16 const size) noexcept {
   ip_header ip_header {
    /* 32-bit Data Line #1 */
    .version = 4,
    .ihl = sizeof(ip_header) / 4,
    .service_type = 0,
    .size = static_cast<u16>(sizeof(ip_header) + size),
    /* 32-bit Data Line #2 */
    .id = 0x69de,
    .reserved{},
    .df = true,
    .mf = false,
    .fragment_offset = 0,
    /* 32-bit Data Line #3 */
    .ttl = 128,
    .protocol = static_cast<u08>(net::protocol::tcp),
    .header_checksum = 0,
    /* 32-bit Data Line #4 */
    .src = src,
    /* 32-bit Data Line #5 */
    .dst = dst
   };
   ip_header.header_checksum = ip_header_checksum(ip_header);
   return ip_header;
  }
 };
 #pragma pack(pop)
}