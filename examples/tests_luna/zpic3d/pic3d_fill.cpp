#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#include"pic3d_fill.h"
#include"pic3d_codes.h"

constexpr real PI=3.1415926535897932384626433832795;

void add_particle(real x, real y, real z, real u, real v, real w, std::vector<Particle> &p, real x1, real y1, real z1, real x2, real y2, real z2)
{
    if (x>=x1 && x<x2 && y>=y1 && y<y2 && z>=z1 && z<z2) {
        p.push_back(Particle(x, y, z, u, v, w));
    }
}
void add_particleXYZ(real x, real y, real z, std::vector<Particle> &p, real x1, real y1, real z1, real x2, real y2, real z2)
{
    if (x>=x1 && x<x2 && y>=y1 && y<y2 && z>=z1 && z<z2) {
        p.push_back(Particle(x, y, z));
    }
}

real get_integral_2D_table(real r, real xt[], real yt[], int n, int dim, real radius)
{ 
    real x=r/radius, y=0;
    int i;

    if (x>xt[0]) { 
        for (i=1; i<n && x>xt[i]; i++)
            y+=0.5*(xt[i]-xt[i-1])*(yt[i]*xt[i]+yt[i-1]*xt[i-1]);

        if (i<n) {
            y+=0.5*(x-xt[i-1])*(yt[i]*xt[i]+yt[i-1]*xt[i-1]);
        } else {    
            y+=(x-xt[n-1])*yt[n-1]*xt[n-1];
        }
    }
    return y;
}

real get_integral_3D_table(real r, real xt[], real yt[], int n, int dim, real radius)
{ 
    real x=r/radius, y=0;
    int i;

    if (x>xt[0]) { 
        for (i=1; i<n && x>xt[i]; i++)
            y+=0.5*(xt[i]-xt[i-1])*(yt[i]*xt[i]*xt[i]+yt[i-1]*xt[i-1]*xt[i-1]);

        if (i<n) {
            y+=0.5*(x-xt[i-1])*(yt[i]*xt[i]*xt[i]+yt[i-1]*xt[i-1]*xt[i-1]);
        } else {
            y+=(x-xt[n-1])*yt[n-1]*xt[n-1]*xt[n-1];
        }
    }
    return y;
}

real get_integral_2D_sqrt(real r,real radius)
{
    real a=radius*radius-r*r;
    return -1.0*(a*sqrt(a)-radius*radius*radius)/(3.0*radius);
}

real get_integral_3D_sqrt(real r,real radius)
{ 
    real a=radius*radius-r*r;
    return -1.0*(a*sqrt(a)-radius*radius*radius)/(3.0*radius);
}

real get_integral_2D_exp(real r,real radius)
{ 
    return radius*(radius-exp(-r/radius)*(r+radius)); 
}

real get_integral_3D_exp(real r,real radius)
{ 
    return radius*(2.0*radius*radius-exp(-r/radius)*(r*r+2.0*radius*r+2.0*radius*radius));
}

real get_integral_2D_line(real r,real radius) 
{
    return (r*r)*(0.5-r/(3*radius)); 
}

real get_integral_3D_line(real r,real radius) 
{ 
    return (r*r*r)*((1.0/3.0)-r/(4*radius)); 
}

real get_integral_2D_const(real r) 
{ 
    return 0.5*r*r;
}

real get_integral_3D_const(real r) 
{ 
    return (1.0/3.0)*r*r*r; 
}

real get_integral(real r, int kind, int dim, real radius)
{ 
    if (dim==2) {
        switch (kind) { 
            case 0:
                return 1.0;
            case 1: 
                return get_integral_2D_sqrt(r, radius);
            case 2: 
                return get_integral_2D_exp(r, radius);
            case 3: 
                return get_integral_2D_line(r, radius);
            case 4: 
                return get_integral_2D_const(r);
        }
    } else {
        if (dim==3) {
            switch (kind) { 
                case 0: 
                    return 1.0;
                case 1: 
                    return get_integral_3D_sqrt(r, radius);
                case 2: 
                    return get_integral_3D_exp(r, radius);
                case 3: 
                    return get_integral_3D_line(r, radius);
                case 4: 
                    return get_integral_3D_const(r);
            }
        }
    }
    return 1.0;
}

