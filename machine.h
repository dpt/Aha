/* machine.h */

#ifndef MACHINE_H
#define MACHINE_H

// The machine's instruction set:
static const isa_t isa[] = {
   {neg,    1, 0, {RX,  0,  0}, "neg",   "-(",   ""     },  // Negate.
// {_not,   1, 0, {RX,  0,  0}, "not",   "~(",   ""     },  // One's-complement.
// {pop,    1, 0, {RX,  0,  0}, "pop",   "pop(", ""     },  // Population count.
// {nlz,    1, 0, {RX,  0,  0}, "nlz",   "nlz(", ""     },  // Num leading 0's.
// {rev,    1, 0, {RX,  0,  0}, "rev",   "rev(", ""     },  // Bit reversal.
   {add,    2, 1, {RX,  2,  0}, "add",   "(",    " + "  },  // Add.
   {sub,    2, 0, { 2,  2,  0}, "sub",   "(",    " - "  },  // Subtract.
// {rsb,    2, 0, { 2,  2,  0}, "rsb",   "(",    " -r "  },  // Reverse subtract.
// {mul,    2, 1, {RX,  3,  0}, "mul",   "(",    " * "  },  // Multiply.
// {_div,   2, 0, { 1,  3,  0}, "div",   "(",    " / "  },  // Divide signed.
// {_divu,  2, 0, { 1,  1,  0}, "divu",  "(",    " /u " },  // Divide unsigned.
// {_mod,   2, 0, { 1,  3,  0}, "mod",   "(",    " % "  },  // Modulus signed.
// {_modu,  2, 0, { 1,  1,  0}, "modu",  "(",    " %u " },  // Modulus unsigned.
   {_and,   2, 1, {RX,  2,  0}, "and",   "(",    " & "  },  // AND.
   {_or,    2, 1, {RX,  2,  0}, "or",    "(",    " | "  },  // OR.
   {_xor,   2, 1, {RX,  2,  0}, "xor",   "(",    " ^ "  },  // XOR.
   {_bic,   2, 1, {RX,  2,  0}, "bic",   "(",    " & ~" },  // AND-NOT / bitwise clear.
// {rotl,   2, 0, { 1,NIM,  0}, "rotl",  "(",    " <<r "},  // Rotate shift left.
// {rotr,   2, 0, { 1,NIM,  0}, "rotr",  "(",    " >>r "},  // Rotate shift right.
   {shl,    2, 0, { 1,NIM,  0}, "shl",   "(",    " << " },  // Shift left.
   {shr,    2, 0, { 1,NIM,  0}, "shr",   "(",    " >>u "},  // Shift right.
   {shrs,   2, 0, { 3,NIM,  0}, "shrs",  "(",    " >>s "},  // Shift right signed.
// {cmpeq,  2, 1, {RX,  0,  0}, "cmpeq", "(",    " == " },  // Compare equal.
// {cmplt,  2, 0, { 0,  0,  0}, "cmplt", "(",    " < "  },  // Compare less than.
// {cmpltu, 2, 0, { 1,  1,  0}, "cmpltu","(",    " <u " },  // Compare less than unsigned.
// {seleq,  3, 0, {RX,  0,  0}, "seleq", "seleq(", ", " },  // Select if = 0.
// {sellt,  3, 0, {RX,  0,  0}, "sellt", "sellt(", ", " },  // Select if < 0.
// {selle,  3, 0, {RX,  0,  0}, "selle", "selle(", ", " },  // Select if <= 0.
    {revb,   1, 0, {RX,   0, 0}, "revb",   "revb(",  ""     }, // Byte reversal.
};

#endif /* MACHINE_H */

