/**
***  Copyright (c) 1995, 1996, 1997, 1998, 1999, 2000 by
***  The Board of Trustees of the University of Illinois.
***  All rights reserved.
**/

/*
    Defines a new stream: iout, for "i"nforming consoles.
*/

#ifndef INFOSTREAM_H
#define INFOSTREAM_H

#include <iostream.h>

#if !defined(WIN32) || defined(__CYGWIN__)
#include <strstream.h>
#else
#include <strstrea.h>
#endif
class Vector;
class Tensor;

class infostream : public ostrstream
{
  private:
  char iBuffer[16384];

  public:
  infostream();
  ~infostream();
  void endi();

  /* define how to use the remaining << args */
  /** infostream<<ostream (hot to handle inherited modifiers) **/
  infostream& operator<<(ostream& (*f)(ostream&));
  /** infostream<<infostream (how to handle class modifiers) **/
  infostream& operator<<(infostream& (*f)(infostream&));

  #define LOCALMOD(type) infostream& operator<<(type x)
  /** << characters **/
  LOCALMOD(char);
  LOCALMOD(unsigned char);
  LOCALMOD(const char *);
  /** << integers **/
  LOCALMOD(int);
  LOCALMOD(long);
  LOCALMOD(short);
  LOCALMOD(unsigned int);
  LOCALMOD(unsigned long);
  LOCALMOD(unsigned short);
  /** << floats **/
  LOCALMOD(float);
  LOCALMOD(double);
  /** << pointers **/
  LOCALMOD(void *);
  LOCALMOD(streambuf *);
  #undef LOCALMOD
};

ostream& operator<<(ostream& strm, const Vector &v1);
infostream& operator<<(infostream& strm, const Vector &v1);

ostream& operator<<(ostream& strm, const Tensor &t1);
infostream& operator<<(infostream& strm, const Tensor &t1);

/** modifiers **/
infostream& endi(infostream& s);

/** common messages **/
/** iINFO, iWARN, iERROR, iDEBUG provide initial headings. **/
/** iINFOF, iWARNF, iERRORF, iDEBUGF provide initial headings with file name
    and line numbers. **/
ostream& iINFO (ostream& s);
ostream& iWARN (ostream& s);
ostream& iERROR(ostream& s);
ostream& iDEBUG(ostream& s);
ostream& iPE(ostream& s);  // outlined because of CkMyPe()

#define iFILE __FILE__<<'('<<__LINE__<<"): "
#define iINFOF  iINFO << iFILE
#define iWARNF  iWARN << iFILE
#define iERRORF  iERROR << iFILE
#define iDEBUGF  iDEBUG << iFILE

extern infostream iout;

#endif /* INFOSTREAM_H */