real get_arg(real a, real b, real r, int kind, int dim, real radius)
{ 
    real aa, bb, r1, x;

    if (a<b) { 
        aa=a; 
        bb=b; 
    } else { 
        aa=b;
        bb=a; 
    }

    x=aa+(bb-aa)*0.5;
    r1=get_integral(x, kind, dim, radius);

    while (fabs(r1-r)>1.0e-7) { 
        if (r1<r) { 
            aa=x;
            x+=0.5*(bb-x);
        } else { 
            bb=x;
            x-=0.5*(x-aa);
        }
        r1=get_integral(x, kind, dim, radius);
    }
    return x;
}

void v_dispers(g05dde &rnd, real *vr, real *vf, real *vz, real dvr, real dvf, real dvz)
{ 
    *vr=rnd.get(*vr, dvr);
    *vf=rnd.get(*vf, dvf);
    *vz=rnd.get(*vz, dvz);
}

void v_dispers_wave(g05dde &rnd, real *vr, real *vf, real *vz, real dvr, real dvf, real dvz, real fi, int wave)
{ 
    real s=(cos(wave*fi)+1.0)*0.5;
    *vr=rnd.get(*vr, s*dvr);
    *vf=rnd.get(*vf, s*dvf);
    *vz=rnd.get(*vz, s*dvz);
}

void fill_particles_circle_xy(size_t n, int kind, real radius, real cx, real cy, real cz, real x1, real y1, real z1, real x2, real y2, real z2, std::vector<Particle> &p)
{ 
    g05cae unirnd;
    size_t k, n0;
    real x, y, z;
    real r1, a, a1, s, s0, s1, r, f0, f, df, tmp;

    r1=1.0;
    s0=get_integral(radius, kind, 2, radius);
    s1=PI/n;
    a=sqrt(s1);

    while (n>1) { 
        tmp=r1-a;
        s=PI*(r1*r1-tmp*tmp);

        if (n==2) { 
            n0=n;
            a1=r1;
        } else { 
            n0=s/s1;
            n0+=n%2-n0%2;

            if (n0>n) {
                n0=n;
            }

            a1=r1-sqrt(r1*r1-n0*s1/PI);
        }

        df=2.0*PI/n0;
        r=r1-a1*0.5;
        r=get_arg(0.0, radius, r*r*s0, kind,2, radius);
        f0=unirnd.get()*df;

        for (k=0; k<n0; k++) { 
            f=f0+k*df;
            x=cx+r*cos(f);
            y=cy+r*sin(f);
            z=cz;
            add_particleXYZ(x, y, z, p, x1, y1, z1, x2, y2, z2);
        }

        r1-=a1;
        n-=n0;
    }

    if (n==1) { 
        printf("fill_circle_xy(): 1 strange particle...\n"); 
        fflush(stdout); 
    }
}

void fill_particles_circle_xz(size_t n, int kind, real radius, real cx, real cy, real cz, real x1, real y1, real z1, real x2 ,real y2, real z2, std::vector<Particle> &p)
{ 
    g05cae unirnd;
    size_t k, n0;
    real x, y, z;
    real r1, a, a1, s, s0, s1, r, f0, f, df, tmp;

    r1=1.0;
    s0=get_integral(radius, kind, 2, radius);
    s1=PI/n;
    a=sqrt(s1);

    while (n>1) { 
        tmp=r1-a;
        s=PI*(r1*r1-tmp*tmp);

        if (n==2) { 
            n0=n;
            a1=r1;
        } else { 
            n0=s/s1;
            n0+=n%2-n0%2;

            if (n0>n) { 
                n0=n;
            }

            a1=r1-sqrt(r1*r1-n0*s1/PI);
        }

        df=2.0*PI/n0;
        r=r1-a1*0.5;
        r=get_arg(0.0, radius, r*r*s0, kind, 2, radius);
        f0=unirnd.get()*df;

        for (k=0; k<n0; k++) { 
            f=f0+k*df;
            x=cx+r*cos(f);
            y=cy;
            z=cz+r*sin(f);
            add_particleXYZ(x, y, z, p, x1, y1, z1, x2, y2, z2);
        }

        r1-=a1;
        n-=n0;
    }

    if (n==1) { 
        printf("fill_circle_xy(): 1 strange particle...\n"); 
        fflush(stdout); 
    }
}

