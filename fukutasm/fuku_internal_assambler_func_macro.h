#pragma once

/************************************************************
            automatically generated by hands
                do not edit (please)
************************************************************/

#define fuku_internal_assambler_arith_add 0
#define fuku_internal_assambler_arith_or  1
#define fuku_internal_assambler_arith_adc 2
#define fuku_internal_assambler_arith_sbb 3
#define fuku_internal_assambler_arith_and 4
#define fuku_internal_assambler_arith_sub 5
#define fuku_internal_assambler_arith_xor 6
#define fuku_internal_assambler_arith_cmp 7

#define fuku_internal_assambler_arith_ex_not  2
#define fuku_internal_assambler_arith_ex_neg  3
#define fuku_internal_assambler_arith_ex_mul  4
#define fuku_internal_assambler_arith_ex_imul 5
#define fuku_internal_assambler_arith_ex_div  6
#define fuku_internal_assambler_arith_ex_idiv 7

#define fuku_internal_assambler_arith_inc 0
#define fuku_internal_assambler_arith_dec 1

#define fuku_internal_assambler_shift_rol 0
#define fuku_internal_assambler_shift_ror 1
#define fuku_internal_assambler_shift_rcl 2
#define fuku_internal_assambler_shift_rcr 3
#define fuku_internal_assambler_shift_shl 4
#define fuku_internal_assambler_shift_shr 5
#define fuku_internal_assambler_shift_sar 7

#define fuku_internal_assambler_shift_shld 0
#define fuku_internal_assambler_shift_shrd 1

#define fuku_internal_assambler_bittest_bt  4
#define fuku_internal_assambler_bittest_bts 5
#define fuku_internal_assambler_bittest_btr 6
#define fuku_internal_assambler_bittest_btc 7

#define fuku_internal_assambler_bittest_bsf 0
#define fuku_internal_assambler_bittest_bsr 1

#define fuku_internal_assambler_string_out 55
#define fuku_internal_assambler_string_mov 82
#define fuku_internal_assambler_string_cmp 83
#define fuku_internal_assambler_string_sto 85
#define fuku_internal_assambler_string_lod 86
#define fuku_internal_assambler_string_sca 87

#define fuku_internal_assambler_pop 0
#define fuku_internal_assambler_push 6

#include "fuku_internal_assambler_pattern_macro.h"

static uint64_t di_fl_jcc[] = {
        X86_EFLAGS_TEST_OF , X86_EFLAGS_TEST_OF, //jo   / jno
        X86_EFLAGS_TEST_CF , X86_EFLAGS_TEST_CF, //jb   / jae
        X86_EFLAGS_TEST_ZF , X86_EFLAGS_TEST_ZF, //je   / jne
        X86_EFLAGS_TEST_ZF | X86_EFLAGS_TEST_CF, X86_EFLAGS_TEST_ZF | X86_EFLAGS_TEST_CF, //jbe / jnbe
        X86_EFLAGS_TEST_SF , X86_EFLAGS_TEST_SF, //js   / jns
        X86_EFLAGS_TEST_PF , X86_EFLAGS_TEST_PF, //jp   / jnp
        X86_EFLAGS_TEST_OF | X86_EFLAGS_TEST_SF, X86_EFLAGS_TEST_OF | X86_EFLAGS_TEST_SF, //jnge / jge
        X86_EFLAGS_TEST_OF | X86_EFLAGS_TEST_SF | X86_EFLAGS_TEST_ZF, X86_EFLAGS_TEST_OF | X86_EFLAGS_TEST_SF | X86_EFLAGS_TEST_ZF //jng / jnle
};


#define is_used_short_eax() (ctx.short_cfg & FUKU_ASM_SHORT_CFG_USE_EAX_SHORT)
#define is_used_short_imm() (ctx.short_cfg & FUKU_ASM_SHORT_CFG_USE_IMM_SHORT)
#define is_used_short_disp() (ctx.short_cfg & FUKU_ASM_SHORT_CFG_USE_DISP_SHORT)


#define gen_func_body_onebyte_no_arg(name ,byte, id, cap_eflags) \
    fuku_asm_ret_type  _##name## (fuku_assambler_ctx& ctx) { \
        gencleanerdata\
        emit_b(ctx, byte);\
        gen_func_return(id, cap_eflags)\
    } 

#define gen_func_body_twobyte_no_arg(name ,byte1,byte2, id, cap_eflags) \
    fuku_asm_ret_type  _##name## (fuku_assambler_ctx& ctx) { \
        gencleanerdata\
        emit_b(ctx, byte1);\
        emit_b(ctx, byte2);\
        gen_func_return(id, cap_eflags)\
    } 

#define gen_func_body_threebyte_no_arg(name ,byte1,byte2,byte3, id, cap_eflags) \
    fuku_asm_ret_type  _##name## (fuku_assambler_ctx& ctx) { \
        gencleanerdata\
        emit_b(ctx, byte1);\
        emit_b(ctx, byte2);\
        emit_b(ctx, byte3);\
        gen_func_return(id, cap_eflags)\
    } 


#define gen_func_body_ff_r(name ,type, id, cap_eflags) \
    fuku_asm_ret_type  fuku_asm_gen_name(_,name,) (fuku_assambler_ctx& ctx, const fuku_register& src) { \
        gencleanerdata\
        gen_pattern32_1em_rm_idx(0xFF, src, type)\
        gen_func_return(id, cap_eflags)\
    } 

