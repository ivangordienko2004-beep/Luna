#include <math.h>
#include <string.h>
#include <cstdio>
#include "pic3d_codes.h"
#include "pic3d_fill.h"

constexpr real PI =  3.1415926535897932384626433832795;

real func_fi(real x, real y, real z)
{ 
    return x*x + y*y + z*z; 
}

real func_rhs(real x, real y, real z)
{ 
    return 6; 
}

static real sqr(real x) 
{ 
    return x*x; 
}

// transformation of local cell number to coordinates of cell center
real il2xc(int i, int sx, real hx) 
{ 
    return (il2g(i, sx)+0.5)*hx; 
}

real kl2yc(int k, int sy, real hy) 
{ 
    return (kl2g(k, sy)+0.5)*hy; 
}

real ll2zc(int l, int sz, real hz) 
{ 
    return (ll2g(l, sz)+0.5)*hz; 
}

void init_array3d(int nx, int ny, int nz, int sx, int sy, int sz, real hx, real hy, real hz, real *u1d)
{
    real (*u)[nx][ny][nz]=(real(*)[nx][ny][nz])u1d;
    int i, k, l;

    for (i=0; i<nx; i++) {
        for (k=0; k<ny; k++) {
            for (l=0; l<nz; l++) {
                (*u)[i][k][l]=func_fi(il2xc(i, sx, hx), kl2yc(k, sy, hy), ll2zc(l, sz, hz));
            }
        }
    }
}

void poisson_init(int nx, int ny, int nz, int sx, int sy, int sz, real hx, real hy, real hz, real *fi1d)
{
    real (*fi)[nx][ny][nz]=(real(*)[nx][ny][nz])fi1d;
    int i, k, l;

    for (i=0; i<nx; i++) {
        for (k=0; k<ny; k++) {
            for (l=0; l<nz; l++) {
                (*fi)[i][k][l]=0.0;
            }
        }
    }
}

void poisson_edge_function(int nfx, int nfy, int nfz, int ifx, int ify, int ifz, int nx, int ny, int nz, int sx, int sy, int sz, real hx, real hy, real hz, real *fi1d)
{
  real (*fi)[nx][ny][nz]=(real(*)[nx][ny][nz])fi1d;
  int i, k, l;

  if (ifx==0) {
      for (k=0; k<ny; k++) {
          for (l=0; l<nz; l++) {
            (*fi)[0][k][l]=func_fi(il2xc(0, sx, hx), kl2yc(k, sy, hy), ll2zc(l, sz, hz));
          }
      }
  }

  if (ifx==nfx-1) {
      for (k=0; k<ny; k++) {
          for (l=0; l<nz; l++) {
              (*fi)[nx-1][k][l]=func_fi(il2xc(nx-1, sx, hx), kl2yc(k, sy, hy), ll2zc(l, sz, hz));
          }
      }
  }

  if (ify==0) {
      for (i=0; i<nx; i++) {
          for (l=0; l<nz; l++) {
              (*fi)[i][0][l]=func_fi(il2xc(i, sx, hx), kl2yc(0, sy, hy), ll2zc(l, sz, hz));
          }
      }
  }

  if (ify==nfy-1) {
      for (i=0; i<nx; i++) {
          for (l=0;l<nz;l++) {
              (*fi)[i][ny-1][l]=func_fi(il2xc(i, sx, hx), kl2yc(ny-1, sy, hy), ll2zc(l, sz, hz));
          }
      }
  }

  if (ifz==0) {
      for (i=0; i<nx; i++) {
          for (k=0; k<ny; k++) {
              (*fi)[i][k][0]=func_fi(il2xc(i, sx, hx), kl2yc(k, sy, hy), ll2zc(0, sz, hz));
          }
      }
  }

  if (ifz==nfz-1) {
      for (i=0; i<nx; i++) {
          for (k=0; k<ny; k++) {
              (*fi)[i][k][nz-1]=func_fi(il2xc(i, sx, hx), kl2yc(k, sy, hy), ll2zc(nz-1, sz, hz));
          }
      }
  }
}

