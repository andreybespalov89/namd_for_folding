
TCLDIR=$(HOME)/tcl
TCLINCL=-I$(TCLDIR)/include
TCLLIB=-L$(TCLDIR)/lib -ltcl8.3
TCLFLAGS=-DNAMD_TCL -DUSE_NON_CONST
TCL=$(TCLINCL) $(TCLFLAGS)

