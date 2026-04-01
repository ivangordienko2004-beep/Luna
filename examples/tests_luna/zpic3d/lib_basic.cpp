#include <cstdio>
#include <string.h>
#include <math.h>
#include "ucenv.h"

#include "lib_basic.h"

extern "C"
{
    void c_empty0() {}
    void c_empty1(const InputDF &df) {}
    void c_empty2(const InputDF &df1,const InputDF &df2) {}
    void c_empty3(const InputDF &df1,const InputDF &df2,const InputDF &df3) {}
    void c_empty4(const InputDF &df1,const InputDF &df2,const InputDF &df3,const InputDF &df4) {}
    void c_empty5(const InputDF &df1,const InputDF &df2,const InputDF &df3,const InputDF &df4,const InputDF &df5) {}
    void c_empty6(const InputDF &df1,const InputDF &df2,const InputDF &df3,const InputDF &df4,const InputDF &df5,const InputDF &df6) {}
    
    void c_df_ready(const InputDF &df, OutputDF &df_yes)
    {
        df_yes.setValue(1);
    }

    void c_df_ready2(const InputDF &df1, const InputDF &df2, OutputDF &df_yes)
    {
        df_yes.setValue(1);
    }

    void c_df_ready3(const InputDF &df1, const InputDF &df2, const InputDF &df3, OutputDF &df_yes)
    {
        df_yes.setValue(1);
    }

    void c_df_ready4(const InputDF &df1, const InputDF &df2, const InputDF &df3, const InputDF &df4, OutputDF &df_yes)
    {
        df_yes.setValue(1);
    }

    void c_check(const InputDF &df, const char *msg)
    {
        df.getSize();
        puts(msg);
    }

    void c_check_seq(const InputDF &df, const char *msg, InputDF &prev, OutputDF &next)
    {
        df.getSize();
        puts(msg);
        next.copy(prev);
    }

    void c_copy(const InputDF &df_in, OutputDF &df_out)
    {
        df_out.copy(df_in);
    }

    void c_assign_int(int val, OutputDF& df)
    {
        df.setValue(val);
    }

    void c_assign_real(double val, OutputDF& df)
    {
        df.setValue(val);
    }

    void c_assign_string(const char *val, OutputDF &df)
    {
        df.setValue(std::string(val));
    }

    void c_puts(const char *str)
    {
        puts(str);
        fflush(stdout);
    }

    void c_puts_seq(const char *str, const InputDF &prev, OutputDF &next)
    {
        puts(str);
        fflush(stdout);
        next.copy(prev);
    }

    void c_printf(const char* str)
    {
        printf("%s", str);
        fflush(stdout);
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
        printf(str,val1);
        fflush(stdout);
    }

    void c_sprintf_d(OutputDF &df_result, char *str, int val1)
    {
        int length=strlen(str);
        char *tmp=new char [length+16];
        sprintf(tmp, str, val1);
        df_result.setValue(std::string(tmp));
        delete[] tmp;
    }

    void c_sprintf_dd(OutputDF &df_result, char *str, int val1, int val2)
    {
        int length=strlen(str);
        char *tmp=new char [length+32];
        sprintf(tmp, str, val1, val2);
        df_result.setValue(std::string(tmp));
        delete[] tmp;
    }

    void c_sprintf_ddd(OutputDF &df_result, char *str, int val1, int val2, int val3)
    {
        int length=strlen(str);
        char *tmp=new char [length+48];
        sprintf(tmp, str, val1, val2, val3);
        df_result.setValue(std::string(tmp));
        delete[] tmp;
    }

    void c_sprintf_dddd(OutputDF &df_result, char *str, int val1, int val2, int val3, int val4)
    {
        int length=strlen(str);
        char *tmp=new char [length+64];
        sprintf(tmp, str, val1, val2, val3, val4);
        df_result.setValue(std::string(tmp));
        delete[] tmp;
    }

    void c_printf_seq(const char* str, const InputDF &prev, OutputDF &next)
    {
        printf("%s", str);
        fflush(stdout);
        next.copy(prev);
    }

    void c_sprintf_d_seq(OutputDF &df_result, char *str, int val1, const InputDF &prev, OutputDF &next)
    {
        int length=strlen(str);
        char *tmp=new char [length+16];
        sprintf(tmp, str, val1);
        df_result.setValue(std::string(tmp));
        delete[] tmp;
        next.copy(prev);
    }

    void c_sprintf_dd_seq(OutputDF &df_result, char *str, int val1, int val2, const InputDF &prev, OutputDF &next)
    {
        int length=strlen(str);
        char *tmp=new char [length+32];
        sprintf(tmp, str, val1, val2);
        df_result.setValue(std::string(tmp));
        delete[] tmp;
        next.copy(prev);
    }

    void c_sprintf_ddd_seq(OutputDF &df_result, char *str, int val1, int val2, int val3, const InputDF &prev, OutputDF &next)
    {
        int length=strlen(str);
        char *tmp=new char [length+48];
        sprintf(tmp, str, val1, val2, val3);
        df_result.setValue(std::string(tmp));
        delete[] tmp;
        next.copy(prev);
    }

    void c_sprintf_dddd_seq(OutputDF &df_result, char *str, int val1, int val2, int val3, int val4, const InputDF &prev, OutputDF &next)
    {
        int length=strlen(str);
        char *tmp=new char [length+64];
        sprintf(tmp, str, val1, val2, val3, val4);
        df_result.setValue(std::string(tmp));
        delete[] tmp;
        next.copy(prev);
    }

    void c_sscanf_d(const char *str, OutputDF& val1)
    {
        int v1;
        sscanf(str, "%d", &v1);
        val1.setValue(v1);
    }

    void c_sscanf_dd(const char *str, OutputDF& val1, OutputDF& val2)
    {
        int v1, v2;
        sscanf(str, "%d%d", &v1, &v2);
        val1.setValue(v1);
        val2.setValue(v2);
    }

    void c_sscanf_ddd(const char *str, OutputDF& val1, OutputDF& val2, OutputDF& val3)
    {
        int v1, v2, v3;
        sscanf(str, "%d%d%d", &v1, &v2, &v3);
        val1.setValue(v1);
        val2.setValue(v2);
        val3.setValue(v3);
    }

    void c_sscanf_dddd(const char *str, OutputDF& val1, OutputDF& val2, OutputDF& val3, OutputDF& val4)
    {
        int v1, v2, v3, v4;
        sscanf(str, "%d%d%d%d", &v1, &v2, &v3, &v4);
        val1.setValue(v1);
        val2.setValue(v2);
        val3.setValue(v3);
        val4.setValue(v4);
    }

    void c_strlen(const char* str, luna::ucenv::OutputDF& df_length)
    {
        df_length.setValue((int)strlen(str));
    }

    void c_real1d_fill(int n, double val, OutputDF& df_x)
    {
        double *x = df_x.create<double>(n);

        for (int i=0; i<n; i++) {
            x[i]=val;
        }
    }

    void c_int1d_fill(int n, int val, OutputDF& df_x)
    {
        int *x=df_x.create<int>(n);

        for (int i=0; i<n; i++) {
            x[i]=val;
        }
    }

    void c_real_add(real v1, real v2, OutputDF &df_result)
    {
        df_result.setValue(v1+v2);
    }

    void c_real_max(real v1, real v2, OutputDF &df_result)
    {
        df_result.setValue(v1>v2 ? v1 : v2);
    }

    void c_real1d_reduce_max(int n, const InputDF &df_x, OutputDF &df_result)
    {
        assert(df_x.getSize()==n*sizeof(real));
        const real *x=df_x.getData<real>();
        real max = 0.0;

        if (n>0) {
            max = x[0];
        }

        for (int i=1; i<n; i++) {
            if (max<x[i]) {
                max=x[i];
            }
        }

        df_result.setValue(max);
    }

    void c_real1d_reduce_sum(int n, const InputDF &df_x, OutputDF &df_result)
    {
        assert(df_x.getSize()==n*sizeof(real));
        const real *x=df_x.getData<real>();
        real sum=0.0;
        if (n>0) {
            sum=x[0];
        }

        for (int i=1; i<n; i++) {
            sum+=x[i];
        }

        df_result.setValue(sum);
    }

    void c_real1d_add(int n, const InputDF &df_x1, const InputDF &df_x2, OutputDF &df_result)
    {
        assert(df_x1.getSize()==n*sizeof(real));
        assert(df_x2.getSize()==n*sizeof(real));
        const real *x1=df_x1.getData<real>();
        const real *x2=df_x2.getData<real>();
        real *r=df_result.create<real>(n);

        for (int i=0; i<n; i++) {
            r[i]=x1[i]+x2[i];
        }
    }

    void c_real1d_delta_abs_reduce_max(int n, const InputDF &df_x, const InputDF &df_y, OutputDF &df_result)
    {
        assert(df_x.getSize()==n*sizeof(real));
        assert(df_y.getSize()==n*sizeof(real));
        const real *x=df_x.getData<real>();
        const real *y=df_y.getData<real>();
        real delta = 0.0;

        for (int i=0; i<n; i++) {
            real d=fabs(y[i]-x[i]);
            if (d>delta) {
                delta=d;
            }
        }
        df_result.setValue(delta);
    }
}