// Edge: fi = -M/R
void poisson_edge_simple(int nfx, int nfy, int nfz, int ifx, int ify, int ifz, int nx, int ny, int nz, int sx, int sy, int sz, real hx, real hy, real hz, real cx, real cy, real cz, real pm, real *fi1d)
{
  real (*fi)[nx][ny][nz]=(real(*)[nx][ny][nz])fi1d;
  int i, k, l;

  if (ifx==0) { 
      real x=-0.5*hx-cx;
      real x2=x*x;

      for (k=0; k<ny; k++) { 
          real y=(kl2g(k,sy)+0.5)*hy-cy;
          real x2py2=x2+y*y;
        
          for (l=0; l<nz; l++) { 
              real z=(ll2g(l, sz)+0.5)*hz-cz;
              real r=sqrt(x2py2+z*z);
              (*fi)[0][k][l]=-pm/r;
          }
      }
  }

  if (ifx==nfx-1) { 
      real x=(il2g(nx-1, sx)+0.5)*hx-cx;
      real x2=x*x;

      for (k=0; k<ny; k++) { 
          real y=(kl2g(k,sy)+0.5)*hy-cy;
          real x2py2=x2+y*y;

          for (l=0;l<nz;l++) { 
              real z=(ll2g(l, sz)+0.5)*hz-cz;
              real r=sqrt(x2py2+z*z);
              (*fi)[nx-1][k][l]=-pm/r;
          }
      }
  }

  if (ify==0) { 
      real y=-0.5*hy-cy;
      real y2=y*y;

      for (i=0; i<nx; i++) { 
          real x=(il2g(i, sx)+0.5)*hx-cx;
          real x2py2=x*x+y2;

          for (l=0; l<nz; l++) { 
              real z=(ll2g(l, sz)+0.5)*hz-cz;
              real r=sqrt(x2py2+z*z);
              (*fi)[i][0][l]=-pm/r;
          }
      }
  }

  if (ify==nfy-1) { 
      real y=(kl2g(ny-1,sy)+0.5)*hy-cy;
      real y2=y*y;

      for (i=0; i<nx; i++) { 
          real x=(il2g(i,sx)+0.5)*hx-cx;
          real x2py2=x*x+y2;

          for (l=0; l<nz; l++)  { 
              real z=(ll2g(l,sz)+0.5)*hz-cz;
              real r=sqrt(x2py2+z*z);
              (*fi)[i][ny-1][l]=-pm/r;
          }
      }
  }

  if (ifz==0) { 
      real z=-0.5*hz - cz;
      real z2=z*z;

      for (i=0; i<nx; i++) { 
          real x=(il2g(i,sx)+0.5)*hx-cx;
          real x2pz2=x*x + z2;

          for (k=0; k<ny; k++) { 
              real y=(kl2g(k,sy)+0.5)*hy-cy;
              real r=sqrt(x2pz2+y*y);
              (*fi)[i][k][0]=-pm/r;
          }
      }
  }

  if (ifz==nfz-1) { 
      real z=(ll2g(nz-1,sz)+0.5)*hz-cz;
      real z2=z*z;

      for (i=0; i<nx; i++) { 
          real x=(il2g(i,sx)+0.5)*hx-cx;
          real x2pz2=x*x+z2;

          for (k=0; k<ny; k++) { 
              real y=(kl2g(k,sy)+0.5)*hy-cy;
              real r=sqrt(x2pz2+y*y);
              (*fi)[i][k][nz-1]=-pm/r;
          }
      }
  }
}

