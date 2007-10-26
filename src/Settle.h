/**
***  Copyright (c) 1995, 1996, 1997, 1998, 1999, 2000 by
***  The Board of Trustees of the University of Illinois.
***  All rights reserved.
**/

#ifndef SETTLE_H__
#define SETTLE_H__

#include "Vector.h"
#include "Tensor.h"

/*

Oxygen at a0, hydrogens at b0, c0, center of mass at the origin.

                   |
                   |
                   |
                a0 .-------
                   |   |
                   |   ra
                   |   | 
---------------------------------------
           |       |        |
           rb      |---rc---|
           |       |        |
    b0 .-----------|        c0 .
  
SETTLE for step one of velocity verlet.
ref: positions before unconstrained step
mass: masses
pos: on input: positions after unconstrained step; on output: the new 
               positions.
vel: on input: velocities after unconstrained step; on output: the new
               velocities.
ra, rb, rc: canonical positions of water atoms; see above diagram
*/

extern int settle1(const Vector *ref, BigReal mO, BigReal mH,
                  Vector *pos, Vector *vel, 
                  BigReal invdt, BigReal hhdist, BigReal ohdist);

extern int settle2(BigReal mO, BigReal mH, const Vector *pos,
                  Vector *vel, BigReal dt, Tensor *virial); 
#endif