void fill_particles_circle_yz(size_t n, int kind, real radius, real cx, real cy, real cz, real x1, real y1, real z1, real x2, real y2, real z2, std::vector<Particle> &p)
{ 
    g05cae unirnd;
    size_t k, n0;
    real x, y, z;
    real r1, a, a1, s, s0, s1, r, f0, f, df, tmp;

    r1=1.0;
    s0=get_integral(radius, kind, 2, radius);
    s1=PI/n;
    a=sqrt(s1);

    while (n>1) { 
        tmp=r1-a;
        s=PI*(r1*r1-tmp*tmp);

        if (n==2) { 
            n0=n;
            a1=r1;
        } else { 
            n0=s/s1;
            n0+=n%2-n0%2;

            if (n0>n) {
                n0=n;
            }

            a1=r1-sqrt(r1*r1-n0*s1/PI);
        }

        df=2.0*PI/n0;
        r=r1-a1*0.5;
        r=get_arg(0.0, radius, r*r*s0, kind, 2, radius);
        f0=unirnd.get()*df;

        for (k=0; k<n0; k++) { 
            f=f0+k*df;
            x=cx;
            y=cy+r*cos(f);
            z=cz+r*sin(f);
            add_particleXYZ(x, y, z, p, x1, y1, z1, x2, y2, z2);
        }

        r1-=a1;
        n-=n0;
    }

    if (n==1) { 
      printf("fill_circle_xy(): 1 strange particle...\n"); 
      fflush(stdout); 
    }
}

