#include "ucenv.h"
#include "lib_basic.h"
typedef real itemtype;

extern "C"
{
void c_mesh3d_exchange_6_copy_00_00_00(int n0,int n1,int n2,const InputDF &dfu,OutputDF &dfv)
{
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  dfv.copy(dfu);
}

void c_mesh3d_exchange_6_get_00_00_01(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb112)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b112)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb112.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b112)[i][k][0] = (*u)[i][k][n2-2];
}

void c_mesh3d_exchange_6_set_00_00_01(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb112,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb112.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b112)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb112.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][n2-1] = (*b112)[i][k][0];
}

void c_mesh3d_exchange_6_get_00_00_10(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb110)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b110)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb110.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b110)[i][k][0] = (*u)[i][k][1];
}

void c_mesh3d_exchange_6_set_00_00_10(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb110,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb110.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b110)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb110.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][0] = (*b110)[i][k][0];
}

void c_mesh3d_exchange_6_get_00_00_11(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb110,OutputDF &dfb112)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b110)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb110.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b110)[i][k][0] = (*u)[i][k][1];
  itemtype (*b112)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb112.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b112)[i][k][0] = (*u)[i][k][n2-2];
}

void c_mesh3d_exchange_6_set_00_00_11(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb110,const InputDF &dfb112,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb110.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b110)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb110.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][0] = (*b110)[i][k][0];
  assert(dfb112.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b112)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb112.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][n2-1] = (*b112)[i][k][0];
}

void c_mesh3d_exchange_6_get_00_01_00(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb121)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b121)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb121.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b121)[i][0][l] = (*u)[i][n1-2][l];
}

void c_mesh3d_exchange_6_set_00_01_00(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb121,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb121.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b121)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb121.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][n1-1][l] = (*b121)[i][0][l];
}

void c_mesh3d_exchange_6_get_00_01_01(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb112,OutputDF &dfb121)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b112)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb112.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b112)[i][k][0] = (*u)[i][k][n2-2];
  itemtype (*b121)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb121.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b121)[i][0][l] = (*u)[i][n1-2][l];
}

void c_mesh3d_exchange_6_set_00_01_01(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb112,const InputDF &dfb121,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb112.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b112)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb112.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][n2-1] = (*b112)[i][k][0];
  assert(dfb121.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b121)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb121.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][n1-1][l] = (*b121)[i][0][l];
}

void c_mesh3d_exchange_6_get_00_01_10(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb110,OutputDF &dfb121)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b110)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb110.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b110)[i][k][0] = (*u)[i][k][1];
  itemtype (*b121)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb121.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b121)[i][0][l] = (*u)[i][n1-2][l];
}

void c_mesh3d_exchange_6_set_00_01_10(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb110,const InputDF &dfb121,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb110.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b110)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb110.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][0] = (*b110)[i][k][0];
  assert(dfb121.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b121)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb121.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][n1-1][l] = (*b121)[i][0][l];
}

void c_mesh3d_exchange_6_get_00_01_11(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb110,OutputDF &dfb112,OutputDF &dfb121)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b110)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb110.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b110)[i][k][0] = (*u)[i][k][1];
  itemtype (*b112)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb112.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b112)[i][k][0] = (*u)[i][k][n2-2];
  itemtype (*b121)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb121.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b121)[i][0][l] = (*u)[i][n1-2][l];
}

void c_mesh3d_exchange_6_set_00_01_11(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb110,const InputDF &dfb112,const InputDF &dfb121,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb110.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b110)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb110.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][0] = (*b110)[i][k][0];
  assert(dfb112.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b112)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb112.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][n2-1] = (*b112)[i][k][0];
  assert(dfb121.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b121)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb121.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][n1-1][l] = (*b121)[i][0][l];
}

void c_mesh3d_exchange_6_get_00_10_00(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb101)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b101)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb101.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b101)[i][0][l] = (*u)[i][1][l];
}

void c_mesh3d_exchange_6_set_00_10_00(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb101,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb101.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b101)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb101.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][0][l] = (*b101)[i][0][l];
}

void c_mesh3d_exchange_6_get_00_10_01(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb101,OutputDF &dfb112)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b101)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb101.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b101)[i][0][l] = (*u)[i][1][l];
  itemtype (*b112)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb112.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b112)[i][k][0] = (*u)[i][k][n2-2];
}

void c_mesh3d_exchange_6_set_00_10_01(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb101,const InputDF &dfb112,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb101.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b101)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb101.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][0][l] = (*b101)[i][0][l];
  assert(dfb112.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b112)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb112.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][n2-1] = (*b112)[i][k][0];
}

void c_mesh3d_exchange_6_get_00_10_10(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb101,OutputDF &dfb110)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b101)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb101.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b101)[i][0][l] = (*u)[i][1][l];
  itemtype (*b110)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb110.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b110)[i][k][0] = (*u)[i][k][1];
}

void c_mesh3d_exchange_6_set_00_10_10(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb101,const InputDF &dfb110,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb101.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b101)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb101.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][0][l] = (*b101)[i][0][l];
  assert(dfb110.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b110)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb110.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][0] = (*b110)[i][k][0];
}

void c_mesh3d_exchange_6_get_00_10_11(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb101,OutputDF &dfb110,OutputDF &dfb112)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b101)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb101.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b101)[i][0][l] = (*u)[i][1][l];
  itemtype (*b110)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb110.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b110)[i][k][0] = (*u)[i][k][1];
  itemtype (*b112)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb112.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b112)[i][k][0] = (*u)[i][k][n2-2];
}

void c_mesh3d_exchange_6_set_00_10_11(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb101,const InputDF &dfb110,const InputDF &dfb112,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb101.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b101)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb101.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][0][l] = (*b101)[i][0][l];
  assert(dfb110.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b110)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb110.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][0] = (*b110)[i][k][0];
  assert(dfb112.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b112)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb112.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][n2-1] = (*b112)[i][k][0];
}

void c_mesh3d_exchange_6_get_00_11_00(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb101,OutputDF &dfb121)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b101)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb101.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b101)[i][0][l] = (*u)[i][1][l];
  itemtype (*b121)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb121.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b121)[i][0][l] = (*u)[i][n1-2][l];
}

void c_mesh3d_exchange_6_set_00_11_00(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb101,const InputDF &dfb121,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb101.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b101)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb101.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][0][l] = (*b101)[i][0][l];
  assert(dfb121.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b121)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb121.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][n1-1][l] = (*b121)[i][0][l];
}

