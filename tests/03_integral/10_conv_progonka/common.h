#ifndef COMMON_H
#define COMMON_H
#define aar(i,j,k) a[(i)*rny*rnz+(j)*rnz+(k)]
#define bar(i,j,k) b[(i)*rny*rnz+(j)*rnz+(k)]
#define car(i,j,k) c[(i)*rny*rnz+(j)*rnz+(k)]
#define far(i,j,k) f[(i)*rny*rnz+(j)*rnz+(k)]
#define uar(i,j,k) u[(i)*rny*rnz+(j)*rnz+(k)]
#define uOldar(i,j,k) uOld[(i)*rny*rnz+(j)*rnz+(k)]
#define alfaar(i,j) alfa[(i)*rnt+(j)]
#define betaar(i,j) beta[(i)*rnt+(j)]
#define uallar(i,j,k) u[(i)*ny*nz+(j)*nz+(k)]
struct str_params{
    int nx;
    int ny;
    int nz;
    double T;
    double tau;
    double hx;
    double hy;
    double hz;
    double hx2;
    double hy2;
    double hz2;
    int tprint;
    int rnx;
    int rny;
    int rnz;
    int beg_index_x;
    int end_index_x;
    int beg_index_y;
    int end_index_y;
    int beg_index_z;
    int end_index_z;
    int size_x;
    int size_y;
    int size_z;
    int rank_x;
    int rank_y;
    int rank_z;

};
#endif // COMMON_H
