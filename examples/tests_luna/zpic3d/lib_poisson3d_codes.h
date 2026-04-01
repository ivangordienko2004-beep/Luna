#pragma once

#include "lib_mesh3d_codes.h"

extern "C"
{
/*
* nx,ny,nz    : int : in : sizes of current fragment
* hx,hy,hz    : real : in : mesh steps
* wp          : real : acceleration parameter of the method
* ro1d        : real[nx][ny][nz] : in : fragment of right hand side (density)
* fiold1d     : real[nx][ny][nz] : in :  fragment of 3D array, function to be found (gravitational potential)
* fi1d        : real[nx][ny][nz] : out :  fragment of 3D array, function to be found (gravitational potential)
* delta       : real : out : maximum delta for the fragment
*/
    void poisson3d_step_implicit(int nx, int ny, int nz, real hx, real hy, real hz, real wp, real crhs, const real *ro1d, const real *fiold1d, real *fi1d, real *delta);
/*
* nx,ny,nz    : int : in : sizes of current fragment
* hx,hy,hz    : real : in : mesh steps
* wp          : real : acceleration parameter of the method
* ro1d        : real[nx][ny][nz] : in : fragment of right hand side (density)
* fi1d        : real[nx][ny][nz] : in :  fragment of 3D array, function to be found (gravitational potential)
* finew1d     : real[nx][ny][nz] : out :  fragment of 3D array, function to be found (gravitational potential)
* delta       : real : out : maximum delta for the fragment
*/
    void poisson3d_step_explicit(int nfx, int nfy, int nfz, int ifx, int ify, int ifz, int nx, int ny, int nz, real hx, real hy, real hz, real wp, real crhs, const real *ro1d, const real *fi1d, real *finew1d, real *delta);
}