void fill_particles_ball(size_t n, int kind, real radius, real cx, real cy, real cz, real x1, real y1, real z1, real x2, real y2, real z2, std::vector<Particle> &p)
{ 
    g05cae unirnd;
    size_t k, n0, n1, n2;
    real x, y, z;
    real r0, rs, rs1, v1, vs, a, a1, s, s0, hh, f10, f20, f, df, tmp;
    real sl, al;
    real alpha0, alpha, alpha1, dalpha, alp;
    real sin1, sin2, sin3, cos1, cos2, cos3;

    n0=n;
    r0=1.0;
    v1=(4.0*PI/3.0)/n;
    a1=pow(v1, 1.0/3.0);
    s0=get_integral(radius, kind, 3, radius);

    while (r0>a1) {
        tmp=r0-a1;
        vs=(4.0/3.0)*PI*(r0*r0*r0-tmp*tmp*tmp);
        n1=vs/v1;

        if (n1>n0) {
            n1=n0;
        }

        n1-=n1%2;
        a=r0-pow(r0*r0*r0-(3.0*n1*v1)/(4.0*PI),1.0/3.0);

        if (a>r0) {
            a=r0;
        }

        rs=r0-a*0.5;
        sl=4.0*PI*rs*rs/n1;
        al=sqrt(sl);
        alpha0=0.0;
        dalpha=al/rs;
        n0-=n1;
        rs1=get_arg(0.0, radius, s0*rs*rs*rs, kind, 3, radius);

        while (PI*0.5-alpha0>dalpha) {
            alpha1=alpha0+dalpha;
            hh=rs*(cos(alpha0)-cos(alpha1));
            s=2.0*PI*rs*hh;
            n2=s/sl;

            if (n2>n1/2) {
                n2=n1/2;
            }

            s=n2*sl;
            alpha1=acos(cos(alpha0)-s/(2.0*PI*rs*rs));
            alpha=alpha1-alpha0;
            alp=alpha0+alpha*0.5;
            df=2.0*PI/n2;
            f10=unirnd.get()*df;
            f20=unirnd.get()*df;
            sin1=rs1*sin(alp);
            sin2=rs1*sin(PI-alp);
            cos1=rs1*cos(alp);
            cos2=rs1*cos(PI-alp);

            for (k=0; k<n2; k++) { 
                f=f10+k*df;
                x=cx+sin1*cos(f);
                y=cy+sin1*sin(f);
                z=cz+cos1;
                add_particleXYZ(x, y, z, p, x1, y1, z1, x2, y2, z2);

                f=f20+k*df;
                x=cx+sin2*cos(f);
                y=cy+sin2*sin(f);
                z=cz+cos2;
                add_particleXYZ(x, y, z, p, x1, y1, z1, x2, y2, z2);
            }

            alpha0=alpha1;
            n1-=2*n2;
        }

        if (n1>0) { 
            alpha=PI-2.0*alpha0;
            al=alpha*rs;
            df=2.0*PI/n1;
            x=df*rs;

            if (2.0*x>=al) {
                alp=alpha*0.5;
            } else { 
                y=al*al-3.0*x*x;
                alp=(2.0*al+sqrt(y))/3.0;

                if (alp<0.0 || alp>2.0*x) { 
                    alp=(2.0*al-sqrt(y))/3.0;

                    if (alp<0.0 || alp>2.0*x) {
                        alp=2.0*x;
                    }
                }
            alp/=rs;
            }

            alpha1=alpha0+alpha-alp;
            alpha0=alpha0+alp;
            sin1=rs1*sin(alpha0);
            sin2=rs1*sin(alpha1);
            cos1=rs1*cos(alpha0);
            cos2=rs1*cos(alpha1);
            f10=unirnd.get()*df;

            for (k=0; k<n1; k+=2) { 
                f=f10+k*df;
                x=cx+sin1*cos(f);
                y=cy+sin1*sin(f);
                z=cz+cos1;
                add_particleXYZ(x, y, z, p, x1, y1, z1, x2, y2, z2);

                f=f+df;
                x=cx+sin2*cos(f);
                y=cy+sin2*sin(f);
                z=cz+cos2;
                add_particleXYZ(x, y, z, p, x1, y1, z1, x2, y2, z2);
            }
        }
        r0-=a;
    }

      if (n0==2) { 
          rs=2.0*r0/3.0;
          rs1=get_arg(0.0, radius, s0*rs*rs*rs, kind, 3, radius);
          f=unirnd.get()*PI;
          alp=unirnd.get()*PI*0.5;
          x=cx+rs1*sin(alp)*cos(f);
          y=cy+rs1*sin(alp)*sin(f);
          z=cz+rs1*cos(alp);
          add_particleXYZ(x, y, z, p, x1, y1, z1, x2, y2, z2);

          x=cx+rs1*sin(PI-alp)*cos(f+PI);
          y=cy+rs1*sin(PI-alp)*sin(f+PI);
          z=cz+rs1*cos(PI-alp);
          add_particleXYZ(x, y, z, p, x1, y1, z1, x2, y2, z2);
      } else {
          if (n0==3) { 
              rs=r0/(1.0+sqrt(3.0));
              rs1=get_arg(0.0, radius, s0*rs*rs*rs, kind, 3, radius);
              alpha0=unirnd.get()*2.0*PI;
              alpha1=unirnd.get()*2.0*PI;
              alpha=unirnd.get()*2.0*PI;
              sin1=sin(alpha0);
              sin2=sin(alpha1);
              sin3=sin(alpha );
              cos1=cos(alpha0);
              cos2=cos(alpha1);
              cos3=cos(alpha );
              x=rs1;
              y=0.0;
              z=0.0;
              y=cos1*y+sin1*z;  // y : yz
              z=-sin1*y+cos1*z; // z : yz
              a=cos2*x+sin2*z;  // x : xz
              z=cz-sin2*x+cos2*z; // z : xz
              x=cx+cos2*a+sin2*y; // x : xy
              y=cy-sin2*a+cos2*y; // y : xy
              add_particleXYZ(x, y, z, p, x1, y1, z1, x2, y2, z2);

              x=rs1*(-0.5);
              y=rs1*(sqrt(3.0)/2.0);
              z=0.0;
              y=cos1*y+sin1*z;  // y : yz
              z=-sin1*y+cos1*z; // z : yz
              a=cos2*x+sin2*z;  // x : xz
              z=cz-sin2*x+cos2*z; // z : xz
              x=cx+cos2*a+sin2*y; // x : xy
              y=cy-sin2*a+cos2*y; // y : xy
              add_particleXYZ(x, y, z, p, x1, y1, z1, x2, y2, z2);

              x=rs1*(-0.5);
              y=rs1*(-sqrt(3.0)/2.0);
              z=0.0;
              y=cos1*y+sin1*z;  // y : yz
              z=-sin1*y+cos1*z; // z : yz
              a=cos2*x+sin2*z;  // x : xz
              z=cz-sin2*x+cos2*z; // z : xz
              x=cx+cos2*a+sin2*y; // x : xy
              y=cy-sin2*a+cos2*y; // y : xy
              add_particleXYZ(x, y, z, p, x1, y1, z1, x2, y2, z2);
          } else {
              if (n0==4) {
                  rs=r0/(1.0+2.0*sqrt(2.0/3.0));
                  rs1=get_arg(0.0, radius, s0*rs*rs*rs, kind, 3, radius);
                  f=sqrt(2.0/3.0)*rs1;
                  alpha0=unirnd.get()*2.0*PI;
                  alpha1=unirnd.get()*2.0*PI;
                  alpha= unirnd.get()*2.0*PI;
                  sin1=sin(alpha0);
                  sin2=sin(alpha1);
                  sin3=sin(alpha );
                  cos1=cos(alpha0);
                  cos2=cos(alpha1);
                  cos3=cos(alpha );
                  x=rs1;
                  y=0.0;
                  z=0.0;
                  y=cos1*y+sin1*z;  // y : yz
                  z=-sin1*y+cos1*z; // z : yz
                  a=cos2*x+sin2*z;  // x : xz
                  z=cz-sin2*x+cos2*z; // z : xz
                  x=cx+cos2*a+sin2*y; // x : xy
                  y=cy-sin2*a+cos2*y; // y : xy
                  add_particleXYZ(x, y, z, p, x1, y1, z1, x2, y2, z2);

                  x=rs1/(-3.0);
                  y=(2.0/3.0*sqrt(2.0))*rs1;
                  z=0.0;
                  y=cos1*y+sin1*z;  // y : yz
                  z=-sin1*y+cos1*z; // z : yz
                  a=cos2*x+sin2*z;  // x : xz
                  z=cz-sin2*x+cos2*z; // z : xz
                  x=cx+cos2*a+sin2*y; // x : xy
                  y=cy-sin2*a+cos2*y; // y : xy
                  add_particleXYZ(x, y, z, p, x1, y1, z1, x2, y2, z2);

                  x=-sqrt(1.0/3.0)*rs1;
                  y=-sqrt(2.0/3.0)*rs1;
                  z=rs1; // f/2
                  y=cos1*y+sin1*z;  // y : yz
                  z=-sin1*y+cos1*z; // z : yz
                  a=cos2*x+sin2*z;  // x : xz
                  z=cz-sin2*x+cos2*z; // z : xz
                  x=cx+cos2*a+sin2*y; // x : xy
                  y=cy-sin2*a+cos2*y; // y : xy
                  add_particleXYZ(x, y, z, p, x1, y1, z1, x2, y2, z2);

                  x=-sqrt(1.0/3.0)*rs1;
                  y=-sqrt(2.0/3.0)*rs1;
                  z=-f/2.0;
                  y=cos1*y+sin1*z;  // y : yz
                  z=-sin1*y+cos1*z; // z : yz
                  a=cos2*x+sin2*z;  // x : xz
                  z=cz-sin2*x+cos2*z; // z : xz
                  x=cx+cos2*a+sin2*y; // x : xy
                  y=cy-sin2*a+cos2*y; // y : xy
                  add_particleXYZ(x, y, z, p, x1, y1, z1, x2, y2, z2);
              } else { 
                  x=n0;
              }
          }
      }
}