void c_mesh3d_exchange_6_get_00_11_01(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb101,OutputDF &dfb112,OutputDF &dfb121)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b101)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb101.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b101)[i][0][l] = (*u)[i][1][l];
  itemtype (*b112)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb112.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b112)[i][k][0] = (*u)[i][k][n2-2];
  itemtype (*b121)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb121.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b121)[i][0][l] = (*u)[i][n1-2][l];
}

void c_mesh3d_exchange_6_set_00_11_01(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb101,const InputDF &dfb112,const InputDF &dfb121,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb101.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b101)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb101.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][0][l] = (*b101)[i][0][l];
  assert(dfb112.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b112)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb112.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][n2-1] = (*b112)[i][k][0];
  assert(dfb121.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b121)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb121.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][n1-1][l] = (*b121)[i][0][l];
}

void c_mesh3d_exchange_6_get_00_11_10(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb101,OutputDF &dfb110,OutputDF &dfb121)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b101)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb101.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b101)[i][0][l] = (*u)[i][1][l];
  itemtype (*b110)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb110.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b110)[i][k][0] = (*u)[i][k][1];
  itemtype (*b121)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb121.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b121)[i][0][l] = (*u)[i][n1-2][l];
}

void c_mesh3d_exchange_6_set_00_11_10(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb101,const InputDF &dfb110,const InputDF &dfb121,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb101.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b101)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb101.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][0][l] = (*b101)[i][0][l];
  assert(dfb110.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b110)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb110.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][0] = (*b110)[i][k][0];
  assert(dfb121.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b121)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb121.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][n1-1][l] = (*b121)[i][0][l];
}

void c_mesh3d_exchange_6_get_00_11_11(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb101,OutputDF &dfb110,OutputDF &dfb112,OutputDF &dfb121)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b101)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb101.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b101)[i][0][l] = (*u)[i][1][l];
  itemtype (*b110)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb110.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b110)[i][k][0] = (*u)[i][k][1];
  itemtype (*b112)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb112.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b112)[i][k][0] = (*u)[i][k][n2-2];
  itemtype (*b121)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb121.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b121)[i][0][l] = (*u)[i][n1-2][l];
}

void c_mesh3d_exchange_6_set_00_11_11(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb101,const InputDF &dfb110,const InputDF &dfb112,const InputDF &dfb121,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb101.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b101)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb101.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][0][l] = (*b101)[i][0][l];
  assert(dfb110.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b110)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb110.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][0] = (*b110)[i][k][0];
  assert(dfb112.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b112)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb112.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][n2-1] = (*b112)[i][k][0];
  assert(dfb121.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b121)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb121.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][n1-1][l] = (*b121)[i][0][l];
}

void c_mesh3d_exchange_6_get_01_00_00(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb211)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b211)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb211.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b211)[0][k][l] = (*u)[n0-2][k][l];
}

void c_mesh3d_exchange_6_set_01_00_00(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb211,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb211.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b211)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb211.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[n0-1][k][l] = (*b211)[0][k][l];
}

void c_mesh3d_exchange_6_get_01_00_01(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb112,OutputDF &dfb211)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b112)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb112.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b112)[i][k][0] = (*u)[i][k][n2-2];
  itemtype (*b211)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb211.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b211)[0][k][l] = (*u)[n0-2][k][l];
}

void c_mesh3d_exchange_6_set_01_00_01(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb112,const InputDF &dfb211,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb112.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b112)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb112.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][n2-1] = (*b112)[i][k][0];
  assert(dfb211.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b211)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb211.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[n0-1][k][l] = (*b211)[0][k][l];
}

void c_mesh3d_exchange_6_get_01_00_10(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb110,OutputDF &dfb211)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b110)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb110.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b110)[i][k][0] = (*u)[i][k][1];
  itemtype (*b211)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb211.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b211)[0][k][l] = (*u)[n0-2][k][l];
}

void c_mesh3d_exchange_6_set_01_00_10(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb110,const InputDF &dfb211,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb110.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b110)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb110.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][0] = (*b110)[i][k][0];
  assert(dfb211.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b211)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb211.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[n0-1][k][l] = (*b211)[0][k][l];
}

void c_mesh3d_exchange_6_get_01_00_11(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb110,OutputDF &dfb112,OutputDF &dfb211)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b110)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb110.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b110)[i][k][0] = (*u)[i][k][1];
  itemtype (*b112)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb112.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b112)[i][k][0] = (*u)[i][k][n2-2];
  itemtype (*b211)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb211.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b211)[0][k][l] = (*u)[n0-2][k][l];
}

void c_mesh3d_exchange_6_set_01_00_11(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb110,const InputDF &dfb112,const InputDF &dfb211,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb110.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b110)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb110.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][0] = (*b110)[i][k][0];
  assert(dfb112.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b112)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb112.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][n2-1] = (*b112)[i][k][0];
  assert(dfb211.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b211)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb211.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[n0-1][k][l] = (*b211)[0][k][l];
}

void c_mesh3d_exchange_6_get_01_01_00(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb121,OutputDF &dfb211)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b121)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb121.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b121)[i][0][l] = (*u)[i][n1-2][l];
  itemtype (*b211)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb211.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b211)[0][k][l] = (*u)[n0-2][k][l];
}

void c_mesh3d_exchange_6_set_01_01_00(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb121,const InputDF &dfb211,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb121.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b121)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb121.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][n1-1][l] = (*b121)[i][0][l];
  assert(dfb211.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b211)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb211.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[n0-1][k][l] = (*b211)[0][k][l];
}

void c_mesh3d_exchange_6_get_01_01_01(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb112,OutputDF &dfb121,OutputDF &dfb211)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b112)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb112.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b112)[i][k][0] = (*u)[i][k][n2-2];
  itemtype (*b121)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb121.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b121)[i][0][l] = (*u)[i][n1-2][l];
  itemtype (*b211)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb211.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b211)[0][k][l] = (*u)[n0-2][k][l];
}

void c_mesh3d_exchange_6_set_01_01_01(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb112,const InputDF &dfb121,const InputDF &dfb211,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb112.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b112)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb112.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][n2-1] = (*b112)[i][k][0];
  assert(dfb121.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b121)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb121.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][n1-1][l] = (*b121)[i][0][l];
  assert(dfb211.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b211)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb211.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[n0-1][k][l] = (*b211)[0][k][l];
}

void c_mesh3d_exchange_6_get_01_01_10(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb110,OutputDF &dfb121,OutputDF &dfb211)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b110)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb110.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b110)[i][k][0] = (*u)[i][k][1];
  itemtype (*b121)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb121.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b121)[i][0][l] = (*u)[i][n1-2][l];
  itemtype (*b211)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb211.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b211)[0][k][l] = (*u)[n0-2][k][l];
}

