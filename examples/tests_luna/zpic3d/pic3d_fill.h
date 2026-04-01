#pragma once

#include<vector>
#include"pic3d_utils.h"

extern "C"
{
/*
* n : int : in : total number of particles to generate
* kind : int : in : density distribution type
* radius : real : in : circle radius
* cx,cy,cz : real : in : circle center coordinates
* x1,y1,z1,x2,y2,z2 : int : in : subdomain coordinates
* p : vector<Particles> : out : particles generated for local subdomain
*/
    void fill_particles_circle_xy(size_t n, int kind, double radius, double cx, double cy, double cz, double x1, double y1, double z1, double x2, double y2, double z2, std::vector<Particle> &p);
/*
* n : int : in : total number of particles to generate
* kind : int : in : density distribution type
* radius : real : in : circle radius
* cx,cy,cz : real : in : circle center coordinates
* x1,y1,z1,x2,y2,z2 : int : in : subdomain coordinates
* p : vector<Particles> : out : particles generated for local subdomain
*/
    void fill_particles_circle_xz(size_t n, int kind, double radius, double cx, double cy, double cz, double x1, double y1, double z1, double x2, double y2, double z2, std::vector<Particle> &p);
/*
* n : int : in : total number of particles to generate
* kind : int : in : density distribution type
* radius : real : in : circle radius
* cx,cy,cz : real : in : circle center coordinates
* x1,y1,z1,x2,y2,z2 : int : in : subdomain coordinates
* p : vector<Particles> : out : particles generated for local subdomain
*/
    void fill_particles_circle_yz(size_t n, int kind, double radius, double cx, double cy, double cz, double x1, double y1, double z1, double x2, double y2, double z2, std::vector<Particle> &p);
/*
* n : int : in : total number of particles to generate
* kind : int : in : density distribution type
* radius : real : in : ball radius
* cx,cy,cz : real : in : ball center coordinates
* x1,y1,z1,x2,y2,z2 : int : in : subdomain coordinates
* p : vector<Particles> : out : particles generated for local subdomain
*/
    void fill_particles_ball(size_t n, int kind, double radius, double cx, double cy, double cz, double x1, double y1, double z1, double x2, double y2, double z2, std::vector<Particle> &p);
/*
* n : int : in : total number of particles to generate
* x1,y1,z1,x2,y2,z2 : int : in : subdomain coordinates
* p : vector<Particles> : out : particles generated for local subdomain
*/
    void fill_particles_full(size_t n, double x1, double y1, double z1, double x2, double y2, double z2, std::vector<Particle> &p);

    void particle_velocity_z(double x, double y, double z, double fx, double fy, double fz, double cx, double cy, double cz, double tau, double pfi, double dvr, double dvf, double dvz, double emax, int wave, double *u, double *v, double *w);
    void particle_velocity_y(double x, double y, double z, double fx, double fy, double fz, double cx, double cy, double cz, double tau, double pfi, double dvr, double dvf, double dvy, double emax, int wave, double *u, double *v, double *w);
    void particle_velocity_x(double x, double y, double z, double fx, double fy, double fz, double cx, double cy, double cz, double tau, double pfi, double dvr, double dvf, double dvx, double emax, int wave, double *u, double *v, double *w);

/*
* nx,ny,nz       : int : in : sizes of current fragment
* sx,sy,sz       : int : in : position of the element [0][0][0] of current fragment in global mesh
* hx,hy,hz       : real : in : mesh steps
* dvr,dvf,dvz    : real : initial particles distribution parameters: radius, angle and Z velocity dispersions
* wave           : int : in : number of velocity radial waves from 0 to max
* cx,cy,cz       : real : in : center coordinates
* tau            : real : in : time step
* emax           : real : maximum particle kinetic energy
* fi1d           : real[nx][ny][nz] : out : fragment of 3D array (gravitational potential)
* fx1d,fy1d,fz1d : real[nx][ny][nz] : out : fragment of 3D array (gravitational forces)
* np             : size_t : in: number of particles
* p              : Particle[np] : inout : particles
*/
    void init_particles_velocity_z(int nx, int ny, int nz, int sx, int sy, int sz, real hx, real hy, real hz, real cx, real cy, real cz,
              real dvr, real dvf, real dvz, int wave, real tau, real emax, const real *fi, const real *fx, const real *fy, const real *fz, int np, Particle *p);
/*
* nx,ny,nz       : int : in : sizes of current fragment
* sx,sy,sz       : int : in : position of the element [0][0][0] of current fragment in global mesh
* hx,hy,hz       : real : in : mesh steps
* dvr,dvf,dvy    : real : initial particles distribution parameters: radius, angle and Y velocity dispersions
* wave           : int : in : number of velocity radial waves from 0 to max
* cx,cy,cz       : real : in : center coordinates
* tau            : real : in : time step
* emax           : real : maximum particle kinetic energy
* fi1d           : real[nx][ny][nz] : out : fragment of 3D array (gravitational potential)
* fx1d,fy1d,fz1d : real[nx][ny][nz] : out : fragment of 3D array (gravitational forces)
* np             : size_t : in: number of particles
* p              : Particle[np] : inout : particles
*/
    void init_particles_velocity_y(int nx, int ny, int nz, int sx, int sy, int sz, real hx, real hy, real hz, real cx, real cy, real cz,
              real dvr, real dvf, real dvy, int wave, real tau, real emax, const real *fi, const real *fx, const real *fy, const real *fz, int np, Particle *p);
/*
* nx,ny,nz       : int : in : sizes of current fragment
* sx,sy,sz       : int : in : position of the element [0][0][0] of current fragment in global mesh
* hx,hy,hz       : real : in : mesh steps
* dvr,dvf,dvx    : real : initial particles distribution parameters: radius, angle and X velocity dispersions
* wave           : int : in : number of velocity radial waves from 0 to max
* cx,cy,cz       : real : in : center coordinates
* tau            : real : in : time step
* emax           : real : maximum particle kinetic energy
* fi1d           : real[nx][ny][nz] : out : fragment of 3D array (gravitational potential)
* fx1d,fy1d,fz1d : real[nx][ny][nz] : out : fragment of 3D array (gravitational forces)
* np             : size_t : in: number of particles
* p              : Particle[np] : inout : particles 
*/
    void init_particles_velocity_x(int nx, int ny, int nz, int sx, int sy, int sz, real hx, real hy, real hz, real cx, real cy, real cz,
              real dvr, real dvf, real dvx, int wave, real tau, real emax, const real *fi, const real *fx, const real *fy, const real *fz, int np,Particle *p);
/*
* nx,ny,nz       : int : in : sizes of current fragment
* sx,sy,sz       : int : in : position of the element [0][0][0] of current fragment in global mesh
* hx,hy,hz       : real : in : mesh steps
* dvr,dvf,dvz    : real : initial particles distribution parameters: radius, angle and Z velocity dispersions
* cx,cy,cz       : real : in : center coordinates
* tau            : real : in : time step
* emax           : real : maximum particle kinetic energy
* fi1d           : real[nx][ny][nz] : out : fragment of 3D array (gravitational potential)
* fx1d,fy1d,fz1d : real[nx][ny][nz] : out : fragment of 3D array (gravitational forces)
* np             : size_t : in: number of particles
* p              : Particle[np] : inout : particles
*/
    void init_particles_velocity_ball(int nx, int ny, int nz, int sx, int sy, int sz, real hx, real hy, real hz, real cx, real cy, real cz,
              real dvr, real dvf, real dvz, real tau, real emax, const real *fi, const real *fx, const real *fy, const real *fz, int np,Particle *p);
}