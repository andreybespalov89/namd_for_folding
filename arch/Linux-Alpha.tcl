
TCLDIR=/Projects/namd2/tcl/alphalinux
TCLINCL=-I$(TCLDIR)/include
TCLLIB=-L$(TCLDIR)/lib -ltcl8.3 -ldl
TCLFLAGS=-DNAMD_TCL -DUSE_NON_CONST
TCL=$(TCLINCL) $(TCLFLAGS)