void c_mesh3d_exchange_6_set_01_01_10(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb110,const InputDF &dfb121,const InputDF &dfb211,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb110.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b110)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb110.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][0] = (*b110)[i][k][0];
  assert(dfb121.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b121)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb121.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][n1-1][l] = (*b121)[i][0][l];
  assert(dfb211.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b211)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb211.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[n0-1][k][l] = (*b211)[0][k][l];
}

void c_mesh3d_exchange_6_get_01_01_11(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb110,OutputDF &dfb112,OutputDF &dfb121,OutputDF &dfb211)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b110)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb110.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b110)[i][k][0] = (*u)[i][k][1];
  itemtype (*b112)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb112.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b112)[i][k][0] = (*u)[i][k][n2-2];
  itemtype (*b121)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb121.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b121)[i][0][l] = (*u)[i][n1-2][l];
  itemtype (*b211)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb211.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b211)[0][k][l] = (*u)[n0-2][k][l];
}

void c_mesh3d_exchange_6_set_01_01_11(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb110,const InputDF &dfb112,const InputDF &dfb121,const InputDF &dfb211,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb110.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b110)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb110.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][0] = (*b110)[i][k][0];
  assert(dfb112.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b112)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb112.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][n2-1] = (*b112)[i][k][0];
  assert(dfb121.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b121)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb121.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][n1-1][l] = (*b121)[i][0][l];
  assert(dfb211.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b211)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb211.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[n0-1][k][l] = (*b211)[0][k][l];
}

void c_mesh3d_exchange_6_get_01_10_00(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb101,OutputDF &dfb211)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b101)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb101.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b101)[i][0][l] = (*u)[i][1][l];
  itemtype (*b211)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb211.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b211)[0][k][l] = (*u)[n0-2][k][l];
}

void c_mesh3d_exchange_6_set_01_10_00(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb101,const InputDF &dfb211,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb101.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b101)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb101.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][0][l] = (*b101)[i][0][l];
  assert(dfb211.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b211)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb211.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[n0-1][k][l] = (*b211)[0][k][l];
}

void c_mesh3d_exchange_6_get_01_10_01(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb101,OutputDF &dfb112,OutputDF &dfb211)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b101)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb101.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b101)[i][0][l] = (*u)[i][1][l];
  itemtype (*b112)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb112.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b112)[i][k][0] = (*u)[i][k][n2-2];
  itemtype (*b211)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb211.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b211)[0][k][l] = (*u)[n0-2][k][l];
}

void c_mesh3d_exchange_6_set_01_10_01(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb101,const InputDF &dfb112,const InputDF &dfb211,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb101.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b101)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb101.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][0][l] = (*b101)[i][0][l];
  assert(dfb112.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b112)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb112.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][n2-1] = (*b112)[i][k][0];
  assert(dfb211.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b211)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb211.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[n0-1][k][l] = (*b211)[0][k][l];
}

void c_mesh3d_exchange_6_get_01_10_10(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb101,OutputDF &dfb110,OutputDF &dfb211)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b101)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb101.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b101)[i][0][l] = (*u)[i][1][l];
  itemtype (*b110)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb110.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b110)[i][k][0] = (*u)[i][k][1];
  itemtype (*b211)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb211.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b211)[0][k][l] = (*u)[n0-2][k][l];
}

void c_mesh3d_exchange_6_set_01_10_10(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb101,const InputDF &dfb110,const InputDF &dfb211,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb101.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b101)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb101.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][0][l] = (*b101)[i][0][l];
  assert(dfb110.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b110)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb110.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][0] = (*b110)[i][k][0];
  assert(dfb211.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b211)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb211.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[n0-1][k][l] = (*b211)[0][k][l];
}

void c_mesh3d_exchange_6_get_01_10_11(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb101,OutputDF &dfb110,OutputDF &dfb112,OutputDF &dfb211)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b101)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb101.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b101)[i][0][l] = (*u)[i][1][l];
  itemtype (*b110)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb110.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b110)[i][k][0] = (*u)[i][k][1];
  itemtype (*b112)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb112.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b112)[i][k][0] = (*u)[i][k][n2-2];
  itemtype (*b211)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb211.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b211)[0][k][l] = (*u)[n0-2][k][l];
}

void c_mesh3d_exchange_6_set_01_10_11(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb101,const InputDF &dfb110,const InputDF &dfb112,const InputDF &dfb211,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb101.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b101)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb101.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][0][l] = (*b101)[i][0][l];
  assert(dfb110.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b110)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb110.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][0] = (*b110)[i][k][0];
  assert(dfb112.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b112)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb112.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][n2-1] = (*b112)[i][k][0];
  assert(dfb211.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b211)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb211.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[n0-1][k][l] = (*b211)[0][k][l];
}

void c_mesh3d_exchange_6_get_01_11_00(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb101,OutputDF &dfb121,OutputDF &dfb211)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b101)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb101.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b101)[i][0][l] = (*u)[i][1][l];
  itemtype (*b121)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb121.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b121)[i][0][l] = (*u)[i][n1-2][l];
  itemtype (*b211)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb211.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b211)[0][k][l] = (*u)[n0-2][k][l];
}

void c_mesh3d_exchange_6_set_01_11_00(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb101,const InputDF &dfb121,const InputDF &dfb211,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb101.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b101)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb101.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][0][l] = (*b101)[i][0][l];
  assert(dfb121.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b121)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb121.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][n1-1][l] = (*b121)[i][0][l];
  assert(dfb211.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b211)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb211.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[n0-1][k][l] = (*b211)[0][k][l];
}

void c_mesh3d_exchange_6_get_01_11_01(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb101,OutputDF &dfb112,OutputDF &dfb121,OutputDF &dfb211)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b101)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb101.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b101)[i][0][l] = (*u)[i][1][l];
  itemtype (*b112)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb112.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b112)[i][k][0] = (*u)[i][k][n2-2];
  itemtype (*b121)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb121.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b121)[i][0][l] = (*u)[i][n1-2][l];
  itemtype (*b211)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb211.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b211)[0][k][l] = (*u)[n0-2][k][l];
}

