#include <cstdio>
#include <string.h>
#include <math.h>
#include "ucenv.h"

#include <stdlib.h>
#include <unistd.h>

constexpr PI 3.14159265358979323846

struct task_parameters
{
    double x0;     // x left
    double x1;     // x right
    double r;      // iade acceleration parameter
    double g;      //
    double h;      // mesh step
    double tau;    // time step
    double lambda; // mesh ratio = tau/(h*h)
    double theta;  // method selection
    double omey;   // iade method parameter
    double omez;   // iade method parameter
    double a,b,c;  // matrix coefficients
    double d;      //
    double s;      //
    double u;      //
    double w;      //
    double eps;    // method convergence threshold
    int n;         // mesh size
};

double value_f(double x)
{
    return sin(PI*x);
}

double value_exact(double x, double t)
{
    return exp(-PI*PI*t)*sin(PI*x);
}

int min(int n1, int n2)
{
    return n1<n2 ? n1 : n2;
}

extern "C"
{

    static int ii;

    void c_empty(const InputDF &df) {}
    void c_empty2(const InputDF &df1, const InputDF &df2) {}

    void c_isready(const InputDF &df, OutputDF &df_yes)
    {
        df_yes.setValue(1);
    }

    void c_assign_int(int val,OutputDF &df)
    {
        df.setValue(val);
    }

    void c_assign_real(double val,OutputDF &df)
    {
        df.setValue(val);
    }

    void c_puts(const char *str)
    {
        puts(str);
    }

    void c_printf_d(const char* str, int val1)
    {
        printf(str, val1);
        fflush(stdout);
    }

    void c_printf_dd(const char* str, int val1, int val2)
    {
        printf(str, val1, val2);
        fflush(stdout);
    }

    void c_printf_ddd(const char* str, int val1, int val2, int val3)
    {
        printf(str, val1, val2, val3);
        fflush(stdout);
    }

    void c_printf_dddd(const char* str, int val1, int val2, int val3, int val4)
    {
        printf(str, val1, val2, val3, val4);
        fflush(stdout);
    }

    void c_printf_r(const char* str, double val1)
    {
        printf(str, val1);
        fflush(stdout);
    }

    void c_sscanf_d(const char *str, OutputDF &val1)
    {
        int v1;
        sscanf(str, "%d", &v1);
        val1.setValue(v1);
    }

    void c_sscanf_dd(const char *str, OutputDF &val1, OutputDF &val2)
    {
        int v1, v2;
        sscanf(str, "%d%d", &v1, &v2);
        val1.setValue(v1);
        val2.setValue(v2);
    }

    void c_sscanf_ddd(const char *str, OutputDF &val1, OutputDF &val2, OutputDF &val3)
    {
        int v1, v2, v3;
        sscanf(str,"%d%d%d", &v1, &v2, &v3);
        val1.setValue(v1);
        val2.setValue(v2);
        val3.setValue(v3);
    }

    void c_sscanf_dddd(const char *str, OutputDF &val1, OutputDF &val2, OutputDF &val3, OutputDF &val4)
    {
        int v1, v2, v3, v4;
        sscanf(str,"%d%d%d%d", &v1, &v2, &v3, &v4);
        val1.setValue(v1);
        val2.setValue(v2);
        val3.setValue(v3);
        val4.setValue(v4);
    }

    void c_init_fragment_size_start(int n, int nf, int nfi, OutputDF &df_nfsR, OutputDF &df_nfsB, OutputDF &df_nf0R, OutputDF &df_nf0B)
    {   // n  - mesh size, nf - number of fragments, nfi - current fragment number
        int nn=(n+2*nf-1)/(2*nf);     // max fragment size (one colour, without borders) (always even)
        int n0=2*nn*nfi;              // global index of x[0] = xR[0] (always even)
        int n1=1+n0;                // global index of x[1] = xB[0] (always odd)
        int n2=min(2*nn*(nfi+1),n);   // global index of x[nfs] =(if nfi!=nf-1)= xR[nfsR]
        int n3=n2+1;                // global index of x[nfs] =(if nfi!=nf-1)= xR[nfsR]
        int nfs=n2-n1+1;          // local mesh size (without borders)
        int nfsB =nfs/2;               // number of local Black cells (without right border)
        int nfsR = nfs - nfsB;          // number of local Red cells (without left border)
        df_nf0R.setValue(n0);
        df_nf0B.setValue(n1);
        df_nfsR.setValue(nfsR);
        df_nfsB.setValue(nfsB);
    }

    void c_init_parameters(int n, OutputDF &df_param)
    {
        double x0=0.0;      // x left
        double x1=1.0;      // x right
        double r=1.4;       // iade acceleration parameter
        double lambda=0.5;  // mesh ratio = tau/(h*h)
        double theta=1.0;   // method: implicit O(h^2 + tau  )

        double omey=1.0;    // iade method parameter
        double omez=1.0;    // iade method parameter
        double eps=1.0e-15; // method convergence threshold

        double h=(x1-x0)/(n+1);
        double b=-lambda*theta;
        double g=(6.0+r)/6.0;
        double u=6.0*b/5.0;

        struct task_parameters *p=(struct task_parameters *)df_param.create(sizeof(struct task_parameters));
        p->x0=x0;
        p->x1=x1;
        p->r=r;
        p->g=g;
        p->h=h;
        p->tau=lambda*h*h;
        p->lambda=lambda;
        p->theta=theta;
        p->omey=omey;
        p->omez=omez;
        p->a=1.0+2.0*lambda*theta;
        p->b=b;
        p->c=b;
        p->d=1+r;
        p->s=r-g;
        p->u=u;
        p->w=-g*u;
        p->eps=eps;
        p->n=n;
    }

    void c_print_parameters(const InputDF &df_param)
    {
        assert(df_param.getSize()==sizeof(struct task_parameters));
        const struct task_parameters *p=df_param.getData<struct task_parameters>();
        printf("%le %le %le %le\n%le %le %le %le\n%le %le %le %le\n%le %le %le %le\n%le %le %d\n",
               p->x0, p->x1, p->r, p->g, p->h, p->tau, p->lambda, p->theta,
               p->omey, p->omez, p->a, p->b, p->c, p->d, p->s, p->u, p->w, p->eps, p->n);
    }

    void c_get_eps(const InputDF &df_param, OutputDF &df_eps)
    {
        assert(df_param.getSize()==sizeof(struct task_parameters));
        const struct task_parameters *p=df_param.getData<struct task_parameters>();
        df_eps.setValue(p->eps);
    }

    void c_init_e_l(int nfsR,int nfsB,int nfi,const InputDF &df_param,double eprev,
                    OutputDF &df_eR,OutputDF &df_eB,OutputDF &df_lR,OutputDF &df_lB,OutputDF &df_enext)
    {
        assert(df_param.getSize()==sizeof(struct task_parameters));
        const struct task_parameters *p=df_param.getData<struct task_parameters>();
        double *eR=df_eR.create<double>(nfsR+1);
        double *lR=df_lR.create<double>(nfsR+1);
        double *eB=df_eB.create<double>(nfsB+1);
        double *lB=df_lB.create<double>(nfsB+1);
        double u=p->u;
        double a=p->a;
        double c=p->c;
        int i;

        if (nfi==0) {
            lR[0]=0.0;
            eB[0]=6.0*(a-1.0)/5.0;
            lB[0]=6.0*c/(6.0-eB[0]);
        } else {
            lR[0]=6.0*c/(6.0-eprev);
            eB[0]=6.0*(a-1.0+lR[0]*u/6.0)/5.0;
            lB[0]=6.0*c/(6.0-eB[0]);
        }

        for (i=1; i<=nfsB; i++) {
            eR[i]=6.0*(a-1.0+lB[i-1]*u/6.0)/5.0;
            lR[i]=6.0*c/(6.0-eR[i]);
            eB[i]=6.0*(a-1.0+lR[i]*u/6.0)/5.0;
            lB[i]=6.0*c/(6.0-eB[i]);
        }

        df_enext.setValue(eR[nfsR]);
    }

    void c_init_v(int nfs, int nf0, const InputDF &df_param, const InputDF &df_l, OutputDF &df_v)
    {
        assert(df_param.getSize()==sizeof(struct task_parameters));
        const struct task_parameters *p=df_param.getData<struct task_parameters>();
        assert(df_l.getSize()==(nfs+1)*sizeof(double));
        const double *l=df_l.getData<double>();
        double *v=df_v.create<double>(nfs+1);
        double g=p->g;
        int i;

        if (nf0%2==0) {
            for (i=0; i<=nfs; i++) {
                v[i]=-g*l[i]; // Red
            }
        } else {
            for (i=0; i<=nfs-1; i++) {
                v[i]=-g*l[i]; // Black
            }
        }
    }

    void c_init_exact(int nfs, int nf0, const InputDF &df_param, int it, OutputDF &df_exact)
    {
        assert(df_param.getSize()==sizeof(struct task_parameters));
        const struct task_parameters *p=df_param.getData<struct task_parameters>();
        double *x=df_exact.create<double>(nfs+1);
        double x0=p->x0;
        double h=p->h;
        double t=p->tau*it;
        int i;

        for (i=0; i<=nfs; i++) {
            x[i]=value_exact(x0+(nf0+2*i)*h,t);
        }
    }

    void c_init_s(int nfs, int nf0, const InputDF &df_param, const InputDF &df_e, OutputDF &df_s)
    {
        assert(df_param.getSize()==sizeof(struct task_parameters));
        const struct task_parameters *p=df_param.getData<struct task_parameters>();
        assert(df_e.getSize()==(nfs+1)*sizeof(double));
        const double *e=df_e.getData<double>();
        double *s=df_s.create<double>(nfs+1);
        double r=p->r;
        double g=p->g;
        int i;

        if (nf0%2==0) {
            for (i=1; i<=nfs; i++) {
                s[i]=r-g*e[i]; // Red
            }
        } else {
            for (i=0; i<=nfs-1; i++) {
                s[i]=r-g*e[i]; // Black
            }
        }
    }

    void c_init_d(int nfs, int nf0, const InputDF &df_param, const InputDF &df_e, OutputDF &df_d)
    {
        assert(df_param.getSize()==sizeof(struct task_parameters));
        const struct task_parameters *p=df_param.getData<struct task_parameters>();
        assert(df_e.getSize()==(nfs+1)*sizeof(double));
        const double *e=df_e.getData<double>();
        double *d=df_d.create<double>(nfs+1);
        double r=p->r;
        int i;

        if (nf0%2==0) {
            for (i=1; i<=nfs; i++) {
                d[i]=r+e[i]; // Red
            }
        } else {
            for (i=0; i<=nfs-1; i++) {
                d[i]=r+e[i]; // Black
            }
        }
    }

    void c_init_x(int nfs, int nf0, const InputDF &df_param, OutputDF &df_x)
    {
        assert(df_param.getSize()==sizeof(struct task_parameters));
        const struct task_parameters *p=df_param.getData<struct task_parameters>();
        double *x=df_x.create<double>(nfs+1);
        double x0=p->x0;
        double x1=p->x1;
        double h=p->h;
        double tau=p->tau;
        int n=p->n;
        int i;

        for (i=0; i<=nfs; i++) {
            x[i]=value_f(x0+(nf0+2*i)*h);
        }

        if (nf0==0) {
            x[0]=value_exact(x0,0.0);
        }

        if (nf0+nfs==n+1) {
            x[nfs]=value_exact(x1,0.0);
        }
    }

    void c_get_init_y(int nfsR, int nfsB, const InputDF &df_param, const InputDF &df_xR, const InputDF &df_xB, const InputDF &df_sB, OutputDF &df_y_value, OutputDF &df_y_left)
    {
        assert(df_param.getSize()==sizeof(struct task_parameters));
        const struct task_parameters *p=df_param.getData<struct task_parameters>();
        assert(df_xR.getSize()==(nfsR+1)*sizeof(double));
        assert(df_xB.getSize()==(nfsB+1)*sizeof(double));
        assert(df_sB.getSize()==(nfsB+1)*sizeof(double));
        const double *xR=df_xR.getData<double>();
        const double *xB=df_xB.getData<double>();
        const double *sB=df_sB.getData<double>();
        double lambda=p->lambda;
        double theta=p->theta;
        double d=p->d;
        double w=p->w;
        double x_0=xR[0];
        double x_1=xB[0];
        double x_2=xR[1];
        double s_1=sB[0];
        double f_1=lambda*(1.0-theta)*(x_0+x_2)+(1.0-2.0*lambda*(1.0-theta))*x_1;
        double y=(s_1*x_1+w*x_2+f_1)/d;
        df_y_value.setValue(y);
        df_y_left.setValue(x_0);
    }

    void c_init_y(int nfs, int nf0, const InputDF &df_param, double value, double value_left, OutputDF &df_y)
    {
        assert(df_param.getSize()==sizeof(struct task_parameters));
        const struct task_parameters *p=df_param.getData<struct task_parameters>();
        double *y=df_y.create<double>(nfs+1);
        int i;

        for (i=0; i<=nfs; i++) {
            y[i]=value;
        }

        if (nf0==0) {
            y[0]=value_left;
        }
    }

    void c_init_rhs(int nfsR, int nfsB, const InputDF &df_param, const InputDF &df_xR, const InputDF &df_xB, OutputDF &df_fR, OutputDF &df_fB)
    {
        assert(df_param.getSize()==sizeof(struct task_parameters));
        const struct task_parameters *p=df_param.getData<struct task_parameters>();
        assert(df_xR.getSize()==(nfsR+1)*sizeof(double));
        assert(df_xB.getSize()==(nfsB+1)*sizeof(double));
        const double *xR=df_xR.getData<double>();
        const double *xB=df_xB.getData<double>();
        double *fR=df_fR.create<double>(nfsR+1);
        double *fB=df_fB.create<double>(nfsB+1);
        double lambda=p->lambda;
        double theta=p->theta;
        int i;

        for (i=1; i<=nfsR; i++) {
            fR[i]=lambda*(1.0-theta)*(xB[i-1]+xB[i])+(1.0-2.0*lambda*(1.0-theta))*xR[i]; // Red
        }

        for (i=0; i<=nfsB-1; i++) {
            fB[i]=lambda*(1.0-theta)*(xR[i]+xR[i+1])+(1.0-2.0*lambda*(1.0-theta))*xB[i]; // Black
        }
    }

    void c_copy(const InputDF &df_in, OutputDF &df_out)
    {
        df_out.copy(df_in);
    }

    void c_dset(int nn, double value, OutputDF &df_out)
    {
        assert(nn>=0);
        double *out=df_out.create<double>(nn);
        int i;

        for (i=0; i<nn; i++) {
            out[i]=value;
        }
    }

    void c_iadeR(int nfsR, int nfsB, const InputDF &df_param,
                 const InputDF &df_xR, const InputDF &df_xB,  const InputDF &df_yR, const InputDF &df_yB, const InputDF &df_fR,
                 const InputDF &df_sR, const InputDF &df_lB, const InputDF &df_dR, const InputDF &df_vB,
                 OutputDF &df_xR_new, OutputDF &df_yR_new)
    {
        assert(df_param.getSize()==sizeof(struct task_parameters));
        const struct task_parameters *p=df_param.getData<struct task_parameters>();
        assert(df_xR.getSize()==(nfsR+1)*sizeof(double));
        assert(df_xB.getSize()==(nfsB+1)*sizeof(double));
        assert(df_yR.getSize()==(nfsR+1)*sizeof(double));
        assert(df_yB.getSize()==(nfsB+1)*sizeof(double));
        assert(df_fR.getSize()==(nfsR+1)*sizeof(double));
        assert(df_sR.getSize()==(nfsR+1)*sizeof(double));
        assert(df_lB.getSize()==(nfsB+1)*sizeof(double));
        assert(df_dR.getSize()==(nfsR+1)*sizeof(double));
        assert(df_vB.getSize()==(nfsB+1)*sizeof(double));
        const double *xR=df_xR.getData<double>();
        const double *xB=df_xB.getData<double>();
        const double *yR=df_yR.getData<double>();
        const double *yB=df_yB.getData<double>();
        const double *fR=df_fR.getData<double>();
        const double *sR=df_sR.getData<double>();
        const double *lB=df_lB.getData<double>();
        const double *dR=df_dR.getData<double>();
        const double *vB=df_vB.getData<double>();
        double *xnR=df_xR_new.create<double>(nfsR+1);
        double *ynR=df_yR_new.create<double>(nfsR+1);
        double omey=p->omey;
        double omez=p->omez;
        double d=p->d;
        double w=p->w;
        double s=p->s;
        double g=p->g;
        double u=p->u;
        int i;
        ynR[0]=yR[0];
        xnR[0]=xR[0];

        for (i=1; i<=nfsR; i++) {
            ynR[i]=yR[i]+omey*(-d*yR[i]-lB[i-1]*yB[i-1]+(sR[i]*xR[i]+w*xB[i]+fR[i]))/d;
        }

        for (i=1; i<=nfsR; i++) {
            xnR[i]=xR[i]+omez*(-dR[i]*xR[i]+(vB[i-1]*yB[i-1]+s*ynR[i]+g*fR[i])-u*xB[i])/dR[i];
        }
    }

    void c_iadeB(int nfsR, int nfsB, const InputDF &df_param,
                 const InputDF &df_xR, const InputDF &df_xB, const InputDF &df_yR, const InputDF &df_yB, const InputDF &df_fB,
                 const InputDF &df_sB, const InputDF &df_lR, const InputDF &df_dB, const InputDF &df_vR,
                 OutputDF &df_xB_new, OutputDF &df_yB_new)
    {
        assert(df_param.getSize() == sizeof(struct task_parameters));
        const struct task_parameters *p = df_param.getData<struct task_parameters>();
        assert(df_xR.getSize()==(nfsR+1)*sizeof(double));
        assert(df_xB.getSize()==(nfsB+1)*sizeof(double));
        assert(df_yR.getSize()==(nfsR+1)*sizeof(double));
        assert(df_yB.getSize()==(nfsB+1)*sizeof(double));
        assert(df_fB.getSize()==(nfsB+1)*sizeof(double));
        assert(df_sB.getSize()==(nfsB+1)*sizeof(double));
        assert(df_lR.getSize()==(nfsR+1)*sizeof(double));
        assert(df_dB.getSize()==(nfsB+1)*sizeof(double));
        assert(df_vR.getSize()==(nfsR+1)*sizeof(double));
        const double *xR=df_xR.getData<double>();
        const double *xB=df_xB.getData<double>();
        const double *yR=df_yR.getData<double>();
        const double *yB=df_yB.getData<double>();
        const double *fB=df_fB.getData<double>();
        const double *sB=df_sB.getData<double>();
        const double *lR=df_lR.getData<double>();
        const double *dB=df_dB.getData<double>();
        const double *vR=df_vR.getData<double>();
        double *xnB=df_xB_new.create<double>(nfsB+1);
        double *ynB=df_yB_new.create<double>(nfsB+1);
        double omey=p->omey;
        double omez=p->omez;
        double d=p->d;
        double w=p->w;
        double s=p->s;
        double g=p->g;
        double u=p->u;
        int i;
        ynB[nfsB]=yB[nfsB];
        xnB[nfsB]=xB[nfsB];

        for (i=0; i<=nfsB-1; i++) {
            ynB[i]=yB[i]+omey*(-d*yB[i]-lR[i]*yR[i]+(sB[i]*xB[i]+w*xR[i+1]+fB[i]))/d;
        }

        for (i=0; i<=nfsB-1; i++) {
            xnB[i]=xB[i]+omez*(-dB[i]*xB[i]+(vR[i]*yR[i]+s*ynB[i]+g*fB[i])-u*xR[i+1])/dB[i];
        }
    }

    void c_init_r(int nfsR, int nfsB, int nf0R, int nf0B, const InputDF &df_param, const InputDF &df_xR, const InputDF &df_xB, const InputDF &df_fR, const InputDF &df_fB, OutputDF &df_rR, OutputDF &df_rB)
    {
        assert(df_param.getSize()==sizeof(struct task_parameters));
        const struct task_parameters *p=df_param.getData<struct task_parameters>();
        assert(df_xR.getSize()==(nfsR+1)*sizeof(double));
        assert(df_xB.getSize()==(nfsB+1)*sizeof(double));
        const double *xR=df_xR.getData<double>();
        const double *xB=df_xB.getData<double>();
        const double *fR=df_fR.getData<double>();
        const double *fB=df_fB.getData<double>();
        double *rR=df_rR.create<double>(nfsR+1);
        double *rB=df_rB.create<double>(nfsB+1);
        double a=p->a;
        double b=p->b;
        double c=p->c;
        int n=p->n;
        int i;

        if (nf0R==0) {
            rR[0]=0.0;
        }

        for (i=1; i<=nfsR; i++) {
            rR[i]=fR[i]-(b*xB[i-1]+a*xR[i]+c*xB[i]);
        }

        for (i=0; i<=nfsB-1; i++) {
            rB[i]=fB[i]-(b*xR[i]+a*xB[i]+c*xR[i+1]);
        }

        if (nf0B+nfsB==n+1) {
            rB[nfsB]=0.0;
        }
    }

    void c_cgR(int nfsR, int nfsB, const InputDF &df_param,
               const InputDF &df_xR, const InputDF &df_rR, const InputDF &df_zR, const InputDF &df_zB,
               OutputDF &df_xR_new, OutputDF &df_rR_new, OutputDF &df_zR_new)
    {
        assert(df_param.getSize()==sizeof(struct task_parameters));
        const struct task_parameters *p=df_param.getData<struct task_parameters>();
        assert(df_xR.getSize()==(nfsR+1)*sizeof(double));
        assert(df_rR.getSize()==(nfsR+1)*sizeof(double));
        assert(df_zR.getSize()==(nfsR+1)*sizeof(double));
        assert(df_zB.getSize()==(nfsB+1)*sizeof(double));
        const double *xR=df_xR.getData<double>();
        const double *rR=df_rR.getData<double>();
        const double *zR=df_zR.getData<double>();
        const double *zB=df_zB.getData<double>();
        double *xRn=df_xR_new.create<double>(nfsR+1);
        double *rRn=df_rR_new.create<double>(nfsR+1);
        double *zRn=df_zR_new.create<double>(nfsR+1);
        double a=p->a;
        double b=p->b;
        double c=p->c;
        int i;
        xRn[0]=xR[0];

        for (i=1; i<=nfsR; i++) {
            if (fabs(rR[i])>1.0e-15) {
                double p=b*zB[i-1]+a*zR[i]+c*zB[i];
                double rRi2=rR[i]*rR[i];
                double alpha=rRi2/(zR[i]*p);
                xRn[i]=xR[i]+alpha*zR[i];
                double rer=rR[i]-alpha*p;
                rRn[i]=rer;
                double beta=rer*rer/rRi2;
                zRn[i]=rer+beta*zR[i];
            } else {
                xRn[i]=xR[i];
                rRn[i]=rR[i];
                zRn[i]=zR[i];
            }
        }
    }

    void c_cgB(int nfsR, int nfsB, const InputDF &df_param,
               const InputDF &df_xB, const InputDF &df_rB, const InputDF &df_zR, const InputDF &df_zB,
               OutputDF &df_xB_new, OutputDF &df_rB_new, OutputDF &df_zB_new)
    {
        assert(df_param.getSize()==sizeof(struct task_parameters));
        const struct task_parameters *p=df_param.getData<struct task_parameters>();
        assert(df_xB.getSize()==(nfsB+1)*sizeof(double));
        assert(df_rB.getSize()==(nfsB+1)*sizeof(double));
        assert(df_zR.getSize()==(nfsR+1)*sizeof(double));
        assert(df_zB.getSize()==(nfsB+1)*sizeof(double));
        const double *xB=df_xB.getData<double>();
        const double *rB=df_rB.getData<double>();
        const double *zR=df_zR.getData<double>();
        const double *zB=df_zB.getData<double>();
        double *xBn=df_xB_new.create<double>(nfsB+1);
        double *rBn=df_rB_new.create<double>(nfsB+1);
        double *zBn=df_zB_new.create<double>(nfsB+1);
        double a=p->a;
        double b=p->b;
        double c=p->c;
        int i;

        for (i=0; i<=nfsB-1; i++) {
            if (fabs(rB[i])>1.0e-15) {
                double p=b*zR[i]+a*zB[i]+c*zR[i+1];
                double rBi2=rB[i]*rB[i];
                double alpha=rBi2/(zB[i]*p);
                xBn[i]=xB[i]+alpha*zB[i];
                double rer=rB[i]-alpha*p;
                rBn[i]=rer;
                double beta=rer*rer/rBi2;
                zBn[i]=rer+beta*zB[i];
            } else {
                xBn[i]=xB[i];
                rBn[i]=rB[i];
                zBn[i]=zB[i];
            }
        }

        xBn[nfsB]=xB[nfsB];
    }

    void c_get_B_left_border(int nfsB, const InputDF &df_xB, OutputDF &df_xleft)
    {
        assert(df_xB.getSize()==(nfsB+1)*sizeof(double));
        const double *xB=df_xB.getData<double>();
        df_xleft.setValue(xB[0]);
    }

    void c_get_R_right_border(int nfsR, const InputDF &df_xR, OutputDF &df_xright)
    {
        assert(df_xR.getSize()==(nfsR+1)*sizeof(double));
        const double *xR=df_xR.getData<double>();
        df_xright.setValue(xR[nfsR]);
    }

    void c_set_B_right_border(int nfsB,const InputDF &df_xB,double xleft,OutputDF &df_xB_new)
    {
        assert(df_xB.getSize()==(nfsB+1)*sizeof(double));
        const double *xB=df_xB.getData<double>();
        double *xnB=df_xB_new.create<double>(nfsB+1);
        int i;

        for (i=0; i<=nfsB-1; i++) {
            xnB[i]=xB[i];
        }

        xnB[nfsB]=xleft;
    }

    void c_set_R_left_border(int nfsR, const InputDF &df_xR, double xright, OutputDF &df_xR_new)
    {
        assert(df_xR.getSize()==(nfsR+1)*sizeof(double));
        const double *xR=df_xR.getData<double>();
        double *xnR=df_xR_new.create<double>(nfsR+1);
        int i;
        xnR[0]=xright;

        for (i=1; i<=nfsR; i++) {
            xnR[i]=xR[i];
        }
    }

    void c_delta_norma_inf(const InputDF &df_x1, const InputDF &df_x2, OutputDF &df_result)
    {
        assert(df_x1.getSize()==df_x2.getSize());
        int nn = df_x1.getSize()/sizeof(double);
        const double *x1=df_x1.getData<double>();
        const double *x2=df_x2.getData<double>();
        double s=0.0;
        int i;

        for (i=0; i<nn; i++) {
            double y=fabs(x1[i]-x2[i]);

            if (y>s) {
                s=y;
            }
        }

        df_result.setValue(s);
    }

    void c_dmax3(double x1, double x2, double x3, OutputDF &df_max)
    {
        double r=x1>x2 ? x1 : x2;
        r=r>x3 ? r : x3;
        df_max.setValue(r);
    }

    void c_save_file(const InputDF &df, char *name, int it)
    {
        char fn[256];
        sprintf(fn, name, it);
        FILE *f = fopen(fn, "w");

        if (f==NULL) {
            printf("c_save_file_d(): Can't open file: %s\n", fn);
            fflush(stdout);
            return;
        }

        const double *x=df.getData<double>();
        int nn=df.getSize()/sizeof(double);
        int i;

        for (i=0; i<nn; i++) {
            fprintf(f,"%.18le\n", x[i]);
        }

        fclose(f);
    }

    void c_save_file_seq(int nfsR, int nfsB, int nfi, int nf, const InputDF &df_xR, const InputDF &df_xB, char *name,int it, int prev, OutputDF &df_next)
    {
        assert(df_xR.getSize()==(nfsR+1)*sizeof(double));
        assert(df_xB.getSize()==(nfsB+1)*sizeof(double));
        char fn[256];
        sprintf(fn, name, it);
        FILE *f;

        if (nfi==0) {
            f=fopen(fn, "w");
        } else {
            f=fopen(fn, "a");
        }

        if (f==NULL) {
            printf("c_save_file_d(): Can't open file: %s\n", fn);
            fflush(stdout);
            return;
        }

        const double *xR=df_xR.getData<double>();
        const double *xB=df_xB.getData<double>();
        int i;

        if (nfi==0 && nfsR>0) {
            fprintf(f,"%.18le\n", xR[0]);
        }

        for (i=1; i<=nfsR; i++) {
            fprintf(f,"%.18le\n%.18le\n", xB[i-1], xR[i]);
        }

        if (nfi==nf-1 && nfsB==nfsR) {
            fprintf(f,"%.18le\n", xB[nfsB]);
        }

        fclose(f);
        df_next.setValue(prev);
    }
}