#define gen_func_body_ff_offset(name ,type, id, cap_eflags) \
    fuku_asm_ret_type  fuku_asm_gen_name(_,name,) (fuku_assambler_ctx& ctx, const fuku_immediate& src) { \
        gencleanerdata\
        gen_pattern32_1em_immdw(type, fuku_register(FUKU_REG_NONE),  src)\
        gen_func_return(id, cap_eflags)\
    } 

#define gen_func_body_ff_op(name ,type, id, cap_eflags) \
    fuku_asm_ret_type  fuku_asm_gen_name(_,name,) (fuku_assambler_ctx& ctx, const fuku_operand& src) { \
        gencleanerdata\
        gen_pattern32_1em_op_idx(0xFF, src, type)\
        gen_func_return(id, cap_eflags)\
    } 


#define gen_func_body_arith(name ,type, id, cap_eflags) \
    fuku_asm_ret_type  fuku_asm_gen_name(_,name,_b) (fuku_assambler_ctx& ctx, const fuku_register& dst, const fuku_register& src) { \
        gencleanerdata\
        gen_pattern32_1em_rm_r(8*type, dst, src)\
        gen_func_return(id, cap_eflags)\
    } \
    fuku_asm_ret_type  fuku_asm_gen_name(_,name,_b) (fuku_assambler_ctx& ctx, const fuku_register& dst,const fuku_immediate& src) { \
        gencleanerdata\
        if(is_used_short_eax() && dst.get_reg() == FUKU_REG_AL) {\
            gen_pattern32_1em_immb(0x04 + 8*type, dst, src)\
        } else {\
            gen_pattern32_1em_rm_idx_immb(0x80, dst, type, src)\
        }\
        gen_func_return(id, cap_eflags)\
    } \
    fuku_asm_ret_type  fuku_asm_gen_name(_,name,_b) (fuku_assambler_ctx& ctx, const fuku_register& dst,const fuku_operand& src) { \
        gencleanerdata\
        gen_pattern32_1em_op_idx(0x02 + 8*type, src, dst)\
        gen_func_return(id, cap_eflags)\
    } \
    fuku_asm_ret_type  fuku_asm_gen_name(_,name,_b) (fuku_assambler_ctx& ctx, const fuku_operand& dst,const fuku_immediate& src) { \
        gencleanerdata\
        gen_pattern32_1em_op_idx_immb(0x80, dst, type, src)\
        gen_func_return(id, cap_eflags)\
    } \
    fuku_asm_ret_type  fuku_asm_gen_name(_,name,_b) (fuku_assambler_ctx& ctx, const fuku_operand& dst, const fuku_register& src) { \
        gencleanerdata\
        gen_pattern32_1em_op_r(0x00 + 8 * type, dst, src)\
        gen_func_return(id, cap_eflags)\
    } \
\
    fuku_asm_ret_type  fuku_asm_gen_name(_,name,_w) (fuku_assambler_ctx& ctx, const fuku_register& dst, const fuku_register& src) { \
        gencleanerdata\
        gen_pattern32_1em_rm_r_word(0x01 + 8 * type, dst, src)\
        gen_func_return(id, cap_eflags)\
    } \
    fuku_asm_ret_type  fuku_asm_gen_name(_,name,_w) (fuku_assambler_ctx& ctx, const fuku_register& dst,const fuku_immediate& src) { \
        gencleanerdata\
        if(is_used_short_eax() && dst.get_reg() == FUKU_REG_AX) {\
            gen_pattern32_1em_immw_word(0x05 + 8*type, dst, src)\
        } else {\
            if (is_used_short_imm() && src.is_8()) {\
                gen_pattern32_1em_rm_idx_immb_word(0x83, dst, type, src)\
            }else{\
                gen_pattern32_1em_rm_idx_immw_word(0x81, dst, type, src)\
            }\
        }\
        gen_func_return(id, cap_eflags)\
    } \
    fuku_asm_ret_type  fuku_asm_gen_name(_,name,_w) (fuku_assambler_ctx& ctx, const fuku_register& dst,const fuku_operand& src) { \
        gencleanerdata\
        gen_pattern32_1em_op_r_word(0x03 + 8*type, src, dst)\
        gen_func_return(id, cap_eflags)\
    } \
    fuku_asm_ret_type  fuku_asm_gen_name(_,name,_w) (fuku_assambler_ctx& ctx, const fuku_operand& dst, const fuku_register& src) { \
        gencleanerdata\
        gen_pattern32_1em_op_r_word(0x01 + 8*type, dst, src)\
        gen_func_return(id, cap_eflags)\
    } \
    fuku_asm_ret_type  fuku_asm_gen_name(_,name,_w) (fuku_assambler_ctx& ctx, const fuku_operand& dst,const fuku_immediate& src) { \
        gencleanerdata\
        if (is_used_short_imm() && src.is_8()) {\
            gen_pattern32_1em_op_idx_immb_word(0x83, dst, type, src)\
        }else{\
            gen_pattern32_1em_op_idx_immw_word(0x81, dst, type, src)\
        }\
        gen_func_return(id, cap_eflags)\
    } \