void c_mesh3d_exchange_6_set_01_11_01(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb101,const InputDF &dfb112,const InputDF &dfb121,const InputDF &dfb211,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb101.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b101)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb101.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][0][l] = (*b101)[i][0][l];
  assert(dfb112.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b112)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb112.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][n2-1] = (*b112)[i][k][0];
  assert(dfb121.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b121)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb121.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][n1-1][l] = (*b121)[i][0][l];
  assert(dfb211.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b211)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb211.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[n0-1][k][l] = (*b211)[0][k][l];
}

void c_mesh3d_exchange_6_get_01_11_10(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb101,OutputDF &dfb110,OutputDF &dfb121,OutputDF &dfb211)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b101)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb101.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b101)[i][0][l] = (*u)[i][1][l];
  itemtype (*b110)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb110.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b110)[i][k][0] = (*u)[i][k][1];
  itemtype (*b121)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb121.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b121)[i][0][l] = (*u)[i][n1-2][l];
  itemtype (*b211)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb211.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b211)[0][k][l] = (*u)[n0-2][k][l];
}

void c_mesh3d_exchange_6_set_01_11_10(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb101,const InputDF &dfb110,const InputDF &dfb121,const InputDF &dfb211,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb101.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b101)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb101.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][0][l] = (*b101)[i][0][l];
  assert(dfb110.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b110)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb110.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][0] = (*b110)[i][k][0];
  assert(dfb121.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b121)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb121.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][n1-1][l] = (*b121)[i][0][l];
  assert(dfb211.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b211)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb211.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[n0-1][k][l] = (*b211)[0][k][l];
}

void c_mesh3d_exchange_6_get_01_11_11(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb101,OutputDF &dfb110,OutputDF &dfb112,OutputDF &dfb121,OutputDF &dfb211)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b101)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb101.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b101)[i][0][l] = (*u)[i][1][l];
  itemtype (*b110)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb110.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b110)[i][k][0] = (*u)[i][k][1];
  itemtype (*b112)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb112.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b112)[i][k][0] = (*u)[i][k][n2-2];
  itemtype (*b121)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb121.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b121)[i][0][l] = (*u)[i][n1-2][l];
  itemtype (*b211)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb211.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b211)[0][k][l] = (*u)[n0-2][k][l];
}

void c_mesh3d_exchange_6_set_01_11_11(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb101,const InputDF &dfb110,const InputDF &dfb112,const InputDF &dfb121,const InputDF &dfb211,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb101.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b101)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb101.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][0][l] = (*b101)[i][0][l];
  assert(dfb110.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b110)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb110.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][0] = (*b110)[i][k][0];
  assert(dfb112.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b112)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb112.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][n2-1] = (*b112)[i][k][0];
  assert(dfb121.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b121)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb121.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][n1-1][l] = (*b121)[i][0][l];
  assert(dfb211.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b211)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb211.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[n0-1][k][l] = (*b211)[0][k][l];
}

void c_mesh3d_exchange_6_get_10_00_00(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb011)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b011)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb011.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b011)[0][k][l] = (*u)[1][k][l];
}

void c_mesh3d_exchange_6_set_10_00_00(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb011,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb011.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b011)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb011.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[0][k][l] = (*b011)[0][k][l];
}

void c_mesh3d_exchange_6_get_10_00_01(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb011,OutputDF &dfb112)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b011)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb011.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b011)[0][k][l] = (*u)[1][k][l];
  itemtype (*b112)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb112.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b112)[i][k][0] = (*u)[i][k][n2-2];
}

void c_mesh3d_exchange_6_set_10_00_01(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb011,const InputDF &dfb112,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb011.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b011)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb011.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[0][k][l] = (*b011)[0][k][l];
  assert(dfb112.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b112)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb112.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][n2-1] = (*b112)[i][k][0];
}

void c_mesh3d_exchange_6_get_10_00_10(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb011,OutputDF &dfb110)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b011)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb011.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b011)[0][k][l] = (*u)[1][k][l];
  itemtype (*b110)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb110.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b110)[i][k][0] = (*u)[i][k][1];
}

void c_mesh3d_exchange_6_set_10_00_10(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb011,const InputDF &dfb110,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb011.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b011)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb011.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[0][k][l] = (*b011)[0][k][l];
  assert(dfb110.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b110)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb110.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][0] = (*b110)[i][k][0];
}

void c_mesh3d_exchange_6_get_10_00_11(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb011,OutputDF &dfb110,OutputDF &dfb112)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b011)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb011.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b011)[0][k][l] = (*u)[1][k][l];
  itemtype (*b110)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb110.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b110)[i][k][0] = (*u)[i][k][1];
  itemtype (*b112)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb112.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b112)[i][k][0] = (*u)[i][k][n2-2];
}

void c_mesh3d_exchange_6_set_10_00_11(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb011,const InputDF &dfb110,const InputDF &dfb112,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb011.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b011)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb011.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[0][k][l] = (*b011)[0][k][l];
  assert(dfb110.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b110)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb110.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][0] = (*b110)[i][k][0];
  assert(dfb112.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b112)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb112.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][n2-1] = (*b112)[i][k][0];
}

void c_mesh3d_exchange_6_get_10_01_00(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb011,OutputDF &dfb121)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b011)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb011.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b011)[0][k][l] = (*u)[1][k][l];
  itemtype (*b121)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb121.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b121)[i][0][l] = (*u)[i][n1-2][l];
}

void c_mesh3d_exchange_6_set_10_01_00(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb011,const InputDF &dfb121,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb011.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b011)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb011.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[0][k][l] = (*b011)[0][k][l];
  assert(dfb121.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b121)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb121.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][n1-1][l] = (*b121)[i][0][l];
}

void c_mesh3d_exchange_6_get_10_01_01(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb011,OutputDF &dfb112,OutputDF &dfb121)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b011)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb011.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b011)[0][k][l] = (*u)[1][k][l];
  itemtype (*b112)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb112.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b112)[i][k][0] = (*u)[i][k][n2-2];
  itemtype (*b121)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb121.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b121)[i][0][l] = (*u)[i][n1-2][l];
}

void c_mesh3d_exchange_6_set_10_01_01(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb011,const InputDF &dfb112,const InputDF &dfb121,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb011.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b011)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb011.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[0][k][l] = (*b011)[0][k][l];
  assert(dfb112.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b112)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb112.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][n2-1] = (*b112)[i][k][0];
  assert(dfb121.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b121)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb121.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][n1-1][l] = (*b121)[i][0][l];
}

void c_mesh3d_exchange_6_get_10_01_10(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb011,OutputDF &dfb110,OutputDF &dfb121)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b011)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb011.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b011)[0][k][l] = (*u)[1][k][l];
  itemtype (*b110)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb110.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b110)[i][k][0] = (*u)[i][k][1];
  itemtype (*b121)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb121.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b121)[i][0][l] = (*u)[i][n1-2][l];
}