// Edge: fi += -M/R
void fi_dobavka(int nfx, int nfy, int nfz, int ifx, int ify, int ifz, int nx, int ny, int nz, int sx, int sy, int sz, real hx, real hy, real hz, real cx, real cy, real cz, real sm, const real *fp1d, real *fi1d)
{
  const real (*fp)[nx][ny][nz]=(real(*)[nx][ny][nz])fp1d;
  real (*fi)[nx][ny][nz]=(real(*)[nx][ny][nz])fi1d;
  int i, k, l;

  if (sm==0.0) {
    memcpy(fi1d, fp1d, nx*ny*nz*sizeof(real));
  } else {
      for (i=0; i<nx; i++) { 
          real x=il2xc(i,sx,hx)-cx;
          real x2=x*x;

          for (k=0; k<ny; k++) { 
              real y=kl2yc(k,sy,hy)-cy;
              real x2py2=x2+y*y;

              for (l=0; l<nz; l++) { 
                  real z=ll2zc(l,sz,hz)-cz;
                  real r=sqrt(x2py2+z*z);
                  (*fi)[i][k][l]=(*fp)[i][k][l]-sm/r;
              }
          }
      }
  }
}

void print_x(int ifx, int nx, int sx, real hx)
{ 
    printf("X[%d] : (%lf,%lf, - %lf,%lf)\n",ifx, il2xc(0, sx, hx), il2xc(1, sx, hx), il2xc(nx-2, sx, hx), il2xc(nx-1, sx, hx));
    fflush(stdout); 
}

void print_y(int ify, int ny, int sy, real hy)
{ 
    printf("Y[%d] : (%lf,%lf, - %lf,%lf)\n",ify, kl2yc(0, sy, hy), kl2yc(1, sy, hy), kl2yc(ny-2, sy, hy), kl2yc(ny-1, sy, hy)); 
    fflush(stdout); 
}

void print_z(int ifz, int nz, int sz, real hz) 
{ 
    printf("Z[%d] : (%lf,%lf, - %lf,%lf)\n",ifz, ll2zc(0, sz, hz), ll2zc(1, sz, hz), ll2zc(nz-2, sz, hz), ll2zc(nz-1, sz, hz)); 
    fflush(stdout); 
}

void density(int nx, int ny, int nz, int sx, int sy, int sz, real hx, real hy, real hz, real am, const Particle *p, size_t np, real *ro1d)
{
    real (*ro)[nx][ny][nz]=(real(*)[nx][ny][nz])ro1d;
    size_t j;
    int i, k, l;

    for (i=0; i<nx; i++) {
        for (k=0; k<ny; k++) {
            for (l=0; l<nz; l++) {
                (*ro)[i][k][l]=0;
            }
        }
    }  

    for (j=0; j<np; j++) { 
        real rx=p[j].x/hx-0.5; 
        i=floor(rx); 
        rx=rx-i; 
        i=ig2l(i, sx);
        real ry=p[j].y/hy-0.5; 
        k=floor(ry); 
        ry=ry-k; 
        k=kg2l(k, sy);
        real rz=p[j].z/hz-0.5; 
        l=floor(rz); 
        rz=rz-l; 
        l=lg2l(l, sz);
        (*ro)[i][k][l]+=(1-rx)*(1-ry)*(1-rz);
        (*ro)[i][k][l+1]+=(1-rx)*(1-ry)*rz;
        (*ro)[i][k+1][l]+=(1-rx)*ry*(1-rz);
        (*ro)[i][k+1][l+1]+=(1-rx)*ry*rz ;
        (*ro)[i+1][k][l]+=rx *(1-ry)*(1-rz);
        (*ro)[i+1][k][l+1]+=rx*(1-ry)*rz;
        (*ro)[i+1][k+1][l]+=rx*ry*(1-rz);
        (*ro)[i+1][k+1][l+1]+=rx*ry*rz;
    }

    real s=am/(hx*hy*hz);

    for (i=0; i<nx; i++) {
        for (k=0; k<ny; k++) {
            for (l=0; l<nz; l++) {
                (*ro)[i][k][l] *= s;
            }
        }
    }
}

