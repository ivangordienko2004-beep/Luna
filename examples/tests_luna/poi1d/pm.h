#pragma once

#define FG_COUNT 16
#define nx ((NX)/(FG_COUNT))

#define PI 3.1415926535897932384626433832795

//parameters: integer
#define NX 128     // mesh size X: 300
#define NY 4       // mesh size Y: 300
#define NZ 16	   // mesh size Z: 300
#define NP 10000   // number of particles: 10000000
#define NT 1000    // number of time steps
#define STEPLOG 10 // number of time steps between logs

//parameters: real
#define XN 4.0     // Domain size: X
#define YN 4.0     // Domain size: Y
#define ZN 4.0     // Domain size: Z
#define PM 1.0     // Particles total mass
#define EPS 1.0e-3 // Poisson solver precision
#define TAU 0.001  // time step
#define R0  1.0    // Initial distribution parameter: radius
#define DVR 0.0    // radius velocity dispersion
#define DVF 0.0    // angle velocity dispersion
#define DVZ 0.0    // Z velocity dispersion

#define hx (XN/(NX-2))
#define hy (YN/(NY-2))
#define hz (ZN/(NZ-2))
#define cx (XN/2)
#define cy (YN/2)
#define cz (ZN/2)
#define am (PM/NP)

struct Particle
{ 
    double x, y, z;
    double u, v, w;
};

#define px(j) (p[j].x)
#define py(j) (p[j].y)
#define pz(j) (p[j].z)
#define pu(j) (p[j].u)
#define pv(j) (p[j].v)
#define pw(j) (p[j].w)

#define FI(i, j, k) Fi[(i)*(NY)*(NZ)+(j)*(NZ)+(k)]
#define RO(i, j, k) Ro[(i)*(NY)*(NZ)+(j)*(NZ)+(k)]

typedef long long particle_count_t;

struct Conservation
{ 
    double cCPX, cCPY, cCPZ; // mass center
    double cPPX, cPPY, cPPZ; // momentum
    double cMPX, cMPY, cMPZ; // angular momentum
    double cEPP;             // potential energy
    double cEPK;             // kinetic energy
    double cM;               // particles mass
};

void particle_force(double x, double y, double z, double *fx, double *fy, double *fz);
double particle_potential(double x, double y, double z);

double g05cae();
double g05dde(double a, double b);
double get_integral_2D_table(double r, double xt[], double yt[], int n, int dim);
double get_integral_3D_table(double r, double xt[], double yt[], int n, int dim);
double get_integral_2D_sqrt(double r);
double get_integral_3D_sqrt(double r);
double get_integral_2D_exp(double r);
double get_integral_3D_exp(double r);
double get_integral_2D_line(double r);
double get_integral_3D_line(double r);
double get_integral_2D_const(double r);
double get_integral_3D_const(double r);
double get_integral(double r, int kind, int dim);
double get_arg(double a, double b, double r, int kind, int dim);
void add_particle(double x, double y, double z, double u, double v, double w);
void add_particleXYZ(double x, double y, double z);

void fill_particles_circle_xy(particle_count_t n, int kind);
void fill_particles_ball(particle_count_t n, int kind);

void particle_velocity_ball(double x, double y, double z, double *u, double *v, double *w);
void particle_velocity_z(double x, double y, double z, double *u, double *v, double *w, int wave, int disp);

void poisson_edge_simple(double *Fi, int rank);
void poisson_zeidel(double *Fi, const double *Ro, int rank, double& loc_max);

void v_dispers(double *vr, double *vf, double *vz);
void v_dispers_wave(double *vr, double *vf, double *vz, double fi, int wave);
void fill_particles_circle1_xy();
void fill_particles_left();