void c_mesh3d_exchange_6_set_10_01_10(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb011,const InputDF &dfb110,const InputDF &dfb121,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb011.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b011)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb011.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[0][k][l] = (*b011)[0][k][l];
  assert(dfb110.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b110)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb110.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][0] = (*b110)[i][k][0];
  assert(dfb121.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b121)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb121.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][n1-1][l] = (*b121)[i][0][l];
}

void c_mesh3d_exchange_6_get_10_01_11(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb011,OutputDF &dfb110,OutputDF &dfb112,OutputDF &dfb121)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b011)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb011.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b011)[0][k][l] = (*u)[1][k][l];
  itemtype (*b110)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb110.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b110)[i][k][0] = (*u)[i][k][1];
  itemtype (*b112)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb112.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b112)[i][k][0] = (*u)[i][k][n2-2];
  itemtype (*b121)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb121.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b121)[i][0][l] = (*u)[i][n1-2][l];
}

void c_mesh3d_exchange_6_set_10_01_11(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb011,const InputDF &dfb110,const InputDF &dfb112,const InputDF &dfb121,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb011.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b011)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb011.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[0][k][l] = (*b011)[0][k][l];
  assert(dfb110.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b110)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb110.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][0] = (*b110)[i][k][0];
  assert(dfb112.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b112)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb112.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][n2-1] = (*b112)[i][k][0];
  assert(dfb121.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b121)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb121.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][n1-1][l] = (*b121)[i][0][l];
}

void c_mesh3d_exchange_6_get_10_10_00(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb011,OutputDF &dfb101)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b011)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb011.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b011)[0][k][l] = (*u)[1][k][l];
  itemtype (*b101)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb101.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b101)[i][0][l] = (*u)[i][1][l];
}

void c_mesh3d_exchange_6_set_10_10_00(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb011,const InputDF &dfb101,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb011.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b011)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb011.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[0][k][l] = (*b011)[0][k][l];
  assert(dfb101.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b101)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb101.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][0][l] = (*b101)[i][0][l];
}

void c_mesh3d_exchange_6_get_10_10_01(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb011,OutputDF &dfb101,OutputDF &dfb112)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b011)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb011.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b011)[0][k][l] = (*u)[1][k][l];
  itemtype (*b101)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb101.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b101)[i][0][l] = (*u)[i][1][l];
  itemtype (*b112)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb112.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b112)[i][k][0] = (*u)[i][k][n2-2];
}

void c_mesh3d_exchange_6_set_10_10_01(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb011,const InputDF &dfb101,const InputDF &dfb112,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb011.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b011)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb011.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[0][k][l] = (*b011)[0][k][l];
  assert(dfb101.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b101)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb101.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][0][l] = (*b101)[i][0][l];
  assert(dfb112.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b112)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb112.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][n2-1] = (*b112)[i][k][0];
}

void c_mesh3d_exchange_6_get_10_10_10(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb011,OutputDF &dfb101,OutputDF &dfb110)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b011)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb011.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b011)[0][k][l] = (*u)[1][k][l];
  itemtype (*b101)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb101.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b101)[i][0][l] = (*u)[i][1][l];
  itemtype (*b110)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb110.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b110)[i][k][0] = (*u)[i][k][1];
}

void c_mesh3d_exchange_6_set_10_10_10(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb011,const InputDF &dfb101,const InputDF &dfb110,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb011.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b011)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb011.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[0][k][l] = (*b011)[0][k][l];
  assert(dfb101.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b101)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb101.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][0][l] = (*b101)[i][0][l];
  assert(dfb110.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b110)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb110.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][0] = (*b110)[i][k][0];
}

void c_mesh3d_exchange_6_get_10_10_11(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb011,OutputDF &dfb101,OutputDF &dfb110,OutputDF &dfb112)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b011)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb011.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b011)[0][k][l] = (*u)[1][k][l];
  itemtype (*b101)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb101.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b101)[i][0][l] = (*u)[i][1][l];
  itemtype (*b110)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb110.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b110)[i][k][0] = (*u)[i][k][1];
  itemtype (*b112)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb112.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b112)[i][k][0] = (*u)[i][k][n2-2];
}

void c_mesh3d_exchange_6_set_10_10_11(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb011,const InputDF &dfb101,const InputDF &dfb110,const InputDF &dfb112,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb011.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b011)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb011.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[0][k][l] = (*b011)[0][k][l];
  assert(dfb101.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b101)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb101.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][0][l] = (*b101)[i][0][l];
  assert(dfb110.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b110)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb110.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][0] = (*b110)[i][k][0];
  assert(dfb112.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b112)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb112.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][n2-1] = (*b112)[i][k][0];
}

void c_mesh3d_exchange_6_get_10_11_00(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb011,OutputDF &dfb101,OutputDF &dfb121)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b011)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb011.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b011)[0][k][l] = (*u)[1][k][l];
  itemtype (*b101)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb101.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b101)[i][0][l] = (*u)[i][1][l];
  itemtype (*b121)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb121.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b121)[i][0][l] = (*u)[i][n1-2][l];
}

void c_mesh3d_exchange_6_set_10_11_00(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb011,const InputDF &dfb101,const InputDF &dfb121,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb011.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b011)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb011.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[0][k][l] = (*b011)[0][k][l];
  assert(dfb101.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b101)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb101.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][0][l] = (*b101)[i][0][l];
  assert(dfb121.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b121)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb121.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][n1-1][l] = (*b121)[i][0][l];
}

void c_mesh3d_exchange_6_get_10_11_01(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb011,OutputDF &dfb101,OutputDF &dfb112,OutputDF &dfb121)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b011)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb011.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b011)[0][k][l] = (*u)[1][k][l];
  itemtype (*b101)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb101.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b101)[i][0][l] = (*u)[i][1][l];
  itemtype (*b112)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb112.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b112)[i][k][0] = (*u)[i][k][n2-2];
  itemtype (*b121)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb121.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b121)[i][0][l] = (*u)[i][n1-2][l];
}

void c_mesh3d_exchange_6_set_10_11_01(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb011,const InputDF &dfb101,const InputDF &dfb112,const InputDF &dfb121,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb011.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b011)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb011.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[0][k][l] = (*b011)[0][k][l];
  assert(dfb101.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b101)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb101.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][0][l] = (*b101)[i][0][l];
  assert(dfb112.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b112)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb112.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][n2-1] = (*b112)[i][k][0];
  assert(dfb121.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b121)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb121.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][n1-1][l] = (*b121)[i][0][l];
}