void force(int nx, int ny, int nz, real hx, real hy, real hz, const real *fi1d, real *fx1d, real *fy1d, real *fz1d)
{ 
    int i, k, l;
    real (*fx)[nx][ny][nz]=(real(*)[nx][ny][nz])fx1d;
    real (*fy)[nx][ny][nz]=(real(*)[nx][ny][nz])fy1d;
    real (*fz)[nx][ny][nz]=(real(*)[nx][ny][nz])fz1d;
    const real (*fi)[nx][ny][nz]=(const real(*)[nx][ny][nz])fi1d;

    for (i=1; i<nx; i++) {
        for (k=1; k<ny; k++) {
            for (l=1; l<nz; l++) {
                (*fx)[i][k][l]=((*fi)[i-1][k][l]-(*fi)[i][k][l])/hx;
                (*fy)[i][k][l]=((*fi)[i][k-1][l]-(*fi)[i][k][l])/hy;
                (*fz)[i][k][l]=((*fi)[i][k][l-1]-(*fi)[i][k][l])/hz;
            }
        }
    }

    for (k=1; k<ny; k++) {
        for (l=1; l<nz; l++) {
            (*fy)[0][k][l]=((*fi)[0][k-1][l]-(*fi)[0][k][l])/hy;
            (*fz)[0][k][l]=((*fi)[0][k][l-1]-(*fi)[0][k][l])/hz;
        }
    }

    for (i=1; i<nx; i++) {
        for (l=1; l<nz; l++) {
            (*fx)[i][0][l]=((*fi)[i-1][0][l]-(*fi)[i][0][l])/hx;
            (*fz)[i][0][l]=((*fi)[i][0][l-1]-(*fi)[i][0][l])/hz;
        }
    }

    for (i=1; i<nx; i++) {
        for (k=1; k<ny; k++) {
            (*fx)[i][k][0]=((*fi)[i-1][k][0]-(*fi)[i][k][0])/hx;
            (*fy)[i][k][0]=((*fi)[i][k-1][0]-(*fi)[i][k][0])/hy;
        }
    }

    for (i=1; i<nx; i++) {
        (*fx)[i][0][0]=((*fi)[i-1][0][0]-(*fi)[i][0][0])/hx;
    }

    for (k=1; k<ny; k++) {
        (*fy)[0][k][0]=((*fi)[0][k-1][0]-(*fi)[0][k][0])/hy;
    }

    for (l=1; l<nz; l++) {
        (*fz)[0][0][l]=((*fi)[0][0][l-1]-(*fi)[0][0][l])/hz;
    }
}

void particle_force(real x, real y, real z, int nx, int ny, int nz, int sx, int sy, int sz, real hx, real hy, real hz,
     const real *fx1d, const real *fy1d, const real *fz1d, real *rfx, real *rfy, real *rfz)
{
    const real (*fx)[nx][ny][nz]=(const real(*)[nx][ny][nz])fx1d;
    const real (*fy)[nx][ny][nz]=(const real(*)[nx][ny][nz])fy1d;
    const real (*fz)[nx][ny][nz]=(const real(*)[nx][ny][nz])fz1d;

    real xb=x/hx;
    real yb=y/hy;
    real zb=z/hz;
    real xa=xb-0.5;
    real ya=yb-0.5;
    real za=zb-0.5;

    int ib=floor(xb); 
    xb-=ib; 
    ib=ig2l(ib, sx);

    int kb=floor(yb); 
    yb-=kb; 
    kb=kg2l(kb, sy);

    int lb=floor(zb); 
    zb-=lb; 
    lb=lg2l(lb, sz);

    int ia=floor(xa); 
    xa-=ia; 
    ia=ig2l(ia, sx);

    int ka=floor(ya); 
    ya-=ka; 
    ka kg2l(ka, sy);

    int la=floor(za); 
    za-=la; 
    la=lg2l(la, sz);

    *rfx=(1-xb)*((1-ya)*((1-za)*(*fx)[ib][ka][la]+za*(*fx)[ib][ka][la+1])+
      ya*((1-za)*(*fx)[ib][ka+1][la]+za*(*fx)[ib][ka+1][la+1]))+
        xb*((1-ya)*((1-za)*(*fx)[ib+1][ka][la]+za*(*fx)[ib+1][ka][la+1])+
          ya*((1-za)*(*fx)[ib+1][ka+1][la]+za*(*fx)[ib+1][ka+1][la+1]));

    *rfy=(1-xa)*((1-yb)*((1-za)*(*fy)[ia][kb][la]+za*(*fy)[ia][kb][la+1])+
      yb*((1-za)*(*fy)[ia][kb+1][la]+za*(*fy)[ia][kb+1][la+1]))+
        xa*((1-yb)*((1-za)*(*fy)[ia+1][kb][la]+za*(*fy)[ia+1][kb][la+1])+
          yb*((1-za)*(*fy)[ia+1][kb+1][la]+za*(*fy)[ia+1][kb+1][la+1]));

    *rfz=(1-xa)*((1-ya)*((1-zb)*(*fz)[ia][ka][lb]+zb*(*fz)[ia][ka][lb+1])+
      ya*((1-zb)*(*fz)[ia][ka+1][lb]+zb*(*fz)[ia][ka+1][lb+1]))+
        xa*((1-ya)*((1-zb)*(*fz)[ia+1][ka][lb]+zb*(*fz)[ia+1][ka][lb+1])+
          ya*((1-zb)*(*fz)[ia+1][ka+1][lb]+zb*(*fz)[ia+1][ka+1][lb+1]));
}