void fill_particles_full(size_t n, real x1, real y1, real z1, real x2, real y2, real z2, std::vector<Particle> &p)
{
    g05cae unirnd;
    size_t j;

    for (j=0; j<n; j++) { 
        real x=x1+(x2-x1)*unirnd.get(); //+ 0.25*(x2-x1);
        real y=y1+(y2-y1)*unirnd.get(); //+ 0.25*(y2-y1);
        real z=z1+(z2-z1)*unirnd.get(); //+ 0.25*(z2-z1);

        add_particleXYZ(x, y, z, p, x1, y1, z1, x2, y2, z2);
    }
}

void particle_velocity_z(g05dde &gaurnd, real x, real y, real z, real fx, real fy, real fz, real cx, real cy, real cz, real tau, real pfi, real dvr, real dvf, real dvz, real emax, int wave, real *u, real *v, real *w)
{
    real rxy, rxy2, rxyz, rxyz2, sn, cs, fxy;
    real fr, ff, s;
    real vr, vf, vz, svr, svf, svz;
    real ep;
    int i, stp;

    x-=cx;
    y-=cy;
    z-=cz;
    rxy2=x*x+y*y;
    rxy=sqrt(rxy2);
    rxyz2=rxy2+z*z;
    rxyz=sqrt(rxyz2);

    if (fabs(rxy)>1.0e-14) { 
        sn=y/rxy; 
        cs=x/rxy; 
    } else { 
        sn=0.0; 
        cs=1.0; 
    }

    fxy=acos(cs);

    if (sn<0) {
        fxy=2.0*PI-fxy;
    }

    ff=fy*cs-fx*sn;
    fr=fx*cs+fy*sn;

    if (fr>0.0) {
        fr=0.0;
    }

    vr=-tau*fr*0.5;
    s=(tau*tau)*fr*0.25;

    if (rxy>-s) {
        vf=sqrt(-fr*(rxy+s));
    } else {
        vf=sqrt(-fr*rxy);
    }

    vz=0.0;
    svr=vr;
    svf=vf;
    svz=vz;
    stp=0;

    for (i=0; !stp && i<100; i++) { 
      if (wave) {
          v_dispers_wave(gaurnd, &vr, &vf, &vz, dvr, dvf, dvz, fxy, wave);
      } else {
          v_dispers(gaurnd, &vr, &vf, &vz, dvr, dvf, dvz);
      }

      ep=0.5*(vr*vr+vf*vf+vz*vz)+pfi;

      if (ep<emax) {
          stp=1;
      } else { 
          vr=svr;
          vf=svf;
          vz=svz;
      }
    }

    *u=vr*cs-vf*sn;
    *v=vr*sn+vf*cs;
    *w=vz;
}