void c_mesh3d_exchange_6_get_10_11_10(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb011,OutputDF &dfb101,OutputDF &dfb110,OutputDF &dfb121)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b011)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb011.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b011)[0][k][l] = (*u)[1][k][l];
  itemtype (*b101)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb101.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b101)[i][0][l] = (*u)[i][1][l];
  itemtype (*b110)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb110.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b110)[i][k][0] = (*u)[i][k][1];
  itemtype (*b121)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb121.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b121)[i][0][l] = (*u)[i][n1-2][l];
}

void c_mesh3d_exchange_6_set_10_11_10(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb011,const InputDF &dfb101,const InputDF &dfb110,const InputDF &dfb121,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb011.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b011)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb011.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[0][k][l] = (*b011)[0][k][l];
  assert(dfb101.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b101)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb101.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][0][l] = (*b101)[i][0][l];
  assert(dfb110.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b110)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb110.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][0] = (*b110)[i][k][0];
  assert(dfb121.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b121)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb121.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][n1-1][l] = (*b121)[i][0][l];
}

void c_mesh3d_exchange_6_get_10_11_11(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb011,OutputDF &dfb101,OutputDF &dfb110,OutputDF &dfb112,OutputDF &dfb121)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b011)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb011.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b011)[0][k][l] = (*u)[1][k][l];
  itemtype (*b101)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb101.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b101)[i][0][l] = (*u)[i][1][l];
  itemtype (*b110)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb110.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b110)[i][k][0] = (*u)[i][k][1];
  itemtype (*b112)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb112.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b112)[i][k][0] = (*u)[i][k][n2-2];
  itemtype (*b121)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb121.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b121)[i][0][l] = (*u)[i][n1-2][l];
}

void c_mesh3d_exchange_6_set_10_11_11(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb011,const InputDF &dfb101,const InputDF &dfb110,const InputDF &dfb112,const InputDF &dfb121,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb011.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b011)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb011.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[0][k][l] = (*b011)[0][k][l];
  assert(dfb101.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b101)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb101.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][0][l] = (*b101)[i][0][l];
  assert(dfb110.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b110)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb110.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][0] = (*b110)[i][k][0];
  assert(dfb112.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b112)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb112.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][n2-1] = (*b112)[i][k][0];
  assert(dfb121.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b121)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb121.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][n1-1][l] = (*b121)[i][0][l];
}

void c_mesh3d_exchange_6_get_11_00_00(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb011,OutputDF &dfb211)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b011)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb011.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b011)[0][k][l] = (*u)[1][k][l];
  itemtype (*b211)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb211.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b211)[0][k][l] = (*u)[n0-2][k][l];
}

void c_mesh3d_exchange_6_set_11_00_00(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb011,const InputDF &dfb211,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb011.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b011)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb011.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[0][k][l] = (*b011)[0][k][l];
  assert(dfb211.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b211)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb211.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[n0-1][k][l] = (*b211)[0][k][l];
}

void c_mesh3d_exchange_6_get_11_00_01(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb011,OutputDF &dfb112,OutputDF &dfb211)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b011)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb011.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b011)[0][k][l] = (*u)[1][k][l];
  itemtype (*b112)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb112.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b112)[i][k][0] = (*u)[i][k][n2-2];
  itemtype (*b211)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb211.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b211)[0][k][l] = (*u)[n0-2][k][l];
}

void c_mesh3d_exchange_6_set_11_00_01(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb011,const InputDF &dfb112,const InputDF &dfb211,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb011.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b011)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb011.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[0][k][l] = (*b011)[0][k][l];
  assert(dfb112.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b112)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb112.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][n2-1] = (*b112)[i][k][0];
  assert(dfb211.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b211)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb211.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[n0-1][k][l] = (*b211)[0][k][l];
}

void c_mesh3d_exchange_6_get_11_00_10(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb011,OutputDF &dfb110,OutputDF &dfb211)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b011)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb011.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b011)[0][k][l] = (*u)[1][k][l];
  itemtype (*b110)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb110.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b110)[i][k][0] = (*u)[i][k][1];
  itemtype (*b211)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb211.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b211)[0][k][l] = (*u)[n0-2][k][l];
}

void c_mesh3d_exchange_6_set_11_00_10(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb011,const InputDF &dfb110,const InputDF &dfb211,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb011.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b011)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb011.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[0][k][l] = (*b011)[0][k][l];
  assert(dfb110.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b110)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb110.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][0] = (*b110)[i][k][0];
  assert(dfb211.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b211)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb211.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[n0-1][k][l] = (*b211)[0][k][l];
}

void c_mesh3d_exchange_6_get_11_00_11(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb011,OutputDF &dfb110,OutputDF &dfb112,OutputDF &dfb211)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b011)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb011.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b011)[0][k][l] = (*u)[1][k][l];
  itemtype (*b110)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb110.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b110)[i][k][0] = (*u)[i][k][1];
  itemtype (*b112)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb112.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b112)[i][k][0] = (*u)[i][k][n2-2];
  itemtype (*b211)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb211.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b211)[0][k][l] = (*u)[n0-2][k][l];
}

void c_mesh3d_exchange_6_set_11_00_11(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb011,const InputDF &dfb110,const InputDF &dfb112,const InputDF &dfb211,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb011.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b011)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb011.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[0][k][l] = (*b011)[0][k][l];
  assert(dfb110.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b110)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb110.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][0] = (*b110)[i][k][0];
  assert(dfb112.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b112)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb112.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][n2-1] = (*b112)[i][k][0];
  assert(dfb211.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b211)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb211.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[n0-1][k][l] = (*b211)[0][k][l];
}

void c_mesh3d_exchange_6_get_11_01_00(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb011,OutputDF &dfb121,OutputDF &dfb211)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b011)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb011.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b011)[0][k][l] = (*u)[1][k][l];
  itemtype (*b121)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb121.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b121)[i][0][l] = (*u)[i][n1-2][l];
  itemtype (*b211)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb211.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b211)[0][k][l] = (*u)[n0-2][k][l];
}

void c_mesh3d_exchange_6_set_11_01_00(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb011,const InputDF &dfb121,const InputDF &dfb211,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb011.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b011)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb011.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[0][k][l] = (*b011)[0][k][l];
  assert(dfb121.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b121)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb121.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][n1-1][l] = (*b121)[i][0][l];
  assert(dfb211.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b211)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb211.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[n0-1][k][l] = (*b211)[0][k][l];
}

