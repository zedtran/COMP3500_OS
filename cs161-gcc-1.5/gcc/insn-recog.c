/* Generated automatically by the program `genrecog' from the target
   machine description file.  */

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tm.h"
#include "rtl.h"
#include "tm_p.h"
#include "function.h"
#include "insn-config.h"
#include "recog.h"
#include "real.h"
#include "output.h"
#include "flags.h"
#include "hard-reg-set.h"
#include "resource.h"
#include "toplev.h"
#include "reload.h"



/* `recog' contains a decision tree that recognizes whether the rtx
   X0 is a valid instruction.

   recog returns -1 if the rtx is not valid.  If the rtx is valid, recog
   returns a nonnegative number which is the insn code number for the
   pattern that matched.  This is the same as the order in the machine
   description of the entry that matched.  This number can be used as an
   index into `insn_data' and other tables.

   The third argument to recog is an optional pointer to an int.  If
   present, recog will accept a pattern if it matches except for missing
   CLOBBER expressions at the end.  In that case, the value pointed to by
   the optional pointer will be set to the number of CLOBBERs that need
   to be added (it should be initialized to zero by the caller).  If it
   is set nonzero, the caller should allocate a PARALLEL of the
   appropriate size, copy the initial entries, and call add_clobbers
   (found in insn-emit.c) to fill in the CLOBBERs.


   The function split_insns returns 0 if the rtl could not
   be split or the split rtl as an INSN list if it can be.

   The function peephole2_insns returns 0 if the rtl could not
   be matched. If there was a match, the new rtl is returned in an INSN list,
   and LAST_INSN will point to the last recognized insn in the old sequence.
*/


extern rtx gen_split_503 (rtx, rtx *);
extern rtx gen_split_504 (rtx, rtx *);
extern rtx gen_split_505 (rtx, rtx *);
extern rtx gen_split_506 (rtx, rtx *);
extern rtx gen_split_507 (rtx, rtx *);
extern rtx gen_peephole2_512 (rtx, rtx *);
extern rtx gen_peephole2_513 (rtx, rtx *);
extern rtx gen_split_514 (rtx, rtx *);
extern rtx gen_split_515 (rtx, rtx *);
extern rtx gen_split_516 (rtx, rtx *);
extern rtx gen_peephole2_517 (rtx, rtx *);
extern rtx gen_peephole2_518 (rtx, rtx *);
extern rtx gen_peephole2_519 (rtx, rtx *);
extern rtx gen_split_520 (rtx, rtx *);
extern rtx gen_split_521 (rtx, rtx *);
extern rtx gen_split_524 (rtx, rtx *);
extern rtx gen_split_525 (rtx, rtx *);
extern rtx gen_split_537 (rtx, rtx *);
extern rtx gen_split_538 (rtx, rtx *);
extern rtx gen_split_539 (rtx, rtx *);
extern rtx gen_split_545 (rtx, rtx *);
extern rtx gen_split_550 (rtx, rtx *);
extern rtx gen_split_551 (rtx, rtx *);
extern rtx gen_split_552 (rtx, rtx *);
extern rtx gen_split_553 (rtx, rtx *);
extern rtx gen_split_554 (rtx, rtx *);
extern rtx gen_split_564 (rtx, rtx *);
extern rtx gen_peephole2_565 (rtx, rtx *);
extern rtx gen_split_566 (rtx, rtx *);
extern rtx gen_split_567 (rtx, rtx *);
extern rtx gen_split_568 (rtx, rtx *);
extern rtx gen_split_569 (rtx, rtx *);
extern rtx gen_split_570 (rtx, rtx *);
extern rtx gen_split_571 (rtx, rtx *);
extern rtx gen_split_572 (rtx, rtx *);
extern rtx gen_split_573 (rtx, rtx *);
extern rtx gen_split_574 (rtx, rtx *);
extern rtx gen_split_576 (rtx, rtx *);
extern rtx gen_split_578 (rtx, rtx *);
extern rtx gen_split_579 (rtx, rtx *);
extern rtx gen_split_583 (rtx, rtx *);
extern rtx gen_split_585 (rtx, rtx *);
extern rtx gen_split_588 (rtx, rtx *);
extern rtx gen_split_589 (rtx, rtx *);
extern rtx gen_split_590 (rtx, rtx *);
extern rtx gen_split_594 (rtx, rtx *);
extern rtx gen_split_602 (rtx, rtx *);
extern rtx gen_split_603 (rtx, rtx *);
extern rtx gen_split_604 (rtx, rtx *);
extern rtx gen_split_605 (rtx, rtx *);
extern rtx gen_split_606 (rtx, rtx *);
extern rtx gen_split_607 (rtx, rtx *);
extern rtx gen_split_608 (rtx, rtx *);
extern rtx gen_split_649 (rtx, rtx *);
extern rtx gen_split_650 (rtx, rtx *);
extern rtx gen_split_654 (rtx, rtx *);
extern rtx gen_split_656 (rtx, rtx *);
extern rtx gen_split_657 (rtx, rtx *);
extern rtx gen_split_663 (rtx, rtx *);
extern rtx gen_split_670 (rtx, rtx *);
extern rtx gen_split_671 (rtx, rtx *);



static int
recog_1 (rtx x0 ATTRIBUTE_UNUSED,
	rtx insn ATTRIBUTE_UNUSED,
	int *pnum_clobbers ATTRIBUTE_UNUSED)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x1 ATTRIBUTE_UNUSED;
  rtx x2 ATTRIBUTE_UNUSED;
  rtx x3 ATTRIBUTE_UNUSED;
  rtx x4 ATTRIBUTE_UNUSED;
  rtx x5 ATTRIBUTE_UNUSED;
  rtx x6 ATTRIBUTE_UNUSED;
  rtx x7 ATTRIBUTE_UNUSED;
  int tem ATTRIBUTE_UNUSED;

  x1 = XEXP (x0, 1);
  switch (GET_CODE (x1))
    {
    case PLUS:
      goto L16;
    case MINUS:
      goto L96;
    case MULT:
      goto L132;
    case NEG:
      goto L916;
    case DIV:
      goto L1021;
    case SQRT:
      goto L1101;
    case ABS:
      goto L1158;
    case FLOAT_TRUNCATE:
      goto L1304;
    case FLOAT:
      goto L1572;
    case MEM:
      goto L1786;
    case IF_THEN_ELSE:
      goto L2809;
    case VEC_SELECT:
      goto L2943;
    case UNSPEC:
      goto L4500;
    default:
     break;
   }
  goto ret0;

 L16: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SFmode)
    goto L4505;
  goto ret0;

 L4505: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == MULT)
    goto L869;
  if (register_operand (x2, SFmode))
    {
      operands[1] = x2;
      goto L17;
    }
  goto ret0;

 L869: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SFmode))
    {
      operands[1] = x3;
      goto L870;
    }
  goto ret0;

 L870: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, SFmode))
    {
      operands[2] = x3;
      goto L871;
    }
  goto ret0;

 L871: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, SFmode))
    {
      operands[3] = x2;
      goto L872;
    }
  goto ret0;

 L872: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 1742 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_FP4 && TARGET_FUSED_MADD) && 
#line 418 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT)))
    {
      return 64;  /* *maddsf */
    }
  goto ret0;

 L17: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, SFmode))
    {
      operands[2] = x2;
      goto L18;
    }
  goto ret0;

 L18: ATTRIBUTE_UNUSED_LABEL
  if (
#line 418 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT))
    {
      return 3;  /* addsf3 */
    }
  goto ret0;

 L96: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SFmode)
    goto L4507;
  goto ret0;

 L4507: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == MULT)
    goto L893;
  if (register_operand (x2, SFmode))
    {
      operands[1] = x2;
      goto L97;
    }
  goto ret0;

 L893: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SFmode)
    goto L4509;
  goto ret0;

 L4509: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x3) == NEG)
    goto L945;
  if (register_operand (x3, SFmode))
    {
      operands[1] = x3;
      goto L894;
    }
  goto ret0;

 L945: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, SFmode))
    {
      operands[1] = x4;
      goto L946;
    }
  goto ret0;

 L946: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, SFmode))
    {
      operands[2] = x3;
      goto L947;
    }
  goto ret0;

 L947: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, SFmode))
    {
      operands[3] = x2;
      goto L948;
    }
  goto ret0;

 L948: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 1775 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_NMADD_NMSUB && TARGET_FUSED_MADD
   && !HONOR_SIGNED_ZEROS (SFmode)) && 
#line 418 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT)))
    {
      return 73;  /* *nmaddsf_fastmath */
    }
  goto ret0;

 L894: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, SFmode))
    {
      operands[2] = x3;
      goto L895;
    }
  goto ret0;

 L895: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, SFmode))
    {
      operands[3] = x2;
      goto L896;
    }
  goto ret0;

 L896: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 1752 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_FP4 && TARGET_FUSED_MADD) && 
#line 418 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT)))
    {
      return 67;  /* *msubsf */
    }
  goto ret0;

 L97: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SFmode)
    goto L4511;
  goto ret0;

 L4511: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == MULT)
    goto L999;
  if (register_operand (x2, SFmode))
    {
      operands[2] = x2;
      goto L98;
    }
  goto ret0;

 L999: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SFmode))
    {
      operands[2] = x3;
      goto L1000;
    }
  goto ret0;

 L1000: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, SFmode))
    {
      operands[3] = x3;
      goto L1001;
    }
  goto ret0;

 L1001: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 1799 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_NMADD_NMSUB && TARGET_FUSED_MADD
   && !HONOR_SIGNED_ZEROS (SFmode)) && 
#line 418 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT)))
    {
      return 79;  /* *nmsubsf_fastmath */
    }
  goto ret0;

 L98: ATTRIBUTE_UNUSED_LABEL
  if (
#line 418 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT))
    {
      return 16;  /* subsf3 */
    }
  goto ret0;

 L132: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SFmode))
    {
      operands[1] = x2;
      goto L133;
    }
  goto ret0;

 L133: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, SFmode))
    {
      operands[2] = x2;
      goto L134;
    }
  goto ret0;

 L134: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 932 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_4300_MUL_FIX) && 
#line 423 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT)))
    {
      return 22;  /* *mulsf3 */
    }
 L146: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 945 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_4300_MUL_FIX) && 
#line 423 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT)))
    {
      return 24;  /* *mulsf3_r4300 */
    }
  goto ret0;

 L916: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SFmode)
    goto L4512;
  goto ret0;

 L4512: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case PLUS:
      goto L917;
    case MINUS:
      goto L971;
    case REG:
    case SUBREG:
      goto L4514;
    default:
      goto ret0;
   }
 L4514: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SFmode))
    {
      operands[1] = x2;
      goto L1193;
    }
  goto ret0;

 L917: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SFmode
      && GET_CODE (x3) == MULT)
    goto L918;
  goto ret0;

 L918: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, SFmode))
    {
      operands[1] = x4;
      goto L919;
    }
  goto ret0;

 L919: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (register_operand (x4, SFmode))
    {
      operands[2] = x4;
      goto L920;
    }
  goto ret0;

 L920: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, SFmode))
    {
      operands[3] = x3;
      goto L921;
    }
  goto ret0;

 L921: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 1763 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_NMADD_NMSUB && TARGET_FUSED_MADD
   && HONOR_SIGNED_ZEROS (SFmode)) && 
#line 418 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT)))
    {
      return 70;  /* *nmaddsf */
    }
  goto ret0;

 L971: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SFmode
      && GET_CODE (x3) == MULT)
    goto L972;
  goto ret0;

 L972: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, SFmode))
    {
      operands[2] = x4;
      goto L973;
    }
  goto ret0;

 L973: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (register_operand (x4, SFmode))
    {
      operands[3] = x4;
      goto L974;
    }
  goto ret0;

 L974: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, SFmode))
    {
      operands[1] = x3;
      goto L975;
    }
  goto ret0;

 L975: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 1787 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_NMADD_NMSUB && TARGET_FUSED_MADD
   && HONOR_SIGNED_ZEROS (SFmode)) && 
#line 418 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT)))
    {
      return 76;  /* *nmsubsf */
    }
  goto ret0;

 L1193: ATTRIBUTE_UNUSED_LABEL
  if (
#line 418 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT))
    {
      return 108;  /* negsf2 */
    }
  goto ret0;

 L1021: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SFmode))
    {
      operands[1] = x2;
      goto L1022;
    }
  if (const_1_operand (x2, SFmode))
    {
      operands[1] = x2;
      goto L1040;
    }
  goto ret0;

 L1022: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, SFmode))
    {
      operands[2] = x2;
      goto L1023;
    }
  goto ret0;

 L1023: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 1840 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_FIX_SB1 || flag_unsafe_math_optimizations) && 
#line 418 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT)))
    {
      return 82;  /* *divsf3 */
    }
  goto ret0;

 L1040: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SFmode)
    goto L4516;
  goto ret0;

 L4516: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == SQRT)
    goto L1118;
  if (register_operand (x2, SFmode))
    {
      operands[2] = x2;
      goto L1041;
    }
  goto ret0;

 L1118: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SFmode))
    {
      operands[2] = x3;
      goto L1119;
    }
  goto ret0;

 L1119: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 1929 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_FP4 && flag_unsafe_math_optimizations) && 
#line 418 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT)))
    {
      return 95;  /* *rsqrtsfa */
    }
  goto ret0;

 L1041: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 1858 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_FP4 && flag_unsafe_math_optimizations) && 
#line 418 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT)))
    {
      return 85;  /* *recipsf3 */
    }
  goto ret0;

 L1101: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SFmode)
    goto L4518;
  goto ret0;

 L4518: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == DIV)
    goto L1138;
  if (register_operand (x2, SFmode))
    {
      operands[1] = x2;
      goto L1102;
    }
  goto ret0;

 L1138: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (const_1_operand (x3, SFmode))
    {
      operands[1] = x3;
      goto L1139;
    }
  goto ret0;

 L1139: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, SFmode))
    {
      operands[2] = x3;
      goto L1140;
    }
  goto ret0;

 L1140: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 1947 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_FP4 && flag_unsafe_math_optimizations) && 
#line 418 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT)))
    {
      return 98;  /* *rsqrtsfb */
    }
  goto ret0;

 L1102: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 1911 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!ISA_MIPS1) && 
#line 418 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT)))
    {
      return 92;  /* sqrtsf2 */
    }
  goto ret0;

 L1158: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SFmode))
    {
      operands[1] = x2;
      goto L1159;
    }
  goto ret0;

 L1159: ATTRIBUTE_UNUSED_LABEL
  if (
#line 418 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT))
    {
      return 101;  /* abssf2 */
    }
  goto ret0;

 L1304: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DFmode))
    {
      operands[1] = x2;
      goto L1305;
    }
  goto ret0;

 L1305: ATTRIBUTE_UNUSED_LABEL
  if (
#line 2172 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT))
    {
      return 127;  /* truncdfsf2 */
    }
  goto ret0;

 L1572: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L4519;
    case DImode:
      goto L4520;
    default:
      break;
    }
  goto ret0;

 L4519: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L1573;
    }
  goto ret0;

 L1573: ATTRIBUTE_UNUSED_LABEL
  if (
#line 2643 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT))
    {
      return 176;  /* floatsisf2 */
    }
  goto ret0;

 L4520: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L1578;
    }
  goto ret0;

 L1578: ATTRIBUTE_UNUSED_LABEL
  if (
#line 2654 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_FLOAT64 && TARGET_DOUBLE_FLOAT))
    {
      return 177;  /* floatdisf2 */
    }
  goto ret0;

 L1786: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L4521;
    case DImode:
      goto L4522;
    default:
      break;
    }
  goto ret0;

 L4521: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == PLUS)
    goto L1787;
  goto ret0;

 L1787: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L1788;
    }
  goto ret0;

 L1788: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L1789;
    }
  goto ret0;

 L1789: ATTRIBUTE_UNUSED_LABEL
  if (((
#line 3478 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_FP4) && 
#line 406 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(Pmode == SImode)) && 
#line 418 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT)))
    {
      return 215;  /* *lwxc1_si */
    }
  goto ret0;

 L4522: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == PLUS)
    goto L1808;
  goto ret0;

 L1808: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L1809;
    }
  goto ret0;

 L1809: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L1810;
    }
  goto ret0;

 L1810: ATTRIBUTE_UNUSED_LABEL
  if (((
#line 3478 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_FP4) && 
#line 406 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(Pmode == DImode)) && 
#line 418 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT)))
    {
      return 218;  /* *lwxc1_di */
    }
  goto ret0;

 L2809: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L4523;
    case DImode:
      goto L4524;
    case CCmode:
      goto L4525;
    default:
      break;
    }
  goto ret0;

 L4523: ATTRIBUTE_UNUSED_LABEL
  if (equality_operator (x2, SImode))
    {
      operands[4] = x2;
      goto L2810;
    }
  goto ret0;

 L2810: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L2811;
    }
  goto ret0;

 L2811: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L2812;
  goto ret0;

 L2812: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, SFmode))
    {
      operands[2] = x2;
      goto L2813;
    }
  goto ret0;

 L2813: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (register_operand (x2, SFmode))
    {
      operands[3] = x2;
      goto L2814;
    }
  goto ret0;

 L2814: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 5324 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_CONDMOVE) && 
#line 423 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT)))
    {
      return 369;  /* *movsf_on_si */
    }
  goto ret0;

 L4524: ATTRIBUTE_UNUSED_LABEL
  if (equality_operator (x2, DImode))
    {
      operands[4] = x2;
      goto L2828;
    }
  goto ret0;

 L2828: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L2829;
    }
  goto ret0;

 L2829: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L2830;
  goto ret0;

 L2830: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, SFmode))
    {
      operands[2] = x2;
      goto L2831;
    }
  goto ret0;

 L2831: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (register_operand (x2, SFmode))
    {
      operands[3] = x2;
      goto L2832;
    }
  goto ret0;

 L2832: ATTRIBUTE_UNUSED_LABEL
  if (((
#line 5324 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_CONDMOVE) && 
#line 410 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT)) && 
#line 423 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT)))
    {
      return 371;  /* *movsf_on_di */
    }
  goto ret0;

 L4525: ATTRIBUTE_UNUSED_LABEL
  if (equality_operator (x2, CCmode))
    {
      operands[4] = x2;
      goto L2846;
    }
  goto ret0;

 L2846: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, CCmode))
    {
      operands[1] = x3;
      goto L2847;
    }
  goto ret0;

 L2847: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L2848;
  goto ret0;

 L2848: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, SFmode))
    {
      operands[2] = x2;
      goto L2849;
    }
  goto ret0;

 L2849: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (register_operand (x2, SFmode))
    {
      operands[3] = x2;
      goto L2850;
    }
  goto ret0;

 L2850: ATTRIBUTE_UNUSED_LABEL
  if (((
#line 5324 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_CONDMOVE) && 
#line 410 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT)) && 
#line 423 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT)))
    {
      return 373;  /* *movsf_on_cc */
    }
  goto ret0;

 L2943: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V2SFmode))
    {
      operands[1] = x2;
      goto L2944;
    }
  goto ret0;

 L2944: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == PARALLEL
      && XVECLEN (x2, 0) == 1)
    goto L2945;
  goto ret0;

 L2945: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (const_0_or_1_operand (x3, VOIDmode))
    {
      operands[2] = x3;
      goto L2946;
    }
  goto ret0;

 L2946: ATTRIBUTE_UNUSED_LABEL
  if (
#line 161 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-ps-3d.md"
(TARGET_PAIRED_SINGLE_FLOAT))
    {
      return 386;  /* vec_extractv2sf */
    }
  goto ret0;

 L4500: ATTRIBUTE_UNUSED_LABEL
  switch (XVECLEN (x1, 0))
    {
    case 1:
      goto L4526;
    case 2:
      goto L4527;
    default:
      break;
    }
  goto ret0;

 L4526: ATTRIBUTE_UNUSED_LABEL
  switch (XINT (x1, 1))
    {
    case 208L:
      goto L3061;
    case 210L:
      goto L3094;
    default:
      break;
    }
  goto ret0;

 L3061: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, SFmode))
    {
      operands[1] = x2;
      goto L3062;
    }
  goto ret0;

 L3062: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 445 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-ps-3d.md"
(TARGET_MIPS3D) && 
#line 418 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT)))
    {
      return 402;  /* mips_rsqrt1_s */
    }
  goto ret0;

 L3094: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, SFmode))
    {
      operands[1] = x2;
      goto L3095;
    }
  goto ret0;

 L3095: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 464 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-ps-3d.md"
(TARGET_MIPS3D) && 
#line 418 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT)))
    {
      return 408;  /* mips_recip1_s */
    }
  goto ret0;

 L4527: ATTRIBUTE_UNUSED_LABEL
  switch (XINT (x1, 1))
    {
    case 209L:
      goto L3076;
    case 211L:
      goto L3109;
    default:
      break;
    }
  goto ret0;

 L3076: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, SFmode))
    {
      operands[1] = x2;
      goto L3077;
    }
  goto ret0;

 L3077: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, SFmode))
    {
      operands[2] = x2;
      goto L3078;
    }
  goto ret0;

 L3078: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 455 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-ps-3d.md"
(TARGET_MIPS3D) && 
#line 418 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT)))
    {
      return 405;  /* mips_rsqrt2_s */
    }
  goto ret0;

 L3109: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, SFmode))
    {
      operands[1] = x2;
      goto L3110;
    }
  goto ret0;

 L3110: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, SFmode))
    {
      operands[2] = x2;
      goto L3111;
    }
  goto ret0;

 L3111: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 474 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-ps-3d.md"
(TARGET_MIPS3D) && 
#line 418 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT)))
    {
      return 411;  /* mips_recip2_s */
    }
  goto ret0;
 ret0:
  return -1;
}

static int
recog_2 (rtx x0 ATTRIBUTE_UNUSED,
	rtx insn ATTRIBUTE_UNUSED,
	int *pnum_clobbers ATTRIBUTE_UNUSED)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x1 ATTRIBUTE_UNUSED;
  rtx x2 ATTRIBUTE_UNUSED;
  rtx x3 ATTRIBUTE_UNUSED;
  rtx x4 ATTRIBUTE_UNUSED;
  rtx x5 ATTRIBUTE_UNUSED;
  rtx x6 ATTRIBUTE_UNUSED;
  rtx x7 ATTRIBUTE_UNUSED;
  int tem ATTRIBUTE_UNUSED;

  x1 = XEXP (x0, 1);
  switch (GET_CODE (x1))
    {
    case PLUS:
      goto L22;
    case MINUS:
      goto L102;
    case MULT:
      goto L138;
    case NEG:
      goto L925;
    case DIV:
      goto L1027;
    case SQRT:
      goto L1106;
    case ABS:
      goto L1163;
    case FLOAT_EXTEND:
      goto L1511;
    case FLOAT:
      goto L1562;
    case MEM:
      goto L1793;
    case UNSPEC:
      goto L4549;
    case IF_THEN_ELSE:
      goto L2818;
    default:
     break;
   }
  goto ret0;

 L22: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == DFmode)
    goto L4556;
  goto ret0;

 L4556: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == MULT)
    goto L877;
  if (register_operand (x2, DFmode))
    {
      operands[1] = x2;
      goto L23;
    }
  goto ret0;

 L877: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DFmode))
    {
      operands[1] = x3;
      goto L878;
    }
  goto ret0;

 L878: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, DFmode))
    {
      operands[2] = x3;
      goto L879;
    }
  goto ret0;

 L879: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, DFmode))
    {
      operands[3] = x2;
      goto L880;
    }
  goto ret0;

 L880: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 1742 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_FP4 && TARGET_FUSED_MADD) && 
#line 419 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT)))
    {
      return 65;  /* *madddf */
    }
  goto ret0;

 L23: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, DFmode))
    {
      operands[2] = x2;
      goto L24;
    }
  goto ret0;

 L24: ATTRIBUTE_UNUSED_LABEL
  if (
#line 419 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT))
    {
      return 4;  /* adddf3 */
    }
  goto ret0;

 L102: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == DFmode)
    goto L4558;
  goto ret0;

 L4558: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == MULT)
    goto L901;
  if (register_operand (x2, DFmode))
    {
      operands[1] = x2;
      goto L103;
    }
  goto ret0;

 L901: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DFmode)
    goto L4560;
  goto ret0;

 L4560: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x3) == NEG)
    goto L954;
  if (register_operand (x3, DFmode))
    {
      operands[1] = x3;
      goto L902;
    }
  goto ret0;

 L954: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, DFmode))
    {
      operands[1] = x4;
      goto L955;
    }
  goto ret0;

 L955: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, DFmode))
    {
      operands[2] = x3;
      goto L956;
    }
  goto ret0;

 L956: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, DFmode))
    {
      operands[3] = x2;
      goto L957;
    }
  goto ret0;

 L957: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 1775 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_NMADD_NMSUB && TARGET_FUSED_MADD
   && !HONOR_SIGNED_ZEROS (DFmode)) && 
#line 419 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT)))
    {
      return 74;  /* *nmadddf_fastmath */
    }
  goto ret0;

 L902: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, DFmode))
    {
      operands[2] = x3;
      goto L903;
    }
  goto ret0;

 L903: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, DFmode))
    {
      operands[3] = x2;
      goto L904;
    }
  goto ret0;

 L904: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 1752 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_FP4 && TARGET_FUSED_MADD) && 
#line 419 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT)))
    {
      return 68;  /* *msubdf */
    }
  goto ret0;

 L103: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DFmode)
    goto L4562;
  goto ret0;

 L4562: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == MULT)
    goto L1007;
  if (register_operand (x2, DFmode))
    {
      operands[2] = x2;
      goto L104;
    }
  goto ret0;

 L1007: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DFmode))
    {
      operands[2] = x3;
      goto L1008;
    }
  goto ret0;

 L1008: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, DFmode))
    {
      operands[3] = x3;
      goto L1009;
    }
  goto ret0;

 L1009: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 1799 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_NMADD_NMSUB && TARGET_FUSED_MADD
   && !HONOR_SIGNED_ZEROS (DFmode)) && 
#line 419 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT)))
    {
      return 80;  /* *nmsubdf_fastmath */
    }
  goto ret0;

 L104: ATTRIBUTE_UNUSED_LABEL
  if (
#line 419 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT))
    {
      return 17;  /* subdf3 */
    }
  goto ret0;

 L138: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DFmode))
    {
      operands[1] = x2;
      goto L139;
    }
  goto ret0;

 L139: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, DFmode))
    {
      operands[2] = x2;
      goto L140;
    }
  goto ret0;

 L140: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 932 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_4300_MUL_FIX) && 
#line 424 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT)))
    {
      return 23;  /* *muldf3 */
    }
 L152: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 945 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_4300_MUL_FIX) && 
#line 424 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT)))
    {
      return 25;  /* *muldf3_r4300 */
    }
  goto ret0;

 L925: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == DFmode)
    goto L4563;
  goto ret0;

 L4563: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case PLUS:
      goto L926;
    case MINUS:
      goto L980;
    case REG:
    case SUBREG:
      goto L4565;
    default:
      goto ret0;
   }
 L4565: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DFmode))
    {
      operands[1] = x2;
      goto L1198;
    }
  goto ret0;

 L926: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DFmode
      && GET_CODE (x3) == MULT)
    goto L927;
  goto ret0;

 L927: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, DFmode))
    {
      operands[1] = x4;
      goto L928;
    }
  goto ret0;

 L928: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (register_operand (x4, DFmode))
    {
      operands[2] = x4;
      goto L929;
    }
  goto ret0;

 L929: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, DFmode))
    {
      operands[3] = x3;
      goto L930;
    }
  goto ret0;

 L930: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 1763 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_NMADD_NMSUB && TARGET_FUSED_MADD
   && HONOR_SIGNED_ZEROS (DFmode)) && 
#line 419 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT)))
    {
      return 71;  /* *nmadddf */
    }
  goto ret0;

 L980: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DFmode
      && GET_CODE (x3) == MULT)
    goto L981;
  goto ret0;

 L981: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, DFmode))
    {
      operands[2] = x4;
      goto L982;
    }
  goto ret0;

 L982: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (register_operand (x4, DFmode))
    {
      operands[3] = x4;
      goto L983;
    }
  goto ret0;

 L983: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, DFmode))
    {
      operands[1] = x3;
      goto L984;
    }
  goto ret0;

 L984: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 1787 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_NMADD_NMSUB && TARGET_FUSED_MADD
   && HONOR_SIGNED_ZEROS (DFmode)) && 
#line 419 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT)))
    {
      return 77;  /* *nmsubdf */
    }
  goto ret0;

 L1198: ATTRIBUTE_UNUSED_LABEL
  if (
#line 419 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT))
    {
      return 109;  /* negdf2 */
    }
  goto ret0;

 L1027: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DFmode))
    {
      operands[1] = x2;
      goto L1028;
    }
  if (const_1_operand (x2, DFmode))
    {
      operands[1] = x2;
      goto L1046;
    }
  goto ret0;

 L1028: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, DFmode))
    {
      operands[2] = x2;
      goto L1029;
    }
  goto ret0;

 L1029: ATTRIBUTE_UNUSED_LABEL
  if (
#line 419 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT))
    {
      return 83;  /* *divdf3 */
    }
  goto ret0;

 L1046: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DFmode)
    goto L4567;
  goto ret0;

 L4567: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == SQRT)
    goto L1125;
  if (register_operand (x2, DFmode))
    {
      operands[2] = x2;
      goto L1047;
    }
  goto ret0;

 L1125: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DFmode))
    {
      operands[2] = x3;
      goto L1126;
    }
  goto ret0;

 L1126: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 1929 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_FP4 && flag_unsafe_math_optimizations) && 
#line 419 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT)))
    {
      return 96;  /* *rsqrtdfa */
    }
  goto ret0;

 L1047: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 1858 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_FP4 && flag_unsafe_math_optimizations) && 
#line 419 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT)))
    {
      return 86;  /* *recipdf3 */
    }
  goto ret0;

 L1106: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == DFmode)
    goto L4569;
  goto ret0;

 L4569: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == DIV)
    goto L1145;
  if (register_operand (x2, DFmode))
    {
      operands[1] = x2;
      goto L1107;
    }
  goto ret0;

 L1145: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (const_1_operand (x3, DFmode))
    {
      operands[1] = x3;
      goto L1146;
    }
  goto ret0;

 L1146: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, DFmode))
    {
      operands[2] = x3;
      goto L1147;
    }
  goto ret0;

 L1147: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 1947 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_FP4 && flag_unsafe_math_optimizations) && 
#line 419 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT)))
    {
      return 99;  /* *rsqrtdfb */
    }
  goto ret0;

 L1107: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 1911 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!ISA_MIPS1) && 
#line 419 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT)))
    {
      return 93;  /* sqrtdf2 */
    }
  goto ret0;

 L1163: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DFmode))
    {
      operands[1] = x2;
      goto L1164;
    }
  goto ret0;

 L1164: ATTRIBUTE_UNUSED_LABEL
  if (
#line 419 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT))
    {
      return 102;  /* absdf2 */
    }
  goto ret0;

 L1511: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SFmode))
    {
      operands[1] = x2;
      goto L1512;
    }
  goto ret0;

 L1512: ATTRIBUTE_UNUSED_LABEL
  if (
#line 2506 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT))
    {
      return 167;  /* extendsfdf2 */
    }
  goto ret0;

 L1562: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L4570;
    case DImode:
      goto L4571;
    default:
      break;
    }
  goto ret0;

 L4570: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L1563;
    }
  goto ret0;

 L1563: ATTRIBUTE_UNUSED_LABEL
  if (
#line 2621 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT))
    {
      return 174;  /* floatsidf2 */
    }
  goto ret0;

 L4571: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L1568;
    }
  goto ret0;

 L1568: ATTRIBUTE_UNUSED_LABEL
  if (
#line 2632 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_FLOAT64 && TARGET_DOUBLE_FLOAT))
    {
      return 175;  /* floatdidf2 */
    }
  goto ret0;

 L1793: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L4572;
    case DImode:
      goto L4573;
    default:
      break;
    }
  goto ret0;

 L4572: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == PLUS)
    goto L1794;
  goto ret0;

 L1794: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L1795;
    }
  goto ret0;

 L1795: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L1796;
    }
  goto ret0;

 L1796: ATTRIBUTE_UNUSED_LABEL
  if (((
#line 3478 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_FP4) && 
#line 406 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(Pmode == SImode)) && 
#line 419 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT)))
    {
      return 216;  /* *ldxc1_si */
    }
  goto ret0;

 L4573: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == PLUS)
    goto L1815;
  goto ret0;

 L1815: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L1816;
    }
  goto ret0;

 L1816: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L1817;
    }
  goto ret0;

 L1817: ATTRIBUTE_UNUSED_LABEL
  if (((
#line 3478 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_FP4) && 
#line 406 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(Pmode == DImode)) && 
#line 419 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT)))
    {
      return 219;  /* *ldxc1_di */
    }
  goto ret0;

 L4549: ATTRIBUTE_UNUSED_LABEL
  switch (XVECLEN (x1, 0))
    {
    case 1:
      goto L4574;
    case 2:
      goto L4575;
    default:
      break;
    }
  goto ret0;

 L4574: ATTRIBUTE_UNUSED_LABEL
  switch (XINT (x1, 1))
    {
    case 0L:
      goto L1942;
    case 208L:
      goto L3066;
    case 210L:
      goto L3099;
    default:
      break;
    }
  goto ret0;

 L1942: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (general_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L1943;
    }
  goto ret0;

 L1943: ATTRIBUTE_UNUSED_LABEL
  if (
#line 3893 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT && !TARGET_64BIT))
    {
      return 243;  /* load_df_low */
    }
  goto ret0;

 L3066: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, DFmode))
    {
      operands[1] = x2;
      goto L3067;
    }
  goto ret0;

 L3067: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 445 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-ps-3d.md"
(TARGET_MIPS3D) && 
#line 419 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT)))
    {
      return 403;  /* mips_rsqrt1_d */
    }
  goto ret0;

 L3099: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, DFmode))
    {
      operands[1] = x2;
      goto L3100;
    }
  goto ret0;

 L3100: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 464 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-ps-3d.md"
(TARGET_MIPS3D) && 
#line 419 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT)))
    {
      return 409;  /* mips_recip1_d */
    }
  goto ret0;

 L4575: ATTRIBUTE_UNUSED_LABEL
  switch (XINT (x1, 1))
    {
    case 1L:
      goto L1947;
    case 209L:
      goto L3082;
    case 211L:
      goto L3115;
    default:
      break;
    }
  goto ret0;

 L1947: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (general_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L1948;
    }
  goto ret0;

 L1948: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, DFmode))
    {
      operands[2] = x2;
      goto L1949;
    }
  goto ret0;

 L1949: ATTRIBUTE_UNUSED_LABEL
  if (
#line 3908 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT && !TARGET_64BIT))
    {
      return 244;  /* load_df_high */
    }
  goto ret0;

 L3082: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, DFmode))
    {
      operands[1] = x2;
      goto L3083;
    }
  goto ret0;

 L3083: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, DFmode))
    {
      operands[2] = x2;
      goto L3084;
    }
  goto ret0;

 L3084: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 455 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-ps-3d.md"
(TARGET_MIPS3D) && 
#line 419 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT)))
    {
      return 406;  /* mips_rsqrt2_d */
    }
  goto ret0;

 L3115: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, DFmode))
    {
      operands[1] = x2;
      goto L3116;
    }
  goto ret0;

 L3116: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, DFmode))
    {
      operands[2] = x2;
      goto L3117;
    }
  goto ret0;

 L3117: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 474 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-ps-3d.md"
(TARGET_MIPS3D) && 
#line 419 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT)))
    {
      return 412;  /* mips_recip2_d */
    }
  goto ret0;

 L2818: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L4580;
    case DImode:
      goto L4581;
    case CCmode:
      goto L4582;
    default:
      break;
    }
  goto ret0;

 L4580: ATTRIBUTE_UNUSED_LABEL
  if (equality_operator (x2, SImode))
    {
      operands[4] = x2;
      goto L2819;
    }
  goto ret0;

 L2819: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L2820;
    }
  goto ret0;

 L2820: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L2821;
  goto ret0;

 L2821: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, DFmode))
    {
      operands[2] = x2;
      goto L2822;
    }
  goto ret0;

 L2822: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (register_operand (x2, DFmode))
    {
      operands[3] = x2;
      goto L2823;
    }
  goto ret0;

 L2823: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 5324 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_CONDMOVE) && 
#line 424 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT)))
    {
      return 370;  /* *movdf_on_si */
    }
  goto ret0;

 L4581: ATTRIBUTE_UNUSED_LABEL
  if (equality_operator (x2, DImode))
    {
      operands[4] = x2;
      goto L2837;
    }
  goto ret0;

 L2837: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L2838;
    }
  goto ret0;

 L2838: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L2839;
  goto ret0;

 L2839: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, DFmode))
    {
      operands[2] = x2;
      goto L2840;
    }
  goto ret0;

 L2840: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (register_operand (x2, DFmode))
    {
      operands[3] = x2;
      goto L2841;
    }
  goto ret0;

 L2841: ATTRIBUTE_UNUSED_LABEL
  if (((
#line 5324 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_CONDMOVE) && 
#line 410 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT)) && 
#line 424 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT)))
    {
      return 372;  /* *movdf_on_di */
    }
  goto ret0;

 L4582: ATTRIBUTE_UNUSED_LABEL
  if (equality_operator (x2, CCmode))
    {
      operands[4] = x2;
      goto L2855;
    }
  goto ret0;

 L2855: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, CCmode))
    {
      operands[1] = x3;
      goto L2856;
    }
  goto ret0;

 L2856: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L2857;
  goto ret0;

 L2857: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, DFmode))
    {
      operands[2] = x2;
      goto L2858;
    }
  goto ret0;

 L2858: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (register_operand (x2, DFmode))
    {
      operands[3] = x2;
      goto L2859;
    }
  goto ret0;

 L2859: ATTRIBUTE_UNUSED_LABEL
  if (((
#line 5324 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_CONDMOVE) && 
#line 410 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT)) && 
#line 424 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT)))
    {
      return 374;  /* *movdf_on_cc */
    }
  goto ret0;
 ret0:
  return -1;
}

static int
recog_3 (rtx x0 ATTRIBUTE_UNUSED,
	rtx insn ATTRIBUTE_UNUSED,
	int *pnum_clobbers ATTRIBUTE_UNUSED)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x1 ATTRIBUTE_UNUSED;
  rtx x2 ATTRIBUTE_UNUSED;
  rtx x3 ATTRIBUTE_UNUSED;
  rtx x4 ATTRIBUTE_UNUSED;
  rtx x5 ATTRIBUTE_UNUSED;
  rtx x6 ATTRIBUTE_UNUSED;
  rtx x7 ATTRIBUTE_UNUSED;
  int tem ATTRIBUTE_UNUSED;

  x1 = XEXP (x0, 1);
  switch (GET_CODE (x1))
    {
    case PLUS:
      goto L28;
    case MINUS:
      goto L108;
    case MULT:
      goto L156;
    case NEG:
      goto L934;
    case DIV:
      goto L1033;
    case SQRT:
      goto L1111;
    case ABS:
      goto L1168;
    case MEM:
      goto L1800;
    case IF_THEN_ELSE:
      goto L2872;
    case UNSPEC:
      goto L4606;
    case VEC_MERGE:
      goto L2897;
    case VEC_CONCAT:
      goto L2937;
    default:
     break;
   }
  goto ret0;

 L28: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == V2SFmode)
    goto L4617;
  goto ret0;

 L4617: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == MULT)
    goto L885;
  if (register_operand (x2, V2SFmode))
    {
      operands[1] = x2;
      goto L29;
    }
  goto ret0;

 L885: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V2SFmode))
    {
      operands[1] = x3;
      goto L886;
    }
  goto ret0;

 L886: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, V2SFmode))
    {
      operands[2] = x3;
      goto L887;
    }
  goto ret0;

 L887: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, V2SFmode))
    {
      operands[3] = x2;
      goto L888;
    }
  goto ret0;

 L888: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 1742 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_FP4 && TARGET_FUSED_MADD) && 
#line 420 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_PAIRED_SINGLE_FLOAT)))
    {
      return 66;  /* *maddv2sf */
    }
  goto ret0;

 L29: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, V2SFmode))
    {
      operands[2] = x2;
      goto L30;
    }
  goto ret0;

 L30: ATTRIBUTE_UNUSED_LABEL
  if (
#line 420 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_PAIRED_SINGLE_FLOAT))
    {
      return 5;  /* addv2sf3 */
    }
  goto ret0;

 L108: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == V2SFmode)
    goto L4619;
  goto ret0;

 L4619: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == MULT)
    goto L909;
  if (register_operand (x2, V2SFmode))
    {
      operands[1] = x2;
      goto L109;
    }
  goto ret0;

 L909: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == V2SFmode)
    goto L4621;
  goto ret0;

 L4621: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x3) == NEG)
    goto L963;
  if (register_operand (x3, V2SFmode))
    {
      operands[1] = x3;
      goto L910;
    }
  goto ret0;

 L963: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, V2SFmode))
    {
      operands[1] = x4;
      goto L964;
    }
  goto ret0;

 L964: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, V2SFmode))
    {
      operands[2] = x3;
      goto L965;
    }
  goto ret0;

 L965: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, V2SFmode))
    {
      operands[3] = x2;
      goto L966;
    }
  goto ret0;

 L966: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 1775 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_NMADD_NMSUB && TARGET_FUSED_MADD
   && !HONOR_SIGNED_ZEROS (V2SFmode)) && 
#line 420 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_PAIRED_SINGLE_FLOAT)))
    {
      return 75;  /* *nmaddv2sf_fastmath */
    }
  goto ret0;

 L910: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, V2SFmode))
    {
      operands[2] = x3;
      goto L911;
    }
  goto ret0;

 L911: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, V2SFmode))
    {
      operands[3] = x2;
      goto L912;
    }
  goto ret0;

 L912: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 1752 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_FP4 && TARGET_FUSED_MADD) && 
#line 420 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_PAIRED_SINGLE_FLOAT)))
    {
      return 69;  /* *msubv2sf */
    }
  goto ret0;

 L109: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == V2SFmode)
    goto L4623;
  goto ret0;

 L4623: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == MULT)
    goto L1015;
  if (register_operand (x2, V2SFmode))
    {
      operands[2] = x2;
      goto L110;
    }
  goto ret0;

 L1015: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V2SFmode))
    {
      operands[2] = x3;
      goto L1016;
    }
  goto ret0;

 L1016: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, V2SFmode))
    {
      operands[3] = x3;
      goto L1017;
    }
  goto ret0;

 L1017: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 1799 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_NMADD_NMSUB && TARGET_FUSED_MADD
   && !HONOR_SIGNED_ZEROS (V2SFmode)) && 
#line 420 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_PAIRED_SINGLE_FLOAT)))
    {
      return 81;  /* *nmsubv2sf_fastmath */
    }
  goto ret0;

 L110: ATTRIBUTE_UNUSED_LABEL
  if (
#line 420 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_PAIRED_SINGLE_FLOAT))
    {
      return 18;  /* subv2sf3 */
    }
  goto ret0;

 L156: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V2SFmode))
    {
      operands[1] = x2;
      goto L157;
    }
  goto ret0;

 L157: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, V2SFmode))
    {
      operands[2] = x2;
      goto L158;
    }
  goto ret0;

 L158: ATTRIBUTE_UNUSED_LABEL
  if (
#line 955 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_PAIRED_SINGLE_FLOAT))
    {
      return 26;  /* mulv2sf3 */
    }
  goto ret0;

 L934: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == V2SFmode)
    goto L4624;
  goto ret0;

 L4624: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case PLUS:
      goto L935;
    case MINUS:
      goto L989;
    case REG:
    case SUBREG:
      goto L4626;
    default:
      goto ret0;
   }
 L4626: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, V2SFmode))
    {
      operands[1] = x2;
      goto L1203;
    }
  goto ret0;

 L935: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == V2SFmode
      && GET_CODE (x3) == MULT)
    goto L936;
  goto ret0;

 L936: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, V2SFmode))
    {
      operands[1] = x4;
      goto L937;
    }
  goto ret0;

 L937: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (register_operand (x4, V2SFmode))
    {
      operands[2] = x4;
      goto L938;
    }
  goto ret0;

 L938: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, V2SFmode))
    {
      operands[3] = x3;
      goto L939;
    }
  goto ret0;

 L939: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 1763 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_NMADD_NMSUB && TARGET_FUSED_MADD
   && HONOR_SIGNED_ZEROS (V2SFmode)) && 
#line 420 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_PAIRED_SINGLE_FLOAT)))
    {
      return 72;  /* *nmaddv2sf */
    }
  goto ret0;

 L989: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == V2SFmode
      && GET_CODE (x3) == MULT)
    goto L990;
  goto ret0;

 L990: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, V2SFmode))
    {
      operands[2] = x4;
      goto L991;
    }
  goto ret0;

 L991: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (register_operand (x4, V2SFmode))
    {
      operands[3] = x4;
      goto L992;
    }
  goto ret0;

 L992: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, V2SFmode))
    {
      operands[1] = x3;
      goto L993;
    }
  goto ret0;

 L993: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 1787 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_NMADD_NMSUB && TARGET_FUSED_MADD
   && HONOR_SIGNED_ZEROS (V2SFmode)) && 
#line 420 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_PAIRED_SINGLE_FLOAT)))
    {
      return 78;  /* *nmsubv2sf */
    }
  goto ret0;

 L1203: ATTRIBUTE_UNUSED_LABEL
  if (
#line 420 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_PAIRED_SINGLE_FLOAT))
    {
      return 110;  /* negv2sf2 */
    }
  goto ret0;

 L1033: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V2SFmode))
    {
      operands[1] = x2;
      goto L1034;
    }
  if (const_1_operand (x2, V2SFmode))
    {
      operands[1] = x2;
      goto L1052;
    }
  goto ret0;

 L1034: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, V2SFmode))
    {
      operands[2] = x2;
      goto L1035;
    }
  goto ret0;

 L1035: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 1840 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_SB1 && (!TARGET_FIX_SB1 || flag_unsafe_math_optimizations)) && 
#line 420 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_PAIRED_SINGLE_FLOAT)))
    {
      return 84;  /* *divv2sf3 */
    }
  goto ret0;

 L1052: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == V2SFmode)
    goto L4628;
  goto ret0;

 L4628: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == SQRT)
    goto L1132;
  if (register_operand (x2, V2SFmode))
    {
      operands[2] = x2;
      goto L1053;
    }
  goto ret0;

 L1132: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V2SFmode))
    {
      operands[2] = x3;
      goto L1133;
    }
  goto ret0;

 L1133: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 1929 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_SB1 && flag_unsafe_math_optimizations) && 
#line 420 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_PAIRED_SINGLE_FLOAT)))
    {
      return 97;  /* *rsqrtv2sfa */
    }
  goto ret0;

 L1053: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 1858 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_SB1 && flag_unsafe_math_optimizations) && 
#line 420 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_PAIRED_SINGLE_FLOAT)))
    {
      return 87;  /* *recipv2sf3 */
    }
  goto ret0;

 L1111: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == V2SFmode)
    goto L4630;
  goto ret0;

 L4630: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == DIV)
    goto L1152;
  if (register_operand (x2, V2SFmode))
    {
      operands[1] = x2;
      goto L1112;
    }
  goto ret0;

 L1152: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (const_1_operand (x3, V2SFmode))
    {
      operands[1] = x3;
      goto L1153;
    }
  goto ret0;

 L1153: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, V2SFmode))
    {
      operands[2] = x3;
      goto L1154;
    }
  goto ret0;

 L1154: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 1947 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_SB1 && flag_unsafe_math_optimizations) && 
#line 420 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_PAIRED_SINGLE_FLOAT)))
    {
      return 100;  /* *rsqrtv2sfb */
    }
  goto ret0;

 L1112: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 1911 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_SB1) && 
#line 420 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_PAIRED_SINGLE_FLOAT)))
    {
      return 94;  /* sqrtv2sf2 */
    }
  goto ret0;

 L1168: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V2SFmode))
    {
      operands[1] = x2;
      goto L1169;
    }
  goto ret0;

 L1169: ATTRIBUTE_UNUSED_LABEL
  if (
#line 420 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_PAIRED_SINGLE_FLOAT))
    {
      return 103;  /* absv2sf2 */
    }
  goto ret0;

 L1800: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L4631;
    case DImode:
      goto L4632;
    default:
      break;
    }
  goto ret0;

 L4631: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == PLUS)
    goto L1801;
  goto ret0;

 L1801: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L1802;
    }
  goto ret0;

 L1802: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L1803;
    }
  goto ret0;

 L1803: ATTRIBUTE_UNUSED_LABEL
  if (((
#line 3478 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_FP4) && 
#line 406 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(Pmode == SImode)) && 
#line 420 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_PAIRED_SINGLE_FLOAT)))
    {
      return 217;  /* *ldxc1_si */
    }
  goto ret0;

 L4632: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == PLUS)
    goto L1822;
  goto ret0;

 L1822: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L1823;
    }
  goto ret0;

 L1823: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L1824;
    }
  goto ret0;

 L1824: ATTRIBUTE_UNUSED_LABEL
  if (((
#line 3478 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_FP4) && 
#line 406 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(Pmode == DImode)) && 
#line 420 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_PAIRED_SINGLE_FLOAT)))
    {
      return 220;  /* *ldxc1_di */
    }
  goto ret0;

 L2872: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L4633;
    case DImode:
      goto L4634;
    default:
      break;
    }
  goto ret0;

 L4633: ATTRIBUTE_UNUSED_LABEL
  if (equality_operator (x2, SImode))
    {
      operands[4] = x2;
      goto L2873;
    }
  goto ret0;

 L2873: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L2874;
    }
  goto ret0;

 L2874: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L2875;
  goto ret0;

 L2875: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, V2SFmode))
    {
      operands[2] = x2;
      goto L2876;
    }
  goto ret0;

 L2876: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (register_operand (x2, V2SFmode))
    {
      operands[3] = x2;
      goto L2877;
    }
  goto ret0;

 L2877: ATTRIBUTE_UNUSED_LABEL
  if (
#line 29 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-ps-3d.md"
(TARGET_PAIRED_SINGLE_FLOAT))
    {
      return 378;  /* *movcc_v2sf_si */
    }
  goto ret0;

 L4634: ATTRIBUTE_UNUSED_LABEL
  if (equality_operator (x2, DImode))
    {
      operands[4] = x2;
      goto L2882;
    }
  goto ret0;

 L2882: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L2883;
    }
  goto ret0;

 L2883: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L2884;
  goto ret0;

 L2884: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, V2SFmode))
    {
      operands[2] = x2;
      goto L2885;
    }
  goto ret0;

 L2885: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (register_operand (x2, V2SFmode))
    {
      operands[3] = x2;
      goto L2886;
    }
  goto ret0;

 L2886: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 29 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-ps-3d.md"
(TARGET_PAIRED_SINGLE_FLOAT) && 
#line 402 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT)))
    {
      return 379;  /* *movcc_v2sf_di */
    }
  goto ret0;

 L4606: ATTRIBUTE_UNUSED_LABEL
  switch (XVECLEN (x1, 0))
    {
    case 3:
      goto L4635;
    case 2:
      goto L4637;
    case 1:
      goto L4638;
    default:
      break;
    }
  goto ret0;

 L4635: ATTRIBUTE_UNUSED_LABEL
  switch (XINT (x1, 1))
    {
    case 200L:
      goto L2890;
    case 202L:
      goto L2950;
    default:
      break;
    }
  goto ret0;

 L2890: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V2SFmode))
    {
      operands[1] = x2;
      goto L2891;
    }
  goto ret0;

 L2891: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V2SFmode))
    {
      operands[2] = x2;
      goto L2892;
    }
  goto ret0;

 L2892: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 2);
  if (register_operand (x2, CCV2mode))
    {
      operands[3] = x2;
      goto L2893;
    }
  goto ret0;

 L2893: ATTRIBUTE_UNUSED_LABEL
  if (
#line 42 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-ps-3d.md"
(TARGET_PAIRED_SINGLE_FLOAT))
    {
      return 380;  /* mips_cond_move_tf_ps */
    }
  goto ret0;

 L2950: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V2SFmode))
    {
      operands[1] = x2;
      goto L2951;
    }
  goto ret0;

 L2951: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V2SFmode))
    {
      operands[2] = x2;
      goto L2952;
    }
  goto ret0;

 L2952: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 2);
  if (register_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L2953;
    }
  goto ret0;

 L2953: ATTRIBUTE_UNUSED_LABEL
  if (
#line 232 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-ps-3d.md"
(TARGET_PAIRED_SINGLE_FLOAT))
    {
      return 387;  /* mips_alnv_ps */
    }
  goto ret0;

 L4637: ATTRIBUTE_UNUSED_LABEL
  switch (XINT (x1, 1))
    {
    case 204L:
      goto L2957;
    case 207L:
      goto L2973;
    case 209L:
      goto L3088;
    case 211L:
      goto L3121;
    default:
      break;
    }
  goto ret0;

 L2957: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V2SFmode))
    {
      operands[1] = x2;
      goto L2958;
    }
  goto ret0;

 L2958: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V2SFmode))
    {
      operands[2] = x2;
      goto L2959;
    }
  goto ret0;

 L2959: ATTRIBUTE_UNUSED_LABEL
  if (
#line 243 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-ps-3d.md"
(TARGET_MIPS3D))
    {
      return 388;  /* mips_addr_ps */
    }
  goto ret0;

 L2973: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V2SFmode))
    {
      operands[1] = x2;
      goto L2974;
    }
  goto ret0;

 L2974: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V2SFmode))
    {
      operands[2] = x2;
      goto L2975;
    }
  goto ret0;

 L2975: ATTRIBUTE_UNUSED_LABEL
  if (
#line 274 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-ps-3d.md"
(TARGET_MIPS3D))
    {
      return 391;  /* mips_mulr_ps */
    }
  goto ret0;

 L3088: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V2SFmode))
    {
      operands[1] = x2;
      goto L3089;
    }
  goto ret0;

 L3089: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V2SFmode))
    {
      operands[2] = x2;
      goto L3090;
    }
  goto ret0;

 L3090: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 455 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-ps-3d.md"
(TARGET_MIPS3D) && 
#line 420 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_PAIRED_SINGLE_FLOAT)))
    {
      return 407;  /* mips_rsqrt2_ps */
    }
  goto ret0;

 L3121: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V2SFmode))
    {
      operands[1] = x2;
      goto L3122;
    }
  goto ret0;

 L3122: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V2SFmode))
    {
      operands[2] = x2;
      goto L3123;
    }
  goto ret0;

 L3123: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 474 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-ps-3d.md"
(TARGET_MIPS3D) && 
#line 420 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_PAIRED_SINGLE_FLOAT)))
    {
      return 413;  /* mips_recip2_ps */
    }
  goto ret0;

 L4638: ATTRIBUTE_UNUSED_LABEL
  switch (XINT (x1, 1))
    {
    case 205L:
      goto L2963;
    case 206L:
      goto L2968;
    case 208L:
      goto L3071;
    case 210L:
      goto L3104;
    default:
      break;
    }
  goto ret0;

 L2963: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V2SFmode))
    {
      operands[1] = x2;
      goto L2964;
    }
  goto ret0;

 L2964: ATTRIBUTE_UNUSED_LABEL
  if (
#line 253 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-ps-3d.md"
(TARGET_MIPS3D))
    {
      return 389;  /* mips_cvt_pw_ps */
    }
  goto ret0;

 L2968: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V2SFmode))
    {
      operands[1] = x2;
      goto L2969;
    }
  goto ret0;

 L2969: ATTRIBUTE_UNUSED_LABEL
  if (
#line 263 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-ps-3d.md"
(TARGET_MIPS3D))
    {
      return 390;  /* mips_cvt_ps_pw */
    }
  goto ret0;

 L3071: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V2SFmode))
    {
      operands[1] = x2;
      goto L3072;
    }
  goto ret0;

 L3072: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 445 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-ps-3d.md"
(TARGET_MIPS3D) && 
#line 420 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_PAIRED_SINGLE_FLOAT)))
    {
      return 404;  /* mips_rsqrt1_ps */
    }
  goto ret0;

 L3104: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V2SFmode))
    {
      operands[1] = x2;
      goto L3105;
    }
  goto ret0;

 L3105: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 464 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-ps-3d.md"
(TARGET_MIPS3D) && 
#line 420 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_PAIRED_SINGLE_FLOAT)))
    {
      return 410;  /* mips_recip1_ps */
    }
  goto ret0;

 L2897: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == V2SFmode)
    goto L4646;
  goto ret0;

 L4646: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == VEC_SELECT)
    goto L2914;
  if (register_operand (x2, V2SFmode))
    {
      operands[1] = x2;
      goto L2898;
    }
  goto ret0;

 L2914: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V2SFmode))
    {
      operands[1] = x3;
      goto L2915;
    }
  goto ret0;

 L2915: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == PARALLEL
      && XVECLEN (x3, 0) == 2)
    goto L2916;
  goto ret0;

 L2916: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 0);
  if (x4 == const_int_rtx[MAX_SAVED_CONST_INT + (1)])
    goto L2917;
  goto ret0;

 L2917: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 1);
  if (x4 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L2918;
  goto ret0;

 L2918: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == V2SFmode)
    goto L4648;
  goto ret0;

 L4648: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == VEC_SELECT)
    goto L2929;
  if (register_operand (x2, V2SFmode))
    {
      operands[2] = x2;
      goto L2919;
    }
  goto ret0;

 L2929: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V2SFmode))
    {
      operands[2] = x3;
      goto L2930;
    }
  goto ret0;

 L2930: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == PARALLEL
      && XVECLEN (x3, 0) == 2)
    goto L2931;
  goto ret0;

 L2931: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 0);
  if (x4 == const_int_rtx[MAX_SAVED_CONST_INT + (1)])
    goto L2932;
  goto ret0;

 L2932: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 1);
  if (x4 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L2933;
  goto ret0;

 L2933: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (2)]
      && 
#line 120 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-ps-3d.md"
(TARGET_PAIRED_SINGLE_FLOAT))
    {
      return 384;  /* mips_plu_ps */
    }
  goto ret0;

 L2919: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (2)]
      && 
#line 104 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-ps-3d.md"
(TARGET_PAIRED_SINGLE_FLOAT))
    {
      return 383;  /* mips_pll_ps */
    }
  goto ret0;

 L2898: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == V2SFmode)
    goto L4650;
  goto ret0;

 L4650: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == VEC_SELECT)
    goto L2905;
  if (register_operand (x2, V2SFmode))
    {
      operands[2] = x2;
      goto L2899;
    }
  goto ret0;

 L2905: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V2SFmode))
    {
      operands[2] = x3;
      goto L2906;
    }
  goto ret0;

 L2906: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == PARALLEL
      && XVECLEN (x3, 0) == 2)
    goto L2907;
  goto ret0;

 L2907: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 0);
  if (x4 == const_int_rtx[MAX_SAVED_CONST_INT + (1)])
    goto L2908;
  goto ret0;

 L2908: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 1);
  if (x4 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L2909;
  goto ret0;

 L2909: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (2)]
      && 
#line 90 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-ps-3d.md"
(TARGET_PAIRED_SINGLE_FLOAT))
    {
      return 382;  /* mips_puu_ps */
    }
  goto ret0;

 L2899: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (2)]
      && 
#line 76 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-ps-3d.md"
(TARGET_PAIRED_SINGLE_FLOAT))
    {
      return 381;  /* mips_pul_ps */
    }
  goto ret0;

 L2937: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SFmode))
    {
      operands[1] = x2;
      goto L2938;
    }
  goto ret0;

 L2938: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, SFmode))
    {
      operands[2] = x2;
      goto L2939;
    }
  goto ret0;

 L2939: ATTRIBUTE_UNUSED_LABEL
  if (
#line 142 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-ps-3d.md"
(TARGET_PAIRED_SINGLE_FLOAT))
    {
      return 385;  /* vec_initv2sf_internal */
    }
  goto ret0;
 ret0:
  return -1;
}

static int
recog_4 (rtx x0 ATTRIBUTE_UNUSED,
	rtx insn ATTRIBUTE_UNUSED,
	int *pnum_clobbers ATTRIBUTE_UNUSED)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x1 ATTRIBUTE_UNUSED;
  rtx x2 ATTRIBUTE_UNUSED;
  rtx x3 ATTRIBUTE_UNUSED;
  rtx x4 ATTRIBUTE_UNUSED;
  rtx x5 ATTRIBUTE_UNUSED;
  rtx x6 ATTRIBUTE_UNUSED;
  rtx x7 ATTRIBUTE_UNUSED;
  int tem ATTRIBUTE_UNUSED;

  x1 = XEXP (x0, 1);
  switch (GET_CODE (x1))
    {
    case PLUS:
      goto L58;
    case MINUS:
      goto L114;
    case MULT:
      goto L173;
    case NEG:
      goto L449;
    case TRUNCATE:
      goto L640;
    case CLZ:
      goto L1173;
    case NOT:
      goto L1207;
    case AND:
      goto L1216;
    case IOR:
      goto L1240;
    case XOR:
      goto L1264;
    case SIGN_EXTEND:
      goto L1337;
    case ZERO_EXTEND:
      goto L1349;
    case FIX:
      goto L1516;
    case ZERO_EXTRACT:
      goto L1582;
    case UNSPEC:
      goto L4701;
    case HIGH:
      goto L1676;
    case LO_SUM:
      goto L1686;
    case ASHIFT:
      goto L1966;
    case ASHIFTRT:
      goto L1972;
    case LSHIFTRT:
      goto L1978;
    case ROTATERT:
      goto L2065;
    case EQ:
      goto L2190;
    case NE:
      goto L2210;
    case GT:
      goto L2220;
    case GE:
      goto L2244;
    case LT:
      goto L2254;
    case LE:
      goto L2278;
    case GTU:
      goto L2302;
    case GEU:
      goto L2326;
    case LTU:
      goto L2336;
    case LEU:
      goto L2360;
    case IF_THEN_ELSE:
      goto L2755;
    case CONST:
    case LABEL_REF:
    case SYMBOL_REF:
      goto L4671;
    default:
      goto ret0;
   }
 L4671: ATTRIBUTE_UNUSED_LABEL
  if (global_got_operand (x1, SImode))
    {
      operands[1] = x1;
      goto L1698;
    }
  goto ret0;

 L58: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode)
    goto L4717;
  goto ret0;

 L4717: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case REG:
      goto L4720;
    case MULT:
      goto L276;
    default:
     break;
   }
 L4718: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L71;
    }
  goto ret0;

 L4720: ATTRIBUTE_UNUSED_LABEL
  if (XINT (x2, 0) == 29)
    goto L59;
  goto L4718;

 L59: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const_arith_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L60;
    }
  x2 = XEXP (x1, 0);
  goto L4718;

 L60: ATTRIBUTE_UNUSED_LABEL
  if (
#line 692 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_MIPS16))
    {
      return 10;  /* *addsi3_sp2 */
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  goto L4718;

 L276: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L277;
    }
  goto ret0;

 L277: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L278;
    }
  goto ret0;

 L278: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L279;
    }
 L844: ATTRIBUTE_UNUSED_LABEL
  if (rtx_equal_p (x2, operands[0])
      && 
#line 1710 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_MAD)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 61;  /* madsi */
    }
  goto ret0;

 L279: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1156 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
((TARGET_MIPS3900
   || ISA_HAS_MADD_MSUB)
   && !TARGET_MIPS16)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 3;
      return 33;  /* *mul_acc_si */
    }
 L300: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1218 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_MACC)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 2;
      return 34;  /* *macc */
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L844;

 L71: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (arith_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L72;
    }
  goto ret0;

 L72: ATTRIBUTE_UNUSED_LABEL
  if (
#line 704 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_MIPS16))
    {
      return 12;  /* *addsi3_mips16 */
    }
  goto ret0;

 L114: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L115;
    }
  goto ret0;

 L115: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode)
    goto L4722;
  goto ret0;

 L4722: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == MULT)
    goto L319;
  if (register_operand (x2, SImode))
    {
      operands[2] = x2;
      return 19;  /* subsi3 */
    }
  goto ret0;

 L319: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L320;
    }
  goto ret0;

 L320: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, SImode))
    {
      operands[3] = x3;
      goto L321;
    }
  goto ret0;

 L321: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1240 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_MSAC)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 2;
      return 35;  /* *msac */
    }
 L344: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1261 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_MACC && !ISA_HAS_MSAC)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 3;
      return 36;  /* *msac_using_macc */
    }
 L433: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1417 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_MADD_MSUB)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 3;
      return 39;  /* *mul_sub_si */
    }
  goto ret0;

 L173: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L174;
    }
  goto ret0;

 L174: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L175;
    }
  goto ret0;

 L175: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1028 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(GENERATE_MULT3_SI)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 2;
      return 27;  /* mulsi3_mult3 */
    }
 L207: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1088 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_FIX_R4000)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 29;  /* mulsi3_internal */
    }
 L239: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1099 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_FIX_R4000)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 2;
      return 31;  /* mulsi3_r4000 */
    }
  goto ret0;

 L449: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode)
    goto L4723;
  goto ret0;

 L4723: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == MULT)
    goto L450;
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      return 106;  /* negsi2 */
    }
  goto ret0;

 L450: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L451;
    }
  goto ret0;

 L451: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L452;
    }
  goto ret0;

 L452: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1472 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_MULS)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 2;
      return 40;  /* *muls */
    }
  goto ret0;

 L640: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == DImode)
    goto L4725;
  goto ret0;

 L4725: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case LSHIFTRT:
      goto L641;
    case ASHIFTRT:
      goto L1325;
    default:
     break;
   }
  goto ret0;

 L641: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DImode)
    goto L4727;
  goto ret0;

 L4727: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x3))
    {
    case MULT:
      goto L642;
    case NEG:
      goto L745;
    case REG:
    case SUBREG:
      goto L4729;
    default:
      goto ret0;
   }
 L4729: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L1333;
    }
  goto ret0;

 L642: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == DImode)
    goto L4730;
  goto ret0;

 L4730: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x4))
    {
    case SIGN_EXTEND:
      goto L643;
    case ZERO_EXTEND:
      goto L667;
    default:
     break;
   }
  goto ret0;

 L643: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (register_operand (x5, SImode))
    {
      operands[1] = x5;
      goto L644;
    }
  goto ret0;

 L644: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_MODE (x4) == DImode
      && GET_CODE (x4) == SIGN_EXTEND)
    goto L645;
  goto ret0;

 L645: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (register_operand (x5, SImode))
    {
      operands[2] = x5;
      goto L646;
    }
  goto ret0;

 L646: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT)
    goto L4732;
  goto ret0;

 L4732: ATTRIBUTE_UNUSED_LABEL
  if (XWINT (x3, 0) == 32L)
    goto L4734;
  goto ret0;

 L4734: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1643 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!ISA_HAS_MULHI && !TARGET_FIX_R4000)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 53;  /* smulsi3_highpart_internal */
    }
 L4735: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1658 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_MULHI)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 2;
      return 55;  /* smulsi3_highpart_mulhi_internal */
    }
  goto ret0;

 L667: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (register_operand (x5, SImode))
    {
      operands[1] = x5;
      goto L668;
    }
  goto ret0;

 L668: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_MODE (x4) == DImode
      && GET_CODE (x4) == ZERO_EXTEND)
    goto L669;
  goto ret0;

 L669: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (register_operand (x5, SImode))
    {
      operands[2] = x5;
      goto L670;
    }
  goto ret0;

 L670: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT)
    goto L4736;
  goto ret0;

 L4736: ATTRIBUTE_UNUSED_LABEL
  if (XWINT (x3, 0) == 32L)
    goto L4738;
  goto ret0;

 L4738: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1643 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!ISA_HAS_MULHI && !TARGET_FIX_R4000)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 54;  /* umulsi3_highpart_internal */
    }
 L4739: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1658 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_MULHI)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 2;
      return 56;  /* umulsi3_highpart_mulhi_internal */
    }
  goto ret0;

 L745: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == DImode
      && GET_CODE (x4) == MULT)
    goto L746;
  goto ret0;

 L746: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (GET_MODE (x5) == DImode)
    goto L4740;
  goto ret0;

 L4740: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x5))
    {
    case SIGN_EXTEND:
      goto L747;
    case ZERO_EXTEND:
      goto L775;
    default:
     break;
   }
  goto ret0;

 L747: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (register_operand (x6, SImode))
    {
      operands[1] = x6;
      goto L748;
    }
  goto ret0;

 L748: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (GET_MODE (x5) == DImode
      && GET_CODE (x5) == SIGN_EXTEND)
    goto L749;
  goto ret0;

 L749: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (register_operand (x6, SImode))
    {
      operands[2] = x6;
      goto L750;
    }
  goto ret0;

 L750: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (32)]
      && 
#line 1676 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_MULHI)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 2;
      return 57;  /* *smulsi3_highpart_neg_mulhi_internal */
    }
  goto ret0;

 L775: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (register_operand (x6, SImode))
    {
      operands[1] = x6;
      goto L776;
    }
  goto ret0;

 L776: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (GET_MODE (x5) == DImode
      && GET_CODE (x5) == ZERO_EXTEND)
    goto L777;
  goto ret0;

 L777: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (register_operand (x6, SImode))
    {
      operands[2] = x6;
      goto L778;
    }
  goto ret0;

 L778: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (32)]
      && 
#line 1676 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_MULHI)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 2;
      return 58;  /* *umulsi3_highpart_neg_mulhi_internal */
    }
  goto ret0;

 L1333: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (32)]
      && 
#line 2240 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT && !TARGET_MIPS16))
    {
      return 132;  /* *mips.md:2236 */
    }
  goto ret0;

 L1325: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L1326;
    }
  goto ret0;

 L1326: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const_arith_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L1327;
    }
  goto ret0;

 L1327: ATTRIBUTE_UNUSED_LABEL
  if (
#line 2231 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT && !TARGET_MIPS16 && INTVAL (operands[2]) >= 32))
    {
      return 131;  /* *mips.md:2226 */
    }
  goto ret0;

 L1173: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L1174;
    }
  goto ret0;

 L1174: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1990 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_CLZ_CLO))
    {
      return 104;  /* clzsi2 */
    }
  goto ret0;

 L1207: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      return 111;  /* one_cmplsi2 */
    }
  goto ret0;

 L1216: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode)
    goto L4743;
  goto ret0;

 L4743: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == NOT)
    goto L1289;
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L1217;
    }
  goto ret0;

 L1289: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L1290;
    }
  goto ret0;

 L1290: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == NOT)
    goto L1291;
  goto ret0;

 L1291: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L1292;
    }
  goto ret0;

 L1292: ATTRIBUTE_UNUSED_LABEL
  if (
#line 2155 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_MIPS16))
    {
      return 125;  /* *norsi3 */
    }
  goto ret0;

 L1217: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (uns_arith_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L1218;
    }
 L1229: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L1230;
    }
  goto ret0;

 L1218: ATTRIBUTE_UNUSED_LABEL
  if (
#line 2069 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_MIPS16))
    {
      return 113;  /* *andsi3 */
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L1229;

 L1230: ATTRIBUTE_UNUSED_LABEL
  if (
#line 2080 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_MIPS16))
    {
      return 115;  /* *andsi3_mips16 */
    }
  goto ret0;

 L1240: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L1241;
    }
  goto ret0;

 L1241: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (uns_arith_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L1242;
    }
 L1253: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L1254;
    }
  goto ret0;

 L1242: ATTRIBUTE_UNUSED_LABEL
  if (
#line 2099 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_MIPS16))
    {
      return 117;  /* *iorsi3 */
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L1253;

 L1254: ATTRIBUTE_UNUSED_LABEL
  if (
#line 2110 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_MIPS16))
    {
      return 119;  /* *iorsi3_mips16 */
    }
  goto ret0;

 L1264: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L1265;
    }
  goto ret0;

 L1265: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (uns_arith_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L1266;
    }
  goto ret0;

 L1266: ATTRIBUTE_UNUSED_LABEL
  if (
#line 2126 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_MIPS16))
    {
      return 121;  /* *mips.md:2122 */
    }
 L1278: ATTRIBUTE_UNUSED_LABEL
  if (
#line 2137 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_MIPS16))
    {
      return 123;  /* *mips.md:2133 */
    }
  goto ret0;

 L1337: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case HImode:
      goto L4744;
    case QImode:
      goto L4745;
    default:
      break;
    }
  goto ret0;

 L4744: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == TRUNCATE)
    goto L1338;
  if (nonimmediate_operand (x2, HImode))
    {
      operands[1] = x2;
      goto L1458;
    }
 L4748: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == MEM)
    goto L3948;
  goto ret0;

 L1338: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L1339;
    }
  goto ret0;

 L1339: ATTRIBUTE_UNUSED_LABEL
  if (
#line 2253 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT && !TARGET_MIPS16))
    {
      return 133;  /* *mips.md:2249 */
    }
  goto ret0;

 L1458: ATTRIBUTE_UNUSED_LABEL
  if (
#line 2451 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(GENERATE_MIPS16E))
    {
      return 156;  /* *extendhisi2_mips16e */
    }
 L1478: ATTRIBUTE_UNUSED_LABEL
  if (
#line 2462 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!ISA_HAS_SEB_SEH && !GENERATE_MIPS16E))
    {
      return 160;  /* *extendhisi2 */
    }
 L1498: ATTRIBUTE_UNUSED_LABEL
  if (
#line 2482 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_SEB_SEH))
    {
      return 164;  /* *extendhisi2_seh */
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  goto L4748;

 L3948: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == PLUS)
    goto L3949;
  goto ret0;

 L3949: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L3950;
    }
  goto ret0;

 L3950: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (register_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L3951;
    }
  goto ret0;

 L3951: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1029 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP))
    {
      return 497;  /* mips_lhx */
    }
  goto ret0;

 L4745: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == TRUNCATE)
    goto L1344;
  if (nonimmediate_operand (x2, QImode))
    {
      operands[1] = x2;
      goto L1448;
    }
  goto ret0;

 L1344: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L1345;
    }
  goto ret0;

 L1345: ATTRIBUTE_UNUSED_LABEL
  if (
#line 2268 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT && !TARGET_MIPS16))
    {
      return 134;  /* *mips.md:2264 */
    }
  goto ret0;

 L1448: ATTRIBUTE_UNUSED_LABEL
  if (
#line 2451 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(GENERATE_MIPS16E))
    {
      return 154;  /* *extendqisi2_mips16e */
    }
 L1468: ATTRIBUTE_UNUSED_LABEL
  if (
#line 2462 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!ISA_HAS_SEB_SEH && !GENERATE_MIPS16E))
    {
      return 158;  /* *extendqisi2 */
    }
 L1488: ATTRIBUTE_UNUSED_LABEL
  if (
#line 2482 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_SEB_SEH))
    {
      return 162;  /* *extendqisi2_seb */
    }
  goto ret0;

 L1349: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case HImode:
      goto L4749;
    case QImode:
      goto L4750;
    default:
      break;
    }
  goto ret0;

 L4749: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == TRUNCATE)
    goto L1350;
  if (nonimmediate_operand (x2, HImode))
    {
      operands[1] = x2;
      goto L1383;
    }
 L4754: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, HImode))
    {
      operands[1] = x2;
      goto L1403;
    }
 L4756: ATTRIBUTE_UNUSED_LABEL
  if (memory_operand (x2, HImode))
    {
      operands[1] = x2;
      goto L1423;
    }
  goto ret0;

 L1350: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L1351;
    }
  goto ret0;

 L1351: ATTRIBUTE_UNUSED_LABEL
  if (
#line 2286 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT && !TARGET_MIPS16))
    {
      return 135;  /* *mips.md:2282 */
    }
  goto ret0;

 L1383: ATTRIBUTE_UNUSED_LABEL
  if (
#line 2355 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_MIPS16))
    {
      return 141;  /* *zero_extendhisi2 */
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  goto L4754;

 L1403: ATTRIBUTE_UNUSED_LABEL
  if (
#line 2365 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(GENERATE_MIPS16E))
    {
      return 145;  /* *zero_extendhisi2_mips16e */
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  goto L4756;

 L1423: ATTRIBUTE_UNUSED_LABEL
  if (
#line 2373 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_MIPS16))
    {
      return 149;  /* *zero_extendhisi2_mips16 */
    }
  goto ret0;

 L4750: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == TRUNCATE)
    goto L1356;
  if (nonimmediate_operand (x2, QImode))
    {
      operands[1] = x2;
      goto L1373;
    }
 L4753: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, QImode))
    {
      operands[1] = x2;
      goto L1393;
    }
 L4755: ATTRIBUTE_UNUSED_LABEL
  if (memory_operand (x2, QImode))
    {
      operands[1] = x2;
      goto L1413;
    }
 L4757: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == MEM)
    goto L3940;
  goto ret0;

 L1356: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L1357;
    }
  goto ret0;

 L1357: ATTRIBUTE_UNUSED_LABEL
  if (
#line 2295 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT && !TARGET_MIPS16))
    {
      return 136;  /* *mips.md:2291 */
    }
  goto ret0;

 L1373: ATTRIBUTE_UNUSED_LABEL
  if (
#line 2355 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_MIPS16))
    {
      return 139;  /* *zero_extendqisi2 */
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  goto L4753;

 L1393: ATTRIBUTE_UNUSED_LABEL
  if (
#line 2365 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(GENERATE_MIPS16E))
    {
      return 143;  /* *zero_extendqisi2_mips16e */
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  goto L4755;

 L1413: ATTRIBUTE_UNUSED_LABEL
  if (
#line 2373 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_MIPS16))
    {
      return 147;  /* *zero_extendqisi2_mips16 */
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  goto L4757;

 L3940: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == PLUS)
    goto L3941;
  goto ret0;

 L3941: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L3942;
    }
  goto ret0;

 L3942: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (register_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L3943;
    }
  goto ret0;

 L3943: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1017 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP))
    {
      return 496;  /* mips_lbux */
    }
  goto ret0;

 L1516: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case DFmode:
      goto L4758;
    case SFmode:
      goto L4759;
    default:
      break;
    }
  goto ret0;

 L4758: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DFmode))
    {
      operands[1] = x2;
      goto L1517;
    }
  goto ret0;

 L1517: ATTRIBUTE_UNUSED_LABEL
  if (
#line 2534 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT && ISA_HAS_TRUNC_W))
    {
      return 168;  /* fix_truncdfsi2_insn */
    }
 L1530: ATTRIBUTE_UNUSED_LABEL
  if (
#line 2545 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT && !ISA_HAS_TRUNC_W)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 169;  /* fix_truncdfsi2_macro */
    }
  goto ret0;

 L4759: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SFmode))
    {
      operands[1] = x2;
      goto L1535;
    }
  goto ret0;

 L1535: ATTRIBUTE_UNUSED_LABEL
  if (
#line 2572 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && ISA_HAS_TRUNC_W))
    {
      return 170;  /* fix_truncsfsi2_insn */
    }
 L1548: ATTRIBUTE_UNUSED_LABEL
  if (
#line 2583 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && !ISA_HAS_TRUNC_W)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 171;  /* fix_truncsfsi2_macro */
    }
  goto ret0;

 L1582: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L1583;
    }
  goto ret0;

 L1583: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (immediate_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L1584;
    }
  goto ret0;

 L1584: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (immediate_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L1585;
    }
  goto ret0;

 L1585: ATTRIBUTE_UNUSED_LABEL
  if (
#line 2886 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(mips_use_ins_ext_p (operands[1], operands[2], operands[3])))
    {
      return 178;  /* extzvsi */
    }
  goto ret0;

 L4701: ATTRIBUTE_UNUSED_LABEL
  switch (XVECLEN (x1, 0))
    {
    case 2:
      goto L4760;
    case 3:
      goto L4761;
    case 1:
      goto L4766;
    case 4:
      goto L4771;
    case 7:
      goto L4775;
    default:
      break;
    }
  goto ret0;

 L4760: ATTRIBUTE_UNUSED_LABEL
  switch (XINT (x1, 1))
    {
    case 18L:
      goto L1610;
    case 24L:
      goto L1716;
    case 26L:
      goto L1918;
    case 306L:
      goto L3260;
    case 327L:
      goto L3429;
    case 353L:
      goto L3769;
    case 354L:
      goto L3775;
    case 355L:
      goto L3781;
    default:
      break;
    }
  goto ret0;

 L1610: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (memory_operand (x2, BLKmode))
    {
      operands[1] = x2;
      goto L1611;
    }
  goto ret0;

 L1611: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (memory_operand (x2, QImode))
    {
      operands[2] = x2;
      goto L1612;
    }
  goto ret0;

 L1612: ATTRIBUTE_UNUSED_LABEL
  if (
#line 2944 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_MIPS16 && mips_mem_fits_mode_p (SImode, operands[1])))
    {
      return 182;  /* mov_lwl */
    }
  goto ret0;

 L1716: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L1717;
    }
  goto ret0;

 L1717: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (immediate_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L1718;
    }
  goto ret0;

 L1718: ATTRIBUTE_UNUSED_LABEL
  if (
#line 406 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(Pmode == SImode))
    {
      return 200;  /* load_gotsi */
    }
  goto ret0;

 L1918: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L1919;
    }
  goto ret0;

 L1919: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L1920;
    }
  goto ret0;

 L1920: ATTRIBUTE_UNUSED_LABEL
  if (
#line 3864 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!ISA_HAS_MACCHI))
    {
      return 239;  /* *mfhilo_si */
    }
 L1932: ATTRIBUTE_UNUSED_LABEL
  if (
#line 3874 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_MACCHI))
    {
      return 241;  /* *mfhilo_si_macc */
    }
  goto ret0;

 L3260: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L3261;
    }
  goto ret0;

 L3261: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L3262;
    }
  goto ret0;

 L3262: ATTRIBUTE_UNUSED_LABEL
  if (
#line 124 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP))
    {
      return 426;  /* mips_modsub */
    }
  goto ret0;

 L3429: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L3430;
    }
  goto ret0;

 L3430: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (arith_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L3431;
    }
  goto ret0;

 L3431: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 384 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP) && 
#line 19 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP)))
    {
      return 450;  /* mips_shra_r_w */
    }
  goto ret0;

 L3769: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V4QImode))
    {
      operands[1] = x2;
      goto L3770;
    }
  goto ret0;

 L3770: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V4QImode))
    {
      operands[2] = x2;
      goto L3771;
    }
  goto ret0;

 L3771: ATTRIBUTE_UNUSED_LABEL
  if (
#line 753 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP))
    {
      return 480;  /* mips_cmpgu_eq_qb */
    }
  goto ret0;

 L3775: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V4QImode))
    {
      operands[1] = x2;
      goto L3776;
    }
  goto ret0;

 L3776: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V4QImode))
    {
      operands[2] = x2;
      goto L3777;
    }
  goto ret0;

 L3777: ATTRIBUTE_UNUSED_LABEL
  if (
#line 763 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP))
    {
      return 481;  /* mips_cmpgu_lt_qb */
    }
  goto ret0;

 L3781: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V4QImode))
    {
      operands[1] = x2;
      goto L3782;
    }
  goto ret0;

 L3782: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V4QImode))
    {
      operands[2] = x2;
      goto L3783;
    }
  goto ret0;

 L3783: ATTRIBUTE_UNUSED_LABEL
  if (
#line 773 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP))
    {
      return 482;  /* mips_cmpgu_le_qb */
    }
  goto ret0;

 L4761: ATTRIBUTE_UNUSED_LABEL
  switch (XINT (x1, 1))
    {
    case 19L:
      goto L1622;
    case 23L:
      goto L2579;
    default:
      break;
    }
  goto ret0;

 L1622: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (memory_operand (x2, BLKmode))
    {
      operands[1] = x2;
      goto L1623;
    }
  goto ret0;

 L1623: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (memory_operand (x2, QImode))
    {
      operands[2] = x2;
      goto L1624;
    }
  goto ret0;

 L1624: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 2);
  if (register_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L1625;
    }
  goto ret0;

 L1625: ATTRIBUTE_UNUSED_LABEL
  if (
#line 2955 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_MIPS16 && mips_mem_fits_mode_p (SImode, operands[1])))
    {
      return 184;  /* mov_lwr */
    }
  goto ret0;

 L2579: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L2580;
    }
  goto ret0;

 L2580: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (immediate_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L2581;
    }
  goto ret0;

 L2581: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 2);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 79
      && (
#line 5000 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_ABICALLS) && 
#line 406 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(Pmode == SImode)))
    {
      return 347;  /* load_callsi */
    }
  goto ret0;

 L4766: ATTRIBUTE_UNUSED_LABEL
  switch (XINT (x1, 1))
    {
    case 307L:
      goto L3266;
    case 313L:
      goto L3323;
    case 314L:
      goto L3328;
    case 346L:
      goto L3711;
    default:
      break;
    }
  goto ret0;

 L3266: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V4QImode))
    {
      operands[1] = x2;
      goto L3267;
    }
  goto ret0;

 L3267: ATTRIBUTE_UNUSED_LABEL
  if (
#line 134 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP))
    {
      return 427;  /* mips_raddu_w_qb */
    }
  goto ret0;

 L3323: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V2HImode))
    {
      operands[1] = x2;
      goto L3324;
    }
  goto ret0;

 L3324: ATTRIBUTE_UNUSED_LABEL
  if (
#line 207 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP))
    {
      return 434;  /* mips_preceq_w_phl */
    }
  goto ret0;

 L3328: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V2HImode))
    {
      operands[1] = x2;
      goto L3329;
    }
  goto ret0;

 L3329: ATTRIBUTE_UNUSED_LABEL
  if (
#line 216 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP))
    {
      return 435;  /* mips_preceq_w_phr */
    }
  goto ret0;

 L3711: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L3712;
    }
  goto ret0;

 L3712: ATTRIBUTE_UNUSED_LABEL
  if (
#line 666 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP))
    {
      return 470;  /* mips_bitrev */
    }
  goto ret0;

 L4771: ATTRIBUTE_UNUSED_LABEL
  if (XINT (x1, 1) == 347)
    goto L3716;
  goto ret0;

 L3716: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L3717;
    }
  goto ret0;

 L3717: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L3718;
    }
  goto ret0;

 L3718: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 2);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 183)
    goto L3719;
  goto ret0;

 L3719: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 3);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 182
      && 
#line 679 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP))
    {
      return 471;  /* mips_insv */
    }
  goto ret0;

 L4775: ATTRIBUTE_UNUSED_LABEL
  if (XINT (x1, 1) == 367)
    goto L3929;
  goto ret0;

 L3929: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (const_uimm6_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L3930;
    }
  goto ret0;

 L3930: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 182)
    goto L3931;
  goto ret0;

 L3931: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 2);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 183)
    goto L3932;
  goto ret0;

 L3932: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 3);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 184)
    goto L3933;
  goto ret0;

 L3933: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 4);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 185)
    goto L3934;
  goto ret0;

 L3934: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 5);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 186)
    goto L3935;
  goto ret0;

 L3935: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 6);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 187
      && 
#line 1004 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP))
    {
      return 495;  /* mips_rddsp */
    }
  goto ret0;

 L1676: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode)
    goto L4776;
  goto ret0;

 L4776: ATTRIBUTE_UNUSED_LABEL
  if (global_got_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L1677;
    }
 L4777: ATTRIBUTE_UNUSED_LABEL
  if (local_got_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L1707;
    }
  goto ret0;

 L1677: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 3073 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_EXPLICIT_RELOCS && TARGET_XGOT) && 
#line 406 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(Pmode == SImode)))
    {
      return 192;  /* *xgot_hisi */
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  goto L4777;

 L1707: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 3120 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_EXPLICIT_RELOCS) && 
#line 406 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(Pmode == SImode)))
    {
      return 198;  /* *got_pagesi */
    }
  goto ret0;

 L1686: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L1687;
    }
  goto ret0;

 L1687: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (global_got_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L1688;
    }
 L1729: ATTRIBUTE_UNUSED_LABEL
  if (immediate_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L1730;
    }
  goto ret0;

 L1688: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 3089 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_EXPLICIT_RELOCS && TARGET_XGOT) && 
#line 406 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(Pmode == SImode)))
    {
      return 194;  /* *xgot_losi */
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L1729;

 L1730: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 3155 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_MIPS16) && 
#line 406 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(Pmode == SImode)))
    {
      return 202;  /* *lowsi */
    }
 L1742: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 3164 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_MIPS16) && 
#line 406 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(Pmode == SImode)))
    {
      return 204;  /* *lowsi_mips16 */
    }
  goto ret0;

 L1966: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L1967;
    }
  goto ret0;

 L1967: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (arith_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L1968;
    }
  goto ret0;

 L1968: ATTRIBUTE_UNUSED_LABEL
  if (
#line 4038 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_MIPS16))
    {
      return 249;  /* *ashlsi3 */
    }
 L2025: ATTRIBUTE_UNUSED_LABEL
  if (
#line 4068 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_MIPS16))
    {
      return 258;  /* *ashlsi3_mips16 */
    }
  goto ret0;

 L1972: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L1973;
    }
  goto ret0;

 L1973: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (arith_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L1974;
    }
  goto ret0;

 L1974: ATTRIBUTE_UNUSED_LABEL
  if (
#line 4038 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_MIPS16))
    {
      return 250;  /* *ashrsi3 */
    }
 L2031: ATTRIBUTE_UNUSED_LABEL
  if (
#line 4068 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_MIPS16))
    {
      return 259;  /* *ashrsi3_mips16 */
    }
  goto ret0;

 L1978: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode)
    goto L4778;
  goto ret0;

 L4778: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L1979;
    }
 L4779: ATTRIBUTE_UNUSED_LABEL
  if (memory_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L2060;
    }
  goto ret0;

 L1979: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (arith_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L1980;
    }
  x2 = XEXP (x1, 0);
  goto L4779;

 L1980: ATTRIBUTE_UNUSED_LABEL
  if (
#line 4038 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_MIPS16))
    {
      return 251;  /* *lshrsi3 */
    }
 L2037: ATTRIBUTE_UNUSED_LABEL
  if (
#line 4068 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_MIPS16))
    {
      return 260;  /* *lshrsi3_mips16 */
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  goto L4779;

 L2060: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (immediate_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L2061;
    }
  goto ret0;

 L2061: ATTRIBUTE_UNUSED_LABEL
  if (
#line 4171 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_MIPS16))
    {
      return 264;  /* *mips.md:4167 */
    }
  goto ret0;

 L2065: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L2066;
    }
  goto ret0;

 L2066: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (arith_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L2067;
    }
  goto ret0;

 L2067: ATTRIBUTE_UNUSED_LABEL
  if (
#line 4185 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_ROTR_SI))
    {
      return 265;  /* rotrsi3 */
    }
  goto ret0;

 L2190: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L2191;
    }
  goto ret0;

 L2191: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT)
    goto L4780;
  goto ret0;

 L4780: ATTRIBUTE_UNUSED_LABEL
  if (XWINT (x2, 0) == 0L)
    goto L4782;
  goto ret0;

 L4782: ATTRIBUTE_UNUSED_LABEL
  if (
#line 4434 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_MIPS16))
    {
      return 279;  /* *seq_si */
    }
 L4783: ATTRIBUTE_UNUSED_LABEL
  if (
#line 4443 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_MIPS16))
    {
      return 281;  /* *seq_si_mips16 */
    }
  goto ret0;

 L2210: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L2211;
    }
  goto ret0;

 L2211: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (0)]
      && 
#line 4462 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_MIPS16))
    {
      return 283;  /* *sne_si */
    }
  goto ret0;

 L2220: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L2221;
    }
  goto ret0;

 L2221: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (reg_or_0_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L2222;
    }
 L2233: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L2234;
    }
  goto ret0;

 L2222: ATTRIBUTE_UNUSED_LABEL
  if (
#line 4478 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_MIPS16))
    {
      return 285;  /* *sgt_si */
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L2233;

 L2234: ATTRIBUTE_UNUSED_LABEL
  if (
#line 4487 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_MIPS16))
    {
      return 287;  /* *sgt_si_mips16 */
    }
  goto ret0;

 L2244: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L2245;
    }
  goto ret0;

 L2245: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (1)]
      && 
#line 4503 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_MIPS16))
    {
      return 289;  /* *sge_si */
    }
  goto ret0;

 L2254: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L2255;
    }
  goto ret0;

 L2255: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (arith_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L2256;
    }
  goto ret0;

 L2256: ATTRIBUTE_UNUSED_LABEL
  if (
#line 4519 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_MIPS16))
    {
      return 291;  /* *slt_si */
    }
 L2268: ATTRIBUTE_UNUSED_LABEL
  if (
#line 4528 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_MIPS16))
    {
      return 293;  /* *slt_si_mips16 */
    }
  goto ret0;

 L2278: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L2279;
    }
  goto ret0;

 L2279: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (sle_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L2280;
    }
  goto ret0;

 L2280: ATTRIBUTE_UNUSED_LABEL
  if (
#line 4549 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_MIPS16))
    {
      return 295;  /* *sle_si */
    }
 L2292: ATTRIBUTE_UNUSED_LABEL
  if (
#line 4561 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_MIPS16))
    {
      return 297;  /* *sle_si_mips16 */
    }
  goto ret0;

 L2302: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L2303;
    }
  goto ret0;

 L2303: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (reg_or_0_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L2304;
    }
 L2315: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L2316;
    }
  goto ret0;

 L2304: ATTRIBUTE_UNUSED_LABEL
  if (
#line 4583 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_MIPS16))
    {
      return 299;  /* *sgtu_si */
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L2315;

 L2316: ATTRIBUTE_UNUSED_LABEL
  if (
#line 4592 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_MIPS16))
    {
      return 301;  /* *sgtu_si_mips16 */
    }
  goto ret0;

 L2326: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L2327;
    }
  goto ret0;

 L2327: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (1)]
      && 
#line 4608 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_MIPS16))
    {
      return 303;  /* *sge_si */
    }
  goto ret0;

 L2336: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L2337;
    }
  goto ret0;

 L2337: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (arith_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L2338;
    }
  goto ret0;

 L2338: ATTRIBUTE_UNUSED_LABEL
  if (
#line 4624 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_MIPS16))
    {
      return 305;  /* *sltu_si */
    }
 L2350: ATTRIBUTE_UNUSED_LABEL
  if (
#line 4633 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_MIPS16))
    {
      return 307;  /* *sltu_si_mips16 */
    }
  goto ret0;

 L2360: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L2361;
    }
  goto ret0;

 L2361: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (sleu_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L2362;
    }
  goto ret0;

 L2362: ATTRIBUTE_UNUSED_LABEL
  if (
#line 4654 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_MIPS16))
    {
      return 309;  /* *sleu_si */
    }
 L2374: ATTRIBUTE_UNUSED_LABEL
  if (
#line 4666 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_MIPS16))
    {
      return 311;  /* *sleu_si_mips16 */
    }
  goto ret0;

 L2755: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L4784;
    case DImode:
      goto L4785;
    case CCmode:
      goto L4786;
    default:
      break;
    }
  goto ret0;

 L4784: ATTRIBUTE_UNUSED_LABEL
  if (equality_operator (x2, SImode))
    {
      operands[4] = x2;
      goto L2756;
    }
  goto ret0;

 L2756: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L2757;
    }
  goto ret0;

 L2757: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L2758;
  goto ret0;

 L2758: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (reg_or_0_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L2759;
    }
  goto ret0;

 L2759: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (reg_or_0_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L2760;
    }
  goto ret0;

 L2760: ATTRIBUTE_UNUSED_LABEL
  if (
#line 5309 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_CONDMOVE))
    {
      return 363;  /* *movsi_on_si */
    }
  goto ret0;

 L4785: ATTRIBUTE_UNUSED_LABEL
  if (equality_operator (x2, DImode))
    {
      operands[4] = x2;
      goto L2774;
    }
  goto ret0;

 L2774: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L2775;
    }
  goto ret0;

 L2775: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L2776;
  goto ret0;

 L2776: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (reg_or_0_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L2777;
    }
  goto ret0;

 L2777: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (reg_or_0_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L2778;
    }
  goto ret0;

 L2778: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 5309 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_CONDMOVE) && 
#line 410 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT)))
    {
      return 365;  /* *movsi_on_di */
    }
  goto ret0;

 L4786: ATTRIBUTE_UNUSED_LABEL
  if (equality_operator (x2, CCmode))
    {
      operands[4] = x2;
      goto L2792;
    }
  goto ret0;

 L2792: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, CCmode))
    {
      operands[1] = x3;
      goto L2793;
    }
  goto ret0;

 L2793: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L2794;
  goto ret0;

 L2794: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (reg_or_0_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L2795;
    }
  goto ret0;

 L2795: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (reg_or_0_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L2796;
    }
  goto ret0;

 L2796: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 5309 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_CONDMOVE) && 
#line 410 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT)))
    {
      return 367;  /* *movsi_on_cc */
    }
  goto ret0;

 L1698: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 3103 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_EXPLICIT_RELOCS && !TARGET_XGOT) && 
#line 406 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(Pmode == SImode)))
    {
      return 196;  /* *got_dispsi */
    }
  goto ret0;
 ret0:
  return -1;
}

static int
recog_5 (rtx x0 ATTRIBUTE_UNUSED,
	rtx insn ATTRIBUTE_UNUSED,
	int *pnum_clobbers ATTRIBUTE_UNUSED)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x1 ATTRIBUTE_UNUSED;
  rtx x2 ATTRIBUTE_UNUSED;
  rtx x3 ATTRIBUTE_UNUSED;
  rtx x4 ATTRIBUTE_UNUSED;
  rtx x5 ATTRIBUTE_UNUSED;
  rtx x6 ATTRIBUTE_UNUSED;
  rtx x7 ATTRIBUTE_UNUSED;
  int tem ATTRIBUTE_UNUSED;

  x1 = XEXP (x0, 1);
  switch (GET_CODE (x1))
    {
    case PLUS:
      goto L64;
    case SIGN_EXTEND:
      goto L82;
    case MINUS:
      goto L119;
    case MULT:
      goto L190;
    case NEG:
      goto L588;
    case TRUNCATE:
      goto L796;
    case CLZ:
      goto L1178;
    case NOT:
      goto L1211;
    case AND:
      goto L1222;
    case IOR:
      goto L1246;
    case XOR:
      goto L1270;
    case ZERO_EXTEND:
      goto L1367;
    case FIX:
      goto L1552;
    case ZERO_EXTRACT:
      goto L1589;
    case UNSPEC:
      goto L4834;
    case HIGH:
      goto L1660;
    case LO_SUM:
      goto L1692;
    case ASHIFT:
      goto L1984;
    case ASHIFTRT:
      goto L1990;
    case LSHIFTRT:
      goto L1996;
    case ROTATERT:
      goto L2071;
    case EQ:
      goto L2195;
    case NE:
      goto L2215;
    case GT:
      goto L2226;
    case GE:
      goto L2249;
    case LT:
      goto L2260;
    case LE:
      goto L2284;
    case GTU:
      goto L2308;
    case GEU:
      goto L2331;
    case LTU:
      goto L2342;
    case LEU:
      goto L2366;
    case IF_THEN_ELSE:
      goto L2764;
    case CONST:
    case LABEL_REF:
    case SYMBOL_REF:
      goto L4808;
    default:
      goto L4810;
   }
 L4808: ATTRIBUTE_UNUSED_LABEL
  if (general_symbolic_operand (x1, DImode))
    {
      operands[1] = x1;
      goto L1672;
    }
 L4810: ATTRIBUTE_UNUSED_LABEL
  if (global_got_operand (x1, DImode))
    {
      operands[1] = x1;
      goto L1702;
    }
  goto ret0;

 L64: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == DImode)
    goto L4844;
  goto ret0;

 L4844: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case REG:
      goto L4847;
    case MULT:
      goto L849;
    default:
     break;
   }
 L4845: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L77;
    }
  goto ret0;

 L4847: ATTRIBUTE_UNUSED_LABEL
  if (XINT (x2, 0) == 29)
    goto L65;
  goto L4845;

 L65: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const_arith_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L66;
    }
  x2 = XEXP (x1, 0);
  goto L4845;

 L66: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 692 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_MIPS16) && 
#line 402 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT)))
    {
      return 11;  /* *adddi3_sp2 */
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  goto L4845;

 L849: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DImode)
    goto L4848;
  goto ret0;

 L4848: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x3))
    {
    case SIGN_EXTEND:
      goto L850;
    case ZERO_EXTEND:
      goto L860;
    default:
     break;
   }
  goto ret0;

 L850: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L851;
    }
  goto ret0;

 L851: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == DImode
      && GET_CODE (x3) == SIGN_EXTEND)
    goto L852;
  goto ret0;

 L852: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L853;
    }
  goto ret0;

 L853: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, DImode))
    {
      operands[3] = x2;
      goto L854;
    }
  goto ret0;

 L854: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1721 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
((TARGET_MAD || ISA_HAS_MACC)
   && !TARGET_64BIT))
    {
      return 62;  /* *smul_acc_di */
    }
  goto ret0;

 L860: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L861;
    }
  goto ret0;

 L861: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == DImode
      && GET_CODE (x3) == ZERO_EXTEND)
    goto L862;
  goto ret0;

 L862: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L863;
    }
  goto ret0;

 L863: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, DImode))
    {
      operands[3] = x2;
      goto L864;
    }
  goto ret0;

 L864: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1721 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
((TARGET_MAD || ISA_HAS_MACC)
   && !TARGET_64BIT))
    {
      return 63;  /* *umul_acc_di */
    }
  goto ret0;

 L77: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (arith_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L78;
    }
  goto ret0;

 L78: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 704 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_MIPS16) && 
#line 402 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT)))
    {
      return 13;  /* *adddi3_mips16 */
    }
  goto ret0;

 L82: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L4850;
    case QImode:
      goto L4853;
    case HImode:
      goto L4854;
    default:
      break;
    }
  goto ret0;

 L4850: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case PLUS:
      goto L83;
    case MINUS:
      goto L126;
    case ASHIFT:
      goto L2003;
    case ASHIFTRT:
      goto L2010;
    case LSHIFTRT:
      goto L2017;
    case REG:
    case SUBREG:
    case MEM:
      goto L4852;
    default:
      goto ret0;
   }
 L4852: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L1443;
    }
  goto ret0;

 L83: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L84;
    }
  goto ret0;

 L84: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (arith_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L85;
    }
  goto ret0;

 L85: ATTRIBUTE_UNUSED_LABEL
  if (
#line 854 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT && !TARGET_MIPS16))
    {
      return 14;  /* *addsi3_extended */
    }
 L92: ATTRIBUTE_UNUSED_LABEL
  if (
#line 868 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT && TARGET_MIPS16))
    {
      return 15;  /* *addsi3_extended_mips16 */
    }
  goto ret0;

 L126: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L127;
    }
  goto ret0;

 L127: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L128;
    }
  goto ret0;

 L128: ATTRIBUTE_UNUSED_LABEL
  if (
#line 908 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT))
    {
      return 21;  /* *subsi3_extended */
    }
  goto ret0;

 L2003: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L2004;
    }
  goto ret0;

 L2004: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (arith_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L2005;
    }
  goto ret0;

 L2005: ATTRIBUTE_UNUSED_LABEL
  if (
#line 4054 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT && !TARGET_MIPS16))
    {
      return 255;  /* *ashlsi3_extend */
    }
  goto ret0;

 L2010: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L2011;
    }
  goto ret0;

 L2011: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (arith_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L2012;
    }
  goto ret0;

 L2012: ATTRIBUTE_UNUSED_LABEL
  if (
#line 4054 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT && !TARGET_MIPS16))
    {
      return 256;  /* *ashrsi3_extend */
    }
  goto ret0;

 L2017: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L2018;
    }
  goto ret0;

 L2018: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (arith_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L2019;
    }
  goto ret0;

 L2019: ATTRIBUTE_UNUSED_LABEL
  if (
#line 4054 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT && !TARGET_MIPS16))
    {
      return 257;  /* *lshrsi3_extend */
    }
  goto ret0;

 L1443: ATTRIBUTE_UNUSED_LABEL
  if (
#line 2430 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT))
    {
      return 153;  /* extendsidi2 */
    }
  goto ret0;

 L4853: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, QImode))
    {
      operands[1] = x2;
      goto L1453;
    }
  goto ret0;

 L1453: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 2451 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(GENERATE_MIPS16E) && 
#line 402 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT)))
    {
      return 155;  /* *extendqidi2_mips16e */
    }
 L1473: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 2462 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!ISA_HAS_SEB_SEH && !GENERATE_MIPS16E) && 
#line 402 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT)))
    {
      return 159;  /* *extendqidi2 */
    }
 L1493: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 2482 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_SEB_SEH) && 
#line 402 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT)))
    {
      return 163;  /* *extendqidi2_seb */
    }
  goto ret0;

 L4854: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, HImode))
    {
      operands[1] = x2;
      goto L1463;
    }
  goto ret0;

 L1463: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 2451 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(GENERATE_MIPS16E) && 
#line 402 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT)))
    {
      return 157;  /* *extendhidi2_mips16e */
    }
 L1483: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 2462 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!ISA_HAS_SEB_SEH && !GENERATE_MIPS16E) && 
#line 402 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT)))
    {
      return 161;  /* *extendhidi2 */
    }
 L1503: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 2482 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_SEB_SEH) && 
#line 402 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT)))
    {
      return 165;  /* *extendhidi2_seh */
    }
  goto ret0;

 L119: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == DImode)
    goto L4858;
  goto ret0;

 L4858: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L120;
    }
 L4859: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DImode))
    {
      operands[3] = x2;
      goto L607;
    }
  goto ret0;

 L120: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L121;
    }
  x2 = XEXP (x1, 0);
  goto L4859;

 L121: ATTRIBUTE_UNUSED_LABEL
  if (
#line 402 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT))
    {
      return 20;  /* subdi3 */
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  goto L4859;

 L607: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == MULT)
    goto L608;
  goto ret0;

 L608: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DImode)
    goto L4860;
  goto ret0;

 L4860: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x3))
    {
    case SIGN_EXTEND:
      goto L609;
    case ZERO_EXTEND:
      goto L619;
    default:
     break;
   }
  goto ret0;

 L609: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L610;
    }
  goto ret0;

 L610: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == DImode
      && GET_CODE (x3) == SIGN_EXTEND)
    goto L611;
  goto ret0;

 L611: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L612;
    }
  goto ret0;

 L612: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1604 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_64BIT && ISA_HAS_MSAC))
    {
      return 51;  /* *msac_di */
    }
  goto ret0;

 L619: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L620;
    }
  goto ret0;

 L620: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == DImode
      && GET_CODE (x3) == ZERO_EXTEND)
    goto L621;
  goto ret0;

 L621: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L622;
    }
  goto ret0;

 L622: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1604 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_64BIT && ISA_HAS_MSAC))
    {
      return 52;  /* *msacu_di */
    }
  goto ret0;

 L190: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == DImode)
    goto L4863;
  goto ret0;

 L4863: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case SIGN_EXTEND:
      goto L457;
    case ZERO_EXTEND:
      goto L465;
    case REG:
    case SUBREG:
      goto L4862;
    default:
      goto ret0;
   }
 L4862: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L191;
    }
  goto ret0;

 L457: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L458;
    }
  goto ret0;

 L458: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == SIGN_EXTEND)
    goto L459;
  goto ret0;

 L459: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L460;
    }
  goto ret0;

 L460: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1507 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_64BIT && !TARGET_FIX_R4000))
    {
      return 41;  /* mulsidi3_32bit_internal */
    }
 L487: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1517 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_64BIT && TARGET_FIX_R4000)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 43;  /* mulsidi3_32bit_r4000 */
    }
 L529: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1530 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT && !TARGET_FIX_R4000)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 3;
      return 45;  /* *mulsidi3_64bit */
    }
  goto ret0;

 L465: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L466;
    }
  goto ret0;

 L466: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == ZERO_EXTEND)
    goto L467;
  goto ret0;

 L467: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L468;
    }
  goto ret0;

 L468: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1507 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_64BIT && !TARGET_FIX_R4000))
    {
      return 42;  /* umulsidi3_32bit_internal */
    }
 L506: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1517 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_64BIT && TARGET_FIX_R4000)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 44;  /* umulsidi3_32bit_r4000 */
    }
 L552: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1530 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT && !TARGET_FIX_R4000)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 3;
      return 46;  /* *umulsidi3_64bit */
    }
  goto ret0;

 L191: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L192;
    }
  goto ret0;

 L192: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1052 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT && GENERATE_MULT3_DI)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 2;
      return 28;  /* muldi3_mult3 */
    }
 L222: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 1088 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_FIX_R4000) && 
#line 402 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 30;  /* muldi3_internal */
    }
 L256: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 1099 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_FIX_R4000) && 
#line 402 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 2;
      return 32;  /* muldi3_r4000 */
    }
  goto ret0;

 L588: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == DImode)
    goto L4865;
  goto ret0;

 L4865: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == MULT)
    goto L589;
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L1188;
    }
  goto ret0;

 L589: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DImode)
    goto L4867;
  goto ret0;

 L4867: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x3))
    {
    case SIGN_EXTEND:
      goto L590;
    case ZERO_EXTEND:
      goto L599;
    default:
     break;
   }
  goto ret0;

 L590: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L591;
    }
  goto ret0;

 L591: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == DImode
      && GET_CODE (x3) == SIGN_EXTEND)
    goto L592;
  goto ret0;

 L592: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L593;
    }
  goto ret0;

 L593: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1592 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_64BIT && ISA_HAS_MULS))
    {
      return 49;  /* *muls_di */
    }
  goto ret0;

 L599: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L600;
    }
  goto ret0;

 L600: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == DImode
      && GET_CODE (x3) == ZERO_EXTEND)
    goto L601;
  goto ret0;

 L601: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L602;
    }
  goto ret0;

 L602: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1592 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_64BIT && ISA_HAS_MULS))
    {
      return 50;  /* *mulsu_di */
    }
  goto ret0;

 L1188: ATTRIBUTE_UNUSED_LABEL
  if (
#line 2018 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT && !TARGET_MIPS16))
    {
      return 107;  /* negdi2 */
    }
  goto ret0;

 L796: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == TImode
      && GET_CODE (x2) == LSHIFTRT)
    goto L797;
  goto ret0;

 L797: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == TImode
      && GET_CODE (x3) == MULT)
    goto L798;
  goto ret0;

 L798: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == TImode)
    goto L4869;
  goto ret0;

 L4869: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x4))
    {
    case SIGN_EXTEND:
      goto L799;
    case ZERO_EXTEND:
      goto L823;
    default:
     break;
   }
  goto ret0;

 L799: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (register_operand (x5, DImode))
    {
      operands[1] = x5;
      goto L800;
    }
  goto ret0;

 L800: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_MODE (x4) == TImode
      && GET_CODE (x4) == SIGN_EXTEND)
    goto L801;
  goto ret0;

 L801: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (register_operand (x5, DImode))
    {
      operands[2] = x5;
      goto L802;
    }
  goto ret0;

 L802: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (64)]
      && 
#line 1695 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT && !TARGET_FIX_R4000
   && !(SIGN_EXTEND == ZERO_EXTEND && TARGET_FIX_VR4120))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 59;  /* smuldi3_highpart */
    }
  goto ret0;

 L823: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (register_operand (x5, DImode))
    {
      operands[1] = x5;
      goto L824;
    }
  goto ret0;

 L824: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_MODE (x4) == TImode
      && GET_CODE (x4) == ZERO_EXTEND)
    goto L825;
  goto ret0;

 L825: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (register_operand (x5, DImode))
    {
      operands[2] = x5;
      goto L826;
    }
  goto ret0;

 L826: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (64)]
      && 
#line 1695 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT && !TARGET_FIX_R4000
   && !(ZERO_EXTEND == ZERO_EXTEND && TARGET_FIX_VR4120))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 60;  /* umuldi3_highpart */
    }
  goto ret0;

 L1178: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L1179;
    }
  goto ret0;

 L1179: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 1990 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_CLZ_CLO) && 
#line 402 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT)))
    {
      return 105;  /* clzdi2 */
    }
  goto ret0;

 L1211: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L1212;
    }
  goto ret0;

 L1212: ATTRIBUTE_UNUSED_LABEL
  if (
#line 402 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT))
    {
      return 112;  /* one_cmpldi2 */
    }
  goto ret0;

 L1222: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == DImode)
    goto L4872;
  goto ret0;

 L4872: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == NOT)
    goto L1297;
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L1223;
    }
  goto ret0;

 L1297: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L1298;
    }
  goto ret0;

 L1298: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == NOT)
    goto L1299;
  goto ret0;

 L1299: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L1300;
    }
  goto ret0;

 L1300: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 2155 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_MIPS16) && 
#line 402 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT)))
    {
      return 126;  /* *nordi3 */
    }
  goto ret0;

 L1223: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (uns_arith_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L1224;
    }
 L1235: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L1236;
    }
  goto ret0;

 L1224: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 2069 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_MIPS16) && 
#line 402 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT)))
    {
      return 114;  /* *anddi3 */
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L1235;

 L1236: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 2080 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_MIPS16) && 
#line 402 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT)))
    {
      return 116;  /* *anddi3_mips16 */
    }
  goto ret0;

 L1246: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L1247;
    }
  goto ret0;

 L1247: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (uns_arith_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L1248;
    }
 L1259: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L1260;
    }
  goto ret0;

 L1248: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 2099 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_MIPS16) && 
#line 402 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT)))
    {
      return 118;  /* *iordi3 */
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L1259;

 L1260: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 2110 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_MIPS16) && 
#line 402 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT)))
    {
      return 120;  /* *iordi3_mips16 */
    }
  goto ret0;

 L1270: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L1271;
    }
  goto ret0;

 L1271: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (uns_arith_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L1272;
    }
  goto ret0;

 L1272: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 2126 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_MIPS16) && 
#line 402 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT)))
    {
      return 122;  /* *mips.md:2122 */
    }
 L1284: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 2137 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_MIPS16) && 
#line 402 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT)))
    {
      return 124;  /* *mips.md:2133 */
    }
  goto ret0;

 L1367: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L4873;
    case QImode:
      goto L4874;
    case HImode:
      goto L4875;
    default:
      break;
    }
  goto ret0;

 L4873: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L1368;
    }
  goto ret0;

 L1368: ATTRIBUTE_UNUSED_LABEL
  if (
#line 2321 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT))
    {
      return 138;  /* zero_extendsidi2 */
    }
  goto ret0;

 L4874: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, QImode))
    {
      operands[1] = x2;
      goto L1378;
    }
 L4876: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, QImode))
    {
      operands[1] = x2;
      goto L1398;
    }
 L4878: ATTRIBUTE_UNUSED_LABEL
  if (memory_operand (x2, QImode))
    {
      operands[1] = x2;
      goto L1418;
    }
  goto ret0;

 L1378: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 2355 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_MIPS16) && 
#line 402 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT)))
    {
      return 140;  /* *zero_extendqidi2 */
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  goto L4876;

 L1398: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 2365 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(GENERATE_MIPS16E) && 
#line 402 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT)))
    {
      return 144;  /* *zero_extendqidi2_mips16e */
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  goto L4878;

 L1418: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 2373 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_MIPS16) && 
#line 402 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT)))
    {
      return 148;  /* *zero_extendqidi2_mips16 */
    }
  goto ret0;

 L4875: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, HImode))
    {
      operands[1] = x2;
      goto L1388;
    }
 L4877: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, HImode))
    {
      operands[1] = x2;
      goto L1408;
    }
 L4879: ATTRIBUTE_UNUSED_LABEL
  if (memory_operand (x2, HImode))
    {
      operands[1] = x2;
      goto L1428;
    }
  goto ret0;

 L1388: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 2355 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_MIPS16) && 
#line 402 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT)))
    {
      return 142;  /* *zero_extendhidi2 */
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  goto L4877;

 L1408: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 2365 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(GENERATE_MIPS16E) && 
#line 402 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT)))
    {
      return 146;  /* *zero_extendhidi2_mips16e */
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  goto L4879;

 L1428: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 2373 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_MIPS16) && 
#line 402 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT)))
    {
      return 150;  /* *zero_extendhidi2_mips16 */
    }
  goto ret0;

 L1552: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case DFmode:
      goto L4880;
    case SFmode:
      goto L4881;
    default:
      break;
    }
  goto ret0;

 L4880: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DFmode))
    {
      operands[1] = x2;
      goto L1553;
    }
  goto ret0;

 L1553: ATTRIBUTE_UNUSED_LABEL
  if (
#line 2599 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_FLOAT64 && TARGET_DOUBLE_FLOAT))
    {
      return 172;  /* fix_truncdfdi2 */
    }
  goto ret0;

 L4881: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SFmode))
    {
      operands[1] = x2;
      goto L1558;
    }
  goto ret0;

 L1558: ATTRIBUTE_UNUSED_LABEL
  if (
#line 2610 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_FLOAT64 && TARGET_DOUBLE_FLOAT))
    {
      return 173;  /* fix_truncsfdi2 */
    }
  goto ret0;

 L1589: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L1590;
    }
  goto ret0;

 L1590: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (immediate_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L1591;
    }
  goto ret0;

 L1591: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (immediate_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L1592;
    }
  goto ret0;

 L1592: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 2886 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(mips_use_ins_ext_p (operands[1], operands[2], operands[3])) && 
#line 402 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT)))
    {
      return 179;  /* extzvdi */
    }
  goto ret0;

 L4834: ATTRIBUTE_UNUSED_LABEL
  switch (XVECLEN (x1, 0))
    {
    case 2:
      goto L4882;
    case 3:
      goto L4883;
    default:
      break;
    }
  goto ret0;

 L4882: ATTRIBUTE_UNUSED_LABEL
  switch (XINT (x1, 1))
    {
    case 18L:
      goto L1616;
    case 24L:
      goto L1722;
    case 26L:
      goto L1924;
    case 364L:
      goto L3879;
    default:
      break;
    }
  goto ret0;

 L1616: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (memory_operand (x2, BLKmode))
    {
      operands[1] = x2;
      goto L1617;
    }
  goto ret0;

 L1617: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (memory_operand (x2, QImode))
    {
      operands[2] = x2;
      goto L1618;
    }
  goto ret0;

 L1618: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 2944 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_MIPS16 && mips_mem_fits_mode_p (DImode, operands[1])) && 
#line 402 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT)))
    {
      return 183;  /* mov_ldl */
    }
  goto ret0;

 L1722: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L1723;
    }
  goto ret0;

 L1723: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (immediate_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L1724;
    }
  goto ret0;

 L1724: ATTRIBUTE_UNUSED_LABEL
  if (
#line 406 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(Pmode == DImode))
    {
      return 201;  /* load_gotdi */
    }
  goto ret0;

 L1924: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L1925;
    }
  goto ret0;

 L1925: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L1926;
    }
  goto ret0;

 L1926: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 3864 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!ISA_HAS_MACCHI) && 
#line 402 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT)))
    {
      return 240;  /* *mfhilo_di */
    }
 L1938: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 3874 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_MACCHI) && 
#line 402 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT)))
    {
      return 242;  /* *mfhilo_di_macc */
    }
  goto ret0;

 L3879: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L3880;
    }
  goto ret0;

 L3880: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (arith_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L3881;
    }
  goto ret0;

 L3881: ATTRIBUTE_UNUSED_LABEL
  if (
#line 942 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP && !TARGET_64BIT))
    {
      return 492;  /* mips_shilo */
    }
  goto ret0;

 L4883: ATTRIBUTE_UNUSED_LABEL
  switch (XINT (x1, 1))
    {
    case 19L:
      goto L1629;
    case 23L:
      goto L2585;
    case 333L:
      goto L3566;
    case 334L:
      goto L3573;
    case 335L:
      goto L3580;
    case 336L:
      goto L3587;
    default:
      break;
    }
  goto ret0;

 L1629: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (memory_operand (x2, BLKmode))
    {
      operands[1] = x2;
      goto L1630;
    }
  goto ret0;

 L1630: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (memory_operand (x2, QImode))
    {
      operands[2] = x2;
      goto L1631;
    }
  goto ret0;

 L1631: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 2);
  if (register_operand (x2, DImode))
    {
      operands[3] = x2;
      goto L1632;
    }
  goto ret0;

 L1632: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 2955 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_MIPS16 && mips_mem_fits_mode_p (DImode, operands[1])) && 
#line 402 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT)))
    {
      return 185;  /* mov_ldr */
    }
  goto ret0;

 L2585: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L2586;
    }
  goto ret0;

 L2586: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (immediate_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L2587;
    }
  goto ret0;

 L2587: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 2);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 79
      && (
#line 5000 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_ABICALLS) && 
#line 406 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(Pmode == DImode)))
    {
      return 348;  /* load_calldi */
    }
  goto ret0;

 L3566: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L3567;
    }
  goto ret0;

 L3567: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V4QImode))
    {
      operands[2] = x2;
      goto L3568;
    }
  goto ret0;

 L3568: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 2);
  if (register_operand (x2, V4QImode))
    {
      operands[3] = x2;
      goto L3569;
    }
  goto ret0;

 L3569: ATTRIBUTE_UNUSED_LABEL
  if (
#line 479 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP && !TARGET_64BIT))
    {
      return 457;  /* mips_dpau_h_qbl */
    }
  goto ret0;

 L3573: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L3574;
    }
  goto ret0;

 L3574: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V4QImode))
    {
      operands[2] = x2;
      goto L3575;
    }
  goto ret0;

 L3575: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 2);
  if (register_operand (x2, V4QImode))
    {
      operands[3] = x2;
      goto L3576;
    }
  goto ret0;

 L3576: ATTRIBUTE_UNUSED_LABEL
  if (
#line 490 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP && !TARGET_64BIT))
    {
      return 458;  /* mips_dpau_h_qbr */
    }
  goto ret0;

 L3580: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L3581;
    }
  goto ret0;

 L3581: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V4QImode))
    {
      operands[2] = x2;
      goto L3582;
    }
  goto ret0;

 L3582: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 2);
  if (register_operand (x2, V4QImode))
    {
      operands[3] = x2;
      goto L3583;
    }
  goto ret0;

 L3583: ATTRIBUTE_UNUSED_LABEL
  if (
#line 502 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP && !TARGET_64BIT))
    {
      return 459;  /* mips_dpsu_h_qbl */
    }
  goto ret0;

 L3587: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L3588;
    }
  goto ret0;

 L3588: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V4QImode))
    {
      operands[2] = x2;
      goto L3589;
    }
  goto ret0;

 L3589: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 2);
  if (register_operand (x2, V4QImode))
    {
      operands[3] = x2;
      goto L3590;
    }
  goto ret0;

 L3590: ATTRIBUTE_UNUSED_LABEL
  if (
#line 513 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP && !TARGET_64BIT))
    {
      return 460;  /* mips_dpsu_h_qbr */
    }
  goto ret0;

 L1660: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == DImode)
    goto L4892;
  goto ret0;

 L4892: ATTRIBUTE_UNUSED_LABEL
  if (general_symbolic_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L1661;
    }
 L4893: ATTRIBUTE_UNUSED_LABEL
  if (global_got_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L1682;
    }
 L4894: ATTRIBUTE_UNUSED_LABEL
  if (local_got_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L1712;
    }
  goto ret0;

 L1661: ATTRIBUTE_UNUSED_LABEL
  if (
#line 2999 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_EXPLICIT_RELOCS && ABI_HAS_64BIT_SYMBOLS))
    {
      return 190;  /* *lea_high64 */
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  goto L4893;

 L1682: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 3073 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_EXPLICIT_RELOCS && TARGET_XGOT) && 
#line 406 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(Pmode == DImode)))
    {
      return 193;  /* *xgot_hidi */
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  goto L4894;

 L1712: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 3120 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_EXPLICIT_RELOCS) && 
#line 406 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(Pmode == DImode)))
    {
      return 199;  /* *got_pagedi */
    }
  goto ret0;

 L1692: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L1693;
    }
  goto ret0;

 L1693: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (global_got_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L1694;
    }
 L1735: ATTRIBUTE_UNUSED_LABEL
  if (immediate_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L1736;
    }
  goto ret0;

 L1694: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 3089 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_EXPLICIT_RELOCS && TARGET_XGOT) && 
#line 406 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(Pmode == DImode)))
    {
      return 195;  /* *xgot_lodi */
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L1735;

 L1736: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 3155 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_MIPS16) && 
#line 406 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(Pmode == DImode)))
    {
      return 203;  /* *lowdi */
    }
 L1748: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 3164 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_MIPS16) && 
#line 406 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(Pmode == DImode)))
    {
      return 205;  /* *lowdi_mips16 */
    }
  goto ret0;

 L1984: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L1985;
    }
  goto ret0;

 L1985: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (arith_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L1986;
    }
  goto ret0;

 L1986: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 4038 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_MIPS16) && 
#line 402 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT)))
    {
      return 252;  /* *ashldi3 */
    }
 L2043: ATTRIBUTE_UNUSED_LABEL
  if (
#line 4090 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT && TARGET_MIPS16))
    {
      return 261;  /* *ashldi3_mips16 */
    }
  goto ret0;

 L1990: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L1991;
    }
  goto ret0;

 L1991: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (arith_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L1992;
    }
  goto ret0;

 L1992: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 4038 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_MIPS16) && 
#line 402 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT)))
    {
      return 253;  /* *ashrdi3 */
    }
 L2049: ATTRIBUTE_UNUSED_LABEL
  if (
#line 4110 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT && TARGET_MIPS16))
    {
      return 262;  /* *ashrdi3_mips16 */
    }
  goto ret0;

 L1996: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L1997;
    }
  goto ret0;

 L1997: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (arith_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L1998;
    }
  goto ret0;

 L1998: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 4038 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_MIPS16) && 
#line 402 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT)))
    {
      return 254;  /* *lshrdi3 */
    }
 L2055: ATTRIBUTE_UNUSED_LABEL
  if (
#line 4129 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT && TARGET_MIPS16))
    {
      return 263;  /* *lshrdi3_mips16 */
    }
  goto ret0;

 L2071: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L2072;
    }
  goto ret0;

 L2072: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (arith_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L2073;
    }
  goto ret0;

 L2073: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 4185 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_ROTR_DI) && 
#line 402 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT)))
    {
      return 266;  /* rotrdi3 */
    }
  goto ret0;

 L2195: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L2196;
    }
  goto ret0;

 L2196: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT)
    goto L4895;
  goto ret0;

 L4895: ATTRIBUTE_UNUSED_LABEL
  if (XWINT (x2, 0) == 0L)
    goto L4897;
  goto ret0;

 L4897: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 4434 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_MIPS16) && 
#line 402 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT)))
    {
      return 280;  /* *seq_di */
    }
 L4898: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 4443 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_MIPS16) && 
#line 402 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT)))
    {
      return 282;  /* *seq_di_mips16 */
    }
  goto ret0;

 L2215: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L2216;
    }
  goto ret0;

 L2216: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (0)]
      && (
#line 4462 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_MIPS16) && 
#line 402 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT)))
    {
      return 284;  /* *sne_di */
    }
  goto ret0;

 L2226: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L2227;
    }
  goto ret0;

 L2227: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (reg_or_0_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L2228;
    }
 L2239: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L2240;
    }
  goto ret0;

 L2228: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 4478 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_MIPS16) && 
#line 402 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT)))
    {
      return 286;  /* *sgt_di */
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L2239;

 L2240: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 4487 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_MIPS16) && 
#line 402 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT)))
    {
      return 288;  /* *sgt_di_mips16 */
    }
  goto ret0;

 L2249: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L2250;
    }
  goto ret0;

 L2250: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (1)]
      && (
#line 4503 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_MIPS16) && 
#line 402 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT)))
    {
      return 290;  /* *sge_di */
    }
  goto ret0;

 L2260: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L2261;
    }
  goto ret0;

 L2261: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (arith_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L2262;
    }
  goto ret0;

 L2262: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 4519 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_MIPS16) && 
#line 402 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT)))
    {
      return 292;  /* *slt_di */
    }
 L2274: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 4528 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_MIPS16) && 
#line 402 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT)))
    {
      return 294;  /* *slt_di_mips16 */
    }
  goto ret0;

 L2284: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L2285;
    }
  goto ret0;

 L2285: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (sle_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L2286;
    }
  goto ret0;

 L2286: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 4549 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_MIPS16) && 
#line 402 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT)))
    {
      return 296;  /* *sle_di */
    }
 L2298: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 4561 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_MIPS16) && 
#line 402 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT)))
    {
      return 298;  /* *sle_di_mips16 */
    }
  goto ret0;

 L2308: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L2309;
    }
  goto ret0;

 L2309: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (reg_or_0_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L2310;
    }
 L2321: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L2322;
    }
  goto ret0;

 L2310: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 4583 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_MIPS16) && 
#line 402 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT)))
    {
      return 300;  /* *sgtu_di */
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L2321;

 L2322: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 4592 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_MIPS16) && 
#line 402 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT)))
    {
      return 302;  /* *sgtu_di_mips16 */
    }
  goto ret0;

 L2331: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L2332;
    }
  goto ret0;

 L2332: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (1)]
      && (
#line 4608 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_MIPS16) && 
#line 402 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT)))
    {
      return 304;  /* *sge_di */
    }
  goto ret0;

 L2342: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L2343;
    }
  goto ret0;

 L2343: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (arith_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L2344;
    }
  goto ret0;

 L2344: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 4624 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_MIPS16) && 
#line 402 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT)))
    {
      return 306;  /* *sltu_di */
    }
 L2356: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 4633 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_MIPS16) && 
#line 402 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT)))
    {
      return 308;  /* *sltu_di_mips16 */
    }
  goto ret0;

 L2366: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L2367;
    }
  goto ret0;

 L2367: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (sleu_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L2368;
    }
  goto ret0;

 L2368: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 4654 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_MIPS16) && 
#line 402 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT)))
    {
      return 310;  /* *sleu_di */
    }
 L2380: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 4666 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_MIPS16) && 
#line 402 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT)))
    {
      return 312;  /* *sleu_di_mips16 */
    }
  goto ret0;

 L2764: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L4899;
    case DImode:
      goto L4900;
    case CCmode:
      goto L4901;
    default:
      break;
    }
  goto ret0;

 L4899: ATTRIBUTE_UNUSED_LABEL
  if (equality_operator (x2, SImode))
    {
      operands[4] = x2;
      goto L2765;
    }
  goto ret0;

 L2765: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L2766;
    }
  goto ret0;

 L2766: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L2767;
  goto ret0;

 L2767: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (reg_or_0_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L2768;
    }
  goto ret0;

 L2768: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (reg_or_0_operand (x2, DImode))
    {
      operands[3] = x2;
      goto L2769;
    }
  goto ret0;

 L2769: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 5309 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_CONDMOVE) && 
#line 402 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT)))
    {
      return 364;  /* *movdi_on_si */
    }
  goto ret0;

 L4900: ATTRIBUTE_UNUSED_LABEL
  if (equality_operator (x2, DImode))
    {
      operands[4] = x2;
      goto L2783;
    }
  goto ret0;

 L2783: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L2784;
    }
  goto ret0;

 L2784: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L2785;
  goto ret0;

 L2785: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (reg_or_0_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L2786;
    }
  goto ret0;

 L2786: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (reg_or_0_operand (x2, DImode))
    {
      operands[3] = x2;
      goto L2787;
    }
  goto ret0;

 L2787: ATTRIBUTE_UNUSED_LABEL
  if (((
#line 5309 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_CONDMOVE) && 
#line 410 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT)) && 
#line 402 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT)))
    {
      return 366;  /* *movdi_on_di */
    }
  goto ret0;

 L4901: ATTRIBUTE_UNUSED_LABEL
  if (equality_operator (x2, CCmode))
    {
      operands[4] = x2;
      goto L2801;
    }
  goto ret0;

 L2801: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, CCmode))
    {
      operands[1] = x3;
      goto L2802;
    }
  goto ret0;

 L2802: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L2803;
  goto ret0;

 L2803: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (reg_or_0_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L2804;
    }
  goto ret0;

 L2804: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (reg_or_0_operand (x2, DImode))
    {
      operands[3] = x2;
      goto L2805;
    }
  goto ret0;

 L2805: ATTRIBUTE_UNUSED_LABEL
  if (((
#line 5309 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_CONDMOVE) && 
#line 410 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT)) && 
#line 402 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT)))
    {
      return 368;  /* *movdi_on_cc */
    }
  goto ret0;

 L1672: ATTRIBUTE_UNUSED_LABEL
  if (
#line 3053 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_EXPLICIT_RELOCS && ABI_HAS_64BIT_SYMBOLS && cse_not_expected)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 191;  /* *lea64 */
    }
  x1 = XEXP (x0, 1);
  goto L4810;

 L1702: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 3103 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_EXPLICIT_RELOCS && !TARGET_XGOT) && 
#line 406 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(Pmode == DImode)))
    {
      return 197;  /* *got_dispdi */
    }
  goto ret0;
 ret0:
  return -1;
}

static int
recog_6 (rtx x0 ATTRIBUTE_UNUSED,
	rtx insn ATTRIBUTE_UNUSED,
	int *pnum_clobbers ATTRIBUTE_UNUSED)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x1 ATTRIBUTE_UNUSED;
  rtx x2 ATTRIBUTE_UNUSED;
  rtx x3 ATTRIBUTE_UNUSED;
  rtx x4 ATTRIBUTE_UNUSED;
  rtx x5 ATTRIBUTE_UNUSED;
  rtx x6 ATTRIBUTE_UNUSED;
  rtx x7 ATTRIBUTE_UNUSED;
  int tem ATTRIBUTE_UNUSED;

  x1 = XEXP (x0, 1);
  switch (GET_CODE (x1))
    {
    case UNORDERED:
      goto L2384;
    case UNEQ:
      goto L2390;
    case UNLT:
      goto L2396;
    case UNLE:
      goto L2402;
    case EQ:
      goto L2408;
    case LT:
      goto L2414;
    case LE:
      goto L2420;
    case GE:
      goto L2468;
    case GT:
      goto L2474;
    case UNGE:
      goto L2480;
    case UNGT:
      goto L2486;
    case UNSPEC:
      goto L4925;
    default:
     break;
   }
  goto ret0;

 L2384: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SFmode:
      goto L4926;
    case DFmode:
      goto L4927;
    default:
      break;
    }
  goto ret0;

 L4926: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SFmode))
    {
      operands[1] = x2;
      goto L2385;
    }
  goto ret0;

 L2385: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, SFmode))
    {
      operands[2] = x2;
      goto L2386;
    }
  goto ret0;

 L2386: ATTRIBUTE_UNUSED_LABEL
  if (
#line 423 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT))
    {
      return 313;  /* sunordered_sf */
    }
  goto ret0;

 L4927: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DFmode))
    {
      operands[1] = x2;
      goto L2427;
    }
  goto ret0;

 L2427: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, DFmode))
    {
      operands[2] = x2;
      goto L2428;
    }
  goto ret0;

 L2428: ATTRIBUTE_UNUSED_LABEL
  if (
#line 424 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT))
    {
      return 320;  /* sunordered_df */
    }
  goto ret0;

 L2390: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SFmode:
      goto L4928;
    case DFmode:
      goto L4929;
    default:
      break;
    }
  goto ret0;

 L4928: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SFmode))
    {
      operands[1] = x2;
      goto L2391;
    }
  goto ret0;

 L2391: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, SFmode))
    {
      operands[2] = x2;
      goto L2392;
    }
  goto ret0;

 L2392: ATTRIBUTE_UNUSED_LABEL
  if (
#line 423 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT))
    {
      return 314;  /* suneq_sf */
    }
  goto ret0;

 L4929: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DFmode))
    {
      operands[1] = x2;
      goto L2433;
    }
  goto ret0;

 L2433: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, DFmode))
    {
      operands[2] = x2;
      goto L2434;
    }
  goto ret0;

 L2434: ATTRIBUTE_UNUSED_LABEL
  if (
#line 424 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT))
    {
      return 321;  /* suneq_df */
    }
  goto ret0;

 L2396: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SFmode:
      goto L4930;
    case DFmode:
      goto L4931;
    default:
      break;
    }
  goto ret0;

 L4930: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SFmode))
    {
      operands[1] = x2;
      goto L2397;
    }
  goto ret0;

 L2397: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, SFmode))
    {
      operands[2] = x2;
      goto L2398;
    }
  goto ret0;

 L2398: ATTRIBUTE_UNUSED_LABEL
  if (
#line 423 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT))
    {
      return 315;  /* sunlt_sf */
    }
  goto ret0;

 L4931: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DFmode))
    {
      operands[1] = x2;
      goto L2439;
    }
  goto ret0;

 L2439: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, DFmode))
    {
      operands[2] = x2;
      goto L2440;
    }
  goto ret0;

 L2440: ATTRIBUTE_UNUSED_LABEL
  if (
#line 424 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT))
    {
      return 322;  /* sunlt_df */
    }
  goto ret0;

 L2402: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SFmode:
      goto L4932;
    case DFmode:
      goto L4933;
    default:
      break;
    }
  goto ret0;

 L4932: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SFmode))
    {
      operands[1] = x2;
      goto L2403;
    }
  goto ret0;

 L2403: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, SFmode))
    {
      operands[2] = x2;
      goto L2404;
    }
  goto ret0;

 L2404: ATTRIBUTE_UNUSED_LABEL
  if (
#line 423 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT))
    {
      return 316;  /* sunle_sf */
    }
  goto ret0;

 L4933: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DFmode))
    {
      operands[1] = x2;
      goto L2445;
    }
  goto ret0;

 L2445: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, DFmode))
    {
      operands[2] = x2;
      goto L2446;
    }
  goto ret0;

 L2446: ATTRIBUTE_UNUSED_LABEL
  if (
#line 424 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT))
    {
      return 323;  /* sunle_df */
    }
  goto ret0;

 L2408: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SFmode:
      goto L4934;
    case DFmode:
      goto L4935;
    default:
      break;
    }
  goto ret0;

 L4934: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SFmode))
    {
      operands[1] = x2;
      goto L2409;
    }
  goto ret0;

 L2409: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, SFmode))
    {
      operands[2] = x2;
      goto L2410;
    }
  goto ret0;

 L2410: ATTRIBUTE_UNUSED_LABEL
  if (
#line 423 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT))
    {
      return 317;  /* seq_sf */
    }
  goto ret0;

 L4935: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DFmode))
    {
      operands[1] = x2;
      goto L2451;
    }
  goto ret0;

 L2451: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, DFmode))
    {
      operands[2] = x2;
      goto L2452;
    }
  goto ret0;

 L2452: ATTRIBUTE_UNUSED_LABEL
  if (
#line 424 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT))
    {
      return 324;  /* seq_df */
    }
  goto ret0;

 L2414: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SFmode:
      goto L4936;
    case DFmode:
      goto L4937;
    default:
      break;
    }
  goto ret0;

 L4936: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SFmode))
    {
      operands[1] = x2;
      goto L2415;
    }
  goto ret0;

 L2415: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, SFmode))
    {
      operands[2] = x2;
      goto L2416;
    }
  goto ret0;

 L2416: ATTRIBUTE_UNUSED_LABEL
  if (
#line 423 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT))
    {
      return 318;  /* slt_sf */
    }
  goto ret0;

 L4937: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DFmode))
    {
      operands[1] = x2;
      goto L2457;
    }
  goto ret0;

 L2457: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, DFmode))
    {
      operands[2] = x2;
      goto L2458;
    }
  goto ret0;

 L2458: ATTRIBUTE_UNUSED_LABEL
  if (
#line 424 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT))
    {
      return 325;  /* slt_df */
    }
  goto ret0;

 L2420: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SFmode:
      goto L4938;
    case DFmode:
      goto L4939;
    default:
      break;
    }
  goto ret0;

 L4938: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SFmode))
    {
      operands[1] = x2;
      goto L2421;
    }
  goto ret0;

 L2421: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, SFmode))
    {
      operands[2] = x2;
      goto L2422;
    }
  goto ret0;

 L2422: ATTRIBUTE_UNUSED_LABEL
  if (
#line 423 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT))
    {
      return 319;  /* sle_sf */
    }
  goto ret0;

 L4939: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DFmode))
    {
      operands[1] = x2;
      goto L2463;
    }
  goto ret0;

 L2463: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, DFmode))
    {
      operands[2] = x2;
      goto L2464;
    }
  goto ret0;

 L2464: ATTRIBUTE_UNUSED_LABEL
  if (
#line 424 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT))
    {
      return 326;  /* sle_df */
    }
  goto ret0;

 L2468: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SFmode:
      goto L4940;
    case DFmode:
      goto L4941;
    default:
      break;
    }
  goto ret0;

 L4940: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SFmode))
    {
      operands[1] = x2;
      goto L2469;
    }
  goto ret0;

 L2469: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, SFmode))
    {
      operands[2] = x2;
      goto L2470;
    }
  goto ret0;

 L2470: ATTRIBUTE_UNUSED_LABEL
  if (
#line 423 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT))
    {
      return 327;  /* sge_sf */
    }
  goto ret0;

 L4941: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DFmode))
    {
      operands[1] = x2;
      goto L2493;
    }
  goto ret0;

 L2493: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, DFmode))
    {
      operands[2] = x2;
      goto L2494;
    }
  goto ret0;

 L2494: ATTRIBUTE_UNUSED_LABEL
  if (
#line 424 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT))
    {
      return 331;  /* sge_df */
    }
  goto ret0;

 L2474: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SFmode:
      goto L4942;
    case DFmode:
      goto L4943;
    default:
      break;
    }
  goto ret0;

 L4942: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SFmode))
    {
      operands[1] = x2;
      goto L2475;
    }
  goto ret0;

 L2475: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, SFmode))
    {
      operands[2] = x2;
      goto L2476;
    }
  goto ret0;

 L2476: ATTRIBUTE_UNUSED_LABEL
  if (
#line 423 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT))
    {
      return 328;  /* sgt_sf */
    }
  goto ret0;

 L4943: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DFmode))
    {
      operands[1] = x2;
      goto L2499;
    }
  goto ret0;

 L2499: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, DFmode))
    {
      operands[2] = x2;
      goto L2500;
    }
  goto ret0;

 L2500: ATTRIBUTE_UNUSED_LABEL
  if (
#line 424 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT))
    {
      return 332;  /* sgt_df */
    }
  goto ret0;

 L2480: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SFmode:
      goto L4944;
    case DFmode:
      goto L4945;
    default:
      break;
    }
  goto ret0;

 L4944: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SFmode))
    {
      operands[1] = x2;
      goto L2481;
    }
  goto ret0;

 L2481: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, SFmode))
    {
      operands[2] = x2;
      goto L2482;
    }
  goto ret0;

 L2482: ATTRIBUTE_UNUSED_LABEL
  if (
#line 423 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT))
    {
      return 329;  /* sunge_sf */
    }
  goto ret0;

 L4945: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DFmode))
    {
      operands[1] = x2;
      goto L2505;
    }
  goto ret0;

 L2505: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, DFmode))
    {
      operands[2] = x2;
      goto L2506;
    }
  goto ret0;

 L2506: ATTRIBUTE_UNUSED_LABEL
  if (
#line 424 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT))
    {
      return 333;  /* sunge_df */
    }
  goto ret0;

 L2486: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SFmode:
      goto L4946;
    case DFmode:
      goto L4947;
    default:
      break;
    }
  goto ret0;

 L4946: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SFmode))
    {
      operands[1] = x2;
      goto L2487;
    }
  goto ret0;

 L2487: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, SFmode))
    {
      operands[2] = x2;
      goto L2488;
    }
  goto ret0;

 L2488: ATTRIBUTE_UNUSED_LABEL
  if (
#line 423 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT))
    {
      return 330;  /* sungt_sf */
    }
  goto ret0;

 L4947: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DFmode))
    {
      operands[1] = x2;
      goto L2511;
    }
  goto ret0;

 L2511: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, DFmode))
    {
      operands[2] = x2;
      goto L2512;
    }
  goto ret0;

 L2512: ATTRIBUTE_UNUSED_LABEL
  if (
#line 424 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT))
    {
      return 334;  /* sungt_df */
    }
  goto ret0;

 L4925: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x1, 0) == 3
      && XINT (x1, 1) == 203)
    goto L2979;
  goto ret0;

 L2979: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  switch (GET_MODE (x2))
    {
    case SFmode:
      goto L4948;
    case DFmode:
      goto L4949;
    default:
      break;
    }
  goto ret0;

 L4948: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SFmode))
    {
      operands[1] = x2;
      goto L2980;
    }
  goto ret0;

 L2980: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, SFmode))
    {
      operands[2] = x2;
      goto L2981;
    }
  goto ret0;

 L2981: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 2);
  if (const_int_operand (x2, VOIDmode))
    {
      operands[3] = x2;
      goto L2982;
    }
  goto ret0;

 L2982: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 289 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-ps-3d.md"
(TARGET_MIPS3D) && 
#line 423 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT)))
    {
      return 392;  /* mips_cabs_cond_s */
    }
  goto ret0;

 L4949: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DFmode))
    {
      operands[1] = x2;
      goto L2987;
    }
  goto ret0;

 L2987: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, DFmode))
    {
      operands[2] = x2;
      goto L2988;
    }
  goto ret0;

 L2988: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 2);
  if (const_int_operand (x2, VOIDmode))
    {
      operands[3] = x2;
      goto L2989;
    }
  goto ret0;

 L2989: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 289 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-ps-3d.md"
(TARGET_MIPS3D) && 
#line 424 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT)))
    {
      return 393;  /* mips_cabs_cond_d */
    }
  goto ret0;
 ret0:
  return -1;
}

static int
recog_7 (rtx x0 ATTRIBUTE_UNUSED,
	rtx insn ATTRIBUTE_UNUSED,
	int *pnum_clobbers ATTRIBUTE_UNUSED)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x1 ATTRIBUTE_UNUSED;
  rtx x2 ATTRIBUTE_UNUSED;
  rtx x3 ATTRIBUTE_UNUSED;
  rtx x4 ATTRIBUTE_UNUSED;
  rtx x5 ATTRIBUTE_UNUSED;
  rtx x6 ATTRIBUTE_UNUSED;
  rtx x7 ATTRIBUTE_UNUSED;
  int tem ATTRIBUTE_UNUSED;

  x1 = XEXP (x0, 1);
  switch (GET_MODE (x1))
    {
    case SImode:
      goto L5031;
    case DImode:
      goto L5032;
    default:
      break;
    }
 L2076: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case IF_THEN_ELSE:
      goto L2077;
    case LABEL_REF:
      goto L2516;
    default:
     break;
   }
  goto ret0;

 L5031: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, SImode))
    {
      operands[0] = x1;
      goto L2526;
    }
  goto L2076;

 L2526: ATTRIBUTE_UNUSED_LABEL
  if (
#line 406 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(Pmode == SImode))
    {
      return 337;  /* indirect_jumpsi */
    }
  x1 = XEXP (x0, 1);
  goto L2076;

 L5032: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, DImode))
    {
      operands[0] = x1;
      goto L2530;
    }
  goto L2076;

 L2530: ATTRIBUTE_UNUSED_LABEL
  if (
#line 406 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(Pmode == DImode))
    {
      return 338;  /* indirect_jumpdi */
    }
  x1 = XEXP (x0, 1);
  goto L2076;

 L2077: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case CCmode:
      goto L5033;
    case SImode:
      goto L5034;
    case DImode:
      goto L5035;
    case CCV4mode:
      goto L5038;
    case CCV2mode:
      goto L5039;
    case CCDSPmode:
      goto L5040;
    default:
      break;
    }
  goto ret0;

 L5033: ATTRIBUTE_UNUSED_LABEL
  if (comparison_operator (x2, CCmode))
    {
      operands[0] = x2;
      goto L2078;
    }
  goto ret0;

 L2078: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, CCmode))
    {
      operands[2] = x3;
      goto L2079;
    }
  goto ret0;

 L2079: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L2080;
  goto ret0;

 L2080: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  switch (GET_CODE (x2))
    {
    case LABEL_REF:
      goto L2081;
    case PC:
      goto L2090;
    default:
     break;
   }
  goto ret0;

 L2081: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  operands[1] = x3;
  goto L2082;

 L2082: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == PC
      && 
#line 4257 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT))
    {
      return 267;  /* branch_fp */
    }
  goto ret0;

 L2090: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == LABEL_REF)
    goto L2091;
  goto ret0;

 L2091: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  operands[1] = x3;
  goto L2092;

 L2092: ATTRIBUTE_UNUSED_LABEL
  if (
#line 4277 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT))
    {
      return 268;  /* branch_fp_inverted */
    }
  goto ret0;

 L5034: ATTRIBUTE_UNUSED_LABEL
  if (comparison_operator (x2, SImode))
    {
      operands[0] = x2;
      goto L2097;
    }
 L5036: ATTRIBUTE_UNUSED_LABEL
  if (equality_operator (x2, SImode))
    {
      operands[0] = x2;
      goto L2135;
    }
  goto ret0;

 L2097: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L2098;
    }
  goto L5036;

 L2098: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L2099;
  goto L5036;

 L2099: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  switch (GET_CODE (x2))
    {
    case LABEL_REF:
      goto L2100;
    case PC:
      goto L2118;
    default:
     break;
   }
  x2 = XEXP (x1, 0);
  goto L5036;

 L2100: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  operands[1] = x3;
  goto L2101;

 L2101: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == PC
      && 
#line 4299 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_MIPS16))
    {
      return 269;  /* *branch_zerosi */
    }
  x2 = XEXP (x1, 0);
  goto L5036;

 L2118: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == LABEL_REF)
    goto L2119;
  x2 = XEXP (x1, 0);
  goto L5036;

 L2119: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  operands[1] = x3;
  goto L2120;

 L2120: ATTRIBUTE_UNUSED_LABEL
  if (
#line 4319 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_MIPS16))
    {
      return 271;  /* *branch_zerosi_inverted */
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  goto L5036;

 L2135: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode)
    goto L5041;
  goto ret0;

 L5041: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L2136;
    }
 L5042: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L2174;
    }
  goto ret0;

 L2136: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, SImode))
    {
      operands[3] = x3;
      goto L2137;
    }
  x3 = XEXP (x2, 0);
  goto L5042;

 L2137: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  switch (GET_CODE (x2))
    {
    case LABEL_REF:
      goto L2138;
    case PC:
      goto L2156;
    default:
     break;
   }
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  goto L5042;

 L2138: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  operands[1] = x3;
  goto L2139;

 L2139: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == PC
      && 
#line 4341 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_MIPS16))
    {
      return 273;  /* *branch_equalitysi */
    }
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  goto L5042;

 L2156: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == LABEL_REF)
    goto L2157;
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  goto L5042;

 L2157: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  operands[1] = x3;
  goto L2158;

 L2158: ATTRIBUTE_UNUSED_LABEL
  if (
#line 4361 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_MIPS16))
    {
      return 275;  /* *branch_equalitysi_inverted */
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  goto L5042;

 L2174: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L2175;
  goto ret0;

 L2175: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (pc_or_label_operand (x2, VOIDmode))
    {
      operands[2] = x2;
      goto L2176;
    }
  goto ret0;

 L2176: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (pc_or_label_operand (x2, VOIDmode))
    {
      operands[3] = x2;
      goto L2177;
    }
  goto ret0;

 L2177: ATTRIBUTE_UNUSED_LABEL
  if (
#line 4383 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_MIPS16))
    {
      return 277;  /* *branch_equalitysi_mips16 */
    }
  goto ret0;

 L5035: ATTRIBUTE_UNUSED_LABEL
  if (comparison_operator (x2, DImode))
    {
      operands[0] = x2;
      goto L2106;
    }
 L5037: ATTRIBUTE_UNUSED_LABEL
  if (equality_operator (x2, DImode))
    {
      operands[0] = x2;
      goto L2144;
    }
  goto ret0;

 L2106: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L2107;
    }
  goto L5037;

 L2107: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L2108;
  goto L5037;

 L2108: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  switch (GET_CODE (x2))
    {
    case LABEL_REF:
      goto L2109;
    case PC:
      goto L2128;
    default:
     break;
   }
  x2 = XEXP (x1, 0);
  goto L5037;

 L2109: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  operands[1] = x3;
  goto L2110;

 L2110: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == PC
      && (
#line 4299 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_MIPS16) && 
#line 402 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT)))
    {
      return 270;  /* *branch_zerodi */
    }
  x2 = XEXP (x1, 0);
  goto L5037;

 L2128: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == LABEL_REF)
    goto L2129;
  x2 = XEXP (x1, 0);
  goto L5037;

 L2129: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  operands[1] = x3;
  goto L2130;

 L2130: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 4319 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_MIPS16) && 
#line 402 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT)))
    {
      return 272;  /* *branch_zerodi_inverted */
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  goto L5037;

 L2144: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DImode)
    goto L5043;
  goto ret0;

 L5043: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L2145;
    }
 L5044: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L2183;
    }
  goto ret0;

 L2145: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, DImode))
    {
      operands[3] = x3;
      goto L2146;
    }
  x3 = XEXP (x2, 0);
  goto L5044;

 L2146: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  switch (GET_CODE (x2))
    {
    case LABEL_REF:
      goto L2147;
    case PC:
      goto L2166;
    default:
     break;
   }
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  goto L5044;

 L2147: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  operands[1] = x3;
  goto L2148;

 L2148: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == PC
      && (
#line 4341 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_MIPS16) && 
#line 402 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT)))
    {
      return 274;  /* *branch_equalitydi */
    }
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  goto L5044;

 L2166: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == LABEL_REF)
    goto L2167;
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  goto L5044;

 L2167: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  operands[1] = x3;
  goto L2168;

 L2168: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 4361 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_MIPS16) && 
#line 402 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT)))
    {
      return 276;  /* *branch_equalitydi_inverted */
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  goto L5044;

 L2183: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    goto L2184;
  goto ret0;

 L2184: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (pc_or_label_operand (x2, VOIDmode))
    {
      operands[2] = x2;
      goto L2185;
    }
  goto ret0;

 L2185: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (pc_or_label_operand (x2, VOIDmode))
    {
      operands[3] = x2;
      goto L2186;
    }
  goto ret0;

 L2186: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 4383 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_MIPS16) && 
#line 402 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT)))
    {
      return 278;  /* *branch_equalitydi_mips16 */
    }
  goto ret0;

 L5038: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == NE)
    goto L3026;
  goto ret0;

 L3026: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, CCV4mode))
    {
      operands[0] = x3;
      goto L3027;
    }
  goto ret0;

 L3027: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT)
    goto L5045;
  goto ret0;

 L5045: ATTRIBUTE_UNUSED_LABEL
  if ((int) XWINT (x3, 0) == XWINT (x3, 0))
    switch ((int) XWINT (x3, 0))
      {
      case 0L:
        goto L3028;
      case -1L:
        goto L3037;
      default:
        break;
      }
  goto ret0;

 L3028: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == LABEL_REF)
    goto L3029;
  goto ret0;

 L3029: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  operands[1] = x3;
  goto L3030;

 L3030: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == PC
      && 
#line 396 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-ps-3d.md"
(TARGET_MIPS3D))
    {
      return 398;  /* bc1any4t */
    }
  goto ret0;

 L3037: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == LABEL_REF)
    goto L3038;
  goto ret0;

 L3038: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  operands[1] = x3;
  goto L3039;

 L3039: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == PC
      && 
#line 408 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-ps-3d.md"
(TARGET_MIPS3D))
    {
      return 399;  /* bc1any4f */
    }
  goto ret0;

 L5039: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == NE)
    goto L3044;
  goto ret0;

 L3044: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, CCV2mode))
    {
      operands[0] = x3;
      goto L3045;
    }
  goto ret0;

 L3045: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT)
    goto L5047;
  goto ret0;

 L5047: ATTRIBUTE_UNUSED_LABEL
  if ((int) XWINT (x3, 0) == XWINT (x3, 0))
    switch ((int) XWINT (x3, 0))
      {
      case 0L:
        goto L3046;
      case -1L:
        goto L3055;
      default:
        break;
      }
  goto ret0;

 L3046: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == LABEL_REF)
    goto L3047;
  goto ret0;

 L3047: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  operands[1] = x3;
  goto L3048;

 L3048: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == PC
      && 
#line 420 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-ps-3d.md"
(TARGET_MIPS3D))
    {
      return 400;  /* bc1any2t */
    }
  goto ret0;

 L3055: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == LABEL_REF)
    goto L3056;
  goto ret0;

 L3056: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  operands[1] = x3;
  goto L3057;

 L3057: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == PC
      && 
#line 432 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-ps-3d.md"
(TARGET_MIPS3D))
    {
      return 401;  /* bc1any2f */
    }
  goto ret0;

 L5040: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == GE)
    goto L3963;
  goto ret0;

 L3963: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == CCDSPmode
      && GET_CODE (x3) == REG
      && XINT (x3, 0) == 182)
    goto L3964;
  goto ret0;

 L3964: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (immediate_operand (x3, SImode))
    {
      operands[0] = x3;
      goto L3965;
    }
  goto ret0;

 L3965: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == LABEL_REF)
    goto L3966;
  goto ret0;

 L3966: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  operands[1] = x3;
  goto L3967;

 L3967: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == PC
      && 
#line 1054 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP))
    {
      return 499;  /* mips_bposge */
    }
  goto ret0;

 L2516: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  operands[0] = x2;
  goto L2517;

 L2517: ATTRIBUTE_UNUSED_LABEL
  if (
#line 4714 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_MIPS16))
    {
      return 335;  /* jump */
    }
 L2522: ATTRIBUTE_UNUSED_LABEL
  if (
#line 4748 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_MIPS16))
    {
      return 336;  /* *mips.md:4745 */
    }
  goto ret0;
 ret0:
  return -1;
}

static int
recog_8 (rtx x0 ATTRIBUTE_UNUSED,
	rtx insn ATTRIBUTE_UNUSED,
	int *pnum_clobbers ATTRIBUTE_UNUSED)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x1 ATTRIBUTE_UNUSED;
  rtx x2 ATTRIBUTE_UNUSED;
  rtx x3 ATTRIBUTE_UNUSED;
  rtx x4 ATTRIBUTE_UNUSED;
  rtx x5 ATTRIBUTE_UNUSED;
  rtx x6 ATTRIBUTE_UNUSED;
  rtx x7 ATTRIBUTE_UNUSED;
  int tem ATTRIBUTE_UNUSED;

  x1 = XEXP (x0, 0);
  switch (GET_MODE (x1))
    {
    case SFmode:
      goto L4468;
    case DFmode:
      goto L4469;
    case V2SFmode:
      goto L4470;
    case SImode:
      goto L4460;
    case DImode:
      goto L4461;
    case HImode:
      goto L4457;
    case QImode:
      goto L4458;
    case BLKmode:
      goto L4462;
    case CCmode:
      goto L4467;
    case CCV4mode:
      goto L4476;
    case CCV2mode:
      goto L4477;
    case V4QImode:
      goto L4478;
    case V2HImode:
      goto L4479;
    case CCDSPmode:
      goto L4480;
    default:
      break;
    }
 L2075: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x1) == PC)
    goto L2525;
  if (register_operand (x1, VOIDmode))
    {
      operands[0] = x1;
      goto L2595;
    }
  goto ret0;

 L4468: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x1) == MEM)
    goto L1827;
  if (register_operand (x1, SFmode))
    {
      operands[0] = x1;
      goto L15;
    }
 L4471: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x1, SFmode))
    {
      operands[0] = x1;
      goto L1885;
    }
  goto L2075;

 L1827: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L4482;
    case DImode:
      goto L4483;
    default:
      break;
    }
  goto L4471;

 L4482: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == PLUS)
    goto L1828;
  goto L4471;

 L1828: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L1829;
    }
  goto L4471;

 L1829: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L1830;
    }
  goto L4471;

 L1830: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (register_operand (x1, SFmode))
    {
      operands[0] = x1;
      goto L1831;
    }
  x1 = XEXP (x0, 0);
  goto L4471;

 L1831: ATTRIBUTE_UNUSED_LABEL
  if (((
#line 3487 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_FP4) && 
#line 406 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(Pmode == SImode)) && 
#line 418 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT)))
    {
      return 221;  /* *swxc1_si */
    }
  x1 = XEXP (x0, 0);
  goto L4471;

 L4483: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == PLUS)
    goto L1849;
  goto L4471;

 L1849: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L1850;
    }
  goto L4471;

 L1850: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L1851;
    }
  goto L4471;

 L1851: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (register_operand (x1, SFmode))
    {
      operands[0] = x1;
      goto L1852;
    }
  x1 = XEXP (x0, 0);
  goto L4471;

 L1852: ATTRIBUTE_UNUSED_LABEL
  if (((
#line 3487 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_FP4) && 
#line 406 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(Pmode == DImode)) && 
#line 418 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT)))
    {
      return 224;  /* *swxc1_di */
    }
  x1 = XEXP (x0, 0);
  goto L4471;

 L15: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == SFmode)
    goto L4484;
  x1 = XEXP (x0, 0);
  goto L4471;

 L4484: ATTRIBUTE_UNUSED_LABEL
  tem = recog_1 (x0, insn, pnum_clobbers);
  if (tem >= 0)
    return tem;
  x1 = XEXP (x0, 0);
  goto L4471;

 L1885: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (move_operand (x1, SFmode))
    {
      operands[1] = x1;
      goto L1886;
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L1886: ATTRIBUTE_UNUSED_LABEL
  if (
#line 3696 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT
   && (register_operand (operands[0], SFmode)
       || reg_or_0_operand (operands[1], SFmode))))
    {
      return 231;  /* *movsf_hardfloat */
    }
 L1890: ATTRIBUTE_UNUSED_LABEL
  if (
#line 3707 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_SOFT_FLOAT && !TARGET_MIPS16
   && (register_operand (operands[0], SFmode)
       || reg_or_0_operand (operands[1], SFmode))))
    {
      return 232;  /* *movsf_softfloat */
    }
 L1894: ATTRIBUTE_UNUSED_LABEL
  if (
#line 3718 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_MIPS16
   && (register_operand (operands[0], SFmode)
       || register_operand (operands[1], SFmode))))
    {
      return 233;  /* *movsf_mips16 */
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L4469: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x1) == MEM)
    goto L1834;
  if (register_operand (x1, DFmode))
    {
      operands[0] = x1;
      goto L21;
    }
 L4472: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x1, DFmode))
    {
      operands[0] = x1;
      goto L1897;
    }
  goto L2075;

 L1834: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L4530;
    case DImode:
      goto L4531;
    default:
      break;
    }
  goto L4472;

 L4530: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == PLUS)
    goto L1835;
  goto L4472;

 L1835: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L1836;
    }
  goto L4472;

 L1836: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L1837;
    }
  goto L4472;

 L1837: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (register_operand (x1, DFmode))
    {
      operands[0] = x1;
      goto L1838;
    }
  x1 = XEXP (x0, 0);
  goto L4472;

 L1838: ATTRIBUTE_UNUSED_LABEL
  if (((
#line 3487 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_FP4) && 
#line 406 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(Pmode == SImode)) && 
#line 419 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT)))
    {
      return 222;  /* *sdxc1_si */
    }
  x1 = XEXP (x0, 0);
  goto L4472;

 L4531: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == PLUS)
    goto L1856;
  goto L4472;

 L1856: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L1857;
    }
  goto L4472;

 L1857: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L1858;
    }
  goto L4472;

 L1858: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (register_operand (x1, DFmode))
    {
      operands[0] = x1;
      goto L1859;
    }
  x1 = XEXP (x0, 0);
  goto L4472;

 L1859: ATTRIBUTE_UNUSED_LABEL
  if (((
#line 3487 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_FP4) && 
#line 406 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(Pmode == DImode)) && 
#line 419 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT)))
    {
      return 225;  /* *sdxc1_di */
    }
  x1 = XEXP (x0, 0);
  goto L4472;

 L21: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == DFmode)
    goto L4532;
  x1 = XEXP (x0, 0);
  goto L4472;

 L4532: ATTRIBUTE_UNUSED_LABEL
  tem = recog_2 (x0, insn, pnum_clobbers);
  if (tem >= 0)
    return tem;
  x1 = XEXP (x0, 0);
  goto L4472;

 L1897: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (move_operand (x1, DFmode))
    {
      operands[1] = x1;
      goto L1898;
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L1898: ATTRIBUTE_UNUSED_LABEL
  if (
#line 3741 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT && TARGET_64BIT
   && (register_operand (operands[0], DFmode)
       || reg_or_0_operand (operands[1], DFmode))))
    {
      return 234;  /* *movdf_hardfloat_64bit */
    }
 L1902: ATTRIBUTE_UNUSED_LABEL
  if (
#line 3752 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT && !TARGET_64BIT
   && (register_operand (operands[0], DFmode)
       || reg_or_0_operand (operands[1], DFmode))))
    {
      return 235;  /* *movdf_hardfloat_32bit */
    }
 L1906: ATTRIBUTE_UNUSED_LABEL
  if (
#line 3763 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
((TARGET_SOFT_FLOAT || TARGET_SINGLE_FLOAT) && !TARGET_MIPS16
   && (register_operand (operands[0], DFmode)
       || reg_or_0_operand (operands[1], DFmode))))
    {
      return 236;  /* *movdf_softfloat */
    }
 L1910: ATTRIBUTE_UNUSED_LABEL
  if (
#line 3774 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_MIPS16
   && (register_operand (operands[0], DFmode)
       || register_operand (operands[1], DFmode))))
    {
      return 237;  /* *movdf_mips16 */
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L4470: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x1) == MEM)
    goto L1841;
  if (register_operand (x1, V2SFmode))
    {
      operands[0] = x1;
      goto L27;
    }
 L4473: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x1, V2SFmode))
    {
      operands[0] = x1;
      goto L1913;
    }
  goto L2075;

 L1841: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L4583;
    case DImode:
      goto L4584;
    default:
      break;
    }
  goto L4473;

 L4583: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == PLUS)
    goto L1842;
  goto L4473;

 L1842: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L1843;
    }
  goto L4473;

 L1843: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L1844;
    }
  goto L4473;

 L1844: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (register_operand (x1, V2SFmode))
    {
      operands[0] = x1;
      goto L1845;
    }
  x1 = XEXP (x0, 0);
  goto L4473;

 L1845: ATTRIBUTE_UNUSED_LABEL
  if (((
#line 3487 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_FP4) && 
#line 406 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(Pmode == SImode)) && 
#line 420 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_PAIRED_SINGLE_FLOAT)))
    {
      return 223;  /* *sdxc1_si */
    }
  x1 = XEXP (x0, 0);
  goto L4473;

 L4584: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == PLUS)
    goto L1863;
  goto L4473;

 L1863: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L1864;
    }
  goto L4473;

 L1864: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L1865;
    }
  goto L4473;

 L1865: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (register_operand (x1, V2SFmode))
    {
      operands[0] = x1;
      goto L1866;
    }
  x1 = XEXP (x0, 0);
  goto L4473;

 L1866: ATTRIBUTE_UNUSED_LABEL
  if (((
#line 3487 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_FP4) && 
#line 406 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(Pmode == DImode)) && 
#line 420 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_PAIRED_SINGLE_FLOAT)))
    {
      return 226;  /* *sdxc1_di */
    }
  x1 = XEXP (x0, 0);
  goto L4473;

 L27: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == V2SFmode)
    goto L4585;
  x1 = XEXP (x0, 0);
  goto L4473;

 L4585: ATTRIBUTE_UNUSED_LABEL
  tem = recog_3 (x0, insn, pnum_clobbers);
  if (tem >= 0)
    return tem;
  x1 = XEXP (x0, 0);
  goto L4473;

 L1913: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (move_operand (x1, V2SFmode))
    {
      operands[1] = x1;
      goto L1914;
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L1914: ATTRIBUTE_UNUSED_LABEL
  if (
#line 3833 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_PAIRED_SINGLE_FLOAT
   && TARGET_64BIT
   && (register_operand (operands[0], V2SFmode)
       || reg_or_0_operand (operands[1], V2SFmode))))
    {
      return 238;  /* movv2sf_hardfloat_64bit */
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L4460: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case ZERO_EXTRACT:
      goto L1595;
    case MEM:
      goto L4651;
    case REG:
      goto L4652;
    default:
     break;
   }
 L4450: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, SImode))
    {
      operands[0] = x1;
      goto L33;
    }
 L4452: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x1) == REG
      && XINT (x1, 0) == 29)
    goto L45;
 L4454: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, SImode))
    {
      operands[0] = x1;
      goto L57;
    }
 L4456: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x1, SImode))
    {
      operands[0] = x1;
      goto L1308;
    }
 L4481: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, SImode))
    {
      operands[0] = x1;
      goto L3954;
    }
  goto L2075;

 L1595: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L1596;
    }
  goto L2075;

 L1596: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (immediate_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L1597;
    }
  goto L2075;

 L1597: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (immediate_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L1598;
    }
  goto L2075;

 L1598: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (reg_or_0_operand (x1, SImode))
    {
      operands[3] = x1;
      goto L1599;
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L1599: ATTRIBUTE_UNUSED_LABEL
  if (
#line 2922 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(mips_use_ins_ext_p (operands[0], operands[1], operands[2])))
    {
      return 180;  /* insvsi */
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L4651: ATTRIBUTE_UNUSED_LABEL
  if (stack_operand (x1, SImode))
    {
      operands[0] = x1;
      goto L1751;
    }
  goto L4456;

 L1751: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == SImode
      && GET_CODE (x1) == REG
      && XINT (x1, 0) == 31
      && 
#line 3192 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_MIPS16))
    {
      return 206;  /* *movsi_ra */
    }
  x1 = XEXP (x0, 0);
  goto L4456;

 L4652: ATTRIBUTE_UNUSED_LABEL
  if (XINT (x1, 0) == 28)
    goto L2574;
  goto L4450;

 L2574: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == SImode
      && GET_CODE (x1) == UNSPEC_VOLATILE
      && XVECLEN (x1, 0) == 1
      && XINT (x1, 1) == 6)
    goto L2575;
  x1 = XEXP (x0, 0);
  goto L4450;

 L2575: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (0)]
      && 
#line 4962 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_ABICALLS && TARGET_OLDABI))
    {
      return 346;  /* exception_receiver */
    }
  x1 = XEXP (x0, 0);
  goto L4450;

 L33: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == SImode
      && GET_CODE (x1) == PLUS)
    goto L34;
  x1 = XEXP (x0, 0);
  goto L4452;

 L34: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L35;
    }
  x1 = XEXP (x0, 0);
  goto L4452;

 L35: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (arith_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L36;
    }
  x1 = XEXP (x0, 0);
  goto L4452;

 L36: ATTRIBUTE_UNUSED_LABEL
  if (
#line 665 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_MIPS16))
    {
      return 6;  /* *addsi3 */
    }
  x1 = XEXP (x0, 0);
  goto L4452;

 L45: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == SImode
      && GET_CODE (x1) == PLUS)
    goto L46;
  x1 = XEXP (x0, 0);
  goto L4454;

 L46: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 29)
    goto L47;
  x1 = XEXP (x0, 0);
  goto L4454;

 L47: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const_arith_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L48;
    }
  x1 = XEXP (x0, 0);
  goto L4454;

 L48: ATTRIBUTE_UNUSED_LABEL
  if (
#line 680 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_MIPS16))
    {
      return 8;  /* *addsi3_sp1 */
    }
  x1 = XEXP (x0, 0);
  goto L4454;

 L57: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == SImode)
    goto L4653;
  x1 = XEXP (x0, 0);
  goto L4456;

 L4653: ATTRIBUTE_UNUSED_LABEL
  tem = recog_4 (x0, insn, pnum_clobbers);
  if (tem >= 0)
    return tem;
  x1 = XEXP (x0, 0);
  goto L4456;

 L1308: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == SImode)
    goto L4787;
 L1773: ATTRIBUTE_UNUSED_LABEL
  if (move_operand (x1, SImode))
    {
      operands[1] = x1;
      goto L1774;
    }
  x1 = XEXP (x0, 0);
  goto L4481;

 L4787: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case TRUNCATE:
      goto L1309;
    case UNSPEC:
      goto L4789;
    default:
     break;
   }
  goto L1773;

 L1309: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L1310;
    }
  goto L1773;

 L1310: ATTRIBUTE_UNUSED_LABEL
  if (
#line 2194 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT))
    {
      return 128;  /* truncdisi2 */
    }
  x1 = XEXP (x0, 1);
  goto L1773;

 L4789: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x1, 0) == 1
      && XINT (x1, 1) == 2)
    goto L1953;
  goto L1773;

 L1953: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, DFmode))
    {
      operands[1] = x2;
      goto L1954;
    }
  goto L1773;

 L1954: ATTRIBUTE_UNUSED_LABEL
  if (
#line 3922 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT && !TARGET_64BIT))
    {
      return 245;  /* store_df_high */
    }
  x1 = XEXP (x0, 1);
  goto L1773;

 L1774: ATTRIBUTE_UNUSED_LABEL
  if (
#line 3318 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_MIPS16
   && (register_operand (operands[0], SImode)
       || reg_or_0_operand (operands[1], SImode))))
    {
      return 212;  /* *movsi_internal */
    }
 L1778: ATTRIBUTE_UNUSED_LABEL
  if (
#line 3329 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_MIPS16
   && (register_operand (operands[0], SImode)
       || register_operand (operands[1], SImode))))
    {
      return 213;  /* *movsi_mips16 */
    }
  x1 = XEXP (x0, 0);
  goto L4481;

 L3954: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == SImode
      && GET_CODE (x1) == MEM)
    goto L3955;
  x1 = XEXP (x0, 0);
  goto L2075;

 L3955: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L3956;
  x1 = XEXP (x0, 0);
  goto L2075;

 L3956: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L3957;
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L3957: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L3958;
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L3958: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1039 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP))
    {
      return 498;  /* mips_lwx */
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L4461: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case ZERO_EXTRACT:
      goto L1602;
    case MEM:
      goto L4790;
    case REG:
    case SUBREG:
      goto L4451;
    default:
      goto L4453;
   }
 L4451: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, DImode))
    {
      operands[0] = x1;
      goto L39;
    }
 L4453: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x1) == REG
      && XINT (x1, 0) == 29)
    goto L51;
 L4455: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, DImode))
    {
      operands[0] = x1;
      goto L63;
    }
 L4465: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x1, DImode))
    {
      operands[0] = x1;
      goto L1757;
    }
  goto L2075;

 L1602: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L1603;
    }
  goto L2075;

 L1603: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (immediate_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L1604;
    }
  goto L2075;

 L1604: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (immediate_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L1605;
    }
  goto L2075;

 L1605: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (reg_or_0_operand (x1, DImode))
    {
      operands[3] = x1;
      goto L1606;
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L1606: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 2922 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(mips_use_ins_ext_p (operands[0], operands[1], operands[2])) && 
#line 402 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT)))
    {
      return 181;  /* insvdi */
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L4790: ATTRIBUTE_UNUSED_LABEL
  if (stack_operand (x1, DImode))
    {
      operands[0] = x1;
      goto L1754;
    }
  goto L4465;

 L1754: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == DImode
      && GET_CODE (x1) == REG
      && XINT (x1, 0) == 31
      && (
#line 3192 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_MIPS16) && 
#line 402 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT)))
    {
      return 207;  /* *movdi_ra */
    }
  x1 = XEXP (x0, 0);
  goto L4465;

 L39: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == DImode
      && GET_CODE (x1) == PLUS)
    goto L40;
  x1 = XEXP (x0, 0);
  goto L4453;

 L40: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L41;
    }
  x1 = XEXP (x0, 0);
  goto L4453;

 L41: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (arith_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L42;
    }
  x1 = XEXP (x0, 0);
  goto L4453;

 L42: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 665 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_MIPS16) && 
#line 402 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT)))
    {
      return 7;  /* *adddi3 */
    }
  x1 = XEXP (x0, 0);
  goto L4453;

 L51: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == DImode
      && GET_CODE (x1) == PLUS)
    goto L52;
  x1 = XEXP (x0, 0);
  goto L4455;

 L52: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 29)
    goto L53;
  x1 = XEXP (x0, 0);
  goto L4455;

 L53: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const_arith_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L54;
    }
  x1 = XEXP (x0, 0);
  goto L4455;

 L54: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 680 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_MIPS16) && 
#line 402 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT)))
    {
      return 9;  /* *adddi3_sp1 */
    }
  x1 = XEXP (x0, 0);
  goto L4455;

 L63: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == DImode)
    goto L4791;
  x1 = XEXP (x0, 0);
  goto L4465;

 L4791: ATTRIBUTE_UNUSED_LABEL
  tem = recog_5 (x0, insn, pnum_clobbers);
  if (tem >= 0)
    return tem;
  x1 = XEXP (x0, 0);
  goto L4465;

 L1757: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (move_operand (x1, DImode))
    {
      operands[1] = x1;
      goto L1758;
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L1758: ATTRIBUTE_UNUSED_LABEL
  if (
#line 3200 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_64BIT && !TARGET_MIPS16
   && (register_operand (operands[0], DImode)
       || reg_or_0_operand (operands[1], DImode))))
    {
      return 208;  /* *movdi_32bit */
    }
 L1762: ATTRIBUTE_UNUSED_LABEL
  if (
#line 3211 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_64BIT && TARGET_MIPS16
   && (register_operand (operands[0], DImode)
       || register_operand (operands[1], DImode))))
    {
      return 209;  /* *movdi_32bit_mips16 */
    }
 L1766: ATTRIBUTE_UNUSED_LABEL
  if (
#line 3222 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT && !TARGET_MIPS16
   && (register_operand (operands[0], DImode)
       || reg_or_0_operand (operands[1], DImode))))
    {
      return 210;  /* *movdi_64bit */
    }
 L1770: ATTRIBUTE_UNUSED_LABEL
  if (
#line 3233 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT && TARGET_MIPS16
   && (register_operand (operands[0], DImode)
       || register_operand (operands[1], DImode))))
    {
      return 211;  /* *movdi_64bit_mips16 */
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L4457: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x1, HImode))
    {
      operands[0] = x1;
      goto L1313;
    }
 L4459: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, HImode))
    {
      operands[0] = x1;
      goto L1360;
    }
  goto L2075;

 L1313: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == HImode
      && GET_CODE (x1) == TRUNCATE)
    goto L1314;
  if (move_operand (x1, HImode))
    {
      operands[1] = x1;
      goto L1870;
    }
  x1 = XEXP (x0, 0);
  goto L4459;

 L1314: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L1315;
    }
  x1 = XEXP (x0, 0);
  goto L4459;

 L1315: ATTRIBUTE_UNUSED_LABEL
  if (
#line 2205 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT))
    {
      return 129;  /* truncdihi2 */
    }
  x1 = XEXP (x0, 0);
  goto L4459;

 L1870: ATTRIBUTE_UNUSED_LABEL
  if (
#line 3511 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_MIPS16
   && (register_operand (operands[0], HImode)
       || reg_or_0_operand (operands[1], HImode))))
    {
      return 227;  /* *movhi_internal */
    }
 L1874: ATTRIBUTE_UNUSED_LABEL
  if (
#line 3530 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_MIPS16
   && (register_operand (operands[0], HImode)
       || register_operand (operands[1], HImode))))
    {
      return 228;  /* *movhi_mips16 */
    }
  x1 = XEXP (x0, 0);
  goto L4459;

 L1360: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == HImode)
    goto L4902;
  x1 = XEXP (x0, 0);
  goto L2075;

 L4902: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case ZERO_EXTEND:
      goto L1361;
    case SIGN_EXTEND:
      goto L1507;
    default:
     break;
   }
  x1 = XEXP (x0, 0);
  goto L2075;

 L1361: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == QImode)
    goto L4904;
  x1 = XEXP (x0, 0);
  goto L2075;

 L4904: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == TRUNCATE)
    goto L1362;
  if (nonimmediate_operand (x2, QImode))
    {
      operands[1] = x2;
      goto L1433;
    }
 L4906: ATTRIBUTE_UNUSED_LABEL
  if (memory_operand (x2, QImode))
    {
      operands[1] = x2;
      goto L1438;
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L1362: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L1363;
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L1363: ATTRIBUTE_UNUSED_LABEL
  if (
#line 2304 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT && !TARGET_MIPS16))
    {
      return 137;  /* *mips.md:2300 */
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L1433: ATTRIBUTE_UNUSED_LABEL
  if (
#line 2394 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_MIPS16))
    {
      return 151;  /* *zero_extendqihi2 */
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  goto L4906;

 L1438: ATTRIBUTE_UNUSED_LABEL
  if (
#line 2404 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_MIPS16))
    {
      return 152;  /* *zero_extendqihi2_mips16 */
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L1507: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, QImode))
    {
      operands[1] = x2;
      return 166;  /* extendqihi2 */
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L4458: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x1, QImode))
    {
      operands[0] = x1;
      goto L1318;
    }
  goto L2075;

 L1318: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == QImode
      && GET_CODE (x1) == TRUNCATE)
    goto L1319;
  if (move_operand (x1, QImode))
    {
      operands[1] = x1;
      goto L1878;
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L1319: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L1320;
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L1320: ATTRIBUTE_UNUSED_LABEL
  if (
#line 2216 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT))
    {
      return 130;  /* truncdiqi2 */
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L1878: ATTRIBUTE_UNUSED_LABEL
  if (
#line 3618 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_MIPS16
   && (register_operand (operands[0], QImode)
       || reg_or_0_operand (operands[1], QImode))))
    {
      return 229;  /* *movqi_internal */
    }
 L1882: ATTRIBUTE_UNUSED_LABEL
  if (
#line 3637 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_MIPS16
   && (register_operand (operands[0], QImode)
       || register_operand (operands[1], QImode))))
    {
      return 230;  /* *movqi_mips16 */
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L4462: ATTRIBUTE_UNUSED_LABEL
  if (memory_operand (x1, BLKmode))
    {
      operands[0] = x1;
      goto L1635;
    }
  goto L2075;

 L1635: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == BLKmode)
    goto L4907;
  x1 = XEXP (x0, 0);
  goto L2075;

 L4907: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x1) == UNSPEC)
    goto L4909;
  x1 = XEXP (x0, 0);
  goto L2075;

 L4909: ATTRIBUTE_UNUSED_LABEL
  switch (XVECLEN (x1, 0))
    {
    case 2:
      goto L4911;
    case 3:
      goto L4912;
    default:
      break;
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L4911: ATTRIBUTE_UNUSED_LABEL
  if (XINT (x1, 1) == 20)
    goto L1636;
  x1 = XEXP (x0, 0);
  goto L2075;

 L1636: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (reg_or_0_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L1637;
    }
 L1642: ATTRIBUTE_UNUSED_LABEL
  if (reg_or_0_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L1643;
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L1637: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (memory_operand (x2, QImode))
    {
      operands[2] = x2;
      goto L1638;
    }
  x2 = XVECEXP (x1, 0, 0);
  goto L1642;

 L1638: ATTRIBUTE_UNUSED_LABEL
  if (
#line 2965 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_MIPS16 && mips_mem_fits_mode_p (SImode, operands[0])))
    {
      return 186;  /* mov_swl */
    }
  x1 = XEXP (x0, 1);
  x2 = XVECEXP (x1, 0, 0);
  goto L1642;

 L1643: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (memory_operand (x2, QImode))
    {
      operands[2] = x2;
      goto L1644;
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L1644: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 2965 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_MIPS16 && mips_mem_fits_mode_p (DImode, operands[0])) && 
#line 402 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT)))
    {
      return 187;  /* mov_sdl */
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L4912: ATTRIBUTE_UNUSED_LABEL
  if (XINT (x1, 1) == 21)
    goto L1648;
  x1 = XEXP (x0, 0);
  goto L2075;

 L1648: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (reg_or_0_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L1649;
    }
 L1654: ATTRIBUTE_UNUSED_LABEL
  if (reg_or_0_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L1655;
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L1649: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (memory_operand (x2, QImode))
    {
      operands[2] = x2;
      goto L1650;
    }
  x2 = XVECEXP (x1, 0, 0);
  goto L1654;

 L1650: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 2);
  if (rtx_equal_p (x2, operands[0])
      && 
#line 2976 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_MIPS16 && mips_mem_fits_mode_p (SImode, operands[0])))
    {
      return 188;  /* mov_swr */
    }
  x2 = XVECEXP (x1, 0, 0);
  goto L1654;

 L1655: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (memory_operand (x2, QImode))
    {
      operands[2] = x2;
      goto L1656;
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L1656: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 2);
  if (rtx_equal_p (x2, operands[0])
      && (
#line 2976 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_MIPS16 && mips_mem_fits_mode_p (DImode, operands[0])) && 
#line 402 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT)))
    {
      return 189;  /* mov_sdr */
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L4467: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x1, CCmode))
    {
      operands[0] = x1;
      goto L1781;
    }
 L4474: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, CCmode))
    {
      operands[0] = x1;
      goto L2383;
    }
  goto L2075;

 L1781: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (general_operand (x1, CCmode))
    {
      operands[1] = x1;
      goto L1782;
    }
  x1 = XEXP (x0, 0);
  goto L4474;

 L1782: ATTRIBUTE_UNUSED_LABEL
  if (
#line 3421 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_8CC && TARGET_HARD_FLOAT))
    {
      return 214;  /* movcc */
    }
  x1 = XEXP (x0, 0);
  goto L4474;

 L2383: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == CCmode)
    goto L4913;
  x1 = XEXP (x0, 0);
  goto L2075;

 L4913: ATTRIBUTE_UNUSED_LABEL
  tem = recog_6 (x0, insn, pnum_clobbers);
  if (tem >= 0)
    return tem;
  x1 = XEXP (x0, 0);
  goto L2075;

 L4476: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, CCV4mode))
    {
      operands[0] = x1;
      goto L2992;
    }
  goto L2075;

 L2992: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == CCV4mode)
    goto L4950;
  x1 = XEXP (x0, 0);
  goto L2075;

 L4950: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x1) == UNSPEC)
    goto L4952;
  x1 = XEXP (x0, 0);
  goto L2075;

 L4952: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x1, 0) == 5)
    goto L4954;
  x1 = XEXP (x0, 0);
  goto L2075;

 L4954: ATTRIBUTE_UNUSED_LABEL
  switch (XINT (x1, 1))
    {
    case 201L:
      goto L2993;
    case 203L:
      goto L3002;
    default:
      break;
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L2993: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V2SFmode))
    {
      operands[1] = x2;
      goto L2994;
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L2994: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V2SFmode))
    {
      operands[2] = x2;
      goto L2995;
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L2995: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 2);
  if (register_operand (x2, V2SFmode))
    {
      operands[3] = x2;
      goto L2996;
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L2996: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 3);
  if (register_operand (x2, V2SFmode))
    {
      operands[4] = x2;
      goto L2997;
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L2997: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 4);
  if (const_int_operand (x2, VOIDmode))
    {
      operands[5] = x2;
      goto L2998;
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L2998: ATTRIBUTE_UNUSED_LABEL
  if (
#line 307 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-ps-3d.md"
(TARGET_PAIRED_SINGLE_FLOAT))
    {
      return 394;  /* mips_c_cond_4s */
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L3002: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V2SFmode))
    {
      operands[1] = x2;
      goto L3003;
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L3003: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V2SFmode))
    {
      operands[2] = x2;
      goto L3004;
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L3004: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 2);
  if (register_operand (x2, V2SFmode))
    {
      operands[3] = x2;
      goto L3005;
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L3005: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 3);
  if (register_operand (x2, V2SFmode))
    {
      operands[4] = x2;
      goto L3006;
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L3006: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 4);
  if (const_int_operand (x2, VOIDmode))
    {
      operands[5] = x2;
      goto L3007;
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L3007: ATTRIBUTE_UNUSED_LABEL
  if (
#line 336 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-ps-3d.md"
(TARGET_MIPS3D))
    {
      return 395;  /* mips_cabs_cond_4s */
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L4477: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, CCV2mode))
    {
      operands[0] = x1;
      goto L3010;
    }
  goto L2075;

 L3010: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == CCV2mode)
    goto L4956;
  x1 = XEXP (x0, 0);
  goto L2075;

 L4956: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x1) == UNSPEC)
    goto L4958;
  x1 = XEXP (x0, 0);
  goto L2075;

 L4958: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x1, 0) == 3)
    goto L4960;
  x1 = XEXP (x0, 0);
  goto L2075;

 L4960: ATTRIBUTE_UNUSED_LABEL
  switch (XINT (x1, 1))
    {
    case 201L:
      goto L3011;
    case 203L:
      goto L3018;
    default:
      break;
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L3011: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V2SFmode))
    {
      operands[1] = x2;
      goto L3012;
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L3012: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V2SFmode))
    {
      operands[2] = x2;
      goto L3013;
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L3013: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 2);
  if (const_int_operand (x2, VOIDmode))
    {
      operands[3] = x2;
      goto L3014;
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L3014: ATTRIBUTE_UNUSED_LABEL
  if (
#line 368 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-ps-3d.md"
(TARGET_PAIRED_SINGLE_FLOAT))
    {
      return 396;  /* mips_c_cond_ps */
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L3018: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V2SFmode))
    {
      operands[1] = x2;
      goto L3019;
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L3019: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V2SFmode))
    {
      operands[2] = x2;
      goto L3020;
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L3020: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 2);
  if (const_int_operand (x2, VOIDmode))
    {
      operands[3] = x2;
      goto L3021;
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L3021: ATTRIBUTE_UNUSED_LABEL
  if (
#line 379 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-ps-3d.md"
(TARGET_MIPS3D))
    {
      return 397;  /* mips_cabs_cond_ps */
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L4478: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, V4QImode))
    {
      operands[0] = x1;
      goto L3288;
    }
  goto L2075;

 L3288: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == V4QImode)
    goto L4962;
  x1 = XEXP (x0, 0);
  goto L2075;

 L4962: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x1) == UNSPEC)
    goto L4966;
  x1 = XEXP (x0, 0);
  goto L2075;

 L4966: ATTRIBUTE_UNUSED_LABEL
  switch (XVECLEN (x1, 0))
    {
    case 2:
      goto L4970;
    case 1:
      goto L4972;
    case 3:
      goto L4973;
    default:
      break;
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L4970: ATTRIBUTE_UNUSED_LABEL
  switch (XINT (x1, 1))
    {
    case 309L:
      goto L3289;
    case 325L:
      goto L3417;
    default:
      break;
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L3289: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V2HImode))
    {
      operands[1] = x2;
      goto L3290;
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L3290: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V2HImode))
    {
      operands[2] = x2;
      goto L3291;
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L3291: ATTRIBUTE_UNUSED_LABEL
  if (
#line 158 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP))
    {
      return 430;  /* mips_precrq_qb_ph */
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L3417: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V4QImode))
    {
      operands[1] = x2;
      goto L3418;
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L3418: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (arith_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L3419;
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L3419: ATTRIBUTE_UNUSED_LABEL
  if (
#line 347 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP))
    {
      return 448;  /* mips_shrl_qb */
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L4972: ATTRIBUTE_UNUSED_LABEL
  if (XINT (x1, 1) == 348)
    goto L3723;
  x1 = XEXP (x0, 0);
  goto L2075;

 L3723: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (arith_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L3724;
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L3724: ATTRIBUTE_UNUSED_LABEL
  if (
#line 689 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP))
    {
      return 472;  /* mips_repl_qb */
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L4973: ATTRIBUTE_UNUSED_LABEL
  if (XINT (x1, 1) == 356)
    goto L3793;
  x1 = XEXP (x0, 0);
  goto L2075;

 L3793: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V4QImode))
    {
      operands[1] = x2;
      goto L3794;
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L3794: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V4QImode))
    {
      operands[2] = x2;
      goto L3795;
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L3795: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 2);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 186
      && (
#line 785 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP) && 
#line 16 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP)))
    {
      return 484;  /* mips_pick_qb */
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L4479: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, V2HImode))
    {
      operands[0] = x1;
      goto L3294;
    }
  goto L2075;

 L3294: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == V2HImode)
    goto L4974;
  x1 = XEXP (x0, 0);
  goto L2075;

 L4974: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x1) == UNSPEC)
    goto L4988;
  x1 = XEXP (x0, 0);
  goto L2075;

 L4988: ATTRIBUTE_UNUSED_LABEL
  switch (XVECLEN (x1, 0))
    {
    case 2:
      goto L5002;
    case 1:
      goto L5003;
    case 3:
      goto L5014;
    default:
      break;
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L5002: ATTRIBUTE_UNUSED_LABEL
  switch (XINT (x1, 1))
    {
    case 310L:
      goto L3295;
    case 326L:
      goto L3423;
    case 327L:
      goto L3435;
    case 357L:
      goto L3799;
    default:
      break;
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L3295: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L3296;
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L3296: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L3297;
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L3297: ATTRIBUTE_UNUSED_LABEL
  if (
#line 168 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP))
    {
      return 431;  /* mips_precrq_ph_w */
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L3423: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V2HImode))
    {
      operands[1] = x2;
      goto L3424;
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L3424: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (arith_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L3425;
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L3425: ATTRIBUTE_UNUSED_LABEL
  if (
#line 366 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP))
    {
      return 449;  /* mips_shra_ph */
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L3435: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V2HImode))
    {
      operands[1] = x2;
      goto L3436;
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L3436: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (arith_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L3437;
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L3437: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 384 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP) && 
#line 20 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP)))
    {
      return 451;  /* mips_shra_r_ph */
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L3799: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V2HImode))
    {
      operands[1] = x2;
      goto L3800;
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L3800: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V2HImode))
    {
      operands[2] = x2;
      goto L3801;
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L3801: ATTRIBUTE_UNUSED_LABEL
  if (
#line 796 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP))
    {
      return 485;  /* mips_packrl_ph */
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L5003: ATTRIBUTE_UNUSED_LABEL
  switch (XINT (x1, 1))
    {
    case 315L:
      goto L3333;
    case 316L:
      goto L3338;
    case 317L:
      goto L3343;
    case 318L:
      goto L3348;
    case 319L:
      goto L3353;
    case 320L:
      goto L3358;
    case 321L:
      goto L3363;
    case 322L:
      goto L3368;
    case 349L:
      goto L3728;
    default:
      break;
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L3333: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V4QImode))
    {
      operands[1] = x2;
      goto L3334;
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L3334: ATTRIBUTE_UNUSED_LABEL
  if (
#line 226 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP))
    {
      return 436;  /* mips_precequ_ph_qbl */
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L3338: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V4QImode))
    {
      operands[1] = x2;
      goto L3339;
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L3339: ATTRIBUTE_UNUSED_LABEL
  if (
#line 235 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP))
    {
      return 437;  /* mips_precequ_ph_qbr */
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L3343: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V4QImode))
    {
      operands[1] = x2;
      goto L3344;
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L3344: ATTRIBUTE_UNUSED_LABEL
  if (
#line 244 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP))
    {
      return 438;  /* mips_precequ_ph_qbla */
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L3348: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V4QImode))
    {
      operands[1] = x2;
      goto L3349;
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L3349: ATTRIBUTE_UNUSED_LABEL
  if (
#line 253 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP))
    {
      return 439;  /* mips_precequ_ph_qbra */
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L3353: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V4QImode))
    {
      operands[1] = x2;
      goto L3354;
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L3354: ATTRIBUTE_UNUSED_LABEL
  if (
#line 263 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP))
    {
      return 440;  /* mips_preceu_ph_qbl */
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L3358: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V4QImode))
    {
      operands[1] = x2;
      goto L3359;
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L3359: ATTRIBUTE_UNUSED_LABEL
  if (
#line 272 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP))
    {
      return 441;  /* mips_preceu_ph_qbr */
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L3363: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V4QImode))
    {
      operands[1] = x2;
      goto L3364;
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L3364: ATTRIBUTE_UNUSED_LABEL
  if (
#line 281 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP))
    {
      return 442;  /* mips_preceu_ph_qbla */
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L3368: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V4QImode))
    {
      operands[1] = x2;
      goto L3369;
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L3369: ATTRIBUTE_UNUSED_LABEL
  if (
#line 290 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP))
    {
      return 443;  /* mips_preceu_ph_qbra */
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L3728: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (reg_imm10_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L3729;
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L3729: ATTRIBUTE_UNUSED_LABEL
  if (
#line 706 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP))
    {
      return 473;  /* mips_repl_ph */
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L5014: ATTRIBUTE_UNUSED_LABEL
  if (XINT (x1, 1) == 356)
    goto L3787;
  x1 = XEXP (x0, 0);
  goto L2075;

 L3787: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V2HImode))
    {
      operands[1] = x2;
      goto L3788;
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L3788: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V2HImode))
    {
      operands[2] = x2;
      goto L3789;
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L3789: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 2);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 186
      && (
#line 785 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP) && 
#line 15 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP)))
    {
      return 483;  /* mips_pick_ph */
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L4480: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x1) == REG
      && XINT (x1, 0) == 186)
    goto L3732;
  goto L2075;

 L3732: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == CCDSPmode)
    goto L5016;
  x1 = XEXP (x0, 0);
  goto L2075;

 L5016: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x1) == UNSPEC)
    goto L5019;
  x1 = XEXP (x0, 0);
  goto L2075;

 L5019: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x1, 0) == 3)
    goto L5022;
  x1 = XEXP (x0, 0);
  goto L2075;

 L5022: ATTRIBUTE_UNUSED_LABEL
  switch (XINT (x1, 1))
    {
    case 350L:
      goto L3733;
    case 351L:
      goto L3745;
    case 352L:
      goto L3757;
    default:
      break;
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L3733: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  switch (GET_MODE (x2))
    {
    case V2HImode:
      goto L5025;
    case V4QImode:
      goto L5026;
    default:
      break;
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L5025: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, V2HImode))
    {
      operands[0] = x2;
      goto L3734;
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L3734: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V2HImode))
    {
      operands[1] = x2;
      goto L3735;
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L3735: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 2);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 186
      && (
#line 721 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP) && 
#line 15 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP)))
    {
      return 474;  /* mips_cmp_eq_ph */
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L5026: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, V4QImode))
    {
      operands[0] = x2;
      goto L3740;
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L3740: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V4QImode))
    {
      operands[1] = x2;
      goto L3741;
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L3741: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 2);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 186
      && (
#line 721 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP) && 
#line 16 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP)))
    {
      return 475;  /* mips_cmpu_eq_qb */
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L3745: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  switch (GET_MODE (x2))
    {
    case V2HImode:
      goto L5027;
    case V4QImode:
      goto L5028;
    default:
      break;
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L5027: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, V2HImode))
    {
      operands[0] = x2;
      goto L3746;
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L3746: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V2HImode))
    {
      operands[1] = x2;
      goto L3747;
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L3747: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 2);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 186
      && (
#line 732 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP) && 
#line 15 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP)))
    {
      return 476;  /* mips_cmp_lt_ph */
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L5028: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, V4QImode))
    {
      operands[0] = x2;
      goto L3752;
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L3752: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V4QImode))
    {
      operands[1] = x2;
      goto L3753;
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L3753: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 2);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 186
      && (
#line 732 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP) && 
#line 16 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP)))
    {
      return 477;  /* mips_cmpu_lt_qb */
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L3757: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  switch (GET_MODE (x2))
    {
    case V2HImode:
      goto L5029;
    case V4QImode:
      goto L5030;
    default:
      break;
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L5029: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, V2HImode))
    {
      operands[0] = x2;
      goto L3758;
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L3758: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V2HImode))
    {
      operands[1] = x2;
      goto L3759;
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L3759: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 2);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 186
      && (
#line 743 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP) && 
#line 15 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP)))
    {
      return 478;  /* mips_cmp_le_ph */
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L5030: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, V4QImode))
    {
      operands[0] = x2;
      goto L3764;
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L3764: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V4QImode))
    {
      operands[1] = x2;
      goto L3765;
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L3765: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 2);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 186
      && (
#line 743 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP) && 
#line 16 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP)))
    {
      return 479;  /* mips_cmpu_le_qb */
    }
  x1 = XEXP (x0, 0);
  goto L2075;

 L2525: ATTRIBUTE_UNUSED_LABEL
  return recog_7 (x0, insn, pnum_clobbers);

 L2595: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_CODE (x1) == CALL)
    goto L2596;
  goto ret0;

 L2596: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == MEM)
    goto L2597;
  goto ret0;

 L2597: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (call_insn_operand (x3, VOIDmode))
    {
      operands[1] = x3;
      goto L2598;
    }
  goto ret0;

 L2598: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  operands[2] = x2;
  goto L2599;

 L2599: ATTRIBUTE_UNUSED_LABEL
  if (
#line 5054 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_SIBCALLS && SIBLING_CALL_P (insn)))
    {
      return 350;  /* sibcall_value_internal */
    }
 L2654: ATTRIBUTE_UNUSED_LABEL
  if (pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 354;  /* call_value_internal */
    }
 L2672: ATTRIBUTE_UNUSED_LABEL
  if (
#line 5185 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_SPLIT_CALLS)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 2;
      return 355;  /* call_value_split */
    }
  goto ret0;
 ret0:
  return -1;
}

static int
recog_9 (rtx x0 ATTRIBUTE_UNUSED,
	rtx insn ATTRIBUTE_UNUSED,
	int *pnum_clobbers ATTRIBUTE_UNUSED)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x1 ATTRIBUTE_UNUSED;
  rtx x2 ATTRIBUTE_UNUSED;
  rtx x3 ATTRIBUTE_UNUSED;
  rtx x4 ATTRIBUTE_UNUSED;
  rtx x5 ATTRIBUTE_UNUSED;
  rtx x6 ATTRIBUTE_UNUSED;
  rtx x7 ATTRIBUTE_UNUSED;
  int tem ATTRIBUTE_UNUSED;

  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  switch (GET_CODE (x2))
    {
    case MULT:
      goto L163;
    case PLUS:
      goto L284;
    case MINUS:
      goto L305;
    case NEG:
      goto L438;
    case TRUNCATE:
      goto L675;
    case UNSPEC:
      goto L5060;
    default:
     break;
   }
  goto ret0;

 L163: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L164;
    }
  goto ret0;

 L164: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L165;
    }
  goto ret0;

 L165: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L166;
  goto ret0;

 L166: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L167;
    }
  goto ret0;

 L167: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L168;
  goto ret0;

 L168: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L169;
    }
  goto ret0;

 L169: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1028 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(GENERATE_MULT3_SI))
    {
      return 27;  /* mulsi3_mult3 */
    }
 L233: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1099 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_FIX_R4000))
    {
      return 31;  /* mulsi3_r4000 */
    }
  goto ret0;

 L284: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == MULT)
    goto L285;
  goto ret0;

 L285: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L286;
    }
  goto ret0;

 L286: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (register_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L287;
    }
  goto ret0;

 L287: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, SImode))
    {
      operands[3] = x3;
      goto L288;
    }
 L352: ATTRIBUTE_UNUSED_LABEL
  if (rtx_equal_p (x3, operands[0]))
    goto L353;
  goto ret0;

 L288: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L289;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L352;

 L289: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L290;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L352;

 L290: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L291;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L352;

 L291: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[5] = x2;
      goto L292;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L352;

 L292: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1218 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_MACC))
    {
      return 34;  /* *macc */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L352;

 L353: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L354;
  goto ret0;

 L354: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L355;
    }
  goto ret0;

 L355: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L356;
  goto ret0;

 L356: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == MULT)
    goto L357;
  goto ret0;

 L357: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L358;
  goto ret0;

 L358: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (rtx_equal_p (x4, operands[2]))
    goto L359;
  goto ret0;

 L359: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[0]))
    goto L360;
  goto ret0;

 L360: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L361;
  goto ret0;

 L361: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L362;
    }
  goto ret0;

 L362: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1289 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_MACC && reload_completed))
    {
      return 37;  /* *macc2 */
    }
  goto ret0;

 L305: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L306;
    }
 L382: ATTRIBUTE_UNUSED_LABEL
  if (rtx_equal_p (x3, operands[0]))
    goto L383;
  goto ret0;

 L306: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == MULT)
    goto L307;
  x3 = XEXP (x2, 0);
  goto L382;

 L307: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L308;
    }
  x3 = XEXP (x2, 0);
  goto L382;

 L308: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (register_operand (x4, SImode))
    {
      operands[3] = x4;
      goto L309;
    }
  x3 = XEXP (x2, 0);
  goto L382;

 L309: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L310;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L382;

 L310: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L311;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L382;

 L311: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L312;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L382;

 L312: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[5] = x2;
      goto L313;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L382;

 L313: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1240 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_MSAC))
    {
      return 35;  /* *msac */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L382;

 L383: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == MULT)
    goto L384;
  goto ret0;

 L384: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L385;
    }
  goto ret0;

 L385: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (register_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L386;
    }
  goto ret0;

 L386: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L387;
  goto ret0;

 L387: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L388;
    }
  goto ret0;

 L388: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == MINUS)
    goto L389;
  goto ret0;

 L389: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[0]))
    goto L390;
  goto ret0;

 L390: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == MULT)
    goto L391;
  goto ret0;

 L391: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L392;
  goto ret0;

 L392: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (rtx_equal_p (x4, operands[2]))
    goto L393;
  goto ret0;

 L393: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L394;
  goto ret0;

 L394: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L395;
    }
  goto ret0;

 L395: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1304 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_MSAC && reload_completed))
    {
      return 38;  /* *msac2 */
    }
  goto ret0;

 L438: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == MULT)
    goto L439;
  goto ret0;

 L439: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L440;
    }
  goto ret0;

 L440: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (register_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L441;
    }
  goto ret0;

 L441: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L442;
  goto ret0;

 L442: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L443;
    }
  goto ret0;

 L443: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L444;
  goto ret0;

 L444: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L445;
    }
  goto ret0;

 L445: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1472 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_MULS))
    {
      return 40;  /* *muls */
    }
  goto ret0;

 L675: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DImode
      && GET_CODE (x3) == LSHIFTRT)
    goto L676;
  goto ret0;

 L676: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == DImode)
    goto L5063;
  goto ret0;

 L5063: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x4))
    {
    case MULT:
      goto L677;
    case NEG:
      goto L729;
    default:
     break;
   }
  goto ret0;

 L677: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (GET_MODE (x5) == DImode)
    goto L5065;
  goto ret0;

 L5065: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x5))
    {
    case SIGN_EXTEND:
      goto L678;
    case ZERO_EXTEND:
      goto L704;
    default:
     break;
   }
  goto ret0;

 L678: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (register_operand (x6, SImode))
    {
      operands[1] = x6;
      goto L679;
    }
  goto ret0;

 L679: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (GET_MODE (x5) == DImode
      && GET_CODE (x5) == SIGN_EXTEND)
    goto L680;
  goto ret0;

 L680: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (register_operand (x6, SImode))
    {
      operands[2] = x6;
      goto L681;
    }
  goto ret0;

 L681: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (x4 == const_int_rtx[MAX_SAVED_CONST_INT + (32)])
    goto L682;
  goto ret0;

 L682: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L683;
  goto ret0;

 L683: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L684;
    }
  goto ret0;

 L684: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L685;
  goto ret0;

 L685: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L686;
    }
  goto ret0;

 L686: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1658 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_MULHI))
    {
      return 55;  /* smulsi3_highpart_mulhi_internal */
    }
  goto ret0;

 L704: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (register_operand (x6, SImode))
    {
      operands[1] = x6;
      goto L705;
    }
  goto ret0;

 L705: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (GET_MODE (x5) == DImode
      && GET_CODE (x5) == ZERO_EXTEND)
    goto L706;
  goto ret0;

 L706: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (register_operand (x6, SImode))
    {
      operands[2] = x6;
      goto L707;
    }
  goto ret0;

 L707: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (x4 == const_int_rtx[MAX_SAVED_CONST_INT + (32)])
    goto L708;
  goto ret0;

 L708: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L709;
  goto ret0;

 L709: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L710;
    }
  goto ret0;

 L710: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L711;
  goto ret0;

 L711: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L712;
    }
  goto ret0;

 L712: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1658 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_MULHI))
    {
      return 56;  /* umulsi3_highpart_mulhi_internal */
    }
  goto ret0;

 L729: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (GET_MODE (x5) == DImode
      && GET_CODE (x5) == MULT)
    goto L730;
  goto ret0;

 L730: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (GET_MODE (x6) == DImode)
    goto L5067;
  goto ret0;

 L5067: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x6))
    {
    case SIGN_EXTEND:
      goto L731;
    case ZERO_EXTEND:
      goto L759;
    default:
     break;
   }
  goto ret0;

 L731: ATTRIBUTE_UNUSED_LABEL
  x7 = XEXP (x6, 0);
  if (register_operand (x7, SImode))
    {
      operands[1] = x7;
      goto L732;
    }
  goto ret0;

 L732: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 1);
  if (GET_MODE (x6) == DImode
      && GET_CODE (x6) == SIGN_EXTEND)
    goto L733;
  goto ret0;

 L733: ATTRIBUTE_UNUSED_LABEL
  x7 = XEXP (x6, 0);
  if (register_operand (x7, SImode))
    {
      operands[2] = x7;
      goto L734;
    }
  goto ret0;

 L734: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (x4 == const_int_rtx[MAX_SAVED_CONST_INT + (32)])
    goto L735;
  goto ret0;

 L735: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L736;
  goto ret0;

 L736: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L737;
    }
  goto ret0;

 L737: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L738;
  goto ret0;

 L738: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L739;
    }
  goto ret0;

 L739: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1676 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_MULHI))
    {
      return 57;  /* *smulsi3_highpart_neg_mulhi_internal */
    }
  goto ret0;

 L759: ATTRIBUTE_UNUSED_LABEL
  x7 = XEXP (x6, 0);
  if (register_operand (x7, SImode))
    {
      operands[1] = x7;
      goto L760;
    }
  goto ret0;

 L760: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 1);
  if (GET_MODE (x6) == DImode
      && GET_CODE (x6) == ZERO_EXTEND)
    goto L761;
  goto ret0;

 L761: ATTRIBUTE_UNUSED_LABEL
  x7 = XEXP (x6, 0);
  if (register_operand (x7, SImode))
    {
      operands[2] = x7;
      goto L762;
    }
  goto ret0;

 L762: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (x4 == const_int_rtx[MAX_SAVED_CONST_INT + (32)])
    goto L763;
  goto ret0;

 L763: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L764;
  goto ret0;

 L764: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L765;
    }
  goto ret0;

 L765: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L766;
  goto ret0;

 L766: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L767;
    }
  goto ret0;

 L767: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1676 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_MULHI))
    {
      return 58;  /* *umulsi3_highpart_neg_mulhi_internal */
    }
  goto ret0;

 L5060: ATTRIBUTE_UNUSED_LABEL
  switch (XVECLEN (x2, 0))
    {
    case 2:
      goto L5069;
    case 3:
      goto L5071;
    default:
      break;
    }
  goto ret0;

 L5069: ATTRIBUTE_UNUSED_LABEL
  switch (XINT (x2, 1))
    {
    case 331L:
      goto L3517;
    case 332L:
      goto L3542;
    default:
      break;
    }
  goto ret0;

 L3517: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, V2HImode))
    {
      operands[1] = x3;
      goto L3518;
    }
  goto ret0;

 L3518: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (register_operand (x3, V2HImode))
    {
      operands[2] = x3;
      goto L3519;
    }
  goto ret0;

 L3519: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3520;
  goto ret0;

 L3520: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 185)
    goto L3521;
  goto ret0;

 L3521: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 2
      && XINT (x2, 1) == 331)
    goto L3522;
  goto ret0;

 L3522: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L3523;
  goto ret0;

 L3523: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (rtx_equal_p (x3, operands[2]))
    goto L3524;
  goto ret0;

 L3524: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L3525;
  goto ret0;

 L3525: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[3] = x2;
      goto L3526;
    }
  goto ret0;

 L3526: ATTRIBUTE_UNUSED_LABEL
  if (
#line 453 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP))
    {
      return 455;  /* mips_muleq_s_w_phl */
    }
  goto ret0;

 L3542: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, V2HImode))
    {
      operands[1] = x3;
      goto L3543;
    }
  goto ret0;

 L3543: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (register_operand (x3, V2HImode))
    {
      operands[2] = x3;
      goto L3544;
    }
  goto ret0;

 L3544: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3545;
  goto ret0;

 L3545: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 185)
    goto L3546;
  goto ret0;

 L3546: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 2
      && XINT (x2, 1) == 332)
    goto L3547;
  goto ret0;

 L3547: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L3548;
  goto ret0;

 L3548: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (rtx_equal_p (x3, operands[2]))
    goto L3549;
  goto ret0;

 L3549: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L3550;
  goto ret0;

 L3550: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[3] = x2;
      goto L3551;
    }
  goto ret0;

 L3551: ATTRIBUTE_UNUSED_LABEL
  if (
#line 467 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP))
    {
      return 456;  /* mips_muleq_s_w_phr */
    }
  goto ret0;

 L5071: ATTRIBUTE_UNUSED_LABEL
  if (XINT (x2, 1) == 363)
    goto L3862;
  goto ret0;

 L3862: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L3863;
    }
  goto ret0;

 L3863: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (arith_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L3864;
    }
  goto ret0;

 L3864: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 2);
  if (GET_MODE (x3) == CCDSPmode
      && GET_CODE (x3) == REG
      && XINT (x3, 0) == 182)
    goto L3865;
  goto ret0;

 L3865: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3866;
  goto ret0;

 L3866: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 182)
    goto L3867;
  goto ret0;

 L3867: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 3
      && XINT (x2, 1) == 363)
    goto L3868;
  goto ret0;

 L3868: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L3869;
  goto ret0;

 L3869: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (rtx_equal_p (x3, operands[2]))
    goto L3870;
  goto ret0;

 L3870: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 2);
  if (GET_MODE (x3) == CCDSPmode
      && GET_CODE (x3) == REG
      && XINT (x3, 0) == 182)
    goto L3871;
  goto ret0;

 L3871: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == SET)
    goto L3872;
  goto ret0;

 L3872: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 187)
    goto L3873;
  goto ret0;

 L3873: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 2
      && XINT (x2, 1) == 363)
    goto L3874;
  goto ret0;

 L3874: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L3875;
  goto ret0;

 L3875: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (rtx_equal_p (x3, operands[2])
      && 
#line 923 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP && !TARGET_64BIT))
    {
      return 491;  /* mips_extpdp */
    }
  goto ret0;
 ret0:
  return -1;
}

static int
recog_10 (rtx x0 ATTRIBUTE_UNUSED,
	rtx insn ATTRIBUTE_UNUSED,
	int *pnum_clobbers ATTRIBUTE_UNUSED)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x1 ATTRIBUTE_UNUSED;
  rtx x2 ATTRIBUTE_UNUSED;
  rtx x3 ATTRIBUTE_UNUSED;
  rtx x4 ATTRIBUTE_UNUSED;
  rtx x5 ATTRIBUTE_UNUSED;
  rtx x6 ATTRIBUTE_UNUSED;
  rtx x7 ATTRIBUTE_UNUSED;
  int tem ATTRIBUTE_UNUSED;

  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  switch (XVECLEN (x2, 0))
    {
    case 2:
      goto L5123;
    case 3:
      goto L5126;
    case 1:
      goto L5127;
    default:
      break;
    }
  goto ret0;

 L5123: ATTRIBUTE_UNUSED_LABEL
  switch (XINT (x2, 1))
    {
    case 301L:
      goto L3150;
    case 303L:
      goto L3205;
    case 304L:
      goto L3238;
    case 324L:
      goto L3396;
    case 331L:
      goto L3531;
    case 332L:
      goto L3556;
    case 358L:
      goto L3806;
    case 359L:
      goto L3817;
    case 360L:
      goto L3828;
    case 361L:
      goto L3839;
    default:
      break;
    }
  goto ret0;

 L3150: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L3151;
    }
  goto ret0;

 L3151: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (register_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L3152;
    }
  goto ret0;

 L3152: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3153;
  goto ret0;

 L3153: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 185)
    goto L3154;
  goto ret0;

 L3154: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 2
      && XINT (x2, 1) == 301)
    goto L3155;
  goto ret0;

 L3155: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L3156;
  goto ret0;

 L3156: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (rtx_equal_p (x3, operands[2])
      && 
#line 10 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP))
    {
      return 416;  /* mips_addq_s_w */
    }
  goto ret0;

 L3205: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L3206;
    }
  goto ret0;

 L3206: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (register_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L3207;
    }
  goto ret0;

 L3207: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3208;
  goto ret0;

 L3208: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 185)
    goto L3209;
  goto ret0;

 L3209: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 2
      && XINT (x2, 1) == 303)
    goto L3210;
  goto ret0;

 L3210: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L3211;
  goto ret0;

 L3211: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (rtx_equal_p (x3, operands[2])
      && (
#line 84 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP) && 
#line 10 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP)))
    {
      return 421;  /* mips_subq_s_w */
    }
  goto ret0;

 L3238: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L3239;
    }
  goto ret0;

 L3239: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (register_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L3240;
    }
  goto ret0;

 L3240: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3241;
  goto ret0;

 L3241: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 184)
    goto L3242;
  goto ret0;

 L3242: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 2
      && XINT (x2, 1) == 304)
    goto L3243;
  goto ret0;

 L3243: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L3244;
  goto ret0;

 L3244: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (rtx_equal_p (x3, operands[2])
      && 
#line 98 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP))
    {
      return 424;  /* mips_addsc */
    }
  goto ret0;

 L3396: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L3397;
    }
  goto ret0;

 L3397: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (arith_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L3398;
    }
  goto ret0;

 L3398: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3399;
  goto ret0;

 L3399: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 185)
    goto L3400;
  goto ret0;

 L3400: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 2
      && XINT (x2, 1) == 324)
    goto L3401;
  goto ret0;

 L3401: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L3402;
  goto ret0;

 L3402: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (rtx_equal_p (x3, operands[2])
      && (
#line 327 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP) && 
#line 19 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP)))
    {
      return 446;  /* mips_shll_s_w */
    }
  goto ret0;

 L3531: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, V2HImode))
    {
      operands[1] = x3;
      goto L3532;
    }
  goto ret0;

 L3532: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (register_operand (x3, V2HImode))
    {
      operands[2] = x3;
      goto L3533;
    }
  goto ret0;

 L3533: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3534;
  goto ret0;

 L3534: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 185)
    goto L3535;
  goto ret0;

 L3535: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 2
      && XINT (x2, 1) == 331)
    goto L3536;
  goto ret0;

 L3536: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L3537;
  goto ret0;

 L3537: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (rtx_equal_p (x3, operands[2])
      && 
#line 453 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 455;  /* mips_muleq_s_w_phl */
    }
  goto ret0;

 L3556: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, V2HImode))
    {
      operands[1] = x3;
      goto L3557;
    }
  goto ret0;

 L3557: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (register_operand (x3, V2HImode))
    {
      operands[2] = x3;
      goto L3558;
    }
  goto ret0;

 L3558: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3559;
  goto ret0;

 L3559: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 185)
    goto L3560;
  goto ret0;

 L3560: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 2
      && XINT (x2, 1) == 332)
    goto L3561;
  goto ret0;

 L3561: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L3562;
  goto ret0;

 L3562: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (rtx_equal_p (x3, operands[2])
      && 
#line 467 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 456;  /* mips_muleq_s_w_phr */
    }
  goto ret0;

 L3806: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L3807;
    }
  goto ret0;

 L3807: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (arith_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L3808;
    }
  goto ret0;

 L3808: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3809;
  goto ret0;

 L3809: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 185)
    goto L3810;
  goto ret0;

 L3810: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 2
      && XINT (x2, 1) == 358)
    goto L3811;
  goto ret0;

 L3811: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L3812;
  goto ret0;

 L3812: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (rtx_equal_p (x3, operands[2])
      && 
#line 811 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP && !TARGET_64BIT))
    {
      return 486;  /* mips_extr_w */
    }
  goto ret0;

 L3817: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L3818;
    }
  goto ret0;

 L3818: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (arith_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L3819;
    }
  goto ret0;

 L3819: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3820;
  goto ret0;

 L3820: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 185)
    goto L3821;
  goto ret0;

 L3821: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 2
      && XINT (x2, 1) == 359)
    goto L3822;
  goto ret0;

 L3822: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L3823;
  goto ret0;

 L3823: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (rtx_equal_p (x3, operands[2])
      && 
#line 832 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP && !TARGET_64BIT))
    {
      return 487;  /* mips_extr_r_w */
    }
  goto ret0;

 L3828: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L3829;
    }
  goto ret0;

 L3829: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (arith_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L3830;
    }
  goto ret0;

 L3830: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3831;
  goto ret0;

 L3831: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 185)
    goto L3832;
  goto ret0;

 L3832: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 2
      && XINT (x2, 1) == 360)
    goto L3833;
  goto ret0;

 L3833: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L3834;
  goto ret0;

 L3834: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (rtx_equal_p (x3, operands[2])
      && 
#line 853 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP && !TARGET_64BIT))
    {
      return 488;  /* mips_extr_rs_w */
    }
  goto ret0;

 L3839: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L3840;
    }
  goto ret0;

 L3840: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (arith_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L3841;
    }
  goto ret0;

 L3841: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3842;
  goto ret0;

 L3842: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 185)
    goto L3843;
  goto ret0;

 L3843: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 2
      && XINT (x2, 1) == 361)
    goto L3844;
  goto ret0;

 L3844: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L3845;
  goto ret0;

 L3845: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (rtx_equal_p (x3, operands[2])
      && 
#line 875 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP && !TARGET_64BIT))
    {
      return 489;  /* mips_extr_s_h */
    }
  goto ret0;

 L5126: ATTRIBUTE_UNUSED_LABEL
  switch (XINT (x2, 1))
    {
    case 305L:
      goto L3249;
    case 362L:
      goto L3850;
    default:
      break;
    }
  goto ret0;

 L3249: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L3250;
    }
  goto ret0;

 L3250: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (register_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L3251;
    }
  goto ret0;

 L3251: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 2);
  if (GET_MODE (x3) == CCDSPmode
      && GET_CODE (x3) == REG
      && XINT (x3, 0) == 184)
    goto L3252;
  goto ret0;

 L3252: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3253;
  goto ret0;

 L3253: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 185)
    goto L3254;
  goto ret0;

 L3254: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 2
      && XINT (x2, 1) == 305)
    goto L3255;
  goto ret0;

 L3255: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L3256;
  goto ret0;

 L3256: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (rtx_equal_p (x3, operands[2])
      && 
#line 113 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP))
    {
      return 425;  /* mips_addwc */
    }
  goto ret0;

 L3850: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L3851;
    }
  goto ret0;

 L3851: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (arith_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L3852;
    }
  goto ret0;

 L3852: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 2);
  if (GET_MODE (x3) == CCDSPmode
      && GET_CODE (x3) == REG
      && XINT (x3, 0) == 182)
    goto L3853;
  goto ret0;

 L3853: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3854;
  goto ret0;

 L3854: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 187)
    goto L3855;
  goto ret0;

 L3855: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 2
      && XINT (x2, 1) == 362)
    goto L3856;
  goto ret0;

 L3856: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L3857;
  goto ret0;

 L3857: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (rtx_equal_p (x3, operands[2])
      && 
#line 898 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP && !TARGET_64BIT))
    {
      return 490;  /* mips_extp */
    }
  goto ret0;

 L5127: ATTRIBUTE_UNUSED_LABEL
  if (XINT (x2, 1) == 308)
    goto L3272;
  goto ret0;

 L3272: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L3273;
    }
  goto ret0;

 L3273: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3274;
  goto ret0;

 L3274: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 185)
    goto L3275;
  goto ret0;

 L3275: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 1
      && XINT (x2, 1) == 308)
    goto L3276;
  goto ret0;

 L3276: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (rtx_equal_p (x3, operands[1])
      && (
#line 147 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP) && 
#line 19 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP)))
    {
      return 428;  /* mips_absq_s_w */
    }
  goto ret0;
 ret0:
  return -1;
}

static int
recog_11 (rtx x0 ATTRIBUTE_UNUSED,
	rtx insn ATTRIBUTE_UNUSED,
	int *pnum_clobbers ATTRIBUTE_UNUSED)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x1 ATTRIBUTE_UNUSED;
  rtx x2 ATTRIBUTE_UNUSED;
  rtx x3 ATTRIBUTE_UNUSED;
  rtx x4 ATTRIBUTE_UNUSED;
  rtx x5 ATTRIBUTE_UNUSED;
  rtx x6 ATTRIBUTE_UNUSED;
  rtx x7 ATTRIBUTE_UNUSED;
  int tem ATTRIBUTE_UNUSED;

  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  if (XVECLEN (x2, 0) == 3)
    goto L5169;
  goto ret0;

 L5169: ATTRIBUTE_UNUSED_LABEL
  switch (XINT (x2, 1))
    {
    case 337L:
      goto L3595;
    case 338L:
      goto L3608;
    case 339L:
      goto L3621;
    case 340L:
      goto L3634;
    case 341L:
      goto L3647;
    case 342L:
      goto L3660;
    case 343L:
      goto L3673;
    case 344L:
      goto L3686;
    case 345L:
      goto L3699;
    case 365L:
      goto L3886;
    default:
      break;
    }
  goto ret0;

 L3595: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L3596;
    }
  goto ret0;

 L3596: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (register_operand (x3, V2HImode))
    {
      operands[2] = x3;
      goto L3597;
    }
  goto ret0;

 L3597: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 2);
  if (register_operand (x3, V2HImode))
    {
      operands[3] = x3;
      goto L3598;
    }
  goto ret0;

 L3598: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3599;
  goto ret0;

 L3599: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 185)
    goto L3600;
  goto ret0;

 L3600: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 3
      && XINT (x2, 1) == 337)
    goto L3601;
  goto ret0;

 L3601: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L3602;
  goto ret0;

 L3602: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (rtx_equal_p (x3, operands[2]))
    goto L3603;
  goto ret0;

 L3603: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 2);
  if (rtx_equal_p (x3, operands[3])
      && 
#line 529 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP && !TARGET_64BIT))
    {
      return 461;  /* mips_dpaq_s_w_ph */
    }
  goto ret0;

 L3608: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L3609;
    }
  goto ret0;

 L3609: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (register_operand (x3, V2HImode))
    {
      operands[2] = x3;
      goto L3610;
    }
  goto ret0;

 L3610: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 2);
  if (register_operand (x3, V2HImode))
    {
      operands[3] = x3;
      goto L3611;
    }
  goto ret0;

 L3611: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3612;
  goto ret0;

 L3612: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 185)
    goto L3613;
  goto ret0;

 L3613: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 3
      && XINT (x2, 1) == 338)
    goto L3614;
  goto ret0;

 L3614: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L3615;
  goto ret0;

 L3615: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (rtx_equal_p (x3, operands[2]))
    goto L3616;
  goto ret0;

 L3616: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 2);
  if (rtx_equal_p (x3, operands[3])
      && 
#line 545 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP && !TARGET_64BIT))
    {
      return 462;  /* mips_dpsq_s_w_ph */
    }
  goto ret0;

 L3621: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L3622;
    }
  goto ret0;

 L3622: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (register_operand (x3, V2HImode))
    {
      operands[2] = x3;
      goto L3623;
    }
  goto ret0;

 L3623: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 2);
  if (register_operand (x3, V2HImode))
    {
      operands[3] = x3;
      goto L3624;
    }
  goto ret0;

 L3624: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3625;
  goto ret0;

 L3625: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 185)
    goto L3626;
  goto ret0;

 L3626: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 3
      && XINT (x2, 1) == 339)
    goto L3627;
  goto ret0;

 L3627: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L3628;
  goto ret0;

 L3628: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (rtx_equal_p (x3, operands[2]))
    goto L3629;
  goto ret0;

 L3629: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 2);
  if (rtx_equal_p (x3, operands[3])
      && 
#line 561 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP && !TARGET_64BIT))
    {
      return 463;  /* mips_mulsaq_s_w_ph */
    }
  goto ret0;

 L3634: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L3635;
    }
  goto ret0;

 L3635: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (register_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L3636;
    }
  goto ret0;

 L3636: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 2);
  if (register_operand (x3, SImode))
    {
      operands[3] = x3;
      goto L3637;
    }
  goto ret0;

 L3637: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3638;
  goto ret0;

 L3638: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 185)
    goto L3639;
  goto ret0;

 L3639: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 3
      && XINT (x2, 1) == 340)
    goto L3640;
  goto ret0;

 L3640: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L3641;
  goto ret0;

 L3641: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (rtx_equal_p (x3, operands[2]))
    goto L3642;
  goto ret0;

 L3642: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 2);
  if (rtx_equal_p (x3, operands[3])
      && 
#line 577 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP && !TARGET_64BIT))
    {
      return 464;  /* mips_dpaq_sa_l_w */
    }
  goto ret0;

 L3647: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L3648;
    }
  goto ret0;

 L3648: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (register_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L3649;
    }
  goto ret0;

 L3649: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 2);
  if (register_operand (x3, SImode))
    {
      operands[3] = x3;
      goto L3650;
    }
  goto ret0;

 L3650: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3651;
  goto ret0;

 L3651: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 185)
    goto L3652;
  goto ret0;

 L3652: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 3
      && XINT (x2, 1) == 341)
    goto L3653;
  goto ret0;

 L3653: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L3654;
  goto ret0;

 L3654: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (rtx_equal_p (x3, operands[2]))
    goto L3655;
  goto ret0;

 L3655: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 2);
  if (rtx_equal_p (x3, operands[3])
      && 
#line 593 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP && !TARGET_64BIT))
    {
      return 465;  /* mips_dpsq_sa_l_w */
    }
  goto ret0;

 L3660: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L3661;
    }
  goto ret0;

 L3661: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (register_operand (x3, V2HImode))
    {
      operands[2] = x3;
      goto L3662;
    }
  goto ret0;

 L3662: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 2);
  if (register_operand (x3, V2HImode))
    {
      operands[3] = x3;
      goto L3663;
    }
  goto ret0;

 L3663: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3664;
  goto ret0;

 L3664: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 185)
    goto L3665;
  goto ret0;

 L3665: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 3
      && XINT (x2, 1) == 342)
    goto L3666;
  goto ret0;

 L3666: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L3667;
  goto ret0;

 L3667: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (rtx_equal_p (x3, operands[2]))
    goto L3668;
  goto ret0;

 L3668: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 2);
  if (rtx_equal_p (x3, operands[3])
      && 
#line 609 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP && !TARGET_64BIT))
    {
      return 466;  /* mips_maq_s_w_phl */
    }
  goto ret0;

 L3673: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L3674;
    }
  goto ret0;

 L3674: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (register_operand (x3, V2HImode))
    {
      operands[2] = x3;
      goto L3675;
    }
  goto ret0;

 L3675: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 2);
  if (register_operand (x3, V2HImode))
    {
      operands[3] = x3;
      goto L3676;
    }
  goto ret0;

 L3676: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3677;
  goto ret0;

 L3677: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 185)
    goto L3678;
  goto ret0;

 L3678: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 3
      && XINT (x2, 1) == 343)
    goto L3679;
  goto ret0;

 L3679: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L3680;
  goto ret0;

 L3680: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (rtx_equal_p (x3, operands[2]))
    goto L3681;
  goto ret0;

 L3681: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 2);
  if (rtx_equal_p (x3, operands[3])
      && 
#line 624 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP && !TARGET_64BIT))
    {
      return 467;  /* mips_maq_s_w_phr */
    }
  goto ret0;

 L3686: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L3687;
    }
  goto ret0;

 L3687: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (register_operand (x3, V2HImode))
    {
      operands[2] = x3;
      goto L3688;
    }
  goto ret0;

 L3688: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 2);
  if (register_operand (x3, V2HImode))
    {
      operands[3] = x3;
      goto L3689;
    }
  goto ret0;

 L3689: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3690;
  goto ret0;

 L3690: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 185)
    goto L3691;
  goto ret0;

 L3691: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 3
      && XINT (x2, 1) == 344)
    goto L3692;
  goto ret0;

 L3692: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L3693;
  goto ret0;

 L3693: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (rtx_equal_p (x3, operands[2]))
    goto L3694;
  goto ret0;

 L3694: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 2);
  if (rtx_equal_p (x3, operands[3])
      && 
#line 640 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP && !TARGET_64BIT))
    {
      return 468;  /* mips_maq_sa_w_phl */
    }
  goto ret0;

 L3699: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L3700;
    }
  goto ret0;

 L3700: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (register_operand (x3, V2HImode))
    {
      operands[2] = x3;
      goto L3701;
    }
  goto ret0;

 L3701: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 2);
  if (register_operand (x3, V2HImode))
    {
      operands[3] = x3;
      goto L3702;
    }
  goto ret0;

 L3702: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3703;
  goto ret0;

 L3703: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 185)
    goto L3704;
  goto ret0;

 L3704: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 3
      && XINT (x2, 1) == 345)
    goto L3705;
  goto ret0;

 L3705: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L3706;
  goto ret0;

 L3706: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (rtx_equal_p (x3, operands[2]))
    goto L3707;
  goto ret0;

 L3707: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 2);
  if (rtx_equal_p (x3, operands[3])
      && 
#line 655 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP && !TARGET_64BIT))
    {
      return 469;  /* mips_maq_sa_w_phr */
    }
  goto ret0;

 L3886: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L3887;
    }
  goto ret0;

 L3887: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (register_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L3888;
    }
  goto ret0;

 L3888: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 2);
  if (GET_MODE (x3) == CCDSPmode
      && GET_CODE (x3) == REG
      && XINT (x3, 0) == 182)
    goto L3889;
  goto ret0;

 L3889: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3890;
  goto ret0;

 L3890: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 182)
    goto L3891;
  goto ret0;

 L3891: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 3
      && XINT (x2, 1) == 365)
    goto L3892;
  goto ret0;

 L3892: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L3893;
  goto ret0;

 L3893: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (rtx_equal_p (x3, operands[2]))
    goto L3894;
  goto ret0;

 L3894: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 2);
  if (GET_MODE (x3) == CCDSPmode
      && GET_CODE (x3) == REG
      && XINT (x3, 0) == 182
      && 
#line 966 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP && !TARGET_64BIT))
    {
      return 493;  /* mips_mthlip */
    }
  goto ret0;
 ret0:
  return -1;
}

static int
recog_12 (rtx x0 ATTRIBUTE_UNUSED,
	rtx insn ATTRIBUTE_UNUSED,
	int *pnum_clobbers ATTRIBUTE_UNUSED)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x1 ATTRIBUTE_UNUSED;
  rtx x2 ATTRIBUTE_UNUSED;
  rtx x3 ATTRIBUTE_UNUSED;
  rtx x4 ATTRIBUTE_UNUSED;
  rtx x5 ATTRIBUTE_UNUSED;
  rtx x6 ATTRIBUTE_UNUSED;
  rtx x7 ATTRIBUTE_UNUSED;
  int tem ATTRIBUTE_UNUSED;

  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L5082;
    case DImode:
      goto L5083;
    case V2HImode:
      goto L5084;
    case V4QImode:
      goto L5085;
    default:
      break;
    }
 L2533: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == PC)
    goto L2534;
  if (register_operand (x2, VOIDmode))
    {
      operands[0] = x2;
      goto L2603;
    }
  goto ret0;

 L5082: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L196;
    }
  goto L2533;

 L196: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode)
    goto L5086;
  x2 = XEXP (x1, 0);
  goto L2533;

 L5086: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case MULT:
      goto L197;
    case PLUS:
      goto L367;
    case MINUS:
      goto L400;
    case TRUNCATE:
      goto L627;
    case DIV:
      goto L1058;
    case UDIV:
      goto L1080;
    case FIX:
      goto L1522;
    case UNSPEC:
      goto L5106;
    default:
     break;
   }
  x2 = XEXP (x1, 0);
  goto L2533;

 L197: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L198;
    }
  x2 = XEXP (x1, 0);
  goto L2533;

 L198: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L199;
    }
  x2 = XEXP (x1, 0);
  goto L2533;

 L199: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L200;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L200: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L201;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L201: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1088 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_FIX_R4000))
    {
      return 29;  /* mulsi3_internal */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L367: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == MULT)
    goto L368;
  x2 = XEXP (x1, 0);
  goto L2533;

 L368: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L369;
    }
  x2 = XEXP (x1, 0);
  goto L2533;

 L369: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (register_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L370;
    }
  x2 = XEXP (x1, 0);
  goto L2533;

 L370: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[0]))
    goto L371;
  x2 = XEXP (x1, 0);
  goto L2533;

 L371: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  switch (GET_CODE (x1))
    {
    case SET:
      goto L372;
    case CLOBBER:
      goto L836;
    default:
     break;
   }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L372: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L373;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L373: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L374;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L374: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == MULT)
    goto L375;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L375: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L376;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L376: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (rtx_equal_p (x4, operands[2]))
    goto L377;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L377: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[0])
      && 
#line 1289 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_MACC && reload_completed)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 37;  /* *macc2 */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L836: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L837;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L837: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1710 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_MAD))
    {
      return 61;  /* madsi */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L400: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[0]))
    goto L401;
  x2 = XEXP (x1, 0);
  goto L2533;

 L401: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == MULT)
    goto L402;
  x2 = XEXP (x1, 0);
  goto L2533;

 L402: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L403;
    }
  x2 = XEXP (x1, 0);
  goto L2533;

 L403: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (register_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L404;
    }
  x2 = XEXP (x1, 0);
  goto L2533;

 L404: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L405;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L405: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L406;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L406: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == MINUS)
    goto L407;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L407: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[0]))
    goto L408;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L408: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == MULT)
    goto L409;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L409: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L410;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L410: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (rtx_equal_p (x4, operands[2])
      && 
#line 1304 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_MSAC && reload_completed)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 38;  /* *msac2 */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L627: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DImode
      && GET_CODE (x3) == LSHIFTRT)
    goto L628;
  x2 = XEXP (x1, 0);
  goto L2533;

 L628: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == DImode
      && GET_CODE (x4) == MULT)
    goto L629;
  x2 = XEXP (x1, 0);
  goto L2533;

 L629: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (GET_MODE (x5) == DImode)
    goto L5119;
  x2 = XEXP (x1, 0);
  goto L2533;

 L5119: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x5))
    {
    case SIGN_EXTEND:
      goto L630;
    case ZERO_EXTEND:
      goto L654;
    default:
     break;
   }
  x2 = XEXP (x1, 0);
  goto L2533;

 L630: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (register_operand (x6, SImode))
    {
      operands[1] = x6;
      goto L631;
    }
  x2 = XEXP (x1, 0);
  goto L2533;

 L631: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (GET_MODE (x5) == DImode
      && GET_CODE (x5) == SIGN_EXTEND)
    goto L632;
  x2 = XEXP (x1, 0);
  goto L2533;

 L632: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (register_operand (x6, SImode))
    {
      operands[2] = x6;
      goto L633;
    }
  x2 = XEXP (x1, 0);
  goto L2533;

 L633: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (x4 == const_int_rtx[MAX_SAVED_CONST_INT + (32)])
    goto L634;
  x2 = XEXP (x1, 0);
  goto L2533;

 L634: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L635;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L635: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L636;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L636: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1643 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!ISA_HAS_MULHI && !TARGET_FIX_R4000))
    {
      return 53;  /* smulsi3_highpart_internal */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L654: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (register_operand (x6, SImode))
    {
      operands[1] = x6;
      goto L655;
    }
  x2 = XEXP (x1, 0);
  goto L2533;

 L655: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (GET_MODE (x5) == DImode
      && GET_CODE (x5) == ZERO_EXTEND)
    goto L656;
  x2 = XEXP (x1, 0);
  goto L2533;

 L656: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (register_operand (x6, SImode))
    {
      operands[2] = x6;
      goto L657;
    }
  x2 = XEXP (x1, 0);
  goto L2533;

 L657: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (x4 == const_int_rtx[MAX_SAVED_CONST_INT + (32)])
    goto L658;
  x2 = XEXP (x1, 0);
  goto L2533;

 L658: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L659;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L659: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L660;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L660: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1643 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!ISA_HAS_MULHI && !TARGET_FIX_R4000))
    {
      return 54;  /* umulsi3_highpart_internal */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L1058: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L1059;
    }
  x2 = XEXP (x1, 0);
  goto L2533;

 L1059: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L1060;
    }
  x2 = XEXP (x1, 0);
  goto L2533;

 L1060: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L1061;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L1061: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L1062;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L1062: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == MOD)
    goto L1063;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L1063: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L1064;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L1064: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && 
#line 1881 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_FIX_VR4120))
    {
      return 88;  /* divmodsi4 */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L1080: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L1081;
    }
  x2 = XEXP (x1, 0);
  goto L2533;

 L1081: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L1082;
    }
  x2 = XEXP (x1, 0);
  goto L2533;

 L1082: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L1083;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L1083: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L1084;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L1084: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == UMOD)
    goto L1085;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L1085: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L1086;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L1086: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2]))
    {
      return 90;  /* udivmodsi4 */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L1522: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  switch (GET_MODE (x3))
    {
    case DFmode:
      goto L5121;
    case SFmode:
      goto L5122;
    default:
      break;
    }
  x2 = XEXP (x1, 0);
  goto L2533;

 L5121: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x3, DFmode))
    {
      operands[1] = x3;
      goto L1523;
    }
  x2 = XEXP (x1, 0);
  goto L2533;

 L1523: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1524;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L1524: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DFmode))
    {
      operands[2] = x2;
      goto L1525;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L1525: ATTRIBUTE_UNUSED_LABEL
  if (
#line 2545 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT && !ISA_HAS_TRUNC_W))
    {
      return 169;  /* fix_truncdfsi2_macro */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L5122: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x3, SFmode))
    {
      operands[1] = x3;
      goto L1541;
    }
  x2 = XEXP (x1, 0);
  goto L2533;

 L1541: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1542;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L1542: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SFmode))
    {
      operands[2] = x2;
      goto L1543;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L1543: ATTRIBUTE_UNUSED_LABEL
  if (
#line 2583 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && !ISA_HAS_TRUNC_W))
    {
      return 171;  /* fix_truncsfsi2_macro */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L5106: ATTRIBUTE_UNUSED_LABEL
  tem = recog_10 (x0, insn, pnum_clobbers);
  if (tem >= 0)
    return tem;
  x2 = XEXP (x1, 0);
  goto L2533;

 L5083: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L211;
    }
  goto L2533;

 L211: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode)
    goto L5136;
  x2 = XEXP (x1, 0);
  goto L2533;

 L5136: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case MULT:
      goto L212;
    case SIGN_EXTEND:
      goto L557;
    case TRUNCATE:
      goto L783;
    case DIV:
      goto L1069;
    case UDIV:
      goto L1091;
    case UNSPEC:
      goto L5152;
    case CONST:
    case LABEL_REF:
    case SYMBOL_REF:
      goto L5141;
    default:
      x2 = XEXP (x1, 0);
      goto L2533;
   }
 L5141: ATTRIBUTE_UNUSED_LABEL
  if (general_symbolic_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L1666;
    }
  x2 = XEXP (x1, 0);
  goto L2533;

 L212: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DImode)
    goto L5163;
  x2 = XEXP (x1, 0);
  goto L2533;

 L5163: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x3))
    {
    case SIGN_EXTEND:
      goto L474;
    case ZERO_EXTEND:
      goto L493;
    case REG:
    case SUBREG:
      goto L5162;
    default:
      x2 = XEXP (x1, 0);
      goto L2533;
   }
 L5162: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L213;
    }
  x2 = XEXP (x1, 0);
  goto L2533;

 L474: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L475;
    }
  x2 = XEXP (x1, 0);
  goto L2533;

 L475: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == DImode
      && GET_CODE (x3) == SIGN_EXTEND)
    goto L476;
  x2 = XEXP (x1, 0);
  goto L2533;

 L476: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L477;
    }
  x2 = XEXP (x1, 0);
  goto L2533;

 L477: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L478;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L478: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[3] = x2;
      goto L479;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L479: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1517 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_64BIT && TARGET_FIX_R4000))
    {
      return 43;  /* mulsidi3_32bit_r4000 */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L493: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L494;
    }
  x2 = XEXP (x1, 0);
  goto L2533;

 L494: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == DImode
      && GET_CODE (x3) == ZERO_EXTEND)
    goto L495;
  x2 = XEXP (x1, 0);
  goto L2533;

 L495: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L496;
    }
  x2 = XEXP (x1, 0);
  goto L2533;

 L496: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L497;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L497: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[3] = x2;
      goto L498;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L498: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1517 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_64BIT && TARGET_FIX_R4000))
    {
      return 44;  /* umulsidi3_32bit_r4000 */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L213: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L214;
    }
  x2 = XEXP (x1, 0);
  goto L2533;

 L214: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L215;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L215: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[3] = x2;
      goto L216;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L216: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 1088 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_FIX_R4000) && 
#line 402 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT)))
    {
      return 30;  /* muldi3_internal */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L557: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == MULT)
    goto L558;
  x2 = XEXP (x1, 0);
  goto L2533;

 L558: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L559;
    }
  x2 = XEXP (x1, 0);
  goto L2533;

 L559: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (register_operand (x4, SImode))
    {
      operands[3] = x4;
      goto L560;
    }
  x2 = XEXP (x1, 0);
  goto L2533;

 L560: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L561;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L561: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L562;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L562: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == ASHIFTRT)
    goto L563;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L563: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DImode
      && GET_CODE (x3) == MULT)
    goto L564;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L564: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == DImode)
    goto L5165;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L5165: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x4))
    {
    case SIGN_EXTEND:
      goto L565;
    case ZERO_EXTEND:
      goto L581;
    default:
     break;
   }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L565: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (rtx_equal_p (x5, operands[2]))
    goto L566;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L566: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_MODE (x4) == DImode
      && GET_CODE (x4) == SIGN_EXTEND)
    goto L567;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L567: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (rtx_equal_p (x5, operands[3]))
    goto L568;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L568: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (32)]
      && 
#line 1580 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT && !TARGET_FIX_R4000))
    {
      return 47;  /* *mulsidi3_64bit_parts */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L581: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (rtx_equal_p (x5, operands[2]))
    goto L582;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L582: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_MODE (x4) == DImode
      && GET_CODE (x4) == ZERO_EXTEND)
    goto L583;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L583: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (rtx_equal_p (x5, operands[3]))
    goto L584;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L584: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x3 == const_int_rtx[MAX_SAVED_CONST_INT + (32)]
      && 
#line 1580 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT && !TARGET_FIX_R4000))
    {
      return 48;  /* *umulsidi3_64bit_parts */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L783: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == TImode
      && GET_CODE (x3) == LSHIFTRT)
    goto L784;
  x2 = XEXP (x1, 0);
  goto L2533;

 L784: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == TImode
      && GET_CODE (x4) == MULT)
    goto L785;
  x2 = XEXP (x1, 0);
  goto L2533;

 L785: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (GET_MODE (x5) == TImode)
    goto L5167;
  x2 = XEXP (x1, 0);
  goto L2533;

 L5167: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x5))
    {
    case SIGN_EXTEND:
      goto L786;
    case ZERO_EXTEND:
      goto L810;
    default:
     break;
   }
  x2 = XEXP (x1, 0);
  goto L2533;

 L786: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (register_operand (x6, DImode))
    {
      operands[1] = x6;
      goto L787;
    }
  x2 = XEXP (x1, 0);
  goto L2533;

 L787: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (GET_MODE (x5) == TImode
      && GET_CODE (x5) == SIGN_EXTEND)
    goto L788;
  x2 = XEXP (x1, 0);
  goto L2533;

 L788: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (register_operand (x6, DImode))
    {
      operands[2] = x6;
      goto L789;
    }
  x2 = XEXP (x1, 0);
  goto L2533;

 L789: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (x4 == const_int_rtx[MAX_SAVED_CONST_INT + (64)])
    goto L790;
  x2 = XEXP (x1, 0);
  goto L2533;

 L790: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L791;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L791: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[3] = x2;
      goto L792;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L792: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1695 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT && !TARGET_FIX_R4000
   && !(SIGN_EXTEND == ZERO_EXTEND && TARGET_FIX_VR4120)))
    {
      return 59;  /* smuldi3_highpart */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L810: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (register_operand (x6, DImode))
    {
      operands[1] = x6;
      goto L811;
    }
  x2 = XEXP (x1, 0);
  goto L2533;

 L811: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (GET_MODE (x5) == TImode
      && GET_CODE (x5) == ZERO_EXTEND)
    goto L812;
  x2 = XEXP (x1, 0);
  goto L2533;

 L812: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (register_operand (x6, DImode))
    {
      operands[2] = x6;
      goto L813;
    }
  x2 = XEXP (x1, 0);
  goto L2533;

 L813: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (x4 == const_int_rtx[MAX_SAVED_CONST_INT + (64)])
    goto L814;
  x2 = XEXP (x1, 0);
  goto L2533;

 L814: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L815;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L815: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[3] = x2;
      goto L816;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L816: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1695 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT && !TARGET_FIX_R4000
   && !(ZERO_EXTEND == ZERO_EXTEND && TARGET_FIX_VR4120)))
    {
      return 60;  /* umuldi3_highpart */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L1069: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L1070;
    }
  x2 = XEXP (x1, 0);
  goto L2533;

 L1070: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L1071;
    }
  x2 = XEXP (x1, 0);
  goto L2533;

 L1071: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L1072;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L1072: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[3] = x2;
      goto L1073;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L1073: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == MOD)
    goto L1074;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L1074: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L1075;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L1075: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (
#line 1881 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!TARGET_FIX_VR4120) && 
#line 402 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT)))
    {
      return 89;  /* divmoddi4 */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L1091: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L1092;
    }
  x2 = XEXP (x1, 0);
  goto L2533;

 L1092: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L1093;
    }
  x2 = XEXP (x1, 0);
  goto L2533;

 L1093: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L1094;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L1094: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[3] = x2;
      goto L1095;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L1095: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == UMOD)
    goto L1096;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L1096: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L1097;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L1097: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && 
#line 402 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT))
    {
      return 91;  /* udivmoddi4 */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L5152: ATTRIBUTE_UNUSED_LABEL
  tem = recog_11 (x0, insn, pnum_clobbers);
  if (tem >= 0)
    return tem;
  x2 = XEXP (x1, 0);
  goto L2533;

 L1666: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1667;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L1667: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L1668;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L1668: ATTRIBUTE_UNUSED_LABEL
  if (
#line 3053 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_EXPLICIT_RELOCS && ABI_HAS_64BIT_SYMBOLS && cse_not_expected))
    {
      return 191;  /* *lea64 */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L5084: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, V2HImode))
    {
      operands[0] = x2;
      goto L3127;
    }
  goto L2533;

 L3127: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == V2HImode)
    goto L5179;
  x2 = XEXP (x1, 0);
  goto L2533;

 L5179: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case PLUS:
      goto L3128;
    case UNSPEC:
      goto L5190;
    case MINUS:
      goto L3183;
    default:
     break;
   }
  x2 = XEXP (x1, 0);
  goto L2533;

 L3128: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V2HImode))
    {
      operands[1] = x3;
      goto L3129;
    }
  x2 = XEXP (x1, 0);
  goto L2533;

 L3129: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, V2HImode))
    {
      operands[2] = x3;
      goto L3130;
    }
  x2 = XEXP (x1, 0);
  goto L2533;

 L3130: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3131;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L3131: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 185)
    goto L3132;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L3132: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 2
      && XINT (x2, 1) == 300)
    goto L3133;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L3133: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L3134;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L3134: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (rtx_equal_p (x3, operands[2])
      && 
#line 15 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP))
    {
      return 414;  /* addv2hi3 */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L5190: ATTRIBUTE_UNUSED_LABEL
  switch (XVECLEN (x2, 0))
    {
    case 2:
      goto L5199;
    case 1:
      goto L5201;
    default:
      break;
    }
  x2 = XEXP (x1, 0);
  goto L2533;

 L5199: ATTRIBUTE_UNUSED_LABEL
  switch (XINT (x2, 1))
    {
    case 301L:
      goto L3161;
    case 303L:
      goto L3216;
    case 311L:
      goto L3302;
    case 323L:
      goto L3374;
    case 324L:
      goto L3407;
    case 328L:
      goto L3456;
    case 329L:
      goto L3481;
    case 330L:
      goto L3506;
    default:
      break;
    }
  x2 = XEXP (x1, 0);
  goto L2533;

 L3161: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, V2HImode))
    {
      operands[1] = x3;
      goto L3162;
    }
  x2 = XEXP (x1, 0);
  goto L2533;

 L3162: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (register_operand (x3, V2HImode))
    {
      operands[2] = x3;
      goto L3163;
    }
  x2 = XEXP (x1, 0);
  goto L2533;

 L3163: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3164;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L3164: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 185)
    goto L3165;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L3165: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 2
      && XINT (x2, 1) == 301)
    goto L3166;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L3166: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L3167;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L3167: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (rtx_equal_p (x3, operands[2])
      && 
#line 11 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP))
    {
      return 417;  /* mips_addq_s_ph */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L3216: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, V2HImode))
    {
      operands[1] = x3;
      goto L3217;
    }
  x2 = XEXP (x1, 0);
  goto L2533;

 L3217: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (register_operand (x3, V2HImode))
    {
      operands[2] = x3;
      goto L3218;
    }
  x2 = XEXP (x1, 0);
  goto L2533;

 L3218: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3219;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L3219: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 185)
    goto L3220;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L3220: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 2
      && XINT (x2, 1) == 303)
    goto L3221;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L3221: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L3222;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L3222: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (rtx_equal_p (x3, operands[2])
      && (
#line 84 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP) && 
#line 11 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP)))
    {
      return 422;  /* mips_subq_s_ph */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L3302: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L3303;
    }
  x2 = XEXP (x1, 0);
  goto L2533;

 L3303: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (register_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L3304;
    }
  x2 = XEXP (x1, 0);
  goto L2533;

 L3304: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3305;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L3305: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 185)
    goto L3306;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L3306: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 2
      && XINT (x2, 1) == 311)
    goto L3307;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L3307: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L3308;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L3308: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (rtx_equal_p (x3, operands[2])
      && 
#line 182 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP))
    {
      return 432;  /* mips_precrq_rs_ph_w */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L3374: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, V2HImode))
    {
      operands[1] = x3;
      goto L3375;
    }
  x2 = XEXP (x1, 0);
  goto L2533;

 L3375: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (arith_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L3376;
    }
  x2 = XEXP (x1, 0);
  goto L2533;

 L3376: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3377;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L3377: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 185)
    goto L3378;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L3378: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 2
      && XINT (x2, 1) == 323)
    goto L3379;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L3379: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L3380;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L3380: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (rtx_equal_p (x3, operands[2])
      && (
#line 305 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP) && 
#line 15 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP)))
    {
      return 444;  /* mips_shll_ph */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L3407: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, V2HImode))
    {
      operands[1] = x3;
      goto L3408;
    }
  x2 = XEXP (x1, 0);
  goto L2533;

 L3408: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (arith_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L3409;
    }
  x2 = XEXP (x1, 0);
  goto L2533;

 L3409: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3410;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L3410: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 185)
    goto L3411;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L3411: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 2
      && XINT (x2, 1) == 324)
    goto L3412;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L3412: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L3413;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L3413: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (rtx_equal_p (x3, operands[2])
      && (
#line 327 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP) && 
#line 20 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP)))
    {
      return 447;  /* mips_shll_s_ph */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L3456: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, V4QImode))
    {
      operands[1] = x3;
      goto L3457;
    }
  x2 = XEXP (x1, 0);
  goto L2533;

 L3457: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (register_operand (x3, V2HImode))
    {
      operands[2] = x3;
      goto L3458;
    }
  x2 = XEXP (x1, 0);
  goto L2533;

 L3458: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3459;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L3459: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 185)
    goto L3460;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L3460: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 2
      && XINT (x2, 1) == 328)
    goto L3461;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L3461: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L3462;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L3462: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (rtx_equal_p (x3, operands[2])
      && 
#line 409 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 452;  /* mips_muleu_s_ph_qbl */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L3481: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, V4QImode))
    {
      operands[1] = x3;
      goto L3482;
    }
  x2 = XEXP (x1, 0);
  goto L2533;

 L3482: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (register_operand (x3, V2HImode))
    {
      operands[2] = x3;
      goto L3483;
    }
  x2 = XEXP (x1, 0);
  goto L2533;

 L3483: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3484;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L3484: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 185)
    goto L3485;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L3485: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 2
      && XINT (x2, 1) == 329)
    goto L3486;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L3486: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L3487;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L3487: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (rtx_equal_p (x3, operands[2])
      && 
#line 423 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 453;  /* mips_muleu_s_ph_qbr */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L3506: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, V2HImode))
    {
      operands[1] = x3;
      goto L3507;
    }
  x2 = XEXP (x1, 0);
  goto L2533;

 L3507: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (register_operand (x3, V2HImode))
    {
      operands[2] = x3;
      goto L3508;
    }
  x2 = XEXP (x1, 0);
  goto L2533;

 L3508: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3509;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L3509: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 185)
    goto L3510;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L3510: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 2
      && XINT (x2, 1) == 330)
    goto L3511;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L3511: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L3512;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L3512: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (rtx_equal_p (x3, operands[2])
      && 
#line 438 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 454;  /* mips_mulq_rs_ph */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L5201: ATTRIBUTE_UNUSED_LABEL
  if (XINT (x2, 1) == 308)
    goto L3281;
  x2 = XEXP (x1, 0);
  goto L2533;

 L3281: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, V2HImode))
    {
      operands[1] = x3;
      goto L3282;
    }
  x2 = XEXP (x1, 0);
  goto L2533;

 L3282: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3283;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L3283: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 185)
    goto L3284;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L3284: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 1
      && XINT (x2, 1) == 308)
    goto L3285;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L3285: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (rtx_equal_p (x3, operands[1])
      && (
#line 147 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP) && 
#line 20 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP)))
    {
      return 429;  /* mips_absq_s_ph */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L3183: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V2HImode))
    {
      operands[1] = x3;
      goto L3184;
    }
  x2 = XEXP (x1, 0);
  goto L2533;

 L3184: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, V2HImode))
    {
      operands[2] = x3;
      goto L3185;
    }
  x2 = XEXP (x1, 0);
  goto L2533;

 L3185: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3186;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L3186: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 185)
    goto L3187;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L3187: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 2
      && XINT (x2, 1) == 302)
    goto L3188;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L3188: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L3189;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L3189: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (rtx_equal_p (x3, operands[2])
      && (
#line 71 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP) && 
#line 15 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP)))
    {
      return 419;  /* subv2hi3 */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L5085: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, V4QImode))
    {
      operands[0] = x2;
      goto L3138;
    }
  goto L2533;

 L3138: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == V4QImode)
    goto L5208;
  x2 = XEXP (x1, 0);
  goto L2533;

 L5208: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case PLUS:
      goto L3139;
    case UNSPEC:
      goto L5214;
    case MINUS:
      goto L3194;
    default:
     break;
   }
  x2 = XEXP (x1, 0);
  goto L2533;

 L3139: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V4QImode))
    {
      operands[1] = x3;
      goto L3140;
    }
  x2 = XEXP (x1, 0);
  goto L2533;

 L3140: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, V4QImode))
    {
      operands[2] = x3;
      goto L3141;
    }
  x2 = XEXP (x1, 0);
  goto L2533;

 L3141: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3142;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L3142: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 185)
    goto L3143;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L3143: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 2
      && XINT (x2, 1) == 300)
    goto L3144;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L3144: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L3145;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L3145: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (rtx_equal_p (x3, operands[2])
      && 
#line 16 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP))
    {
      return 415;  /* addv4qi3 */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L5214: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x2, 0) == 2)
    goto L5218;
  x2 = XEXP (x1, 0);
  goto L2533;

 L5218: ATTRIBUTE_UNUSED_LABEL
  switch (XINT (x2, 1))
    {
    case 301L:
      goto L3172;
    case 303L:
      goto L3227;
    case 312L:
      goto L3313;
    case 323L:
      goto L3385;
    default:
      break;
    }
  x2 = XEXP (x1, 0);
  goto L2533;

 L3172: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, V4QImode))
    {
      operands[1] = x3;
      goto L3173;
    }
  x2 = XEXP (x1, 0);
  goto L2533;

 L3173: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (register_operand (x3, V4QImode))
    {
      operands[2] = x3;
      goto L3174;
    }
  x2 = XEXP (x1, 0);
  goto L2533;

 L3174: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3175;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L3175: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 185)
    goto L3176;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L3176: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 2
      && XINT (x2, 1) == 301)
    goto L3177;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L3177: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L3178;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L3178: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (rtx_equal_p (x3, operands[2])
      && 
#line 12 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP))
    {
      return 418;  /* mips_addu_s_qb */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L3227: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, V4QImode))
    {
      operands[1] = x3;
      goto L3228;
    }
  x2 = XEXP (x1, 0);
  goto L2533;

 L3228: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (register_operand (x3, V4QImode))
    {
      operands[2] = x3;
      goto L3229;
    }
  x2 = XEXP (x1, 0);
  goto L2533;

 L3229: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3230;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L3230: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 185)
    goto L3231;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L3231: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 2
      && XINT (x2, 1) == 303)
    goto L3232;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L3232: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L3233;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L3233: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (rtx_equal_p (x3, operands[2])
      && (
#line 84 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP) && 
#line 12 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP)))
    {
      return 423;  /* mips_subu_s_qb */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L3313: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, V2HImode))
    {
      operands[1] = x3;
      goto L3314;
    }
  x2 = XEXP (x1, 0);
  goto L2533;

 L3314: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (register_operand (x3, V2HImode))
    {
      operands[2] = x3;
      goto L3315;
    }
  x2 = XEXP (x1, 0);
  goto L2533;

 L3315: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3316;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L3316: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 185)
    goto L3317;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L3317: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 2
      && XINT (x2, 1) == 312)
    goto L3318;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L3318: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L3319;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L3319: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (rtx_equal_p (x3, operands[2])
      && 
#line 197 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP))
    {
      return 433;  /* mips_precrqu_s_qb_ph */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L3385: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, V4QImode))
    {
      operands[1] = x3;
      goto L3386;
    }
  x2 = XEXP (x1, 0);
  goto L2533;

 L3386: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (arith_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L3387;
    }
  x2 = XEXP (x1, 0);
  goto L2533;

 L3387: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3388;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L3388: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 185)
    goto L3389;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L3389: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 2
      && XINT (x2, 1) == 323)
    goto L3390;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L3390: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L3391;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L3391: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (rtx_equal_p (x3, operands[2])
      && (
#line 305 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP) && 
#line 16 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP)))
    {
      return 445;  /* mips_shll_qb */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L3194: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V4QImode))
    {
      operands[1] = x3;
      goto L3195;
    }
  x2 = XEXP (x1, 0);
  goto L2533;

 L3195: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, V4QImode))
    {
      operands[2] = x3;
      goto L3196;
    }
  x2 = XEXP (x1, 0);
  goto L2533;

 L3196: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3197;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L3197: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 185)
    goto L3198;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L3198: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 2
      && XINT (x2, 1) == 302)
    goto L3199;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L3199: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L3200;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L3200: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (rtx_equal_p (x3, operands[2])
      && (
#line 71 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP) && 
#line 16 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP)))
    {
      return 420;  /* subv4qi3 */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2533;

 L2534: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L5222;
    case DImode:
      goto L5223;
    default:
      break;
    }
  goto ret0;

 L5222: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L2535;
    }
  goto ret0;

 L2535: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == USE)
    goto L2536;
  goto ret0;

 L2536: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_CODE (x2) == LABEL_REF)
    goto L2537;
  goto ret0;

 L2537: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  operands[1] = x3;
  goto L2538;

 L2538: ATTRIBUTE_UNUSED_LABEL
  if (
#line 406 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(Pmode == SImode))
    {
      return 339;  /* tablejumpsi */
    }
  goto ret0;

 L5223: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L2543;
    }
  goto ret0;

 L2543: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == USE)
    goto L2544;
  goto ret0;

 L2544: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_CODE (x2) == LABEL_REF)
    goto L2545;
  goto ret0;

 L2545: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  operands[1] = x3;
  goto L2546;

 L2546: ATTRIBUTE_UNUSED_LABEL
  if (
#line 406 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(Pmode == DImode))
    {
      return 340;  /* tablejumpdi */
    }
  goto ret0;

 L2603: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CALL)
    goto L2604;
  goto ret0;

 L2604: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == MEM)
    goto L2605;
  goto ret0;

 L2605: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (call_insn_operand (x4, VOIDmode))
    {
      operands[1] = x4;
      goto L2606;
    }
  goto ret0;

 L2606: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  operands[2] = x3;
  goto L2607;

 L2607: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  switch (GET_CODE (x1))
    {
    case SET:
      goto L2608;
    case CLOBBER:
      goto L2647;
    default:
     break;
   }
  goto ret0;

 L2608: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, VOIDmode))
    {
      operands[3] = x2;
      goto L2609;
    }
  goto ret0;

 L2609: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CALL)
    goto L2610;
  goto ret0;

 L2610: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == MEM)
    goto L2611;
  goto ret0;

 L2611: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L2612;
  goto ret0;

 L2612: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && 
#line 5067 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_SIBCALLS && SIBLING_CALL_P (insn)))
    {
      return 351;  /* sibcall_value_multiple_internal */
    }
 L2700: ATTRIBUTE_UNUSED_LABEL
  if (rtx_equal_p (x3, operands[2])
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 356;  /* call_value_multiple_internal */
    }
 L2730: ATTRIBUTE_UNUSED_LABEL
  if (rtx_equal_p (x3, operands[2])
      && 
#line 5221 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_SPLIT_CALLS)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 2;
      return 357;  /* call_value_multiple_split */
    }
  goto ret0;

 L2647: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 31)
    {
      return 354;  /* call_value_internal */
    }
  goto ret0;
 ret0:
  return -1;
}

static int
recog_13 (rtx x0 ATTRIBUTE_UNUSED,
	rtx insn ATTRIBUTE_UNUSED,
	int *pnum_clobbers ATTRIBUTE_UNUSED)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x1 ATTRIBUTE_UNUSED;
  rtx x2 ATTRIBUTE_UNUSED;
  rtx x3 ATTRIBUTE_UNUSED;
  rtx x4 ATTRIBUTE_UNUSED;
  rtx x5 ATTRIBUTE_UNUSED;
  rtx x6 ATTRIBUTE_UNUSED;
  rtx x7 ATTRIBUTE_UNUSED;
  int tem ATTRIBUTE_UNUSED;

  switch (XVECLEN (x0, 0))
    {
    case 3:
      goto L160;
    case 2:
      goto L194;
    case 4:
      goto L258;
    case 6:
      goto L3896;
    default:
      break;
    }
  goto ret0;

 L160: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 0);
  switch (GET_CODE (x1))
    {
    case SET:
      goto L161;
    case CALL:
      goto L2627;
    default:
     break;
   }
  goto ret0;

 L161: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L5049;
    case DImode:
      goto L5050;
    case V2HImode:
      goto L5051;
    default:
      break;
    }
 L2657: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, VOIDmode))
    {
      operands[0] = x2;
      goto L2658;
    }
  goto ret0;

 L5049: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L162;
    }
  goto L2657;

 L162: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode)
    goto L5052;
  x2 = XEXP (x1, 0);
  goto L2657;

 L5052: ATTRIBUTE_UNUSED_LABEL
  tem = recog_9 (x0, insn, pnum_clobbers);
  if (tem >= 0)
    return tem;
  x2 = XEXP (x1, 0);
  goto L2657;

 L5050: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L179;
    }
  goto L2657;

 L179: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == MULT)
    goto L180;
  x2 = XEXP (x1, 0);
  goto L2657;

 L180: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L181;
    }
  x2 = XEXP (x1, 0);
  goto L2657;

 L181: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L182;
    }
  x2 = XEXP (x1, 0);
  goto L2657;

 L182: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L183;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2657;

 L183: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[3] = x2;
      goto L184;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2657;

 L184: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L185;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2657;

 L185: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[4] = x2;
      goto L186;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2657;

 L186: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1052 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT && GENERATE_MULT3_DI))
    {
      return 28;  /* muldi3_mult3 */
    }
 L250: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 1099 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_FIX_R4000) && 
#line 402 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT)))
    {
      return 32;  /* muldi3_r4000 */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2657;

 L5051: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, V2HImode))
    {
      operands[0] = x2;
      goto L3441;
    }
  goto L2657;

 L3441: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == V2HImode)
    goto L5072;
  x2 = XEXP (x1, 0);
  goto L2657;

 L5072: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == UNSPEC)
    goto L5075;
  x2 = XEXP (x1, 0);
  goto L2657;

 L5075: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x2, 0) == 2)
    goto L5078;
  x2 = XEXP (x1, 0);
  goto L2657;

 L5078: ATTRIBUTE_UNUSED_LABEL
  switch (XINT (x2, 1))
    {
    case 328L:
      goto L3442;
    case 329L:
      goto L3467;
    case 330L:
      goto L3492;
    default:
      break;
    }
  x2 = XEXP (x1, 0);
  goto L2657;

 L3442: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, V4QImode))
    {
      operands[1] = x3;
      goto L3443;
    }
  x2 = XEXP (x1, 0);
  goto L2657;

 L3443: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (register_operand (x3, V2HImode))
    {
      operands[2] = x3;
      goto L3444;
    }
  x2 = XEXP (x1, 0);
  goto L2657;

 L3444: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3445;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2657;

 L3445: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 185)
    goto L3446;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2657;

 L3446: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 2
      && XINT (x2, 1) == 328)
    goto L3447;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2657;

 L3447: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L3448;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2657;

 L3448: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (rtx_equal_p (x3, operands[2]))
    goto L3449;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2657;

 L3449: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L3450;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2657;

 L3450: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[3] = x2;
      goto L3451;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2657;

 L3451: ATTRIBUTE_UNUSED_LABEL
  if (
#line 409 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP))
    {
      return 452;  /* mips_muleu_s_ph_qbl */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2657;

 L3467: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, V4QImode))
    {
      operands[1] = x3;
      goto L3468;
    }
  x2 = XEXP (x1, 0);
  goto L2657;

 L3468: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (register_operand (x3, V2HImode))
    {
      operands[2] = x3;
      goto L3469;
    }
  x2 = XEXP (x1, 0);
  goto L2657;

 L3469: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3470;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2657;

 L3470: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 185)
    goto L3471;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2657;

 L3471: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 2
      && XINT (x2, 1) == 329)
    goto L3472;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2657;

 L3472: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L3473;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2657;

 L3473: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (rtx_equal_p (x3, operands[2]))
    goto L3474;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2657;

 L3474: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L3475;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2657;

 L3475: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[3] = x2;
      goto L3476;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2657;

 L3476: ATTRIBUTE_UNUSED_LABEL
  if (
#line 423 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP))
    {
      return 453;  /* mips_muleu_s_ph_qbr */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2657;

 L3492: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, V2HImode))
    {
      operands[1] = x3;
      goto L3493;
    }
  x2 = XEXP (x1, 0);
  goto L2657;

 L3493: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (register_operand (x3, V2HImode))
    {
      operands[2] = x3;
      goto L3494;
    }
  x2 = XEXP (x1, 0);
  goto L2657;

 L3494: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3495;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2657;

 L3495: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 185)
    goto L3496;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2657;

 L3496: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 2
      && XINT (x2, 1) == 330)
    goto L3497;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2657;

 L3497: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L3498;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2657;

 L3498: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (rtx_equal_p (x3, operands[2]))
    goto L3499;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2657;

 L3499: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L3500;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2657;

 L3500: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[3] = x2;
      goto L3501;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2657;

 L3501: ATTRIBUTE_UNUSED_LABEL
  if (
#line 438 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP))
    {
      return 454;  /* mips_mulq_rs_ph */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2657;

 L2658: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CALL)
    goto L2659;
  goto ret0;

 L2659: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == MEM)
    goto L2660;
  goto ret0;

 L2660: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (call_insn_operand (x4, VOIDmode))
    {
      operands[1] = x4;
      goto L2661;
    }
  goto ret0;

 L2661: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  operands[2] = x3;
  goto L2662;

 L2662: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  switch (GET_CODE (x1))
    {
    case CLOBBER:
      goto L2663;
    case SET:
      goto L2681;
    default:
     break;
   }
  goto ret0;

 L2663: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 31)
    goto L2664;
  goto ret0;

 L2664: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L2665;
  goto ret0;

 L2665: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 28
      && 
#line 5185 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_SPLIT_CALLS))
    {
      return 355;  /* call_value_split */
    }
  goto ret0;

 L2681: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, VOIDmode))
    {
      operands[3] = x2;
      goto L2682;
    }
  goto ret0;

 L2682: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CALL)
    goto L2683;
  goto ret0;

 L2683: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == MEM)
    goto L2684;
  goto ret0;

 L2684: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L2685;
  goto ret0;

 L2685: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2]))
    goto L2686;
  goto ret0;

 L2686: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L2687;
  goto ret0;

 L2687: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 31)
    {
      return 356;  /* call_value_multiple_internal */
    }
  goto ret0;

 L2627: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == MEM)
    goto L2628;
  goto ret0;

 L2628: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (call_insn_operand (x3, VOIDmode))
    {
      operands[0] = x3;
      goto L2629;
    }
  goto ret0;

 L2629: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  operands[1] = x2;
  goto L2630;

 L2630: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2631;
  goto ret0;

 L2631: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 31)
    goto L2632;
  goto ret0;

 L2632: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L2633;
  goto ret0;

 L2633: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 28
      && 
#line 5143 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_SPLIT_CALLS))
    {
      return 353;  /* call_split */
    }
  goto ret0;

 L194: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 0);
  switch (GET_CODE (x1))
    {
    case SET:
      goto L195;
    case RETURN:
      goto L2552;
    case UNSPEC:
      goto L5081;
    case CALL:
      goto L2615;
    default:
     break;
   }
  goto ret0;

 L195: ATTRIBUTE_UNUSED_LABEL
  return recog_12 (x0, insn, pnum_clobbers);

 L2552: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == USE)
    goto L2553;
  goto ret0;

 L2553: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (pmode_register_operand (x2, VOIDmode))
    {
      operands[0] = x2;
      return 343;  /* return_internal */
    }
  goto ret0;

 L5081: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x1, 0) == 1
      && XINT (x1, 1) == 7)
    goto L2556;
  goto ret0;

 L2556: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L5224;
    case DImode:
      goto L5225;
    default:
      break;
    }
  goto ret0;

 L5224: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L2557;
    }
  goto ret0;

 L2557: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2558;
  goto ret0;

 L2558: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L2559;
    }
  goto ret0;

 L2559: ATTRIBUTE_UNUSED_LABEL
  if (
#line 4940 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(! TARGET_64BIT))
    {
      return 344;  /* eh_set_lr_si */
    }
  goto ret0;

 L5225: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L2566;
    }
  goto ret0;

 L2566: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2567;
  goto ret0;

 L2567: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L2568;
    }
  goto ret0;

 L2568: ATTRIBUTE_UNUSED_LABEL
  if (
#line 4946 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT))
    {
      return 345;  /* eh_set_lr_di */
    }
  goto ret0;

 L2615: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == MEM)
    goto L2616;
  goto ret0;

 L2616: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (call_insn_operand (x3, VOIDmode))
    {
      operands[0] = x3;
      goto L2617;
    }
  goto ret0;

 L2617: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  operands[1] = x2;
  goto L2618;

 L2618: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2619;
  goto ret0;

 L2619: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 31)
    {
      return 352;  /* call_internal */
    }
  goto ret0;

 L258: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 0);
  if (GET_CODE (x1) == SET)
    goto L259;
  goto ret0;

 L259: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L5226;
    case DImode:
      goto L5227;
    default:
      break;
    }
 L2703: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, VOIDmode))
    {
      operands[0] = x2;
      goto L2704;
    }
  goto ret0;

 L5226: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L260;
    }
  goto L2703;

 L260: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode)
    goto L5228;
  x2 = XEXP (x1, 0);
  goto L2703;

 L5228: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case PLUS:
      goto L261;
    case MINUS:
      goto L326;
    default:
     break;
   }
  x2 = XEXP (x1, 0);
  goto L2703;

 L261: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == MULT)
    goto L262;
  x2 = XEXP (x1, 0);
  goto L2703;

 L262: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L263;
    }
  x2 = XEXP (x1, 0);
  goto L2703;

 L263: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (register_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L264;
    }
  x2 = XEXP (x1, 0);
  goto L2703;

 L264: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, SImode))
    {
      operands[3] = x3;
      goto L265;
    }
  x2 = XEXP (x1, 0);
  goto L2703;

 L265: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L266;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2703;

 L266: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L267;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2703;

 L267: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L268;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2703;

 L268: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[5] = x2;
      goto L269;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2703;

 L269: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 3);
  if (GET_CODE (x1) == CLOBBER)
    goto L270;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2703;

 L270: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[6] = x2;
      goto L271;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2703;

 L271: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1156 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
((TARGET_MIPS3900
   || ISA_HAS_MADD_MSUB)
   && !TARGET_MIPS16))
    {
      return 33;  /* *mul_acc_si */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2703;

 L326: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L327;
    }
  x2 = XEXP (x1, 0);
  goto L2703;

 L327: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == MULT)
    goto L328;
  x2 = XEXP (x1, 0);
  goto L2703;

 L328: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L329;
    }
  x2 = XEXP (x1, 0);
  goto L2703;

 L329: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (register_operand (x4, SImode))
    {
      operands[3] = x4;
      goto L330;
    }
  x2 = XEXP (x1, 0);
  goto L2703;

 L330: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L331;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2703;

 L331: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L332;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2703;

 L332: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L333;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2703;

 L333: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[5] = x2;
      goto L334;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2703;

 L334: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 3);
  if (GET_CODE (x1) == CLOBBER)
    goto L335;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2703;

 L335: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[6] = x2;
      goto L336;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2703;

 L336: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1261 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_MACC && !ISA_HAS_MSAC))
    {
      return 36;  /* *msac_using_macc */
    }
 L425: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1417 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_MADD_MSUB))
    {
      return 39;  /* *mul_sub_si */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2703;

 L5227: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L510;
    }
  goto L2703;

 L510: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == MULT)
    goto L511;
  x2 = XEXP (x1, 0);
  goto L2703;

 L511: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DImode)
    goto L5230;
  x2 = XEXP (x1, 0);
  goto L2703;

 L5230: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x3))
    {
    case SIGN_EXTEND:
      goto L512;
    case ZERO_EXTEND:
      goto L535;
    default:
     break;
   }
  x2 = XEXP (x1, 0);
  goto L2703;

 L512: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L513;
    }
  x2 = XEXP (x1, 0);
  goto L2703;

 L513: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == DImode
      && GET_CODE (x3) == SIGN_EXTEND)
    goto L514;
  x2 = XEXP (x1, 0);
  goto L2703;

 L514: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L515;
    }
  x2 = XEXP (x1, 0);
  goto L2703;

 L515: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L516;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2703;

 L516: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[3] = x2;
      goto L517;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2703;

 L517: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L518;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2703;

 L518: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[4] = x2;
      goto L519;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2703;

 L519: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 3);
  if (GET_CODE (x1) == CLOBBER)
    goto L520;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2703;

 L520: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[5] = x2;
      goto L521;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2703;

 L521: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1530 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT && !TARGET_FIX_R4000))
    {
      return 45;  /* *mulsidi3_64bit */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2703;

 L535: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L536;
    }
  x2 = XEXP (x1, 0);
  goto L2703;

 L536: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == DImode
      && GET_CODE (x3) == ZERO_EXTEND)
    goto L537;
  x2 = XEXP (x1, 0);
  goto L2703;

 L537: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L538;
    }
  x2 = XEXP (x1, 0);
  goto L2703;

 L538: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L539;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2703;

 L539: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[3] = x2;
      goto L540;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2703;

 L540: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L541;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2703;

 L541: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[4] = x2;
      goto L542;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2703;

 L542: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 3);
  if (GET_CODE (x1) == CLOBBER)
    goto L543;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2703;

 L543: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[5] = x2;
      goto L544;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2703;

 L544: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1530 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT && !TARGET_FIX_R4000))
    {
      return 46;  /* *umulsidi3_64bit */
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L2703;

 L2704: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CALL)
    goto L2705;
  goto ret0;

 L2705: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == MEM)
    goto L2706;
  goto ret0;

 L2706: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (call_insn_operand (x4, VOIDmode))
    {
      operands[1] = x4;
      goto L2707;
    }
  goto ret0;

 L2707: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  operands[2] = x3;
  goto L2708;

 L2708: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L2709;
  goto ret0;

 L2709: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, VOIDmode))
    {
      operands[3] = x2;
      goto L2710;
    }
  goto ret0;

 L2710: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CALL)
    goto L2711;
  goto ret0;

 L2711: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == MEM)
    goto L2712;
  goto ret0;

 L2712: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L2713;
  goto ret0;

 L2713: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2]))
    goto L2714;
  goto ret0;

 L2714: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L2715;
  goto ret0;

 L2715: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 31)
    goto L2716;
  goto ret0;

 L2716: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 3);
  if (GET_CODE (x1) == CLOBBER)
    goto L2717;
  goto ret0;

 L2717: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 28
      && 
#line 5221 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_SPLIT_CALLS))
    {
      return 357;  /* call_value_multiple_split */
    }
  goto ret0;

 L3896: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 0);
  if (GET_CODE (x1) == SET)
    goto L3897;
  goto ret0;

 L3897: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 182)
    goto L3898;
  goto ret0;

 L3898: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 2
      && XINT (x2, 1) == 366)
    goto L3899;
  goto ret0;

 L3899: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, SImode))
    {
      operands[0] = x3;
      goto L3900;
    }
  goto ret0;

 L3900: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (const_uimm6_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L3901;
    }
  goto ret0;

 L3901: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3902;
  goto ret0;

 L3902: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 183)
    goto L3903;
  goto ret0;

 L3903: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 2
      && XINT (x2, 1) == 366)
    goto L3904;
  goto ret0;

 L3904: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (rtx_equal_p (x3, operands[0]))
    goto L3905;
  goto ret0;

 L3905: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (rtx_equal_p (x3, operands[1]))
    goto L3906;
  goto ret0;

 L3906: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == SET)
    goto L3907;
  goto ret0;

 L3907: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 184)
    goto L3908;
  goto ret0;

 L3908: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 2
      && XINT (x2, 1) == 366)
    goto L3909;
  goto ret0;

 L3909: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (rtx_equal_p (x3, operands[0]))
    goto L3910;
  goto ret0;

 L3910: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (rtx_equal_p (x3, operands[1]))
    goto L3911;
  goto ret0;

 L3911: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 3);
  if (GET_CODE (x1) == SET)
    goto L3912;
  goto ret0;

 L3912: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 185)
    goto L3913;
  goto ret0;

 L3913: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 2
      && XINT (x2, 1) == 366)
    goto L3914;
  goto ret0;

 L3914: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (rtx_equal_p (x3, operands[0]))
    goto L3915;
  goto ret0;

 L3915: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (rtx_equal_p (x3, operands[1]))
    goto L3916;
  goto ret0;

 L3916: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 4);
  if (GET_CODE (x1) == SET)
    goto L3917;
  goto ret0;

 L3917: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 186)
    goto L3918;
  goto ret0;

 L3918: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 2
      && XINT (x2, 1) == 366)
    goto L3919;
  goto ret0;

 L3919: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (rtx_equal_p (x3, operands[0]))
    goto L3920;
  goto ret0;

 L3920: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (rtx_equal_p (x3, operands[1]))
    goto L3921;
  goto ret0;

 L3921: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 5);
  if (GET_CODE (x1) == SET)
    goto L3922;
  goto ret0;

 L3922: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 187)
    goto L3923;
  goto ret0;

 L3923: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == CCDSPmode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 2
      && XINT (x2, 1) == 366)
    goto L3924;
  goto ret0;

 L3924: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (rtx_equal_p (x3, operands[0]))
    goto L3925;
  goto ret0;

 L3925: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (rtx_equal_p (x3, operands[1])
      && 
#line 988 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-dsp.md"
(TARGET_DSP))
    {
      return 494;  /* mips_wrdsp */
    }
  goto ret0;
 ret0:
  return -1;
}

int
recog (rtx x0 ATTRIBUTE_UNUSED,
	rtx insn ATTRIBUTE_UNUSED,
	int *pnum_clobbers ATTRIBUTE_UNUSED)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x1 ATTRIBUTE_UNUSED;
  rtx x2 ATTRIBUTE_UNUSED;
  rtx x3 ATTRIBUTE_UNUSED;
  rtx x4 ATTRIBUTE_UNUSED;
  rtx x5 ATTRIBUTE_UNUSED;
  rtx x6 ATTRIBUTE_UNUSED;
  rtx x7 ATTRIBUTE_UNUSED;
  int tem ATTRIBUTE_UNUSED;
  recog_data.insn = NULL_RTX;

  switch (GET_CODE (x0))
    {
    case TRAP_IF:
      goto L4;
    case SET:
      goto L14;
    case PARALLEL:
      goto L4431;
    case UNSPEC_VOLATILE:
      goto L4434;
    case RETURN:
      goto L4437;
    case UNSPEC:
      goto L4438;
    case CALL:
      goto L2589;
    case PREFETCH:
      goto L2732;
    case CONST_INT:
      goto L4439;
    default:
     break;
   }
  goto ret0;

 L4: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 0);
  switch (GET_MODE (x1))
    {
    case SImode:
      goto L4445;
    case DImode:
      goto L4446;
    default:
      break;
    }
 L1: ATTRIBUTE_UNUSED_LABEL
  if (x1 == const_int_rtx[MAX_SAVED_CONST_INT + (1)])
    goto L2;
  goto ret0;

 L4445: ATTRIBUTE_UNUSED_LABEL
  if (trap_comparison_operator (x1, SImode))
    {
      operands[0] = x1;
      goto L5;
    }
  goto L1;

 L5: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (reg_or_0_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L6;
    }
  goto L1;

 L6: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (arith_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L7;
    }
  goto L1;

 L7: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (x1 == const_int_rtx[MAX_SAVED_CONST_INT + (0)]
      && 
#line 634 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_COND_TRAP))
    {
      return 1;  /* *conditional_trapsi */
    }
  x1 = XEXP (x0, 0);
  goto L1;

 L4446: ATTRIBUTE_UNUSED_LABEL
  if (trap_comparison_operator (x1, DImode))
    {
      operands[0] = x1;
      goto L10;
    }
  goto L1;

 L10: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (reg_or_0_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L11;
    }
  goto L1;

 L11: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (arith_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L12;
    }
  goto L1;

 L12: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (x1 == const_int_rtx[MAX_SAVED_CONST_INT + (0)]
      && (
#line 634 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_COND_TRAP) && 
#line 402 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT)))
    {
      return 2;  /* *conditional_trapdi */
    }
  x1 = XEXP (x0, 0);
  goto L1;

 L2: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (x1 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    {
      return 0;  /* trap */
    }
  goto ret0;

 L14: ATTRIBUTE_UNUSED_LABEL
  return recog_8 (x0, insn, pnum_clobbers);

 L4431: ATTRIBUTE_UNUSED_LABEL
  return recog_13 (x0, insn, pnum_clobbers);

 L4434: ATTRIBUTE_UNUSED_LABEL
  switch (XVECLEN (x0, 0))
    {
    case 2:
      goto L5232;
    case 1:
      goto L5233;
    default:
      break;
    }
  goto ret0;

 L5232: ATTRIBUTE_UNUSED_LABEL
  switch (XINT (x0, 1))
    {
    case 22L:
      goto L1956;
    case 8L:
      goto L2861;
    default:
      break;
    }
  goto ret0;

 L1956: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 0);
  operands[0] = x1;
  goto L1957;

 L1957: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (register_operand (x1, VOIDmode))
    {
      operands[1] = x1;
      goto L1958;
    }
  goto ret0;

 L1958: ATTRIBUTE_UNUSED_LABEL
  if (
#line 3936 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_ABICALLS && TARGET_NEWABI))
    {
      return 246;  /* loadgp */
    }
  goto ret0;

 L2861: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 0);
  if (consttable_operand (x1, VOIDmode))
    {
      operands[0] = x1;
      goto L2862;
    }
  goto ret0;

 L2862: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (const_int_operand (x1, VOIDmode))
    {
      operands[1] = x1;
      goto L2863;
    }
  goto ret0;

 L2863: ATTRIBUTE_UNUSED_LABEL
  if (
#line 5369 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_MIPS16))
    {
      return 375;  /* consttable_int */
    }
  goto ret0;

 L5233: ATTRIBUTE_UNUSED_LABEL
  switch (XINT (x0, 1))
    {
    case 4L:
      goto L1960;
    case 5L:
      goto L1962;
    case 9L:
      goto L2865;
    case 14L:
      goto L2868;
    default:
      break;
    }
  goto ret0;

 L1960: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 0);
  if (GET_MODE (x1) == DImode
      && GET_CODE (x1) == REG
      && XINT (x1, 0) == 28)
    {
      return 247;  /* loadgp_blockage */
    }
  if (x1 == const_int_rtx[MAX_SAVED_CONST_INT + (0)])
    {
      return 341;  /* blockage */
    }
  goto ret0;

 L1962: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 0);
  if (const_int_operand (x1, VOIDmode))
    {
      operands[0] = x1;
      return 248;  /* cprestore */
    }
  goto ret0;

 L2865: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 0);
  if (consttable_operand (x1, VOIDmode))
    {
      operands[0] = x1;
      goto L2866;
    }
  goto ret0;

 L2866: ATTRIBUTE_UNUSED_LABEL
  if (
#line 5380 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_MIPS16))
    {
      return 376;  /* consttable_float */
    }
  goto ret0;

 L2868: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 0);
  if (const_int_operand (x1, VOIDmode))
    {
      operands[0] = x1;
      return 377;  /* align */
    }
  goto ret0;

 L4437: ATTRIBUTE_UNUSED_LABEL
  if (
#line 4902 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(mips_can_use_return_insn ()))
    {
      return 342;  /* return */
    }
  goto ret0;

 L4438: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x0, 0) == 1
      && XINT (x0, 1) == 7)
    goto L2561;
  goto ret0;

 L2561: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 0);
  switch (GET_MODE (x1))
    {
    case SImode:
      goto L5238;
    case DImode:
      goto L5239;
    default:
      break;
    }
  goto ret0;

 L5238: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, SImode))
    {
      operands[0] = x1;
      goto L2562;
    }
  goto ret0;

 L2562: ATTRIBUTE_UNUSED_LABEL
  if (
#line 4940 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(! TARGET_64BIT)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 344;  /* eh_set_lr_si */
    }
  goto ret0;

 L5239: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, DImode))
    {
      operands[0] = x1;
      goto L2571;
    }
  goto ret0;

 L2571: ATTRIBUTE_UNUSED_LABEL
  if (
#line 4946 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 345;  /* eh_set_lr_di */
    }
  goto ret0;

 L2589: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 0);
  if (GET_MODE (x1) == SImode
      && GET_CODE (x1) == MEM)
    goto L2590;
  goto ret0;

 L2590: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (call_insn_operand (x2, VOIDmode))
    {
      operands[0] = x2;
      goto L2591;
    }
  goto ret0;

 L2591: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  operands[1] = x1;
  goto L2592;

 L2592: ATTRIBUTE_UNUSED_LABEL
  if (
#line 5032 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_SIBCALLS && SIBLING_CALL_P (insn)))
    {
      return 349;  /* sibcall_internal */
    }
 L2624: ATTRIBUTE_UNUSED_LABEL
  if (pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 352;  /* call_internal */
    }
 L2638: ATTRIBUTE_UNUSED_LABEL
  if (
#line 5143 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_SPLIT_CALLS)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 2;
      return 353;  /* call_split */
    }
  goto ret0;

 L2732: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 0);
  if (address_operand (x1, QImode))
    {
      operands[0] = x1;
      goto L2733;
    }
 L2737: ATTRIBUTE_UNUSED_LABEL
  switch (GET_MODE (x1))
    {
    case SImode:
      goto L5240;
    case DImode:
      goto L5241;
    default:
      break;
    }
  goto ret0;

 L2733: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (const_int_operand (x1, VOIDmode))
    {
      operands[1] = x1;
      goto L2734;
    }
  x1 = XEXP (x0, 0);
  goto L2737;

 L2734: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 2);
  if (const_int_operand (x1, VOIDmode))
    {
      operands[2] = x1;
      goto L2735;
    }
  x1 = XEXP (x0, 0);
  goto L2737;

 L2735: ATTRIBUTE_UNUSED_LABEL
  if (
#line 5261 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_PREFETCH && TARGET_EXPLICIT_RELOCS))
    {
      return 358;  /* prefetch */
    }
  x1 = XEXP (x0, 0);
  goto L2737;

 L5240: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x1) == PLUS)
    goto L2738;
  goto ret0;

 L2738: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L2739;
    }
  goto ret0;

 L2739: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L2740;
    }
  goto ret0;

 L2740: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (const_int_operand (x1, VOIDmode))
    {
      operands[2] = x1;
      goto L2741;
    }
  goto ret0;

 L2741: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 2);
  if (const_int_operand (x1, VOIDmode))
    {
      operands[3] = x1;
      goto L2742;
    }
  goto ret0;

 L2742: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 5273 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_PREFETCHX && TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT) && 
#line 406 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(Pmode == SImode)))
    {
      return 359;  /* *prefetch_indexed_si */
    }
  goto ret0;

 L5241: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x1) == PLUS)
    goto L2745;
  goto ret0;

 L2745: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L2746;
    }
  goto ret0;

 L2746: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L2747;
    }
  goto ret0;

 L2747: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (const_int_operand (x1, VOIDmode))
    {
      operands[2] = x1;
      goto L2748;
    }
  goto ret0;

 L2748: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 2);
  if (const_int_operand (x1, VOIDmode))
    {
      operands[3] = x1;
      goto L2749;
    }
  goto ret0;

 L2749: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 5273 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_PREFETCHX && TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT) && 
#line 406 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(Pmode == DImode)))
    {
      return 360;  /* *prefetch_indexed_di */
    }
  goto ret0;

 L4439: ATTRIBUTE_UNUSED_LABEL
  if ((int) XWINT (x0, 0) == XWINT (x0, 0))
    switch ((int) XWINT (x0, 0))
      {
      case 0L:
        goto L5242;
      case 1L:
        goto L5243;
      default:
        break;
      }
  goto ret0;

 L5242: ATTRIBUTE_UNUSED_LABEL
  return 361;  /* nop */

 L5243: ATTRIBUTE_UNUSED_LABEL
  return 362;  /* hazard_nop */
 ret0:
  return -1;
}

static rtx
split_1 (rtx x0 ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x1 ATTRIBUTE_UNUSED;
  rtx x2 ATTRIBUTE_UNUSED;
  rtx x3 ATTRIBUTE_UNUSED;
  rtx x4 ATTRIBUTE_UNUSED;
  rtx x5 ATTRIBUTE_UNUSED;
  rtx x6 ATTRIBUTE_UNUSED;
  rtx x7 ATTRIBUTE_UNUSED;
  rtx tem ATTRIBUTE_UNUSED;

  x1 = XEXP (x0, 0);
  switch (GET_MODE (x1))
    {
    case SImode:
      goto L5254;
    case DImode:
      goto L5249;
    case HImode:
      goto L5250;
    case QImode:
      goto L5251;
    case DFmode:
      goto L5253;
    default:
      break;
    }
 L4323: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, VOIDmode))
    {
      operands[0] = x1;
      goto L4324;
    }
  goto ret0;

 L5254: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x1) == REG
      && XINT (x1, 0) == 28)
    goto L4378;
 L5248: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, SImode))
    {
      operands[0] = x1;
      goto L3970;
    }
  goto L4323;

 L4378: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == SImode
      && GET_CODE (x1) == UNSPEC_VOLATILE
      && XVECLEN (x1, 0) == 1
      && XINT (x1, 1) == 6)
    goto L4379;
  x1 = XEXP (x0, 0);
  goto L5248;

 L4379: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (x2 == const_int_rtx[MAX_SAVED_CONST_INT + (0)]
      && (
#line 4962 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_ABICALLS && TARGET_OLDABI) && 
#line 4964 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
( reload_completed)))
    {
      return gen_split_650 (insn, operands);
    }
  x1 = XEXP (x0, 0);
  goto L5248;

 L3970: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == SImode)
    goto L5255;
 L4298: ATTRIBUTE_UNUSED_LABEL
  if (const_int_operand (x1, SImode))
    {
      operands[1] = x1;
      goto L4299;
    }
  x1 = XEXP (x0, 0);
  goto L4323;

 L5255: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case PLUS:
      goto L3971;
    case SIGN_EXTEND:
      goto L4180;
    case HIGH:
      goto L4245;
    case LO_SUM:
      goto L4255;
    case MEM:
      goto L4292;
    case ASHIFT:
      goto L4332;
    case ASHIFTRT:
      goto L4338;
    case LSHIFTRT:
      goto L4344;
    case CONST:
    case LABEL_REF:
    case SYMBOL_REF:
      goto L5259;
    default:
      goto L4298;
   }
 L5259: ATTRIBUTE_UNUSED_LABEL
  if (global_got_operand (x1, SImode))
    {
      operands[1] = x1;
      goto L4267;
    }
  goto L4298;

 L3971: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (rtx_equal_p (x2, operands[0]))
    goto L3972;
 L3977: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L3978;
    }
  goto L4298;

 L3972: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const_int_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L3973;
    }
  x2 = XEXP (x1, 0);
  goto L3977;

 L3973: ATTRIBUTE_UNUSED_LABEL
  if (
#line 731 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_MIPS16 && reload_completed && !TARGET_DEBUG_D_MODE
   && REG_P (operands[0])
   && M16_REG_P (REGNO (operands[0]))
   && GET_CODE (operands[1]) == CONST_INT
   && ((INTVAL (operands[1]) > 0x7f
	&& INTVAL (operands[1]) <= 0x7f + 0x7f)
       || (INTVAL (operands[1]) < - 0x80
	   && INTVAL (operands[1]) >= - 0x80 - 0x80))))
    {
      return gen_split_503 (insn, operands);
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  goto L3977;

 L3978: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const_int_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L3979;
    }
  goto L4298;

 L3979: ATTRIBUTE_UNUSED_LABEL
  if (
#line 760 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_MIPS16 && reload_completed && !TARGET_DEBUG_D_MODE
   && REG_P (operands[0])
   && M16_REG_P (REGNO (operands[0]))
   && REG_P (operands[1])
   && M16_REG_P (REGNO (operands[1]))
   && REGNO (operands[0]) != REGNO (operands[1])
   && GET_CODE (operands[2]) == CONST_INT
   && ((INTVAL (operands[2]) > 0x7
	&& INTVAL (operands[2]) <= 0x7 + 0x7f)
       || (INTVAL (operands[2]) < - 0x8
	   && INTVAL (operands[2]) >= - 0x8 - 0x80))))
    {
      return gen_split_504 (insn, operands);
    }
  x1 = XEXP (x0, 1);
  goto L4298;

 L4180: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case HImode:
      goto L5264;
    case QImode:
      goto L5265;
    default:
      break;
    }
  goto L4298;

 L5264: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == TRUNCATE)
    goto L4181;
  if (nonimmediate_operand (x2, HImode))
    {
      operands[1] = x2;
      goto L4213;
    }
  goto L4298;

 L4181: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L4182;
    }
  goto L4298;

 L4182: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 2253 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT && !TARGET_MIPS16) && 
#line 2255 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
( reload_completed)))
    {
      return gen_split_537 (insn, operands);
    }
  x1 = XEXP (x0, 1);
  goto L4298;

 L4213: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 2462 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!ISA_HAS_SEB_SEH && !GENERATE_MIPS16E) && 
#line 2466 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
( reload_completed && REG_P (operands[1]))))
    {
      return gen_split_552 (insn, operands);
    }
  x1 = XEXP (x0, 1);
  goto L4298;

 L5265: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == TRUNCATE)
    goto L4187;
  if (nonimmediate_operand (x2, QImode))
    {
      operands[1] = x2;
      goto L4203;
    }
  goto L4298;

 L4187: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L4188;
    }
  goto L4298;

 L4188: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 2268 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT && !TARGET_MIPS16) && 
#line 2270 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
( reload_completed)))
    {
      return gen_split_538 (insn, operands);
    }
  x1 = XEXP (x0, 1);
  goto L4298;

 L4203: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 2462 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!ISA_HAS_SEB_SEH && !GENERATE_MIPS16E) && 
#line 2466 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
( reload_completed && REG_P (operands[1]))))
    {
      return gen_split_550 (insn, operands);
    }
  x1 = XEXP (x0, 1);
  goto L4298;

 L4245: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode)
    goto L5268;
  goto L4298;

 L5268: ATTRIBUTE_UNUSED_LABEL
  if (global_got_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L4246;
    }
 L5269: ATTRIBUTE_UNUSED_LABEL
  if (local_got_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L4276;
    }
  goto L4298;

 L4246: ATTRIBUTE_UNUSED_LABEL
  if (((
#line 3073 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_EXPLICIT_RELOCS && TARGET_XGOT) && 
#line 406 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(Pmode == SImode)) && 
#line 3075 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
( reload_completed)))
    {
      return gen_split_567 (insn, operands);
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  goto L5269;

 L4276: ATTRIBUTE_UNUSED_LABEL
  if (((
#line 3120 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_EXPLICIT_RELOCS) && 
#line 406 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(Pmode == SImode)) && 
#line 3122 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
( reload_completed)))
    {
      return gen_split_573 (insn, operands);
    }
  x1 = XEXP (x0, 1);
  goto L4298;

 L4255: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L4256;
    }
  goto L4298;

 L4256: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (global_got_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L4257;
    }
  goto L4298;

 L4257: ATTRIBUTE_UNUSED_LABEL
  if (((
#line 3089 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_EXPLICIT_RELOCS && TARGET_XGOT) && 
#line 406 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(Pmode == SImode)) && 
#line 3091 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
( reload_completed)))
    {
      return gen_split_569 (insn, operands);
    }
  x1 = XEXP (x0, 1);
  goto L4298;

 L4292: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L4293;
  goto L4298;

 L4293: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[0]))
    goto L4294;
  goto L4298;

 L4294: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const_int_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L4295;
    }
  goto L4298;

 L4295: ATTRIBUTE_UNUSED_LABEL
  if (
#line 3357 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_MIPS16 && reload_completed && !TARGET_DEBUG_D_MODE
   && REG_P (operands[0])
   && M16_REG_P (REGNO (operands[0]))
   && GET_CODE (operands[1]) == CONST_INT
   && ((INTVAL (operands[1]) < 0
	&& INTVAL (operands[1]) >= -0x80)
       || (INTVAL (operands[1]) >= 32 * 4
	   && INTVAL (operands[1]) <= 31 * 4 + 0x7c)
       || (INTVAL (operands[1]) >= 0
	   && INTVAL (operands[1]) < 32 * 4
	   && (INTVAL (operands[1]) & 3) != 0))))
    {
      return gen_split_578 (insn, operands);
    }
  x1 = XEXP (x0, 1);
  goto L4298;

 L4332: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L4333;
    }
  goto L4298;

 L4333: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const_int_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L4334;
    }
  goto L4298;

 L4334: ATTRIBUTE_UNUSED_LABEL
  if (
#line 4150 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_MIPS16 && reload_completed && !TARGET_DEBUG_D_MODE
   && GET_CODE (operands[2]) == CONST_INT
   && INTVAL (operands[2]) > 8
   && INTVAL (operands[2]) <= 16))
    {
      return gen_split_602 (insn, operands);
    }
  x1 = XEXP (x0, 1);
  goto L4298;

 L4338: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L4339;
    }
  goto L4298;

 L4339: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const_int_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L4340;
    }
  goto L4298;

 L4340: ATTRIBUTE_UNUSED_LABEL
  if (
#line 4150 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_MIPS16 && reload_completed && !TARGET_DEBUG_D_MODE
   && GET_CODE (operands[2]) == CONST_INT
   && INTVAL (operands[2]) > 8
   && INTVAL (operands[2]) <= 16))
    {
      return gen_split_603 (insn, operands);
    }
  x1 = XEXP (x0, 1);
  goto L4298;

 L4344: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode)
    goto L5270;
  goto L4298;

 L5270: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L4345;
    }
 L5271: ATTRIBUTE_UNUSED_LABEL
  if (memory_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L4369;
    }
  goto L4298;

 L4345: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const_int_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L4346;
    }
  x2 = XEXP (x1, 0);
  goto L5271;

 L4346: ATTRIBUTE_UNUSED_LABEL
  if (
#line 4150 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_MIPS16 && reload_completed && !TARGET_DEBUG_D_MODE
   && GET_CODE (operands[2]) == CONST_INT
   && INTVAL (operands[2]) > 8
   && INTVAL (operands[2]) <= 16))
    {
      return gen_split_604 (insn, operands);
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  goto L5271;

 L4369: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (immediate_operand (x2, SImode))
    {
      operands[2] = x2;
      return gen_split_608 (insn, operands);
    }
  goto L4298;

 L4267: ATTRIBUTE_UNUSED_LABEL
  if (((
#line 3103 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_EXPLICIT_RELOCS && !TARGET_XGOT) && 
#line 406 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(Pmode == SImode)) && 
#line 3105 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
( reload_completed)))
    {
      return gen_split_571 (insn, operands);
    }
  x1 = XEXP (x0, 1);
  goto L4298;

 L4299: ATTRIBUTE_UNUSED_LABEL
  if (
#line 3398 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_MIPS16 && reload_completed && !TARGET_DEBUG_D_MODE
   && REG_P (operands[0])
   && M16_REG_P (REGNO (operands[0]))
   && GET_CODE (operands[1]) == CONST_INT
   && INTVAL (operands[1]) >= 0x100
   && INTVAL (operands[1]) <= 0xff + 0x7f))
    {
      return gen_split_579 (insn, operands);
    }
  x1 = XEXP (x0, 0);
  goto L4323;

 L5249: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, DImode))
    {
      operands[0] = x1;
      goto L3982;
    }
 L5252: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x1, DImode))
    {
      operands[0] = x1;
      goto L4316;
    }
  goto L4323;

 L3982: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == DImode)
    goto L5272;
  x1 = XEXP (x0, 0);
  goto L5252;

 L5272: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case PLUS:
      goto L3983;
    case SIGN_EXTEND:
      goto L3995;
    case ZERO_EXTEND:
      goto L4192;
    case HIGH:
      goto L4227;
    case LO_SUM:
      goto L4261;
    case MEM:
      goto L4285;
    case ASHIFT:
      goto L4350;
    case ASHIFTRT:
      goto L4356;
    case LSHIFTRT:
      goto L4362;
    case CONST:
    case LABEL_REF:
    case SYMBOL_REF:
      goto L5277;
    default:
      x1 = XEXP (x0, 0);
      goto L5252;
   }
 L5277: ATTRIBUTE_UNUSED_LABEL
  if (global_got_operand (x1, DImode))
    {
      operands[1] = x1;
      goto L4271;
    }
  x1 = XEXP (x0, 0);
  goto L5252;

 L3983: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (rtx_equal_p (x2, operands[0]))
    goto L3984;
 L3989: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L3990;
    }
  x1 = XEXP (x0, 0);
  goto L5252;

 L3984: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const_int_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L3985;
    }
  x2 = XEXP (x1, 0);
  goto L3989;

 L3985: ATTRIBUTE_UNUSED_LABEL
  if (
#line 792 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_MIPS16 && TARGET_64BIT && reload_completed && !TARGET_DEBUG_D_MODE
   && REG_P (operands[0])
   && M16_REG_P (REGNO (operands[0]))
   && GET_CODE (operands[1]) == CONST_INT
   && ((INTVAL (operands[1]) > 0xf
	&& INTVAL (operands[1]) <= 0xf + 0xf)
       || (INTVAL (operands[1]) < - 0x10
	   && INTVAL (operands[1]) >= - 0x10 - 0x10))))
    {
      return gen_split_505 (insn, operands);
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  goto L3989;

 L3990: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const_int_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L3991;
    }
  x1 = XEXP (x0, 0);
  goto L5252;

 L3991: ATTRIBUTE_UNUSED_LABEL
  if (
#line 821 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_MIPS16 && TARGET_64BIT && reload_completed && !TARGET_DEBUG_D_MODE
   && REG_P (operands[0])
   && M16_REG_P (REGNO (operands[0]))
   && REG_P (operands[1])
   && M16_REG_P (REGNO (operands[1]))
   && REGNO (operands[0]) != REGNO (operands[1])
   && GET_CODE (operands[2]) == CONST_INT
   && ((INTVAL (operands[2]) > 0x7
	&& INTVAL (operands[2]) <= 0x7 + 0xf)
       || (INTVAL (operands[2]) < - 0x8
	   && INTVAL (operands[2]) >= - 0x8 - 0x10))))
    {
      return gen_split_506 (insn, operands);
    }
  x1 = XEXP (x0, 0);
  goto L5252;

 L3995: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L5282;
    case QImode:
      goto L5284;
    case HImode:
      goto L5285;
    default:
      break;
    }
  x1 = XEXP (x0, 0);
  goto L5252;

 L5282: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == PLUS)
    goto L3996;
  if (nonimmediate_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L4198;
    }
  x1 = XEXP (x0, 0);
  goto L5252;

 L3996: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L3997;
    }
  x1 = XEXP (x0, 0);
  goto L5252;

 L3997: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (arith_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L3998;
    }
  x1 = XEXP (x0, 0);
  goto L5252;

 L3998: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 868 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT && TARGET_MIPS16) && 
#line 870 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
( reload_completed)))
    {
      return gen_split_507 (insn, operands);
    }
  x1 = XEXP (x0, 0);
  goto L5252;

 L4198: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 2430 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT) && 
#line 2434 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
( reload_completed && register_operand (operands[1], VOIDmode))))
    {
      return gen_split_545 (insn, operands);
    }
  x1 = XEXP (x0, 0);
  goto L5252;

 L5284: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, QImode))
    {
      operands[1] = x2;
      goto L4208;
    }
  x1 = XEXP (x0, 0);
  goto L5252;

 L4208: ATTRIBUTE_UNUSED_LABEL
  if (((
#line 2462 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!ISA_HAS_SEB_SEH && !GENERATE_MIPS16E) && 
#line 402 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT)) && 
#line 2466 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
( reload_completed && REG_P (operands[1]))))
    {
      return gen_split_551 (insn, operands);
    }
  x1 = XEXP (x0, 0);
  goto L5252;

 L5285: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, HImode))
    {
      operands[1] = x2;
      goto L4218;
    }
  x1 = XEXP (x0, 0);
  goto L5252;

 L4218: ATTRIBUTE_UNUSED_LABEL
  if (((
#line 2462 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(!ISA_HAS_SEB_SEH && !GENERATE_MIPS16E) && 
#line 402 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT)) && 
#line 2466 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
( reload_completed && REG_P (operands[1]))))
    {
      return gen_split_553 (insn, operands);
    }
  x1 = XEXP (x0, 0);
  goto L5252;

 L4192: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L4193;
    }
  x1 = XEXP (x0, 0);
  goto L5252;

 L4193: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 2321 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT) && 
#line 2325 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
( reload_completed && REG_P (operands[1]))))
    {
      return gen_split_539 (insn, operands);
    }
  x1 = XEXP (x0, 0);
  goto L5252;

 L4227: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == DImode)
    goto L5286;
  x1 = XEXP (x0, 0);
  goto L5252;

 L5286: ATTRIBUTE_UNUSED_LABEL
  if (general_symbolic_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L4228;
    }
 L5287: ATTRIBUTE_UNUSED_LABEL
  if (global_got_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L4251;
    }
 L5288: ATTRIBUTE_UNUSED_LABEL
  if (local_got_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L4281;
    }
  x1 = XEXP (x0, 0);
  goto L5252;

 L4228: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 2999 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_EXPLICIT_RELOCS && ABI_HAS_64BIT_SYMBOLS) && 
#line 3001 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
( flow2_completed)))
    {
      return gen_split_564 (insn, operands);
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  goto L5287;

 L4251: ATTRIBUTE_UNUSED_LABEL
  if (((
#line 3073 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_EXPLICIT_RELOCS && TARGET_XGOT) && 
#line 406 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(Pmode == DImode)) && 
#line 3075 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
( reload_completed)))
    {
      return gen_split_568 (insn, operands);
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  goto L5288;

 L4281: ATTRIBUTE_UNUSED_LABEL
  if (((
#line 3120 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_EXPLICIT_RELOCS) && 
#line 406 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(Pmode == DImode)) && 
#line 3122 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
( reload_completed)))
    {
      return gen_split_574 (insn, operands);
    }
  x1 = XEXP (x0, 0);
  goto L5252;

 L4261: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L4262;
    }
  x1 = XEXP (x0, 0);
  goto L5252;

 L4262: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (global_got_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L4263;
    }
  x1 = XEXP (x0, 0);
  goto L5252;

 L4263: ATTRIBUTE_UNUSED_LABEL
  if (((
#line 3089 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_EXPLICIT_RELOCS && TARGET_XGOT) && 
#line 406 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(Pmode == DImode)) && 
#line 3091 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
( reload_completed)))
    {
      return gen_split_570 (insn, operands);
    }
  x1 = XEXP (x0, 0);
  goto L5252;

 L4285: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == PLUS)
    goto L4286;
  x1 = XEXP (x0, 0);
  goto L5252;

 L4286: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[0]))
    goto L4287;
  x1 = XEXP (x0, 0);
  goto L5252;

 L4287: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const_int_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L4288;
    }
  x1 = XEXP (x0, 0);
  goto L5252;

 L4288: ATTRIBUTE_UNUSED_LABEL
  if (
#line 3262 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT && TARGET_MIPS16 && reload_completed
   && !TARGET_DEBUG_D_MODE
   && REG_P (operands[0])
   && M16_REG_P (REGNO (operands[0]))
   && GET_CODE (operands[1]) == CONST_INT
   && ((INTVAL (operands[1]) < 0
	&& INTVAL (operands[1]) >= -0x10)
       || (INTVAL (operands[1]) >= 32 * 8
	   && INTVAL (operands[1]) <= 31 * 8 + 0x8)
       || (INTVAL (operands[1]) >= 0
	   && INTVAL (operands[1]) < 32 * 8
	   && (INTVAL (operands[1]) & 7) != 0))))
    {
      return gen_split_576 (insn, operands);
    }
  x1 = XEXP (x0, 0);
  goto L5252;

 L4350: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L4351;
    }
  x1 = XEXP (x0, 0);
  goto L5252;

 L4351: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const_int_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L4352;
    }
  x1 = XEXP (x0, 0);
  goto L5252;

 L4352: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 4150 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_MIPS16 && reload_completed && !TARGET_DEBUG_D_MODE
   && GET_CODE (operands[2]) == CONST_INT
   && INTVAL (operands[2]) > 8
   && INTVAL (operands[2]) <= 16) && 
#line 402 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT)))
    {
      return gen_split_605 (insn, operands);
    }
  x1 = XEXP (x0, 0);
  goto L5252;

 L4356: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L4357;
    }
  x1 = XEXP (x0, 0);
  goto L5252;

 L4357: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const_int_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L4358;
    }
  x1 = XEXP (x0, 0);
  goto L5252;

 L4358: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 4150 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_MIPS16 && reload_completed && !TARGET_DEBUG_D_MODE
   && GET_CODE (operands[2]) == CONST_INT
   && INTVAL (operands[2]) > 8
   && INTVAL (operands[2]) <= 16) && 
#line 402 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT)))
    {
      return gen_split_606 (insn, operands);
    }
  x1 = XEXP (x0, 0);
  goto L5252;

 L4362: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L4363;
    }
  x1 = XEXP (x0, 0);
  goto L5252;

 L4363: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const_int_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L4364;
    }
  x1 = XEXP (x0, 0);
  goto L5252;

 L4364: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 4150 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_MIPS16 && reload_completed && !TARGET_DEBUG_D_MODE
   && GET_CODE (operands[2]) == CONST_INT
   && INTVAL (operands[2]) > 8
   && INTVAL (operands[2]) <= 16) && 
#line 402 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT)))
    {
      return gen_split_607 (insn, operands);
    }
  x1 = XEXP (x0, 0);
  goto L5252;

 L4271: ATTRIBUTE_UNUSED_LABEL
  if (((
#line 3103 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_EXPLICIT_RELOCS && !TARGET_XGOT) && 
#line 406 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(Pmode == DImode)) && 
#line 3105 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
( reload_completed)))
    {
      return gen_split_572 (insn, operands);
    }
  x1 = XEXP (x0, 0);
  goto L5252;

 L4316: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (move_operand (x1, DImode))
    {
      operands[1] = x1;
      goto L4317;
    }
  x1 = XEXP (x0, 0);
  goto L4323;

 L4317: ATTRIBUTE_UNUSED_LABEL
  if (
#line 3785 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(reload_completed && !TARGET_64BIT
   && mips_split_64bit_move_p (operands[0], operands[1])))
    {
      return gen_split_588 (insn, operands);
    }
  x1 = XEXP (x0, 0);
  goto L4323;

 L5250: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, HImode))
    {
      operands[0] = x1;
      goto L4221;
    }
  goto L4323;

 L4221: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == HImode)
    goto L5289;
  x1 = XEXP (x0, 0);
  goto L4323;

 L5289: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case SIGN_EXTEND:
      goto L4222;
    case MEM:
      goto L4303;
    default:
     break;
   }
  x1 = XEXP (x0, 0);
  goto L4323;

 L4222: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, QImode))
    {
      operands[1] = x2;
      goto L4223;
    }
  x1 = XEXP (x0, 0);
  goto L4323;

 L4223: ATTRIBUTE_UNUSED_LABEL
  if (
#line 2496 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(reload_completed))
    {
      return gen_split_554 (insn, operands);
    }
  x1 = XEXP (x0, 0);
  goto L4323;

 L4303: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L4304;
  x1 = XEXP (x0, 0);
  goto L4323;

 L4304: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[0]))
    goto L4305;
  x1 = XEXP (x0, 0);
  goto L4323;

 L4305: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const_int_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L4306;
    }
  x1 = XEXP (x0, 0);
  goto L4323;

 L4306: ATTRIBUTE_UNUSED_LABEL
  if (
#line 3565 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_MIPS16 && reload_completed && !TARGET_DEBUG_D_MODE
   && REG_P (operands[0])
   && M16_REG_P (REGNO (operands[0]))
   && GET_CODE (operands[1]) == CONST_INT
   && ((INTVAL (operands[1]) < 0
	&& INTVAL (operands[1]) >= -0x80)
       || (INTVAL (operands[1]) >= 32 * 2
	   && INTVAL (operands[1]) <= 31 * 2 + 0x7e)
       || (INTVAL (operands[1]) >= 0
	   && INTVAL (operands[1]) < 32 * 2
	   && (INTVAL (operands[1]) & 1) != 0))))
    {
      return gen_split_583 (insn, operands);
    }
  x1 = XEXP (x0, 0);
  goto L4323;

 L5251: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, QImode))
    {
      operands[0] = x1;
      goto L4309;
    }
  goto L4323;

 L4309: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == QImode
      && GET_CODE (x1) == MEM)
    goto L4310;
  x1 = XEXP (x0, 0);
  goto L4323;

 L4310: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L4311;
  x1 = XEXP (x0, 0);
  goto L4323;

 L4311: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[0]))
    goto L4312;
  x1 = XEXP (x0, 0);
  goto L4323;

 L4312: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const_int_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L4313;
    }
  x1 = XEXP (x0, 0);
  goto L4323;

 L4313: ATTRIBUTE_UNUSED_LABEL
  if (
#line 3660 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_MIPS16 && reload_completed && !TARGET_DEBUG_D_MODE
   && REG_P (operands[0])
   && M16_REG_P (REGNO (operands[0]))
   && GET_CODE (operands[1]) == CONST_INT
   && ((INTVAL (operands[1]) < 0
	&& INTVAL (operands[1]) >= -0x80)
       || (INTVAL (operands[1]) >= 32
	   && INTVAL (operands[1]) <= 31 + 0x7f))))
    {
      return gen_split_585 (insn, operands);
    }
  x1 = XEXP (x0, 0);
  goto L4323;

 L5253: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x1, DFmode))
    {
      operands[0] = x1;
      goto L4320;
    }
  goto L4323;

 L4320: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (move_operand (x1, DFmode))
    {
      operands[1] = x1;
      goto L4321;
    }
  x1 = XEXP (x0, 0);
  goto L4323;

 L4321: ATTRIBUTE_UNUSED_LABEL
  if (
#line 3796 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(reload_completed && !TARGET_64BIT
   && mips_split_64bit_move_p (operands[0], operands[1])))
    {
      return gen_split_589 (insn, operands);
    }
  x1 = XEXP (x0, 0);
  goto L4323;

 L4324: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (const_int_operand (x1, VOIDmode))
    {
      operands[1] = x1;
      goto L4325;
    }
  goto ret0;

 L4325: ATTRIBUTE_UNUSED_LABEL
  if (
#line 3809 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_MIPS16 && reload_completed && INTVAL (operands[1]) < 0))
    {
      return gen_split_590 (insn, operands);
    }
  goto ret0;
 ret0:
  return 0;
}

rtx
split_insns (rtx x0 ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x1 ATTRIBUTE_UNUSED;
  rtx x2 ATTRIBUTE_UNUSED;
  rtx x3 ATTRIBUTE_UNUSED;
  rtx x4 ATTRIBUTE_UNUSED;
  rtx x5 ATTRIBUTE_UNUSED;
  rtx x6 ATTRIBUTE_UNUSED;
  rtx x7 ATTRIBUTE_UNUSED;
  rtx tem ATTRIBUTE_UNUSED;
  recog_data.insn = NULL_RTX;

  switch (GET_CODE (x0))
    {
    case SET:
      goto L3969;
    case PARALLEL:
      goto L5244;
    case UNSPEC_VOLATILE:
      goto L5246;
    default:
     break;
   }
 L4411: ATTRIBUTE_UNUSED_LABEL
  if (small_data_pattern (x0, VOIDmode))
    {
      operands[0] = x0;
      goto L4412;
    }
 L4413: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x0) == SET)
    goto L4414;
  goto ret0;

 L3969: ATTRIBUTE_UNUSED_LABEL
  tem = split_1 (x0, insn);
  if (tem != 0)
    return tem;
  goto L4411;

 L5244: ATTRIBUTE_UNUSED_LABEL
  switch (XVECLEN (x0, 0))
    {
    case 4:
      goto L4030;
    case 2:
      goto L4236;
    case 3:
      goto L4397;
    default:
      break;
    }
  goto L4411;

 L4030: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 0);
  if (GET_CODE (x1) == SET)
    goto L4031;
  goto L4411;

 L4031: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L5291;
    case DImode:
      goto L5292;
    default:
      break;
    }
  goto L4411;

 L5291: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L4032;
    }
  goto L4411;

 L4032: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode)
    goto L5293;
  goto L4411;

 L5293: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case PLUS:
      goto L4033;
    case MINUS:
      goto L4063;
    default:
     break;
   }
  goto L4411;

 L4033: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == MULT)
    goto L4034;
  goto L4411;

 L4034: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L4035;
    }
  goto L4411;

 L4035: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (register_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L4036;
    }
  goto L4411;

 L4036: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, SImode))
    {
      operands[3] = x3;
      goto L4037;
    }
  goto L4411;

 L4037: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4038;
  goto L4411;

 L4038: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L4039;
    }
  goto L4411;

 L4039: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L4040;
  goto L4411;

 L4040: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[5] = x2;
      goto L4041;
    }
  goto L4411;

 L4041: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 3);
  if (GET_CODE (x1) == CLOBBER)
    goto L4042;
  goto L4411;

 L4042: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[6] = x2;
      goto L4043;
    }
  goto L4411;

 L4043: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1180 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(reload_completed && !TARGET_DEBUG_D_MODE
   && GP_REG_P (true_regnum (operands[0]))
   && GP_REG_P (true_regnum (operands[3]))))
    {
      return gen_split_514 (insn, operands);
    }
 L4058: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1199 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(reload_completed && !TARGET_DEBUG_D_MODE
   && GP_REG_P (true_regnum (operands[0]))
   && true_regnum (operands[3]) == LO_REGNUM))
    {
      return gen_split_515 (insn, operands);
    }
  goto L4411;

 L4063: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L4064;
    }
  goto L4411;

 L4064: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == MULT)
    goto L4065;
  goto L4411;

 L4065: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L4066;
    }
  goto L4411;

 L4066: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (register_operand (x4, SImode))
    {
      operands[3] = x4;
      goto L4067;
    }
  goto L4411;

 L4067: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4068;
  goto L4411;

 L4068: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L4069;
    }
  goto L4411;

 L4069: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L4070;
  goto L4411;

 L4070: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[5] = x2;
      goto L4071;
    }
  goto L4411;

 L4071: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 3);
  if (GET_CODE (x1) == CLOBBER)
    goto L4072;
  goto L4411;

 L4072: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[6] = x2;
      goto L4073;
    }
  goto L4411;

 L4073: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 1261 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_MACC && !ISA_HAS_MSAC) && 
#line 1263 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
( reload_completed)))
    {
      return gen_split_516 (insn, operands);
    }
 L4131: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1435 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(reload_completed && !TARGET_DEBUG_D_MODE
   && GP_REG_P (true_regnum (operands[0]))
   && GP_REG_P (true_regnum (operands[1]))))
    {
      return gen_split_520 (insn, operands);
    }
 L4146: ATTRIBUTE_UNUSED_LABEL
  if (
#line 1454 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(reload_completed && !TARGET_DEBUG_D_MODE
   && GP_REG_P (true_regnum (operands[0]))
   && true_regnum (operands[1]) == LO_REGNUM))
    {
      return gen_split_521 (insn, operands);
    }
  goto L4411;

 L5292: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L4150;
    }
  goto L4411;

 L4150: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == MULT)
    goto L4151;
  goto L4411;

 L4151: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DImode)
    goto L5295;
  goto L4411;

 L5295: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x3))
    {
    case SIGN_EXTEND:
      goto L4152;
    case ZERO_EXTEND:
      goto L4167;
    default:
     break;
   }
  goto L4411;

 L4152: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L4153;
    }
  goto L4411;

 L4153: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == DImode
      && GET_CODE (x3) == SIGN_EXTEND)
    goto L4154;
  goto L4411;

 L4154: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L4155;
    }
  goto L4411;

 L4155: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4156;
  goto L4411;

 L4156: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[3] = x2;
      goto L4157;
    }
  goto L4411;

 L4157: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L4158;
  goto L4411;

 L4158: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[4] = x2;
      goto L4159;
    }
  goto L4411;

 L4159: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 3);
  if (GET_CODE (x1) == CLOBBER)
    goto L4160;
  goto L4411;

 L4160: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[5] = x2;
      goto L4161;
    }
  goto L4411;

 L4161: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 1530 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT && !TARGET_FIX_R4000) && 
#line 1532 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
( reload_completed)))
    {
      return gen_split_524 (insn, operands);
    }
  goto L4411;

 L4167: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L4168;
    }
  goto L4411;

 L4168: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == DImode
      && GET_CODE (x3) == ZERO_EXTEND)
    goto L4169;
  goto L4411;

 L4169: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L4170;
    }
  goto L4411;

 L4170: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4171;
  goto L4411;

 L4171: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[3] = x2;
      goto L4172;
    }
  goto L4411;

 L4172: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L4173;
  goto L4411;

 L4173: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[4] = x2;
      goto L4174;
    }
  goto L4411;

 L4174: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 3);
  if (GET_CODE (x1) == CLOBBER)
    goto L4175;
  goto L4411;

 L4175: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[5] = x2;
      goto L4176;
    }
  goto L4411;

 L4176: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 1530 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_64BIT && !TARGET_FIX_R4000) && 
#line 1532 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
( reload_completed)))
    {
      return gen_split_525 (insn, operands);
    }
  goto L4411;

 L4236: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 0);
  switch (GET_CODE (x1))
    {
    case SET:
      goto L4237;
    case UNSPEC:
      goto L5297;
    case CALL:
      goto L4382;
    default:
     break;
   }
  goto L4411;

 L4237: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L4238;
    }
 L4389: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, VOIDmode))
    {
      operands[0] = x2;
      goto L4390;
    }
  goto L4411;

 L4238: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (general_symbolic_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L4239;
    }
  x2 = XEXP (x1, 0);
  goto L4389;

 L4239: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4240;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L4389;

 L4240: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L4241;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L4389;

 L4241: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 3053 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_EXPLICIT_RELOCS && ABI_HAS_64BIT_SYMBOLS && cse_not_expected) && 
#line 3055 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
( reload_completed)))
    {
      return gen_split_566 (insn, operands);
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L4389;

 L4390: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CALL)
    goto L4391;
  goto L4411;

 L4391: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == MEM)
    goto L4392;
  goto L4411;

 L4392: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (call_insn_operand (x4, VOIDmode))
    {
      operands[1] = x4;
      goto L4393;
    }
  goto L4411;

 L4393: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  operands[2] = x3;
  goto L4394;

 L4394: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4395;
  goto L4411;

 L4395: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 31
      && 
#line 5167 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(reload_completed && TARGET_SPLIT_CALLS && (operands[3] = insn)))
    {
      return gen_split_656 (insn, operands);
    }
  goto L4411;

 L5297: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x1, 0) == 1
      && XINT (x1, 1) == 7)
    goto L4372;
  goto L4411;

 L4372: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, VOIDmode))
    {
      operands[0] = x2;
      goto L4373;
    }
  goto L4411;

 L4373: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4374;
  goto L4411;

 L4374: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, VOIDmode))
    {
      operands[1] = x2;
      goto L4375;
    }
  goto L4411;

 L4375: ATTRIBUTE_UNUSED_LABEL
  if (
#line 4952 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(reload_completed && !TARGET_DEBUG_D_MODE))
    {
      return gen_split_649 (insn, operands);
    }
  goto L4411;

 L4382: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == MEM)
    goto L4383;
  goto L4411;

 L4383: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (call_insn_operand (x3, VOIDmode))
    {
      operands[0] = x3;
      goto L4384;
    }
  goto L4411;

 L4384: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  operands[1] = x2;
  goto L4385;

 L4385: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4386;
  goto L4411;

 L4386: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 31
      && 
#line 5127 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(reload_completed && TARGET_SPLIT_CALLS && (operands[2] = insn)))
    {
      return gen_split_654 (insn, operands);
    }
  goto L4411;

 L4397: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 0);
  if (GET_CODE (x1) == SET)
    goto L4398;
  goto L4411;

 L4398: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, VOIDmode))
    {
      operands[0] = x2;
      goto L4399;
    }
  goto L4411;

 L4399: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CALL)
    goto L4400;
  goto L4411;

 L4400: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == MEM)
    goto L4401;
  goto L4411;

 L4401: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (call_insn_operand (x4, VOIDmode))
    {
      operands[1] = x4;
      goto L4402;
    }
  goto L4411;

 L4402: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  operands[2] = x3;
  goto L4403;

 L4403: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L4404;
  goto L4411;

 L4404: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, VOIDmode))
    {
      operands[3] = x2;
      goto L4405;
    }
  goto L4411;

 L4405: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CALL)
    goto L4406;
  goto L4411;

 L4406: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == MEM)
    goto L4407;
  goto L4411;

 L4407: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L4408;
  goto L4411;

 L4408: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2]))
    goto L4409;
  goto L4411;

 L4409: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L4410;
  goto L4411;

 L4410: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 31
      && 
#line 5200 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(reload_completed && TARGET_SPLIT_CALLS && (operands[4] = insn)))
    {
      return gen_split_657 (insn, operands);
    }
  goto L4411;

 L5246: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x0, 0) == 2
      && XINT (x0, 1) == 22)
    goto L4327;
  goto L4411;

 L4327: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 0);
  operands[0] = x1;
  goto L4328;

 L4328: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (register_operand (x1, VOIDmode))
    {
      operands[1] = x1;
      return gen_split_594 (insn, operands);
    }
  goto L4411;

 L4412: ATTRIBUTE_UNUSED_LABEL
  if (
#line 5401 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(reload_completed))
    {
      return gen_split_663 (insn, operands);
    }
  goto L4413;

 L4414: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 0);
  if (register_operand (x1, CCV4mode))
    {
      operands[0] = x1;
      goto L4415;
    }
  goto ret0;

 L4415: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == CCV4mode)
    goto L5298;
  goto ret0;

 L5298: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x1) == UNSPEC)
    goto L5300;
  goto ret0;

 L5300: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x1, 0) == 5)
    goto L5302;
  goto ret0;

 L5302: ATTRIBUTE_UNUSED_LABEL
  switch (XINT (x1, 1))
    {
    case 201L:
      goto L4416;
    case 203L:
      goto L4425;
    default:
      break;
    }
  goto ret0;

 L4416: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V2SFmode))
    {
      operands[1] = x2;
      goto L4417;
    }
  goto ret0;

 L4417: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V2SFmode))
    {
      operands[2] = x2;
      goto L4418;
    }
  goto ret0;

 L4418: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 2);
  if (register_operand (x2, V2SFmode))
    {
      operands[3] = x2;
      goto L4419;
    }
  goto ret0;

 L4419: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 3);
  if (register_operand (x2, V2SFmode))
    {
      operands[4] = x2;
      goto L4420;
    }
  goto ret0;

 L4420: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 4);
  if (const_int_operand (x2, VOIDmode))
    {
      operands[5] = x2;
      goto L4421;
    }
  goto ret0;

 L4421: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 307 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-ps-3d.md"
(TARGET_PAIRED_SINGLE_FLOAT) && 
#line 309 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-ps-3d.md"
( reload_completed)))
    {
      return gen_split_670 (insn, operands);
    }
  goto ret0;

 L4425: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V2SFmode))
    {
      operands[1] = x2;
      goto L4426;
    }
  goto ret0;

 L4426: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V2SFmode))
    {
      operands[2] = x2;
      goto L4427;
    }
  goto ret0;

 L4427: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 2);
  if (register_operand (x2, V2SFmode))
    {
      operands[3] = x2;
      goto L4428;
    }
  goto ret0;

 L4428: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 3);
  if (register_operand (x2, V2SFmode))
    {
      operands[4] = x2;
      goto L4429;
    }
  goto ret0;

 L4429: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 4);
  if (const_int_operand (x2, VOIDmode))
    {
      operands[5] = x2;
      goto L4430;
    }
  goto ret0;

 L4430: ATTRIBUTE_UNUSED_LABEL
  if ((
#line 336 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-ps-3d.md"
(TARGET_MIPS3D) && 
#line 338 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips-ps-3d.md"
( reload_completed)))
    {
      return gen_split_671 (insn, operands);
    }
  goto ret0;
 ret0:
  return 0;
}

rtx
peephole2_insns (rtx x0 ATTRIBUTE_UNUSED,
	rtx insn ATTRIBUTE_UNUSED,
	int *_pmatch_len ATTRIBUTE_UNUSED)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x1 ATTRIBUTE_UNUSED;
  rtx x2 ATTRIBUTE_UNUSED;
  rtx x3 ATTRIBUTE_UNUSED;
  rtx x4 ATTRIBUTE_UNUSED;
  rtx x5 ATTRIBUTE_UNUSED;
  rtx x6 ATTRIBUTE_UNUSED;
  rtx x7 ATTRIBUTE_UNUSED;
  rtx tem ATTRIBUTE_UNUSED;
  recog_data.insn = NULL_RTX;

  if (peep2_current_count >= 2)
    goto L4000;
 L4100: ATTRIBUTE_UNUSED_LABEL
  if (peep2_current_count >= 3)
    goto L4101;
 L4230: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x0) == SET)
    goto L4231;
  goto ret0;

 L4000: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x0))
    {
    case PARALLEL:
      goto L5304;
    case SET:
      goto L4090;
    default:
     break;
   }
  goto L4100;

 L5304: ATTRIBUTE_UNUSED_LABEL
  switch (XVECLEN (x0, 0))
    {
    case 3:
      goto L4001;
    case 2:
      goto L4017;
    default:
      break;
    }
  goto L4100;

 L4001: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 0);
  if (GET_CODE (x1) == SET)
    goto L4002;
  goto L4100;

 L4002: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L4003;
    }
  goto L4100;

 L4003: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode)
    goto L5306;
  goto L4100;

 L5306: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == MULT)
    goto L4004;
  if (macc_msac_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L4079;
    }
  goto L4100;

 L4004: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L4005;
    }
  goto L4100;

 L4005: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L4006;
    }
  goto L4100;

 L4006: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4007;
  goto L4100;

 L4007: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L4008;
    }
  goto L4100;

 L4008: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L4009;
  goto L4100;

 L4009: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == SCRATCH)
    goto L4010;
  goto L4100;

 L4010: ATTRIBUTE_UNUSED_LABEL
  tem = peep2_next_insn (1);
  x1 = PATTERN (tem);
  if (GET_CODE (x1) == SET)
    goto L4011;
  goto L4100;

 L4011: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L4012;
    }
  goto L4100;

 L4012: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 2
      && XINT (x2, 1) == 26)
    goto L4013;
  goto L4100;

 L4013: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (rtx_equal_p (x3, operands[0]))
    goto L4014;
  goto L4100;

 L4014: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (rtx_equal_p (x3, operands[3])
      && 
#line 1075 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(GENERATE_MULT3_SI && peep2_reg_dead_p (2, operands[0])))
    {
      *_pmatch_len = 1;
      tem = gen_peephole2_512 (insn, operands);
      if (tem != 0)
        return tem;
    }
  goto L4100;

 L4079: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4080;
  goto L4100;

 L4080: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L4081;
    }
  goto L4100;

 L4081: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L4082;
  goto L4100;

 L4082: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == SCRATCH)
    goto L4083;
  goto L4100;

 L4083: ATTRIBUTE_UNUSED_LABEL
  tem = peep2_next_insn (1);
  x1 = PATTERN (tem);
  if (GET_CODE (x1) == SET)
    goto L4084;
  goto L4100;

 L4084: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L4085;
    }
  goto L4100;

 L4085: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 2
      && XINT (x2, 1) == 26)
    goto L4086;
  goto L4100;

 L4086: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (rtx_equal_p (x3, operands[0]))
    goto L4087;
  goto L4100;

 L4087: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (rtx_equal_p (x3, operands[2]))
    {
      *_pmatch_len = 1;
      tem = gen_peephole2_517 (insn, operands);
      if (tem != 0)
        return tem;
    }
  goto L4100;

 L4017: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 0);
  if (GET_CODE (x1) == SET)
    goto L4018;
  goto L4100;

 L4018: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L4019;
    }
  goto L4100;

 L4019: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == MULT)
    goto L4020;
  goto L4100;

 L4020: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L4021;
    }
  goto L4100;

 L4021: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L4022;
    }
  goto L4100;

 L4022: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4023;
  goto L4100;

 L4023: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L4024;
    }
  goto L4100;

 L4024: ATTRIBUTE_UNUSED_LABEL
  tem = peep2_next_insn (1);
  x1 = PATTERN (tem);
  if (GET_CODE (x1) == SET)
    goto L4025;
  goto L4100;

 L4025: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L4026;
    }
  goto L4100;

 L4026: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 2
      && XINT (x2, 1) == 26)
    goto L4027;
  goto L4100;

 L4027: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (rtx_equal_p (x3, operands[0]))
    goto L4028;
  goto L4100;

 L4028: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (rtx_equal_p (x3, operands[3])
      && 
#line 1122 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(ISA_HAS_MACC && !GENERATE_MULT3_SI))
    {
      *_pmatch_len = 1;
      tem = gen_peephole2_513 (insn, operands);
      if (tem != 0)
        return tem;
    }
  goto L4100;

 L4090: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 0);
  if (register_operand (x1, SImode))
    {
      operands[1] = x1;
      goto L4091;
    }
  goto L4100;

 L4091: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (register_operand (x1, SImode))
    {
      operands[2] = x1;
      goto L4092;
    }
  goto L4100;

 L4092: ATTRIBUTE_UNUSED_LABEL
  tem = peep2_next_insn (1);
  x1 = PATTERN (tem);
  if (GET_CODE (x1) == PARALLEL
      && XVECLEN (x1, 0) == 3)
    goto L4093;
  goto L4100;

 L4093: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (GET_CODE (x2) == SET)
    goto L4094;
  goto L4100;

 L4094: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      operands[3] = x3;
      goto L4095;
    }
  goto L4100;

 L4095: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (macc_msac_operand (x3, SImode))
    {
      operands[4] = x3;
      goto L4096;
    }
  goto L4100;

 L4096: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (GET_CODE (x2) == CLOBBER)
    goto L4097;
  goto L4100;

 L4097: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      operands[5] = x3;
      goto L4098;
    }
  goto L4100;

 L4098: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 2);
  if (GET_CODE (x2) == CLOBBER)
    goto L4099;
  goto L4100;

 L4099: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1])
      && 
#line 1357 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(GENERATE_MULT3_SI
   && true_regnum (operands[1]) == LO_REGNUM
   && peep2_reg_dead_p (2, operands[1])
   && GP_REG_P (true_regnum (operands[3]))))
    {
      *_pmatch_len = 1;
      tem = gen_peephole2_518 (insn, operands);
      if (tem != 0)
        return tem;
    }
  goto L4100;

 L4101: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x0) == SET)
    goto L4102;
  goto L4230;

 L4102: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 0);
  if (register_operand (x1, SImode))
    {
      operands[1] = x1;
      goto L4103;
    }
  goto L4230;

 L4103: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (register_operand (x1, SImode))
    {
      operands[2] = x1;
      goto L4104;
    }
  goto L4230;

 L4104: ATTRIBUTE_UNUSED_LABEL
  tem = peep2_next_insn (1);
  x1 = PATTERN (tem);
  if (GET_CODE (x1) == PARALLEL
      && XVECLEN (x1, 0) == 3)
    goto L4105;
  goto L4230;

 L4105: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (GET_CODE (x2) == SET)
    goto L4106;
  goto L4230;

 L4106: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L4107;
  goto L4230;

 L4107: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (macc_msac_operand (x3, SImode))
    {
      operands[3] = x3;
      goto L4108;
    }
  goto L4230;

 L4108: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (GET_CODE (x2) == CLOBBER)
    goto L4109;
  goto L4230;

 L4109: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      operands[4] = x3;
      goto L4110;
    }
  goto L4230;

 L4110: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 2);
  if (GET_CODE (x2) == CLOBBER)
    goto L4111;
  goto L4230;

 L4111: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == SCRATCH)
    goto L4112;
  goto L4230;

 L4112: ATTRIBUTE_UNUSED_LABEL
  tem = peep2_next_insn (2);
  x1 = PATTERN (tem);
  if (GET_CODE (x1) == SET)
    goto L4113;
  goto L4230;

 L4113: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[5] = x2;
      goto L4114;
    }
  goto L4230;

 L4114: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 2
      && XINT (x2, 1) == 26)
    goto L4115;
  goto L4230;

 L4115: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L4116;
  goto L4230;

 L4116: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (rtx_equal_p (x3, operands[4])
      && 
#line 1396 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(GENERATE_MULT3_SI && peep2_reg_dead_p (3, operands[1])))
    {
      *_pmatch_len = 2;
      tem = gen_peephole2_519 (insn, operands);
      if (tem != 0)
        return tem;
    }
  goto L4230;

 L4231: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 0);
  if (register_operand (x1, DImode))
    {
      operands[1] = x1;
      goto L4232;
    }
  goto ret0;

 L4232: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == DImode
      && GET_CODE (x1) == HIGH)
    goto L4233;
  goto ret0;

 L4233: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (general_symbolic_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L4234;
    }
  goto ret0;

 L4234: ATTRIBUTE_UNUSED_LABEL
  tem = peep2_next_insn (0);
  x1 = PATTERN (tem);
  if (
#line 3025 "/home/blakedonzac/cs161/cs161-gcc-1.5/./gcc-4.1.2+cs161/gcc/config/mips/mips.md"
(TARGET_EXPLICIT_RELOCS && ABI_HAS_64BIT_SYMBOLS))
    {
      *_pmatch_len = 0;
      tem = gen_peephole2_565 (insn, operands);
      if (tem != 0)
        return tem;
    }
  goto ret0;
 ret0:
  return 0;
}

