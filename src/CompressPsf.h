#ifndef COMPRESSPSF_H
#define COMPRESSPSF_H

#include "structures.h"
#include <string>
using namespace std;

class Molecule;
class Parameters;
class SimParameters;

void compress_psf_file(Molecule *mol, char *psfFileName, Parameters *param, SimParameters *simParam);

template <typename T>
int lookupCstPool(const vector<T>& pool, const T& val)
{
    for(int i=0; i<pool.size(); i++)
    {
        if(pool[i]==val)
            return i;
    }
    return -1;
}
#endif