#pragma once

#include "lib_basic.h"

extern "C"
{
// transformation of local cell number to global
    int il2g(int i, int sx);
    int kl2g(int k, int sy);
    int ll2g(int l, int sz);

// transformation of global cell number to local
    int ig2l(int i, int sx);
    int kg2l(int k, int sy);
    int lg2l(int l, int sz);

/*
* nx,ny,nz    : int : in : sizes of current fragment
* sx,sy,sz    : int : in : position of the element [0][0][0] of current fragment in global mesh
* u1d         : real[nx][ny][nz] : in : fragment of 3D array
* lg          : global Z index of required XY layer
* uxy1d       : real[nx][ny] : out : resulting XY layer
*/
    void real3d_select_xy(int nx, int ny, int nz, int sx, int sy, int sz, int nb, const real *u1d, int lg, real *uxy1d);
/*
* nx,ny,nz    : int : in : sizes of current fragment
* sx,sy,sz    : int : in : position of the element [0][0][0] of current fragment in global mesh
* u1d         : real[nx][ny][nz] : in : fragment of 3D array
* kg          : global Y index of required XZ layer
* uxz1d       : real[nx][nz] : out : resulting XZ layer
*/
    void real3d_select_xz(int nx, int ny, int nz, int sx, int sy, int sz, int nb, const real *u1d, int kg, real *uxz1d);
/*
* nx,ny,nz    : int : in : sizes of current fragment
* sx,sy,sz    : int : in : position of the element [0][0][0] of current fragment in global mesh
* u1d         : real[nx][ny][nz] : in : fragment of 3D array
* ig          : global X index of required yz layer
* uyz1d       : real[ny][nz] : out : resulting yz layer
*/
    void real3d_select_yz(int nx, int ny, int nz, int sx, int sy, int sz, int nb, const real *u1d, int ig, real *uyz1d);

    void real3d_sum_xy(int nx, int ny, int nz, int nb, const real *u3d, const real *u2d);
    void real3d_sum_xz(int nx, int ny, int nz, int nb, const real *u3d, const real *u2d);
    void real3d_sum_yz(int nx, int ny, int nz, int nb, const real *u3d, const real *u2d);
    void real3d_delta_abs_reduce_max(int nx, int ny, int nz, int nb, const real *u3d, const real *v3d, real *result);
}