void particle_velocity_y(g05dde &gaurnd, real x, real y, real z, real fx, real fy, real fz, real cx, real cy, real cz, real tau, real pfi, real dvr, real dvf, real dvy, real emax, int wave, real *u, real *v, real *w)
{
    real rxz, rxz2, rxyz, rxyz2, sn, cs, fxz;
    real fr, ff, s;
    real vr, vf, vy, svr, svf, svy;
    real ep;
    int i, stp;

    x-=cx;
    y-=cy;
    z-=cz;
    rxz2=x*x+z*z;
    rxz=sqrt(rxz2);
    rxyz2=rxz2+y*y;
    rxyz=sqrt(rxyz2);

    if (fabs(rxz)>1.0e-14) { 
        sn=z/rxz; 
        cs=x/rxz; 
    } else { 
        sn=0.0; 
        cs=1.0; 
    }

    fxz=acos(cs);

    if (sn<0.0) {
        fxz=2.0*PI-fxz;
    }

    ff=fz*cs-fx*sn;
    fr=fx*cs+fz*sn;

    if (fr>0) {
        fr=0;
    }

    vr=-tau*fr*0.5;
    s=(tau*tau)*fr*0.25;

    if (rxz>-s) {
        vf=sqrt(-fr*(rxz+s));
    } else {
        vf=sqrt(-fr*rxz);
    }

    vy=0.0;
    svr=vr;
    svf=vf;
    svy=vy;
    stp=0;

    for (i=0; !stp && i<100; i++) { 
        if (wave) {
            v_dispers_wave(gaurnd, &vr, &vf, &vy, dvr, dvf, dvy, fxz, wave);
        } else {
            v_dispers(gaurnd, &vr, &vf, &vy, dvr, dvf, dvy);
        }

        ep=0.5*(vr*vr+vf*vf+vy*vy)+pfi;

        if (ep<emax) {
            stp=1;
        } else { 
            vr=svr;
            vf=svf;
            vy=svy;
        }
    }

    *u=vr*cs-vf*sn;
    *v=vy;
    *w=vr*sn+vf*cs;
}