void particle_potential(real x, real y, real z, int nx, int ny, int nz, int sx, int sy, int sz, real hx, real hy, real hz, const real *fi1d, real *s)
{
    const real (*fi)[nx][ny][nz]=(const real(*)[nx][ny][nz])fi1d;

    real xa=x/hx-0.5;
    real ya=y/hy-0.5;
    real za=z/hz-0.5;

    int i=floor(xa); 
    xa-=i; 
    i=ig2l(i, sx);

    int k=floor(ya); 
    ya-=k; 
    k=kg2l(k, sy);

    int l=floor(za); 
    za-=l; 
    l=lg2l(l, sz);

    *s=(1-xa)*((1-ya)*((1-za)*(*fi)[i][k][l]+za*(*fi)[i][k][l+1])+
      ya*((1-za)*(*fi)[i][k+1][l]+za*(*fi)[i][k+1][l+1]))+
        xa*((1-ya)*((1-za)*(*fi)[i+1][k][l]+za*(*fi)[i+1][k][l+1])+
          ya*((1-za)*(*fi)[i+1][k+1][l]+za*(*fi)[i+1][k+1][l+1]));
}

void move_particles(int nx, int ny, int nz ,int sx, int sy, int sz, real hx, real hy, real hz,
                    const real *fx1d, const real *fy1d, const real *fz1d, real tau, size_t np, Particle *p)
{
    real const um=hx/tau, vm=hy/tau, wm =hz/tau;
    size_t j;
    int warn=0;

    for (j=0; j<np; j++) {
        real x=p[j].x;
        real y=p[j].y;
        real z=p[j].z;
        real u=p[j].u;
        real v=p[j].v;
        real w=p[j].w;
        real fx,fy,fz;
        particle_force(x, y, z, nx, ny, nz, sx, sy, sz, hx, hy, hz, fx1d, fy1d, fz1d, &fx, &fy, &fz);

        int war=0;
        real du=tau*fx; 

        if (fabs(du)<=um) {
            u+=du; 
        } else { 
            u+=(1-2*signbit(du))*um; 
            war=1; 
        }

        real dv=tau*fy; 

        if (fabs(dv)<=vm) {
            v+=dv; 
        } else { 
            v+=(1-2*signbit(dv))*vm; 
            war=1; 
        }

        real dw=tau*fz; 
        
        if (fabs(dw)<=wm) {
            w+=dw; 
        } else { 
            w+=(1-2*signbit(dw))*wm; 
            war=1;
        }

        x+=tau*u;
        y+=tau*v;
        z+=tau*w;
        p[j].x=x;
        p[j].y=y;
        p[j].z=z;
        p[j].u=u;
        p[j].v=v;
        p[j].w=w;

        if (war) {
            warn++;
        }
    }

    if (warn) { 
        printf("Warning! %d fast particle(s)!\n", warn); 
        fflush(stdout); 
    }
}


