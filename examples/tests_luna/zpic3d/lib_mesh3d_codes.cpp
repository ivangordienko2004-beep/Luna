#include <cstdio>
#include <math.h>
#include "lib_mesh3d_codes.h"

extern "C"
{
// transformation of local cell number to global
    int il2g(int i, int sx)
    {
        return i+sx;
    }

    int kl2g(int k, int sy)
    {
        return k+sy;
    }

    int ll2g(int l, int sz)
    {
        return l+sz;
    }

// transformation of global cell number to local
    int ig2l(int i, int sx)
    {
        return i-sx;
    }

    int kg2l(int k, int sy)
    {
        return k-sy;
    }

    int lg2l(int l, int sz)
    {
        return l-sz;
    }

    void real3d_select_xy(int nx, int ny, int nz, int sx, int sy, int sz, int nb, const real *u1d, int lg, real *uxy1d)
    {
        real (*u)[nx][ny][nz]=(real (*)[nx][ny][nz])u1d;
        real (*uxy)[nx][ny]=(real (*)[nx][ny])uxy1d;

        if (lg>=ll2g(nb,sz) && lg<ll2g(nz-nb,sz)) {
            int l=lg2l(lg,sz);

            for (int i=0; i<nx; i++) {
                for (int k=0; k<ny; k++) {
                    (*uxy)[i][k]=(*u)[i][k][l];
                }
            }
        } else {
            printf("select3d_xy: Warning! trying to select %d from %d..%d\n", lg, ll2g(1, sz), ll2g(nz-1, sz));
            fflush(stdout);
        }
    }

    void real3d_select_xz(int nx, int ny, int nz, int sx, int sy, int sz, int nb, const real *u1d, int kg, real *uxz1d)
    {
        real (*u)[nx][ny][nz]=(real (*)[nx][ny][nz])u1d;
        real (*uxz)[nx][nz]=(real (*)[nx][nz])uxz1d;

        if (kg>=kl2g(nb,sy) && kg<kl2g(ny-nb,sy)) {
            int k=kg2l(kg,sy);

            for (int i=0; i<nx; i++) {
                for (int l=0; l<nz; l++) {
                    (*uxz)[i][l]=(*u)[i][k][l];
                }
            }
        } else {
            printf("select3d_xz: Warning! trying to select %d from %d..%d\n", kg, kl2g(1, sy), kl2g(ny-1, sy));
            fflush(stdout);
        }
    }

    void real3d_select_yz(int nx, int ny, int nz, int sx, int sy, int sz, int nb, const real *u1d, int ig, real *uyz1d)
    {
        real (*u)[nx][ny][nz]=(real (*)[nx][ny][nz])u1d;
        real (*uyz)[ny][nz]=(real (*)[ny][nz])uyz1d;
        if (ig>=il2g(nb,sx) && ig<il2g(nx-nb,sx)) {
            int i=ig2l(ig,sx);

            for (int k=0; k<ny; k++) {
                for (int l=0; l<nz; l++) {
                    (*uyz)[k][l]=(*u)[i][k][l];
                }
            }
        } else {
            printf("select3d_yz: Warning! trying to select %d from %d..%d\n", ig, il2g(1, sx), il2g(nx-1, sx));
            fflush(stdout);
        }
    }

    void real3d_sum_xy(int nx, int ny, int nz, int nb, const real *u3d, const real *u2d)
    {
        real (*u)[nx][ny][nz]=(real (*)[nx][ny][nz])u3d;
        real (*uxy)[nx][ny]=(real (*)[nx][ny])u2d;

        for (int i=0; i<nx; i++) {
            for (int k=0; k<ny; k++) {
                (*uxy)[i][k]=0.0;
            }
        }

        for (int i=nb; i<nx-nb; i++) {
            for (int k=nb; k<ny-nb; k++) {
                real s = 0.0;
                for (int l=nb; l<nz-nb; l++) {
                    s+=(*u)[i][k][l];
                }
            }
                (*uxy)[i][k]=s;
        }
    }

    void real3d_sum_xz(int nx, int ny, int nz, int nb, const real *u3d, const real *u2d)
    {
        real (*u)[nx][ny][nz]=(real (*)[nx][ny][nz])u3d;
        real (*uxz)[nx][nz]=(real (*)[nx][nz])u2d;

        for (int i=0; i<nx; i++) {
            for (int l=0; l<nz; l++) {
                (*uxz)[i][l]=0.0;
            }
        }

        for (int i=nb; i<nx-nb; i++) {
            for (int k=nb; k<ny-nb; k++) {
                for (int l=nb; l<nz-nb; l++) {
                    (*uxz)[i][l]+=(*u)[i][k][l];
                }
            }
        }
    }

    void real3d_sum_yz(int nx, int ny, int nz, int nb, const real *u3d, const real *u2d)
    {
        real (*u)[nx][ny][nz]=(real (*)[nx][ny][nz])u3d;
        real (*uyz)[ny][nz]=(real (*)[ny][nz])u2d;

        for (int  k=0; k<ny; k++) {
            for (int l=0; l<nz; l++) {
                (*uyz)[k][l]=0.0;
            }
        }

        for (int i=nb; i<nx-nb; i++) {
            for (int k=nb; k<ny-nb; k++) {
                for (int l=nb; l<nz-nb; l++) {
                    (*uyz)[k][l]+=(*u)[i][k][l];
                }
            }
        }
    }

    void real3d_delta_abs_reduce_max(int nx, int ny, int nz, int nb, const real *u3d, const real *v3d, real *result)
    {
        const real (*u)[nx][ny][nz]=(const real(*)[nx][ny][nz])u3d;
        const real (*v)[nx][ny][nz]=(const real(*)[nx][ny][nz])v3d;
        real delta=0.0;

        for (int i=nb; i<nx-nb; i++) {
            for (int k=nb; k<ny-nb; k++) {
                for (int l=nb; l<nz-nb; l++) {
                    real d=fabs((*u)[i][k][l]-(*v)[i][k][l]);
                    if (d>delta) {
                        delta=d;
                    }
                }
            }
        }
        *result=delta;
    }
}