\
    fuku_asm_ret_type  fuku_asm_gen_name(_,name,_dw) (fuku_assambler_ctx& ctx, const fuku_register& dst, const fuku_register& src) { \
        gencleanerdata\
        gen_pattern32_1em_rm_r(0x01 + 8*type, dst, src)\
        gen_func_return(id, cap_eflags)\
    } \
    fuku_asm_ret_type  fuku_asm_gen_name(_,name,_dw) (fuku_assambler_ctx& ctx, const fuku_register& dst,const fuku_immediate& src) { \
        gencleanerdata\
         if(is_used_short_eax() && dst.get_reg() == FUKU_REG_EAX) {\
            gen_pattern32_1em_immdw(0x05 + 8*type, dst, src)\
        } else {\
            if (is_used_short_imm() && src.is_8()) {\
                gen_pattern32_1em_rm_idx_immb(0x83, dst, type, src)\
            }else{\
                gen_pattern32_1em_rm_idx_immdw(0x81, dst, type, src)\
            }\
        }\
        gen_func_return(id, cap_eflags)\
    } \
    fuku_asm_ret_type  fuku_asm_gen_name(_,name,_dw) (fuku_assambler_ctx& ctx, const fuku_register& dst,const fuku_operand& src) { \
        gencleanerdata\
        gen_pattern32_1em_op_r(0x03 + 8*type, src, dst)\
        gen_func_return(id, cap_eflags)\
    } \
    fuku_asm_ret_type  fuku_asm_gen_name(_,name,_dw) (fuku_assambler_ctx& ctx, const fuku_operand& dst, const fuku_register& src) { \
        gencleanerdata\
        gen_pattern32_1em_op_r(0x01 + 8*type, dst, src)\
        gen_func_return(id, cap_eflags)\
    } \
    fuku_asm_ret_type  fuku_asm_gen_name(_,name,_dw) (fuku_assambler_ctx& ctx, const fuku_operand& dst,const fuku_immediate& src) { \
        gencleanerdata\
         if (is_used_short_imm() && src.is_8()) {\
            gen_pattern32_1em_op_idx_immb(0x83, dst, type, src)\
        }else{\
            gen_pattern32_1em_op_idx_immdw(0x81, dst, type, src)\
        }\
        gen_func_return(id, cap_eflags)\
    } \
\
    fuku_asm_ret_type  fuku_asm_gen_name(_,name,_qw) (fuku_assambler_ctx& ctx, const fuku_register& dst, const fuku_register& src) { \
        gencleanerdata\
        gen_pattern64_1em_rm_r(0x01 + 8*type, dst, src)\
        gen_func_return(id, cap_eflags)\
    } \
    fuku_asm_ret_type  fuku_asm_gen_name(_,name,_qw) (fuku_assambler_ctx& ctx, const fuku_register& dst,const fuku_immediate& src) { \
        gencleanerdata\
       if(is_used_short_eax() && dst.get_reg() == FUKU_REG_RAX) {\
            gen_pattern64_1em_immdw(0x05 + 8*type, dst, src)\
        } else {\
            if (is_used_short_imm() && src.is_8()) {\
                gen_pattern64_1em_rm_idx_immb(0x83, dst, type, src)\
            }else{\
                gen_pattern64_1em_rm_idx_immdw(0x81, dst, type, src)\
            }\
        }\
        gen_func_return(id, cap_eflags)\
    } \
    fuku_asm_ret_type  fuku_asm_gen_name(_,name,_qw) (fuku_assambler_ctx& ctx, const fuku_register& dst,const fuku_operand& src) { \
        gencleanerdata\
        gen_pattern64_1em_op_r(0x03 + 8*type, src, dst)\
        gen_func_return(id, cap_eflags)\
    } \
    fuku_asm_ret_type  fuku_asm_gen_name(_,name,_qw) (fuku_assambler_ctx& ctx, const fuku_operand& dst, const fuku_register& src) { \
        gencleanerdata\
        gen_pattern64_1em_op_r(0x01 + 8*type, dst, src)\
        gen_func_return(id, cap_eflags)\
    } \
    fuku_asm_ret_type  fuku_asm_gen_name(_,name,_qw) (fuku_assambler_ctx& ctx, const fuku_operand& dst,const fuku_immediate& src) { \
        gencleanerdata\
         if (is_used_short_imm() && src.is_8()) {\
            gen_pattern64_1em_op_idx_immb(0x83, dst, type, src)\
        }else{\
            gen_pattern64_1em_op_idx_immdw(0x81, dst, type, src)\
        }\
        gen_func_return(id, cap_eflags)\
    } 



#define gen_func_body_arith_ex_one_op(name ,type, id, cap_eflags) \
    fuku_asm_ret_type  fuku_asm_gen_name(_,name,_b) (fuku_assambler_ctx& ctx, const fuku_register& src) { \
        gencleanerdata\
        gen_pattern32_1em_rm_idx(0xF6, src, type)\
        gen_func_return(id, cap_eflags)\
    } \
    fuku_asm_ret_type  fuku_asm_gen_name(_,name,_b) (fuku_assambler_ctx& ctx, const fuku_operand& src) { \
        gencleanerdata\
        gen_pattern32_1em_op_idx(0xF6, src, type)\
        gen_func_return(id, cap_eflags)\
    } \
\
    fuku_asm_ret_type  fuku_asm_gen_name(_,name,_w) (fuku_assambler_ctx& ctx, const fuku_register& src) { \
        gencleanerdata\
        gen_pattern32_1em_rm_idx_word(0xF7, src, type)\
        gen_func_return(id, cap_eflags)\
    } \
    fuku_asm_ret_type  fuku_asm_gen_name(_,name,_w) (fuku_assambler_ctx& ctx, const fuku_operand& src) { \
        gencleanerdata\
        gen_pattern32_1em_op_idx_word(0xF7, src, type)\
        gen_func_return(id, cap_eflags)\
    } \