void particle_velocity_x(g05dde &gaurnd, real x, real y, real z, real fx, real fy, real fz, real cx, real cy, real cz, real tau, real pfi, real dvr, real dvf, real dvx, real emax, int wave, real *u, real *v, real *w)
{
    real ryz, ryz2, rxyz, rxyz2, sn, cs, fyz;
    real fr, ff, s;
    real vr, vf, vx, svr, svf, svx;
    real ep;
    int i, stp;

    x-=cx;
    y-=cy;
    z-=cz;
    ryz2=y*y+z*z;
    ryz=sqrt(ryz2);
    rxyz2=x*x+ryz2;
    rxyz=sqrt(rxyz2);

    if (fabs(ryz)>1.0e-14) { 
        sn=z/ryz; 
        cs=y/ryz; 
    } else { 
        sn=0.0; 
        cs=1.0; 
    }

    fyz=acos(cs);

    if (sn<0.0) {
        fyz=2.0*PI-fyz;
    }

    ff=fz*cs-fy*sn;
    fr=fy*cs+fz*sn;

    if (fr>0.0) {
      fr=0.0;
    }

    vr=-tau*fr*0.5;
    s=(tau*tau)*fr*0.25;

    if (ryz>-s) {
        vf=sqrt(-fr*(ryz+s));
    } else {
        vf=sqrt(-fr*ryz);
    }

    vx=0.0;
    svr=vr;
    svf=vf;
    svx=vx;
    stp=0;

    for (i=0; !stp && i<100; i++) { 
        if (wave) {
            v_dispers_wave(gaurnd, &vr, &vf, &vx, dvr, dvf, dvx, fyz, wave);
        } else {
            v_dispers(gaurnd, &vr, &vf, &vx, dvr, dvf, dvx);
        }

        ep=0.5*(vr*vr+vf*vf+vx*vx)+pfi;

        if (ep<emax) {
            stp=1;
        } else { 
            vr=svr;
            vf=svf;
            x=svx;
        }
    }

    *u=vx;
    *v=vr*cs-vf*sn;
    *w=vr*sn+vf*cs;
}

void particle_velocity_ball(g05cae &rnd, real x, real y, real z, real fx, real fy, real fz, real cx, real cy, real cz,
                            real tau, real pfi, real dvr, real dvf, real dvz, real emax, real *u, real *v, real *w)
{
    real rxy, rxy2, rxyz, rxyz2, vx, vy, vz, fr, fi;
    real vr, vf;
    real cx1, cx2, cx3, cy1, cy2, cy3, cz1, cz2, cz3;

    x-=cx;
    y-=cy;
    z-=cz;
    rxy2=x*x+y*y;
    rxyz2=rxy2+z*z;
    rxy=sqrt(rxy2);
    rxyz=sqrt(rxyz2);

    if (rxy>1.0e-14 || rxyz>1.0e-14) { 
        cx1=x/rxyz;
        cx2=y/rxyz;
        cx3=z/rxyz;
        cy1=-x*z/(rxy*rxyz);
        cy2=-y*z/(rxy*rxyz);
        cy3=rxy/rxyz;
        cz1=y/rxy;
        cz2=-x/rxy;
        cz3=0.0;
    } else { 
        cx1=0.0; 
        cx2=0.0; 
        cx3=1.0;
        cy1=0.0; 
        cy2=0.0; 
        cy3=0.0;
        cz1=0.0; 
        cz2=0.0; 
        cz3=0.0;
    }

    fr=cx1*fx+cx2*fy+cx3*fz;

    if (fr>0.0) {
        fr=0.0;
    }

    vr=-0.5*tau*fr;
    vf=sqrt(-fr*(rxyz+0.25*tau*tau*fr));
    fi=2.0*PI*rnd.get();
    vx=vr;
    vy=vf*sin(fi);
    vz=vf*cos(fi);
    *u=cx1*vx+cy1*vy+cz1*vz;
    *v=cx2*vx+cy2*vy+cz2*vz;
    *w=cx3*vx+cy3*vy+cz3*vz;
}

