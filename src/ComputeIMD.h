
#ifndef COMPUTE_IMD_H__
#define COMPUTE_IMD_H__

#include "ComputeGlobalMaster.h"

class ComputeGlobalConfigMsg;
class ComputeGlobalResultsMsg;

class ComputeIMD : public ComputeGlobalMaster {
friend class ComputeGlobal;

private:
  ComputeIMD(ComputeGlobal *);
  ~ComputeIMD();

  virtual void initialize();
  virtual void calculate();

  ComputeGlobalConfigMsg *configMsg;
  ComputeGlobalResultsMsg *resultsMsg;

  // Simple function for getting MDComm-style forces from VMD
  int get_vmd_forces();

  // My socket handle
  void *sock;
};

#endif