\
    fuku_asm_ret_type  fuku_asm_gen_name(_,name,_dw) (fuku_assambler_ctx& ctx, const fuku_register& src) { \
        gencleanerdata\
        gen_pattern32_1em_rm_idx(0xF7, src, type)\
        gen_func_return(id, cap_eflags)\
    } \
    fuku_asm_ret_type  fuku_asm_gen_name(_,name,_dw) (fuku_assambler_ctx& ctx, const fuku_operand& src) { \
        gencleanerdata\
        gen_pattern32_1em_op_idx(0xF7, src, type)\
        gen_func_return(id, cap_eflags)\
    } \
\
    fuku_asm_ret_type  fuku_asm_gen_name(_,name,_qw) (fuku_assambler_ctx& ctx, const fuku_register& src) { \
        gencleanerdata\
        gen_pattern64_1em_rm_idx(0xF7, src, type)\
        gen_func_return(id, cap_eflags)\
    } \
    fuku_asm_ret_type  fuku_asm_gen_name(_,name,_qw) (fuku_assambler_ctx& ctx, const fuku_operand& src) { \
        gencleanerdata\
        gen_pattern64_1em_op_idx(0xF7, src, type)\
        gen_func_return(id, cap_eflags)\
    } 

#define gen_func_body_arith_incdec(name ,type, id, cap_eflags) \
    fuku_asm_ret_type  fuku_asm_gen_name(_,name,_b) (fuku_assambler_ctx& ctx, const fuku_register& src) { \
        gencleanerdata\
        gen_pattern32_1em_rm_idx(0xFE, src, type)\
        gen_func_return(id, cap_eflags)\
    } \
    fuku_asm_ret_type  fuku_asm_gen_name(_,name,_b) (fuku_assambler_ctx& ctx, const fuku_operand& src) { \
        gencleanerdata\
        gen_pattern32_1em_op_idx(0xFE, src, type)\
        gen_func_return(id, cap_eflags)\
    } \
\
    fuku_asm_ret_type  fuku_asm_gen_name(_,name,_w) (fuku_assambler_ctx& ctx, const fuku_register& src) { \
        gencleanerdata\
        gen_pattern32_1em_rm_idx_word(0xFF, src, type)\
        gen_func_return(id, cap_eflags)\
    } \
    fuku_asm_ret_type  fuku_asm_gen_name(_,name,_w) (fuku_assambler_ctx& ctx, const fuku_operand& src) { \
        gencleanerdata\
        gen_pattern32_1em_op_idx_word(0xFF, src, type)\
        gen_func_return(id, cap_eflags)\
    } \
\
    fuku_asm_ret_type  fuku_asm_gen_name(_,name,_dw) (fuku_assambler_ctx& ctx, const fuku_register& src) { \
        gencleanerdata\
        gen_pattern32_1em_rm_idx(0xFF, src, type)\
        gen_func_return(id, cap_eflags)\
    } \
    fuku_asm_ret_type  fuku_asm_gen_name(_,name,_dw) (fuku_assambler_ctx& ctx, const fuku_operand& src) { \
        gencleanerdata\
        gen_pattern32_1em_op_idx(0xFF, src, type)\
        gen_func_return(id, cap_eflags)\
    } \
\
    fuku_asm_ret_type  fuku_asm_gen_name(_,name,_qw) (fuku_assambler_ctx& ctx, const fuku_register& src) {\
        gencleanerdata\
        gen_pattern64_1em_rm_idx(0xFF, src, type)\
        gen_func_return(id, cap_eflags)\
    } \
    fuku_asm_ret_type  fuku_asm_gen_name(_,name,_qw) (fuku_assambler_ctx& ctx, const fuku_operand& src) {  \
        gencleanerdata\
        gen_pattern64_1em_op_idx(0xFF, src, type)\
        gen_func_return(id, cap_eflags)\
    }

#define gen_func_body_shift(name ,type, id, cap_eflags) \
     fuku_asm_ret_type  fuku_asm_gen_name(_,name,_cl_b)(fuku_assambler_ctx& ctx, const fuku_register& dst) {\
       gencleanerdata\
       gen_pattern32_1em_rm_idx(0xD2, dst, type)\
       gen_func_return(id, cap_eflags)\
     } \
     fuku_asm_ret_type  fuku_asm_gen_name(_,name,_cl_b)(fuku_assambler_ctx& ctx, const fuku_operand& dst) {\
       gencleanerdata\
       gen_pattern32_1em_op_idx(0xD2, dst, type)\
       gen_func_return(id, cap_eflags)\
     } \
      fuku_asm_ret_type  fuku_asm_gen_name(_,name,_b)(fuku_assambler_ctx& ctx, const fuku_register& dst, const fuku_immediate& src) {\
       gencleanerdata\
       emit_optional_rex_32(ctx, dst);\
       if(is_used_short_imm() && src.get_immediate8() == 1) {\
          gen_pattern32_1em_rm_idx(0xD0, dst, type)\
       }else {\
          gen_pattern32_1em_rm_idx_immb(0xC0, dst, type, src)\
       }\
       gen_func_return(id, cap_eflags)\
     } \
      fuku_asm_ret_type  fuku_asm_gen_name(_,name,_b)(fuku_assambler_ctx& ctx, const fuku_operand& dst, const fuku_immediate& src) {\
       gencleanerdata\
       if(is_used_short_imm() && src.get_immediate8() == 1) {\
          gen_pattern32_1em_op_idx(0xD0, dst, type)\
       }else {\
          gen_pattern32_1em_op_idx_immb(0xC0, dst, type, src)\
       }\
       gen_func_return(id, cap_eflags)\
     } \
