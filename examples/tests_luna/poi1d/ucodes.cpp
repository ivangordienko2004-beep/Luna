#include <cstdio>
#include <cstring>
#include <cmath>
#include "ucenv.h"
#include "pm.h"

extern "C" 
{

    void reset_file(const char* path)
    {
        FILE *fl=fopen(path, "w");

        if (fl==NULL) { 
            printf("reset_file: Can't open file: %s\n", path); 
            fflush(stdout); 
            return; 
        }

	      fclose(fl);
    }

    void save1(const double* Fi, const char* path, int i0, int j0, int k0, int nx1, int ny, int nz)
    {
	      FILE *fl=fopen(path, "a");

        if (fl==NULL) { 
            printf("save1: Can't open file: %s\n", path); 
            fflush(stdout); 
            return; 
        }

	      for (int i=0; i<nx1; i++) {
		        for (int j=0; j<ny; j++) {
			          for (int k=0; k<nz; k++) {
				            fprintf(fl, "%d\t%d\t%d\t%lf\n", i0+i, j0+j, k0+k, FI(i, j, k));
                }
            }
        }

	      fclose(fl);
    }

    void save(InputDF& fi, int rank)
    {
	      printf("SAVE: %d\n", rank);
	      return;
	      const double* Fi=fi.getData<double>();
	      int I=rank*NX/FG_COUNT-1;

	      if (rank==0) {
		        reset_file("fi.txt");
	      }

	      save1(Fi, "fi.txt", I+1, 0, 0, nx, NY, NZ);
    }

    void show(int t, double diff)
    {
	      printf("%d: %lf\n", t, diff);
    }

    void rinit(OutputDF &df, double val)
    {
	      df.setValue(val);
    }

    void iset(OutputDF &df, int val)
    {
	      df.setValue(val);
    }

    void calc_max(double a, double b, OutputDF &c)
    {
	      c.setValue(a>b? a: b);
    }

    double ro(double x, double y, double z)
    {
	      if (x*x+y*y+z*z < 1*1) {
		        return 1;
	      } else {
		        return 0;
	      }
    }

    void init_ro(OutputDF& out_ro, int rank)
    {
	      assert(NX%FG_COUNT==0);
	      assert(rank<FG_COUNT);

	      double *Ro=out_ro.create<double>((nx+2)*NY*NZ, 0);
	      int I=rank*NX/FG_COUNT-1;

	      for (int i=0; i<nx; i++) {
		        for (int j=0; j<NY; j++) {
			          for (int k=0; k<NZ; k++) {
				            RO(i, j, k)=ro((i+I)*hx-cx, j*hy-cy, k*hz-cz);
                }
            }
        }

    }

    void init_fi(OutputDF& fi, OutputDF& u, OutputDF& d, int rank)
    {
	      double *Fi=fi.create<double>((nx+2)*NY*NZ, 0.0);
	      poisson_edge_simple(Fi, rank);

	      double *U=u.create<double>(NY*NZ);
	      memcpy(U, &FI(1, 0, 0), sizeof(double)*NY*NZ);

	      double *D=d.create<double>(NY*NZ);
	      memcpy(D, &FI(nx, 0, 0), sizeof(double)*NY*NZ);
    }

    void poi_part(InputDF& ro, InputDF& fi, InputDF& u, InputDF& d, int rank,
		    OutputDF& out_fi, OutputDF& out_u, OutputDF& out_d,
		    OutputDF& out_lmax)
    {
	      double *Fi=out_fi.create<double>((nx+2)*NY*NZ);
	      const double *old_Fi=fi.getData<double>();
	      memcpy(Fi, old_Fi, sizeof(double)*(nx+2)*NY*NZ);
	      memcpy(Fi, u.getData<double>(), sizeof(double)*NY*NZ);
	      memcpy(&FI(nx+1, 0, 0), d.getData<double>(), sizeof(double)*NY*NZ);

	      double lmax;
	      poisson_zeidel(Fi, ro.getData<double>(), rank, lmax);

	      double *U=out_u.create<double>(NY*NZ);
	      memcpy(U, &FI(1, 0, 0), sizeof(double)*NY*NZ);

	      double *D=out_d.create<double>(NY*NZ);
	      memcpy(D, &FI(nx, 0, 0), sizeof(double)*NY*NZ);

	      out_lmax.setValue(lmax);
    }

    void poisson_zeidel(double *Fi, const double *Ro, int rank, double& loc_max)
    { 
        int i, k, l, n;
        double s,ds;
        const double hx2=1.0/(hx*hx),
                  hy2=1.0/(hy*hy),
                  hz2=1.0/(hz*hz);
        const double w=1.2;
        const double koef=0.5*w/(hx2+hy2+hz2);
        loc_max=0;

	      int i0=rank==0? 2: 1;
	      int i1=rank==FG_COUNT-1? nx: nx+1;

        for (i=i0; i<i1; i++) {
            for (k=1; k<NY-1; k++) {
                for (l=1; l<NZ-1; l++) {
                    s=koef*((FI(i-1, k, l)+FI(i+1, k, l))*hx2+
                    (FI(i, k-1, l)+FI(i, k+1, l))*hy2+
                    (FI(i, k, l-1)+FI(i, k, l+1))*hz2-4*PI*RO(i, k, l))+(1-w)*FI(i, k, l);
                    ds=fabs(FI(i, k, l)-s);

                    if (ds>loc_max) {
                        loc_max=ds;
                    }
                    FI(i, k, l)=s;
                }
	          }
	      }
    }

    void poisson_edge_simple(double *Fi, int rank)
    { 
        double x, y, z, x2, y2, z2, x2py2, x2pz2, r;
        int i, k, l;
	      int I=rank*NX/FG_COUNT-1;

        if (rank==0) {
            x=-0.5*hx-cx;
            x2=x*x;

            for (k=0; k<NY; k++) { 
                y=(k-0.5)*hy-cy;
                x2py2=x2+y*y;

                for (l=0; l<NZ; l++) { 
                    z=(l-0.5)*hz-cz;
                    r=sqrt(x2py2+z*z);
                    FI(1, k, l)=-PM/r;
                }
            }
        }
  
        if (rank==FG_COUNT-1) {
            x=XN+0.5*hx-cx;
            x2=x*x;

            for (k=0; k<NY; k++) { 
                y=(k-0.5)*hy-cy;
                x2py2=x2+y*y;

                for (l=0; l<NZ; l++) { 
                    z=(l-0.5)*hz-cz;
                    r=sqrt(x2py2+z*z);
                    FI(nx, k, l)=-PM/r;
                }
            }
        }
  
        y=-0.5*hy-cy;
        y2=y*y;

        for (i=I; i<I+nx+2; i++) { 
            x=(i-0.5)*hx-cx;
            x2py2=x*x+y2;

            for (l=0; l<NZ; l++) { 
                z=(l-0.5)*hz-cz;
                r=sqrt(x2py2+z*z);
                FI(i-I, 0, l)=-PM/r;
            }
        }
  
        y=YN+0.5*hy-cy;
        y2=y*y;

        for (i=I; i<I+nx+2; i++) { 
            x=(i-0.5)*hx-cx;
            x2py2=x*x+y2;

            for (l=0; l<NZ; l++) { 
                z=(l-0.5)*hz-cz;
                r=sqrt(x2py2+z*z);
                FI(i-I, NY-1, l)=-PM/r;
            }
        }
  
        z=-0.5*hz-cz;
        z2=z*z;

        for (i=I; i<I+nx+2; i++) { 
            x=(i-0.5)*hx-cx;
            x2pz2=x*x+z2;

            for (k=0; k<NY; k++) { 
                y=(k-0.5)*hy-cy;
                r=sqrt(x2pz2+y*y);
                FI(i-I, k, 0)=-PM/r;
            }
        }
  
        z=ZN+0.5*hz-cz;
        z2=z*z;

        for (i=I; i<I+nx+2; i++) { 
            x=(i-0.5)*hx-cx;
            x2pz2=x*x+z2;

            for (k=0; k<NY; k++) { 
                y=(k-0.5)*hy-cy;
                r=sqrt(x2pz2+y*y);
                FI(i-I, k, NZ-1)=-PM/r;
            }
        }
    }
}