void c_mesh3d_exchange_6_get_11_01_01(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb011,OutputDF &dfb112,OutputDF &dfb121,OutputDF &dfb211)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b011)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb011.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b011)[0][k][l] = (*u)[1][k][l];
  itemtype (*b112)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb112.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b112)[i][k][0] = (*u)[i][k][n2-2];
  itemtype (*b121)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb121.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b121)[i][0][l] = (*u)[i][n1-2][l];
  itemtype (*b211)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb211.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b211)[0][k][l] = (*u)[n0-2][k][l];
}

void c_mesh3d_exchange_6_set_11_01_01(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb011,const InputDF &dfb112,const InputDF &dfb121,const InputDF &dfb211,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb011.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b011)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb011.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[0][k][l] = (*b011)[0][k][l];
  assert(dfb112.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b112)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb112.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][n2-1] = (*b112)[i][k][0];
  assert(dfb121.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b121)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb121.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][n1-1][l] = (*b121)[i][0][l];
  assert(dfb211.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b211)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb211.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[n0-1][k][l] = (*b211)[0][k][l];
}

void c_mesh3d_exchange_6_get_11_01_10(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb011,OutputDF &dfb110,OutputDF &dfb121,OutputDF &dfb211)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b011)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb011.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b011)[0][k][l] = (*u)[1][k][l];
  itemtype (*b110)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb110.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b110)[i][k][0] = (*u)[i][k][1];
  itemtype (*b121)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb121.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b121)[i][0][l] = (*u)[i][n1-2][l];
  itemtype (*b211)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb211.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b211)[0][k][l] = (*u)[n0-2][k][l];
}

void c_mesh3d_exchange_6_set_11_01_10(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb011,const InputDF &dfb110,const InputDF &dfb121,const InputDF &dfb211,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb011.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b011)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb011.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[0][k][l] = (*b011)[0][k][l];
  assert(dfb110.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b110)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb110.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][0] = (*b110)[i][k][0];
  assert(dfb121.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b121)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb121.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][n1-1][l] = (*b121)[i][0][l];
  assert(dfb211.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b211)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb211.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[n0-1][k][l] = (*b211)[0][k][l];
}

void c_mesh3d_exchange_6_get_11_01_11(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb011,OutputDF &dfb110,OutputDF &dfb112,OutputDF &dfb121,OutputDF &dfb211)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b011)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb011.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b011)[0][k][l] = (*u)[1][k][l];
  itemtype (*b110)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb110.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b110)[i][k][0] = (*u)[i][k][1];
  itemtype (*b112)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb112.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b112)[i][k][0] = (*u)[i][k][n2-2];
  itemtype (*b121)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb121.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b121)[i][0][l] = (*u)[i][n1-2][l];
  itemtype (*b211)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb211.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b211)[0][k][l] = (*u)[n0-2][k][l];
}

void c_mesh3d_exchange_6_set_11_01_11(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb011,const InputDF &dfb110,const InputDF &dfb112,const InputDF &dfb121,const InputDF &dfb211,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb011.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b011)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb011.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[0][k][l] = (*b011)[0][k][l];
  assert(dfb110.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b110)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb110.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][0] = (*b110)[i][k][0];
  assert(dfb112.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b112)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb112.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][n2-1] = (*b112)[i][k][0];
  assert(dfb121.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b121)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb121.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][n1-1][l] = (*b121)[i][0][l];
  assert(dfb211.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b211)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb211.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[n0-1][k][l] = (*b211)[0][k][l];
}

void c_mesh3d_exchange_6_get_11_10_00(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb011,OutputDF &dfb101,OutputDF &dfb211)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b011)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb011.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b011)[0][k][l] = (*u)[1][k][l];
  itemtype (*b101)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb101.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b101)[i][0][l] = (*u)[i][1][l];
  itemtype (*b211)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb211.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b211)[0][k][l] = (*u)[n0-2][k][l];
}

void c_mesh3d_exchange_6_set_11_10_00(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb011,const InputDF &dfb101,const InputDF &dfb211,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb011.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b011)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb011.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[0][k][l] = (*b011)[0][k][l];
  assert(dfb101.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b101)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb101.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][0][l] = (*b101)[i][0][l];
  assert(dfb211.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b211)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb211.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[n0-1][k][l] = (*b211)[0][k][l];
}

void c_mesh3d_exchange_6_get_11_10_01(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb011,OutputDF &dfb101,OutputDF &dfb112,OutputDF &dfb211)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b011)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb011.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b011)[0][k][l] = (*u)[1][k][l];
  itemtype (*b101)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb101.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b101)[i][0][l] = (*u)[i][1][l];
  itemtype (*b112)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb112.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b112)[i][k][0] = (*u)[i][k][n2-2];
  itemtype (*b211)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb211.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b211)[0][k][l] = (*u)[n0-2][k][l];
}

void c_mesh3d_exchange_6_set_11_10_01(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb011,const InputDF &dfb101,const InputDF &dfb112,const InputDF &dfb211,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb011.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b011)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb011.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[0][k][l] = (*b011)[0][k][l];
  assert(dfb101.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b101)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb101.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][0][l] = (*b101)[i][0][l];
  assert(dfb112.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b112)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb112.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][n2-1] = (*b112)[i][k][0];
  assert(dfb211.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b211)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb211.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[n0-1][k][l] = (*b211)[0][k][l];
}

void c_mesh3d_exchange_6_get_11_10_10(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb011,OutputDF &dfb101,OutputDF &dfb110,OutputDF &dfb211)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b011)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb011.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b011)[0][k][l] = (*u)[1][k][l];
  itemtype (*b101)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb101.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b101)[i][0][l] = (*u)[i][1][l];
  itemtype (*b110)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb110.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b110)[i][k][0] = (*u)[i][k][1];
  itemtype (*b211)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb211.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b211)[0][k][l] = (*u)[n0-2][k][l];
}

void c_mesh3d_exchange_6_set_11_10_10(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb011,const InputDF &dfb101,const InputDF &dfb110,const InputDF &dfb211,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb011.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b011)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb011.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[0][k][l] = (*b011)[0][k][l];
  assert(dfb101.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b101)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb101.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][0][l] = (*b101)[i][0][l];
  assert(dfb110.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b110)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb110.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][0] = (*b110)[i][k][0];
  assert(dfb211.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b211)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb211.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[n0-1][k][l] = (*b211)[0][k][l];
}