\
      fuku_asm_ret_type  fuku_asm_gen_name(_,name,_cl_w)(fuku_assambler_ctx& ctx, const fuku_register& dst) {\
       gencleanerdata\
       gen_pattern32_1em_rm_idx_word(0xD3, dst, type)\
       gen_func_return(id, cap_eflags)\
     } \
     fuku_asm_ret_type  fuku_asm_gen_name(_,name,_cl_w)(fuku_assambler_ctx& ctx, const fuku_operand& dst) {\
       gencleanerdata\
       gen_pattern32_1em_op_idx_word(0xD3, dst, type)\
       gen_func_return(id, cap_eflags)\
     } \
      fuku_asm_ret_type  fuku_asm_gen_name(_,name,_w)(fuku_assambler_ctx& ctx, const fuku_register& dst, const fuku_immediate& src) {\
       gencleanerdata\
       if(is_used_short_imm() && src.get_immediate8() == 1) {\
          gen_pattern32_1em_rm_idx_word(0xD1, dst, type)\
       }else {\
          gen_pattern32_1em_rm_idx_immb_word(0xC1, dst, type, src)\
       }\
       gen_func_return(id, cap_eflags)\
     } \
      fuku_asm_ret_type  fuku_asm_gen_name(_,name,_w)(fuku_assambler_ctx& ctx, const fuku_operand& dst, const fuku_immediate& src) {\
       gencleanerdata\
       if(is_used_short_imm() && src.get_immediate8() == 1) {\
          gen_pattern32_1em_op_idx_word(0xD1, dst, type)\
       }else {\
          gen_pattern32_1em_op_idx_immb_word(0xC1, dst, type, src)\
       }\
       gen_func_return(id, cap_eflags)\
     } \
\
    fuku_asm_ret_type  fuku_asm_gen_name(_,name,_cl_dw)(fuku_assambler_ctx& ctx, const fuku_register& dst) {\
       gencleanerdata\
       gen_pattern32_1em_rm_idx(0xD3, dst, type)\
       gen_func_return(id, cap_eflags)\
     } \
     fuku_asm_ret_type  fuku_asm_gen_name(_,name,_cl_dw)(fuku_assambler_ctx& ctx, const fuku_operand& dst) {\
       gencleanerdata\
       gen_pattern32_1em_op_idx(0xD3, dst, type)\
       gen_func_return(id, cap_eflags)\
     } \
      fuku_asm_ret_type  fuku_asm_gen_name(_,name,_dw)(fuku_assambler_ctx& ctx, const fuku_register& dst, const fuku_immediate& src) {\
       gencleanerdata\
       if(is_used_short_imm() && src.get_immediate8() == 1) {\
          gen_pattern32_1em_rm_idx(0xD1, dst, type)\
       }else {\
          gen_pattern32_1em_rm_idx_immb(0xC1, dst, type, src)\
       }\
       gen_func_return(id, cap_eflags)\
     } \
      fuku_asm_ret_type  fuku_asm_gen_name(_,name,_dw)(fuku_assambler_ctx& ctx, const fuku_operand& dst, const fuku_immediate& src) {\
       gencleanerdata\
       if(is_used_short_imm() && src.get_immediate8() == 1) {\
          gen_pattern32_1em_op_idx(0xD1, dst, type)\
       }else {\
          gen_pattern32_1em_op_idx_immb(0xC1, dst, type, src)\
       }\
       gen_func_return(id, cap_eflags)\
     } \
\
    fuku_asm_ret_type  fuku_asm_gen_name(_,name,_cl_qw)(fuku_assambler_ctx& ctx, const fuku_register& dst) {\
       gencleanerdata\
       gen_pattern64_1em_rm_idx(0xD3, dst, type)\
       gen_func_return(id, cap_eflags)\
     } \
     fuku_asm_ret_type  fuku_asm_gen_name(_,name,_cl_qw)(fuku_assambler_ctx& ctx, const fuku_operand& dst) {\
       gencleanerdata\
       gen_pattern64_1em_op_idx(0xD3, dst, type)\
       gen_func_return(id, cap_eflags)\
     } \
      fuku_asm_ret_type  fuku_asm_gen_name(_,name,_qw)(fuku_assambler_ctx& ctx, const fuku_register& dst, const fuku_immediate& src) {\
       gencleanerdata\
       if(is_used_short_imm() && src.get_immediate8() == 1) {\
          gen_pattern64_1em_rm_idx(0xD1, dst, type)\
       }else {\
          gen_pattern64_1em_rm_idx_immb(0xC1, dst, type, src)\
       }\
       gen_func_return(id, cap_eflags)\
     } \
      fuku_asm_ret_type  fuku_asm_gen_name(_,name,_qw)(fuku_assambler_ctx& ctx, const fuku_operand& dst, const fuku_immediate& src) {\
       gencleanerdata\
       if(is_used_short_imm() && src.get_immediate8() == 1) {\
          gen_pattern64_1em_op_idx(0xD1, dst, type)\
       }else {\
          gen_pattern64_1em_op_idx_immb(0xC1, dst, type, src)\
       }\
       gen_func_return(id, cap_eflags)\
     } 

