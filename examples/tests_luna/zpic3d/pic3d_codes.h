#pragma once

#include "pic3d_utils.h"

extern "C"
{
// transformation of local cell number to global
    int il2g(int i, int sx);// { return i+sx; }
    int kl2g(int k, int sy);// { return k+sy; }
    int ll2g(int l, int sz);// { return l+sz; }

// transformation of global cell number to local
    int ig2l(int i, int sx);// { return i-sx; }
    int kg2l(int k, int sy);// { return k-sy; }
    int lg2l(int l, int sz);// { return l-sz; }

// transformation of local cell number to coordinates of cell center
    real il2xc(int i, int sx, int hx);// { return (il2g(i,sx)+0.5)*hx; }
    real kl2yc(int k, int sy, int hy);// { return (kl2g(k,sy)+0.5)*hy; }
    real ll2zc(int l, int sz, int hz);// { return (ll2g(l,sz)+0.5)*hz; }
/*
* nfx,nfy,nfz : int : in : fragments grid sizes
* ifx,ify,ifz : int : in : current fragment number
* nx,ny,nz    : int : in : sizes of current fragment
* sx,sy,sz    : int : in : position of the element [0][0][0] of current fragment in global mesh
* hx,hy,hz    : real : in : mesh steps
* u1d         : real[nx][ny][nz] : out : array to be set
*/
    void init_array3d(int nx, int ny, int nz, int sx, int sy, int sz, real hx, real hy, real hz, real *u1d);
/*
* nfx,nfy,nfz : int : in : fragments grid sizes
* ifx,ify,ifz : int : in : current fragment number
* nx,ny,nz    : int : in : sizes of current fragment
* sx,sy,sz    : int : in : position of the element [0][0][0] of current fragment in global mesh
* hx,hy,hz    : real : in : mesh steps
* fi1d        : real[nx][ny][nz] : inout : fragment of 3D array to be set (gravitational potential)
*/
    void poisson_init(int nx, int ny, int nz, int sx, int sy, int sz, real hx, real hy, real hz, real *fi1d);
/*
* nfx,nfy,nfz : int : in : fragments grid sizes
* ifx,ify,ifz : int : in : current fragment number
* nx,ny,nz    : int : in : sizes of current fragment
* sx,sy,sz    : int : in : position of the element [0][0][0] of current fragment in global mesh
* hx,hy,hz    : real : in : mesh steps
* fi1d        : real[nx][ny][nz] : inout : fragment of 3D array to be set (gravitational potential)
*/
    void poisson_edge_function(int nfx, int nfy, int nfz, int ifx, int ify, int ifz, int nx, int ny, int nz, int sx, int sy, int sz, real hx, real hy, real hz, real *fi1d);
/*
* nfx,nfy,nfz : int : in : fragments grid sizes
* ifx,ify,ifz : int : in : current fragment number
* nx,ny,nz    : int : in : sizes of current fragment
* sx,sy,sz    : int : in : position of the element [0][0][0] of current fragment in global mesh
* hx,hy,hz    : real : in : mesh steps
* cx,cy,cz    : real : in : cordinates of domain centre
* pm          : real : in : particles mass
* fi1d        : real[nx][ny][nz] : inout : fragment of 3D array to be set (gravitational potential)
*/
    void poisson_edge_simple(int nfx, int nfy, int nfz, int ifx, int ify, int ifz, int nx, int ny, int nz, int sx, int sy, int sz, real hx, real hy, real hz, real cx, real cy, real cz, real mass, real *fi1d);
    void poisson_step_zeidel(int nx, int ny, int nz, real hx, real hy, real hz, real wp, const real *ro1d, const real *fiold1d, real *fi1d, real *delta);
    void poisson_step_jakobi(int nfx, int nfy, int nfz, int ifx, int ify, int ifz, int nx, int ny, int nz, real hx, real hy, real hz, real wp, const real *ro1d, const real *fi1d, real *finew1d, real *delta);

    void select3d_xy(int nx, int ny, int nz, int sx, int sy, int sz, const real *u1d, int lg, real *uxy1d);
    void select3d_xz(int nx, int ny, int nz, int sx, int sy, int sz, const real *u1d, int kg, real *uxz1d);
    void select3d_yz(int nx, int ny, int nz, int sx, int sy, int sz, const real *u1d, int ig, real *uyz1d);

    void print_x(int ifx, int nx, int sx, real hx);
    void print_y(int ify, int ny, int sy, real hy);
    void print_z(int ifz, int nz, int sz, real hz);
/*
* nx,ny,nz    : int : in : sizes of current fragment
* sx,sy,sz    : int : in : position of the element [0][0][0] of current fragment in global mesh
* hx,hy,hz    : real : in : mesh steps
* am          : real : in : single pacticle mass
* p           : Particle[np] : in : particles
* np          : size_t : in : number of particles
* ro1d        : real[nx][ny][nz] : out : fragment of 3D array to be set (particles density distribution)
*/
    void density(int nx, int ny, int nz, int sx, int sy, int sz, real hx, real hy, real hz, real am, const Particle *p, size_t np, real *ro1d);
/*
* nx,ny,nz       : int : in : sizes of current fragment
* hx,hy,hz       : real : in : mesh steps
* ro1d           : real[nx][ny][nz] : in : fragment of 3D array (gravitational potential)
* fx1d,fy1d,fz1d : real[nx][ny][nz] : out : fragment of 3D array (gravitational forces)
*/
    void force(int nx, int ny, int nz, real hx, real hy, real hz, const real *fi1d, real *fx1d, real *fy1d, real *fz1d);
/*
* x,y,z          : real : in : article coordinates
* nx,ny,nz       : int : in : sizes of current fragment
* sx,sy,sz       : int : in : position of the element [0][0][0] of current fragment in global mesh
* hx,hy,hz       : real : in : mesh steps
* fx1d,fy1d,fz1d : real[nx][ny][nz] : in : fragment of 3D array (gravitational forces)
* rfx,rfy,rfz    : real : out : particle forces
*/
    void particle_force(real x, real y, real z, int nx, int ny, int nz, int sx, int sy, int sz, real hx, real hy, real hz, const real *fx1d, const real *fy1d, const real *fz1d, real *rfx, real *rfy, real *rfz);
/*
* x,y,z    : real : in : article coordinates
* nx,ny,nz : int : in : sizes of current fragment
* sx,sy,sz : int : in : position of the element [0][0][0] of current fragment in global mesh
* hx,hy,hz : real : in : mesh steps
* fi1d     : real[nx][ny][nz] : out : fragment of 3D array (gravitational potential)
* s        : real : out : particle potential
*/
    void particle_potential(real x, real y, real z, int nx, int ny, int nz, int sx, int sy, int sz, real hx, real hy, real hz, const real *fi1d, real *s);
/*
* nx,ny,nz       : int : in : sizes of current fragment
* sx,sy,sz       : int : in : position of the element [0][0][0] of current fragment in global mesh
* hx,hy,hz       : real : in : mesh steps
* fx1d,fy1d,fz1d : real[nx][ny][nz] : in : fragment of 3D array (gravitational forces)
* tau            : real : in : time step
* np             : size_t : in : number of particles
* p              : Particle[np] : inout : particles
*/
    void move_particles(int nx, int ny, int nz, int sx, int sy, int sz, real hx, real hy, real hz,
                const real *fx1d, const real *fy1d, const real *fz1d, real tau, size_t np, Particle *p);
/*
* nx,ny,nz : int : in : sizes of current fragment
* sx,sy,sz : int : in : position of the element [0][0][0] of current fragment in global mesh
* hx,hy,hz : real : in : mesh steps
* cx,cy,cz : real : in : cordinates of domain centre
* sm       : real : in : central (sun) mass
* fi       : real[nx][ny][nz] : in : fragment of 3D array (gravitational potential)
* np       : size_t : in : number of particles
* p        : Particle[np] : in : particles
* prop     : real[13] : out : whole system integral properties (not ready)
*/
    void get_properties(int nx, int ny, int nz, int sx, int sy ,int sz, real hx, real hy, real hz,
                real cx, real cy, real cz, real sm, const real *fi, int np, const Particle *p, real *prop);
/*
* am       : real : in : single particle mass
* pm       : real : in : total particles mass
* prop0    : real[13] : in : whole system integral properties (not ready)
* prop     : Properties : out : whole system integral properties (ready)
*/
    void get_properties_finish(real am, real pm, const real *prop0, Properties *prop);
    void print_properties(const char *filename, const Properties *prop, int it, real cx, real cy, real cz);
/*
* nfx,nfy,nfz : int : in : fragments grid sizes
* ifx,ify,ifz : int : in : current fragment number
* nx,ny,nz    : int : in : sizes of current fragment
* sx,sy,sz    : int : in : position of the element [0][0][0] of current fragment in global mesh
* hx,hy,hz    : real : in : mesh steps
* cx,cy,cz    : real : in : cordinates of domain centre
* sm          : real : in : central (sun) mass
* fp1d        : real[nx][ny][nz] : in : gravitational potentialvfrom psrticles only
* fi1d        : real[nx][ny][nz] : out : gravitational potential with addition
*/
    void fi_dobavka(int nfx, int nfy, int nfz, int ifx, int ify, int ifz, int nx, int ny, int nz, int sx, int sy, int sz, real hx, real hy, real hz, real cx, real cy, real cz, real sm, const real *fp1d, real *fi1d);
}