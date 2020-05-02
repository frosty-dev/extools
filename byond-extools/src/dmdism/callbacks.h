#pragma once

#include <map>
#include <typeindex>

#include "opcodes.h"

#include "instr_basics.h"
#include "instr_builtins.h"
#include "instr_control_flow.h"
#include "instr_text.h"
#include "instr_math.h"
#include "instr_input.h"
#include "instr_icon.h"
#include "instr_matrix.h"
#include "instr_debug.h"

#ifndef _WIN32
#define __forceinline
#endif

#define ADD_CALLBACK(op) case op: return new Instr_##op(op);

__forceinline Instruction* get_instr(std::uint32_t op) {
	switch (op)
	{
		ADD_CALLBACK(END)
		ADD_CALLBACK(NEW)
		ADD_CALLBACK(FORMAT)
		ADD_CALLBACK(OUTPUT)
		ADD_CALLBACK(OUTPUT_FORMAT)
		ADD_CALLBACK(TEST)
		ADD_CALLBACK(NOT)
		ADD_CALLBACK(JMP)
		ADD_CALLBACK(JZ)
		ADD_CALLBACK(RET)
		ADD_CALLBACK(NEWLIST)
		ADD_CALLBACK(SLEEP)
		ADD_CALLBACK(SPAWN)
		ADD_CALLBACK(CALL)
		ADD_CALLBACK(CALLNR)
		ADD_CALLBACK(CALLPATH)
		ADD_CALLBACK(CALLPARENT)
		ADD_CALLBACK(CALLGLOB)
		ADD_CALLBACK(GETVAR)
		ADD_CALLBACK(SETVAR)
		ADD_CALLBACK(GETFLAG)
		ADD_CALLBACK(TEQ)
		ADD_CALLBACK(TNE)
		ADD_CALLBACK(TL)
		ADD_CALLBACK(TG)
		ADD_CALLBACK(TLE)
		ADD_CALLBACK(TGE)
		ADD_CALLBACK(ANEG)
		ADD_CALLBACK(ADD)
		ADD_CALLBACK(SUB)
		ADD_CALLBACK(MUL)
		ADD_CALLBACK(DIV)
		ADD_CALLBACK(MOD)
		ADD_CALLBACK(ROUND)
		ADD_CALLBACK(ROUNDN)
		ADD_CALLBACK(AUGADD)
		ADD_CALLBACK(AUGSUB)
		ADD_CALLBACK(AUGMUL)
		ADD_CALLBACK(AUGDIV)
		ADD_CALLBACK(AUGMOD)
		ADD_CALLBACK(AUGAND)
		ADD_CALLBACK(AUGOR)
		ADD_CALLBACK(AUGXOR)
		ADD_CALLBACK(AUGLSHIFT)
		ADD_CALLBACK(AUGRSHIFT)
		ADD_CALLBACK(PUSHI)
		ADD_CALLBACK(POP)
		ADD_CALLBACK(ITERLOAD)
		ADD_CALLBACK(ITERNEXT)
		ADD_CALLBACK(LOCATE_POS)
		ADD_CALLBACK(LOCATE_REF)
		ADD_CALLBACK(PUSHVAL)
		ADD_CALLBACK(INC)
		ADD_CALLBACK(DEC)
		ADD_CALLBACK(SQRT)
		ADD_CALLBACK(POW)
		ADD_CALLBACK(FINDTEXT)
		ADD_CALLBACK(LISTGET)
		ADD_CALLBACK(LISTSET)
		ADD_CALLBACK(ISTYPE)
		ADD_CALLBACK(DBG_FILE)
		ADD_CALLBACK(DBG_LINENO)
		ADD_CALLBACK(ISNULL)
		ADD_CALLBACK(ISINLIST)
		ADD_CALLBACK(CALLNAME)
		ADD_CALLBACK(PROMPTCHECK)
		ADD_CALLBACK(INPUT_)
		ADD_CALLBACK(CALL_GLOBAL_ARGLIST)
		ADD_CALLBACK(ICON_NEW)
		ADD_CALLBACK(JMP2)
		ADD_CALLBACK(JNZ)
		ADD_CALLBACK(JNZ2)
		ADD_CALLBACK(JZ2)
		ADD_CALLBACK(POPN)
		ADD_CALLBACK(CHECKNUM)
		ADD_CALLBACK(FOR_RANGE)
		ADD_CALLBACK(MD5)
		ADD_CALLBACK(CALL_LIB)
		ADD_CALLBACK(CALL_LIB_ARGLIST)
		ADD_CALLBACK(ICON_BLEND)
		ADD_CALLBACK(MATRIX_NEW)
		ADD_CALLBACK(REPLACETEXT)
		ADD_CALLBACK(REGEX_NEW)
		ADD_CALLBACK(FEXISTS)
		ADD_CALLBACK(COPYTEXT)
		ADD_CALLBACK(ABS)
		ADD_CALLBACK(FCOPY_RSC)
		ADD_CALLBACK(ICON_STATES_MODE)
		ADD_CALLBACK(CRASH)
		ADD_CALLBACK(ISNUM)
		ADD_CALLBACK(JMP_OR)
		ADD_CALLBACK(JMP_AND)
		ADD_CALLBACK(PROB)
		ADD_CALLBACK(RAND)
		ADD_CALLBACK(RAND_RANGE)
		ADD_CALLBACK(BLOCK)
		ADD_CALLBACK(STAT)
		ADD_CALLBACK(LOG)
		ADD_CALLBACK(LOG10)
		ADD_CALLBACK(SIN)
		ADD_CALLBACK(COS)
		ADD_CALLBACK(MIN)
		ADD_CALLBACK(MAX)
		ADD_CALLBACK(MIN_LIST)
		ADD_CALLBACK(MAX_LIST)
		ADD_CALLBACK(LOCATE_TYPE)
		ADD_CALLBACK(BINARY_AND)
		ADD_CALLBACK(BINARY_OR)
		ADD_CALLBACK(BINARY_XOR)
		ADD_CALLBACK(BITWISE_NOT)
		ADD_CALLBACK(LSHIFT)
		ADD_CALLBACK(RSHIFT)
		ADD_CALLBACK(LENGTH)
		ADD_CALLBACK(PICK)
		ADD_CALLBACK(ISPATH)
		ADD_CALLBACK(ISSUBPATH)
		ADD_CALLBACK(TYPESOF)
		ADD_CALLBACK(NEW_IMAGE)
		ADD_CALLBACK(PRE_INC)
		ADD_CALLBACK(POST_INC)
		ADD_CALLBACK(PRE_DEC)
		ADD_CALLBACK(POST_DEC)
		ADD_CALLBACK(LPUSH_CACHE)
		ADD_CALLBACK(SET_CACHE)
		ADD_CALLBACK(SWITCH)
		ADD_CALLBACK(GET_STEP)
		ADD_CALLBACK(ISLOC)
		ADD_CALLBACK(ISMOB)
		ADD_CALLBACK(ISAREA)
		ADD_CALLBACK(ISTURF)
		ADD_CALLBACK(ISOBJ)
		ADD_CALLBACK(ISTEXT)
		ADD_CALLBACK(CKEY)
		ADD_CALLBACK(BROWSE_RSC)
	}
	return new Instr_UNK;
}

#undef ADD_CALLBACK