#define gen_func_body_bit(name ,type, id, cap_eflags) \
    fuku_asm_ret_type  fuku_asm_gen_name(_,name,_w) (fuku_assambler_ctx& ctx, const fuku_register& dst, const fuku_register& src) { \
        gencleanerdata\
        gen_pattern32_2em_rm_r_word(0x0F, 0x83 + 8*type, dst, src)\
        gen_func_return(id, cap_eflags)\
    } \
    fuku_asm_ret_type  fuku_asm_gen_name(_,name,_w) (fuku_assambler_ctx& ctx, const fuku_register& dst,const fuku_immediate& src) { \
        gencleanerdata\
        gen_pattern32_2em_rm_idx_immb_word(0x0F, 0xBA, dst, type, src)\
        gen_func_return(id, cap_eflags)\
    } \
    fuku_asm_ret_type  fuku_asm_gen_name(_,name,_w) (fuku_assambler_ctx& ctx, const fuku_operand& dst, const fuku_register& src) { \
        gencleanerdata\
        gen_pattern32_2em_op_r_word(0x0F, 0x83 + 8*type, dst, src)\
        gen_func_return(id, cap_eflags)\
    } \
    fuku_asm_ret_type  fuku_asm_gen_name(_,name,_w) (fuku_assambler_ctx& ctx, const fuku_operand& dst,const fuku_immediate& src) { \
        gencleanerdata\
        gen_pattern32_2em_op_idx_immb_word(0x0F, 0xBA, dst, type, src)\
        gen_func_return(id, cap_eflags)\
    } \
    fuku_asm_ret_type  fuku_asm_gen_name(_,name,_dw) (fuku_assambler_ctx& ctx, const fuku_register& dst, const fuku_register& src) { \
        gencleanerdata\
        gen_pattern32_2em_rm_r(0x0F, 0x83 + 8*type, dst, src)\
        gen_func_return(id, cap_eflags)\
    } \
    fuku_asm_ret_type  fuku_asm_gen_name(_,name,_dw) (fuku_assambler_ctx& ctx, const fuku_register& dst,const fuku_immediate& src) { \
        gencleanerdata\
        gen_pattern32_2em_rm_idx_immb(0x0F, 0xBA, dst, type, src)\
        gen_func_return(id, cap_eflags)\
    } \
    fuku_asm_ret_type  fuku_asm_gen_name(_,name,_dw) (fuku_assambler_ctx& ctx, const fuku_operand& dst, const fuku_register& src) { \
        gencleanerdata\
        gen_pattern32_2em_op_r(0x0F, 0x83 + 8*type, dst, src)\
        gen_func_return(id, cap_eflags)\
    } \
    fuku_asm_ret_type  fuku_asm_gen_name(_,name,_dw) (fuku_assambler_ctx& ctx, const fuku_operand& dst,const fuku_immediate& src) { \
        gencleanerdata\
        gen_pattern32_2em_op_idx_immb(0x0F, 0xBA, dst, type, src)\
        gen_func_return(id, cap_eflags)\
    } \
\
    fuku_asm_ret_type  fuku_asm_gen_name(_,name,_qw) (fuku_assambler_ctx& ctx, const fuku_register& dst, const fuku_register& src) { \
        gencleanerdata\
        gen_pattern64_2em_rm_r(0x0F, 0x83 + 8*type, dst, src)\
        gen_func_return(id, cap_eflags)\
    } \
    fuku_asm_ret_type  fuku_asm_gen_name(_,name,_qw) (fuku_assambler_ctx& ctx, const fuku_register& dst,const fuku_immediate& src) { \
        gencleanerdata\
        gen_pattern64_2em_rm_idx_immb(0x0F, 0xBA, dst, type, src)\
        gen_func_return(id, cap_eflags)\
    } \
    fuku_asm_ret_type  fuku_asm_gen_name(_,name,_qw) (fuku_assambler_ctx& ctx, const fuku_operand& dst, const fuku_register& src) { \
        gencleanerdata\
        gen_pattern64_2em_op_r(0x0F, 0x83 + 8*type, dst, src)\
        gen_func_return(id, cap_eflags)\
    } \
    fuku_asm_ret_type  fuku_asm_gen_name(_,name,_qw) (fuku_assambler_ctx& ctx, const fuku_operand& dst,const fuku_immediate& src) { \
        gencleanerdata\
        gen_pattern64_2em_op_idx_immb(0x0F, 0xBA, dst, type, src)\
        gen_func_return(id, cap_eflags)\
    } 
    

#define gen_func_body_bit_ex(name ,type, id, cap_eflags) \
    fuku_asm_ret_type  fuku_asm_gen_name(_,name,_w) (fuku_assambler_ctx& ctx, const fuku_register& dst, const fuku_register& src) { \
        gencleanerdata\
        gen_pattern32_2em_rm_r_word(0x0F, 0xBC + type, dst, src)\
        gen_func_return(id, cap_eflags)\
    } \
    fuku_asm_ret_type  fuku_asm_gen_name(_,name,_w) (fuku_assambler_ctx& ctx, const fuku_operand& dst, const fuku_register& src) { \
        gencleanerdata\
        gen_pattern32_2em_op_r_word(0x0F, 0xBC + type, dst, src)\
        gen_func_return(id, cap_eflags)\
    } \
\
    fuku_asm_ret_type  fuku_asm_gen_name(_,name,_dw) (fuku_assambler_ctx& ctx, const fuku_register& dst, const fuku_register& src) { \
        gencleanerdata\
        gen_pattern32_2em_rm_r(0x0F, 0xBC + type, dst, src)\
        gen_func_return(id, cap_eflags)\
    } \
    fuku_asm_ret_type  fuku_asm_gen_name(_,name,_dw) (fuku_assambler_ctx& ctx, const fuku_operand& dst, const fuku_register& src) { \
        gencleanerdata\
        gen_pattern32_2em_op_r(0x0F, 0xBC + type, dst, src)\
        gen_func_return(id, cap_eflags)\
    } \
