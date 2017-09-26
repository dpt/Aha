// Copyright (C) 2002 by Henry S. Warren, Jr.

#include "config.h"
#include "simulator.h"

#ifndef NARGS
#define NARGS 1                 // Number of args in userfun, 1, 2 or 3.
#endif

const int debug = 0;            // 0 or 1; debugging printouts if 1.
const int counters = 1;         // 0 or 1; count number of evaluations.

/* A note about the registers:

They are divided into four groups.  The first group, starting with
register 0, holds ordinary immediate values.  The second group, starting
with register NIM, holds the shift immediate values.  The next 1 or 2
regs are the arguments to the user-defined function.  The last group
holds the results of computations done by the trial programs.

0        Start of ordinary immediate values (those given by IMMEDS)
NIM      Start of shift immediate values    (those given by SHIMMEDS)
RX       First (or only) user function argument
RY       Second user function argument
RZ       Third user function argument
RI0      Result of instruction 0 goes here
RI0 + i  Result of instruction i goes here
where:
NIM   = number of ordinary immediate values
NSHIM = number of shift immediate values
*/

static const int trialx[] = TRIAL;
#if NARGS >= 2
static const int trialy[] = TRIAL;
#endif
#if NARGS >= 3
static const int trialz[] = TRIAL;
#endif

int dummy1[] = {IMMEDS};        // These get optimized out of existence.
int dummy2[] = {SHIMMEDS};

#define NELEMS(a) (int)(sizeof(a)/sizeof(a[0]))
#define NIM NELEMS(dummy1)
#define NSHIM NELEMS(dummy2)
#define RX (NIM + NSHIM)        // First (or only) user function argument
#define RY (RX + 1)             // Second user function argument
#define RZ (RY + 1)             // Third user function argument
#define RI0 (RX + NARGS)        // Result of instruction 0 goes here

int unacceptable;               // Code below sets this to 1 for an
                                // unacceptable operation, such as
                                // divide by 0.  It is initially 0.

// Note: Commutative ops are commutative in operands 0 and 1.
typedef struct isa_t
{
   simproc *proc;                // Procedure for simulating the op.
   int  numopnds;               // Number of operands, 1 to 3.
   int  commutative;            // 1 if opnds 0 and 1 commutative.
   int  opndstart[3];           // Starting reg no. for each operand.
   const char *mnemonic;              // Name of op, for printing.
   const char *fun_name;              // Function name, for printing.
   const char *op_name;               // Operator name, for printing.
}
isa_t;

#include "machine.h"

/* ------------------- End of user-setup Portion -------------------- */

#define MAXNUMI 5               // Max num of insns that can be tried.
#if NARGS == 1
int userfun(int);
#elif NARGS == 2
int userfun(int, int);
#elif NARGS == 3
int userfun(int, int, int);
#else
#error Invalid NARGS
#endif

#define NTRIALX NELEMS(trialx)
#define NTRIALY NELEMS(trialy)
#define NTRIALZ NELEMS(trialz)

#if NARGS == 1
   int correct_result[NTRIALX];
#elif NARGS == 2
   int correct_result[NTRIALX][NTRIALY];
#elif NARGS == 3
   int correct_result[NTRIALX][NTRIALY][NTRIALZ];
#endif

int corr_result;                // Correct result for current trial.

#define NUM_INSNS_IN_ISA NELEMS(isa)

struct {                        // The current program.
   int op;                      // Index into isa.
   int opnd[3];                 // Operands of op.  Register numbers
                                // except if negative, it's the negative
                                // of a shift amount.
} pgm[MAXNUMI];

int numi;                       // Current size of the trial programs,
                                // must be from 1 to MAXNUMI.

/* GPR array:  First NIM slots hold ordinary immediate values (IMMEDS),
next NSHIM slots hold shift immediate values (SHIMMEDS), next NARGS
slots hold the arguments x and, optionally, y, and the last numi slots
hold the result of instructions 0 through numi - 1. */

int r[NIM + NSHIM + NARGS + MAXNUMI] = {IMMEDS, SHIMMEDS};
unsigned long long counter[MAXNUMI];    // Count num times insn at level i is evaluated.
