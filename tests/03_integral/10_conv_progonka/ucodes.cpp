#include "common.h"
#include <fstream>
#include <iostream>
#include <stdlib.h>
//#include <stdio.h>
#include <math.h>
#include <string.h>
#include <sstream>
#include "ucenv.h"
#include "common.h"
using namespace std;

const char* const CONFIG_PATH_IN_PAR="input3D/DVPAR.txt";
extern "C" {
void calcCoef(int n, double *&a, double *&b, double *&c, double *&f, double *&alfa, double *&beta);
int getSize(int n, int *&dim);
double cheksum(int rnx, int rny, int rnz, int i0, int iend, int j0, int jend, int k0, int kend, double *&u);
void writeData(char numb[], int rank, int rnx, int rny, int rnz, int i0, int iend, int j0, int jend, int k0, int kend, const double *u);

void c_rinit(double val, OutputDF &df) {
    df.setValue(val);
//    printf("c_rinit: %lf --> %s, size: %d\n", val, df.getName().c_str(), (int)df.getSize());
}

void c_intinit(int val, OutputDF &df) {
    df.setValue(val);
//    printf("c_rinit: %d --> %s, size: %d\n", val, df.getName().c_str(), (int)df.getSize());
}

void c_vinit(OutputDF &df){
    df.create(sizeof(double)*(1));
    double * u = df.getData<double>();
    u[0]=0;
}

void getFG_Size(const char *x, OutputDF &size_x_out, OutputDF &size_y_out, OutputDF &size_z_out, OutputDF &fg_size){
    int val;
    if(strlen(x) > 0) {
        val=atoi(x);
        if (val==0) {
            val=4;
        }
    } else{
        val=4;
    }
    fg_size.setValue(val);

    int size_x,size_y,size_z;
    ifstream inp_f(CONFIG_PATH_IN_PAR);
    if(!inp_f) {
        printf("File not found\n");
        abort();
    }
    if (inp_f.is_open()){
        int nx,ny,nz;
        double tau,T;
        inp_f >>nx>>ny>>nz>>tau>>T>>size_x>>size_y>>size_z;
        inp_f.close();
    }
    size_x_out.setValue(size_x);
    size_y_out.setValue(size_y);
    size_z_out.setValue(size_z);

}

void loadData(int rank, int size, OutputDF &params,
              OutputDF &rank_x_out,OutputDF &rank_y_out, OutputDF &rank_z_out,
              OutputDF &dim_x_out, OutputDF &dim_y_out, OutputDF &dim_z_out, OutputDF &u_out){
    str_params & par = *params.create<str_params>(1);

    int cursize=cbrt(size);
    ifstream inp_f(CONFIG_PATH_IN_PAR);
    if(!inp_f) {
        printf("File not found\n");
        abort();
    }
    if (inp_f.is_open()){
        inp_f >>par.nx>>par.ny>>par.nz>>par.tau>>par.T>>par.size_x>>par.size_y>>par.size_z>>par.tprint;
        inp_f.close();
        par.hx=1.0/(par.nx);
        par.hy=1.0/(par.ny);
        par.hz=1.0/(par.nz);
        par.hx2=par.hx*par.hx;
        par.hy2=par.hy*par.hy;
        par.hz2=par.hz*par.hz;
        int size_x=par.size_x;
        int size_y=par.size_y;
        int size_z=par.size_z;
//        if (size!=size_x*size_y*size_z) {
//            fprintf(stderr,"The multiplication is not equal total size %d\n",size);
//            abort();
//        }
        par.rnx=(par.nx+1)/size_x;
        par.rny=(par.ny+1)/size_y;
        par.rnz=(par.nz+1)/size_z;
        dim_x_out.create(sizeof(int)*(size_x+1));
        int * dim_x= dim_x_out.getData<int>();
        dim_y_out.create(sizeof(int)*(size_y+1));
        int * dim_y= dim_y_out.getData<int>();
        dim_z_out.create(sizeof(int)*(size_z+1));
        int * dim_z= dim_z_out.getData<int>();

        par.rank_x=rank%size_x;
        par.rank_y=(rank%(size_x*size_y))/size_x;
        par.rank_z=rank/(size_x*size_y);

        for (int i = 0; i < size_x; ++i) {
            dim_x[i]=par.rnx;
        }

        for (int i = 0; i < size_y; ++i) {
            dim_y[i]=par.rny;
        }
        for (int i = 0; i < size_z; ++i) {
            dim_z[i]=par.rnz;
        }

        int div=(par.nx+1)%size_x;
        if (div!=0) {
            if(par.rank_x<div) {
                par.rnx=par.rnx+1;
            }
            for (int i = 0; i < div; ++i) {
                dim_x[i]=dim_x[i]+1;
            }
        }
        div=(par.ny+1)%size_y;
        if (div!=0){
            if (par.rank_y<div) {
                par.rny=par.rny+1;
//                fprintf(stderr,"rank=%d rank for y=%d div=%d\n",rank,rank%(size_x*size_y),div);
            }
            for (int i = 0; i < div; ++i) {
                dim_y[i]=dim_y[i]+1;
            }
        }

        div=(par.nz+1)%size_z;
        if (div!=0){
            if (par.rank_z<div) {
                par.rnz=par.rnz+1;
            }
            for (int i = 0; i < div; ++i) {
                dim_z[i]=dim_z[i]+1;
            }
        }
        par.beg_index_x=0;
        par.end_index_x=0;
        par.beg_index_y=0;
        par.end_index_y=0;
        par.beg_index_z=0;
        par.end_index_z=0;
        if (rank%size_x==0) {
            par.beg_index_x=1;
        }
        if ((rank+1)%size_x==0) {
            par.end_index_x=1;
        }
        if (rank%(size_x*size_y)<size_x) {
            par.beg_index_y=1;
        }
        if ((rank)%(size_x*size_y)>(size_x*(size_y-1))-1) {
            par.end_index_y=1;
        }
        if (rank<(size_x*size_y)) {
            par.beg_index_z=1;
        }
        if (rank>(size_x*size_y*(size_z-1))-1) {
            par.end_index_z=1;
        }
//        cout<<"rank="<< rank<<" T="<<par.T<<" nx="<<par.nx<<" rnx="<<par.rnx<<endl;

        fprintf(stderr,"rank=%d curSize=%d hx=%lf nx=%d rnx=%d ny=%d rny=%d nz=%d rnz=%d\n",
                rank,cursize,par.hx,par.nx,par.rnx,par.ny,par.rny,par.nz,par.rnz);

//        fprintf(stderr,"rank=%d beg_ind_x=%d end_ind_x=%d beg_ind_y=%d end_ind_y=%d beg_ind_z=%d end_ind_z=%d rank_x=%d rank_y=%d rank_z=%d\n",
//                rank,par.beg_index_x,par.end_index_x,par.beg_index_y,par.end_index_y,par.beg_index_z,par.end_index_z,par.rank_x, par.rank_y, par.rank_z);
        int rnx=par.rnx+2;
        int rny=par.rny+2;
        int rnz=par.rnz+2;
        u_out.create(sizeof(double)*(rnx*rny*rnz));
        double * u= u_out.getData<double>();

//        u= new double [rnx*rny*rnz];
//        uOld= new double [rnx*rny*rnz];
        for (int i = 0; i < rnx*rny*rnz; ++i) {
            u[i]=0.0;
//            uOld[i]=0.0;
        }

//        stringstream ssout;

//        ssout << "output3D/"<<"begValue"<<rank<<".txt";
//        ofstream out_f(ssout.str().c_str());

        double x;
        double y;
        double z;
        int cnt=1;
        for (int i = par.beg_index_x; i < rnx-par.end_index_x; ++i) {
            x=(i+getSize(par.rank_x,dim_x)-1)*par.hx;
            for (int j = par.beg_index_y; j < rny-par.end_index_y; ++j) {
                y=(j+getSize(par.rank_y,dim_y)-1)*par.hy;

                for (int k = par.beg_index_z; k < rnz-par.end_index_z; ++k) {
                    z=(k+getSize(par.rank_z,dim_z)-1)*par.hz;
//                    uar(i,j,k)=641;//*x*y*z*(1-x)*(1-y)*(1-z);
//                    uOldar(i,j,k)=641;//*x*y*z*(1-x)*(1-y)*(1-z);
                    cnt++;
                    uar(i,j,k)=1+640*x*y*z*(1-x)*(1-y)*(1-z);
//                    uOldar(i,j,k)=1+640*x*y*z*(1-x)*(1-y)*(1-z);
//                    out_f<<x<<"\t"<<y<<"\t"<<z<<"\t"<<i<<"\t"<<j<<"\t"<<k<<"\t"<<uar(i,j,k)<<endl;
//                    uOldar(i,j,k)=1+640*i*par.hx*j*par.hy*(rank*par.rnz+k-1)*par.hz*(1-i*par.hx)*(1-j*par.hy)*(1-(rank*par.rnz+k-1)*par.hz);
                }


            }
        }
//        printf("loaddata rank=%d u=%lf\n",rank, cheksum(par.nx,ny,nz,0,par.nx,0,ny,0,nz,u));
//        printf("rank=%d data is loaded\n",rank);
//        char numbuold[] = "output3D/u_bg10000000.dat";
//        numbuold[20]='0'+rank;
//        numbuold[15]='0'+1;
//        writeData(numbuold,rank,rnx,rny,rnz,0,rnx,0,rny,0,rnz,u);
    }

    rank_x_out.setValue(par.rank_x);
    rank_y_out.setValue(par.rank_y);
    rank_z_out.setValue(par.rank_z);


}

void initconst(const InputDF &params, OutputDF &T_out, OutputDF &tprint, OutputDF &tau){
    const str_params &par =*params.getData<str_params>();
    T_out.setValue<double>(par.T);
    tprint.setValue<int>(par.tprint);
    tau.setValue<double>(par.tau);
//    printf("end init const\n");
}

void initforParams(int rank, int typeDim, const InputDF &params, OutputDF &cntfor, OutputDF &cntstep){
    const str_params &par =*params.getData<str_params>();

    int cntf=0,cnts=0;
    switch (typeDim) {
    case 1: {
        cntf=1*(par.rny-par.end_index_y-par.beg_index_y);
        cnts=1*(par.rnz-par.end_index_z-par.beg_index_z);
    }
        break;
    case 2: {
        cntf=1*(par.rnz-par.end_index_z-par.beg_index_z);
        cnts=1*(par.rnx-par.end_index_x-par.beg_index_x);
    }
        break;
    case 3: {
        cntf=1*(par.rnx-par.end_index_x-par.beg_index_x);
        cnts=1*(par.rny-par.end_index_y-par.beg_index_y);
    }
        break;
    }
    cntfor.setValue(cntf);
    cntstep.setValue(cnts);
//    printf("rank=%d initparams for dim=%d cntfor=%d cntstep=%d\n",rank,typeDim,cntf,cnts);

}

void calcCoef(int n, double *&a, double *&b, double *&c, double *&f, double *&alfa, double *&beta){
    alfa[1]=0;
    beta[1]=1;

    for (int i = 1; i < n-1; ++i) {
        double tmp=c[i]-a[i]*alfa[i];
        alfa[i+1]=b[i]/(tmp);
        beta[i+1]=(a[i]*beta[i]+f[i])/tmp;
    }
}
double cheksum(int rnx, int rny, int rnz, int i0, int iend, int j0, int jend, int k0, int kend, double *&u){
    double avg=0.0;
    for (int i = i0; i < iend; ++i) {
        for (int j = j0; j < jend; ++j) {
            for (int k = k0; k < kend; ++k) {
                avg+=uar(i,j,k);
            }
        }
    }
    avg=avg/(rnx*rny*rnz);
    return avg;
}

void calcCoef_x(const InputDF &params, const InputDF &uOld_in, OutputDF &a_out, OutputDF &b_out, OutputDF &c_out, OutputDF &f_out){
//    printf("calc Coeff_x ");
    const str_params &par =*params.getData<str_params>();
//    printf("rank_x=%d rank_y=%d rank_z=%d\n",par.rank_x,par.rank_y,par.rank_z);
    const double * uOld=uOld_in.getData<double>();
    int rnx=par.rnx+2;
    int rny=par.rny+2;
    int rnz=par.rnz+2;
    a_out.create(sizeof(double)*rnx*rny*rnz);
    double * a = a_out.getData<double>();
    b_out.create(sizeof(double)*rnx*rny*rnz);
    double * b = b_out.getData<double>();
    c_out.create(sizeof(double)*rnx*rny*rnz);
    double * c = c_out.getData<double>();
    f_out.create(sizeof(double)*rnx*rny*rnz);
    double * f = f_out.getData<double>();

    for (int i = 1+par.beg_index_x; i < rnx-1-par.end_index_x; ++i) {
        for (int j = 1+par.beg_index_y; j < rny-1-par.end_index_y; ++j) {
            for (int k = 1+par.beg_index_z; k < rnz-1-par.end_index_z; ++k) {
                aar(i,j,k)=1/par.hx2;
                bar(i,j,k)=1/par.hx2;
                car(i,j,k)=2/par.hx2+1/par.tau;
                far(i,j,k)=(uOldar(i,j,k))/par.tau+(uOldar(i,j-1,k)-
                        2*uOldar(i,j,k)+uOldar(i,j+1,k))/par.hy2+
                        (uOldar(i,j,k-1)-2*uOldar(i,j,k)+
                        uOldar(i,j,k+1))/par.hz2;
            }
        }
    }
//    char numbuold[] = "output3D/coff10000000.dat";
//    int rank;
//    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
//    numbuold[20]='0'+rank;
//    numbuold[15]='0'+1;
//    writeData(numbuold,rank,rnx,rny,rnz,1+par.beg_index_x,rnx-1-par.end_index_x,1+par.beg_index_y,rny-1-par.end_index_y,1+par.beg_index_z,rnz-1-par.end_index_z,f);
}

void calcCoef_y(const InputDF &params, const InputDF &uOld_in, const InputDF &u_in,
                OutputDF &a_out, OutputDF &b_out, OutputDF &c_out, OutputDF &f_out){
    const str_params &par =*params.getData<str_params>();
    const double * uOld=uOld_in.getData<double>();
    const double * u=u_in.getData<double>();
    int rnx=par.rnx+2;
    int rny=par.rny+2;
    int rnz=par.rnz+2;
    a_out.create(sizeof(double)*rnx*rny*rnz);
    double * a = a_out.getData<double>();
    b_out.create(sizeof(double)*rnx*rny*rnz);
    double * b = b_out.getData<double>();
    c_out.create(sizeof(double)*rnx*rny*rnz);
    double * c = c_out.getData<double>();
    f_out.create(sizeof(double)*rnx*rny*rnz);
    double * f = f_out.getData<double>();

    for (int i = 1+par.beg_index_x; i < rnx-1-par.end_index_x; ++i) {
        for (int j = 1+par.beg_index_y; j < rny-1-par.end_index_y; ++j) {
            for (int k = 1+par.beg_index_z; k < rnz-1-par.end_index_z; ++k) {
                aar(i,j,k)=1/par.hy2;
                bar(i,j,k)=1/par.hy2;
                car(i,j,k)=2/par.hy2+1/par.tau;
                far(i,j,k)=(uar(i,j,k))/par.tau-(uOldar(i,j-1,k)-2*uOldar(i,j,k)+uOldar(i,j+1,k))/par.hy2;

            }
        }
    }

}

void calcCoef_z(const InputDF &params, const InputDF &uOld_in, const InputDF &u_in,
                OutputDF &a_out, OutputDF &b_out, OutputDF &c_out, OutputDF &f_out){
    const str_params &par =*params.getData<str_params>();
    const double * uOld=uOld_in.getData<double>();
    const double * u=u_in.getData<double>();
    int rnx=par.rnx+2;
    int rny=par.rny+2;
    int rnz=par.rnz+2;
    a_out.create(sizeof(double)*rnx*rny*rnz);
    double * a = a_out.getData<double>();
    b_out.create(sizeof(double)*rnx*rny*rnz);
    double * b = b_out.getData<double>();
    c_out.create(sizeof(double)*rnx*rny*rnz);
    double * c = c_out.getData<double>();
    f_out.create(sizeof(double)*rnx*rny*rnz);
    double * f = f_out.getData<double>();

    for (int i = 1+par.beg_index_x; i < rnx-1-par.end_index_x; ++i) {
        for (int j = 1+par.beg_index_y; j < rny-1-par.end_index_y; ++j) {
            for (int k = 1+par.beg_index_z; k < rnz-1-par.end_index_z; ++k) {
                aar(i,j,k)=1/par.hz2;
                bar(i,j,k)=1/par.hz2;
                car(i,j,k)=2/par.hz2+1/par.tau;
                far(i,j,k)=(uar(i,j,k))/par.tau-(uOldar(i,j,k-1)-2*uOldar(i,j,k)+uOldar(i,j,k+1))/par.hz2;

            }
        }
    }

}

void init_alfa_beta(int cntstep, OutputDF &albt_out){
    albt_out.create(sizeof(double)*2*cntstep);
    double * alfa_beta_beg = albt_out.getData<double>();

    for (int i = 0; i < cntstep; ++i) {
        alfa_beta_beg[2*i]=0;
        alfa_beta_beg[2*i+1]=1;
    }
}
void init_uend(int cntstep, OutputDF &uend_out){
    uend_out.create(sizeof(double)*cntstep);
    double * uend = uend_out.getData<double>();

    for (int i = 0; i < cntstep; ++i) {
        uend[i]=1.0;
    }
}


void calccoef_pr_x(int rank, int cnt, int j, const InputDF &params,
              const InputDF &a_in, const InputDF &b_in, const InputDF &c_in, const InputDF &f_in,
              OutputDF &alfa_out, OutputDF &beta_out,
              const InputDF &alfabetabeg_in, OutputDF &alfabetaend_out){
    const str_params &par =*params.getData<str_params>();
//    printf("calc coef_pr_x j=%d rank_x=%d, rank_y=%d rank_z=%d\n",j,par.rank_x,par.rank_y,par.rank_z);
    const double * a=a_in.getData<double>();
    const double * b=b_in.getData<double>();
    const double * c=c_in.getData<double>();
    const double * f=f_in.getData<double>();
    const double * alfabetabeg=alfabetabeg_in.getData<double>();

    alfabetaend_out.create(sizeof(double)*2*cnt);
    double * alfabetaend = alfabetaend_out.getData<double>();


//    int cnt=cntstep;
    int rnx=par.rnx+2;
    int rny=par.rny+2;
    int rnz=par.rnz+2;
    int rn=rnx-1-par.end_index_x;
    int rnt=rnx-1;
    int curj=j+1+par.beg_index_y;
//    int curj=j+1+par.beg_index_y-par.rank_x;
    int curi,curk;
    double tmp;

    alfa_out.create(sizeof(double)*cnt*rnt);
    double * alfa = alfa_out.getData<double>();
    beta_out.create(sizeof(double)*cnt*rnt);
    double * beta = beta_out.getData<double>();


    for (int k = 0; k < cnt; ++k) {
        curk=k+1+par.beg_index_z;
        alfaar(k,par.beg_index_x)=alfabetabeg[2*k];
        betaar(k,par.beg_index_x)=alfabetabeg[2*k+1];
        for (int i = 1+par.beg_index_x; i < rn; ++i) {
            curi=i+1;
            if (curi<1+par.beg_index_x||curj<1+par.beg_index_y||curk<1+par.beg_index_z) {
                fprintf(stderr,"exit from borders a rank_x=%d size_x=%d i=%d j=%d k=%d curi=%d curj=%d curk=%d beg_x=%d nbeg_y=%d beg_index_z=%d\n",
                        par.rank_x,par.size_x,i,j,k,curi,curj,curk,par.beg_index_x,par.beg_index_y,par.beg_index_z);
            }
            tmp=car(curi-1,curj,curk)-aar(curi-1,curj,curk)*alfaar(k,i-1);
            if (tmp==0) {
                fprintf(stderr,"rank=%d i=%d j=%d k=%d curi=%d curj=%d curk=%d a=%lf c=%lf\n",
                        rank,i,j,k,curi,curj,curk,aar(curi-1,curj,curk),car(curi-1,curj,curk));
                char numbuold[] = "output3D/alfa10000000.dat";
                numbuold[20]='0'+rank;
                numbuold[15]='0'+j;
                writeData(numbuold,rank,rnx,rny,rnz,1+par.beg_index_x,rnx-par.end_index_x,1+par.beg_index_y,rny-par.end_index_x,1+par.beg_index_z,rnz-par.end_index_x,a);

                char numb_c[] = "output3D/beta10000000.dat";
                numb_c[20]='0'+rank;
                numb_c[15]='0'+j;
                writeData(numb_c,rank,rnx,rny,rnz,1+par.beg_index_x,rnx-par.end_index_x,1+par.beg_index_y,rny-par.end_index_x,1+par.beg_index_z,rnz-par.end_index_x,c);

                abort();
            }
            alfaar(k,i)=bar(curi-1,curj,curk)/tmp;
            betaar(k,i)=(aar(curi-1,curj,curk)*betaar(k,i-1)+far(curi-1,curj,curk))/tmp;
        }
        alfabetaend[2*k]=alfaar(k,rn-1);
        alfabetaend[2*k+1]=betaar(k,rn-1);
    }

//    char numbuold[] = "output3D/alfa10000000.dat";
//    numbuold[20]='0'+rank;
//    numbuold[15]='0'+j;
//    writeData(numbuold,rank,1,cnt,rnt,0,1,0,cnt,1,rn,alfa);

//    char numbbeta[] = "output3D/beta10000000.dat";
//    numbbeta[20]='0'+rank;
//    numbbeta[15]='0'+j;
//    writeData(numbbeta,rank,1,cnt,rnt,0,1,0,cnt,1,rn,beta);

}

void calccoef_pr_y(int cnt, int k, const InputDF &params,
                   const InputDF &a_in, const InputDF &b_in, const InputDF &c_in, const InputDF &f_in,
                   OutputDF &alfa_out, OutputDF &beta_out,
                   const InputDF &alfabetabeg_in, OutputDF &alfabetaend_out){
    const str_params &par =*params.getData<str_params>();
    const double * a=a_in.getData<double>();
    const double * b=b_in.getData<double>();
    const double * c=c_in.getData<double>();
    const double * f=f_in.getData<double>();
    const double * alfabetabeg=alfabetabeg_in.getData<double>();

    alfabetaend_out.create(sizeof(double)*2*cnt);
    double * alfabetaend = alfabetaend_out.getData<double>();

//    int cnt=cntstep;
    int rnx=par.rnx+2;
    int rny=par.rny+2;
    int rnz=par.rnz+2;
    int rn=rny-1-par.end_index_y;
    int rnt=rny-1;
    int curk=k+1+par.beg_index_z;
//    int curk=k+1+par.beg_index_z-par.rank_y;
    int curi, curj;
    double tmp;

    alfa_out.create(sizeof(double)*cnt*rnt);
    double * alfa = alfa_out.getData<double>();
    beta_out.create(sizeof(double)*cnt*rnt);
    double * beta = beta_out.getData<double>();

    for (int i = 0; i < cnt; ++i) {
        curi=i+1+par.beg_index_x;
        alfaar(i,par.beg_index_y)=alfabetabeg[2*i];
        betaar(i,par.beg_index_y)=alfabetabeg[2*i+1];
        for (int j = 1+par.beg_index_y; j < rn; ++j) {
            curj=j+1;
            tmp=car(curi,curj-1,curk)-aar(curi,curj-1,curk)*alfaar(i,j-1);
            alfaar(i,j)=bar(curi,curj-1,curk)/tmp;
            betaar(i,j)=(aar(curi,curj-1,curk)*betaar(i,j-1)+far(curi,curj-1,curk))/tmp;
        }
        alfabetaend[2*i]=alfaar(i,rn-1);
        alfabetaend[2*i+1]=betaar(i,rn-1);
    }

}

void calccoef_pr_z(int cnt, int i, const InputDF &params,
                   const InputDF &a_in, const InputDF &b_in, const InputDF &c_in, const InputDF &f_in,
                   OutputDF &alfa_out, OutputDF &beta_out,
                   const InputDF &alfabetabeg_in, OutputDF &alfabetaend_out){
    const str_params &par =*params.getData<str_params>();
    const double * a=a_in.getData<double>();
    const double * b=b_in.getData<double>();
    const double * c=c_in.getData<double>();
    const double * f=f_in.getData<double>();
    const double * alfabetabeg=alfabetabeg_in.getData<double>();

    alfabetaend_out.create(sizeof(double)*2*cnt);
    double * alfabetaend = alfabetaend_out.getData<double>();

//    int cnt=cntstep;
    int rnx=par.rnx+2;
    int rny=par.rny+2;
    int rnz=par.rnz+2;
    int rn=rnz-1-par.end_index_z;
    int rnt=rnz-1;
    int curi=i+1+par.beg_index_x;
//    int curi=i+1+par.beg_index_x-par.rank_z;
    int curj, curk;
    double tmp;

    alfa_out.create(sizeof(double)*cnt*rnt);
    double * alfa = alfa_out.getData<double>();
    beta_out.create(sizeof(double)*cnt*rnt);
    double * beta = beta_out.getData<double>();

    for (int j = 0; j < cnt; ++j) {
        curj=j+1+par.beg_index_y;
        alfaar(j,par.beg_index_z)=alfabetabeg[2*j];
        betaar(j,par.beg_index_z)=alfabetabeg[2*j+1];
        for (int k = 1+par.beg_index_z; k < rn; ++k) {
            curk=k+1;
            tmp=car(curi,curj,curk-1)-aar(curi,curj,curk-1)*alfaar(j,k-1);
            alfaar(j,k)=bar(curi,curj,curk-1)/tmp;
            betaar(j,k)=(aar(curi,curj,curk-1)*betaar(j,k-1)+far(curi,curj,curk-1))/tmp;
        }
        alfabetaend[2*j]=alfaar(j,rn-1);
        alfabetaend[2*j+1]=betaar(j,rn-1);
    }

}

void calcVal(int rank, int step, int cnt, const InputDF & params, const InputDF &alfa_in, const InputDF &beta_in,
             OutputDF &u_out, OutputDF &ubeg_out, const InputDF &uend_in){
    const str_params &par =*params.getData<str_params>();
    const double * alfa=alfa_in.getData<double>();
    const double * beta=beta_in.getData<double>();

    const double * uend=uend_in.getData<double>();

    int rn=0;
    int rnt=0;
    int j0=0;
    int jend=0;
    switch (step) {
    case 1:{
//        printf("calc Val_x cnt=%d rank_x=%d, rank_y=%d rank_z=%d\n",cnt, par.rank_x,par.rank_y,par.rank_z);
        rn=par.rnx+1-par.end_index_x;
        rnt=par.rnx+1;
        j0=par.beg_index_x;
        jend=par.end_index_x;
        break;
    }
    case 2:{
//        printf("calc Val_y cnt=%d rank_x=%d, rank_y=%d rank_z=%d\n",cnt, par.rank_x,par.rank_y,par.rank_z);
        rn=par.rny+1-par.end_index_y;
        rnt=par.rny+1;
        j0=par.beg_index_y;
        jend=par.end_index_y;
        break;
    }
    case 3:{
//        printf("calc Val_z cnt=%d rank_x=%d, rank_y=%d rank_z=%d\n",cnt, par.rank_x,par.rank_y,par.rank_z);
        rn=par.rnz+1-par.end_index_z;
        rnt=par.rnz+1;
        j0=par.beg_index_z;
        jend=par.end_index_z;
        break;
    }
    }
    u_out.create(sizeof(double)*cnt*rnt);
    double * u = u_out.getData<double>();

    ubeg_out.create(sizeof(double)*cnt);
    double * ubeg = ubeg_out.getData<double>();

//    u = new double[cnt*rnx];
//    ubeg= new double[cnt];
    for (int i = 0; i < cnt; ++i) {
        u[i*rnt+rn-1]=uend[i];
        for (int j = rn-2; j >= 0; j--) {
//            for (int j = rn-2; j >= j0; j--) {
            u[i*rnt+j]=alfaar(i,j+1)*u[i*rnt+j+1]+betaar(i,j+1);
        }
        ubeg[i]=u[i*rnt+0];
    }
//    char numbuold[] = "output3D/uost10000000.dat";
//    numbuold[20]='0'+rank;
//    numbuold[15]='0'+step;
//    writeData(numbuold,rank,1,cnt,rn,0,1,0,cnt,j0,rn,u);


}

void fill_u(int step, int cnt, const InputDF &params, const InputDF &u_t_in, OutputDF &u_out){
//    printf("fill u %s\n",u_t_in.getId().toString().c_str());
    const str_params &par =*params.getData<str_params>();
    const double * u_t=u_t_in.getData<double>();

    int rnx,rny,rnz;
    rnx=par.rnx+2;
    rny=par.rny+2;
    rnz=par.rnz+2;

    u_out.create(sizeof(double)*rnx*rny*rnz);
    double * u = u_out.getData<double>();
    for (int i = 0; i < rnx*rny*rnz; ++i) {
        u[i]=1;
    }

    switch (step) {
    case 1:{
        for (int j = 1+par.beg_index_y; j < rny-1-par.end_index_y; ++j) {
//            int j=cur+1+par.beg_index_y;
            for (int i = 0; i <= par.rnx-par.end_index_x; ++i) {
                for (int k = 0; k < cnt; ++k) {
                    uar(i+1,j,k+1+par.beg_index_z)=u_t[(j-1-par.beg_index_y)*(rnx-1)*cnt+(k)*(rnx-1)+i];

                }
            }

        }
        break;
    }
    case 2:{
        for (int k = 1+par.beg_index_z; k < rnz-1-par.end_index_z; ++k) {
//            int k=cur+1+par.beg_index_z;

            for (int j = 0; j <= par.rny-par.end_index_y; ++j) {
                for (int i = 0; i < cnt; ++i) {
                    uar(i+1+par.beg_index_x,j+1,k)=u_t[(k-1-par.beg_index_z)*(rny-1)*cnt+(i)*(rny-1)+j];

                }
            }

        }
        break;
    }
    case 3:{
        for (int i = 1+par.beg_index_x; i < rnx-1-par.end_index_x; ++i) {
//            int i=cur+1+par.beg_index_x;
            for (int k = 0; k <= par.rnz-par.end_index_z; ++k) {
                for (int j = 0; j < cnt; ++j) {
                    uar(i,j+1+par.beg_index_y,k+1)=u_t[(i-1-par.beg_index_x)*(rnz-1)*cnt+(j)*(rnz-1)+k];

                }
            }

        }
        break;
    }
    }
}

void swapFields(double *& u, double *& uOld){
    swap(u,uOld);
}

void setBorder_x(const InputDF &params, const InputDF &uOld_in,
               OutputDF &sendar_x_L_out, OutputDF &sendar_x_R_out){
    const str_params &par =*params.getData<str_params>();
    const double * uOld=uOld_in.getData<double>();

    int rnx=par.rnx+2;
    int rny=par.rny+2;
    int rnz=par.rnz+2;
    int nx=par.rnx;
    int ny=par.rny;
    int nz=par.rnz;

    sendar_x_L_out.create(sizeof(double)*ny*nz);
    double * sendar_x_L = sendar_x_L_out.getData<double>();
    sendar_x_R_out.create(sizeof(double)*ny*nz);
    double * sendar_x_R = sendar_x_R_out.getData<double>();
//    sendar_x_R= new double[ny*nz];
//    sendar_x_L= new double[ny*nz];
    for (int i = 0; i < ny*nz; ++i) {
        sendar_x_L[i]=0;
        sendar_x_R[i]=0;
    }
    for (int j = 1; j <= ny; ++j) {
        for (int k = 1; k <= nz; ++k) {
            if (par.rank_x!=0){
                sendar_x_L[(j-1)*nz+k-1]=uOldar(1,j,k);
            }
            if (par.rank_x!=par.size_x-1){
                sendar_x_R[(j-1)*nz+k-1]=uOldar(nx,j,k);
            }
        }
    }
}

void setBorder_y(const InputDF &params, const InputDF &uOld_in,
               OutputDF &sendar_y_T_out, OutputDF &sendar_y_B_out){
    const str_params &par =*params.getData<str_params>();
    const double * uOld=uOld_in.getData<double>();

    int rnx=par.rnx+2;
    int rny=par.rny+2;
    int rnz=par.rnz+2;
    int nx=par.rnx;
    int ny=par.rny;
    int nz=par.rnz;

    sendar_y_B_out.create(sizeof(double)*nx*nz);
    double * sendar_y_B = sendar_y_B_out.getData<double>();
    sendar_y_T_out.create(sizeof(double)*nx*nz);
    double * sendar_y_T = sendar_y_T_out.getData<double>();

//    sendar_y_B= new double [nx*nz];
//    sendar_y_T= new double [nx*nz];
    for (int i = 0; i < nx*nz; ++i) {
        sendar_y_B[i]=10;
        sendar_y_T[i]=10;
    }
    for (int i = 1; i <= nx; ++i) {
        for (int k = 1; k <= nz; ++k) {
            if (par.rank_y!=0){
                sendar_y_B[(i-1)*nz+k-1]=uOldar(i,1,k);
            }
            if (par.rank_y!=par.size_y-1){
                sendar_y_T[(i-1)*nz+k-1]=uOldar(i,ny,k);
            }
        }
    }

}

void setBorder_z(const InputDF &params, const InputDF &uOld_in,
               OutputDF &sendar_z_F_out, OutputDF &sendar_z_B_out){

    const str_params &par =*params.getData<str_params>();
    const double * uOld=uOld_in.getData<double>();

    int rnx=par.rnx+2;
    int rny=par.rny+2;
    int rnz=par.rnz+2;
    int nx=par.rnx;
    int ny=par.rny;
    int nz=par.rnz;

    sendar_z_B_out.create(sizeof(double)*nx*ny);
    double * sendar_z_B = sendar_z_B_out.getData<double>();
    sendar_z_F_out.create(sizeof(double)*nx*ny);
    double * sendar_z_F = sendar_z_F_out.getData<double>();
//    sendar_z_B= new double [nx*ny];
//    sendar_z_F= new double [nx*ny];
    for (int i = 0; i < nx*ny; ++i) {
        sendar_z_B[i]=20;
        sendar_z_F[i]=20;
    }
    for (int i = 1; i <= nx; ++i) {
        for (int j = 1; j <= ny; ++j) {
            if (par.rank_z!=0){
                sendar_z_B[(i-1)*ny+j-1]=uOldar(i,j,1);
            }
            if (par.rank_z!=par.size_z-1){
                sendar_z_F[(i-1)*ny+j-1]=uOldar(i,j,nz);
            }
        }
    }
}


void loadBorder(const InputDF &params, OutputDF &u_out, const InputDF &uOld_in,
                const InputDF &recvar_x_L_in, const InputDF &recvar_x_R_in,
                const InputDF &recvar_y_B_in, const InputDF &recvar_y_T_in,
                const InputDF &recvar_z_B_in, const InputDF &recvar_z_F_in){

    const str_params &par =*params.getData<str_params>();
//    fprintf(stderr,"load Border rank_x=%d rank_y=%d rank_z=%d\n",par.rank_x,par.rank_y, par.rank_z);
    const double * uOld=uOld_in.getData<double>();
    const double * recvar_x_L=recvar_x_L_in.getData<double>();
    const double * recvar_x_R=recvar_x_R_in.getData<double>();
    const double * recvar_y_T=recvar_y_T_in.getData<double>();
    const double * recvar_y_B=recvar_y_B_in.getData<double>();
    const double * recvar_z_F=recvar_z_F_in.getData<double>();
    const double * recvar_z_B=recvar_z_B_in.getData<double>();


    int rnx=par.rnx+2;
    int rny=par.rny+2;
    int rnz=par.rnz+2;

    int nx=par.rnx;
    int ny=par.rny;
    int nz=par.rnz;

    u_out.create(sizeof(double)*rnx*rny*rnz);
    double * u = u_out.getData<double>();

    for (int i = 1; i <= nx; ++i) {
        for (int j = 1; j <= ny; ++j) {
            for (int k = 1; k <= nz; ++k) {
              uar(i,j,k)=uOldar(i,j,k);
            }
        }
    }
    for (int j = 1; j <= ny; ++j) {
        for (int k = 1; k <= nz; ++k) {
            if (par.rank_x!=0) {
                uar(0,j,k)=recvar_x_L[(j-1)*nz+k-1];
            }
            if (par.rank_x!=par.size_x-1) {
                uar(nx+1,j,k)=recvar_x_R[(j-1)*nz+k-1];
            }
        }
    }

    for (int i = 1; i <= nx; ++i) {
        for (int k = 1; k <= nz; ++k) {
            if (par.rank_y!=0){
                uar(i,0,k)=recvar_y_B[(i-1)*nz+k-1];
            }
            if (par.rank_y!=par.size_y-1) {
                uar(i,ny+1,k)=recvar_y_T[(i-1)*nz+k-1];
            }
        }
    }

    for (int i = 1; i <= nx; ++i) {
        for (int j = 1; j <= ny; ++j) {
            if(par.rank_z!=0){
                uar(i,j,0)=recvar_z_B[(i-1)*ny+j-1];
            }
            if(par.rank_z!=par.size_z-1){
                uar(i,j,nz+1)=recvar_z_F[(i-1)*ny+j-1];
            }

        }
    }

}

void outputData(int iter, int rank, const InputDF &params, const InputDF &u_in){
    const str_params &par =*params.getData<str_params>();
    const double * u=u_in.getData<double>();

    printf( "%d\n", iter);
    int rnx, rny, rnz;
    rnx=par.rnx+2;
    rny=par.rny+2;
    rnz=par.rnz+2;

//    fprintf(stderr,"rank=%d rank_x=%d rank_y=%d rank_z=%d nx=%d rnx=%d ny=%d rny=%d nz=%d rnz=%d\n",
//            rank,par.rank_x,par.rank_y,par.rank_z, par.nx,par.rnx,par.ny,par.rny,par.nz,par.rnz);

//        fprintf(stderr,"rank=%d beg_ind_x=%d end_ind_x=%d beg_ind_y=%d end_ind_y=%d beg_ind_z=%d end_ind_z=%d rank_x=%d rank_y=%d rank_z=%d\n",
//                rank,par.beg_index_x,par.end_index_x,par.beg_index_y,par.end_index_y,par.beg_index_z,par.end_index_z,par.rank_x, par.rank_y, par.rank_z);


    char numb[] = "output3D/000000000000.dat";
    numb[20]='0'+rank;
    int pos = 19;
    while( iter !=0 )
    {
        numb[pos] = '0' + iter%10;
        iter /= 10;
        pos--;
    }

//    printf("rank=%d j=%d k=%d\n",rank, j0, k0);

    FILE * outf = fopen( numb, "w" );

    fputs( "TITLE=\"USERData\"\nVARIABLES=i,j,k,Temperatue\n", outf );
    fprintf( outf, "ZONE T=\"ZONE1\", i=%d j=%d k=%d\n", rnx-2, rny-2, rnz-2 );

//    for( int k=0; k<rnz; k++ )
//        for( int j=0; j<rny; j++ )
//            for( int i=0; i<rnx; i++ )
    for( int k=1; k<rnz-1; k++ )
        for( int j=1; j<rny-1; j++ )
            for( int i=1; i<rnx-1; i++ )
            {
//                if (uar(i,j,k)!=1.0) {
                    fprintf( outf, "%d\t%d\t%d\t%.10f\n", i+par.rank_x*(par.rnx+1), j+(par.rny+1)*par.rank_y, k+par.rank_z*(par.rnz+1), uar(i,j,k));
//                }
//                fprintf( outf, "%.8f\t%.8f\t%.8f\t%.8f\n", i*par.hx, ((rank*par.rny-1)*stepy+j)*par.hy, ((rank*par.rnz-1)*stepz+k)*par.hz, uar(i,j,k));
            }

    fclose(outf);
}

void writeData(char numb[], int rank, int rnx, int rny, int rnz, int i0, int iend, int j0, int jend, int k0, int kend, const double *u){
//    char numb[] = "output3D/st0000000000.dat";
//    numb[20]='0'+rank;
    FILE * outf = fopen( numb, "w" );
    for( int k=k0; k<kend; k++ )
        for( int j=j0; j<jend; j++ )
            for( int i=i0; i<iend; i++ )
            {
              fprintf( outf, "%d\t%d\t%d\t%.8f\n", i, j, k, uar(i,j,k));
            }

    fclose(outf);

}


void outputDataAll(int iter, str_params *&params, double *&u){
    str_params & par = *params;
    printf( "all %d\n", iter);
    int nx, ny, nz;
    nx=par.nx;
    ny=par.ny;
    nz=par.nz;
    int i0,j0,k0,iend, jend,kend;
    i0=1;
    j0=1;
    k0=1;
    iend=nx-1;
    jend=ny-1;
    kend=nz-1;

    char numb[] = "output3D/11000000000.dat";
//    numb[20]='0'+0;
    int pos = 19;
    while( iter !=0 )
    {
        numb[pos] = '0' + iter%10;
        iter /= 10;
        pos--;
    }

//    printf("rank=%d j=%d k=%d\n",rank, j0, k0);

    FILE * outf = fopen( numb, "w" );

    fputs( "TITLE=\"USERData\"\nVARIABLES=i,j,k,Temperatue\n", outf );
    fprintf( outf, "ZONE T=\"ZONE1\", i=%d j=%d k=%d\n", nx-2, ny-2, nz-2 );

    for( int k=k0; k<kend; k++ )
        for( int j=j0; j<jend; j++ )
            for( int i=i0; i<iend; i++ )
            {
              fprintf( outf, "%.8f\t%.8f\t%.8f\t%.8f\n", i*par.hx, j*par.hy, k*par.hz, uallar(i,j,k));
            }

    fclose(outf);
}
void gather_arr(const InputDF &v1, const InputDF &v2, OutputDF & resv) {
//    printf("gatther\n");
//    printf("size all =%d size =%d val1=%d val2=%d\n", (int)v1.getSize(),(int)v1.getSize()/sizeof(int),(v1.getData<int>())[0],(v2.getData<int>())[0]);
    int v1_size=(int)v1.getSize();
    int v2_size=(int)v2.getSize();

    //printf("gather arr %s\n",resv.getId().toString().c_str());

    resv.create(v1_size+v2_size);
    double * res= resv.getData<double>();
    memcpy(res,v1.getData<double>(),v1_size);
    memcpy(&res[v1_size/sizeof(double)],v2.getData<double>(),v2_size);
//    for (int i = 0; i < (v1_size+v2_size)/sizeof(int); ++i) {
//        printf("i=%d val=%d\n",i,res[i]);
//    }
}

void copy_vector(const InputDF &v, OutputDF & resv){
//    printf("copy_v\n");
    int v_size=(int)v.getSize();

    resv.create(v_size);
    double * res= resv.getData<double>();
    memcpy(res,v.getData<double>(),v_size);

}

void freeData(double *&u, double *&uOld){
    delete [] u;
    delete [] uOld;
}

int getSize(int n, int *&dim){
    int val=0;
    for (int i = 0; i < n; ++i) {
        val+=dim[i];
    }
    return val;
}

}
