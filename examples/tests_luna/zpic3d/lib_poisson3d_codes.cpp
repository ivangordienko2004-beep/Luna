#include <math.h>
#include <string.h>
#include <cstdio>

#include "lib_poisson3d_codes.h"

void poisson3d_step_implicit(int nx, int ny, int nz, real hx, real hy, real hz, real wp, real crhs, const real *ro1d, const real *fiold1d, real *fi1d, real *delta)
{
    memcpy(fi1d,fiold1d,nx*ny*nz*sizeof(real));
    real (*fiold)[nx][ny][nz]=(real (*)[nx][ny][nz])fiold1d;
    real (*ro)[nx][ny][nz]=(real (*)[nx][ny][nz])ro1d;
    real (*fi)[nx][ny][nz]=(real (*)[nx][ny][nz])fi1d;
    int i, k, l;
    const real rhx2=1.0/(hx*hx),
               rhy2=1.0/(hy*hy),
               rhz2=1.0/(hz*hz),
               a=0.5*wp/(rhx2+rhy2+rhz2);

    real dmax = 0.0;

    for (i=1; i<nx-1; i++) {
        for (k=1; k<ny-1; k++) {
            for (l=1; l<nz-1; l++) {
                real s=a*(((*fi)[i-1][k][l]+(*fi)[i+1][k][l])*rhx2
                            +((*fi)[i][k-1][l]+(*fi)[i][k+1][l])*rhy2
                            +((*fi)[i][k][l-1]+(*fi)[i][k][l+1])*rhz2
                            -(*ro)[i][k][l]*crhs
                            )+(1.0-wp)*(*fi)[i][k][l];
                real ds=fabs((*fi)[i][k][l]-s);

                if (ds > dmax) {
                    dmax=ds;
                }

                (*fi)[i][k][l]=s;
            }
        }
    }

    *delta=dmax;
}

void poisson3d_step_explicit(int nfx, int nfy, int nfz, int ifx, int ify, int ifz, int nx, int ny, int nz, real hx, real hy, real hz, real wp, real crhs, const real *ro1d, const real *fi1d, real *finew1d, real *delta)
{
    real (*fi)[nx][ny][nz]=(real (*)[nx][ny][nz])fi1d;
    real (*ro)[nx][ny][nz]=(real (*)[nx][ny][nz])ro1d;
    real (*finew)[nx][ny][nz]=(real (*)[nx][ny][nz])finew1d;
    int i, k, l;
    const real rhx2=1.0/(hx*hx),
               rhy2=1.0/(hy*hy),
               rhz2=1.0/(hz*hz),
               a=0.5*wp/(rhx2+rhy2+rhz2);
    real dmax=0.0;

    for (i=1; i<nx-1; i++) {
        for (k=1; k<ny-1; k++) {
            for (l=1; l<nz-1; l++) {
                real s=a*(((*fi)[i-1][k][l]+(*fi)[i+1][k][l])*rhx2
                            +((*fi)[i][k-1][l]+(*fi)[i][k+1][l])*rhy2
                            +((*fi)[i][k][l-1]+(*fi)[i][k][l+1])*rhz2
                            -(*ro)[i][k][l]*crhs
                            )+(1.0-wp)*(*fi)[i][k][l];
                real ds=fabs((*fi)[i][k][l]-s);

                if (ds > dmax) {
                    dmax=ds;
                }

                (*finew)[i][k][l]=s;
            }
        }
    }

    *delta=dmax;

    // copy border values to new fragment
    if (ifx==0) {
        for (k=0; k<ny; k++) {
            for (l=0; l<nz; l++) {
                (*finew)[0][k][l]=(*fi)[0][k][l];
            }
        }
    }

    if (ifx==nfx-1) {
        for (k=0; k<ny; k++) {
            for (l=0; l<nz; l++) {
                (*finew)[nx-1][k][l]=(*fi)[nx-1][k][l];
            }
        }
    }

    if (ify==0) {
        for (i=0; i<nx; i++) {
            for (l=0; l<nz; l++) {
                (*finew)[i][0][l]=(*fi)[i][0][l];
            }
        }
    }

    if (ify==nfy-1) {
        for (i=0; i<nx; i++) {
            for (l=0; l<nz; l++) {
                (*finew)[i][ny-1][l]=(*fi)[i][ny-1][l];
            }
        }
    }

    if (ifz==0) {
        for (i=0; i<nx; i++) {
            for (k=0; k<ny; k++) {
                (*finew)[i][k][0]=(*fi)[i][k][0];
            }
        }
    }

    if (ifz==nfz-1) {
        for (i=0; i<nx; i++) {
            for (k=0; k<ny; k++) {
                (*finew)[i][k][nz-1]=(*fi)[i][k][nz-1];
            }
        }
    }
}