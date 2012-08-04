
#ifndef COMPUTEMSM_H
#define COMPUTEMSM_H

#include "Lattice.h"
#include "ComputeMsmMgr.decl.h"
#include "ComputeHomePatches.h"
#include "NamdTypes.h"


class ComputeMsmMgr;
class SubmitReduction;

class MsmInitMsg : public CMessage_MsmInitMsg {
  public:
    ScaledPosition smin, smax;  // needs the extreme positions
};


class ComputeMsm : public ComputeHomePatches {
public:
  ComputeMsm(ComputeID c);
  virtual ~ComputeMsm();
  void doWork();
  void saveResults();

  void setMgr(ComputeMsmMgr *mgr) { myMgr = mgr; }

private:
  BigReal qscaling;  // charge scaling constant
  SubmitReduction *reduction;

  ComputeMsmMgr *myMgr;  // points to the local MSM manager
};


#endif // COMPUTEMSM_H

