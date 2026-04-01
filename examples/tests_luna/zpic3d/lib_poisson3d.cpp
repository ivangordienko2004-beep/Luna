#include <cstdio>
#include "ucenv.h"

#include "lib_poisson3d_codes.h"

extern "C"
{
    void c_poisson3d_step_implicit_subdomain(int nfx, int nfy, int nfz, int ifx, int ify, int ifz, int nx, int ny, int nz, real hx, real hy, real hz, real wp, real crhs, const InputDF &df_ro, const InputDF &df_fi, OutputDF &df_fi_new, OutputDF &df_delta)
    {
        assert(df_ro.getSize()==nx*ny*nz*sizeof(real));
        assert(df_fi.getSize()==nx*ny*nz*sizeof(real));
        const real *ro1d=df_ro.getData<real>();
        const real *fi1d=df_fi.getData<real>();
        real *finew1d=df_fi_new.create<real>(nx*ny*nz);
        real delta;
        poisson3d_step_implicit(nx, ny, nz, hx, hy, hz, wp, crhs, ro1d, fi1d, finew1d, &delta);
        df_delta.setValue(delta);
    }

    void c_poisson3d_step_explicit_subdomain(int nfx, int nfy, int nfz, int ifx, int ify, int ifz, int nx, int ny, int nz, real hx, real hy, real hz, real wp, real crhs, const InputDF &df_ro, const InputDF &df_fi, OutputDF &df_fi_new, OutputDF &df_delta)
    {
        assert(df_ro.getSize()==nx*ny*nz*sizeof(real));
        assert(df_fi.getSize()==nx*ny*nz*sizeof(real));
        const real *ro1d=df_ro.getData<real>();
        const real *fi1d=df_fi.getData<real>();
        real *finew1d=df_fi_new.create<real>(nx*ny*nz);
        real delta;
        poisson3d_step_explicit(nfx, nfy, nfz, ifx, ify, ifz, nx, ny, nz, hx, hy, hz, wp, crhs, ro1d, fi1d, finew1d, &delta);
        df_delta.setValue(delta);
    }
}