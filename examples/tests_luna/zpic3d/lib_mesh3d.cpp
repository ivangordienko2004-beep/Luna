#include <cstdio>
#include <string.h>
#include <math.h>
#include "ucenv.h"

#include "lib_mesh3d_codes.h"

extern "C"
{
    void c_get_fragment_parameters(int n, int nf, int nb, int ni, OutputDF &df_nfs, OutputDF &df_nf0)
    {
        int ns=n/nf;
        int nr=n%nf;
        int size_in,first_in;
        if (ni<nr) {
            size_in=ns+1;
            first_in=ni*(ns+1);
        } else {
            size_in=ns;
            first_in=ni*ns+nr;
        }
        int size_out=size_in+nb*2;
        int first_out=first_in-nb;
        df_nfs.setValue(size_out);
        df_nf0.setValue(first_out);
    }

    void c_real3d_select_xy(int nx, int ny, int nz, int sx, int sy, int sz, int nb, const InputDF &df_u, int lg, OutputDF &df_uxy)
    {
        assert(df_u.getSize()==nx*ny*nz*sizeof(real));
        const real *u=df_u.getData<real>();
        real *uxy=df_uxy.create<real>(nx*ny);
        real3d_select_xy(nx, ny, nz, sx, sy, sz, nb, u, lg, uxy);
    }

    void c_real3d_select_xz(int nx, int ny, int nz, int sx, int sy, int sz, int nb, const InputDF &df_u, int kg, OutputDF &df_uxz)
    {
        assert(df_u.getSize()==nx*ny*nz*sizeof(real));
        const real *u=df_u.getData<real>();
        real *uxz=df_uxz.create<real>(nx*nz);
        real3d_select_xz(nx, ny, nz, sx, sy, sz, nb, u, kg, uxz);
    }

    void c_real3d_select_yz(int nx, int ny, int nz, int sx, int sy, int sz, int nb, const InputDF &df_u, int ig, OutputDF &df_uyz)
    {
        assert(df_u.getSize()==nx*ny*nz*sizeof(real));
        const real *u=df_u.getData<real>();
        real *uyz=df_uyz.create<real>(ny*nz);
        real3d_select_yz(nx, ny, nz, sx, sy, sz, nb, u, ig, uyz);
    }

    void c_real3d_sum_xy(int nx, int ny, int nz, int nb, const InputDF &df_u3d, OutputDF &df_u2d)
    {
        assert(df_u3d.getSize()==nx*ny*nz*sizeof(real));
        const real *u3d=df_u3d.getData<real>();
        real *u2d=df_u2d.create<real>(nx*ny);
        real3d_sum_xy(nx, ny, nz, nb, u3d, u2d);
    }

    void c_real3d_sum_xz(int nx, int ny, int nz, int nb, const InputDF &df_u3d, OutputDF &df_u2d)
    {
        assert(df_u3d.getSize()==nx*ny*nz*sizeof(real));
        const real *u3d=df_u3d.getData<real>();
        real *u2d=df_u2d.create<real>(nx*nz);
        real3d_sum_xz(nx, ny, nz, nb, u3d, u2d);
    }

    void c_real3d_sum_yz(int nx, int ny, int nz, int nb, const InputDF &df_u3d, OutputDF &df_u2d)
    {
        assert(df_u3d.getSize()==nx*ny*nz*sizeof(real));
        const real *u3d=df_u3d.getData<real>();
        real *u2d=df_u2d.create<real>(ny*nz);
        real3d_sum_yz(nx, ny, nz, nb, u3d, u2d);
    }

    void c_real3d_delta_abs_reduce_max(int nx, int ny, int nz, int nb, const InputDF &df_u, const InputDF &df_v, OutputDF &df_result)
    {
        assert(df_u.getSize()==nx*ny*nz*sizeof(real));
        assert(df_v.getSize()==nx*ny*nz*sizeof(real));
        assert(nb>=0);
        const real *u3d=df_u.getData<real>();
        const real *v3d=df_v.getData<real>();
        real result;
        real3d_delta_abs_reduce_max(nx, ny, nz, nb, u3d, v3d, &result);
        df_result.setValue(result);
    }
}