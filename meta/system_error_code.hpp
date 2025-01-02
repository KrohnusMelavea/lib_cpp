#pragma once

#include "types.hpp"
#include <array>   
#include <tuple>   
#include <string_view>              

namespace win32 {    
 enum class system_error_code : u16 {              
  error_success                                                            = 0x0000,
  error_invalid_function                                                   = 0x0001,
  error_file_not_found                                                     = 0x0002,
  error_path_not_found                                                     = 0x0003,
  error_too_many_open_files                                                = 0x0004,
  error_access_denied                                                      = 0x0005,
  error_invalid_handle                                                     = 0x0006,
  error_arena_trashed                                                      = 0x0007,
  error_not_enough_memory                                                  = 0x0008,
  error_invalid_block                                                      = 0x0009,
  error_bad_environment                                                    = 0x000a,
  error_bad_format                                                         = 0x000b,
  error_invalid_access                                                     = 0x000c,
  error_invalid_data                                                       = 0x000d,
  error_outofmemory                                                        = 0x000e,
  error_invalid_drive                                                      = 0x000f,
  error_current_directory                                                  = 0x0010,
  error_not_same_device                                                    = 0x0011,
  error_no_more_files                                                      = 0x0012,
  error_write_protect                                                      = 0x0013,
  error_bad_unit                                                           = 0x0014,
  error_not_ready                                                          = 0x0015,
  error_bad_command                                                        = 0x0016,
  error_crc                                                                = 0x0017,
  error_bad_length                                                         = 0x0018,
  error_seek                                                               = 0x0019,
  error_not_dos_disk                                                       = 0x001a,
  error_sector_not_found                                                   = 0x001b,
  error_out_of_paper                                                       = 0x001c,
  error_write_fault                                                        = 0x001d,
  error_read_fault                                                         = 0x001e,
  error_gen_failure                                                        = 0x001f,
  error_sharing_violation                                                  = 0x0020,
  error_lock_violation                                                     = 0x0021,
  error_wrong_disk                                                         = 0x0022,
  error_sharing_buffer_exceeded                                            = 0x0024,
  error_handle_eof                                                         = 0x0026,
  error_handle_disk_full                                                   = 0x0027,
  error_not_supported                                                      = 0x0032,
  error_rem_not_list                                                       = 0x0033,
  error_dup_name                                                           = 0x0034,
  error_bad_netpath                                                        = 0x0035,
  error_network_busy                                                       = 0x0036,
  error_dev_not_exist                                                      = 0x0037,
  error_too_many_cmds                                                      = 0x0038,
  error_adap_hdw_err                                                       = 0x0039,
  error_bad_net_resp                                                       = 0x003a,
  error_unexp_net_err                                                      = 0x003b,
  error_bad_rem_adap                                                       = 0x003c,
  error_printq_full                                                        = 0x003d,
  error_no_spool_space                                                     = 0x003e,
  error_print_cancelled                                                    = 0x003f,
  error_netname_deleted                                                    = 0x0040,
  error_network_access_denied                                              = 0x0041,
  error_bad_dev_type                                                       = 0x0042,
  error_bad_net_name                                                       = 0x0043,
  error_too_many_names                                                     = 0x0044,
  error_too_many_sess                                                      = 0x0045,
  error_sharing_paused                                                     = 0x0046,
  error_req_not_accep                                                      = 0x0047,
  error_redir_paused                                                       = 0x0048,
  error_file_exists                                                        = 0x0050,
  error_cannot_make                                                        = 0x0052,
  error_fail_i24                                                           = 0x0053,
  error_out_of_structures                                                  = 0x0054,
  error_already_assigned                                                   = 0x0055,
  error_invalid_password                                                   = 0x0056,
  error_invalid_parameter                                                  = 0x0057,
  error_net_write_fault                                                    = 0x0058,
  error_no_proc_slots                                                      = 0x0059,
  error_too_many_semaphores                                                = 0x0064,
  error_excl_sem_already_owned                                             = 0x0065,
  error_sem_is_set                                                         = 0x0066,
  error_too_many_sem_requests                                              = 0x0067,
  error_invalid_at_interrupt_time                                          = 0x0068,
  error_sem_owner_died                                                     = 0x0069,
  error_sem_user_limit                                                     = 0x006a,
  error_disk_change                                                        = 0x006b,
  error_drive_locked                                                       = 0x006c,
  error_broken_pipe                                                        = 0x006d,
  error_open_failed                                                        = 0x006e,
  error_buffer_overflow                                                    = 0x006f,
  error_disk_full                                                          = 0x0070,
  error_no_more_search_handles                                             = 0x0071,
  error_invalid_target_handle                                              = 0x0072,
  error_invalid_category                                                   = 0x0075,
  error_invalid_verify_switch                                              = 0x0076,
  error_bad_driver_level                                                   = 0x0077,
  error_call_not_implemented                                               = 0x0078,
  error_sem_timeout                                                        = 0x0079,
  error_insufficient_buffer                                                = 0x007a,
  error_invalid_name                                                       = 0x007b,
  error_invalid_level                                                      = 0x007c,
  error_no_volume_label                                                    = 0x007d,
  error_mod_not_found                                                      = 0x007e,
  error_proc_not_found                                                     = 0x007f,
  error_wait_no_children                                                   = 0x0080,
  error_child_not_complete                                                 = 0x0081,
  error_direct_access_handle                                               = 0x0082,
  error_negative_seek                                                      = 0x0083,
  error_seek_on_device                                                     = 0x0084,
  error_is_join_target                                                     = 0x0085,
  error_is_joined                                                          = 0x0086,
  error_is_substed                                                         = 0x0087,
  error_not_joined                                                         = 0x0088,
  error_not_substed                                                        = 0x0089,
  error_join_to_join                                                       = 0x008a,
  error_subst_to_subst                                                     = 0x008b,
  error_join_to_subst                                                      = 0x008c,
  error_subst_to_join                                                      = 0x008d,
  error_busy_drive                                                         = 0x008e,
  error_same_drive                                                         = 0x008f,
  error_dir_not_root                                                       = 0x0090,
  error_dir_not_empty                                                      = 0x0091,
  error_is_subst_path                                                      = 0x0092,
  error_is_join_path                                                       = 0x0093,
  error_path_busy                                                          = 0x0094,
  error_is_subst_target                                                    = 0x0095,
  error_system_trace                                                       = 0x0096,
  error_invalid_event_count                                                = 0x0097,
  error_too_many_muxwaiters                                                = 0x0098,
  error_invalid_list_format                                                = 0x0099,
  error_label_too_long                                                     = 0x009a,
  error_too_many_tcbs                                                      = 0x009b,
  error_signal_refused                                                     = 0x009c,
  error_discarded                                                          = 0x009d,
  error_not_locked                                                         = 0x009e,
  error_bad_threadid_addr                                                  = 0x009f,
  error_bad_arguments                                                      = 0x00a0,
  error_bad_pathname                                                       = 0x00a1,
  error_signal_pending                                                     = 0x00a2,
  error_max_thrds_reached                                                  = 0x00a4,
  error_lock_failed                                                        = 0x00a7,
  error_busy                                                               = 0x00aa,
  error_device_support_in_progress                                         = 0x00ab,
  error_cancel_violation                                                   = 0x00ad,
  error_atomic_locks_not_supported                                         = 0x00ae,
  error_invalid_segment_number                                             = 0x00b4,
  error_invalid_ordinal                                                    = 0x00b6,
  error_already_exists                                                     = 0x00b7,
  error_invalid_flag_number                                                = 0x00ba,
  error_sem_not_found                                                      = 0x00bb,
  error_invalid_starting_codeseg                                           = 0x00bc,
  error_invalid_stackseg                                                   = 0x00bd,
  error_invalid_moduletype                                                 = 0x00be,
  error_invalid_exe_signature                                              = 0x00bf,
  error_exe_marked_invalid                                                 = 0x00c0,
  error_bad_exe_format                                                     = 0x00c1,
  error_iterated_data_exceeds_64k                                          = 0x00c2,
  error_invalid_minallocsize                                               = 0x00c3,
  error_dynlink_from_invalid_ring                                          = 0x00c4,
  error_iopl_not_enabled                                                   = 0x00c5,
  error_invalid_segdpl                                                     = 0x00c6,
  error_autodataseg_exceeds_64k                                            = 0x00c7,
  error_ring2seg_must_be_movable                                           = 0x00c8,
  error_reloc_chain_xeeds_seglim                                           = 0x00c9,
  error_infloop_in_reloc_chain                                             = 0x00ca,
  error_envvar_not_found                                                   = 0x00cb,
  error_no_signal_sent                                                     = 0x00cd,
  error_filename_exced_range                                               = 0x00ce,
  error_ring2_stack_in_use                                                 = 0x00cf,
  error_meta_expansion_too_long                                            = 0x00d0,
  error_invalid_signal_number                                              = 0x00d1,
  error_thread_1_inactive                                                  = 0x00d2,
  error_locked                                                             = 0x00d4,
  error_too_many_modules                                                   = 0x00d6,
  error_nesting_not_allowed                                                = 0x00d7,
  error_exe_machine_type_mismatch                                          = 0x00d8,
  error_exe_cannot_modify_signed_binary                                    = 0x00d9,
  error_exe_cannot_modify_strong_signed_binary                             = 0x00da,
  error_file_checked_out                                                   = 0x00dc,
  error_checkout_required                                                  = 0x00dd,
  error_bad_file_type                                                      = 0x00de,
  error_file_too_large                                                     = 0x00df,
  error_forms_auth_required                                                = 0x00e0,
  error_virus_infected                                                     = 0x00e1,
  error_virus_deleted                                                      = 0x00e2,
  error_pipe_local                                                         = 0x00e5,
  error_bad_pipe                                                           = 0x00e6,
  error_pipe_busy                                                          = 0x00e7,
  error_no_data                                                            = 0x00e8,
  error_pipe_not_connected                                                 = 0x00e9,
  error_more_data                                                          = 0x00ea,
  error_vc_disconnected                                                    = 0x00f0,
  error_invalid_ea_name                                                    = 0x00fe,
  error_ea_list_inconsistent                                               = 0x00ff,
  wait_timeout                                                             = 0x0102,
  error_no_more_items                                                      = 0x0103,
  error_cannot_copy                                                        = 0x010a,
  error_directory                                                          = 0x010b,
  error_eas_didnt_fit                                                      = 0x0113,
  error_ea_file_corrupt                                                    = 0x0114,
  error_ea_table_full                                                      = 0x0115,
  error_invalid_ea_handle                                                  = 0x0116,
  error_eas_not_supported                                                  = 0x011a,
  error_not_owner                                                          = 0x0120,
  error_too_many_posts                                                     = 0x012a,
  error_partial_copy                                                       = 0x012b,
  error_oplock_not_granted                                                 = 0x012c,
  error_invalid_oplock_protocol                                            = 0x012d,
  error_disk_too_fragmented                                                = 0x012e,
  error_delete_pending                                                     = 0x012f,
  error_incompatible_with_global_short_name_registry_setting               = 0x0130,
  error_short_names_not_enabled_on_volume                                  = 0x0131,
  error_security_stream_is_inconsistent                                    = 0x0132,
  error_invalid_lock_range                                                 = 0x0133,
  error_image_subsystem_not_present                                        = 0x0134,
  error_notification_guid_already_defined                                  = 0x0135,
  error_invalid_exception_handler                                          = 0x0136,
  error_duplicate_privileges                                               = 0x0137,
  error_no_ranges_processed                                                = 0x0138,
  error_not_allowed_on_system_file                                         = 0x0139,
  error_disk_resources_exhausted                                           = 0x013a,
  error_invalid_token                                                      = 0x013b,
  error_device_feature_not_supported                                       = 0x013c,
  error_mr_mid_not_found                                                   = 0x013d,
  error_scope_not_found                                                    = 0x013e,
  error_undefined_scope                                                    = 0x013f,
  error_invalid_cap                                                        = 0x0140,
  error_device_unreachable                                                 = 0x0141,
  error_device_no_resources                                                = 0x0142,
  error_data_checksum_error                                                = 0x0143,
  error_intermixed_kernel_ea_operation                                     = 0x0144,
  error_file_level_trim_not_supported                                      = 0x0146,
  error_offset_alignment_violation                                         = 0x0147,
  error_invalid_field_in_parameter_list                                    = 0x0148,
  error_operation_in_progress                                              = 0x0149,
  error_bad_device_path                                                    = 0x014a,
  error_too_many_descriptors                                               = 0x014b,
  error_scrub_data_disabled                                                = 0x014c,
  error_not_redundant_storage                                              = 0x014d,
  error_resident_file_not_supported                                        = 0x014e,
  error_compressed_file_not_supported                                      = 0x014f,
  error_directory_not_supported                                            = 0x0150,
  error_not_read_from_copy                                                 = 0x0151,
  error_fail_noaction_reboot                                               = 0x015e,
  error_fail_shutdown                                                      = 0x015f,
  error_fail_restart                                                       = 0x0160,
  error_max_sessions_reached                                               = 0x0161,
  error_thread_mode_already_background                                     = 0x0190,
  error_thread_mode_not_background                                         = 0x0191,
  error_process_mode_already_background                                    = 0x0192,
  error_process_mode_not_background                                        = 0x0193,
  error_invalid_address                                                    = 0x01e7,
  error_user_profile_load                                                  = 0x01f4,
  error_arithmetic_overflow                                                = 0x0216,
  error_pipe_connected                                                     = 0x0217,
  error_pipe_listening                                                     = 0x0218,
  error_verifier_stop                                                      = 0x0219,
  error_abios_error                                                        = 0x021a,
  error_wx86_warning                                                       = 0x021b,
  error_wx86_error                                                         = 0x021c,
  error_timer_not_canceled                                                 = 0x021d,
  error_unwind                                                             = 0x021e,
  error_bad_stack                                                          = 0x021f,
  error_invalid_unwind_target                                              = 0x0220,
  error_invalid_port_attributes                                            = 0x0221,
  error_port_message_too_long                                              = 0x0222,
  error_invalid_quota_lower                                                = 0x0223,
  error_device_already_attached                                            = 0x0224,
  error_instruction_misalignment                                           = 0x0225,
  error_profiling_not_started                                              = 0x0226,
  error_profiling_not_stopped                                              = 0x0227,
  error_could_not_interpret                                                = 0x0228,
  error_profiling_at_limit                                                 = 0x0229,
  error_cant_wait                                                          = 0x022a,
  error_cant_terminate_self                                                = 0x022b,
  error_unexpected_mm_create_err                                           = 0x022c,
  error_unexpected_mm_map_error                                            = 0x022d,
  error_unexpected_mm_extend_err                                           = 0x022e,
  error_bad_function_table                                                 = 0x022f,
  error_no_guid_translation                                                = 0x0230,
  error_invalid_ldt_size                                                   = 0x0231,
  error_invalid_ldt_offset                                                 = 0x0233,
  error_invalid_ldt_descriptor                                             = 0x0234,
  error_too_many_threads                                                   = 0x0235,
  error_thread_not_in_process                                              = 0x0236,
  error_pagefile_quota_exceeded                                            = 0x0237,
  error_logon_server_conflict                                              = 0x0238,
  error_synchronization_required                                           = 0x0239,
  error_net_open_failed                                                    = 0x023a,
  error_io_privilege_failed                                                = 0x023b,
  error_control_c_exit                                                     = 0x023c,
  error_missing_systemfile                                                 = 0x023d,
  error_unhandled_exception                                                = 0x023e,
  error_app_init_failure                                                   = 0x023f,
  error_pagefile_create_failed                                             = 0x0240,
  error_invalid_image_hash                                                 = 0x0241,
  error_no_pagefile                                                        = 0x0242,
  error_illegal_float_context                                              = 0x0243,
  error_no_event_pair                                                      = 0x0244,
  error_domain_ctrlr_config_error                                          = 0x0245,
  error_illegal_character                                                  = 0x0246,
  error_undefined_character                                                = 0x0247,
  error_floppy_volume                                                      = 0x0248,
  error_bios_failed_to_connect_interrupt                                   = 0x0249,
  error_backup_controller                                                  = 0x024a,
  error_mutant_limit_exceeded                                              = 0x024b,
  error_fs_driver_required                                                 = 0x024c,
  error_cannot_load_registry_file                                          = 0x024d,
  error_debug_attach_failed                                                = 0x024e,
  error_system_process_terminated                                          = 0x024f,
  error_data_not_accepted                                                  = 0x0250,
  error_vdm_hard_error                                                     = 0x0251,
  error_driver_cancel_timeout                                              = 0x0252,
  error_reply_message_mismatch                                             = 0x0253,
  error_lost_writebehind_data                                              = 0x0254,
  error_client_server_parameters_invalid                                   = 0x0255,
  error_not_tiny_stream                                                    = 0x0256,
  error_stack_overflow_read                                                = 0x0257,
  error_convert_to_large                                                   = 0x0258,
  error_found_out_of_scope                                                 = 0x0259,
  error_allocate_bucket                                                    = 0x025a,
  error_marshall_overflow                                                  = 0x025b,
  error_invalid_variant                                                    = 0x025c,
  error_bad_compression_buffer                                             = 0x025d,
  error_audit_failed                                                       = 0x025e,
  error_timer_resolution_not_set                                           = 0x025f,
  error_insufficient_logon_info                                            = 0x0260,
  error_bad_dll_entrypoint                                                 = 0x0261,
  error_bad_service_entrypoint                                             = 0x0262,
  error_ip_address_conflict1                                               = 0x0263,
  error_ip_address_conflict2                                               = 0x0264,
  error_registry_quota_limit                                               = 0x0265,
  error_no_callback_active                                                 = 0x0266,
  error_pwd_too_short                                                      = 0x0267,
  error_pwd_too_recent                                                     = 0x0268,
  error_pwd_history_conflict                                               = 0x0269,
  error_unsupported_compression                                            = 0x026a,
  error_invalid_hw_profile                                                 = 0x026b,
  error_invalid_plugplay_device_path                                       = 0x026c,
  error_quota_list_inconsistent                                            = 0x026d,
  error_evaluation_expiration                                              = 0x026e,
  error_illegal_dll_relocation                                             = 0x026f,
  error_dll_init_failed_logoff                                             = 0x0270,
  error_validate_continue                                                  = 0x0271,
  error_no_more_matches                                                    = 0x0272,
  error_range_list_conflict                                                = 0x0273,
  error_server_sid_mismatch                                                = 0x0274,
  error_cant_enable_deny_only                                              = 0x0275,
  error_float_multiple_faults                                              = 0x0276,
  error_float_multiple_traps                                               = 0x0277,
  error_nointerface                                                        = 0x0278,
  error_driver_failed_sleep                                                = 0x0279,
  error_corrupt_system_file                                                = 0x027a,
  error_commitment_minimum                                                 = 0x027b,
  error_pnp_restart_enumeration                                            = 0x027c,
  error_system_image_bad_signature                                         = 0x027d,
  error_pnp_reboot_required                                                = 0x027e,
  error_insufficient_power                                                 = 0x027f,
  error_multiple_fault_violation                                           = 0x0280,
  error_system_shutdown                                                    = 0x0281,
  error_port_not_set                                                       = 0x0282,
  error_ds_version_check_failure                                           = 0x0283,
  error_range_not_found                                                    = 0x0284,
  error_not_safe_mode_driver                                               = 0x0286,
  error_failed_driver_entry                                                = 0x0287,
  error_device_enumeration_error                                           = 0x0288,
  error_mount_point_not_resolved                                           = 0x0289,
  error_invalid_device_object_parameter                                    = 0x028a,
  error_mca_occured                                                        = 0x028b,
  error_driver_database_error                                              = 0x028c,
  error_system_hive_too_large                                              = 0x028d,
  error_driver_failed_prior_unload                                         = 0x028e,
  error_volsnap_prepare_hibernate                                          = 0x028f,
  error_hibernation_failure                                                = 0x0290,
  error_pwd_too_long                                                       = 0x0291,
  error_file_system_limitation                                             = 0x0299,
  error_assertion_failure                                                  = 0x029c,
  error_acpi_error                                                         = 0x029d,
  error_wow_assertion                                                      = 0x029e,
  error_pnp_bad_mps_table                                                  = 0x029f,
  error_pnp_translation_failed                                             = 0x02a0,
  error_pnp_irq_translation_failed                                         = 0x02a1,
  error_pnp_invalid_id                                                     = 0x02a2,
  error_wake_system_debugger                                               = 0x02a3,
  error_handles_closed                                                     = 0x02a4,
  error_extraneous_information                                             = 0x02a5,
  error_rxact_commit_necessary                                             = 0x02a6,
  error_media_check                                                        = 0x02a7,
  error_guid_substitution_made                                             = 0x02a8,
  error_stopped_on_symlink                                                 = 0x02a9,
  error_longjump                                                           = 0x02aa,
  error_plugplay_query_vetoed                                              = 0x02ab,
  error_unwind_consolidate                                                 = 0x02ac,
  error_registry_hive_recovered                                            = 0x02ad,
  error_dll_might_be_insecure                                              = 0x02ae,
  error_dll_might_be_incompatible                                          = 0x02af,
  error_dbg_exception_not_handled                                          = 0x02b0,
  error_dbg_reply_later                                                    = 0x02b1,
  error_dbg_unable_to_provide_handle                                       = 0x02b2,
  error_dbg_terminate_thread                                               = 0x02b3,
  error_dbg_terminate_process                                              = 0x02b4,
  error_dbg_control_c                                                      = 0x02b5,
  error_dbg_printexception_c                                               = 0x02b6,
  error_dbg_ripexception                                                   = 0x02b7,
  error_dbg_control_break                                                  = 0x02b8,
  error_dbg_command_exception                                              = 0x02b9,
  error_object_name_exists                                                 = 0x02ba,
  error_thread_was_suspended                                               = 0x02bb,
  error_image_not_at_base                                                  = 0x02bc,
  error_rxact_state_created                                                = 0x02bd,
  error_segment_notification                                               = 0x02be,
  error_bad_current_directory                                              = 0x02bf,
  error_ft_read_recovery_from_backup                                       = 0x02c0,
  error_ft_write_recovery                                                  = 0x02c1,
  error_image_machine_type_mismatch                                        = 0x02c2,
  error_receive_partial                                                    = 0x02c3,
  error_receive_expedited                                                  = 0x02c4,
  error_receive_partial_expedited                                          = 0x02c5,
  error_event_done                                                         = 0x02c6,
  error_event_pending                                                      = 0x02c7,
  error_checking_file_system                                               = 0x02c8,
  error_fatal_app_exit                                                     = 0x02c9,
  error_predefined_handle                                                  = 0x02ca,
  error_was_unlocked                                                       = 0x02cb,
  error_service_notification                                               = 0x02cc,
  error_was_locked                                                         = 0x02cd,
  error_log_hard_error                                                     = 0x02ce,
  error_already_win32                                                      = 0x02cf,
  error_image_machine_type_mismatch_exe                                    = 0x02d0,
  error_no_yield_performed                                                 = 0x02d1,
  error_timer_resume_ignored                                               = 0x02d2,
  error_arbitration_unhandled                                              = 0x02d3,
  error_cardbus_not_supported                                              = 0x02d4,
  error_mp_processor_mismatch                                              = 0x02d5,
  error_hibernated                                                         = 0x02d6,
  error_resume_hibernation                                                 = 0x02d7,
  error_firmware_updated                                                   = 0x02d8,
  error_drivers_leaking_locked_pages                                       = 0x02d9,
  error_wake_system                                                        = 0x02da,
  error_wait_1                                                             = 0x02db,
  error_wait_2                                                             = 0x02dc,
  error_wait_3                                                             = 0x02dd,
  error_wait_63                                                            = 0x02de,
  error_abandoned_wait_0                                                   = 0x02df,
  error_abandoned_wait_63                                                  = 0x02e0,
  error_user_apc                                                           = 0x02e1,
  error_kernel_apc                                                         = 0x02e2,
  error_alerted                                                            = 0x02e3,
  error_elevation_required                                                 = 0x02e4,
  error_reparse                                                            = 0x02e5,
  error_oplock_break_in_progress                                           = 0x02e6,
  error_volume_mounted                                                     = 0x02e7,
  error_rxact_committed                                                    = 0x02e8,
  error_notify_cleanup                                                     = 0x02e9,
  error_primary_transport_connect_failed                                   = 0x02ea,
  error_page_fault_transition                                              = 0x02eb,
  error_page_fault_demand_zero                                             = 0x02ec,
  error_page_fault_copy_on_write                                           = 0x02ed,
  error_page_fault_guard_page                                              = 0x02ee,
  error_page_fault_paging_file                                             = 0x02ef,
  error_cache_page_locked                                                  = 0x02f0,
  error_crash_dump                                                         = 0x02f1,
  error_buffer_all_zeros                                                   = 0x02f2,
  error_reparse_object                                                     = 0x02f3,
  error_resource_requirements_changed                                      = 0x02f4,
  error_translation_complete                                               = 0x02f5,
  error_nothing_to_terminate                                               = 0x02f6,
  error_process_not_in_job                                                 = 0x02f7,
  error_process_in_job                                                     = 0x02f8,
  error_volsnap_hibernate_ready                                            = 0x02f9,
  error_fsfilter_op_completed_successfully                                 = 0x02fa,
  error_interrupt_vector_already_connected                                 = 0x02fb,
  error_interrupt_still_connected                                          = 0x02fc,
  error_wait_for_oplock                                                    = 0x02fd,
  error_dbg_exception_handled                                              = 0x02fe,
  error_dbg_continue                                                       = 0x02ff,
  error_callback_pop_stack                                                 = 0x0300,
  error_compression_disabled                                               = 0x0301,
  error_cantfetchbackwards                                                 = 0x0302,
  error_cantscrollbackwards                                                = 0x0303,
  error_rowsnotreleased                                                    = 0x0304,
  error_bad_accessor_flags                                                 = 0x0305,
  error_errors_encountered                                                 = 0x0306,
  error_not_capable                                                        = 0x0307,
  error_request_out_of_sequence                                            = 0x0308,
  error_version_parse_error                                                = 0x0309,
  error_badstartposition                                                   = 0x030a,
  error_memory_hardware                                                    = 0x030b,
  error_disk_repair_disabled                                               = 0x030c,
  error_insufficient_resource_for_specified_shared_section_size            = 0x030d,
  error_system_powerstate_transition                                       = 0x030e,
  error_system_powerstate_complex_transition                               = 0x030f,
  error_mca_exception                                                      = 0x0310,
  error_access_audit_by_policy                                             = 0x0311,
  error_access_disabled_no_safer_ui_by_policy                              = 0x0312,
  error_abandon_hiberfile                                                  = 0x0313,
  error_lost_writebehind_data_network_disconnected                         = 0x0314,
  error_lost_writebehind_data_network_server_error                         = 0x0315,
  error_lost_writebehind_data_local_disk_error                             = 0x0316,
  error_bad_mcfg_table                                                     = 0x0317,
  error_disk_repair_redirected                                             = 0x0318,
  error_disk_repair_unsuccessful                                           = 0x0319,
  error_corrupt_log_overfull                                               = 0x031a,
  error_corrupt_log_corrupted                                              = 0x031b,
  error_corrupt_log_unavailable                                            = 0x031c,
  error_corrupt_log_deleted_full                                           = 0x031d,
  error_corrupt_log_cleared                                                = 0x031e,
  error_orphan_name_exhausted                                              = 0x031f,
  error_oplock_switched_to_new_handle                                      = 0x0320,
  error_cannot_grant_requested_oplock                                      = 0x0321,
  error_cannot_break_oplock                                                = 0x0322,
  error_oplock_handle_closed                                               = 0x0323,
  error_no_ace_condition                                                   = 0x0324,
  error_invalid_ace_condition                                              = 0x0325,
  error_file_handle_revoked                                                = 0x0326,
  error_image_at_different_base                                            = 0x0327,
  error_ea_access_denied                                                   = 0x03e2,
  error_operation_aborted                                                  = 0x03e3,
  error_io_incomplete                                                      = 0x03e4,
  error_io_pending                                                         = 0x03e5,
  error_noaccess                                                           = 0x03e6,
  error_swaperror                                                          = 0x03e7,
  error_stack_overflow                                                     = 0x03e9,
  error_invalid_message                                                    = 0x03ea,
  error_can_not_complete                                                   = 0x03eb,
  error_invalid_flags                                                      = 0x03ec,
  error_unrecognized_volume                                                = 0x03ed,
  error_file_invalid                                                       = 0x03ee,
  error_fullscreen_mode                                                    = 0x03ef,
  error_no_token                                                           = 0x03f0,
  error_baddb                                                              = 0x03f1,
  error_badkey                                                             = 0x03f2,
  error_cantopen                                                           = 0x03f3,
  error_cantread                                                           = 0x03f4,
  error_cantwrite                                                          = 0x03f5,
  error_registry_recovered                                                 = 0x03f6,
  error_registry_corrupt                                                   = 0x03f7,
  error_registry_io_failed                                                 = 0x03f8,
  error_not_registry_file                                                  = 0x03f9,
  error_key_deleted                                                        = 0x03fa,
  error_no_log_space                                                       = 0x03fb,
  error_key_has_children                                                   = 0x03fc,
  error_child_must_be_volatile                                             = 0x03fd,
  error_notify_enum_dir                                                    = 0x03fe,
  error_dependent_services_running                                         = 0x041b,
  error_invalid_service_control                                            = 0x041c,
  error_service_request_timeout                                            = 0x041d,
  error_service_no_thread                                                  = 0x041e,
  error_service_database_locked                                            = 0x041f,
  error_service_already_running                                            = 0x0420,
  error_invalid_service_account                                            = 0x0421,
  error_service_disabled                                                   = 0x0422,
  error_circular_dependency                                                = 0x0423,
  error_service_does_not_exist                                             = 0x0424,
  error_service_cannot_accept_ctrl                                         = 0x0425,
  error_service_not_active                                                 = 0x0426,
  error_failed_service_controller_connect                                  = 0x0427,
  error_exception_in_service                                               = 0x0428,
  error_database_does_not_exist                                            = 0x0429,
  error_service_specific_error                                             = 0x042a,
  error_process_aborted                                                    = 0x042b,
  error_service_dependency_fail                                            = 0x042c,
  error_service_logon_failed                                               = 0x042d,
  error_service_start_hang                                                 = 0x042e,
  error_invalid_service_lock                                               = 0x042f,
  error_service_marked_for_delete                                          = 0x0430,
  error_service_exists                                                     = 0x0431,
  error_already_running_lkg                                                = 0x0432,
  error_service_dependency_deleted                                         = 0x0433,
  error_boot_already_accepted                                              = 0x0434,
  error_service_never_started                                              = 0x0435,
  error_duplicate_service_name                                             = 0x0436,
  error_different_service_account                                          = 0x0437,
  error_cannot_detect_driver_failure                                       = 0x0438,
  error_cannot_detect_process_abort                                        = 0x0439,
  error_no_recovery_program                                                = 0x043a,
  error_service_not_in_exe                                                 = 0x043b,
  error_not_safeboot_service                                               = 0x043c,
  error_end_of_media                                                       = 0x044c,
  error_filemark_detected                                                  = 0x044d,
  error_beginning_of_media                                                 = 0x044e,
  error_setmark_detected                                                   = 0x044f,
  error_no_data_detected                                                   = 0x0450,
  error_partition_failure                                                  = 0x0451,
  error_invalid_block_length                                               = 0x0452,
  error_device_not_partitioned                                             = 0x0453,
  error_unable_to_lock_media                                               = 0x0454,
  error_unable_to_unload_media                                             = 0x0455,
  error_media_changed                                                      = 0x0456,
  error_bus_reset                                                          = 0x0457,
  error_no_media_in_drive                                                  = 0x0458,
  error_no_unicode_translation                                             = 0x0459,
  error_dll_init_failed                                                    = 0x045a,
  error_shutdown_in_progress                                               = 0x045b,
  error_no_shutdown_in_progress                                            = 0x045c,
  error_io_device                                                          = 0x045d,
  error_serial_no_device                                                   = 0x045e,
  error_irq_busy                                                           = 0x045f,
  error_more_writes                                                        = 0x0460,
  error_counter_timeout                                                    = 0x0461,
  error_floppy_id_mark_not_found                                           = 0x0462,
  error_floppy_wrong_cylinder                                              = 0x0463,
  error_floppy_unknown_error                                               = 0x0464,
  error_floppy_bad_registers                                               = 0x0465,
  error_disk_recalibrate_failed                                            = 0x0466,
  error_disk_operation_failed                                              = 0x0467,
  error_disk_reset_failed                                                  = 0x0468,
  error_eom_overflow                                                       = 0x0469,
  error_not_enough_server_memory                                           = 0x046a,
  error_possible_deadlock                                                  = 0x046b,
  error_mapped_alignment                                                   = 0x046c,
  error_set_power_state_vetoed                                             = 0x0474,
  error_set_power_state_failed                                             = 0x0475,
  error_too_many_links                                                     = 0x0476,
  error_old_win_version                                                    = 0x047e,
  error_app_wrong_os                                                       = 0x047f,
  error_single_instance_app                                                = 0x0480,
  error_rmode_app                                                          = 0x0481,
  error_invalid_dll                                                        = 0x0482,
  error_no_association                                                     = 0x0483,
  error_dde_fail                                                           = 0x0484,
  error_dll_not_found                                                      = 0x0485,
  error_no_more_user_handles                                               = 0x0486,
  error_message_sync_only                                                  = 0x0487,
  error_source_element_empty                                               = 0x0488,
  error_destination_element_full                                           = 0x0489,
  error_illegal_element_address                                            = 0x048a,
  error_magazine_not_present                                               = 0x048b,
  error_device_reinitialization_needed                                     = 0x048c,
  error_device_requires_cleaning                                           = 0x048d,
  error_device_door_open                                                   = 0x048e,
  error_device_not_connected                                               = 0x048f,
  error_not_found                                                          = 0x0490,
  error_no_match                                                           = 0x0491,
  error_set_not_found                                                      = 0x0492,
  error_point_not_found                                                    = 0x0493,
  error_no_tracking_service                                                = 0x0494,
  error_no_volume_id                                                       = 0x0495,
  error_unable_to_remove_replaced                                          = 0x0497,
  error_unable_to_move_replacement                                         = 0x0498,
  error_unable_to_move_replacement_2                                       = 0x0499,
  error_journal_delete_in_progress                                         = 0x049a,
  error_journal_not_active                                                 = 0x049b,
  error_potential_file_found                                               = 0x049c,
  error_journal_entry_deleted                                              = 0x049d,
  error_shutdown_is_scheduled                                              = 0x04a6,
  error_shutdown_users_logged_on                                           = 0x04a7,
  error_bad_device                                                         = 0x04b0,
  error_connection_unavail                                                 = 0x04b1,
  error_device_already_remembered                                          = 0x04b2,
  error_no_net_or_bad_path                                                 = 0x04b3,
  error_bad_provider                                                       = 0x04b4,
  error_cannot_open_profile                                                = 0x04b5,
  error_bad_profile                                                        = 0x04b6,
  error_not_container                                                      = 0x04b7,
  error_extended_error                                                     = 0x04b8,
  error_invalid_groupname                                                  = 0x04b9,
  error_invalid_computername                                               = 0x04ba,
  error_invalid_eventname                                                  = 0x04bb,
  error_invalid_domainname                                                 = 0x04bc,
  error_invalid_servicename                                                = 0x04bd,
  error_invalid_netname                                                    = 0x04be,
  error_invalid_sharename                                                  = 0x04bf,
  error_invalid_passwordname                                               = 0x04c0,
  error_invalid_messagename                                                = 0x04c1,
  error_invalid_messagedest                                                = 0x04c2,
  error_session_credential_conflict                                        = 0x04c3,
  error_remote_session_limit_exceeded                                      = 0x04c4,
  error_dup_domainname                                                     = 0x04c5,
  error_no_network                                                         = 0x04c6,
  error_cancelled                                                          = 0x04c7,
  error_user_mapped_file                                                   = 0x04c8,
  error_connection_refused                                                 = 0x04c9,
  error_graceful_disconnect                                                = 0x04ca,
  error_address_already_associated                                         = 0x04cb,
  error_address_not_associated                                             = 0x04cc,
  error_connection_invalid                                                 = 0x04cd,
  error_connection_active                                                  = 0x04ce,
  error_network_unreachable                                                = 0x04cf,
  error_host_unreachable                                                   = 0x04d0,
  error_protocol_unreachable                                               = 0x04d1,
  error_port_unreachable                                                   = 0x04d2,
  error_request_aborted                                                    = 0x04d3,
  error_connection_aborted                                                 = 0x04d4,
  error_retry                                                              = 0x04d5,
  error_connection_count_limit                                             = 0x04d6,
  error_login_time_restriction                                             = 0x04d7,
  error_login_wksta_restriction                                            = 0x04d8,
  error_incorrect_address                                                  = 0x04d9,
  error_already_registered                                                 = 0x04da,
  error_service_not_found                                                  = 0x04db,
  error_not_authenticated                                                  = 0x04dc,
  error_not_logged_on                                                      = 0x04dd,
  error_continue                                                           = 0x04de,
  error_already_initialized                                                = 0x04df,
  error_no_more_devices                                                    = 0x04e0,
  error_no_such_site                                                       = 0x04e1,
  error_domain_controller_exists                                           = 0x04e2,
  error_only_if_connected                                                  = 0x04e3,
  error_override_nochanges                                                 = 0x04e4,
  error_bad_user_profile                                                   = 0x04e5,
  error_not_supported_on_sbs                                               = 0x04e6,
  error_server_shutdown_in_progress                                        = 0x04e7,
  error_host_down                                                          = 0x04e8,
  error_non_account_sid                                                    = 0x04e9,
  error_non_domain_sid                                                     = 0x04ea,
  error_apphelp_block                                                      = 0x04eb,
  error_access_disabled_by_policy                                          = 0x04ec,
  error_reg_nat_consumption                                                = 0x04ed,
  error_cscshare_offline                                                   = 0x04ee,
  error_pkinit_failure                                                     = 0x04ef,
  error_smartcard_subsystem_failure                                        = 0x04f0,
  error_downgrade_detected                                                 = 0x04f1,
  error_machine_locked                                                     = 0x04f7,
  error_callback_supplied_invalid_data                                     = 0x04f9,
  error_sync_foreground_refresh_required                                   = 0x04fa,
  error_driver_blocked                                                     = 0x04fb,
  error_invalid_import_of_non_dll                                          = 0x04fc,
  error_access_disabled_webblade                                           = 0x04fd,
  error_access_disabled_webblade_tamper                                    = 0x04fe,
  error_recovery_failure                                                   = 0x04ff,
  error_already_fiber                                                      = 0x0500,
  error_already_thread                                                     = 0x0501,
  error_stack_buffer_overrun                                               = 0x0502,
  error_parameter_quota_exceeded                                           = 0x0503,
  error_debugger_inactive                                                  = 0x0504,
  error_delay_load_failed                                                  = 0x0505,
  error_vdm_disallowed                                                     = 0x0506,
  error_unidentified_error                                                 = 0x0507,
  error_invalid_cruntime_parameter                                         = 0x0508,
  error_beyond_vdl                                                         = 0x0509,
  error_incompatible_service_sid_type                                      = 0x050a,
  error_driver_process_terminated                                          = 0x050b,
  error_implementation_limit                                               = 0x050c,
  error_process_is_protected                                               = 0x050d,
  error_service_notify_client_lagging                                      = 0x050e,
  error_disk_quota_exceeded                                                = 0x050f,
  error_content_blocked                                                    = 0x0510,
  error_incompatible_service_privilege                                     = 0x0511,
  error_app_hang                                                           = 0x0512,
  error_invalid_label                                                      = 0x0513,
  error_not_all_assigned                                                   = 0x0514,
  error_some_not_mapped                                                    = 0x0515,
  error_no_quotas_for_account                                              = 0x0516,
  error_local_user_session_key                                             = 0x0517,
  error_null_lm_password                                                   = 0x0518,
  error_unknown_revision                                                   = 0x0519,
  error_revision_mismatch                                                  = 0x051a,
  error_invalid_owner                                                      = 0x051b,
  error_invalid_primary_group                                              = 0x051c,
  error_no_impersonation_token                                             = 0x051d,
  error_cant_disable_mandatory                                             = 0x051e,
  error_no_logon_servers                                                   = 0x051f,
  error_no_such_logon_session                                              = 0x0520,
  error_no_such_privilege                                                  = 0x0521,
  error_privilege_not_held                                                 = 0x0522,
  error_invalid_account_name                                               = 0x0523,
  error_user_exists                                                        = 0x0524,
  error_no_such_user                                                       = 0x0525,
  error_group_exists                                                       = 0x0526,
  error_no_such_group                                                      = 0x0527,
  error_member_in_group                                                    = 0x0528,
  error_member_not_in_group                                                = 0x0529,
  error_last_admin                                                         = 0x052a,
  error_wrong_password                                                     = 0x052b,
  error_ill_formed_password                                                = 0x052c,
  error_password_restriction                                               = 0x052d,
  error_logon_failure                                                      = 0x052e,
  error_account_restriction                                                = 0x052f,
  error_invalid_logon_hours                                                = 0x0530,
  error_invalid_workstation                                                = 0x0531,
  error_password_expired                                                   = 0x0532,
  error_account_disabled                                                   = 0x0533,
  error_none_mapped                                                        = 0x0534,
  error_too_many_luids_requested                                           = 0x0535,
  error_luids_exhausted                                                    = 0x0536,
  error_invalid_sub_authority                                              = 0x0537,
  error_invalid_acl                                                        = 0x0538,
  error_invalid_sid                                                        = 0x0539,
  error_invalid_security_descr                                             = 0x053a,
  error_bad_inheritance_acl                                                = 0x053c,
  error_server_disabled                                                    = 0x053d,
  error_server_not_disabled                                                = 0x053e,
  error_invalid_id_authority                                               = 0x053f,
  error_allotted_space_exceeded                                            = 0x0540,
  error_invalid_group_attributes                                           = 0x0541,
  error_bad_impersonation_level                                            = 0x0542,
  error_cant_open_anonymous                                                = 0x0543,
  error_bad_validation_class                                               = 0x0544,
  error_bad_token_type                                                     = 0x0545,
  error_no_security_on_object                                              = 0x0546,
  error_cant_access_domain_info                                            = 0x0547,
  error_invalid_server_state                                               = 0x0548,
  error_invalid_domain_state                                               = 0x0549,
  error_invalid_domain_role                                                = 0x054a,
  error_no_such_domain                                                     = 0x054b,
  error_domain_exists                                                      = 0x054c,
  error_domain_limit_exceeded                                              = 0x054d,
  error_internal_db_corruption                                             = 0x054e,
  error_internal_error                                                     = 0x054f,
  error_generic_not_mapped                                                 = 0x0550,
  error_bad_descriptor_format                                              = 0x0551,
  error_not_logon_process                                                  = 0x0552,
  error_logon_session_exists                                               = 0x0553,
  error_no_such_package                                                    = 0x0554,
  error_bad_logon_session_state                                            = 0x0555,
  error_logon_session_collision                                            = 0x0556,
  error_invalid_logon_type                                                 = 0x0557,
  error_cannot_impersonate                                                 = 0x0558,
  error_rxact_invalid_state                                                = 0x0559,
  error_rxact_commit_failure                                               = 0x055a,
  error_special_account                                                    = 0x055b,
  error_special_group                                                      = 0x055c,
  error_special_user                                                       = 0x055d,
  error_members_primary_group                                              = 0x055e,
  error_token_already_in_use                                               = 0x055f,
  error_no_such_alias                                                      = 0x0560,
  error_member_not_in_alias                                                = 0x0561,
  error_member_in_alias                                                    = 0x0562,
  error_alias_exists                                                       = 0x0563,
  error_logon_not_granted                                                  = 0x0564,
  error_too_many_secrets                                                   = 0x0565,
  error_secret_too_long                                                    = 0x0566,
  error_internal_db_error                                                  = 0x0567,
  error_too_many_context_ids                                               = 0x0568,
  error_logon_type_not_granted                                             = 0x0569,
  error_nt_cross_encryption_required                                       = 0x056a,
  error_no_such_member                                                     = 0x056b,
  error_invalid_member                                                     = 0x056c,
  error_too_many_sids                                                      = 0x056d,
  error_lm_cross_encryption_required                                       = 0x056e,
  error_no_inheritance                                                     = 0x056f,
  error_file_corrupt                                                       = 0x0570,
  error_disk_corrupt                                                       = 0x0571,
  error_no_user_session_key                                                = 0x0572,
  error_license_quota_exceeded                                             = 0x0573,
  error_wrong_target_name                                                  = 0x0574,
  error_mutual_auth_failed                                                 = 0x0575,
  error_time_skew                                                          = 0x0576,
  error_current_domain_not_allowed                                         = 0x0577,
  error_invalid_window_handle                                              = 0x0578,
  error_invalid_menu_handle                                                = 0x0579,
  error_invalid_cursor_handle                                              = 0x057a,
  error_invalid_accel_handle                                               = 0x057b,
  error_invalid_hook_handle                                                = 0x057c,
  error_invalid_dwp_handle                                                 = 0x057d,
  error_tlw_with_wschild                                                   = 0x057e,
  error_cannot_find_wnd_class                                              = 0x057f,
  error_window_of_other_thread                                             = 0x0580,
  error_hotkey_already_registered                                          = 0x0581,
  error_class_already_exists                                               = 0x0582,
  error_class_does_not_exist                                               = 0x0583,
  error_class_has_windows                                                  = 0x0584,
  error_invalid_index                                                      = 0x0585,
  error_invalid_icon_handle                                                = 0x0586,
  error_private_dialog_index                                               = 0x0587,
  error_listbox_id_not_found                                               = 0x0588,
  error_no_wildcard_characters                                             = 0x0589,
  error_clipboard_not_open                                                 = 0x058a,
  error_hotkey_not_registered                                              = 0x058b,
  error_window_not_dialog                                                  = 0x058c,
  error_control_id_not_found                                               = 0x058d,
  error_invalid_combobox_message                                           = 0x058e,
  error_window_not_combobox                                                = 0x058f,
  error_invalid_edit_height                                                = 0x0590,
  error_dc_not_found                                                       = 0x0591,
  error_invalid_hook_filter                                                = 0x0592,
  error_invalid_filter_proc                                                = 0x0593,
  error_hook_needs_hmod                                                    = 0x0594,
  error_global_only_hook                                                   = 0x0595,
  error_journal_hook_set                                                   = 0x0596,
  error_hook_not_installed                                                 = 0x0597,
  error_invalid_lb_message                                                 = 0x0598,
  error_setcount_on_bad_lb                                                 = 0x0599,
  error_lb_without_tabstops                                                = 0x059a,
  error_destroy_object_of_other_thread                                     = 0x059b,
  error_child_window_menu                                                  = 0x059c,
  error_no_system_menu                                                     = 0x059d,
  error_invalid_msgbox_style                                               = 0x059e,
  error_invalid_spi_value                                                  = 0x059f,
  error_screen_already_locked                                              = 0x05a0,
  error_hwnds_have_diff_parent                                             = 0x05a1,
  error_not_child_window                                                   = 0x05a2,
  error_invalid_gw_command                                                 = 0x05a3,
  error_invalid_thread_id                                                  = 0x05a4,
  error_non_mdichild_window                                                = 0x05a5,
  error_popup_already_active                                               = 0x05a6,
  error_no_scrollbars                                                      = 0x05a7,
  error_invalid_scrollbar_range                                            = 0x05a8,
  error_invalid_showwin_command                                            = 0x05a9,
  error_no_system_resources                                                = 0x05aa,
  error_nonpaged_system_resources                                          = 0x05ab,
  error_paged_system_resources                                             = 0x05ac,
  error_working_set_quota                                                  = 0x05ad,
  error_pagefile_quota                                                     = 0x05ae,
  error_commitment_limit                                                   = 0x05af,
  error_menu_item_not_found                                                = 0x05b0,
  error_invalid_keyboard_handle                                            = 0x05b1,
  error_hook_type_not_allowed                                              = 0x05b2,
  error_requires_interactive_windowstation                                 = 0x05b3,
  error_timeout                                                            = 0x05b4,
  error_invalid_monitor_handle                                             = 0x05b5,
  error_incorrect_size                                                     = 0x05b6,
  error_symlink_class_disabled                                             = 0x05b7,
  error_symlink_not_supported                                              = 0x05b8,
  error_xml_parse_error                                                    = 0x05b9,
  error_xmldsig_error                                                      = 0x05ba,
  error_restart_application                                                = 0x05bb,
  error_wrong_compartment                                                  = 0x05bc,
  error_authip_failure                                                     = 0x05bd,
  error_no_nvram_resources                                                 = 0x05be,
  error_not_gui_process                                                    = 0x05bf,
  error_eventlog_file_corrupt                                              = 0x05dc,
  error_eventlog_cant_start                                                = 0x05dd,
  error_log_file_full                                                      = 0x05de,
  error_eventlog_file_changed                                              = 0x05df,
  error_invalid_task_name                                                  = 0x060e,
  error_invalid_task_index                                                 = 0x060f,
  error_thread_already_in_task                                             = 0x0610,
  error_install_service_failure                                            = 0x0641,
  error_install_userexit                                                   = 0x0642,
  error_install_failure                                                    = 0x0643,
  error_install_suspend                                                    = 0x0644,
  error_unknown_product                                                    = 0x0645,
  error_unknown_feature                                                    = 0x0646,
  error_unknown_component                                                  = 0x0647,
  error_unknown_property                                                   = 0x0648,
  error_invalid_handle_state                                               = 0x0649,
  error_bad_configuration                                                  = 0x064a,
  error_index_absent                                                       = 0x064b,
  error_install_source_absent                                              = 0x064c,
  error_install_package_version                                            = 0x064d,
  error_product_uninstalled                                                = 0x064e,
  error_bad_query_syntax                                                   = 0x064f,
  error_invalid_field                                                      = 0x0650,
  error_device_removed                                                     = 0x0651,
  error_install_already_running                                            = 0x0652,
  error_install_package_open_failed                                        = 0x0653,
  error_install_package_invalid                                            = 0x0654,
  error_install_ui_failure                                                 = 0x0655,
  error_install_log_failure                                                = 0x0656,
  error_install_language_unsupported                                       = 0x0657,
  error_install_transform_failure                                          = 0x0658,
  error_install_package_rejected                                           = 0x0659,
  error_function_not_called                                                = 0x065a,
  error_function_failed                                                    = 0x065b,
  error_invalid_table                                                      = 0x065c,
  error_datatype_mismatch                                                  = 0x065d,
  error_unsupported_type                                                   = 0x065e,
  error_create_failed                                                      = 0x065f,
  error_install_temp_unwritable                                            = 0x0660,
  error_install_platform_unsupported                                       = 0x0661,
  error_install_notused                                                    = 0x0662,
  error_patch_package_open_failed                                          = 0x0663,
  error_patch_package_invalid                                              = 0x0664,
  error_patch_package_unsupported                                          = 0x0665,
  error_product_version                                                    = 0x0666,
  error_invalid_command_line                                               = 0x0667,
  error_install_remote_disallowed                                          = 0x0668,
  error_success_reboot_initiated                                           = 0x0669,
  error_patch_target_not_found                                             = 0x066a,
  error_patch_package_rejected                                             = 0x066b,
  error_install_transform_rejected                                         = 0x066c,
  error_install_remote_prohibited                                          = 0x066d,
  error_patch_removal_unsupported                                          = 0x066e,
  error_unknown_patch                                                      = 0x066f,
  error_patch_no_sequence                                                  = 0x0670,
  error_patch_removal_disallowed                                           = 0x0671,
  error_invalid_patch_xml                                                  = 0x0672,
  error_patch_managed_advertised_product                                   = 0x0673,
  error_install_service_safeboot                                           = 0x0674,
  error_fail_fast_exception                                                = 0x0675,
  error_install_rejected                                                   = 0x0676,
  rpc_s_invalid_string_binding                                             = 0x06a4,
  rpc_s_wrong_kind_of_binding                                              = 0x06a5,
  rpc_s_invalid_binding                                                    = 0x06a6,
  rpc_s_protseq_not_supported                                              = 0x06a7,
  rpc_s_invalid_rpc_protseq                                                = 0x06a8,
  rpc_s_invalid_string_uuid                                                = 0x06a9,
  rpc_s_invalid_endpoint_format                                            = 0x06aa,
  rpc_s_invalid_net_addr                                                   = 0x06ab,
  rpc_s_no_endpoint_found                                                  = 0x06ac,
  rpc_s_invalid_timeout                                                    = 0x06ad,
  rpc_s_object_not_found                                                   = 0x06ae,
  rpc_s_already_registered                                                 = 0x06af,
  rpc_s_type_already_registered                                            = 0x06b0,
  rpc_s_already_listening                                                  = 0x06b1,
  rpc_s_no_protseqs_registered                                             = 0x06b2,
  rpc_s_not_listening                                                      = 0x06b3,
  rpc_s_unknown_mgr_type                                                   = 0x06b4,
  rpc_s_unknown_if                                                         = 0x06b5,
  rpc_s_no_bindings                                                        = 0x06b6,
  rpc_s_no_protseqs                                                        = 0x06b7,
  rpc_s_cant_create_endpoint                                               = 0x06b8,
  rpc_s_out_of_resources                                                   = 0x06b9,
  rpc_s_server_unavailable                                                 = 0x06ba,
  rpc_s_server_too_busy                                                    = 0x06bb,
  rpc_s_invalid_network_options                                            = 0x06bc,
  rpc_s_no_call_active                                                     = 0x06bd,
  rpc_s_call_failed                                                        = 0x06be,
  rpc_s_call_failed_dne                                                    = 0x06bf,
  rpc_s_protocol_error                                                     = 0x06c0,
  rpc_s_proxy_access_denied                                                = 0x06c1,
  rpc_s_unsupported_trans_syn                                              = 0x06c2,
  rpc_s_unsupported_type                                                   = 0x06c4,
  rpc_s_invalid_tag                                                        = 0x06c5,
  rpc_s_invalid_bound                                                      = 0x06c6,
  rpc_s_no_entry_name                                                      = 0x06c7,
  rpc_s_invalid_name_syntax                                                = 0x06c8,
  rpc_s_unsupported_name_syntax                                            = 0x06c9,
  rpc_s_uuid_no_address                                                    = 0x06cb,
  rpc_s_duplicate_endpoint                                                 = 0x06cc,
  rpc_s_unknown_authn_type                                                 = 0x06cd,
  rpc_s_max_calls_too_small                                                = 0x06ce,
  rpc_s_string_too_long                                                    = 0x06cf,
  rpc_s_protseq_not_found                                                  = 0x06d0,
  rpc_s_procnum_out_of_range                                               = 0x06d1,
  rpc_s_binding_has_no_auth                                                = 0x06d2,
  rpc_s_unknown_authn_service                                              = 0x06d3,
  rpc_s_unknown_authn_level                                                = 0x06d4,
  rpc_s_invalid_auth_identity                                              = 0x06d5,
  rpc_s_unknown_authz_service                                              = 0x06d6,
  ept_s_invalid_entry                                                      = 0x06d7,
  ept_s_cant_perform_op                                                    = 0x06d8,
  ept_s_not_registered                                                     = 0x06d9,
  rpc_s_nothing_to_export                                                  = 0x06da,
  rpc_s_incomplete_name                                                    = 0x06db,
  rpc_s_invalid_vers_option                                                = 0x06dc,
  rpc_s_no_more_members                                                    = 0x06dd,
  rpc_s_not_all_objs_unexported                                            = 0x06de,
  rpc_s_interface_not_found                                                = 0x06df,
  rpc_s_entry_already_exists                                               = 0x06e0,
  rpc_s_entry_not_found                                                    = 0x06e1,
  rpc_s_name_service_unavailable                                           = 0x06e2,
  rpc_s_invalid_naf_id                                                     = 0x06e3,
  rpc_s_cannot_support                                                     = 0x06e4,
  rpc_s_no_context_available                                               = 0x06e5,
  rpc_s_internal_error                                                     = 0x06e6,
  rpc_s_zero_divide                                                        = 0x06e7,
  rpc_s_address_error                                                      = 0x06e8,
  rpc_s_fp_div_zero                                                        = 0x06e9,
  rpc_s_fp_underflow                                                       = 0x06ea,
  rpc_s_fp_overflow                                                        = 0x06eb,
  rpc_x_no_more_entries                                                    = 0x06ec,
  rpc_x_ss_char_trans_open_fail                                            = 0x06ed,
  rpc_x_ss_char_trans_short_file                                           = 0x06ee,
  rpc_x_ss_in_null_context                                                 = 0x06ef,
  rpc_x_ss_context_damaged                                                 = 0x06f1,
  rpc_x_ss_handles_mismatch                                                = 0x06f2,
  rpc_x_ss_cannot_get_call_handle                                          = 0x06f3,
  rpc_x_null_ref_pointer                                                   = 0x06f4,
  rpc_x_enum_value_out_of_range                                            = 0x06f5,
  rpc_x_byte_count_too_small                                               = 0x06f6,
  rpc_x_bad_stub_data                                                      = 0x06f7,
  error_invalid_user_buffer                                                = 0x06f8,
  error_unrecognized_media                                                 = 0x06f9,
  error_no_trust_lsa_secret                                                = 0x06fa,
  error_no_trust_sam_account                                               = 0x06fb,
  error_trusted_domain_failure                                             = 0x06fc,
  error_trusted_relationship_failure                                       = 0x06fd,
  error_trust_failure                                                      = 0x06fe,
  rpc_s_call_in_progress                                                   = 0x06ff,
  error_netlogon_not_started                                               = 0x0700,
  error_account_expired                                                    = 0x0701,
  error_redirector_has_open_handles                                        = 0x0702,
  error_printer_driver_already_installed                                   = 0x0703,
  error_unknown_port                                                       = 0x0704,
  error_unknown_printer_driver                                             = 0x0705,
  error_unknown_printprocessor                                             = 0x0706,
  error_invalid_separator_file                                             = 0x0707,
  error_invalid_priority                                                   = 0x0708,
  error_invalid_printer_name                                               = 0x0709,
  error_printer_already_exists                                             = 0x070a,
  error_invalid_printer_command                                            = 0x070b,
  error_invalid_datatype                                                   = 0x070c,
  error_invalid_environment                                                = 0x070d,
  rpc_s_no_more_bindings                                                   = 0x070e,
  error_nologon_interdomain_trust_account                                  = 0x070f,
  error_nologon_workstation_trust_account                                  = 0x0710,
  error_nologon_server_trust_account                                       = 0x0711,
  error_domain_trust_inconsistent                                          = 0x0712,
  error_server_has_open_handles                                            = 0x0713,
  error_resource_data_not_found                                            = 0x0714,
  error_resource_type_not_found                                            = 0x0715,
  error_resource_name_not_found                                            = 0x0716,
  error_resource_lang_not_found                                            = 0x0717,
  error_not_enough_quota                                                   = 0x0718,
  rpc_s_no_interfaces                                                      = 0x0719,
  rpc_s_call_cancelled                                                     = 0x071a,
  rpc_s_binding_incomplete                                                 = 0x071b,
  rpc_s_comm_failure                                                       = 0x071c,
  rpc_s_unsupported_authn_level                                            = 0x071d,
  rpc_s_no_princ_name                                                      = 0x071e,
  rpc_s_not_rpc_error                                                      = 0x071f,
  rpc_s_uuid_local_only                                                    = 0x0720,
  rpc_s_sec_pkg_error                                                      = 0x0721,
  rpc_s_not_cancelled                                                      = 0x0722,
  rpc_x_invalid_es_action                                                  = 0x0723,
  rpc_x_wrong_es_version                                                   = 0x0724,
  rpc_x_wrong_stub_version                                                 = 0x0725,
  rpc_x_invalid_pipe_object                                                = 0x0726,
  rpc_x_wrong_pipe_order                                                   = 0x0727,
  rpc_x_wrong_pipe_version                                                 = 0x0728,
  rpc_s_cookie_auth_failed                                                 = 0x0729,
  rpc_s_group_member_not_found                                             = 0x076a,
  ept_s_cant_create                                                        = 0x076b,
  rpc_s_invalid_object                                                     = 0x076c,
  error_invalid_time                                                       = 0x076d,
  error_invalid_form_name                                                  = 0x076e,
  error_invalid_form_size                                                  = 0x076f,
  error_already_waiting                                                    = 0x0770,
  error_printer_deleted                                                    = 0x0771,
  error_invalid_printer_state                                              = 0x0772,
  error_password_must_change                                               = 0x0773,
  error_domain_controller_not_found                                        = 0x0774,
  error_account_locked_out                                                 = 0x0775,
  or_invalid_oxid                                                          = 0x0776,
  or_invalid_oid                                                           = 0x0777,
  or_invalid_set                                                           = 0x0778,
  rpc_s_send_incomplete                                                    = 0x0779,
  rpc_s_invalid_async_handle                                               = 0x077a,
  rpc_s_invalid_async_call                                                 = 0x077b,
  rpc_x_pipe_closed                                                        = 0x077c,
  rpc_x_pipe_discipline_error                                              = 0x077d,
  rpc_x_pipe_empty                                                         = 0x077e,
  error_no_sitename                                                        = 0x077f,
  error_cant_access_file                                                   = 0x0780,
  error_cant_resolve_filename                                              = 0x0781,
  rpc_s_entry_type_mismatch                                                = 0x0782,
  rpc_s_not_all_objs_exported                                              = 0x0783,
  rpc_s_interface_not_exported                                             = 0x0784,
  rpc_s_profile_not_added                                                  = 0x0785,
  rpc_s_prf_elt_not_added                                                  = 0x0786,
  rpc_s_prf_elt_not_removed                                                = 0x0787,
  rpc_s_grp_elt_not_added                                                  = 0x0788,
  rpc_s_grp_elt_not_removed                                                = 0x0789,
  error_km_driver_blocked                                                  = 0x078a,
  error_context_expired                                                    = 0x078b,
  error_per_user_trust_quota_exceeded                                      = 0x078c,
  error_all_user_trust_quota_exceeded                                      = 0x078d,
  error_user_delete_trust_quota_exceeded                                   = 0x078e,
  error_authentication_firewall_failed                                     = 0x078f,
  error_remote_print_connections_blocked                                   = 0x0790,
  error_ntlm_blocked                                                       = 0x0791,
  error_password_change_required                                           = 0x0792,
  error_invalid_pixel_format                                               = 0x07d0,
  error_bad_driver                                                         = 0x07d1,
  error_invalid_window_style                                               = 0x07d2,
  error_metafile_not_supported                                             = 0x07d3,
  error_transform_not_supported                                            = 0x07d4,
  error_clipping_not_supported                                             = 0x07d5,
  error_invalid_cmm                                                        = 0x07da,
  error_invalid_profile                                                    = 0x07db,
  error_tag_not_found                                                      = 0x07dc,
  error_tag_not_present                                                    = 0x07dd,
  error_duplicate_tag                                                      = 0x07de,
  error_profile_not_associated_with_device                                 = 0x07df,
  error_profile_not_found                                                  = 0x07e0,
  error_invalid_colorspace                                                 = 0x07e1,
  error_icm_not_enabled                                                    = 0x07e2,
  error_deleting_icm_xform                                                 = 0x07e3,
  error_invalid_transform                                                  = 0x07e4,
  error_colorspace_mismatch                                                = 0x07e5,
  error_invalid_colorindex                                                 = 0x07e6,
  error_profile_does_not_match_device                                      = 0x07e7,
  error_connected_other_password                                           = 0x083c,
  error_connected_other_password_default                                   = 0x083d,
  error_bad_username                                                       = 0x089a,
  error_not_connected                                                      = 0x08ca,
  error_open_files                                                         = 0x0961,
  error_active_connections                                                 = 0x0962,
  error_device_in_use                                                      = 0x0964,
  error_unknown_print_monitor                                              = 0x0bb8,
  error_printer_driver_in_use                                              = 0x0bb9,
  error_spool_file_not_found                                               = 0x0bba,
  error_spl_no_startdoc                                                    = 0x0bbb,
  error_spl_no_addjob                                                      = 0x0bbc,
  error_print_processor_already_installed                                  = 0x0bbd,
  error_print_monitor_already_installed                                    = 0x0bbe,
  error_invalid_print_monitor                                              = 0x0bbf,
  error_print_monitor_in_use                                               = 0x0bc0,
  error_printer_has_jobs_queued                                            = 0x0bc1,
  error_success_reboot_required                                            = 0x0bc2,
  error_success_restart_required                                           = 0x0bc3,
  error_printer_not_found                                                  = 0x0bc4,
  error_printer_driver_warned                                              = 0x0bc5,
  error_printer_driver_blocked                                             = 0x0bc6,
  error_printer_driver_package_in_use                                      = 0x0bc7,
  error_core_driver_package_not_found                                      = 0x0bc8,
  error_fail_reboot_required                                               = 0x0bc9,
  error_fail_reboot_initiated                                              = 0x0bca,
  error_printer_driver_download_needed                                     = 0x0bcb,
  error_print_job_restart_required                                         = 0x0bcc,
  error_invalid_printer_driver_manifest                                    = 0x0bcd,
  error_printer_not_shareable                                              = 0x0bce,
  error_request_paused                                                     = 0x0bea,
  error_io_reissue_as_cached                                               = 0x0f6e,
  error_wins_internal                                                      = 0x0fa0,
  error_can_not_del_local_wins                                             = 0x0fa1,
  error_static_init                                                        = 0x0fa2,
  error_inc_backup                                                         = 0x0fa3,
  error_full_backup                                                        = 0x0fa4,
  error_rec_non_existent                                                   = 0x0fa5,
  error_rpl_not_allowed                                                    = 0x0fa6,
  peerdist_error_contentinfo_version_unsupported                           = 0x0fd2,
  peerdist_error_cannot_parse_contentinfo                                  = 0x0fd3,
  peerdist_error_missing_data                                              = 0x0fd4,
  peerdist_error_no_more                                                   = 0x0fd5,
  peerdist_error_not_initialized                                           = 0x0fd6,
  peerdist_error_already_initialized                                       = 0x0fd7,
  peerdist_error_shutdown_in_progress                                      = 0x0fd8,
  peerdist_error_invalidated                                               = 0x0fd9,
  peerdist_error_already_exists                                            = 0x0fda,
  peerdist_error_operation_notfound                                        = 0x0fdb,
  peerdist_error_already_completed                                         = 0x0fdc,
  peerdist_error_out_of_bounds                                             = 0x0fdd,
  peerdist_error_version_unsupported                                       = 0x0fde,
  peerdist_error_invalid_configuration                                     = 0x0fdf,
  peerdist_error_not_licensed                                              = 0x0fe0,
  peerdist_error_service_unavailable                                       = 0x0fe1,
  peerdist_error_trust_failure                                             = 0x0fe2,
  error_dhcp_address_conflict                                              = 0x1004,
  error_wmi_guid_not_found                                                 = 0x1068,
  error_wmi_instance_not_found                                             = 0x1069,
  error_wmi_itemid_not_found                                               = 0x106a,
  error_wmi_try_again                                                      = 0x106b,
  error_wmi_dp_not_found                                                   = 0x106c,
  error_wmi_unresolved_instance_ref                                        = 0x106d,
  error_wmi_already_enabled                                                = 0x106e,
  error_wmi_guid_disconnected                                              = 0x106f,
  error_wmi_server_unavailable                                             = 0x1070,
  error_wmi_dp_failed                                                      = 0x1071,
  error_wmi_invalid_mof                                                    = 0x1072,
  error_wmi_invalid_reginfo                                                = 0x1073,
  error_wmi_already_disabled                                               = 0x1074,
  error_wmi_read_only                                                      = 0x1075,
  error_wmi_set_failure                                                    = 0x1076,
  error_not_appcontainer                                                   = 0x109a,
  error_appcontainer_required                                              = 0x109b,
  error_not_supported_in_appcontainer                                      = 0x109c,
  error_invalid_package_sid_length                                         = 0x109d,
  error_invalid_media                                                      = 0x10cc,
  error_invalid_library                                                    = 0x10cd,
  error_invalid_media_pool                                                 = 0x10ce,
  error_drive_media_mismatch                                               = 0x10cf,
  error_media_offline                                                      = 0x10d0,
  error_library_offline                                                    = 0x10d1,
  error_empty                                                              = 0x10d2,
  error_not_empty                                                          = 0x10d3,
  error_media_unavailable                                                  = 0x10d4,
  error_resource_disabled                                                  = 0x10d5,
  error_invalid_cleaner                                                    = 0x10d6,
  error_unable_to_clean                                                    = 0x10d7,
  error_object_not_found                                                   = 0x10d8,
  error_database_failure                                                   = 0x10d9,
  error_database_full                                                      = 0x10da,
  error_media_incompatible                                                 = 0x10db,
  error_resource_not_present                                               = 0x10dc,
  error_invalid_operation                                                  = 0x10dd,
  error_media_not_available                                                = 0x10de,
  error_device_not_available                                               = 0x10df,
  error_request_refused                                                    = 0x10e0,
  error_invalid_drive_object                                               = 0x10e1,
  error_library_full                                                       = 0x10e2,
  error_medium_not_accessible                                              = 0x10e3,
  error_unable_to_load_medium                                              = 0x10e4,
  error_unable_to_inventory_drive                                          = 0x10e5,
  error_unable_to_inventory_slot                                           = 0x10e6,
  error_unable_to_inventory_transport                                      = 0x10e7,
  error_transport_full                                                     = 0x10e8,
  error_controlling_ieport                                                 = 0x10e9,
  error_unable_to_eject_mounted_media                                      = 0x10ea,
  error_cleaner_slot_set                                                   = 0x10eb,
  error_cleaner_slot_not_set                                               = 0x10ec,
  error_cleaner_cartridge_spent                                            = 0x10ed,
  error_unexpected_omid                                                    = 0x10ee,
  error_cant_delete_last_item                                              = 0x10ef,
  error_message_exceeds_max_size                                           = 0x10f0,
  error_volume_contains_sys_files                                          = 0x10f1,
  error_indigenous_type                                                    = 0x10f2,
  error_no_supporting_drives                                               = 0x10f3,
  error_cleaner_cartridge_installed                                        = 0x10f4,
  error_ieport_full                                                        = 0x10f5,
  error_file_offline                                                       = 0x10fe,
  error_remote_storage_not_active                                          = 0x10ff,
  error_remote_storage_media_error                                         = 0x1100,
  error_not_a_reparse_point                                                = 0x1126,
  error_reparse_attribute_conflict                                         = 0x1127,
  error_invalid_reparse_data                                               = 0x1128,
  error_reparse_tag_invalid                                                = 0x1129,
  error_reparse_tag_mismatch                                               = 0x112a,
  error_app_data_not_found                                                 = 0x1130,
  error_app_data_expired                                                   = 0x1131,
  error_app_data_corrupt                                                   = 0x1132,
  error_app_data_limit_exceeded                                            = 0x1133,
  error_app_data_reboot_required                                           = 0x1134,
  error_secureboot_rollback_detected                                       = 0x1144,
  error_secureboot_policy_violation                                        = 0x1145,
  error_secureboot_invalid_policy                                          = 0x1146,
  error_secureboot_policy_publisher_not_found                              = 0x1147,
  error_secureboot_policy_not_signed                                       = 0x1148,
  error_secureboot_not_enabled                                             = 0x1149,
  error_secureboot_file_replaced                                           = 0x114a,
  error_offload_read_flt_not_supported                                     = 0x1158,
  error_offload_write_flt_not_supported                                    = 0x1159,
  error_offload_read_file_not_supported                                    = 0x115a,
  error_offload_write_file_not_supported                                   = 0x115b,
  error_volume_not_sis_enabled                                             = 0x1194,
  error_dependent_resource_exists                                          = 0x1389,
  error_dependency_not_found                                               = 0x138a,
  error_dependency_already_exists                                          = 0x138b,
  error_resource_not_online                                                = 0x138c,
  error_host_node_not_available                                            = 0x138d,
  error_resource_not_available                                             = 0x138e,
  error_resource_not_found                                                 = 0x138f,
  error_shutdown_cluster                                                   = 0x1390,
  error_cant_evict_active_node                                             = 0x1391,
  error_object_already_exists                                              = 0x1392,
  error_object_in_list                                                     = 0x1393,
  error_group_not_available                                                = 0x1394,
  error_group_not_found                                                    = 0x1395,
  error_group_not_online                                                   = 0x1396,
  error_host_node_not_resource_owner                                       = 0x1397,
  error_host_node_not_group_owner                                          = 0x1398,
  error_resmon_create_failed                                               = 0x1399,
  error_resmon_online_failed                                               = 0x139a,
  error_resource_online                                                    = 0x139b,
  error_quorum_resource                                                    = 0x139c,
  error_not_quorum_capable                                                 = 0x139d,
  error_cluster_shutting_down                                              = 0x139e,
  error_invalid_state                                                      = 0x139f,
  error_resource_properties_stored                                         = 0x13a0,
  error_not_quorum_class                                                   = 0x13a1,
  error_core_resource                                                      = 0x13a2,
  error_quorum_resource_online_failed                                      = 0x13a3,
  error_quorumlog_open_failed                                              = 0x13a4,
  error_clusterlog_corrupt                                                 = 0x13a5,
  error_clusterlog_record_exceeds_maxsize                                  = 0x13a6,
  error_clusterlog_exceeds_maxsize                                         = 0x13a7,
  error_clusterlog_chkpoint_not_found                                      = 0x13a8,
  error_clusterlog_not_enough_space                                        = 0x13a9,
  error_quorum_owner_alive                                                 = 0x13aa,
  error_network_not_available                                              = 0x13ab,
  error_node_not_available                                                 = 0x13ac,
  error_all_nodes_not_available                                            = 0x13ad,
  error_resource_failed                                                    = 0x13ae,
  error_cluster_invalid_node                                               = 0x13af,
  error_cluster_node_exists                                                = 0x13b0,
  error_cluster_join_in_progress                                           = 0x13b1,
  error_cluster_node_not_found                                             = 0x13b2,
  error_cluster_local_node_not_found                                       = 0x13b3,
  error_cluster_network_exists                                             = 0x13b4,
  error_cluster_network_not_found                                          = 0x13b5,
  error_cluster_netinterface_exists                                        = 0x13b6,
  error_cluster_netinterface_not_found                                     = 0x13b7,
  error_cluster_invalid_request                                            = 0x13b8,
  error_cluster_invalid_network_provider                                   = 0x13b9,
  error_cluster_node_down                                                  = 0x13ba,
  error_cluster_node_unreachable                                           = 0x13bb,
  error_cluster_node_not_member                                            = 0x13bc,
  error_cluster_join_not_in_progress                                       = 0x13bd,
  error_cluster_invalid_network                                            = 0x13be,
  error_cluster_node_up                                                    = 0x13c0,
  error_cluster_ipaddr_in_use                                              = 0x13c1,
  error_cluster_node_not_paused                                            = 0x13c2,
  error_cluster_no_security_context                                        = 0x13c3,
  error_cluster_network_not_internal                                       = 0x13c4,
  error_cluster_node_already_up                                            = 0x13c5,
  error_cluster_node_already_down                                          = 0x13c6,
  error_cluster_network_already_online                                     = 0x13c7,
  error_cluster_network_already_offline                                    = 0x13c8,
  error_cluster_node_already_member                                        = 0x13c9,
  error_cluster_last_internal_network                                      = 0x13ca,
  error_cluster_network_has_dependents                                     = 0x13cb,
  error_invalid_operation_on_quorum                                        = 0x13cc,
  error_dependency_not_allowed                                             = 0x13cd,
  error_cluster_node_paused                                                = 0x13ce,
  error_node_cant_host_resource                                            = 0x13cf,
  error_cluster_node_not_ready                                             = 0x13d0,
  error_cluster_node_shutting_down                                         = 0x13d1,
  error_cluster_join_aborted                                               = 0x13d2,
  error_cluster_incompatible_versions                                      = 0x13d3,
  error_cluster_maxnum_of_resources_exceeded                               = 0x13d4,
  error_cluster_system_config_changed                                      = 0x13d5,
  error_cluster_resource_type_not_found                                    = 0x13d6,
  error_cluster_restype_not_supported                                      = 0x13d7,
  error_cluster_resname_not_found                                          = 0x13d8,
  error_cluster_no_rpc_packages_registered                                 = 0x13d9,
  error_cluster_owner_not_in_preflist                                      = 0x13da,
  error_cluster_database_seqmismatch                                       = 0x13db,
  error_resmon_invalid_state                                               = 0x13dc,
  error_cluster_gum_not_locker                                             = 0x13dd,
  error_quorum_disk_not_found                                              = 0x13de,
  error_database_backup_corrupt                                            = 0x13df,
  error_cluster_node_already_has_dfs_root                                  = 0x13e0,
  error_resource_property_unchangeable                                     = 0x13e1,
  error_cluster_membership_invalid_state                                   = 0x1702,
  error_cluster_quorumlog_not_found                                        = 0x1703,
  error_cluster_membership_halt                                            = 0x1704,
  error_cluster_instance_id_mismatch                                       = 0x1705,
  error_cluster_network_not_found_for_ip                                   = 0x1706,
  error_cluster_property_data_type_mismatch                                = 0x1707,
  error_cluster_evict_without_cleanup                                      = 0x1708,
  error_cluster_parameter_mismatch                                         = 0x1709,
  error_node_cannot_be_clustered                                           = 0x170a,
  error_cluster_wrong_os_version                                           = 0x170b,
  error_cluster_cant_create_dup_cluster_name                               = 0x170c,
  error_cluscfg_already_committed                                          = 0x170d,
  error_cluscfg_rollback_failed                                            = 0x170e,
  error_cluscfg_system_disk_drive_letter_conflict                          = 0x170f,
  error_cluster_old_version                                                = 0x1710,
  error_cluster_mismatched_computer_acct_name                              = 0x1711,
  error_cluster_no_net_adapters                                            = 0x1712,
  error_cluster_poisoned                                                   = 0x1713,
  error_cluster_group_moving                                               = 0x1714,
  error_cluster_resource_type_busy                                         = 0x1715,
  error_resource_call_timed_out                                            = 0x1716,
  error_invalid_cluster_ipv6_address                                       = 0x1717,
  error_cluster_internal_invalid_function                                  = 0x1718,
  error_cluster_parameter_out_of_bounds                                    = 0x1719,
  error_cluster_partial_send                                               = 0x171a,
  error_cluster_registry_invalid_function                                  = 0x171b,
  error_cluster_invalid_string_termination                                 = 0x171c,
  error_cluster_invalid_string_format                                      = 0x171d,
  error_cluster_database_transaction_in_progress                           = 0x171e,
  error_cluster_database_transaction_not_in_progress                       = 0x171f,
  error_cluster_null_data                                                  = 0x1720,
  error_cluster_partial_read                                               = 0x1721,
  error_cluster_partial_write                                              = 0x1722,
  error_cluster_cant_deserialize_data                                      = 0x1723,
  error_dependent_resource_property_conflict                               = 0x1724,
  error_cluster_no_quorum                                                  = 0x1725,
  error_cluster_invalid_ipv6_network                                       = 0x1726,
  error_cluster_invalid_ipv6_tunnel_network                                = 0x1727,
  error_quorum_not_allowed_in_this_group                                   = 0x1728,
  error_dependency_tree_too_complex                                        = 0x1729,
  error_exception_in_resource_call                                         = 0x172a,
  error_cluster_rhs_failed_initialization                                  = 0x172b,
  error_cluster_not_installed                                              = 0x172c,
  error_cluster_resources_must_be_online_on_the_same_node                  = 0x172d,
  error_cluster_max_nodes_in_cluster                                       = 0x172e,
  error_cluster_too_many_nodes                                             = 0x172f,
  error_cluster_object_already_used                                        = 0x1730,
  error_noncore_groups_found                                               = 0x1731,
  error_file_share_resource_conflict                                       = 0x1732,
  error_cluster_evict_invalid_request                                      = 0x1733,
  error_cluster_singleton_resource                                         = 0x1734,
  error_cluster_group_singleton_resource                                   = 0x1735,
  error_cluster_resource_provider_failed                                   = 0x1736,
  error_cluster_resource_configuration_error                               = 0x1737,
  error_cluster_group_busy                                                 = 0x1738,
  error_cluster_not_shared_volume                                          = 0x1739,
  error_cluster_invalid_security_descriptor                                = 0x173a,
  error_cluster_shared_volumes_in_use                                      = 0x173b,
  error_cluster_use_shared_volumes_api                                     = 0x173c,
  error_cluster_backup_in_progress                                         = 0x173d,
  error_non_csv_path                                                       = 0x173e,
  error_csv_volume_not_local                                               = 0x173f,
  error_cluster_watchdog_terminating                                       = 0x1740,
  error_cluster_resource_vetoed_move_incompatible_nodes                    = 0x1741,
  error_cluster_invalid_node_weight                                        = 0x1742,
  error_cluster_resource_vetoed_call                                       = 0x1743,
  error_resmon_system_resources_lacking                                    = 0x1744,
  error_cluster_resource_vetoed_move_not_enough_resources_on_destination   = 0x1745,
  error_cluster_resource_vetoed_move_not_enough_resources_on_source        = 0x1746,
  error_cluster_group_queued                                               = 0x1747,
  error_cluster_resource_locked_status                                     = 0x1748,
  error_cluster_shared_volume_failover_not_allowed                         = 0x1749,
  error_cluster_node_drain_in_progress                                     = 0x174a,
  error_cluster_disk_not_connected                                         = 0x174b,
  error_disk_not_csv_capable                                               = 0x174c,
  error_resource_not_in_available_storage                                  = 0x174d,
  error_cluster_shared_volume_redirected                                   = 0x174e,
  error_cluster_shared_volume_not_redirected                               = 0x174f,
  error_cluster_cannot_return_properties                                   = 0x1750,
  error_cluster_resource_contains_unsupported_diff_area_for_shared_volumes = 0x1751,
  error_cluster_resource_is_in_maintenance_mode                            = 0x1752,
  error_cluster_affinity_conflict                                          = 0x1753,
  error_cluster_resource_is_replica_virtual_machine                        = 0x1754,
   error_encryption_failed                                                 = 0x1770,
  error_decryption_failed                                                  = 0x1771,
  error_file_encrypted                                                     = 0x1772,
  error_no_recovery_policy                                                 = 0x1773,
  error_no_efs                                                             = 0x1774,
  error_wrong_efs                                                          = 0x1775,
  error_no_user_keys                                                       = 0x1776,
  error_file_not_encrypted                                                 = 0x1777,
  error_not_export_format                                                  = 0x1778,
  error_file_read_only                                                     = 0x1779,
  error_dir_efs_disallowed                                                 = 0x177a,
  error_efs_server_not_trusted                                             = 0x177b,
  error_bad_recovery_policy                                                = 0x177c,
  error_efs_alg_blob_too_big                                               = 0x177d,
  error_volume_not_support_efs                                             = 0x177e,
  error_efs_disabled                                                       = 0x177f,
  error_efs_version_not_support                                            = 0x1780,
  error_cs_encryption_invalid_server_response                              = 0x1781,
  error_cs_encryption_unsupported_server                                   = 0x1782,
  error_cs_encryption_existing_encrypted_file                              = 0x1783,
  error_cs_encryption_new_encrypted_file                                   = 0x1784,
  error_cs_encryption_file_not_cse                                         = 0x1785,
  error_encryption_policy_denies_operation                                 = 0x1786,
  error_no_browser_servers_found                                           = 0x17e6,
  sched_e_service_not_localsystem                                          = 0x1838,
  error_log_sector_invalid                                                 = 0x19c8,
  error_log_sector_parity_invalid                                          = 0x19c9,
  error_log_sector_remapped                                                = 0x19ca,
  error_log_block_incomplete                                               = 0x19cb,
  error_log_invalid_range                                                  = 0x19cc,
  error_log_blocks_exhausted                                               = 0x19cd,
  error_log_read_context_invalid                                           = 0x19ce,
  error_log_restart_invalid                                                = 0x19cf,
  error_log_block_version                                                  = 0x19d0,
  error_log_block_invalid                                                  = 0x19d1,
  error_log_read_mode_invalid                                              = 0x19d2,
  error_log_no_restart                                                     = 0x19d3,
  error_log_metadata_corrupt                                               = 0x19d4,
  error_log_metadata_invalid                                               = 0x19d5,
  error_log_metadata_inconsistent                                          = 0x19d6,
  error_log_reservation_invalid                                            = 0x19d7,
  error_log_cant_delete                                                    = 0x19d8,
  error_log_container_limit_exceeded                                       = 0x19d9,
  error_log_start_of_log                                                   = 0x19da,
  error_log_policy_already_installed                                       = 0x19db,
  error_log_policy_not_installed                                           = 0x19dc,
  error_log_policy_invalid                                                 = 0x19dd,
  error_log_policy_conflict                                                = 0x19de,
  error_log_pinned_archive_tail                                            = 0x19df,
  error_log_record_nonexistent                                             = 0x19e0,
  error_log_records_reserved_invalid                                       = 0x19e1,
  error_log_space_reserved_invalid                                         = 0x19e2,
  error_log_tail_invalid                                                   = 0x19e3,
  error_log_full                                                           = 0x19e4,
  error_could_not_resize_log                                               = 0x19e5,
  error_log_multiplexed                                                    = 0x19e6,
  error_log_dedicated                                                      = 0x19e7,
  error_log_archive_not_in_progress                                        = 0x19e8,
  error_log_archive_in_progress                                            = 0x19e9,
  error_log_ephemeral                                                      = 0x19ea,
  error_log_not_enough_containers                                          = 0x19eb,
  error_log_client_already_registered                                      = 0x19ec,
  error_log_client_not_registered                                          = 0x19ed,
  error_log_full_handler_in_progress                                       = 0x19ee,
  error_log_container_read_failed                                          = 0x19ef,
  error_log_container_write_failed                                         = 0x19f0,
  error_log_container_open_failed                                          = 0x19f1,
  error_log_container_state_invalid                                        = 0x19f2,
  error_log_state_invalid                                                  = 0x19f3,
  error_log_pinned                                                         = 0x19f4,
  error_log_metadata_flush_failed                                          = 0x19f5,
  error_log_inconsistent_security                                          = 0x19f6,
  error_log_appended_flush_failed                                          = 0x19f7,
  error_log_pinned_reservation                                             = 0x19f8,
  error_invalid_transaction                                                = 0x1a2c,
  error_transaction_not_active                                             = 0x1a2d,
  error_transaction_request_not_valid                                      = 0x1a2e,
  error_transaction_not_requested                                          = 0x1a2f,
  error_transaction_already_aborted                                        = 0x1a30,
  error_transaction_already_committed                                      = 0x1a31,
  error_tm_initialization_failed                                           = 0x1a32,
  error_resourcemanager_read_only                                          = 0x1a33,
  error_transaction_not_joined                                             = 0x1a34,
  error_transaction_superior_exists                                        = 0x1a35,
  error_crm_protocol_already_exists                                        = 0x1a36,
  error_transaction_propagation_failed                                     = 0x1a37,
  error_crm_protocol_not_found                                             = 0x1a38,
  error_transaction_invalid_marshall_buffer                                = 0x1a39,
  error_current_transaction_not_valid                                      = 0x1a3a,
  error_transaction_not_found                                              = 0x1a3b,
  error_resourcemanager_not_found                                          = 0x1a3c,
  error_enlistment_not_found                                               = 0x1a3d,
  error_transactionmanager_not_found                                       = 0x1a3e,
  error_transactionmanager_not_online                                      = 0x1a3f,
  error_transactionmanager_recovery_name_collision                         = 0x1a40,
  error_transaction_not_root                                               = 0x1a41,
  error_transaction_object_expired                                         = 0x1a42,
  error_transaction_response_not_enlisted                                  = 0x1a43,
  error_transaction_record_too_long                                        = 0x1a44,
  error_implicit_transaction_not_supported                                 = 0x1a45,
  error_transaction_integrity_violated                                     = 0x1a46,
  error_transactionmanager_identity_mismatch                               = 0x1a47,
  error_rm_cannot_be_frozen_for_snapshot                                   = 0x1a48,
  error_transaction_must_writethrough                                      = 0x1a49,
  error_transaction_no_superior                                            = 0x1a4a,
  error_heuristic_damage_possible                                          = 0x1a4b,
  error_transactional_conflict                                             = 0x1a90,
  error_rm_not_active                                                      = 0x1a91,
  error_rm_metadata_corrupt                                                = 0x1a92,
  error_directory_not_rm                                                   = 0x1a93,
  error_transactions_unsupported_remote                                    = 0x1a95,
  error_log_resize_invalid_size                                            = 0x1a96,
  error_object_no_longer_exists                                            = 0x1a97,
  error_stream_miniversion_not_found                                       = 0x1a98,
  error_stream_miniversion_not_valid                                       = 0x1a99,
  error_miniversion_inaccessible_from_specified_transaction                = 0x1a9a,
  error_cant_open_miniversion_with_modify_intent                           = 0x1a9b,
  error_cant_create_more_stream_miniversions                               = 0x1a9c,
  error_remote_file_version_mismatch                                       = 0x1a9e,
  error_handle_no_longer_valid                                             = 0x1a9f,
  error_no_txf_metadata                                                    = 0x1aa0,
  error_log_corruption_detected                                            = 0x1aa1,
  error_cant_recover_with_handle_open                                      = 0x1aa2,
  error_rm_disconnected                                                    = 0x1aa3,
  error_enlistment_not_superior                                            = 0x1aa4,
  error_recovery_not_needed                                                = 0x1aa5,
  error_rm_already_started                                                 = 0x1aa6,
  error_file_identity_not_persistent                                       = 0x1aa7,
  error_cant_break_transactional_dependency                                = 0x1aa8,
  error_cant_cross_rm_boundary                                             = 0x1aa9,
  error_txf_dir_not_empty                                                  = 0x1aaa,
  error_indoubt_transactions_exist                                         = 0x1aab,
  error_tm_volatile                                                        = 0x1aac,
  error_rollback_timer_expired                                             = 0x1aad,
  error_txf_attribute_corrupt                                              = 0x1aae,
  error_efs_not_allowed_in_transaction                                     = 0x1aaf,
  error_transactional_open_not_allowed                                     = 0x1ab0,
  error_log_growth_failed                                                  = 0x1ab1,
  error_transacted_mapping_unsupported_remote                              = 0x1ab2,
  error_txf_metadata_already_present                                       = 0x1ab3,
  error_transaction_scope_callbacks_not_set                                = 0x1ab4,
  error_transaction_required_promotion                                     = 0x1ab5,
  error_cannot_execute_file_in_transaction                                 = 0x1ab6,
  error_transactions_not_frozen                                            = 0x1ab7,
  error_transaction_freeze_in_progress                                     = 0x1ab8,
  error_not_snapshot_volume                                                = 0x1ab9,
  error_no_savepoint_with_open_files                                       = 0x1aba,
  error_data_lost_repair                                                   = 0x1abb,
  error_sparse_not_allowed_in_transaction                                  = 0x1abc,
  error_tm_identity_mismatch                                               = 0x1abd,
  error_floated_section                                                    = 0x1abe,
  error_cannot_accept_transacted_work                                      = 0x1abf,
  error_cannot_abort_transactions                                          = 0x1ac0,
  error_bad_clusters                                                       = 0x1ac1,
  error_compression_not_allowed_in_transaction                             = 0x1ac2,
  error_volume_dirty                                                       = 0x1ac3,
  error_no_link_tracking_in_transaction                                    = 0x1ac4,
  error_operation_not_supported_in_transaction                             = 0x1ac5,
  error_expired_handle                                                     = 0x1ac6,
  error_transaction_not_enlisted                                           = 0x1ac7,
  error_ctx_winstation_name_invalid                                        = 0x1b59,
  error_ctx_invalid_pd                                                     = 0x1b5a,
  error_ctx_pd_not_found                                                   = 0x1b5b,
  error_ctx_wd_not_found                                                   = 0x1b5c,
  error_ctx_cannot_make_eventlog_entry                                     = 0x1b5d,
  error_ctx_service_name_collision                                         = 0x1b5e,
  error_ctx_close_pending                                                  = 0x1b5f,
  error_ctx_no_outbuf                                                      = 0x1b60,
  error_ctx_modem_inf_not_found                                            = 0x1b61,
  error_ctx_invalid_modemname                                              = 0x1b62,
  error_ctx_modem_response_error                                           = 0x1b63,
  error_ctx_modem_response_timeout                                         = 0x1b64,
  error_ctx_modem_response_no_carrier                                      = 0x1b65,
  error_ctx_modem_response_no_dialtone                                     = 0x1b66,
  error_ctx_modem_response_busy                                            = 0x1b67,
  error_ctx_modem_response_voice                                           = 0x1b68,
  error_ctx_td_error                                                       = 0x1b69,
  error_ctx_winstation_not_found                                           = 0x1b6e,
  error_ctx_winstation_already_exists                                      = 0x1b6f,
  error_ctx_winstation_busy                                                = 0x1b70,
  error_ctx_bad_video_mode                                                 = 0x1b71,
  error_ctx_graphics_invalid                                               = 0x1b7b,
  error_ctx_logon_disabled                                                 = 0x1b7d,
  error_ctx_not_console                                                    = 0x1b7e,
  error_ctx_client_query_timeout                                           = 0x1b80,
  error_ctx_console_disconnect                                             = 0x1b81,
  error_ctx_console_connect                                                = 0x1b82,
  error_ctx_shadow_denied                                                  = 0x1b84,
  error_ctx_winstation_access_denied                                       = 0x1b85,
  error_ctx_invalid_wd                                                     = 0x1b89,
  error_ctx_shadow_invalid                                                 = 0x1b8a,
  error_ctx_shadow_disabled                                                = 0x1b8b,
  error_ctx_client_license_in_use                                          = 0x1b8c,
  error_ctx_client_license_not_set                                         = 0x1b8d,
  error_ctx_license_not_available                                          = 0x1b8e,
  error_ctx_license_client_invalid                                         = 0x1b8f,
  error_ctx_license_expired                                                = 0x1b90,
  error_ctx_shadow_not_running                                             = 0x1b91,
  error_ctx_shadow_ended_by_mode_change                                    = 0x1b92,
  error_activation_count_exceeded                                          = 0x1b93,
  error_ctx_winstations_disabled                                           = 0x1b94,
  error_ctx_encryption_level_required                                      = 0x1b95,
  error_ctx_session_in_use                                                 = 0x1b96,
  error_ctx_no_force_logoff                                                = 0x1b97,
  error_ctx_account_restriction                                            = 0x1b98,
  error_rdp_protocol_error                                                 = 0x1b99,
  error_ctx_cdm_connect                                                    = 0x1b9a,
  error_ctx_cdm_disconnect                                                 = 0x1b9b,
  error_ctx_security_layer_error                                           = 0x1b9c,
  error_ts_incompatible_sessions                                           = 0x1b9d,
  error_ts_video_subsystem_error                                           = 0x1b9e,
  frs_err_invalid_api_sequence                                             = 0x1f41,
  frs_err_starting_service                                                 = 0x1f42,
  frs_err_stopping_service                                                 = 0x1f43,
  frs_err_internal_api                                                     = 0x1f44,
  frs_err_internal                                                         = 0x1f45,
  frs_err_service_comm                                                     = 0x1f46,
  frs_err_insufficient_priv                                                = 0x1f47,
  frs_err_authentication                                                   = 0x1f48,
  frs_err_parent_insufficient_priv                                         = 0x1f49,
  frs_err_parent_authentication                                            = 0x1f4a,
  frs_err_child_to_parent_comm                                             = 0x1f4b,
  frs_err_parent_to_child_comm                                             = 0x1f4c,
  frs_err_sysvol_populate                                                  = 0x1f4d,
  frs_err_sysvol_populate_timeout                                          = 0x1f4e,
  frs_err_sysvol_is_busy                                                   = 0x1f4f,
  frs_err_sysvol_demote                                                    = 0x1f50,
  frs_err_invalid_service_parameter                                        = 0x1f51,
  error_ds_not_installed                                                   = 0x2008,
  error_ds_membership_evaluated_locally                                    = 0x2009,
  error_ds_no_attribute_or_value                                           = 0x200a,
  error_ds_invalid_attribute_syntax                                        = 0x200b,
  error_ds_attribute_type_undefined                                        = 0x200c,
  error_ds_attribute_or_value_exists                                       = 0x200d,
  error_ds_busy                                                            = 0x200e,
  error_ds_unavailable                                                     = 0x200f,
  error_ds_no_rids_allocated                                               = 0x2010,
  error_ds_no_more_rids                                                    = 0x2011,
  error_ds_incorrect_role_owner                                            = 0x2012,
  error_ds_ridmgr_init_error                                               = 0x2013,
  error_ds_obj_class_violation                                             = 0x2014,
  error_ds_cant_on_non_leaf                                                = 0x2015,
  error_ds_cant_on_rdn                                                     = 0x2016,
  error_ds_cant_mod_obj_class                                              = 0x2017,
  error_ds_cross_dom_move_error                                            = 0x2018,
  error_ds_gc_not_available                                                = 0x2019,
  error_shared_policy                                                      = 0x201a,
  error_policy_object_not_found                                            = 0x201b,
  error_policy_only_in_ds                                                  = 0x201c,
  error_promotion_active                                                   = 0x201d,
  error_no_promotion_active                                                = 0x201e,
  error_ds_operations_error                                                = 0x2020,
  error_ds_protocol_error                                                  = 0x2021,
  error_ds_timelimit_exceeded                                              = 0x2022,
  error_ds_sizelimit_exceeded                                              = 0x2023,
  error_ds_admin_limit_exceeded                                            = 0x2024,
  error_ds_compare_false                                                   = 0x2025,
  error_ds_compare_true                                                    = 0x2026,
  error_ds_auth_method_not_supported                                       = 0x2027,
  error_ds_strong_auth_required                                            = 0x2028,
  error_ds_inappropriate_auth                                              = 0x2029,
  error_ds_auth_unknown                                                    = 0x202a,
  error_ds_referral                                                        = 0x202b,
  error_ds_unavailable_crit_extension                                      = 0x202c,
  error_ds_confidentiality_required                                        = 0x202d,
  error_ds_inappropriate_matching                                          = 0x202e,
  error_ds_constraint_violation                                            = 0x202f,
  error_ds_no_such_object                                                  = 0x2030,
  error_ds_alias_problem                                                   = 0x2031,
  error_ds_invalid_dn_syntax                                               = 0x2032,
  error_ds_is_leaf                                                         = 0x2033,
  error_ds_alias_deref_problem                                             = 0x2034,
  error_ds_unwilling_to_perform                                            = 0x2035,
  error_ds_loop_detect                                                     = 0x2036,
  error_ds_naming_violation                                                = 0x2037,
  error_ds_object_results_too_large                                        = 0x2038,
  error_ds_affects_multiple_dsas                                           = 0x2039,
  error_ds_server_down                                                     = 0x203a,
  error_ds_local_error                                                     = 0x203b,
  error_ds_encoding_error                                                  = 0x203c,
  error_ds_decoding_error                                                  = 0x203d,
  error_ds_filter_unknown                                                  = 0x203e,
  error_ds_param_error                                                     = 0x203f,
  error_ds_not_supported                                                   = 0x2040,
  error_ds_no_results_returned                                             = 0x2041,
  error_ds_control_not_found                                               = 0x2042,
  error_ds_client_loop                                                     = 0x2043,
  error_ds_referral_limit_exceeded                                         = 0x2044,
  error_ds_sort_control_missing                                            = 0x2045,
  error_ds_offset_range_error                                              = 0x2046,
  error_ds_ridmgr_disabled                                                 = 0x2047,
  error_ds_root_must_be_nc                                                 = 0x206d,
  error_ds_add_replica_inhibited                                           = 0x206e,
  error_ds_att_not_def_in_schema                                           = 0x206f,
  error_ds_max_obj_size_exceeded                                           = 0x2070,
  error_ds_obj_string_name_exists                                          = 0x2071,
  error_ds_no_rdn_defined_in_schema                                        = 0x2072,
  error_ds_rdn_doesnt_match_schema                                         = 0x2073,
  error_ds_no_requested_atts_found                                         = 0x2074,
  error_ds_user_buffer_to_small                                            = 0x2075,
  error_ds_att_is_not_on_obj                                               = 0x2076,
  error_ds_illegal_mod_operation                                           = 0x2077,
  error_ds_obj_too_large                                                   = 0x2078,
  error_ds_bad_instance_type                                               = 0x2079,
  error_ds_masterdsa_required                                              = 0x207a,
  error_ds_object_class_required                                           = 0x207b,
  error_ds_missing_required_att                                            = 0x207c,
  error_ds_att_not_def_for_class                                           = 0x207d,
  error_ds_att_already_exists                                              = 0x207e,
  error_ds_cant_add_att_values                                             = 0x2080,
  error_ds_single_value_constraint                                         = 0x2081,
  error_ds_range_constraint                                                = 0x2082,
  error_ds_att_val_already_exists                                          = 0x2083,
  error_ds_cant_rem_missing_att                                            = 0x2084,
  error_ds_cant_rem_missing_att_val                                        = 0x2085,
  error_ds_root_cant_be_subref                                             = 0x2086,
  error_ds_no_chaining                                                     = 0x2087,
  error_ds_no_chained_eval                                                 = 0x2088,
  error_ds_no_parent_object                                                = 0x2089,
  error_ds_parent_is_an_alias                                              = 0x208a,
  error_ds_cant_mix_master_and_reps                                        = 0x208b,
  error_ds_children_exist                                                  = 0x208c,
  error_ds_obj_not_found                                                   = 0x208d,
  error_ds_aliased_obj_missing                                             = 0x208e,
  error_ds_bad_name_syntax                                                 = 0x208f,
  error_ds_alias_points_to_alias                                           = 0x2090,
  error_ds_cant_deref_alias                                                = 0x2091,
  error_ds_out_of_scope                                                    = 0x2092,
  error_ds_object_being_removed                                            = 0x2093,
  error_ds_cant_delete_dsa_obj                                             = 0x2094,
  error_ds_generic_error                                                   = 0x2095,
  error_ds_dsa_must_be_int_master                                          = 0x2096,
  error_ds_class_not_dsa                                                   = 0x2097,
  error_ds_insuff_access_rights                                            = 0x2098,
  error_ds_illegal_superior                                                = 0x2099,
  error_ds_attribute_owned_by_sam                                          = 0x209a,
  error_ds_name_too_many_parts                                             = 0x209b,
  error_ds_name_too_long                                                   = 0x209c,
  error_ds_name_value_too_long                                             = 0x209d,
  error_ds_name_unparseable                                                = 0x209e,
  error_ds_name_type_unknown                                               = 0x209f,
  error_ds_not_an_object                                                   = 0x20a0,
  error_ds_sec_desc_too_short                                              = 0x20a1,
  error_ds_sec_desc_invalid                                                = 0x20a2,
  error_ds_no_deleted_name                                                 = 0x20a3,
  error_ds_subref_must_have_parent                                         = 0x20a4,
  error_ds_ncname_must_be_nc                                               = 0x20a5,
  error_ds_cant_add_system_only                                            = 0x20a6,
  error_ds_class_must_be_concrete                                          = 0x20a7,
  error_ds_invalid_dmd                                                     = 0x20a8,
  error_ds_obj_guid_exists                                                 = 0x20a9,
  error_ds_not_on_backlink                                                 = 0x20aa,
  error_ds_no_crossref_for_nc                                              = 0x20ab,
  error_ds_shutting_down                                                   = 0x20ac,
  error_ds_unknown_operation                                               = 0x20ad,
  error_ds_invalid_role_owner                                              = 0x20ae,
  error_ds_couldnt_contact_fsmo                                            = 0x20af,
  error_ds_cross_nc_dn_rename                                              = 0x20b0,
  error_ds_cant_mod_system_only                                            = 0x20b1,
  error_ds_replicator_only                                                 = 0x20b2,
  error_ds_obj_class_not_defined                                           = 0x20b3,
  error_ds_obj_class_not_subclass                                          = 0x20b4,
  error_ds_name_reference_invalid                                          = 0x20b5,
  error_ds_cross_ref_exists                                                = 0x20b6,
  error_ds_cant_del_master_crossref                                        = 0x20b7,
  error_ds_subtree_notify_not_nc_head                                      = 0x20b8,
  error_ds_notify_filter_too_complex                                       = 0x20b9,
  error_ds_dup_rdn                                                         = 0x20ba,
  error_ds_dup_oid                                                         = 0x20bb,
  error_ds_dup_mapi_id                                                     = 0x20bc,
  error_ds_dup_schema_id_guid                                              = 0x20bd,
  error_ds_dup_ldap_display_name                                           = 0x20be,
  error_ds_semantic_att_test                                               = 0x20bf,
  error_ds_syntax_mismatch                                                 = 0x20c0,
  error_ds_exists_in_must_have                                             = 0x20c1,
  error_ds_exists_in_may_have                                              = 0x20c2,
  error_ds_nonexistent_may_have                                            = 0x20c3,
  error_ds_nonexistent_must_have                                           = 0x20c4,
  error_ds_aux_cls_test_fail                                               = 0x20c5,
  error_ds_nonexistent_poss_sup                                            = 0x20c6,
  error_ds_sub_cls_test_fail                                               = 0x20c7,
  error_ds_bad_rdn_att_id_syntax                                           = 0x20c8,
  error_ds_exists_in_aux_cls                                               = 0x20c9,
  error_ds_exists_in_sub_cls                                               = 0x20ca,
  error_ds_exists_in_poss_sup                                              = 0x20cb,
  error_ds_recalcschema_failed                                             = 0x20cc,
  error_ds_tree_delete_not_finished                                        = 0x20cd,
  error_ds_cant_delete                                                     = 0x20ce,
  error_ds_att_schema_req_id                                               = 0x20cf,
  error_ds_bad_att_schema_syntax                                           = 0x20d0,
  error_ds_cant_cache_att                                                  = 0x20d1,
  error_ds_cant_cache_class                                                = 0x20d2,
  error_ds_cant_remove_att_cache                                           = 0x20d3,
  error_ds_cant_remove_class_cache                                         = 0x20d4,
  error_ds_cant_retrieve_dn                                                = 0x20d5,
  error_ds_missing_supref                                                  = 0x20d6,
  error_ds_cant_retrieve_instance                                          = 0x20d7,
  error_ds_code_inconsistency                                              = 0x20d8,
  error_ds_database_error                                                  = 0x20d9,
  error_ds_governsid_missing                                               = 0x20da,
  error_ds_missing_expected_att                                            = 0x20db,
  error_ds_ncname_missing_cr_ref                                           = 0x20dc,
  error_ds_security_checking_error                                         = 0x20dd,
  error_ds_schema_not_loaded                                               = 0x20de,
  error_ds_schema_alloc_failed                                             = 0x20df,
  error_ds_att_schema_req_syntax                                           = 0x20e0,
  error_ds_gcverify_error                                                  = 0x20e1,
  error_ds_dra_schema_mismatch                                             = 0x20e2,
  error_ds_cant_find_dsa_obj                                               = 0x20e3,
  error_ds_cant_find_expected_nc                                           = 0x20e4,
  error_ds_cant_find_nc_in_cache                                           = 0x20e5,
  error_ds_cant_retrieve_child                                             = 0x20e6,
  error_ds_security_illegal_modify                                         = 0x20e7,
  error_ds_cant_replace_hidden_rec                                         = 0x20e8,
  error_ds_bad_hierarchy_file                                              = 0x20e9,
  error_ds_build_hierarchy_table_failed                                    = 0x20ea,
  error_ds_config_param_missing                                            = 0x20eb,
  error_ds_counting_ab_indices_failed                                      = 0x20ec,
  error_ds_hierarchy_table_malloc_failed                                   = 0x20ed,
  error_ds_internal_failure                                                = 0x20ee,
  error_ds_unknown_error                                                   = 0x20ef,
  error_ds_root_requires_class_top                                         = 0x20f0,
  error_ds_refusing_fsmo_roles                                             = 0x20f1,
  error_ds_missing_fsmo_settings                                           = 0x20f2,
  error_ds_unable_to_surrender_roles                                       = 0x20f3,
  error_ds_dra_generic                                                     = 0x20f4,
  error_ds_dra_invalid_parameter                                           = 0x20f5,
  error_ds_dra_busy                                                        = 0x20f6,
  error_ds_dra_bad_dn                                                      = 0x20f7,
  error_ds_dra_bad_nc                                                      = 0x20f8,
  error_ds_dra_dn_exists                                                   = 0x20f9,
  error_ds_dra_internal_error                                              = 0x20fa,
  error_ds_dra_inconsistent_dit                                            = 0x20fb,
  error_ds_dra_connection_failed                                           = 0x20fc,
  error_ds_dra_bad_instance_type                                           = 0x20fd,
  error_ds_dra_out_of_mem                                                  = 0x20fe,
  error_ds_dra_mail_problem                                                = 0x20ff,
  error_ds_dra_ref_already_exists                                          = 0x2100,
  error_ds_dra_ref_not_found                                               = 0x2101,
  error_ds_dra_obj_is_rep_source                                           = 0x2102,
  error_ds_dra_db_error                                                    = 0x2103,
  error_ds_dra_no_replica                                                  = 0x2104,
  error_ds_dra_access_denied                                               = 0x2105,
  error_ds_dra_not_supported                                               = 0x2106,
  error_ds_dra_rpc_cancelled                                               = 0x2107,
  error_ds_dra_source_disabled                                             = 0x2108,
  error_ds_dra_sink_disabled                                               = 0x2109,
  error_ds_dra_name_collision                                              = 0x210a,
  error_ds_dra_source_reinstalled                                          = 0x210b,
  error_ds_dra_missing_parent                                              = 0x210c,
  error_ds_dra_preempted                                                   = 0x210d,
  error_ds_dra_abandon_sync                                                = 0x210e,
  error_ds_dra_shutdown                                                    = 0x210f,
  error_ds_dra_incompatible_partial_set                                    = 0x2110,
  error_ds_dra_source_is_partial_replica                                   = 0x2111,
  error_ds_dra_extn_connection_failed                                      = 0x2112,
  error_ds_install_schema_mismatch                                         = 0x2113,
  error_ds_dup_link_id                                                     = 0x2114,
  error_ds_name_error_resolving                                            = 0x2115,
  error_ds_name_error_not_found                                            = 0x2116,
  error_ds_name_error_not_unique                                           = 0x2117,
  error_ds_name_error_no_mapping                                           = 0x2118,
  error_ds_name_error_domain_only                                          = 0x2119,
  error_ds_name_error_no_syntactical_mapping                               = 0x211a,
  error_ds_constructed_att_mod                                             = 0x211b,
  error_ds_wrong_om_obj_class                                              = 0x211c,
  error_ds_dra_repl_pending                                                = 0x211d,
  error_ds_ds_required                                                     = 0x211e,
  error_ds_invalid_ldap_display_name                                       = 0x211f,
  error_ds_non_base_search                                                 = 0x2120,
  error_ds_cant_retrieve_atts                                              = 0x2121,
  error_ds_backlink_without_link                                           = 0x2122,
  error_ds_epoch_mismatch                                                  = 0x2123,
  error_ds_src_name_mismatch                                               = 0x2124,
  error_ds_src_and_dst_nc_identical                                        = 0x2125,
  error_ds_dst_nc_mismatch                                                 = 0x2126,
  error_ds_not_authoritive_for_dst_nc                                      = 0x2127,
  error_ds_src_guid_mismatch                                               = 0x2128,
  error_ds_cant_move_deleted_object                                        = 0x2129,
  error_ds_pdc_operation_in_progress                                       = 0x212a,
  error_ds_cross_domain_cleanup_reqd                                       = 0x212b,
  error_ds_illegal_xdom_move_operation                                     = 0x212c,
  error_ds_cant_with_acct_group_membershps                                 = 0x212d,
  error_ds_nc_must_have_nc_parent                                          = 0x212e,
  error_ds_cr_impossible_to_validate                                       = 0x212f,
  error_ds_dst_domain_not_native                                           = 0x2130,
  error_ds_missing_infrastructure_container                                = 0x2131,
  error_ds_cant_move_account_group                                         = 0x2132,
  error_ds_cant_move_resource_group                                        = 0x2133,
  error_ds_invalid_search_flag                                             = 0x2134,
  error_ds_no_tree_delete_above_nc                                         = 0x2135,
  error_ds_couldnt_lock_tree_for_delete                                    = 0x2136,
  error_ds_couldnt_identify_objects_for_tree_delete                        = 0x2137,
  error_ds_sam_init_failure                                                = 0x2138,
  error_ds_sensitive_group_violation                                       = 0x2139,
  error_ds_cant_mod_primarygroupid                                         = 0x213a,
  error_ds_illegal_base_schema_mod                                         = 0x213b,
  error_ds_nonsafe_schema_change                                           = 0x213c,
  error_ds_schema_update_disallowed                                        = 0x213d,
  error_ds_cant_create_under_schema                                        = 0x213e,
  error_ds_install_no_src_sch_version                                      = 0x213f,
  error_ds_install_no_sch_version_in_inifile                               = 0x2140,
  error_ds_invalid_group_type                                              = 0x2141,
  error_ds_no_nest_globalgroup_in_mixeddomain                              = 0x2142,
  error_ds_no_nest_localgroup_in_mixeddomain                               = 0x2143,
  error_ds_global_cant_have_local_member                                   = 0x2144,
  error_ds_global_cant_have_universal_member                               = 0x2145,
  error_ds_universal_cant_have_local_member                                = 0x2146,
  error_ds_global_cant_have_crossdomain_member                             = 0x2147,
  error_ds_local_cant_have_crossdomain_local_member                        = 0x2148,
  error_ds_have_primary_members                                            = 0x2149,
  error_ds_string_sd_conversion_failed                                     = 0x214a,
  error_ds_naming_master_gc                                                = 0x214b,
  error_ds_dns_lookup_failure                                              = 0x214c,
  error_ds_couldnt_update_spns                                             = 0x214d,
  error_ds_cant_retrieve_sd                                                = 0x214e,
  error_ds_key_not_unique                                                  = 0x214f,
  error_ds_wrong_linked_att_syntax                                         = 0x2150,
  error_ds_sam_need_bootkey_password                                       = 0x2151,
  error_ds_sam_need_bootkey_floppy                                         = 0x2152,
  error_ds_cant_start                                                      = 0x2153,
  error_ds_init_failure                                                    = 0x2154,
  error_ds_no_pkt_privacy_on_connection                                    = 0x2155,
  error_ds_source_domain_in_forest                                         = 0x2156,
  error_ds_destination_domain_not_in_forest                                = 0x2157,
  error_ds_destination_auditing_not_enabled                                = 0x2158,
  error_ds_cant_find_dc_for_src_domain                                     = 0x2159,
  error_ds_src_obj_not_group_or_user                                       = 0x215a,
  error_ds_src_sid_exists_in_forest                                        = 0x215b,
  error_ds_src_and_dst_object_class_mismatch                               = 0x215c,
  error_sam_init_failure                                                   = 0x215d,
  error_ds_dra_schema_info_ship                                            = 0x215e,
  error_ds_dra_schema_conflict                                             = 0x215f,
  error_ds_dra_earlier_schema_conflict                                     = 0x2160,
  error_ds_dra_obj_nc_mismatch                                             = 0x2161,
  error_ds_nc_still_has_dsas                                               = 0x2162,
  error_ds_gc_required                                                     = 0x2163,
  error_ds_local_member_of_local_only                                      = 0x2164,
  error_ds_no_fpo_in_universal_groups                                      = 0x2165,
  error_ds_cant_add_to_gc                                                  = 0x2166,
  error_ds_no_checkpoint_with_pdc                                          = 0x2167,
  error_ds_source_auditing_not_enabled                                     = 0x2168,
  error_ds_cant_create_in_nondomain_nc                                     = 0x2169,
  error_ds_invalid_name_for_spn                                            = 0x216a,
  error_ds_filter_uses_contructed_attrs                                    = 0x216b,
  error_ds_unicodepwd_not_in_quotes                                        = 0x216c,
  error_ds_machine_account_quota_exceeded                                  = 0x216d,
  error_ds_must_be_run_on_dst_dc                                           = 0x216e,
  error_ds_src_dc_must_be_sp4_or_greater                                   = 0x216f,
  error_ds_cant_tree_delete_critical_obj                                   = 0x2170,
  error_ds_init_failure_console                                            = 0x2171,
  error_ds_sam_init_failure_console                                        = 0x2172,
  error_ds_forest_version_too_high                                         = 0x2173,
  error_ds_domain_version_too_high                                         = 0x2174,
  error_ds_forest_version_too_low                                          = 0x2175,
  error_ds_domain_version_too_low                                          = 0x2176,
  error_ds_incompatible_version                                            = 0x2177,
  error_ds_low_dsa_version                                                 = 0x2178,
  error_ds_no_behavior_version_in_mixeddomain                              = 0x2179,
  error_ds_not_supported_sort_order                                        = 0x217a,
  error_ds_name_not_unique                                                 = 0x217b,
  error_ds_machine_account_created_prent4                                  = 0x217c,
  error_ds_out_of_version_store                                            = 0x217d,
  error_ds_incompatible_controls_used                                      = 0x217e,
  error_ds_no_ref_domain                                                   = 0x217f,
  error_ds_reserved_link_id                                                = 0x2180,
  error_ds_link_id_not_available                                           = 0x2181,
  error_ds_ag_cant_have_universal_member                                   = 0x2182,
  error_ds_modifydn_disallowed_by_instance_type                            = 0x2183,
  error_ds_no_object_move_in_schema_nc                                     = 0x2184,
  error_ds_modifydn_disallowed_by_flag                                     = 0x2185,
  error_ds_modifydn_wrong_grandparent                                      = 0x2186,
  error_ds_name_error_trust_referral                                       = 0x2187,
  error_not_supported_on_standard_server                                   = 0x2188,
  error_ds_cant_access_remote_part_of_ad                                   = 0x2189,
  error_ds_cr_impossible_to_validate_v2                                    = 0x218a,
  error_ds_thread_limit_exceeded                                           = 0x218b,
  error_ds_not_closest                                                     = 0x218c,
  error_ds_cant_derive_spn_without_server_ref                              = 0x218d,
  error_ds_single_user_mode_failed                                         = 0x218e,
  error_ds_ntdscript_syntax_error                                          = 0x218f,
  error_ds_ntdscript_process_error                                         = 0x2190,
  error_ds_different_repl_epochs                                           = 0x2191,
  error_ds_drs_extensions_changed                                          = 0x2192,
  error_ds_replica_set_change_not_allowed_on_disabled_cr                   = 0x2193,
  error_ds_no_msds_intid                                                   = 0x2194,
  error_ds_dup_msds_intid                                                  = 0x2195,
  error_ds_exists_in_rdnattid                                              = 0x2196,
  error_ds_authorization_failed                                            = 0x2197,
  error_ds_invalid_script                                                  = 0x2198,
  error_ds_remote_crossref_op_failed                                       = 0x2199,
  error_ds_cross_ref_busy                                                  = 0x219a,
  error_ds_cant_derive_spn_for_deleted_domain                              = 0x219b,
  error_ds_cant_demote_with_writeable_nc                                   = 0x219c,
  error_ds_duplicate_id_found                                              = 0x219d,
  error_ds_insufficient_attr_to_create_object                              = 0x219e,
  error_ds_group_conversion_error                                          = 0x219f,
  error_ds_cant_move_app_basic_group                                       = 0x21a0,
  error_ds_cant_move_app_query_group                                       = 0x21a1,
  error_ds_role_not_verified                                               = 0x21a2,
  error_ds_wko_container_cannot_be_special                                 = 0x21a3,
  error_ds_domain_rename_in_progress                                       = 0x21a4,
  error_ds_existing_ad_child_nc                                            = 0x21a5,
  error_ds_repl_lifetime_exceeded                                          = 0x21a6,
  error_ds_disallowed_in_system_container                                  = 0x21a7,
  error_ds_ldap_send_queue_full                                            = 0x21a8,
  error_ds_dra_out_schedule_window                                         = 0x21a9,
  error_ds_policy_not_known                                                = 0x21aa,
  error_no_site_settings_object                                            = 0x21ab,
  error_no_secrets                                                         = 0x21ac,
  error_no_writable_dc_found                                               = 0x21ad,
  error_ds_no_server_object                                                = 0x21ae,
  error_ds_no_ntdsa_object                                                 = 0x21af,
  error_ds_non_asq_search                                                  = 0x21b0,
  error_ds_audit_failure                                                   = 0x21b1,
  error_ds_invalid_search_flag_subtree                                     = 0x21b2,
  error_ds_invalid_search_flag_tuple                                       = 0x21b3,
  error_ds_hierarchy_table_too_deep                                        = 0x21b4,
  error_ds_dra_corrupt_utd_vector                                          = 0x21b5,
  error_ds_dra_secrets_denied                                              = 0x21b6,
  error_ds_reserved_mapi_id                                                = 0x21b7,
  error_ds_mapi_id_not_available                                           = 0x21b8,
  error_ds_dra_missing_krbtgt_secret                                       = 0x21b9,
  error_ds_domain_name_exists_in_forest                                    = 0x21ba,
  error_ds_flat_name_exists_in_forest                                      = 0x21bb,
  error_invalid_user_principal_name                                        = 0x21bc,
  error_ds_oid_mapped_group_cant_have_members                              = 0x21bd,
  error_ds_oid_not_found                                                   = 0x21be,
  error_ds_dra_recycled_target                                             = 0x21bf,
  error_ds_disallowed_nc_redirect                                          = 0x21c0,
  error_ds_high_adlds_ffl                                                  = 0x21c1,
  error_ds_high_dsa_version                                                = 0x21c2,
  error_ds_low_adlds_ffl                                                   = 0x21c3,
  error_domain_sid_same_as_local_workstation                               = 0x21c4,
  error_ds_undelete_sam_validation_failed                                  = 0x21c5,
  error_incorrect_account_type                                             = 0x21c6,
  dns_error_rcode_format_error                                             = 0x2329,
  dns_error_rcode_server_failure                                           = 0x232a,
  dns_error_rcode_name_error                                               = 0x232b,
  dns_error_rcode_not_implemented                                          = 0x232c,
  dns_error_rcode_refused                                                  = 0x232d,
  dns_error_rcode_yxdomain                                                 = 0x232e,
  dns_error_rcode_yxrrset                                                  = 0x232f,
  dns_error_rcode_nxrrset                                                  = 0x2330,
  dns_error_rcode_notauth                                                  = 0x2331,
  dns_error_rcode_notzone                                                  = 0x2332,
  dns_error_rcode_badsig                                                   = 0x2338,
  dns_error_rcode_badkey                                                   = 0x2339,
  dns_error_rcode_badtime                                                  = 0x233a,
  dns_error_keymaster_required                                             = 0x238d,
  dns_error_not_allowed_on_signed_zone                                     = 0x238e,
  dns_error_nsec3_incompatible_with_rsa_sha1                               = 0x238f,
  dns_error_not_enough_signing_key_descriptors                             = 0x2390,
  dns_error_unsupported_algorithm                                          = 0x2391,
  dns_error_invalid_key_size                                               = 0x2392,
  dns_error_signing_key_not_accessible                                     = 0x2393,
  dns_error_ksp_does_not_support_protection                                = 0x2394,
  dns_error_unexpected_data_protection_error                               = 0x2395,
  dns_error_unexpected_cng_error                                           = 0x2396,
  dns_error_unknown_signing_parameter_version                              = 0x2397,
  dns_error_ksp_not_accessible                                             = 0x2398,
  dns_error_too_many_skds                                                  = 0x2399,
  dns_error_invalid_rollover_period                                        = 0x239a,
  dns_error_invalid_initial_rollover_offset                                = 0x239b,
  dns_error_rollover_in_progress                                           = 0x239c,
  dns_error_standby_key_not_present                                        = 0x239d,
  dns_error_not_allowed_on_zsk                                             = 0x239e,
  dns_error_not_allowed_on_active_skd                                      = 0x239f,
  dns_error_rollover_already_queued                                        = 0x23a0,
  dns_error_not_allowed_on_unsigned_zone                                   = 0x23a1,
  dns_error_bad_keymaster                                                  = 0x23a2,
  dns_error_invalid_signature_validity_period                              = 0x23a3,
  dns_error_invalid_nsec3_iteration_count                                  = 0x23a4,
  dns_error_dnssec_is_disabled                                             = 0x23a5,
  dns_error_invalid_xml                                                    = 0x23a6,
  dns_error_no_valid_trust_anchors                                         = 0x23a7,
  dns_error_rollover_not_pokeable                                          = 0x23a8,
  dns_error_nsec3_name_collision                                           = 0x23a9,
  dns_error_nsec_incompatible_with_nsec3_rsa_sha1                          = 0x23aa,
  dns_info_no_records                                                      = 0x251d,
  dns_error_bad_packet                                                     = 0x251e,
  dns_error_no_packet                                                      = 0x251f,
  dns_error_rcode                                                          = 0x2520,
  dns_error_unsecure_packet                                                = 0x2521,
  dns_request_pending                                                      = 0x2522,
  dns_error_invalid_type                                                   = 0x254f,
  dns_error_invalid_ip_address                                             = 0x2550,
  dns_error_invalid_property                                               = 0x2551,
  dns_error_try_again_later                                                = 0x2552,
  dns_error_not_unique                                                     = 0x2553,
  dns_error_non_rfc_name                                                   = 0x2554,
  dns_status_fqdn                                                          = 0x2555,
  dns_status_dotted_name                                                   = 0x2556,
  dns_status_single_part_name                                              = 0x2557,
  dns_error_invalid_name_char                                              = 0x2558,
  dns_error_numeric_name                                                   = 0x2559,
  dns_error_not_allowed_on_root_server                                     = 0x255a,
  dns_error_not_allowed_under_delegation                                   = 0x255b,
  dns_error_cannot_find_root_hints                                         = 0x255c,
  dns_error_inconsistent_root_hints                                        = 0x255d,
  dns_error_dword_value_too_small                                          = 0x255e,
  dns_error_dword_value_too_large                                          = 0x255f,
  dns_error_background_loading                                             = 0x2560,
  dns_error_not_allowed_on_rodc                                            = 0x2561,
  dns_error_not_allowed_under_dname                                        = 0x2562,
  dns_error_delegation_required                                            = 0x2563,
  dns_error_invalid_policy_table                                           = 0x2564,
  dns_error_zone_does_not_exist                                            = 0x2581,
  dns_error_no_zone_info                                                   = 0x2582,
  dns_error_invalid_zone_operation                                         = 0x2583,
  dns_error_zone_configuration_error                                       = 0x2584,
  dns_error_zone_has_no_soa_record                                         = 0x2585,
  dns_error_zone_has_no_ns_records                                         = 0x2586,
  dns_error_zone_locked                                                    = 0x2587,
  dns_error_zone_creation_failed                                           = 0x2588,
  dns_error_zone_already_exists                                            = 0x2589,
  dns_error_autozone_already_exists                                        = 0x258a,
  dns_error_invalid_zone_type                                              = 0x258b,
  dns_error_secondary_requires_master_ip                                   = 0x258c,
  dns_error_zone_not_secondary                                             = 0x258d,
  dns_error_need_secondary_addresses                                       = 0x258e,
  dns_error_wins_init_failed                                               = 0x258f,
  dns_error_need_wins_servers                                              = 0x2590,
  dns_error_nbstat_init_failed                                             = 0x2591,
  dns_error_soa_delete_invalid                                             = 0x2592,
  dns_error_forwarder_already_exists                                       = 0x2593,
  dns_error_zone_requires_master_ip                                        = 0x2594,
  dns_error_zone_is_shutdown                                               = 0x2595,
  dns_error_zone_locked_for_signing                                        = 0x2596,
  dns_error_primary_requires_datafile                                      = 0x25b3,
  dns_error_invalid_datafile_name                                          = 0x25b4,
  dns_error_datafile_open_failure                                          = 0x25b5,
  dns_error_file_writeback_failed                                          = 0x25b6,
  dns_error_datafile_parsing                                               = 0x25b7,
  dns_error_record_does_not_exist                                          = 0x25e5,
  dns_error_record_format                                                  = 0x25e6,
  dns_error_node_creation_failed                                           = 0x25e7,
  dns_error_unknown_record_type                                            = 0x25e8,
  dns_error_record_timed_out                                               = 0x25e9,
  dns_error_name_not_in_zone                                               = 0x25ea,
  dns_error_cname_loop                                                     = 0x25eb,
  dns_error_node_is_cname                                                  = 0x25ec,
  dns_error_cname_collision                                                = 0x25ed,
  dns_error_record_only_at_zone_root                                       = 0x25ee,
  dns_error_record_already_exists                                          = 0x25ef,
  dns_error_secondary_data                                                 = 0x25f0,
  dns_error_no_create_cache_data                                           = 0x25f1,
  dns_error_name_does_not_exist                                            = 0x25f2,
  dns_warning_ptr_create_failed                                            = 0x25f3,
  dns_warning_domain_undeleted                                             = 0x25f4,
  dns_error_ds_unavailable                                                 = 0x25f5,
  dns_error_ds_zone_already_exists                                         = 0x25f6,
  dns_error_no_bootfile_if_ds_zone                                         = 0x25f7,
  dns_error_node_is_dname                                                  = 0x25f8,
  dns_error_dname_collision                                                = 0x25f9,
  dns_error_alias_loop                                                     = 0x25fa,
  dns_info_axfr_complete                                                   = 0x2617,
  dns_error_axfr                                                           = 0x2618,
  dns_info_added_local_wins                                                = 0x2619,
  dns_status_continue_needed                                               = 0x2649,
  dns_error_no_tcpip                                                       = 0x267b,
  dns_error_no_dns_servers                                                 = 0x267c,
  dns_error_dp_does_not_exist                                              = 0x26ad,
  dns_error_dp_already_exists                                              = 0x26ae,
  dns_error_dp_not_enlisted                                                = 0x26af,
  dns_error_dp_already_enlisted                                            = 0x26b0,
  dns_error_dp_not_available                                               = 0x26b1,
  dns_error_dp_fsmo_error                                                  = 0x26b2,
  wsaeintr                                                                 = 0x2714,
  wsaebadf                                                                 = 0x2719,
  wsaeacces                                                                = 0x271d,
  wsaefault                                                                = 0x271e,
  wsaeinval                                                                = 0x2726,
  wsaemfile                                                                = 0x2728,
  wsaewouldblock                                                           = 0x2733,
  wsaeinprogress                                                           = 0x2734,
  wsaealready                                                              = 0x2735,
  wsaenotsock                                                              = 0x2736,
  wsaedestaddrreq                                                          = 0x2737,
  wsaemsgsize                                                              = 0x2738,
  wsaeprototype                                                            = 0x2739,
  wsaenoprotoopt                                                           = 0x273a,
  wsaeprotonosupport                                                       = 0x273b,
  wsaesocktnosupport                                                       = 0x273c,
  wsaeopnotsupp                                                            = 0x273d,
  wsaepfnosupport                                                          = 0x273e,
  wsaeafnosupport                                                          = 0x273f,
  wsaeaddrinuse                                                            = 0x2740,
  wsaeaddrnotavail                                                         = 0x2741,
  wsaenetdown                                                              = 0x2742,
  wsaenetunreach                                                           = 0x2743,
  wsaenetreset                                                             = 0x2744,
  wsaeconnaborted                                                          = 0x2745,
  wsaeconnreset                                                            = 0x2746,
  wsaenobufs                                                               = 0x2747,
  wsaeisconn                                                               = 0x2748,
  wsaenotconn                                                              = 0x2749,
  wsaeshutdown                                                             = 0x274a,
  wsaetoomanyrefs                                                          = 0x274b,
  wsaetimedout                                                             = 0x274c,
  wsaeconnrefused                                                          = 0x274d,
  wsaeloop                                                                 = 0x274e,
  wsaenametoolong                                                          = 0x274f,
  wsaehostdown                                                             = 0x2750,
  wsaehostunreach                                                          = 0x2751,
  wsaenotempty                                                             = 0x2752,
  wsaeproclim                                                              = 0x2753,
  wsaeusers                                                                = 0x2754,
  wsaedquot                                                                = 0x2755,
  wsaestale                                                                = 0x2756,
  wsaeremote                                                               = 0x2757,
  wsasysnotready                                                           = 0x276b,
  wsavernotsupported                                                       = 0x276c,
  wsanotinitialised                                                        = 0x276d,
  wsaediscon                                                               = 0x2775,
  wsaenomore                                                               = 0x2776,
  wsaecancelled                                                            = 0x2777,
  wsaeinvalidproctable                                                     = 0x2778,
  wsaeinvalidprovider                                                      = 0x2779,
  wsaeproviderfailedinit                                                   = 0x277a,
  wsasyscallfailure                                                        = 0x277b,
  wsaservice_not_found                                                     = 0x277c,
  wsatype_not_found                                                        = 0x277d,
  wsa_e_no_more                                                            = 0x277e,
  wsa_e_cancelled                                                          = 0x277f,
  wsaerefused                                                              = 0x2780,
  wsahost_not_found                                                        = 0x2af9,
  wsatry_again                                                             = 0x2afa,
  wsano_recovery                                                           = 0x2afb,
  wsano_data                                                               = 0x2afc,
  wsa_qos_receivers                                                        = 0x2afd,
  wsa_qos_senders                                                          = 0x2afe,
  wsa_qos_no_senders                                                       = 0x2aff,
  wsa_qos_no_receivers                                                     = 0x2b00,
  wsa_qos_request_confirmed                                                = 0x2b01,
  wsa_qos_admission_failure                                                = 0x2b02,
  wsa_qos_policy_failure                                                   = 0x2b03,
  wsa_qos_bad_style                                                        = 0x2b04,
  wsa_qos_bad_object                                                       = 0x2b05,
  wsa_qos_traffic_ctrl_error                                               = 0x2b06,
  wsa_qos_generic_error                                                    = 0x2b07,
  wsa_qos_eservicetype                                                     = 0x2b08,
  wsa_qos_eflowspec                                                        = 0x2b09,
  wsa_qos_eprovspecbuf                                                     = 0x2b0a,
  wsa_qos_efilterstyle                                                     = 0x2b0b,
  wsa_qos_efiltertype                                                      = 0x2b0c,
  wsa_qos_efiltercount                                                     = 0x2b0d,
  wsa_qos_eobjlength                                                       = 0x2b0e,
  wsa_qos_eflowcount                                                       = 0x2b0f,
  wsa_qos_eunkownpsobj                                                     = 0x2b10,
  wsa_qos_epolicyobj                                                       = 0x2b11,
  wsa_qos_eflowdesc                                                        = 0x2b12,
  wsa_qos_epsflowspec                                                      = 0x2b13,
  wsa_qos_epsfilterspec                                                    = 0x2b14,
  wsa_qos_esdmodeobj                                                       = 0x2b15,
  wsa_qos_eshaperateobj                                                    = 0x2b16,
  wsa_qos_reserved_petype                                                  = 0x2b17,
  wsa_secure_host_not_found                                                = 0x2b18,
  wsa_ipsec_name_policy_error                                              = 0x2b19,
 };                                                                    
 inline constexpr std::array<std::pair<system_error_code, std::string_view>, 2330> SYSTEM_ERROR_CODE_LOOKUP {
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_success,                      
   "system_error_code::error_success"                      
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_function,
   "system_error_code::error_invalid_function"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_file_not_found,
   "system_error_code::error_file_not_found"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_path_not_found,
   "system_error_code::error_path_not_found"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_too_many_open_files,
   "system_error_code::error_too_many_open_files"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_access_denied,
   "system_error_code::error_access_denied"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_handle,
   "system_error_code::error_invalid_handle"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_arena_trashed,
   "system_error_code::error_arena_trashed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_not_enough_memory,
   "system_error_code::error_not_enough_memory"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_block,
   "system_error_code::error_invalid_block"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_bad_environment,
   "system_error_code::error_bad_environment"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_bad_format,
   "system_error_code::error_bad_format"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_access,
   "system_error_code::error_invalid_access"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_data,
   "system_error_code::error_invalid_data"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_outofmemory,
   "system_error_code::error_outofmemory"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_drive,
   "system_error_code::error_invalid_drive"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_current_directory,
   "system_error_code::error_current_directory"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_not_same_device,
   "system_error_code::error_not_same_device"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_no_more_files,
   "system_error_code::error_no_more_files"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_write_protect,
   "system_error_code::error_write_protect"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_bad_unit,
   "system_error_code::error_bad_unit"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_not_ready,
   "system_error_code::error_not_ready"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_bad_command,
   "system_error_code::error_bad_command"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_crc,
   "system_error_code::error_crc"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_bad_length,
   "system_error_code::error_bad_length"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_seek,
   "system_error_code::error_seek"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_not_dos_disk,
   "system_error_code::error_not_dos_disk"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_sector_not_found,
   "system_error_code::error_sector_not_found"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_out_of_paper,
   "system_error_code::error_out_of_paper"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_write_fault,
   "system_error_code::error_write_fault"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_read_fault,
   "system_error_code::error_read_fault"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_gen_failure,
   "system_error_code::error_gen_failure"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_sharing_violation,
   "system_error_code::error_sharing_violation"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_lock_violation,
   "system_error_code::error_lock_violation"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_wrong_disk,
   "system_error_code::error_wrong_disk"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_sharing_buffer_exceeded,
   "system_error_code::error_sharing_buffer_exceeded"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_handle_eof,
   "system_error_code::error_handle_eof"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_handle_disk_full,
   "system_error_code::error_handle_disk_full"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_not_supported,
   "system_error_code::error_not_supported"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_rem_not_list,
   "system_error_code::error_rem_not_list"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_dup_name,
   "system_error_code::error_dup_name"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_bad_netpath,
   "system_error_code::error_bad_netpath"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_network_busy,
   "system_error_code::error_network_busy"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_dev_not_exist,
   "system_error_code::error_dev_not_exist"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_too_many_cmds,
   "system_error_code::error_too_many_cmds"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_adap_hdw_err,
   "system_error_code::error_adap_hdw_err"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_bad_net_resp,
   "system_error_code::error_bad_net_resp"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_unexp_net_err,
   "system_error_code::error_unexp_net_err"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_bad_rem_adap,
   "system_error_code::error_bad_rem_adap"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_printq_full,
   "system_error_code::error_printq_full"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_no_spool_space,
   "system_error_code::error_no_spool_space"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_print_cancelled,
   "system_error_code::error_print_cancelled"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_netname_deleted,
   "system_error_code::error_netname_deleted"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_network_access_denied,
   "system_error_code::error_network_access_denied"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_bad_dev_type,
   "system_error_code::error_bad_dev_type"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_bad_net_name,
   "system_error_code::error_bad_net_name"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_too_many_names,
   "system_error_code::error_too_many_names"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_too_many_sess,
   "system_error_code::error_too_many_sess"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_sharing_paused,
   "system_error_code::error_sharing_paused"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_req_not_accep,
   "system_error_code::error_req_not_accep"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_redir_paused,
   "system_error_code::error_redir_paused"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_file_exists,
   "system_error_code::error_file_exists"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cannot_make,
   "system_error_code::error_cannot_make"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_fail_i24,
   "system_error_code::error_fail_i24"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_out_of_structures,
   "system_error_code::error_out_of_structures"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_already_assigned,
   "system_error_code::error_already_assigned"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_password,
   "system_error_code::error_invalid_password"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_parameter,
   "system_error_code::error_invalid_parameter"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_net_write_fault,
   "system_error_code::error_net_write_fault"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_no_proc_slots,
   "system_error_code::error_no_proc_slots"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_too_many_semaphores,
   "system_error_code::error_too_many_semaphores"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_excl_sem_already_owned,
   "system_error_code::error_excl_sem_already_owned"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_sem_is_set,
   "system_error_code::error_sem_is_set"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_too_many_sem_requests,
   "system_error_code::error_too_many_sem_requests"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_at_interrupt_time,
   "system_error_code::error_invalid_at_interrupt_time"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_sem_owner_died,
   "system_error_code::error_sem_owner_died"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_sem_user_limit,
   "system_error_code::error_sem_user_limit"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_disk_change,
   "system_error_code::error_disk_change"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_drive_locked,
   "system_error_code::error_drive_locked"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_broken_pipe,
   "system_error_code::error_broken_pipe"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_open_failed,
   "system_error_code::error_open_failed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_buffer_overflow,
   "system_error_code::error_buffer_overflow"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_disk_full,
   "system_error_code::error_disk_full"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_no_more_search_handles,
   "system_error_code::error_no_more_search_handles"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_target_handle,
   "system_error_code::error_invalid_target_handle"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_category,
   "system_error_code::error_invalid_category"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_verify_switch,
   "system_error_code::error_invalid_verify_switch"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_bad_driver_level,
   "system_error_code::error_bad_driver_level"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_call_not_implemented,
   "system_error_code::error_call_not_implemented"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_sem_timeout,
   "system_error_code::error_sem_timeout"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_insufficient_buffer,
   "system_error_code::error_insufficient_buffer"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_name,
   "system_error_code::error_invalid_name"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_level,
   "system_error_code::error_invalid_level"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_no_volume_label,
   "system_error_code::error_no_volume_label"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_mod_not_found,
   "system_error_code::error_mod_not_found"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_proc_not_found,
   "system_error_code::error_proc_not_found"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_wait_no_children,
   "system_error_code::error_wait_no_children"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_child_not_complete,
   "system_error_code::error_child_not_complete"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_direct_access_handle,
   "system_error_code::error_direct_access_handle"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_negative_seek,
   "system_error_code::error_negative_seek"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_seek_on_device,
   "system_error_code::error_seek_on_device"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_is_join_target,
   "system_error_code::error_is_join_target"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_is_joined,
   "system_error_code::error_is_joined"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_is_substed,
   "system_error_code::error_is_substed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_not_joined,
   "system_error_code::error_not_joined"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_not_substed,
   "system_error_code::error_not_substed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_join_to_join,
   "system_error_code::error_join_to_join"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_subst_to_subst,
   "system_error_code::error_subst_to_subst"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_join_to_subst,
   "system_error_code::error_join_to_subst"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_subst_to_join,
   "system_error_code::error_subst_to_join"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_busy_drive,
   "system_error_code::error_busy_drive"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_same_drive,
   "system_error_code::error_same_drive"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_dir_not_root,
   "system_error_code::error_dir_not_root"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_dir_not_empty,
   "system_error_code::error_dir_not_empty"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_is_subst_path,
   "system_error_code::error_is_subst_path"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_is_join_path,
   "system_error_code::error_is_join_path"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_path_busy,
   "system_error_code::error_path_busy"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_is_subst_target,
   "system_error_code::error_is_subst_target"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_system_trace,
   "system_error_code::error_system_trace"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_event_count,
   "system_error_code::error_invalid_event_count"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_too_many_muxwaiters,
   "system_error_code::error_too_many_muxwaiters"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_list_format,
   "system_error_code::error_invalid_list_format"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_label_too_long,
   "system_error_code::error_label_too_long"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_too_many_tcbs,
   "system_error_code::error_too_many_tcbs"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_signal_refused,
   "system_error_code::error_signal_refused"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_discarded,
   "system_error_code::error_discarded"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_not_locked,
   "system_error_code::error_not_locked"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_bad_threadid_addr,
   "system_error_code::error_bad_threadid_addr"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_bad_arguments,
   "system_error_code::error_bad_arguments"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_bad_pathname,
   "system_error_code::error_bad_pathname"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_signal_pending,
   "system_error_code::error_signal_pending"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_max_thrds_reached,
   "system_error_code::error_max_thrds_reached"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_lock_failed,
   "system_error_code::error_lock_failed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_busy,
   "system_error_code::error_busy"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_device_support_in_progress,
   "system_error_code::error_device_support_in_progress"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cancel_violation,
   "system_error_code::error_cancel_violation"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_atomic_locks_not_supported,
   "system_error_code::error_atomic_locks_not_supported"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_segment_number,
   "system_error_code::error_invalid_segment_number"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_ordinal,
   "system_error_code::error_invalid_ordinal"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_already_exists,
   "system_error_code::error_already_exists"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_flag_number,
   "system_error_code::error_invalid_flag_number"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_sem_not_found,
   "system_error_code::error_sem_not_found"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_starting_codeseg,
   "system_error_code::error_invalid_starting_codeseg"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_stackseg,
   "system_error_code::error_invalid_stackseg"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_moduletype,
   "system_error_code::error_invalid_moduletype"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_exe_signature,
   "system_error_code::error_invalid_exe_signature"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_exe_marked_invalid,
   "system_error_code::error_exe_marked_invalid"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_bad_exe_format,
   "system_error_code::error_bad_exe_format"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_iterated_data_exceeds_64k,
   "system_error_code::error_iterated_data_exceeds_64k"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_minallocsize,
   "system_error_code::error_invalid_minallocsize"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_dynlink_from_invalid_ring,
   "system_error_code::error_dynlink_from_invalid_ring"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_iopl_not_enabled,
   "system_error_code::error_iopl_not_enabled"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_segdpl,
   "system_error_code::error_invalid_segdpl"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_autodataseg_exceeds_64k,
   "system_error_code::error_autodataseg_exceeds_64k"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ring2seg_must_be_movable,
   "system_error_code::error_ring2seg_must_be_movable"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_reloc_chain_xeeds_seglim,
   "system_error_code::error_reloc_chain_xeeds_seglim"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_infloop_in_reloc_chain,
   "system_error_code::error_infloop_in_reloc_chain"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_envvar_not_found,
   "system_error_code::error_envvar_not_found"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_no_signal_sent,
   "system_error_code::error_no_signal_sent"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_filename_exced_range,
   "system_error_code::error_filename_exced_range"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ring2_stack_in_use,
   "system_error_code::error_ring2_stack_in_use"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_meta_expansion_too_long,
   "system_error_code::error_meta_expansion_too_long"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_signal_number,
   "system_error_code::error_invalid_signal_number"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_thread_1_inactive,
   "system_error_code::error_thread_1_inactive"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_locked,
   "system_error_code::error_locked"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_too_many_modules,
   "system_error_code::error_too_many_modules"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_nesting_not_allowed,
   "system_error_code::error_nesting_not_allowed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_exe_machine_type_mismatch,
   "system_error_code::error_exe_machine_type_mismatch"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_exe_cannot_modify_signed_binary,
   "system_error_code::error_exe_cannot_modify_signed_binary"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_exe_cannot_modify_strong_signed_binary,
   "system_error_code::error_exe_cannot_modify_strong_signed_binary"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_file_checked_out,
   "system_error_code::error_file_checked_out"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_checkout_required,
   "system_error_code::error_checkout_required"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_bad_file_type,
   "system_error_code::error_bad_file_type"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_file_too_large,
   "system_error_code::error_file_too_large"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_forms_auth_required,
   "system_error_code::error_forms_auth_required"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_virus_infected,
   "system_error_code::error_virus_infected"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_virus_deleted,
   "system_error_code::error_virus_deleted"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_pipe_local,
   "system_error_code::error_pipe_local"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_bad_pipe,
   "system_error_code::error_bad_pipe"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_pipe_busy,
   "system_error_code::error_pipe_busy"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_no_data,
   "system_error_code::error_no_data"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_pipe_not_connected,
   "system_error_code::error_pipe_not_connected"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_more_data,
   "system_error_code::error_more_data"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_vc_disconnected,
   "system_error_code::error_vc_disconnected"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_ea_name,
   "system_error_code::error_invalid_ea_name"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ea_list_inconsistent,
   "system_error_code::error_ea_list_inconsistent"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wait_timeout,
   "system_error_code::wait_timeout"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_no_more_items,
   "system_error_code::error_no_more_items"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cannot_copy,
   "system_error_code::error_cannot_copy"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_directory,
   "system_error_code::error_directory"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_eas_didnt_fit,
   "system_error_code::error_eas_didnt_fit"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ea_file_corrupt,
   "system_error_code::error_ea_file_corrupt"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ea_table_full,
   "system_error_code::error_ea_table_full"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_ea_handle,
   "system_error_code::error_invalid_ea_handle"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_eas_not_supported,
   "system_error_code::error_eas_not_supported"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_not_owner,
   "system_error_code::error_not_owner"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_too_many_posts,
   "system_error_code::error_too_many_posts"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_partial_copy,
   "system_error_code::error_partial_copy"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_oplock_not_granted,
   "system_error_code::error_oplock_not_granted"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_oplock_protocol,
   "system_error_code::error_invalid_oplock_protocol"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_disk_too_fragmented,
   "system_error_code::error_disk_too_fragmented"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_delete_pending,
   "system_error_code::error_delete_pending"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_incompatible_with_global_short_name_registry_setting,
   "system_error_code::error_incompatible_with_global_short_name_registry_setting"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_short_names_not_enabled_on_volume,
   "system_error_code::error_short_names_not_enabled_on_volume"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_security_stream_is_inconsistent,
   "system_error_code::error_security_stream_is_inconsistent"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_lock_range,
   "system_error_code::error_invalid_lock_range"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_image_subsystem_not_present,
   "system_error_code::error_image_subsystem_not_present"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_notification_guid_already_defined,
   "system_error_code::error_notification_guid_already_defined"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_exception_handler,
   "system_error_code::error_invalid_exception_handler"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_duplicate_privileges,
   "system_error_code::error_duplicate_privileges"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_no_ranges_processed,
   "system_error_code::error_no_ranges_processed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_not_allowed_on_system_file,
   "system_error_code::error_not_allowed_on_system_file"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_disk_resources_exhausted,
   "system_error_code::error_disk_resources_exhausted"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_token,
   "system_error_code::error_invalid_token"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_device_feature_not_supported,
   "system_error_code::error_device_feature_not_supported"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_mr_mid_not_found,
   "system_error_code::error_mr_mid_not_found"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_scope_not_found,
   "system_error_code::error_scope_not_found"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_undefined_scope,
   "system_error_code::error_undefined_scope"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_cap,
   "system_error_code::error_invalid_cap"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_device_unreachable,
   "system_error_code::error_device_unreachable"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_device_no_resources,
   "system_error_code::error_device_no_resources"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_data_checksum_error,
   "system_error_code::error_data_checksum_error"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_intermixed_kernel_ea_operation,
   "system_error_code::error_intermixed_kernel_ea_operation"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_file_level_trim_not_supported,
   "system_error_code::error_file_level_trim_not_supported"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_offset_alignment_violation,
   "system_error_code::error_offset_alignment_violation"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_field_in_parameter_list,
   "system_error_code::error_invalid_field_in_parameter_list"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_operation_in_progress,
   "system_error_code::error_operation_in_progress"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_bad_device_path,
   "system_error_code::error_bad_device_path"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_too_many_descriptors,
   "system_error_code::error_too_many_descriptors"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_scrub_data_disabled,
   "system_error_code::error_scrub_data_disabled"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_not_redundant_storage,
   "system_error_code::error_not_redundant_storage"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_resident_file_not_supported,
   "system_error_code::error_resident_file_not_supported"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_compressed_file_not_supported,
   "system_error_code::error_compressed_file_not_supported"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_directory_not_supported,
   "system_error_code::error_directory_not_supported"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_not_read_from_copy,
   "system_error_code::error_not_read_from_copy"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_fail_noaction_reboot,
   "system_error_code::error_fail_noaction_reboot"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_fail_shutdown,
   "system_error_code::error_fail_shutdown"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_fail_restart,
   "system_error_code::error_fail_restart"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_max_sessions_reached,
   "system_error_code::error_max_sessions_reached"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_thread_mode_already_background,
   "system_error_code::error_thread_mode_already_background"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_thread_mode_not_background,
   "system_error_code::error_thread_mode_not_background"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_process_mode_already_background,
   "system_error_code::error_process_mode_already_background"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_process_mode_not_background,
   "system_error_code::error_process_mode_not_background"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_address,
   "system_error_code::error_invalid_address"
  },
   std::pair<system_error_code, std::string_view>{
   system_error_code::error_user_profile_load,
   "system_error_code::error_user_profile_load"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_arithmetic_overflow,
   "system_error_code::error_arithmetic_overflow"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_pipe_connected,
   "system_error_code::error_pipe_connected"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_pipe_listening,
   "system_error_code::error_pipe_listening"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_verifier_stop,
   "system_error_code::error_verifier_stop"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_abios_error,
   "system_error_code::error_abios_error"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_wx86_warning,
   "system_error_code::error_wx86_warning"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_wx86_error,
   "system_error_code::error_wx86_error"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_timer_not_canceled,
   "system_error_code::error_timer_not_canceled"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_unwind,
   "system_error_code::error_unwind"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_bad_stack,
   "system_error_code::error_bad_stack"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_unwind_target,
   "system_error_code::error_invalid_unwind_target"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_port_attributes,
   "system_error_code::error_invalid_port_attributes"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_port_message_too_long,
   "system_error_code::error_port_message_too_long"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_quota_lower,
   "system_error_code::error_invalid_quota_lower"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_device_already_attached,
   "system_error_code::error_device_already_attached"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_instruction_misalignment,
   "system_error_code::error_instruction_misalignment"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_profiling_not_started,
   "system_error_code::error_profiling_not_started"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_profiling_not_stopped,
   "system_error_code::error_profiling_not_stopped"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_could_not_interpret,
   "system_error_code::error_could_not_interpret"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_profiling_at_limit,
   "system_error_code::error_profiling_at_limit"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cant_wait,
   "system_error_code::error_cant_wait"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cant_terminate_self,
   "system_error_code::error_cant_terminate_self"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_unexpected_mm_create_err,
   "system_error_code::error_unexpected_mm_create_err"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_unexpected_mm_map_error,
   "system_error_code::error_unexpected_mm_map_error"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_unexpected_mm_extend_err,
   "system_error_code::error_unexpected_mm_extend_err"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_bad_function_table,
   "system_error_code::error_bad_function_table"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_no_guid_translation,
   "system_error_code::error_no_guid_translation"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_ldt_size,
   "system_error_code::error_invalid_ldt_size"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_ldt_offset,
   "system_error_code::error_invalid_ldt_offset"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_ldt_descriptor,
   "system_error_code::error_invalid_ldt_descriptor"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_too_many_threads,
   "system_error_code::error_too_many_threads"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_thread_not_in_process,
   "system_error_code::error_thread_not_in_process"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_pagefile_quota_exceeded,
   "system_error_code::error_pagefile_quota_exceeded"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_logon_server_conflict,
   "system_error_code::error_logon_server_conflict"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_synchronization_required,
   "system_error_code::error_synchronization_required"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_net_open_failed,
   "system_error_code::error_net_open_failed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_io_privilege_failed,
   "system_error_code::error_io_privilege_failed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_control_c_exit,
   "system_error_code::error_control_c_exit"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_missing_systemfile,
   "system_error_code::error_missing_systemfile"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_unhandled_exception,
   "system_error_code::error_unhandled_exception"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_app_init_failure,
   "system_error_code::error_app_init_failure"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_pagefile_create_failed,
   "system_error_code::error_pagefile_create_failed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_image_hash,
   "system_error_code::error_invalid_image_hash"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_no_pagefile,
   "system_error_code::error_no_pagefile"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_illegal_float_context,
   "system_error_code::error_illegal_float_context"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_no_event_pair,
   "system_error_code::error_no_event_pair"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_domain_ctrlr_config_error,
   "system_error_code::error_domain_ctrlr_config_error"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_illegal_character,
   "system_error_code::error_illegal_character"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_undefined_character,
   "system_error_code::error_undefined_character"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_floppy_volume,
   "system_error_code::error_floppy_volume"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_bios_failed_to_connect_interrupt,
   "system_error_code::error_bios_failed_to_connect_interrupt"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_backup_controller,
   "system_error_code::error_backup_controller"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_mutant_limit_exceeded,
   "system_error_code::error_mutant_limit_exceeded"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_fs_driver_required,
   "system_error_code::error_fs_driver_required"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cannot_load_registry_file,
   "system_error_code::error_cannot_load_registry_file"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_debug_attach_failed,
   "system_error_code::error_debug_attach_failed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_system_process_terminated,
   "system_error_code::error_system_process_terminated"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_data_not_accepted,
   "system_error_code::error_data_not_accepted"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_vdm_hard_error,
   "system_error_code::error_vdm_hard_error"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_driver_cancel_timeout,
   "system_error_code::error_driver_cancel_timeout"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_reply_message_mismatch,
   "system_error_code::error_reply_message_mismatch"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_lost_writebehind_data,
   "system_error_code::error_lost_writebehind_data"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_client_server_parameters_invalid,
   "system_error_code::error_client_server_parameters_invalid"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_not_tiny_stream,
   "system_error_code::error_not_tiny_stream"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_stack_overflow_read,
   "system_error_code::error_stack_overflow_read"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_convert_to_large,
   "system_error_code::error_convert_to_large"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_found_out_of_scope,
   "system_error_code::error_found_out_of_scope"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_allocate_bucket,
   "system_error_code::error_allocate_bucket"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_marshall_overflow,
   "system_error_code::error_marshall_overflow"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_variant,
   "system_error_code::error_invalid_variant"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_bad_compression_buffer,
   "system_error_code::error_bad_compression_buffer"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_audit_failed,
   "system_error_code::error_audit_failed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_timer_resolution_not_set,
   "system_error_code::error_timer_resolution_not_set"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_insufficient_logon_info,
   "system_error_code::error_insufficient_logon_info"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_bad_dll_entrypoint,
   "system_error_code::error_bad_dll_entrypoint"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_bad_service_entrypoint,
   "system_error_code::error_bad_service_entrypoint"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ip_address_conflict1,
   "system_error_code::error_ip_address_conflict1"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ip_address_conflict2,
   "system_error_code::error_ip_address_conflict2"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_registry_quota_limit,
   "system_error_code::error_registry_quota_limit"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_no_callback_active,
   "system_error_code::error_no_callback_active"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_pwd_too_short,
   "system_error_code::error_pwd_too_short"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_pwd_too_recent,
   "system_error_code::error_pwd_too_recent"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_pwd_history_conflict,
   "system_error_code::error_pwd_history_conflict"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_unsupported_compression,
   "system_error_code::error_unsupported_compression"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_hw_profile,
   "system_error_code::error_invalid_hw_profile"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_plugplay_device_path,
   "system_error_code::error_invalid_plugplay_device_path"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_quota_list_inconsistent,
   "system_error_code::error_quota_list_inconsistent"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_evaluation_expiration,
   "system_error_code::error_evaluation_expiration"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_illegal_dll_relocation,
   "system_error_code::error_illegal_dll_relocation"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_dll_init_failed_logoff,
   "system_error_code::error_dll_init_failed_logoff"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_validate_continue,
   "system_error_code::error_validate_continue"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_no_more_matches,
   "system_error_code::error_no_more_matches"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_range_list_conflict,
   "system_error_code::error_range_list_conflict"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_server_sid_mismatch,
   "system_error_code::error_server_sid_mismatch"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cant_enable_deny_only,
   "system_error_code::error_cant_enable_deny_only"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_float_multiple_faults,
   "system_error_code::error_float_multiple_faults"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_float_multiple_traps,
   "system_error_code::error_float_multiple_traps"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_nointerface,
   "system_error_code::error_nointerface"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_driver_failed_sleep,
   "system_error_code::error_driver_failed_sleep"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_corrupt_system_file,
   "system_error_code::error_corrupt_system_file"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_commitment_minimum,
   "system_error_code::error_commitment_minimum"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_pnp_restart_enumeration,
   "system_error_code::error_pnp_restart_enumeration"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_system_image_bad_signature,
   "system_error_code::error_system_image_bad_signature"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_pnp_reboot_required,
   "system_error_code::error_pnp_reboot_required"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_insufficient_power,
   "system_error_code::error_insufficient_power"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_multiple_fault_violation,
   "system_error_code::error_multiple_fault_violation"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_system_shutdown,
   "system_error_code::error_system_shutdown"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_port_not_set,
   "system_error_code::error_port_not_set"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_version_check_failure,
   "system_error_code::error_ds_version_check_failure"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_range_not_found,
   "system_error_code::error_range_not_found"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_not_safe_mode_driver,
   "system_error_code::error_not_safe_mode_driver"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_failed_driver_entry,
   "system_error_code::error_failed_driver_entry"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_device_enumeration_error,
   "system_error_code::error_device_enumeration_error"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_mount_point_not_resolved,
   "system_error_code::error_mount_point_not_resolved"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_device_object_parameter,
   "system_error_code::error_invalid_device_object_parameter"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_mca_occured,
   "system_error_code::error_mca_occured"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_driver_database_error,
   "system_error_code::error_driver_database_error"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_system_hive_too_large,
   "system_error_code::error_system_hive_too_large"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_driver_failed_prior_unload,
   "system_error_code::error_driver_failed_prior_unload"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_volsnap_prepare_hibernate,
   "system_error_code::error_volsnap_prepare_hibernate"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_hibernation_failure,
   "system_error_code::error_hibernation_failure"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_pwd_too_long,
   "system_error_code::error_pwd_too_long"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_file_system_limitation,
   "system_error_code::error_file_system_limitation"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_assertion_failure,
   "system_error_code::error_assertion_failure"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_acpi_error,
   "system_error_code::error_acpi_error"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_wow_assertion,
   "system_error_code::error_wow_assertion"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_pnp_bad_mps_table,
   "system_error_code::error_pnp_bad_mps_table"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_pnp_translation_failed,
   "system_error_code::error_pnp_translation_failed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_pnp_irq_translation_failed,
   "system_error_code::error_pnp_irq_translation_failed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_pnp_invalid_id,
   "system_error_code::error_pnp_invalid_id"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_wake_system_debugger,
   "system_error_code::error_wake_system_debugger"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_handles_closed,
   "system_error_code::error_handles_closed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_extraneous_information,
   "system_error_code::error_extraneous_information"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_rxact_commit_necessary,
   "system_error_code::error_rxact_commit_necessary"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_media_check,
   "system_error_code::error_media_check"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_guid_substitution_made,
   "system_error_code::error_guid_substitution_made"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_stopped_on_symlink,
   "system_error_code::error_stopped_on_symlink"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_longjump,
   "system_error_code::error_longjump"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_plugplay_query_vetoed,
   "system_error_code::error_plugplay_query_vetoed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_unwind_consolidate,
   "system_error_code::error_unwind_consolidate"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_registry_hive_recovered,
   "system_error_code::error_registry_hive_recovered"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_dll_might_be_insecure,
   "system_error_code::error_dll_might_be_insecure"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_dll_might_be_incompatible,
   "system_error_code::error_dll_might_be_incompatible"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_dbg_exception_not_handled,
   "system_error_code::error_dbg_exception_not_handled"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_dbg_reply_later,
   "system_error_code::error_dbg_reply_later"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_dbg_unable_to_provide_handle,
   "system_error_code::error_dbg_unable_to_provide_handle"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_dbg_terminate_thread,
   "system_error_code::error_dbg_terminate_thread"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_dbg_terminate_process,
   "system_error_code::error_dbg_terminate_process"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_dbg_control_c,
   "system_error_code::error_dbg_control_c"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_dbg_printexception_c,
   "system_error_code::error_dbg_printexception_c"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_dbg_ripexception,
   "system_error_code::error_dbg_ripexception"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_dbg_control_break,
   "system_error_code::error_dbg_control_break"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_dbg_command_exception,
   "system_error_code::error_dbg_command_exception"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_object_name_exists,
   "system_error_code::error_object_name_exists"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_thread_was_suspended,
   "system_error_code::error_thread_was_suspended"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_image_not_at_base,
   "system_error_code::error_image_not_at_base"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_rxact_state_created,
   "system_error_code::error_rxact_state_created"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_segment_notification,
   "system_error_code::error_segment_notification"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_bad_current_directory,
   "system_error_code::error_bad_current_directory"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ft_read_recovery_from_backup,
   "system_error_code::error_ft_read_recovery_from_backup"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ft_write_recovery,
   "system_error_code::error_ft_write_recovery"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_image_machine_type_mismatch,
   "system_error_code::error_image_machine_type_mismatch"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_receive_partial,
   "system_error_code::error_receive_partial"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_receive_expedited,
   "system_error_code::error_receive_expedited"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_receive_partial_expedited,
   "system_error_code::error_receive_partial_expedited"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_event_done,
   "system_error_code::error_event_done"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_event_pending,
   "system_error_code::error_event_pending"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_checking_file_system,
   "system_error_code::error_checking_file_system"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_fatal_app_exit,
   "system_error_code::error_fatal_app_exit"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_predefined_handle,
   "system_error_code::error_predefined_handle"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_was_unlocked,
   "system_error_code::error_was_unlocked"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_service_notification,
   "system_error_code::error_service_notification"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_was_locked,
   "system_error_code::error_was_locked"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_log_hard_error,
   "system_error_code::error_log_hard_error"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_already_win32,
   "system_error_code::error_already_win32"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_image_machine_type_mismatch_exe,
   "system_error_code::error_image_machine_type_mismatch_exe"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_no_yield_performed,
   "system_error_code::error_no_yield_performed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_timer_resume_ignored,
   "system_error_code::error_timer_resume_ignored"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_arbitration_unhandled,
   "system_error_code::error_arbitration_unhandled"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cardbus_not_supported,
   "system_error_code::error_cardbus_not_supported"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_mp_processor_mismatch,
   "system_error_code::error_mp_processor_mismatch"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_hibernated,
   "system_error_code::error_hibernated"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_resume_hibernation,
   "system_error_code::error_resume_hibernation"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_firmware_updated,
   "system_error_code::error_firmware_updated"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_drivers_leaking_locked_pages,
   "system_error_code::error_drivers_leaking_locked_pages"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_wake_system,
   "system_error_code::error_wake_system"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_wait_1,
   "system_error_code::error_wait_1"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_wait_2,
   "system_error_code::error_wait_2"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_wait_3,
   "system_error_code::error_wait_3"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_wait_63,
   "system_error_code::error_wait_63"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_abandoned_wait_0,
   "system_error_code::error_abandoned_wait_0"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_abandoned_wait_63,
   "system_error_code::error_abandoned_wait_63"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_user_apc,
   "system_error_code::error_user_apc"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_kernel_apc,
   "system_error_code::error_kernel_apc"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_alerted,
   "system_error_code::error_alerted"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_elevation_required,
   "system_error_code::error_elevation_required"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_reparse,
   "system_error_code::error_reparse"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_oplock_break_in_progress,
   "system_error_code::error_oplock_break_in_progress"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_volume_mounted,
   "system_error_code::error_volume_mounted"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_rxact_committed,
   "system_error_code::error_rxact_committed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_notify_cleanup,
   "system_error_code::error_notify_cleanup"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_primary_transport_connect_failed,
   "system_error_code::error_primary_transport_connect_failed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_page_fault_transition,
   "system_error_code::error_page_fault_transition"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_page_fault_demand_zero,
   "system_error_code::error_page_fault_demand_zero"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_page_fault_copy_on_write,
   "system_error_code::error_page_fault_copy_on_write"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_page_fault_guard_page,
   "system_error_code::error_page_fault_guard_page"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_page_fault_paging_file,
   "system_error_code::error_page_fault_paging_file"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cache_page_locked,
   "system_error_code::error_cache_page_locked"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_crash_dump,
   "system_error_code::error_crash_dump"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_buffer_all_zeros,
   "system_error_code::error_buffer_all_zeros"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_reparse_object,
   "system_error_code::error_reparse_object"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_resource_requirements_changed,
   "system_error_code::error_resource_requirements_changed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_translation_complete,
   "system_error_code::error_translation_complete"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_nothing_to_terminate,
   "system_error_code::error_nothing_to_terminate"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_process_not_in_job,
   "system_error_code::error_process_not_in_job"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_process_in_job,
   "system_error_code::error_process_in_job"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_volsnap_hibernate_ready,
   "system_error_code::error_volsnap_hibernate_ready"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_fsfilter_op_completed_successfully,
   "system_error_code::error_fsfilter_op_completed_successfully"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_interrupt_vector_already_connected,
   "system_error_code::error_interrupt_vector_already_connected"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_interrupt_still_connected,
   "system_error_code::error_interrupt_still_connected"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_wait_for_oplock,
   "system_error_code::error_wait_for_oplock"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_dbg_exception_handled,
   "system_error_code::error_dbg_exception_handled"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_dbg_continue,
   "system_error_code::error_dbg_continue"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_callback_pop_stack,
   "system_error_code::error_callback_pop_stack"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_compression_disabled,
   "system_error_code::error_compression_disabled"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cantfetchbackwards,
   "system_error_code::error_cantfetchbackwards"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cantscrollbackwards,
   "system_error_code::error_cantscrollbackwards"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_rowsnotreleased,
   "system_error_code::error_rowsnotreleased"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_bad_accessor_flags,
   "system_error_code::error_bad_accessor_flags"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_errors_encountered,
   "system_error_code::error_errors_encountered"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_not_capable,
   "system_error_code::error_not_capable"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_request_out_of_sequence,
   "system_error_code::error_request_out_of_sequence"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_version_parse_error,
   "system_error_code::error_version_parse_error"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_badstartposition,
   "system_error_code::error_badstartposition"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_memory_hardware,
   "system_error_code::error_memory_hardware"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_disk_repair_disabled,
   "system_error_code::error_disk_repair_disabled"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_insufficient_resource_for_specified_shared_section_size,
   "system_error_code::error_insufficient_resource_for_specified_shared_section_size"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_system_powerstate_transition,
   "system_error_code::error_system_powerstate_transition"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_system_powerstate_complex_transition,
   "system_error_code::error_system_powerstate_complex_transition"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_mca_exception,
   "system_error_code::error_mca_exception"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_access_audit_by_policy,
   "system_error_code::error_access_audit_by_policy"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_access_disabled_no_safer_ui_by_policy,
   "system_error_code::error_access_disabled_no_safer_ui_by_policy"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_abandon_hiberfile,
   "system_error_code::error_abandon_hiberfile"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_lost_writebehind_data_network_disconnected,
   "system_error_code::error_lost_writebehind_data_network_disconnected"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_lost_writebehind_data_network_server_error,
   "system_error_code::error_lost_writebehind_data_network_server_error"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_lost_writebehind_data_local_disk_error,
   "system_error_code::error_lost_writebehind_data_local_disk_error"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_bad_mcfg_table,
   "system_error_code::error_bad_mcfg_table"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_disk_repair_redirected,
   "system_error_code::error_disk_repair_redirected"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_disk_repair_unsuccessful,
   "system_error_code::error_disk_repair_unsuccessful"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_corrupt_log_overfull,
   "system_error_code::error_corrupt_log_overfull"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_corrupt_log_corrupted,
   "system_error_code::error_corrupt_log_corrupted"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_corrupt_log_unavailable,
   "system_error_code::error_corrupt_log_unavailable"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_corrupt_log_deleted_full,
   "system_error_code::error_corrupt_log_deleted_full"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_corrupt_log_cleared,
   "system_error_code::error_corrupt_log_cleared"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_orphan_name_exhausted,
   "system_error_code::error_orphan_name_exhausted"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_oplock_switched_to_new_handle,
   "system_error_code::error_oplock_switched_to_new_handle"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cannot_grant_requested_oplock,
   "system_error_code::error_cannot_grant_requested_oplock"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cannot_break_oplock,
   "system_error_code::error_cannot_break_oplock"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_oplock_handle_closed,
   "system_error_code::error_oplock_handle_closed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_no_ace_condition,
   "system_error_code::error_no_ace_condition"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_ace_condition,
   "system_error_code::error_invalid_ace_condition"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_file_handle_revoked,
   "system_error_code::error_file_handle_revoked"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_image_at_different_base,
   "system_error_code::error_image_at_different_base"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ea_access_denied,
   "system_error_code::error_ea_access_denied"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_operation_aborted,
   "system_error_code::error_operation_aborted"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_io_incomplete,
   "system_error_code::error_io_incomplete"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_io_pending,
   "system_error_code::error_io_pending"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_noaccess,
   "system_error_code::error_noaccess"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_swaperror,
   "system_error_code::error_swaperror"
  },
   std::pair<system_error_code, std::string_view>{
   system_error_code::error_stack_overflow,
   "system_error_code::error_stack_overflow"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_message,
   "system_error_code::error_invalid_message"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_can_not_complete,
   "system_error_code::error_can_not_complete"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_flags,
   "system_error_code::error_invalid_flags"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_unrecognized_volume,
   "system_error_code::error_unrecognized_volume"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_file_invalid,
   "system_error_code::error_file_invalid"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_fullscreen_mode,
   "system_error_code::error_fullscreen_mode"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_no_token,
   "system_error_code::error_no_token"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_baddb,
   "system_error_code::error_baddb"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_badkey,
   "system_error_code::error_badkey"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cantopen,
   "system_error_code::error_cantopen"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cantread,
   "system_error_code::error_cantread"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cantwrite,
   "system_error_code::error_cantwrite"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_registry_recovered,
   "system_error_code::error_registry_recovered"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_registry_corrupt,
   "system_error_code::error_registry_corrupt"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_registry_io_failed,
   "system_error_code::error_registry_io_failed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_not_registry_file,
   "system_error_code::error_not_registry_file"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_key_deleted,
   "system_error_code::error_key_deleted"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_no_log_space,
   "system_error_code::error_no_log_space"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_key_has_children,
   "system_error_code::error_key_has_children"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_child_must_be_volatile,
   "system_error_code::error_child_must_be_volatile"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_notify_enum_dir,
   "system_error_code::error_notify_enum_dir"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_dependent_services_running,
   "system_error_code::error_dependent_services_running"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_service_control,
   "system_error_code::error_invalid_service_control"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_service_request_timeout,
   "system_error_code::error_service_request_timeout"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_service_no_thread,
   "system_error_code::error_service_no_thread"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_service_database_locked,
   "system_error_code::error_service_database_locked"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_service_already_running,
   "system_error_code::error_service_already_running"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_service_account,
   "system_error_code::error_invalid_service_account"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_service_disabled,
   "system_error_code::error_service_disabled"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_circular_dependency,
   "system_error_code::error_circular_dependency"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_service_does_not_exist,
   "system_error_code::error_service_does_not_exist"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_service_cannot_accept_ctrl,
   "system_error_code::error_service_cannot_accept_ctrl"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_service_not_active,
   "system_error_code::error_service_not_active"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_failed_service_controller_connect,
   "system_error_code::error_failed_service_controller_connect"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_exception_in_service,
   "system_error_code::error_exception_in_service"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_database_does_not_exist,
   "system_error_code::error_database_does_not_exist"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_service_specific_error,
   "system_error_code::error_service_specific_error"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_process_aborted,
   "system_error_code::error_process_aborted"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_service_dependency_fail,
   "system_error_code::error_service_dependency_fail"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_service_logon_failed,
   "system_error_code::error_service_logon_failed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_service_start_hang,
   "system_error_code::error_service_start_hang"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_service_lock,
   "system_error_code::error_invalid_service_lock"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_service_marked_for_delete,
   "system_error_code::error_service_marked_for_delete"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_service_exists,
   "system_error_code::error_service_exists"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_already_running_lkg,
   "system_error_code::error_already_running_lkg"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_service_dependency_deleted,
   "system_error_code::error_service_dependency_deleted"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_boot_already_accepted,
   "system_error_code::error_boot_already_accepted"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_service_never_started,
   "system_error_code::error_service_never_started"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_duplicate_service_name,
   "system_error_code::error_duplicate_service_name"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_different_service_account,
   "system_error_code::error_different_service_account"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cannot_detect_driver_failure,
   "system_error_code::error_cannot_detect_driver_failure"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cannot_detect_process_abort,
   "system_error_code::error_cannot_detect_process_abort"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_no_recovery_program,
   "system_error_code::error_no_recovery_program"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_service_not_in_exe,
   "system_error_code::error_service_not_in_exe"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_not_safeboot_service,
   "system_error_code::error_not_safeboot_service"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_end_of_media,
   "system_error_code::error_end_of_media"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_filemark_detected,
   "system_error_code::error_filemark_detected"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_beginning_of_media,
   "system_error_code::error_beginning_of_media"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_setmark_detected,
   "system_error_code::error_setmark_detected"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_no_data_detected,
   "system_error_code::error_no_data_detected"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_partition_failure,
   "system_error_code::error_partition_failure"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_block_length,
   "system_error_code::error_invalid_block_length"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_device_not_partitioned,
   "system_error_code::error_device_not_partitioned"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_unable_to_lock_media,
   "system_error_code::error_unable_to_lock_media"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_unable_to_unload_media,
   "system_error_code::error_unable_to_unload_media"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_media_changed,
   "system_error_code::error_media_changed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_bus_reset,
   "system_error_code::error_bus_reset"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_no_media_in_drive,
   "system_error_code::error_no_media_in_drive"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_no_unicode_translation,
   "system_error_code::error_no_unicode_translation"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_dll_init_failed,
   "system_error_code::error_dll_init_failed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_shutdown_in_progress,
   "system_error_code::error_shutdown_in_progress"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_no_shutdown_in_progress,
   "system_error_code::error_no_shutdown_in_progress"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_io_device,
   "system_error_code::error_io_device"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_serial_no_device,
   "system_error_code::error_serial_no_device"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_irq_busy,
   "system_error_code::error_irq_busy"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_more_writes,
   "system_error_code::error_more_writes"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_counter_timeout,
   "system_error_code::error_counter_timeout"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_floppy_id_mark_not_found,
   "system_error_code::error_floppy_id_mark_not_found"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_floppy_wrong_cylinder,
   "system_error_code::error_floppy_wrong_cylinder"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_floppy_unknown_error,
   "system_error_code::error_floppy_unknown_error"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_floppy_bad_registers,
   "system_error_code::error_floppy_bad_registers"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_disk_recalibrate_failed,
   "system_error_code::error_disk_recalibrate_failed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_disk_operation_failed,
   "system_error_code::error_disk_operation_failed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_disk_reset_failed,
   "system_error_code::error_disk_reset_failed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_eom_overflow,
   "system_error_code::error_eom_overflow"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_not_enough_server_memory,
   "system_error_code::error_not_enough_server_memory"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_possible_deadlock,
   "system_error_code::error_possible_deadlock"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_mapped_alignment,
   "system_error_code::error_mapped_alignment"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_set_power_state_vetoed,
   "system_error_code::error_set_power_state_vetoed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_set_power_state_failed,
   "system_error_code::error_set_power_state_failed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_too_many_links,
   "system_error_code::error_too_many_links"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_old_win_version,
   "system_error_code::error_old_win_version"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_app_wrong_os,
   "system_error_code::error_app_wrong_os"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_single_instance_app,
   "system_error_code::error_single_instance_app"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_rmode_app,
   "system_error_code::error_rmode_app"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_dll,
   "system_error_code::error_invalid_dll"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_no_association,
   "system_error_code::error_no_association"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_dde_fail,
   "system_error_code::error_dde_fail"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_dll_not_found,
   "system_error_code::error_dll_not_found"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_no_more_user_handles,
   "system_error_code::error_no_more_user_handles"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_message_sync_only,
   "system_error_code::error_message_sync_only"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_source_element_empty,
   "system_error_code::error_source_element_empty"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_destination_element_full,
   "system_error_code::error_destination_element_full"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_illegal_element_address,
   "system_error_code::error_illegal_element_address"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_magazine_not_present,
   "system_error_code::error_magazine_not_present"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_device_reinitialization_needed,
   "system_error_code::error_device_reinitialization_needed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_device_requires_cleaning,
   "system_error_code::error_device_requires_cleaning"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_device_door_open,
   "system_error_code::error_device_door_open"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_device_not_connected,
   "system_error_code::error_device_not_connected"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_not_found,
   "system_error_code::error_not_found"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_no_match,
   "system_error_code::error_no_match"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_set_not_found,
   "system_error_code::error_set_not_found"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_point_not_found,
   "system_error_code::error_point_not_found"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_no_tracking_service,
   "system_error_code::error_no_tracking_service"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_no_volume_id,
   "system_error_code::error_no_volume_id"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_unable_to_remove_replaced,
   "system_error_code::error_unable_to_remove_replaced"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_unable_to_move_replacement,
   "system_error_code::error_unable_to_move_replacement"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_unable_to_move_replacement_2,
   "system_error_code::error_unable_to_move_replacement_2"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_journal_delete_in_progress,
   "system_error_code::error_journal_delete_in_progress"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_journal_not_active,
   "system_error_code::error_journal_not_active"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_potential_file_found,
   "system_error_code::error_potential_file_found"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_journal_entry_deleted,
   "system_error_code::error_journal_entry_deleted"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_shutdown_is_scheduled,
   "system_error_code::error_shutdown_is_scheduled"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_shutdown_users_logged_on,
   "system_error_code::error_shutdown_users_logged_on"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_bad_device,
   "system_error_code::error_bad_device"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_connection_unavail,
   "system_error_code::error_connection_unavail"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_device_already_remembered,
   "system_error_code::error_device_already_remembered"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_no_net_or_bad_path,
   "system_error_code::error_no_net_or_bad_path"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_bad_provider,
   "system_error_code::error_bad_provider"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cannot_open_profile,
   "system_error_code::error_cannot_open_profile"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_bad_profile,
   "system_error_code::error_bad_profile"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_not_container,
   "system_error_code::error_not_container"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_extended_error,
   "system_error_code::error_extended_error"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_groupname,
   "system_error_code::error_invalid_groupname"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_computername,
   "system_error_code::error_invalid_computername"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_eventname,
   "system_error_code::error_invalid_eventname"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_domainname,
   "system_error_code::error_invalid_domainname"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_servicename,
   "system_error_code::error_invalid_servicename"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_netname,
   "system_error_code::error_invalid_netname"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_sharename,
   "system_error_code::error_invalid_sharename"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_passwordname,
   "system_error_code::error_invalid_passwordname"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_messagename,
   "system_error_code::error_invalid_messagename"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_messagedest,
   "system_error_code::error_invalid_messagedest"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_session_credential_conflict,
   "system_error_code::error_session_credential_conflict"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_remote_session_limit_exceeded,
   "system_error_code::error_remote_session_limit_exceeded"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_dup_domainname,
   "system_error_code::error_dup_domainname"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_no_network,
   "system_error_code::error_no_network"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cancelled,
   "system_error_code::error_cancelled"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_user_mapped_file,
   "system_error_code::error_user_mapped_file"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_connection_refused,
   "system_error_code::error_connection_refused"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_graceful_disconnect,
   "system_error_code::error_graceful_disconnect"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_address_already_associated,
   "system_error_code::error_address_already_associated"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_address_not_associated,
   "system_error_code::error_address_not_associated"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_connection_invalid,
   "system_error_code::error_connection_invalid"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_connection_active,
   "system_error_code::error_connection_active"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_network_unreachable,
   "system_error_code::error_network_unreachable"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_host_unreachable,
   "system_error_code::error_host_unreachable"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_protocol_unreachable,
   "system_error_code::error_protocol_unreachable"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_port_unreachable,
   "system_error_code::error_port_unreachable"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_request_aborted,
   "system_error_code::error_request_aborted"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_connection_aborted,
   "system_error_code::error_connection_aborted"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_retry,
   "system_error_code::error_retry"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_connection_count_limit,
   "system_error_code::error_connection_count_limit"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_login_time_restriction,
   "system_error_code::error_login_time_restriction"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_login_wksta_restriction,
   "system_error_code::error_login_wksta_restriction"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_incorrect_address,
   "system_error_code::error_incorrect_address"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_already_registered,
   "system_error_code::error_already_registered"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_service_not_found,
   "system_error_code::error_service_not_found"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_not_authenticated,
   "system_error_code::error_not_authenticated"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_not_logged_on,
   "system_error_code::error_not_logged_on"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_continue,
   "system_error_code::error_continue"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_already_initialized,
   "system_error_code::error_already_initialized"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_no_more_devices,
   "system_error_code::error_no_more_devices"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_no_such_site,
   "system_error_code::error_no_such_site"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_domain_controller_exists,
   "system_error_code::error_domain_controller_exists"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_only_if_connected,
   "system_error_code::error_only_if_connected"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_override_nochanges,
   "system_error_code::error_override_nochanges"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_bad_user_profile,
   "system_error_code::error_bad_user_profile"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_not_supported_on_sbs,
   "system_error_code::error_not_supported_on_sbs"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_server_shutdown_in_progress,
   "system_error_code::error_server_shutdown_in_progress"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_host_down,
   "system_error_code::error_host_down"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_non_account_sid,
   "system_error_code::error_non_account_sid"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_non_domain_sid,
   "system_error_code::error_non_domain_sid"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_apphelp_block,
   "system_error_code::error_apphelp_block"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_access_disabled_by_policy,
   "system_error_code::error_access_disabled_by_policy"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_reg_nat_consumption,
   "system_error_code::error_reg_nat_consumption"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cscshare_offline,
   "system_error_code::error_cscshare_offline"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_pkinit_failure,
   "system_error_code::error_pkinit_failure"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_smartcard_subsystem_failure,
   "system_error_code::error_smartcard_subsystem_failure"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_downgrade_detected,
   "system_error_code::error_downgrade_detected"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_machine_locked,
   "system_error_code::error_machine_locked"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_callback_supplied_invalid_data,
   "system_error_code::error_callback_supplied_invalid_data"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_sync_foreground_refresh_required,
   "system_error_code::error_sync_foreground_refresh_required"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_driver_blocked,
   "system_error_code::error_driver_blocked"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_import_of_non_dll,
   "system_error_code::error_invalid_import_of_non_dll"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_access_disabled_webblade,
   "system_error_code::error_access_disabled_webblade"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_access_disabled_webblade_tamper,
   "system_error_code::error_access_disabled_webblade_tamper"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_recovery_failure,
   "system_error_code::error_recovery_failure"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_already_fiber,
   "system_error_code::error_already_fiber"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_already_thread,
   "system_error_code::error_already_thread"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_stack_buffer_overrun,
   "system_error_code::error_stack_buffer_overrun"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_parameter_quota_exceeded,
   "system_error_code::error_parameter_quota_exceeded"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_debugger_inactive,
   "system_error_code::error_debugger_inactive"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_delay_load_failed,
   "system_error_code::error_delay_load_failed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_vdm_disallowed,
   "system_error_code::error_vdm_disallowed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_unidentified_error,
   "system_error_code::error_unidentified_error"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_cruntime_parameter,
   "system_error_code::error_invalid_cruntime_parameter"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_beyond_vdl,
   "system_error_code::error_beyond_vdl"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_incompatible_service_sid_type,
   "system_error_code::error_incompatible_service_sid_type"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_driver_process_terminated,
   "system_error_code::error_driver_process_terminated"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_implementation_limit,
   "system_error_code::error_implementation_limit"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_process_is_protected,
   "system_error_code::error_process_is_protected"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_service_notify_client_lagging,
   "system_error_code::error_service_notify_client_lagging"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_disk_quota_exceeded,
   "system_error_code::error_disk_quota_exceeded"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_content_blocked,
   "system_error_code::error_content_blocked"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_incompatible_service_privilege,
   "system_error_code::error_incompatible_service_privilege"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_app_hang,
   "system_error_code::error_app_hang"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_label,
   "system_error_code::error_invalid_label"
  },
   std::pair<system_error_code, std::string_view>{
   system_error_code::error_not_all_assigned,
   "system_error_code::error_not_all_assigned"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_some_not_mapped,
   "system_error_code::error_some_not_mapped"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_no_quotas_for_account,
   "system_error_code::error_no_quotas_for_account"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_local_user_session_key,
   "system_error_code::error_local_user_session_key"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_null_lm_password,
   "system_error_code::error_null_lm_password"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_unknown_revision,
   "system_error_code::error_unknown_revision"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_revision_mismatch,
   "system_error_code::error_revision_mismatch"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_owner,
   "system_error_code::error_invalid_owner"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_primary_group,
   "system_error_code::error_invalid_primary_group"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_no_impersonation_token,
   "system_error_code::error_no_impersonation_token"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cant_disable_mandatory,
   "system_error_code::error_cant_disable_mandatory"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_no_logon_servers,
   "system_error_code::error_no_logon_servers"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_no_such_logon_session,
   "system_error_code::error_no_such_logon_session"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_no_such_privilege,
   "system_error_code::error_no_such_privilege"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_privilege_not_held,
   "system_error_code::error_privilege_not_held"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_account_name,
   "system_error_code::error_invalid_account_name"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_user_exists,
   "system_error_code::error_user_exists"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_no_such_user,
   "system_error_code::error_no_such_user"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_group_exists,
   "system_error_code::error_group_exists"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_no_such_group,
   "system_error_code::error_no_such_group"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_member_in_group,
   "system_error_code::error_member_in_group"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_member_not_in_group,
   "system_error_code::error_member_not_in_group"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_last_admin,
   "system_error_code::error_last_admin"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_wrong_password,
   "system_error_code::error_wrong_password"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ill_formed_password,
   "system_error_code::error_ill_formed_password"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_password_restriction,
   "system_error_code::error_password_restriction"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_logon_failure,
   "system_error_code::error_logon_failure"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_account_restriction,
   "system_error_code::error_account_restriction"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_logon_hours,
   "system_error_code::error_invalid_logon_hours"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_workstation,
   "system_error_code::error_invalid_workstation"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_password_expired,
   "system_error_code::error_password_expired"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_account_disabled,
   "system_error_code::error_account_disabled"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_none_mapped,
   "system_error_code::error_none_mapped"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_too_many_luids_requested,
   "system_error_code::error_too_many_luids_requested"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_luids_exhausted,
   "system_error_code::error_luids_exhausted"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_sub_authority,
   "system_error_code::error_invalid_sub_authority"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_acl,
   "system_error_code::error_invalid_acl"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_sid,
   "system_error_code::error_invalid_sid"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_security_descr,
   "system_error_code::error_invalid_security_descr"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_bad_inheritance_acl,
   "system_error_code::error_bad_inheritance_acl"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_server_disabled,
   "system_error_code::error_server_disabled"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_server_not_disabled,
   "system_error_code::error_server_not_disabled"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_id_authority,
   "system_error_code::error_invalid_id_authority"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_allotted_space_exceeded,
   "system_error_code::error_allotted_space_exceeded"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_group_attributes,
   "system_error_code::error_invalid_group_attributes"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_bad_impersonation_level,
   "system_error_code::error_bad_impersonation_level"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cant_open_anonymous,
   "system_error_code::error_cant_open_anonymous"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_bad_validation_class,
   "system_error_code::error_bad_validation_class"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_bad_token_type,
   "system_error_code::error_bad_token_type"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_no_security_on_object,
   "system_error_code::error_no_security_on_object"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cant_access_domain_info,
   "system_error_code::error_cant_access_domain_info"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_server_state,
   "system_error_code::error_invalid_server_state"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_domain_state,
   "system_error_code::error_invalid_domain_state"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_domain_role,
   "system_error_code::error_invalid_domain_role"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_no_such_domain,
   "system_error_code::error_no_such_domain"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_domain_exists,
   "system_error_code::error_domain_exists"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_domain_limit_exceeded,
   "system_error_code::error_domain_limit_exceeded"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_internal_db_corruption,
   "system_error_code::error_internal_db_corruption"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_internal_error,
   "system_error_code::error_internal_error"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_generic_not_mapped,
   "system_error_code::error_generic_not_mapped"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_bad_descriptor_format,
   "system_error_code::error_bad_descriptor_format"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_not_logon_process,
   "system_error_code::error_not_logon_process"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_logon_session_exists,
   "system_error_code::error_logon_session_exists"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_no_such_package,
   "system_error_code::error_no_such_package"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_bad_logon_session_state,
   "system_error_code::error_bad_logon_session_state"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_logon_session_collision,
   "system_error_code::error_logon_session_collision"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_logon_type,
   "system_error_code::error_invalid_logon_type"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cannot_impersonate,
   "system_error_code::error_cannot_impersonate"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_rxact_invalid_state,
   "system_error_code::error_rxact_invalid_state"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_rxact_commit_failure,
   "system_error_code::error_rxact_commit_failure"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_special_account,
   "system_error_code::error_special_account"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_special_group,
   "system_error_code::error_special_group"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_special_user,
   "system_error_code::error_special_user"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_members_primary_group,
   "system_error_code::error_members_primary_group"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_token_already_in_use,
   "system_error_code::error_token_already_in_use"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_no_such_alias,
   "system_error_code::error_no_such_alias"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_member_not_in_alias,
   "system_error_code::error_member_not_in_alias"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_member_in_alias,
   "system_error_code::error_member_in_alias"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_alias_exists,
   "system_error_code::error_alias_exists"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_logon_not_granted,
   "system_error_code::error_logon_not_granted"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_too_many_secrets,
   "system_error_code::error_too_many_secrets"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_secret_too_long,
   "system_error_code::error_secret_too_long"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_internal_db_error,
   "system_error_code::error_internal_db_error"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_too_many_context_ids,
   "system_error_code::error_too_many_context_ids"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_logon_type_not_granted,
   "system_error_code::error_logon_type_not_granted"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_nt_cross_encryption_required,
   "system_error_code::error_nt_cross_encryption_required"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_no_such_member,
   "system_error_code::error_no_such_member"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_member,
   "system_error_code::error_invalid_member"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_too_many_sids,
   "system_error_code::error_too_many_sids"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_lm_cross_encryption_required,
   "system_error_code::error_lm_cross_encryption_required"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_no_inheritance,
   "system_error_code::error_no_inheritance"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_file_corrupt,
   "system_error_code::error_file_corrupt"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_disk_corrupt,
   "system_error_code::error_disk_corrupt"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_no_user_session_key,
   "system_error_code::error_no_user_session_key"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_license_quota_exceeded,
   "system_error_code::error_license_quota_exceeded"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_wrong_target_name,
   "system_error_code::error_wrong_target_name"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_mutual_auth_failed,
   "system_error_code::error_mutual_auth_failed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_time_skew,
   "system_error_code::error_time_skew"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_current_domain_not_allowed,
   "system_error_code::error_current_domain_not_allowed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_window_handle,
   "system_error_code::error_invalid_window_handle"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_menu_handle,
   "system_error_code::error_invalid_menu_handle"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_cursor_handle,
   "system_error_code::error_invalid_cursor_handle"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_accel_handle,
   "system_error_code::error_invalid_accel_handle"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_hook_handle,
   "system_error_code::error_invalid_hook_handle"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_dwp_handle,
   "system_error_code::error_invalid_dwp_handle"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_tlw_with_wschild,
   "system_error_code::error_tlw_with_wschild"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cannot_find_wnd_class,
   "system_error_code::error_cannot_find_wnd_class"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_window_of_other_thread,
   "system_error_code::error_window_of_other_thread"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_hotkey_already_registered,
   "system_error_code::error_hotkey_already_registered"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_class_already_exists,
   "system_error_code::error_class_already_exists"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_class_does_not_exist,
   "system_error_code::error_class_does_not_exist"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_class_has_windows,
   "system_error_code::error_class_has_windows"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_index,
   "system_error_code::error_invalid_index"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_icon_handle,
   "system_error_code::error_invalid_icon_handle"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_private_dialog_index,
   "system_error_code::error_private_dialog_index"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_listbox_id_not_found,
   "system_error_code::error_listbox_id_not_found"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_no_wildcard_characters,
   "system_error_code::error_no_wildcard_characters"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_clipboard_not_open,
   "system_error_code::error_clipboard_not_open"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_hotkey_not_registered,
   "system_error_code::error_hotkey_not_registered"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_window_not_dialog,
   "system_error_code::error_window_not_dialog"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_control_id_not_found,
   "system_error_code::error_control_id_not_found"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_combobox_message,
   "system_error_code::error_invalid_combobox_message"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_window_not_combobox,
   "system_error_code::error_window_not_combobox"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_edit_height,
   "system_error_code::error_invalid_edit_height"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_dc_not_found,
   "system_error_code::error_dc_not_found"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_hook_filter,
   "system_error_code::error_invalid_hook_filter"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_filter_proc,
   "system_error_code::error_invalid_filter_proc"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_hook_needs_hmod,
   "system_error_code::error_hook_needs_hmod"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_global_only_hook,
   "system_error_code::error_global_only_hook"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_journal_hook_set,
   "system_error_code::error_journal_hook_set"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_hook_not_installed,
   "system_error_code::error_hook_not_installed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_lb_message,
   "system_error_code::error_invalid_lb_message"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_setcount_on_bad_lb,
   "system_error_code::error_setcount_on_bad_lb"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_lb_without_tabstops,
   "system_error_code::error_lb_without_tabstops"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_destroy_object_of_other_thread,
   "system_error_code::error_destroy_object_of_other_thread"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_child_window_menu,
   "system_error_code::error_child_window_menu"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_no_system_menu,
   "system_error_code::error_no_system_menu"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_msgbox_style,
   "system_error_code::error_invalid_msgbox_style"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_spi_value,
   "system_error_code::error_invalid_spi_value"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_screen_already_locked,
   "system_error_code::error_screen_already_locked"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_hwnds_have_diff_parent,
   "system_error_code::error_hwnds_have_diff_parent"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_not_child_window,
   "system_error_code::error_not_child_window"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_gw_command,
   "system_error_code::error_invalid_gw_command"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_thread_id,
   "system_error_code::error_invalid_thread_id"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_non_mdichild_window,
   "system_error_code::error_non_mdichild_window"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_popup_already_active,
   "system_error_code::error_popup_already_active"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_no_scrollbars,
   "system_error_code::error_no_scrollbars"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_scrollbar_range,
   "system_error_code::error_invalid_scrollbar_range"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_showwin_command,
   "system_error_code::error_invalid_showwin_command"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_no_system_resources,
   "system_error_code::error_no_system_resources"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_nonpaged_system_resources,
   "system_error_code::error_nonpaged_system_resources"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_paged_system_resources,
   "system_error_code::error_paged_system_resources"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_working_set_quota,
   "system_error_code::error_working_set_quota"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_pagefile_quota,
   "system_error_code::error_pagefile_quota"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_commitment_limit,
   "system_error_code::error_commitment_limit"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_menu_item_not_found,
   "system_error_code::error_menu_item_not_found"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_keyboard_handle,
   "system_error_code::error_invalid_keyboard_handle"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_hook_type_not_allowed,
   "system_error_code::error_hook_type_not_allowed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_requires_interactive_windowstation,
   "system_error_code::error_requires_interactive_windowstation"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_timeout,
   "system_error_code::error_timeout"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_monitor_handle,
   "system_error_code::error_invalid_monitor_handle"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_incorrect_size,
   "system_error_code::error_incorrect_size"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_symlink_class_disabled,
   "system_error_code::error_symlink_class_disabled"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_symlink_not_supported,
   "system_error_code::error_symlink_not_supported"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_xml_parse_error,
   "system_error_code::error_xml_parse_error"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_xmldsig_error,
   "system_error_code::error_xmldsig_error"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_restart_application,
   "system_error_code::error_restart_application"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_wrong_compartment,
   "system_error_code::error_wrong_compartment"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_authip_failure,
   "system_error_code::error_authip_failure"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_no_nvram_resources,
   "system_error_code::error_no_nvram_resources"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_not_gui_process,
   "system_error_code::error_not_gui_process"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_eventlog_file_corrupt,
   "system_error_code::error_eventlog_file_corrupt"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_eventlog_cant_start,
   "system_error_code::error_eventlog_cant_start"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_log_file_full,
   "system_error_code::error_log_file_full"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_eventlog_file_changed,
   "system_error_code::error_eventlog_file_changed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_task_name,
   "system_error_code::error_invalid_task_name"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_task_index,
   "system_error_code::error_invalid_task_index"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_thread_already_in_task,
   "system_error_code::error_thread_already_in_task"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_install_service_failure,
   "system_error_code::error_install_service_failure"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_install_userexit,
   "system_error_code::error_install_userexit"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_install_failure,
   "system_error_code::error_install_failure"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_install_suspend,
   "system_error_code::error_install_suspend"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_unknown_product,
   "system_error_code::error_unknown_product"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_unknown_feature,
   "system_error_code::error_unknown_feature"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_unknown_component,
   "system_error_code::error_unknown_component"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_unknown_property,
   "system_error_code::error_unknown_property"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_handle_state,
   "system_error_code::error_invalid_handle_state"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_bad_configuration,
   "system_error_code::error_bad_configuration"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_index_absent,
   "system_error_code::error_index_absent"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_install_source_absent,
   "system_error_code::error_install_source_absent"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_install_package_version,
   "system_error_code::error_install_package_version"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_product_uninstalled,
   "system_error_code::error_product_uninstalled"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_bad_query_syntax,
   "system_error_code::error_bad_query_syntax"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_field,
   "system_error_code::error_invalid_field"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_device_removed,
   "system_error_code::error_device_removed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_install_already_running,
   "system_error_code::error_install_already_running"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_install_package_open_failed,
   "system_error_code::error_install_package_open_failed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_install_package_invalid,
   "system_error_code::error_install_package_invalid"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_install_ui_failure,
   "system_error_code::error_install_ui_failure"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_install_log_failure,
   "system_error_code::error_install_log_failure"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_install_language_unsupported,
   "system_error_code::error_install_language_unsupported"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_install_transform_failure,
   "system_error_code::error_install_transform_failure"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_install_package_rejected,
   "system_error_code::error_install_package_rejected"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_function_not_called,
   "system_error_code::error_function_not_called"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_function_failed,
   "system_error_code::error_function_failed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_table,
   "system_error_code::error_invalid_table"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_datatype_mismatch,
   "system_error_code::error_datatype_mismatch"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_unsupported_type,
   "system_error_code::error_unsupported_type"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_create_failed,
   "system_error_code::error_create_failed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_install_temp_unwritable,
   "system_error_code::error_install_temp_unwritable"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_install_platform_unsupported,
   "system_error_code::error_install_platform_unsupported"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_install_notused,
   "system_error_code::error_install_notused"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_patch_package_open_failed,
   "system_error_code::error_patch_package_open_failed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_patch_package_invalid,
   "system_error_code::error_patch_package_invalid"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_patch_package_unsupported,
   "system_error_code::error_patch_package_unsupported"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_product_version,
   "system_error_code::error_product_version"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_command_line,
   "system_error_code::error_invalid_command_line"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_install_remote_disallowed,
   "system_error_code::error_install_remote_disallowed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_success_reboot_initiated,
   "system_error_code::error_success_reboot_initiated"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_patch_target_not_found,
   "system_error_code::error_patch_target_not_found"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_patch_package_rejected,
   "system_error_code::error_patch_package_rejected"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_install_transform_rejected,
   "system_error_code::error_install_transform_rejected"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_install_remote_prohibited,
   "system_error_code::error_install_remote_prohibited"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_patch_removal_unsupported,
   "system_error_code::error_patch_removal_unsupported"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_unknown_patch,
   "system_error_code::error_unknown_patch"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_patch_no_sequence,
   "system_error_code::error_patch_no_sequence"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_patch_removal_disallowed,
   "system_error_code::error_patch_removal_disallowed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_patch_xml,
   "system_error_code::error_invalid_patch_xml"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_patch_managed_advertised_product,
   "system_error_code::error_patch_managed_advertised_product"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_install_service_safeboot,
   "system_error_code::error_install_service_safeboot"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_fail_fast_exception,
   "system_error_code::error_fail_fast_exception"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_install_rejected,
   "system_error_code::error_install_rejected"
  },
   std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_invalid_string_binding,
   "system_error_code::rpc_s_invalid_string_binding"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_wrong_kind_of_binding,
   "system_error_code::rpc_s_wrong_kind_of_binding"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_invalid_binding,
   "system_error_code::rpc_s_invalid_binding"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_protseq_not_supported,
   "system_error_code::rpc_s_protseq_not_supported"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_invalid_rpc_protseq,
   "system_error_code::rpc_s_invalid_rpc_protseq"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_invalid_string_uuid,
   "system_error_code::rpc_s_invalid_string_uuid"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_invalid_endpoint_format,
   "system_error_code::rpc_s_invalid_endpoint_format"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_invalid_net_addr,
   "system_error_code::rpc_s_invalid_net_addr"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_no_endpoint_found,
   "system_error_code::rpc_s_no_endpoint_found"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_invalid_timeout,
   "system_error_code::rpc_s_invalid_timeout"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_object_not_found,
   "system_error_code::rpc_s_object_not_found"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_already_registered,
   "system_error_code::rpc_s_already_registered"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_type_already_registered,
   "system_error_code::rpc_s_type_already_registered"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_already_listening,
   "system_error_code::rpc_s_already_listening"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_no_protseqs_registered,
   "system_error_code::rpc_s_no_protseqs_registered"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_not_listening,
   "system_error_code::rpc_s_not_listening"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_unknown_mgr_type,
   "system_error_code::rpc_s_unknown_mgr_type"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_unknown_if,
   "system_error_code::rpc_s_unknown_if"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_no_bindings,
   "system_error_code::rpc_s_no_bindings"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_no_protseqs,
   "system_error_code::rpc_s_no_protseqs"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_cant_create_endpoint,
   "system_error_code::rpc_s_cant_create_endpoint"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_out_of_resources,
   "system_error_code::rpc_s_out_of_resources"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_server_unavailable,
   "system_error_code::rpc_s_server_unavailable"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_server_too_busy,
   "system_error_code::rpc_s_server_too_busy"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_invalid_network_options,
   "system_error_code::rpc_s_invalid_network_options"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_no_call_active,
   "system_error_code::rpc_s_no_call_active"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_call_failed,
   "system_error_code::rpc_s_call_failed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_call_failed_dne,
   "system_error_code::rpc_s_call_failed_dne"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_protocol_error,
   "system_error_code::rpc_s_protocol_error"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_proxy_access_denied,
   "system_error_code::rpc_s_proxy_access_denied"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_unsupported_trans_syn,
   "system_error_code::rpc_s_unsupported_trans_syn"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_unsupported_type,
   "system_error_code::rpc_s_unsupported_type"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_invalid_tag,
   "system_error_code::rpc_s_invalid_tag"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_invalid_bound,
   "system_error_code::rpc_s_invalid_bound"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_no_entry_name,
   "system_error_code::rpc_s_no_entry_name"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_invalid_name_syntax,
   "system_error_code::rpc_s_invalid_name_syntax"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_unsupported_name_syntax,
   "system_error_code::rpc_s_unsupported_name_syntax"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_uuid_no_address,
   "system_error_code::rpc_s_uuid_no_address"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_duplicate_endpoint,
   "system_error_code::rpc_s_duplicate_endpoint"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_unknown_authn_type,
   "system_error_code::rpc_s_unknown_authn_type"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_max_calls_too_small,
   "system_error_code::rpc_s_max_calls_too_small"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_string_too_long,
   "system_error_code::rpc_s_string_too_long"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_protseq_not_found,
   "system_error_code::rpc_s_protseq_not_found"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_procnum_out_of_range,
   "system_error_code::rpc_s_procnum_out_of_range"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_binding_has_no_auth,
   "system_error_code::rpc_s_binding_has_no_auth"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_unknown_authn_service,
   "system_error_code::rpc_s_unknown_authn_service"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_unknown_authn_level,
   "system_error_code::rpc_s_unknown_authn_level"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_invalid_auth_identity,
   "system_error_code::rpc_s_invalid_auth_identity"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_unknown_authz_service,
   "system_error_code::rpc_s_unknown_authz_service"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::ept_s_invalid_entry,
   "system_error_code::ept_s_invalid_entry"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::ept_s_cant_perform_op,
   "system_error_code::ept_s_cant_perform_op"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::ept_s_not_registered,
   "system_error_code::ept_s_not_registered"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_nothing_to_export,
   "system_error_code::rpc_s_nothing_to_export"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_incomplete_name,
   "system_error_code::rpc_s_incomplete_name"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_invalid_vers_option,
   "system_error_code::rpc_s_invalid_vers_option"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_no_more_members,
   "system_error_code::rpc_s_no_more_members"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_not_all_objs_unexported,
   "system_error_code::rpc_s_not_all_objs_unexported"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_interface_not_found,
   "system_error_code::rpc_s_interface_not_found"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_entry_already_exists,
   "system_error_code::rpc_s_entry_already_exists"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_entry_not_found,
   "system_error_code::rpc_s_entry_not_found"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_name_service_unavailable,
   "system_error_code::rpc_s_name_service_unavailable"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_invalid_naf_id,
   "system_error_code::rpc_s_invalid_naf_id"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_cannot_support,
   "system_error_code::rpc_s_cannot_support"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_no_context_available,
   "system_error_code::rpc_s_no_context_available"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_internal_error,
   "system_error_code::rpc_s_internal_error"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_zero_divide,
   "system_error_code::rpc_s_zero_divide"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_address_error,
   "system_error_code::rpc_s_address_error"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_fp_div_zero,
   "system_error_code::rpc_s_fp_div_zero"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_fp_underflow,
   "system_error_code::rpc_s_fp_underflow"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_fp_overflow,
   "system_error_code::rpc_s_fp_overflow"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_x_no_more_entries,
   "system_error_code::rpc_x_no_more_entries"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_x_ss_char_trans_open_fail,
   "system_error_code::rpc_x_ss_char_trans_open_fail"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_x_ss_char_trans_short_file,
   "system_error_code::rpc_x_ss_char_trans_short_file"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_x_ss_in_null_context,
   "system_error_code::rpc_x_ss_in_null_context"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_x_ss_context_damaged,
   "system_error_code::rpc_x_ss_context_damaged"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_x_ss_handles_mismatch,
   "system_error_code::rpc_x_ss_handles_mismatch"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_x_ss_cannot_get_call_handle,
   "system_error_code::rpc_x_ss_cannot_get_call_handle"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_x_null_ref_pointer,
   "system_error_code::rpc_x_null_ref_pointer"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_x_enum_value_out_of_range,
   "system_error_code::rpc_x_enum_value_out_of_range"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_x_byte_count_too_small,
   "system_error_code::rpc_x_byte_count_too_small"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_x_bad_stub_data,
   "system_error_code::rpc_x_bad_stub_data"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_user_buffer,
   "system_error_code::error_invalid_user_buffer"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_unrecognized_media,
   "system_error_code::error_unrecognized_media"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_no_trust_lsa_secret,
   "system_error_code::error_no_trust_lsa_secret"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_no_trust_sam_account,
   "system_error_code::error_no_trust_sam_account"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_trusted_domain_failure,
   "system_error_code::error_trusted_domain_failure"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_trusted_relationship_failure,
   "system_error_code::error_trusted_relationship_failure"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_trust_failure,
   "system_error_code::error_trust_failure"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_call_in_progress,
   "system_error_code::rpc_s_call_in_progress"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_netlogon_not_started,
   "system_error_code::error_netlogon_not_started"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_account_expired,
   "system_error_code::error_account_expired"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_redirector_has_open_handles,
   "system_error_code::error_redirector_has_open_handles"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_printer_driver_already_installed,
   "system_error_code::error_printer_driver_already_installed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_unknown_port,
   "system_error_code::error_unknown_port"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_unknown_printer_driver,
   "system_error_code::error_unknown_printer_driver"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_unknown_printprocessor,
   "system_error_code::error_unknown_printprocessor"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_separator_file,
   "system_error_code::error_invalid_separator_file"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_priority,
   "system_error_code::error_invalid_priority"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_printer_name,
   "system_error_code::error_invalid_printer_name"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_printer_already_exists,
   "system_error_code::error_printer_already_exists"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_printer_command,
   "system_error_code::error_invalid_printer_command"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_datatype,
   "system_error_code::error_invalid_datatype"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_environment,
   "system_error_code::error_invalid_environment"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_no_more_bindings,
   "system_error_code::rpc_s_no_more_bindings"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_nologon_interdomain_trust_account,
   "system_error_code::error_nologon_interdomain_trust_account"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_nologon_workstation_trust_account,
   "system_error_code::error_nologon_workstation_trust_account"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_nologon_server_trust_account,
   "system_error_code::error_nologon_server_trust_account"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_domain_trust_inconsistent,
   "system_error_code::error_domain_trust_inconsistent"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_server_has_open_handles,
   "system_error_code::error_server_has_open_handles"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_resource_data_not_found,
   "system_error_code::error_resource_data_not_found"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_resource_type_not_found,
   "system_error_code::error_resource_type_not_found"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_resource_name_not_found,
   "system_error_code::error_resource_name_not_found"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_resource_lang_not_found,
   "system_error_code::error_resource_lang_not_found"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_not_enough_quota,
   "system_error_code::error_not_enough_quota"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_no_interfaces,
   "system_error_code::rpc_s_no_interfaces"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_call_cancelled,
   "system_error_code::rpc_s_call_cancelled"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_binding_incomplete,
   "system_error_code::rpc_s_binding_incomplete"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_comm_failure,
   "system_error_code::rpc_s_comm_failure"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_unsupported_authn_level,
   "system_error_code::rpc_s_unsupported_authn_level"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_no_princ_name,
   "system_error_code::rpc_s_no_princ_name"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_not_rpc_error,
   "system_error_code::rpc_s_not_rpc_error"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_uuid_local_only,
   "system_error_code::rpc_s_uuid_local_only"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_sec_pkg_error,
   "system_error_code::rpc_s_sec_pkg_error"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_not_cancelled,
   "system_error_code::rpc_s_not_cancelled"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_x_invalid_es_action,
   "system_error_code::rpc_x_invalid_es_action"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_x_wrong_es_version,
   "system_error_code::rpc_x_wrong_es_version"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_x_wrong_stub_version,
   "system_error_code::rpc_x_wrong_stub_version"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_x_invalid_pipe_object,
   "system_error_code::rpc_x_invalid_pipe_object"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_x_wrong_pipe_order,
   "system_error_code::rpc_x_wrong_pipe_order"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_x_wrong_pipe_version,
   "system_error_code::rpc_x_wrong_pipe_version"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_cookie_auth_failed,
   "system_error_code::rpc_s_cookie_auth_failed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_group_member_not_found,
   "system_error_code::rpc_s_group_member_not_found"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::ept_s_cant_create,
   "system_error_code::ept_s_cant_create"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_invalid_object,
   "system_error_code::rpc_s_invalid_object"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_time,
   "system_error_code::error_invalid_time"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_form_name,
   "system_error_code::error_invalid_form_name"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_form_size,
   "system_error_code::error_invalid_form_size"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_already_waiting,
   "system_error_code::error_already_waiting"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_printer_deleted,
   "system_error_code::error_printer_deleted"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_printer_state,
   "system_error_code::error_invalid_printer_state"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_password_must_change,
   "system_error_code::error_password_must_change"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_domain_controller_not_found,
   "system_error_code::error_domain_controller_not_found"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_account_locked_out,
   "system_error_code::error_account_locked_out"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::or_invalid_oxid,
   "system_error_code::or_invalid_oxid"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::or_invalid_oid,
   "system_error_code::or_invalid_oid"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::or_invalid_set,
   "system_error_code::or_invalid_set"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_send_incomplete,
   "system_error_code::rpc_s_send_incomplete"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_invalid_async_handle,
   "system_error_code::rpc_s_invalid_async_handle"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_invalid_async_call,
   "system_error_code::rpc_s_invalid_async_call"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_x_pipe_closed,
   "system_error_code::rpc_x_pipe_closed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_x_pipe_discipline_error,
   "system_error_code::rpc_x_pipe_discipline_error"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_x_pipe_empty,
   "system_error_code::rpc_x_pipe_empty"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_no_sitename,
   "system_error_code::error_no_sitename"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cant_access_file,
   "system_error_code::error_cant_access_file"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cant_resolve_filename,
   "system_error_code::error_cant_resolve_filename"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_entry_type_mismatch,
   "system_error_code::rpc_s_entry_type_mismatch"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_not_all_objs_exported,
   "system_error_code::rpc_s_not_all_objs_exported"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_interface_not_exported,
   "system_error_code::rpc_s_interface_not_exported"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_profile_not_added,
   "system_error_code::rpc_s_profile_not_added"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_prf_elt_not_added,
   "system_error_code::rpc_s_prf_elt_not_added"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_prf_elt_not_removed,
   "system_error_code::rpc_s_prf_elt_not_removed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_grp_elt_not_added,
   "system_error_code::rpc_s_grp_elt_not_added"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::rpc_s_grp_elt_not_removed,
   "system_error_code::rpc_s_grp_elt_not_removed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_km_driver_blocked,
   "system_error_code::error_km_driver_blocked"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_context_expired,
   "system_error_code::error_context_expired"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_per_user_trust_quota_exceeded,
   "system_error_code::error_per_user_trust_quota_exceeded"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_all_user_trust_quota_exceeded,
   "system_error_code::error_all_user_trust_quota_exceeded"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_user_delete_trust_quota_exceeded,
   "system_error_code::error_user_delete_trust_quota_exceeded"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_authentication_firewall_failed,
   "system_error_code::error_authentication_firewall_failed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_remote_print_connections_blocked,
   "system_error_code::error_remote_print_connections_blocked"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ntlm_blocked,
   "system_error_code::error_ntlm_blocked"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_password_change_required,
   "system_error_code::error_password_change_required"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_pixel_format,
   "system_error_code::error_invalid_pixel_format"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_bad_driver,
   "system_error_code::error_bad_driver"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_window_style,
   "system_error_code::error_invalid_window_style"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_metafile_not_supported,
   "system_error_code::error_metafile_not_supported"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_transform_not_supported,
   "system_error_code::error_transform_not_supported"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_clipping_not_supported,
   "system_error_code::error_clipping_not_supported"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_cmm,
   "system_error_code::error_invalid_cmm"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_profile,
   "system_error_code::error_invalid_profile"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_tag_not_found,
   "system_error_code::error_tag_not_found"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_tag_not_present,
   "system_error_code::error_tag_not_present"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_duplicate_tag,
   "system_error_code::error_duplicate_tag"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_profile_not_associated_with_device,
   "system_error_code::error_profile_not_associated_with_device"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_profile_not_found,
   "system_error_code::error_profile_not_found"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_colorspace,
   "system_error_code::error_invalid_colorspace"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_icm_not_enabled,
   "system_error_code::error_icm_not_enabled"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_deleting_icm_xform,
   "system_error_code::error_deleting_icm_xform"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_transform,
   "system_error_code::error_invalid_transform"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_colorspace_mismatch,
   "system_error_code::error_colorspace_mismatch"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_colorindex,
   "system_error_code::error_invalid_colorindex"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_profile_does_not_match_device,
   "system_error_code::error_profile_does_not_match_device"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_connected_other_password,
   "system_error_code::error_connected_other_password"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_connected_other_password_default,
   "system_error_code::error_connected_other_password_default"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_bad_username,
   "system_error_code::error_bad_username"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_not_connected,
   "system_error_code::error_not_connected"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_open_files,
   "system_error_code::error_open_files"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_active_connections,
   "system_error_code::error_active_connections"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_device_in_use,
   "system_error_code::error_device_in_use"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_unknown_print_monitor,
   "system_error_code::error_unknown_print_monitor"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_printer_driver_in_use,
   "system_error_code::error_printer_driver_in_use"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_spool_file_not_found,
   "system_error_code::error_spool_file_not_found"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_spl_no_startdoc,
   "system_error_code::error_spl_no_startdoc"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_spl_no_addjob,
   "system_error_code::error_spl_no_addjob"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_print_processor_already_installed,
   "system_error_code::error_print_processor_already_installed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_print_monitor_already_installed,
   "system_error_code::error_print_monitor_already_installed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_print_monitor,
   "system_error_code::error_invalid_print_monitor"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_print_monitor_in_use,
   "system_error_code::error_print_monitor_in_use"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_printer_has_jobs_queued,
   "system_error_code::error_printer_has_jobs_queued"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_success_reboot_required,
   "system_error_code::error_success_reboot_required"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_success_restart_required,
   "system_error_code::error_success_restart_required"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_printer_not_found,
   "system_error_code::error_printer_not_found"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_printer_driver_warned,
   "system_error_code::error_printer_driver_warned"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_printer_driver_blocked,
   "system_error_code::error_printer_driver_blocked"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_printer_driver_package_in_use,
   "system_error_code::error_printer_driver_package_in_use"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_core_driver_package_not_found,
   "system_error_code::error_core_driver_package_not_found"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_fail_reboot_required,
   "system_error_code::error_fail_reboot_required"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_fail_reboot_initiated,
   "system_error_code::error_fail_reboot_initiated"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_printer_driver_download_needed,
   "system_error_code::error_printer_driver_download_needed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_print_job_restart_required,
   "system_error_code::error_print_job_restart_required"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_printer_driver_manifest,
   "system_error_code::error_invalid_printer_driver_manifest"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_printer_not_shareable,
   "system_error_code::error_printer_not_shareable"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_request_paused,
   "system_error_code::error_request_paused"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_io_reissue_as_cached,
   "system_error_code::error_io_reissue_as_cached"
  },
   std::pair<system_error_code, std::string_view>{
   system_error_code::error_wins_internal,
   "system_error_code::error_wins_internal"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_can_not_del_local_wins,
   "system_error_code::error_can_not_del_local_wins"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_static_init,
   "system_error_code::error_static_init"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_inc_backup,
   "system_error_code::error_inc_backup"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_full_backup,
   "system_error_code::error_full_backup"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_rec_non_existent,
   "system_error_code::error_rec_non_existent"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_rpl_not_allowed,
   "system_error_code::error_rpl_not_allowed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::peerdist_error_contentinfo_version_unsupported,
   "system_error_code::peerdist_error_contentinfo_version_unsupported"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::peerdist_error_cannot_parse_contentinfo,
   "system_error_code::peerdist_error_cannot_parse_contentinfo"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::peerdist_error_missing_data,
   "system_error_code::peerdist_error_missing_data"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::peerdist_error_no_more,
   "system_error_code::peerdist_error_no_more"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::peerdist_error_not_initialized,
   "system_error_code::peerdist_error_not_initialized"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::peerdist_error_already_initialized,
   "system_error_code::peerdist_error_already_initialized"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::peerdist_error_shutdown_in_progress,
   "system_error_code::peerdist_error_shutdown_in_progress"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::peerdist_error_invalidated,
   "system_error_code::peerdist_error_invalidated"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::peerdist_error_already_exists,
   "system_error_code::peerdist_error_already_exists"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::peerdist_error_operation_notfound,
   "system_error_code::peerdist_error_operation_notfound"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::peerdist_error_already_completed,
   "system_error_code::peerdist_error_already_completed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::peerdist_error_out_of_bounds,
   "system_error_code::peerdist_error_out_of_bounds"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::peerdist_error_version_unsupported,
   "system_error_code::peerdist_error_version_unsupported"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::peerdist_error_invalid_configuration,
   "system_error_code::peerdist_error_invalid_configuration"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::peerdist_error_not_licensed,
   "system_error_code::peerdist_error_not_licensed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::peerdist_error_service_unavailable,
   "system_error_code::peerdist_error_service_unavailable"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::peerdist_error_trust_failure,
   "system_error_code::peerdist_error_trust_failure"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_dhcp_address_conflict,
   "system_error_code::error_dhcp_address_conflict"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_wmi_guid_not_found,
   "system_error_code::error_wmi_guid_not_found"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_wmi_instance_not_found,
   "system_error_code::error_wmi_instance_not_found"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_wmi_itemid_not_found,
   "system_error_code::error_wmi_itemid_not_found"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_wmi_try_again,
   "system_error_code::error_wmi_try_again"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_wmi_dp_not_found,
   "system_error_code::error_wmi_dp_not_found"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_wmi_unresolved_instance_ref,
   "system_error_code::error_wmi_unresolved_instance_ref"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_wmi_already_enabled,
   "system_error_code::error_wmi_already_enabled"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_wmi_guid_disconnected,
   "system_error_code::error_wmi_guid_disconnected"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_wmi_server_unavailable,
   "system_error_code::error_wmi_server_unavailable"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_wmi_dp_failed,
   "system_error_code::error_wmi_dp_failed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_wmi_invalid_mof,
   "system_error_code::error_wmi_invalid_mof"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_wmi_invalid_reginfo,
   "system_error_code::error_wmi_invalid_reginfo"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_wmi_already_disabled,
   "system_error_code::error_wmi_already_disabled"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_wmi_read_only,
   "system_error_code::error_wmi_read_only"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_wmi_set_failure,
   "system_error_code::error_wmi_set_failure"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_not_appcontainer,
   "system_error_code::error_not_appcontainer"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_appcontainer_required,
   "system_error_code::error_appcontainer_required"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_not_supported_in_appcontainer,
   "system_error_code::error_not_supported_in_appcontainer"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_package_sid_length,
   "system_error_code::error_invalid_package_sid_length"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_media,
   "system_error_code::error_invalid_media"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_library,
   "system_error_code::error_invalid_library"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_media_pool,
   "system_error_code::error_invalid_media_pool"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_drive_media_mismatch,
   "system_error_code::error_drive_media_mismatch"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_media_offline,
   "system_error_code::error_media_offline"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_library_offline,
   "system_error_code::error_library_offline"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_empty,
   "system_error_code::error_empty"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_not_empty,
   "system_error_code::error_not_empty"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_media_unavailable,
   "system_error_code::error_media_unavailable"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_resource_disabled,
   "system_error_code::error_resource_disabled"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_cleaner,
   "system_error_code::error_invalid_cleaner"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_unable_to_clean,
   "system_error_code::error_unable_to_clean"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_object_not_found,
   "system_error_code::error_object_not_found"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_database_failure,
   "system_error_code::error_database_failure"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_database_full,
   "system_error_code::error_database_full"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_media_incompatible,
   "system_error_code::error_media_incompatible"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_resource_not_present,
   "system_error_code::error_resource_not_present"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_operation,
   "system_error_code::error_invalid_operation"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_media_not_available,
   "system_error_code::error_media_not_available"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_device_not_available,
   "system_error_code::error_device_not_available"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_request_refused,
   "system_error_code::error_request_refused"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_drive_object,
   "system_error_code::error_invalid_drive_object"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_library_full,
   "system_error_code::error_library_full"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_medium_not_accessible,
   "system_error_code::error_medium_not_accessible"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_unable_to_load_medium,
   "system_error_code::error_unable_to_load_medium"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_unable_to_inventory_drive,
   "system_error_code::error_unable_to_inventory_drive"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_unable_to_inventory_slot,
   "system_error_code::error_unable_to_inventory_slot"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_unable_to_inventory_transport,
   "system_error_code::error_unable_to_inventory_transport"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_transport_full,
   "system_error_code::error_transport_full"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_controlling_ieport,
   "system_error_code::error_controlling_ieport"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_unable_to_eject_mounted_media,
   "system_error_code::error_unable_to_eject_mounted_media"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cleaner_slot_set,
   "system_error_code::error_cleaner_slot_set"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cleaner_slot_not_set,
   "system_error_code::error_cleaner_slot_not_set"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cleaner_cartridge_spent,
   "system_error_code::error_cleaner_cartridge_spent"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_unexpected_omid,
   "system_error_code::error_unexpected_omid"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cant_delete_last_item,
   "system_error_code::error_cant_delete_last_item"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_message_exceeds_max_size,
   "system_error_code::error_message_exceeds_max_size"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_volume_contains_sys_files,
   "system_error_code::error_volume_contains_sys_files"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_indigenous_type,
   "system_error_code::error_indigenous_type"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_no_supporting_drives,
   "system_error_code::error_no_supporting_drives"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cleaner_cartridge_installed,
   "system_error_code::error_cleaner_cartridge_installed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ieport_full,
   "system_error_code::error_ieport_full"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_file_offline,
   "system_error_code::error_file_offline"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_remote_storage_not_active,
   "system_error_code::error_remote_storage_not_active"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_remote_storage_media_error,
   "system_error_code::error_remote_storage_media_error"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_not_a_reparse_point,
   "system_error_code::error_not_a_reparse_point"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_reparse_attribute_conflict,
   "system_error_code::error_reparse_attribute_conflict"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_reparse_data,
   "system_error_code::error_invalid_reparse_data"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_reparse_tag_invalid,
   "system_error_code::error_reparse_tag_invalid"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_reparse_tag_mismatch,
   "system_error_code::error_reparse_tag_mismatch"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_app_data_not_found,
   "system_error_code::error_app_data_not_found"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_app_data_expired,
   "system_error_code::error_app_data_expired"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_app_data_corrupt,
   "system_error_code::error_app_data_corrupt"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_app_data_limit_exceeded,
   "system_error_code::error_app_data_limit_exceeded"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_app_data_reboot_required,
   "system_error_code::error_app_data_reboot_required"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_secureboot_rollback_detected,
   "system_error_code::error_secureboot_rollback_detected"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_secureboot_policy_violation,
   "system_error_code::error_secureboot_policy_violation"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_secureboot_invalid_policy,
   "system_error_code::error_secureboot_invalid_policy"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_secureboot_policy_publisher_not_found,
   "system_error_code::error_secureboot_policy_publisher_not_found"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_secureboot_policy_not_signed,
   "system_error_code::error_secureboot_policy_not_signed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_secureboot_not_enabled,
   "system_error_code::error_secureboot_not_enabled"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_secureboot_file_replaced,
   "system_error_code::error_secureboot_file_replaced"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_offload_read_flt_not_supported,
   "system_error_code::error_offload_read_flt_not_supported"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_offload_write_flt_not_supported,
   "system_error_code::error_offload_write_flt_not_supported"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_offload_read_file_not_supported,
   "system_error_code::error_offload_read_file_not_supported"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_offload_write_file_not_supported,
   "system_error_code::error_offload_write_file_not_supported"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_volume_not_sis_enabled,
   "system_error_code::error_volume_not_sis_enabled"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_dependent_resource_exists,
   "system_error_code::error_dependent_resource_exists"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_dependency_not_found,
   "system_error_code::error_dependency_not_found"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_dependency_already_exists,
   "system_error_code::error_dependency_already_exists"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_resource_not_online,
   "system_error_code::error_resource_not_online"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_host_node_not_available,
   "system_error_code::error_host_node_not_available"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_resource_not_available,
   "system_error_code::error_resource_not_available"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_resource_not_found,
   "system_error_code::error_resource_not_found"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_shutdown_cluster,
   "system_error_code::error_shutdown_cluster"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cant_evict_active_node,
   "system_error_code::error_cant_evict_active_node"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_object_already_exists,
   "system_error_code::error_object_already_exists"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_object_in_list,
   "system_error_code::error_object_in_list"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_group_not_available,
   "system_error_code::error_group_not_available"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_group_not_found,
   "system_error_code::error_group_not_found"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_group_not_online,
   "system_error_code::error_group_not_online"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_host_node_not_resource_owner,
   "system_error_code::error_host_node_not_resource_owner"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_host_node_not_group_owner,
   "system_error_code::error_host_node_not_group_owner"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_resmon_create_failed,
   "system_error_code::error_resmon_create_failed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_resmon_online_failed,
   "system_error_code::error_resmon_online_failed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_resource_online,
   "system_error_code::error_resource_online"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_quorum_resource,
   "system_error_code::error_quorum_resource"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_not_quorum_capable,
   "system_error_code::error_not_quorum_capable"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_shutting_down,
   "system_error_code::error_cluster_shutting_down"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_state,
   "system_error_code::error_invalid_state"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_resource_properties_stored,
   "system_error_code::error_resource_properties_stored"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_not_quorum_class,
   "system_error_code::error_not_quorum_class"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_core_resource,
   "system_error_code::error_core_resource"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_quorum_resource_online_failed,
   "system_error_code::error_quorum_resource_online_failed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_quorumlog_open_failed,
   "system_error_code::error_quorumlog_open_failed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_clusterlog_corrupt,
   "system_error_code::error_clusterlog_corrupt"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_clusterlog_record_exceeds_maxsize,
   "system_error_code::error_clusterlog_record_exceeds_maxsize"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_clusterlog_exceeds_maxsize,
   "system_error_code::error_clusterlog_exceeds_maxsize"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_clusterlog_chkpoint_not_found,
   "system_error_code::error_clusterlog_chkpoint_not_found"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_clusterlog_not_enough_space,
   "system_error_code::error_clusterlog_not_enough_space"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_quorum_owner_alive,
   "system_error_code::error_quorum_owner_alive"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_network_not_available,
   "system_error_code::error_network_not_available"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_node_not_available,
   "system_error_code::error_node_not_available"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_all_nodes_not_available,
   "system_error_code::error_all_nodes_not_available"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_resource_failed,
   "system_error_code::error_resource_failed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_invalid_node,
   "system_error_code::error_cluster_invalid_node"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_node_exists,
   "system_error_code::error_cluster_node_exists"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_join_in_progress,
   "system_error_code::error_cluster_join_in_progress"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_node_not_found,
   "system_error_code::error_cluster_node_not_found"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_local_node_not_found,
   "system_error_code::error_cluster_local_node_not_found"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_network_exists,
   "system_error_code::error_cluster_network_exists"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_network_not_found,
   "system_error_code::error_cluster_network_not_found"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_netinterface_exists,
   "system_error_code::error_cluster_netinterface_exists"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_netinterface_not_found,
   "system_error_code::error_cluster_netinterface_not_found"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_invalid_request,
   "system_error_code::error_cluster_invalid_request"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_invalid_network_provider,
   "system_error_code::error_cluster_invalid_network_provider"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_node_down,
   "system_error_code::error_cluster_node_down"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_node_unreachable,
   "system_error_code::error_cluster_node_unreachable"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_node_not_member,
   "system_error_code::error_cluster_node_not_member"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_join_not_in_progress,
   "system_error_code::error_cluster_join_not_in_progress"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_invalid_network,
   "system_error_code::error_cluster_invalid_network"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_node_up,
   "system_error_code::error_cluster_node_up"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_ipaddr_in_use,
   "system_error_code::error_cluster_ipaddr_in_use"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_node_not_paused,
   "system_error_code::error_cluster_node_not_paused"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_no_security_context,
   "system_error_code::error_cluster_no_security_context"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_network_not_internal,
   "system_error_code::error_cluster_network_not_internal"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_node_already_up,
   "system_error_code::error_cluster_node_already_up"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_node_already_down,
   "system_error_code::error_cluster_node_already_down"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_network_already_online,
   "system_error_code::error_cluster_network_already_online"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_network_already_offline,
   "system_error_code::error_cluster_network_already_offline"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_node_already_member,
   "system_error_code::error_cluster_node_already_member"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_last_internal_network,
   "system_error_code::error_cluster_last_internal_network"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_network_has_dependents,
   "system_error_code::error_cluster_network_has_dependents"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_operation_on_quorum,
   "system_error_code::error_invalid_operation_on_quorum"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_dependency_not_allowed,
   "system_error_code::error_dependency_not_allowed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_node_paused,
   "system_error_code::error_cluster_node_paused"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_node_cant_host_resource,
   "system_error_code::error_node_cant_host_resource"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_node_not_ready,
   "system_error_code::error_cluster_node_not_ready"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_node_shutting_down,
   "system_error_code::error_cluster_node_shutting_down"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_join_aborted,
   "system_error_code::error_cluster_join_aborted"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_incompatible_versions,
   "system_error_code::error_cluster_incompatible_versions"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_maxnum_of_resources_exceeded,
   "system_error_code::error_cluster_maxnum_of_resources_exceeded"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_system_config_changed,
   "system_error_code::error_cluster_system_config_changed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_resource_type_not_found,
   "system_error_code::error_cluster_resource_type_not_found"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_restype_not_supported,
   "system_error_code::error_cluster_restype_not_supported"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_resname_not_found,
   "system_error_code::error_cluster_resname_not_found"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_no_rpc_packages_registered,
   "system_error_code::error_cluster_no_rpc_packages_registered"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_owner_not_in_preflist,
   "system_error_code::error_cluster_owner_not_in_preflist"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_database_seqmismatch,
   "system_error_code::error_cluster_database_seqmismatch"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_resmon_invalid_state,
   "system_error_code::error_resmon_invalid_state"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_gum_not_locker,
   "system_error_code::error_cluster_gum_not_locker"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_quorum_disk_not_found,
   "system_error_code::error_quorum_disk_not_found"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_database_backup_corrupt,
   "system_error_code::error_database_backup_corrupt"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_node_already_has_dfs_root,
   "system_error_code::error_cluster_node_already_has_dfs_root"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_resource_property_unchangeable,
   "system_error_code::error_resource_property_unchangeable"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_membership_invalid_state,
   "system_error_code::error_cluster_membership_invalid_state"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_quorumlog_not_found,
   "system_error_code::error_cluster_quorumlog_not_found"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_membership_halt,
   "system_error_code::error_cluster_membership_halt"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_instance_id_mismatch,
   "system_error_code::error_cluster_instance_id_mismatch"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_network_not_found_for_ip,
   "system_error_code::error_cluster_network_not_found_for_ip"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_property_data_type_mismatch,
   "system_error_code::error_cluster_property_data_type_mismatch"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_evict_without_cleanup,
   "system_error_code::error_cluster_evict_without_cleanup"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_parameter_mismatch,
   "system_error_code::error_cluster_parameter_mismatch"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_node_cannot_be_clustered,
   "system_error_code::error_node_cannot_be_clustered"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_wrong_os_version,
   "system_error_code::error_cluster_wrong_os_version"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_cant_create_dup_cluster_name,
   "system_error_code::error_cluster_cant_create_dup_cluster_name"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluscfg_already_committed,
   "system_error_code::error_cluscfg_already_committed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluscfg_rollback_failed,
   "system_error_code::error_cluscfg_rollback_failed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluscfg_system_disk_drive_letter_conflict,
   "system_error_code::error_cluscfg_system_disk_drive_letter_conflict"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_old_version,
   "system_error_code::error_cluster_old_version"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_mismatched_computer_acct_name,
   "system_error_code::error_cluster_mismatched_computer_acct_name"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_no_net_adapters,
   "system_error_code::error_cluster_no_net_adapters"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_poisoned,
   "system_error_code::error_cluster_poisoned"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_group_moving,
   "system_error_code::error_cluster_group_moving"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_resource_type_busy,
   "system_error_code::error_cluster_resource_type_busy"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_resource_call_timed_out,
   "system_error_code::error_resource_call_timed_out"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_cluster_ipv6_address,
   "system_error_code::error_invalid_cluster_ipv6_address"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_internal_invalid_function,
   "system_error_code::error_cluster_internal_invalid_function"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_parameter_out_of_bounds,
   "system_error_code::error_cluster_parameter_out_of_bounds"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_partial_send,
   "system_error_code::error_cluster_partial_send"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_registry_invalid_function,
   "system_error_code::error_cluster_registry_invalid_function"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_invalid_string_termination,
   "system_error_code::error_cluster_invalid_string_termination"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_invalid_string_format,
   "system_error_code::error_cluster_invalid_string_format"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_database_transaction_in_progress,
   "system_error_code::error_cluster_database_transaction_in_progress"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_database_transaction_not_in_progress,
   "system_error_code::error_cluster_database_transaction_not_in_progress"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_null_data,
   "system_error_code::error_cluster_null_data"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_partial_read,
   "system_error_code::error_cluster_partial_read"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_partial_write,
   "system_error_code::error_cluster_partial_write"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_cant_deserialize_data,
   "system_error_code::error_cluster_cant_deserialize_data"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_dependent_resource_property_conflict,
   "system_error_code::error_dependent_resource_property_conflict"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_no_quorum,
   "system_error_code::error_cluster_no_quorum"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_invalid_ipv6_network,
   "system_error_code::error_cluster_invalid_ipv6_network"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_invalid_ipv6_tunnel_network,
   "system_error_code::error_cluster_invalid_ipv6_tunnel_network"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_quorum_not_allowed_in_this_group,
   "system_error_code::error_quorum_not_allowed_in_this_group"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_dependency_tree_too_complex,
   "system_error_code::error_dependency_tree_too_complex"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_exception_in_resource_call,
   "system_error_code::error_exception_in_resource_call"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_rhs_failed_initialization,
   "system_error_code::error_cluster_rhs_failed_initialization"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_not_installed,
   "system_error_code::error_cluster_not_installed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_resources_must_be_online_on_the_same_node,
   "system_error_code::error_cluster_resources_must_be_online_on_the_same_node"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_max_nodes_in_cluster,
   "system_error_code::error_cluster_max_nodes_in_cluster"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_too_many_nodes,
   "system_error_code::error_cluster_too_many_nodes"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_object_already_used,
   "system_error_code::error_cluster_object_already_used"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_noncore_groups_found,
   "system_error_code::error_noncore_groups_found"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_file_share_resource_conflict,
   "system_error_code::error_file_share_resource_conflict"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_evict_invalid_request,
   "system_error_code::error_cluster_evict_invalid_request"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_singleton_resource,
   "system_error_code::error_cluster_singleton_resource"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_group_singleton_resource,
   "system_error_code::error_cluster_group_singleton_resource"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_resource_provider_failed,
   "system_error_code::error_cluster_resource_provider_failed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_resource_configuration_error,
   "system_error_code::error_cluster_resource_configuration_error"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_group_busy,
   "system_error_code::error_cluster_group_busy"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_not_shared_volume,
   "system_error_code::error_cluster_not_shared_volume"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_invalid_security_descriptor,
   "system_error_code::error_cluster_invalid_security_descriptor"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_shared_volumes_in_use,
   "system_error_code::error_cluster_shared_volumes_in_use"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_use_shared_volumes_api,
   "system_error_code::error_cluster_use_shared_volumes_api"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_backup_in_progress,
   "system_error_code::error_cluster_backup_in_progress"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_non_csv_path,
   "system_error_code::error_non_csv_path"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_csv_volume_not_local,
   "system_error_code::error_csv_volume_not_local"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_watchdog_terminating,
   "system_error_code::error_cluster_watchdog_terminating"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_resource_vetoed_move_incompatible_nodes,
   "system_error_code::error_cluster_resource_vetoed_move_incompatible_nodes"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_invalid_node_weight,
   "system_error_code::error_cluster_invalid_node_weight"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_resource_vetoed_call,
   "system_error_code::error_cluster_resource_vetoed_call"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_resmon_system_resources_lacking,
   "system_error_code::error_resmon_system_resources_lacking"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_resource_vetoed_move_not_enough_resources_on_destination,
   "system_error_code::error_cluster_resource_vetoed_move_not_enough_resources_on_destination"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_resource_vetoed_move_not_enough_resources_on_source,
   "system_error_code::error_cluster_resource_vetoed_move_not_enough_resources_on_source"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_group_queued,
   "system_error_code::error_cluster_group_queued"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_resource_locked_status,
   "system_error_code::error_cluster_resource_locked_status"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_shared_volume_failover_not_allowed,
   "system_error_code::error_cluster_shared_volume_failover_not_allowed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_node_drain_in_progress,
   "system_error_code::error_cluster_node_drain_in_progress"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_disk_not_connected,
   "system_error_code::error_cluster_disk_not_connected"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_disk_not_csv_capable,
   "system_error_code::error_disk_not_csv_capable"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_resource_not_in_available_storage,
   "system_error_code::error_resource_not_in_available_storage"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_shared_volume_redirected,
   "system_error_code::error_cluster_shared_volume_redirected"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_shared_volume_not_redirected,
   "system_error_code::error_cluster_shared_volume_not_redirected"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_cannot_return_properties,
   "system_error_code::error_cluster_cannot_return_properties"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_resource_contains_unsupported_diff_area_for_shared_volumes,
   "system_error_code::error_cluster_resource_contains_unsupported_diff_area_for_shared_volumes"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_resource_is_in_maintenance_mode,
   "system_error_code::error_cluster_resource_is_in_maintenance_mode"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_affinity_conflict,
   "system_error_code::error_cluster_affinity_conflict"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cluster_resource_is_replica_virtual_machine,
   "system_error_code::error_cluster_resource_is_replica_virtual_machine"
  },
   std::pair<system_error_code, std::string_view>{
   system_error_code::error_encryption_failed,
   "system_error_code::error_encryption_failed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_decryption_failed,
   "system_error_code::error_decryption_failed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_file_encrypted,
   "system_error_code::error_file_encrypted"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_no_recovery_policy,
   "system_error_code::error_no_recovery_policy"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_no_efs,
   "system_error_code::error_no_efs"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_wrong_efs,
   "system_error_code::error_wrong_efs"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_no_user_keys,
   "system_error_code::error_no_user_keys"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_file_not_encrypted,
   "system_error_code::error_file_not_encrypted"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_not_export_format,
   "system_error_code::error_not_export_format"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_file_read_only,
   "system_error_code::error_file_read_only"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_dir_efs_disallowed,
   "system_error_code::error_dir_efs_disallowed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_efs_server_not_trusted,
   "system_error_code::error_efs_server_not_trusted"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_bad_recovery_policy,
   "system_error_code::error_bad_recovery_policy"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_efs_alg_blob_too_big,
   "system_error_code::error_efs_alg_blob_too_big"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_volume_not_support_efs,
   "system_error_code::error_volume_not_support_efs"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_efs_disabled,
   "system_error_code::error_efs_disabled"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_efs_version_not_support,
   "system_error_code::error_efs_version_not_support"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cs_encryption_invalid_server_response,
   "system_error_code::error_cs_encryption_invalid_server_response"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cs_encryption_unsupported_server,
   "system_error_code::error_cs_encryption_unsupported_server"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cs_encryption_existing_encrypted_file,
   "system_error_code::error_cs_encryption_existing_encrypted_file"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cs_encryption_new_encrypted_file,
   "system_error_code::error_cs_encryption_new_encrypted_file"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cs_encryption_file_not_cse,
   "system_error_code::error_cs_encryption_file_not_cse"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_encryption_policy_denies_operation,
   "system_error_code::error_encryption_policy_denies_operation"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_no_browser_servers_found,
   "system_error_code::error_no_browser_servers_found"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::sched_e_service_not_localsystem,
   "system_error_code::sched_e_service_not_localsystem"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_log_sector_invalid,
   "system_error_code::error_log_sector_invalid"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_log_sector_parity_invalid,
   "system_error_code::error_log_sector_parity_invalid"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_log_sector_remapped,
   "system_error_code::error_log_sector_remapped"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_log_block_incomplete,
   "system_error_code::error_log_block_incomplete"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_log_invalid_range,
   "system_error_code::error_log_invalid_range"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_log_blocks_exhausted,
   "system_error_code::error_log_blocks_exhausted"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_log_read_context_invalid,
   "system_error_code::error_log_read_context_invalid"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_log_restart_invalid,
   "system_error_code::error_log_restart_invalid"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_log_block_version,
   "system_error_code::error_log_block_version"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_log_block_invalid,
   "system_error_code::error_log_block_invalid"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_log_read_mode_invalid,
   "system_error_code::error_log_read_mode_invalid"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_log_no_restart,
   "system_error_code::error_log_no_restart"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_log_metadata_corrupt,
   "system_error_code::error_log_metadata_corrupt"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_log_metadata_invalid,
   "system_error_code::error_log_metadata_invalid"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_log_metadata_inconsistent,
   "system_error_code::error_log_metadata_inconsistent"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_log_reservation_invalid,
   "system_error_code::error_log_reservation_invalid"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_log_cant_delete,
   "system_error_code::error_log_cant_delete"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_log_container_limit_exceeded,
   "system_error_code::error_log_container_limit_exceeded"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_log_start_of_log,
   "system_error_code::error_log_start_of_log"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_log_policy_already_installed,
   "system_error_code::error_log_policy_already_installed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_log_policy_not_installed,
   "system_error_code::error_log_policy_not_installed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_log_policy_invalid,
   "system_error_code::error_log_policy_invalid"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_log_policy_conflict,
   "system_error_code::error_log_policy_conflict"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_log_pinned_archive_tail,
   "system_error_code::error_log_pinned_archive_tail"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_log_record_nonexistent,
   "system_error_code::error_log_record_nonexistent"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_log_records_reserved_invalid,
   "system_error_code::error_log_records_reserved_invalid"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_log_space_reserved_invalid,
   "system_error_code::error_log_space_reserved_invalid"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_log_tail_invalid,
   "system_error_code::error_log_tail_invalid"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_log_full,
   "system_error_code::error_log_full"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_could_not_resize_log,
   "system_error_code::error_could_not_resize_log"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_log_multiplexed,
   "system_error_code::error_log_multiplexed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_log_dedicated,
   "system_error_code::error_log_dedicated"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_log_archive_not_in_progress,
   "system_error_code::error_log_archive_not_in_progress"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_log_archive_in_progress,
   "system_error_code::error_log_archive_in_progress"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_log_ephemeral,
   "system_error_code::error_log_ephemeral"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_log_not_enough_containers,
   "system_error_code::error_log_not_enough_containers"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_log_client_already_registered,
   "system_error_code::error_log_client_already_registered"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_log_client_not_registered,
   "system_error_code::error_log_client_not_registered"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_log_full_handler_in_progress,
   "system_error_code::error_log_full_handler_in_progress"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_log_container_read_failed,
   "system_error_code::error_log_container_read_failed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_log_container_write_failed,
   "system_error_code::error_log_container_write_failed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_log_container_open_failed,
   "system_error_code::error_log_container_open_failed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_log_container_state_invalid,
   "system_error_code::error_log_container_state_invalid"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_log_state_invalid,
   "system_error_code::error_log_state_invalid"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_log_pinned,
   "system_error_code::error_log_pinned"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_log_metadata_flush_failed,
   "system_error_code::error_log_metadata_flush_failed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_log_inconsistent_security,
   "system_error_code::error_log_inconsistent_security"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_log_appended_flush_failed,
   "system_error_code::error_log_appended_flush_failed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_log_pinned_reservation,
   "system_error_code::error_log_pinned_reservation"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_transaction,
   "system_error_code::error_invalid_transaction"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_transaction_not_active,
   "system_error_code::error_transaction_not_active"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_transaction_request_not_valid,
   "system_error_code::error_transaction_request_not_valid"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_transaction_not_requested,
   "system_error_code::error_transaction_not_requested"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_transaction_already_aborted,
   "system_error_code::error_transaction_already_aborted"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_transaction_already_committed,
   "system_error_code::error_transaction_already_committed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_tm_initialization_failed,
   "system_error_code::error_tm_initialization_failed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_resourcemanager_read_only,
   "system_error_code::error_resourcemanager_read_only"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_transaction_not_joined,
   "system_error_code::error_transaction_not_joined"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_transaction_superior_exists,
   "system_error_code::error_transaction_superior_exists"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_crm_protocol_already_exists,
   "system_error_code::error_crm_protocol_already_exists"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_transaction_propagation_failed,
   "system_error_code::error_transaction_propagation_failed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_crm_protocol_not_found,
   "system_error_code::error_crm_protocol_not_found"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_transaction_invalid_marshall_buffer,
   "system_error_code::error_transaction_invalid_marshall_buffer"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_current_transaction_not_valid,
   "system_error_code::error_current_transaction_not_valid"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_transaction_not_found,
   "system_error_code::error_transaction_not_found"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_resourcemanager_not_found,
   "system_error_code::error_resourcemanager_not_found"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_enlistment_not_found,
   "system_error_code::error_enlistment_not_found"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_transactionmanager_not_found,
   "system_error_code::error_transactionmanager_not_found"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_transactionmanager_not_online,
   "system_error_code::error_transactionmanager_not_online"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_transactionmanager_recovery_name_collision,
   "system_error_code::error_transactionmanager_recovery_name_collision"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_transaction_not_root,
   "system_error_code::error_transaction_not_root"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_transaction_object_expired,
   "system_error_code::error_transaction_object_expired"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_transaction_response_not_enlisted,
   "system_error_code::error_transaction_response_not_enlisted"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_transaction_record_too_long,
   "system_error_code::error_transaction_record_too_long"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_implicit_transaction_not_supported,
   "system_error_code::error_implicit_transaction_not_supported"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_transaction_integrity_violated,
   "system_error_code::error_transaction_integrity_violated"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_transactionmanager_identity_mismatch,
   "system_error_code::error_transactionmanager_identity_mismatch"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_rm_cannot_be_frozen_for_snapshot,
   "system_error_code::error_rm_cannot_be_frozen_for_snapshot"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_transaction_must_writethrough,
   "system_error_code::error_transaction_must_writethrough"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_transaction_no_superior,
   "system_error_code::error_transaction_no_superior"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_heuristic_damage_possible,
   "system_error_code::error_heuristic_damage_possible"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_transactional_conflict,
   "system_error_code::error_transactional_conflict"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_rm_not_active,
   "system_error_code::error_rm_not_active"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_rm_metadata_corrupt,
   "system_error_code::error_rm_metadata_corrupt"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_directory_not_rm,
   "system_error_code::error_directory_not_rm"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_transactions_unsupported_remote,
   "system_error_code::error_transactions_unsupported_remote"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_log_resize_invalid_size,
   "system_error_code::error_log_resize_invalid_size"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_object_no_longer_exists,
   "system_error_code::error_object_no_longer_exists"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_stream_miniversion_not_found,
   "system_error_code::error_stream_miniversion_not_found"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_stream_miniversion_not_valid,
   "system_error_code::error_stream_miniversion_not_valid"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_miniversion_inaccessible_from_specified_transaction,
   "system_error_code::error_miniversion_inaccessible_from_specified_transaction"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cant_open_miniversion_with_modify_intent,
   "system_error_code::error_cant_open_miniversion_with_modify_intent"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cant_create_more_stream_miniversions,
   "system_error_code::error_cant_create_more_stream_miniversions"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_remote_file_version_mismatch,
   "system_error_code::error_remote_file_version_mismatch"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_handle_no_longer_valid,
   "system_error_code::error_handle_no_longer_valid"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_no_txf_metadata,
   "system_error_code::error_no_txf_metadata"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_log_corruption_detected,
   "system_error_code::error_log_corruption_detected"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cant_recover_with_handle_open,
   "system_error_code::error_cant_recover_with_handle_open"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_rm_disconnected,
   "system_error_code::error_rm_disconnected"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_enlistment_not_superior,
   "system_error_code::error_enlistment_not_superior"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_recovery_not_needed,
   "system_error_code::error_recovery_not_needed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_rm_already_started,
   "system_error_code::error_rm_already_started"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_file_identity_not_persistent,
   "system_error_code::error_file_identity_not_persistent"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cant_break_transactional_dependency,
   "system_error_code::error_cant_break_transactional_dependency"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cant_cross_rm_boundary,
   "system_error_code::error_cant_cross_rm_boundary"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_txf_dir_not_empty,
   "system_error_code::error_txf_dir_not_empty"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_indoubt_transactions_exist,
   "system_error_code::error_indoubt_transactions_exist"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_tm_volatile,
   "system_error_code::error_tm_volatile"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_rollback_timer_expired,
   "system_error_code::error_rollback_timer_expired"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_txf_attribute_corrupt,
   "system_error_code::error_txf_attribute_corrupt"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_efs_not_allowed_in_transaction,
   "system_error_code::error_efs_not_allowed_in_transaction"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_transactional_open_not_allowed,
   "system_error_code::error_transactional_open_not_allowed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_log_growth_failed,
   "system_error_code::error_log_growth_failed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_transacted_mapping_unsupported_remote,
   "system_error_code::error_transacted_mapping_unsupported_remote"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_txf_metadata_already_present,
   "system_error_code::error_txf_metadata_already_present"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_transaction_scope_callbacks_not_set,
   "system_error_code::error_transaction_scope_callbacks_not_set"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_transaction_required_promotion,
   "system_error_code::error_transaction_required_promotion"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cannot_execute_file_in_transaction,
   "system_error_code::error_cannot_execute_file_in_transaction"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_transactions_not_frozen,
   "system_error_code::error_transactions_not_frozen"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_transaction_freeze_in_progress,
   "system_error_code::error_transaction_freeze_in_progress"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_not_snapshot_volume,
   "system_error_code::error_not_snapshot_volume"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_no_savepoint_with_open_files,
   "system_error_code::error_no_savepoint_with_open_files"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_data_lost_repair,
   "system_error_code::error_data_lost_repair"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_sparse_not_allowed_in_transaction,
   "system_error_code::error_sparse_not_allowed_in_transaction"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_tm_identity_mismatch,
   "system_error_code::error_tm_identity_mismatch"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_floated_section,
   "system_error_code::error_floated_section"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cannot_accept_transacted_work,
   "system_error_code::error_cannot_accept_transacted_work"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_cannot_abort_transactions,
   "system_error_code::error_cannot_abort_transactions"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_bad_clusters,
   "system_error_code::error_bad_clusters"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_compression_not_allowed_in_transaction,
   "system_error_code::error_compression_not_allowed_in_transaction"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_volume_dirty,
   "system_error_code::error_volume_dirty"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_no_link_tracking_in_transaction,
   "system_error_code::error_no_link_tracking_in_transaction"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_operation_not_supported_in_transaction,
   "system_error_code::error_operation_not_supported_in_transaction"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_expired_handle,
   "system_error_code::error_expired_handle"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_transaction_not_enlisted,
   "system_error_code::error_transaction_not_enlisted"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ctx_winstation_name_invalid,
   "system_error_code::error_ctx_winstation_name_invalid"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ctx_invalid_pd,
   "system_error_code::error_ctx_invalid_pd"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ctx_pd_not_found,
   "system_error_code::error_ctx_pd_not_found"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ctx_wd_not_found,
   "system_error_code::error_ctx_wd_not_found"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ctx_cannot_make_eventlog_entry,
   "system_error_code::error_ctx_cannot_make_eventlog_entry"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ctx_service_name_collision,
   "system_error_code::error_ctx_service_name_collision"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ctx_close_pending,
   "system_error_code::error_ctx_close_pending"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ctx_no_outbuf,
   "system_error_code::error_ctx_no_outbuf"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ctx_modem_inf_not_found,
   "system_error_code::error_ctx_modem_inf_not_found"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ctx_invalid_modemname,
   "system_error_code::error_ctx_invalid_modemname"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ctx_modem_response_error,
   "system_error_code::error_ctx_modem_response_error"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ctx_modem_response_timeout,
   "system_error_code::error_ctx_modem_response_timeout"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ctx_modem_response_no_carrier,
   "system_error_code::error_ctx_modem_response_no_carrier"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ctx_modem_response_no_dialtone,
   "system_error_code::error_ctx_modem_response_no_dialtone"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ctx_modem_response_busy,
   "system_error_code::error_ctx_modem_response_busy"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ctx_modem_response_voice,
   "system_error_code::error_ctx_modem_response_voice"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ctx_td_error,
   "system_error_code::error_ctx_td_error"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ctx_winstation_not_found,
   "system_error_code::error_ctx_winstation_not_found"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ctx_winstation_already_exists,
   "system_error_code::error_ctx_winstation_already_exists"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ctx_winstation_busy,
   "system_error_code::error_ctx_winstation_busy"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ctx_bad_video_mode,
   "system_error_code::error_ctx_bad_video_mode"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ctx_graphics_invalid,
   "system_error_code::error_ctx_graphics_invalid"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ctx_logon_disabled,
   "system_error_code::error_ctx_logon_disabled"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ctx_not_console,
   "system_error_code::error_ctx_not_console"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ctx_client_query_timeout,
   "system_error_code::error_ctx_client_query_timeout"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ctx_console_disconnect,
   "system_error_code::error_ctx_console_disconnect"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ctx_console_connect,
   "system_error_code::error_ctx_console_connect"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ctx_shadow_denied,
   "system_error_code::error_ctx_shadow_denied"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ctx_winstation_access_denied,
   "system_error_code::error_ctx_winstation_access_denied"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ctx_invalid_wd,
   "system_error_code::error_ctx_invalid_wd"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ctx_shadow_invalid,
   "system_error_code::error_ctx_shadow_invalid"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ctx_shadow_disabled,
   "system_error_code::error_ctx_shadow_disabled"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ctx_client_license_in_use,
   "system_error_code::error_ctx_client_license_in_use"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ctx_client_license_not_set,
   "system_error_code::error_ctx_client_license_not_set"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ctx_license_not_available,
   "system_error_code::error_ctx_license_not_available"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ctx_license_client_invalid,
   "system_error_code::error_ctx_license_client_invalid"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ctx_license_expired,
   "system_error_code::error_ctx_license_expired"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ctx_shadow_not_running,
   "system_error_code::error_ctx_shadow_not_running"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ctx_shadow_ended_by_mode_change,
   "system_error_code::error_ctx_shadow_ended_by_mode_change"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_activation_count_exceeded,
   "system_error_code::error_activation_count_exceeded"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ctx_winstations_disabled,
   "system_error_code::error_ctx_winstations_disabled"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ctx_encryption_level_required,
   "system_error_code::error_ctx_encryption_level_required"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ctx_session_in_use,
   "system_error_code::error_ctx_session_in_use"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ctx_no_force_logoff,
   "system_error_code::error_ctx_no_force_logoff"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ctx_account_restriction,
   "system_error_code::error_ctx_account_restriction"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_rdp_protocol_error,
   "system_error_code::error_rdp_protocol_error"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ctx_cdm_connect,
   "system_error_code::error_ctx_cdm_connect"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ctx_cdm_disconnect,
   "system_error_code::error_ctx_cdm_disconnect"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ctx_security_layer_error,
   "system_error_code::error_ctx_security_layer_error"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ts_incompatible_sessions,
   "system_error_code::error_ts_incompatible_sessions"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ts_video_subsystem_error,
   "system_error_code::error_ts_video_subsystem_error"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::frs_err_invalid_api_sequence,
   "system_error_code::frs_err_invalid_api_sequence"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::frs_err_starting_service,
   "system_error_code::frs_err_starting_service"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::frs_err_stopping_service,
   "system_error_code::frs_err_stopping_service"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::frs_err_internal_api,
   "system_error_code::frs_err_internal_api"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::frs_err_internal,
   "system_error_code::frs_err_internal"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::frs_err_service_comm,
   "system_error_code::frs_err_service_comm"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::frs_err_insufficient_priv,
   "system_error_code::frs_err_insufficient_priv"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::frs_err_authentication,
   "system_error_code::frs_err_authentication"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::frs_err_parent_insufficient_priv,
   "system_error_code::frs_err_parent_insufficient_priv"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::frs_err_parent_authentication,
   "system_error_code::frs_err_parent_authentication"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::frs_err_child_to_parent_comm,
   "system_error_code::frs_err_child_to_parent_comm"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::frs_err_parent_to_child_comm,
   "system_error_code::frs_err_parent_to_child_comm"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::frs_err_sysvol_populate,
   "system_error_code::frs_err_sysvol_populate"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::frs_err_sysvol_populate_timeout,
   "system_error_code::frs_err_sysvol_populate_timeout"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::frs_err_sysvol_is_busy,
   "system_error_code::frs_err_sysvol_is_busy"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::frs_err_sysvol_demote,
   "system_error_code::frs_err_sysvol_demote"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::frs_err_invalid_service_parameter,
   "system_error_code::frs_err_invalid_service_parameter"
  },
   std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_not_installed,
   "system_error_code::error_ds_not_installed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_membership_evaluated_locally,
   "system_error_code::error_ds_membership_evaluated_locally"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_no_attribute_or_value,
   "system_error_code::error_ds_no_attribute_or_value"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_invalid_attribute_syntax,
   "system_error_code::error_ds_invalid_attribute_syntax"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_attribute_type_undefined,
   "system_error_code::error_ds_attribute_type_undefined"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_attribute_or_value_exists,
   "system_error_code::error_ds_attribute_or_value_exists"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_busy,
   "system_error_code::error_ds_busy"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_unavailable,
   "system_error_code::error_ds_unavailable"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_no_rids_allocated,
   "system_error_code::error_ds_no_rids_allocated"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_no_more_rids,
   "system_error_code::error_ds_no_more_rids"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_incorrect_role_owner,
   "system_error_code::error_ds_incorrect_role_owner"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_ridmgr_init_error,
   "system_error_code::error_ds_ridmgr_init_error"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_obj_class_violation,
   "system_error_code::error_ds_obj_class_violation"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_cant_on_non_leaf,
   "system_error_code::error_ds_cant_on_non_leaf"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_cant_on_rdn,
   "system_error_code::error_ds_cant_on_rdn"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_cant_mod_obj_class,
   "system_error_code::error_ds_cant_mod_obj_class"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_cross_dom_move_error,
   "system_error_code::error_ds_cross_dom_move_error"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_gc_not_available,
   "system_error_code::error_ds_gc_not_available"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_shared_policy,
   "system_error_code::error_shared_policy"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_policy_object_not_found,
   "system_error_code::error_policy_object_not_found"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_policy_only_in_ds,
   "system_error_code::error_policy_only_in_ds"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_promotion_active,
   "system_error_code::error_promotion_active"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_no_promotion_active,
   "system_error_code::error_no_promotion_active"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_operations_error,
   "system_error_code::error_ds_operations_error"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_protocol_error,
   "system_error_code::error_ds_protocol_error"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_timelimit_exceeded,
   "system_error_code::error_ds_timelimit_exceeded"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_sizelimit_exceeded,
   "system_error_code::error_ds_sizelimit_exceeded"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_admin_limit_exceeded,
   "system_error_code::error_ds_admin_limit_exceeded"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_compare_false,
   "system_error_code::error_ds_compare_false"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_compare_true,
   "system_error_code::error_ds_compare_true"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_auth_method_not_supported,
   "system_error_code::error_ds_auth_method_not_supported"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_strong_auth_required,
   "system_error_code::error_ds_strong_auth_required"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_inappropriate_auth,
   "system_error_code::error_ds_inappropriate_auth"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_auth_unknown,
   "system_error_code::error_ds_auth_unknown"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_referral,
   "system_error_code::error_ds_referral"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_unavailable_crit_extension,
   "system_error_code::error_ds_unavailable_crit_extension"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_confidentiality_required,
   "system_error_code::error_ds_confidentiality_required"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_inappropriate_matching,
   "system_error_code::error_ds_inappropriate_matching"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_constraint_violation,
   "system_error_code::error_ds_constraint_violation"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_no_such_object,
   "system_error_code::error_ds_no_such_object"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_alias_problem,
   "system_error_code::error_ds_alias_problem"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_invalid_dn_syntax,
   "system_error_code::error_ds_invalid_dn_syntax"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_is_leaf,
   "system_error_code::error_ds_is_leaf"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_alias_deref_problem,
   "system_error_code::error_ds_alias_deref_problem"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_unwilling_to_perform,
   "system_error_code::error_ds_unwilling_to_perform"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_loop_detect,
   "system_error_code::error_ds_loop_detect"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_naming_violation,
   "system_error_code::error_ds_naming_violation"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_object_results_too_large,
   "system_error_code::error_ds_object_results_too_large"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_affects_multiple_dsas,
   "system_error_code::error_ds_affects_multiple_dsas"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_server_down,
   "system_error_code::error_ds_server_down"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_local_error,
   "system_error_code::error_ds_local_error"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_encoding_error,
   "system_error_code::error_ds_encoding_error"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_decoding_error,
   "system_error_code::error_ds_decoding_error"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_filter_unknown,
   "system_error_code::error_ds_filter_unknown"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_param_error,
   "system_error_code::error_ds_param_error"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_not_supported,
   "system_error_code::error_ds_not_supported"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_no_results_returned,
   "system_error_code::error_ds_no_results_returned"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_control_not_found,
   "system_error_code::error_ds_control_not_found"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_client_loop,
   "system_error_code::error_ds_client_loop"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_referral_limit_exceeded,
   "system_error_code::error_ds_referral_limit_exceeded"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_sort_control_missing,
   "system_error_code::error_ds_sort_control_missing"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_offset_range_error,
   "system_error_code::error_ds_offset_range_error"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_ridmgr_disabled,
   "system_error_code::error_ds_ridmgr_disabled"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_root_must_be_nc,
   "system_error_code::error_ds_root_must_be_nc"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_add_replica_inhibited,
   "system_error_code::error_ds_add_replica_inhibited"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_att_not_def_in_schema,
   "system_error_code::error_ds_att_not_def_in_schema"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_max_obj_size_exceeded,
   "system_error_code::error_ds_max_obj_size_exceeded"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_obj_string_name_exists,
   "system_error_code::error_ds_obj_string_name_exists"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_no_rdn_defined_in_schema,
   "system_error_code::error_ds_no_rdn_defined_in_schema"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_rdn_doesnt_match_schema,
   "system_error_code::error_ds_rdn_doesnt_match_schema"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_no_requested_atts_found,
   "system_error_code::error_ds_no_requested_atts_found"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_user_buffer_to_small,
   "system_error_code::error_ds_user_buffer_to_small"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_att_is_not_on_obj,
   "system_error_code::error_ds_att_is_not_on_obj"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_illegal_mod_operation,
   "system_error_code::error_ds_illegal_mod_operation"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_obj_too_large,
   "system_error_code::error_ds_obj_too_large"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_bad_instance_type,
   "system_error_code::error_ds_bad_instance_type"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_masterdsa_required,
   "system_error_code::error_ds_masterdsa_required"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_object_class_required,
   "system_error_code::error_ds_object_class_required"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_missing_required_att,
   "system_error_code::error_ds_missing_required_att"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_att_not_def_for_class,
   "system_error_code::error_ds_att_not_def_for_class"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_att_already_exists,
   "system_error_code::error_ds_att_already_exists"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_cant_add_att_values,
   "system_error_code::error_ds_cant_add_att_values"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_single_value_constraint,
   "system_error_code::error_ds_single_value_constraint"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_range_constraint,
   "system_error_code::error_ds_range_constraint"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_att_val_already_exists,
   "system_error_code::error_ds_att_val_already_exists"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_cant_rem_missing_att,
   "system_error_code::error_ds_cant_rem_missing_att"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_cant_rem_missing_att_val,
   "system_error_code::error_ds_cant_rem_missing_att_val"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_root_cant_be_subref,
   "system_error_code::error_ds_root_cant_be_subref"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_no_chaining,
   "system_error_code::error_ds_no_chaining"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_no_chained_eval,
   "system_error_code::error_ds_no_chained_eval"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_no_parent_object,
   "system_error_code::error_ds_no_parent_object"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_parent_is_an_alias,
   "system_error_code::error_ds_parent_is_an_alias"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_cant_mix_master_and_reps,
   "system_error_code::error_ds_cant_mix_master_and_reps"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_children_exist,
   "system_error_code::error_ds_children_exist"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_obj_not_found,
   "system_error_code::error_ds_obj_not_found"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_aliased_obj_missing,
   "system_error_code::error_ds_aliased_obj_missing"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_bad_name_syntax,
   "system_error_code::error_ds_bad_name_syntax"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_alias_points_to_alias,
   "system_error_code::error_ds_alias_points_to_alias"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_cant_deref_alias,
   "system_error_code::error_ds_cant_deref_alias"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_out_of_scope,
   "system_error_code::error_ds_out_of_scope"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_object_being_removed,
   "system_error_code::error_ds_object_being_removed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_cant_delete_dsa_obj,
   "system_error_code::error_ds_cant_delete_dsa_obj"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_generic_error,
   "system_error_code::error_ds_generic_error"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_dsa_must_be_int_master,
   "system_error_code::error_ds_dsa_must_be_int_master"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_class_not_dsa,
   "system_error_code::error_ds_class_not_dsa"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_insuff_access_rights,
   "system_error_code::error_ds_insuff_access_rights"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_illegal_superior,
   "system_error_code::error_ds_illegal_superior"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_attribute_owned_by_sam,
   "system_error_code::error_ds_attribute_owned_by_sam"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_name_too_many_parts,
   "system_error_code::error_ds_name_too_many_parts"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_name_too_long,
   "system_error_code::error_ds_name_too_long"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_name_value_too_long,
   "system_error_code::error_ds_name_value_too_long"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_name_unparseable,
   "system_error_code::error_ds_name_unparseable"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_name_type_unknown,
   "system_error_code::error_ds_name_type_unknown"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_not_an_object,
   "system_error_code::error_ds_not_an_object"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_sec_desc_too_short,
   "system_error_code::error_ds_sec_desc_too_short"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_sec_desc_invalid,
   "system_error_code::error_ds_sec_desc_invalid"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_no_deleted_name,
   "system_error_code::error_ds_no_deleted_name"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_subref_must_have_parent,
   "system_error_code::error_ds_subref_must_have_parent"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_ncname_must_be_nc,
   "system_error_code::error_ds_ncname_must_be_nc"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_cant_add_system_only,
   "system_error_code::error_ds_cant_add_system_only"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_class_must_be_concrete,
   "system_error_code::error_ds_class_must_be_concrete"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_invalid_dmd,
   "system_error_code::error_ds_invalid_dmd"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_obj_guid_exists,
   "system_error_code::error_ds_obj_guid_exists"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_not_on_backlink,
   "system_error_code::error_ds_not_on_backlink"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_no_crossref_for_nc,
   "system_error_code::error_ds_no_crossref_for_nc"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_shutting_down,
   "system_error_code::error_ds_shutting_down"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_unknown_operation,
   "system_error_code::error_ds_unknown_operation"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_invalid_role_owner,
   "system_error_code::error_ds_invalid_role_owner"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_couldnt_contact_fsmo,
   "system_error_code::error_ds_couldnt_contact_fsmo"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_cross_nc_dn_rename,
   "system_error_code::error_ds_cross_nc_dn_rename"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_cant_mod_system_only,
   "system_error_code::error_ds_cant_mod_system_only"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_replicator_only,
   "system_error_code::error_ds_replicator_only"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_obj_class_not_defined,
   "system_error_code::error_ds_obj_class_not_defined"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_obj_class_not_subclass,
   "system_error_code::error_ds_obj_class_not_subclass"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_name_reference_invalid,
   "system_error_code::error_ds_name_reference_invalid"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_cross_ref_exists,
   "system_error_code::error_ds_cross_ref_exists"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_cant_del_master_crossref,
   "system_error_code::error_ds_cant_del_master_crossref"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_subtree_notify_not_nc_head,
   "system_error_code::error_ds_subtree_notify_not_nc_head"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_notify_filter_too_complex,
   "system_error_code::error_ds_notify_filter_too_complex"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_dup_rdn,
   "system_error_code::error_ds_dup_rdn"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_dup_oid,
   "system_error_code::error_ds_dup_oid"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_dup_mapi_id,
   "system_error_code::error_ds_dup_mapi_id"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_dup_schema_id_guid,
   "system_error_code::error_ds_dup_schema_id_guid"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_dup_ldap_display_name,
   "system_error_code::error_ds_dup_ldap_display_name"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_semantic_att_test,
   "system_error_code::error_ds_semantic_att_test"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_syntax_mismatch,
   "system_error_code::error_ds_syntax_mismatch"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_exists_in_must_have,
   "system_error_code::error_ds_exists_in_must_have"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_exists_in_may_have,
   "system_error_code::error_ds_exists_in_may_have"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_nonexistent_may_have,
   "system_error_code::error_ds_nonexistent_may_have"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_nonexistent_must_have,
   "system_error_code::error_ds_nonexistent_must_have"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_aux_cls_test_fail,
   "system_error_code::error_ds_aux_cls_test_fail"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_nonexistent_poss_sup,
   "system_error_code::error_ds_nonexistent_poss_sup"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_sub_cls_test_fail,
   "system_error_code::error_ds_sub_cls_test_fail"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_bad_rdn_att_id_syntax,
   "system_error_code::error_ds_bad_rdn_att_id_syntax"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_exists_in_aux_cls,
   "system_error_code::error_ds_exists_in_aux_cls"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_exists_in_sub_cls,
   "system_error_code::error_ds_exists_in_sub_cls"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_exists_in_poss_sup,
   "system_error_code::error_ds_exists_in_poss_sup"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_recalcschema_failed,
   "system_error_code::error_ds_recalcschema_failed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_tree_delete_not_finished,
   "system_error_code::error_ds_tree_delete_not_finished"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_cant_delete,
   "system_error_code::error_ds_cant_delete"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_att_schema_req_id,
   "system_error_code::error_ds_att_schema_req_id"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_bad_att_schema_syntax,
   "system_error_code::error_ds_bad_att_schema_syntax"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_cant_cache_att,
   "system_error_code::error_ds_cant_cache_att"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_cant_cache_class,
   "system_error_code::error_ds_cant_cache_class"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_cant_remove_att_cache,
   "system_error_code::error_ds_cant_remove_att_cache"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_cant_remove_class_cache,
   "system_error_code::error_ds_cant_remove_class_cache"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_cant_retrieve_dn,
   "system_error_code::error_ds_cant_retrieve_dn"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_missing_supref,
   "system_error_code::error_ds_missing_supref"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_cant_retrieve_instance,
   "system_error_code::error_ds_cant_retrieve_instance"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_code_inconsistency,
   "system_error_code::error_ds_code_inconsistency"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_database_error,
   "system_error_code::error_ds_database_error"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_governsid_missing,
   "system_error_code::error_ds_governsid_missing"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_missing_expected_att,
   "system_error_code::error_ds_missing_expected_att"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_ncname_missing_cr_ref,
   "system_error_code::error_ds_ncname_missing_cr_ref"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_security_checking_error,
   "system_error_code::error_ds_security_checking_error"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_schema_not_loaded,
   "system_error_code::error_ds_schema_not_loaded"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_schema_alloc_failed,
   "system_error_code::error_ds_schema_alloc_failed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_att_schema_req_syntax,
   "system_error_code::error_ds_att_schema_req_syntax"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_gcverify_error,
   "system_error_code::error_ds_gcverify_error"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_dra_schema_mismatch,
   "system_error_code::error_ds_dra_schema_mismatch"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_cant_find_dsa_obj,
   "system_error_code::error_ds_cant_find_dsa_obj"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_cant_find_expected_nc,
   "system_error_code::error_ds_cant_find_expected_nc"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_cant_find_nc_in_cache,
   "system_error_code::error_ds_cant_find_nc_in_cache"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_cant_retrieve_child,
   "system_error_code::error_ds_cant_retrieve_child"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_security_illegal_modify,
   "system_error_code::error_ds_security_illegal_modify"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_cant_replace_hidden_rec,
   "system_error_code::error_ds_cant_replace_hidden_rec"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_bad_hierarchy_file,
   "system_error_code::error_ds_bad_hierarchy_file"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_build_hierarchy_table_failed,
   "system_error_code::error_ds_build_hierarchy_table_failed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_config_param_missing,
   "system_error_code::error_ds_config_param_missing"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_counting_ab_indices_failed,
   "system_error_code::error_ds_counting_ab_indices_failed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_hierarchy_table_malloc_failed,
   "system_error_code::error_ds_hierarchy_table_malloc_failed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_internal_failure,
   "system_error_code::error_ds_internal_failure"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_unknown_error,
   "system_error_code::error_ds_unknown_error"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_root_requires_class_top,
   "system_error_code::error_ds_root_requires_class_top"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_refusing_fsmo_roles,
   "system_error_code::error_ds_refusing_fsmo_roles"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_missing_fsmo_settings,
   "system_error_code::error_ds_missing_fsmo_settings"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_unable_to_surrender_roles,
   "system_error_code::error_ds_unable_to_surrender_roles"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_dra_generic,
   "system_error_code::error_ds_dra_generic"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_dra_invalid_parameter,
   "system_error_code::error_ds_dra_invalid_parameter"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_dra_busy,
   "system_error_code::error_ds_dra_busy"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_dra_bad_dn,
   "system_error_code::error_ds_dra_bad_dn"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_dra_bad_nc,
   "system_error_code::error_ds_dra_bad_nc"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_dra_dn_exists,
   "system_error_code::error_ds_dra_dn_exists"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_dra_internal_error,
   "system_error_code::error_ds_dra_internal_error"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_dra_inconsistent_dit,
   "system_error_code::error_ds_dra_inconsistent_dit"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_dra_connection_failed,
   "system_error_code::error_ds_dra_connection_failed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_dra_bad_instance_type,
   "system_error_code::error_ds_dra_bad_instance_type"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_dra_out_of_mem,
   "system_error_code::error_ds_dra_out_of_mem"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_dra_mail_problem,
   "system_error_code::error_ds_dra_mail_problem"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_dra_ref_already_exists,
   "system_error_code::error_ds_dra_ref_already_exists"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_dra_ref_not_found,
   "system_error_code::error_ds_dra_ref_not_found"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_dra_obj_is_rep_source,
   "system_error_code::error_ds_dra_obj_is_rep_source"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_dra_db_error,
   "system_error_code::error_ds_dra_db_error"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_dra_no_replica,
   "system_error_code::error_ds_dra_no_replica"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_dra_access_denied,
   "system_error_code::error_ds_dra_access_denied"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_dra_not_supported,
   "system_error_code::error_ds_dra_not_supported"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_dra_rpc_cancelled,
   "system_error_code::error_ds_dra_rpc_cancelled"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_dra_source_disabled,
   "system_error_code::error_ds_dra_source_disabled"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_dra_sink_disabled,
   "system_error_code::error_ds_dra_sink_disabled"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_dra_name_collision,
   "system_error_code::error_ds_dra_name_collision"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_dra_source_reinstalled,
   "system_error_code::error_ds_dra_source_reinstalled"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_dra_missing_parent,
   "system_error_code::error_ds_dra_missing_parent"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_dra_preempted,
   "system_error_code::error_ds_dra_preempted"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_dra_abandon_sync,
   "system_error_code::error_ds_dra_abandon_sync"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_dra_shutdown,
   "system_error_code::error_ds_dra_shutdown"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_dra_incompatible_partial_set,
   "system_error_code::error_ds_dra_incompatible_partial_set"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_dra_source_is_partial_replica,
   "system_error_code::error_ds_dra_source_is_partial_replica"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_dra_extn_connection_failed,
   "system_error_code::error_ds_dra_extn_connection_failed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_install_schema_mismatch,
   "system_error_code::error_ds_install_schema_mismatch"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_dup_link_id,
   "system_error_code::error_ds_dup_link_id"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_name_error_resolving,
   "system_error_code::error_ds_name_error_resolving"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_name_error_not_found,
   "system_error_code::error_ds_name_error_not_found"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_name_error_not_unique,
   "system_error_code::error_ds_name_error_not_unique"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_name_error_no_mapping,
   "system_error_code::error_ds_name_error_no_mapping"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_name_error_domain_only,
   "system_error_code::error_ds_name_error_domain_only"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_name_error_no_syntactical_mapping,
   "system_error_code::error_ds_name_error_no_syntactical_mapping"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_constructed_att_mod,
   "system_error_code::error_ds_constructed_att_mod"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_wrong_om_obj_class,
   "system_error_code::error_ds_wrong_om_obj_class"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_dra_repl_pending,
   "system_error_code::error_ds_dra_repl_pending"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_ds_required,
   "system_error_code::error_ds_ds_required"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_invalid_ldap_display_name,
   "system_error_code::error_ds_invalid_ldap_display_name"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_non_base_search,
   "system_error_code::error_ds_non_base_search"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_cant_retrieve_atts,
   "system_error_code::error_ds_cant_retrieve_atts"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_backlink_without_link,
   "system_error_code::error_ds_backlink_without_link"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_epoch_mismatch,
   "system_error_code::error_ds_epoch_mismatch"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_src_name_mismatch,
   "system_error_code::error_ds_src_name_mismatch"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_src_and_dst_nc_identical,
   "system_error_code::error_ds_src_and_dst_nc_identical"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_dst_nc_mismatch,
   "system_error_code::error_ds_dst_nc_mismatch"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_not_authoritive_for_dst_nc,
   "system_error_code::error_ds_not_authoritive_for_dst_nc"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_src_guid_mismatch,
   "system_error_code::error_ds_src_guid_mismatch"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_cant_move_deleted_object,
   "system_error_code::error_ds_cant_move_deleted_object"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_pdc_operation_in_progress,
   "system_error_code::error_ds_pdc_operation_in_progress"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_cross_domain_cleanup_reqd,
   "system_error_code::error_ds_cross_domain_cleanup_reqd"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_illegal_xdom_move_operation,
   "system_error_code::error_ds_illegal_xdom_move_operation"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_cant_with_acct_group_membershps,
   "system_error_code::error_ds_cant_with_acct_group_membershps"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_nc_must_have_nc_parent,
   "system_error_code::error_ds_nc_must_have_nc_parent"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_cr_impossible_to_validate,
   "system_error_code::error_ds_cr_impossible_to_validate"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_dst_domain_not_native,
   "system_error_code::error_ds_dst_domain_not_native"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_missing_infrastructure_container,
   "system_error_code::error_ds_missing_infrastructure_container"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_cant_move_account_group,
   "system_error_code::error_ds_cant_move_account_group"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_cant_move_resource_group,
   "system_error_code::error_ds_cant_move_resource_group"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_invalid_search_flag,
   "system_error_code::error_ds_invalid_search_flag"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_no_tree_delete_above_nc,
   "system_error_code::error_ds_no_tree_delete_above_nc"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_couldnt_lock_tree_for_delete,
   "system_error_code::error_ds_couldnt_lock_tree_for_delete"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_couldnt_identify_objects_for_tree_delete,
   "system_error_code::error_ds_couldnt_identify_objects_for_tree_delete"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_sam_init_failure,
   "system_error_code::error_ds_sam_init_failure"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_sensitive_group_violation,
   "system_error_code::error_ds_sensitive_group_violation"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_cant_mod_primarygroupid,
   "system_error_code::error_ds_cant_mod_primarygroupid"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_illegal_base_schema_mod,
   "system_error_code::error_ds_illegal_base_schema_mod"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_nonsafe_schema_change,
   "system_error_code::error_ds_nonsafe_schema_change"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_schema_update_disallowed,
   "system_error_code::error_ds_schema_update_disallowed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_cant_create_under_schema,
   "system_error_code::error_ds_cant_create_under_schema"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_install_no_src_sch_version,
   "system_error_code::error_ds_install_no_src_sch_version"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_install_no_sch_version_in_inifile,
   "system_error_code::error_ds_install_no_sch_version_in_inifile"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_invalid_group_type,
   "system_error_code::error_ds_invalid_group_type"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_no_nest_globalgroup_in_mixeddomain,
   "system_error_code::error_ds_no_nest_globalgroup_in_mixeddomain"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_no_nest_localgroup_in_mixeddomain,
   "system_error_code::error_ds_no_nest_localgroup_in_mixeddomain"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_global_cant_have_local_member,
   "system_error_code::error_ds_global_cant_have_local_member"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_global_cant_have_universal_member,
   "system_error_code::error_ds_global_cant_have_universal_member"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_universal_cant_have_local_member,
   "system_error_code::error_ds_universal_cant_have_local_member"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_global_cant_have_crossdomain_member,
   "system_error_code::error_ds_global_cant_have_crossdomain_member"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_local_cant_have_crossdomain_local_member,
   "system_error_code::error_ds_local_cant_have_crossdomain_local_member"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_have_primary_members,
   "system_error_code::error_ds_have_primary_members"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_string_sd_conversion_failed,
   "system_error_code::error_ds_string_sd_conversion_failed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_naming_master_gc,
   "system_error_code::error_ds_naming_master_gc"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_dns_lookup_failure,
   "system_error_code::error_ds_dns_lookup_failure"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_couldnt_update_spns,
   "system_error_code::error_ds_couldnt_update_spns"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_cant_retrieve_sd,
   "system_error_code::error_ds_cant_retrieve_sd"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_key_not_unique,
   "system_error_code::error_ds_key_not_unique"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_wrong_linked_att_syntax,
   "system_error_code::error_ds_wrong_linked_att_syntax"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_sam_need_bootkey_password,
   "system_error_code::error_ds_sam_need_bootkey_password"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_sam_need_bootkey_floppy,
   "system_error_code::error_ds_sam_need_bootkey_floppy"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_cant_start,
   "system_error_code::error_ds_cant_start"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_init_failure,
   "system_error_code::error_ds_init_failure"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_no_pkt_privacy_on_connection,
   "system_error_code::error_ds_no_pkt_privacy_on_connection"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_source_domain_in_forest,
   "system_error_code::error_ds_source_domain_in_forest"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_destination_domain_not_in_forest,
   "system_error_code::error_ds_destination_domain_not_in_forest"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_destination_auditing_not_enabled,
   "system_error_code::error_ds_destination_auditing_not_enabled"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_cant_find_dc_for_src_domain,
   "system_error_code::error_ds_cant_find_dc_for_src_domain"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_src_obj_not_group_or_user,
   "system_error_code::error_ds_src_obj_not_group_or_user"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_src_sid_exists_in_forest,
   "system_error_code::error_ds_src_sid_exists_in_forest"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_src_and_dst_object_class_mismatch,
   "system_error_code::error_ds_src_and_dst_object_class_mismatch"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_sam_init_failure,
   "system_error_code::error_sam_init_failure"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_dra_schema_info_ship,
   "system_error_code::error_ds_dra_schema_info_ship"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_dra_schema_conflict,
   "system_error_code::error_ds_dra_schema_conflict"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_dra_earlier_schema_conflict,
   "system_error_code::error_ds_dra_earlier_schema_conflict"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_dra_obj_nc_mismatch,
   "system_error_code::error_ds_dra_obj_nc_mismatch"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_nc_still_has_dsas,
   "system_error_code::error_ds_nc_still_has_dsas"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_gc_required,
   "system_error_code::error_ds_gc_required"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_local_member_of_local_only,
   "system_error_code::error_ds_local_member_of_local_only"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_no_fpo_in_universal_groups,
   "system_error_code::error_ds_no_fpo_in_universal_groups"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_cant_add_to_gc,
   "system_error_code::error_ds_cant_add_to_gc"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_no_checkpoint_with_pdc,
   "system_error_code::error_ds_no_checkpoint_with_pdc"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_source_auditing_not_enabled,
   "system_error_code::error_ds_source_auditing_not_enabled"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_cant_create_in_nondomain_nc,
   "system_error_code::error_ds_cant_create_in_nondomain_nc"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_invalid_name_for_spn,
   "system_error_code::error_ds_invalid_name_for_spn"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_filter_uses_contructed_attrs,
   "system_error_code::error_ds_filter_uses_contructed_attrs"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_unicodepwd_not_in_quotes,
   "system_error_code::error_ds_unicodepwd_not_in_quotes"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_machine_account_quota_exceeded,
   "system_error_code::error_ds_machine_account_quota_exceeded"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_must_be_run_on_dst_dc,
   "system_error_code::error_ds_must_be_run_on_dst_dc"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_src_dc_must_be_sp4_or_greater,
   "system_error_code::error_ds_src_dc_must_be_sp4_or_greater"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_cant_tree_delete_critical_obj,
   "system_error_code::error_ds_cant_tree_delete_critical_obj"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_init_failure_console,
   "system_error_code::error_ds_init_failure_console"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_sam_init_failure_console,
   "system_error_code::error_ds_sam_init_failure_console"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_forest_version_too_high,
   "system_error_code::error_ds_forest_version_too_high"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_domain_version_too_high,
   "system_error_code::error_ds_domain_version_too_high"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_forest_version_too_low,
   "system_error_code::error_ds_forest_version_too_low"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_domain_version_too_low,
   "system_error_code::error_ds_domain_version_too_low"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_incompatible_version,
   "system_error_code::error_ds_incompatible_version"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_low_dsa_version,
   "system_error_code::error_ds_low_dsa_version"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_no_behavior_version_in_mixeddomain,
   "system_error_code::error_ds_no_behavior_version_in_mixeddomain"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_not_supported_sort_order,
   "system_error_code::error_ds_not_supported_sort_order"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_name_not_unique,
   "system_error_code::error_ds_name_not_unique"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_machine_account_created_prent4,
   "system_error_code::error_ds_machine_account_created_prent4"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_out_of_version_store,
   "system_error_code::error_ds_out_of_version_store"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_incompatible_controls_used,
   "system_error_code::error_ds_incompatible_controls_used"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_no_ref_domain,
   "system_error_code::error_ds_no_ref_domain"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_reserved_link_id,
   "system_error_code::error_ds_reserved_link_id"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_link_id_not_available,
   "system_error_code::error_ds_link_id_not_available"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_ag_cant_have_universal_member,
   "system_error_code::error_ds_ag_cant_have_universal_member"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_modifydn_disallowed_by_instance_type,
   "system_error_code::error_ds_modifydn_disallowed_by_instance_type"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_no_object_move_in_schema_nc,
   "system_error_code::error_ds_no_object_move_in_schema_nc"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_modifydn_disallowed_by_flag,
   "system_error_code::error_ds_modifydn_disallowed_by_flag"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_modifydn_wrong_grandparent,
   "system_error_code::error_ds_modifydn_wrong_grandparent"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_name_error_trust_referral,
   "system_error_code::error_ds_name_error_trust_referral"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_not_supported_on_standard_server,
   "system_error_code::error_not_supported_on_standard_server"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_cant_access_remote_part_of_ad,
   "system_error_code::error_ds_cant_access_remote_part_of_ad"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_cr_impossible_to_validate_v2,
   "system_error_code::error_ds_cr_impossible_to_validate_v2"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_thread_limit_exceeded,
   "system_error_code::error_ds_thread_limit_exceeded"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_not_closest,
   "system_error_code::error_ds_not_closest"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_cant_derive_spn_without_server_ref,
   "system_error_code::error_ds_cant_derive_spn_without_server_ref"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_single_user_mode_failed,
   "system_error_code::error_ds_single_user_mode_failed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_ntdscript_syntax_error,
   "system_error_code::error_ds_ntdscript_syntax_error"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_ntdscript_process_error,
   "system_error_code::error_ds_ntdscript_process_error"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_different_repl_epochs,
   "system_error_code::error_ds_different_repl_epochs"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_drs_extensions_changed,
   "system_error_code::error_ds_drs_extensions_changed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_replica_set_change_not_allowed_on_disabled_cr,
   "system_error_code::error_ds_replica_set_change_not_allowed_on_disabled_cr"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_no_msds_intid,
   "system_error_code::error_ds_no_msds_intid"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_dup_msds_intid,
   "system_error_code::error_ds_dup_msds_intid"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_exists_in_rdnattid,
   "system_error_code::error_ds_exists_in_rdnattid"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_authorization_failed,
   "system_error_code::error_ds_authorization_failed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_invalid_script,
   "system_error_code::error_ds_invalid_script"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_remote_crossref_op_failed,
   "system_error_code::error_ds_remote_crossref_op_failed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_cross_ref_busy,
   "system_error_code::error_ds_cross_ref_busy"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_cant_derive_spn_for_deleted_domain,
   "system_error_code::error_ds_cant_derive_spn_for_deleted_domain"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_cant_demote_with_writeable_nc,
   "system_error_code::error_ds_cant_demote_with_writeable_nc"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_duplicate_id_found,
   "system_error_code::error_ds_duplicate_id_found"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_insufficient_attr_to_create_object,
   "system_error_code::error_ds_insufficient_attr_to_create_object"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_group_conversion_error,
   "system_error_code::error_ds_group_conversion_error"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_cant_move_app_basic_group,
   "system_error_code::error_ds_cant_move_app_basic_group"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_cant_move_app_query_group,
   "system_error_code::error_ds_cant_move_app_query_group"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_role_not_verified,
   "system_error_code::error_ds_role_not_verified"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_wko_container_cannot_be_special,
   "system_error_code::error_ds_wko_container_cannot_be_special"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_domain_rename_in_progress,
   "system_error_code::error_ds_domain_rename_in_progress"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_existing_ad_child_nc,
   "system_error_code::error_ds_existing_ad_child_nc"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_repl_lifetime_exceeded,
   "system_error_code::error_ds_repl_lifetime_exceeded"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_disallowed_in_system_container,
   "system_error_code::error_ds_disallowed_in_system_container"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_ldap_send_queue_full,
   "system_error_code::error_ds_ldap_send_queue_full"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_dra_out_schedule_window,
   "system_error_code::error_ds_dra_out_schedule_window"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_policy_not_known,
   "system_error_code::error_ds_policy_not_known"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_no_site_settings_object,
   "system_error_code::error_no_site_settings_object"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_no_secrets,
   "system_error_code::error_no_secrets"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_no_writable_dc_found,
   "system_error_code::error_no_writable_dc_found"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_no_server_object,
   "system_error_code::error_ds_no_server_object"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_no_ntdsa_object,
   "system_error_code::error_ds_no_ntdsa_object"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_non_asq_search,
   "system_error_code::error_ds_non_asq_search"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_audit_failure,
   "system_error_code::error_ds_audit_failure"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_invalid_search_flag_subtree,
   "system_error_code::error_ds_invalid_search_flag_subtree"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_invalid_search_flag_tuple,
   "system_error_code::error_ds_invalid_search_flag_tuple"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_hierarchy_table_too_deep,
   "system_error_code::error_ds_hierarchy_table_too_deep"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_dra_corrupt_utd_vector,
   "system_error_code::error_ds_dra_corrupt_utd_vector"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_dra_secrets_denied,
   "system_error_code::error_ds_dra_secrets_denied"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_reserved_mapi_id,
   "system_error_code::error_ds_reserved_mapi_id"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_mapi_id_not_available,
   "system_error_code::error_ds_mapi_id_not_available"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_dra_missing_krbtgt_secret,
   "system_error_code::error_ds_dra_missing_krbtgt_secret"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_domain_name_exists_in_forest,
   "system_error_code::error_ds_domain_name_exists_in_forest"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_flat_name_exists_in_forest,
   "system_error_code::error_ds_flat_name_exists_in_forest"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_invalid_user_principal_name,
   "system_error_code::error_invalid_user_principal_name"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_oid_mapped_group_cant_have_members,
   "system_error_code::error_ds_oid_mapped_group_cant_have_members"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_oid_not_found,
   "system_error_code::error_ds_oid_not_found"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_dra_recycled_target,
   "system_error_code::error_ds_dra_recycled_target"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_disallowed_nc_redirect,
   "system_error_code::error_ds_disallowed_nc_redirect"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_high_adlds_ffl,
   "system_error_code::error_ds_high_adlds_ffl"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_high_dsa_version,
   "system_error_code::error_ds_high_dsa_version"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_low_adlds_ffl,
   "system_error_code::error_ds_low_adlds_ffl"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_domain_sid_same_as_local_workstation,
   "system_error_code::error_domain_sid_same_as_local_workstation"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_ds_undelete_sam_validation_failed,
   "system_error_code::error_ds_undelete_sam_validation_failed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::error_incorrect_account_type,
   "system_error_code::error_incorrect_account_type"
  },
   std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_rcode_format_error,
   "system_error_code::dns_error_rcode_format_error"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_rcode_server_failure,
   "system_error_code::dns_error_rcode_server_failure"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_rcode_name_error,
   "system_error_code::dns_error_rcode_name_error"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_rcode_not_implemented,
   "system_error_code::dns_error_rcode_not_implemented"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_rcode_refused,
   "system_error_code::dns_error_rcode_refused"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_rcode_yxdomain,
   "system_error_code::dns_error_rcode_yxdomain"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_rcode_yxrrset,
   "system_error_code::dns_error_rcode_yxrrset"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_rcode_nxrrset,
   "system_error_code::dns_error_rcode_nxrrset"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_rcode_notauth,
   "system_error_code::dns_error_rcode_notauth"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_rcode_notzone,
   "system_error_code::dns_error_rcode_notzone"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_rcode_badsig,
   "system_error_code::dns_error_rcode_badsig"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_rcode_badkey,
   "system_error_code::dns_error_rcode_badkey"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_rcode_badtime,
   "system_error_code::dns_error_rcode_badtime"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_keymaster_required,
   "system_error_code::dns_error_keymaster_required"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_not_allowed_on_signed_zone,
   "system_error_code::dns_error_not_allowed_on_signed_zone"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_nsec3_incompatible_with_rsa_sha1,
   "system_error_code::dns_error_nsec3_incompatible_with_rsa_sha1"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_not_enough_signing_key_descriptors,
   "system_error_code::dns_error_not_enough_signing_key_descriptors"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_unsupported_algorithm,
   "system_error_code::dns_error_unsupported_algorithm"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_invalid_key_size,
   "system_error_code::dns_error_invalid_key_size"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_signing_key_not_accessible,
   "system_error_code::dns_error_signing_key_not_accessible"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_ksp_does_not_support_protection,
   "system_error_code::dns_error_ksp_does_not_support_protection"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_unexpected_data_protection_error,
   "system_error_code::dns_error_unexpected_data_protection_error"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_unexpected_cng_error,
   "system_error_code::dns_error_unexpected_cng_error"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_unknown_signing_parameter_version,
   "system_error_code::dns_error_unknown_signing_parameter_version"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_ksp_not_accessible,
   "system_error_code::dns_error_ksp_not_accessible"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_too_many_skds,
   "system_error_code::dns_error_too_many_skds"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_invalid_rollover_period,
   "system_error_code::dns_error_invalid_rollover_period"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_invalid_initial_rollover_offset,
   "system_error_code::dns_error_invalid_initial_rollover_offset"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_rollover_in_progress,
   "system_error_code::dns_error_rollover_in_progress"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_standby_key_not_present,
   "system_error_code::dns_error_standby_key_not_present"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_not_allowed_on_zsk,
   "system_error_code::dns_error_not_allowed_on_zsk"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_not_allowed_on_active_skd,
   "system_error_code::dns_error_not_allowed_on_active_skd"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_rollover_already_queued,
   "system_error_code::dns_error_rollover_already_queued"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_not_allowed_on_unsigned_zone,
   "system_error_code::dns_error_not_allowed_on_unsigned_zone"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_bad_keymaster,
   "system_error_code::dns_error_bad_keymaster"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_invalid_signature_validity_period,
   "system_error_code::dns_error_invalid_signature_validity_period"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_invalid_nsec3_iteration_count,
   "system_error_code::dns_error_invalid_nsec3_iteration_count"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_dnssec_is_disabled,
   "system_error_code::dns_error_dnssec_is_disabled"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_invalid_xml,
   "system_error_code::dns_error_invalid_xml"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_no_valid_trust_anchors,
   "system_error_code::dns_error_no_valid_trust_anchors"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_rollover_not_pokeable,
   "system_error_code::dns_error_rollover_not_pokeable"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_nsec3_name_collision,
   "system_error_code::dns_error_nsec3_name_collision"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_nsec_incompatible_with_nsec3_rsa_sha1,
   "system_error_code::dns_error_nsec_incompatible_with_nsec3_rsa_sha1"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_info_no_records,
   "system_error_code::dns_info_no_records"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_bad_packet,
   "system_error_code::dns_error_bad_packet"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_no_packet,
   "system_error_code::dns_error_no_packet"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_rcode,
   "system_error_code::dns_error_rcode"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_unsecure_packet,
   "system_error_code::dns_error_unsecure_packet"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_request_pending,
   "system_error_code::dns_request_pending"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_invalid_type,
   "system_error_code::dns_error_invalid_type"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_invalid_ip_address,
   "system_error_code::dns_error_invalid_ip_address"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_invalid_property,
   "system_error_code::dns_error_invalid_property"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_try_again_later,
   "system_error_code::dns_error_try_again_later"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_not_unique,
   "system_error_code::dns_error_not_unique"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_non_rfc_name,
   "system_error_code::dns_error_non_rfc_name"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_status_fqdn,
   "system_error_code::dns_status_fqdn"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_status_dotted_name,
   "system_error_code::dns_status_dotted_name"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_status_single_part_name,
   "system_error_code::dns_status_single_part_name"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_invalid_name_char,
   "system_error_code::dns_error_invalid_name_char"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_numeric_name,
   "system_error_code::dns_error_numeric_name"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_not_allowed_on_root_server,
   "system_error_code::dns_error_not_allowed_on_root_server"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_not_allowed_under_delegation,
   "system_error_code::dns_error_not_allowed_under_delegation"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_cannot_find_root_hints,
   "system_error_code::dns_error_cannot_find_root_hints"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_inconsistent_root_hints,
   "system_error_code::dns_error_inconsistent_root_hints"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_dword_value_too_small,
   "system_error_code::dns_error_dword_value_too_small"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_dword_value_too_large,
   "system_error_code::dns_error_dword_value_too_large"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_background_loading,
   "system_error_code::dns_error_background_loading"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_not_allowed_on_rodc,
   "system_error_code::dns_error_not_allowed_on_rodc"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_not_allowed_under_dname,
   "system_error_code::dns_error_not_allowed_under_dname"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_delegation_required,
   "system_error_code::dns_error_delegation_required"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_invalid_policy_table,
   "system_error_code::dns_error_invalid_policy_table"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_zone_does_not_exist,
   "system_error_code::dns_error_zone_does_not_exist"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_no_zone_info,
   "system_error_code::dns_error_no_zone_info"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_invalid_zone_operation,
   "system_error_code::dns_error_invalid_zone_operation"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_zone_configuration_error,
   "system_error_code::dns_error_zone_configuration_error"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_zone_has_no_soa_record,
   "system_error_code::dns_error_zone_has_no_soa_record"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_zone_has_no_ns_records,
   "system_error_code::dns_error_zone_has_no_ns_records"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_zone_locked,
   "system_error_code::dns_error_zone_locked"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_zone_creation_failed,
   "system_error_code::dns_error_zone_creation_failed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_zone_already_exists,
   "system_error_code::dns_error_zone_already_exists"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_autozone_already_exists,
   "system_error_code::dns_error_autozone_already_exists"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_invalid_zone_type,
   "system_error_code::dns_error_invalid_zone_type"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_secondary_requires_master_ip,
   "system_error_code::dns_error_secondary_requires_master_ip"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_zone_not_secondary,
   "system_error_code::dns_error_zone_not_secondary"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_need_secondary_addresses,
   "system_error_code::dns_error_need_secondary_addresses"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_wins_init_failed,
   "system_error_code::dns_error_wins_init_failed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_need_wins_servers,
   "system_error_code::dns_error_need_wins_servers"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_nbstat_init_failed,
   "system_error_code::dns_error_nbstat_init_failed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_soa_delete_invalid,
   "system_error_code::dns_error_soa_delete_invalid"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_forwarder_already_exists,
   "system_error_code::dns_error_forwarder_already_exists"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_zone_requires_master_ip,
   "system_error_code::dns_error_zone_requires_master_ip"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_zone_is_shutdown,
   "system_error_code::dns_error_zone_is_shutdown"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_zone_locked_for_signing,
   "system_error_code::dns_error_zone_locked_for_signing"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_primary_requires_datafile,
   "system_error_code::dns_error_primary_requires_datafile"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_invalid_datafile_name,
   "system_error_code::dns_error_invalid_datafile_name"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_datafile_open_failure,
   "system_error_code::dns_error_datafile_open_failure"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_file_writeback_failed,
   "system_error_code::dns_error_file_writeback_failed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_datafile_parsing,
   "system_error_code::dns_error_datafile_parsing"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_record_does_not_exist,
   "system_error_code::dns_error_record_does_not_exist"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_record_format,
   "system_error_code::dns_error_record_format"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_node_creation_failed,
   "system_error_code::dns_error_node_creation_failed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_unknown_record_type,
   "system_error_code::dns_error_unknown_record_type"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_record_timed_out,
   "system_error_code::dns_error_record_timed_out"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_name_not_in_zone,
   "system_error_code::dns_error_name_not_in_zone"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_cname_loop,
   "system_error_code::dns_error_cname_loop"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_node_is_cname,
   "system_error_code::dns_error_node_is_cname"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_cname_collision,
   "system_error_code::dns_error_cname_collision"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_record_only_at_zone_root,
   "system_error_code::dns_error_record_only_at_zone_root"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_record_already_exists,
   "system_error_code::dns_error_record_already_exists"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_secondary_data,
   "system_error_code::dns_error_secondary_data"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_no_create_cache_data,
   "system_error_code::dns_error_no_create_cache_data"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_name_does_not_exist,
   "system_error_code::dns_error_name_does_not_exist"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_warning_ptr_create_failed,
   "system_error_code::dns_warning_ptr_create_failed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_warning_domain_undeleted,
   "system_error_code::dns_warning_domain_undeleted"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_ds_unavailable,
   "system_error_code::dns_error_ds_unavailable"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_ds_zone_already_exists,
   "system_error_code::dns_error_ds_zone_already_exists"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_no_bootfile_if_ds_zone,
   "system_error_code::dns_error_no_bootfile_if_ds_zone"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_node_is_dname,
   "system_error_code::dns_error_node_is_dname"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_dname_collision,
   "system_error_code::dns_error_dname_collision"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_alias_loop,
   "system_error_code::dns_error_alias_loop"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_info_axfr_complete,
   "system_error_code::dns_info_axfr_complete"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_axfr,
   "system_error_code::dns_error_axfr"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_info_added_local_wins,
   "system_error_code::dns_info_added_local_wins"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_status_continue_needed,
   "system_error_code::dns_status_continue_needed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_no_tcpip,
   "system_error_code::dns_error_no_tcpip"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_no_dns_servers,
   "system_error_code::dns_error_no_dns_servers"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_dp_does_not_exist,
   "system_error_code::dns_error_dp_does_not_exist"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_dp_already_exists,
   "system_error_code::dns_error_dp_already_exists"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_dp_not_enlisted,
   "system_error_code::dns_error_dp_not_enlisted"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_dp_already_enlisted,
   "system_error_code::dns_error_dp_already_enlisted"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_dp_not_available,
   "system_error_code::dns_error_dp_not_available"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::dns_error_dp_fsmo_error,
   "system_error_code::dns_error_dp_fsmo_error"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsaeintr,
   "system_error_code::wsaeintr"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsaebadf,
   "system_error_code::wsaebadf"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsaeacces,
   "system_error_code::wsaeacces"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsaefault,
   "system_error_code::wsaefault"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsaeinval,
   "system_error_code::wsaeinval"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsaemfile,
   "system_error_code::wsaemfile"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsaewouldblock,
   "system_error_code::wsaewouldblock"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsaeinprogress,
   "system_error_code::wsaeinprogress"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsaealready,
   "system_error_code::wsaealready"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsaenotsock,
   "system_error_code::wsaenotsock"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsaedestaddrreq,
   "system_error_code::wsaedestaddrreq"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsaemsgsize,
   "system_error_code::wsaemsgsize"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsaeprototype,
   "system_error_code::wsaeprototype"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsaenoprotoopt,
   "system_error_code::wsaenoprotoopt"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsaeprotonosupport,
   "system_error_code::wsaeprotonosupport"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsaesocktnosupport,
   "system_error_code::wsaesocktnosupport"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsaeopnotsupp,
   "system_error_code::wsaeopnotsupp"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsaepfnosupport,
   "system_error_code::wsaepfnosupport"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsaeafnosupport,
   "system_error_code::wsaeafnosupport"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsaeaddrinuse,
   "system_error_code::wsaeaddrinuse"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsaeaddrnotavail,
   "system_error_code::wsaeaddrnotavail"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsaenetdown,
   "system_error_code::wsaenetdown"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsaenetunreach,
   "system_error_code::wsaenetunreach"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsaenetreset,
   "system_error_code::wsaenetreset"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsaeconnaborted,
   "system_error_code::wsaeconnaborted"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsaeconnreset,
   "system_error_code::wsaeconnreset"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsaenobufs,
   "system_error_code::wsaenobufs"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsaeisconn,
   "system_error_code::wsaeisconn"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsaenotconn,
   "system_error_code::wsaenotconn"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsaeshutdown,
   "system_error_code::wsaeshutdown"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsaetoomanyrefs,
   "system_error_code::wsaetoomanyrefs"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsaetimedout,
   "system_error_code::wsaetimedout"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsaeconnrefused,
   "system_error_code::wsaeconnrefused"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsaeloop,
   "system_error_code::wsaeloop"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsaenametoolong,
   "system_error_code::wsaenametoolong"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsaehostdown,
   "system_error_code::wsaehostdown"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsaehostunreach,
   "system_error_code::wsaehostunreach"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsaenotempty,
   "system_error_code::wsaenotempty"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsaeproclim,
   "system_error_code::wsaeproclim"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsaeusers,
   "system_error_code::wsaeusers"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsaedquot,
   "system_error_code::wsaedquot"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsaestale,
   "system_error_code::wsaestale"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsaeremote,
   "system_error_code::wsaeremote"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsasysnotready,
   "system_error_code::wsasysnotready"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsavernotsupported,
   "system_error_code::wsavernotsupported"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsanotinitialised,
   "system_error_code::wsanotinitialised"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsaediscon,
   "system_error_code::wsaediscon"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsaenomore,
   "system_error_code::wsaenomore"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsaecancelled,
   "system_error_code::wsaecancelled"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsaeinvalidproctable,
   "system_error_code::wsaeinvalidproctable"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsaeinvalidprovider,
   "system_error_code::wsaeinvalidprovider"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsaeproviderfailedinit,
   "system_error_code::wsaeproviderfailedinit"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsasyscallfailure,
   "system_error_code::wsasyscallfailure"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsaservice_not_found,
   "system_error_code::wsaservice_not_found"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsatype_not_found,
   "system_error_code::wsatype_not_found"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsa_e_no_more,
   "system_error_code::wsa_e_no_more"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsa_e_cancelled,
   "system_error_code::wsa_e_cancelled"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsaerefused,
   "system_error_code::wsaerefused"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsahost_not_found,
   "system_error_code::wsahost_not_found"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsatry_again,
   "system_error_code::wsatry_again"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsano_recovery,
   "system_error_code::wsano_recovery"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsano_data,
   "system_error_code::wsano_data"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsa_qos_receivers,
   "system_error_code::wsa_qos_receivers"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsa_qos_senders,
   "system_error_code::wsa_qos_senders"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsa_qos_no_senders,
   "system_error_code::wsa_qos_no_senders"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsa_qos_no_receivers,
   "system_error_code::wsa_qos_no_receivers"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsa_qos_request_confirmed,
   "system_error_code::wsa_qos_request_confirmed"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsa_qos_admission_failure,
   "system_error_code::wsa_qos_admission_failure"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsa_qos_policy_failure,
   "system_error_code::wsa_qos_policy_failure"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsa_qos_bad_style,
   "system_error_code::wsa_qos_bad_style"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsa_qos_bad_object,
   "system_error_code::wsa_qos_bad_object"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsa_qos_traffic_ctrl_error,
   "system_error_code::wsa_qos_traffic_ctrl_error"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsa_qos_generic_error,
   "system_error_code::wsa_qos_generic_error"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsa_qos_eservicetype,
   "system_error_code::wsa_qos_eservicetype"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsa_qos_eflowspec,
   "system_error_code::wsa_qos_eflowspec"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsa_qos_eprovspecbuf,
   "system_error_code::wsa_qos_eprovspecbuf"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsa_qos_efilterstyle,
   "system_error_code::wsa_qos_efilterstyle"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsa_qos_efiltertype,
   "system_error_code::wsa_qos_efiltertype"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsa_qos_efiltercount,
   "system_error_code::wsa_qos_efiltercount"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsa_qos_eobjlength,
   "system_error_code::wsa_qos_eobjlength"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsa_qos_eflowcount,
   "system_error_code::wsa_qos_eflowcount"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsa_qos_eunkownpsobj,
   "system_error_code::wsa_qos_eunkownpsobj"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsa_qos_epolicyobj,
   "system_error_code::wsa_qos_epolicyobj"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsa_qos_eflowdesc,
   "system_error_code::wsa_qos_eflowdesc"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsa_qos_epsflowspec,
   "system_error_code::wsa_qos_epsflowspec"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsa_qos_epsfilterspec,
   "system_error_code::wsa_qos_epsfilterspec"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsa_qos_esdmodeobj,
   "system_error_code::wsa_qos_esdmodeobj"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsa_qos_eshaperateobj,
   "system_error_code::wsa_qos_eshaperateobj"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsa_qos_reserved_petype,
   "system_error_code::wsa_qos_reserved_petype"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsa_secure_host_not_found,
   "system_error_code::wsa_secure_host_not_found"
  },
  std::pair<system_error_code, std::string_view>{
   system_error_code::wsa_ipsec_name_policy_error,
   "system_error_code::wsa_ipsec_name_policy_error"
  },
 };

 inline constexpr std::string_view lookup_enum(system_error_code const system_error_code) noexcept {
  auto const it = std::find_if(
   std::cbegin(SYSTEM_ERROR_CODE_LOOKUP), 
   std::cend(SYSTEM_ERROR_CODE_LOOKUP), 
   [&](auto&& entry) noexcept {
    return entry.first == system_error_code;
   });
  if (it == std::cend(SYSTEM_ERROR_CODE_LOOKUP)) [[unlikely]] {
   return "system_error_code::invalid_enum";
  } else [[likely]] {
   return it->second;
  }
 }
}