void c_mesh3d_exchange_6_get_11_10_11(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb011,OutputDF &dfb101,OutputDF &dfb110,OutputDF &dfb112,OutputDF &dfb211)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b011)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb011.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b011)[0][k][l] = (*u)[1][k][l];
  itemtype (*b101)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb101.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b101)[i][0][l] = (*u)[i][1][l];
  itemtype (*b110)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb110.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b110)[i][k][0] = (*u)[i][k][1];
  itemtype (*b112)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb112.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b112)[i][k][0] = (*u)[i][k][n2-2];
  itemtype (*b211)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb211.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b211)[0][k][l] = (*u)[n0-2][k][l];
}

void c_mesh3d_exchange_6_set_11_10_11(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb011,const InputDF &dfb101,const InputDF &dfb110,const InputDF &dfb112,const InputDF &dfb211,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb011.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b011)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb011.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[0][k][l] = (*b011)[0][k][l];
  assert(dfb101.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b101)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb101.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][0][l] = (*b101)[i][0][l];
  assert(dfb110.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b110)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb110.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][0] = (*b110)[i][k][0];
  assert(dfb112.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b112)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb112.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][n2-1] = (*b112)[i][k][0];
  assert(dfb211.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b211)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb211.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[n0-1][k][l] = (*b211)[0][k][l];
}

void c_mesh3d_exchange_6_get_11_11_00(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb011,OutputDF &dfb101,OutputDF &dfb121,OutputDF &dfb211)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b011)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb011.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b011)[0][k][l] = (*u)[1][k][l];
  itemtype (*b101)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb101.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b101)[i][0][l] = (*u)[i][1][l];
  itemtype (*b121)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb121.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b121)[i][0][l] = (*u)[i][n1-2][l];
  itemtype (*b211)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb211.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b211)[0][k][l] = (*u)[n0-2][k][l];
}

void c_mesh3d_exchange_6_set_11_11_00(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb011,const InputDF &dfb101,const InputDF &dfb121,const InputDF &dfb211,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb011.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b011)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb011.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[0][k][l] = (*b011)[0][k][l];
  assert(dfb101.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b101)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb101.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][0][l] = (*b101)[i][0][l];
  assert(dfb121.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b121)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb121.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][n1-1][l] = (*b121)[i][0][l];
  assert(dfb211.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b211)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb211.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[n0-1][k][l] = (*b211)[0][k][l];
}

void c_mesh3d_exchange_6_get_11_11_01(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb011,OutputDF &dfb101,OutputDF &dfb112,OutputDF &dfb121,OutputDF &dfb211)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b011)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb011.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b011)[0][k][l] = (*u)[1][k][l];
  itemtype (*b101)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb101.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b101)[i][0][l] = (*u)[i][1][l];
  itemtype (*b112)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb112.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b112)[i][k][0] = (*u)[i][k][n2-2];
  itemtype (*b121)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb121.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b121)[i][0][l] = (*u)[i][n1-2][l];
  itemtype (*b211)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb211.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b211)[0][k][l] = (*u)[n0-2][k][l];
}

void c_mesh3d_exchange_6_set_11_11_01(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb011,const InputDF &dfb101,const InputDF &dfb112,const InputDF &dfb121,const InputDF &dfb211,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb011.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b011)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb011.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[0][k][l] = (*b011)[0][k][l];
  assert(dfb101.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b101)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb101.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][0][l] = (*b101)[i][0][l];
  assert(dfb112.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b112)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb112.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][n2-1] = (*b112)[i][k][0];
  assert(dfb121.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b121)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb121.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][n1-1][l] = (*b121)[i][0][l];
  assert(dfb211.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b211)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb211.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[n0-1][k][l] = (*b211)[0][k][l];
}

void c_mesh3d_exchange_6_get_11_11_10(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb011,OutputDF &dfb101,OutputDF &dfb110,OutputDF &dfb121,OutputDF &dfb211)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b011)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb011.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b011)[0][k][l] = (*u)[1][k][l];
  itemtype (*b101)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb101.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b101)[i][0][l] = (*u)[i][1][l];
  itemtype (*b110)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb110.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b110)[i][k][0] = (*u)[i][k][1];
  itemtype (*b121)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb121.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b121)[i][0][l] = (*u)[i][n1-2][l];
  itemtype (*b211)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb211.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b211)[0][k][l] = (*u)[n0-2][k][l];
}

void c_mesh3d_exchange_6_set_11_11_10(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb011,const InputDF &dfb101,const InputDF &dfb110,const InputDF &dfb121,const InputDF &dfb211,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb011.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b011)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb011.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[0][k][l] = (*b011)[0][k][l];
  assert(dfb101.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b101)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb101.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][0][l] = (*b101)[i][0][l];
  assert(dfb110.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b110)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb110.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][0] = (*b110)[i][k][0];
  assert(dfb121.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b121)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb121.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][n1-1][l] = (*b121)[i][0][l];
  assert(dfb211.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b211)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb211.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[n0-1][k][l] = (*b211)[0][k][l];
}

void c_mesh3d_exchange_6_get_11_11_11(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb011,OutputDF &dfb101,OutputDF &dfb110,OutputDF &dfb112,OutputDF &dfb121,OutputDF &dfb211)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b011)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb011.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b011)[0][k][l] = (*u)[1][k][l];
  itemtype (*b101)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb101.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b101)[i][0][l] = (*u)[i][1][l];
  itemtype (*b110)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb110.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b110)[i][k][0] = (*u)[i][k][1];
  itemtype (*b112)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb112.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b112)[i][k][0] = (*u)[i][k][n2-2];
  itemtype (*b121)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb121.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b121)[i][0][l] = (*u)[i][n1-2][l];
  itemtype (*b211)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb211.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b211)[0][k][l] = (*u)[n0-2][k][l];
}

void c_mesh3d_exchange_6_set_11_11_11(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb011,const InputDF &dfb101,const InputDF &dfb110,const InputDF &dfb112,const InputDF &dfb121,const InputDF &dfb211,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb011.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b011)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb011.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[0][k][l] = (*b011)[0][k][l];
  assert(dfb101.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b101)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb101.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][0][l] = (*b101)[i][0][l];
  assert(dfb110.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b110)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb110.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][0] = (*b110)[i][k][0];
  assert(dfb112.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b112)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb112.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][n2-1] = (*b112)[i][k][0];
  assert(dfb121.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b121)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb121.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][n1-1][l] = (*b121)[i][0][l];
  assert(dfb211.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b211)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb211.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[n0-1][k][l] = (*b211)[0][k][l];
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