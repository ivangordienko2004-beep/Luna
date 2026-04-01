#include <cstdio>
#include "lib_mesh3d_codes.h"
#include "ucenv.h"

extern "C"
{
    void c_write2d_subdomain(const char *filename, int n0, int n1, const InputDF &df_u)
    {
        assert(df_u.getSize()==n0*n1*sizeof(real));
        const real *u=df_u.getData<real>();
        FILE *f=fopen(filename, "wb");

        if (f==NULL) {
            printf("c_write2d_subdomain: Can't create file: %s\n",filename);
            fflush(stdout);
            return;
        }

        if (fwrite(u, sizeof(real), n0*n1, f)!=n0*n1) {
            printf("c_write2d_subdomain: Error writing file: %s\n",filename);
            fflush(stdout);
            return;
        }

        if (fclose(f)==EOF) {
            printf("c_write2d_subdomain: Can't close file: %s\n",filename);
            fflush(stdout);
            return;
        }
    }

    void c_write2d_part_subdomain(const char *filename, int g0, int g1, int n0, int n1, int s0, int s1, int nb, const InputDF &df_u, const InputDF &prev, OutputDF &next)
    {
        assert(df_u.getSize()==n0*n1*sizeof(real));
        const real (*u)[n0][n1]=(const real (*)[n0][n1])df_u.getData<real>();

        FILE *f=fopen(filename, "r+b");

        if (f==NULL) {
            f=fopen(filename, "wb");
        }

        if (f==NULL) {
            printf("c_write2d_part_subdomain(%d,%d,%d,%d,%d,%d,...): Can't open file: %s\n", g0, g1, n0, n1, s0, s1, filename);
            fflush(stdout);
            return;
        }

        int fs=(s0+nb)*g1+s1+nb; // start of subdomain in file [g0][g1] of real
        int i;

        for (i=0; i<n0-2*nb; i++,fs+=g1) {
            if (fseek(f, fs*sizeof(real), SEEK_SET)!=0) {
                printf("c_write2d_part_subdomain: Error fseek %s\n", filename);
                fflush(stdout);
                fclose(f);
            }

            if (fwrite(&(*u)[nb+i][nb], sizeof(real), n1-2*nb,f)!=n1-2*nb) {
                printf("c_write2d_part_subdomain: Error writing file: %s\n", filename);
                fflush(stdout);
            }

            fclose(f);
        }

        fclose(f);
        next.copy(prev);
    }

    void c_gnuplot_script_init(const char *scriptname, OutputDF &df_next)
    {
        FILE *f=fopen(scriptname, "w");
        if (f==NULL) {
            printf("c_gnuplot_script_init: Can't create file: %s\n", scriptname);
            fflush(stdout);
            return;
        }

        fprintf(f,"set terminal png\n");
        fprintf(f,"#set cbrange[0:3]\n");
        fclose(f);
        df_next.setValue(1);
    }

    void c_gnuplot_script_add(const char *scriptname, const char *filename, int n0, int n1, const InputDF &df_prev, OutputDF &df_next)
    {
        FILE *f=fopen(scriptname, "a");
        if (f==NULL) {
            printf("c_gnuplot_script_add: Can't open file: %s\n", scriptname);
            fflush(stdout);
            return;
        }

        fprintf(f,"set xrange[0:%d]; set yrange[0:%d]; ", n0-1, n1-1);
        fprintf(f,"set output \"%s.png\"; ", filename);
        fprintf(f,"plot \"%s\" binary array=(%d,%d) format=\"%%lf\" transpose with image\n",filename,n0,n1);
        fclose(f);
        df_next.copy(df_prev);
    }
}