\
    fuku_asm_ret_type  fuku_asm_gen_name(_,name,_qw) (fuku_assambler_ctx& ctx, const fuku_register& dst, const fuku_register& src) { \
        gencleanerdata\
        gen_pattern64_2em_rm_r(0x0F, 0xBC + type, dst, src)\
        gen_func_return(id, cap_eflags)\
    } \
    fuku_asm_ret_type  fuku_asm_gen_name(_,name,_qw) (fuku_assambler_ctx& ctx, const fuku_operand& dst, const fuku_register& src) { \
        gencleanerdata\
        gen_pattern64_2em_op_r(0x0F, 0xBC + type, dst, src)\
        gen_func_return(id, cap_eflags)\
    }

#define gen_func_body_string_inst(name ,type, idMASK, cap_eflags)\
    fuku_asm_ret_type  fuku_asm_gen_name(_,name,b) (fuku_assambler_ctx& ctx) { \
        gencleanerdata\
        emit_b(ctx, type*2);\
        gen_func_return(fuku_asm_gen_name(,idMASK,B), cap_eflags)\
    }\
    fuku_asm_ret_type  fuku_asm_gen_name(_,name,w) (fuku_assambler_ctx& ctx) { \
        gencleanerdata\
        emit_b(ctx,FUKU_PREFIX_OVERRIDE_DATA);\
        emit_b(ctx, type*2 + 1);\
        gen_func_return(fuku_asm_gen_name(,idMASK,W), cap_eflags)\
    }\
    fuku_asm_ret_type  fuku_asm_gen_name(_,name,d) (fuku_assambler_ctx& ctx) { \
        gencleanerdata\
        emit_b(ctx, type*2 + 1);\
        gen_func_return(fuku_asm_gen_name(,idMASK,D), cap_eflags)\
    }\
    fuku_asm_ret_type  fuku_asm_gen_name(_,name,q) (fuku_assambler_ctx& ctx) { \
        gencleanerdata\
        emit_rex_64(ctx);\
        emit_b(ctx, type*2 + 1);\
        gen_func_return(fuku_asm_gen_name(,idMASK,Q), cap_eflags)\
    }

#define gen_func_body_string_inst_withoutq(name ,type, idMASK, cap_eflags)\
    fuku_asm_ret_type  fuku_asm_gen_name(_,name,b) (fuku_assambler_ctx& ctx) { \
        gencleanerdata\
        emit_b(ctx, type*2);\
        gen_func_return(fuku_asm_gen_name(,idMASK,B), cap_eflags)\
    }\
    fuku_asm_ret_type  fuku_asm_gen_name(_,name,w) (fuku_assambler_ctx& ctx) { \
        gencleanerdata\
        emit_b(ctx, FUKU_PREFIX_OVERRIDE_DATA);\
        emit_b(ctx, type*2 + 1);\
        gen_func_return(fuku_asm_gen_name(,idMASK,W), cap_eflags)\
    }\
    fuku_asm_ret_type  fuku_asm_gen_name(_,name,d) (fuku_assambler_ctx& ctx) { \
        gencleanerdata\
        emit_b(ctx, type*2 + 1);\
        gen_func_return(fuku_asm_gen_name(,idMASK,D), cap_eflags)\
    }
    
#define gen_func_body_movxx(name ,type, id)\
    fuku_asm_ret_type  fuku_asm_gen_name(_,name,_byte_w) (fuku_assambler_ctx& ctx, const fuku_register& src, const fuku_register& dst) {\
        gencleanerdata\
        gen_pattern32_2em_rm_r_word(0x0F,type, dst, src);\
        gen_func_return(id, 0)\
    }\
    fuku_asm_ret_type fuku_asm_gen_name(_,name,_byte_w)(fuku_assambler_ctx& ctx, const fuku_register& src, const fuku_operand& dst) {\
        gencleanerdata\
        gen_pattern32_2em_op_r_word(0x0F,type, dst, src);\
        gen_func_return(id, 0)\
    }\
    fuku_asm_ret_type fuku_asm_gen_name(_,name,_byte_dw)(fuku_assambler_ctx& ctx, const fuku_register& src, const fuku_register& dst) {\
        gencleanerdata\
        gen_pattern32_2em_rm_r(0x0F,type, dst, src);\
        gen_func_return(id, 0)\
    }\
    fuku_asm_ret_type fuku_asm_gen_name(_,name,_byte_dw)(fuku_assambler_ctx& ctx, const fuku_register& src, const fuku_operand& dst) {\
        gencleanerdata\
        gen_pattern32_2em_op_r(0x0F,type, dst, src);\
        gen_func_return(id, 0)\
    }\
    fuku_asm_ret_type fuku_asm_gen_name(_,name,_byte_qw)(fuku_assambler_ctx& ctx, const fuku_register& src, const fuku_register& dst) {\
        gencleanerdata\
        gen_pattern64_2em_rm_r(0x0F,type, dst, src);\
        gen_func_return(id, 0)\
    }\
    fuku_asm_ret_type fuku_asm_gen_name(_,name,_byte_qw)(fuku_assambler_ctx& ctx, const fuku_register& src, const fuku_operand& dst) {\
        gencleanerdata\
        gen_pattern64_2em_op_r(0x0F,type, dst, src);\
        gen_func_return(id, 0)\
    }\
