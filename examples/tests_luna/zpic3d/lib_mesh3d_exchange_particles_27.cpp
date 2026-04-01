#include "ucenv.h"
#include "lib_basic.h"
#include <vector>
#include "pic3d_utils.h"

#define D000 0
#define D001 1
#define D002 2
#define D010 3
#define D011 4
#define D012 5
#define D020 6
#define D021 7
#define D022 8
#define D100 9
#define D101 10
#define D102 11
#define D110 12
#define D111 13
#define D112 14
#define D120 15
#define D121 16
#define D122 17
#define D200 18
#define D201 19
#define D202 20
#define D210 21
#define D211 22
#define D212 23
#define D220 24
#define D221 25
#define D222 26
static int code2dir[44]={ D111,D110,D112, -1,D101,D100,D102, -1,D121,D120,D122, -1, -1, -1, -1, -1,
                          D011,D010,D012, -1,D001,D000,D002, -1,D021,D020,D022, -1, -1, -1, -1, -1,
                          D211,D210,D212, -1,D201,D200,D202, -1,D221,D220,D222, -1 };

typedef real itemtype;

extern "C"
{

void c_mesh3d_exchange_particles_27_copy_00_00_00(int np,InputDF &df_p,real x1,real y1,real z1,real x2,real y2,real z2,OutputDF &df_npnew,OutputDF &df_pnew)
{ int j;
  assert(df_p.getSize() == np*sizeof(Particle));
  const Particle *p = df_p.getData<Particle>();
  Particle *pnew = df_pnew.create<Particle>(np);
  for (j=0;j<np;j++)
  {
    real x = p[j].x;
    real y = p[j].y;
    real z = p[j].z;
    real u = p[j].u;
    real v = p[j].v;
    real w = p[j].w;
    if (x<x1) { x = 2*x1-x; u = -u; }
    else if (x>=x2) { x = 2*x2-x; u = -u; }
    if (y<y1) { y = 2*y1-y; v = -v; }
    else if (y>=y2) { y = 2*y2-y; v = -v; }
    if (z<z1) { z = 2*z1-z; w = -w; }
    else if (z>=z2) { z = 2*z2-z; w = -w; }
    pnew[j].x = x;
    pnew[j].y = y;
    pnew[j].z = z;
    pnew[j].u = u;
    pnew[j].v = v;
    pnew[j].w = w;
  }
  df_npnew.setValue(np);
}

void c_mesh3d_exchange_particles_27_get_00_00_01(int np,const InputDF &df_p,real x1,real y1,real z1,real x2,real y2,real z2,
  OutputDF &dfb111,OutputDF &dfb112)
{ int j;
  assert(df_p.getSize() == np*sizeof(Particle));
  const Particle *p = df_p.getData<Particle>();
  std::vector<Particle> vp[27];
  for (j=0;j<np;j++)
  {
    real x = p[j].x;
    real y = p[j].y;
    real z = p[j].z;
    real u = p[j].u;
    real v = p[j].v;
    real w = p[j].w;
    int code = 0;
    if (x<x1) { x = 2*x1-x; u = -u; }
    else if (x>=x2) { x = 2*x2-x; u = -u; }
    if (y<y1) { y = 2*y1-y; v = -v; }
    else if (y>=y2) { y = 2*y2-y; v = -v; }
    if (z<z1) { z = 2*z1-z; w = -w; }
    else if (z>=z2) code += 2;
    int dir = code2dir[code];
    vp[dir].push_back(Particle(x,y,z,u,v,w));
  }
  assert(vp[D000].size() == 0);
  assert(vp[D001].size() == 0);
  assert(vp[D002].size() == 0);
  assert(vp[D010].size() == 0);
  assert(vp[D011].size() == 0);
  assert(vp[D012].size() == 0);
  assert(vp[D020].size() == 0);
  assert(vp[D021].size() == 0);
  assert(vp[D022].size() == 0);
  assert(vp[D100].size() == 0);
  assert(vp[D101].size() == 0);
  assert(vp[D102].size() == 0);
  assert(vp[D110].size() == 0);
  { int np = vp[D111].size();
    int j1;
    Particle *b111 = dfb111.create<Particle>(np);
    for (j=0;j<np;j++) b111[j] = vp[D111][j];
  }
  { int np = vp[D112].size();
    int j1;
    Particle *b112 = dfb112.create<Particle>(np);
    for (j=0;j<np;j++) b112[j] = vp[D112][j];
  }
  assert(vp[D120].size() == 0);
  assert(vp[D121].size() == 0);
  assert(vp[D122].size() == 0);
  assert(vp[D200].size() == 0);
  assert(vp[D201].size() == 0);
  assert(vp[D202].size() == 0);
  assert(vp[D210].size() == 0);
  assert(vp[D211].size() == 0);
  assert(vp[D212].size() == 0);
  assert(vp[D220].size() == 0);
  assert(vp[D221].size() == 0);
  assert(vp[D222].size() == 0);
}

void c_mesh3d_exchange_particles_27_set_00_00_01(
  const InputDF &dfb111,const InputDF &dfb112,
  OutputDF &dfnp,OutputDF &dfp)
{ int np = (dfb111.getSize()+dfb112.getSize())/sizeof(Particle);
  int j = 0;
  Particle *p =  dfp.create<Particle>(np);
  { const Particle *b111 = dfb111.getData<Particle>();
    assert(dfb111.getSize() % sizeof(Particle) == 0);
    int np1 = dfb111.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b111[j1];
  }
  { const Particle *b112 = dfb112.getData<Particle>();
    assert(dfb112.getSize() % sizeof(Particle) == 0);
    int np1 = dfb112.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b112[j1];
  }
  dfnp.setValue(np);
}

void c_mesh3d_exchange_particles_27_get_00_00_10(int np,const InputDF &df_p,real x1,real y1,real z1,real x2,real y2,real z2,
  OutputDF &dfb110,OutputDF &dfb111)
{ int j;
  assert(df_p.getSize() == np*sizeof(Particle));
  const Particle *p = df_p.getData<Particle>();
  std::vector<Particle> vp[27];
  for (j=0;j<np;j++)
  {
    real x = p[j].x;
    real y = p[j].y;
    real z = p[j].z;
    real u = p[j].u;
    real v = p[j].v;
    real w = p[j].w;
    int code = 0;
    if (x<x1) { x = 2*x1-x; u = -u; }
    else if (x>=x2) { x = 2*x2-x; u = -u; }
    if (y<y1) { y = 2*y1-y; v = -v; }
    else if (y>=y2) { y = 2*y2-y; v = -v; }
    if (z<z1) code += 1;
    else if (z>=z2) { z = 2*z2-z; w = -w; }
    int dir = code2dir[code];
    vp[dir].push_back(Particle(x,y,z,u,v,w));
  }
  assert(vp[D000].size() == 0);
  assert(vp[D001].size() == 0);
  assert(vp[D002].size() == 0);
  assert(vp[D010].size() == 0);
  assert(vp[D011].size() == 0);
  assert(vp[D012].size() == 0);
  assert(vp[D020].size() == 0);
  assert(vp[D021].size() == 0);
  assert(vp[D022].size() == 0);
  assert(vp[D100].size() == 0);
  assert(vp[D101].size() == 0);
  assert(vp[D102].size() == 0);
  { int np = vp[D110].size();
    int j1;
    Particle *b110 = dfb110.create<Particle>(np);
    for (j=0;j<np;j++) b110[j] = vp[D110][j];
  }
  { int np = vp[D111].size();
    int j1;
    Particle *b111 = dfb111.create<Particle>(np);
    for (j=0;j<np;j++) b111[j] = vp[D111][j];
  }
  assert(vp[D112].size() == 0);
  assert(vp[D120].size() == 0);
  assert(vp[D121].size() == 0);
  assert(vp[D122].size() == 0);
  assert(vp[D200].size() == 0);
  assert(vp[D201].size() == 0);
  assert(vp[D202].size() == 0);
  assert(vp[D210].size() == 0);
  assert(vp[D211].size() == 0);
  assert(vp[D212].size() == 0);
  assert(vp[D220].size() == 0);
  assert(vp[D221].size() == 0);
  assert(vp[D222].size() == 0);
}

void c_mesh3d_exchange_particles_27_set_00_00_10(
  const InputDF &dfb110,const InputDF &dfb111,
  OutputDF &dfnp,OutputDF &dfp)
{ int np = (dfb110.getSize()+dfb111.getSize())/sizeof(Particle);
  int j = 0;
  Particle *p =  dfp.create<Particle>(np);
  { const Particle *b110 = dfb110.getData<Particle>();
    assert(dfb110.getSize() % sizeof(Particle) == 0);
    int np1 = dfb110.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b110[j1];
  }
  { const Particle *b111 = dfb111.getData<Particle>();
    assert(dfb111.getSize() % sizeof(Particle) == 0);
    int np1 = dfb111.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b111[j1];
  }
  dfnp.setValue(np);
}

void c_mesh3d_exchange_particles_27_get_00_00_11(int np,const InputDF &df_p,real x1,real y1,real z1,real x2,real y2,real z2,
  OutputDF &dfb110,OutputDF &dfb111,OutputDF &dfb112)
{ int j;
  assert(df_p.getSize() == np*sizeof(Particle));
  const Particle *p = df_p.getData<Particle>();
  std::vector<Particle> vp[27];
  for (j=0;j<np;j++)
  {
    real x = p[j].x;
    real y = p[j].y;
    real z = p[j].z;
    real u = p[j].u;
    real v = p[j].v;
    real w = p[j].w;
    int code = 0;
    if (x<x1) { x = 2*x1-x; u = -u; }
    else if (x>=x2) { x = 2*x2-x; u = -u; }
    if (y<y1) { y = 2*y1-y; v = -v; }
    else if (y>=y2) { y = 2*y2-y; v = -v; }
    if (z<z1) code += 1;
    else if (z>=z2) code += 2;
    int dir = code2dir[code];
    vp[dir].push_back(Particle(x,y,z,u,v,w));
  }
  assert(vp[D000].size() == 0);
  assert(vp[D001].size() == 0);
  assert(vp[D002].size() == 0);
  assert(vp[D010].size() == 0);
  assert(vp[D011].size() == 0);
  assert(vp[D012].size() == 0);
  assert(vp[D020].size() == 0);
  assert(vp[D021].size() == 0);
  assert(vp[D022].size() == 0);
  assert(vp[D100].size() == 0);
  assert(vp[D101].size() == 0);
  assert(vp[D102].size() == 0);
  { int np = vp[D110].size();
    int j1;
    Particle *b110 = dfb110.create<Particle>(np);
    for (j=0;j<np;j++) b110[j] = vp[D110][j];
  }
  { int np = vp[D111].size();
    int j1;
    Particle *b111 = dfb111.create<Particle>(np);
    for (j=0;j<np;j++) b111[j] = vp[D111][j];
  }
  { int np = vp[D112].size();
    int j1;
    Particle *b112 = dfb112.create<Particle>(np);
    for (j=0;j<np;j++) b112[j] = vp[D112][j];
  }
  assert(vp[D120].size() == 0);
  assert(vp[D121].size() == 0);
  assert(vp[D122].size() == 0);
  assert(vp[D200].size() == 0);
  assert(vp[D201].size() == 0);
  assert(vp[D202].size() == 0);
  assert(vp[D210].size() == 0);
  assert(vp[D211].size() == 0);
  assert(vp[D212].size() == 0);
  assert(vp[D220].size() == 0);
  assert(vp[D221].size() == 0);
  assert(vp[D222].size() == 0);
}

void c_mesh3d_exchange_particles_27_set_00_00_11(
  const InputDF &dfb110,const InputDF &dfb111,const InputDF &dfb112,
  OutputDF &dfnp,OutputDF &dfp)
{ int np = (dfb110.getSize()+dfb111.getSize()+dfb112.getSize())/sizeof(Particle);
  int j = 0;
  Particle *p =  dfp.create<Particle>(np);
  { const Particle *b110 = dfb110.getData<Particle>();
    assert(dfb110.getSize() % sizeof(Particle) == 0);
    int np1 = dfb110.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b110[j1];
  }
  { const Particle *b111 = dfb111.getData<Particle>();
    assert(dfb111.getSize() % sizeof(Particle) == 0);
    int np1 = dfb111.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b111[j1];
  }
  { const Particle *b112 = dfb112.getData<Particle>();
    assert(dfb112.getSize() % sizeof(Particle) == 0);
    int np1 = dfb112.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b112[j1];
  }
  dfnp.setValue(np);
}

void c_mesh3d_exchange_particles_27_get_00_01_00(int np,const InputDF &df_p,real x1,real y1,real z1,real x2,real y2,real z2,
  OutputDF &dfb111,OutputDF &dfb121)
{ int j;
  assert(df_p.getSize() == np*sizeof(Particle));
  const Particle *p = df_p.getData<Particle>();
  std::vector<Particle> vp[27];
  for (j=0;j<np;j++)
  {
    real x = p[j].x;
    real y = p[j].y;
    real z = p[j].z;
    real u = p[j].u;
    real v = p[j].v;
    real w = p[j].w;
    int code = 0;
    if (x<x1) { x = 2*x1-x; u = -u; }
    else if (x>=x2) { x = 2*x2-x; u = -u; }
    if (y<y1) { y = 2*y1-y; v = -v; }
    else if (y>=y2) code += 8;
    if (z<z1) { z = 2*z1-z; w = -w; }
    else if (z>=z2) { z = 2*z2-z; w = -w; }
    int dir = code2dir[code];
    vp[dir].push_back(Particle(x,y,z,u,v,w));
  }
  assert(vp[D000].size() == 0);
  assert(vp[D001].size() == 0);
  assert(vp[D002].size() == 0);
  assert(vp[D010].size() == 0);
  assert(vp[D011].size() == 0);
  assert(vp[D012].size() == 0);
  assert(vp[D020].size() == 0);
  assert(vp[D021].size() == 0);
  assert(vp[D022].size() == 0);
  assert(vp[D100].size() == 0);
  assert(vp[D101].size() == 0);
  assert(vp[D102].size() == 0);
  assert(vp[D110].size() == 0);
  { int np = vp[D111].size();
    int j1;
    Particle *b111 = dfb111.create<Particle>(np);
    for (j=0;j<np;j++) b111[j] = vp[D111][j];
  }
  assert(vp[D112].size() == 0);
  assert(vp[D120].size() == 0);
  { int np = vp[D121].size();
    int j1;
    Particle *b121 = dfb121.create<Particle>(np);
    for (j=0;j<np;j++) b121[j] = vp[D121][j];
  }
  assert(vp[D122].size() == 0);
  assert(vp[D200].size() == 0);
  assert(vp[D201].size() == 0);
  assert(vp[D202].size() == 0);
  assert(vp[D210].size() == 0);
  assert(vp[D211].size() == 0);
  assert(vp[D212].size() == 0);
  assert(vp[D220].size() == 0);
  assert(vp[D221].size() == 0);
  assert(vp[D222].size() == 0);
}

void c_mesh3d_exchange_particles_27_set_00_01_00(
  const InputDF &dfb111,const InputDF &dfb121,
  OutputDF &dfnp,OutputDF &dfp)
{ int np = (dfb111.getSize()+dfb121.getSize())/sizeof(Particle);
  int j = 0;
  Particle *p =  dfp.create<Particle>(np);
  { const Particle *b111 = dfb111.getData<Particle>();
    assert(dfb111.getSize() % sizeof(Particle) == 0);
    int np1 = dfb111.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b111[j1];
  }
  { const Particle *b121 = dfb121.getData<Particle>();
    assert(dfb121.getSize() % sizeof(Particle) == 0);
    int np1 = dfb121.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b121[j1];
  }
  dfnp.setValue(np);
}

void c_mesh3d_exchange_particles_27_get_00_01_01(int np,const InputDF &df_p,real x1,real y1,real z1,real x2,real y2,real z2,
  OutputDF &dfb111,OutputDF &dfb112,OutputDF &dfb121,OutputDF &dfb122)
{ int j;
  assert(df_p.getSize() == np*sizeof(Particle));
  const Particle *p = df_p.getData<Particle>();
  std::vector<Particle> vp[27];
  for (j=0;j<np;j++)
  {
    real x = p[j].x;
    real y = p[j].y;
    real z = p[j].z;
    real u = p[j].u;
    real v = p[j].v;
    real w = p[j].w;
    int code = 0;
    if (x<x1) { x = 2*x1-x; u = -u; }
    else if (x>=x2) { x = 2*x2-x; u = -u; }
    if (y<y1) { y = 2*y1-y; v = -v; }
    else if (y>=y2) code += 8;
    if (z<z1) { z = 2*z1-z; w = -w; }
    else if (z>=z2) code += 2;
    int dir = code2dir[code];
    vp[dir].push_back(Particle(x,y,z,u,v,w));
  }
  assert(vp[D000].size() == 0);
  assert(vp[D001].size() == 0);
  assert(vp[D002].size() == 0);
  assert(vp[D010].size() == 0);
  assert(vp[D011].size() == 0);
  assert(vp[D012].size() == 0);
  assert(vp[D020].size() == 0);
  assert(vp[D021].size() == 0);
  assert(vp[D022].size() == 0);
  assert(vp[D100].size() == 0);
  assert(vp[D101].size() == 0);
  assert(vp[D102].size() == 0);
  assert(vp[D110].size() == 0);
  { int np = vp[D111].size();
    int j1;
    Particle *b111 = dfb111.create<Particle>(np);
    for (j=0;j<np;j++) b111[j] = vp[D111][j];
  }
  { int np = vp[D112].size();
    int j1;
    Particle *b112 = dfb112.create<Particle>(np);
    for (j=0;j<np;j++) b112[j] = vp[D112][j];
  }
  assert(vp[D120].size() == 0);
  { int np = vp[D121].size();
    int j1;
    Particle *b121 = dfb121.create<Particle>(np);
    for (j=0;j<np;j++) b121[j] = vp[D121][j];
  }
  { int np = vp[D122].size();
    int j1;
    Particle *b122 = dfb122.create<Particle>(np);
    for (j=0;j<np;j++) b122[j] = vp[D122][j];
  }
  assert(vp[D200].size() == 0);
  assert(vp[D201].size() == 0);
  assert(vp[D202].size() == 0);
  assert(vp[D210].size() == 0);
  assert(vp[D211].size() == 0);
  assert(vp[D212].size() == 0);
  assert(vp[D220].size() == 0);
  assert(vp[D221].size() == 0);
  assert(vp[D222].size() == 0);
}

void c_mesh3d_exchange_particles_27_set_00_01_01(
  const InputDF &dfb111,const InputDF &dfb112,const InputDF &dfb121,const InputDF &dfb122,
  OutputDF &dfnp,OutputDF &dfp)
{ int np = (dfb111.getSize()+dfb112.getSize()+dfb121.getSize()+dfb122.getSize())/sizeof(Particle);
  int j = 0;
  Particle *p =  dfp.create<Particle>(np);
  { const Particle *b111 = dfb111.getData<Particle>();
    assert(dfb111.getSize() % sizeof(Particle) == 0);
    int np1 = dfb111.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b111[j1];
  }
  { const Particle *b112 = dfb112.getData<Particle>();
    assert(dfb112.getSize() % sizeof(Particle) == 0);
    int np1 = dfb112.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b112[j1];
  }
  { const Particle *b121 = dfb121.getData<Particle>();
    assert(dfb121.getSize() % sizeof(Particle) == 0);
    int np1 = dfb121.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b121[j1];
  }
  { const Particle *b122 = dfb122.getData<Particle>();
    assert(dfb122.getSize() % sizeof(Particle) == 0);
    int np1 = dfb122.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b122[j1];
  }
  dfnp.setValue(np);
}

void c_mesh3d_exchange_particles_27_get_00_01_10(int np,const InputDF &df_p,real x1,real y1,real z1,real x2,real y2,real z2,
  OutputDF &dfb110,OutputDF &dfb111,OutputDF &dfb120,OutputDF &dfb121)
{ int j;
  assert(df_p.getSize() == np*sizeof(Particle));
  const Particle *p = df_p.getData<Particle>();
  std::vector<Particle> vp[27];
  for (j=0;j<np;j++)
  {
    real x = p[j].x;
    real y = p[j].y;
    real z = p[j].z;
    real u = p[j].u;
    real v = p[j].v;
    real w = p[j].w;
    int code = 0;
    if (x<x1) { x = 2*x1-x; u = -u; }
    else if (x>=x2) { x = 2*x2-x; u = -u; }
    if (y<y1) { y = 2*y1-y; v = -v; }
    else if (y>=y2) code += 8;
    if (z<z1) code += 1;
    else if (z>=z2) { z = 2*z2-z; w = -w; }
    int dir = code2dir[code];
    vp[dir].push_back(Particle(x,y,z,u,v,w));
  }
  assert(vp[D000].size() == 0);
  assert(vp[D001].size() == 0);
  assert(vp[D002].size() == 0);
  assert(vp[D010].size() == 0);
  assert(vp[D011].size() == 0);
  assert(vp[D012].size() == 0);
  assert(vp[D020].size() == 0);
  assert(vp[D021].size() == 0);
  assert(vp[D022].size() == 0);
  assert(vp[D100].size() == 0);
  assert(vp[D101].size() == 0);
  assert(vp[D102].size() == 0);
  { int np = vp[D110].size();
    int j1;
    Particle *b110 = dfb110.create<Particle>(np);
    for (j=0;j<np;j++) b110[j] = vp[D110][j];
  }
  { int np = vp[D111].size();
    int j1;
    Particle *b111 = dfb111.create<Particle>(np);
    for (j=0;j<np;j++) b111[j] = vp[D111][j];
  }
  assert(vp[D112].size() == 0);
  { int np = vp[D120].size();
    int j1;
    Particle *b120 = dfb120.create<Particle>(np);
    for (j=0;j<np;j++) b120[j] = vp[D120][j];
  }
  { int np = vp[D121].size();
    int j1;
    Particle *b121 = dfb121.create<Particle>(np);
    for (j=0;j<np;j++) b121[j] = vp[D121][j];
  }
  assert(vp[D122].size() == 0);
  assert(vp[D200].size() == 0);
  assert(vp[D201].size() == 0);
  assert(vp[D202].size() == 0);
  assert(vp[D210].size() == 0);
  assert(vp[D211].size() == 0);
  assert(vp[D212].size() == 0);
  assert(vp[D220].size() == 0);
  assert(vp[D221].size() == 0);
  assert(vp[D222].size() == 0);
}

void c_mesh3d_exchange_particles_27_set_00_01_10(
  const InputDF &dfb110,const InputDF &dfb111,const InputDF &dfb120,const InputDF &dfb121,
  OutputDF &dfnp,OutputDF &dfp)
{ int np = (dfb110.getSize()+dfb111.getSize()+dfb120.getSize()+dfb121.getSize())/sizeof(Particle);
  int j = 0;
  Particle *p =  dfp.create<Particle>(np);
  { const Particle *b110 = dfb110.getData<Particle>();
    assert(dfb110.getSize() % sizeof(Particle) == 0);
    int np1 = dfb110.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b110[j1];
  }
  { const Particle *b111 = dfb111.getData<Particle>();
    assert(dfb111.getSize() % sizeof(Particle) == 0);
    int np1 = dfb111.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b111[j1];
  }
  { const Particle *b120 = dfb120.getData<Particle>();
    assert(dfb120.getSize() % sizeof(Particle) == 0);
    int np1 = dfb120.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b120[j1];
  }
  { const Particle *b121 = dfb121.getData<Particle>();
    assert(dfb121.getSize() % sizeof(Particle) == 0);
    int np1 = dfb121.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b121[j1];
  }
  dfnp.setValue(np);
}

void c_mesh3d_exchange_particles_27_get_00_01_11(int np,const InputDF &df_p,real x1,real y1,real z1,real x2,real y2,real z2,
  OutputDF &dfb110,OutputDF &dfb111,OutputDF &dfb112,OutputDF &dfb120,OutputDF &dfb121,OutputDF &dfb122)
{ int j;
  assert(df_p.getSize() == np*sizeof(Particle));
  const Particle *p = df_p.getData<Particle>();
  std::vector<Particle> vp[27];
  for (j=0;j<np;j++)
  {
    real x = p[j].x;
    real y = p[j].y;
    real z = p[j].z;
    real u = p[j].u;
    real v = p[j].v;
    real w = p[j].w;
    int code = 0;
    if (x<x1) { x = 2*x1-x; u = -u; }
    else if (x>=x2) { x = 2*x2-x; u = -u; }
    if (y<y1) { y = 2*y1-y; v = -v; }
    else if (y>=y2) code += 8;
    if (z<z1) code += 1;
    else if (z>=z2) code += 2;
    int dir = code2dir[code];
    vp[dir].push_back(Particle(x,y,z,u,v,w));
  }
  assert(vp[D000].size() == 0);
  assert(vp[D001].size() == 0);
  assert(vp[D002].size() == 0);
  assert(vp[D010].size() == 0);
  assert(vp[D011].size() == 0);
  assert(vp[D012].size() == 0);
  assert(vp[D020].size() == 0);
  assert(vp[D021].size() == 0);
  assert(vp[D022].size() == 0);
  assert(vp[D100].size() == 0);
  assert(vp[D101].size() == 0);
  assert(vp[D102].size() == 0);
  { int np = vp[D110].size();
    int j1;
    Particle *b110 = dfb110.create<Particle>(np);
    for (j=0;j<np;j++) b110[j] = vp[D110][j];
  }
  { int np = vp[D111].size();
    int j1;
    Particle *b111 = dfb111.create<Particle>(np);
    for (j=0;j<np;j++) b111[j] = vp[D111][j];
  }
  { int np = vp[D112].size();
    int j1;
    Particle *b112 = dfb112.create<Particle>(np);
    for (j=0;j<np;j++) b112[j] = vp[D112][j];
  }
  { int np = vp[D120].size();
    int j1;
    Particle *b120 = dfb120.create<Particle>(np);
    for (j=0;j<np;j++) b120[j] = vp[D120][j];
  }
  { int np = vp[D121].size();
    int j1;
    Particle *b121 = dfb121.create<Particle>(np);
    for (j=0;j<np;j++) b121[j] = vp[D121][j];
  }
  { int np = vp[D122].size();
    int j1;
    Particle *b122 = dfb122.create<Particle>(np);
    for (j=0;j<np;j++) b122[j] = vp[D122][j];
  }
  assert(vp[D200].size() == 0);
  assert(vp[D201].size() == 0);
  assert(vp[D202].size() == 0);
  assert(vp[D210].size() == 0);
  assert(vp[D211].size() == 0);
  assert(vp[D212].size() == 0);
  assert(vp[D220].size() == 0);
  assert(vp[D221].size() == 0);
  assert(vp[D222].size() == 0);
}

void c_mesh3d_exchange_particles_27_set_00_01_11(
  const InputDF &dfb110,const InputDF &dfb111,const InputDF &dfb112,const InputDF &dfb120,const InputDF &dfb121,const InputDF &dfb122,
  OutputDF &dfnp,OutputDF &dfp)
{ int np = (dfb110.getSize()+dfb111.getSize()+dfb112.getSize()+dfb120.getSize()+dfb121.getSize()+dfb122.getSize())/sizeof(Particle);
  int j = 0;
  Particle *p =  dfp.create<Particle>(np);
  { const Particle *b110 = dfb110.getData<Particle>();
    assert(dfb110.getSize() % sizeof(Particle) == 0);
    int np1 = dfb110.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b110[j1];
  }
  { const Particle *b111 = dfb111.getData<Particle>();
    assert(dfb111.getSize() % sizeof(Particle) == 0);
    int np1 = dfb111.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b111[j1];
  }
  { const Particle *b112 = dfb112.getData<Particle>();
    assert(dfb112.getSize() % sizeof(Particle) == 0);
    int np1 = dfb112.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b112[j1];
  }
  { const Particle *b120 = dfb120.getData<Particle>();
    assert(dfb120.getSize() % sizeof(Particle) == 0);
    int np1 = dfb120.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b120[j1];
  }
  { const Particle *b121 = dfb121.getData<Particle>();
    assert(dfb121.getSize() % sizeof(Particle) == 0);
    int np1 = dfb121.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b121[j1];
  }
  { const Particle *b122 = dfb122.getData<Particle>();
    assert(dfb122.getSize() % sizeof(Particle) == 0);
    int np1 = dfb122.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b122[j1];
  }
  dfnp.setValue(np);
}

void c_mesh3d_exchange_particles_27_get_00_10_00(int np,const InputDF &df_p,real x1,real y1,real z1,real x2,real y2,real z2,
  OutputDF &dfb101,OutputDF &dfb111)
{ int j;
  assert(df_p.getSize() == np*sizeof(Particle));
  const Particle *p = df_p.getData<Particle>();
  std::vector<Particle> vp[27];
  for (j=0;j<np;j++)
  {
    real x = p[j].x;
    real y = p[j].y;
    real z = p[j].z;
    real u = p[j].u;
    real v = p[j].v;
    real w = p[j].w;
    int code = 0;
    if (x<x1) { x = 2*x1-x; u = -u; }
    else if (x>=x2) { x = 2*x2-x; u = -u; }
    if (y<y1) code += 4;
    else if (y>=y2) { y = 2*y2-y; v = -v; }
    if (z<z1) { z = 2*z1-z; w = -w; }
    else if (z>=z2) { z = 2*z2-z; w = -w; }
    int dir = code2dir[code];
    vp[dir].push_back(Particle(x,y,z,u,v,w));
  }
  assert(vp[D000].size() == 0);
  assert(vp[D001].size() == 0);
  assert(vp[D002].size() == 0);
  assert(vp[D010].size() == 0);
  assert(vp[D011].size() == 0);
  assert(vp[D012].size() == 0);
  assert(vp[D020].size() == 0);
  assert(vp[D021].size() == 0);
  assert(vp[D022].size() == 0);
  assert(vp[D100].size() == 0);
  { int np = vp[D101].size();
    int j1;
    Particle *b101 = dfb101.create<Particle>(np);
    for (j=0;j<np;j++) b101[j] = vp[D101][j];
  }
  assert(vp[D102].size() == 0);
  assert(vp[D110].size() == 0);
  { int np = vp[D111].size();
    int j1;
    Particle *b111 = dfb111.create<Particle>(np);
    for (j=0;j<np;j++) b111[j] = vp[D111][j];
  }
  assert(vp[D112].size() == 0);
  assert(vp[D120].size() == 0);
  assert(vp[D121].size() == 0);
  assert(vp[D122].size() == 0);
  assert(vp[D200].size() == 0);
  assert(vp[D201].size() == 0);
  assert(vp[D202].size() == 0);
  assert(vp[D210].size() == 0);
  assert(vp[D211].size() == 0);
  assert(vp[D212].size() == 0);
  assert(vp[D220].size() == 0);
  assert(vp[D221].size() == 0);
  assert(vp[D222].size() == 0);
}

void c_mesh3d_exchange_particles_27_set_00_10_00(
  const InputDF &dfb101,const InputDF &dfb111,
  OutputDF &dfnp,OutputDF &dfp)
{ int np = (dfb101.getSize()+dfb111.getSize())/sizeof(Particle);
  int j = 0;
  Particle *p =  dfp.create<Particle>(np);
  { const Particle *b101 = dfb101.getData<Particle>();
    assert(dfb101.getSize() % sizeof(Particle) == 0);
    int np1 = dfb101.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b101[j1];
  }
  { const Particle *b111 = dfb111.getData<Particle>();
    assert(dfb111.getSize() % sizeof(Particle) == 0);
    int np1 = dfb111.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b111[j1];
  }
  dfnp.setValue(np);
}

void c_mesh3d_exchange_particles_27_get_00_10_01(int np,const InputDF &df_p,real x1,real y1,real z1,real x2,real y2,real z2,
  OutputDF &dfb101,OutputDF &dfb102,OutputDF &dfb111,OutputDF &dfb112)
{ int j;
  assert(df_p.getSize() == np*sizeof(Particle));
  const Particle *p = df_p.getData<Particle>();
  std::vector<Particle> vp[27];
  for (j=0;j<np;j++)
  {
    real x = p[j].x;
    real y = p[j].y;
    real z = p[j].z;
    real u = p[j].u;
    real v = p[j].v;
    real w = p[j].w;
    int code = 0;
    if (x<x1) { x = 2*x1-x; u = -u; }
    else if (x>=x2) { x = 2*x2-x; u = -u; }
    if (y<y1) code += 4;
    else if (y>=y2) { y = 2*y2-y; v = -v; }
    if (z<z1) { z = 2*z1-z; w = -w; }
    else if (z>=z2) code += 2;
    int dir = code2dir[code];
    vp[dir].push_back(Particle(x,y,z,u,v,w));
  }
  assert(vp[D000].size() == 0);
  assert(vp[D001].size() == 0);
  assert(vp[D002].size() == 0);
  assert(vp[D010].size() == 0);
  assert(vp[D011].size() == 0);
  assert(vp[D012].size() == 0);
  assert(vp[D020].size() == 0);
  assert(vp[D021].size() == 0);
  assert(vp[D022].size() == 0);
  assert(vp[D100].size() == 0);
  { int np = vp[D101].size();
    int j1;
    Particle *b101 = dfb101.create<Particle>(np);
    for (j=0;j<np;j++) b101[j] = vp[D101][j];
  }
  { int np = vp[D102].size();
    int j1;
    Particle *b102 = dfb102.create<Particle>(np);
    for (j=0;j<np;j++) b102[j] = vp[D102][j];
  }
  assert(vp[D110].size() == 0);
  { int np = vp[D111].size();
    int j1;
    Particle *b111 = dfb111.create<Particle>(np);
    for (j=0;j<np;j++) b111[j] = vp[D111][j];
  }
  { int np = vp[D112].size();
    int j1;
    Particle *b112 = dfb112.create<Particle>(np);
    for (j=0;j<np;j++) b112[j] = vp[D112][j];
  }
  assert(vp[D120].size() == 0);
  assert(vp[D121].size() == 0);
  assert(vp[D122].size() == 0);
  assert(vp[D200].size() == 0);
  assert(vp[D201].size() == 0);
  assert(vp[D202].size() == 0);
  assert(vp[D210].size() == 0);
  assert(vp[D211].size() == 0);
  assert(vp[D212].size() == 0);
  assert(vp[D220].size() == 0);
  assert(vp[D221].size() == 0);
  assert(vp[D222].size() == 0);
}

void c_mesh3d_exchange_particles_27_set_00_10_01(
  const InputDF &dfb101,const InputDF &dfb102,const InputDF &dfb111,const InputDF &dfb112,
  OutputDF &dfnp,OutputDF &dfp)
{ int np = (dfb101.getSize()+dfb102.getSize()+dfb111.getSize()+dfb112.getSize())/sizeof(Particle);
  int j = 0;
  Particle *p =  dfp.create<Particle>(np);
  { const Particle *b101 = dfb101.getData<Particle>();
    assert(dfb101.getSize() % sizeof(Particle) == 0);
    int np1 = dfb101.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b101[j1];
  }
  { const Particle *b102 = dfb102.getData<Particle>();
    assert(dfb102.getSize() % sizeof(Particle) == 0);
    int np1 = dfb102.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b102[j1];
  }
  { const Particle *b111 = dfb111.getData<Particle>();
    assert(dfb111.getSize() % sizeof(Particle) == 0);
    int np1 = dfb111.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b111[j1];
  }
  { const Particle *b112 = dfb112.getData<Particle>();
    assert(dfb112.getSize() % sizeof(Particle) == 0);
    int np1 = dfb112.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b112[j1];
  }
  dfnp.setValue(np);
}

void c_mesh3d_exchange_particles_27_get_00_10_10(int np,const InputDF &df_p,real x1,real y1,real z1,real x2,real y2,real z2,
  OutputDF &dfb100,OutputDF &dfb101,OutputDF &dfb110,OutputDF &dfb111)
{ int j;
  assert(df_p.getSize() == np*sizeof(Particle));
  const Particle *p = df_p.getData<Particle>();
  std::vector<Particle> vp[27];
  for (j=0;j<np;j++)
  {
    real x = p[j].x;
    real y = p[j].y;
    real z = p[j].z;
    real u = p[j].u;
    real v = p[j].v;
    real w = p[j].w;
    int code = 0;
    if (x<x1) { x = 2*x1-x; u = -u; }
    else if (x>=x2) { x = 2*x2-x; u = -u; }
    if (y<y1) code += 4;
    else if (y>=y2) { y = 2*y2-y; v = -v; }
    if (z<z1) code += 1;
    else if (z>=z2) { z = 2*z2-z; w = -w; }
    int dir = code2dir[code];
    vp[dir].push_back(Particle(x,y,z,u,v,w));
  }
  assert(vp[D000].size() == 0);
  assert(vp[D001].size() == 0);
  assert(vp[D002].size() == 0);
  assert(vp[D010].size() == 0);
  assert(vp[D011].size() == 0);
  assert(vp[D012].size() == 0);
  assert(vp[D020].size() == 0);
  assert(vp[D021].size() == 0);
  assert(vp[D022].size() == 0);
  { int np = vp[D100].size();
    int j1;
    Particle *b100 = dfb100.create<Particle>(np);
    for (j=0;j<np;j++) b100[j] = vp[D100][j];
  }
  { int np = vp[D101].size();
    int j1;
    Particle *b101 = dfb101.create<Particle>(np);
    for (j=0;j<np;j++) b101[j] = vp[D101][j];
  }
  assert(vp[D102].size() == 0);
  { int np = vp[D110].size();
    int j1;
    Particle *b110 = dfb110.create<Particle>(np);
    for (j=0;j<np;j++) b110[j] = vp[D110][j];
  }
  { int np = vp[D111].size();
    int j1;
    Particle *b111 = dfb111.create<Particle>(np);
    for (j=0;j<np;j++) b111[j] = vp[D111][j];
  }
  assert(vp[D112].size() == 0);
  assert(vp[D120].size() == 0);
  assert(vp[D121].size() == 0);
  assert(vp[D122].size() == 0);
  assert(vp[D200].size() == 0);
  assert(vp[D201].size() == 0);
  assert(vp[D202].size() == 0);
  assert(vp[D210].size() == 0);
  assert(vp[D211].size() == 0);
  assert(vp[D212].size() == 0);
  assert(vp[D220].size() == 0);
  assert(vp[D221].size() == 0);
  assert(vp[D222].size() == 0);
}

void c_mesh3d_exchange_particles_27_set_00_10_10(
  const InputDF &dfb100,const InputDF &dfb101,const InputDF &dfb110,const InputDF &dfb111,
  OutputDF &dfnp,OutputDF &dfp)
{ int np = (dfb100.getSize()+dfb101.getSize()+dfb110.getSize()+dfb111.getSize())/sizeof(Particle);
  int j = 0;
  Particle *p =  dfp.create<Particle>(np);
  { const Particle *b100 = dfb100.getData<Particle>();
    assert(dfb100.getSize() % sizeof(Particle) == 0);
    int np1 = dfb100.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b100[j1];
  }
  { const Particle *b101 = dfb101.getData<Particle>();
    assert(dfb101.getSize() % sizeof(Particle) == 0);
    int np1 = dfb101.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b101[j1];
  }
  { const Particle *b110 = dfb110.getData<Particle>();
    assert(dfb110.getSize() % sizeof(Particle) == 0);
    int np1 = dfb110.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b110[j1];
  }
  { const Particle *b111 = dfb111.getData<Particle>();
    assert(dfb111.getSize() % sizeof(Particle) == 0);
    int np1 = dfb111.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b111[j1];
  }
  dfnp.setValue(np);
}

void c_mesh3d_exchange_particles_27_get_00_10_11(int np,const InputDF &df_p,real x1,real y1,real z1,real x2,real y2,real z2,
  OutputDF &dfb100,OutputDF &dfb101,OutputDF &dfb102,OutputDF &dfb110,OutputDF &dfb111,OutputDF &dfb112)
{ int j;
  assert(df_p.getSize() == np*sizeof(Particle));
  const Particle *p = df_p.getData<Particle>();
  std::vector<Particle> vp[27];
  for (j=0;j<np;j++)
  {
    real x = p[j].x;
    real y = p[j].y;
    real z = p[j].z;
    real u = p[j].u;
    real v = p[j].v;
    real w = p[j].w;
    int code = 0;
    if (x<x1) { x = 2*x1-x; u = -u; }
    else if (x>=x2) { x = 2*x2-x; u = -u; }
    if (y<y1) code += 4;
    else if (y>=y2) { y = 2*y2-y; v = -v; }
    if (z<z1) code += 1;
    else if (z>=z2) code += 2;
    int dir = code2dir[code];
    vp[dir].push_back(Particle(x,y,z,u,v,w));
  }
  assert(vp[D000].size() == 0);
  assert(vp[D001].size() == 0);
  assert(vp[D002].size() == 0);
  assert(vp[D010].size() == 0);
  assert(vp[D011].size() == 0);
  assert(vp[D012].size() == 0);
  assert(vp[D020].size() == 0);
  assert(vp[D021].size() == 0);
  assert(vp[D022].size() == 0);
  { int np = vp[D100].size();
    int j1;
    Particle *b100 = dfb100.create<Particle>(np);
    for (j=0;j<np;j++) b100[j] = vp[D100][j];
  }
  { int np = vp[D101].size();
    int j1;
    Particle *b101 = dfb101.create<Particle>(np);
    for (j=0;j<np;j++) b101[j] = vp[D101][j];
  }
  { int np = vp[D102].size();
    int j1;
    Particle *b102 = dfb102.create<Particle>(np);
    for (j=0;j<np;j++) b102[j] = vp[D102][j];
  }
  { int np = vp[D110].size();
    int j1;
    Particle *b110 = dfb110.create<Particle>(np);
    for (j=0;j<np;j++) b110[j] = vp[D110][j];
  }
  { int np = vp[D111].size();
    int j1;
    Particle *b111 = dfb111.create<Particle>(np);
    for (j=0;j<np;j++) b111[j] = vp[D111][j];
  }
  { int np = vp[D112].size();
    int j1;
    Particle *b112 = dfb112.create<Particle>(np);
    for (j=0;j<np;j++) b112[j] = vp[D112][j];
  }
  assert(vp[D120].size() == 0);
  assert(vp[D121].size() == 0);
  assert(vp[D122].size() == 0);
  assert(vp[D200].size() == 0);
  assert(vp[D201].size() == 0);
  assert(vp[D202].size() == 0);
  assert(vp[D210].size() == 0);
  assert(vp[D211].size() == 0);
  assert(vp[D212].size() == 0);
  assert(vp[D220].size() == 0);
  assert(vp[D221].size() == 0);
  assert(vp[D222].size() == 0);
}

void c_mesh3d_exchange_particles_27_set_00_10_11(
  const InputDF &dfb100,const InputDF &dfb101,const InputDF &dfb102,const InputDF &dfb110,const InputDF &dfb111,const InputDF &dfb112,
  OutputDF &dfnp,OutputDF &dfp)
{ int np = (dfb100.getSize()+dfb101.getSize()+dfb102.getSize()+dfb110.getSize()+dfb111.getSize()+dfb112.getSize())/sizeof(Particle);
  int j = 0;
  Particle *p =  dfp.create<Particle>(np);
  { const Particle *b100 = dfb100.getData<Particle>();
    assert(dfb100.getSize() % sizeof(Particle) == 0);
    int np1 = dfb100.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b100[j1];
  }
  { const Particle *b101 = dfb101.getData<Particle>();
    assert(dfb101.getSize() % sizeof(Particle) == 0);
    int np1 = dfb101.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b101[j1];
  }
  { const Particle *b102 = dfb102.getData<Particle>();
    assert(dfb102.getSize() % sizeof(Particle) == 0);
    int np1 = dfb102.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b102[j1];
  }
  { const Particle *b110 = dfb110.getData<Particle>();
    assert(dfb110.getSize() % sizeof(Particle) == 0);
    int np1 = dfb110.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b110[j1];
  }
  { const Particle *b111 = dfb111.getData<Particle>();
    assert(dfb111.getSize() % sizeof(Particle) == 0);
    int np1 = dfb111.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b111[j1];
  }
  { const Particle *b112 = dfb112.getData<Particle>();
    assert(dfb112.getSize() % sizeof(Particle) == 0);
    int np1 = dfb112.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b112[j1];
  }
  dfnp.setValue(np);
}

void c_mesh3d_exchange_particles_27_get_00_11_00(int np,const InputDF &df_p,real x1,real y1,real z1,real x2,real y2,real z2,
  OutputDF &dfb101,OutputDF &dfb111,OutputDF &dfb121)
{ int j;
  assert(df_p.getSize() == np*sizeof(Particle));
  const Particle *p = df_p.getData<Particle>();
  std::vector<Particle> vp[27];
  for (j=0;j<np;j++)
  {
    real x = p[j].x;
    real y = p[j].y;
    real z = p[j].z;
    real u = p[j].u;
    real v = p[j].v;
    real w = p[j].w;
    int code = 0;
    if (x<x1) { x = 2*x1-x; u = -u; }
    else if (x>=x2) { x = 2*x2-x; u = -u; }
    if (y<y1) code += 4;
    else if (y>=y2) code += 8;
    if (z<z1) { z = 2*z1-z; w = -w; }
    else if (z>=z2) { z = 2*z2-z; w = -w; }
    int dir = code2dir[code];
    vp[dir].push_back(Particle(x,y,z,u,v,w));
  }
  assert(vp[D000].size() == 0);
  assert(vp[D001].size() == 0);
  assert(vp[D002].size() == 0);
  assert(vp[D010].size() == 0);
  assert(vp[D011].size() == 0);
  assert(vp[D012].size() == 0);
  assert(vp[D020].size() == 0);
  assert(vp[D021].size() == 0);
  assert(vp[D022].size() == 0);
  assert(vp[D100].size() == 0);
  { int np = vp[D101].size();
    int j1;
    Particle *b101 = dfb101.create<Particle>(np);
    for (j=0;j<np;j++) b101[j] = vp[D101][j];
  }
  assert(vp[D102].size() == 0);
  assert(vp[D110].size() == 0);
  { int np = vp[D111].size();
    int j1;
    Particle *b111 = dfb111.create<Particle>(np);
    for (j=0;j<np;j++) b111[j] = vp[D111][j];
  }
  assert(vp[D112].size() == 0);
  assert(vp[D120].size() == 0);
  { int np = vp[D121].size();
    int j1;
    Particle *b121 = dfb121.create<Particle>(np);
    for (j=0;j<np;j++) b121[j] = vp[D121][j];
  }
  assert(vp[D122].size() == 0);
  assert(vp[D200].size() == 0);
  assert(vp[D201].size() == 0);
  assert(vp[D202].size() == 0);
  assert(vp[D210].size() == 0);
  assert(vp[D211].size() == 0);
  assert(vp[D212].size() == 0);
  assert(vp[D220].size() == 0);
  assert(vp[D221].size() == 0);
  assert(vp[D222].size() == 0);
}

void c_mesh3d_exchange_particles_27_set_00_11_00(
  const InputDF &dfb101,const InputDF &dfb111,const InputDF &dfb121,
  OutputDF &dfnp,OutputDF &dfp)
{ int np = (dfb101.getSize()+dfb111.getSize()+dfb121.getSize())/sizeof(Particle);
  int j = 0;
  Particle *p =  dfp.create<Particle>(np);
  { const Particle *b101 = dfb101.getData<Particle>();
    assert(dfb101.getSize() % sizeof(Particle) == 0);
    int np1 = dfb101.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b101[j1];
  }
  { const Particle *b111 = dfb111.getData<Particle>();
    assert(dfb111.getSize() % sizeof(Particle) == 0);
    int np1 = dfb111.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b111[j1];
  }
  { const Particle *b121 = dfb121.getData<Particle>();
    assert(dfb121.getSize() % sizeof(Particle) == 0);
    int np1 = dfb121.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b121[j1];
  }
  dfnp.setValue(np);
}

void c_mesh3d_exchange_particles_27_get_00_11_01(int np,const InputDF &df_p,real x1,real y1,real z1,real x2,real y2,real z2,
  OutputDF &dfb101,OutputDF &dfb102,OutputDF &dfb111,OutputDF &dfb112,OutputDF &dfb121,OutputDF &dfb122)
{ int j;
  assert(df_p.getSize() == np*sizeof(Particle));
  const Particle *p = df_p.getData<Particle>();
  std::vector<Particle> vp[27];
  for (j=0;j<np;j++)
  {
    real x = p[j].x;
    real y = p[j].y;
    real z = p[j].z;
    real u = p[j].u;
    real v = p[j].v;
    real w = p[j].w;
    int code = 0;
    if (x<x1) { x = 2*x1-x; u = -u; }
    else if (x>=x2) { x = 2*x2-x; u = -u; }
    if (y<y1) code += 4;
    else if (y>=y2) code += 8;
    if (z<z1) { z = 2*z1-z; w = -w; }
    else if (z>=z2) code += 2;
    int dir = code2dir[code];
    vp[dir].push_back(Particle(x,y,z,u,v,w));
  }
  assert(vp[D000].size() == 0);
  assert(vp[D001].size() == 0);
  assert(vp[D002].size() == 0);
  assert(vp[D010].size() == 0);
  assert(vp[D011].size() == 0);
  assert(vp[D012].size() == 0);
  assert(vp[D020].size() == 0);
  assert(vp[D021].size() == 0);
  assert(vp[D022].size() == 0);
  assert(vp[D100].size() == 0);
  { int np = vp[D101].size();
    int j1;
    Particle *b101 = dfb101.create<Particle>(np);
    for (j=0;j<np;j++) b101[j] = vp[D101][j];
  }
  { int np = vp[D102].size();
    int j1;
    Particle *b102 = dfb102.create<Particle>(np);
    for (j=0;j<np;j++) b102[j] = vp[D102][j];
  }
  assert(vp[D110].size() == 0);
  { int np = vp[D111].size();
    int j1;
    Particle *b111 = dfb111.create<Particle>(np);
    for (j=0;j<np;j++) b111[j] = vp[D111][j];
  }
  { int np = vp[D112].size();
    int j1;
    Particle *b112 = dfb112.create<Particle>(np);
    for (j=0;j<np;j++) b112[j] = vp[D112][j];
  }
  assert(vp[D120].size() == 0);
  { int np = vp[D121].size();
    int j1;
    Particle *b121 = dfb121.create<Particle>(np);
    for (j=0;j<np;j++) b121[j] = vp[D121][j];
  }
  { int np = vp[D122].size();
    int j1;
    Particle *b122 = dfb122.create<Particle>(np);
    for (j=0;j<np;j++) b122[j] = vp[D122][j];
  }
  assert(vp[D200].size() == 0);
  assert(vp[D201].size() == 0);
  assert(vp[D202].size() == 0);
  assert(vp[D210].size() == 0);
  assert(vp[D211].size() == 0);
  assert(vp[D212].size() == 0);
  assert(vp[D220].size() == 0);
  assert(vp[D221].size() == 0);
  assert(vp[D222].size() == 0);
}

void c_mesh3d_exchange_particles_27_set_00_11_01(
  const InputDF &dfb101,const InputDF &dfb102,const InputDF &dfb111,const InputDF &dfb112,const InputDF &dfb121,const InputDF &dfb122,
  OutputDF &dfnp,OutputDF &dfp)
{ int np = (dfb101.getSize()+dfb102.getSize()+dfb111.getSize()+dfb112.getSize()+dfb121.getSize()+dfb122.getSize())/sizeof(Particle);
  int j = 0;
  Particle *p =  dfp.create<Particle>(np);
  { const Particle *b101 = dfb101.getData<Particle>();
    assert(dfb101.getSize() % sizeof(Particle) == 0);
    int np1 = dfb101.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b101[j1];
  }
  { const Particle *b102 = dfb102.getData<Particle>();
    assert(dfb102.getSize() % sizeof(Particle) == 0);
    int np1 = dfb102.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b102[j1];
  }
  { const Particle *b111 = dfb111.getData<Particle>();
    assert(dfb111.getSize() % sizeof(Particle) == 0);
    int np1 = dfb111.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b111[j1];
  }
  { const Particle *b112 = dfb112.getData<Particle>();
    assert(dfb112.getSize() % sizeof(Particle) == 0);
    int np1 = dfb112.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b112[j1];
  }
  { const Particle *b121 = dfb121.getData<Particle>();
    assert(dfb121.getSize() % sizeof(Particle) == 0);
    int np1 = dfb121.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b121[j1];
  }
  { const Particle *b122 = dfb122.getData<Particle>();
    assert(dfb122.getSize() % sizeof(Particle) == 0);
    int np1 = dfb122.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b122[j1];
  }
  dfnp.setValue(np);
}

void c_mesh3d_exchange_particles_27_get_00_11_10(int np,const InputDF &df_p,real x1,real y1,real z1,real x2,real y2,real z2,
  OutputDF &dfb100,OutputDF &dfb101,OutputDF &dfb110,OutputDF &dfb111,OutputDF &dfb120,OutputDF &dfb121)
{ int j;
  assert(df_p.getSize() == np*sizeof(Particle));
  const Particle *p = df_p.getData<Particle>();
  std::vector<Particle> vp[27];
  for (j=0;j<np;j++)
  {
    real x = p[j].x;
    real y = p[j].y;
    real z = p[j].z;
    real u = p[j].u;
    real v = p[j].v;
    real w = p[j].w;
    int code = 0;
    if (x<x1) { x = 2*x1-x; u = -u; }
    else if (x>=x2) { x = 2*x2-x; u = -u; }
    if (y<y1) code += 4;
    else if (y>=y2) code += 8;
    if (z<z1) code += 1;
    else if (z>=z2) { z = 2*z2-z; w = -w; }
    int dir = code2dir[code];
    vp[dir].push_back(Particle(x,y,z,u,v,w));
  }
  assert(vp[D000].size() == 0);
  assert(vp[D001].size() == 0);
  assert(vp[D002].size() == 0);
  assert(vp[D010].size() == 0);
  assert(vp[D011].size() == 0);
  assert(vp[D012].size() == 0);
  assert(vp[D020].size() == 0);
  assert(vp[D021].size() == 0);
  assert(vp[D022].size() == 0);
  { int np = vp[D100].size();
    int j1;
    Particle *b100 = dfb100.create<Particle>(np);
    for (j=0;j<np;j++) b100[j] = vp[D100][j];
  }
  { int np = vp[D101].size();
    int j1;
    Particle *b101 = dfb101.create<Particle>(np);
    for (j=0;j<np;j++) b101[j] = vp[D101][j];
  }
  assert(vp[D102].size() == 0);
  { int np = vp[D110].size();
    int j1;
    Particle *b110 = dfb110.create<Particle>(np);
    for (j=0;j<np;j++) b110[j] = vp[D110][j];
  }
  { int np = vp[D111].size();
    int j1;
    Particle *b111 = dfb111.create<Particle>(np);
    for (j=0;j<np;j++) b111[j] = vp[D111][j];
  }
  assert(vp[D112].size() == 0);
  { int np = vp[D120].size();
    int j1;
    Particle *b120 = dfb120.create<Particle>(np);
    for (j=0;j<np;j++) b120[j] = vp[D120][j];
  }
  { int np = vp[D121].size();
    int j1;
    Particle *b121 = dfb121.create<Particle>(np);
    for (j=0;j<np;j++) b121[j] = vp[D121][j];
  }
  assert(vp[D122].size() == 0);
  assert(vp[D200].size() == 0);
  assert(vp[D201].size() == 0);
  assert(vp[D202].size() == 0);
  assert(vp[D210].size() == 0);
  assert(vp[D211].size() == 0);
  assert(vp[D212].size() == 0);
  assert(vp[D220].size() == 0);
  assert(vp[D221].size() == 0);
  assert(vp[D222].size() == 0);
}

void c_mesh3d_exchange_particles_27_set_00_11_10(
  const InputDF &dfb100,const InputDF &dfb101,const InputDF &dfb110,const InputDF &dfb111,const InputDF &dfb120,const InputDF &dfb121,
  OutputDF &dfnp,OutputDF &dfp)
{ int np = (dfb100.getSize()+dfb101.getSize()+dfb110.getSize()+dfb111.getSize()+dfb120.getSize()+dfb121.getSize())/sizeof(Particle);
  int j = 0;
  Particle *p =  dfp.create<Particle>(np);
  { const Particle *b100 = dfb100.getData<Particle>();
    assert(dfb100.getSize() % sizeof(Particle) == 0);
    int np1 = dfb100.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b100[j1];
  }
  { const Particle *b101 = dfb101.getData<Particle>();
    assert(dfb101.getSize() % sizeof(Particle) == 0);
    int np1 = dfb101.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b101[j1];
  }
  { const Particle *b110 = dfb110.getData<Particle>();
    assert(dfb110.getSize() % sizeof(Particle) == 0);
    int np1 = dfb110.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b110[j1];
  }
  { const Particle *b111 = dfb111.getData<Particle>();
    assert(dfb111.getSize() % sizeof(Particle) == 0);
    int np1 = dfb111.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b111[j1];
  }
  { const Particle *b120 = dfb120.getData<Particle>();
    assert(dfb120.getSize() % sizeof(Particle) == 0);
    int np1 = dfb120.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b120[j1];
  }
  { const Particle *b121 = dfb121.getData<Particle>();
    assert(dfb121.getSize() % sizeof(Particle) == 0);
    int np1 = dfb121.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b121[j1];
  }
  dfnp.setValue(np);
}

void c_mesh3d_exchange_particles_27_get_00_11_11(int np,const InputDF &df_p,real x1,real y1,real z1,real x2,real y2,real z2,
  OutputDF &dfb100,OutputDF &dfb101,OutputDF &dfb102,OutputDF &dfb110,OutputDF &dfb111,OutputDF &dfb112,OutputDF &dfb120,OutputDF &dfb121,OutputDF &dfb122)
{ int j;
  assert(df_p.getSize() == np*sizeof(Particle));
  const Particle *p = df_p.getData<Particle>();
  std::vector<Particle> vp[27];
  for (j=0;j<np;j++)
  {
    real x = p[j].x;
    real y = p[j].y;
    real z = p[j].z;
    real u = p[j].u;
    real v = p[j].v;
    real w = p[j].w;
    int code = 0;
    if (x<x1) { x = 2*x1-x; u = -u; }
    else if (x>=x2) { x = 2*x2-x; u = -u; }
    if (y<y1) code += 4;
    else if (y>=y2) code += 8;
    if (z<z1) code += 1;
    else if (z>=z2) code += 2;
    int dir = code2dir[code];
    vp[dir].push_back(Particle(x,y,z,u,v,w));
  }
  assert(vp[D000].size() == 0);
  assert(vp[D001].size() == 0);
  assert(vp[D002].size() == 0);
  assert(vp[D010].size() == 0);
  assert(vp[D011].size() == 0);
  assert(vp[D012].size() == 0);
  assert(vp[D020].size() == 0);
  assert(vp[D021].size() == 0);
  assert(vp[D022].size() == 0);
  { int np = vp[D100].size();
    int j1;
    Particle *b100 = dfb100.create<Particle>(np);
    for (j=0;j<np;j++) b100[j] = vp[D100][j];
  }
  { int np = vp[D101].size();
    int j1;
    Particle *b101 = dfb101.create<Particle>(np);
    for (j=0;j<np;j++) b101[j] = vp[D101][j];
  }
  { int np = vp[D102].size();
    int j1;
    Particle *b102 = dfb102.create<Particle>(np);
    for (j=0;j<np;j++) b102[j] = vp[D102][j];
  }
  { int np = vp[D110].size();
    int j1;
    Particle *b110 = dfb110.create<Particle>(np);
    for (j=0;j<np;j++) b110[j] = vp[D110][j];
  }
  { int np = vp[D111].size();
    int j1;
    Particle *b111 = dfb111.create<Particle>(np);
    for (j=0;j<np;j++) b111[j] = vp[D111][j];
  }
  { int np = vp[D112].size();
    int j1;
    Particle *b112 = dfb112.create<Particle>(np);
    for (j=0;j<np;j++) b112[j] = vp[D112][j];
  }
  { int np = vp[D120].size();
    int j1;
    Particle *b120 = dfb120.create<Particle>(np);
    for (j=0;j<np;j++) b120[j] = vp[D120][j];
  }
  { int np = vp[D121].size();
    int j1;
    Particle *b121 = dfb121.create<Particle>(np);
    for (j=0;j<np;j++) b121[j] = vp[D121][j];
  }
  { int np = vp[D122].size();
    int j1;
    Particle *b122 = dfb122.create<Particle>(np);
    for (j=0;j<np;j++) b122[j] = vp[D122][j];
  }
  assert(vp[D200].size() == 0);
  assert(vp[D201].size() == 0);
  assert(vp[D202].size() == 0);
  assert(vp[D210].size() == 0);
  assert(vp[D211].size() == 0);
  assert(vp[D212].size() == 0);
  assert(vp[D220].size() == 0);
  assert(vp[D221].size() == 0);
  assert(vp[D222].size() == 0);
}

void c_mesh3d_exchange_particles_27_set_00_11_11(
  const InputDF &dfb100,const InputDF &dfb101,const InputDF &dfb102,const InputDF &dfb110,const InputDF &dfb111,const InputDF &dfb112,const InputDF &dfb120,const InputDF &dfb121,const InputDF &dfb122,
  OutputDF &dfnp,OutputDF &dfp)
{ int np = (dfb100.getSize()+dfb101.getSize()+dfb102.getSize()+dfb110.getSize()+dfb111.getSize()+dfb112.getSize()+dfb120.getSize()+dfb121.getSize()+dfb122.getSize())/sizeof(Particle);
  int j = 0;
  Particle *p =  dfp.create<Particle>(np);
  { const Particle *b100 = dfb100.getData<Particle>();
    assert(dfb100.getSize() % sizeof(Particle) == 0);
    int np1 = dfb100.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b100[j1];
  }
  { const Particle *b101 = dfb101.getData<Particle>();
    assert(dfb101.getSize() % sizeof(Particle) == 0);
    int np1 = dfb101.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b101[j1];
  }
  { const Particle *b102 = dfb102.getData<Particle>();
    assert(dfb102.getSize() % sizeof(Particle) == 0);
    int np1 = dfb102.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b102[j1];
  }
  { const Particle *b110 = dfb110.getData<Particle>();
    assert(dfb110.getSize() % sizeof(Particle) == 0);
    int np1 = dfb110.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b110[j1];
  }
  { const Particle *b111 = dfb111.getData<Particle>();
    assert(dfb111.getSize() % sizeof(Particle) == 0);
    int np1 = dfb111.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b111[j1];
  }
  { const Particle *b112 = dfb112.getData<Particle>();
    assert(dfb112.getSize() % sizeof(Particle) == 0);
    int np1 = dfb112.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b112[j1];
  }
  { const Particle *b120 = dfb120.getData<Particle>();
    assert(dfb120.getSize() % sizeof(Particle) == 0);
    int np1 = dfb120.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b120[j1];
  }
  { const Particle *b121 = dfb121.getData<Particle>();
    assert(dfb121.getSize() % sizeof(Particle) == 0);
    int np1 = dfb121.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b121[j1];
  }
  { const Particle *b122 = dfb122.getData<Particle>();
    assert(dfb122.getSize() % sizeof(Particle) == 0);
    int np1 = dfb122.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b122[j1];
  }
  dfnp.setValue(np);
}

void c_mesh3d_exchange_particles_27_get_01_00_00(int np,const InputDF &df_p,real x1,real y1,real z1,real x2,real y2,real z2,
  OutputDF &dfb111,OutputDF &dfb211)
{ int j;
  assert(df_p.getSize() == np*sizeof(Particle));
  const Particle *p = df_p.getData<Particle>();
  std::vector<Particle> vp[27];
  for (j=0;j<np;j++)
  {
    real x = p[j].x;
    real y = p[j].y;
    real z = p[j].z;
    real u = p[j].u;
    real v = p[j].v;
    real w = p[j].w;
    int code = 0;
    if (x<x1) { x = 2*x1-x; u = -u; }
    else if (x>=x2) code += 32;
    if (y<y1) { y = 2*y1-y; v = -v; }
    else if (y>=y2) { y = 2*y2-y; v = -v; }
    if (z<z1) { z = 2*z1-z; w = -w; }
    else if (z>=z2) { z = 2*z2-z; w = -w; }
    int dir = code2dir[code];
    vp[dir].push_back(Particle(x,y,z,u,v,w));
  }
  assert(vp[D000].size() == 0);
  assert(vp[D001].size() == 0);
  assert(vp[D002].size() == 0);
  assert(vp[D010].size() == 0);
  assert(vp[D011].size() == 0);
  assert(vp[D012].size() == 0);
  assert(vp[D020].size() == 0);
  assert(vp[D021].size() == 0);
  assert(vp[D022].size() == 0);
  assert(vp[D100].size() == 0);
  assert(vp[D101].size() == 0);
  assert(vp[D102].size() == 0);
  assert(vp[D110].size() == 0);
  { int np = vp[D111].size();
    int j1;
    Particle *b111 = dfb111.create<Particle>(np);
    for (j=0;j<np;j++) b111[j] = vp[D111][j];
  }
  assert(vp[D112].size() == 0);
  assert(vp[D120].size() == 0);
  assert(vp[D121].size() == 0);
  assert(vp[D122].size() == 0);
  assert(vp[D200].size() == 0);
  assert(vp[D201].size() == 0);
  assert(vp[D202].size() == 0);
  assert(vp[D210].size() == 0);
  { int np = vp[D211].size();
    int j1;
    Particle *b211 = dfb211.create<Particle>(np);
    for (j=0;j<np;j++) b211[j] = vp[D211][j];
  }
  assert(vp[D212].size() == 0);
  assert(vp[D220].size() == 0);
  assert(vp[D221].size() == 0);
  assert(vp[D222].size() == 0);
}

void c_mesh3d_exchange_particles_27_set_01_00_00(
  const InputDF &dfb111,const InputDF &dfb211,
  OutputDF &dfnp,OutputDF &dfp)
{ int np = (dfb111.getSize()+dfb211.getSize())/sizeof(Particle);
  int j = 0;
  Particle *p =  dfp.create<Particle>(np);
  { const Particle *b111 = dfb111.getData<Particle>();
    assert(dfb111.getSize() % sizeof(Particle) == 0);
    int np1 = dfb111.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b111[j1];
  }
  { const Particle *b211 = dfb211.getData<Particle>();
    assert(dfb211.getSize() % sizeof(Particle) == 0);
    int np1 = dfb211.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b211[j1];
  }
  dfnp.setValue(np);
}

void c_mesh3d_exchange_particles_27_get_01_00_01(int np,const InputDF &df_p,real x1,real y1,real z1,real x2,real y2,real z2,
  OutputDF &dfb111,OutputDF &dfb112,OutputDF &dfb211,OutputDF &dfb212)
{ int j;
  assert(df_p.getSize() == np*sizeof(Particle));
  const Particle *p = df_p.getData<Particle>();
  std::vector<Particle> vp[27];
  for (j=0;j<np;j++)
  {
    real x = p[j].x;
    real y = p[j].y;
    real z = p[j].z;
    real u = p[j].u;
    real v = p[j].v;
    real w = p[j].w;
    int code = 0;
    if (x<x1) { x = 2*x1-x; u = -u; }
    else if (x>=x2) code += 32;
    if (y<y1) { y = 2*y1-y; v = -v; }
    else if (y>=y2) { y = 2*y2-y; v = -v; }
    if (z<z1) { z = 2*z1-z; w = -w; }
    else if (z>=z2) code += 2;
    int dir = code2dir[code];
    vp[dir].push_back(Particle(x,y,z,u,v,w));
  }
  assert(vp[D000].size() == 0);
  assert(vp[D001].size() == 0);
  assert(vp[D002].size() == 0);
  assert(vp[D010].size() == 0);
  assert(vp[D011].size() == 0);
  assert(vp[D012].size() == 0);
  assert(vp[D020].size() == 0);
  assert(vp[D021].size() == 0);
  assert(vp[D022].size() == 0);
  assert(vp[D100].size() == 0);
  assert(vp[D101].size() == 0);
  assert(vp[D102].size() == 0);
  assert(vp[D110].size() == 0);
  { int np = vp[D111].size();
    int j1;
    Particle *b111 = dfb111.create<Particle>(np);
    for (j=0;j<np;j++) b111[j] = vp[D111][j];
  }
  { int np = vp[D112].size();
    int j1;
    Particle *b112 = dfb112.create<Particle>(np);
    for (j=0;j<np;j++) b112[j] = vp[D112][j];
  }
  assert(vp[D120].size() == 0);
  assert(vp[D121].size() == 0);
  assert(vp[D122].size() == 0);
  assert(vp[D200].size() == 0);
  assert(vp[D201].size() == 0);
  assert(vp[D202].size() == 0);
  assert(vp[D210].size() == 0);
  { int np = vp[D211].size();
    int j1;
    Particle *b211 = dfb211.create<Particle>(np);
    for (j=0;j<np;j++) b211[j] = vp[D211][j];
  }
  { int np = vp[D212].size();
    int j1;
    Particle *b212 = dfb212.create<Particle>(np);
    for (j=0;j<np;j++) b212[j] = vp[D212][j];
  }
  assert(vp[D220].size() == 0);
  assert(vp[D221].size() == 0);
  assert(vp[D222].size() == 0);
}

void c_mesh3d_exchange_particles_27_set_01_00_01(
  const InputDF &dfb111,const InputDF &dfb112,const InputDF &dfb211,const InputDF &dfb212,
  OutputDF &dfnp,OutputDF &dfp)
{ int np = (dfb111.getSize()+dfb112.getSize()+dfb211.getSize()+dfb212.getSize())/sizeof(Particle);
  int j = 0;
  Particle *p =  dfp.create<Particle>(np);
  { const Particle *b111 = dfb111.getData<Particle>();
    assert(dfb111.getSize() % sizeof(Particle) == 0);
    int np1 = dfb111.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b111[j1];
  }
  { const Particle *b112 = dfb112.getData<Particle>();
    assert(dfb112.getSize() % sizeof(Particle) == 0);
    int np1 = dfb112.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b112[j1];
  }
  { const Particle *b211 = dfb211.getData<Particle>();
    assert(dfb211.getSize() % sizeof(Particle) == 0);
    int np1 = dfb211.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b211[j1];
  }
  { const Particle *b212 = dfb212.getData<Particle>();
    assert(dfb212.getSize() % sizeof(Particle) == 0);
    int np1 = dfb212.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b212[j1];
  }
  dfnp.setValue(np);
}

void c_mesh3d_exchange_particles_27_get_01_00_10(int np,const InputDF &df_p,real x1,real y1,real z1,real x2,real y2,real z2,
  OutputDF &dfb110,OutputDF &dfb111,OutputDF &dfb210,OutputDF &dfb211)
{ int j;
  assert(df_p.getSize() == np*sizeof(Particle));
  const Particle *p = df_p.getData<Particle>();
  std::vector<Particle> vp[27];
  for (j=0;j<np;j++)
  {
    real x = p[j].x;
    real y = p[j].y;
    real z = p[j].z;
    real u = p[j].u;
    real v = p[j].v;
    real w = p[j].w;
    int code = 0;
    if (x<x1) { x = 2*x1-x; u = -u; }
    else if (x>=x2) code += 32;
    if (y<y1) { y = 2*y1-y; v = -v; }
    else if (y>=y2) { y = 2*y2-y; v = -v; }
    if (z<z1) code += 1;
    else if (z>=z2) { z = 2*z2-z; w = -w; }
    int dir = code2dir[code];
    vp[dir].push_back(Particle(x,y,z,u,v,w));
  }
  assert(vp[D000].size() == 0);
  assert(vp[D001].size() == 0);
  assert(vp[D002].size() == 0);
  assert(vp[D010].size() == 0);
  assert(vp[D011].size() == 0);
  assert(vp[D012].size() == 0);
  assert(vp[D020].size() == 0);
  assert(vp[D021].size() == 0);
  assert(vp[D022].size() == 0);
  assert(vp[D100].size() == 0);
  assert(vp[D101].size() == 0);
  assert(vp[D102].size() == 0);
  { int np = vp[D110].size();
    int j1;
    Particle *b110 = dfb110.create<Particle>(np);
    for (j=0;j<np;j++) b110[j] = vp[D110][j];
  }
  { int np = vp[D111].size();
    int j1;
    Particle *b111 = dfb111.create<Particle>(np);
    for (j=0;j<np;j++) b111[j] = vp[D111][j];
  }
  assert(vp[D112].size() == 0);
  assert(vp[D120].size() == 0);
  assert(vp[D121].size() == 0);
  assert(vp[D122].size() == 0);
  assert(vp[D200].size() == 0);
  assert(vp[D201].size() == 0);
  assert(vp[D202].size() == 0);
  { int np = vp[D210].size();
    int j1;
    Particle *b210 = dfb210.create<Particle>(np);
    for (j=0;j<np;j++) b210[j] = vp[D210][j];
  }
  { int np = vp[D211].size();
    int j1;
    Particle *b211 = dfb211.create<Particle>(np);
    for (j=0;j<np;j++) b211[j] = vp[D211][j];
  }
  assert(vp[D212].size() == 0);
  assert(vp[D220].size() == 0);
  assert(vp[D221].size() == 0);
  assert(vp[D222].size() == 0);
}

void c_mesh3d_exchange_particles_27_set_01_00_10(
  const InputDF &dfb110,const InputDF &dfb111,const InputDF &dfb210,const InputDF &dfb211,
  OutputDF &dfnp,OutputDF &dfp)
{ int np = (dfb110.getSize()+dfb111.getSize()+dfb210.getSize()+dfb211.getSize())/sizeof(Particle);
  int j = 0;
  Particle *p =  dfp.create<Particle>(np);
  { const Particle *b110 = dfb110.getData<Particle>();
    assert(dfb110.getSize() % sizeof(Particle) == 0);
    int np1 = dfb110.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b110[j1];
  }
  { const Particle *b111 = dfb111.getData<Particle>();
    assert(dfb111.getSize() % sizeof(Particle) == 0);
    int np1 = dfb111.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b111[j1];
  }
  { const Particle *b210 = dfb210.getData<Particle>();
    assert(dfb210.getSize() % sizeof(Particle) == 0);
    int np1 = dfb210.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b210[j1];
  }
  { const Particle *b211 = dfb211.getData<Particle>();
    assert(dfb211.getSize() % sizeof(Particle) == 0);
    int np1 = dfb211.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b211[j1];
  }
  dfnp.setValue(np);
}

void c_mesh3d_exchange_particles_27_get_01_00_11(int np,const InputDF &df_p,real x1,real y1,real z1,real x2,real y2,real z2,
  OutputDF &dfb110,OutputDF &dfb111,OutputDF &dfb112,OutputDF &dfb210,OutputDF &dfb211,OutputDF &dfb212)
{ int j;
  assert(df_p.getSize() == np*sizeof(Particle));
  const Particle *p = df_p.getData<Particle>();
  std::vector<Particle> vp[27];
  for (j=0;j<np;j++)
  {
    real x = p[j].x;
    real y = p[j].y;
    real z = p[j].z;
    real u = p[j].u;
    real v = p[j].v;
    real w = p[j].w;
    int code = 0;
    if (x<x1) { x = 2*x1-x; u = -u; }
    else if (x>=x2) code += 32;
    if (y<y1) { y = 2*y1-y; v = -v; }
    else if (y>=y2) { y = 2*y2-y; v = -v; }
    if (z<z1) code += 1;
    else if (z>=z2) code += 2;
    int dir = code2dir[code];
    vp[dir].push_back(Particle(x,y,z,u,v,w));
  }
  assert(vp[D000].size() == 0);
  assert(vp[D001].size() == 0);
  assert(vp[D002].size() == 0);
  assert(vp[D010].size() == 0);
  assert(vp[D011].size() == 0);
  assert(vp[D012].size() == 0);
  assert(vp[D020].size() == 0);
  assert(vp[D021].size() == 0);
  assert(vp[D022].size() == 0);
  assert(vp[D100].size() == 0);
  assert(vp[D101].size() == 0);
  assert(vp[D102].size() == 0);
  { int np = vp[D110].size();
    int j1;
    Particle *b110 = dfb110.create<Particle>(np);
    for (j=0;j<np;j++) b110[j] = vp[D110][j];
  }
  { int np = vp[D111].size();
    int j1;
    Particle *b111 = dfb111.create<Particle>(np);
    for (j=0;j<np;j++) b111[j] = vp[D111][j];
  }
  { int np = vp[D112].size();
    int j1;
    Particle *b112 = dfb112.create<Particle>(np);
    for (j=0;j<np;j++) b112[j] = vp[D112][j];
  }
  assert(vp[D120].size() == 0);
  assert(vp[D121].size() == 0);
  assert(vp[D122].size() == 0);
  assert(vp[D200].size() == 0);
  assert(vp[D201].size() == 0);
  assert(vp[D202].size() == 0);
  { int np = vp[D210].size();
    int j1;
    Particle *b210 = dfb210.create<Particle>(np);
    for (j=0;j<np;j++) b210[j] = vp[D210][j];
  }
  { int np = vp[D211].size();
    int j1;
    Particle *b211 = dfb211.create<Particle>(np);
    for (j=0;j<np;j++) b211[j] = vp[D211][j];
  }
  { int np = vp[D212].size();
    int j1;
    Particle *b212 = dfb212.create<Particle>(np);
    for (j=0;j<np;j++) b212[j] = vp[D212][j];
  }
  assert(vp[D220].size() == 0);
  assert(vp[D221].size() == 0);
  assert(vp[D222].size() == 0);
}

void c_mesh3d_exchange_particles_27_set_01_00_11(
  const InputDF &dfb110,const InputDF &dfb111,const InputDF &dfb112,const InputDF &dfb210,const InputDF &dfb211,const InputDF &dfb212,
  OutputDF &dfnp,OutputDF &dfp)
{ int np = (dfb110.getSize()+dfb111.getSize()+dfb112.getSize()+dfb210.getSize()+dfb211.getSize()+dfb212.getSize())/sizeof(Particle);
  int j = 0;
  Particle *p =  dfp.create<Particle>(np);
  { const Particle *b110 = dfb110.getData<Particle>();
    assert(dfb110.getSize() % sizeof(Particle) == 0);
    int np1 = dfb110.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b110[j1];
  }
  { const Particle *b111 = dfb111.getData<Particle>();
    assert(dfb111.getSize() % sizeof(Particle) == 0);
    int np1 = dfb111.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b111[j1];
  }
  { const Particle *b112 = dfb112.getData<Particle>();
    assert(dfb112.getSize() % sizeof(Particle) == 0);
    int np1 = dfb112.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b112[j1];
  }
  { const Particle *b210 = dfb210.getData<Particle>();
    assert(dfb210.getSize() % sizeof(Particle) == 0);
    int np1 = dfb210.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b210[j1];
  }
  { const Particle *b211 = dfb211.getData<Particle>();
    assert(dfb211.getSize() % sizeof(Particle) == 0);
    int np1 = dfb211.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b211[j1];
  }
  { const Particle *b212 = dfb212.getData<Particle>();
    assert(dfb212.getSize() % sizeof(Particle) == 0);
    int np1 = dfb212.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b212[j1];
  }
  dfnp.setValue(np);
}

void c_mesh3d_exchange_particles_27_get_01_01_00(int np,const InputDF &df_p,real x1,real y1,real z1,real x2,real y2,real z2,
  OutputDF &dfb111,OutputDF &dfb121,OutputDF &dfb211,OutputDF &dfb221)
{ int j;
  assert(df_p.getSize() == np*sizeof(Particle));
  const Particle *p = df_p.getData<Particle>();
  std::vector<Particle> vp[27];
  for (j=0;j<np;j++)
  {
    real x = p[j].x;
    real y = p[j].y;
    real z = p[j].z;
    real u = p[j].u;
    real v = p[j].v;
    real w = p[j].w;
    int code = 0;
    if (x<x1) { x = 2*x1-x; u = -u; }
    else if (x>=x2) code += 32;
    if (y<y1) { y = 2*y1-y; v = -v; }
    else if (y>=y2) code += 8;
    if (z<z1) { z = 2*z1-z; w = -w; }
    else if (z>=z2) { z = 2*z2-z; w = -w; }
    int dir = code2dir[code];
    vp[dir].push_back(Particle(x,y,z,u,v,w));
  }
  assert(vp[D000].size() == 0);
  assert(vp[D001].size() == 0);
  assert(vp[D002].size() == 0);
  assert(vp[D010].size() == 0);
  assert(vp[D011].size() == 0);
  assert(vp[D012].size() == 0);
  assert(vp[D020].size() == 0);
  assert(vp[D021].size() == 0);
  assert(vp[D022].size() == 0);
  assert(vp[D100].size() == 0);
  assert(vp[D101].size() == 0);
  assert(vp[D102].size() == 0);
  assert(vp[D110].size() == 0);
  { int np = vp[D111].size();
    int j1;
    Particle *b111 = dfb111.create<Particle>(np);
    for (j=0;j<np;j++) b111[j] = vp[D111][j];
  }
  assert(vp[D112].size() == 0);
  assert(vp[D120].size() == 0);
  { int np = vp[D121].size();
    int j1;
    Particle *b121 = dfb121.create<Particle>(np);
    for (j=0;j<np;j++) b121[j] = vp[D121][j];
  }
  assert(vp[D122].size() == 0);
  assert(vp[D200].size() == 0);
  assert(vp[D201].size() == 0);
  assert(vp[D202].size() == 0);
  assert(vp[D210].size() == 0);
  { int np = vp[D211].size();
    int j1;
    Particle *b211 = dfb211.create<Particle>(np);
    for (j=0;j<np;j++) b211[j] = vp[D211][j];
  }
  assert(vp[D212].size() == 0);
  assert(vp[D220].size() == 0);
  { int np = vp[D221].size();
    int j1;
    Particle *b221 = dfb221.create<Particle>(np);
    for (j=0;j<np;j++) b221[j] = vp[D221][j];
  }
  assert(vp[D222].size() == 0);
}

void c_mesh3d_exchange_particles_27_set_01_01_00(
  const InputDF &dfb111,const InputDF &dfb121,const InputDF &dfb211,const InputDF &dfb221,
  OutputDF &dfnp,OutputDF &dfp)
{ int np = (dfb111.getSize()+dfb121.getSize()+dfb211.getSize()+dfb221.getSize())/sizeof(Particle);
  int j = 0;
  Particle *p =  dfp.create<Particle>(np);
  { const Particle *b111 = dfb111.getData<Particle>();
    assert(dfb111.getSize() % sizeof(Particle) == 0);
    int np1 = dfb111.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b111[j1];
  }
  { const Particle *b121 = dfb121.getData<Particle>();
    assert(dfb121.getSize() % sizeof(Particle) == 0);
    int np1 = dfb121.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b121[j1];
  }
  { const Particle *b211 = dfb211.getData<Particle>();
    assert(dfb211.getSize() % sizeof(Particle) == 0);
    int np1 = dfb211.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b211[j1];
  }
  { const Particle *b221 = dfb221.getData<Particle>();
    assert(dfb221.getSize() % sizeof(Particle) == 0);
    int np1 = dfb221.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b221[j1];
  }
  dfnp.setValue(np);
}

void c_mesh3d_exchange_particles_27_get_01_01_01(int np,const InputDF &df_p,real x1,real y1,real z1,real x2,real y2,real z2,
  OutputDF &dfb111,OutputDF &dfb112,OutputDF &dfb121,OutputDF &dfb122,OutputDF &dfb211,OutputDF &dfb212,OutputDF &dfb221,OutputDF &dfb222)
{ int j;
  assert(df_p.getSize() == np*sizeof(Particle));
  const Particle *p = df_p.getData<Particle>();
  std::vector<Particle> vp[27];
  for (j=0;j<np;j++)
  {
    real x = p[j].x;
    real y = p[j].y;
    real z = p[j].z;
    real u = p[j].u;
    real v = p[j].v;
    real w = p[j].w;
    int code = 0;
    if (x<x1) { x = 2*x1-x; u = -u; }
    else if (x>=x2) code += 32;
    if (y<y1) { y = 2*y1-y; v = -v; }
    else if (y>=y2) code += 8;
    if (z<z1) { z = 2*z1-z; w = -w; }
    else if (z>=z2) code += 2;
    int dir = code2dir[code];
    vp[dir].push_back(Particle(x,y,z,u,v,w));
  }
  assert(vp[D000].size() == 0);
  assert(vp[D001].size() == 0);
  assert(vp[D002].size() == 0);
  assert(vp[D010].size() == 0);
  assert(vp[D011].size() == 0);
  assert(vp[D012].size() == 0);
  assert(vp[D020].size() == 0);
  assert(vp[D021].size() == 0);
  assert(vp[D022].size() == 0);
  assert(vp[D100].size() == 0);
  assert(vp[D101].size() == 0);
  assert(vp[D102].size() == 0);
  assert(vp[D110].size() == 0);
  { int np = vp[D111].size();
    int j1;
    Particle *b111 = dfb111.create<Particle>(np);
    for (j=0;j<np;j++) b111[j] = vp[D111][j];
  }
  { int np = vp[D112].size();
    int j1;
    Particle *b112 = dfb112.create<Particle>(np);
    for (j=0;j<np;j++) b112[j] = vp[D112][j];
  }
  assert(vp[D120].size() == 0);
  { int np = vp[D121].size();
    int j1;
    Particle *b121 = dfb121.create<Particle>(np);
    for (j=0;j<np;j++) b121[j] = vp[D121][j];
  }
  { int np = vp[D122].size();
    int j1;
    Particle *b122 = dfb122.create<Particle>(np);
    for (j=0;j<np;j++) b122[j] = vp[D122][j];
  }
  assert(vp[D200].size() == 0);
  assert(vp[D201].size() == 0);
  assert(vp[D202].size() == 0);
  assert(vp[D210].size() == 0);
  { int np = vp[D211].size();
    int j1;
    Particle *b211 = dfb211.create<Particle>(np);
    for (j=0;j<np;j++) b211[j] = vp[D211][j];
  }
  { int np = vp[D212].size();
    int j1;
    Particle *b212 = dfb212.create<Particle>(np);
    for (j=0;j<np;j++) b212[j] = vp[D212][j];
  }
  assert(vp[D220].size() == 0);
  { int np = vp[D221].size();
    int j1;
    Particle *b221 = dfb221.create<Particle>(np);
    for (j=0;j<np;j++) b221[j] = vp[D221][j];
  }
  { int np = vp[D222].size();
    int j1;
    Particle *b222 = dfb222.create<Particle>(np);
    for (j=0;j<np;j++) b222[j] = vp[D222][j];
  }
}

void c_mesh3d_exchange_particles_27_set_01_01_01(
  const InputDF &dfb111,const InputDF &dfb112,const InputDF &dfb121,const InputDF &dfb122,const InputDF &dfb211,const InputDF &dfb212,const InputDF &dfb221,const InputDF &dfb222,
  OutputDF &dfnp,OutputDF &dfp)
{ int np = (dfb111.getSize()+dfb112.getSize()+dfb121.getSize()+dfb122.getSize()+dfb211.getSize()+dfb212.getSize()+dfb221.getSize()+dfb222.getSize())/sizeof(Particle);
  int j = 0;
  Particle *p =  dfp.create<Particle>(np);
  { const Particle *b111 = dfb111.getData<Particle>();
    assert(dfb111.getSize() % sizeof(Particle) == 0);
    int np1 = dfb111.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b111[j1];
  }
  { const Particle *b112 = dfb112.getData<Particle>();
    assert(dfb112.getSize() % sizeof(Particle) == 0);
    int np1 = dfb112.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b112[j1];
  }
  { const Particle *b121 = dfb121.getData<Particle>();
    assert(dfb121.getSize() % sizeof(Particle) == 0);
    int np1 = dfb121.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b121[j1];
  }
  { const Particle *b122 = dfb122.getData<Particle>();
    assert(dfb122.getSize() % sizeof(Particle) == 0);
    int np1 = dfb122.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b122[j1];
  }
  { const Particle *b211 = dfb211.getData<Particle>();
    assert(dfb211.getSize() % sizeof(Particle) == 0);
    int np1 = dfb211.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b211[j1];
  }
  { const Particle *b212 = dfb212.getData<Particle>();
    assert(dfb212.getSize() % sizeof(Particle) == 0);
    int np1 = dfb212.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b212[j1];
  }
  { const Particle *b221 = dfb221.getData<Particle>();
    assert(dfb221.getSize() % sizeof(Particle) == 0);
    int np1 = dfb221.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b221[j1];
  }
  { const Particle *b222 = dfb222.getData<Particle>();
    assert(dfb222.getSize() % sizeof(Particle) == 0);
    int np1 = dfb222.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b222[j1];
  }
  dfnp.setValue(np);
}

void c_mesh3d_exchange_particles_27_get_01_01_10(int np,const InputDF &df_p,real x1,real y1,real z1,real x2,real y2,real z2,
  OutputDF &dfb110,OutputDF &dfb111,OutputDF &dfb120,OutputDF &dfb121,OutputDF &dfb210,OutputDF &dfb211,OutputDF &dfb220,OutputDF &dfb221)
{ int j;
  assert(df_p.getSize() == np*sizeof(Particle));
  const Particle *p = df_p.getData<Particle>();
  std::vector<Particle> vp[27];
  for (j=0;j<np;j++)
  {
    real x = p[j].x;
    real y = p[j].y;
    real z = p[j].z;
    real u = p[j].u;
    real v = p[j].v;
    real w = p[j].w;
    int code = 0;
    if (x<x1) { x = 2*x1-x; u = -u; }
    else if (x>=x2) code += 32;
    if (y<y1) { y = 2*y1-y; v = -v; }
    else if (y>=y2) code += 8;
    if (z<z1) code += 1;
    else if (z>=z2) { z = 2*z2-z; w = -w; }
    int dir = code2dir[code];
    vp[dir].push_back(Particle(x,y,z,u,v,w));
  }
  assert(vp[D000].size() == 0);
  assert(vp[D001].size() == 0);
  assert(vp[D002].size() == 0);
  assert(vp[D010].size() == 0);
  assert(vp[D011].size() == 0);
  assert(vp[D012].size() == 0);
  assert(vp[D020].size() == 0);
  assert(vp[D021].size() == 0);
  assert(vp[D022].size() == 0);
  assert(vp[D100].size() == 0);
  assert(vp[D101].size() == 0);
  assert(vp[D102].size() == 0);
  { int np = vp[D110].size();
    int j1;
    Particle *b110 = dfb110.create<Particle>(np);
    for (j=0;j<np;j++) b110[j] = vp[D110][j];
  }
  { int np = vp[D111].size();
    int j1;
    Particle *b111 = dfb111.create<Particle>(np);
    for (j=0;j<np;j++) b111[j] = vp[D111][j];
  }
  assert(vp[D112].size() == 0);
  { int np = vp[D120].size();
    int j1;
    Particle *b120 = dfb120.create<Particle>(np);
    for (j=0;j<np;j++) b120[j] = vp[D120][j];
  }
  { int np = vp[D121].size();
    int j1;
    Particle *b121 = dfb121.create<Particle>(np);
    for (j=0;j<np;j++) b121[j] = vp[D121][j];
  }
  assert(vp[D122].size() == 0);
  assert(vp[D200].size() == 0);
  assert(vp[D201].size() == 0);
  assert(vp[D202].size() == 0);
  { int np = vp[D210].size();
    int j1;
    Particle *b210 = dfb210.create<Particle>(np);
    for (j=0;j<np;j++) b210[j] = vp[D210][j];
  }
  { int np = vp[D211].size();
    int j1;
    Particle *b211 = dfb211.create<Particle>(np);
    for (j=0;j<np;j++) b211[j] = vp[D211][j];
  }
  assert(vp[D212].size() == 0);
  { int np = vp[D220].size();
    int j1;
    Particle *b220 = dfb220.create<Particle>(np);
    for (j=0;j<np;j++) b220[j] = vp[D220][j];
  }
  { int np = vp[D221].size();
    int j1;
    Particle *b221 = dfb221.create<Particle>(np);
    for (j=0;j<np;j++) b221[j] = vp[D221][j];
  }
  assert(vp[D222].size() == 0);
}

void c_mesh3d_exchange_particles_27_set_01_01_10(
  const InputDF &dfb110,const InputDF &dfb111,const InputDF &dfb120,const InputDF &dfb121,const InputDF &dfb210,const InputDF &dfb211,const InputDF &dfb220,const InputDF &dfb221,
  OutputDF &dfnp,OutputDF &dfp)
{ int np = (dfb110.getSize()+dfb111.getSize()+dfb120.getSize()+dfb121.getSize()+dfb210.getSize()+dfb211.getSize()+dfb220.getSize()+dfb221.getSize())/sizeof(Particle);
  int j = 0;
  Particle *p =  dfp.create<Particle>(np);
  { const Particle *b110 = dfb110.getData<Particle>();
    assert(dfb110.getSize() % sizeof(Particle) == 0);
    int np1 = dfb110.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b110[j1];
  }
  { const Particle *b111 = dfb111.getData<Particle>();
    assert(dfb111.getSize() % sizeof(Particle) == 0);
    int np1 = dfb111.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b111[j1];
  }
  { const Particle *b120 = dfb120.getData<Particle>();
    assert(dfb120.getSize() % sizeof(Particle) == 0);
    int np1 = dfb120.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b120[j1];
  }
  { const Particle *b121 = dfb121.getData<Particle>();
    assert(dfb121.getSize() % sizeof(Particle) == 0);
    int np1 = dfb121.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b121[j1];
  }
  { const Particle *b210 = dfb210.getData<Particle>();
    assert(dfb210.getSize() % sizeof(Particle) == 0);
    int np1 = dfb210.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b210[j1];
  }
  { const Particle *b211 = dfb211.getData<Particle>();
    assert(dfb211.getSize() % sizeof(Particle) == 0);
    int np1 = dfb211.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b211[j1];
  }
  { const Particle *b220 = dfb220.getData<Particle>();
    assert(dfb220.getSize() % sizeof(Particle) == 0);
    int np1 = dfb220.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b220[j1];
  }
  { const Particle *b221 = dfb221.getData<Particle>();
    assert(dfb221.getSize() % sizeof(Particle) == 0);
    int np1 = dfb221.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b221[j1];
  }
  dfnp.setValue(np);
}

void c_mesh3d_exchange_particles_27_get_01_01_11(int np,const InputDF &df_p,real x1,real y1,real z1,real x2,real y2,real z2,
  OutputDF &dfb110,OutputDF &dfb111,OutputDF &dfb112,OutputDF &dfb120,OutputDF &dfb121,OutputDF &dfb122,OutputDF &dfb210,OutputDF &dfb211,OutputDF &dfb212,OutputDF &dfb220,OutputDF &dfb221,OutputDF &dfb222)
{ int j;
  assert(df_p.getSize() == np*sizeof(Particle));
  const Particle *p = df_p.getData<Particle>();
  std::vector<Particle> vp[27];
  for (j=0;j<np;j++)
  {
    real x = p[j].x;
    real y = p[j].y;
    real z = p[j].z;
    real u = p[j].u;
    real v = p[j].v;
    real w = p[j].w;
    int code = 0;
    if (x<x1) { x = 2*x1-x; u = -u; }
    else if (x>=x2) code += 32;
    if (y<y1) { y = 2*y1-y; v = -v; }
    else if (y>=y2) code += 8;
    if (z<z1) code += 1;
    else if (z>=z2) code += 2;
    int dir = code2dir[code];
    vp[dir].push_back(Particle(x,y,z,u,v,w));
  }
  assert(vp[D000].size() == 0);
  assert(vp[D001].size() == 0);
  assert(vp[D002].size() == 0);
  assert(vp[D010].size() == 0);
  assert(vp[D011].size() == 0);
  assert(vp[D012].size() == 0);
  assert(vp[D020].size() == 0);
  assert(vp[D021].size() == 0);
  assert(vp[D022].size() == 0);
  assert(vp[D100].size() == 0);
  assert(vp[D101].size() == 0);
  assert(vp[D102].size() == 0);
  { int np = vp[D110].size();
    int j1;
    Particle *b110 = dfb110.create<Particle>(np);
    for (j=0;j<np;j++) b110[j] = vp[D110][j];
  }
  { int np = vp[D111].size();
    int j1;
    Particle *b111 = dfb111.create<Particle>(np);
    for (j=0;j<np;j++) b111[j] = vp[D111][j];
  }
  { int np = vp[D112].size();
    int j1;
    Particle *b112 = dfb112.create<Particle>(np);
    for (j=0;j<np;j++) b112[j] = vp[D112][j];
  }
  { int np = vp[D120].size();
    int j1;
    Particle *b120 = dfb120.create<Particle>(np);
    for (j=0;j<np;j++) b120[j] = vp[D120][j];
  }
  { int np = vp[D121].size();
    int j1;
    Particle *b121 = dfb121.create<Particle>(np);
    for (j=0;j<np;j++) b121[j] = vp[D121][j];
  }
  { int np = vp[D122].size();
    int j1;
    Particle *b122 = dfb122.create<Particle>(np);
    for (j=0;j<np;j++) b122[j] = vp[D122][j];
  }
  assert(vp[D200].size() == 0);
  assert(vp[D201].size() == 0);
  assert(vp[D202].size() == 0);
  { int np = vp[D210].size();
    int j1;
    Particle *b210 = dfb210.create<Particle>(np);
    for (j=0;j<np;j++) b210[j] = vp[D210][j];
  }
  { int np = vp[D211].size();
    int j1;
    Particle *b211 = dfb211.create<Particle>(np);
    for (j=0;j<np;j++) b211[j] = vp[D211][j];
  }
  { int np = vp[D212].size();
    int j1;
    Particle *b212 = dfb212.create<Particle>(np);
    for (j=0;j<np;j++) b212[j] = vp[D212][j];
  }
  { int np = vp[D220].size();
    int j1;
    Particle *b220 = dfb220.create<Particle>(np);
    for (j=0;j<np;j++) b220[j] = vp[D220][j];
  }
  { int np = vp[D221].size();
    int j1;
    Particle *b221 = dfb221.create<Particle>(np);
    for (j=0;j<np;j++) b221[j] = vp[D221][j];
  }
  { int np = vp[D222].size();
    int j1;
    Particle *b222 = dfb222.create<Particle>(np);
    for (j=0;j<np;j++) b222[j] = vp[D222][j];
  }
}

void c_mesh3d_exchange_particles_27_set_01_01_11(
  const InputDF &dfb110,const InputDF &dfb111,const InputDF &dfb112,const InputDF &dfb120,const InputDF &dfb121,const InputDF &dfb122,const InputDF &dfb210,const InputDF &dfb211,const InputDF &dfb212,const InputDF &dfb220,const InputDF &dfb221,const InputDF &dfb222,
  OutputDF &dfnp,OutputDF &dfp)
{ int np = (dfb110.getSize()+dfb111.getSize()+dfb112.getSize()+dfb120.getSize()+dfb121.getSize()+dfb122.getSize()+dfb210.getSize()+dfb211.getSize()+dfb212.getSize()+dfb220.getSize()+dfb221.getSize()+dfb222.getSize())/sizeof(Particle);
  int j = 0;
  Particle *p =  dfp.create<Particle>(np);
  { const Particle *b110 = dfb110.getData<Particle>();
    assert(dfb110.getSize() % sizeof(Particle) == 0);
    int np1 = dfb110.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b110[j1];
  }
  { const Particle *b111 = dfb111.getData<Particle>();
    assert(dfb111.getSize() % sizeof(Particle) == 0);
    int np1 = dfb111.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b111[j1];
  }
  { const Particle *b112 = dfb112.getData<Particle>();
    assert(dfb112.getSize() % sizeof(Particle) == 0);
    int np1 = dfb112.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b112[j1];
  }
  { const Particle *b120 = dfb120.getData<Particle>();
    assert(dfb120.getSize() % sizeof(Particle) == 0);
    int np1 = dfb120.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b120[j1];
  }
  { const Particle *b121 = dfb121.getData<Particle>();
    assert(dfb121.getSize() % sizeof(Particle) == 0);
    int np1 = dfb121.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b121[j1];
  }
  { const Particle *b122 = dfb122.getData<Particle>();
    assert(dfb122.getSize() % sizeof(Particle) == 0);
    int np1 = dfb122.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b122[j1];
  }
  { const Particle *b210 = dfb210.getData<Particle>();
    assert(dfb210.getSize() % sizeof(Particle) == 0);
    int np1 = dfb210.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b210[j1];
  }
  { const Particle *b211 = dfb211.getData<Particle>();
    assert(dfb211.getSize() % sizeof(Particle) == 0);
    int np1 = dfb211.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b211[j1];
  }
  { const Particle *b212 = dfb212.getData<Particle>();
    assert(dfb212.getSize() % sizeof(Particle) == 0);
    int np1 = dfb212.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b212[j1];
  }
  { const Particle *b220 = dfb220.getData<Particle>();
    assert(dfb220.getSize() % sizeof(Particle) == 0);
    int np1 = dfb220.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b220[j1];
  }
  { const Particle *b221 = dfb221.getData<Particle>();
    assert(dfb221.getSize() % sizeof(Particle) == 0);
    int np1 = dfb221.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b221[j1];
  }
  { const Particle *b222 = dfb222.getData<Particle>();
    assert(dfb222.getSize() % sizeof(Particle) == 0);
    int np1 = dfb222.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b222[j1];
  }
  dfnp.setValue(np);
}

void c_mesh3d_exchange_particles_27_get_01_10_00(int np,const InputDF &df_p,real x1,real y1,real z1,real x2,real y2,real z2,
  OutputDF &dfb101,OutputDF &dfb111,OutputDF &dfb201,OutputDF &dfb211)
{ int j;
  assert(df_p.getSize() == np*sizeof(Particle));
  const Particle *p = df_p.getData<Particle>();
  std::vector<Particle> vp[27];
  for (j=0;j<np;j++)
  {
    real x = p[j].x;
    real y = p[j].y;
    real z = p[j].z;
    real u = p[j].u;
    real v = p[j].v;
    real w = p[j].w;
    int code = 0;
    if (x<x1) { x = 2*x1-x; u = -u; }
    else if (x>=x2) code += 32;
    if (y<y1) code += 4;
    else if (y>=y2) { y = 2*y2-y; v = -v; }
    if (z<z1) { z = 2*z1-z; w = -w; }
    else if (z>=z2) { z = 2*z2-z; w = -w; }
    int dir = code2dir[code];
    vp[dir].push_back(Particle(x,y,z,u,v,w));
  }
  assert(vp[D000].size() == 0);
  assert(vp[D001].size() == 0);
  assert(vp[D002].size() == 0);
  assert(vp[D010].size() == 0);
  assert(vp[D011].size() == 0);
  assert(vp[D012].size() == 0);
  assert(vp[D020].size() == 0);
  assert(vp[D021].size() == 0);
  assert(vp[D022].size() == 0);
  assert(vp[D100].size() == 0);
  { int np = vp[D101].size();
    int j1;
    Particle *b101 = dfb101.create<Particle>(np);
    for (j=0;j<np;j++) b101[j] = vp[D101][j];
  }
  assert(vp[D102].size() == 0);
  assert(vp[D110].size() == 0);
  { int np = vp[D111].size();
    int j1;
    Particle *b111 = dfb111.create<Particle>(np);
    for (j=0;j<np;j++) b111[j] = vp[D111][j];
  }
  assert(vp[D112].size() == 0);
  assert(vp[D120].size() == 0);
  assert(vp[D121].size() == 0);
  assert(vp[D122].size() == 0);
  assert(vp[D200].size() == 0);
  { int np = vp[D201].size();
    int j1;
    Particle *b201 = dfb201.create<Particle>(np);
    for (j=0;j<np;j++) b201[j] = vp[D201][j];
  }
  assert(vp[D202].size() == 0);
  assert(vp[D210].size() == 0);
  { int np = vp[D211].size();
    int j1;
    Particle *b211 = dfb211.create<Particle>(np);
    for (j=0;j<np;j++) b211[j] = vp[D211][j];
  }
  assert(vp[D212].size() == 0);
  assert(vp[D220].size() == 0);
  assert(vp[D221].size() == 0);
  assert(vp[D222].size() == 0);
}

void c_mesh3d_exchange_particles_27_set_01_10_00(
  const InputDF &dfb101,const InputDF &dfb111,const InputDF &dfb201,const InputDF &dfb211,
  OutputDF &dfnp,OutputDF &dfp)
{ int np = (dfb101.getSize()+dfb111.getSize()+dfb201.getSize()+dfb211.getSize())/sizeof(Particle);
  int j = 0;
  Particle *p =  dfp.create<Particle>(np);
  { const Particle *b101 = dfb101.getData<Particle>();
    assert(dfb101.getSize() % sizeof(Particle) == 0);
    int np1 = dfb101.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b101[j1];
  }
  { const Particle *b111 = dfb111.getData<Particle>();
    assert(dfb111.getSize() % sizeof(Particle) == 0);
    int np1 = dfb111.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b111[j1];
  }
  { const Particle *b201 = dfb201.getData<Particle>();
    assert(dfb201.getSize() % sizeof(Particle) == 0);
    int np1 = dfb201.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b201[j1];
  }
  { const Particle *b211 = dfb211.getData<Particle>();
    assert(dfb211.getSize() % sizeof(Particle) == 0);
    int np1 = dfb211.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b211[j1];
  }
  dfnp.setValue(np);
}

void c_mesh3d_exchange_particles_27_get_01_10_01(int np,const InputDF &df_p,real x1,real y1,real z1,real x2,real y2,real z2,
  OutputDF &dfb101,OutputDF &dfb102,OutputDF &dfb111,OutputDF &dfb112,OutputDF &dfb201,OutputDF &dfb202,OutputDF &dfb211,OutputDF &dfb212)
{ int j;
  assert(df_p.getSize() == np*sizeof(Particle));
  const Particle *p = df_p.getData<Particle>();
  std::vector<Particle> vp[27];
  for (j=0;j<np;j++)
  {
    real x = p[j].x;
    real y = p[j].y;
    real z = p[j].z;
    real u = p[j].u;
    real v = p[j].v;
    real w = p[j].w;
    int code = 0;
    if (x<x1) { x = 2*x1-x; u = -u; }
    else if (x>=x2) code += 32;
    if (y<y1) code += 4;
    else if (y>=y2) { y = 2*y2-y; v = -v; }
    if (z<z1) { z = 2*z1-z; w = -w; }
    else if (z>=z2) code += 2;
    int dir = code2dir[code];
    vp[dir].push_back(Particle(x,y,z,u,v,w));
  }
  assert(vp[D000].size() == 0);
  assert(vp[D001].size() == 0);
  assert(vp[D002].size() == 0);
  assert(vp[D010].size() == 0);
  assert(vp[D011].size() == 0);
  assert(vp[D012].size() == 0);
  assert(vp[D020].size() == 0);
  assert(vp[D021].size() == 0);
  assert(vp[D022].size() == 0);
  assert(vp[D100].size() == 0);
  { int np = vp[D101].size();
    int j1;
    Particle *b101 = dfb101.create<Particle>(np);
    for (j=0;j<np;j++) b101[j] = vp[D101][j];
  }
  { int np = vp[D102].size();
    int j1;
    Particle *b102 = dfb102.create<Particle>(np);
    for (j=0;j<np;j++) b102[j] = vp[D102][j];
  }
  assert(vp[D110].size() == 0);
  { int np = vp[D111].size();
    int j1;
    Particle *b111 = dfb111.create<Particle>(np);
    for (j=0;j<np;j++) b111[j] = vp[D111][j];
  }
  { int np = vp[D112].size();
    int j1;
    Particle *b112 = dfb112.create<Particle>(np);
    for (j=0;j<np;j++) b112[j] = vp[D112][j];
  }
  assert(vp[D120].size() == 0);
  assert(vp[D121].size() == 0);
  assert(vp[D122].size() == 0);
  assert(vp[D200].size() == 0);
  { int np = vp[D201].size();
    int j1;
    Particle *b201 = dfb201.create<Particle>(np);
    for (j=0;j<np;j++) b201[j] = vp[D201][j];
  }
  { int np = vp[D202].size();
    int j1;
    Particle *b202 = dfb202.create<Particle>(np);
    for (j=0;j<np;j++) b202[j] = vp[D202][j];
  }
  assert(vp[D210].size() == 0);
  { int np = vp[D211].size();
    int j1;
    Particle *b211 = dfb211.create<Particle>(np);
    for (j=0;j<np;j++) b211[j] = vp[D211][j];
  }
  { int np = vp[D212].size();
    int j1;
    Particle *b212 = dfb212.create<Particle>(np);
    for (j=0;j<np;j++) b212[j] = vp[D212][j];
  }
  assert(vp[D220].size() == 0);
  assert(vp[D221].size() == 0);
  assert(vp[D222].size() == 0);
}

void c_mesh3d_exchange_particles_27_set_01_10_01(
  const InputDF &dfb101,const InputDF &dfb102,const InputDF &dfb111,const InputDF &dfb112,const InputDF &dfb201,const InputDF &dfb202,const InputDF &dfb211,const InputDF &dfb212,
  OutputDF &dfnp,OutputDF &dfp)
{ int np = (dfb101.getSize()+dfb102.getSize()+dfb111.getSize()+dfb112.getSize()+dfb201.getSize()+dfb202.getSize()+dfb211.getSize()+dfb212.getSize())/sizeof(Particle);
  int j = 0;
  Particle *p =  dfp.create<Particle>(np);
  { const Particle *b101 = dfb101.getData<Particle>();
    assert(dfb101.getSize() % sizeof(Particle) == 0);
    int np1 = dfb101.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b101[j1];
  }
  { const Particle *b102 = dfb102.getData<Particle>();
    assert(dfb102.getSize() % sizeof(Particle) == 0);
    int np1 = dfb102.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b102[j1];
  }
  { const Particle *b111 = dfb111.getData<Particle>();
    assert(dfb111.getSize() % sizeof(Particle) == 0);
    int np1 = dfb111.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b111[j1];
  }
  { const Particle *b112 = dfb112.getData<Particle>();
    assert(dfb112.getSize() % sizeof(Particle) == 0);
    int np1 = dfb112.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b112[j1];
  }
  { const Particle *b201 = dfb201.getData<Particle>();
    assert(dfb201.getSize() % sizeof(Particle) == 0);
    int np1 = dfb201.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b201[j1];
  }
  { const Particle *b202 = dfb202.getData<Particle>();
    assert(dfb202.getSize() % sizeof(Particle) == 0);
    int np1 = dfb202.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b202[j1];
  }
  { const Particle *b211 = dfb211.getData<Particle>();
    assert(dfb211.getSize() % sizeof(Particle) == 0);
    int np1 = dfb211.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b211[j1];
  }
  { const Particle *b212 = dfb212.getData<Particle>();
    assert(dfb212.getSize() % sizeof(Particle) == 0);
    int np1 = dfb212.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b212[j1];
  }
  dfnp.setValue(np);
}

void c_mesh3d_exchange_particles_27_get_01_10_10(int np,const InputDF &df_p,real x1,real y1,real z1,real x2,real y2,real z2,
  OutputDF &dfb100,OutputDF &dfb101,OutputDF &dfb110,OutputDF &dfb111,OutputDF &dfb200,OutputDF &dfb201,OutputDF &dfb210,OutputDF &dfb211)
{ int j;
  assert(df_p.getSize() == np*sizeof(Particle));
  const Particle *p = df_p.getData<Particle>();
  std::vector<Particle> vp[27];
  for (j=0;j<np;j++)
  {
    real x = p[j].x;
    real y = p[j].y;
    real z = p[j].z;
    real u = p[j].u;
    real v = p[j].v;
    real w = p[j].w;
    int code = 0;
    if (x<x1) { x = 2*x1-x; u = -u; }
    else if (x>=x2) code += 32;
    if (y<y1) code += 4;
    else if (y>=y2) { y = 2*y2-y; v = -v; }
    if (z<z1) code += 1;
    else if (z>=z2) { z = 2*z2-z; w = -w; }
    int dir = code2dir[code];
    vp[dir].push_back(Particle(x,y,z,u,v,w));
  }
  assert(vp[D000].size() == 0);
  assert(vp[D001].size() == 0);
  assert(vp[D002].size() == 0);
  assert(vp[D010].size() == 0);
  assert(vp[D011].size() == 0);
  assert(vp[D012].size() == 0);
  assert(vp[D020].size() == 0);
  assert(vp[D021].size() == 0);
  assert(vp[D022].size() == 0);
  { int np = vp[D100].size();
    int j1;
    Particle *b100 = dfb100.create<Particle>(np);
    for (j=0;j<np;j++) b100[j] = vp[D100][j];
  }
  { int np = vp[D101].size();
    int j1;
    Particle *b101 = dfb101.create<Particle>(np);
    for (j=0;j<np;j++) b101[j] = vp[D101][j];
  }
  assert(vp[D102].size() == 0);
  { int np = vp[D110].size();
    int j1;
    Particle *b110 = dfb110.create<Particle>(np);
    for (j=0;j<np;j++) b110[j] = vp[D110][j];
  }
  { int np = vp[D111].size();
    int j1;
    Particle *b111 = dfb111.create<Particle>(np);
    for (j=0;j<np;j++) b111[j] = vp[D111][j];
  }
  assert(vp[D112].size() == 0);
  assert(vp[D120].size() == 0);
  assert(vp[D121].size() == 0);
  assert(vp[D122].size() == 0);
  { int np = vp[D200].size();
    int j1;
    Particle *b200 = dfb200.create<Particle>(np);
    for (j=0;j<np;j++) b200[j] = vp[D200][j];
  }
  { int np = vp[D201].size();
    int j1;
    Particle *b201 = dfb201.create<Particle>(np);
    for (j=0;j<np;j++) b201[j] = vp[D201][j];
  }
  assert(vp[D202].size() == 0);
  { int np = vp[D210].size();
    int j1;
    Particle *b210 = dfb210.create<Particle>(np);
    for (j=0;j<np;j++) b210[j] = vp[D210][j];
  }
  { int np = vp[D211].size();
    int j1;
    Particle *b211 = dfb211.create<Particle>(np);
    for (j=0;j<np;j++) b211[j] = vp[D211][j];
  }
  assert(vp[D212].size() == 0);
  assert(vp[D220].size() == 0);
  assert(vp[D221].size() == 0);
  assert(vp[D222].size() == 0);
}

void c_mesh3d_exchange_particles_27_set_01_10_10(
  const InputDF &dfb100,const InputDF &dfb101,const InputDF &dfb110,const InputDF &dfb111,const InputDF &dfb200,const InputDF &dfb201,const InputDF &dfb210,const InputDF &dfb211,
  OutputDF &dfnp,OutputDF &dfp)
{ int np = (dfb100.getSize()+dfb101.getSize()+dfb110.getSize()+dfb111.getSize()+dfb200.getSize()+dfb201.getSize()+dfb210.getSize()+dfb211.getSize())/sizeof(Particle);
  int j = 0;
  Particle *p =  dfp.create<Particle>(np);
  { const Particle *b100 = dfb100.getData<Particle>();
    assert(dfb100.getSize() % sizeof(Particle) == 0);
    int np1 = dfb100.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b100[j1];
  }
  { const Particle *b101 = dfb101.getData<Particle>();
    assert(dfb101.getSize() % sizeof(Particle) == 0);
    int np1 = dfb101.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b101[j1];
  }
  { const Particle *b110 = dfb110.getData<Particle>();
    assert(dfb110.getSize() % sizeof(Particle) == 0);
    int np1 = dfb110.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b110[j1];
  }
  { const Particle *b111 = dfb111.getData<Particle>();
    assert(dfb111.getSize() % sizeof(Particle) == 0);
    int np1 = dfb111.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b111[j1];
  }
  { const Particle *b200 = dfb200.getData<Particle>();
    assert(dfb200.getSize() % sizeof(Particle) == 0);
    int np1 = dfb200.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b200[j1];
  }
  { const Particle *b201 = dfb201.getData<Particle>();
    assert(dfb201.getSize() % sizeof(Particle) == 0);
    int np1 = dfb201.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b201[j1];
  }
  { const Particle *b210 = dfb210.getData<Particle>();
    assert(dfb210.getSize() % sizeof(Particle) == 0);
    int np1 = dfb210.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b210[j1];
  }
  { const Particle *b211 = dfb211.getData<Particle>();
    assert(dfb211.getSize() % sizeof(Particle) == 0);
    int np1 = dfb211.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b211[j1];
  }
  dfnp.setValue(np);
}

void c_mesh3d_exchange_particles_27_get_01_10_11(int np,const InputDF &df_p,real x1,real y1,real z1,real x2,real y2,real z2,
  OutputDF &dfb100,OutputDF &dfb101,OutputDF &dfb102,OutputDF &dfb110,OutputDF &dfb111,OutputDF &dfb112,OutputDF &dfb200,OutputDF &dfb201,OutputDF &dfb202,OutputDF &dfb210,OutputDF &dfb211,OutputDF &dfb212)
{ int j;
  assert(df_p.getSize() == np*sizeof(Particle));
  const Particle *p = df_p.getData<Particle>();
  std::vector<Particle> vp[27];
  for (j=0;j<np;j++)
  {
    real x = p[j].x;
    real y = p[j].y;
    real z = p[j].z;
    real u = p[j].u;
    real v = p[j].v;
    real w = p[j].w;
    int code = 0;
    if (x<x1) { x = 2*x1-x; u = -u; }
    else if (x>=x2) code += 32;
    if (y<y1) code += 4;
    else if (y>=y2) { y = 2*y2-y; v = -v; }
    if (z<z1) code += 1;
    else if (z>=z2) code += 2;
    int dir = code2dir[code];
    vp[dir].push_back(Particle(x,y,z,u,v,w));
  }
  assert(vp[D000].size() == 0);
  assert(vp[D001].size() == 0);
  assert(vp[D002].size() == 0);
  assert(vp[D010].size() == 0);
  assert(vp[D011].size() == 0);
  assert(vp[D012].size() == 0);
  assert(vp[D020].size() == 0);
  assert(vp[D021].size() == 0);
  assert(vp[D022].size() == 0);
  { int np = vp[D100].size();
    int j1;
    Particle *b100 = dfb100.create<Particle>(np);
    for (j=0;j<np;j++) b100[j] = vp[D100][j];
  }
  { int np = vp[D101].size();
    int j1;
    Particle *b101 = dfb101.create<Particle>(np);
    for (j=0;j<np;j++) b101[j] = vp[D101][j];
  }
  { int np = vp[D102].size();
    int j1;
    Particle *b102 = dfb102.create<Particle>(np);
    for (j=0;j<np;j++) b102[j] = vp[D102][j];
  }
  { int np = vp[D110].size();
    int j1;
    Particle *b110 = dfb110.create<Particle>(np);
    for (j=0;j<np;j++) b110[j] = vp[D110][j];
  }
  { int np = vp[D111].size();
    int j1;
    Particle *b111 = dfb111.create<Particle>(np);
    for (j=0;j<np;j++) b111[j] = vp[D111][j];
  }
  { int np = vp[D112].size();
    int j1;
    Particle *b112 = dfb112.create<Particle>(np);
    for (j=0;j<np;j++) b112[j] = vp[D112][j];
  }
  assert(vp[D120].size() == 0);
  assert(vp[D121].size() == 0);
  assert(vp[D122].size() == 0);
  { int np = vp[D200].size();
    int j1;
    Particle *b200 = dfb200.create<Particle>(np);
    for (j=0;j<np;j++) b200[j] = vp[D200][j];
  }
  { int np = vp[D201].size();
    int j1;
    Particle *b201 = dfb201.create<Particle>(np);
    for (j=0;j<np;j++) b201[j] = vp[D201][j];
  }
  { int np = vp[D202].size();
    int j1;
    Particle *b202 = dfb202.create<Particle>(np);
    for (j=0;j<np;j++) b202[j] = vp[D202][j];
  }
  { int np = vp[D210].size();
    int j1;
    Particle *b210 = dfb210.create<Particle>(np);
    for (j=0;j<np;j++) b210[j] = vp[D210][j];
  }
  { int np = vp[D211].size();
    int j1;
    Particle *b211 = dfb211.create<Particle>(np);
    for (j=0;j<np;j++) b211[j] = vp[D211][j];
  }
  { int np = vp[D212].size();
    int j1;
    Particle *b212 = dfb212.create<Particle>(np);
    for (j=0;j<np;j++) b212[j] = vp[D212][j];
  }
  assert(vp[D220].size() == 0);
  assert(vp[D221].size() == 0);
  assert(vp[D222].size() == 0);
}

void c_mesh3d_exchange_particles_27_set_01_10_11(
  const InputDF &dfb100,const InputDF &dfb101,const InputDF &dfb102,const InputDF &dfb110,const InputDF &dfb111,const InputDF &dfb112,const InputDF &dfb200,const InputDF &dfb201,const InputDF &dfb202,const InputDF &dfb210,const InputDF &dfb211,const InputDF &dfb212,
  OutputDF &dfnp,OutputDF &dfp)
{ int np = (dfb100.getSize()+dfb101.getSize()+dfb102.getSize()+dfb110.getSize()+dfb111.getSize()+dfb112.getSize()+dfb200.getSize()+dfb201.getSize()+dfb202.getSize()+dfb210.getSize()+dfb211.getSize()+dfb212.getSize())/sizeof(Particle);
  int j = 0;
  Particle *p =  dfp.create<Particle>(np);
  { const Particle *b100 = dfb100.getData<Particle>();
    assert(dfb100.getSize() % sizeof(Particle) == 0);
    int np1 = dfb100.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b100[j1];
  }
  { const Particle *b101 = dfb101.getData<Particle>();
    assert(dfb101.getSize() % sizeof(Particle) == 0);
    int np1 = dfb101.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b101[j1];
  }
  { const Particle *b102 = dfb102.getData<Particle>();
    assert(dfb102.getSize() % sizeof(Particle) == 0);
    int np1 = dfb102.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b102[j1];
  }
  { const Particle *b110 = dfb110.getData<Particle>();
    assert(dfb110.getSize() % sizeof(Particle) == 0);
    int np1 = dfb110.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b110[j1];
  }
  { const Particle *b111 = dfb111.getData<Particle>();
    assert(dfb111.getSize() % sizeof(Particle) == 0);
    int np1 = dfb111.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b111[j1];
  }
  { const Particle *b112 = dfb112.getData<Particle>();
    assert(dfb112.getSize() % sizeof(Particle) == 0);
    int np1 = dfb112.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b112[j1];
  }
  { const Particle *b200 = dfb200.getData<Particle>();
    assert(dfb200.getSize() % sizeof(Particle) == 0);
    int np1 = dfb200.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b200[j1];
  }
  { const Particle *b201 = dfb201.getData<Particle>();
    assert(dfb201.getSize() % sizeof(Particle) == 0);
    int np1 = dfb201.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b201[j1];
  }
  { const Particle *b202 = dfb202.getData<Particle>();
    assert(dfb202.getSize() % sizeof(Particle) == 0);
    int np1 = dfb202.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b202[j1];
  }
  { const Particle *b210 = dfb210.getData<Particle>();
    assert(dfb210.getSize() % sizeof(Particle) == 0);
    int np1 = dfb210.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b210[j1];
  }
  { const Particle *b211 = dfb211.getData<Particle>();
    assert(dfb211.getSize() % sizeof(Particle) == 0);
    int np1 = dfb211.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b211[j1];
  }
  { const Particle *b212 = dfb212.getData<Particle>();
    assert(dfb212.getSize() % sizeof(Particle) == 0);
    int np1 = dfb212.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b212[j1];
  }
  dfnp.setValue(np);
}

void c_mesh3d_exchange_particles_27_get_01_11_00(int np,const InputDF &df_p,real x1,real y1,real z1,real x2,real y2,real z2,
  OutputDF &dfb101,OutputDF &dfb111,OutputDF &dfb121,OutputDF &dfb201,OutputDF &dfb211,OutputDF &dfb221)
{ int j;
  assert(df_p.getSize() == np*sizeof(Particle));
  const Particle *p = df_p.getData<Particle>();
  std::vector<Particle> vp[27];
  for (j=0;j<np;j++)
  {
    real x = p[j].x;
    real y = p[j].y;
    real z = p[j].z;
    real u = p[j].u;
    real v = p[j].v;
    real w = p[j].w;
    int code = 0;
    if (x<x1) { x = 2*x1-x; u = -u; }
    else if (x>=x2) code += 32;
    if (y<y1) code += 4;
    else if (y>=y2) code += 8;
    if (z<z1) { z = 2*z1-z; w = -w; }
    else if (z>=z2) { z = 2*z2-z; w = -w; }
    int dir = code2dir[code];
    vp[dir].push_back(Particle(x,y,z,u,v,w));
  }
  assert(vp[D000].size() == 0);
  assert(vp[D001].size() == 0);
  assert(vp[D002].size() == 0);
  assert(vp[D010].size() == 0);
  assert(vp[D011].size() == 0);
  assert(vp[D012].size() == 0);
  assert(vp[D020].size() == 0);
  assert(vp[D021].size() == 0);
  assert(vp[D022].size() == 0);
  assert(vp[D100].size() == 0);
  { int np = vp[D101].size();
    int j1;
    Particle *b101 = dfb101.create<Particle>(np);
    for (j=0;j<np;j++) b101[j] = vp[D101][j];
  }
  assert(vp[D102].size() == 0);
  assert(vp[D110].size() == 0);
  { int np = vp[D111].size();
    int j1;
    Particle *b111 = dfb111.create<Particle>(np);
    for (j=0;j<np;j++) b111[j] = vp[D111][j];
  }
  assert(vp[D112].size() == 0);
  assert(vp[D120].size() == 0);
  { int np = vp[D121].size();
    int j1;
    Particle *b121 = dfb121.create<Particle>(np);
    for (j=0;j<np;j++) b121[j] = vp[D121][j];
  }
  assert(vp[D122].size() == 0);
  assert(vp[D200].size() == 0);
  { int np = vp[D201].size();
    int j1;
    Particle *b201 = dfb201.create<Particle>(np);
    for (j=0;j<np;j++) b201[j] = vp[D201][j];
  }
  assert(vp[D202].size() == 0);
  assert(vp[D210].size() == 0);
  { int np = vp[D211].size();
    int j1;
    Particle *b211 = dfb211.create<Particle>(np);
    for (j=0;j<np;j++) b211[j] = vp[D211][j];
  }
  assert(vp[D212].size() == 0);
  assert(vp[D220].size() == 0);
  { int np = vp[D221].size();
    int j1;
    Particle *b221 = dfb221.create<Particle>(np);
    for (j=0;j<np;j++) b221[j] = vp[D221][j];
  }
  assert(vp[D222].size() == 0);
}

void c_mesh3d_exchange_particles_27_set_01_11_00(
  const InputDF &dfb101,const InputDF &dfb111,const InputDF &dfb121,const InputDF &dfb201,const InputDF &dfb211,const InputDF &dfb221,
  OutputDF &dfnp,OutputDF &dfp)
{ int np = (dfb101.getSize()+dfb111.getSize()+dfb121.getSize()+dfb201.getSize()+dfb211.getSize()+dfb221.getSize())/sizeof(Particle);
  int j = 0;
  Particle *p =  dfp.create<Particle>(np);
  { const Particle *b101 = dfb101.getData<Particle>();
    assert(dfb101.getSize() % sizeof(Particle) == 0);
    int np1 = dfb101.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b101[j1];
  }
  { const Particle *b111 = dfb111.getData<Particle>();
    assert(dfb111.getSize() % sizeof(Particle) == 0);
    int np1 = dfb111.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b111[j1];
  }
  { const Particle *b121 = dfb121.getData<Particle>();
    assert(dfb121.getSize() % sizeof(Particle) == 0);
    int np1 = dfb121.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b121[j1];
  }
  { const Particle *b201 = dfb201.getData<Particle>();
    assert(dfb201.getSize() % sizeof(Particle) == 0);
    int np1 = dfb201.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b201[j1];
  }
  { const Particle *b211 = dfb211.getData<Particle>();
    assert(dfb211.getSize() % sizeof(Particle) == 0);
    int np1 = dfb211.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b211[j1];
  }
  { const Particle *b221 = dfb221.getData<Particle>();
    assert(dfb221.getSize() % sizeof(Particle) == 0);
    int np1 = dfb221.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b221[j1];
  }
  dfnp.setValue(np);
}

void c_mesh3d_exchange_particles_27_get_01_11_01(int np,const InputDF &df_p,real x1,real y1,real z1,real x2,real y2,real z2,
  OutputDF &dfb101,OutputDF &dfb102,OutputDF &dfb111,OutputDF &dfb112,OutputDF &dfb121,OutputDF &dfb122,OutputDF &dfb201,OutputDF &dfb202,OutputDF &dfb211,OutputDF &dfb212,OutputDF &dfb221,OutputDF &dfb222)
{ int j;
  assert(df_p.getSize() == np*sizeof(Particle));
  const Particle *p = df_p.getData<Particle>();
  std::vector<Particle> vp[27];
  for (j=0;j<np;j++)
  {
    real x = p[j].x;
    real y = p[j].y;
    real z = p[j].z;
    real u = p[j].u;
    real v = p[j].v;
    real w = p[j].w;
    int code = 0;
    if (x<x1) { x = 2*x1-x; u = -u; }
    else if (x>=x2) code += 32;
    if (y<y1) code += 4;
    else if (y>=y2) code += 8;
    if (z<z1) { z = 2*z1-z; w = -w; }
    else if (z>=z2) code += 2;
    int dir = code2dir[code];
    vp[dir].push_back(Particle(x,y,z,u,v,w));
  }
  assert(vp[D000].size() == 0);
  assert(vp[D001].size() == 0);
  assert(vp[D002].size() == 0);
  assert(vp[D010].size() == 0);
  assert(vp[D011].size() == 0);
  assert(vp[D012].size() == 0);
  assert(vp[D020].size() == 0);
  assert(vp[D021].size() == 0);
  assert(vp[D022].size() == 0);
  assert(vp[D100].size() == 0);
  { int np = vp[D101].size();
    int j1;
    Particle *b101 = dfb101.create<Particle>(np);
    for (j=0;j<np;j++) b101[j] = vp[D101][j];
  }
  { int np = vp[D102].size();
    int j1;
    Particle *b102 = dfb102.create<Particle>(np);
    for (j=0;j<np;j++) b102[j] = vp[D102][j];
  }
  assert(vp[D110].size() == 0);
  { int np = vp[D111].size();
    int j1;
    Particle *b111 = dfb111.create<Particle>(np);
    for (j=0;j<np;j++) b111[j] = vp[D111][j];
  }
  { int np = vp[D112].size();
    int j1;
    Particle *b112 = dfb112.create<Particle>(np);
    for (j=0;j<np;j++) b112[j] = vp[D112][j];
  }
  assert(vp[D120].size() == 0);
  { int np = vp[D121].size();
    int j1;
    Particle *b121 = dfb121.create<Particle>(np);
    for (j=0;j<np;j++) b121[j] = vp[D121][j];
  }
  { int np = vp[D122].size();
    int j1;
    Particle *b122 = dfb122.create<Particle>(np);
    for (j=0;j<np;j++) b122[j] = vp[D122][j];
  }
  assert(vp[D200].size() == 0);
  { int np = vp[D201].size();
    int j1;
    Particle *b201 = dfb201.create<Particle>(np);
    for (j=0;j<np;j++) b201[j] = vp[D201][j];
  }
  { int np = vp[D202].size();
    int j1;
    Particle *b202 = dfb202.create<Particle>(np);
    for (j=0;j<np;j++) b202[j] = vp[D202][j];
  }
  assert(vp[D210].size() == 0);
  { int np = vp[D211].size();
    int j1;
    Particle *b211 = dfb211.create<Particle>(np);
    for (j=0;j<np;j++) b211[j] = vp[D211][j];
  }
  { int np = vp[D212].size();
    int j1;
    Particle *b212 = dfb212.create<Particle>(np);
    for (j=0;j<np;j++) b212[j] = vp[D212][j];
  }
  assert(vp[D220].size() == 0);
  { int np = vp[D221].size();
    int j1;
    Particle *b221 = dfb221.create<Particle>(np);
    for (j=0;j<np;j++) b221[j] = vp[D221][j];
  }
  { int np = vp[D222].size();
    int j1;
    Particle *b222 = dfb222.create<Particle>(np);
    for (j=0;j<np;j++) b222[j] = vp[D222][j];
  }
}

void c_mesh3d_exchange_particles_27_set_01_11_01(
  const InputDF &dfb101,const InputDF &dfb102,const InputDF &dfb111,const InputDF &dfb112,const InputDF &dfb121,const InputDF &dfb122,const InputDF &dfb201,const InputDF &dfb202,const InputDF &dfb211,const InputDF &dfb212,const InputDF &dfb221,const InputDF &dfb222,
  OutputDF &dfnp,OutputDF &dfp)
{ int np = (dfb101.getSize()+dfb102.getSize()+dfb111.getSize()+dfb112.getSize()+dfb121.getSize()+dfb122.getSize()+dfb201.getSize()+dfb202.getSize()+dfb211.getSize()+dfb212.getSize()+dfb221.getSize()+dfb222.getSize())/sizeof(Particle);
  int j = 0;
  Particle *p =  dfp.create<Particle>(np);
  { const Particle *b101 = dfb101.getData<Particle>();
    assert(dfb101.getSize() % sizeof(Particle) == 0);
    int np1 = dfb101.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b101[j1];
  }
  { const Particle *b102 = dfb102.getData<Particle>();
    assert(dfb102.getSize() % sizeof(Particle) == 0);
    int np1 = dfb102.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b102[j1];
  }
  { const Particle *b111 = dfb111.getData<Particle>();
    assert(dfb111.getSize() % sizeof(Particle) == 0);
    int np1 = dfb111.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b111[j1];
  }
  { const Particle *b112 = dfb112.getData<Particle>();
    assert(dfb112.getSize() % sizeof(Particle) == 0);
    int np1 = dfb112.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b112[j1];
  }
  { const Particle *b121 = dfb121.getData<Particle>();
    assert(dfb121.getSize() % sizeof(Particle) == 0);
    int np1 = dfb121.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b121[j1];
  }
  { const Particle *b122 = dfb122.getData<Particle>();
    assert(dfb122.getSize() % sizeof(Particle) == 0);
    int np1 = dfb122.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b122[j1];
  }
  { const Particle *b201 = dfb201.getData<Particle>();
    assert(dfb201.getSize() % sizeof(Particle) == 0);
    int np1 = dfb201.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b201[j1];
  }
  { const Particle *b202 = dfb202.getData<Particle>();
    assert(dfb202.getSize() % sizeof(Particle) == 0);
    int np1 = dfb202.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b202[j1];
  }
  { const Particle *b211 = dfb211.getData<Particle>();
    assert(dfb211.getSize() % sizeof(Particle) == 0);
    int np1 = dfb211.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b211[j1];
  }
  { const Particle *b212 = dfb212.getData<Particle>();
    assert(dfb212.getSize() % sizeof(Particle) == 0);
    int np1 = dfb212.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b212[j1];
  }
  { const Particle *b221 = dfb221.getData<Particle>();
    assert(dfb221.getSize() % sizeof(Particle) == 0);
    int np1 = dfb221.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b221[j1];
  }
  { const Particle *b222 = dfb222.getData<Particle>();
    assert(dfb222.getSize() % sizeof(Particle) == 0);
    int np1 = dfb222.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b222[j1];
  }
  dfnp.setValue(np);
}

void c_mesh3d_exchange_particles_27_get_01_11_10(int np,const InputDF &df_p,real x1,real y1,real z1,real x2,real y2,real z2,
  OutputDF &dfb100,OutputDF &dfb101,OutputDF &dfb110,OutputDF &dfb111,OutputDF &dfb120,OutputDF &dfb121,OutputDF &dfb200,OutputDF &dfb201,OutputDF &dfb210,OutputDF &dfb211,OutputDF &dfb220,OutputDF &dfb221)
{ int j;
  assert(df_p.getSize() == np*sizeof(Particle));
  const Particle *p = df_p.getData<Particle>();
  std::vector<Particle> vp[27];
  for (j=0;j<np;j++)
  {
    real x = p[j].x;
    real y = p[j].y;
    real z = p[j].z;
    real u = p[j].u;
    real v = p[j].v;
    real w = p[j].w;
    int code = 0;
    if (x<x1) { x = 2*x1-x; u = -u; }
    else if (x>=x2) code += 32;
    if (y<y1) code += 4;
    else if (y>=y2) code += 8;
    if (z<z1) code += 1;
    else if (z>=z2) { z = 2*z2-z; w = -w; }
    int dir = code2dir[code];
    vp[dir].push_back(Particle(x,y,z,u,v,w));
  }
  assert(vp[D000].size() == 0);
  assert(vp[D001].size() == 0);
  assert(vp[D002].size() == 0);
  assert(vp[D010].size() == 0);
  assert(vp[D011].size() == 0);
  assert(vp[D012].size() == 0);
  assert(vp[D020].size() == 0);
  assert(vp[D021].size() == 0);
  assert(vp[D022].size() == 0);
  { int np = vp[D100].size();
    int j1;
    Particle *b100 = dfb100.create<Particle>(np);
    for (j=0;j<np;j++) b100[j] = vp[D100][j];
  }
  { int np = vp[D101].size();
    int j1;
    Particle *b101 = dfb101.create<Particle>(np);
    for (j=0;j<np;j++) b101[j] = vp[D101][j];
  }
  assert(vp[D102].size() == 0);
  { int np = vp[D110].size();
    int j1;
    Particle *b110 = dfb110.create<Particle>(np);
    for (j=0;j<np;j++) b110[j] = vp[D110][j];
  }
  { int np = vp[D111].size();
    int j1;
    Particle *b111 = dfb111.create<Particle>(np);
    for (j=0;j<np;j++) b111[j] = vp[D111][j];
  }
  assert(vp[D112].size() == 0);
  { int np = vp[D120].size();
    int j1;
    Particle *b120 = dfb120.create<Particle>(np);
    for (j=0;j<np;j++) b120[j] = vp[D120][j];
  }
  { int np = vp[D121].size();
    int j1;
    Particle *b121 = dfb121.create<Particle>(np);
    for (j=0;j<np;j++) b121[j] = vp[D121][j];
  }
  assert(vp[D122].size() == 0);
  { int np = vp[D200].size();
    int j1;
    Particle *b200 = dfb200.create<Particle>(np);
    for (j=0;j<np;j++) b200[j] = vp[D200][j];
  }
  { int np = vp[D201].size();
    int j1;
    Particle *b201 = dfb201.create<Particle>(np);
    for (j=0;j<np;j++) b201[j] = vp[D201][j];
  }
  assert(vp[D202].size() == 0);
  { int np = vp[D210].size();
    int j1;
    Particle *b210 = dfb210.create<Particle>(np);
    for (j=0;j<np;j++) b210[j] = vp[D210][j];
  }
  { int np = vp[D211].size();
    int j1;
    Particle *b211 = dfb211.create<Particle>(np);
    for (j=0;j<np;j++) b211[j] = vp[D211][j];
  }
  assert(vp[D212].size() == 0);
  { int np = vp[D220].size();
    int j1;
    Particle *b220 = dfb220.create<Particle>(np);
    for (j=0;j<np;j++) b220[j] = vp[D220][j];
  }
  { int np = vp[D221].size();
    int j1;
    Particle *b221 = dfb221.create<Particle>(np);
    for (j=0;j<np;j++) b221[j] = vp[D221][j];
  }
  assert(vp[D222].size() == 0);
}

void c_mesh3d_exchange_particles_27_set_01_11_10(
  const InputDF &dfb100,const InputDF &dfb101,const InputDF &dfb110,const InputDF &dfb111,const InputDF &dfb120,const InputDF &dfb121,const InputDF &dfb200,const InputDF &dfb201,const InputDF &dfb210,const InputDF &dfb211,const InputDF &dfb220,const InputDF &dfb221,
  OutputDF &dfnp,OutputDF &dfp)
{ int np = (dfb100.getSize()+dfb101.getSize()+dfb110.getSize()+dfb111.getSize()+dfb120.getSize()+dfb121.getSize()+dfb200.getSize()+dfb201.getSize()+dfb210.getSize()+dfb211.getSize()+dfb220.getSize()+dfb221.getSize())/sizeof(Particle);
  int j = 0;
  Particle *p =  dfp.create<Particle>(np);
  { const Particle *b100 = dfb100.getData<Particle>();
    assert(dfb100.getSize() % sizeof(Particle) == 0);
    int np1 = dfb100.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b100[j1];
  }
  { const Particle *b101 = dfb101.getData<Particle>();
    assert(dfb101.getSize() % sizeof(Particle) == 0);
    int np1 = dfb101.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b101[j1];
  }
  { const Particle *b110 = dfb110.getData<Particle>();
    assert(dfb110.getSize() % sizeof(Particle) == 0);
    int np1 = dfb110.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b110[j1];
  }
  { const Particle *b111 = dfb111.getData<Particle>();
    assert(dfb111.getSize() % sizeof(Particle) == 0);
    int np1 = dfb111.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b111[j1];
  }
  { const Particle *b120 = dfb120.getData<Particle>();
    assert(dfb120.getSize() % sizeof(Particle) == 0);
    int np1 = dfb120.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b120[j1];
  }
  { const Particle *b121 = dfb121.getData<Particle>();
    assert(dfb121.getSize() % sizeof(Particle) == 0);
    int np1 = dfb121.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b121[j1];
  }
  { const Particle *b200 = dfb200.getData<Particle>();
    assert(dfb200.getSize() % sizeof(Particle) == 0);
    int np1 = dfb200.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b200[j1];
  }
  { const Particle *b201 = dfb201.getData<Particle>();
    assert(dfb201.getSize() % sizeof(Particle) == 0);
    int np1 = dfb201.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b201[j1];
  }
  { const Particle *b210 = dfb210.getData<Particle>();
    assert(dfb210.getSize() % sizeof(Particle) == 0);
    int np1 = dfb210.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b210[j1];
  }
  { const Particle *b211 = dfb211.getData<Particle>();
    assert(dfb211.getSize() % sizeof(Particle) == 0);
    int np1 = dfb211.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b211[j1];
  }
  { const Particle *b220 = dfb220.getData<Particle>();
    assert(dfb220.getSize() % sizeof(Particle) == 0);
    int np1 = dfb220.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b220[j1];
  }
  { const Particle *b221 = dfb221.getData<Particle>();
    assert(dfb221.getSize() % sizeof(Particle) == 0);
    int np1 = dfb221.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b221[j1];
  }
  dfnp.setValue(np);
}

void c_mesh3d_exchange_particles_27_get_01_11_11(int np,const InputDF &df_p,real x1,real y1,real z1,real x2,real y2,real z2,
  OutputDF &dfb100,OutputDF &dfb101,OutputDF &dfb102,OutputDF &dfb110,OutputDF &dfb111,OutputDF &dfb112,OutputDF &dfb120,OutputDF &dfb121,OutputDF &dfb122,OutputDF &dfb200,OutputDF &dfb201,OutputDF &dfb202,OutputDF &dfb210,OutputDF &dfb211,OutputDF &dfb212,OutputDF &dfb220,OutputDF &dfb221,OutputDF &dfb222)
{ int j;
  assert(df_p.getSize() == np*sizeof(Particle));
  const Particle *p = df_p.getData<Particle>();
  std::vector<Particle> vp[27];
  for (j=0;j<np;j++)
  {
    real x = p[j].x;
    real y = p[j].y;
    real z = p[j].z;
    real u = p[j].u;
    real v = p[j].v;
    real w = p[j].w;
    int code = 0;
    if (x<x1) { x = 2*x1-x; u = -u; }
    else if (x>=x2) code += 32;
    if (y<y1) code += 4;
    else if (y>=y2) code += 8;
    if (z<z1) code += 1;
    else if (z>=z2) code += 2;
    int dir = code2dir[code];
    vp[dir].push_back(Particle(x,y,z,u,v,w));
  }
  assert(vp[D000].size() == 0);
  assert(vp[D001].size() == 0);
  assert(vp[D002].size() == 0);
  assert(vp[D010].size() == 0);
  assert(vp[D011].size() == 0);
  assert(vp[D012].size() == 0);
  assert(vp[D020].size() == 0);
  assert(vp[D021].size() == 0);
  assert(vp[D022].size() == 0);
  { int np = vp[D100].size();
    int j1;
    Particle *b100 = dfb100.create<Particle>(np);
    for (j=0;j<np;j++) b100[j] = vp[D100][j];
  }
  { int np = vp[D101].size();
    int j1;
    Particle *b101 = dfb101.create<Particle>(np);
    for (j=0;j<np;j++) b101[j] = vp[D101][j];
  }
  { int np = vp[D102].size();
    int j1;
    Particle *b102 = dfb102.create<Particle>(np);
    for (j=0;j<np;j++) b102[j] = vp[D102][j];
  }
  { int np = vp[D110].size();
    int j1;
    Particle *b110 = dfb110.create<Particle>(np);
    for (j=0;j<np;j++) b110[j] = vp[D110][j];
  }
  { int np = vp[D111].size();
    int j1;
    Particle *b111 = dfb111.create<Particle>(np);
    for (j=0;j<np;j++) b111[j] = vp[D111][j];
  }
  { int np = vp[D112].size();
    int j1;
    Particle *b112 = dfb112.create<Particle>(np);
    for (j=0;j<np;j++) b112[j] = vp[D112][j];
  }
  { int np = vp[D120].size();
    int j1;
    Particle *b120 = dfb120.create<Particle>(np);
    for (j=0;j<np;j++) b120[j] = vp[D120][j];
  }
  { int np = vp[D121].size();
    int j1;
    Particle *b121 = dfb121.create<Particle>(np);
    for (j=0;j<np;j++) b121[j] = vp[D121][j];
  }
  { int np = vp[D122].size();
    int j1;
    Particle *b122 = dfb122.create<Particle>(np);
    for (j=0;j<np;j++) b122[j] = vp[D122][j];
  }
  { int np = vp[D200].size();
    int j1;
    Particle *b200 = dfb200.create<Particle>(np);
    for (j=0;j<np;j++) b200[j] = vp[D200][j];
  }
  { int np = vp[D201].size();
    int j1;
    Particle *b201 = dfb201.create<Particle>(np);
    for (j=0;j<np;j++) b201[j] = vp[D201][j];
  }
  { int np = vp[D202].size();
    int j1;
    Particle *b202 = dfb202.create<Particle>(np);
    for (j=0;j<np;j++) b202[j] = vp[D202][j];
  }
  { int np = vp[D210].size();
    int j1;
    Particle *b210 = dfb210.create<Particle>(np);
    for (j=0;j<np;j++) b210[j] = vp[D210][j];
  }
  { int np = vp[D211].size();
    int j1;
    Particle *b211 = dfb211.create<Particle>(np);
    for (j=0;j<np;j++) b211[j] = vp[D211][j];
  }
  { int np = vp[D212].size();
    int j1;
    Particle *b212 = dfb212.create<Particle>(np);
    for (j=0;j<np;j++) b212[j] = vp[D212][j];
  }
  { int np = vp[D220].size();
    int j1;
    Particle *b220 = dfb220.create<Particle>(np);
    for (j=0;j<np;j++) b220[j] = vp[D220][j];
  }
  { int np = vp[D221].size();
    int j1;
    Particle *b221 = dfb221.create<Particle>(np);
    for (j=0;j<np;j++) b221[j] = vp[D221][j];
  }
  { int np = vp[D222].size();
    int j1;
    Particle *b222 = dfb222.create<Particle>(np);
    for (j=0;j<np;j++) b222[j] = vp[D222][j];
  }
}

void c_mesh3d_exchange_particles_27_set_01_11_11(
  const InputDF &dfb100,const InputDF &dfb101,const InputDF &dfb102,const InputDF &dfb110,const InputDF &dfb111,const InputDF &dfb112,const InputDF &dfb120,const InputDF &dfb121,const InputDF &dfb122,const InputDF &dfb200,const InputDF &dfb201,const InputDF &dfb202,const InputDF &dfb210,const InputDF &dfb211,const InputDF &dfb212,const InputDF &dfb220,const InputDF &dfb221,const InputDF &dfb222,
  OutputDF &dfnp,OutputDF &dfp)
{ int np = (dfb100.getSize()+dfb101.getSize()+dfb102.getSize()+dfb110.getSize()+dfb111.getSize()+dfb112.getSize()+dfb120.getSize()+dfb121.getSize()+dfb122.getSize()+dfb200.getSize()+dfb201.getSize()+dfb202.getSize()+dfb210.getSize()+dfb211.getSize()+dfb212.getSize()+dfb220.getSize()+dfb221.getSize()+dfb222.getSize())/sizeof(Particle);
  int j = 0;
  Particle *p =  dfp.create<Particle>(np);
  { const Particle *b100 = dfb100.getData<Particle>();
    assert(dfb100.getSize() % sizeof(Particle) == 0);
    int np1 = dfb100.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b100[j1];
  }
  { const Particle *b101 = dfb101.getData<Particle>();
    assert(dfb101.getSize() % sizeof(Particle) == 0);
    int np1 = dfb101.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b101[j1];
  }
  { const Particle *b102 = dfb102.getData<Particle>();
    assert(dfb102.getSize() % sizeof(Particle) == 0);
    int np1 = dfb102.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b102[j1];
  }
  { const Particle *b110 = dfb110.getData<Particle>();
    assert(dfb110.getSize() % sizeof(Particle) == 0);
    int np1 = dfb110.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b110[j1];
  }
  { const Particle *b111 = dfb111.getData<Particle>();
    assert(dfb111.getSize() % sizeof(Particle) == 0);
    int np1 = dfb111.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b111[j1];
  }
  { const Particle *b112 = dfb112.getData<Particle>();
    assert(dfb112.getSize() % sizeof(Particle) == 0);
    int np1 = dfb112.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b112[j1];
  }
  { const Particle *b120 = dfb120.getData<Particle>();
    assert(dfb120.getSize() % sizeof(Particle) == 0);
    int np1 = dfb120.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b120[j1];
  }
  { const Particle *b121 = dfb121.getData<Particle>();
    assert(dfb121.getSize() % sizeof(Particle) == 0);
    int np1 = dfb121.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b121[j1];
  }
  { const Particle *b122 = dfb122.getData<Particle>();
    assert(dfb122.getSize() % sizeof(Particle) == 0);
    int np1 = dfb122.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b122[j1];
  }
  { const Particle *b200 = dfb200.getData<Particle>();
    assert(dfb200.getSize() % sizeof(Particle) == 0);
    int np1 = dfb200.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b200[j1];
  }
  { const Particle *b201 = dfb201.getData<Particle>();
    assert(dfb201.getSize() % sizeof(Particle) == 0);
    int np1 = dfb201.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b201[j1];
  }
  { const Particle *b202 = dfb202.getData<Particle>();
    assert(dfb202.getSize() % sizeof(Particle) == 0);
    int np1 = dfb202.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b202[j1];
  }
  { const Particle *b210 = dfb210.getData<Particle>();
    assert(dfb210.getSize() % sizeof(Particle) == 0);
    int np1 = dfb210.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b210[j1];
  }
  { const Particle *b211 = dfb211.getData<Particle>();
    assert(dfb211.getSize() % sizeof(Particle) == 0);
    int np1 = dfb211.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b211[j1];
  }
  { const Particle *b212 = dfb212.getData<Particle>();
    assert(dfb212.getSize() % sizeof(Particle) == 0);
    int np1 = dfb212.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b212[j1];
  }
  { const Particle *b220 = dfb220.getData<Particle>();
    assert(dfb220.getSize() % sizeof(Particle) == 0);
    int np1 = dfb220.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b220[j1];
  }
  { const Particle *b221 = dfb221.getData<Particle>();
    assert(dfb221.getSize() % sizeof(Particle) == 0);
    int np1 = dfb221.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b221[j1];
  }
  { const Particle *b222 = dfb222.getData<Particle>();
    assert(dfb222.getSize() % sizeof(Particle) == 0);
    int np1 = dfb222.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b222[j1];
  }
  dfnp.setValue(np);
}

void c_mesh3d_exchange_particles_27_get_10_00_00(int np,const InputDF &df_p,real x1,real y1,real z1,real x2,real y2,real z2,
  OutputDF &dfb011,OutputDF &dfb111)
{ int j;
  assert(df_p.getSize() == np*sizeof(Particle));
  const Particle *p = df_p.getData<Particle>();
  std::vector<Particle> vp[27];
  for (j=0;j<np;j++)
  {
    real x = p[j].x;
    real y = p[j].y;
    real z = p[j].z;
    real u = p[j].u;
    real v = p[j].v;
    real w = p[j].w;
    int code = 0;
    if (x<x1) code += 16;
    else if (x>=x2) { x = 2*x2-x; u = -u; }
    if (y<y1) { y = 2*y1-y; v = -v; }
    else if (y>=y2) { y = 2*y2-y; v = -v; }
    if (z<z1) { z = 2*z1-z; w = -w; }
    else if (z>=z2) { z = 2*z2-z; w = -w; }
    int dir = code2dir[code];
    vp[dir].push_back(Particle(x,y,z,u,v,w));
  }
  assert(vp[D000].size() == 0);
  assert(vp[D001].size() == 0);
  assert(vp[D002].size() == 0);
  assert(vp[D010].size() == 0);
  { int np = vp[D011].size();
    int j1;
    Particle *b011 = dfb011.create<Particle>(np);
    for (j=0;j<np;j++) b011[j] = vp[D011][j];
  }
  assert(vp[D012].size() == 0);
  assert(vp[D020].size() == 0);
  assert(vp[D021].size() == 0);
  assert(vp[D022].size() == 0);
  assert(vp[D100].size() == 0);
  assert(vp[D101].size() == 0);
  assert(vp[D102].size() == 0);
  assert(vp[D110].size() == 0);
  { int np = vp[D111].size();
    int j1;
    Particle *b111 = dfb111.create<Particle>(np);
    for (j=0;j<np;j++) b111[j] = vp[D111][j];
  }
  assert(vp[D112].size() == 0);
  assert(vp[D120].size() == 0);
  assert(vp[D121].size() == 0);
  assert(vp[D122].size() == 0);
  assert(vp[D200].size() == 0);
  assert(vp[D201].size() == 0);
  assert(vp[D202].size() == 0);
  assert(vp[D210].size() == 0);
  assert(vp[D211].size() == 0);
  assert(vp[D212].size() == 0);
  assert(vp[D220].size() == 0);
  assert(vp[D221].size() == 0);
  assert(vp[D222].size() == 0);
}

void c_mesh3d_exchange_particles_27_set_10_00_00(
  const InputDF &dfb011,const InputDF &dfb111,
  OutputDF &dfnp,OutputDF &dfp)
{ int np = (dfb011.getSize()+dfb111.getSize())/sizeof(Particle);
  int j = 0;
  Particle *p =  dfp.create<Particle>(np);
  { const Particle *b011 = dfb011.getData<Particle>();
    assert(dfb011.getSize() % sizeof(Particle) == 0);
    int np1 = dfb011.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b011[j1];
  }
  { const Particle *b111 = dfb111.getData<Particle>();
    assert(dfb111.getSize() % sizeof(Particle) == 0);
    int np1 = dfb111.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b111[j1];
  }
  dfnp.setValue(np);
}

void c_mesh3d_exchange_particles_27_get_10_00_01(int np,const InputDF &df_p,real x1,real y1,real z1,real x2,real y2,real z2,
  OutputDF &dfb011,OutputDF &dfb012,OutputDF &dfb111,OutputDF &dfb112)
{ int j;
  assert(df_p.getSize() == np*sizeof(Particle));
  const Particle *p = df_p.getData<Particle>();
  std::vector<Particle> vp[27];
  for (j=0;j<np;j++)
  {
    real x = p[j].x;
    real y = p[j].y;
    real z = p[j].z;
    real u = p[j].u;
    real v = p[j].v;
    real w = p[j].w;
    int code = 0;
    if (x<x1) code += 16;
    else if (x>=x2) { x = 2*x2-x; u = -u; }
    if (y<y1) { y = 2*y1-y; v = -v; }
    else if (y>=y2) { y = 2*y2-y; v = -v; }
    if (z<z1) { z = 2*z1-z; w = -w; }
    else if (z>=z2) code += 2;
    int dir = code2dir[code];
    vp[dir].push_back(Particle(x,y,z,u,v,w));
  }
  assert(vp[D000].size() == 0);
  assert(vp[D001].size() == 0);
  assert(vp[D002].size() == 0);
  assert(vp[D010].size() == 0);
  { int np = vp[D011].size();
    int j1;
    Particle *b011 = dfb011.create<Particle>(np);
    for (j=0;j<np;j++) b011[j] = vp[D011][j];
  }
  { int np = vp[D012].size();
    int j1;
    Particle *b012 = dfb012.create<Particle>(np);
    for (j=0;j<np;j++) b012[j] = vp[D012][j];
  }
  assert(vp[D020].size() == 0);
  assert(vp[D021].size() == 0);
  assert(vp[D022].size() == 0);
  assert(vp[D100].size() == 0);
  assert(vp[D101].size() == 0);
  assert(vp[D102].size() == 0);
  assert(vp[D110].size() == 0);
  { int np = vp[D111].size();
    int j1;
    Particle *b111 = dfb111.create<Particle>(np);
    for (j=0;j<np;j++) b111[j] = vp[D111][j];
  }
  { int np = vp[D112].size();
    int j1;
    Particle *b112 = dfb112.create<Particle>(np);
    for (j=0;j<np;j++) b112[j] = vp[D112][j];
  }
  assert(vp[D120].size() == 0);
  assert(vp[D121].size() == 0);
  assert(vp[D122].size() == 0);
  assert(vp[D200].size() == 0);
  assert(vp[D201].size() == 0);
  assert(vp[D202].size() == 0);
  assert(vp[D210].size() == 0);
  assert(vp[D211].size() == 0);
  assert(vp[D212].size() == 0);
  assert(vp[D220].size() == 0);
  assert(vp[D221].size() == 0);
  assert(vp[D222].size() == 0);
}

void c_mesh3d_exchange_particles_27_set_10_00_01(
  const InputDF &dfb011,const InputDF &dfb012,const InputDF &dfb111,const InputDF &dfb112,
  OutputDF &dfnp,OutputDF &dfp)
{ int np = (dfb011.getSize()+dfb012.getSize()+dfb111.getSize()+dfb112.getSize())/sizeof(Particle);
  int j = 0;
  Particle *p =  dfp.create<Particle>(np);
  { const Particle *b011 = dfb011.getData<Particle>();
    assert(dfb011.getSize() % sizeof(Particle) == 0);
    int np1 = dfb011.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b011[j1];
  }
  { const Particle *b012 = dfb012.getData<Particle>();
    assert(dfb012.getSize() % sizeof(Particle) == 0);
    int np1 = dfb012.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b012[j1];
  }
  { const Particle *b111 = dfb111.getData<Particle>();
    assert(dfb111.getSize() % sizeof(Particle) == 0);
    int np1 = dfb111.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b111[j1];
  }
  { const Particle *b112 = dfb112.getData<Particle>();
    assert(dfb112.getSize() % sizeof(Particle) == 0);
    int np1 = dfb112.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b112[j1];
  }
  dfnp.setValue(np);
}

void c_mesh3d_exchange_particles_27_get_10_00_10(int np,const InputDF &df_p,real x1,real y1,real z1,real x2,real y2,real z2,
  OutputDF &dfb010,OutputDF &dfb011,OutputDF &dfb110,OutputDF &dfb111)
{ int j;
  assert(df_p.getSize() == np*sizeof(Particle));
  const Particle *p = df_p.getData<Particle>();
  std::vector<Particle> vp[27];
  for (j=0;j<np;j++)
  {
    real x = p[j].x;
    real y = p[j].y;
    real z = p[j].z;
    real u = p[j].u;
    real v = p[j].v;
    real w = p[j].w;
    int code = 0;
    if (x<x1) code += 16;
    else if (x>=x2) { x = 2*x2-x; u = -u; }
    if (y<y1) { y = 2*y1-y; v = -v; }
    else if (y>=y2) { y = 2*y2-y; v = -v; }
    if (z<z1) code += 1;
    else if (z>=z2) { z = 2*z2-z; w = -w; }
    int dir = code2dir[code];
    vp[dir].push_back(Particle(x,y,z,u,v,w));
  }
  assert(vp[D000].size() == 0);
  assert(vp[D001].size() == 0);
  assert(vp[D002].size() == 0);
  { int np = vp[D010].size();
    int j1;
    Particle *b010 = dfb010.create<Particle>(np);
    for (j=0;j<np;j++) b010[j] = vp[D010][j];
  }
  { int np = vp[D011].size();
    int j1;
    Particle *b011 = dfb011.create<Particle>(np);
    for (j=0;j<np;j++) b011[j] = vp[D011][j];
  }
  assert(vp[D012].size() == 0);
  assert(vp[D020].size() == 0);
  assert(vp[D021].size() == 0);
  assert(vp[D022].size() == 0);
  assert(vp[D100].size() == 0);
  assert(vp[D101].size() == 0);
  assert(vp[D102].size() == 0);
  { int np = vp[D110].size();
    int j1;
    Particle *b110 = dfb110.create<Particle>(np);
    for (j=0;j<np;j++) b110[j] = vp[D110][j];
  }
  { int np = vp[D111].size();
    int j1;
    Particle *b111 = dfb111.create<Particle>(np);
    for (j=0;j<np;j++) b111[j] = vp[D111][j];
  }
  assert(vp[D112].size() == 0);
  assert(vp[D120].size() == 0);
  assert(vp[D121].size() == 0);
  assert(vp[D122].size() == 0);
  assert(vp[D200].size() == 0);
  assert(vp[D201].size() == 0);
  assert(vp[D202].size() == 0);
  assert(vp[D210].size() == 0);
  assert(vp[D211].size() == 0);
  assert(vp[D212].size() == 0);
  assert(vp[D220].size() == 0);
  assert(vp[D221].size() == 0);
  assert(vp[D222].size() == 0);
}

void c_mesh3d_exchange_particles_27_set_10_00_10(
  const InputDF &dfb010,const InputDF &dfb011,const InputDF &dfb110,const InputDF &dfb111,
  OutputDF &dfnp,OutputDF &dfp)
{ int np = (dfb010.getSize()+dfb011.getSize()+dfb110.getSize()+dfb111.getSize())/sizeof(Particle);
  int j = 0;
  Particle *p =  dfp.create<Particle>(np);
  { const Particle *b010 = dfb010.getData<Particle>();
    assert(dfb010.getSize() % sizeof(Particle) == 0);
    int np1 = dfb010.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b010[j1];
  }
  { const Particle *b011 = dfb011.getData<Particle>();
    assert(dfb011.getSize() % sizeof(Particle) == 0);
    int np1 = dfb011.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b011[j1];
  }
  { const Particle *b110 = dfb110.getData<Particle>();
    assert(dfb110.getSize() % sizeof(Particle) == 0);
    int np1 = dfb110.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b110[j1];
  }
  { const Particle *b111 = dfb111.getData<Particle>();
    assert(dfb111.getSize() % sizeof(Particle) == 0);
    int np1 = dfb111.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b111[j1];
  }
  dfnp.setValue(np);
}

void c_mesh3d_exchange_particles_27_get_10_00_11(int np,const InputDF &df_p,real x1,real y1,real z1,real x2,real y2,real z2,
  OutputDF &dfb010,OutputDF &dfb011,OutputDF &dfb012,OutputDF &dfb110,OutputDF &dfb111,OutputDF &dfb112)
{ int j;
  assert(df_p.getSize() == np*sizeof(Particle));
  const Particle *p = df_p.getData<Particle>();
  std::vector<Particle> vp[27];
  for (j=0;j<np;j++)
  {
    real x = p[j].x;
    real y = p[j].y;
    real z = p[j].z;
    real u = p[j].u;
    real v = p[j].v;
    real w = p[j].w;
    int code = 0;
    if (x<x1) code += 16;
    else if (x>=x2) { x = 2*x2-x; u = -u; }
    if (y<y1) { y = 2*y1-y; v = -v; }
    else if (y>=y2) { y = 2*y2-y; v = -v; }
    if (z<z1) code += 1;
    else if (z>=z2) code += 2;
    int dir = code2dir[code];
    vp[dir].push_back(Particle(x,y,z,u,v,w));
  }
  assert(vp[D000].size() == 0);
  assert(vp[D001].size() == 0);
  assert(vp[D002].size() == 0);
  { int np = vp[D010].size();
    int j1;
    Particle *b010 = dfb010.create<Particle>(np);
    for (j=0;j<np;j++) b010[j] = vp[D010][j];
  }
  { int np = vp[D011].size();
    int j1;
    Particle *b011 = dfb011.create<Particle>(np);
    for (j=0;j<np;j++) b011[j] = vp[D011][j];
  }
  { int np = vp[D012].size();
    int j1;
    Particle *b012 = dfb012.create<Particle>(np);
    for (j=0;j<np;j++) b012[j] = vp[D012][j];
  }
  assert(vp[D020].size() == 0);
  assert(vp[D021].size() == 0);
  assert(vp[D022].size() == 0);
  assert(vp[D100].size() == 0);
  assert(vp[D101].size() == 0);
  assert(vp[D102].size() == 0);
  { int np = vp[D110].size();
    int j1;
    Particle *b110 = dfb110.create<Particle>(np);
    for (j=0;j<np;j++) b110[j] = vp[D110][j];
  }
  { int np = vp[D111].size();
    int j1;
    Particle *b111 = dfb111.create<Particle>(np);
    for (j=0;j<np;j++) b111[j] = vp[D111][j];
  }
  { int np = vp[D112].size();
    int j1;
    Particle *b112 = dfb112.create<Particle>(np);
    for (j=0;j<np;j++) b112[j] = vp[D112][j];
  }
  assert(vp[D120].size() == 0);
  assert(vp[D121].size() == 0);
  assert(vp[D122].size() == 0);
  assert(vp[D200].size() == 0);
  assert(vp[D201].size() == 0);
  assert(vp[D202].size() == 0);
  assert(vp[D210].size() == 0);
  assert(vp[D211].size() == 0);
  assert(vp[D212].size() == 0);
  assert(vp[D220].size() == 0);
  assert(vp[D221].size() == 0);
  assert(vp[D222].size() == 0);
}

void c_mesh3d_exchange_particles_27_set_10_00_11(
  const InputDF &dfb010,const InputDF &dfb011,const InputDF &dfb012,const InputDF &dfb110,const InputDF &dfb111,const InputDF &dfb112,
  OutputDF &dfnp,OutputDF &dfp)
{ int np = (dfb010.getSize()+dfb011.getSize()+dfb012.getSize()+dfb110.getSize()+dfb111.getSize()+dfb112.getSize())/sizeof(Particle);
  int j = 0;
  Particle *p =  dfp.create<Particle>(np);
  { const Particle *b010 = dfb010.getData<Particle>();
    assert(dfb010.getSize() % sizeof(Particle) == 0);
    int np1 = dfb010.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b010[j1];
  }
  { const Particle *b011 = dfb011.getData<Particle>();
    assert(dfb011.getSize() % sizeof(Particle) == 0);
    int np1 = dfb011.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b011[j1];
  }
  { const Particle *b012 = dfb012.getData<Particle>();
    assert(dfb012.getSize() % sizeof(Particle) == 0);
    int np1 = dfb012.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b012[j1];
  }
  { const Particle *b110 = dfb110.getData<Particle>();
    assert(dfb110.getSize() % sizeof(Particle) == 0);
    int np1 = dfb110.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b110[j1];
  }
  { const Particle *b111 = dfb111.getData<Particle>();
    assert(dfb111.getSize() % sizeof(Particle) == 0);
    int np1 = dfb111.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b111[j1];
  }
  { const Particle *b112 = dfb112.getData<Particle>();
    assert(dfb112.getSize() % sizeof(Particle) == 0);
    int np1 = dfb112.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b112[j1];
  }
  dfnp.setValue(np);
}

void c_mesh3d_exchange_particles_27_get_10_01_00(int np,const InputDF &df_p,real x1,real y1,real z1,real x2,real y2,real z2,
  OutputDF &dfb011,OutputDF &dfb021,OutputDF &dfb111,OutputDF &dfb121)
{ int j;
  assert(df_p.getSize() == np*sizeof(Particle));
  const Particle *p = df_p.getData<Particle>();
  std::vector<Particle> vp[27];
  for (j=0;j<np;j++)
  {
    real x = p[j].x;
    real y = p[j].y;
    real z = p[j].z;
    real u = p[j].u;
    real v = p[j].v;
    real w = p[j].w;
    int code = 0;
    if (x<x1) code += 16;
    else if (x>=x2) { x = 2*x2-x; u = -u; }
    if (y<y1) { y = 2*y1-y; v = -v; }
    else if (y>=y2) code += 8;
    if (z<z1) { z = 2*z1-z; w = -w; }
    else if (z>=z2) { z = 2*z2-z; w = -w; }
    int dir = code2dir[code];
    vp[dir].push_back(Particle(x,y,z,u,v,w));
  }
  assert(vp[D000].size() == 0);
  assert(vp[D001].size() == 0);
  assert(vp[D002].size() == 0);
  assert(vp[D010].size() == 0);
  { int np = vp[D011].size();
    int j1;
    Particle *b011 = dfb011.create<Particle>(np);
    for (j=0;j<np;j++) b011[j] = vp[D011][j];
  }
  assert(vp[D012].size() == 0);
  assert(vp[D020].size() == 0);
  { int np = vp[D021].size();
    int j1;
    Particle *b021 = dfb021.create<Particle>(np);
    for (j=0;j<np;j++) b021[j] = vp[D021][j];
  }
  assert(vp[D022].size() == 0);
  assert(vp[D100].size() == 0);
  assert(vp[D101].size() == 0);
  assert(vp[D102].size() == 0);
  assert(vp[D110].size() == 0);
  { int np = vp[D111].size();
    int j1;
    Particle *b111 = dfb111.create<Particle>(np);
    for (j=0;j<np;j++) b111[j] = vp[D111][j];
  }
  assert(vp[D112].size() == 0);
  assert(vp[D120].size() == 0);
  { int np = vp[D121].size();
    int j1;
    Particle *b121 = dfb121.create<Particle>(np);
    for (j=0;j<np;j++) b121[j] = vp[D121][j];
  }
  assert(vp[D122].size() == 0);
  assert(vp[D200].size() == 0);
  assert(vp[D201].size() == 0);
  assert(vp[D202].size() == 0);
  assert(vp[D210].size() == 0);
  assert(vp[D211].size() == 0);
  assert(vp[D212].size() == 0);
  assert(vp[D220].size() == 0);
  assert(vp[D221].size() == 0);
  assert(vp[D222].size() == 0);
}

void c_mesh3d_exchange_particles_27_set_10_01_00(
  const InputDF &dfb011,const InputDF &dfb021,const InputDF &dfb111,const InputDF &dfb121,
  OutputDF &dfnp,OutputDF &dfp)
{ int np = (dfb011.getSize()+dfb021.getSize()+dfb111.getSize()+dfb121.getSize())/sizeof(Particle);
  int j = 0;
  Particle *p =  dfp.create<Particle>(np);
  { const Particle *b011 = dfb011.getData<Particle>();
    assert(dfb011.getSize() % sizeof(Particle) == 0);
    int np1 = dfb011.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b011[j1];
  }
  { const Particle *b021 = dfb021.getData<Particle>();
    assert(dfb021.getSize() % sizeof(Particle) == 0);
    int np1 = dfb021.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b021[j1];
  }
  { const Particle *b111 = dfb111.getData<Particle>();
    assert(dfb111.getSize() % sizeof(Particle) == 0);
    int np1 = dfb111.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b111[j1];
  }
  { const Particle *b121 = dfb121.getData<Particle>();
    assert(dfb121.getSize() % sizeof(Particle) == 0);
    int np1 = dfb121.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b121[j1];
  }
  dfnp.setValue(np);
}

void c_mesh3d_exchange_particles_27_get_10_01_01(int np,const InputDF &df_p,real x1,real y1,real z1,real x2,real y2,real z2,
  OutputDF &dfb011,OutputDF &dfb012,OutputDF &dfb021,OutputDF &dfb022,OutputDF &dfb111,OutputDF &dfb112,OutputDF &dfb121,OutputDF &dfb122)
{ int j;
  assert(df_p.getSize() == np*sizeof(Particle));
  const Particle *p = df_p.getData<Particle>();
  std::vector<Particle> vp[27];
  for (j=0;j<np;j++)
  {
    real x = p[j].x;
    real y = p[j].y;
    real z = p[j].z;
    real u = p[j].u;
    real v = p[j].v;
    real w = p[j].w;
    int code = 0;
    if (x<x1) code += 16;
    else if (x>=x2) { x = 2*x2-x; u = -u; }
    if (y<y1) { y = 2*y1-y; v = -v; }
    else if (y>=y2) code += 8;
    if (z<z1) { z = 2*z1-z; w = -w; }
    else if (z>=z2) code += 2;
    int dir = code2dir[code];
    vp[dir].push_back(Particle(x,y,z,u,v,w));
  }
  assert(vp[D000].size() == 0);
  assert(vp[D001].size() == 0);
  assert(vp[D002].size() == 0);
  assert(vp[D010].size() == 0);
  { int np = vp[D011].size();
    int j1;
    Particle *b011 = dfb011.create<Particle>(np);
    for (j=0;j<np;j++) b011[j] = vp[D011][j];
  }
  { int np = vp[D012].size();
    int j1;
    Particle *b012 = dfb012.create<Particle>(np);
    for (j=0;j<np;j++) b012[j] = vp[D012][j];
  }
  assert(vp[D020].size() == 0);
  { int np = vp[D021].size();
    int j1;
    Particle *b021 = dfb021.create<Particle>(np);
    for (j=0;j<np;j++) b021[j] = vp[D021][j];
  }
  { int np = vp[D022].size();
    int j1;
    Particle *b022 = dfb022.create<Particle>(np);
    for (j=0;j<np;j++) b022[j] = vp[D022][j];
  }
  assert(vp[D100].size() == 0);
  assert(vp[D101].size() == 0);
  assert(vp[D102].size() == 0);
  assert(vp[D110].size() == 0);
  { int np = vp[D111].size();
    int j1;
    Particle *b111 = dfb111.create<Particle>(np);
    for (j=0;j<np;j++) b111[j] = vp[D111][j];
  }
  { int np = vp[D112].size();
    int j1;
    Particle *b112 = dfb112.create<Particle>(np);
    for (j=0;j<np;j++) b112[j] = vp[D112][j];
  }
  assert(vp[D120].size() == 0);
  { int np = vp[D121].size();
    int j1;
    Particle *b121 = dfb121.create<Particle>(np);
    for (j=0;j<np;j++) b121[j] = vp[D121][j];
  }
  { int np = vp[D122].size();
    int j1;
    Particle *b122 = dfb122.create<Particle>(np);
    for (j=0;j<np;j++) b122[j] = vp[D122][j];
  }
  assert(vp[D200].size() == 0);
  assert(vp[D201].size() == 0);
  assert(vp[D202].size() == 0);
  assert(vp[D210].size() == 0);
  assert(vp[D211].size() == 0);
  assert(vp[D212].size() == 0);
  assert(vp[D220].size() == 0);
  assert(vp[D221].size() == 0);
  assert(vp[D222].size() == 0);
}

void c_mesh3d_exchange_particles_27_set_10_01_01(
  const InputDF &dfb011,const InputDF &dfb012,const InputDF &dfb021,const InputDF &dfb022,const InputDF &dfb111,const InputDF &dfb112,const InputDF &dfb121,const InputDF &dfb122,
  OutputDF &dfnp,OutputDF &dfp)
{ int np = (dfb011.getSize()+dfb012.getSize()+dfb021.getSize()+dfb022.getSize()+dfb111.getSize()+dfb112.getSize()+dfb121.getSize()+dfb122.getSize())/sizeof(Particle);
  int j = 0;
  Particle *p =  dfp.create<Particle>(np);
  { const Particle *b011 = dfb011.getData<Particle>();
    assert(dfb011.getSize() % sizeof(Particle) == 0);
    int np1 = dfb011.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b011[j1];
  }
  { const Particle *b012 = dfb012.getData<Particle>();
    assert(dfb012.getSize() % sizeof(Particle) == 0);
    int np1 = dfb012.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b012[j1];
  }
  { const Particle *b021 = dfb021.getData<Particle>();
    assert(dfb021.getSize() % sizeof(Particle) == 0);
    int np1 = dfb021.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b021[j1];
  }
  { const Particle *b022 = dfb022.getData<Particle>();
    assert(dfb022.getSize() % sizeof(Particle) == 0);
    int np1 = dfb022.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b022[j1];
  }
  { const Particle *b111 = dfb111.getData<Particle>();
    assert(dfb111.getSize() % sizeof(Particle) == 0);
    int np1 = dfb111.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b111[j1];
  }
  { const Particle *b112 = dfb112.getData<Particle>();
    assert(dfb112.getSize() % sizeof(Particle) == 0);
    int np1 = dfb112.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b112[j1];
  }
  { const Particle *b121 = dfb121.getData<Particle>();
    assert(dfb121.getSize() % sizeof(Particle) == 0);
    int np1 = dfb121.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b121[j1];
  }
  { const Particle *b122 = dfb122.getData<Particle>();
    assert(dfb122.getSize() % sizeof(Particle) == 0);
    int np1 = dfb122.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b122[j1];
  }
  dfnp.setValue(np);
}

void c_mesh3d_exchange_particles_27_get_10_01_10(int np,const InputDF &df_p,real x1,real y1,real z1,real x2,real y2,real z2,
  OutputDF &dfb010,OutputDF &dfb011,OutputDF &dfb020,OutputDF &dfb021,OutputDF &dfb110,OutputDF &dfb111,OutputDF &dfb120,OutputDF &dfb121)
{ int j;
  assert(df_p.getSize() == np*sizeof(Particle));
  const Particle *p = df_p.getData<Particle>();
  std::vector<Particle> vp[27];
  for (j=0;j<np;j++)
  {
    real x = p[j].x;
    real y = p[j].y;
    real z = p[j].z;
    real u = p[j].u;
    real v = p[j].v;
    real w = p[j].w;
    int code = 0;
    if (x<x1) code += 16;
    else if (x>=x2) { x = 2*x2-x; u = -u; }
    if (y<y1) { y = 2*y1-y; v = -v; }
    else if (y>=y2) code += 8;
    if (z<z1) code += 1;
    else if (z>=z2) { z = 2*z2-z; w = -w; }
    int dir = code2dir[code];
    vp[dir].push_back(Particle(x,y,z,u,v,w));
  }
  assert(vp[D000].size() == 0);
  assert(vp[D001].size() == 0);
  assert(vp[D002].size() == 0);
  { int np = vp[D010].size();
    int j1;
    Particle *b010 = dfb010.create<Particle>(np);
    for (j=0;j<np;j++) b010[j] = vp[D010][j];
  }
  { int np = vp[D011].size();
    int j1;
    Particle *b011 = dfb011.create<Particle>(np);
    for (j=0;j<np;j++) b011[j] = vp[D011][j];
  }
  assert(vp[D012].size() == 0);
  { int np = vp[D020].size();
    int j1;
    Particle *b020 = dfb020.create<Particle>(np);
    for (j=0;j<np;j++) b020[j] = vp[D020][j];
  }
  { int np = vp[D021].size();
    int j1;
    Particle *b021 = dfb021.create<Particle>(np);
    for (j=0;j<np;j++) b021[j] = vp[D021][j];
  }
  assert(vp[D022].size() == 0);
  assert(vp[D100].size() == 0);
  assert(vp[D101].size() == 0);
  assert(vp[D102].size() == 0);
  { int np = vp[D110].size();
    int j1;
    Particle *b110 = dfb110.create<Particle>(np);
    for (j=0;j<np;j++) b110[j] = vp[D110][j];
  }
  { int np = vp[D111].size();
    int j1;
    Particle *b111 = dfb111.create<Particle>(np);
    for (j=0;j<np;j++) b111[j] = vp[D111][j];
  }
  assert(vp[D112].size() == 0);
  { int np = vp[D120].size();
    int j1;
    Particle *b120 = dfb120.create<Particle>(np);
    for (j=0;j<np;j++) b120[j] = vp[D120][j];
  }
  { int np = vp[D121].size();
    int j1;
    Particle *b121 = dfb121.create<Particle>(np);
    for (j=0;j<np;j++) b121[j] = vp[D121][j];
  }
  assert(vp[D122].size() == 0);
  assert(vp[D200].size() == 0);
  assert(vp[D201].size() == 0);
  assert(vp[D202].size() == 0);
  assert(vp[D210].size() == 0);
  assert(vp[D211].size() == 0);
  assert(vp[D212].size() == 0);
  assert(vp[D220].size() == 0);
  assert(vp[D221].size() == 0);
  assert(vp[D222].size() == 0);
}

void c_mesh3d_exchange_particles_27_set_10_01_10(
  const InputDF &dfb010,const InputDF &dfb011,const InputDF &dfb020,const InputDF &dfb021,const InputDF &dfb110,const InputDF &dfb111,const InputDF &dfb120,const InputDF &dfb121,
  OutputDF &dfnp,OutputDF &dfp)
{ int np = (dfb010.getSize()+dfb011.getSize()+dfb020.getSize()+dfb021.getSize()+dfb110.getSize()+dfb111.getSize()+dfb120.getSize()+dfb121.getSize())/sizeof(Particle);
  int j = 0;
  Particle *p =  dfp.create<Particle>(np);
  { const Particle *b010 = dfb010.getData<Particle>();
    assert(dfb010.getSize() % sizeof(Particle) == 0);
    int np1 = dfb010.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b010[j1];
  }
  { const Particle *b011 = dfb011.getData<Particle>();
    assert(dfb011.getSize() % sizeof(Particle) == 0);
    int np1 = dfb011.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b011[j1];
  }
  { const Particle *b020 = dfb020.getData<Particle>();
    assert(dfb020.getSize() % sizeof(Particle) == 0);
    int np1 = dfb020.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b020[j1];
  }
  { const Particle *b021 = dfb021.getData<Particle>();
    assert(dfb021.getSize() % sizeof(Particle) == 0);
    int np1 = dfb021.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b021[j1];
  }
  { const Particle *b110 = dfb110.getData<Particle>();
    assert(dfb110.getSize() % sizeof(Particle) == 0);
    int np1 = dfb110.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b110[j1];
  }
  { const Particle *b111 = dfb111.getData<Particle>();
    assert(dfb111.getSize() % sizeof(Particle) == 0);
    int np1 = dfb111.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b111[j1];
  }
  { const Particle *b120 = dfb120.getData<Particle>();
    assert(dfb120.getSize() % sizeof(Particle) == 0);
    int np1 = dfb120.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b120[j1];
  }
  { const Particle *b121 = dfb121.getData<Particle>();
    assert(dfb121.getSize() % sizeof(Particle) == 0);
    int np1 = dfb121.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b121[j1];
  }
  dfnp.setValue(np);
}

void c_mesh3d_exchange_particles_27_get_10_01_11(int np,const InputDF &df_p,real x1,real y1,real z1,real x2,real y2,real z2,
  OutputDF &dfb010,OutputDF &dfb011,OutputDF &dfb012,OutputDF &dfb020,OutputDF &dfb021,OutputDF &dfb022,OutputDF &dfb110,OutputDF &dfb111,OutputDF &dfb112,OutputDF &dfb120,OutputDF &dfb121,OutputDF &dfb122)
{ int j;
  assert(df_p.getSize() == np*sizeof(Particle));
  const Particle *p = df_p.getData<Particle>();
  std::vector<Particle> vp[27];
  for (j=0;j<np;j++)
  {
    real x = p[j].x;
    real y = p[j].y;
    real z = p[j].z;
    real u = p[j].u;
    real v = p[j].v;
    real w = p[j].w;
    int code = 0;
    if (x<x1) code += 16;
    else if (x>=x2) { x = 2*x2-x; u = -u; }
    if (y<y1) { y = 2*y1-y; v = -v; }
    else if (y>=y2) code += 8;
    if (z<z1) code += 1;
    else if (z>=z2) code += 2;
    int dir = code2dir[code];
    vp[dir].push_back(Particle(x,y,z,u,v,w));
  }
  assert(vp[D000].size() == 0);
  assert(vp[D001].size() == 0);
  assert(vp[D002].size() == 0);
  { int np = vp[D010].size();
    int j1;
    Particle *b010 = dfb010.create<Particle>(np);
    for (j=0;j<np;j++) b010[j] = vp[D010][j];
  }
  { int np = vp[D011].size();
    int j1;
    Particle *b011 = dfb011.create<Particle>(np);
    for (j=0;j<np;j++) b011[j] = vp[D011][j];
  }
  { int np = vp[D012].size();
    int j1;
    Particle *b012 = dfb012.create<Particle>(np);
    for (j=0;j<np;j++) b012[j] = vp[D012][j];
  }
  { int np = vp[D020].size();
    int j1;
    Particle *b020 = dfb020.create<Particle>(np);
    for (j=0;j<np;j++) b020[j] = vp[D020][j];
  }
  { int np = vp[D021].size();
    int j1;
    Particle *b021 = dfb021.create<Particle>(np);
    for (j=0;j<np;j++) b021[j] = vp[D021][j];
  }
  { int np = vp[D022].size();
    int j1;
    Particle *b022 = dfb022.create<Particle>(np);
    for (j=0;j<np;j++) b022[j] = vp[D022][j];
  }
  assert(vp[D100].size() == 0);
  assert(vp[D101].size() == 0);
  assert(vp[D102].size() == 0);
  { int np = vp[D110].size();
    int j1;
    Particle *b110 = dfb110.create<Particle>(np);
    for (j=0;j<np;j++) b110[j] = vp[D110][j];
  }
  { int np = vp[D111].size();
    int j1;
    Particle *b111 = dfb111.create<Particle>(np);
    for (j=0;j<np;j++) b111[j] = vp[D111][j];
  }
  { int np = vp[D112].size();
    int j1;
    Particle *b112 = dfb112.create<Particle>(np);
    for (j=0;j<np;j++) b112[j] = vp[D112][j];
  }
  { int np = vp[D120].size();
    int j1;
    Particle *b120 = dfb120.create<Particle>(np);
    for (j=0;j<np;j++) b120[j] = vp[D120][j];
  }
  { int np = vp[D121].size();
    int j1;
    Particle *b121 = dfb121.create<Particle>(np);
    for (j=0;j<np;j++) b121[j] = vp[D121][j];
  }
  { int np = vp[D122].size();
    int j1;
    Particle *b122 = dfb122.create<Particle>(np);
    for (j=0;j<np;j++) b122[j] = vp[D122][j];
  }
  assert(vp[D200].size() == 0);
  assert(vp[D201].size() == 0);
  assert(vp[D202].size() == 0);
  assert(vp[D210].size() == 0);
  assert(vp[D211].size() == 0);
  assert(vp[D212].size() == 0);
  assert(vp[D220].size() == 0);
  assert(vp[D221].size() == 0);
  assert(vp[D222].size() == 0);
}

void c_mesh3d_exchange_particles_27_set_10_01_11(
  const InputDF &dfb010,const InputDF &dfb011,const InputDF &dfb012,const InputDF &dfb020,const InputDF &dfb021,const InputDF &dfb022,const InputDF &dfb110,const InputDF &dfb111,const InputDF &dfb112,const InputDF &dfb120,const InputDF &dfb121,const InputDF &dfb122,
  OutputDF &dfnp,OutputDF &dfp)
{ int np = (dfb010.getSize()+dfb011.getSize()+dfb012.getSize()+dfb020.getSize()+dfb021.getSize()+dfb022.getSize()+dfb110.getSize()+dfb111.getSize()+dfb112.getSize()+dfb120.getSize()+dfb121.getSize()+dfb122.getSize())/sizeof(Particle);
  int j = 0;
  Particle *p =  dfp.create<Particle>(np);
  { const Particle *b010 = dfb010.getData<Particle>();
    assert(dfb010.getSize() % sizeof(Particle) == 0);
    int np1 = dfb010.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b010[j1];
  }
  { const Particle *b011 = dfb011.getData<Particle>();
    assert(dfb011.getSize() % sizeof(Particle) == 0);
    int np1 = dfb011.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b011[j1];
  }
  { const Particle *b012 = dfb012.getData<Particle>();
    assert(dfb012.getSize() % sizeof(Particle) == 0);
    int np1 = dfb012.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b012[j1];
  }
  { const Particle *b020 = dfb020.getData<Particle>();
    assert(dfb020.getSize() % sizeof(Particle) == 0);
    int np1 = dfb020.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b020[j1];
  }
  { const Particle *b021 = dfb021.getData<Particle>();
    assert(dfb021.getSize() % sizeof(Particle) == 0);
    int np1 = dfb021.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b021[j1];
  }
  { const Particle *b022 = dfb022.getData<Particle>();
    assert(dfb022.getSize() % sizeof(Particle) == 0);
    int np1 = dfb022.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b022[j1];
  }
  { const Particle *b110 = dfb110.getData<Particle>();
    assert(dfb110.getSize() % sizeof(Particle) == 0);
    int np1 = dfb110.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b110[j1];
  }
  { const Particle *b111 = dfb111.getData<Particle>();
    assert(dfb111.getSize() % sizeof(Particle) == 0);
    int np1 = dfb111.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b111[j1];
  }
  { const Particle *b112 = dfb112.getData<Particle>();
    assert(dfb112.getSize() % sizeof(Particle) == 0);
    int np1 = dfb112.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b112[j1];
  }
  { const Particle *b120 = dfb120.getData<Particle>();
    assert(dfb120.getSize() % sizeof(Particle) == 0);
    int np1 = dfb120.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b120[j1];
  }
  { const Particle *b121 = dfb121.getData<Particle>();
    assert(dfb121.getSize() % sizeof(Particle) == 0);
    int np1 = dfb121.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b121[j1];
  }
  { const Particle *b122 = dfb122.getData<Particle>();
    assert(dfb122.getSize() % sizeof(Particle) == 0);
    int np1 = dfb122.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b122[j1];
  }
  dfnp.setValue(np);
}

void c_mesh3d_exchange_particles_27_get_10_10_00(int np,const InputDF &df_p,real x1,real y1,real z1,real x2,real y2,real z2,
  OutputDF &dfb001,OutputDF &dfb011,OutputDF &dfb101,OutputDF &dfb111)
{ int j;
  assert(df_p.getSize() == np*sizeof(Particle));
  const Particle *p = df_p.getData<Particle>();
  std::vector<Particle> vp[27];
  for (j=0;j<np;j++)
  {
    real x = p[j].x;
    real y = p[j].y;
    real z = p[j].z;
    real u = p[j].u;
    real v = p[j].v;
    real w = p[j].w;
    int code = 0;
    if (x<x1) code += 16;
    else if (x>=x2) { x = 2*x2-x; u = -u; }
    if (y<y1) code += 4;
    else if (y>=y2) { y = 2*y2-y; v = -v; }
    if (z<z1) { z = 2*z1-z; w = -w; }
    else if (z>=z2) { z = 2*z2-z; w = -w; }
    int dir = code2dir[code];
    vp[dir].push_back(Particle(x,y,z,u,v,w));
  }
  assert(vp[D000].size() == 0);
  { int np = vp[D001].size();
    int j1;
    Particle *b001 = dfb001.create<Particle>(np);
    for (j=0;j<np;j++) b001[j] = vp[D001][j];
  }
  assert(vp[D002].size() == 0);
  assert(vp[D010].size() == 0);
  { int np = vp[D011].size();
    int j1;
    Particle *b011 = dfb011.create<Particle>(np);
    for (j=0;j<np;j++) b011[j] = vp[D011][j];
  }
  assert(vp[D012].size() == 0);
  assert(vp[D020].size() == 0);
  assert(vp[D021].size() == 0);
  assert(vp[D022].size() == 0);
  assert(vp[D100].size() == 0);
  { int np = vp[D101].size();
    int j1;
    Particle *b101 = dfb101.create<Particle>(np);
    for (j=0;j<np;j++) b101[j] = vp[D101][j];
  }
  assert(vp[D102].size() == 0);
  assert(vp[D110].size() == 0);
  { int np = vp[D111].size();
    int j1;
    Particle *b111 = dfb111.create<Particle>(np);
    for (j=0;j<np;j++) b111[j] = vp[D111][j];
  }
  assert(vp[D112].size() == 0);
  assert(vp[D120].size() == 0);
  assert(vp[D121].size() == 0);
  assert(vp[D122].size() == 0);
  assert(vp[D200].size() == 0);
  assert(vp[D201].size() == 0);
  assert(vp[D202].size() == 0);
  assert(vp[D210].size() == 0);
  assert(vp[D211].size() == 0);
  assert(vp[D212].size() == 0);
  assert(vp[D220].size() == 0);
  assert(vp[D221].size() == 0);
  assert(vp[D222].size() == 0);
}

void c_mesh3d_exchange_particles_27_set_10_10_00(
  const InputDF &dfb001,const InputDF &dfb011,const InputDF &dfb101,const InputDF &dfb111,
  OutputDF &dfnp,OutputDF &dfp)
{ int np = (dfb001.getSize()+dfb011.getSize()+dfb101.getSize()+dfb111.getSize())/sizeof(Particle);
  int j = 0;
  Particle *p =  dfp.create<Particle>(np);
  { const Particle *b001 = dfb001.getData<Particle>();
    assert(dfb001.getSize() % sizeof(Particle) == 0);
    int np1 = dfb001.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b001[j1];
  }
  { const Particle *b011 = dfb011.getData<Particle>();
    assert(dfb011.getSize() % sizeof(Particle) == 0);
    int np1 = dfb011.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b011[j1];
  }
  { const Particle *b101 = dfb101.getData<Particle>();
    assert(dfb101.getSize() % sizeof(Particle) == 0);
    int np1 = dfb101.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b101[j1];
  }
  { const Particle *b111 = dfb111.getData<Particle>();
    assert(dfb111.getSize() % sizeof(Particle) == 0);
    int np1 = dfb111.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b111[j1];
  }
  dfnp.setValue(np);
}

void c_mesh3d_exchange_particles_27_get_10_10_01(int np,const InputDF &df_p,real x1,real y1,real z1,real x2,real y2,real z2,
  OutputDF &dfb001,OutputDF &dfb002,OutputDF &dfb011,OutputDF &dfb012,OutputDF &dfb101,OutputDF &dfb102,OutputDF &dfb111,OutputDF &dfb112)
{ int j;
  assert(df_p.getSize() == np*sizeof(Particle));
  const Particle *p = df_p.getData<Particle>();
  std::vector<Particle> vp[27];
  for (j=0;j<np;j++)
  {
    real x = p[j].x;
    real y = p[j].y;
    real z = p[j].z;
    real u = p[j].u;
    real v = p[j].v;
    real w = p[j].w;
    int code = 0;
    if (x<x1) code += 16;
    else if (x>=x2) { x = 2*x2-x; u = -u; }
    if (y<y1) code += 4;
    else if (y>=y2) { y = 2*y2-y; v = -v; }
    if (z<z1) { z = 2*z1-z; w = -w; }
    else if (z>=z2) code += 2;
    int dir = code2dir[code];
    vp[dir].push_back(Particle(x,y,z,u,v,w));
  }
  assert(vp[D000].size() == 0);
  { int np = vp[D001].size();
    int j1;
    Particle *b001 = dfb001.create<Particle>(np);
    for (j=0;j<np;j++) b001[j] = vp[D001][j];
  }
  { int np = vp[D002].size();
    int j1;
    Particle *b002 = dfb002.create<Particle>(np);
    for (j=0;j<np;j++) b002[j] = vp[D002][j];
  }
  assert(vp[D010].size() == 0);
  { int np = vp[D011].size();
    int j1;
    Particle *b011 = dfb011.create<Particle>(np);
    for (j=0;j<np;j++) b011[j] = vp[D011][j];
  }
  { int np = vp[D012].size();
    int j1;
    Particle *b012 = dfb012.create<Particle>(np);
    for (j=0;j<np;j++) b012[j] = vp[D012][j];
  }
  assert(vp[D020].size() == 0);
  assert(vp[D021].size() == 0);
  assert(vp[D022].size() == 0);
  assert(vp[D100].size() == 0);
  { int np = vp[D101].size();
    int j1;
    Particle *b101 = dfb101.create<Particle>(np);
    for (j=0;j<np;j++) b101[j] = vp[D101][j];
  }
  { int np = vp[D102].size();
    int j1;
    Particle *b102 = dfb102.create<Particle>(np);
    for (j=0;j<np;j++) b102[j] = vp[D102][j];
  }
  assert(vp[D110].size() == 0);
  { int np = vp[D111].size();
    int j1;
    Particle *b111 = dfb111.create<Particle>(np);
    for (j=0;j<np;j++) b111[j] = vp[D111][j];
  }
  { int np = vp[D112].size();
    int j1;
    Particle *b112 = dfb112.create<Particle>(np);
    for (j=0;j<np;j++) b112[j] = vp[D112][j];
  }
  assert(vp[D120].size() == 0);
  assert(vp[D121].size() == 0);
  assert(vp[D122].size() == 0);
  assert(vp[D200].size() == 0);
  assert(vp[D201].size() == 0);
  assert(vp[D202].size() == 0);
  assert(vp[D210].size() == 0);
  assert(vp[D211].size() == 0);
  assert(vp[D212].size() == 0);
  assert(vp[D220].size() == 0);
  assert(vp[D221].size() == 0);
  assert(vp[D222].size() == 0);
}

void c_mesh3d_exchange_particles_27_set_10_10_01(
  const InputDF &dfb001,const InputDF &dfb002,const InputDF &dfb011,const InputDF &dfb012,const InputDF &dfb101,const InputDF &dfb102,const InputDF &dfb111,const InputDF &dfb112,
  OutputDF &dfnp,OutputDF &dfp)
{ int np = (dfb001.getSize()+dfb002.getSize()+dfb011.getSize()+dfb012.getSize()+dfb101.getSize()+dfb102.getSize()+dfb111.getSize()+dfb112.getSize())/sizeof(Particle);
  int j = 0;
  Particle *p =  dfp.create<Particle>(np);
  { const Particle *b001 = dfb001.getData<Particle>();
    assert(dfb001.getSize() % sizeof(Particle) == 0);
    int np1 = dfb001.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b001[j1];
  }
  { const Particle *b002 = dfb002.getData<Particle>();
    assert(dfb002.getSize() % sizeof(Particle) == 0);
    int np1 = dfb002.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b002[j1];
  }
  { const Particle *b011 = dfb011.getData<Particle>();
    assert(dfb011.getSize() % sizeof(Particle) == 0);
    int np1 = dfb011.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b011[j1];
  }
  { const Particle *b012 = dfb012.getData<Particle>();
    assert(dfb012.getSize() % sizeof(Particle) == 0);
    int np1 = dfb012.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b012[j1];
  }
  { const Particle *b101 = dfb101.getData<Particle>();
    assert(dfb101.getSize() % sizeof(Particle) == 0);
    int np1 = dfb101.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b101[j1];
  }
  { const Particle *b102 = dfb102.getData<Particle>();
    assert(dfb102.getSize() % sizeof(Particle) == 0);
    int np1 = dfb102.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b102[j1];
  }
  { const Particle *b111 = dfb111.getData<Particle>();
    assert(dfb111.getSize() % sizeof(Particle) == 0);
    int np1 = dfb111.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b111[j1];
  }
  { const Particle *b112 = dfb112.getData<Particle>();
    assert(dfb112.getSize() % sizeof(Particle) == 0);
    int np1 = dfb112.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b112[j1];
  }
  dfnp.setValue(np);
}

void c_mesh3d_exchange_particles_27_get_10_10_10(int np,const InputDF &df_p,real x1,real y1,real z1,real x2,real y2,real z2,
  OutputDF &dfb000,OutputDF &dfb001,OutputDF &dfb010,OutputDF &dfb011,OutputDF &dfb100,OutputDF &dfb101,OutputDF &dfb110,OutputDF &dfb111)
{ int j;
  assert(df_p.getSize() == np*sizeof(Particle));
  const Particle *p = df_p.getData<Particle>();
  std::vector<Particle> vp[27];
  for (j=0;j<np;j++)
  {
    real x = p[j].x;
    real y = p[j].y;
    real z = p[j].z;
    real u = p[j].u;
    real v = p[j].v;
    real w = p[j].w;
    int code = 0;
    if (x<x1) code += 16;
    else if (x>=x2) { x = 2*x2-x; u = -u; }
    if (y<y1) code += 4;
    else if (y>=y2) { y = 2*y2-y; v = -v; }
    if (z<z1) code += 1;
    else if (z>=z2) { z = 2*z2-z; w = -w; }
    int dir = code2dir[code];
    vp[dir].push_back(Particle(x,y,z,u,v,w));
  }
  { int np = vp[D000].size();
    int j1;
    Particle *b000 = dfb000.create<Particle>(np);
    for (j=0;j<np;j++) b000[j] = vp[D000][j];
  }
  { int np = vp[D001].size();
    int j1;
    Particle *b001 = dfb001.create<Particle>(np);
    for (j=0;j<np;j++) b001[j] = vp[D001][j];
  }
  assert(vp[D002].size() == 0);
  { int np = vp[D010].size();
    int j1;
    Particle *b010 = dfb010.create<Particle>(np);
    for (j=0;j<np;j++) b010[j] = vp[D010][j];
  }
  { int np = vp[D011].size();
    int j1;
    Particle *b011 = dfb011.create<Particle>(np);
    for (j=0;j<np;j++) b011[j] = vp[D011][j];
  }
  assert(vp[D012].size() == 0);
  assert(vp[D020].size() == 0);
  assert(vp[D021].size() == 0);
  assert(vp[D022].size() == 0);
  { int np = vp[D100].size();
    int j1;
    Particle *b100 = dfb100.create<Particle>(np);
    for (j=0;j<np;j++) b100[j] = vp[D100][j];
  }
  { int np = vp[D101].size();
    int j1;
    Particle *b101 = dfb101.create<Particle>(np);
    for (j=0;j<np;j++) b101[j] = vp[D101][j];
  }
  assert(vp[D102].size() == 0);
  { int np = vp[D110].size();
    int j1;
    Particle *b110 = dfb110.create<Particle>(np);
    for (j=0;j<np;j++) b110[j] = vp[D110][j];
  }
  { int np = vp[D111].size();
    int j1;
    Particle *b111 = dfb111.create<Particle>(np);
    for (j=0;j<np;j++) b111[j] = vp[D111][j];
  }
  assert(vp[D112].size() == 0);
  assert(vp[D120].size() == 0);
  assert(vp[D121].size() == 0);
  assert(vp[D122].size() == 0);
  assert(vp[D200].size() == 0);
  assert(vp[D201].size() == 0);
  assert(vp[D202].size() == 0);
  assert(vp[D210].size() == 0);
  assert(vp[D211].size() == 0);
  assert(vp[D212].size() == 0);
  assert(vp[D220].size() == 0);
  assert(vp[D221].size() == 0);
  assert(vp[D222].size() == 0);
}

void c_mesh3d_exchange_particles_27_set_10_10_10(
  const InputDF &dfb000,const InputDF &dfb001,const InputDF &dfb010,const InputDF &dfb011,const InputDF &dfb100,const InputDF &dfb101,const InputDF &dfb110,const InputDF &dfb111,
  OutputDF &dfnp,OutputDF &dfp)
{ int np = (dfb000.getSize()+dfb001.getSize()+dfb010.getSize()+dfb011.getSize()+dfb100.getSize()+dfb101.getSize()+dfb110.getSize()+dfb111.getSize())/sizeof(Particle);
  int j = 0;
  Particle *p =  dfp.create<Particle>(np);
  { const Particle *b000 = dfb000.getData<Particle>();
    assert(dfb000.getSize() % sizeof(Particle) == 0);
    int np1 = dfb000.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b000[j1];
  }
  { const Particle *b001 = dfb001.getData<Particle>();
    assert(dfb001.getSize() % sizeof(Particle) == 0);
    int np1 = dfb001.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b001[j1];
  }
  { const Particle *b010 = dfb010.getData<Particle>();
    assert(dfb010.getSize() % sizeof(Particle) == 0);
    int np1 = dfb010.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b010[j1];
  }
  { const Particle *b011 = dfb011.getData<Particle>();
    assert(dfb011.getSize() % sizeof(Particle) == 0);
    int np1 = dfb011.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b011[j1];
  }
  { const Particle *b100 = dfb100.getData<Particle>();
    assert(dfb100.getSize() % sizeof(Particle) == 0);
    int np1 = dfb100.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b100[j1];
  }
  { const Particle *b101 = dfb101.getData<Particle>();
    assert(dfb101.getSize() % sizeof(Particle) == 0);
    int np1 = dfb101.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b101[j1];
  }
  { const Particle *b110 = dfb110.getData<Particle>();
    assert(dfb110.getSize() % sizeof(Particle) == 0);
    int np1 = dfb110.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b110[j1];
  }
  { const Particle *b111 = dfb111.getData<Particle>();
    assert(dfb111.getSize() % sizeof(Particle) == 0);
    int np1 = dfb111.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b111[j1];
  }
  dfnp.setValue(np);
}

void c_mesh3d_exchange_particles_27_get_10_10_11(int np,const InputDF &df_p,real x1,real y1,real z1,real x2,real y2,real z2,
  OutputDF &dfb000,OutputDF &dfb001,OutputDF &dfb002,OutputDF &dfb010,OutputDF &dfb011,OutputDF &dfb012,OutputDF &dfb100,OutputDF &dfb101,OutputDF &dfb102,OutputDF &dfb110,OutputDF &dfb111,OutputDF &dfb112)
{ int j;
  assert(df_p.getSize() == np*sizeof(Particle));
  const Particle *p = df_p.getData<Particle>();
  std::vector<Particle> vp[27];
  for (j=0;j<np;j++)
  {
    real x = p[j].x;
    real y = p[j].y;
    real z = p[j].z;
    real u = p[j].u;
    real v = p[j].v;
    real w = p[j].w;
    int code = 0;
    if (x<x1) code += 16;
    else if (x>=x2) { x = 2*x2-x; u = -u; }
    if (y<y1) code += 4;
    else if (y>=y2) { y = 2*y2-y; v = -v; }
    if (z<z1) code += 1;
    else if (z>=z2) code += 2;
    int dir = code2dir[code];
    vp[dir].push_back(Particle(x,y,z,u,v,w));
  }
  { int np = vp[D000].size();
    int j1;
    Particle *b000 = dfb000.create<Particle>(np);
    for (j=0;j<np;j++) b000[j] = vp[D000][j];
  }
  { int np = vp[D001].size();
    int j1;
    Particle *b001 = dfb001.create<Particle>(np);
    for (j=0;j<np;j++) b001[j] = vp[D001][j];
  }
  { int np = vp[D002].size();
    int j1;
    Particle *b002 = dfb002.create<Particle>(np);
    for (j=0;j<np;j++) b002[j] = vp[D002][j];
  }
  { int np = vp[D010].size();
    int j1;
    Particle *b010 = dfb010.create<Particle>(np);
    for (j=0;j<np;j++) b010[j] = vp[D010][j];
  }
  { int np = vp[D011].size();
    int j1;
    Particle *b011 = dfb011.create<Particle>(np);
    for (j=0;j<np;j++) b011[j] = vp[D011][j];
  }
  { int np = vp[D012].size();
    int j1;
    Particle *b012 = dfb012.create<Particle>(np);
    for (j=0;j<np;j++) b012[j] = vp[D012][j];
  }
  assert(vp[D020].size() == 0);
  assert(vp[D021].size() == 0);
  assert(vp[D022].size() == 0);
  { int np = vp[D100].size();
    int j1;
    Particle *b100 = dfb100.create<Particle>(np);
    for (j=0;j<np;j++) b100[j] = vp[D100][j];
  }
  { int np = vp[D101].size();
    int j1;
    Particle *b101 = dfb101.create<Particle>(np);
    for (j=0;j<np;j++) b101[j] = vp[D101][j];
  }
  { int np = vp[D102].size();
    int j1;
    Particle *b102 = dfb102.create<Particle>(np);
    for (j=0;j<np;j++) b102[j] = vp[D102][j];
  }
  { int np = vp[D110].size();
    int j1;
    Particle *b110 = dfb110.create<Particle>(np);
    for (j=0;j<np;j++) b110[j] = vp[D110][j];
  }
  { int np = vp[D111].size();
    int j1;
    Particle *b111 = dfb111.create<Particle>(np);
    for (j=0;j<np;j++) b111[j] = vp[D111][j];
  }
  { int np = vp[D112].size();
    int j1;
    Particle *b112 = dfb112.create<Particle>(np);
    for (j=0;j<np;j++) b112[j] = vp[D112][j];
  }
  assert(vp[D120].size() == 0);
  assert(vp[D121].size() == 0);
  assert(vp[D122].size() == 0);
  assert(vp[D200].size() == 0);
  assert(vp[D201].size() == 0);
  assert(vp[D202].size() == 0);
  assert(vp[D210].size() == 0);
  assert(vp[D211].size() == 0);
  assert(vp[D212].size() == 0);
  assert(vp[D220].size() == 0);
  assert(vp[D221].size() == 0);
  assert(vp[D222].size() == 0);
}

void c_mesh3d_exchange_particles_27_set_10_10_11(
  const InputDF &dfb000,const InputDF &dfb001,const InputDF &dfb002,const InputDF &dfb010,const InputDF &dfb011,const InputDF &dfb012,const InputDF &dfb100,const InputDF &dfb101,const InputDF &dfb102,const InputDF &dfb110,const InputDF &dfb111,const InputDF &dfb112,
  OutputDF &dfnp,OutputDF &dfp)
{ int np = (dfb000.getSize()+dfb001.getSize()+dfb002.getSize()+dfb010.getSize()+dfb011.getSize()+dfb012.getSize()+dfb100.getSize()+dfb101.getSize()+dfb102.getSize()+dfb110.getSize()+dfb111.getSize()+dfb112.getSize())/sizeof(Particle);
  int j = 0;
  Particle *p =  dfp.create<Particle>(np);
  { const Particle *b000 = dfb000.getData<Particle>();
    assert(dfb000.getSize() % sizeof(Particle) == 0);
    int np1 = dfb000.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b000[j1];
  }
  { const Particle *b001 = dfb001.getData<Particle>();
    assert(dfb001.getSize() % sizeof(Particle) == 0);
    int np1 = dfb001.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b001[j1];
  }
  { const Particle *b002 = dfb002.getData<Particle>();
    assert(dfb002.getSize() % sizeof(Particle) == 0);
    int np1 = dfb002.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b002[j1];
  }
  { const Particle *b010 = dfb010.getData<Particle>();
    assert(dfb010.getSize() % sizeof(Particle) == 0);
    int np1 = dfb010.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b010[j1];
  }
  { const Particle *b011 = dfb011.getData<Particle>();
    assert(dfb011.getSize() % sizeof(Particle) == 0);
    int np1 = dfb011.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b011[j1];
  }
  { const Particle *b012 = dfb012.getData<Particle>();
    assert(dfb012.getSize() % sizeof(Particle) == 0);
    int np1 = dfb012.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b012[j1];
  }
  { const Particle *b100 = dfb100.getData<Particle>();
    assert(dfb100.getSize() % sizeof(Particle) == 0);
    int np1 = dfb100.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b100[j1];
  }
  { const Particle *b101 = dfb101.getData<Particle>();
    assert(dfb101.getSize() % sizeof(Particle) == 0);
    int np1 = dfb101.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b101[j1];
  }
  { const Particle *b102 = dfb102.getData<Particle>();
    assert(dfb102.getSize() % sizeof(Particle) == 0);
    int np1 = dfb102.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b102[j1];
  }
  { const Particle *b110 = dfb110.getData<Particle>();
    assert(dfb110.getSize() % sizeof(Particle) == 0);
    int np1 = dfb110.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b110[j1];
  }
  { const Particle *b111 = dfb111.getData<Particle>();
    assert(dfb111.getSize() % sizeof(Particle) == 0);
    int np1 = dfb111.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b111[j1];
  }
  { const Particle *b112 = dfb112.getData<Particle>();
    assert(dfb112.getSize() % sizeof(Particle) == 0);
    int np1 = dfb112.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b112[j1];
  }
  dfnp.setValue(np);
}

void c_mesh3d_exchange_particles_27_get_10_11_00(int np,const InputDF &df_p,real x1,real y1,real z1,real x2,real y2,real z2,
  OutputDF &dfb001,OutputDF &dfb011,OutputDF &dfb021,OutputDF &dfb101,OutputDF &dfb111,OutputDF &dfb121)
{ int j;
  assert(df_p.getSize() == np*sizeof(Particle));
  const Particle *p = df_p.getData<Particle>();
  std::vector<Particle> vp[27];
  for (j=0;j<np;j++)
  {
    real x = p[j].x;
    real y = p[j].y;
    real z = p[j].z;
    real u = p[j].u;
    real v = p[j].v;
    real w = p[j].w;
    int code = 0;
    if (x<x1) code += 16;
    else if (x>=x2) { x = 2*x2-x; u = -u; }
    if (y<y1) code += 4;
    else if (y>=y2) code += 8;
    if (z<z1) { z = 2*z1-z; w = -w; }
    else if (z>=z2) { z = 2*z2-z; w = -w; }
    int dir = code2dir[code];
    vp[dir].push_back(Particle(x,y,z,u,v,w));
  }
  assert(vp[D000].size() == 0);
  { int np = vp[D001].size();
    int j1;
    Particle *b001 = dfb001.create<Particle>(np);
    for (j=0;j<np;j++) b001[j] = vp[D001][j];
  }
  assert(vp[D002].size() == 0);
  assert(vp[D010].size() == 0);
  { int np = vp[D011].size();
    int j1;
    Particle *b011 = dfb011.create<Particle>(np);
    for (j=0;j<np;j++) b011[j] = vp[D011][j];
  }
  assert(vp[D012].size() == 0);
  assert(vp[D020].size() == 0);
  { int np = vp[D021].size();
    int j1;
    Particle *b021 = dfb021.create<Particle>(np);
    for (j=0;j<np;j++) b021[j] = vp[D021][j];
  }
  assert(vp[D022].size() == 0);
  assert(vp[D100].size() == 0);
  { int np = vp[D101].size();
    int j1;
    Particle *b101 = dfb101.create<Particle>(np);
    for (j=0;j<np;j++) b101[j] = vp[D101][j];
  }
  assert(vp[D102].size() == 0);
  assert(vp[D110].size() == 0);
  { int np = vp[D111].size();
    int j1;
    Particle *b111 = dfb111.create<Particle>(np);
    for (j=0;j<np;j++) b111[j] = vp[D111][j];
  }
  assert(vp[D112].size() == 0);
  assert(vp[D120].size() == 0);
  { int np = vp[D121].size();
    int j1;
    Particle *b121 = dfb121.create<Particle>(np);
    for (j=0;j<np;j++) b121[j] = vp[D121][j];
  }
  assert(vp[D122].size() == 0);
  assert(vp[D200].size() == 0);
  assert(vp[D201].size() == 0);
  assert(vp[D202].size() == 0);
  assert(vp[D210].size() == 0);
  assert(vp[D211].size() == 0);
  assert(vp[D212].size() == 0);
  assert(vp[D220].size() == 0);
  assert(vp[D221].size() == 0);
  assert(vp[D222].size() == 0);
}

void c_mesh3d_exchange_particles_27_set_10_11_00(
  const InputDF &dfb001,const InputDF &dfb011,const InputDF &dfb021,const InputDF &dfb101,const InputDF &dfb111,const InputDF &dfb121,
  OutputDF &dfnp,OutputDF &dfp)
{ int np = (dfb001.getSize()+dfb011.getSize()+dfb021.getSize()+dfb101.getSize()+dfb111.getSize()+dfb121.getSize())/sizeof(Particle);
  int j = 0;
  Particle *p =  dfp.create<Particle>(np);
  { const Particle *b001 = dfb001.getData<Particle>();
    assert(dfb001.getSize() % sizeof(Particle) == 0);
    int np1 = dfb001.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b001[j1];
  }
  { const Particle *b011 = dfb011.getData<Particle>();
    assert(dfb011.getSize() % sizeof(Particle) == 0);
    int np1 = dfb011.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b011[j1];
  }
  { const Particle *b021 = dfb021.getData<Particle>();
    assert(dfb021.getSize() % sizeof(Particle) == 0);
    int np1 = dfb021.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b021[j1];
  }
  { const Particle *b101 = dfb101.getData<Particle>();
    assert(dfb101.getSize() % sizeof(Particle) == 0);
    int np1 = dfb101.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b101[j1];
  }
  { const Particle *b111 = dfb111.getData<Particle>();
    assert(dfb111.getSize() % sizeof(Particle) == 0);
    int np1 = dfb111.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b111[j1];
  }
  { const Particle *b121 = dfb121.getData<Particle>();
    assert(dfb121.getSize() % sizeof(Particle) == 0);
    int np1 = dfb121.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b121[j1];
  }
  dfnp.setValue(np);
}

void c_mesh3d_exchange_particles_27_get_10_11_01(int np,const InputDF &df_p,real x1,real y1,real z1,real x2,real y2,real z2,
  OutputDF &dfb001,OutputDF &dfb002,OutputDF &dfb011,OutputDF &dfb012,OutputDF &dfb021,OutputDF &dfb022,OutputDF &dfb101,OutputDF &dfb102,OutputDF &dfb111,OutputDF &dfb112,OutputDF &dfb121,OutputDF &dfb122)
{ int j;
  assert(df_p.getSize() == np*sizeof(Particle));
  const Particle *p = df_p.getData<Particle>();
  std::vector<Particle> vp[27];
  for (j=0;j<np;j++)
  {
    real x = p[j].x;
    real y = p[j].y;
    real z = p[j].z;
    real u = p[j].u;
    real v = p[j].v;
    real w = p[j].w;
    int code = 0;
    if (x<x1) code += 16;
    else if (x>=x2) { x = 2*x2-x; u = -u; }
    if (y<y1) code += 4;
    else if (y>=y2) code += 8;
    if (z<z1) { z = 2*z1-z; w = -w; }
    else if (z>=z2) code += 2;
    int dir = code2dir[code];
    vp[dir].push_back(Particle(x,y,z,u,v,w));
  }
  assert(vp[D000].size() == 0);
  { int np = vp[D001].size();
    int j1;
    Particle *b001 = dfb001.create<Particle>(np);
    for (j=0;j<np;j++) b001[j] = vp[D001][j];
  }
  { int np = vp[D002].size();
    int j1;
    Particle *b002 = dfb002.create<Particle>(np);
    for (j=0;j<np;j++) b002[j] = vp[D002][j];
  }
  assert(vp[D010].size() == 0);
  { int np = vp[D011].size();
    int j1;
    Particle *b011 = dfb011.create<Particle>(np);
    for (j=0;j<np;j++) b011[j] = vp[D011][j];
  }
  { int np = vp[D012].size();
    int j1;
    Particle *b012 = dfb012.create<Particle>(np);
    for (j=0;j<np;j++) b012[j] = vp[D012][j];
  }
  assert(vp[D020].size() == 0);
  { int np = vp[D021].size();
    int j1;
    Particle *b021 = dfb021.create<Particle>(np);
    for (j=0;j<np;j++) b021[j] = vp[D021][j];
  }
  { int np = vp[D022].size();
    int j1;
    Particle *b022 = dfb022.create<Particle>(np);
    for (j=0;j<np;j++) b022[j] = vp[D022][j];
  }
  assert(vp[D100].size() == 0);
  { int np = vp[D101].size();
    int j1;
    Particle *b101 = dfb101.create<Particle>(np);
    for (j=0;j<np;j++) b101[j] = vp[D101][j];
  }
  { int np = vp[D102].size();
    int j1;
    Particle *b102 = dfb102.create<Particle>(np);
    for (j=0;j<np;j++) b102[j] = vp[D102][j];
  }
  assert(vp[D110].size() == 0);
  { int np = vp[D111].size();
    int j1;
    Particle *b111 = dfb111.create<Particle>(np);
    for (j=0;j<np;j++) b111[j] = vp[D111][j];
  }
  { int np = vp[D112].size();
    int j1;
    Particle *b112 = dfb112.create<Particle>(np);
    for (j=0;j<np;j++) b112[j] = vp[D112][j];
  }
  assert(vp[D120].size() == 0);
  { int np = vp[D121].size();
    int j1;
    Particle *b121 = dfb121.create<Particle>(np);
    for (j=0;j<np;j++) b121[j] = vp[D121][j];
  }
  { int np = vp[D122].size();
    int j1;
    Particle *b122 = dfb122.create<Particle>(np);
    for (j=0;j<np;j++) b122[j] = vp[D122][j];
  }
  assert(vp[D200].size() == 0);
  assert(vp[D201].size() == 0);
  assert(vp[D202].size() == 0);
  assert(vp[D210].size() == 0);
  assert(vp[D211].size() == 0);
  assert(vp[D212].size() == 0);
  assert(vp[D220].size() == 0);
  assert(vp[D221].size() == 0);
  assert(vp[D222].size() == 0);
}

void c_mesh3d_exchange_particles_27_set_10_11_01(
  const InputDF &dfb001,const InputDF &dfb002,const InputDF &dfb011,const InputDF &dfb012,const InputDF &dfb021,const InputDF &dfb022,const InputDF &dfb101,const InputDF &dfb102,const InputDF &dfb111,const InputDF &dfb112,const InputDF &dfb121,const InputDF &dfb122,
  OutputDF &dfnp,OutputDF &dfp)
{ int np = (dfb001.getSize()+dfb002.getSize()+dfb011.getSize()+dfb012.getSize()+dfb021.getSize()+dfb022.getSize()+dfb101.getSize()+dfb102.getSize()+dfb111.getSize()+dfb112.getSize()+dfb121.getSize()+dfb122.getSize())/sizeof(Particle);
  int j = 0;
  Particle *p =  dfp.create<Particle>(np);
  { const Particle *b001 = dfb001.getData<Particle>();
    assert(dfb001.getSize() % sizeof(Particle) == 0);
    int np1 = dfb001.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b001[j1];
  }
  { const Particle *b002 = dfb002.getData<Particle>();
    assert(dfb002.getSize() % sizeof(Particle) == 0);
    int np1 = dfb002.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b002[j1];
  }
  { const Particle *b011 = dfb011.getData<Particle>();
    assert(dfb011.getSize() % sizeof(Particle) == 0);
    int np1 = dfb011.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b011[j1];
  }
  { const Particle *b012 = dfb012.getData<Particle>();
    assert(dfb012.getSize() % sizeof(Particle) == 0);
    int np1 = dfb012.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b012[j1];
  }
  { const Particle *b021 = dfb021.getData<Particle>();
    assert(dfb021.getSize() % sizeof(Particle) == 0);
    int np1 = dfb021.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b021[j1];
  }
  { const Particle *b022 = dfb022.getData<Particle>();
    assert(dfb022.getSize() % sizeof(Particle) == 0);
    int np1 = dfb022.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b022[j1];
  }
  { const Particle *b101 = dfb101.getData<Particle>();
    assert(dfb101.getSize() % sizeof(Particle) == 0);
    int np1 = dfb101.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b101[j1];
  }
  { const Particle *b102 = dfb102.getData<Particle>();
    assert(dfb102.getSize() % sizeof(Particle) == 0);
    int np1 = dfb102.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b102[j1];
  }
  { const Particle *b111 = dfb111.getData<Particle>();
    assert(dfb111.getSize() % sizeof(Particle) == 0);
    int np1 = dfb111.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b111[j1];
  }
  { const Particle *b112 = dfb112.getData<Particle>();
    assert(dfb112.getSize() % sizeof(Particle) == 0);
    int np1 = dfb112.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b112[j1];
  }
  { const Particle *b121 = dfb121.getData<Particle>();
    assert(dfb121.getSize() % sizeof(Particle) == 0);
    int np1 = dfb121.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b121[j1];
  }
  { const Particle *b122 = dfb122.getData<Particle>();
    assert(dfb122.getSize() % sizeof(Particle) == 0);
    int np1 = dfb122.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b122[j1];
  }
  dfnp.setValue(np);
}

void c_mesh3d_exchange_particles_27_get_10_11_10(int np,const InputDF &df_p,real x1,real y1,real z1,real x2,real y2,real z2,
  OutputDF &dfb000,OutputDF &dfb001,OutputDF &dfb010,OutputDF &dfb011,OutputDF &dfb020,OutputDF &dfb021,OutputDF &dfb100,OutputDF &dfb101,OutputDF &dfb110,OutputDF &dfb111,OutputDF &dfb120,OutputDF &dfb121)
{ int j;
  assert(df_p.getSize() == np*sizeof(Particle));
  const Particle *p = df_p.getData<Particle>();
  std::vector<Particle> vp[27];
  for (j=0;j<np;j++)
  {
    real x = p[j].x;
    real y = p[j].y;
    real z = p[j].z;
    real u = p[j].u;
    real v = p[j].v;
    real w = p[j].w;
    int code = 0;
    if (x<x1) code += 16;
    else if (x>=x2) { x = 2*x2-x; u = -u; }
    if (y<y1) code += 4;
    else if (y>=y2) code += 8;
    if (z<z1) code += 1;
    else if (z>=z2) { z = 2*z2-z; w = -w; }
    int dir = code2dir[code];
    vp[dir].push_back(Particle(x,y,z,u,v,w));
  }
  { int np = vp[D000].size();
    int j1;
    Particle *b000 = dfb000.create<Particle>(np);
    for (j=0;j<np;j++) b000[j] = vp[D000][j];
  }
  { int np = vp[D001].size();
    int j1;
    Particle *b001 = dfb001.create<Particle>(np);
    for (j=0;j<np;j++) b001[j] = vp[D001][j];
  }
  assert(vp[D002].size() == 0);
  { int np = vp[D010].size();
    int j1;
    Particle *b010 = dfb010.create<Particle>(np);
    for (j=0;j<np;j++) b010[j] = vp[D010][j];
  }
  { int np = vp[D011].size();
    int j1;
    Particle *b011 = dfb011.create<Particle>(np);
    for (j=0;j<np;j++) b011[j] = vp[D011][j];
  }
  assert(vp[D012].size() == 0);
  { int np = vp[D020].size();
    int j1;
    Particle *b020 = dfb020.create<Particle>(np);
    for (j=0;j<np;j++) b020[j] = vp[D020][j];
  }
  { int np = vp[D021].size();
    int j1;
    Particle *b021 = dfb021.create<Particle>(np);
    for (j=0;j<np;j++) b021[j] = vp[D021][j];
  }
  assert(vp[D022].size() == 0);
  { int np = vp[D100].size();
    int j1;
    Particle *b100 = dfb100.create<Particle>(np);
    for (j=0;j<np;j++) b100[j] = vp[D100][j];
  }
  { int np = vp[D101].size();
    int j1;
    Particle *b101 = dfb101.create<Particle>(np);
    for (j=0;j<np;j++) b101[j] = vp[D101][j];
  }
  assert(vp[D102].size() == 0);
  { int np = vp[D110].size();
    int j1;
    Particle *b110 = dfb110.create<Particle>(np);
    for (j=0;j<np;j++) b110[j] = vp[D110][j];
  }
  { int np = vp[D111].size();
    int j1;
    Particle *b111 = dfb111.create<Particle>(np);
    for (j=0;j<np;j++) b111[j] = vp[D111][j];
  }
  assert(vp[D112].size() == 0);
  { int np = vp[D120].size();
    int j1;
    Particle *b120 = dfb120.create<Particle>(np);
    for (j=0;j<np;j++) b120[j] = vp[D120][j];
  }
  { int np = vp[D121].size();
    int j1;
    Particle *b121 = dfb121.create<Particle>(np);
    for (j=0;j<np;j++) b121[j] = vp[D121][j];
  }
  assert(vp[D122].size() == 0);
  assert(vp[D200].size() == 0);
  assert(vp[D201].size() == 0);
  assert(vp[D202].size() == 0);
  assert(vp[D210].size() == 0);
  assert(vp[D211].size() == 0);
  assert(vp[D212].size() == 0);
  assert(vp[D220].size() == 0);
  assert(vp[D221].size() == 0);
  assert(vp[D222].size() == 0);
}

void c_mesh3d_exchange_particles_27_set_10_11_10(
  const InputDF &dfb000,const InputDF &dfb001,const InputDF &dfb010,const InputDF &dfb011,const InputDF &dfb020,const InputDF &dfb021,const InputDF &dfb100,const InputDF &dfb101,const InputDF &dfb110,const InputDF &dfb111,const InputDF &dfb120,const InputDF &dfb121,
  OutputDF &dfnp,OutputDF &dfp)
{ int np = (dfb000.getSize()+dfb001.getSize()+dfb010.getSize()+dfb011.getSize()+dfb020.getSize()+dfb021.getSize()+dfb100.getSize()+dfb101.getSize()+dfb110.getSize()+dfb111.getSize()+dfb120.getSize()+dfb121.getSize())/sizeof(Particle);
  int j = 0;
  Particle *p =  dfp.create<Particle>(np);
  { const Particle *b000 = dfb000.getData<Particle>();
    assert(dfb000.getSize() % sizeof(Particle) == 0);
    int np1 = dfb000.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b000[j1];
  }
  { const Particle *b001 = dfb001.getData<Particle>();
    assert(dfb001.getSize() % sizeof(Particle) == 0);
    int np1 = dfb001.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b001[j1];
  }
  { const Particle *b010 = dfb010.getData<Particle>();
    assert(dfb010.getSize() % sizeof(Particle) == 0);
    int np1 = dfb010.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b010[j1];
  }
  { const Particle *b011 = dfb011.getData<Particle>();
    assert(dfb011.getSize() % sizeof(Particle) == 0);
    int np1 = dfb011.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b011[j1];
  }
  { const Particle *b020 = dfb020.getData<Particle>();
    assert(dfb020.getSize() % sizeof(Particle) == 0);
    int np1 = dfb020.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b020[j1];
  }
  { const Particle *b021 = dfb021.getData<Particle>();
    assert(dfb021.getSize() % sizeof(Particle) == 0);
    int np1 = dfb021.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b021[j1];
  }
  { const Particle *b100 = dfb100.getData<Particle>();
    assert(dfb100.getSize() % sizeof(Particle) == 0);
    int np1 = dfb100.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b100[j1];
  }
  { const Particle *b101 = dfb101.getData<Particle>();
    assert(dfb101.getSize() % sizeof(Particle) == 0);
    int np1 = dfb101.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b101[j1];
  }
  { const Particle *b110 = dfb110.getData<Particle>();
    assert(dfb110.getSize() % sizeof(Particle) == 0);
    int np1 = dfb110.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b110[j1];
  }
  { const Particle *b111 = dfb111.getData<Particle>();
    assert(dfb111.getSize() % sizeof(Particle) == 0);
    int np1 = dfb111.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b111[j1];
  }
  { const Particle *b120 = dfb120.getData<Particle>();
    assert(dfb120.getSize() % sizeof(Particle) == 0);
    int np1 = dfb120.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b120[j1];
  }
  { const Particle *b121 = dfb121.getData<Particle>();
    assert(dfb121.getSize() % sizeof(Particle) == 0);
    int np1 = dfb121.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b121[j1];
  }
  dfnp.setValue(np);
}

void c_mesh3d_exchange_particles_27_get_10_11_11(int np,const InputDF &df_p,real x1,real y1,real z1,real x2,real y2,real z2,
  OutputDF &dfb000,OutputDF &dfb001,OutputDF &dfb002,OutputDF &dfb010,OutputDF &dfb011,OutputDF &dfb012,OutputDF &dfb020,OutputDF &dfb021,OutputDF &dfb022,OutputDF &dfb100,OutputDF &dfb101,OutputDF &dfb102,OutputDF &dfb110,OutputDF &dfb111,OutputDF &dfb112,OutputDF &dfb120,OutputDF &dfb121,OutputDF &dfb122)
{ int j;
  assert(df_p.getSize() == np*sizeof(Particle));
  const Particle *p = df_p.getData<Particle>();
  std::vector<Particle> vp[27];
  for (j=0;j<np;j++)
  {
    real x = p[j].x;
    real y = p[j].y;
    real z = p[j].z;
    real u = p[j].u;
    real v = p[j].v;
    real w = p[j].w;
    int code = 0;
    if (x<x1) code += 16;
    else if (x>=x2) { x = 2*x2-x; u = -u; }
    if (y<y1) code += 4;
    else if (y>=y2) code += 8;
    if (z<z1) code += 1;
    else if (z>=z2) code += 2;
    int dir = code2dir[code];
    vp[dir].push_back(Particle(x,y,z,u,v,w));
  }
  { int np = vp[D000].size();
    int j1;
    Particle *b000 = dfb000.create<Particle>(np);
    for (j=0;j<np;j++) b000[j] = vp[D000][j];
  }
  { int np = vp[D001].size();
    int j1;
    Particle *b001 = dfb001.create<Particle>(np);
    for (j=0;j<np;j++) b001[j] = vp[D001][j];
  }
  { int np = vp[D002].size();
    int j1;
    Particle *b002 = dfb002.create<Particle>(np);
    for (j=0;j<np;j++) b002[j] = vp[D002][j];
  }
  { int np = vp[D010].size();
    int j1;
    Particle *b010 = dfb010.create<Particle>(np);
    for (j=0;j<np;j++) b010[j] = vp[D010][j];
  }
  { int np = vp[D011].size();
    int j1;
    Particle *b011 = dfb011.create<Particle>(np);
    for (j=0;j<np;j++) b011[j] = vp[D011][j];
  }
  { int np = vp[D012].size();
    int j1;
    Particle *b012 = dfb012.create<Particle>(np);
    for (j=0;j<np;j++) b012[j] = vp[D012][j];
  }
  { int np = vp[D020].size();
    int j1;
    Particle *b020 = dfb020.create<Particle>(np);
    for (j=0;j<np;j++) b020[j] = vp[D020][j];
  }
  { int np = vp[D021].size();
    int j1;
    Particle *b021 = dfb021.create<Particle>(np);
    for (j=0;j<np;j++) b021[j] = vp[D021][j];
  }
  { int np = vp[D022].size();
    int j1;
    Particle *b022 = dfb022.create<Particle>(np);
    for (j=0;j<np;j++) b022[j] = vp[D022][j];
  }
  { int np = vp[D100].size();
    int j1;
    Particle *b100 = dfb100.create<Particle>(np);
    for (j=0;j<np;j++) b100[j] = vp[D100][j];
  }
  { int np = vp[D101].size();
    int j1;
    Particle *b101 = dfb101.create<Particle>(np);
    for (j=0;j<np;j++) b101[j] = vp[D101][j];
  }
  { int np = vp[D102].size();
    int j1;
    Particle *b102 = dfb102.create<Particle>(np);
    for (j=0;j<np;j++) b102[j] = vp[D102][j];
  }
  { int np = vp[D110].size();
    int j1;
    Particle *b110 = dfb110.create<Particle>(np);
    for (j=0;j<np;j++) b110[j] = vp[D110][j];
  }
  { int np = vp[D111].size();
    int j1;
    Particle *b111 = dfb111.create<Particle>(np);
    for (j=0;j<np;j++) b111[j] = vp[D111][j];
  }
  { int np = vp[D112].size();
    int j1;
    Particle *b112 = dfb112.create<Particle>(np);
    for (j=0;j<np;j++) b112[j] = vp[D112][j];
  }
  { int np = vp[D120].size();
    int j1;
    Particle *b120 = dfb120.create<Particle>(np);
    for (j=0;j<np;j++) b120[j] = vp[D120][j];
  }
  { int np = vp[D121].size();
    int j1;
    Particle *b121 = dfb121.create<Particle>(np);
    for (j=0;j<np;j++) b121[j] = vp[D121][j];
  }
  { int np = vp[D122].size();
    int j1;
    Particle *b122 = dfb122.create<Particle>(np);
    for (j=0;j<np;j++) b122[j] = vp[D122][j];
  }
  assert(vp[D200].size() == 0);
  assert(vp[D201].size() == 0);
  assert(vp[D202].size() == 0);
  assert(vp[D210].size() == 0);
  assert(vp[D211].size() == 0);
  assert(vp[D212].size() == 0);
  assert(vp[D220].size() == 0);
  assert(vp[D221].size() == 0);
  assert(vp[D222].size() == 0);
}

void c_mesh3d_exchange_particles_27_set_10_11_11(
  const InputDF &dfb000,const InputDF &dfb001,const InputDF &dfb002,const InputDF &dfb010,const InputDF &dfb011,const InputDF &dfb012,const InputDF &dfb020,const InputDF &dfb021,const InputDF &dfb022,const InputDF &dfb100,const InputDF &dfb101,const InputDF &dfb102,const InputDF &dfb110,const InputDF &dfb111,const InputDF &dfb112,const InputDF &dfb120,const InputDF &dfb121,const InputDF &dfb122,
  OutputDF &dfnp,OutputDF &dfp)
{ int np = (dfb000.getSize()+dfb001.getSize()+dfb002.getSize()+dfb010.getSize()+dfb011.getSize()+dfb012.getSize()+dfb020.getSize()+dfb021.getSize()+dfb022.getSize()+dfb100.getSize()+dfb101.getSize()+dfb102.getSize()+dfb110.getSize()+dfb111.getSize()+dfb112.getSize()+dfb120.getSize()+dfb121.getSize()+dfb122.getSize())/sizeof(Particle);
  int j = 0;
  Particle *p =  dfp.create<Particle>(np);
  { const Particle *b000 = dfb000.getData<Particle>();
    assert(dfb000.getSize() % sizeof(Particle) == 0);
    int np1 = dfb000.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b000[j1];
  }
  { const Particle *b001 = dfb001.getData<Particle>();
    assert(dfb001.getSize() % sizeof(Particle) == 0);
    int np1 = dfb001.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b001[j1];
  }
  { const Particle *b002 = dfb002.getData<Particle>();
    assert(dfb002.getSize() % sizeof(Particle) == 0);
    int np1 = dfb002.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b002[j1];
  }
  { const Particle *b010 = dfb010.getData<Particle>();
    assert(dfb010.getSize() % sizeof(Particle) == 0);
    int np1 = dfb010.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b010[j1];
  }
  { const Particle *b011 = dfb011.getData<Particle>();
    assert(dfb011.getSize() % sizeof(Particle) == 0);
    int np1 = dfb011.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b011[j1];
  }
  { const Particle *b012 = dfb012.getData<Particle>();
    assert(dfb012.getSize() % sizeof(Particle) == 0);
    int np1 = dfb012.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b012[j1];
  }
  { const Particle *b020 = dfb020.getData<Particle>();
    assert(dfb020.getSize() % sizeof(Particle) == 0);
    int np1 = dfb020.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b020[j1];
  }
  { const Particle *b021 = dfb021.getData<Particle>();
    assert(dfb021.getSize() % sizeof(Particle) == 0);
    int np1 = dfb021.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b021[j1];
  }
  { const Particle *b022 = dfb022.getData<Particle>();
    assert(dfb022.getSize() % sizeof(Particle) == 0);
    int np1 = dfb022.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b022[j1];
  }
  { const Particle *b100 = dfb100.getData<Particle>();
    assert(dfb100.getSize() % sizeof(Particle) == 0);
    int np1 = dfb100.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b100[j1];
  }
  { const Particle *b101 = dfb101.getData<Particle>();
    assert(dfb101.getSize() % sizeof(Particle) == 0);
    int np1 = dfb101.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b101[j1];
  }
  { const Particle *b102 = dfb102.getData<Particle>();
    assert(dfb102.getSize() % sizeof(Particle) == 0);
    int np1 = dfb102.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b102[j1];
  }
  { const Particle *b110 = dfb110.getData<Particle>();
    assert(dfb110.getSize() % sizeof(Particle) == 0);
    int np1 = dfb110.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b110[j1];
  }
  { const Particle *b111 = dfb111.getData<Particle>();
    assert(dfb111.getSize() % sizeof(Particle) == 0);
    int np1 = dfb111.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b111[j1];
  }
  { const Particle *b112 = dfb112.getData<Particle>();
    assert(dfb112.getSize() % sizeof(Particle) == 0);
    int np1 = dfb112.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b112[j1];
  }
  { const Particle *b120 = dfb120.getData<Particle>();
    assert(dfb120.getSize() % sizeof(Particle) == 0);
    int np1 = dfb120.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b120[j1];
  }
  { const Particle *b121 = dfb121.getData<Particle>();
    assert(dfb121.getSize() % sizeof(Particle) == 0);
    int np1 = dfb121.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b121[j1];
  }
  { const Particle *b122 = dfb122.getData<Particle>();
    assert(dfb122.getSize() % sizeof(Particle) == 0);
    int np1 = dfb122.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b122[j1];
  }
  dfnp.setValue(np);
}

void c_mesh3d_exchange_particles_27_get_11_00_00(int np,const InputDF &df_p,real x1,real y1,real z1,real x2,real y2,real z2,
  OutputDF &dfb011,OutputDF &dfb111,OutputDF &dfb211)
{ int j;
  assert(df_p.getSize() == np*sizeof(Particle));
  const Particle *p = df_p.getData<Particle>();
  std::vector<Particle> vp[27];
  for (j=0;j<np;j++)
  {
    real x = p[j].x;
    real y = p[j].y;
    real z = p[j].z;
    real u = p[j].u;
    real v = p[j].v;
    real w = p[j].w;
    int code = 0;
    if (x<x1) code += 16;
    else if (x>=x2) code += 32;
    if (y<y1) { y = 2*y1-y; v = -v; }
    else if (y>=y2) { y = 2*y2-y; v = -v; }
    if (z<z1) { z = 2*z1-z; w = -w; }
    else if (z>=z2) { z = 2*z2-z; w = -w; }
    int dir = code2dir[code];
    vp[dir].push_back(Particle(x,y,z,u,v,w));
  }
  assert(vp[D000].size() == 0);
  assert(vp[D001].size() == 0);
  assert(vp[D002].size() == 0);
  assert(vp[D010].size() == 0);
  { int np = vp[D011].size();
    int j1;
    Particle *b011 = dfb011.create<Particle>(np);
    for (j=0;j<np;j++) b011[j] = vp[D011][j];
  }
  assert(vp[D012].size() == 0);
  assert(vp[D020].size() == 0);
  assert(vp[D021].size() == 0);
  assert(vp[D022].size() == 0);
  assert(vp[D100].size() == 0);
  assert(vp[D101].size() == 0);
  assert(vp[D102].size() == 0);
  assert(vp[D110].size() == 0);
  { int np = vp[D111].size();
    int j1;
    Particle *b111 = dfb111.create<Particle>(np);
    for (j=0;j<np;j++) b111[j] = vp[D111][j];
  }
  assert(vp[D112].size() == 0);
  assert(vp[D120].size() == 0);
  assert(vp[D121].size() == 0);
  assert(vp[D122].size() == 0);
  assert(vp[D200].size() == 0);
  assert(vp[D201].size() == 0);
  assert(vp[D202].size() == 0);
  assert(vp[D210].size() == 0);
  { int np = vp[D211].size();
    int j1;
    Particle *b211 = dfb211.create<Particle>(np);
    for (j=0;j<np;j++) b211[j] = vp[D211][j];
  }
  assert(vp[D212].size() == 0);
  assert(vp[D220].size() == 0);
  assert(vp[D221].size() == 0);
  assert(vp[D222].size() == 0);
}

void c_mesh3d_exchange_particles_27_set_11_00_00(
  const InputDF &dfb011,const InputDF &dfb111,const InputDF &dfb211,
  OutputDF &dfnp,OutputDF &dfp)
{ int np = (dfb011.getSize()+dfb111.getSize()+dfb211.getSize())/sizeof(Particle);
  int j = 0;
  Particle *p =  dfp.create<Particle>(np);
  { const Particle *b011 = dfb011.getData<Particle>();
    assert(dfb011.getSize() % sizeof(Particle) == 0);
    int np1 = dfb011.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b011[j1];
  }
  { const Particle *b111 = dfb111.getData<Particle>();
    assert(dfb111.getSize() % sizeof(Particle) == 0);
    int np1 = dfb111.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b111[j1];
  }
  { const Particle *b211 = dfb211.getData<Particle>();
    assert(dfb211.getSize() % sizeof(Particle) == 0);
    int np1 = dfb211.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b211[j1];
  }
  dfnp.setValue(np);
}

void c_mesh3d_exchange_particles_27_get_11_00_01(int np,const InputDF &df_p,real x1,real y1,real z1,real x2,real y2,real z2,
  OutputDF &dfb011,OutputDF &dfb012,OutputDF &dfb111,OutputDF &dfb112,OutputDF &dfb211,OutputDF &dfb212)
{ int j;
  assert(df_p.getSize() == np*sizeof(Particle));
  const Particle *p = df_p.getData<Particle>();
  std::vector<Particle> vp[27];
  for (j=0;j<np;j++)
  {
    real x = p[j].x;
    real y = p[j].y;
    real z = p[j].z;
    real u = p[j].u;
    real v = p[j].v;
    real w = p[j].w;
    int code = 0;
    if (x<x1) code += 16;
    else if (x>=x2) code += 32;
    if (y<y1) { y = 2*y1-y; v = -v; }
    else if (y>=y2) { y = 2*y2-y; v = -v; }
    if (z<z1) { z = 2*z1-z; w = -w; }
    else if (z>=z2) code += 2;
    int dir = code2dir[code];
    vp[dir].push_back(Particle(x,y,z,u,v,w));
  }
  assert(vp[D000].size() == 0);
  assert(vp[D001].size() == 0);
  assert(vp[D002].size() == 0);
  assert(vp[D010].size() == 0);
  { int np = vp[D011].size();
    int j1;
    Particle *b011 = dfb011.create<Particle>(np);
    for (j=0;j<np;j++) b011[j] = vp[D011][j];
  }
  { int np = vp[D012].size();
    int j1;
    Particle *b012 = dfb012.create<Particle>(np);
    for (j=0;j<np;j++) b012[j] = vp[D012][j];
  }
  assert(vp[D020].size() == 0);
  assert(vp[D021].size() == 0);
  assert(vp[D022].size() == 0);
  assert(vp[D100].size() == 0);
  assert(vp[D101].size() == 0);
  assert(vp[D102].size() == 0);
  assert(vp[D110].size() == 0);
  { int np = vp[D111].size();
    int j1;
    Particle *b111 = dfb111.create<Particle>(np);
    for (j=0;j<np;j++) b111[j] = vp[D111][j];
  }
  { int np = vp[D112].size();
    int j1;
    Particle *b112 = dfb112.create<Particle>(np);
    for (j=0;j<np;j++) b112[j] = vp[D112][j];
  }
  assert(vp[D120].size() == 0);
  assert(vp[D121].size() == 0);
  assert(vp[D122].size() == 0);
  assert(vp[D200].size() == 0);
  assert(vp[D201].size() == 0);
  assert(vp[D202].size() == 0);
  assert(vp[D210].size() == 0);
  { int np = vp[D211].size();
    int j1;
    Particle *b211 = dfb211.create<Particle>(np);
    for (j=0;j<np;j++) b211[j] = vp[D211][j];
  }
  { int np = vp[D212].size();
    int j1;
    Particle *b212 = dfb212.create<Particle>(np);
    for (j=0;j<np;j++) b212[j] = vp[D212][j];
  }
  assert(vp[D220].size() == 0);
  assert(vp[D221].size() == 0);
  assert(vp[D222].size() == 0);
}

void c_mesh3d_exchange_particles_27_set_11_00_01(
  const InputDF &dfb011,const InputDF &dfb012,const InputDF &dfb111,const InputDF &dfb112,const InputDF &dfb211,const InputDF &dfb212,
  OutputDF &dfnp,OutputDF &dfp)
{ int np = (dfb011.getSize()+dfb012.getSize()+dfb111.getSize()+dfb112.getSize()+dfb211.getSize()+dfb212.getSize())/sizeof(Particle);
  int j = 0;
  Particle *p =  dfp.create<Particle>(np);
  { const Particle *b011 = dfb011.getData<Particle>();
    assert(dfb011.getSize() % sizeof(Particle) == 0);
    int np1 = dfb011.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b011[j1];
  }
  { const Particle *b012 = dfb012.getData<Particle>();
    assert(dfb012.getSize() % sizeof(Particle) == 0);
    int np1 = dfb012.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b012[j1];
  }
  { const Particle *b111 = dfb111.getData<Particle>();
    assert(dfb111.getSize() % sizeof(Particle) == 0);
    int np1 = dfb111.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b111[j1];
  }
  { const Particle *b112 = dfb112.getData<Particle>();
    assert(dfb112.getSize() % sizeof(Particle) == 0);
    int np1 = dfb112.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b112[j1];
  }
  { const Particle *b211 = dfb211.getData<Particle>();
    assert(dfb211.getSize() % sizeof(Particle) == 0);
    int np1 = dfb211.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b211[j1];
  }
  { const Particle *b212 = dfb212.getData<Particle>();
    assert(dfb212.getSize() % sizeof(Particle) == 0);
    int np1 = dfb212.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b212[j1];
  }
  dfnp.setValue(np);
}

void c_mesh3d_exchange_particles_27_get_11_00_10(int np,const InputDF &df_p,real x1,real y1,real z1,real x2,real y2,real z2,
  OutputDF &dfb010,OutputDF &dfb011,OutputDF &dfb110,OutputDF &dfb111,OutputDF &dfb210,OutputDF &dfb211)
{ int j;
  assert(df_p.getSize() == np*sizeof(Particle));
  const Particle *p = df_p.getData<Particle>();
  std::vector<Particle> vp[27];
  for (j=0;j<np;j++)
  {
    real x = p[j].x;
    real y = p[j].y;
    real z = p[j].z;
    real u = p[j].u;
    real v = p[j].v;
    real w = p[j].w;
    int code = 0;
    if (x<x1) code += 16;
    else if (x>=x2) code += 32;
    if (y<y1) { y = 2*y1-y; v = -v; }
    else if (y>=y2) { y = 2*y2-y; v = -v; }
    if (z<z1) code += 1;
    else if (z>=z2) { z = 2*z2-z; w = -w; }
    int dir = code2dir[code];
    vp[dir].push_back(Particle(x,y,z,u,v,w));
  }
  assert(vp[D000].size() == 0);
  assert(vp[D001].size() == 0);
  assert(vp[D002].size() == 0);
  { int np = vp[D010].size();
    int j1;
    Particle *b010 = dfb010.create<Particle>(np);
    for (j=0;j<np;j++) b010[j] = vp[D010][j];
  }
  { int np = vp[D011].size();
    int j1;
    Particle *b011 = dfb011.create<Particle>(np);
    for (j=0;j<np;j++) b011[j] = vp[D011][j];
  }
  assert(vp[D012].size() == 0);
  assert(vp[D020].size() == 0);
  assert(vp[D021].size() == 0);
  assert(vp[D022].size() == 0);
  assert(vp[D100].size() == 0);
  assert(vp[D101].size() == 0);
  assert(vp[D102].size() == 0);
  { int np = vp[D110].size();
    int j1;
    Particle *b110 = dfb110.create<Particle>(np);
    for (j=0;j<np;j++) b110[j] = vp[D110][j];
  }
  { int np = vp[D111].size();
    int j1;
    Particle *b111 = dfb111.create<Particle>(np);
    for (j=0;j<np;j++) b111[j] = vp[D111][j];
  }
  assert(vp[D112].size() == 0);
  assert(vp[D120].size() == 0);
  assert(vp[D121].size() == 0);
  assert(vp[D122].size() == 0);
  assert(vp[D200].size() == 0);
  assert(vp[D201].size() == 0);
  assert(vp[D202].size() == 0);
  { int np = vp[D210].size();
    int j1;
    Particle *b210 = dfb210.create<Particle>(np);
    for (j=0;j<np;j++) b210[j] = vp[D210][j];
  }
  { int np = vp[D211].size();
    int j1;
    Particle *b211 = dfb211.create<Particle>(np);
    for (j=0;j<np;j++) b211[j] = vp[D211][j];
  }
  assert(vp[D212].size() == 0);
  assert(vp[D220].size() == 0);
  assert(vp[D221].size() == 0);
  assert(vp[D222].size() == 0);
}

void c_mesh3d_exchange_particles_27_set_11_00_10(
  const InputDF &dfb010,const InputDF &dfb011,const InputDF &dfb110,const InputDF &dfb111,const InputDF &dfb210,const InputDF &dfb211,
  OutputDF &dfnp,OutputDF &dfp)
{ int np = (dfb010.getSize()+dfb011.getSize()+dfb110.getSize()+dfb111.getSize()+dfb210.getSize()+dfb211.getSize())/sizeof(Particle);
  int j = 0;
  Particle *p =  dfp.create<Particle>(np);
  { const Particle *b010 = dfb010.getData<Particle>();
    assert(dfb010.getSize() % sizeof(Particle) == 0);
    int np1 = dfb010.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b010[j1];
  }
  { const Particle *b011 = dfb011.getData<Particle>();
    assert(dfb011.getSize() % sizeof(Particle) == 0);
    int np1 = dfb011.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b011[j1];
  }
  { const Particle *b110 = dfb110.getData<Particle>();
    assert(dfb110.getSize() % sizeof(Particle) == 0);
    int np1 = dfb110.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b110[j1];
  }
  { const Particle *b111 = dfb111.getData<Particle>();
    assert(dfb111.getSize() % sizeof(Particle) == 0);
    int np1 = dfb111.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b111[j1];
  }
  { const Particle *b210 = dfb210.getData<Particle>();
    assert(dfb210.getSize() % sizeof(Particle) == 0);
    int np1 = dfb210.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b210[j1];
  }
  { const Particle *b211 = dfb211.getData<Particle>();
    assert(dfb211.getSize() % sizeof(Particle) == 0);
    int np1 = dfb211.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b211[j1];
  }
  dfnp.setValue(np);
}

void c_mesh3d_exchange_particles_27_get_11_00_11(int np,const InputDF &df_p,real x1,real y1,real z1,real x2,real y2,real z2,
  OutputDF &dfb010,OutputDF &dfb011,OutputDF &dfb012,OutputDF &dfb110,OutputDF &dfb111,OutputDF &dfb112,OutputDF &dfb210,OutputDF &dfb211,OutputDF &dfb212)
{ int j;
  assert(df_p.getSize() == np*sizeof(Particle));
  const Particle *p = df_p.getData<Particle>();
  std::vector<Particle> vp[27];
  for (j=0;j<np;j++)
  {
    real x = p[j].x;
    real y = p[j].y;
    real z = p[j].z;
    real u = p[j].u;
    real v = p[j].v;
    real w = p[j].w;
    int code = 0;
    if (x<x1) code += 16;
    else if (x>=x2) code += 32;
    if (y<y1) { y = 2*y1-y; v = -v; }
    else if (y>=y2) { y = 2*y2-y; v = -v; }
    if (z<z1) code += 1;
    else if (z>=z2) code += 2;
    int dir = code2dir[code];
    vp[dir].push_back(Particle(x,y,z,u,v,w));
  }
  assert(vp[D000].size() == 0);
  assert(vp[D001].size() == 0);
  assert(vp[D002].size() == 0);
  { int np = vp[D010].size();
    int j1;
    Particle *b010 = dfb010.create<Particle>(np);
    for (j=0;j<np;j++) b010[j] = vp[D010][j];
  }
  { int np = vp[D011].size();
    int j1;
    Particle *b011 = dfb011.create<Particle>(np);
    for (j=0;j<np;j++) b011[j] = vp[D011][j];
  }
  { int np = vp[D012].size();
    int j1;
    Particle *b012 = dfb012.create<Particle>(np);
    for (j=0;j<np;j++) b012[j] = vp[D012][j];
  }
  assert(vp[D020].size() == 0);
  assert(vp[D021].size() == 0);
  assert(vp[D022].size() == 0);
  assert(vp[D100].size() == 0);
  assert(vp[D101].size() == 0);
  assert(vp[D102].size() == 0);
  { int np = vp[D110].size();
    int j1;
    Particle *b110 = dfb110.create<Particle>(np);
    for (j=0;j<np;j++) b110[j] = vp[D110][j];
  }
  { int np = vp[D111].size();
    int j1;
    Particle *b111 = dfb111.create<Particle>(np);
    for (j=0;j<np;j++) b111[j] = vp[D111][j];
  }
  { int np = vp[D112].size();
    int j1;
    Particle *b112 = dfb112.create<Particle>(np);
    for (j=0;j<np;j++) b112[j] = vp[D112][j];
  }
  assert(vp[D120].size() == 0);
  assert(vp[D121].size() == 0);
  assert(vp[D122].size() == 0);
  assert(vp[D200].size() == 0);
  assert(vp[D201].size() == 0);
  assert(vp[D202].size() == 0);
  { int np = vp[D210].size();
    int j1;
    Particle *b210 = dfb210.create<Particle>(np);
    for (j=0;j<np;j++) b210[j] = vp[D210][j];
  }
  { int np = vp[D211].size();
    int j1;
    Particle *b211 = dfb211.create<Particle>(np);
    for (j=0;j<np;j++) b211[j] = vp[D211][j];
  }
  { int np = vp[D212].size();
    int j1;
    Particle *b212 = dfb212.create<Particle>(np);
    for (j=0;j<np;j++) b212[j] = vp[D212][j];
  }
  assert(vp[D220].size() == 0);
  assert(vp[D221].size() == 0);
  assert(vp[D222].size() == 0);
}

void c_mesh3d_exchange_particles_27_set_11_00_11(
  const InputDF &dfb010,const InputDF &dfb011,const InputDF &dfb012,const InputDF &dfb110,const InputDF &dfb111,const InputDF &dfb112,const InputDF &dfb210,const InputDF &dfb211,const InputDF &dfb212,
  OutputDF &dfnp,OutputDF &dfp)
{ int np = (dfb010.getSize()+dfb011.getSize()+dfb012.getSize()+dfb110.getSize()+dfb111.getSize()+dfb112.getSize()+dfb210.getSize()+dfb211.getSize()+dfb212.getSize())/sizeof(Particle);
  int j = 0;
  Particle *p =  dfp.create<Particle>(np);
  { const Particle *b010 = dfb010.getData<Particle>();
    assert(dfb010.getSize() % sizeof(Particle) == 0);
    int np1 = dfb010.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b010[j1];
  }
  { const Particle *b011 = dfb011.getData<Particle>();
    assert(dfb011.getSize() % sizeof(Particle) == 0);
    int np1 = dfb011.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b011[j1];
  }
  { const Particle *b012 = dfb012.getData<Particle>();
    assert(dfb012.getSize() % sizeof(Particle) == 0);
    int np1 = dfb012.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b012[j1];
  }
  { const Particle *b110 = dfb110.getData<Particle>();
    assert(dfb110.getSize() % sizeof(Particle) == 0);
    int np1 = dfb110.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b110[j1];
  }
  { const Particle *b111 = dfb111.getData<Particle>();
    assert(dfb111.getSize() % sizeof(Particle) == 0);
    int np1 = dfb111.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b111[j1];
  }
  { const Particle *b112 = dfb112.getData<Particle>();
    assert(dfb112.getSize() % sizeof(Particle) == 0);
    int np1 = dfb112.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b112[j1];
  }
  { const Particle *b210 = dfb210.getData<Particle>();
    assert(dfb210.getSize() % sizeof(Particle) == 0);
    int np1 = dfb210.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b210[j1];
  }
  { const Particle *b211 = dfb211.getData<Particle>();
    assert(dfb211.getSize() % sizeof(Particle) == 0);
    int np1 = dfb211.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b211[j1];
  }
  { const Particle *b212 = dfb212.getData<Particle>();
    assert(dfb212.getSize() % sizeof(Particle) == 0);
    int np1 = dfb212.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b212[j1];
  }
  dfnp.setValue(np);
}

void c_mesh3d_exchange_particles_27_get_11_01_00(int np,const InputDF &df_p,real x1,real y1,real z1,real x2,real y2,real z2,
  OutputDF &dfb011,OutputDF &dfb021,OutputDF &dfb111,OutputDF &dfb121,OutputDF &dfb211,OutputDF &dfb221)
{ int j;
  assert(df_p.getSize() == np*sizeof(Particle));
  const Particle *p = df_p.getData<Particle>();
  std::vector<Particle> vp[27];
  for (j=0;j<np;j++)
  {
    real x = p[j].x;
    real y = p[j].y;
    real z = p[j].z;
    real u = p[j].u;
    real v = p[j].v;
    real w = p[j].w;
    int code = 0;
    if (x<x1) code += 16;
    else if (x>=x2) code += 32;
    if (y<y1) { y = 2*y1-y; v = -v; }
    else if (y>=y2) code += 8;
    if (z<z1) { z = 2*z1-z; w = -w; }
    else if (z>=z2) { z = 2*z2-z; w = -w; }
    int dir = code2dir[code];
    vp[dir].push_back(Particle(x,y,z,u,v,w));
  }
  assert(vp[D000].size() == 0);
  assert(vp[D001].size() == 0);
  assert(vp[D002].size() == 0);
  assert(vp[D010].size() == 0);
  { int np = vp[D011].size();
    int j1;
    Particle *b011 = dfb011.create<Particle>(np);
    for (j=0;j<np;j++) b011[j] = vp[D011][j];
  }
  assert(vp[D012].size() == 0);
  assert(vp[D020].size() == 0);
  { int np = vp[D021].size();
    int j1;
    Particle *b021 = dfb021.create<Particle>(np);
    for (j=0;j<np;j++) b021[j] = vp[D021][j];
  }
  assert(vp[D022].size() == 0);
  assert(vp[D100].size() == 0);
  assert(vp[D101].size() == 0);
  assert(vp[D102].size() == 0);
  assert(vp[D110].size() == 0);
  { int np = vp[D111].size();
    int j1;
    Particle *b111 = dfb111.create<Particle>(np);
    for (j=0;j<np;j++) b111[j] = vp[D111][j];
  }
  assert(vp[D112].size() == 0);
  assert(vp[D120].size() == 0);
  { int np = vp[D121].size();
    int j1;
    Particle *b121 = dfb121.create<Particle>(np);
    for (j=0;j<np;j++) b121[j] = vp[D121][j];
  }
  assert(vp[D122].size() == 0);
  assert(vp[D200].size() == 0);
  assert(vp[D201].size() == 0);
  assert(vp[D202].size() == 0);
  assert(vp[D210].size() == 0);
  { int np = vp[D211].size();
    int j1;
    Particle *b211 = dfb211.create<Particle>(np);
    for (j=0;j<np;j++) b211[j] = vp[D211][j];
  }
  assert(vp[D212].size() == 0);
  assert(vp[D220].size() == 0);
  { int np = vp[D221].size();
    int j1;
    Particle *b221 = dfb221.create<Particle>(np);
    for (j=0;j<np;j++) b221[j] = vp[D221][j];
  }
  assert(vp[D222].size() == 0);
}

void c_mesh3d_exchange_particles_27_set_11_01_00(
  const InputDF &dfb011,const InputDF &dfb021,const InputDF &dfb111,const InputDF &dfb121,const InputDF &dfb211,const InputDF &dfb221,
  OutputDF &dfnp,OutputDF &dfp)
{ int np = (dfb011.getSize()+dfb021.getSize()+dfb111.getSize()+dfb121.getSize()+dfb211.getSize()+dfb221.getSize())/sizeof(Particle);
  int j = 0;
  Particle *p =  dfp.create<Particle>(np);
  { const Particle *b011 = dfb011.getData<Particle>();
    assert(dfb011.getSize() % sizeof(Particle) == 0);
    int np1 = dfb011.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b011[j1];
  }
  { const Particle *b021 = dfb021.getData<Particle>();
    assert(dfb021.getSize() % sizeof(Particle) == 0);
    int np1 = dfb021.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b021[j1];
  }
  { const Particle *b111 = dfb111.getData<Particle>();
    assert(dfb111.getSize() % sizeof(Particle) == 0);
    int np1 = dfb111.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b111[j1];
  }
  { const Particle *b121 = dfb121.getData<Particle>();
    assert(dfb121.getSize() % sizeof(Particle) == 0);
    int np1 = dfb121.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b121[j1];
  }
  { const Particle *b211 = dfb211.getData<Particle>();
    assert(dfb211.getSize() % sizeof(Particle) == 0);
    int np1 = dfb211.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b211[j1];
  }
  { const Particle *b221 = dfb221.getData<Particle>();
    assert(dfb221.getSize() % sizeof(Particle) == 0);
    int np1 = dfb221.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b221[j1];
  }
  dfnp.setValue(np);
}

void c_mesh3d_exchange_particles_27_get_11_01_01(int np,const InputDF &df_p,real x1,real y1,real z1,real x2,real y2,real z2,
  OutputDF &dfb011,OutputDF &dfb012,OutputDF &dfb021,OutputDF &dfb022,OutputDF &dfb111,OutputDF &dfb112,OutputDF &dfb121,OutputDF &dfb122,OutputDF &dfb211,OutputDF &dfb212,OutputDF &dfb221,OutputDF &dfb222)
{ int j;
  assert(df_p.getSize() == np*sizeof(Particle));
  const Particle *p = df_p.getData<Particle>();
  std::vector<Particle> vp[27];
  for (j=0;j<np;j++)
  {
    real x = p[j].x;
    real y = p[j].y;
    real z = p[j].z;
    real u = p[j].u;
    real v = p[j].v;
    real w = p[j].w;
    int code = 0;
    if (x<x1) code += 16;
    else if (x>=x2) code += 32;
    if (y<y1) { y = 2*y1-y; v = -v; }
    else if (y>=y2) code += 8;
    if (z<z1) { z = 2*z1-z; w = -w; }
    else if (z>=z2) code += 2;
    int dir = code2dir[code];
    vp[dir].push_back(Particle(x,y,z,u,v,w));
  }
  assert(vp[D000].size() == 0);
  assert(vp[D001].size() == 0);
  assert(vp[D002].size() == 0);
  assert(vp[D010].size() == 0);
  { int np = vp[D011].size();
    int j1;
    Particle *b011 = dfb011.create<Particle>(np);
    for (j=0;j<np;j++) b011[j] = vp[D011][j];
  }
  { int np = vp[D012].size();
    int j1;
    Particle *b012 = dfb012.create<Particle>(np);
    for (j=0;j<np;j++) b012[j] = vp[D012][j];
  }
  assert(vp[D020].size() == 0);
  { int np = vp[D021].size();
    int j1;
    Particle *b021 = dfb021.create<Particle>(np);
    for (j=0;j<np;j++) b021[j] = vp[D021][j];
  }
  { int np = vp[D022].size();
    int j1;
    Particle *b022 = dfb022.create<Particle>(np);
    for (j=0;j<np;j++) b022[j] = vp[D022][j];
  }
  assert(vp[D100].size() == 0);
  assert(vp[D101].size() == 0);
  assert(vp[D102].size() == 0);
  assert(vp[D110].size() == 0);
  { int np = vp[D111].size();
    int j1;
    Particle *b111 = dfb111.create<Particle>(np);
    for (j=0;j<np;j++) b111[j] = vp[D111][j];
  }
  { int np = vp[D112].size();
    int j1;
    Particle *b112 = dfb112.create<Particle>(np);
    for (j=0;j<np;j++) b112[j] = vp[D112][j];
  }
  assert(vp[D120].size() == 0);
  { int np = vp[D121].size();
    int j1;
    Particle *b121 = dfb121.create<Particle>(np);
    for (j=0;j<np;j++) b121[j] = vp[D121][j];
  }
  { int np = vp[D122].size();
    int j1;
    Particle *b122 = dfb122.create<Particle>(np);
    for (j=0;j<np;j++) b122[j] = vp[D122][j];
  }
  assert(vp[D200].size() == 0);
  assert(vp[D201].size() == 0);
  assert(vp[D202].size() == 0);
  assert(vp[D210].size() == 0);
  { int np = vp[D211].size();
    int j1;
    Particle *b211 = dfb211.create<Particle>(np);
    for (j=0;j<np;j++) b211[j] = vp[D211][j];
  }
  { int np = vp[D212].size();
    int j1;
    Particle *b212 = dfb212.create<Particle>(np);
    for (j=0;j<np;j++) b212[j] = vp[D212][j];
  }
  assert(vp[D220].size() == 0);
  { int np = vp[D221].size();
    int j1;
    Particle *b221 = dfb221.create<Particle>(np);
    for (j=0;j<np;j++) b221[j] = vp[D221][j];
  }
  { int np = vp[D222].size();
    int j1;
    Particle *b222 = dfb222.create<Particle>(np);
    for (j=0;j<np;j++) b222[j] = vp[D222][j];
  }
}

void c_mesh3d_exchange_particles_27_set_11_01_01(
  const InputDF &dfb011,const InputDF &dfb012,const InputDF &dfb021,const InputDF &dfb022,const InputDF &dfb111,const InputDF &dfb112,const InputDF &dfb121,const InputDF &dfb122,const InputDF &dfb211,const InputDF &dfb212,const InputDF &dfb221,const InputDF &dfb222,
  OutputDF &dfnp,OutputDF &dfp)
{ int np = (dfb011.getSize()+dfb012.getSize()+dfb021.getSize()+dfb022.getSize()+dfb111.getSize()+dfb112.getSize()+dfb121.getSize()+dfb122.getSize()+dfb211.getSize()+dfb212.getSize()+dfb221.getSize()+dfb222.getSize())/sizeof(Particle);
  int j = 0;
  Particle *p =  dfp.create<Particle>(np);
  { const Particle *b011 = dfb011.getData<Particle>();
    assert(dfb011.getSize() % sizeof(Particle) == 0);
    int np1 = dfb011.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b011[j1];
  }
  { const Particle *b012 = dfb012.getData<Particle>();
    assert(dfb012.getSize() % sizeof(Particle) == 0);
    int np1 = dfb012.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b012[j1];
  }
  { const Particle *b021 = dfb021.getData<Particle>();
    assert(dfb021.getSize() % sizeof(Particle) == 0);
    int np1 = dfb021.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b021[j1];
  }
  { const Particle *b022 = dfb022.getData<Particle>();
    assert(dfb022.getSize() % sizeof(Particle) == 0);
    int np1 = dfb022.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b022[j1];
  }
  { const Particle *b111 = dfb111.getData<Particle>();
    assert(dfb111.getSize() % sizeof(Particle) == 0);
    int np1 = dfb111.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b111[j1];
  }
  { const Particle *b112 = dfb112.getData<Particle>();
    assert(dfb112.getSize() % sizeof(Particle) == 0);
    int np1 = dfb112.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b112[j1];
  }
  { const Particle *b121 = dfb121.getData<Particle>();
    assert(dfb121.getSize() % sizeof(Particle) == 0);
    int np1 = dfb121.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b121[j1];
  }
  { const Particle *b122 = dfb122.getData<Particle>();
    assert(dfb122.getSize() % sizeof(Particle) == 0);
    int np1 = dfb122.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b122[j1];
  }
  { const Particle *b211 = dfb211.getData<Particle>();
    assert(dfb211.getSize() % sizeof(Particle) == 0);
    int np1 = dfb211.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b211[j1];
  }
  { const Particle *b212 = dfb212.getData<Particle>();
    assert(dfb212.getSize() % sizeof(Particle) == 0);
    int np1 = dfb212.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b212[j1];
  }
  { const Particle *b221 = dfb221.getData<Particle>();
    assert(dfb221.getSize() % sizeof(Particle) == 0);
    int np1 = dfb221.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b221[j1];
  }
  { const Particle *b222 = dfb222.getData<Particle>();
    assert(dfb222.getSize() % sizeof(Particle) == 0);
    int np1 = dfb222.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b222[j1];
  }
  dfnp.setValue(np);
}

void c_mesh3d_exchange_particles_27_get_11_01_10(int np,const InputDF &df_p,real x1,real y1,real z1,real x2,real y2,real z2,
  OutputDF &dfb010,OutputDF &dfb011,OutputDF &dfb020,OutputDF &dfb021,OutputDF &dfb110,OutputDF &dfb111,OutputDF &dfb120,OutputDF &dfb121,OutputDF &dfb210,OutputDF &dfb211,OutputDF &dfb220,OutputDF &dfb221)
{ int j;
  assert(df_p.getSize() == np*sizeof(Particle));
  const Particle *p = df_p.getData<Particle>();
  std::vector<Particle> vp[27];
  for (j=0;j<np;j++)
  {
    real x = p[j].x;
    real y = p[j].y;
    real z = p[j].z;
    real u = p[j].u;
    real v = p[j].v;
    real w = p[j].w;
    int code = 0;
    if (x<x1) code += 16;
    else if (x>=x2) code += 32;
    if (y<y1) { y = 2*y1-y; v = -v; }
    else if (y>=y2) code += 8;
    if (z<z1) code += 1;
    else if (z>=z2) { z = 2*z2-z; w = -w; }
    int dir = code2dir[code];
    vp[dir].push_back(Particle(x,y,z,u,v,w));
  }
  assert(vp[D000].size() == 0);
  assert(vp[D001].size() == 0);
  assert(vp[D002].size() == 0);
  { int np = vp[D010].size();
    int j1;
    Particle *b010 = dfb010.create<Particle>(np);
    for (j=0;j<np;j++) b010[j] = vp[D010][j];
  }
  { int np = vp[D011].size();
    int j1;
    Particle *b011 = dfb011.create<Particle>(np);
    for (j=0;j<np;j++) b011[j] = vp[D011][j];
  }
  assert(vp[D012].size() == 0);
  { int np = vp[D020].size();
    int j1;
    Particle *b020 = dfb020.create<Particle>(np);
    for (j=0;j<np;j++) b020[j] = vp[D020][j];
  }
  { int np = vp[D021].size();
    int j1;
    Particle *b021 = dfb021.create<Particle>(np);
    for (j=0;j<np;j++) b021[j] = vp[D021][j];
  }
  assert(vp[D022].size() == 0);
  assert(vp[D100].size() == 0);
  assert(vp[D101].size() == 0);
  assert(vp[D102].size() == 0);
  { int np = vp[D110].size();
    int j1;
    Particle *b110 = dfb110.create<Particle>(np);
    for (j=0;j<np;j++) b110[j] = vp[D110][j];
  }
  { int np = vp[D111].size();
    int j1;
    Particle *b111 = dfb111.create<Particle>(np);
    for (j=0;j<np;j++) b111[j] = vp[D111][j];
  }
  assert(vp[D112].size() == 0);
  { int np = vp[D120].size();
    int j1;
    Particle *b120 = dfb120.create<Particle>(np);
    for (j=0;j<np;j++) b120[j] = vp[D120][j];
  }
  { int np = vp[D121].size();
    int j1;
    Particle *b121 = dfb121.create<Particle>(np);
    for (j=0;j<np;j++) b121[j] = vp[D121][j];
  }
  assert(vp[D122].size() == 0);
  assert(vp[D200].size() == 0);
  assert(vp[D201].size() == 0);
  assert(vp[D202].size() == 0);
  { int np = vp[D210].size();
    int j1;
    Particle *b210 = dfb210.create<Particle>(np);
    for (j=0;j<np;j++) b210[j] = vp[D210][j];
  }
  { int np = vp[D211].size();
    int j1;
    Particle *b211 = dfb211.create<Particle>(np);
    for (j=0;j<np;j++) b211[j] = vp[D211][j];
  }
  assert(vp[D212].size() == 0);
  { int np = vp[D220].size();
    int j1;
    Particle *b220 = dfb220.create<Particle>(np);
    for (j=0;j<np;j++) b220[j] = vp[D220][j];
  }
  { int np = vp[D221].size();
    int j1;
    Particle *b221 = dfb221.create<Particle>(np);
    for (j=0;j<np;j++) b221[j] = vp[D221][j];
  }
  assert(vp[D222].size() == 0);
}

void c_mesh3d_exchange_particles_27_set_11_01_10(
  const InputDF &dfb010,const InputDF &dfb011,const InputDF &dfb020,const InputDF &dfb021,const InputDF &dfb110,const InputDF &dfb111,const InputDF &dfb120,const InputDF &dfb121,const InputDF &dfb210,const InputDF &dfb211,const InputDF &dfb220,const InputDF &dfb221,
  OutputDF &dfnp,OutputDF &dfp)
{ int np = (dfb010.getSize()+dfb011.getSize()+dfb020.getSize()+dfb021.getSize()+dfb110.getSize()+dfb111.getSize()+dfb120.getSize()+dfb121.getSize()+dfb210.getSize()+dfb211.getSize()+dfb220.getSize()+dfb221.getSize())/sizeof(Particle);
  int j = 0;
  Particle *p =  dfp.create<Particle>(np);
  { const Particle *b010 = dfb010.getData<Particle>();
    assert(dfb010.getSize() % sizeof(Particle) == 0);
    int np1 = dfb010.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b010[j1];
  }
  { const Particle *b011 = dfb011.getData<Particle>();
    assert(dfb011.getSize() % sizeof(Particle) == 0);
    int np1 = dfb011.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b011[j1];
  }
  { const Particle *b020 = dfb020.getData<Particle>();
    assert(dfb020.getSize() % sizeof(Particle) == 0);
    int np1 = dfb020.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b020[j1];
  }
  { const Particle *b021 = dfb021.getData<Particle>();
    assert(dfb021.getSize() % sizeof(Particle) == 0);
    int np1 = dfb021.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b021[j1];
  }
  { const Particle *b110 = dfb110.getData<Particle>();
    assert(dfb110.getSize() % sizeof(Particle) == 0);
    int np1 = dfb110.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b110[j1];
  }
  { const Particle *b111 = dfb111.getData<Particle>();
    assert(dfb111.getSize() % sizeof(Particle) == 0);
    int np1 = dfb111.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b111[j1];
  }
  { const Particle *b120 = dfb120.getData<Particle>();
    assert(dfb120.getSize() % sizeof(Particle) == 0);
    int np1 = dfb120.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b120[j1];
  }
  { const Particle *b121 = dfb121.getData<Particle>();
    assert(dfb121.getSize() % sizeof(Particle) == 0);
    int np1 = dfb121.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b121[j1];
  }
  { const Particle *b210 = dfb210.getData<Particle>();
    assert(dfb210.getSize() % sizeof(Particle) == 0);
    int np1 = dfb210.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b210[j1];
  }
  { const Particle *b211 = dfb211.getData<Particle>();
    assert(dfb211.getSize() % sizeof(Particle) == 0);
    int np1 = dfb211.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b211[j1];
  }
  { const Particle *b220 = dfb220.getData<Particle>();
    assert(dfb220.getSize() % sizeof(Particle) == 0);
    int np1 = dfb220.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b220[j1];
  }
  { const Particle *b221 = dfb221.getData<Particle>();
    assert(dfb221.getSize() % sizeof(Particle) == 0);
    int np1 = dfb221.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b221[j1];
  }
  dfnp.setValue(np);
}

void c_mesh3d_exchange_particles_27_get_11_01_11(int np,const InputDF &df_p,real x1,real y1,real z1,real x2,real y2,real z2,
  OutputDF &dfb010,OutputDF &dfb011,OutputDF &dfb012,OutputDF &dfb020,OutputDF &dfb021,OutputDF &dfb022,OutputDF &dfb110,OutputDF &dfb111,OutputDF &dfb112,OutputDF &dfb120,OutputDF &dfb121,OutputDF &dfb122,OutputDF &dfb210,OutputDF &dfb211,OutputDF &dfb212,OutputDF &dfb220,OutputDF &dfb221,OutputDF &dfb222)
{ int j;
  assert(df_p.getSize() == np*sizeof(Particle));
  const Particle *p = df_p.getData<Particle>();
  std::vector<Particle> vp[27];
  for (j=0;j<np;j++)
  {
    real x = p[j].x;
    real y = p[j].y;
    real z = p[j].z;
    real u = p[j].u;
    real v = p[j].v;
    real w = p[j].w;
    int code = 0;
    if (x<x1) code += 16;
    else if (x>=x2) code += 32;
    if (y<y1) { y = 2*y1-y; v = -v; }
    else if (y>=y2) code += 8;
    if (z<z1) code += 1;
    else if (z>=z2) code += 2;
    int dir = code2dir[code];
    vp[dir].push_back(Particle(x,y,z,u,v,w));
  }
  assert(vp[D000].size() == 0);
  assert(vp[D001].size() == 0);
  assert(vp[D002].size() == 0);
  { int np = vp[D010].size();
    int j1;
    Particle *b010 = dfb010.create<Particle>(np);
    for (j=0;j<np;j++) b010[j] = vp[D010][j];
  }
  { int np = vp[D011].size();
    int j1;
    Particle *b011 = dfb011.create<Particle>(np);
    for (j=0;j<np;j++) b011[j] = vp[D011][j];
  }
  { int np = vp[D012].size();
    int j1;
    Particle *b012 = dfb012.create<Particle>(np);
    for (j=0;j<np;j++) b012[j] = vp[D012][j];
  }
  { int np = vp[D020].size();
    int j1;
    Particle *b020 = dfb020.create<Particle>(np);
    for (j=0;j<np;j++) b020[j] = vp[D020][j];
  }
  { int np = vp[D021].size();
    int j1;
    Particle *b021 = dfb021.create<Particle>(np);
    for (j=0;j<np;j++) b021[j] = vp[D021][j];
  }
  { int np = vp[D022].size();
    int j1;
    Particle *b022 = dfb022.create<Particle>(np);
    for (j=0;j<np;j++) b022[j] = vp[D022][j];
  }
  assert(vp[D100].size() == 0);
  assert(vp[D101].size() == 0);
  assert(vp[D102].size() == 0);
  { int np = vp[D110].size();
    int j1;
    Particle *b110 = dfb110.create<Particle>(np);
    for (j=0;j<np;j++) b110[j] = vp[D110][j];
  }
  { int np = vp[D111].size();
    int j1;
    Particle *b111 = dfb111.create<Particle>(np);
    for (j=0;j<np;j++) b111[j] = vp[D111][j];
  }
  { int np = vp[D112].size();
    int j1;
    Particle *b112 = dfb112.create<Particle>(np);
    for (j=0;j<np;j++) b112[j] = vp[D112][j];
  }
  { int np = vp[D120].size();
    int j1;
    Particle *b120 = dfb120.create<Particle>(np);
    for (j=0;j<np;j++) b120[j] = vp[D120][j];
  }
  { int np = vp[D121].size();
    int j1;
    Particle *b121 = dfb121.create<Particle>(np);
    for (j=0;j<np;j++) b121[j] = vp[D121][j];
  }
  { int np = vp[D122].size();
    int j1;
    Particle *b122 = dfb122.create<Particle>(np);
    for (j=0;j<np;j++) b122[j] = vp[D122][j];
  }
  assert(vp[D200].size() == 0);
  assert(vp[D201].size() == 0);
  assert(vp[D202].size() == 0);
  { int np = vp[D210].size();
    int j1;
    Particle *b210 = dfb210.create<Particle>(np);
    for (j=0;j<np;j++) b210[j] = vp[D210][j];
  }
  { int np = vp[D211].size();
    int j1;
    Particle *b211 = dfb211.create<Particle>(np);
    for (j=0;j<np;j++) b211[j] = vp[D211][j];
  }
  { int np = vp[D212].size();
    int j1;
    Particle *b212 = dfb212.create<Particle>(np);
    for (j=0;j<np;j++) b212[j] = vp[D212][j];
  }
  { int np = vp[D220].size();
    int j1;
    Particle *b220 = dfb220.create<Particle>(np);
    for (j=0;j<np;j++) b220[j] = vp[D220][j];
  }
  { int np = vp[D221].size();
    int j1;
    Particle *b221 = dfb221.create<Particle>(np);
    for (j=0;j<np;j++) b221[j] = vp[D221][j];
  }
  { int np = vp[D222].size();
    int j1;
    Particle *b222 = dfb222.create<Particle>(np);
    for (j=0;j<np;j++) b222[j] = vp[D222][j];
  }
}

void c_mesh3d_exchange_particles_27_set_11_01_11(
  const InputDF &dfb010,const InputDF &dfb011,const InputDF &dfb012,const InputDF &dfb020,const InputDF &dfb021,const InputDF &dfb022,const InputDF &dfb110,const InputDF &dfb111,const InputDF &dfb112,const InputDF &dfb120,const InputDF &dfb121,const InputDF &dfb122,const InputDF &dfb210,const InputDF &dfb211,const InputDF &dfb212,const InputDF &dfb220,const InputDF &dfb221,const InputDF &dfb222,
  OutputDF &dfnp,OutputDF &dfp)
{ int np = (dfb010.getSize()+dfb011.getSize()+dfb012.getSize()+dfb020.getSize()+dfb021.getSize()+dfb022.getSize()+dfb110.getSize()+dfb111.getSize()+dfb112.getSize()+dfb120.getSize()+dfb121.getSize()+dfb122.getSize()+dfb210.getSize()+dfb211.getSize()+dfb212.getSize()+dfb220.getSize()+dfb221.getSize()+dfb222.getSize())/sizeof(Particle);
  int j = 0;
  Particle *p =  dfp.create<Particle>(np);
  { const Particle *b010 = dfb010.getData<Particle>();
    assert(dfb010.getSize() % sizeof(Particle) == 0);
    int np1 = dfb010.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b010[j1];
  }
  { const Particle *b011 = dfb011.getData<Particle>();
    assert(dfb011.getSize() % sizeof(Particle) == 0);
    int np1 = dfb011.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b011[j1];
  }
  { const Particle *b012 = dfb012.getData<Particle>();
    assert(dfb012.getSize() % sizeof(Particle) == 0);
    int np1 = dfb012.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b012[j1];
  }
  { const Particle *b020 = dfb020.getData<Particle>();
    assert(dfb020.getSize() % sizeof(Particle) == 0);
    int np1 = dfb020.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b020[j1];
  }
  { const Particle *b021 = dfb021.getData<Particle>();
    assert(dfb021.getSize() % sizeof(Particle) == 0);
    int np1 = dfb021.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b021[j1];
  }
  { const Particle *b022 = dfb022.getData<Particle>();
    assert(dfb022.getSize() % sizeof(Particle) == 0);
    int np1 = dfb022.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b022[j1];
  }
  { const Particle *b110 = dfb110.getData<Particle>();
    assert(dfb110.getSize() % sizeof(Particle) == 0);
    int np1 = dfb110.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b110[j1];
  }
  { const Particle *b111 = dfb111.getData<Particle>();
    assert(dfb111.getSize() % sizeof(Particle) == 0);
    int np1 = dfb111.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b111[j1];
  }
  { const Particle *b112 = dfb112.getData<Particle>();
    assert(dfb112.getSize() % sizeof(Particle) == 0);
    int np1 = dfb112.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b112[j1];
  }
  { const Particle *b120 = dfb120.getData<Particle>();
    assert(dfb120.getSize() % sizeof(Particle) == 0);
    int np1 = dfb120.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b120[j1];
  }
  { const Particle *b121 = dfb121.getData<Particle>();
    assert(dfb121.getSize() % sizeof(Particle) == 0);
    int np1 = dfb121.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b121[j1];
  }
  { const Particle *b122 = dfb122.getData<Particle>();
    assert(dfb122.getSize() % sizeof(Particle) == 0);
    int np1 = dfb122.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b122[j1];
  }
  { const Particle *b210 = dfb210.getData<Particle>();
    assert(dfb210.getSize() % sizeof(Particle) == 0);
    int np1 = dfb210.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b210[j1];
  }
  { const Particle *b211 = dfb211.getData<Particle>();
    assert(dfb211.getSize() % sizeof(Particle) == 0);
    int np1 = dfb211.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b211[j1];
  }
  { const Particle *b212 = dfb212.getData<Particle>();
    assert(dfb212.getSize() % sizeof(Particle) == 0);
    int np1 = dfb212.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b212[j1];
  }
  { const Particle *b220 = dfb220.getData<Particle>();
    assert(dfb220.getSize() % sizeof(Particle) == 0);
    int np1 = dfb220.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b220[j1];
  }
  { const Particle *b221 = dfb221.getData<Particle>();
    assert(dfb221.getSize() % sizeof(Particle) == 0);
    int np1 = dfb221.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b221[j1];
  }
  { const Particle *b222 = dfb222.getData<Particle>();
    assert(dfb222.getSize() % sizeof(Particle) == 0);
    int np1 = dfb222.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b222[j1];
  }
  dfnp.setValue(np);
}

void c_mesh3d_exchange_particles_27_get_11_10_00(int np,const InputDF &df_p,real x1,real y1,real z1,real x2,real y2,real z2,
  OutputDF &dfb001,OutputDF &dfb011,OutputDF &dfb101,OutputDF &dfb111,OutputDF &dfb201,OutputDF &dfb211)
{ int j;
  assert(df_p.getSize() == np*sizeof(Particle));
  const Particle *p = df_p.getData<Particle>();
  std::vector<Particle> vp[27];
  for (j=0;j<np;j++)
  {
    real x = p[j].x;
    real y = p[j].y;
    real z = p[j].z;
    real u = p[j].u;
    real v = p[j].v;
    real w = p[j].w;
    int code = 0;
    if (x<x1) code += 16;
    else if (x>=x2) code += 32;
    if (y<y1) code += 4;
    else if (y>=y2) { y = 2*y2-y; v = -v; }
    if (z<z1) { z = 2*z1-z; w = -w; }
    else if (z>=z2) { z = 2*z2-z; w = -w; }
    int dir = code2dir[code];
    vp[dir].push_back(Particle(x,y,z,u,v,w));
  }
  assert(vp[D000].size() == 0);
  { int np = vp[D001].size();
    int j1;
    Particle *b001 = dfb001.create<Particle>(np);
    for (j=0;j<np;j++) b001[j] = vp[D001][j];
  }
  assert(vp[D002].size() == 0);
  assert(vp[D010].size() == 0);
  { int np = vp[D011].size();
    int j1;
    Particle *b011 = dfb011.create<Particle>(np);
    for (j=0;j<np;j++) b011[j] = vp[D011][j];
  }
  assert(vp[D012].size() == 0);
  assert(vp[D020].size() == 0);
  assert(vp[D021].size() == 0);
  assert(vp[D022].size() == 0);
  assert(vp[D100].size() == 0);
  { int np = vp[D101].size();
    int j1;
    Particle *b101 = dfb101.create<Particle>(np);
    for (j=0;j<np;j++) b101[j] = vp[D101][j];
  }
  assert(vp[D102].size() == 0);
  assert(vp[D110].size() == 0);
  { int np = vp[D111].size();
    int j1;
    Particle *b111 = dfb111.create<Particle>(np);
    for (j=0;j<np;j++) b111[j] = vp[D111][j];
  }
  assert(vp[D112].size() == 0);
  assert(vp[D120].size() == 0);
  assert(vp[D121].size() == 0);
  assert(vp[D122].size() == 0);
  assert(vp[D200].size() == 0);
  { int np = vp[D201].size();
    int j1;
    Particle *b201 = dfb201.create<Particle>(np);
    for (j=0;j<np;j++) b201[j] = vp[D201][j];
  }
  assert(vp[D202].size() == 0);
  assert(vp[D210].size() == 0);
  { int np = vp[D211].size();
    int j1;
    Particle *b211 = dfb211.create<Particle>(np);
    for (j=0;j<np;j++) b211[j] = vp[D211][j];
  }
  assert(vp[D212].size() == 0);
  assert(vp[D220].size() == 0);
  assert(vp[D221].size() == 0);
  assert(vp[D222].size() == 0);
}

void c_mesh3d_exchange_particles_27_set_11_10_00(
  const InputDF &dfb001,const InputDF &dfb011,const InputDF &dfb101,const InputDF &dfb111,const InputDF &dfb201,const InputDF &dfb211,
  OutputDF &dfnp,OutputDF &dfp)
{ int np = (dfb001.getSize()+dfb011.getSize()+dfb101.getSize()+dfb111.getSize()+dfb201.getSize()+dfb211.getSize())/sizeof(Particle);
  int j = 0;
  Particle *p =  dfp.create<Particle>(np);
  { const Particle *b001 = dfb001.getData<Particle>();
    assert(dfb001.getSize() % sizeof(Particle) == 0);
    int np1 = dfb001.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b001[j1];
  }
  { const Particle *b011 = dfb011.getData<Particle>();
    assert(dfb011.getSize() % sizeof(Particle) == 0);
    int np1 = dfb011.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b011[j1];
  }
  { const Particle *b101 = dfb101.getData<Particle>();
    assert(dfb101.getSize() % sizeof(Particle) == 0);
    int np1 = dfb101.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b101[j1];
  }
  { const Particle *b111 = dfb111.getData<Particle>();
    assert(dfb111.getSize() % sizeof(Particle) == 0);
    int np1 = dfb111.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b111[j1];
  }
  { const Particle *b201 = dfb201.getData<Particle>();
    assert(dfb201.getSize() % sizeof(Particle) == 0);
    int np1 = dfb201.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b201[j1];
  }
  { const Particle *b211 = dfb211.getData<Particle>();
    assert(dfb211.getSize() % sizeof(Particle) == 0);
    int np1 = dfb211.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b211[j1];
  }
  dfnp.setValue(np);
}

void c_mesh3d_exchange_particles_27_get_11_10_01(int np,const InputDF &df_p,real x1,real y1,real z1,real x2,real y2,real z2,
  OutputDF &dfb001,OutputDF &dfb002,OutputDF &dfb011,OutputDF &dfb012,OutputDF &dfb101,OutputDF &dfb102,OutputDF &dfb111,OutputDF &dfb112,OutputDF &dfb201,OutputDF &dfb202,OutputDF &dfb211,OutputDF &dfb212)
{ int j;
  assert(df_p.getSize() == np*sizeof(Particle));
  const Particle *p = df_p.getData<Particle>();
  std::vector<Particle> vp[27];
  for (j=0;j<np;j++)
  {
    real x = p[j].x;
    real y = p[j].y;
    real z = p[j].z;
    real u = p[j].u;
    real v = p[j].v;
    real w = p[j].w;
    int code = 0;
    if (x<x1) code += 16;
    else if (x>=x2) code += 32;
    if (y<y1) code += 4;
    else if (y>=y2) { y = 2*y2-y; v = -v; }
    if (z<z1) { z = 2*z1-z; w = -w; }
    else if (z>=z2) code += 2;
    int dir = code2dir[code];
    vp[dir].push_back(Particle(x,y,z,u,v,w));
  }
  assert(vp[D000].size() == 0);
  { int np = vp[D001].size();
    int j1;
    Particle *b001 = dfb001.create<Particle>(np);
    for (j=0;j<np;j++) b001[j] = vp[D001][j];
  }
  { int np = vp[D002].size();
    int j1;
    Particle *b002 = dfb002.create<Particle>(np);
    for (j=0;j<np;j++) b002[j] = vp[D002][j];
  }
  assert(vp[D010].size() == 0);
  { int np = vp[D011].size();
    int j1;
    Particle *b011 = dfb011.create<Particle>(np);
    for (j=0;j<np;j++) b011[j] = vp[D011][j];
  }
  { int np = vp[D012].size();
    int j1;
    Particle *b012 = dfb012.create<Particle>(np);
    for (j=0;j<np;j++) b012[j] = vp[D012][j];
  }
  assert(vp[D020].size() == 0);
  assert(vp[D021].size() == 0);
  assert(vp[D022].size() == 0);
  assert(vp[D100].size() == 0);
  { int np = vp[D101].size();
    int j1;
    Particle *b101 = dfb101.create<Particle>(np);
    for (j=0;j<np;j++) b101[j] = vp[D101][j];
  }
  { int np = vp[D102].size();
    int j1;
    Particle *b102 = dfb102.create<Particle>(np);
    for (j=0;j<np;j++) b102[j] = vp[D102][j];
  }
  assert(vp[D110].size() == 0);
  { int np = vp[D111].size();
    int j1;
    Particle *b111 = dfb111.create<Particle>(np);
    for (j=0;j<np;j++) b111[j] = vp[D111][j];
  }
  { int np = vp[D112].size();
    int j1;
    Particle *b112 = dfb112.create<Particle>(np);
    for (j=0;j<np;j++) b112[j] = vp[D112][j];
  }
  assert(vp[D120].size() == 0);
  assert(vp[D121].size() == 0);
  assert(vp[D122].size() == 0);
  assert(vp[D200].size() == 0);
  { int np = vp[D201].size();
    int j1;
    Particle *b201 = dfb201.create<Particle>(np);
    for (j=0;j<np;j++) b201[j] = vp[D201][j];
  }
  { int np = vp[D202].size();
    int j1;
    Particle *b202 = dfb202.create<Particle>(np);
    for (j=0;j<np;j++) b202[j] = vp[D202][j];
  }
  assert(vp[D210].size() == 0);
  { int np = vp[D211].size();
    int j1;
    Particle *b211 = dfb211.create<Particle>(np);
    for (j=0;j<np;j++) b211[j] = vp[D211][j];
  }
  { int np = vp[D212].size();
    int j1;
    Particle *b212 = dfb212.create<Particle>(np);
    for (j=0;j<np;j++) b212[j] = vp[D212][j];
  }
  assert(vp[D220].size() == 0);
  assert(vp[D221].size() == 0);
  assert(vp[D222].size() == 0);
}

void c_mesh3d_exchange_particles_27_set_11_10_01(
  const InputDF &dfb001,const InputDF &dfb002,const InputDF &dfb011,const InputDF &dfb012,const InputDF &dfb101,const InputDF &dfb102,const InputDF &dfb111,const InputDF &dfb112,const InputDF &dfb201,const InputDF &dfb202,const InputDF &dfb211,const InputDF &dfb212,
  OutputDF &dfnp,OutputDF &dfp)
{ int np = (dfb001.getSize()+dfb002.getSize()+dfb011.getSize()+dfb012.getSize()+dfb101.getSize()+dfb102.getSize()+dfb111.getSize()+dfb112.getSize()+dfb201.getSize()+dfb202.getSize()+dfb211.getSize()+dfb212.getSize())/sizeof(Particle);
  int j = 0;
  Particle *p =  dfp.create<Particle>(np);
  { const Particle *b001 = dfb001.getData<Particle>();
    assert(dfb001.getSize() % sizeof(Particle) == 0);
    int np1 = dfb001.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b001[j1];
  }
  { const Particle *b002 = dfb002.getData<Particle>();
    assert(dfb002.getSize() % sizeof(Particle) == 0);
    int np1 = dfb002.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b002[j1];
  }
  { const Particle *b011 = dfb011.getData<Particle>();
    assert(dfb011.getSize() % sizeof(Particle) == 0);
    int np1 = dfb011.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b011[j1];
  }
  { const Particle *b012 = dfb012.getData<Particle>();
    assert(dfb012.getSize() % sizeof(Particle) == 0);
    int np1 = dfb012.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b012[j1];
  }
  { const Particle *b101 = dfb101.getData<Particle>();
    assert(dfb101.getSize() % sizeof(Particle) == 0);
    int np1 = dfb101.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b101[j1];
  }
  { const Particle *b102 = dfb102.getData<Particle>();
    assert(dfb102.getSize() % sizeof(Particle) == 0);
    int np1 = dfb102.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b102[j1];
  }
  { const Particle *b111 = dfb111.getData<Particle>();
    assert(dfb111.getSize() % sizeof(Particle) == 0);
    int np1 = dfb111.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b111[j1];
  }
  { const Particle *b112 = dfb112.getData<Particle>();
    assert(dfb112.getSize() % sizeof(Particle) == 0);
    int np1 = dfb112.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b112[j1];
  }
  { const Particle *b201 = dfb201.getData<Particle>();
    assert(dfb201.getSize() % sizeof(Particle) == 0);
    int np1 = dfb201.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b201[j1];
  }
  { const Particle *b202 = dfb202.getData<Particle>();
    assert(dfb202.getSize() % sizeof(Particle) == 0);
    int np1 = dfb202.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b202[j1];
  }
  { const Particle *b211 = dfb211.getData<Particle>();
    assert(dfb211.getSize() % sizeof(Particle) == 0);
    int np1 = dfb211.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b211[j1];
  }
  { const Particle *b212 = dfb212.getData<Particle>();
    assert(dfb212.getSize() % sizeof(Particle) == 0);
    int np1 = dfb212.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b212[j1];
  }
  dfnp.setValue(np);
}

void c_mesh3d_exchange_particles_27_get_11_10_10(int np,const InputDF &df_p,real x1,real y1,real z1,real x2,real y2,real z2,
  OutputDF &dfb000,OutputDF &dfb001,OutputDF &dfb010,OutputDF &dfb011,OutputDF &dfb100,OutputDF &dfb101,OutputDF &dfb110,OutputDF &dfb111,OutputDF &dfb200,OutputDF &dfb201,OutputDF &dfb210,OutputDF &dfb211)
{ int j;
  assert(df_p.getSize() == np*sizeof(Particle));
  const Particle *p = df_p.getData<Particle>();
  std::vector<Particle> vp[27];
  for (j=0;j<np;j++)
  {
    real x = p[j].x;
    real y = p[j].y;
    real z = p[j].z;
    real u = p[j].u;
    real v = p[j].v;
    real w = p[j].w;
    int code = 0;
    if (x<x1) code += 16;
    else if (x>=x2) code += 32;
    if (y<y1) code += 4;
    else if (y>=y2) { y = 2*y2-y; v = -v; }
    if (z<z1) code += 1;
    else if (z>=z2) { z = 2*z2-z; w = -w; }
    int dir = code2dir[code];
    vp[dir].push_back(Particle(x,y,z,u,v,w));
  }
  { int np = vp[D000].size();
    int j1;
    Particle *b000 = dfb000.create<Particle>(np);
    for (j=0;j<np;j++) b000[j] = vp[D000][j];
  }
  { int np = vp[D001].size();
    int j1;
    Particle *b001 = dfb001.create<Particle>(np);
    for (j=0;j<np;j++) b001[j] = vp[D001][j];
  }
  assert(vp[D002].size() == 0);
  { int np = vp[D010].size();
    int j1;
    Particle *b010 = dfb010.create<Particle>(np);
    for (j=0;j<np;j++) b010[j] = vp[D010][j];
  }
  { int np = vp[D011].size();
    int j1;
    Particle *b011 = dfb011.create<Particle>(np);
    for (j=0;j<np;j++) b011[j] = vp[D011][j];
  }
  assert(vp[D012].size() == 0);
  assert(vp[D020].size() == 0);
  assert(vp[D021].size() == 0);
  assert(vp[D022].size() == 0);
  { int np = vp[D100].size();
    int j1;
    Particle *b100 = dfb100.create<Particle>(np);
    for (j=0;j<np;j++) b100[j] = vp[D100][j];
  }
  { int np = vp[D101].size();
    int j1;
    Particle *b101 = dfb101.create<Particle>(np);
    for (j=0;j<np;j++) b101[j] = vp[D101][j];
  }
  assert(vp[D102].size() == 0);
  { int np = vp[D110].size();
    int j1;
    Particle *b110 = dfb110.create<Particle>(np);
    for (j=0;j<np;j++) b110[j] = vp[D110][j];
  }
  { int np = vp[D111].size();
    int j1;
    Particle *b111 = dfb111.create<Particle>(np);
    for (j=0;j<np;j++) b111[j] = vp[D111][j];
  }
  assert(vp[D112].size() == 0);
  assert(vp[D120].size() == 0);
  assert(vp[D121].size() == 0);
  assert(vp[D122].size() == 0);
  { int np = vp[D200].size();
    int j1;
    Particle *b200 = dfb200.create<Particle>(np);
    for (j=0;j<np;j++) b200[j] = vp[D200][j];
  }
  { int np = vp[D201].size();
    int j1;
    Particle *b201 = dfb201.create<Particle>(np);
    for (j=0;j<np;j++) b201[j] = vp[D201][j];
  }
  assert(vp[D202].size() == 0);
  { int np = vp[D210].size();
    int j1;
    Particle *b210 = dfb210.create<Particle>(np);
    for (j=0;j<np;j++) b210[j] = vp[D210][j];
  }
  { int np = vp[D211].size();
    int j1;
    Particle *b211 = dfb211.create<Particle>(np);
    for (j=0;j<np;j++) b211[j] = vp[D211][j];
  }
  assert(vp[D212].size() == 0);
  assert(vp[D220].size() == 0);
  assert(vp[D221].size() == 0);
  assert(vp[D222].size() == 0);
}

void c_mesh3d_exchange_particles_27_set_11_10_10(
  const InputDF &dfb000,const InputDF &dfb001,const InputDF &dfb010,const InputDF &dfb011,const InputDF &dfb100,const InputDF &dfb101,const InputDF &dfb110,const InputDF &dfb111,const InputDF &dfb200,const InputDF &dfb201,const InputDF &dfb210,const InputDF &dfb211,
  OutputDF &dfnp,OutputDF &dfp)
{ int np = (dfb000.getSize()+dfb001.getSize()+dfb010.getSize()+dfb011.getSize()+dfb100.getSize()+dfb101.getSize()+dfb110.getSize()+dfb111.getSize()+dfb200.getSize()+dfb201.getSize()+dfb210.getSize()+dfb211.getSize())/sizeof(Particle);
  int j = 0;
  Particle *p =  dfp.create<Particle>(np);
  { const Particle *b000 = dfb000.getData<Particle>();
    assert(dfb000.getSize() % sizeof(Particle) == 0);
    int np1 = dfb000.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b000[j1];
  }
  { const Particle *b001 = dfb001.getData<Particle>();
    assert(dfb001.getSize() % sizeof(Particle) == 0);
    int np1 = dfb001.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b001[j1];
  }
  { const Particle *b010 = dfb010.getData<Particle>();
    assert(dfb010.getSize() % sizeof(Particle) == 0);
    int np1 = dfb010.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b010[j1];
  }
  { const Particle *b011 = dfb011.getData<Particle>();
    assert(dfb011.getSize() % sizeof(Particle) == 0);
    int np1 = dfb011.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b011[j1];
  }
  { const Particle *b100 = dfb100.getData<Particle>();
    assert(dfb100.getSize() % sizeof(Particle) == 0);
    int np1 = dfb100.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b100[j1];
  }
  { const Particle *b101 = dfb101.getData<Particle>();
    assert(dfb101.getSize() % sizeof(Particle) == 0);
    int np1 = dfb101.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b101[j1];
  }
  { const Particle *b110 = dfb110.getData<Particle>();
    assert(dfb110.getSize() % sizeof(Particle) == 0);
    int np1 = dfb110.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b110[j1];
  }
  { const Particle *b111 = dfb111.getData<Particle>();
    assert(dfb111.getSize() % sizeof(Particle) == 0);
    int np1 = dfb111.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b111[j1];
  }
  { const Particle *b200 = dfb200.getData<Particle>();
    assert(dfb200.getSize() % sizeof(Particle) == 0);
    int np1 = dfb200.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b200[j1];
  }
  { const Particle *b201 = dfb201.getData<Particle>();
    assert(dfb201.getSize() % sizeof(Particle) == 0);
    int np1 = dfb201.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b201[j1];
  }
  { const Particle *b210 = dfb210.getData<Particle>();
    assert(dfb210.getSize() % sizeof(Particle) == 0);
    int np1 = dfb210.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b210[j1];
  }
  { const Particle *b211 = dfb211.getData<Particle>();
    assert(dfb211.getSize() % sizeof(Particle) == 0);
    int np1 = dfb211.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b211[j1];
  }
  dfnp.setValue(np);
}

void c_mesh3d_exchange_particles_27_get_11_10_11(int np,const InputDF &df_p,real x1,real y1,real z1,real x2,real y2,real z2,
  OutputDF &dfb000,OutputDF &dfb001,OutputDF &dfb002,OutputDF &dfb010,OutputDF &dfb011,OutputDF &dfb012,OutputDF &dfb100,OutputDF &dfb101,OutputDF &dfb102,OutputDF &dfb110,OutputDF &dfb111,OutputDF &dfb112,OutputDF &dfb200,OutputDF &dfb201,OutputDF &dfb202,OutputDF &dfb210,OutputDF &dfb211,OutputDF &dfb212)
{ int j;
  assert(df_p.getSize() == np*sizeof(Particle));
  const Particle *p = df_p.getData<Particle>();
  std::vector<Particle> vp[27];
  for (j=0;j<np;j++)
  {
    real x = p[j].x;
    real y = p[j].y;
    real z = p[j].z;
    real u = p[j].u;
    real v = p[j].v;
    real w = p[j].w;
    int code = 0;
    if (x<x1) code += 16;
    else if (x>=x2) code += 32;
    if (y<y1) code += 4;
    else if (y>=y2) { y = 2*y2-y; v = -v; }
    if (z<z1) code += 1;
    else if (z>=z2) code += 2;
    int dir = code2dir[code];
    vp[dir].push_back(Particle(x,y,z,u,v,w));
  }
  { int np = vp[D000].size();
    int j1;
    Particle *b000 = dfb000.create<Particle>(np);
    for (j=0;j<np;j++) b000[j] = vp[D000][j];
  }
  { int np = vp[D001].size();
    int j1;
    Particle *b001 = dfb001.create<Particle>(np);
    for (j=0;j<np;j++) b001[j] = vp[D001][j];
  }
  { int np = vp[D002].size();
    int j1;
    Particle *b002 = dfb002.create<Particle>(np);
    for (j=0;j<np;j++) b002[j] = vp[D002][j];
  }
  { int np = vp[D010].size();
    int j1;
    Particle *b010 = dfb010.create<Particle>(np);
    for (j=0;j<np;j++) b010[j] = vp[D010][j];
  }
  { int np = vp[D011].size();
    int j1;
    Particle *b011 = dfb011.create<Particle>(np);
    for (j=0;j<np;j++) b011[j] = vp[D011][j];
  }
  { int np = vp[D012].size();
    int j1;
    Particle *b012 = dfb012.create<Particle>(np);
    for (j=0;j<np;j++) b012[j] = vp[D012][j];
  }
  assert(vp[D020].size() == 0);
  assert(vp[D021].size() == 0);
  assert(vp[D022].size() == 0);
  { int np = vp[D100].size();
    int j1;
    Particle *b100 = dfb100.create<Particle>(np);
    for (j=0;j<np;j++) b100[j] = vp[D100][j];
  }
  { int np = vp[D101].size();
    int j1;
    Particle *b101 = dfb101.create<Particle>(np);
    for (j=0;j<np;j++) b101[j] = vp[D101][j];
  }
  { int np = vp[D102].size();
    int j1;
    Particle *b102 = dfb102.create<Particle>(np);
    for (j=0;j<np;j++) b102[j] = vp[D102][j];
  }
  { int np = vp[D110].size();
    int j1;
    Particle *b110 = dfb110.create<Particle>(np);
    for (j=0;j<np;j++) b110[j] = vp[D110][j];
  }
  { int np = vp[D111].size();
    int j1;
    Particle *b111 = dfb111.create<Particle>(np);
    for (j=0;j<np;j++) b111[j] = vp[D111][j];
  }
  { int np = vp[D112].size();
    int j1;
    Particle *b112 = dfb112.create<Particle>(np);
    for (j=0;j<np;j++) b112[j] = vp[D112][j];
  }
  assert(vp[D120].size() == 0);
  assert(vp[D121].size() == 0);
  assert(vp[D122].size() == 0);
  { int np = vp[D200].size();
    int j1;
    Particle *b200 = dfb200.create<Particle>(np);
    for (j=0;j<np;j++) b200[j] = vp[D200][j];
  }
  { int np = vp[D201].size();
    int j1;
    Particle *b201 = dfb201.create<Particle>(np);
    for (j=0;j<np;j++) b201[j] = vp[D201][j];
  }
  { int np = vp[D202].size();
    int j1;
    Particle *b202 = dfb202.create<Particle>(np);
    for (j=0;j<np;j++) b202[j] = vp[D202][j];
  }
  { int np = vp[D210].size();
    int j1;
    Particle *b210 = dfb210.create<Particle>(np);
    for (j=0;j<np;j++) b210[j] = vp[D210][j];
  }
  { int np = vp[D211].size();
    int j1;
    Particle *b211 = dfb211.create<Particle>(np);
    for (j=0;j<np;j++) b211[j] = vp[D211][j];
  }
  { int np = vp[D212].size();
    int j1;
    Particle *b212 = dfb212.create<Particle>(np);
    for (j=0;j<np;j++) b212[j] = vp[D212][j];
  }
  assert(vp[D220].size() == 0);
  assert(vp[D221].size() == 0);
  assert(vp[D222].size() == 0);
}

void c_mesh3d_exchange_particles_27_set_11_10_11(
  const InputDF &dfb000,const InputDF &dfb001,const InputDF &dfb002,const InputDF &dfb010,const InputDF &dfb011,const InputDF &dfb012,const InputDF &dfb100,const InputDF &dfb101,const InputDF &dfb102,const InputDF &dfb110,const InputDF &dfb111,const InputDF &dfb112,const InputDF &dfb200,const InputDF &dfb201,const InputDF &dfb202,const InputDF &dfb210,const InputDF &dfb211,const InputDF &dfb212,
  OutputDF &dfnp,OutputDF &dfp)
{ int np = (dfb000.getSize()+dfb001.getSize()+dfb002.getSize()+dfb010.getSize()+dfb011.getSize()+dfb012.getSize()+dfb100.getSize()+dfb101.getSize()+dfb102.getSize()+dfb110.getSize()+dfb111.getSize()+dfb112.getSize()+dfb200.getSize()+dfb201.getSize()+dfb202.getSize()+dfb210.getSize()+dfb211.getSize()+dfb212.getSize())/sizeof(Particle);
  int j = 0;
  Particle *p =  dfp.create<Particle>(np);
  { const Particle *b000 = dfb000.getData<Particle>();
    assert(dfb000.getSize() % sizeof(Particle) == 0);
    int np1 = dfb000.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b000[j1];
  }
  { const Particle *b001 = dfb001.getData<Particle>();
    assert(dfb001.getSize() % sizeof(Particle) == 0);
    int np1 = dfb001.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b001[j1];
  }
  { const Particle *b002 = dfb002.getData<Particle>();
    assert(dfb002.getSize() % sizeof(Particle) == 0);
    int np1 = dfb002.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b002[j1];
  }
  { const Particle *b010 = dfb010.getData<Particle>();
    assert(dfb010.getSize() % sizeof(Particle) == 0);
    int np1 = dfb010.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b010[j1];
  }
  { const Particle *b011 = dfb011.getData<Particle>();
    assert(dfb011.getSize() % sizeof(Particle) == 0);
    int np1 = dfb011.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b011[j1];
  }
  { const Particle *b012 = dfb012.getData<Particle>();
    assert(dfb012.getSize() % sizeof(Particle) == 0);
    int np1 = dfb012.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b012[j1];
  }
  { const Particle *b100 = dfb100.getData<Particle>();
    assert(dfb100.getSize() % sizeof(Particle) == 0);
    int np1 = dfb100.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b100[j1];
  }
  { const Particle *b101 = dfb101.getData<Particle>();
    assert(dfb101.getSize() % sizeof(Particle) == 0);
    int np1 = dfb101.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b101[j1];
  }
  { const Particle *b102 = dfb102.getData<Particle>();
    assert(dfb102.getSize() % sizeof(Particle) == 0);
    int np1 = dfb102.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b102[j1];
  }
  { const Particle *b110 = dfb110.getData<Particle>();
    assert(dfb110.getSize() % sizeof(Particle) == 0);
    int np1 = dfb110.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b110[j1];
  }
  { const Particle *b111 = dfb111.getData<Particle>();
    assert(dfb111.getSize() % sizeof(Particle) == 0);
    int np1 = dfb111.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b111[j1];
  }
  { const Particle *b112 = dfb112.getData<Particle>();
    assert(dfb112.getSize() % sizeof(Particle) == 0);
    int np1 = dfb112.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b112[j1];
  }
  { const Particle *b200 = dfb200.getData<Particle>();
    assert(dfb200.getSize() % sizeof(Particle) == 0);
    int np1 = dfb200.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b200[j1];
  }
  { const Particle *b201 = dfb201.getData<Particle>();
    assert(dfb201.getSize() % sizeof(Particle) == 0);
    int np1 = dfb201.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b201[j1];
  }
  { const Particle *b202 = dfb202.getData<Particle>();
    assert(dfb202.getSize() % sizeof(Particle) == 0);
    int np1 = dfb202.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b202[j1];
  }
  { const Particle *b210 = dfb210.getData<Particle>();
    assert(dfb210.getSize() % sizeof(Particle) == 0);
    int np1 = dfb210.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b210[j1];
  }
  { const Particle *b211 = dfb211.getData<Particle>();
    assert(dfb211.getSize() % sizeof(Particle) == 0);
    int np1 = dfb211.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b211[j1];
  }
  { const Particle *b212 = dfb212.getData<Particle>();
    assert(dfb212.getSize() % sizeof(Particle) == 0);
    int np1 = dfb212.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b212[j1];
  }
  dfnp.setValue(np);
}

void c_mesh3d_exchange_particles_27_get_11_11_00(int np,const InputDF &df_p,real x1,real y1,real z1,real x2,real y2,real z2,
  OutputDF &dfb001,OutputDF &dfb011,OutputDF &dfb021,OutputDF &dfb101,OutputDF &dfb111,OutputDF &dfb121,OutputDF &dfb201,OutputDF &dfb211,OutputDF &dfb221)
{ int j;
  assert(df_p.getSize() == np*sizeof(Particle));
  const Particle *p = df_p.getData<Particle>();
  std::vector<Particle> vp[27];
  for (j=0;j<np;j++)
  {
    real x = p[j].x;
    real y = p[j].y;
    real z = p[j].z;
    real u = p[j].u;
    real v = p[j].v;
    real w = p[j].w;
    int code = 0;
    if (x<x1) code += 16;
    else if (x>=x2) code += 32;
    if (y<y1) code += 4;
    else if (y>=y2) code += 8;
    if (z<z1) { z = 2*z1-z; w = -w; }
    else if (z>=z2) { z = 2*z2-z; w = -w; }
    int dir = code2dir[code];
    vp[dir].push_back(Particle(x,y,z,u,v,w));
  }
  assert(vp[D000].size() == 0);
  { int np = vp[D001].size();
    int j1;
    Particle *b001 = dfb001.create<Particle>(np);
    for (j=0;j<np;j++) b001[j] = vp[D001][j];
  }
  assert(vp[D002].size() == 0);
  assert(vp[D010].size() == 0);
  { int np = vp[D011].size();
    int j1;
    Particle *b011 = dfb011.create<Particle>(np);
    for (j=0;j<np;j++) b011[j] = vp[D011][j];
  }
  assert(vp[D012].size() == 0);
  assert(vp[D020].size() == 0);
  { int np = vp[D021].size();
    int j1;
    Particle *b021 = dfb021.create<Particle>(np);
    for (j=0;j<np;j++) b021[j] = vp[D021][j];
  }
  assert(vp[D022].size() == 0);
  assert(vp[D100].size() == 0);
  { int np = vp[D101].size();
    int j1;
    Particle *b101 = dfb101.create<Particle>(np);
    for (j=0;j<np;j++) b101[j] = vp[D101][j];
  }
  assert(vp[D102].size() == 0);
  assert(vp[D110].size() == 0);
  { int np = vp[D111].size();
    int j1;
    Particle *b111 = dfb111.create<Particle>(np);
    for (j=0;j<np;j++) b111[j] = vp[D111][j];
  }
  assert(vp[D112].size() == 0);
  assert(vp[D120].size() == 0);
  { int np = vp[D121].size();
    int j1;
    Particle *b121 = dfb121.create<Particle>(np);
    for (j=0;j<np;j++) b121[j] = vp[D121][j];
  }
  assert(vp[D122].size() == 0);
  assert(vp[D200].size() == 0);
  { int np = vp[D201].size();
    int j1;
    Particle *b201 = dfb201.create<Particle>(np);
    for (j=0;j<np;j++) b201[j] = vp[D201][j];
  }
  assert(vp[D202].size() == 0);
  assert(vp[D210].size() == 0);
  { int np = vp[D211].size();
    int j1;
    Particle *b211 = dfb211.create<Particle>(np);
    for (j=0;j<np;j++) b211[j] = vp[D211][j];
  }
  assert(vp[D212].size() == 0);
  assert(vp[D220].size() == 0);
  { int np = vp[D221].size();
    int j1;
    Particle *b221 = dfb221.create<Particle>(np);
    for (j=0;j<np;j++) b221[j] = vp[D221][j];
  }
  assert(vp[D222].size() == 0);
}

void c_mesh3d_exchange_particles_27_set_11_11_00(
  const InputDF &dfb001,const InputDF &dfb011,const InputDF &dfb021,const InputDF &dfb101,const InputDF &dfb111,const InputDF &dfb121,const InputDF &dfb201,const InputDF &dfb211,const InputDF &dfb221,
  OutputDF &dfnp,OutputDF &dfp)
{ int np = (dfb001.getSize()+dfb011.getSize()+dfb021.getSize()+dfb101.getSize()+dfb111.getSize()+dfb121.getSize()+dfb201.getSize()+dfb211.getSize()+dfb221.getSize())/sizeof(Particle);
  int j = 0;
  Particle *p =  dfp.create<Particle>(np);
  { const Particle *b001 = dfb001.getData<Particle>();
    assert(dfb001.getSize() % sizeof(Particle) == 0);
    int np1 = dfb001.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b001[j1];
  }
  { const Particle *b011 = dfb011.getData<Particle>();
    assert(dfb011.getSize() % sizeof(Particle) == 0);
    int np1 = dfb011.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b011[j1];
  }
  { const Particle *b021 = dfb021.getData<Particle>();
    assert(dfb021.getSize() % sizeof(Particle) == 0);
    int np1 = dfb021.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b021[j1];
  }
  { const Particle *b101 = dfb101.getData<Particle>();
    assert(dfb101.getSize() % sizeof(Particle) == 0);
    int np1 = dfb101.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b101[j1];
  }
  { const Particle *b111 = dfb111.getData<Particle>();
    assert(dfb111.getSize() % sizeof(Particle) == 0);
    int np1 = dfb111.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b111[j1];
  }
  { const Particle *b121 = dfb121.getData<Particle>();
    assert(dfb121.getSize() % sizeof(Particle) == 0);
    int np1 = dfb121.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b121[j1];
  }
  { const Particle *b201 = dfb201.getData<Particle>();
    assert(dfb201.getSize() % sizeof(Particle) == 0);
    int np1 = dfb201.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b201[j1];
  }
  { const Particle *b211 = dfb211.getData<Particle>();
    assert(dfb211.getSize() % sizeof(Particle) == 0);
    int np1 = dfb211.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b211[j1];
  }
  { const Particle *b221 = dfb221.getData<Particle>();
    assert(dfb221.getSize() % sizeof(Particle) == 0);
    int np1 = dfb221.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b221[j1];
  }
  dfnp.setValue(np);
}

void c_mesh3d_exchange_particles_27_get_11_11_01(int np,const InputDF &df_p,real x1,real y1,real z1,real x2,real y2,real z2,
  OutputDF &dfb001,OutputDF &dfb002,OutputDF &dfb011,OutputDF &dfb012,OutputDF &dfb021,OutputDF &dfb022,OutputDF &dfb101,OutputDF &dfb102,OutputDF &dfb111,OutputDF &dfb112,OutputDF &dfb121,OutputDF &dfb122,OutputDF &dfb201,OutputDF &dfb202,OutputDF &dfb211,OutputDF &dfb212,OutputDF &dfb221,OutputDF &dfb222)
{ int j;
  assert(df_p.getSize() == np*sizeof(Particle));
  const Particle *p = df_p.getData<Particle>();
  std::vector<Particle> vp[27];
  for (j=0;j<np;j++)
  {
    real x = p[j].x;
    real y = p[j].y;
    real z = p[j].z;
    real u = p[j].u;
    real v = p[j].v;
    real w = p[j].w;
    int code = 0;
    if (x<x1) code += 16;
    else if (x>=x2) code += 32;
    if (y<y1) code += 4;
    else if (y>=y2) code += 8;
    if (z<z1) { z = 2*z1-z; w = -w; }
    else if (z>=z2) code += 2;
    int dir = code2dir[code];
    vp[dir].push_back(Particle(x,y,z,u,v,w));
  }
  assert(vp[D000].size() == 0);
  { int np = vp[D001].size();
    int j1;
    Particle *b001 = dfb001.create<Particle>(np);
    for (j=0;j<np;j++) b001[j] = vp[D001][j];
  }
  { int np = vp[D002].size();
    int j1;
    Particle *b002 = dfb002.create<Particle>(np);
    for (j=0;j<np;j++) b002[j] = vp[D002][j];
  }
  assert(vp[D010].size() == 0);
  { int np = vp[D011].size();
    int j1;
    Particle *b011 = dfb011.create<Particle>(np);
    for (j=0;j<np;j++) b011[j] = vp[D011][j];
  }
  { int np = vp[D012].size();
    int j1;
    Particle *b012 = dfb012.create<Particle>(np);
    for (j=0;j<np;j++) b012[j] = vp[D012][j];
  }
  assert(vp[D020].size() == 0);
  { int np = vp[D021].size();
    int j1;
    Particle *b021 = dfb021.create<Particle>(np);
    for (j=0;j<np;j++) b021[j] = vp[D021][j];
  }
  { int np = vp[D022].size();
    int j1;
    Particle *b022 = dfb022.create<Particle>(np);
    for (j=0;j<np;j++) b022[j] = vp[D022][j];
  }
  assert(vp[D100].size() == 0);
  { int np = vp[D101].size();
    int j1;
    Particle *b101 = dfb101.create<Particle>(np);
    for (j=0;j<np;j++) b101[j] = vp[D101][j];
  }
  { int np = vp[D102].size();
    int j1;
    Particle *b102 = dfb102.create<Particle>(np);
    for (j=0;j<np;j++) b102[j] = vp[D102][j];
  }
  assert(vp[D110].size() == 0);
  { int np = vp[D111].size();
    int j1;
    Particle *b111 = dfb111.create<Particle>(np);
    for (j=0;j<np;j++) b111[j] = vp[D111][j];
  }
  { int np = vp[D112].size();
    int j1;
    Particle *b112 = dfb112.create<Particle>(np);
    for (j=0;j<np;j++) b112[j] = vp[D112][j];
  }
  assert(vp[D120].size() == 0);
  { int np = vp[D121].size();
    int j1;
    Particle *b121 = dfb121.create<Particle>(np);
    for (j=0;j<np;j++) b121[j] = vp[D121][j];
  }
  { int np = vp[D122].size();
    int j1;
    Particle *b122 = dfb122.create<Particle>(np);
    for (j=0;j<np;j++) b122[j] = vp[D122][j];
  }
  assert(vp[D200].size() == 0);
  { int np = vp[D201].size();
    int j1;
    Particle *b201 = dfb201.create<Particle>(np);
    for (j=0;j<np;j++) b201[j] = vp[D201][j];
  }
  { int np = vp[D202].size();
    int j1;
    Particle *b202 = dfb202.create<Particle>(np);
    for (j=0;j<np;j++) b202[j] = vp[D202][j];
  }
  assert(vp[D210].size() == 0);
  { int np = vp[D211].size();
    int j1;
    Particle *b211 = dfb211.create<Particle>(np);
    for (j=0;j<np;j++) b211[j] = vp[D211][j];
  }
  { int np = vp[D212].size();
    int j1;
    Particle *b212 = dfb212.create<Particle>(np);
    for (j=0;j<np;j++) b212[j] = vp[D212][j];
  }
  assert(vp[D220].size() == 0);
  { int np = vp[D221].size();
    int j1;
    Particle *b221 = dfb221.create<Particle>(np);
    for (j=0;j<np;j++) b221[j] = vp[D221][j];
  }
  { int np = vp[D222].size();
    int j1;
    Particle *b222 = dfb222.create<Particle>(np);
    for (j=0;j<np;j++) b222[j] = vp[D222][j];
  }
}

void c_mesh3d_exchange_particles_27_set_11_11_01(
  const InputDF &dfb001,const InputDF &dfb002,const InputDF &dfb011,const InputDF &dfb012,const InputDF &dfb021,const InputDF &dfb022,const InputDF &dfb101,const InputDF &dfb102,const InputDF &dfb111,const InputDF &dfb112,const InputDF &dfb121,const InputDF &dfb122,const InputDF &dfb201,const InputDF &dfb202,const InputDF &dfb211,const InputDF &dfb212,const InputDF &dfb221,const InputDF &dfb222,
  OutputDF &dfnp,OutputDF &dfp)
{ int np = (dfb001.getSize()+dfb002.getSize()+dfb011.getSize()+dfb012.getSize()+dfb021.getSize()+dfb022.getSize()+dfb101.getSize()+dfb102.getSize()+dfb111.getSize()+dfb112.getSize()+dfb121.getSize()+dfb122.getSize()+dfb201.getSize()+dfb202.getSize()+dfb211.getSize()+dfb212.getSize()+dfb221.getSize()+dfb222.getSize())/sizeof(Particle);
  int j = 0;
  Particle *p =  dfp.create<Particle>(np);
  { const Particle *b001 = dfb001.getData<Particle>();
    assert(dfb001.getSize() % sizeof(Particle) == 0);
    int np1 = dfb001.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b001[j1];
  }
  { const Particle *b002 = dfb002.getData<Particle>();
    assert(dfb002.getSize() % sizeof(Particle) == 0);
    int np1 = dfb002.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b002[j1];
  }
  { const Particle *b011 = dfb011.getData<Particle>();
    assert(dfb011.getSize() % sizeof(Particle) == 0);
    int np1 = dfb011.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b011[j1];
  }
  { const Particle *b012 = dfb012.getData<Particle>();
    assert(dfb012.getSize() % sizeof(Particle) == 0);
    int np1 = dfb012.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b012[j1];
  }
  { const Particle *b021 = dfb021.getData<Particle>();
    assert(dfb021.getSize() % sizeof(Particle) == 0);
    int np1 = dfb021.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b021[j1];
  }
  { const Particle *b022 = dfb022.getData<Particle>();
    assert(dfb022.getSize() % sizeof(Particle) == 0);
    int np1 = dfb022.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b022[j1];
  }
  { const Particle *b101 = dfb101.getData<Particle>();
    assert(dfb101.getSize() % sizeof(Particle) == 0);
    int np1 = dfb101.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b101[j1];
  }
  { const Particle *b102 = dfb102.getData<Particle>();
    assert(dfb102.getSize() % sizeof(Particle) == 0);
    int np1 = dfb102.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b102[j1];
  }
  { const Particle *b111 = dfb111.getData<Particle>();
    assert(dfb111.getSize() % sizeof(Particle) == 0);
    int np1 = dfb111.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b111[j1];
  }
  { const Particle *b112 = dfb112.getData<Particle>();
    assert(dfb112.getSize() % sizeof(Particle) == 0);
    int np1 = dfb112.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b112[j1];
  }
  { const Particle *b121 = dfb121.getData<Particle>();
    assert(dfb121.getSize() % sizeof(Particle) == 0);
    int np1 = dfb121.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b121[j1];
  }
  { const Particle *b122 = dfb122.getData<Particle>();
    assert(dfb122.getSize() % sizeof(Particle) == 0);
    int np1 = dfb122.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b122[j1];
  }
  { const Particle *b201 = dfb201.getData<Particle>();
    assert(dfb201.getSize() % sizeof(Particle) == 0);
    int np1 = dfb201.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b201[j1];
  }
  { const Particle *b202 = dfb202.getData<Particle>();
    assert(dfb202.getSize() % sizeof(Particle) == 0);
    int np1 = dfb202.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b202[j1];
  }
  { const Particle *b211 = dfb211.getData<Particle>();
    assert(dfb211.getSize() % sizeof(Particle) == 0);
    int np1 = dfb211.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b211[j1];
  }
  { const Particle *b212 = dfb212.getData<Particle>();
    assert(dfb212.getSize() % sizeof(Particle) == 0);
    int np1 = dfb212.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b212[j1];
  }
  { const Particle *b221 = dfb221.getData<Particle>();
    assert(dfb221.getSize() % sizeof(Particle) == 0);
    int np1 = dfb221.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b221[j1];
  }
  { const Particle *b222 = dfb222.getData<Particle>();
    assert(dfb222.getSize() % sizeof(Particle) == 0);
    int np1 = dfb222.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b222[j1];
  }
  dfnp.setValue(np);
}

void c_mesh3d_exchange_particles_27_get_11_11_10(int np,const InputDF &df_p,real x1,real y1,real z1,real x2,real y2,real z2,
  OutputDF &dfb000,OutputDF &dfb001,OutputDF &dfb010,OutputDF &dfb011,OutputDF &dfb020,OutputDF &dfb021,OutputDF &dfb100,OutputDF &dfb101,OutputDF &dfb110,OutputDF &dfb111,OutputDF &dfb120,OutputDF &dfb121,OutputDF &dfb200,OutputDF &dfb201,OutputDF &dfb210,OutputDF &dfb211,OutputDF &dfb220,OutputDF &dfb221)
{ int j;
  assert(df_p.getSize() == np*sizeof(Particle));
  const Particle *p = df_p.getData<Particle>();
  std::vector<Particle> vp[27];
  for (j=0;j<np;j++)
  {
    real x = p[j].x;
    real y = p[j].y;
    real z = p[j].z;
    real u = p[j].u;
    real v = p[j].v;
    real w = p[j].w;
    int code = 0;
    if (x<x1) code += 16;
    else if (x>=x2) code += 32;
    if (y<y1) code += 4;
    else if (y>=y2) code += 8;
    if (z<z1) code += 1;
    else if (z>=z2) { z = 2*z2-z; w = -w; }
    int dir = code2dir[code];
    vp[dir].push_back(Particle(x,y,z,u,v,w));
  }
  { int np = vp[D000].size();
    int j1;
    Particle *b000 = dfb000.create<Particle>(np);
    for (j=0;j<np;j++) b000[j] = vp[D000][j];
  }
  { int np = vp[D001].size();
    int j1;
    Particle *b001 = dfb001.create<Particle>(np);
    for (j=0;j<np;j++) b001[j] = vp[D001][j];
  }
  assert(vp[D002].size() == 0);
  { int np = vp[D010].size();
    int j1;
    Particle *b010 = dfb010.create<Particle>(np);
    for (j=0;j<np;j++) b010[j] = vp[D010][j];
  }
  { int np = vp[D011].size();
    int j1;
    Particle *b011 = dfb011.create<Particle>(np);
    for (j=0;j<np;j++) b011[j] = vp[D011][j];
  }
  assert(vp[D012].size() == 0);
  { int np = vp[D020].size();
    int j1;
    Particle *b020 = dfb020.create<Particle>(np);
    for (j=0;j<np;j++) b020[j] = vp[D020][j];
  }
  { int np = vp[D021].size();
    int j1;
    Particle *b021 = dfb021.create<Particle>(np);
    for (j=0;j<np;j++) b021[j] = vp[D021][j];
  }
  assert(vp[D022].size() == 0);
  { int np = vp[D100].size();
    int j1;
    Particle *b100 = dfb100.create<Particle>(np);
    for (j=0;j<np;j++) b100[j] = vp[D100][j];
  }
  { int np = vp[D101].size();
    int j1;
    Particle *b101 = dfb101.create<Particle>(np);
    for (j=0;j<np;j++) b101[j] = vp[D101][j];
  }
  assert(vp[D102].size() == 0);
  { int np = vp[D110].size();
    int j1;
    Particle *b110 = dfb110.create<Particle>(np);
    for (j=0;j<np;j++) b110[j] = vp[D110][j];
  }
  { int np = vp[D111].size();
    int j1;
    Particle *b111 = dfb111.create<Particle>(np);
    for (j=0;j<np;j++) b111[j] = vp[D111][j];
  }
  assert(vp[D112].size() == 0);
  { int np = vp[D120].size();
    int j1;
    Particle *b120 = dfb120.create<Particle>(np);
    for (j=0;j<np;j++) b120[j] = vp[D120][j];
  }
  { int np = vp[D121].size();
    int j1;
    Particle *b121 = dfb121.create<Particle>(np);
    for (j=0;j<np;j++) b121[j] = vp[D121][j];
  }
  assert(vp[D122].size() == 0);
  { int np = vp[D200].size();
    int j1;
    Particle *b200 = dfb200.create<Particle>(np);
    for (j=0;j<np;j++) b200[j] = vp[D200][j];
  }
  { int np = vp[D201].size();
    int j1;
    Particle *b201 = dfb201.create<Particle>(np);
    for (j=0;j<np;j++) b201[j] = vp[D201][j];
  }
  assert(vp[D202].size() == 0);
  { int np = vp[D210].size();
    int j1;
    Particle *b210 = dfb210.create<Particle>(np);
    for (j=0;j<np;j++) b210[j] = vp[D210][j];
  }
  { int np = vp[D211].size();
    int j1;
    Particle *b211 = dfb211.create<Particle>(np);
    for (j=0;j<np;j++) b211[j] = vp[D211][j];
  }
  assert(vp[D212].size() == 0);
  { int np = vp[D220].size();
    int j1;
    Particle *b220 = dfb220.create<Particle>(np);
    for (j=0;j<np;j++) b220[j] = vp[D220][j];
  }
  { int np = vp[D221].size();
    int j1;
    Particle *b221 = dfb221.create<Particle>(np);
    for (j=0;j<np;j++) b221[j] = vp[D221][j];
  }
  assert(vp[D222].size() == 0);
}

void c_mesh3d_exchange_particles_27_set_11_11_10(
  const InputDF &dfb000,const InputDF &dfb001,const InputDF &dfb010,const InputDF &dfb011,const InputDF &dfb020,const InputDF &dfb021,const InputDF &dfb100,const InputDF &dfb101,const InputDF &dfb110,const InputDF &dfb111,const InputDF &dfb120,const InputDF &dfb121,const InputDF &dfb200,const InputDF &dfb201,const InputDF &dfb210,const InputDF &dfb211,const InputDF &dfb220,const InputDF &dfb221,
  OutputDF &dfnp,OutputDF &dfp)
{ int np = (dfb000.getSize()+dfb001.getSize()+dfb010.getSize()+dfb011.getSize()+dfb020.getSize()+dfb021.getSize()+dfb100.getSize()+dfb101.getSize()+dfb110.getSize()+dfb111.getSize()+dfb120.getSize()+dfb121.getSize()+dfb200.getSize()+dfb201.getSize()+dfb210.getSize()+dfb211.getSize()+dfb220.getSize()+dfb221.getSize())/sizeof(Particle);
  int j = 0;
  Particle *p =  dfp.create<Particle>(np);
  { const Particle *b000 = dfb000.getData<Particle>();
    assert(dfb000.getSize() % sizeof(Particle) == 0);
    int np1 = dfb000.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b000[j1];
  }
  { const Particle *b001 = dfb001.getData<Particle>();
    assert(dfb001.getSize() % sizeof(Particle) == 0);
    int np1 = dfb001.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b001[j1];
  }
  { const Particle *b010 = dfb010.getData<Particle>();
    assert(dfb010.getSize() % sizeof(Particle) == 0);
    int np1 = dfb010.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b010[j1];
  }
  { const Particle *b011 = dfb011.getData<Particle>();
    assert(dfb011.getSize() % sizeof(Particle) == 0);
    int np1 = dfb011.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b011[j1];
  }
  { const Particle *b020 = dfb020.getData<Particle>();
    assert(dfb020.getSize() % sizeof(Particle) == 0);
    int np1 = dfb020.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b020[j1];
  }
  { const Particle *b021 = dfb021.getData<Particle>();
    assert(dfb021.getSize() % sizeof(Particle) == 0);
    int np1 = dfb021.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b021[j1];
  }
  { const Particle *b100 = dfb100.getData<Particle>();
    assert(dfb100.getSize() % sizeof(Particle) == 0);
    int np1 = dfb100.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b100[j1];
  }
  { const Particle *b101 = dfb101.getData<Particle>();
    assert(dfb101.getSize() % sizeof(Particle) == 0);
    int np1 = dfb101.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b101[j1];
  }
  { const Particle *b110 = dfb110.getData<Particle>();
    assert(dfb110.getSize() % sizeof(Particle) == 0);
    int np1 = dfb110.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b110[j1];
  }
  { const Particle *b111 = dfb111.getData<Particle>();
    assert(dfb111.getSize() % sizeof(Particle) == 0);
    int np1 = dfb111.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b111[j1];
  }
  { const Particle *b120 = dfb120.getData<Particle>();
    assert(dfb120.getSize() % sizeof(Particle) == 0);
    int np1 = dfb120.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b120[j1];
  }
  { const Particle *b121 = dfb121.getData<Particle>();
    assert(dfb121.getSize() % sizeof(Particle) == 0);
    int np1 = dfb121.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b121[j1];
  }
  { const Particle *b200 = dfb200.getData<Particle>();
    assert(dfb200.getSize() % sizeof(Particle) == 0);
    int np1 = dfb200.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b200[j1];
  }
  { const Particle *b201 = dfb201.getData<Particle>();
    assert(dfb201.getSize() % sizeof(Particle) == 0);
    int np1 = dfb201.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b201[j1];
  }
  { const Particle *b210 = dfb210.getData<Particle>();
    assert(dfb210.getSize() % sizeof(Particle) == 0);
    int np1 = dfb210.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b210[j1];
  }
  { const Particle *b211 = dfb211.getData<Particle>();
    assert(dfb211.getSize() % sizeof(Particle) == 0);
    int np1 = dfb211.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b211[j1];
  }
  { const Particle *b220 = dfb220.getData<Particle>();
    assert(dfb220.getSize() % sizeof(Particle) == 0);
    int np1 = dfb220.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b220[j1];
  }
  { const Particle *b221 = dfb221.getData<Particle>();
    assert(dfb221.getSize() % sizeof(Particle) == 0);
    int np1 = dfb221.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b221[j1];
  }
  dfnp.setValue(np);
}

void c_mesh3d_exchange_particles_27_get_11_11_11(int np,const InputDF &df_p,real x1,real y1,real z1,real x2,real y2,real z2,
  OutputDF &dfb000,OutputDF &dfb001,OutputDF &dfb002,OutputDF &dfb010,OutputDF &dfb011,OutputDF &dfb012,OutputDF &dfb020,OutputDF &dfb021,OutputDF &dfb022,OutputDF &dfb100,OutputDF &dfb101,OutputDF &dfb102,OutputDF &dfb110,OutputDF &dfb111,OutputDF &dfb112,OutputDF &dfb120,OutputDF &dfb121,OutputDF &dfb122,OutputDF &dfb200,OutputDF &dfb201,OutputDF &dfb202,OutputDF &dfb210,OutputDF &dfb211,OutputDF &dfb212,OutputDF &dfb220,OutputDF &dfb221,OutputDF &dfb222)
{ int j;
  assert(df_p.getSize() == np*sizeof(Particle));
  const Particle *p = df_p.getData<Particle>();
  std::vector<Particle> vp[27];
  for (j=0;j<np;j++)
  {
    real x = p[j].x;
    real y = p[j].y;
    real z = p[j].z;
    real u = p[j].u;
    real v = p[j].v;
    real w = p[j].w;
    int code = 0;
    if (x<x1) code += 16;
    else if (x>=x2) code += 32;
    if (y<y1) code += 4;
    else if (y>=y2) code += 8;
    if (z<z1) code += 1;
    else if (z>=z2) code += 2;
    int dir = code2dir[code];
    vp[dir].push_back(Particle(x,y,z,u,v,w));
  }
  { int np = vp[D000].size();
    int j1;
    Particle *b000 = dfb000.create<Particle>(np);
    for (j=0;j<np;j++) b000[j] = vp[D000][j];
  }
  { int np = vp[D001].size();
    int j1;
    Particle *b001 = dfb001.create<Particle>(np);
    for (j=0;j<np;j++) b001[j] = vp[D001][j];
  }
  { int np = vp[D002].size();
    int j1;
    Particle *b002 = dfb002.create<Particle>(np);
    for (j=0;j<np;j++) b002[j] = vp[D002][j];
  }
  { int np = vp[D010].size();
    int j1;
    Particle *b010 = dfb010.create<Particle>(np);
    for (j=0;j<np;j++) b010[j] = vp[D010][j];
  }
  { int np = vp[D011].size();
    int j1;
    Particle *b011 = dfb011.create<Particle>(np);
    for (j=0;j<np;j++) b011[j] = vp[D011][j];
  }
  { int np = vp[D012].size();
    int j1;
    Particle *b012 = dfb012.create<Particle>(np);
    for (j=0;j<np;j++) b012[j] = vp[D012][j];
  }
  { int np = vp[D020].size();
    int j1;
    Particle *b020 = dfb020.create<Particle>(np);
    for (j=0;j<np;j++) b020[j] = vp[D020][j];
  }
  { int np = vp[D021].size();
    int j1;
    Particle *b021 = dfb021.create<Particle>(np);
    for (j=0;j<np;j++) b021[j] = vp[D021][j];
  }
  { int np = vp[D022].size();
    int j1;
    Particle *b022 = dfb022.create<Particle>(np);
    for (j=0;j<np;j++) b022[j] = vp[D022][j];
  }
  { int np = vp[D100].size();
    int j1;
    Particle *b100 = dfb100.create<Particle>(np);
    for (j=0;j<np;j++) b100[j] = vp[D100][j];
  }
  { int np = vp[D101].size();
    int j1;
    Particle *b101 = dfb101.create<Particle>(np);
    for (j=0;j<np;j++) b101[j] = vp[D101][j];
  }
  { int np = vp[D102].size();
    int j1;
    Particle *b102 = dfb102.create<Particle>(np);
    for (j=0;j<np;j++) b102[j] = vp[D102][j];
  }
  { int np = vp[D110].size();
    int j1;
    Particle *b110 = dfb110.create<Particle>(np);
    for (j=0;j<np;j++) b110[j] = vp[D110][j];
  }
  { int np = vp[D111].size();
    int j1;
    Particle *b111 = dfb111.create<Particle>(np);
    for (j=0;j<np;j++) b111[j] = vp[D111][j];
  }
  { int np = vp[D112].size();
    int j1;
    Particle *b112 = dfb112.create<Particle>(np);
    for (j=0;j<np;j++) b112[j] = vp[D112][j];
  }
  { int np = vp[D120].size();
    int j1;
    Particle *b120 = dfb120.create<Particle>(np);
    for (j=0;j<np;j++) b120[j] = vp[D120][j];
  }
  { int np = vp[D121].size();
    int j1;
    Particle *b121 = dfb121.create<Particle>(np);
    for (j=0;j<np;j++) b121[j] = vp[D121][j];
  }
  { int np = vp[D122].size();
    int j1;
    Particle *b122 = dfb122.create<Particle>(np);
    for (j=0;j<np;j++) b122[j] = vp[D122][j];
  }
  { int np = vp[D200].size();
    int j1;
    Particle *b200 = dfb200.create<Particle>(np);
    for (j=0;j<np;j++) b200[j] = vp[D200][j];
  }
  { int np = vp[D201].size();
    int j1;
    Particle *b201 = dfb201.create<Particle>(np);
    for (j=0;j<np;j++) b201[j] = vp[D201][j];
  }
  { int np = vp[D202].size();
    int j1;
    Particle *b202 = dfb202.create<Particle>(np);
    for (j=0;j<np;j++) b202[j] = vp[D202][j];
  }
  { int np = vp[D210].size();
    int j1;
    Particle *b210 = dfb210.create<Particle>(np);
    for (j=0;j<np;j++) b210[j] = vp[D210][j];
  }
  { int np = vp[D211].size();
    int j1;
    Particle *b211 = dfb211.create<Particle>(np);
    for (j=0;j<np;j++) b211[j] = vp[D211][j];
  }
  { int np = vp[D212].size();
    int j1;
    Particle *b212 = dfb212.create<Particle>(np);
    for (j=0;j<np;j++) b212[j] = vp[D212][j];
  }
  { int np = vp[D220].size();
    int j1;
    Particle *b220 = dfb220.create<Particle>(np);
    for (j=0;j<np;j++) b220[j] = vp[D220][j];
  }
  { int np = vp[D221].size();
    int j1;
    Particle *b221 = dfb221.create<Particle>(np);
    for (j=0;j<np;j++) b221[j] = vp[D221][j];
  }
  { int np = vp[D222].size();
    int j1;
    Particle *b222 = dfb222.create<Particle>(np);
    for (j=0;j<np;j++) b222[j] = vp[D222][j];
  }
}

void c_mesh3d_exchange_particles_27_set_11_11_11(
  const InputDF &dfb000,const InputDF &dfb001,const InputDF &dfb002,const InputDF &dfb010,const InputDF &dfb011,const InputDF &dfb012,const InputDF &dfb020,const InputDF &dfb021,const InputDF &dfb022,const InputDF &dfb100,const InputDF &dfb101,const InputDF &dfb102,const InputDF &dfb110,const InputDF &dfb111,const InputDF &dfb112,const InputDF &dfb120,const InputDF &dfb121,const InputDF &dfb122,const InputDF &dfb200,const InputDF &dfb201,const InputDF &dfb202,const InputDF &dfb210,const InputDF &dfb211,const InputDF &dfb212,const InputDF &dfb220,const InputDF &dfb221,const InputDF &dfb222,
  OutputDF &dfnp,OutputDF &dfp)
{ int np = (dfb000.getSize()+dfb001.getSize()+dfb002.getSize()+dfb010.getSize()+dfb011.getSize()+dfb012.getSize()+dfb020.getSize()+dfb021.getSize()+dfb022.getSize()+dfb100.getSize()+dfb101.getSize()+dfb102.getSize()+dfb110.getSize()+dfb111.getSize()+dfb112.getSize()+dfb120.getSize()+dfb121.getSize()+dfb122.getSize()+dfb200.getSize()+dfb201.getSize()+dfb202.getSize()+dfb210.getSize()+dfb211.getSize()+dfb212.getSize()+dfb220.getSize()+dfb221.getSize()+dfb222.getSize())/sizeof(Particle);
  int j = 0;
  Particle *p =  dfp.create<Particle>(np);
  { const Particle *b000 = dfb000.getData<Particle>();
    assert(dfb000.getSize() % sizeof(Particle) == 0);
    int np1 = dfb000.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b000[j1];
  }
  { const Particle *b001 = dfb001.getData<Particle>();
    assert(dfb001.getSize() % sizeof(Particle) == 0);
    int np1 = dfb001.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b001[j1];
  }
  { const Particle *b002 = dfb002.getData<Particle>();
    assert(dfb002.getSize() % sizeof(Particle) == 0);
    int np1 = dfb002.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b002[j1];
  }
  { const Particle *b010 = dfb010.getData<Particle>();
    assert(dfb010.getSize() % sizeof(Particle) == 0);
    int np1 = dfb010.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b010[j1];
  }
  { const Particle *b011 = dfb011.getData<Particle>();
    assert(dfb011.getSize() % sizeof(Particle) == 0);
    int np1 = dfb011.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b011[j1];
  }
  { const Particle *b012 = dfb012.getData<Particle>();
    assert(dfb012.getSize() % sizeof(Particle) == 0);
    int np1 = dfb012.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b012[j1];
  }
  { const Particle *b020 = dfb020.getData<Particle>();
    assert(dfb020.getSize() % sizeof(Particle) == 0);
    int np1 = dfb020.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b020[j1];
  }
  { const Particle *b021 = dfb021.getData<Particle>();
    assert(dfb021.getSize() % sizeof(Particle) == 0);
    int np1 = dfb021.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b021[j1];
  }
  { const Particle *b022 = dfb022.getData<Particle>();
    assert(dfb022.getSize() % sizeof(Particle) == 0);
    int np1 = dfb022.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b022[j1];
  }
  { const Particle *b100 = dfb100.getData<Particle>();
    assert(dfb100.getSize() % sizeof(Particle) == 0);
    int np1 = dfb100.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b100[j1];
  }
  { const Particle *b101 = dfb101.getData<Particle>();
    assert(dfb101.getSize() % sizeof(Particle) == 0);
    int np1 = dfb101.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b101[j1];
  }
  { const Particle *b102 = dfb102.getData<Particle>();
    assert(dfb102.getSize() % sizeof(Particle) == 0);
    int np1 = dfb102.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b102[j1];
  }
  { const Particle *b110 = dfb110.getData<Particle>();
    assert(dfb110.getSize() % sizeof(Particle) == 0);
    int np1 = dfb110.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b110[j1];
  }
  { const Particle *b111 = dfb111.getData<Particle>();
    assert(dfb111.getSize() % sizeof(Particle) == 0);
    int np1 = dfb111.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b111[j1];
  }
  { const Particle *b112 = dfb112.getData<Particle>();
    assert(dfb112.getSize() % sizeof(Particle) == 0);
    int np1 = dfb112.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b112[j1];
  }
  { const Particle *b120 = dfb120.getData<Particle>();
    assert(dfb120.getSize() % sizeof(Particle) == 0);
    int np1 = dfb120.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b120[j1];
  }
  { const Particle *b121 = dfb121.getData<Particle>();
    assert(dfb121.getSize() % sizeof(Particle) == 0);
    int np1 = dfb121.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b121[j1];
  }
  { const Particle *b122 = dfb122.getData<Particle>();
    assert(dfb122.getSize() % sizeof(Particle) == 0);
    int np1 = dfb122.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b122[j1];
  }
  { const Particle *b200 = dfb200.getData<Particle>();
    assert(dfb200.getSize() % sizeof(Particle) == 0);
    int np1 = dfb200.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b200[j1];
  }
  { const Particle *b201 = dfb201.getData<Particle>();
    assert(dfb201.getSize() % sizeof(Particle) == 0);
    int np1 = dfb201.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b201[j1];
  }
  { const Particle *b202 = dfb202.getData<Particle>();
    assert(dfb202.getSize() % sizeof(Particle) == 0);
    int np1 = dfb202.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b202[j1];
  }
  { const Particle *b210 = dfb210.getData<Particle>();
    assert(dfb210.getSize() % sizeof(Particle) == 0);
    int np1 = dfb210.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b210[j1];
  }
  { const Particle *b211 = dfb211.getData<Particle>();
    assert(dfb211.getSize() % sizeof(Particle) == 0);
    int np1 = dfb211.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b211[j1];
  }
  { const Particle *b212 = dfb212.getData<Particle>();
    assert(dfb212.getSize() % sizeof(Particle) == 0);
    int np1 = dfb212.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b212[j1];
  }
  { const Particle *b220 = dfb220.getData<Particle>();
    assert(dfb220.getSize() % sizeof(Particle) == 0);
    int np1 = dfb220.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b220[j1];
  }
  { const Particle *b221 = dfb221.getData<Particle>();
    assert(dfb221.getSize() % sizeof(Particle) == 0);
    int np1 = dfb221.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b221[j1];
  }
  { const Particle *b222 = dfb222.getData<Particle>();
    assert(dfb222.getSize() % sizeof(Particle) == 0);
    int np1 = dfb222.getSize()/sizeof(Particle);
    int j1;
    for (j1=0;j1<np1;j1++,j++) p[j] = b222[j1];
  }
  dfnp.setValue(np);
}
}
#undef D000
#undef D001
#undef D002
#undef D010
#undef D011
#undef D012
#undef D020
#undef D021
#undef D022
#undef D100
#undef D101
#undef D102
#undef D110
#undef D111
#undef D112
#undef D120
#undef D121
#undef D122
#undef D200
#undef D201
#undef D202
#undef D210
#undef D211
#undef D212
#undef D220
#undef D221
#undef D222