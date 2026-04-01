//#include <mpi.h>

#include <unistd.h>
#include <cstdio>
#include <string.h>
#include <math.h>
#include "ucenv.h"

#include "pic3d_codes.h"
#include "pic3d_fill.h"

real sqr(real x)
{
    return x*x;
}

int min(int n1, int n2)
{
    return n1<n2 ? n1 : n2;
}

#ifdef MPI_VERSION
int mpirank()
{
    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    return rank;
}
#endif

extern "C"
{
    void c_print_memory_usage()
    {
#ifdef MPI_VERSION
        printf("%2d: ", mpirank());
#endif
        char cmd[256];
        sprintf(cmd,"cat /proc/%d/status | grep VmSize", getpid());
        system(cmd);
    }

    void c_ready_print_memory_usage(const InputDF &df)
    {
        c_print_memory_usage();
    }

// Reading parameters

    void c_check_file(const char *filename, OutputDF &df_ok)
    {
        FILE *f = fopen(filename, "r");

        if (f==NULL) {
            df_ok.setValue(0);
        } else {
            df_ok.setValue(1);
            fclose(f);
        }
    }

#define T_INT 1
#define T_REAL 2

    static int read_int(std::string s, int *pvalue)
    {
        return sscanf(s.c_str(), "%d", pvalue)==1;
    }

    static int read_real(std::string s, real *pvalue)
    {
        return sscanf(s.c_str(), "%le", pvalue)==1;
    }

    void c_read_parameters(const char *filename, OutputDF &df_nt, OutputDF &df_nts, OutputDF &df_np,
                           OutputDF &df_nx, OutputDF &df_ny, OutputDF &df_nz,
                           OutputDF &df_nfx, OutputDF &df_nfy, OutputDF &df_nfz,
                           OutputDF &df_xn, OutputDF &df_yn, OutputDF &df_zn,
                           OutputDF &df_tau, OutputDF &df_pm, OutputDF &df_sm,
                           OutputDF &df_radius, OutputDF &df_dvr, OutputDF &df_dvf, OutputDF &df_dvz,
                           OutputDF &df_eps, OutputDF &df_w, OutputDF &df_ok)
    {
        const int npar = 21;
        std::string names[npar]= {
            "nt", "nts", "np", "nx",
            "ny", "nz", "nfx", "nfy",
            "nfz", "tau", "xn", "yn",
            "zn", "pm", "sm", "radius",
            "dvr", "dvf", "dvz", "eps",
            "w"
        };

        char types[npar]= {
            T_INT, T_INT, T_INT, T_INT,
            T_INT, T_INT, T_INT, T_INT,
            T_INT, T_REAL, T_REAL, T_REAL,
            T_REAL, T_REAL, T_REAL, T_REAL ,
            T_REAL, T_REAL, T_REAL, T_REAL,
            T_REAL
        };

        OutputDF *dfs[npar]= {
            &df_nt, &df_nts, &df_np, &df_nx,
            &df_ny, &df_nz, &df_nfx, &df_nfy,
            &df_nfz, &df_tau, &df_xn, &df_yn,
            &df_zn, &df_pm, &df_sm, &df_radius,
            &df_dvr, &df_dvf, &df_dvz, &df_eps,
            &df_w
        };

        int ready[npar]= {0};
        int cpar=0;

        std::map<std::string,int> ids;

        int i;

        for (i=0; i<npar; i++) {
            ids[names[i]] = i;
        }

        FILE *f = fopen(filename,"r");

        if (f==NULL) {
            printf("c_read_parameters: Can't open file: %s\n",filename);
            df_ok.setValue(0);
            return;
        }

        char str[1024], sname[256], svalue[256], *s;

        int stop=0;
        int line=1;

        while (!stop) {
            if (fgets(str, 256, f) == NULL) {
                stop=1;
            } else {
                s=str;

                while (*s && isspace(*s)) {
                    s++;
                }

                if (*s!=0 && *s!='#') {
                    sscanf(s, "%s", sname);
                    s+=strlen(sname);
                    std::map<std::string,int>::iterator it=ids.find(sname);

                    if (it==ids.end()) {
                        printf("c_read_parameters: unknown parameter name '%s' in file %s (line %d)\n", sname, filename, line);
                        fflush(stdout);
                    } else {
                        int id=it->second;

                        while (*s && isspace(*s)) {
                            s++;
                        }

                        if (*s != 0 && *s != '#') {
                            sscanf(s, "%s", svalue);

                            switch (types[id]) {
                            case T_INT: {
                                int val;

                                if (!read_int(svalue, &val)) {
                                    printf("c_read_parameters: can't read integer parameter '%s' in file %s (line %d)\n", sname, filename, line);
                                    fflush(stdout);
                                } else {
                                    dfs[id]->setValue(val);
                                    ready[id]=1;
                                    cpar++;
                                }
                            }
                            break;

                            case T_REAL: {
                                double val;

                                if (!read_real(svalue, &val)) {
                                    printf("c_read_parameters: can't read real parameter '%s' in file %s (line %d)\n", sname, filename, line);
                                    fflush(stdout);
                                } else {
                                    dfs[id]->setValue(val);
                                    ready[id]=1;
                                    cpar++;
                                }
                            }
                            break;

                            default:
                                printf("c_read_parameters: unknown type of parameter '%s' in file %s (line %d)\n", sname, filename, line);
                                fflush(stdout);
                                break;
                            }
                        }
                    }
                }

                line++;
            }
        }

        fclose(f);

        if (cpar<npar) {
            df_ok.setValue(0);
            printf("c_read_parameters: reading file %s: parameters are not ready:",filename);

            for (int i=0; i<npar; i++) {
                if (!ready[i]) {
                    printf(" %s",names[i].c_str());

                    switch (types[i]) {
                    case T_INT:
                        dfs[i]->setValue(0);
                        break;

                    case T_REAL:
                        dfs[i]->setValue(0.0);
                        break;

                    default:
                        dfs[i]->setValue(0);
                        break;
                    }
                }
            }

            printf("\n");
            fflush(stdout);
        } else {
            df_ok.setValue(1);
        }
    }

#undef T_INT
#undef T_REAL

    void c_print_parameters(int nt, int nts, int np ,int nx, int ny, int nz, int nfx, int nfy, int nfz,
                            real xn, real yn, real zn, real tau, real pm, real sm, real radius, real dvr, real dvf, real dvz, real eps, real w)
    {
        printf("Mesh: %d x %d x %d / %d x %d x %d   Particles: %d   Steps: %d (%d)\n", nx, ny, nz, nfx, nfy, nfz, np, nt, nts);
        printf("Domain: %lf x %lf x %lf   Time step: %lf\n", xn, yn, zn, tau);
        printf("Particles mass: %lf   radius: %lf   vel.dispersion: %lf %lf %lf\n", pm, radius, dvr, dvf, dvz);
        printf("Sun mass      : %lf\n",sm);
        printf("Poisson solver threshold: %lf   acceleration parameter: %lf\n", eps, w);
        fflush(stdout);
    }

    void c_print_parameters_seq(int nt, int nts, int np, int nx, int ny, int nz, int nfx, int nfy, int nfz,
                                real xn, real yn, real zn, real tau, real pm, real sm, real radius, real dvr, real dvf, real dvz, real eps, real w,
                                const InputDF &df_prev, OutputDF &df_next)
    {
        c_print_parameters(nt, nts, np, nx, ny, nz, nfx, nfy, nfz, xn, yn, zn, tau, pm, sm, radius, dvr, dvf, dvz, eps, w);
        df_next.copy(df_prev);
    }

// Making initial particles distribution

    void c_init_particles_circle_xy_subdomain(int np, int kind, real x1, real y1, real z1, real x2, real y2, real z2,
            real cx, real cy, real cz, real radius, OutputDF &df_p, OutputDF &df_npfs)
    {
        std::vector<Particle> pv;
        fill_particles_circle_xy(np, kind, radius, cx, cy, cz, x1, y1, z1, x2, y2, z2, pv);
        int npfs=pv.size();
        Particle *p=df_p.create<Particle>(npfs);
        size_t j;

        for (j=0; j<npfs; j++) {
            p[j]=pv[j];
        }

        df_npfs.setValue(npfs);
    }

    void c_init_particles_circle_xz_subdomain(int np, int kind, real x1, real y1, real z1, real x2, real y2, real z2,
            real cx, real cy, real cz, real radius, OutputDF &df_p, OutputDF &df_npfs)
    {
        std::vector<Particle> pv;
        fill_particles_circle_xz(np, kind, radius, cx, cy, cz, x1, y1, z1, x2, y2, z2, pv);
        int npfs = pv.size();
        Particle *p = df_p.create<Particle>(npfs);
        size_t j;

        for (j=0; j<npfs; j++) {
            p[j]=pv[j];
        }

        df_npfs.setValue(npfs);
    }

    void c_init_particles_circle_yz_subdomain(int np, int kind, real x1, real y1, real z1, real x2, real y2, real z2,
            real cx, real cy, real cz, real radius, OutputDF &df_p, OutputDF &df_npfs)
    {
        std::vector<Particle> pv;
        fill_particles_circle_yz(np, kind, radius, cx, cy, cz, x1, y1, z1, x2, y2, z2, pv);
        int npfs=pv.size();
        Particle *p=df_p.create<Particle>(npfs);
        size_t j;

        for (j=0; j<npfs; j++) {
            p[j]=pv[j];
        }

        df_npfs.setValue(npfs);
    }

    void c_init_particles_ball_subdomain(int np, int kind, real x1, real y1, real z1, real x2, real y2, real z2,
                                         real cx, real cy, real cz, real radius, OutputDF &df_p, OutputDF &df_npfs)
    {
        std::vector<Particle> pv;
        fill_particles_ball(np,kind,radius,cx,cy,cz,x1,y1,z1,x2,y2,z2,pv);
        int npfs = pv.size();
        Particle *p = df_p.create<Particle>(npfs);
        size_t j;

        for (j=0; j<npfs; j++) {
            p[j] = pv[j];
        }

        df_npfs.setValue(npfs);
    }

    void c_init_particles_full_subdomain(int np, real x1, real y1, real z1, real x2, real y2, real z2, OutputDF &df_p, OutputDF &df_npfs)
    {
        std::vector<Particle> pv;
        fill_particles_full(np, x1, y1, z1, x2, y2, z1, pv);
        int npfs=pv.size();
        Particle *p=df_p.create<Particle>(npfs);
        size_t j;

        for (j=0; j<npfs; j++) {
            p[j]=pv[j];
        }

        df_npfs.setValue(npfs);
    }

    void c_init_particles_velocity_z_subdomain(int nx, int ny, int nz, int sx, int sy, int sz,
            real hx, real hy, real hz, real cx, real cy, real cz, real dvr, real dvf, real dvz, int wave, real tau, real emax,
            InputDF &df_fx, const InputDF &df_fy, const InputDF &df_fz, const InputDF &df_fi, int np, const InputDF &df_p,
            OutputDF &df_p_new)
    {
        assert(df_p.getSize()==np*sizeof(Particle));
        assert(df_fx.getSize()==nx*ny*nz*sizeof(real));
        assert(df_fy.getSize()==nx*ny*nz*sizeof(real));
        assert(df_fz.getSize()==nx*ny*nz*sizeof(real));
        assert(df_fi.getSize()==nx*ny*nz*sizeof(real));
        const real *fx=df_fx.getData<real>();
        const real *fy=df_fy.getData<real>();
        const real *fz=df_fz.getData<real>();
        const real *fi=df_fi.getData<real>();
        const Particle *p=df_p.getData<Particle>();
        Particle *p_new=df_p_new.create<Particle>(np);
        memcpy(p_new, p, np*sizeof(Particle));
        init_particles_velocity_z(nx, ny, nz, sx, sy, sz, hx, hy, hz, cx, cy, cz, dvr, dvf, dvz, wave, tau, emax, fi, fx, fy, fz, np, p_new);
    }

    void c_init_particles_velocity_y_subdomain(int nx, int ny, int nz, int sx, int sy, int sz,
            real hx, real hy, real hz, real cx, real cy, real cz, real dvr, real dvf, real dvy, int wave, real tau, real emax,
            InputDF &df_fx, const InputDF &df_fy, const InputDF &df_fz, const InputDF &df_fi, int np, const InputDF &df_p,
            OutputDF &df_p_new)
    {
        assert(df_p.getSize()==np*sizeof(Particle));
        assert(df_fx.getSize()==nx*ny*nz*sizeof(real));
        assert(df_fy.getSize()==nx*ny*nz*sizeof(real));
        assert(df_fz.getSize()==nx*ny*nz*sizeof(real));
        assert(df_fi.getSize()==nx*ny*nz*sizeof(real));
        const real *fx=df_fx.getData<real>();
        const real *fy=df_fy.getData<real>();
        const real *fz=df_fz.getData<real>();
        const real *fi=df_fi.getData<real>();
        const Particle *p=df_p.getData<Particle>();
        Particle *p_new=df_p_new.create<Particle>(np);
        memcpy(p_new,p,np*sizeof(Particle));
        init_particles_velocity_y(nx, ny, nz, sx, sy, sz, hx, hy, hz, cx, cy, cz, dvr, dvf, dvy, wave, tau, emax, fi, fx, fy, fz, np, p_new);
    }

    void c_init_particles_velocity_x_subdomain(int nx, int ny, int nz, int sx, int sy, int sz,
            real hx, real hy, real hz, real cx, real cy, real cz, real dvr, real dvf, real dvx, int wave, real tau, real emax,
            InputDF &df_fx, const InputDF &df_fy, const InputDF &df_fz, const InputDF &df_fi, int np, const InputDF &df_p,
            OutputDF &df_p_new)
    {
        assert(df_p.getSize()==np*sizeof(Particle));
        assert(df_fx.getSize()==nx*ny*nz*sizeof(real));
        assert(df_fy.getSize()==nx*ny*nz*sizeof(real));
        assert(df_fz.getSize()==nx*ny*nz*sizeof(real));
        assert(df_fi.getSize()==nx*ny*nz*sizeof(real));
        const real *fx=df_fx.getData<real>();
        const real *fy=df_fy.getData<real>();
        const real *fz=df_fz.getData<real>();
        const real *fi=df_fi.getData<real>();
        const Particle *p=df_p.getData<Particle>();
        Particle *p_new=df_p_new.create<Particle>(np);
        memcpy(p_new, p, np*sizeof(Particle));
        init_particles_velocity_x(nx, ny, nz, sx, sy, sz, hx, hy, hz, cx, cy, cz, dvr, dvf, dvx, wave, tau, emax, fi, fx, fy, fz, np, p_new);
    }

    void c_init_particles_velocity_ball_subdomain(int nx, int ny, int nz, int sx, int sy, int sz,
            real hx, real hy, real hz, real cx, real cy, real cz, real dvr, real dvf, real dvz, real tau, real emax,
            InputDF &df_fx, const InputDF &df_fy, const InputDF &df_fz, const InputDF &df_fi, int np, const InputDF &df_p,
            OutputDF &df_p_new)
    {
        assert(df_p.getSize()==np*sizeof(Particle));
        assert(df_fx.getSize()==nx*ny*nz*sizeof(real));
        assert(df_fy.getSize()==nx*ny*nz*sizeof(real));
        assert(df_fz.getSize()==nx*ny*nz*sizeof(real));
        assert(df_fi.getSize()==nx*ny*nz*sizeof(real));
        const real *fx=df_fx.getData<real>();
        const real *fy=df_fy.getData<real>();
        const real *fz=df_fz.getData<real>();
        const real *fi=df_fi.getData<real>();
        const Particle *p=df_p.getData<Particle>();
        Particle *p_new=df_p_new.create<Particle>(np);
        memcpy(p_new,p,np*sizeof(Particle));
        init_particles_velocity_ball(nx, ny, nz, sx, sy, sz, hx, hy, hz, cx, cy, cz, dvr, dvf, dvz, tau, emax, fi, fx, fy, fz, np, p_new);
    }

    void c_unite_particles_subdomain(const InputDF &df_p1, int np1, const InputDF &df_p2, int np2, OutputDF &df_p, OutputDF &df_np)
    {
        assert(df_p1.getSize()==np1*sizeof(Particle));
        assert(df_p2.getSize()==np2*sizeof(Particle));
        const Particle *p1=df_p1.getData<Particle>();
        const Particle *p2=df_p2.getData<Particle>();
        Particle *p=df_p.create<Particle>(np1+np2);
        memcpy(p, p1, np1*sizeof(Particle));
        memcpy(p+np1, p2, np2*sizeof(Particle));
        df_np.setValue(np1+np2);
    }

// Count subroutines

    void c_init_array3d_subdomain(int nx, int ny, int nz, int sx, int sy, int sz, real hx, real hy, real hz, OutputDF &df_u)
    {
        real *u=df_u.create<real>(nx*ny*nz);
        init_array3d(nx, ny, nz, sx, sy, sz, hx, hy, hz, u);
    }

    void c_density_subdomain(int nx, int ny, int nz, int sx, int sy, int sz, real hx, real hy, real hz, real am, const InputDF &df_p, int np, OutputDF &df_ro)
    {
        assert(df_p.getSize()==np*sizeof(Particle));
        const Particle *p=df_p.getData<Particle>();
        real *ro=df_ro.create<real>(nx*ny*nz);
        density(nx, ny, nz, sx, sy, sz, hx, hy, hz, am, p, np, ro);
    }

    void c_move_particles_subdomain(int nx, int ny, int nz, int sx, int sy, int sz, real hx, real hy, real hz,
                                    const InputDF &df_fx, const InputDF &df_fy, const InputDF &df_fz, real tau, int np, const InputDF &df_p, OutputDF &df_pnew)
    {
        assert(df_fx.getSize()==nx*ny*nz*sizeof(real));
        assert(df_fy.getSize()==nx*ny*nz*sizeof(real));
        assert(df_fz.getSize()==nx*ny*nz*sizeof(real));
        assert(df_p.getSize()==np*sizeof(Particle));
        const real *fx=df_fx.getData<real>();
        const real *fy=df_fy.getData<real>();
        const real *fz=df_fz.getData<real>();
        const Particle *p=df_p.getData<Particle>();
        Particle *pnew=df_pnew.create<Particle>(np);
        memcpy(pnew,p,np*sizeof(Particle));
        move_particles(nx, ny, nz, sx, sy, sz, hx, hy, hz, fx, fy, fz, tau, np, pnew);
    }

    void c_init_fi_subdomain(int nfx, int nfy, int nfz, int ifx, int ify, int ifz,
                             int nx, int ny, int nz, int sx, int sy, int sz,
                             real hx, real hy, real hz, real cx, real cy, real cz, real mass, OutputDF &df_fi)
    {
        real *fi=df_fi.create<real>(nx*ny*nz);
        poisson_init(nx, ny, nz, sx, sy, sz, hx, hy, hz, fi);
        poisson_edge_simple(nfx, nfy, nfz, ifx, ify, ifz, nx, ny, nz, sx, sy, sz, hx, hy, hz, cx, cy, cz, mass, fi);
    }

    void c_fi_dobavka_subdomain(int nfx, int nfy, int nfz, int ifx, int ify, int ifz, int nx, int ny, int nz, int sx, int sy, int sz, real hx, real hy, real hz, real cx, real cy, real cz, real sm, const InputDF &df_fp, OutputDF &df_fi)
    {
        assert(df_fp.getSize()==nx*ny*nz*sizeof(real));
        const real *fp=df_fp.getData<real>();
        real *fi=df_fi.create<real>(nx*ny*nz);
        fi_dobavka(nfx, nfy, nfz, ifx, ify, ifz, nx, ny, nz, sx, sy, sz, hx, hy, hz, cx, cy, cz, sm, fp, fi);
    }

    void c_force_subdomain(int nx, int ny, int nz, real hx, real hy, real hz, const InputDF &df_fi, OutputDF &df_fx, OutputDF &df_fy, OutputDF &df_fz)
    {
        const real *fi=df_fi.getData<real>();
        real *fx=df_fx.create<real>(nx*ny*nz);
        real *fy=df_fy.create<real>(nx*ny*nz);
        real *fz=df_fz.create<real>(nx*ny*nz);
        force(nx, ny, nz, hx, hy, hz, fi, fx, fy, fz);
    }

// Writing logs

    void c_get_properties_subdomain(int nx, int ny, int nz, int sx, int sy, int sz, real hx, real hy, real hz,
                                    real cx, real cy, real cz, real sm, const InputDF &df_fi, const InputDF &df_p, int np, OutputDF &df_prop)
    {
        assert(df_fi.getSize()==nx*ny*nz*sizeof(real));
        assert(df_p.getSize()==np*sizeof(Particle));
        const real *fi=df_fi.getData<real>();
        const Particle *p=df_p.getData<Particle>();
        real *prop=df_prop.create<real>(13);
        get_properties(nx, ny, nz, sx, sy, sz, hx, hy, hz, cx, cy, cz, sm, fi, np, p, prop);
    }

    void c_get_properties_finish(real am, real pm, const InputDF &df_prop0, OutputDF &df_prop)
    {
        assert(df_prop0.getSize()==13*sizeof(real));
        const real *prop0=df_prop0.getData<real>();
        Properties *prop=df_prop.create<Properties>(1);
        get_properties_finish(am, pm, prop0, prop);
    }

    void c_print_properties_seq(const char *filename, const InputDF &df_prop, int it, real cx, real cy, real cz, const InputDF &prev, OutputDF &next)
    {
        assert(df_prop.getSize()==sizeof(Properties));
        const Properties *prop=df_prop.getData<Properties>();
        print_properties(filename, prop, it, cx, cy, cz);
        next.copy(prev);
    }

// Other CFs

    void c_print_x(int ifx, int nx, int sx, real hx)
    {
        print_x(ifx, nx, sx, hx);
    }

    void c_print_y(int ify, int ny, int sy, real hy)
    {
        print_y(ify, ny, sy, hy);
    }

    void c_print_z(int ifz, int nz, int sz, real hz)
    {
        print_z(ifz,nz,sz,hz);
    }

    void c_print_x_seq(int ifx, int nx, int sx, real hx, const InputDF &prev, OutputDF &next)
    {
        print_x(ifx, nx, sx, hx);
        next.copy(prev);
    }

    void c_print_y_seq(int ify, int ny, int sy, real hy, const InputDF &prev, OutputDF &next)
    {
        print_y(ify, ny, sy, hy);
        next.copy(prev);
    }

    void c_print_z_seq(int ifz, int nz, int sz, real hz, const InputDF &prev, OutputDF &next)
    {
        print_z(ifz, nz, sz, hz);
        next.copy(prev);
    }

    void c_print_one_particle(const char *msg, int np, const InputDF &df_p)
    {
        assert(df_p.getSize()==np*sizeof(Particle));
        const Particle *p=df_p.getData<Particle>();
        printf("x(%.18lf %.18lf %.18lf) v(%.18lf %.18lf %.18lf) : %s\n", p[0].x, p[0].y, p[0].z, p[0].u, p[0].v, p[0].w, msg);
        fflush(stdout);
    }
}