\
    fuku_asm_ret_type fuku_asm_gen_name(_,name,_word_dw)(fuku_assambler_ctx& ctx, const fuku_register& src, const fuku_register& dst) {\
        gencleanerdata\
        gen_pattern32_2em_rm_r(0x0F,type + 1, dst, src);\
        gen_func_return(id, 0)\
    }\
    fuku_asm_ret_type fuku_asm_gen_name(_,name,_word_dw)(fuku_assambler_ctx& ctx, const fuku_register& src, const fuku_operand& dst) {\
        gencleanerdata\
        gen_pattern32_2em_op_r(0x0F,type + 1, dst, src);\
        gen_func_return(id, 0)\
    }\
    fuku_asm_ret_type fuku_asm_gen_name(_,name,_word_qw)(fuku_assambler_ctx& ctx, const fuku_register& src, const fuku_register& dst) {\
        gencleanerdata\
        gen_pattern64_2em_rm_r(0x0F,type + 1, dst, src);\
        gen_func_return(id, 0)\
    }\
    fuku_asm_ret_type fuku_asm_gen_name(_,name,_word_qw)(fuku_assambler_ctx& ctx, const fuku_register& src, const fuku_operand& dst) {\
        gencleanerdata\
        gen_pattern64_2em_op_r(0x0F,type + 1, dst, src);\
        gen_func_return(id, 0)\
    }
    

#define gen_func_body_shxd(name ,type, id, cap_eflags)\
    fuku_asm_ret_type  fuku_asm_gen_name(_,name,_w) (fuku_assambler_ctx& ctx, const fuku_register& dst, const fuku_register& src, const fuku_immediate& imm) {\
        gencleanerdata\
        gen_pattern32_2em_rm_idx_immb_word(0x0F,0xA4 + 8*type, dst, src, imm);\
        gen_func_return(id, cap_eflags)\
    }\
    fuku_asm_ret_type  fuku_asm_gen_name(_,name,_w) (fuku_assambler_ctx& ctx, const fuku_operand& dst, const fuku_register& src, const fuku_immediate& imm) {\
        gencleanerdata\
        gen_pattern32_2em_op_idx_immb_word(0x0F,0xA4 + 8*type, dst, src, imm);\
        gen_func_return(id, cap_eflags)\
    }\
    fuku_asm_ret_type  fuku_asm_gen_name(_,name,_cl_w) (fuku_assambler_ctx& ctx, const fuku_register& dst, const fuku_register& src) {\
        gencleanerdata\
        gen_pattern32_2em_rm_idx_word(0x0F,0xA5 + 8*type, dst, src);\
        gen_func_return(id, cap_eflags)\
    }\
    fuku_asm_ret_type  fuku_asm_gen_name(_,name,_cl_w) (fuku_assambler_ctx& ctx, const fuku_operand& dst, const fuku_register& src) {\
        gencleanerdata\
        gen_pattern32_2em_op_idx_word(0x0F,0xA5 + 8*type, dst, src);\
        gen_func_return(id, cap_eflags)\
    }\
\
    fuku_asm_ret_type  fuku_asm_gen_name(_,name,_dw) (fuku_assambler_ctx& ctx, const fuku_register& dst, const fuku_register& src, const fuku_immediate& imm) {\
        gencleanerdata\
        gen_pattern32_2em_rm_idx_immb(0x0F,0xA4 + 8*type, dst, src, imm);\
        gen_func_return(id, cap_eflags)\
    }\
    fuku_asm_ret_type  fuku_asm_gen_name(_,name,_dw) (fuku_assambler_ctx& ctx, const fuku_operand& dst, const fuku_register& src, const fuku_immediate& imm) {\
        gencleanerdata\
        gen_pattern32_2em_op_idx_immb(0x0F,0xA4 + 8*type, dst, src, imm);\
        gen_func_return(id, cap_eflags)\
    }\
    fuku_asm_ret_type  fuku_asm_gen_name(_,name,_cl_dw) (fuku_assambler_ctx& ctx, const fuku_register& dst, const fuku_register& src) {\
        gencleanerdata\
        gen_pattern32_2em_rm_idx(0x0F,0xA5 + 8*type, dst, src);\
        gen_func_return(id, cap_eflags)\
    }\
    fuku_asm_ret_type  fuku_asm_gen_name(_,name,_cl_dw) (fuku_assambler_ctx& ctx, const fuku_operand& dst, const fuku_register& src) {\
        gencleanerdata\
        gen_pattern32_2em_op_idx(0x0F,0xA5 + 8*type, dst, src);\
        gen_func_return(id, cap_eflags)\
    }\
\
    fuku_asm_ret_type  fuku_asm_gen_name(_,name,_qw) (fuku_assambler_ctx& ctx, const fuku_register& dst, const fuku_register& src, const fuku_immediate& imm) {\
        gencleanerdata\
        gen_pattern64_2em_rm_idx_immb(0x0F,0xA4 + 8*type, dst, src, imm);\
        gen_func_return(id, cap_eflags)\
    }\
    fuku_asm_ret_type  fuku_asm_gen_name(_,name,_qw) (fuku_assambler_ctx& ctx, const fuku_operand& dst, const fuku_register& src, const fuku_immediate& imm) {\
        gencleanerdata\
        gen_pattern64_2em_op_idx_immb(0x0F,0xA4 + 8*type, dst, src, imm);\
        gen_func_return(id, cap_eflags)\
    }\
    fuku_asm_ret_type  fuku_asm_gen_name(_,name,_cl_qw) (fuku_assambler_ctx& ctx, const fuku_register& dst, const fuku_register& src) {\
        gencleanerdata\
        gen_pattern64_2em_rm_idx(0x0F,0xA5 + 8*type, dst, src);\
        gen_func_return(id, cap_eflags)\
    }\
    fuku_asm_ret_type  fuku_asm_gen_name(_,name,_cl_qw) (fuku_assambler_ctx& ctx, const fuku_operand& dst, const fuku_register& src) {\
        gencleanerdata\
        gen_pattern64_2em_op_idx(0x0F,0xA5 + 8*type, dst, src);\
        gen_func_return(id, cap_eflags)\
    }