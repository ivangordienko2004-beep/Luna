#pragma once

#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <cassert>
#include <ctype.h>
#include <string.h>
#include "lib_basic.h"

struct Particle
{
    real x, y, z;
    real u, v, w;

    Particle() {}
    Particle(real x, real y, real z);
    Particle(real x, real y, real z,real u,real v,real w);
};

struct Properties
{
    double cCPX, cCPY, cCPZ; // mass center
    double cPPX, cPPY, cPPZ; // momentum
    double cMPX, cMPY, cMPZ; // angular momentum
    double cEPP;           // potential energy
    double cEPS;           // potential energy from sun
    double cEPK;           // kinetic energy
    double cM;             // particles mass
};

// Random numbers generator: Uniform distribution in [0.0, 1.0)
class g05cae
{
    int ix, iy, iz;

public:
    g05cae();

    g05cae(int seed);

    void reset(int seed=0);

    double get();
};

// Random numbers generator: Gauss distribution (mean, dispersion)
class g05dde
{
    double store1;

    static const double d[41];
    static constexpr double half=0.5, one=1.0;

    g05cae cae;

  public:
    g05dde();

    void reset(int seed=0);

    double get(double a, double b);
};