void init_particles_velocity_z(int nx, int ny, int nz, int sx, int sy, int sz, real hx, real hy, real hz, real cx, real cy, real cz,
       real dvr, real dvf, real dvz, int wave, real tau, real emax, const real *fi, const real *fx, const real *fy, const real *fz, int np, Particle *p)
{
    g05dde gaurnd;
    size_t j;
    srand(145);

    for (j=0; j<np; j++) { 
        real x=p[j].x;
        real y=p[j].y;
        real z=p[j].z;

        real pfx, pfy, pfz;
        particle_force(x, y, z, nx, ny, nz, sx, sy, sz, hx, hy, hz, fx, fy, fz, &pfx, &pfy, &pfz);

        real pfi;
        particle_potential(x, y, z, nx, ny, nz, sx, sy, sz, hx, hy, hz, fi, &pfi);

        real u, v, w;
        particle_velocity_z(gaurnd, x, y, z, pfx, pfy, pfz, cx, cy, cz, tau, pfi, dvr, dvf, dvz, emax, wave, &u, &v, &w);

        p[j].u=u;
        p[j].v=v;
        p[j].w=w;
  }
}
void init_particles_velocity_y(int nx, int ny, int nz, int sx, int sy, int sz, real hx, real hy, real hz, real cx, real cy, real cz,
       real dvr, real dvf, real dvy, int wave, real tau, real emax, const real *fi, const real *fx, const real *fy, const real *fz, int np, Particle *p)
{
    g05dde gaurnd;
    size_t j;
    srand(145);

    for (j=0; j<np; j++) { 
        real x=p[j].x;
        real y=p[j].y;
        real z=p[j].z;

        real pfx, pfy, pfz;
        particle_force(x, y, z, nx, ny, nz, sx, sy, sz, hx, hy, hz, fx, fy, fz, &pfx, &pfy, &pfz);

        real pfi;
        particle_potential(x, y, z, nx, ny, nz, sx, sy, sz, hx, hy, hz, fi, &pfi);

        real u, v, w;
        particle_velocity_y(gaurnd, x, y, z, pfx, pfy, pfz, cx, cy, cz, tau, pfi, dvr, dvf, dvy, emax, wave, &u, &v, &w);

        p[j].u=u;
        p[j].v=v;
        p[j].w=w;
    }
}
void init_particles_velocity_x(int nx, int ny, int nz, int sx, int sy, int sz, real hx, real hy, real hz, real cx, real cy, real cz,
       real dvr, real dvf, real dvx, int wave, real tau, real emax, const real *fi, const real *fx, const real *fy, const real *fz, int np, Particle *p)
{
    g05dde gaurnd;
    size_t j;
    srand(145);

    for (j=0; j<np; j++) { 
        real x=p[j].x;
        real y=p[j].y;
        real z=p[j].z;

        real pfx, pfy, pfz;
        particle_force(x, y, z, nx, ny, nz, sx, sy, sz, hx, hy, hz, fx, fy, fz, &pfx, &pfy, &pfz);

        real pfi;
        particle_potential(x,y,z,nx,ny,nz,sx,sy,sz,hx,hy,hz,fi,&pfi);

        real u, v, w;
        particle_velocity_x(gaurnd, x, y, z, pfx, pfy, pfz, cx, cy, cz, tau, pfi, dvr, dvf, dvx, emax, wave, &u, &v, &w);

        p[j].u=u;
        p[j].v=v;
        p[j].w=w;
  }
}
void init_particles_velocity_ball(int nx, int ny, int nz, int sx, int sy, int sz, real hx, real hy, real hz, real cx, real cy, real cz,
       real dvr, real dvf, real dvz, real tau, real emax, const real *fi, const real *fx, const real *fy, const real *fz, int np,Particle *p)
{
    g05cae unirnd;
    size_t j;
    srand(145);

    for (j=0; j<np; j++) { 
        real x=p[j].x;
        real y=p[j].y;
        real z=p[j].z;

        real pfx, pfy, pfz;
        particle_force(x, y, z, nx, ny, nz, sx, sy, sz, hx, hy, hz, fx, fy, fz, &pfx, &pfy, &pfz);

        real pfi=0.0;
        real u, v, w;
        particle_velocity_ball(unirnd, x, y, z, pfx, pfy, pfz, cx, cy, cz, tau, pfi, dvr, dvf, dvz, emax, &u, &v, &w);

        p[j].u=u;
        p[j].v=v;
        p[j].w=w;
    }
}