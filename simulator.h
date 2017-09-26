/* simulator.h */

#ifndef SIMULATOR_H
#define SIMULATOR_H

typedef int (simproc)(int, int, int);

simproc neg, _not, pop, nlz, rev, revb, add, sub, rsb, mul, _div, _divu,
        _mod, _modu, _and, _or, _xor, _bic, rotl, rotr, shl, shr, shrs,
        cmpeq, cmplt, cmpltu, seleq, sellt, selle;

#endif /* SIMULATOR_H */