void get_properties(int nx, int ny, int nz, int sx, int sy, int sz, real hx, real hy, real hz,
       real cx, real cy, real cz, real sm, const real *fi, int np, const Particle *p, real *prop)
{
    real cCPX=0.0, cCPY=0.0, cCPZ=0.0,
        cPPX=0.0, cPPY=0.0, cPPZ=0.0,
        cMPX=0.0, cMPY=0.0, cMPZ=0.0,
        cEPP=0.0, cEPK=0.0, cEPS=0.0;

    size_t j;

    for (j=0; j<np; j++) { 
        real x=p[j].x;
        real y=p[j].y;
        real z=p[j].z;
        real u=p[j].u;
        real v=p[j].v;
        real w=p[j].w;
        real s; 
        particle_potential(x, y, z, nx, ny, nz, sx, sy, sz, hx, hy, hz, fi, &s);

        cEPP+=s;
        x-=cx;
        y-=cy;
        z-=cz;
        cCPX+=x;
        cCPY+=y;
        cCPZ+=z;
        cPPX+=u;
        cPPY+=v;
        cPPZ+=w;
        cMPX+=y*w-z*v;
        cMPY+=z*u-x*w;
        cMPZ+=x*v-y*u;
        cEPK+=u*u+v*v+w*w;
        cEPS+=-sm/sqrt(x*x+y*y+z*z);
    }

    prop[0]=cCPX; 
    prop[1]=cCPY; 
    prop[2]=cCPZ;
    prop[3]=cPPX; 
    prop[4]=cPPY;
    prop[5]=cPPZ;
    prop[6]=cMPX; 
    prop[7]=cMPY; 
    prop[8]=cMPZ;
    prop[9]=cEPP; 
    prop[10]=cEPS; 
    prop[11]=cEPK; 
    prop[12]=np;
}

void get_properties_finish(real am, real pm, const real *prop0, Properties *prop)
{
    prop->cCPX=prop0[0]*am/pm;
    prop->cCPY=prop0[1]*am/pm;
    prop->cCPZ=prop0[2]*am/pm;
    prop->cPPX=prop0[3]*am;
    prop->cPPY=prop0[4]*am;
    prop->cPPZ=prop0[5]*am;
    prop->cMPX=prop0[6]*am;
    prop->cMPY=prop0[7]*am;
    prop->cMPZ=prop0[8]*am;
    prop->cEPP=prop0[9]*am*0.5;
    prop->cEPS=prop0[10]*am;
    prop->cEPK=prop0[11]*am*0.5;
    prop->cM=prop0[12]*am;
}

void print_properties(const char *filename, const Properties *prop, int it, real cx, real cy, real cz)
{ 
    FILE *f=fopen(filename, "a");
    if (f==NULL) { 
        printf("Can't open log file: %s\n",filename); 
        fflush(stdout); 
        return; 
    } else { 
        fprintf(f,"%4d\t%.18le\t%.18le\t%.18le\t%.18le\t%.18le\t%.18le\t%.18le\t%.18le\t%.18le\t%.18le\t%.18le\t%.18le\t%.18le\t%.18le\t%.18le\n", it,
        prop->cCPX, prop->cCPY, prop->cCPZ,   // mass center shift
        prop->cPPX, prop->cPPY, prop->cPPZ,   // momentum
        prop->cMPX, prop->cMPY, prop->cMPZ,   // angular momentum
        prop->cEPP, prop->cEPS, prop->cEPK,   // energy: potential particles, potential outer, kinetic
        0.0, 0.0, prop->cM);  // heat energy, inner energy, particles mass
        fclose(f);
    }

    real distance=sqrt(sqr(prop->cCPX)+sqr(prop->cCPY)+sqr(prop->cCPZ));
    real impulse=sqrt(sqr(prop->cPPX)+sqr(prop->cPPY)+sqr(prop->cPPZ));
    real energy=prop->cEPP+prop->cEPS+prop->cEPK;
    printf("%4d : c:%.18le p:%.18le e:%.18le\n", it, distance, impulse, energy); 
    fflush(stdout);
}