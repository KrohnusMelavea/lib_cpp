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
        nsh
    };

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

        constexpr u16 ip_header_checksum(net::ip_header const& ip_header) noexcept {
            auto data = reinterpret_cast<u08 const*>(&ip_header);
            return 
                *(data +  0) + *(data +  1) + *(data +  2) + *(data +  3) + 
                *(data +  4) + *(data +  5) + *(data +  6) + *(data +  7) +
                *(data +  8) + *(data +  7)                               +
                *(data + 12) + *(data + 13) + *(data + 14) + *(data + 15) + 
                *(data + 16) + *(data + 17) + *(data + 18) + *(data + 19);
        }
        constexpr auto ipv4_tcp_header(u32 const src, u32 const dst, u16 const size) noexcept {
            net::ip_header ip_header {
                /* 32-bit Data Line #1 */
                .version = 4,
                .ihl = sizeof(net::ip_header) / 4,
                .service_type = NULL,
                .size = sizeof(net::ip_header) + size,
                /* 32-bit Data Line #2 */
                .id = NULL,
                .reserved{},
                .df = true,
                .mf = false,
                .fragment_offset = NULL,
                /* 32-bit Data Line #3 */
                .ttl = 255,
                .protocol = static_cast<u08>(net::protocol::tcp),
                .header_checksum = NULL,
                /* 32-bit Data Line #4 */
                .src = src,
                /* 32-bit Data Line #5 */
                .dst = dst
            };
            ip_header.header_checksum = ip_header_checksum(ip_header);
            return ip_header;
        }
    };
}