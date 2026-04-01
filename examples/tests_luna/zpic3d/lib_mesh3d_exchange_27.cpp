#include "ucenv.h"
#include "lib_basic.h"
typedef real itemtype;

extern "C"
{
void c_mesh3d_exchange_27_copy_00_00_00(int n0,int n1,int n2,const InputDF &dfu,OutputDF &dfv)
{
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  dfv.copy(dfu);
}

void c_mesh3d_exchange_27_get_00_00_01(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb112)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b112)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb112.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b112)[i][k][0] = (*u)[i][k][n2-2];
}

void c_mesh3d_exchange_27_set_00_00_01(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb112,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb112.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b112)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb112.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][n2-1] = (*b112)[i][k][0];
}

void c_mesh3d_exchange_27_get_00_00_10(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb110)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b110)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb110.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b110)[i][k][0] = (*u)[i][k][1];
}

void c_mesh3d_exchange_27_set_00_00_10(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb110,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb110.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b110)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb110.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][0] = (*b110)[i][k][0];
}

void c_mesh3d_exchange_27_get_00_00_11(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb110,OutputDF &dfb112)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b110)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb110.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b110)[i][k][0] = (*u)[i][k][1];
  itemtype (*b112)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb112.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b112)[i][k][0] = (*u)[i][k][n2-2];
}

void c_mesh3d_exchange_27_set_00_00_11(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb110,const InputDF &dfb112,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb110.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b110)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb110.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][0] = (*b110)[i][k][0];
  assert(dfb112.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b112)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb112.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][n2-1] = (*b112)[i][k][0];
}

void c_mesh3d_exchange_27_get_00_01_00(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb121)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b121)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb121.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b121)[i][0][l] = (*u)[i][n1-2][l];
}

void c_mesh3d_exchange_27_set_00_01_00(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb121,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb121.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b121)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb121.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][n1-1][l] = (*b121)[i][0][l];
}

void c_mesh3d_exchange_27_get_00_01_01(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb112,OutputDF &dfb121,OutputDF &dfb122)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b112)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb112.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b112)[i][k][0] = (*u)[i][k][n2-2];
  itemtype (*b121)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb121.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b121)[i][0][l] = (*u)[i][n1-2][l];
  itemtype (*b122)[n0][ 1][ 1] = (itemtype(*)[n0][ 1][ 1])dfb122.create<itemtype>(n0* 1* 1); for (i=0;i<n0;i++) (*b122)[i][0][0] = (*u)[i][n1-2][n2-2];
}

void c_mesh3d_exchange_27_set_00_01_01(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb112,const InputDF &dfb121,const InputDF &dfb122,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb112.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b112)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb112.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][n2-1] = (*b112)[i][k][0];
  assert(dfb121.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b121)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb121.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][n1-1][l] = (*b121)[i][0][l];
  assert(dfb122.getSize() == n0* 1* 1*sizeof(itemtype)); const itemtype (*b122)[n0][ 1][ 1] = (const itemtype(*)[n0][ 1][ 1])dfb122.getData<itemtype>(); for (i=1;i<n0-1;i++) (*v)[i][n1-1][n2-1] = (*b122)[i][0][0];
}

void c_mesh3d_exchange_27_get_00_01_10(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb110,OutputDF &dfb120,OutputDF &dfb121)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b110)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb110.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b110)[i][k][0] = (*u)[i][k][1];
  itemtype (*b120)[n0][ 1][ 1] = (itemtype(*)[n0][ 1][ 1])dfb120.create<itemtype>(n0* 1* 1); for (i=0;i<n0;i++) (*b120)[i][0][0] = (*u)[i][n1-2][1];
  itemtype (*b121)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb121.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b121)[i][0][l] = (*u)[i][n1-2][l];
}

void c_mesh3d_exchange_27_set_00_01_10(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb110,const InputDF &dfb120,const InputDF &dfb121,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb110.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b110)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb110.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][0] = (*b110)[i][k][0];
  assert(dfb120.getSize() == n0* 1* 1*sizeof(itemtype)); const itemtype (*b120)[n0][ 1][ 1] = (const itemtype(*)[n0][ 1][ 1])dfb120.getData<itemtype>(); for (i=1;i<n0-1;i++) (*v)[i][n1-1][0] = (*b120)[i][0][0];
  assert(dfb121.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b121)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb121.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][n1-1][l] = (*b121)[i][0][l];
}

void c_mesh3d_exchange_27_get_00_01_11(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb110,OutputDF &dfb112,OutputDF &dfb120,OutputDF &dfb121,OutputDF &dfb122)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b110)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb110.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b110)[i][k][0] = (*u)[i][k][1];
  itemtype (*b112)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb112.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b112)[i][k][0] = (*u)[i][k][n2-2];
  itemtype (*b120)[n0][ 1][ 1] = (itemtype(*)[n0][ 1][ 1])dfb120.create<itemtype>(n0* 1* 1); for (i=0;i<n0;i++) (*b120)[i][0][0] = (*u)[i][n1-2][1];
  itemtype (*b121)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb121.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b121)[i][0][l] = (*u)[i][n1-2][l];
  itemtype (*b122)[n0][ 1][ 1] = (itemtype(*)[n0][ 1][ 1])dfb122.create<itemtype>(n0* 1* 1); for (i=0;i<n0;i++) (*b122)[i][0][0] = (*u)[i][n1-2][n2-2];
}

void c_mesh3d_exchange_27_set_00_01_11(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb110,const InputDF &dfb112,const InputDF &dfb120,const InputDF &dfb121,const InputDF &dfb122,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb110.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b110)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb110.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][0] = (*b110)[i][k][0];
  assert(dfb112.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b112)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb112.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][n2-1] = (*b112)[i][k][0];
  assert(dfb120.getSize() == n0* 1* 1*sizeof(itemtype)); const itemtype (*b120)[n0][ 1][ 1] = (const itemtype(*)[n0][ 1][ 1])dfb120.getData<itemtype>(); for (i=1;i<n0-1;i++) (*v)[i][n1-1][0] = (*b120)[i][0][0];
  assert(dfb121.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b121)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb121.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][n1-1][l] = (*b121)[i][0][l];
  assert(dfb122.getSize() == n0* 1* 1*sizeof(itemtype)); const itemtype (*b122)[n0][ 1][ 1] = (const itemtype(*)[n0][ 1][ 1])dfb122.getData<itemtype>(); for (i=1;i<n0-1;i++) (*v)[i][n1-1][n2-1] = (*b122)[i][0][0];
}

void c_mesh3d_exchange_27_get_00_10_00(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb101)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b101)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb101.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b101)[i][0][l] = (*u)[i][1][l];
}

void c_mesh3d_exchange_27_set_00_10_00(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb101,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb101.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b101)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb101.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][0][l] = (*b101)[i][0][l];
}

void c_mesh3d_exchange_27_get_00_10_01(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb101,OutputDF &dfb102,OutputDF &dfb112)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b101)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb101.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b101)[i][0][l] = (*u)[i][1][l];
  itemtype (*b102)[n0][ 1][ 1] = (itemtype(*)[n0][ 1][ 1])dfb102.create<itemtype>(n0* 1* 1); for (i=0;i<n0;i++) (*b102)[i][0][0] = (*u)[i][1][n2-2];
  itemtype (*b112)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb112.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b112)[i][k][0] = (*u)[i][k][n2-2];
}

void c_mesh3d_exchange_27_set_00_10_01(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb101,const InputDF &dfb102,const InputDF &dfb112,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb101.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b101)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb101.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][0][l] = (*b101)[i][0][l];
  assert(dfb102.getSize() == n0* 1* 1*sizeof(itemtype)); const itemtype (*b102)[n0][ 1][ 1] = (const itemtype(*)[n0][ 1][ 1])dfb102.getData<itemtype>(); for (i=1;i<n0-1;i++) (*v)[i][0][n2-1] = (*b102)[i][0][0];
  assert(dfb112.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b112)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb112.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][n2-1] = (*b112)[i][k][0];
}

void c_mesh3d_exchange_27_get_00_10_10(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb100,OutputDF &dfb101,OutputDF &dfb110)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b100)[n0][ 1][ 1] = (itemtype(*)[n0][ 1][ 1])dfb100.create<itemtype>(n0* 1* 1); for (i=0;i<n0;i++) (*b100)[i][0][0] = (*u)[i][1][1];
  itemtype (*b101)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb101.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b101)[i][0][l] = (*u)[i][1][l];
  itemtype (*b110)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb110.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b110)[i][k][0] = (*u)[i][k][1];
}

void c_mesh3d_exchange_27_set_00_10_10(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb100,const InputDF &dfb101,const InputDF &dfb110,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb100.getSize() == n0* 1* 1*sizeof(itemtype)); const itemtype (*b100)[n0][ 1][ 1] = (const itemtype(*)[n0][ 1][ 1])dfb100.getData<itemtype>(); for (i=1;i<n0-1;i++) (*v)[i][0][0] = (*b100)[i][0][0];
  assert(dfb101.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b101)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb101.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][0][l] = (*b101)[i][0][l];
  assert(dfb110.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b110)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb110.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][0] = (*b110)[i][k][0];
}

void c_mesh3d_exchange_27_get_00_10_11(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb100,OutputDF &dfb101,OutputDF &dfb102,OutputDF &dfb110,OutputDF &dfb112)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b100)[n0][ 1][ 1] = (itemtype(*)[n0][ 1][ 1])dfb100.create<itemtype>(n0* 1* 1); for (i=0;i<n0;i++) (*b100)[i][0][0] = (*u)[i][1][1];
  itemtype (*b101)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb101.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b101)[i][0][l] = (*u)[i][1][l];
  itemtype (*b102)[n0][ 1][ 1] = (itemtype(*)[n0][ 1][ 1])dfb102.create<itemtype>(n0* 1* 1); for (i=0;i<n0;i++) (*b102)[i][0][0] = (*u)[i][1][n2-2];
  itemtype (*b110)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb110.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b110)[i][k][0] = (*u)[i][k][1];
  itemtype (*b112)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb112.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b112)[i][k][0] = (*u)[i][k][n2-2];
}

void c_mesh3d_exchange_27_set_00_10_11(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb100,const InputDF &dfb101,const InputDF &dfb102,const InputDF &dfb110,const InputDF &dfb112,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb100.getSize() == n0* 1* 1*sizeof(itemtype)); const itemtype (*b100)[n0][ 1][ 1] = (const itemtype(*)[n0][ 1][ 1])dfb100.getData<itemtype>(); for (i=1;i<n0-1;i++) (*v)[i][0][0] = (*b100)[i][0][0];
  assert(dfb101.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b101)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb101.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][0][l] = (*b101)[i][0][l];
  assert(dfb102.getSize() == n0* 1* 1*sizeof(itemtype)); const itemtype (*b102)[n0][ 1][ 1] = (const itemtype(*)[n0][ 1][ 1])dfb102.getData<itemtype>(); for (i=1;i<n0-1;i++) (*v)[i][0][n2-1] = (*b102)[i][0][0];
  assert(dfb110.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b110)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb110.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][0] = (*b110)[i][k][0];
  assert(dfb112.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b112)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb112.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][n2-1] = (*b112)[i][k][0];
}

void c_mesh3d_exchange_27_get_00_11_00(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb101,OutputDF &dfb121)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b101)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb101.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b101)[i][0][l] = (*u)[i][1][l];
  itemtype (*b121)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb121.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b121)[i][0][l] = (*u)[i][n1-2][l];
}

void c_mesh3d_exchange_27_set_00_11_00(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb101,const InputDF &dfb121,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb101.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b101)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb101.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][0][l] = (*b101)[i][0][l];
  assert(dfb121.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b121)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb121.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][n1-1][l] = (*b121)[i][0][l];
}

void c_mesh3d_exchange_27_get_00_11_01(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb101,OutputDF &dfb102,OutputDF &dfb112,OutputDF &dfb121,OutputDF &dfb122)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b101)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb101.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b101)[i][0][l] = (*u)[i][1][l];
  itemtype (*b102)[n0][ 1][ 1] = (itemtype(*)[n0][ 1][ 1])dfb102.create<itemtype>(n0* 1* 1); for (i=0;i<n0;i++) (*b102)[i][0][0] = (*u)[i][1][n2-2];
  itemtype (*b112)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb112.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b112)[i][k][0] = (*u)[i][k][n2-2];
  itemtype (*b121)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb121.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b121)[i][0][l] = (*u)[i][n1-2][l];
  itemtype (*b122)[n0][ 1][ 1] = (itemtype(*)[n0][ 1][ 1])dfb122.create<itemtype>(n0* 1* 1); for (i=0;i<n0;i++) (*b122)[i][0][0] = (*u)[i][n1-2][n2-2];
}

void c_mesh3d_exchange_27_set_00_11_01(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb101,const InputDF &dfb102,const InputDF &dfb112,const InputDF &dfb121,const InputDF &dfb122,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb101.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b101)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb101.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][0][l] = (*b101)[i][0][l];
  assert(dfb102.getSize() == n0* 1* 1*sizeof(itemtype)); const itemtype (*b102)[n0][ 1][ 1] = (const itemtype(*)[n0][ 1][ 1])dfb102.getData<itemtype>(); for (i=1;i<n0-1;i++) (*v)[i][0][n2-1] = (*b102)[i][0][0];
  assert(dfb112.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b112)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb112.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][n2-1] = (*b112)[i][k][0];
  assert(dfb121.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b121)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb121.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][n1-1][l] = (*b121)[i][0][l];
  assert(dfb122.getSize() == n0* 1* 1*sizeof(itemtype)); const itemtype (*b122)[n0][ 1][ 1] = (const itemtype(*)[n0][ 1][ 1])dfb122.getData<itemtype>(); for (i=1;i<n0-1;i++) (*v)[i][n1-1][n2-1] = (*b122)[i][0][0];
}

void c_mesh3d_exchange_27_get_00_11_10(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb100,OutputDF &dfb101,OutputDF &dfb110,OutputDF &dfb120,OutputDF &dfb121)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b100)[n0][ 1][ 1] = (itemtype(*)[n0][ 1][ 1])dfb100.create<itemtype>(n0* 1* 1); for (i=0;i<n0;i++) (*b100)[i][0][0] = (*u)[i][1][1];
  itemtype (*b101)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb101.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b101)[i][0][l] = (*u)[i][1][l];
  itemtype (*b110)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb110.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b110)[i][k][0] = (*u)[i][k][1];
  itemtype (*b120)[n0][ 1][ 1] = (itemtype(*)[n0][ 1][ 1])dfb120.create<itemtype>(n0* 1* 1); for (i=0;i<n0;i++) (*b120)[i][0][0] = (*u)[i][n1-2][1];
  itemtype (*b121)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb121.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b121)[i][0][l] = (*u)[i][n1-2][l];
}

void c_mesh3d_exchange_27_set_00_11_10(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb100,const InputDF &dfb101,const InputDF &dfb110,const InputDF &dfb120,const InputDF &dfb121,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb100.getSize() == n0* 1* 1*sizeof(itemtype)); const itemtype (*b100)[n0][ 1][ 1] = (const itemtype(*)[n0][ 1][ 1])dfb100.getData<itemtype>(); for (i=1;i<n0-1;i++) (*v)[i][0][0] = (*b100)[i][0][0];
  assert(dfb101.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b101)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb101.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][0][l] = (*b101)[i][0][l];
  assert(dfb110.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b110)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb110.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][0] = (*b110)[i][k][0];
  assert(dfb120.getSize() == n0* 1* 1*sizeof(itemtype)); const itemtype (*b120)[n0][ 1][ 1] = (const itemtype(*)[n0][ 1][ 1])dfb120.getData<itemtype>(); for (i=1;i<n0-1;i++) (*v)[i][n1-1][0] = (*b120)[i][0][0];
  assert(dfb121.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b121)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb121.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][n1-1][l] = (*b121)[i][0][l];
}

void c_mesh3d_exchange_27_get_00_11_11(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb100,OutputDF &dfb101,OutputDF &dfb102,OutputDF &dfb110,OutputDF &dfb112,OutputDF &dfb120,OutputDF &dfb121,OutputDF &dfb122)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b100)[n0][ 1][ 1] = (itemtype(*)[n0][ 1][ 1])dfb100.create<itemtype>(n0* 1* 1); for (i=0;i<n0;i++) (*b100)[i][0][0] = (*u)[i][1][1];
  itemtype (*b101)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb101.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b101)[i][0][l] = (*u)[i][1][l];
  itemtype (*b102)[n0][ 1][ 1] = (itemtype(*)[n0][ 1][ 1])dfb102.create<itemtype>(n0* 1* 1); for (i=0;i<n0;i++) (*b102)[i][0][0] = (*u)[i][1][n2-2];
  itemtype (*b110)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb110.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b110)[i][k][0] = (*u)[i][k][1];
  itemtype (*b112)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb112.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b112)[i][k][0] = (*u)[i][k][n2-2];
  itemtype (*b120)[n0][ 1][ 1] = (itemtype(*)[n0][ 1][ 1])dfb120.create<itemtype>(n0* 1* 1); for (i=0;i<n0;i++) (*b120)[i][0][0] = (*u)[i][n1-2][1];
  itemtype (*b121)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb121.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b121)[i][0][l] = (*u)[i][n1-2][l];
  itemtype (*b122)[n0][ 1][ 1] = (itemtype(*)[n0][ 1][ 1])dfb122.create<itemtype>(n0* 1* 1); for (i=0;i<n0;i++) (*b122)[i][0][0] = (*u)[i][n1-2][n2-2];
}

void c_mesh3d_exchange_27_set_00_11_11(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb100,const InputDF &dfb101,const InputDF &dfb102,const InputDF &dfb110,const InputDF &dfb112,const InputDF &dfb120,const InputDF &dfb121,const InputDF &dfb122,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb100.getSize() == n0* 1* 1*sizeof(itemtype)); const itemtype (*b100)[n0][ 1][ 1] = (const itemtype(*)[n0][ 1][ 1])dfb100.getData<itemtype>(); for (i=1;i<n0-1;i++) (*v)[i][0][0] = (*b100)[i][0][0];
  assert(dfb101.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b101)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb101.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][0][l] = (*b101)[i][0][l];
  assert(dfb102.getSize() == n0* 1* 1*sizeof(itemtype)); const itemtype (*b102)[n0][ 1][ 1] = (const itemtype(*)[n0][ 1][ 1])dfb102.getData<itemtype>(); for (i=1;i<n0-1;i++) (*v)[i][0][n2-1] = (*b102)[i][0][0];
  assert(dfb110.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b110)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb110.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][0] = (*b110)[i][k][0];
  assert(dfb112.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b112)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb112.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][n2-1] = (*b112)[i][k][0];
  assert(dfb120.getSize() == n0* 1* 1*sizeof(itemtype)); const itemtype (*b120)[n0][ 1][ 1] = (const itemtype(*)[n0][ 1][ 1])dfb120.getData<itemtype>(); for (i=1;i<n0-1;i++) (*v)[i][n1-1][0] = (*b120)[i][0][0];
  assert(dfb121.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b121)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb121.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][n1-1][l] = (*b121)[i][0][l];
  assert(dfb122.getSize() == n0* 1* 1*sizeof(itemtype)); const itemtype (*b122)[n0][ 1][ 1] = (const itemtype(*)[n0][ 1][ 1])dfb122.getData<itemtype>(); for (i=1;i<n0-1;i++) (*v)[i][n1-1][n2-1] = (*b122)[i][0][0];
}

void c_mesh3d_exchange_27_get_01_00_00(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb211)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b211)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb211.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b211)[0][k][l] = (*u)[n0-2][k][l];
}

void c_mesh3d_exchange_27_set_01_00_00(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb211,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb211.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b211)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb211.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[n0-1][k][l] = (*b211)[0][k][l];
}

void c_mesh3d_exchange_27_get_01_00_01(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb112,OutputDF &dfb211,OutputDF &dfb212)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b112)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb112.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b112)[i][k][0] = (*u)[i][k][n2-2];
  itemtype (*b211)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb211.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b211)[0][k][l] = (*u)[n0-2][k][l];
  itemtype (*b212)[ 1][n1][ 1] = (itemtype(*)[ 1][n1][ 1])dfb212.create<itemtype>( 1*n1* 1); for (k=0;k<n1;k++) (*b212)[0][k][0] = (*u)[n0-2][k][n2-2];
}

void c_mesh3d_exchange_27_set_01_00_01(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb112,const InputDF &dfb211,const InputDF &dfb212,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb112.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b112)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb112.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][n2-1] = (*b112)[i][k][0];
  assert(dfb211.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b211)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb211.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[n0-1][k][l] = (*b211)[0][k][l];
  assert(dfb212.getSize() ==  1*n1* 1*sizeof(itemtype)); const itemtype (*b212)[ 1][n1][ 1] = (const itemtype(*)[ 1][n1][ 1])dfb212.getData<itemtype>(); for (k=1;k<n1-1;k++) (*v)[n0-1][k][n2-1] = (*b212)[0][k][0];
}

void c_mesh3d_exchange_27_get_01_00_10(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb110,OutputDF &dfb210,OutputDF &dfb211)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b110)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb110.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b110)[i][k][0] = (*u)[i][k][1];
  itemtype (*b210)[ 1][n1][ 1] = (itemtype(*)[ 1][n1][ 1])dfb210.create<itemtype>( 1*n1* 1); for (k=0;k<n1;k++) (*b210)[0][k][0] = (*u)[n0-2][k][1];
  itemtype (*b211)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb211.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b211)[0][k][l] = (*u)[n0-2][k][l];
}

void c_mesh3d_exchange_27_set_01_00_10(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb110,const InputDF &dfb210,const InputDF &dfb211,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb110.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b110)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb110.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][0] = (*b110)[i][k][0];
  assert(dfb210.getSize() ==  1*n1* 1*sizeof(itemtype)); const itemtype (*b210)[ 1][n1][ 1] = (const itemtype(*)[ 1][n1][ 1])dfb210.getData<itemtype>(); for (k=1;k<n1-1;k++) (*v)[n0-1][k][0] = (*b210)[0][k][0];
  assert(dfb211.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b211)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb211.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[n0-1][k][l] = (*b211)[0][k][l];
}

void c_mesh3d_exchange_27_get_01_00_11(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb110,OutputDF &dfb112,OutputDF &dfb210,OutputDF &dfb211,OutputDF &dfb212)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b110)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb110.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b110)[i][k][0] = (*u)[i][k][1];
  itemtype (*b112)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb112.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b112)[i][k][0] = (*u)[i][k][n2-2];
  itemtype (*b210)[ 1][n1][ 1] = (itemtype(*)[ 1][n1][ 1])dfb210.create<itemtype>( 1*n1* 1); for (k=0;k<n1;k++) (*b210)[0][k][0] = (*u)[n0-2][k][1];
  itemtype (*b211)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb211.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b211)[0][k][l] = (*u)[n0-2][k][l];
  itemtype (*b212)[ 1][n1][ 1] = (itemtype(*)[ 1][n1][ 1])dfb212.create<itemtype>( 1*n1* 1); for (k=0;k<n1;k++) (*b212)[0][k][0] = (*u)[n0-2][k][n2-2];
}

void c_mesh3d_exchange_27_set_01_00_11(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb110,const InputDF &dfb112,const InputDF &dfb210,const InputDF &dfb211,const InputDF &dfb212,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb110.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b110)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb110.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][0] = (*b110)[i][k][0];
  assert(dfb112.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b112)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb112.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][n2-1] = (*b112)[i][k][0];
  assert(dfb210.getSize() ==  1*n1* 1*sizeof(itemtype)); const itemtype (*b210)[ 1][n1][ 1] = (const itemtype(*)[ 1][n1][ 1])dfb210.getData<itemtype>(); for (k=1;k<n1-1;k++) (*v)[n0-1][k][0] = (*b210)[0][k][0];
  assert(dfb211.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b211)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb211.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[n0-1][k][l] = (*b211)[0][k][l];
  assert(dfb212.getSize() ==  1*n1* 1*sizeof(itemtype)); const itemtype (*b212)[ 1][n1][ 1] = (const itemtype(*)[ 1][n1][ 1])dfb212.getData<itemtype>(); for (k=1;k<n1-1;k++) (*v)[n0-1][k][n2-1] = (*b212)[0][k][0];
}

void c_mesh3d_exchange_27_get_01_01_00(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb121,OutputDF &dfb211,OutputDF &dfb221)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b121)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb121.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b121)[i][0][l] = (*u)[i][n1-2][l];
  itemtype (*b211)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb211.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b211)[0][k][l] = (*u)[n0-2][k][l];
  itemtype (*b221)[ 1][ 1][n2] = (itemtype(*)[ 1][ 1][n2])dfb221.create<itemtype>( 1* 1*n2); for (l=0;l<n2;l++) (*b221)[0][0][l] = (*u)[n0-2][n1-2][l];
}

void c_mesh3d_exchange_27_set_01_01_00(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb121,const InputDF &dfb211,const InputDF &dfb221,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb121.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b121)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb121.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][n1-1][l] = (*b121)[i][0][l];
  assert(dfb211.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b211)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb211.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[n0-1][k][l] = (*b211)[0][k][l];
  assert(dfb221.getSize() ==  1* 1*n2*sizeof(itemtype)); const itemtype (*b221)[ 1][ 1][n2] = (const itemtype(*)[ 1][ 1][n2])dfb221.getData<itemtype>(); for (l=1;l<n2-1;l++) (*v)[n0-1][n1-1][l] = (*b221)[0][0][l];
}

void c_mesh3d_exchange_27_get_01_01_01(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb112,OutputDF &dfb121,OutputDF &dfb122,OutputDF &dfb211,OutputDF &dfb212,OutputDF &dfb221,OutputDF &dfb222)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b112)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb112.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b112)[i][k][0] = (*u)[i][k][n2-2];
  itemtype (*b121)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb121.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b121)[i][0][l] = (*u)[i][n1-2][l];
  itemtype (*b122)[n0][ 1][ 1] = (itemtype(*)[n0][ 1][ 1])dfb122.create<itemtype>(n0* 1* 1); for (i=0;i<n0;i++) (*b122)[i][0][0] = (*u)[i][n1-2][n2-2];
  itemtype (*b211)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb211.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b211)[0][k][l] = (*u)[n0-2][k][l];
  itemtype (*b212)[ 1][n1][ 1] = (itemtype(*)[ 1][n1][ 1])dfb212.create<itemtype>( 1*n1* 1); for (k=0;k<n1;k++) (*b212)[0][k][0] = (*u)[n0-2][k][n2-2];
  itemtype (*b221)[ 1][ 1][n2] = (itemtype(*)[ 1][ 1][n2])dfb221.create<itemtype>( 1* 1*n2); for (l=0;l<n2;l++) (*b221)[0][0][l] = (*u)[n0-2][n1-2][l];
  itemtype (*b222)[ 1][ 1][ 1] = (itemtype(*)[ 1][ 1][ 1])dfb222.create<itemtype>( 1* 1* 1); (*b222)[0][0][0] = (*u)[n0-2][n1-2][n2-2];
}

void c_mesh3d_exchange_27_set_01_01_01(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb112,const InputDF &dfb121,const InputDF &dfb122,const InputDF &dfb211,const InputDF &dfb212,const InputDF &dfb221,const InputDF &dfb222,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb112.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b112)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb112.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][n2-1] = (*b112)[i][k][0];
  assert(dfb121.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b121)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb121.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][n1-1][l] = (*b121)[i][0][l];
  assert(dfb122.getSize() == n0* 1* 1*sizeof(itemtype)); const itemtype (*b122)[n0][ 1][ 1] = (const itemtype(*)[n0][ 1][ 1])dfb122.getData<itemtype>(); for (i=1;i<n0-1;i++) (*v)[i][n1-1][n2-1] = (*b122)[i][0][0];
  assert(dfb211.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b211)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb211.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[n0-1][k][l] = (*b211)[0][k][l];
  assert(dfb212.getSize() ==  1*n1* 1*sizeof(itemtype)); const itemtype (*b212)[ 1][n1][ 1] = (const itemtype(*)[ 1][n1][ 1])dfb212.getData<itemtype>(); for (k=1;k<n1-1;k++) (*v)[n0-1][k][n2-1] = (*b212)[0][k][0];
  assert(dfb221.getSize() ==  1* 1*n2*sizeof(itemtype)); const itemtype (*b221)[ 1][ 1][n2] = (const itemtype(*)[ 1][ 1][n2])dfb221.getData<itemtype>(); for (l=1;l<n2-1;l++) (*v)[n0-1][n1-1][l] = (*b221)[0][0][l];
  assert(dfb222.getSize() ==  1* 1* 1*sizeof(itemtype)); const itemtype (*b222)[ 1][ 1][ 1] = (const itemtype(*)[ 1][ 1][ 1])dfb222.getData<itemtype>(); (*v)[n0-1][n1-1][n2-1] = (*b222)[0][0][0];
}

void c_mesh3d_exchange_27_get_01_01_10(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb110,OutputDF &dfb120,OutputDF &dfb121,OutputDF &dfb210,OutputDF &dfb211,OutputDF &dfb220,OutputDF &dfb221)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b110)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb110.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b110)[i][k][0] = (*u)[i][k][1];
  itemtype (*b120)[n0][ 1][ 1] = (itemtype(*)[n0][ 1][ 1])dfb120.create<itemtype>(n0* 1* 1); for (i=0;i<n0;i++) (*b120)[i][0][0] = (*u)[i][n1-2][1];
  itemtype (*b121)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb121.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b121)[i][0][l] = (*u)[i][n1-2][l];
  itemtype (*b210)[ 1][n1][ 1] = (itemtype(*)[ 1][n1][ 1])dfb210.create<itemtype>( 1*n1* 1); for (k=0;k<n1;k++) (*b210)[0][k][0] = (*u)[n0-2][k][1];
  itemtype (*b211)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb211.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b211)[0][k][l] = (*u)[n0-2][k][l];
  itemtype (*b220)[ 1][ 1][ 1] = (itemtype(*)[ 1][ 1][ 1])dfb220.create<itemtype>( 1* 1* 1); (*b220)[0][0][0] = (*u)[n0-2][n1-2][1];
  itemtype (*b221)[ 1][ 1][n2] = (itemtype(*)[ 1][ 1][n2])dfb221.create<itemtype>( 1* 1*n2); for (l=0;l<n2;l++) (*b221)[0][0][l] = (*u)[n0-2][n1-2][l];
}

void c_mesh3d_exchange_27_set_01_01_10(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb110,const InputDF &dfb120,const InputDF &dfb121,const InputDF &dfb210,const InputDF &dfb211,const InputDF &dfb220,const InputDF &dfb221,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb110.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b110)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb110.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][0] = (*b110)[i][k][0];
  assert(dfb120.getSize() == n0* 1* 1*sizeof(itemtype)); const itemtype (*b120)[n0][ 1][ 1] = (const itemtype(*)[n0][ 1][ 1])dfb120.getData<itemtype>(); for (i=1;i<n0-1;i++) (*v)[i][n1-1][0] = (*b120)[i][0][0];
  assert(dfb121.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b121)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb121.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][n1-1][l] = (*b121)[i][0][l];
  assert(dfb210.getSize() ==  1*n1* 1*sizeof(itemtype)); const itemtype (*b210)[ 1][n1][ 1] = (const itemtype(*)[ 1][n1][ 1])dfb210.getData<itemtype>(); for (k=1;k<n1-1;k++) (*v)[n0-1][k][0] = (*b210)[0][k][0];
  assert(dfb211.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b211)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb211.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[n0-1][k][l] = (*b211)[0][k][l];
  assert(dfb220.getSize() ==  1* 1* 1*sizeof(itemtype)); const itemtype (*b220)[ 1][ 1][ 1] = (const itemtype(*)[ 1][ 1][ 1])dfb220.getData<itemtype>(); (*v)[n0-1][n1-1][0] = (*b220)[0][0][0];
  assert(dfb221.getSize() ==  1* 1*n2*sizeof(itemtype)); const itemtype (*b221)[ 1][ 1][n2] = (const itemtype(*)[ 1][ 1][n2])dfb221.getData<itemtype>(); for (l=1;l<n2-1;l++) (*v)[n0-1][n1-1][l] = (*b221)[0][0][l];
}

void c_mesh3d_exchange_27_get_01_01_11(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb110,OutputDF &dfb112,OutputDF &dfb120,OutputDF &dfb121,OutputDF &dfb122,OutputDF &dfb210,OutputDF &dfb211,OutputDF &dfb212,OutputDF &dfb220,OutputDF &dfb221,OutputDF &dfb222)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b110)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb110.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b110)[i][k][0] = (*u)[i][k][1];
  itemtype (*b112)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb112.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b112)[i][k][0] = (*u)[i][k][n2-2];
  itemtype (*b120)[n0][ 1][ 1] = (itemtype(*)[n0][ 1][ 1])dfb120.create<itemtype>(n0* 1* 1); for (i=0;i<n0;i++) (*b120)[i][0][0] = (*u)[i][n1-2][1];
  itemtype (*b121)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb121.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b121)[i][0][l] = (*u)[i][n1-2][l];
  itemtype (*b122)[n0][ 1][ 1] = (itemtype(*)[n0][ 1][ 1])dfb122.create<itemtype>(n0* 1* 1); for (i=0;i<n0;i++) (*b122)[i][0][0] = (*u)[i][n1-2][n2-2];
  itemtype (*b210)[ 1][n1][ 1] = (itemtype(*)[ 1][n1][ 1])dfb210.create<itemtype>( 1*n1* 1); for (k=0;k<n1;k++) (*b210)[0][k][0] = (*u)[n0-2][k][1];
  itemtype (*b211)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb211.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b211)[0][k][l] = (*u)[n0-2][k][l];
  itemtype (*b212)[ 1][n1][ 1] = (itemtype(*)[ 1][n1][ 1])dfb212.create<itemtype>( 1*n1* 1); for (k=0;k<n1;k++) (*b212)[0][k][0] = (*u)[n0-2][k][n2-2];
  itemtype (*b220)[ 1][ 1][ 1] = (itemtype(*)[ 1][ 1][ 1])dfb220.create<itemtype>( 1* 1* 1); (*b220)[0][0][0] = (*u)[n0-2][n1-2][1];
  itemtype (*b221)[ 1][ 1][n2] = (itemtype(*)[ 1][ 1][n2])dfb221.create<itemtype>( 1* 1*n2); for (l=0;l<n2;l++) (*b221)[0][0][l] = (*u)[n0-2][n1-2][l];
  itemtype (*b222)[ 1][ 1][ 1] = (itemtype(*)[ 1][ 1][ 1])dfb222.create<itemtype>( 1* 1* 1); (*b222)[0][0][0] = (*u)[n0-2][n1-2][n2-2];
}

void c_mesh3d_exchange_27_set_01_01_11(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb110,const InputDF &dfb112,const InputDF &dfb120,const InputDF &dfb121,const InputDF &dfb122,const InputDF &dfb210,const InputDF &dfb211,const InputDF &dfb212,const InputDF &dfb220,const InputDF &dfb221,const InputDF &dfb222,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb110.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b110)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb110.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][0] = (*b110)[i][k][0];
  assert(dfb112.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b112)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb112.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][n2-1] = (*b112)[i][k][0];
  assert(dfb120.getSize() == n0* 1* 1*sizeof(itemtype)); const itemtype (*b120)[n0][ 1][ 1] = (const itemtype(*)[n0][ 1][ 1])dfb120.getData<itemtype>(); for (i=1;i<n0-1;i++) (*v)[i][n1-1][0] = (*b120)[i][0][0];
  assert(dfb121.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b121)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb121.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][n1-1][l] = (*b121)[i][0][l];
  assert(dfb122.getSize() == n0* 1* 1*sizeof(itemtype)); const itemtype (*b122)[n0][ 1][ 1] = (const itemtype(*)[n0][ 1][ 1])dfb122.getData<itemtype>(); for (i=1;i<n0-1;i++) (*v)[i][n1-1][n2-1] = (*b122)[i][0][0];
  assert(dfb210.getSize() ==  1*n1* 1*sizeof(itemtype)); const itemtype (*b210)[ 1][n1][ 1] = (const itemtype(*)[ 1][n1][ 1])dfb210.getData<itemtype>(); for (k=1;k<n1-1;k++) (*v)[n0-1][k][0] = (*b210)[0][k][0];
  assert(dfb211.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b211)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb211.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[n0-1][k][l] = (*b211)[0][k][l];
  assert(dfb212.getSize() ==  1*n1* 1*sizeof(itemtype)); const itemtype (*b212)[ 1][n1][ 1] = (const itemtype(*)[ 1][n1][ 1])dfb212.getData<itemtype>(); for (k=1;k<n1-1;k++) (*v)[n0-1][k][n2-1] = (*b212)[0][k][0];
  assert(dfb220.getSize() ==  1* 1* 1*sizeof(itemtype)); const itemtype (*b220)[ 1][ 1][ 1] = (const itemtype(*)[ 1][ 1][ 1])dfb220.getData<itemtype>(); (*v)[n0-1][n1-1][0] = (*b220)[0][0][0];
  assert(dfb221.getSize() ==  1* 1*n2*sizeof(itemtype)); const itemtype (*b221)[ 1][ 1][n2] = (const itemtype(*)[ 1][ 1][n2])dfb221.getData<itemtype>(); for (l=1;l<n2-1;l++) (*v)[n0-1][n1-1][l] = (*b221)[0][0][l];
  assert(dfb222.getSize() ==  1* 1* 1*sizeof(itemtype)); const itemtype (*b222)[ 1][ 1][ 1] = (const itemtype(*)[ 1][ 1][ 1])dfb222.getData<itemtype>(); (*v)[n0-1][n1-1][n2-1] = (*b222)[0][0][0];
}

void c_mesh3d_exchange_27_get_01_10_00(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb101,OutputDF &dfb201,OutputDF &dfb211)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b101)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb101.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b101)[i][0][l] = (*u)[i][1][l];
  itemtype (*b201)[ 1][ 1][n2] = (itemtype(*)[ 1][ 1][n2])dfb201.create<itemtype>( 1* 1*n2); for (l=0;l<n2;l++) (*b201)[0][0][l] = (*u)[n0-2][1][l];
  itemtype (*b211)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb211.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b211)[0][k][l] = (*u)[n0-2][k][l];
}

void c_mesh3d_exchange_27_set_01_10_00(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb101,const InputDF &dfb201,const InputDF &dfb211,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb101.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b101)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb101.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][0][l] = (*b101)[i][0][l];
  assert(dfb201.getSize() ==  1* 1*n2*sizeof(itemtype)); const itemtype (*b201)[ 1][ 1][n2] = (const itemtype(*)[ 1][ 1][n2])dfb201.getData<itemtype>(); for (l=1;l<n2-1;l++) (*v)[n0-1][0][l] = (*b201)[0][0][l];
  assert(dfb211.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b211)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb211.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[n0-1][k][l] = (*b211)[0][k][l];
}

void c_mesh3d_exchange_27_get_01_10_01(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb101,OutputDF &dfb102,OutputDF &dfb112,OutputDF &dfb201,OutputDF &dfb202,OutputDF &dfb211,OutputDF &dfb212)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b101)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb101.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b101)[i][0][l] = (*u)[i][1][l];
  itemtype (*b102)[n0][ 1][ 1] = (itemtype(*)[n0][ 1][ 1])dfb102.create<itemtype>(n0* 1* 1); for (i=0;i<n0;i++) (*b102)[i][0][0] = (*u)[i][1][n2-2];
  itemtype (*b112)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb112.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b112)[i][k][0] = (*u)[i][k][n2-2];
  itemtype (*b201)[ 1][ 1][n2] = (itemtype(*)[ 1][ 1][n2])dfb201.create<itemtype>( 1* 1*n2); for (l=0;l<n2;l++) (*b201)[0][0][l] = (*u)[n0-2][1][l];
  itemtype (*b202)[ 1][ 1][ 1] = (itemtype(*)[ 1][ 1][ 1])dfb202.create<itemtype>( 1* 1* 1); (*b202)[0][0][0] = (*u)[n0-2][1][n2-2];
  itemtype (*b211)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb211.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b211)[0][k][l] = (*u)[n0-2][k][l];
  itemtype (*b212)[ 1][n1][ 1] = (itemtype(*)[ 1][n1][ 1])dfb212.create<itemtype>( 1*n1* 1); for (k=0;k<n1;k++) (*b212)[0][k][0] = (*u)[n0-2][k][n2-2];
}

void c_mesh3d_exchange_27_set_01_10_01(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb101,const InputDF &dfb102,const InputDF &dfb112,const InputDF &dfb201,const InputDF &dfb202,const InputDF &dfb211,const InputDF &dfb212,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb101.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b101)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb101.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][0][l] = (*b101)[i][0][l];
  assert(dfb102.getSize() == n0* 1* 1*sizeof(itemtype)); const itemtype (*b102)[n0][ 1][ 1] = (const itemtype(*)[n0][ 1][ 1])dfb102.getData<itemtype>(); for (i=1;i<n0-1;i++) (*v)[i][0][n2-1] = (*b102)[i][0][0];
  assert(dfb112.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b112)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb112.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][n2-1] = (*b112)[i][k][0];
  assert(dfb201.getSize() ==  1* 1*n2*sizeof(itemtype)); const itemtype (*b201)[ 1][ 1][n2] = (const itemtype(*)[ 1][ 1][n2])dfb201.getData<itemtype>(); for (l=1;l<n2-1;l++) (*v)[n0-1][0][l] = (*b201)[0][0][l];
  assert(dfb202.getSize() ==  1* 1* 1*sizeof(itemtype)); const itemtype (*b202)[ 1][ 1][ 1] = (const itemtype(*)[ 1][ 1][ 1])dfb202.getData<itemtype>(); (*v)[n0-1][0][n2-1] = (*b202)[0][0][0];
  assert(dfb211.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b211)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb211.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[n0-1][k][l] = (*b211)[0][k][l];
  assert(dfb212.getSize() ==  1*n1* 1*sizeof(itemtype)); const itemtype (*b212)[ 1][n1][ 1] = (const itemtype(*)[ 1][n1][ 1])dfb212.getData<itemtype>(); for (k=1;k<n1-1;k++) (*v)[n0-1][k][n2-1] = (*b212)[0][k][0];
}

void c_mesh3d_exchange_27_get_01_10_10(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb100,OutputDF &dfb101,OutputDF &dfb110,OutputDF &dfb200,OutputDF &dfb201,OutputDF &dfb210,OutputDF &dfb211)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b100)[n0][ 1][ 1] = (itemtype(*)[n0][ 1][ 1])dfb100.create<itemtype>(n0* 1* 1); for (i=0;i<n0;i++) (*b100)[i][0][0] = (*u)[i][1][1];
  itemtype (*b101)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb101.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b101)[i][0][l] = (*u)[i][1][l];
  itemtype (*b110)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb110.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b110)[i][k][0] = (*u)[i][k][1];
  itemtype (*b200)[ 1][ 1][ 1] = (itemtype(*)[ 1][ 1][ 1])dfb200.create<itemtype>( 1* 1* 1); (*b200)[0][0][0] = (*u)[n0-2][1][1];
  itemtype (*b201)[ 1][ 1][n2] = (itemtype(*)[ 1][ 1][n2])dfb201.create<itemtype>( 1* 1*n2); for (l=0;l<n2;l++) (*b201)[0][0][l] = (*u)[n0-2][1][l];
  itemtype (*b210)[ 1][n1][ 1] = (itemtype(*)[ 1][n1][ 1])dfb210.create<itemtype>( 1*n1* 1); for (k=0;k<n1;k++) (*b210)[0][k][0] = (*u)[n0-2][k][1];
  itemtype (*b211)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb211.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b211)[0][k][l] = (*u)[n0-2][k][l];
}

void c_mesh3d_exchange_27_set_01_10_10(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb100,const InputDF &dfb101,const InputDF &dfb110,const InputDF &dfb200,const InputDF &dfb201,const InputDF &dfb210,const InputDF &dfb211,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb100.getSize() == n0* 1* 1*sizeof(itemtype)); const itemtype (*b100)[n0][ 1][ 1] = (const itemtype(*)[n0][ 1][ 1])dfb100.getData<itemtype>(); for (i=1;i<n0-1;i++) (*v)[i][0][0] = (*b100)[i][0][0];
  assert(dfb101.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b101)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb101.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][0][l] = (*b101)[i][0][l];
  assert(dfb110.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b110)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb110.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][0] = (*b110)[i][k][0];
  assert(dfb200.getSize() ==  1* 1* 1*sizeof(itemtype)); const itemtype (*b200)[ 1][ 1][ 1] = (const itemtype(*)[ 1][ 1][ 1])dfb200.getData<itemtype>(); (*v)[n0-1][0][0] = (*b200)[0][0][0];
  assert(dfb201.getSize() ==  1* 1*n2*sizeof(itemtype)); const itemtype (*b201)[ 1][ 1][n2] = (const itemtype(*)[ 1][ 1][n2])dfb201.getData<itemtype>(); for (l=1;l<n2-1;l++) (*v)[n0-1][0][l] = (*b201)[0][0][l];
  assert(dfb210.getSize() ==  1*n1* 1*sizeof(itemtype)); const itemtype (*b210)[ 1][n1][ 1] = (const itemtype(*)[ 1][n1][ 1])dfb210.getData<itemtype>(); for (k=1;k<n1-1;k++) (*v)[n0-1][k][0] = (*b210)[0][k][0];
  assert(dfb211.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b211)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb211.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[n0-1][k][l] = (*b211)[0][k][l];
}

void c_mesh3d_exchange_27_get_01_10_11(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb100,OutputDF &dfb101,OutputDF &dfb102,OutputDF &dfb110,OutputDF &dfb112,OutputDF &dfb200,OutputDF &dfb201,OutputDF &dfb202,OutputDF &dfb210,OutputDF &dfb211,OutputDF &dfb212)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b100)[n0][ 1][ 1] = (itemtype(*)[n0][ 1][ 1])dfb100.create<itemtype>(n0* 1* 1); for (i=0;i<n0;i++) (*b100)[i][0][0] = (*u)[i][1][1];
  itemtype (*b101)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb101.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b101)[i][0][l] = (*u)[i][1][l];
  itemtype (*b102)[n0][ 1][ 1] = (itemtype(*)[n0][ 1][ 1])dfb102.create<itemtype>(n0* 1* 1); for (i=0;i<n0;i++) (*b102)[i][0][0] = (*u)[i][1][n2-2];
  itemtype (*b110)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb110.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b110)[i][k][0] = (*u)[i][k][1];
  itemtype (*b112)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb112.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b112)[i][k][0] = (*u)[i][k][n2-2];
  itemtype (*b200)[ 1][ 1][ 1] = (itemtype(*)[ 1][ 1][ 1])dfb200.create<itemtype>( 1* 1* 1); (*b200)[0][0][0] = (*u)[n0-2][1][1];
  itemtype (*b201)[ 1][ 1][n2] = (itemtype(*)[ 1][ 1][n2])dfb201.create<itemtype>( 1* 1*n2); for (l=0;l<n2;l++) (*b201)[0][0][l] = (*u)[n0-2][1][l];
  itemtype (*b202)[ 1][ 1][ 1] = (itemtype(*)[ 1][ 1][ 1])dfb202.create<itemtype>( 1* 1* 1); (*b202)[0][0][0] = (*u)[n0-2][1][n2-2];
  itemtype (*b210)[ 1][n1][ 1] = (itemtype(*)[ 1][n1][ 1])dfb210.create<itemtype>( 1*n1* 1); for (k=0;k<n1;k++) (*b210)[0][k][0] = (*u)[n0-2][k][1];
  itemtype (*b211)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb211.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b211)[0][k][l] = (*u)[n0-2][k][l];
  itemtype (*b212)[ 1][n1][ 1] = (itemtype(*)[ 1][n1][ 1])dfb212.create<itemtype>( 1*n1* 1); for (k=0;k<n1;k++) (*b212)[0][k][0] = (*u)[n0-2][k][n2-2];
}

void c_mesh3d_exchange_27_set_01_10_11(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb100,const InputDF &dfb101,const InputDF &dfb102,const InputDF &dfb110,const InputDF &dfb112,const InputDF &dfb200,const InputDF &dfb201,const InputDF &dfb202,const InputDF &dfb210,const InputDF &dfb211,const InputDF &dfb212,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb100.getSize() == n0* 1* 1*sizeof(itemtype)); const itemtype (*b100)[n0][ 1][ 1] = (const itemtype(*)[n0][ 1][ 1])dfb100.getData<itemtype>(); for (i=1;i<n0-1;i++) (*v)[i][0][0] = (*b100)[i][0][0];
  assert(dfb101.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b101)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb101.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][0][l] = (*b101)[i][0][l];
  assert(dfb102.getSize() == n0* 1* 1*sizeof(itemtype)); const itemtype (*b102)[n0][ 1][ 1] = (const itemtype(*)[n0][ 1][ 1])dfb102.getData<itemtype>(); for (i=1;i<n0-1;i++) (*v)[i][0][n2-1] = (*b102)[i][0][0];
  assert(dfb110.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b110)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb110.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][0] = (*b110)[i][k][0];
  assert(dfb112.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b112)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb112.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][n2-1] = (*b112)[i][k][0];
  assert(dfb200.getSize() ==  1* 1* 1*sizeof(itemtype)); const itemtype (*b200)[ 1][ 1][ 1] = (const itemtype(*)[ 1][ 1][ 1])dfb200.getData<itemtype>(); (*v)[n0-1][0][0] = (*b200)[0][0][0];
  assert(dfb201.getSize() ==  1* 1*n2*sizeof(itemtype)); const itemtype (*b201)[ 1][ 1][n2] = (const itemtype(*)[ 1][ 1][n2])dfb201.getData<itemtype>(); for (l=1;l<n2-1;l++) (*v)[n0-1][0][l] = (*b201)[0][0][l];
  assert(dfb202.getSize() ==  1* 1* 1*sizeof(itemtype)); const itemtype (*b202)[ 1][ 1][ 1] = (const itemtype(*)[ 1][ 1][ 1])dfb202.getData<itemtype>(); (*v)[n0-1][0][n2-1] = (*b202)[0][0][0];
  assert(dfb210.getSize() ==  1*n1* 1*sizeof(itemtype)); const itemtype (*b210)[ 1][n1][ 1] = (const itemtype(*)[ 1][n1][ 1])dfb210.getData<itemtype>(); for (k=1;k<n1-1;k++) (*v)[n0-1][k][0] = (*b210)[0][k][0];
  assert(dfb211.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b211)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb211.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[n0-1][k][l] = (*b211)[0][k][l];
  assert(dfb212.getSize() ==  1*n1* 1*sizeof(itemtype)); const itemtype (*b212)[ 1][n1][ 1] = (const itemtype(*)[ 1][n1][ 1])dfb212.getData<itemtype>(); for (k=1;k<n1-1;k++) (*v)[n0-1][k][n2-1] = (*b212)[0][k][0];
}

void c_mesh3d_exchange_27_get_01_11_00(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb101,OutputDF &dfb121,OutputDF &dfb201,OutputDF &dfb211,OutputDF &dfb221)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b101)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb101.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b101)[i][0][l] = (*u)[i][1][l];
  itemtype (*b121)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb121.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b121)[i][0][l] = (*u)[i][n1-2][l];
  itemtype (*b201)[ 1][ 1][n2] = (itemtype(*)[ 1][ 1][n2])dfb201.create<itemtype>( 1* 1*n2); for (l=0;l<n2;l++) (*b201)[0][0][l] = (*u)[n0-2][1][l];
  itemtype (*b211)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb211.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b211)[0][k][l] = (*u)[n0-2][k][l];
  itemtype (*b221)[ 1][ 1][n2] = (itemtype(*)[ 1][ 1][n2])dfb221.create<itemtype>( 1* 1*n2); for (l=0;l<n2;l++) (*b221)[0][0][l] = (*u)[n0-2][n1-2][l];
}

void c_mesh3d_exchange_27_set_01_11_00(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb101,const InputDF &dfb121,const InputDF &dfb201,const InputDF &dfb211,const InputDF &dfb221,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb101.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b101)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb101.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][0][l] = (*b101)[i][0][l];
  assert(dfb121.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b121)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb121.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][n1-1][l] = (*b121)[i][0][l];
  assert(dfb201.getSize() ==  1* 1*n2*sizeof(itemtype)); const itemtype (*b201)[ 1][ 1][n2] = (const itemtype(*)[ 1][ 1][n2])dfb201.getData<itemtype>(); for (l=1;l<n2-1;l++) (*v)[n0-1][0][l] = (*b201)[0][0][l];
  assert(dfb211.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b211)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb211.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[n0-1][k][l] = (*b211)[0][k][l];
  assert(dfb221.getSize() ==  1* 1*n2*sizeof(itemtype)); const itemtype (*b221)[ 1][ 1][n2] = (const itemtype(*)[ 1][ 1][n2])dfb221.getData<itemtype>(); for (l=1;l<n2-1;l++) (*v)[n0-1][n1-1][l] = (*b221)[0][0][l];
}

void c_mesh3d_exchange_27_get_01_11_01(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb101,OutputDF &dfb102,OutputDF &dfb112,OutputDF &dfb121,OutputDF &dfb122,OutputDF &dfb201,OutputDF &dfb202,OutputDF &dfb211,OutputDF &dfb212,OutputDF &dfb221,OutputDF &dfb222)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b101)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb101.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b101)[i][0][l] = (*u)[i][1][l];
  itemtype (*b102)[n0][ 1][ 1] = (itemtype(*)[n0][ 1][ 1])dfb102.create<itemtype>(n0* 1* 1); for (i=0;i<n0;i++) (*b102)[i][0][0] = (*u)[i][1][n2-2];
  itemtype (*b112)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb112.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b112)[i][k][0] = (*u)[i][k][n2-2];
  itemtype (*b121)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb121.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b121)[i][0][l] = (*u)[i][n1-2][l];
  itemtype (*b122)[n0][ 1][ 1] = (itemtype(*)[n0][ 1][ 1])dfb122.create<itemtype>(n0* 1* 1); for (i=0;i<n0;i++) (*b122)[i][0][0] = (*u)[i][n1-2][n2-2];
  itemtype (*b201)[ 1][ 1][n2] = (itemtype(*)[ 1][ 1][n2])dfb201.create<itemtype>( 1* 1*n2); for (l=0;l<n2;l++) (*b201)[0][0][l] = (*u)[n0-2][1][l];
  itemtype (*b202)[ 1][ 1][ 1] = (itemtype(*)[ 1][ 1][ 1])dfb202.create<itemtype>( 1* 1* 1); (*b202)[0][0][0] = (*u)[n0-2][1][n2-2];
  itemtype (*b211)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb211.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b211)[0][k][l] = (*u)[n0-2][k][l];
  itemtype (*b212)[ 1][n1][ 1] = (itemtype(*)[ 1][n1][ 1])dfb212.create<itemtype>( 1*n1* 1); for (k=0;k<n1;k++) (*b212)[0][k][0] = (*u)[n0-2][k][n2-2];
  itemtype (*b221)[ 1][ 1][n2] = (itemtype(*)[ 1][ 1][n2])dfb221.create<itemtype>( 1* 1*n2); for (l=0;l<n2;l++) (*b221)[0][0][l] = (*u)[n0-2][n1-2][l];
  itemtype (*b222)[ 1][ 1][ 1] = (itemtype(*)[ 1][ 1][ 1])dfb222.create<itemtype>( 1* 1* 1); (*b222)[0][0][0] = (*u)[n0-2][n1-2][n2-2];
}

void c_mesh3d_exchange_27_set_01_11_01(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb101,const InputDF &dfb102,const InputDF &dfb112,const InputDF &dfb121,const InputDF &dfb122,const InputDF &dfb201,const InputDF &dfb202,const InputDF &dfb211,const InputDF &dfb212,const InputDF &dfb221,const InputDF &dfb222,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb101.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b101)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb101.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][0][l] = (*b101)[i][0][l];
  assert(dfb102.getSize() == n0* 1* 1*sizeof(itemtype)); const itemtype (*b102)[n0][ 1][ 1] = (const itemtype(*)[n0][ 1][ 1])dfb102.getData<itemtype>(); for (i=1;i<n0-1;i++) (*v)[i][0][n2-1] = (*b102)[i][0][0];
  assert(dfb112.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b112)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb112.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][n2-1] = (*b112)[i][k][0];
  assert(dfb121.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b121)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb121.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][n1-1][l] = (*b121)[i][0][l];
  assert(dfb122.getSize() == n0* 1* 1*sizeof(itemtype)); const itemtype (*b122)[n0][ 1][ 1] = (const itemtype(*)[n0][ 1][ 1])dfb122.getData<itemtype>(); for (i=1;i<n0-1;i++) (*v)[i][n1-1][n2-1] = (*b122)[i][0][0];
  assert(dfb201.getSize() ==  1* 1*n2*sizeof(itemtype)); const itemtype (*b201)[ 1][ 1][n2] = (const itemtype(*)[ 1][ 1][n2])dfb201.getData<itemtype>(); for (l=1;l<n2-1;l++) (*v)[n0-1][0][l] = (*b201)[0][0][l];
  assert(dfb202.getSize() ==  1* 1* 1*sizeof(itemtype)); const itemtype (*b202)[ 1][ 1][ 1] = (const itemtype(*)[ 1][ 1][ 1])dfb202.getData<itemtype>(); (*v)[n0-1][0][n2-1] = (*b202)[0][0][0];
  assert(dfb211.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b211)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb211.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[n0-1][k][l] = (*b211)[0][k][l];
  assert(dfb212.getSize() ==  1*n1* 1*sizeof(itemtype)); const itemtype (*b212)[ 1][n1][ 1] = (const itemtype(*)[ 1][n1][ 1])dfb212.getData<itemtype>(); for (k=1;k<n1-1;k++) (*v)[n0-1][k][n2-1] = (*b212)[0][k][0];
  assert(dfb221.getSize() ==  1* 1*n2*sizeof(itemtype)); const itemtype (*b221)[ 1][ 1][n2] = (const itemtype(*)[ 1][ 1][n2])dfb221.getData<itemtype>(); for (l=1;l<n2-1;l++) (*v)[n0-1][n1-1][l] = (*b221)[0][0][l];
  assert(dfb222.getSize() ==  1* 1* 1*sizeof(itemtype)); const itemtype (*b222)[ 1][ 1][ 1] = (const itemtype(*)[ 1][ 1][ 1])dfb222.getData<itemtype>(); (*v)[n0-1][n1-1][n2-1] = (*b222)[0][0][0];
}

void c_mesh3d_exchange_27_get_01_11_10(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb100,OutputDF &dfb101,OutputDF &dfb110,OutputDF &dfb120,OutputDF &dfb121,OutputDF &dfb200,OutputDF &dfb201,OutputDF &dfb210,OutputDF &dfb211,OutputDF &dfb220,OutputDF &dfb221)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b100)[n0][ 1][ 1] = (itemtype(*)[n0][ 1][ 1])dfb100.create<itemtype>(n0* 1* 1); for (i=0;i<n0;i++) (*b100)[i][0][0] = (*u)[i][1][1];
  itemtype (*b101)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb101.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b101)[i][0][l] = (*u)[i][1][l];
  itemtype (*b110)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb110.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b110)[i][k][0] = (*u)[i][k][1];
  itemtype (*b120)[n0][ 1][ 1] = (itemtype(*)[n0][ 1][ 1])dfb120.create<itemtype>(n0* 1* 1); for (i=0;i<n0;i++) (*b120)[i][0][0] = (*u)[i][n1-2][1];
  itemtype (*b121)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb121.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b121)[i][0][l] = (*u)[i][n1-2][l];
  itemtype (*b200)[ 1][ 1][ 1] = (itemtype(*)[ 1][ 1][ 1])dfb200.create<itemtype>( 1* 1* 1); (*b200)[0][0][0] = (*u)[n0-2][1][1];
  itemtype (*b201)[ 1][ 1][n2] = (itemtype(*)[ 1][ 1][n2])dfb201.create<itemtype>( 1* 1*n2); for (l=0;l<n2;l++) (*b201)[0][0][l] = (*u)[n0-2][1][l];
  itemtype (*b210)[ 1][n1][ 1] = (itemtype(*)[ 1][n1][ 1])dfb210.create<itemtype>( 1*n1* 1); for (k=0;k<n1;k++) (*b210)[0][k][0] = (*u)[n0-2][k][1];
  itemtype (*b211)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb211.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b211)[0][k][l] = (*u)[n0-2][k][l];
  itemtype (*b220)[ 1][ 1][ 1] = (itemtype(*)[ 1][ 1][ 1])dfb220.create<itemtype>( 1* 1* 1); (*b220)[0][0][0] = (*u)[n0-2][n1-2][1];
  itemtype (*b221)[ 1][ 1][n2] = (itemtype(*)[ 1][ 1][n2])dfb221.create<itemtype>( 1* 1*n2); for (l=0;l<n2;l++) (*b221)[0][0][l] = (*u)[n0-2][n1-2][l];
}

void c_mesh3d_exchange_27_set_01_11_10(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb100,const InputDF &dfb101,const InputDF &dfb110,const InputDF &dfb120,const InputDF &dfb121,const InputDF &dfb200,const InputDF &dfb201,const InputDF &dfb210,const InputDF &dfb211,const InputDF &dfb220,const InputDF &dfb221,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb100.getSize() == n0* 1* 1*sizeof(itemtype)); const itemtype (*b100)[n0][ 1][ 1] = (const itemtype(*)[n0][ 1][ 1])dfb100.getData<itemtype>(); for (i=1;i<n0-1;i++) (*v)[i][0][0] = (*b100)[i][0][0];
  assert(dfb101.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b101)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb101.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][0][l] = (*b101)[i][0][l];
  assert(dfb110.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b110)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb110.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][0] = (*b110)[i][k][0];
  assert(dfb120.getSize() == n0* 1* 1*sizeof(itemtype)); const itemtype (*b120)[n0][ 1][ 1] = (const itemtype(*)[n0][ 1][ 1])dfb120.getData<itemtype>(); for (i=1;i<n0-1;i++) (*v)[i][n1-1][0] = (*b120)[i][0][0];
  assert(dfb121.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b121)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb121.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][n1-1][l] = (*b121)[i][0][l];
  assert(dfb200.getSize() ==  1* 1* 1*sizeof(itemtype)); const itemtype (*b200)[ 1][ 1][ 1] = (const itemtype(*)[ 1][ 1][ 1])dfb200.getData<itemtype>(); (*v)[n0-1][0][0] = (*b200)[0][0][0];
  assert(dfb201.getSize() ==  1* 1*n2*sizeof(itemtype)); const itemtype (*b201)[ 1][ 1][n2] = (const itemtype(*)[ 1][ 1][n2])dfb201.getData<itemtype>(); for (l=1;l<n2-1;l++) (*v)[n0-1][0][l] = (*b201)[0][0][l];
  assert(dfb210.getSize() ==  1*n1* 1*sizeof(itemtype)); const itemtype (*b210)[ 1][n1][ 1] = (const itemtype(*)[ 1][n1][ 1])dfb210.getData<itemtype>(); for (k=1;k<n1-1;k++) (*v)[n0-1][k][0] = (*b210)[0][k][0];
  assert(dfb211.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b211)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb211.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[n0-1][k][l] = (*b211)[0][k][l];
  assert(dfb220.getSize() ==  1* 1* 1*sizeof(itemtype)); const itemtype (*b220)[ 1][ 1][ 1] = (const itemtype(*)[ 1][ 1][ 1])dfb220.getData<itemtype>(); (*v)[n0-1][n1-1][0] = (*b220)[0][0][0];
  assert(dfb221.getSize() ==  1* 1*n2*sizeof(itemtype)); const itemtype (*b221)[ 1][ 1][n2] = (const itemtype(*)[ 1][ 1][n2])dfb221.getData<itemtype>(); for (l=1;l<n2-1;l++) (*v)[n0-1][n1-1][l] = (*b221)[0][0][l];
}

void c_mesh3d_exchange_27_get_01_11_11(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb100,OutputDF &dfb101,OutputDF &dfb102,OutputDF &dfb110,OutputDF &dfb112,OutputDF &dfb120,OutputDF &dfb121,OutputDF &dfb122,OutputDF &dfb200,OutputDF &dfb201,OutputDF &dfb202,OutputDF &dfb210,OutputDF &dfb211,OutputDF &dfb212,OutputDF &dfb220,OutputDF &dfb221,OutputDF &dfb222)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b100)[n0][ 1][ 1] = (itemtype(*)[n0][ 1][ 1])dfb100.create<itemtype>(n0* 1* 1); for (i=0;i<n0;i++) (*b100)[i][0][0] = (*u)[i][1][1];
  itemtype (*b101)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb101.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b101)[i][0][l] = (*u)[i][1][l];
  itemtype (*b102)[n0][ 1][ 1] = (itemtype(*)[n0][ 1][ 1])dfb102.create<itemtype>(n0* 1* 1); for (i=0;i<n0;i++) (*b102)[i][0][0] = (*u)[i][1][n2-2];
  itemtype (*b110)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb110.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b110)[i][k][0] = (*u)[i][k][1];
  itemtype (*b112)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb112.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b112)[i][k][0] = (*u)[i][k][n2-2];
  itemtype (*b120)[n0][ 1][ 1] = (itemtype(*)[n0][ 1][ 1])dfb120.create<itemtype>(n0* 1* 1); for (i=0;i<n0;i++) (*b120)[i][0][0] = (*u)[i][n1-2][1];
  itemtype (*b121)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb121.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b121)[i][0][l] = (*u)[i][n1-2][l];
  itemtype (*b122)[n0][ 1][ 1] = (itemtype(*)[n0][ 1][ 1])dfb122.create<itemtype>(n0* 1* 1); for (i=0;i<n0;i++) (*b122)[i][0][0] = (*u)[i][n1-2][n2-2];
  itemtype (*b200)[ 1][ 1][ 1] = (itemtype(*)[ 1][ 1][ 1])dfb200.create<itemtype>( 1* 1* 1); (*b200)[0][0][0] = (*u)[n0-2][1][1];
  itemtype (*b201)[ 1][ 1][n2] = (itemtype(*)[ 1][ 1][n2])dfb201.create<itemtype>( 1* 1*n2); for (l=0;l<n2;l++) (*b201)[0][0][l] = (*u)[n0-2][1][l];
  itemtype (*b202)[ 1][ 1][ 1] = (itemtype(*)[ 1][ 1][ 1])dfb202.create<itemtype>( 1* 1* 1); (*b202)[0][0][0] = (*u)[n0-2][1][n2-2];
  itemtype (*b210)[ 1][n1][ 1] = (itemtype(*)[ 1][n1][ 1])dfb210.create<itemtype>( 1*n1* 1); for (k=0;k<n1;k++) (*b210)[0][k][0] = (*u)[n0-2][k][1];
  itemtype (*b211)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb211.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b211)[0][k][l] = (*u)[n0-2][k][l];
  itemtype (*b212)[ 1][n1][ 1] = (itemtype(*)[ 1][n1][ 1])dfb212.create<itemtype>( 1*n1* 1); for (k=0;k<n1;k++) (*b212)[0][k][0] = (*u)[n0-2][k][n2-2];
  itemtype (*b220)[ 1][ 1][ 1] = (itemtype(*)[ 1][ 1][ 1])dfb220.create<itemtype>( 1* 1* 1); (*b220)[0][0][0] = (*u)[n0-2][n1-2][1];
  itemtype (*b221)[ 1][ 1][n2] = (itemtype(*)[ 1][ 1][n2])dfb221.create<itemtype>( 1* 1*n2); for (l=0;l<n2;l++) (*b221)[0][0][l] = (*u)[n0-2][n1-2][l];
  itemtype (*b222)[ 1][ 1][ 1] = (itemtype(*)[ 1][ 1][ 1])dfb222.create<itemtype>( 1* 1* 1); (*b222)[0][0][0] = (*u)[n0-2][n1-2][n2-2];
}

void c_mesh3d_exchange_27_set_01_11_11(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb100,const InputDF &dfb101,const InputDF &dfb102,const InputDF &dfb110,const InputDF &dfb112,const InputDF &dfb120,const InputDF &dfb121,const InputDF &dfb122,const InputDF &dfb200,const InputDF &dfb201,const InputDF &dfb202,const InputDF &dfb210,const InputDF &dfb211,const InputDF &dfb212,const InputDF &dfb220,const InputDF &dfb221,const InputDF &dfb222,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb100.getSize() == n0* 1* 1*sizeof(itemtype)); const itemtype (*b100)[n0][ 1][ 1] = (const itemtype(*)[n0][ 1][ 1])dfb100.getData<itemtype>(); for (i=1;i<n0-1;i++) (*v)[i][0][0] = (*b100)[i][0][0];
  assert(dfb101.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b101)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb101.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][0][l] = (*b101)[i][0][l];
  assert(dfb102.getSize() == n0* 1* 1*sizeof(itemtype)); const itemtype (*b102)[n0][ 1][ 1] = (const itemtype(*)[n0][ 1][ 1])dfb102.getData<itemtype>(); for (i=1;i<n0-1;i++) (*v)[i][0][n2-1] = (*b102)[i][0][0];
  assert(dfb110.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b110)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb110.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][0] = (*b110)[i][k][0];
  assert(dfb112.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b112)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb112.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][n2-1] = (*b112)[i][k][0];
  assert(dfb120.getSize() == n0* 1* 1*sizeof(itemtype)); const itemtype (*b120)[n0][ 1][ 1] = (const itemtype(*)[n0][ 1][ 1])dfb120.getData<itemtype>(); for (i=1;i<n0-1;i++) (*v)[i][n1-1][0] = (*b120)[i][0][0];
  assert(dfb121.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b121)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb121.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][n1-1][l] = (*b121)[i][0][l];
  assert(dfb122.getSize() == n0* 1* 1*sizeof(itemtype)); const itemtype (*b122)[n0][ 1][ 1] = (const itemtype(*)[n0][ 1][ 1])dfb122.getData<itemtype>(); for (i=1;i<n0-1;i++) (*v)[i][n1-1][n2-1] = (*b122)[i][0][0];
  assert(dfb200.getSize() ==  1* 1* 1*sizeof(itemtype)); const itemtype (*b200)[ 1][ 1][ 1] = (const itemtype(*)[ 1][ 1][ 1])dfb200.getData<itemtype>(); (*v)[n0-1][0][0] = (*b200)[0][0][0];
  assert(dfb201.getSize() ==  1* 1*n2*sizeof(itemtype)); const itemtype (*b201)[ 1][ 1][n2] = (const itemtype(*)[ 1][ 1][n2])dfb201.getData<itemtype>(); for (l=1;l<n2-1;l++) (*v)[n0-1][0][l] = (*b201)[0][0][l];
  assert(dfb202.getSize() ==  1* 1* 1*sizeof(itemtype)); const itemtype (*b202)[ 1][ 1][ 1] = (const itemtype(*)[ 1][ 1][ 1])dfb202.getData<itemtype>(); (*v)[n0-1][0][n2-1] = (*b202)[0][0][0];
  assert(dfb210.getSize() ==  1*n1* 1*sizeof(itemtype)); const itemtype (*b210)[ 1][n1][ 1] = (const itemtype(*)[ 1][n1][ 1])dfb210.getData<itemtype>(); for (k=1;k<n1-1;k++) (*v)[n0-1][k][0] = (*b210)[0][k][0];
  assert(dfb211.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b211)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb211.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[n0-1][k][l] = (*b211)[0][k][l];
  assert(dfb212.getSize() ==  1*n1* 1*sizeof(itemtype)); const itemtype (*b212)[ 1][n1][ 1] = (const itemtype(*)[ 1][n1][ 1])dfb212.getData<itemtype>(); for (k=1;k<n1-1;k++) (*v)[n0-1][k][n2-1] = (*b212)[0][k][0];
  assert(dfb220.getSize() ==  1* 1* 1*sizeof(itemtype)); const itemtype (*b220)[ 1][ 1][ 1] = (const itemtype(*)[ 1][ 1][ 1])dfb220.getData<itemtype>(); (*v)[n0-1][n1-1][0] = (*b220)[0][0][0];
  assert(dfb221.getSize() ==  1* 1*n2*sizeof(itemtype)); const itemtype (*b221)[ 1][ 1][n2] = (const itemtype(*)[ 1][ 1][n2])dfb221.getData<itemtype>(); for (l=1;l<n2-1;l++) (*v)[n0-1][n1-1][l] = (*b221)[0][0][l];
  assert(dfb222.getSize() ==  1* 1* 1*sizeof(itemtype)); const itemtype (*b222)[ 1][ 1][ 1] = (const itemtype(*)[ 1][ 1][ 1])dfb222.getData<itemtype>(); (*v)[n0-1][n1-1][n2-1] = (*b222)[0][0][0];
}

void c_mesh3d_exchange_27_get_10_00_00(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb011)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b011)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb011.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b011)[0][k][l] = (*u)[1][k][l];
}

void c_mesh3d_exchange_27_set_10_00_00(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb011,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb011.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b011)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb011.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[0][k][l] = (*b011)[0][k][l];
}

void c_mesh3d_exchange_27_get_10_00_01(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb011,OutputDF &dfb012,OutputDF &dfb112)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b011)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb011.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b011)[0][k][l] = (*u)[1][k][l];
  itemtype (*b012)[ 1][n1][ 1] = (itemtype(*)[ 1][n1][ 1])dfb012.create<itemtype>( 1*n1* 1); for (k=0;k<n1;k++) (*b012)[0][k][0] = (*u)[1][k][n2-2];
  itemtype (*b112)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb112.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b112)[i][k][0] = (*u)[i][k][n2-2];
}

void c_mesh3d_exchange_27_set_10_00_01(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb011,const InputDF &dfb012,const InputDF &dfb112,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb011.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b011)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb011.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[0][k][l] = (*b011)[0][k][l];
  assert(dfb012.getSize() ==  1*n1* 1*sizeof(itemtype)); const itemtype (*b012)[ 1][n1][ 1] = (const itemtype(*)[ 1][n1][ 1])dfb012.getData<itemtype>(); for (k=1;k<n1-1;k++) (*v)[0][k][n2-1] = (*b012)[0][k][0];
  assert(dfb112.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b112)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb112.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][n2-1] = (*b112)[i][k][0];
}

void c_mesh3d_exchange_27_get_10_00_10(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb010,OutputDF &dfb011,OutputDF &dfb110)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b010)[ 1][n1][ 1] = (itemtype(*)[ 1][n1][ 1])dfb010.create<itemtype>( 1*n1* 1); for (k=0;k<n1;k++) (*b010)[0][k][0] = (*u)[1][k][1];
  itemtype (*b011)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb011.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b011)[0][k][l] = (*u)[1][k][l];
  itemtype (*b110)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb110.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b110)[i][k][0] = (*u)[i][k][1];
}

void c_mesh3d_exchange_27_set_10_00_10(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb010,const InputDF &dfb011,const InputDF &dfb110,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb010.getSize() ==  1*n1* 1*sizeof(itemtype)); const itemtype (*b010)[ 1][n1][ 1] = (const itemtype(*)[ 1][n1][ 1])dfb010.getData<itemtype>(); for (k=1;k<n1-1;k++) (*v)[0][k][0] = (*b010)[0][k][0];
  assert(dfb011.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b011)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb011.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[0][k][l] = (*b011)[0][k][l];
  assert(dfb110.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b110)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb110.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][0] = (*b110)[i][k][0];
}

void c_mesh3d_exchange_27_get_10_00_11(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb010,OutputDF &dfb011,OutputDF &dfb012,OutputDF &dfb110,OutputDF &dfb112)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b010)[ 1][n1][ 1] = (itemtype(*)[ 1][n1][ 1])dfb010.create<itemtype>( 1*n1* 1); for (k=0;k<n1;k++) (*b010)[0][k][0] = (*u)[1][k][1];
  itemtype (*b011)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb011.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b011)[0][k][l] = (*u)[1][k][l];
  itemtype (*b012)[ 1][n1][ 1] = (itemtype(*)[ 1][n1][ 1])dfb012.create<itemtype>( 1*n1* 1); for (k=0;k<n1;k++) (*b012)[0][k][0] = (*u)[1][k][n2-2];
  itemtype (*b110)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb110.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b110)[i][k][0] = (*u)[i][k][1];
  itemtype (*b112)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb112.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b112)[i][k][0] = (*u)[i][k][n2-2];
}

void c_mesh3d_exchange_27_set_10_00_11(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb010,const InputDF &dfb011,const InputDF &dfb012,const InputDF &dfb110,const InputDF &dfb112,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb010.getSize() ==  1*n1* 1*sizeof(itemtype)); const itemtype (*b010)[ 1][n1][ 1] = (const itemtype(*)[ 1][n1][ 1])dfb010.getData<itemtype>(); for (k=1;k<n1-1;k++) (*v)[0][k][0] = (*b010)[0][k][0];
  assert(dfb011.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b011)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb011.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[0][k][l] = (*b011)[0][k][l];
  assert(dfb012.getSize() ==  1*n1* 1*sizeof(itemtype)); const itemtype (*b012)[ 1][n1][ 1] = (const itemtype(*)[ 1][n1][ 1])dfb012.getData<itemtype>(); for (k=1;k<n1-1;k++) (*v)[0][k][n2-1] = (*b012)[0][k][0];
  assert(dfb110.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b110)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb110.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][0] = (*b110)[i][k][0];
  assert(dfb112.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b112)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb112.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][n2-1] = (*b112)[i][k][0];
}

void c_mesh3d_exchange_27_get_10_01_00(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb011,OutputDF &dfb021,OutputDF &dfb121)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b011)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb011.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b011)[0][k][l] = (*u)[1][k][l];
  itemtype (*b021)[ 1][ 1][n2] = (itemtype(*)[ 1][ 1][n2])dfb021.create<itemtype>( 1* 1*n2); for (l=0;l<n2;l++) (*b021)[0][0][l] = (*u)[1][n1-2][l];
  itemtype (*b121)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb121.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b121)[i][0][l] = (*u)[i][n1-2][l];
}

void c_mesh3d_exchange_27_set_10_01_00(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb011,const InputDF &dfb021,const InputDF &dfb121,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb011.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b011)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb011.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[0][k][l] = (*b011)[0][k][l];
  assert(dfb021.getSize() ==  1* 1*n2*sizeof(itemtype)); const itemtype (*b021)[ 1][ 1][n2] = (const itemtype(*)[ 1][ 1][n2])dfb021.getData<itemtype>(); for (l=1;l<n2-1;l++) (*v)[0][n1-1][l] = (*b021)[0][0][l];
  assert(dfb121.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b121)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb121.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][n1-1][l] = (*b121)[i][0][l];
}

void c_mesh3d_exchange_27_get_10_01_01(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb011,OutputDF &dfb012,OutputDF &dfb021,OutputDF &dfb022,OutputDF &dfb112,OutputDF &dfb121,OutputDF &dfb122)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b011)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb011.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b011)[0][k][l] = (*u)[1][k][l];
  itemtype (*b012)[ 1][n1][ 1] = (itemtype(*)[ 1][n1][ 1])dfb012.create<itemtype>( 1*n1* 1); for (k=0;k<n1;k++) (*b012)[0][k][0] = (*u)[1][k][n2-2];
  itemtype (*b021)[ 1][ 1][n2] = (itemtype(*)[ 1][ 1][n2])dfb021.create<itemtype>( 1* 1*n2); for (l=0;l<n2;l++) (*b021)[0][0][l] = (*u)[1][n1-2][l];
  itemtype (*b022)[ 1][ 1][ 1] = (itemtype(*)[ 1][ 1][ 1])dfb022.create<itemtype>( 1* 1* 1); (*b022)[0][0][0] = (*u)[1][n1-2][n2-2];
  itemtype (*b112)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb112.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b112)[i][k][0] = (*u)[i][k][n2-2];
  itemtype (*b121)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb121.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b121)[i][0][l] = (*u)[i][n1-2][l];
  itemtype (*b122)[n0][ 1][ 1] = (itemtype(*)[n0][ 1][ 1])dfb122.create<itemtype>(n0* 1* 1); for (i=0;i<n0;i++) (*b122)[i][0][0] = (*u)[i][n1-2][n2-2];
}

void c_mesh3d_exchange_27_set_10_01_01(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb011,const InputDF &dfb012,const InputDF &dfb021,const InputDF &dfb022,const InputDF &dfb112,const InputDF &dfb121,const InputDF &dfb122,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb011.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b011)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb011.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[0][k][l] = (*b011)[0][k][l];
  assert(dfb012.getSize() ==  1*n1* 1*sizeof(itemtype)); const itemtype (*b012)[ 1][n1][ 1] = (const itemtype(*)[ 1][n1][ 1])dfb012.getData<itemtype>(); for (k=1;k<n1-1;k++) (*v)[0][k][n2-1] = (*b012)[0][k][0];
  assert(dfb021.getSize() ==  1* 1*n2*sizeof(itemtype)); const itemtype (*b021)[ 1][ 1][n2] = (const itemtype(*)[ 1][ 1][n2])dfb021.getData<itemtype>(); for (l=1;l<n2-1;l++) (*v)[0][n1-1][l] = (*b021)[0][0][l];
  assert(dfb022.getSize() ==  1* 1* 1*sizeof(itemtype)); const itemtype (*b022)[ 1][ 1][ 1] = (const itemtype(*)[ 1][ 1][ 1])dfb022.getData<itemtype>(); (*v)[0][n1-1][n2-1] = (*b022)[0][0][0];
  assert(dfb112.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b112)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb112.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][n2-1] = (*b112)[i][k][0];
  assert(dfb121.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b121)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb121.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][n1-1][l] = (*b121)[i][0][l];
  assert(dfb122.getSize() == n0* 1* 1*sizeof(itemtype)); const itemtype (*b122)[n0][ 1][ 1] = (const itemtype(*)[n0][ 1][ 1])dfb122.getData<itemtype>(); for (i=1;i<n0-1;i++) (*v)[i][n1-1][n2-1] = (*b122)[i][0][0];
}

void c_mesh3d_exchange_27_get_10_01_10(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb010,OutputDF &dfb011,OutputDF &dfb020,OutputDF &dfb021,OutputDF &dfb110,OutputDF &dfb120,OutputDF &dfb121)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b010)[ 1][n1][ 1] = (itemtype(*)[ 1][n1][ 1])dfb010.create<itemtype>( 1*n1* 1); for (k=0;k<n1;k++) (*b010)[0][k][0] = (*u)[1][k][1];
  itemtype (*b011)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb011.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b011)[0][k][l] = (*u)[1][k][l];
  itemtype (*b020)[ 1][ 1][ 1] = (itemtype(*)[ 1][ 1][ 1])dfb020.create<itemtype>( 1* 1* 1); (*b020)[0][0][0] = (*u)[1][n1-2][1];
  itemtype (*b021)[ 1][ 1][n2] = (itemtype(*)[ 1][ 1][n2])dfb021.create<itemtype>( 1* 1*n2); for (l=0;l<n2;l++) (*b021)[0][0][l] = (*u)[1][n1-2][l];
  itemtype (*b110)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb110.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b110)[i][k][0] = (*u)[i][k][1];
  itemtype (*b120)[n0][ 1][ 1] = (itemtype(*)[n0][ 1][ 1])dfb120.create<itemtype>(n0* 1* 1); for (i=0;i<n0;i++) (*b120)[i][0][0] = (*u)[i][n1-2][1];
  itemtype (*b121)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb121.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b121)[i][0][l] = (*u)[i][n1-2][l];
}

void c_mesh3d_exchange_27_set_10_01_10(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb010,const InputDF &dfb011,const InputDF &dfb020,const InputDF &dfb021,const InputDF &dfb110,const InputDF &dfb120,const InputDF &dfb121,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb010.getSize() ==  1*n1* 1*sizeof(itemtype)); const itemtype (*b010)[ 1][n1][ 1] = (const itemtype(*)[ 1][n1][ 1])dfb010.getData<itemtype>(); for (k=1;k<n1-1;k++) (*v)[0][k][0] = (*b010)[0][k][0];
  assert(dfb011.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b011)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb011.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[0][k][l] = (*b011)[0][k][l];
  assert(dfb020.getSize() ==  1* 1* 1*sizeof(itemtype)); const itemtype (*b020)[ 1][ 1][ 1] = (const itemtype(*)[ 1][ 1][ 1])dfb020.getData<itemtype>(); (*v)[0][n1-1][0] = (*b020)[0][0][0];
  assert(dfb021.getSize() ==  1* 1*n2*sizeof(itemtype)); const itemtype (*b021)[ 1][ 1][n2] = (const itemtype(*)[ 1][ 1][n2])dfb021.getData<itemtype>(); for (l=1;l<n2-1;l++) (*v)[0][n1-1][l] = (*b021)[0][0][l];
  assert(dfb110.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b110)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb110.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][0] = (*b110)[i][k][0];
  assert(dfb120.getSize() == n0* 1* 1*sizeof(itemtype)); const itemtype (*b120)[n0][ 1][ 1] = (const itemtype(*)[n0][ 1][ 1])dfb120.getData<itemtype>(); for (i=1;i<n0-1;i++) (*v)[i][n1-1][0] = (*b120)[i][0][0];
  assert(dfb121.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b121)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb121.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][n1-1][l] = (*b121)[i][0][l];
}

void c_mesh3d_exchange_27_get_10_01_11(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb010,OutputDF &dfb011,OutputDF &dfb012,OutputDF &dfb020,OutputDF &dfb021,OutputDF &dfb022,OutputDF &dfb110,OutputDF &dfb112,OutputDF &dfb120,OutputDF &dfb121,OutputDF &dfb122)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b010)[ 1][n1][ 1] = (itemtype(*)[ 1][n1][ 1])dfb010.create<itemtype>( 1*n1* 1); for (k=0;k<n1;k++) (*b010)[0][k][0] = (*u)[1][k][1];
  itemtype (*b011)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb011.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b011)[0][k][l] = (*u)[1][k][l];
  itemtype (*b012)[ 1][n1][ 1] = (itemtype(*)[ 1][n1][ 1])dfb012.create<itemtype>( 1*n1* 1); for (k=0;k<n1;k++) (*b012)[0][k][0] = (*u)[1][k][n2-2];
  itemtype (*b020)[ 1][ 1][ 1] = (itemtype(*)[ 1][ 1][ 1])dfb020.create<itemtype>( 1* 1* 1); (*b020)[0][0][0] = (*u)[1][n1-2][1];
  itemtype (*b021)[ 1][ 1][n2] = (itemtype(*)[ 1][ 1][n2])dfb021.create<itemtype>( 1* 1*n2); for (l=0;l<n2;l++) (*b021)[0][0][l] = (*u)[1][n1-2][l];
  itemtype (*b022)[ 1][ 1][ 1] = (itemtype(*)[ 1][ 1][ 1])dfb022.create<itemtype>( 1* 1* 1); (*b022)[0][0][0] = (*u)[1][n1-2][n2-2];
  itemtype (*b110)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb110.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b110)[i][k][0] = (*u)[i][k][1];
  itemtype (*b112)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb112.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b112)[i][k][0] = (*u)[i][k][n2-2];
  itemtype (*b120)[n0][ 1][ 1] = (itemtype(*)[n0][ 1][ 1])dfb120.create<itemtype>(n0* 1* 1); for (i=0;i<n0;i++) (*b120)[i][0][0] = (*u)[i][n1-2][1];
  itemtype (*b121)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb121.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b121)[i][0][l] = (*u)[i][n1-2][l];
  itemtype (*b122)[n0][ 1][ 1] = (itemtype(*)[n0][ 1][ 1])dfb122.create<itemtype>(n0* 1* 1); for (i=0;i<n0;i++) (*b122)[i][0][0] = (*u)[i][n1-2][n2-2];
}

void c_mesh3d_exchange_27_set_10_01_11(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb010,const InputDF &dfb011,const InputDF &dfb012,const InputDF &dfb020,const InputDF &dfb021,const InputDF &dfb022,const InputDF &dfb110,const InputDF &dfb112,const InputDF &dfb120,const InputDF &dfb121,const InputDF &dfb122,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb010.getSize() ==  1*n1* 1*sizeof(itemtype)); const itemtype (*b010)[ 1][n1][ 1] = (const itemtype(*)[ 1][n1][ 1])dfb010.getData<itemtype>(); for (k=1;k<n1-1;k++) (*v)[0][k][0] = (*b010)[0][k][0];
  assert(dfb011.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b011)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb011.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[0][k][l] = (*b011)[0][k][l];
  assert(dfb012.getSize() ==  1*n1* 1*sizeof(itemtype)); const itemtype (*b012)[ 1][n1][ 1] = (const itemtype(*)[ 1][n1][ 1])dfb012.getData<itemtype>(); for (k=1;k<n1-1;k++) (*v)[0][k][n2-1] = (*b012)[0][k][0];
  assert(dfb020.getSize() ==  1* 1* 1*sizeof(itemtype)); const itemtype (*b020)[ 1][ 1][ 1] = (const itemtype(*)[ 1][ 1][ 1])dfb020.getData<itemtype>(); (*v)[0][n1-1][0] = (*b020)[0][0][0];
  assert(dfb021.getSize() ==  1* 1*n2*sizeof(itemtype)); const itemtype (*b021)[ 1][ 1][n2] = (const itemtype(*)[ 1][ 1][n2])dfb021.getData<itemtype>(); for (l=1;l<n2-1;l++) (*v)[0][n1-1][l] = (*b021)[0][0][l];
  assert(dfb022.getSize() ==  1* 1* 1*sizeof(itemtype)); const itemtype (*b022)[ 1][ 1][ 1] = (const itemtype(*)[ 1][ 1][ 1])dfb022.getData<itemtype>(); (*v)[0][n1-1][n2-1] = (*b022)[0][0][0];
  assert(dfb110.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b110)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb110.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][0] = (*b110)[i][k][0];
  assert(dfb112.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b112)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb112.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][n2-1] = (*b112)[i][k][0];
  assert(dfb120.getSize() == n0* 1* 1*sizeof(itemtype)); const itemtype (*b120)[n0][ 1][ 1] = (const itemtype(*)[n0][ 1][ 1])dfb120.getData<itemtype>(); for (i=1;i<n0-1;i++) (*v)[i][n1-1][0] = (*b120)[i][0][0];
  assert(dfb121.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b121)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb121.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][n1-1][l] = (*b121)[i][0][l];
  assert(dfb122.getSize() == n0* 1* 1*sizeof(itemtype)); const itemtype (*b122)[n0][ 1][ 1] = (const itemtype(*)[n0][ 1][ 1])dfb122.getData<itemtype>(); for (i=1;i<n0-1;i++) (*v)[i][n1-1][n2-1] = (*b122)[i][0][0];
}

void c_mesh3d_exchange_27_get_10_10_00(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb001,OutputDF &dfb011,OutputDF &dfb101)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b001)[ 1][ 1][n2] = (itemtype(*)[ 1][ 1][n2])dfb001.create<itemtype>( 1* 1*n2); for (l=0;l<n2;l++) (*b001)[0][0][l] = (*u)[1][1][l];
  itemtype (*b011)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb011.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b011)[0][k][l] = (*u)[1][k][l];
  itemtype (*b101)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb101.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b101)[i][0][l] = (*u)[i][1][l];
}

void c_mesh3d_exchange_27_set_10_10_00(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb001,const InputDF &dfb011,const InputDF &dfb101,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb001.getSize() ==  1* 1*n2*sizeof(itemtype)); const itemtype (*b001)[ 1][ 1][n2] = (const itemtype(*)[ 1][ 1][n2])dfb001.getData<itemtype>(); for (l=1;l<n2-1;l++) (*v)[0][0][l] = (*b001)[0][0][l];
  assert(dfb011.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b011)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb011.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[0][k][l] = (*b011)[0][k][l];
  assert(dfb101.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b101)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb101.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][0][l] = (*b101)[i][0][l];
}

void c_mesh3d_exchange_27_get_10_10_01(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb001,OutputDF &dfb002,OutputDF &dfb011,OutputDF &dfb012,OutputDF &dfb101,OutputDF &dfb102,OutputDF &dfb112)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b001)[ 1][ 1][n2] = (itemtype(*)[ 1][ 1][n2])dfb001.create<itemtype>( 1* 1*n2); for (l=0;l<n2;l++) (*b001)[0][0][l] = (*u)[1][1][l];
  itemtype (*b002)[ 1][ 1][ 1] = (itemtype(*)[ 1][ 1][ 1])dfb002.create<itemtype>( 1* 1* 1); (*b002)[0][0][0] = (*u)[1][1][n2-2];
  itemtype (*b011)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb011.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b011)[0][k][l] = (*u)[1][k][l];
  itemtype (*b012)[ 1][n1][ 1] = (itemtype(*)[ 1][n1][ 1])dfb012.create<itemtype>( 1*n1* 1); for (k=0;k<n1;k++) (*b012)[0][k][0] = (*u)[1][k][n2-2];
  itemtype (*b101)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb101.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b101)[i][0][l] = (*u)[i][1][l];
  itemtype (*b102)[n0][ 1][ 1] = (itemtype(*)[n0][ 1][ 1])dfb102.create<itemtype>(n0* 1* 1); for (i=0;i<n0;i++) (*b102)[i][0][0] = (*u)[i][1][n2-2];
  itemtype (*b112)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb112.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b112)[i][k][0] = (*u)[i][k][n2-2];
}

void c_mesh3d_exchange_27_set_10_10_01(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb001,const InputDF &dfb002,const InputDF &dfb011,const InputDF &dfb012,const InputDF &dfb101,const InputDF &dfb102,const InputDF &dfb112,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb001.getSize() ==  1* 1*n2*sizeof(itemtype)); const itemtype (*b001)[ 1][ 1][n2] = (const itemtype(*)[ 1][ 1][n2])dfb001.getData<itemtype>(); for (l=1;l<n2-1;l++) (*v)[0][0][l] = (*b001)[0][0][l];
  assert(dfb002.getSize() ==  1* 1* 1*sizeof(itemtype)); const itemtype (*b002)[ 1][ 1][ 1] = (const itemtype(*)[ 1][ 1][ 1])dfb002.getData<itemtype>(); (*v)[0][0][n2-1] = (*b002)[0][0][0];
  assert(dfb011.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b011)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb011.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[0][k][l] = (*b011)[0][k][l];
  assert(dfb012.getSize() ==  1*n1* 1*sizeof(itemtype)); const itemtype (*b012)[ 1][n1][ 1] = (const itemtype(*)[ 1][n1][ 1])dfb012.getData<itemtype>(); for (k=1;k<n1-1;k++) (*v)[0][k][n2-1] = (*b012)[0][k][0];
  assert(dfb101.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b101)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb101.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][0][l] = (*b101)[i][0][l];
  assert(dfb102.getSize() == n0* 1* 1*sizeof(itemtype)); const itemtype (*b102)[n0][ 1][ 1] = (const itemtype(*)[n0][ 1][ 1])dfb102.getData<itemtype>(); for (i=1;i<n0-1;i++) (*v)[i][0][n2-1] = (*b102)[i][0][0];
  assert(dfb112.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b112)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb112.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][n2-1] = (*b112)[i][k][0];
}

void c_mesh3d_exchange_27_get_10_10_10(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb000,OutputDF &dfb001,OutputDF &dfb010,OutputDF &dfb011,OutputDF &dfb100,OutputDF &dfb101,OutputDF &dfb110)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b000)[ 1][ 1][ 1] = (itemtype(*)[ 1][ 1][ 1])dfb000.create<itemtype>( 1* 1* 1); (*b000)[0][0][0] = (*u)[1][1][1];
  itemtype (*b001)[ 1][ 1][n2] = (itemtype(*)[ 1][ 1][n2])dfb001.create<itemtype>( 1* 1*n2); for (l=0;l<n2;l++) (*b001)[0][0][l] = (*u)[1][1][l];
  itemtype (*b010)[ 1][n1][ 1] = (itemtype(*)[ 1][n1][ 1])dfb010.create<itemtype>( 1*n1* 1); for (k=0;k<n1;k++) (*b010)[0][k][0] = (*u)[1][k][1];
  itemtype (*b011)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb011.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b011)[0][k][l] = (*u)[1][k][l];
  itemtype (*b100)[n0][ 1][ 1] = (itemtype(*)[n0][ 1][ 1])dfb100.create<itemtype>(n0* 1* 1); for (i=0;i<n0;i++) (*b100)[i][0][0] = (*u)[i][1][1];
  itemtype (*b101)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb101.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b101)[i][0][l] = (*u)[i][1][l];
  itemtype (*b110)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb110.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b110)[i][k][0] = (*u)[i][k][1];
}

void c_mesh3d_exchange_27_set_10_10_10(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb000,const InputDF &dfb001,const InputDF &dfb010,const InputDF &dfb011,const InputDF &dfb100,const InputDF &dfb101,const InputDF &dfb110,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb000.getSize() ==  1* 1* 1*sizeof(itemtype)); const itemtype (*b000)[ 1][ 1][ 1] = (const itemtype(*)[ 1][ 1][ 1])dfb000.getData<itemtype>(); (*v)[0][0][0] = (*b000)[0][0][0];
  assert(dfb001.getSize() ==  1* 1*n2*sizeof(itemtype)); const itemtype (*b001)[ 1][ 1][n2] = (const itemtype(*)[ 1][ 1][n2])dfb001.getData<itemtype>(); for (l=1;l<n2-1;l++) (*v)[0][0][l] = (*b001)[0][0][l];
  assert(dfb010.getSize() ==  1*n1* 1*sizeof(itemtype)); const itemtype (*b010)[ 1][n1][ 1] = (const itemtype(*)[ 1][n1][ 1])dfb010.getData<itemtype>(); for (k=1;k<n1-1;k++) (*v)[0][k][0] = (*b010)[0][k][0];
  assert(dfb011.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b011)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb011.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[0][k][l] = (*b011)[0][k][l];
  assert(dfb100.getSize() == n0* 1* 1*sizeof(itemtype)); const itemtype (*b100)[n0][ 1][ 1] = (const itemtype(*)[n0][ 1][ 1])dfb100.getData<itemtype>(); for (i=1;i<n0-1;i++) (*v)[i][0][0] = (*b100)[i][0][0];
  assert(dfb101.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b101)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb101.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][0][l] = (*b101)[i][0][l];
  assert(dfb110.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b110)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb110.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][0] = (*b110)[i][k][0];
}

void c_mesh3d_exchange_27_get_10_10_11(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb000,OutputDF &dfb001,OutputDF &dfb002,OutputDF &dfb010,OutputDF &dfb011,OutputDF &dfb012,OutputDF &dfb100,OutputDF &dfb101,OutputDF &dfb102,OutputDF &dfb110,OutputDF &dfb112)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b000)[ 1][ 1][ 1] = (itemtype(*)[ 1][ 1][ 1])dfb000.create<itemtype>( 1* 1* 1); (*b000)[0][0][0] = (*u)[1][1][1];
  itemtype (*b001)[ 1][ 1][n2] = (itemtype(*)[ 1][ 1][n2])dfb001.create<itemtype>( 1* 1*n2); for (l=0;l<n2;l++) (*b001)[0][0][l] = (*u)[1][1][l];
  itemtype (*b002)[ 1][ 1][ 1] = (itemtype(*)[ 1][ 1][ 1])dfb002.create<itemtype>( 1* 1* 1); (*b002)[0][0][0] = (*u)[1][1][n2-2];
  itemtype (*b010)[ 1][n1][ 1] = (itemtype(*)[ 1][n1][ 1])dfb010.create<itemtype>( 1*n1* 1); for (k=0;k<n1;k++) (*b010)[0][k][0] = (*u)[1][k][1];
  itemtype (*b011)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb011.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b011)[0][k][l] = (*u)[1][k][l];
  itemtype (*b012)[ 1][n1][ 1] = (itemtype(*)[ 1][n1][ 1])dfb012.create<itemtype>( 1*n1* 1); for (k=0;k<n1;k++) (*b012)[0][k][0] = (*u)[1][k][n2-2];
  itemtype (*b100)[n0][ 1][ 1] = (itemtype(*)[n0][ 1][ 1])dfb100.create<itemtype>(n0* 1* 1); for (i=0;i<n0;i++) (*b100)[i][0][0] = (*u)[i][1][1];
  itemtype (*b101)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb101.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b101)[i][0][l] = (*u)[i][1][l];
  itemtype (*b102)[n0][ 1][ 1] = (itemtype(*)[n0][ 1][ 1])dfb102.create<itemtype>(n0* 1* 1); for (i=0;i<n0;i++) (*b102)[i][0][0] = (*u)[i][1][n2-2];
  itemtype (*b110)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb110.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b110)[i][k][0] = (*u)[i][k][1];
  itemtype (*b112)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb112.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b112)[i][k][0] = (*u)[i][k][n2-2];
}

void c_mesh3d_exchange_27_set_10_10_11(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb000,const InputDF &dfb001,const InputDF &dfb002,const InputDF &dfb010,const InputDF &dfb011,const InputDF &dfb012,const InputDF &dfb100,const InputDF &dfb101,const InputDF &dfb102,const InputDF &dfb110,const InputDF &dfb112,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb000.getSize() ==  1* 1* 1*sizeof(itemtype)); const itemtype (*b000)[ 1][ 1][ 1] = (const itemtype(*)[ 1][ 1][ 1])dfb000.getData<itemtype>(); (*v)[0][0][0] = (*b000)[0][0][0];
  assert(dfb001.getSize() ==  1* 1*n2*sizeof(itemtype)); const itemtype (*b001)[ 1][ 1][n2] = (const itemtype(*)[ 1][ 1][n2])dfb001.getData<itemtype>(); for (l=1;l<n2-1;l++) (*v)[0][0][l] = (*b001)[0][0][l];
  assert(dfb002.getSize() ==  1* 1* 1*sizeof(itemtype)); const itemtype (*b002)[ 1][ 1][ 1] = (const itemtype(*)[ 1][ 1][ 1])dfb002.getData<itemtype>(); (*v)[0][0][n2-1] = (*b002)[0][0][0];
  assert(dfb010.getSize() ==  1*n1* 1*sizeof(itemtype)); const itemtype (*b010)[ 1][n1][ 1] = (const itemtype(*)[ 1][n1][ 1])dfb010.getData<itemtype>(); for (k=1;k<n1-1;k++) (*v)[0][k][0] = (*b010)[0][k][0];
  assert(dfb011.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b011)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb011.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[0][k][l] = (*b011)[0][k][l];
  assert(dfb012.getSize() ==  1*n1* 1*sizeof(itemtype)); const itemtype (*b012)[ 1][n1][ 1] = (const itemtype(*)[ 1][n1][ 1])dfb012.getData<itemtype>(); for (k=1;k<n1-1;k++) (*v)[0][k][n2-1] = (*b012)[0][k][0];
  assert(dfb100.getSize() == n0* 1* 1*sizeof(itemtype)); const itemtype (*b100)[n0][ 1][ 1] = (const itemtype(*)[n0][ 1][ 1])dfb100.getData<itemtype>(); for (i=1;i<n0-1;i++) (*v)[i][0][0] = (*b100)[i][0][0];
  assert(dfb101.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b101)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb101.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][0][l] = (*b101)[i][0][l];
  assert(dfb102.getSize() == n0* 1* 1*sizeof(itemtype)); const itemtype (*b102)[n0][ 1][ 1] = (const itemtype(*)[n0][ 1][ 1])dfb102.getData<itemtype>(); for (i=1;i<n0-1;i++) (*v)[i][0][n2-1] = (*b102)[i][0][0];
  assert(dfb110.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b110)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb110.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][0] = (*b110)[i][k][0];
  assert(dfb112.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b112)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb112.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][n2-1] = (*b112)[i][k][0];
}

void c_mesh3d_exchange_27_get_10_11_00(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb001,OutputDF &dfb011,OutputDF &dfb021,OutputDF &dfb101,OutputDF &dfb121)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b001)[ 1][ 1][n2] = (itemtype(*)[ 1][ 1][n2])dfb001.create<itemtype>( 1* 1*n2); for (l=0;l<n2;l++) (*b001)[0][0][l] = (*u)[1][1][l];
  itemtype (*b011)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb011.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b011)[0][k][l] = (*u)[1][k][l];
  itemtype (*b021)[ 1][ 1][n2] = (itemtype(*)[ 1][ 1][n2])dfb021.create<itemtype>( 1* 1*n2); for (l=0;l<n2;l++) (*b021)[0][0][l] = (*u)[1][n1-2][l];
  itemtype (*b101)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb101.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b101)[i][0][l] = (*u)[i][1][l];
  itemtype (*b121)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb121.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b121)[i][0][l] = (*u)[i][n1-2][l];
}

void c_mesh3d_exchange_27_set_10_11_00(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb001,const InputDF &dfb011,const InputDF &dfb021,const InputDF &dfb101,const InputDF &dfb121,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb001.getSize() ==  1* 1*n2*sizeof(itemtype)); const itemtype (*b001)[ 1][ 1][n2] = (const itemtype(*)[ 1][ 1][n2])dfb001.getData<itemtype>(); for (l=1;l<n2-1;l++) (*v)[0][0][l] = (*b001)[0][0][l];
  assert(dfb011.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b011)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb011.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[0][k][l] = (*b011)[0][k][l];
  assert(dfb021.getSize() ==  1* 1*n2*sizeof(itemtype)); const itemtype (*b021)[ 1][ 1][n2] = (const itemtype(*)[ 1][ 1][n2])dfb021.getData<itemtype>(); for (l=1;l<n2-1;l++) (*v)[0][n1-1][l] = (*b021)[0][0][l];
  assert(dfb101.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b101)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb101.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][0][l] = (*b101)[i][0][l];
  assert(dfb121.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b121)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb121.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][n1-1][l] = (*b121)[i][0][l];
}

void c_mesh3d_exchange_27_get_10_11_01(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb001,OutputDF &dfb002,OutputDF &dfb011,OutputDF &dfb012,OutputDF &dfb021,OutputDF &dfb022,OutputDF &dfb101,OutputDF &dfb102,OutputDF &dfb112,OutputDF &dfb121,OutputDF &dfb122)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b001)[ 1][ 1][n2] = (itemtype(*)[ 1][ 1][n2])dfb001.create<itemtype>( 1* 1*n2); for (l=0;l<n2;l++) (*b001)[0][0][l] = (*u)[1][1][l];
  itemtype (*b002)[ 1][ 1][ 1] = (itemtype(*)[ 1][ 1][ 1])dfb002.create<itemtype>( 1* 1* 1); (*b002)[0][0][0] = (*u)[1][1][n2-2];
  itemtype (*b011)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb011.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b011)[0][k][l] = (*u)[1][k][l];
  itemtype (*b012)[ 1][n1][ 1] = (itemtype(*)[ 1][n1][ 1])dfb012.create<itemtype>( 1*n1* 1); for (k=0;k<n1;k++) (*b012)[0][k][0] = (*u)[1][k][n2-2];
  itemtype (*b021)[ 1][ 1][n2] = (itemtype(*)[ 1][ 1][n2])dfb021.create<itemtype>( 1* 1*n2); for (l=0;l<n2;l++) (*b021)[0][0][l] = (*u)[1][n1-2][l];
  itemtype (*b022)[ 1][ 1][ 1] = (itemtype(*)[ 1][ 1][ 1])dfb022.create<itemtype>( 1* 1* 1); (*b022)[0][0][0] = (*u)[1][n1-2][n2-2];
  itemtype (*b101)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb101.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b101)[i][0][l] = (*u)[i][1][l];
  itemtype (*b102)[n0][ 1][ 1] = (itemtype(*)[n0][ 1][ 1])dfb102.create<itemtype>(n0* 1* 1); for (i=0;i<n0;i++) (*b102)[i][0][0] = (*u)[i][1][n2-2];
  itemtype (*b112)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb112.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b112)[i][k][0] = (*u)[i][k][n2-2];
  itemtype (*b121)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb121.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b121)[i][0][l] = (*u)[i][n1-2][l];
  itemtype (*b122)[n0][ 1][ 1] = (itemtype(*)[n0][ 1][ 1])dfb122.create<itemtype>(n0* 1* 1); for (i=0;i<n0;i++) (*b122)[i][0][0] = (*u)[i][n1-2][n2-2];
}

void c_mesh3d_exchange_27_set_10_11_01(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb001,const InputDF &dfb002,const InputDF &dfb011,const InputDF &dfb012,const InputDF &dfb021,const InputDF &dfb022,const InputDF &dfb101,const InputDF &dfb102,const InputDF &dfb112,const InputDF &dfb121,const InputDF &dfb122,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb001.getSize() ==  1* 1*n2*sizeof(itemtype)); const itemtype (*b001)[ 1][ 1][n2] = (const itemtype(*)[ 1][ 1][n2])dfb001.getData<itemtype>(); for (l=1;l<n2-1;l++) (*v)[0][0][l] = (*b001)[0][0][l];
  assert(dfb002.getSize() ==  1* 1* 1*sizeof(itemtype)); const itemtype (*b002)[ 1][ 1][ 1] = (const itemtype(*)[ 1][ 1][ 1])dfb002.getData<itemtype>(); (*v)[0][0][n2-1] = (*b002)[0][0][0];
  assert(dfb011.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b011)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb011.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[0][k][l] = (*b011)[0][k][l];
  assert(dfb012.getSize() ==  1*n1* 1*sizeof(itemtype)); const itemtype (*b012)[ 1][n1][ 1] = (const itemtype(*)[ 1][n1][ 1])dfb012.getData<itemtype>(); for (k=1;k<n1-1;k++) (*v)[0][k][n2-1] = (*b012)[0][k][0];
  assert(dfb021.getSize() ==  1* 1*n2*sizeof(itemtype)); const itemtype (*b021)[ 1][ 1][n2] = (const itemtype(*)[ 1][ 1][n2])dfb021.getData<itemtype>(); for (l=1;l<n2-1;l++) (*v)[0][n1-1][l] = (*b021)[0][0][l];
  assert(dfb022.getSize() ==  1* 1* 1*sizeof(itemtype)); const itemtype (*b022)[ 1][ 1][ 1] = (const itemtype(*)[ 1][ 1][ 1])dfb022.getData<itemtype>(); (*v)[0][n1-1][n2-1] = (*b022)[0][0][0];
  assert(dfb101.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b101)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb101.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][0][l] = (*b101)[i][0][l];
  assert(dfb102.getSize() == n0* 1* 1*sizeof(itemtype)); const itemtype (*b102)[n0][ 1][ 1] = (const itemtype(*)[n0][ 1][ 1])dfb102.getData<itemtype>(); for (i=1;i<n0-1;i++) (*v)[i][0][n2-1] = (*b102)[i][0][0];
  assert(dfb112.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b112)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb112.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][n2-1] = (*b112)[i][k][0];
  assert(dfb121.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b121)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb121.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][n1-1][l] = (*b121)[i][0][l];
  assert(dfb122.getSize() == n0* 1* 1*sizeof(itemtype)); const itemtype (*b122)[n0][ 1][ 1] = (const itemtype(*)[n0][ 1][ 1])dfb122.getData<itemtype>(); for (i=1;i<n0-1;i++) (*v)[i][n1-1][n2-1] = (*b122)[i][0][0];
}

void c_mesh3d_exchange_27_get_10_11_10(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb000,OutputDF &dfb001,OutputDF &dfb010,OutputDF &dfb011,OutputDF &dfb020,OutputDF &dfb021,OutputDF &dfb100,OutputDF &dfb101,OutputDF &dfb110,OutputDF &dfb120,OutputDF &dfb121)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b000)[ 1][ 1][ 1] = (itemtype(*)[ 1][ 1][ 1])dfb000.create<itemtype>( 1* 1* 1); (*b000)[0][0][0] = (*u)[1][1][1];
  itemtype (*b001)[ 1][ 1][n2] = (itemtype(*)[ 1][ 1][n2])dfb001.create<itemtype>( 1* 1*n2); for (l=0;l<n2;l++) (*b001)[0][0][l] = (*u)[1][1][l];
  itemtype (*b010)[ 1][n1][ 1] = (itemtype(*)[ 1][n1][ 1])dfb010.create<itemtype>( 1*n1* 1); for (k=0;k<n1;k++) (*b010)[0][k][0] = (*u)[1][k][1];
  itemtype (*b011)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb011.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b011)[0][k][l] = (*u)[1][k][l];
  itemtype (*b020)[ 1][ 1][ 1] = (itemtype(*)[ 1][ 1][ 1])dfb020.create<itemtype>( 1* 1* 1); (*b020)[0][0][0] = (*u)[1][n1-2][1];
  itemtype (*b021)[ 1][ 1][n2] = (itemtype(*)[ 1][ 1][n2])dfb021.create<itemtype>( 1* 1*n2); for (l=0;l<n2;l++) (*b021)[0][0][l] = (*u)[1][n1-2][l];
  itemtype (*b100)[n0][ 1][ 1] = (itemtype(*)[n0][ 1][ 1])dfb100.create<itemtype>(n0* 1* 1); for (i=0;i<n0;i++) (*b100)[i][0][0] = (*u)[i][1][1];
  itemtype (*b101)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb101.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b101)[i][0][l] = (*u)[i][1][l];
  itemtype (*b110)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb110.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b110)[i][k][0] = (*u)[i][k][1];
  itemtype (*b120)[n0][ 1][ 1] = (itemtype(*)[n0][ 1][ 1])dfb120.create<itemtype>(n0* 1* 1); for (i=0;i<n0;i++) (*b120)[i][0][0] = (*u)[i][n1-2][1];
  itemtype (*b121)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb121.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b121)[i][0][l] = (*u)[i][n1-2][l];
}

void c_mesh3d_exchange_27_set_10_11_10(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb000,const InputDF &dfb001,const InputDF &dfb010,const InputDF &dfb011,const InputDF &dfb020,const InputDF &dfb021,const InputDF &dfb100,const InputDF &dfb101,const InputDF &dfb110,const InputDF &dfb120,const InputDF &dfb121,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb000.getSize() ==  1* 1* 1*sizeof(itemtype)); const itemtype (*b000)[ 1][ 1][ 1] = (const itemtype(*)[ 1][ 1][ 1])dfb000.getData<itemtype>(); (*v)[0][0][0] = (*b000)[0][0][0];
  assert(dfb001.getSize() ==  1* 1*n2*sizeof(itemtype)); const itemtype (*b001)[ 1][ 1][n2] = (const itemtype(*)[ 1][ 1][n2])dfb001.getData<itemtype>(); for (l=1;l<n2-1;l++) (*v)[0][0][l] = (*b001)[0][0][l];
  assert(dfb010.getSize() ==  1*n1* 1*sizeof(itemtype)); const itemtype (*b010)[ 1][n1][ 1] = (const itemtype(*)[ 1][n1][ 1])dfb010.getData<itemtype>(); for (k=1;k<n1-1;k++) (*v)[0][k][0] = (*b010)[0][k][0];
  assert(dfb011.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b011)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb011.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[0][k][l] = (*b011)[0][k][l];
  assert(dfb020.getSize() ==  1* 1* 1*sizeof(itemtype)); const itemtype (*b020)[ 1][ 1][ 1] = (const itemtype(*)[ 1][ 1][ 1])dfb020.getData<itemtype>(); (*v)[0][n1-1][0] = (*b020)[0][0][0];
  assert(dfb021.getSize() ==  1* 1*n2*sizeof(itemtype)); const itemtype (*b021)[ 1][ 1][n2] = (const itemtype(*)[ 1][ 1][n2])dfb021.getData<itemtype>(); for (l=1;l<n2-1;l++) (*v)[0][n1-1][l] = (*b021)[0][0][l];
  assert(dfb100.getSize() == n0* 1* 1*sizeof(itemtype)); const itemtype (*b100)[n0][ 1][ 1] = (const itemtype(*)[n0][ 1][ 1])dfb100.getData<itemtype>(); for (i=1;i<n0-1;i++) (*v)[i][0][0] = (*b100)[i][0][0];
  assert(dfb101.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b101)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb101.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][0][l] = (*b101)[i][0][l];
  assert(dfb110.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b110)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb110.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][0] = (*b110)[i][k][0];
  assert(dfb120.getSize() == n0* 1* 1*sizeof(itemtype)); const itemtype (*b120)[n0][ 1][ 1] = (const itemtype(*)[n0][ 1][ 1])dfb120.getData<itemtype>(); for (i=1;i<n0-1;i++) (*v)[i][n1-1][0] = (*b120)[i][0][0];
  assert(dfb121.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b121)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb121.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][n1-1][l] = (*b121)[i][0][l];
}

void c_mesh3d_exchange_27_get_10_11_11(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb000,OutputDF &dfb001,OutputDF &dfb002,OutputDF &dfb010,OutputDF &dfb011,OutputDF &dfb012,OutputDF &dfb020,OutputDF &dfb021,OutputDF &dfb022,OutputDF &dfb100,OutputDF &dfb101,OutputDF &dfb102,OutputDF &dfb110,OutputDF &dfb112,OutputDF &dfb120,OutputDF &dfb121,OutputDF &dfb122)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b000)[ 1][ 1][ 1] = (itemtype(*)[ 1][ 1][ 1])dfb000.create<itemtype>( 1* 1* 1); (*b000)[0][0][0] = (*u)[1][1][1];
  itemtype (*b001)[ 1][ 1][n2] = (itemtype(*)[ 1][ 1][n2])dfb001.create<itemtype>( 1* 1*n2); for (l=0;l<n2;l++) (*b001)[0][0][l] = (*u)[1][1][l];
  itemtype (*b002)[ 1][ 1][ 1] = (itemtype(*)[ 1][ 1][ 1])dfb002.create<itemtype>( 1* 1* 1); (*b002)[0][0][0] = (*u)[1][1][n2-2];
  itemtype (*b010)[ 1][n1][ 1] = (itemtype(*)[ 1][n1][ 1])dfb010.create<itemtype>( 1*n1* 1); for (k=0;k<n1;k++) (*b010)[0][k][0] = (*u)[1][k][1];
  itemtype (*b011)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb011.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b011)[0][k][l] = (*u)[1][k][l];
  itemtype (*b012)[ 1][n1][ 1] = (itemtype(*)[ 1][n1][ 1])dfb012.create<itemtype>( 1*n1* 1); for (k=0;k<n1;k++) (*b012)[0][k][0] = (*u)[1][k][n2-2];
  itemtype (*b020)[ 1][ 1][ 1] = (itemtype(*)[ 1][ 1][ 1])dfb020.create<itemtype>( 1* 1* 1); (*b020)[0][0][0] = (*u)[1][n1-2][1];
  itemtype (*b021)[ 1][ 1][n2] = (itemtype(*)[ 1][ 1][n2])dfb021.create<itemtype>( 1* 1*n2); for (l=0;l<n2;l++) (*b021)[0][0][l] = (*u)[1][n1-2][l];
  itemtype (*b022)[ 1][ 1][ 1] = (itemtype(*)[ 1][ 1][ 1])dfb022.create<itemtype>( 1* 1* 1); (*b022)[0][0][0] = (*u)[1][n1-2][n2-2];
  itemtype (*b100)[n0][ 1][ 1] = (itemtype(*)[n0][ 1][ 1])dfb100.create<itemtype>(n0* 1* 1); for (i=0;i<n0;i++) (*b100)[i][0][0] = (*u)[i][1][1];
  itemtype (*b101)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb101.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b101)[i][0][l] = (*u)[i][1][l];
  itemtype (*b102)[n0][ 1][ 1] = (itemtype(*)[n0][ 1][ 1])dfb102.create<itemtype>(n0* 1* 1); for (i=0;i<n0;i++) (*b102)[i][0][0] = (*u)[i][1][n2-2];
  itemtype (*b110)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb110.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b110)[i][k][0] = (*u)[i][k][1];
  itemtype (*b112)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb112.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b112)[i][k][0] = (*u)[i][k][n2-2];
  itemtype (*b120)[n0][ 1][ 1] = (itemtype(*)[n0][ 1][ 1])dfb120.create<itemtype>(n0* 1* 1); for (i=0;i<n0;i++) (*b120)[i][0][0] = (*u)[i][n1-2][1];
  itemtype (*b121)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb121.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b121)[i][0][l] = (*u)[i][n1-2][l];
  itemtype (*b122)[n0][ 1][ 1] = (itemtype(*)[n0][ 1][ 1])dfb122.create<itemtype>(n0* 1* 1); for (i=0;i<n0;i++) (*b122)[i][0][0] = (*u)[i][n1-2][n2-2];
}

void c_mesh3d_exchange_27_set_10_11_11(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb000,const InputDF &dfb001,const InputDF &dfb002,const InputDF &dfb010,const InputDF &dfb011,const InputDF &dfb012,const InputDF &dfb020,const InputDF &dfb021,const InputDF &dfb022,const InputDF &dfb100,const InputDF &dfb101,const InputDF &dfb102,const InputDF &dfb110,const InputDF &dfb112,const InputDF &dfb120,const InputDF &dfb121,const InputDF &dfb122,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb000.getSize() ==  1* 1* 1*sizeof(itemtype)); const itemtype (*b000)[ 1][ 1][ 1] = (const itemtype(*)[ 1][ 1][ 1])dfb000.getData<itemtype>(); (*v)[0][0][0] = (*b000)[0][0][0];
  assert(dfb001.getSize() ==  1* 1*n2*sizeof(itemtype)); const itemtype (*b001)[ 1][ 1][n2] = (const itemtype(*)[ 1][ 1][n2])dfb001.getData<itemtype>(); for (l=1;l<n2-1;l++) (*v)[0][0][l] = (*b001)[0][0][l];
  assert(dfb002.getSize() ==  1* 1* 1*sizeof(itemtype)); const itemtype (*b002)[ 1][ 1][ 1] = (const itemtype(*)[ 1][ 1][ 1])dfb002.getData<itemtype>(); (*v)[0][0][n2-1] = (*b002)[0][0][0];
  assert(dfb010.getSize() ==  1*n1* 1*sizeof(itemtype)); const itemtype (*b010)[ 1][n1][ 1] = (const itemtype(*)[ 1][n1][ 1])dfb010.getData<itemtype>(); for (k=1;k<n1-1;k++) (*v)[0][k][0] = (*b010)[0][k][0];
  assert(dfb011.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b011)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb011.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[0][k][l] = (*b011)[0][k][l];
  assert(dfb012.getSize() ==  1*n1* 1*sizeof(itemtype)); const itemtype (*b012)[ 1][n1][ 1] = (const itemtype(*)[ 1][n1][ 1])dfb012.getData<itemtype>(); for (k=1;k<n1-1;k++) (*v)[0][k][n2-1] = (*b012)[0][k][0];
  assert(dfb020.getSize() ==  1* 1* 1*sizeof(itemtype)); const itemtype (*b020)[ 1][ 1][ 1] = (const itemtype(*)[ 1][ 1][ 1])dfb020.getData<itemtype>(); (*v)[0][n1-1][0] = (*b020)[0][0][0];
  assert(dfb021.getSize() ==  1* 1*n2*sizeof(itemtype)); const itemtype (*b021)[ 1][ 1][n2] = (const itemtype(*)[ 1][ 1][n2])dfb021.getData<itemtype>(); for (l=1;l<n2-1;l++) (*v)[0][n1-1][l] = (*b021)[0][0][l];
  assert(dfb022.getSize() ==  1* 1* 1*sizeof(itemtype)); const itemtype (*b022)[ 1][ 1][ 1] = (const itemtype(*)[ 1][ 1][ 1])dfb022.getData<itemtype>(); (*v)[0][n1-1][n2-1] = (*b022)[0][0][0];
  assert(dfb100.getSize() == n0* 1* 1*sizeof(itemtype)); const itemtype (*b100)[n0][ 1][ 1] = (const itemtype(*)[n0][ 1][ 1])dfb100.getData<itemtype>(); for (i=1;i<n0-1;i++) (*v)[i][0][0] = (*b100)[i][0][0];
  assert(dfb101.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b101)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb101.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][0][l] = (*b101)[i][0][l];
  assert(dfb102.getSize() == n0* 1* 1*sizeof(itemtype)); const itemtype (*b102)[n0][ 1][ 1] = (const itemtype(*)[n0][ 1][ 1])dfb102.getData<itemtype>(); for (i=1;i<n0-1;i++) (*v)[i][0][n2-1] = (*b102)[i][0][0];
  assert(dfb110.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b110)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb110.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][0] = (*b110)[i][k][0];
  assert(dfb112.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b112)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb112.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][n2-1] = (*b112)[i][k][0];
  assert(dfb120.getSize() == n0* 1* 1*sizeof(itemtype)); const itemtype (*b120)[n0][ 1][ 1] = (const itemtype(*)[n0][ 1][ 1])dfb120.getData<itemtype>(); for (i=1;i<n0-1;i++) (*v)[i][n1-1][0] = (*b120)[i][0][0];
  assert(dfb121.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b121)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb121.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][n1-1][l] = (*b121)[i][0][l];
  assert(dfb122.getSize() == n0* 1* 1*sizeof(itemtype)); const itemtype (*b122)[n0][ 1][ 1] = (const itemtype(*)[n0][ 1][ 1])dfb122.getData<itemtype>(); for (i=1;i<n0-1;i++) (*v)[i][n1-1][n2-1] = (*b122)[i][0][0];
}

void c_mesh3d_exchange_27_get_11_00_00(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb011,OutputDF &dfb211)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b011)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb011.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b011)[0][k][l] = (*u)[1][k][l];
  itemtype (*b211)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb211.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b211)[0][k][l] = (*u)[n0-2][k][l];
}

void c_mesh3d_exchange_27_set_11_00_00(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb011,const InputDF &dfb211,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb011.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b011)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb011.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[0][k][l] = (*b011)[0][k][l];
  assert(dfb211.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b211)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb211.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[n0-1][k][l] = (*b211)[0][k][l];
}

void c_mesh3d_exchange_27_get_11_00_01(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb011,OutputDF &dfb012,OutputDF &dfb112,OutputDF &dfb211,OutputDF &dfb212)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b011)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb011.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b011)[0][k][l] = (*u)[1][k][l];
  itemtype (*b012)[ 1][n1][ 1] = (itemtype(*)[ 1][n1][ 1])dfb012.create<itemtype>( 1*n1* 1); for (k=0;k<n1;k++) (*b012)[0][k][0] = (*u)[1][k][n2-2];
  itemtype (*b112)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb112.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b112)[i][k][0] = (*u)[i][k][n2-2];
  itemtype (*b211)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb211.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b211)[0][k][l] = (*u)[n0-2][k][l];
  itemtype (*b212)[ 1][n1][ 1] = (itemtype(*)[ 1][n1][ 1])dfb212.create<itemtype>( 1*n1* 1); for (k=0;k<n1;k++) (*b212)[0][k][0] = (*u)[n0-2][k][n2-2];
}

void c_mesh3d_exchange_27_set_11_00_01(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb011,const InputDF &dfb012,const InputDF &dfb112,const InputDF &dfb211,const InputDF &dfb212,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb011.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b011)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb011.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[0][k][l] = (*b011)[0][k][l];
  assert(dfb012.getSize() ==  1*n1* 1*sizeof(itemtype)); const itemtype (*b012)[ 1][n1][ 1] = (const itemtype(*)[ 1][n1][ 1])dfb012.getData<itemtype>(); for (k=1;k<n1-1;k++) (*v)[0][k][n2-1] = (*b012)[0][k][0];
  assert(dfb112.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b112)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb112.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][n2-1] = (*b112)[i][k][0];
  assert(dfb211.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b211)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb211.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[n0-1][k][l] = (*b211)[0][k][l];
  assert(dfb212.getSize() ==  1*n1* 1*sizeof(itemtype)); const itemtype (*b212)[ 1][n1][ 1] = (const itemtype(*)[ 1][n1][ 1])dfb212.getData<itemtype>(); for (k=1;k<n1-1;k++) (*v)[n0-1][k][n2-1] = (*b212)[0][k][0];
}

void c_mesh3d_exchange_27_get_11_00_10(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb010,OutputDF &dfb011,OutputDF &dfb110,OutputDF &dfb210,OutputDF &dfb211)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b010)[ 1][n1][ 1] = (itemtype(*)[ 1][n1][ 1])dfb010.create<itemtype>( 1*n1* 1); for (k=0;k<n1;k++) (*b010)[0][k][0] = (*u)[1][k][1];
  itemtype (*b011)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb011.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b011)[0][k][l] = (*u)[1][k][l];
  itemtype (*b110)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb110.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b110)[i][k][0] = (*u)[i][k][1];
  itemtype (*b210)[ 1][n1][ 1] = (itemtype(*)[ 1][n1][ 1])dfb210.create<itemtype>( 1*n1* 1); for (k=0;k<n1;k++) (*b210)[0][k][0] = (*u)[n0-2][k][1];
  itemtype (*b211)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb211.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b211)[0][k][l] = (*u)[n0-2][k][l];
}

void c_mesh3d_exchange_27_set_11_00_10(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb010,const InputDF &dfb011,const InputDF &dfb110,const InputDF &dfb210,const InputDF &dfb211,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb010.getSize() ==  1*n1* 1*sizeof(itemtype)); const itemtype (*b010)[ 1][n1][ 1] = (const itemtype(*)[ 1][n1][ 1])dfb010.getData<itemtype>(); for (k=1;k<n1-1;k++) (*v)[0][k][0] = (*b010)[0][k][0];
  assert(dfb011.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b011)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb011.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[0][k][l] = (*b011)[0][k][l];
  assert(dfb110.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b110)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb110.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][0] = (*b110)[i][k][0];
  assert(dfb210.getSize() ==  1*n1* 1*sizeof(itemtype)); const itemtype (*b210)[ 1][n1][ 1] = (const itemtype(*)[ 1][n1][ 1])dfb210.getData<itemtype>(); for (k=1;k<n1-1;k++) (*v)[n0-1][k][0] = (*b210)[0][k][0];
  assert(dfb211.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b211)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb211.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[n0-1][k][l] = (*b211)[0][k][l];
}

void c_mesh3d_exchange_27_get_11_00_11(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb010,OutputDF &dfb011,OutputDF &dfb012,OutputDF &dfb110,OutputDF &dfb112,OutputDF &dfb210,OutputDF &dfb211,OutputDF &dfb212)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b010)[ 1][n1][ 1] = (itemtype(*)[ 1][n1][ 1])dfb010.create<itemtype>( 1*n1* 1); for (k=0;k<n1;k++) (*b010)[0][k][0] = (*u)[1][k][1];
  itemtype (*b011)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb011.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b011)[0][k][l] = (*u)[1][k][l];
  itemtype (*b012)[ 1][n1][ 1] = (itemtype(*)[ 1][n1][ 1])dfb012.create<itemtype>( 1*n1* 1); for (k=0;k<n1;k++) (*b012)[0][k][0] = (*u)[1][k][n2-2];
  itemtype (*b110)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb110.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b110)[i][k][0] = (*u)[i][k][1];
  itemtype (*b112)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb112.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b112)[i][k][0] = (*u)[i][k][n2-2];
  itemtype (*b210)[ 1][n1][ 1] = (itemtype(*)[ 1][n1][ 1])dfb210.create<itemtype>( 1*n1* 1); for (k=0;k<n1;k++) (*b210)[0][k][0] = (*u)[n0-2][k][1];
  itemtype (*b211)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb211.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b211)[0][k][l] = (*u)[n0-2][k][l];
  itemtype (*b212)[ 1][n1][ 1] = (itemtype(*)[ 1][n1][ 1])dfb212.create<itemtype>( 1*n1* 1); for (k=0;k<n1;k++) (*b212)[0][k][0] = (*u)[n0-2][k][n2-2];
}

void c_mesh3d_exchange_27_set_11_00_11(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb010,const InputDF &dfb011,const InputDF &dfb012,const InputDF &dfb110,const InputDF &dfb112,const InputDF &dfb210,const InputDF &dfb211,const InputDF &dfb212,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb010.getSize() ==  1*n1* 1*sizeof(itemtype)); const itemtype (*b010)[ 1][n1][ 1] = (const itemtype(*)[ 1][n1][ 1])dfb010.getData<itemtype>(); for (k=1;k<n1-1;k++) (*v)[0][k][0] = (*b010)[0][k][0];
  assert(dfb011.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b011)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb011.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[0][k][l] = (*b011)[0][k][l];
  assert(dfb012.getSize() ==  1*n1* 1*sizeof(itemtype)); const itemtype (*b012)[ 1][n1][ 1] = (const itemtype(*)[ 1][n1][ 1])dfb012.getData<itemtype>(); for (k=1;k<n1-1;k++) (*v)[0][k][n2-1] = (*b012)[0][k][0];
  assert(dfb110.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b110)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb110.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][0] = (*b110)[i][k][0];
  assert(dfb112.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b112)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb112.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][n2-1] = (*b112)[i][k][0];
  assert(dfb210.getSize() ==  1*n1* 1*sizeof(itemtype)); const itemtype (*b210)[ 1][n1][ 1] = (const itemtype(*)[ 1][n1][ 1])dfb210.getData<itemtype>(); for (k=1;k<n1-1;k++) (*v)[n0-1][k][0] = (*b210)[0][k][0];
  assert(dfb211.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b211)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb211.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[n0-1][k][l] = (*b211)[0][k][l];
  assert(dfb212.getSize() ==  1*n1* 1*sizeof(itemtype)); const itemtype (*b212)[ 1][n1][ 1] = (const itemtype(*)[ 1][n1][ 1])dfb212.getData<itemtype>(); for (k=1;k<n1-1;k++) (*v)[n0-1][k][n2-1] = (*b212)[0][k][0];
}

void c_mesh3d_exchange_27_get_11_01_00(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb011,OutputDF &dfb021,OutputDF &dfb121,OutputDF &dfb211,OutputDF &dfb221)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b011)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb011.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b011)[0][k][l] = (*u)[1][k][l];
  itemtype (*b021)[ 1][ 1][n2] = (itemtype(*)[ 1][ 1][n2])dfb021.create<itemtype>( 1* 1*n2); for (l=0;l<n2;l++) (*b021)[0][0][l] = (*u)[1][n1-2][l];
  itemtype (*b121)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb121.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b121)[i][0][l] = (*u)[i][n1-2][l];
  itemtype (*b211)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb211.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b211)[0][k][l] = (*u)[n0-2][k][l];
  itemtype (*b221)[ 1][ 1][n2] = (itemtype(*)[ 1][ 1][n2])dfb221.create<itemtype>( 1* 1*n2); for (l=0;l<n2;l++) (*b221)[0][0][l] = (*u)[n0-2][n1-2][l];
}

void c_mesh3d_exchange_27_set_11_01_00(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb011,const InputDF &dfb021,const InputDF &dfb121,const InputDF &dfb211,const InputDF &dfb221,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb011.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b011)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb011.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[0][k][l] = (*b011)[0][k][l];
  assert(dfb021.getSize() ==  1* 1*n2*sizeof(itemtype)); const itemtype (*b021)[ 1][ 1][n2] = (const itemtype(*)[ 1][ 1][n2])dfb021.getData<itemtype>(); for (l=1;l<n2-1;l++) (*v)[0][n1-1][l] = (*b021)[0][0][l];
  assert(dfb121.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b121)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb121.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][n1-1][l] = (*b121)[i][0][l];
  assert(dfb211.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b211)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb211.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[n0-1][k][l] = (*b211)[0][k][l];
  assert(dfb221.getSize() ==  1* 1*n2*sizeof(itemtype)); const itemtype (*b221)[ 1][ 1][n2] = (const itemtype(*)[ 1][ 1][n2])dfb221.getData<itemtype>(); for (l=1;l<n2-1;l++) (*v)[n0-1][n1-1][l] = (*b221)[0][0][l];
}

void c_mesh3d_exchange_27_get_11_01_01(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb011,OutputDF &dfb012,OutputDF &dfb021,OutputDF &dfb022,OutputDF &dfb112,OutputDF &dfb121,OutputDF &dfb122,OutputDF &dfb211,OutputDF &dfb212,OutputDF &dfb221,OutputDF &dfb222)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b011)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb011.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b011)[0][k][l] = (*u)[1][k][l];
  itemtype (*b012)[ 1][n1][ 1] = (itemtype(*)[ 1][n1][ 1])dfb012.create<itemtype>( 1*n1* 1); for (k=0;k<n1;k++) (*b012)[0][k][0] = (*u)[1][k][n2-2];
  itemtype (*b021)[ 1][ 1][n2] = (itemtype(*)[ 1][ 1][n2])dfb021.create<itemtype>( 1* 1*n2); for (l=0;l<n2;l++) (*b021)[0][0][l] = (*u)[1][n1-2][l];
  itemtype (*b022)[ 1][ 1][ 1] = (itemtype(*)[ 1][ 1][ 1])dfb022.create<itemtype>( 1* 1* 1); (*b022)[0][0][0] = (*u)[1][n1-2][n2-2];
  itemtype (*b112)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb112.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b112)[i][k][0] = (*u)[i][k][n2-2];
  itemtype (*b121)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb121.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b121)[i][0][l] = (*u)[i][n1-2][l];
  itemtype (*b122)[n0][ 1][ 1] = (itemtype(*)[n0][ 1][ 1])dfb122.create<itemtype>(n0* 1* 1); for (i=0;i<n0;i++) (*b122)[i][0][0] = (*u)[i][n1-2][n2-2];
  itemtype (*b211)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb211.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b211)[0][k][l] = (*u)[n0-2][k][l];
  itemtype (*b212)[ 1][n1][ 1] = (itemtype(*)[ 1][n1][ 1])dfb212.create<itemtype>( 1*n1* 1); for (k=0;k<n1;k++) (*b212)[0][k][0] = (*u)[n0-2][k][n2-2];
  itemtype (*b221)[ 1][ 1][n2] = (itemtype(*)[ 1][ 1][n2])dfb221.create<itemtype>( 1* 1*n2); for (l=0;l<n2;l++) (*b221)[0][0][l] = (*u)[n0-2][n1-2][l];
  itemtype (*b222)[ 1][ 1][ 1] = (itemtype(*)[ 1][ 1][ 1])dfb222.create<itemtype>( 1* 1* 1); (*b222)[0][0][0] = (*u)[n0-2][n1-2][n2-2];
}

void c_mesh3d_exchange_27_set_11_01_01(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb011,const InputDF &dfb012,const InputDF &dfb021,const InputDF &dfb022,const InputDF &dfb112,const InputDF &dfb121,const InputDF &dfb122,const InputDF &dfb211,const InputDF &dfb212,const InputDF &dfb221,const InputDF &dfb222,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb011.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b011)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb011.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[0][k][l] = (*b011)[0][k][l];
  assert(dfb012.getSize() ==  1*n1* 1*sizeof(itemtype)); const itemtype (*b012)[ 1][n1][ 1] = (const itemtype(*)[ 1][n1][ 1])dfb012.getData<itemtype>(); for (k=1;k<n1-1;k++) (*v)[0][k][n2-1] = (*b012)[0][k][0];
  assert(dfb021.getSize() ==  1* 1*n2*sizeof(itemtype)); const itemtype (*b021)[ 1][ 1][n2] = (const itemtype(*)[ 1][ 1][n2])dfb021.getData<itemtype>(); for (l=1;l<n2-1;l++) (*v)[0][n1-1][l] = (*b021)[0][0][l];
  assert(dfb022.getSize() ==  1* 1* 1*sizeof(itemtype)); const itemtype (*b022)[ 1][ 1][ 1] = (const itemtype(*)[ 1][ 1][ 1])dfb022.getData<itemtype>(); (*v)[0][n1-1][n2-1] = (*b022)[0][0][0];
  assert(dfb112.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b112)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb112.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][n2-1] = (*b112)[i][k][0];
  assert(dfb121.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b121)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb121.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][n1-1][l] = (*b121)[i][0][l];
  assert(dfb122.getSize() == n0* 1* 1*sizeof(itemtype)); const itemtype (*b122)[n0][ 1][ 1] = (const itemtype(*)[n0][ 1][ 1])dfb122.getData<itemtype>(); for (i=1;i<n0-1;i++) (*v)[i][n1-1][n2-1] = (*b122)[i][0][0];
  assert(dfb211.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b211)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb211.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[n0-1][k][l] = (*b211)[0][k][l];
  assert(dfb212.getSize() ==  1*n1* 1*sizeof(itemtype)); const itemtype (*b212)[ 1][n1][ 1] = (const itemtype(*)[ 1][n1][ 1])dfb212.getData<itemtype>(); for (k=1;k<n1-1;k++) (*v)[n0-1][k][n2-1] = (*b212)[0][k][0];
  assert(dfb221.getSize() ==  1* 1*n2*sizeof(itemtype)); const itemtype (*b221)[ 1][ 1][n2] = (const itemtype(*)[ 1][ 1][n2])dfb221.getData<itemtype>(); for (l=1;l<n2-1;l++) (*v)[n0-1][n1-1][l] = (*b221)[0][0][l];
  assert(dfb222.getSize() ==  1* 1* 1*sizeof(itemtype)); const itemtype (*b222)[ 1][ 1][ 1] = (const itemtype(*)[ 1][ 1][ 1])dfb222.getData<itemtype>(); (*v)[n0-1][n1-1][n2-1] = (*b222)[0][0][0];
}

void c_mesh3d_exchange_27_get_11_01_10(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb010,OutputDF &dfb011,OutputDF &dfb020,OutputDF &dfb021,OutputDF &dfb110,OutputDF &dfb120,OutputDF &dfb121,OutputDF &dfb210,OutputDF &dfb211,OutputDF &dfb220,OutputDF &dfb221)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b010)[ 1][n1][ 1] = (itemtype(*)[ 1][n1][ 1])dfb010.create<itemtype>( 1*n1* 1); for (k=0;k<n1;k++) (*b010)[0][k][0] = (*u)[1][k][1];
  itemtype (*b011)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb011.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b011)[0][k][l] = (*u)[1][k][l];
  itemtype (*b020)[ 1][ 1][ 1] = (itemtype(*)[ 1][ 1][ 1])dfb020.create<itemtype>( 1* 1* 1); (*b020)[0][0][0] = (*u)[1][n1-2][1];
  itemtype (*b021)[ 1][ 1][n2] = (itemtype(*)[ 1][ 1][n2])dfb021.create<itemtype>( 1* 1*n2); for (l=0;l<n2;l++) (*b021)[0][0][l] = (*u)[1][n1-2][l];
  itemtype (*b110)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb110.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b110)[i][k][0] = (*u)[i][k][1];
  itemtype (*b120)[n0][ 1][ 1] = (itemtype(*)[n0][ 1][ 1])dfb120.create<itemtype>(n0* 1* 1); for (i=0;i<n0;i++) (*b120)[i][0][0] = (*u)[i][n1-2][1];
  itemtype (*b121)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb121.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b121)[i][0][l] = (*u)[i][n1-2][l];
  itemtype (*b210)[ 1][n1][ 1] = (itemtype(*)[ 1][n1][ 1])dfb210.create<itemtype>( 1*n1* 1); for (k=0;k<n1;k++) (*b210)[0][k][0] = (*u)[n0-2][k][1];
  itemtype (*b211)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb211.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b211)[0][k][l] = (*u)[n0-2][k][l];
  itemtype (*b220)[ 1][ 1][ 1] = (itemtype(*)[ 1][ 1][ 1])dfb220.create<itemtype>( 1* 1* 1); (*b220)[0][0][0] = (*u)[n0-2][n1-2][1];
  itemtype (*b221)[ 1][ 1][n2] = (itemtype(*)[ 1][ 1][n2])dfb221.create<itemtype>( 1* 1*n2); for (l=0;l<n2;l++) (*b221)[0][0][l] = (*u)[n0-2][n1-2][l];
}

void c_mesh3d_exchange_27_set_11_01_10(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb010,const InputDF &dfb011,const InputDF &dfb020,const InputDF &dfb021,const InputDF &dfb110,const InputDF &dfb120,const InputDF &dfb121,const InputDF &dfb210,const InputDF &dfb211,const InputDF &dfb220,const InputDF &dfb221,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb010.getSize() ==  1*n1* 1*sizeof(itemtype)); const itemtype (*b010)[ 1][n1][ 1] = (const itemtype(*)[ 1][n1][ 1])dfb010.getData<itemtype>(); for (k=1;k<n1-1;k++) (*v)[0][k][0] = (*b010)[0][k][0];
  assert(dfb011.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b011)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb011.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[0][k][l] = (*b011)[0][k][l];
  assert(dfb020.getSize() ==  1* 1* 1*sizeof(itemtype)); const itemtype (*b020)[ 1][ 1][ 1] = (const itemtype(*)[ 1][ 1][ 1])dfb020.getData<itemtype>(); (*v)[0][n1-1][0] = (*b020)[0][0][0];
  assert(dfb021.getSize() ==  1* 1*n2*sizeof(itemtype)); const itemtype (*b021)[ 1][ 1][n2] = (const itemtype(*)[ 1][ 1][n2])dfb021.getData<itemtype>(); for (l=1;l<n2-1;l++) (*v)[0][n1-1][l] = (*b021)[0][0][l];
  assert(dfb110.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b110)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb110.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][0] = (*b110)[i][k][0];
  assert(dfb120.getSize() == n0* 1* 1*sizeof(itemtype)); const itemtype (*b120)[n0][ 1][ 1] = (const itemtype(*)[n0][ 1][ 1])dfb120.getData<itemtype>(); for (i=1;i<n0-1;i++) (*v)[i][n1-1][0] = (*b120)[i][0][0];
  assert(dfb121.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b121)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb121.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][n1-1][l] = (*b121)[i][0][l];
  assert(dfb210.getSize() ==  1*n1* 1*sizeof(itemtype)); const itemtype (*b210)[ 1][n1][ 1] = (const itemtype(*)[ 1][n1][ 1])dfb210.getData<itemtype>(); for (k=1;k<n1-1;k++) (*v)[n0-1][k][0] = (*b210)[0][k][0];
  assert(dfb211.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b211)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb211.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[n0-1][k][l] = (*b211)[0][k][l];
  assert(dfb220.getSize() ==  1* 1* 1*sizeof(itemtype)); const itemtype (*b220)[ 1][ 1][ 1] = (const itemtype(*)[ 1][ 1][ 1])dfb220.getData<itemtype>(); (*v)[n0-1][n1-1][0] = (*b220)[0][0][0];
  assert(dfb221.getSize() ==  1* 1*n2*sizeof(itemtype)); const itemtype (*b221)[ 1][ 1][n2] = (const itemtype(*)[ 1][ 1][n2])dfb221.getData<itemtype>(); for (l=1;l<n2-1;l++) (*v)[n0-1][n1-1][l] = (*b221)[0][0][l];
}

void c_mesh3d_exchange_27_get_11_01_11(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb010,OutputDF &dfb011,OutputDF &dfb012,OutputDF &dfb020,OutputDF &dfb021,OutputDF &dfb022,OutputDF &dfb110,OutputDF &dfb112,OutputDF &dfb120,OutputDF &dfb121,OutputDF &dfb122,OutputDF &dfb210,OutputDF &dfb211,OutputDF &dfb212,OutputDF &dfb220,OutputDF &dfb221,OutputDF &dfb222)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b010)[ 1][n1][ 1] = (itemtype(*)[ 1][n1][ 1])dfb010.create<itemtype>( 1*n1* 1); for (k=0;k<n1;k++) (*b010)[0][k][0] = (*u)[1][k][1];
  itemtype (*b011)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb011.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b011)[0][k][l] = (*u)[1][k][l];
  itemtype (*b012)[ 1][n1][ 1] = (itemtype(*)[ 1][n1][ 1])dfb012.create<itemtype>( 1*n1* 1); for (k=0;k<n1;k++) (*b012)[0][k][0] = (*u)[1][k][n2-2];
  itemtype (*b020)[ 1][ 1][ 1] = (itemtype(*)[ 1][ 1][ 1])dfb020.create<itemtype>( 1* 1* 1); (*b020)[0][0][0] = (*u)[1][n1-2][1];
  itemtype (*b021)[ 1][ 1][n2] = (itemtype(*)[ 1][ 1][n2])dfb021.create<itemtype>( 1* 1*n2); for (l=0;l<n2;l++) (*b021)[0][0][l] = (*u)[1][n1-2][l];
  itemtype (*b022)[ 1][ 1][ 1] = (itemtype(*)[ 1][ 1][ 1])dfb022.create<itemtype>( 1* 1* 1); (*b022)[0][0][0] = (*u)[1][n1-2][n2-2];
  itemtype (*b110)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb110.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b110)[i][k][0] = (*u)[i][k][1];
  itemtype (*b112)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb112.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b112)[i][k][0] = (*u)[i][k][n2-2];
  itemtype (*b120)[n0][ 1][ 1] = (itemtype(*)[n0][ 1][ 1])dfb120.create<itemtype>(n0* 1* 1); for (i=0;i<n0;i++) (*b120)[i][0][0] = (*u)[i][n1-2][1];
  itemtype (*b121)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb121.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b121)[i][0][l] = (*u)[i][n1-2][l];
  itemtype (*b122)[n0][ 1][ 1] = (itemtype(*)[n0][ 1][ 1])dfb122.create<itemtype>(n0* 1* 1); for (i=0;i<n0;i++) (*b122)[i][0][0] = (*u)[i][n1-2][n2-2];
  itemtype (*b210)[ 1][n1][ 1] = (itemtype(*)[ 1][n1][ 1])dfb210.create<itemtype>( 1*n1* 1); for (k=0;k<n1;k++) (*b210)[0][k][0] = (*u)[n0-2][k][1];
  itemtype (*b211)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb211.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b211)[0][k][l] = (*u)[n0-2][k][l];
  itemtype (*b212)[ 1][n1][ 1] = (itemtype(*)[ 1][n1][ 1])dfb212.create<itemtype>( 1*n1* 1); for (k=0;k<n1;k++) (*b212)[0][k][0] = (*u)[n0-2][k][n2-2];
  itemtype (*b220)[ 1][ 1][ 1] = (itemtype(*)[ 1][ 1][ 1])dfb220.create<itemtype>( 1* 1* 1); (*b220)[0][0][0] = (*u)[n0-2][n1-2][1];
  itemtype (*b221)[ 1][ 1][n2] = (itemtype(*)[ 1][ 1][n2])dfb221.create<itemtype>( 1* 1*n2); for (l=0;l<n2;l++) (*b221)[0][0][l] = (*u)[n0-2][n1-2][l];
  itemtype (*b222)[ 1][ 1][ 1] = (itemtype(*)[ 1][ 1][ 1])dfb222.create<itemtype>( 1* 1* 1); (*b222)[0][0][0] = (*u)[n0-2][n1-2][n2-2];
}

void c_mesh3d_exchange_27_set_11_01_11(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb010,const InputDF &dfb011,const InputDF &dfb012,const InputDF &dfb020,const InputDF &dfb021,const InputDF &dfb022,const InputDF &dfb110,const InputDF &dfb112,const InputDF &dfb120,const InputDF &dfb121,const InputDF &dfb122,const InputDF &dfb210,const InputDF &dfb211,const InputDF &dfb212,const InputDF &dfb220,const InputDF &dfb221,const InputDF &dfb222,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb010.getSize() ==  1*n1* 1*sizeof(itemtype)); const itemtype (*b010)[ 1][n1][ 1] = (const itemtype(*)[ 1][n1][ 1])dfb010.getData<itemtype>(); for (k=1;k<n1-1;k++) (*v)[0][k][0] = (*b010)[0][k][0];
  assert(dfb011.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b011)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb011.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[0][k][l] = (*b011)[0][k][l];
  assert(dfb012.getSize() ==  1*n1* 1*sizeof(itemtype)); const itemtype (*b012)[ 1][n1][ 1] = (const itemtype(*)[ 1][n1][ 1])dfb012.getData<itemtype>(); for (k=1;k<n1-1;k++) (*v)[0][k][n2-1] = (*b012)[0][k][0];
  assert(dfb020.getSize() ==  1* 1* 1*sizeof(itemtype)); const itemtype (*b020)[ 1][ 1][ 1] = (const itemtype(*)[ 1][ 1][ 1])dfb020.getData<itemtype>(); (*v)[0][n1-1][0] = (*b020)[0][0][0];
  assert(dfb021.getSize() ==  1* 1*n2*sizeof(itemtype)); const itemtype (*b021)[ 1][ 1][n2] = (const itemtype(*)[ 1][ 1][n2])dfb021.getData<itemtype>(); for (l=1;l<n2-1;l++) (*v)[0][n1-1][l] = (*b021)[0][0][l];
  assert(dfb022.getSize() ==  1* 1* 1*sizeof(itemtype)); const itemtype (*b022)[ 1][ 1][ 1] = (const itemtype(*)[ 1][ 1][ 1])dfb022.getData<itemtype>(); (*v)[0][n1-1][n2-1] = (*b022)[0][0][0];
  assert(dfb110.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b110)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb110.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][0] = (*b110)[i][k][0];
  assert(dfb112.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b112)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb112.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][n2-1] = (*b112)[i][k][0];
  assert(dfb120.getSize() == n0* 1* 1*sizeof(itemtype)); const itemtype (*b120)[n0][ 1][ 1] = (const itemtype(*)[n0][ 1][ 1])dfb120.getData<itemtype>(); for (i=1;i<n0-1;i++) (*v)[i][n1-1][0] = (*b120)[i][0][0];
  assert(dfb121.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b121)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb121.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][n1-1][l] = (*b121)[i][0][l];
  assert(dfb122.getSize() == n0* 1* 1*sizeof(itemtype)); const itemtype (*b122)[n0][ 1][ 1] = (const itemtype(*)[n0][ 1][ 1])dfb122.getData<itemtype>(); for (i=1;i<n0-1;i++) (*v)[i][n1-1][n2-1] = (*b122)[i][0][0];
  assert(dfb210.getSize() ==  1*n1* 1*sizeof(itemtype)); const itemtype (*b210)[ 1][n1][ 1] = (const itemtype(*)[ 1][n1][ 1])dfb210.getData<itemtype>(); for (k=1;k<n1-1;k++) (*v)[n0-1][k][0] = (*b210)[0][k][0];
  assert(dfb211.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b211)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb211.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[n0-1][k][l] = (*b211)[0][k][l];
  assert(dfb212.getSize() ==  1*n1* 1*sizeof(itemtype)); const itemtype (*b212)[ 1][n1][ 1] = (const itemtype(*)[ 1][n1][ 1])dfb212.getData<itemtype>(); for (k=1;k<n1-1;k++) (*v)[n0-1][k][n2-1] = (*b212)[0][k][0];
  assert(dfb220.getSize() ==  1* 1* 1*sizeof(itemtype)); const itemtype (*b220)[ 1][ 1][ 1] = (const itemtype(*)[ 1][ 1][ 1])dfb220.getData<itemtype>(); (*v)[n0-1][n1-1][0] = (*b220)[0][0][0];
  assert(dfb221.getSize() ==  1* 1*n2*sizeof(itemtype)); const itemtype (*b221)[ 1][ 1][n2] = (const itemtype(*)[ 1][ 1][n2])dfb221.getData<itemtype>(); for (l=1;l<n2-1;l++) (*v)[n0-1][n1-1][l] = (*b221)[0][0][l];
  assert(dfb222.getSize() ==  1* 1* 1*sizeof(itemtype)); const itemtype (*b222)[ 1][ 1][ 1] = (const itemtype(*)[ 1][ 1][ 1])dfb222.getData<itemtype>(); (*v)[n0-1][n1-1][n2-1] = (*b222)[0][0][0];
}

void c_mesh3d_exchange_27_get_11_10_00(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb001,OutputDF &dfb011,OutputDF &dfb101,OutputDF &dfb201,OutputDF &dfb211)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b001)[ 1][ 1][n2] = (itemtype(*)[ 1][ 1][n2])dfb001.create<itemtype>( 1* 1*n2); for (l=0;l<n2;l++) (*b001)[0][0][l] = (*u)[1][1][l];
  itemtype (*b011)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb011.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b011)[0][k][l] = (*u)[1][k][l];
  itemtype (*b101)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb101.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b101)[i][0][l] = (*u)[i][1][l];
  itemtype (*b201)[ 1][ 1][n2] = (itemtype(*)[ 1][ 1][n2])dfb201.create<itemtype>( 1* 1*n2); for (l=0;l<n2;l++) (*b201)[0][0][l] = (*u)[n0-2][1][l];
  itemtype (*b211)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb211.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b211)[0][k][l] = (*u)[n0-2][k][l];
}

void c_mesh3d_exchange_27_set_11_10_00(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb001,const InputDF &dfb011,const InputDF &dfb101,const InputDF &dfb201,const InputDF &dfb211,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb001.getSize() ==  1* 1*n2*sizeof(itemtype)); const itemtype (*b001)[ 1][ 1][n2] = (const itemtype(*)[ 1][ 1][n2])dfb001.getData<itemtype>(); for (l=1;l<n2-1;l++) (*v)[0][0][l] = (*b001)[0][0][l];
  assert(dfb011.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b011)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb011.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[0][k][l] = (*b011)[0][k][l];
  assert(dfb101.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b101)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb101.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][0][l] = (*b101)[i][0][l];
  assert(dfb201.getSize() ==  1* 1*n2*sizeof(itemtype)); const itemtype (*b201)[ 1][ 1][n2] = (const itemtype(*)[ 1][ 1][n2])dfb201.getData<itemtype>(); for (l=1;l<n2-1;l++) (*v)[n0-1][0][l] = (*b201)[0][0][l];
  assert(dfb211.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b211)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb211.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[n0-1][k][l] = (*b211)[0][k][l];
}

void c_mesh3d_exchange_27_get_11_10_01(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb001,OutputDF &dfb002,OutputDF &dfb011,OutputDF &dfb012,OutputDF &dfb101,OutputDF &dfb102,OutputDF &dfb112,OutputDF &dfb201,OutputDF &dfb202,OutputDF &dfb211,OutputDF &dfb212)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b001)[ 1][ 1][n2] = (itemtype(*)[ 1][ 1][n2])dfb001.create<itemtype>( 1* 1*n2); for (l=0;l<n2;l++) (*b001)[0][0][l] = (*u)[1][1][l];
  itemtype (*b002)[ 1][ 1][ 1] = (itemtype(*)[ 1][ 1][ 1])dfb002.create<itemtype>( 1* 1* 1); (*b002)[0][0][0] = (*u)[1][1][n2-2];
  itemtype (*b011)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb011.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b011)[0][k][l] = (*u)[1][k][l];
  itemtype (*b012)[ 1][n1][ 1] = (itemtype(*)[ 1][n1][ 1])dfb012.create<itemtype>( 1*n1* 1); for (k=0;k<n1;k++) (*b012)[0][k][0] = (*u)[1][k][n2-2];
  itemtype (*b101)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb101.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b101)[i][0][l] = (*u)[i][1][l];
  itemtype (*b102)[n0][ 1][ 1] = (itemtype(*)[n0][ 1][ 1])dfb102.create<itemtype>(n0* 1* 1); for (i=0;i<n0;i++) (*b102)[i][0][0] = (*u)[i][1][n2-2];
  itemtype (*b112)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb112.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b112)[i][k][0] = (*u)[i][k][n2-2];
  itemtype (*b201)[ 1][ 1][n2] = (itemtype(*)[ 1][ 1][n2])dfb201.create<itemtype>( 1* 1*n2); for (l=0;l<n2;l++) (*b201)[0][0][l] = (*u)[n0-2][1][l];
  itemtype (*b202)[ 1][ 1][ 1] = (itemtype(*)[ 1][ 1][ 1])dfb202.create<itemtype>( 1* 1* 1); (*b202)[0][0][0] = (*u)[n0-2][1][n2-2];
  itemtype (*b211)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb211.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b211)[0][k][l] = (*u)[n0-2][k][l];
  itemtype (*b212)[ 1][n1][ 1] = (itemtype(*)[ 1][n1][ 1])dfb212.create<itemtype>( 1*n1* 1); for (k=0;k<n1;k++) (*b212)[0][k][0] = (*u)[n0-2][k][n2-2];
}

void c_mesh3d_exchange_27_set_11_10_01(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb001,const InputDF &dfb002,const InputDF &dfb011,const InputDF &dfb012,const InputDF &dfb101,const InputDF &dfb102,const InputDF &dfb112,const InputDF &dfb201,const InputDF &dfb202,const InputDF &dfb211,const InputDF &dfb212,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb001.getSize() ==  1* 1*n2*sizeof(itemtype)); const itemtype (*b001)[ 1][ 1][n2] = (const itemtype(*)[ 1][ 1][n2])dfb001.getData<itemtype>(); for (l=1;l<n2-1;l++) (*v)[0][0][l] = (*b001)[0][0][l];
  assert(dfb002.getSize() ==  1* 1* 1*sizeof(itemtype)); const itemtype (*b002)[ 1][ 1][ 1] = (const itemtype(*)[ 1][ 1][ 1])dfb002.getData<itemtype>(); (*v)[0][0][n2-1] = (*b002)[0][0][0];
  assert(dfb011.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b011)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb011.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[0][k][l] = (*b011)[0][k][l];
  assert(dfb012.getSize() ==  1*n1* 1*sizeof(itemtype)); const itemtype (*b012)[ 1][n1][ 1] = (const itemtype(*)[ 1][n1][ 1])dfb012.getData<itemtype>(); for (k=1;k<n1-1;k++) (*v)[0][k][n2-1] = (*b012)[0][k][0];
  assert(dfb101.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b101)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb101.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][0][l] = (*b101)[i][0][l];
  assert(dfb102.getSize() == n0* 1* 1*sizeof(itemtype)); const itemtype (*b102)[n0][ 1][ 1] = (const itemtype(*)[n0][ 1][ 1])dfb102.getData<itemtype>(); for (i=1;i<n0-1;i++) (*v)[i][0][n2-1] = (*b102)[i][0][0];
  assert(dfb112.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b112)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb112.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][n2-1] = (*b112)[i][k][0];
  assert(dfb201.getSize() ==  1* 1*n2*sizeof(itemtype)); const itemtype (*b201)[ 1][ 1][n2] = (const itemtype(*)[ 1][ 1][n2])dfb201.getData<itemtype>(); for (l=1;l<n2-1;l++) (*v)[n0-1][0][l] = (*b201)[0][0][l];
  assert(dfb202.getSize() ==  1* 1* 1*sizeof(itemtype)); const itemtype (*b202)[ 1][ 1][ 1] = (const itemtype(*)[ 1][ 1][ 1])dfb202.getData<itemtype>(); (*v)[n0-1][0][n2-1] = (*b202)[0][0][0];
  assert(dfb211.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b211)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb211.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[n0-1][k][l] = (*b211)[0][k][l];
  assert(dfb212.getSize() ==  1*n1* 1*sizeof(itemtype)); const itemtype (*b212)[ 1][n1][ 1] = (const itemtype(*)[ 1][n1][ 1])dfb212.getData<itemtype>(); for (k=1;k<n1-1;k++) (*v)[n0-1][k][n2-1] = (*b212)[0][k][0];
}

void c_mesh3d_exchange_27_get_11_10_10(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb000,OutputDF &dfb001,OutputDF &dfb010,OutputDF &dfb011,OutputDF &dfb100,OutputDF &dfb101,OutputDF &dfb110,OutputDF &dfb200,OutputDF &dfb201,OutputDF &dfb210,OutputDF &dfb211)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b000)[ 1][ 1][ 1] = (itemtype(*)[ 1][ 1][ 1])dfb000.create<itemtype>( 1* 1* 1); (*b000)[0][0][0] = (*u)[1][1][1];
  itemtype (*b001)[ 1][ 1][n2] = (itemtype(*)[ 1][ 1][n2])dfb001.create<itemtype>( 1* 1*n2); for (l=0;l<n2;l++) (*b001)[0][0][l] = (*u)[1][1][l];
  itemtype (*b010)[ 1][n1][ 1] = (itemtype(*)[ 1][n1][ 1])dfb010.create<itemtype>( 1*n1* 1); for (k=0;k<n1;k++) (*b010)[0][k][0] = (*u)[1][k][1];
  itemtype (*b011)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb011.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b011)[0][k][l] = (*u)[1][k][l];
  itemtype (*b100)[n0][ 1][ 1] = (itemtype(*)[n0][ 1][ 1])dfb100.create<itemtype>(n0* 1* 1); for (i=0;i<n0;i++) (*b100)[i][0][0] = (*u)[i][1][1];
  itemtype (*b101)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb101.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b101)[i][0][l] = (*u)[i][1][l];
  itemtype (*b110)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb110.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b110)[i][k][0] = (*u)[i][k][1];
  itemtype (*b200)[ 1][ 1][ 1] = (itemtype(*)[ 1][ 1][ 1])dfb200.create<itemtype>( 1* 1* 1); (*b200)[0][0][0] = (*u)[n0-2][1][1];
  itemtype (*b201)[ 1][ 1][n2] = (itemtype(*)[ 1][ 1][n2])dfb201.create<itemtype>( 1* 1*n2); for (l=0;l<n2;l++) (*b201)[0][0][l] = (*u)[n0-2][1][l];
  itemtype (*b210)[ 1][n1][ 1] = (itemtype(*)[ 1][n1][ 1])dfb210.create<itemtype>( 1*n1* 1); for (k=0;k<n1;k++) (*b210)[0][k][0] = (*u)[n0-2][k][1];
  itemtype (*b211)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb211.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b211)[0][k][l] = (*u)[n0-2][k][l];
}

void c_mesh3d_exchange_27_set_11_10_10(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb000,const InputDF &dfb001,const InputDF &dfb010,const InputDF &dfb011,const InputDF &dfb100,const InputDF &dfb101,const InputDF &dfb110,const InputDF &dfb200,const InputDF &dfb201,const InputDF &dfb210,const InputDF &dfb211,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb000.getSize() ==  1* 1* 1*sizeof(itemtype)); const itemtype (*b000)[ 1][ 1][ 1] = (const itemtype(*)[ 1][ 1][ 1])dfb000.getData<itemtype>(); (*v)[0][0][0] = (*b000)[0][0][0];
  assert(dfb001.getSize() ==  1* 1*n2*sizeof(itemtype)); const itemtype (*b001)[ 1][ 1][n2] = (const itemtype(*)[ 1][ 1][n2])dfb001.getData<itemtype>(); for (l=1;l<n2-1;l++) (*v)[0][0][l] = (*b001)[0][0][l];
  assert(dfb010.getSize() ==  1*n1* 1*sizeof(itemtype)); const itemtype (*b010)[ 1][n1][ 1] = (const itemtype(*)[ 1][n1][ 1])dfb010.getData<itemtype>(); for (k=1;k<n1-1;k++) (*v)[0][k][0] = (*b010)[0][k][0];
  assert(dfb011.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b011)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb011.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[0][k][l] = (*b011)[0][k][l];
  assert(dfb100.getSize() == n0* 1* 1*sizeof(itemtype)); const itemtype (*b100)[n0][ 1][ 1] = (const itemtype(*)[n0][ 1][ 1])dfb100.getData<itemtype>(); for (i=1;i<n0-1;i++) (*v)[i][0][0] = (*b100)[i][0][0];
  assert(dfb101.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b101)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb101.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][0][l] = (*b101)[i][0][l];
  assert(dfb110.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b110)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb110.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][0] = (*b110)[i][k][0];
  assert(dfb200.getSize() ==  1* 1* 1*sizeof(itemtype)); const itemtype (*b200)[ 1][ 1][ 1] = (const itemtype(*)[ 1][ 1][ 1])dfb200.getData<itemtype>(); (*v)[n0-1][0][0] = (*b200)[0][0][0];
  assert(dfb201.getSize() ==  1* 1*n2*sizeof(itemtype)); const itemtype (*b201)[ 1][ 1][n2] = (const itemtype(*)[ 1][ 1][n2])dfb201.getData<itemtype>(); for (l=1;l<n2-1;l++) (*v)[n0-1][0][l] = (*b201)[0][0][l];
  assert(dfb210.getSize() ==  1*n1* 1*sizeof(itemtype)); const itemtype (*b210)[ 1][n1][ 1] = (const itemtype(*)[ 1][n1][ 1])dfb210.getData<itemtype>(); for (k=1;k<n1-1;k++) (*v)[n0-1][k][0] = (*b210)[0][k][0];
  assert(dfb211.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b211)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb211.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[n0-1][k][l] = (*b211)[0][k][l];
}

void c_mesh3d_exchange_27_get_11_10_11(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb000,OutputDF &dfb001,OutputDF &dfb002,OutputDF &dfb010,OutputDF &dfb011,OutputDF &dfb012,OutputDF &dfb100,OutputDF &dfb101,OutputDF &dfb102,OutputDF &dfb110,OutputDF &dfb112,OutputDF &dfb200,OutputDF &dfb201,OutputDF &dfb202,OutputDF &dfb210,OutputDF &dfb211,OutputDF &dfb212)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b000)[ 1][ 1][ 1] = (itemtype(*)[ 1][ 1][ 1])dfb000.create<itemtype>( 1* 1* 1); (*b000)[0][0][0] = (*u)[1][1][1];
  itemtype (*b001)[ 1][ 1][n2] = (itemtype(*)[ 1][ 1][n2])dfb001.create<itemtype>( 1* 1*n2); for (l=0;l<n2;l++) (*b001)[0][0][l] = (*u)[1][1][l];
  itemtype (*b002)[ 1][ 1][ 1] = (itemtype(*)[ 1][ 1][ 1])dfb002.create<itemtype>( 1* 1* 1); (*b002)[0][0][0] = (*u)[1][1][n2-2];
  itemtype (*b010)[ 1][n1][ 1] = (itemtype(*)[ 1][n1][ 1])dfb010.create<itemtype>( 1*n1* 1); for (k=0;k<n1;k++) (*b010)[0][k][0] = (*u)[1][k][1];
  itemtype (*b011)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb011.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b011)[0][k][l] = (*u)[1][k][l];
  itemtype (*b012)[ 1][n1][ 1] = (itemtype(*)[ 1][n1][ 1])dfb012.create<itemtype>( 1*n1* 1); for (k=0;k<n1;k++) (*b012)[0][k][0] = (*u)[1][k][n2-2];
  itemtype (*b100)[n0][ 1][ 1] = (itemtype(*)[n0][ 1][ 1])dfb100.create<itemtype>(n0* 1* 1); for (i=0;i<n0;i++) (*b100)[i][0][0] = (*u)[i][1][1];
  itemtype (*b101)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb101.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b101)[i][0][l] = (*u)[i][1][l];
  itemtype (*b102)[n0][ 1][ 1] = (itemtype(*)[n0][ 1][ 1])dfb102.create<itemtype>(n0* 1* 1); for (i=0;i<n0;i++) (*b102)[i][0][0] = (*u)[i][1][n2-2];
  itemtype (*b110)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb110.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b110)[i][k][0] = (*u)[i][k][1];
  itemtype (*b112)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb112.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b112)[i][k][0] = (*u)[i][k][n2-2];
  itemtype (*b200)[ 1][ 1][ 1] = (itemtype(*)[ 1][ 1][ 1])dfb200.create<itemtype>( 1* 1* 1); (*b200)[0][0][0] = (*u)[n0-2][1][1];
  itemtype (*b201)[ 1][ 1][n2] = (itemtype(*)[ 1][ 1][n2])dfb201.create<itemtype>( 1* 1*n2); for (l=0;l<n2;l++) (*b201)[0][0][l] = (*u)[n0-2][1][l];
  itemtype (*b202)[ 1][ 1][ 1] = (itemtype(*)[ 1][ 1][ 1])dfb202.create<itemtype>( 1* 1* 1); (*b202)[0][0][0] = (*u)[n0-2][1][n2-2];
  itemtype (*b210)[ 1][n1][ 1] = (itemtype(*)[ 1][n1][ 1])dfb210.create<itemtype>( 1*n1* 1); for (k=0;k<n1;k++) (*b210)[0][k][0] = (*u)[n0-2][k][1];
  itemtype (*b211)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb211.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b211)[0][k][l] = (*u)[n0-2][k][l];
  itemtype (*b212)[ 1][n1][ 1] = (itemtype(*)[ 1][n1][ 1])dfb212.create<itemtype>( 1*n1* 1); for (k=0;k<n1;k++) (*b212)[0][k][0] = (*u)[n0-2][k][n2-2];
}

void c_mesh3d_exchange_27_set_11_10_11(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb000,const InputDF &dfb001,const InputDF &dfb002,const InputDF &dfb010,const InputDF &dfb011,const InputDF &dfb012,const InputDF &dfb100,const InputDF &dfb101,const InputDF &dfb102,const InputDF &dfb110,const InputDF &dfb112,const InputDF &dfb200,const InputDF &dfb201,const InputDF &dfb202,const InputDF &dfb210,const InputDF &dfb211,const InputDF &dfb212,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb000.getSize() ==  1* 1* 1*sizeof(itemtype)); const itemtype (*b000)[ 1][ 1][ 1] = (const itemtype(*)[ 1][ 1][ 1])dfb000.getData<itemtype>(); (*v)[0][0][0] = (*b000)[0][0][0];
  assert(dfb001.getSize() ==  1* 1*n2*sizeof(itemtype)); const itemtype (*b001)[ 1][ 1][n2] = (const itemtype(*)[ 1][ 1][n2])dfb001.getData<itemtype>(); for (l=1;l<n2-1;l++) (*v)[0][0][l] = (*b001)[0][0][l];
  assert(dfb002.getSize() ==  1* 1* 1*sizeof(itemtype)); const itemtype (*b002)[ 1][ 1][ 1] = (const itemtype(*)[ 1][ 1][ 1])dfb002.getData<itemtype>(); (*v)[0][0][n2-1] = (*b002)[0][0][0];
  assert(dfb010.getSize() ==  1*n1* 1*sizeof(itemtype)); const itemtype (*b010)[ 1][n1][ 1] = (const itemtype(*)[ 1][n1][ 1])dfb010.getData<itemtype>(); for (k=1;k<n1-1;k++) (*v)[0][k][0] = (*b010)[0][k][0];
  assert(dfb011.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b011)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb011.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[0][k][l] = (*b011)[0][k][l];
  assert(dfb012.getSize() ==  1*n1* 1*sizeof(itemtype)); const itemtype (*b012)[ 1][n1][ 1] = (const itemtype(*)[ 1][n1][ 1])dfb012.getData<itemtype>(); for (k=1;k<n1-1;k++) (*v)[0][k][n2-1] = (*b012)[0][k][0];
  assert(dfb100.getSize() == n0* 1* 1*sizeof(itemtype)); const itemtype (*b100)[n0][ 1][ 1] = (const itemtype(*)[n0][ 1][ 1])dfb100.getData<itemtype>(); for (i=1;i<n0-1;i++) (*v)[i][0][0] = (*b100)[i][0][0];
  assert(dfb101.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b101)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb101.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][0][l] = (*b101)[i][0][l];
  assert(dfb102.getSize() == n0* 1* 1*sizeof(itemtype)); const itemtype (*b102)[n0][ 1][ 1] = (const itemtype(*)[n0][ 1][ 1])dfb102.getData<itemtype>(); for (i=1;i<n0-1;i++) (*v)[i][0][n2-1] = (*b102)[i][0][0];
  assert(dfb110.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b110)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb110.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][0] = (*b110)[i][k][0];
  assert(dfb112.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b112)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb112.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][n2-1] = (*b112)[i][k][0];
  assert(dfb200.getSize() ==  1* 1* 1*sizeof(itemtype)); const itemtype (*b200)[ 1][ 1][ 1] = (const itemtype(*)[ 1][ 1][ 1])dfb200.getData<itemtype>(); (*v)[n0-1][0][0] = (*b200)[0][0][0];
  assert(dfb201.getSize() ==  1* 1*n2*sizeof(itemtype)); const itemtype (*b201)[ 1][ 1][n2] = (const itemtype(*)[ 1][ 1][n2])dfb201.getData<itemtype>(); for (l=1;l<n2-1;l++) (*v)[n0-1][0][l] = (*b201)[0][0][l];
  assert(dfb202.getSize() ==  1* 1* 1*sizeof(itemtype)); const itemtype (*b202)[ 1][ 1][ 1] = (const itemtype(*)[ 1][ 1][ 1])dfb202.getData<itemtype>(); (*v)[n0-1][0][n2-1] = (*b202)[0][0][0];
  assert(dfb210.getSize() ==  1*n1* 1*sizeof(itemtype)); const itemtype (*b210)[ 1][n1][ 1] = (const itemtype(*)[ 1][n1][ 1])dfb210.getData<itemtype>(); for (k=1;k<n1-1;k++) (*v)[n0-1][k][0] = (*b210)[0][k][0];
  assert(dfb211.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b211)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb211.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[n0-1][k][l] = (*b211)[0][k][l];
  assert(dfb212.getSize() ==  1*n1* 1*sizeof(itemtype)); const itemtype (*b212)[ 1][n1][ 1] = (const itemtype(*)[ 1][n1][ 1])dfb212.getData<itemtype>(); for (k=1;k<n1-1;k++) (*v)[n0-1][k][n2-1] = (*b212)[0][k][0];
}

void c_mesh3d_exchange_27_get_11_11_00(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb001,OutputDF &dfb011,OutputDF &dfb021,OutputDF &dfb101,OutputDF &dfb121,OutputDF &dfb201,OutputDF &dfb211,OutputDF &dfb221)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b001)[ 1][ 1][n2] = (itemtype(*)[ 1][ 1][n2])dfb001.create<itemtype>( 1* 1*n2); for (l=0;l<n2;l++) (*b001)[0][0][l] = (*u)[1][1][l];
  itemtype (*b011)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb011.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b011)[0][k][l] = (*u)[1][k][l];
  itemtype (*b021)[ 1][ 1][n2] = (itemtype(*)[ 1][ 1][n2])dfb021.create<itemtype>( 1* 1*n2); for (l=0;l<n2;l++) (*b021)[0][0][l] = (*u)[1][n1-2][l];
  itemtype (*b101)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb101.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b101)[i][0][l] = (*u)[i][1][l];
  itemtype (*b121)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb121.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b121)[i][0][l] = (*u)[i][n1-2][l];
  itemtype (*b201)[ 1][ 1][n2] = (itemtype(*)[ 1][ 1][n2])dfb201.create<itemtype>( 1* 1*n2); for (l=0;l<n2;l++) (*b201)[0][0][l] = (*u)[n0-2][1][l];
  itemtype (*b211)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb211.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b211)[0][k][l] = (*u)[n0-2][k][l];
  itemtype (*b221)[ 1][ 1][n2] = (itemtype(*)[ 1][ 1][n2])dfb221.create<itemtype>( 1* 1*n2); for (l=0;l<n2;l++) (*b221)[0][0][l] = (*u)[n0-2][n1-2][l];
}

void c_mesh3d_exchange_27_set_11_11_00(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb001,const InputDF &dfb011,const InputDF &dfb021,const InputDF &dfb101,const InputDF &dfb121,const InputDF &dfb201,const InputDF &dfb211,const InputDF &dfb221,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb001.getSize() ==  1* 1*n2*sizeof(itemtype)); const itemtype (*b001)[ 1][ 1][n2] = (const itemtype(*)[ 1][ 1][n2])dfb001.getData<itemtype>(); for (l=1;l<n2-1;l++) (*v)[0][0][l] = (*b001)[0][0][l];
  assert(dfb011.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b011)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb011.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[0][k][l] = (*b011)[0][k][l];
  assert(dfb021.getSize() ==  1* 1*n2*sizeof(itemtype)); const itemtype (*b021)[ 1][ 1][n2] = (const itemtype(*)[ 1][ 1][n2])dfb021.getData<itemtype>(); for (l=1;l<n2-1;l++) (*v)[0][n1-1][l] = (*b021)[0][0][l];
  assert(dfb101.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b101)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb101.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][0][l] = (*b101)[i][0][l];
  assert(dfb121.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b121)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb121.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][n1-1][l] = (*b121)[i][0][l];
  assert(dfb201.getSize() ==  1* 1*n2*sizeof(itemtype)); const itemtype (*b201)[ 1][ 1][n2] = (const itemtype(*)[ 1][ 1][n2])dfb201.getData<itemtype>(); for (l=1;l<n2-1;l++) (*v)[n0-1][0][l] = (*b201)[0][0][l];
  assert(dfb211.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b211)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb211.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[n0-1][k][l] = (*b211)[0][k][l];
  assert(dfb221.getSize() ==  1* 1*n2*sizeof(itemtype)); const itemtype (*b221)[ 1][ 1][n2] = (const itemtype(*)[ 1][ 1][n2])dfb221.getData<itemtype>(); for (l=1;l<n2-1;l++) (*v)[n0-1][n1-1][l] = (*b221)[0][0][l];
}

void c_mesh3d_exchange_27_get_11_11_01(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb001,OutputDF &dfb002,OutputDF &dfb011,OutputDF &dfb012,OutputDF &dfb021,OutputDF &dfb022,OutputDF &dfb101,OutputDF &dfb102,OutputDF &dfb112,OutputDF &dfb121,OutputDF &dfb122,OutputDF &dfb201,OutputDF &dfb202,OutputDF &dfb211,OutputDF &dfb212,OutputDF &dfb221,OutputDF &dfb222)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b001)[ 1][ 1][n2] = (itemtype(*)[ 1][ 1][n2])dfb001.create<itemtype>( 1* 1*n2); for (l=0;l<n2;l++) (*b001)[0][0][l] = (*u)[1][1][l];
  itemtype (*b002)[ 1][ 1][ 1] = (itemtype(*)[ 1][ 1][ 1])dfb002.create<itemtype>( 1* 1* 1); (*b002)[0][0][0] = (*u)[1][1][n2-2];
  itemtype (*b011)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb011.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b011)[0][k][l] = (*u)[1][k][l];
  itemtype (*b012)[ 1][n1][ 1] = (itemtype(*)[ 1][n1][ 1])dfb012.create<itemtype>( 1*n1* 1); for (k=0;k<n1;k++) (*b012)[0][k][0] = (*u)[1][k][n2-2];
  itemtype (*b021)[ 1][ 1][n2] = (itemtype(*)[ 1][ 1][n2])dfb021.create<itemtype>( 1* 1*n2); for (l=0;l<n2;l++) (*b021)[0][0][l] = (*u)[1][n1-2][l];
  itemtype (*b022)[ 1][ 1][ 1] = (itemtype(*)[ 1][ 1][ 1])dfb022.create<itemtype>( 1* 1* 1); (*b022)[0][0][0] = (*u)[1][n1-2][n2-2];
  itemtype (*b101)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb101.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b101)[i][0][l] = (*u)[i][1][l];
  itemtype (*b102)[n0][ 1][ 1] = (itemtype(*)[n0][ 1][ 1])dfb102.create<itemtype>(n0* 1* 1); for (i=0;i<n0;i++) (*b102)[i][0][0] = (*u)[i][1][n2-2];
  itemtype (*b112)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb112.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b112)[i][k][0] = (*u)[i][k][n2-2];
  itemtype (*b121)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb121.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b121)[i][0][l] = (*u)[i][n1-2][l];
  itemtype (*b122)[n0][ 1][ 1] = (itemtype(*)[n0][ 1][ 1])dfb122.create<itemtype>(n0* 1* 1); for (i=0;i<n0;i++) (*b122)[i][0][0] = (*u)[i][n1-2][n2-2];
  itemtype (*b201)[ 1][ 1][n2] = (itemtype(*)[ 1][ 1][n2])dfb201.create<itemtype>( 1* 1*n2); for (l=0;l<n2;l++) (*b201)[0][0][l] = (*u)[n0-2][1][l];
  itemtype (*b202)[ 1][ 1][ 1] = (itemtype(*)[ 1][ 1][ 1])dfb202.create<itemtype>( 1* 1* 1); (*b202)[0][0][0] = (*u)[n0-2][1][n2-2];
  itemtype (*b211)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb211.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b211)[0][k][l] = (*u)[n0-2][k][l];
  itemtype (*b212)[ 1][n1][ 1] = (itemtype(*)[ 1][n1][ 1])dfb212.create<itemtype>( 1*n1* 1); for (k=0;k<n1;k++) (*b212)[0][k][0] = (*u)[n0-2][k][n2-2];
  itemtype (*b221)[ 1][ 1][n2] = (itemtype(*)[ 1][ 1][n2])dfb221.create<itemtype>( 1* 1*n2); for (l=0;l<n2;l++) (*b221)[0][0][l] = (*u)[n0-2][n1-2][l];
  itemtype (*b222)[ 1][ 1][ 1] = (itemtype(*)[ 1][ 1][ 1])dfb222.create<itemtype>( 1* 1* 1); (*b222)[0][0][0] = (*u)[n0-2][n1-2][n2-2];
}

void c_mesh3d_exchange_27_set_11_11_01(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb001,const InputDF &dfb002,const InputDF &dfb011,const InputDF &dfb012,const InputDF &dfb021,const InputDF &dfb022,const InputDF &dfb101,const InputDF &dfb102,const InputDF &dfb112,const InputDF &dfb121,const InputDF &dfb122,const InputDF &dfb201,const InputDF &dfb202,const InputDF &dfb211,const InputDF &dfb212,const InputDF &dfb221,const InputDF &dfb222,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb001.getSize() ==  1* 1*n2*sizeof(itemtype)); const itemtype (*b001)[ 1][ 1][n2] = (const itemtype(*)[ 1][ 1][n2])dfb001.getData<itemtype>(); for (l=1;l<n2-1;l++) (*v)[0][0][l] = (*b001)[0][0][l];
  assert(dfb002.getSize() ==  1* 1* 1*sizeof(itemtype)); const itemtype (*b002)[ 1][ 1][ 1] = (const itemtype(*)[ 1][ 1][ 1])dfb002.getData<itemtype>(); (*v)[0][0][n2-1] = (*b002)[0][0][0];
  assert(dfb011.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b011)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb011.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[0][k][l] = (*b011)[0][k][l];
  assert(dfb012.getSize() ==  1*n1* 1*sizeof(itemtype)); const itemtype (*b012)[ 1][n1][ 1] = (const itemtype(*)[ 1][n1][ 1])dfb012.getData<itemtype>(); for (k=1;k<n1-1;k++) (*v)[0][k][n2-1] = (*b012)[0][k][0];
  assert(dfb021.getSize() ==  1* 1*n2*sizeof(itemtype)); const itemtype (*b021)[ 1][ 1][n2] = (const itemtype(*)[ 1][ 1][n2])dfb021.getData<itemtype>(); for (l=1;l<n2-1;l++) (*v)[0][n1-1][l] = (*b021)[0][0][l];
  assert(dfb022.getSize() ==  1* 1* 1*sizeof(itemtype)); const itemtype (*b022)[ 1][ 1][ 1] = (const itemtype(*)[ 1][ 1][ 1])dfb022.getData<itemtype>(); (*v)[0][n1-1][n2-1] = (*b022)[0][0][0];
  assert(dfb101.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b101)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb101.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][0][l] = (*b101)[i][0][l];
  assert(dfb102.getSize() == n0* 1* 1*sizeof(itemtype)); const itemtype (*b102)[n0][ 1][ 1] = (const itemtype(*)[n0][ 1][ 1])dfb102.getData<itemtype>(); for (i=1;i<n0-1;i++) (*v)[i][0][n2-1] = (*b102)[i][0][0];
  assert(dfb112.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b112)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb112.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][n2-1] = (*b112)[i][k][0];
  assert(dfb121.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b121)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb121.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][n1-1][l] = (*b121)[i][0][l];
  assert(dfb122.getSize() == n0* 1* 1*sizeof(itemtype)); const itemtype (*b122)[n0][ 1][ 1] = (const itemtype(*)[n0][ 1][ 1])dfb122.getData<itemtype>(); for (i=1;i<n0-1;i++) (*v)[i][n1-1][n2-1] = (*b122)[i][0][0];
  assert(dfb201.getSize() ==  1* 1*n2*sizeof(itemtype)); const itemtype (*b201)[ 1][ 1][n2] = (const itemtype(*)[ 1][ 1][n2])dfb201.getData<itemtype>(); for (l=1;l<n2-1;l++) (*v)[n0-1][0][l] = (*b201)[0][0][l];
  assert(dfb202.getSize() ==  1* 1* 1*sizeof(itemtype)); const itemtype (*b202)[ 1][ 1][ 1] = (const itemtype(*)[ 1][ 1][ 1])dfb202.getData<itemtype>(); (*v)[n0-1][0][n2-1] = (*b202)[0][0][0];
  assert(dfb211.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b211)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb211.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[n0-1][k][l] = (*b211)[0][k][l];
  assert(dfb212.getSize() ==  1*n1* 1*sizeof(itemtype)); const itemtype (*b212)[ 1][n1][ 1] = (const itemtype(*)[ 1][n1][ 1])dfb212.getData<itemtype>(); for (k=1;k<n1-1;k++) (*v)[n0-1][k][n2-1] = (*b212)[0][k][0];
  assert(dfb221.getSize() ==  1* 1*n2*sizeof(itemtype)); const itemtype (*b221)[ 1][ 1][n2] = (const itemtype(*)[ 1][ 1][n2])dfb221.getData<itemtype>(); for (l=1;l<n2-1;l++) (*v)[n0-1][n1-1][l] = (*b221)[0][0][l];
  assert(dfb222.getSize() ==  1* 1* 1*sizeof(itemtype)); const itemtype (*b222)[ 1][ 1][ 1] = (const itemtype(*)[ 1][ 1][ 1])dfb222.getData<itemtype>(); (*v)[n0-1][n1-1][n2-1] = (*b222)[0][0][0];
}

void c_mesh3d_exchange_27_get_11_11_10(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb000,OutputDF &dfb001,OutputDF &dfb010,OutputDF &dfb011,OutputDF &dfb020,OutputDF &dfb021,OutputDF &dfb100,OutputDF &dfb101,OutputDF &dfb110,OutputDF &dfb120,OutputDF &dfb121,OutputDF &dfb200,OutputDF &dfb201,OutputDF &dfb210,OutputDF &dfb211,OutputDF &dfb220,OutputDF &dfb221)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b000)[ 1][ 1][ 1] = (itemtype(*)[ 1][ 1][ 1])dfb000.create<itemtype>( 1* 1* 1); (*b000)[0][0][0] = (*u)[1][1][1];
  itemtype (*b001)[ 1][ 1][n2] = (itemtype(*)[ 1][ 1][n2])dfb001.create<itemtype>( 1* 1*n2); for (l=0;l<n2;l++) (*b001)[0][0][l] = (*u)[1][1][l];
  itemtype (*b010)[ 1][n1][ 1] = (itemtype(*)[ 1][n1][ 1])dfb010.create<itemtype>( 1*n1* 1); for (k=0;k<n1;k++) (*b010)[0][k][0] = (*u)[1][k][1];
  itemtype (*b011)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb011.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b011)[0][k][l] = (*u)[1][k][l];
  itemtype (*b020)[ 1][ 1][ 1] = (itemtype(*)[ 1][ 1][ 1])dfb020.create<itemtype>( 1* 1* 1); (*b020)[0][0][0] = (*u)[1][n1-2][1];
  itemtype (*b021)[ 1][ 1][n2] = (itemtype(*)[ 1][ 1][n2])dfb021.create<itemtype>( 1* 1*n2); for (l=0;l<n2;l++) (*b021)[0][0][l] = (*u)[1][n1-2][l];
  itemtype (*b100)[n0][ 1][ 1] = (itemtype(*)[n0][ 1][ 1])dfb100.create<itemtype>(n0* 1* 1); for (i=0;i<n0;i++) (*b100)[i][0][0] = (*u)[i][1][1];
  itemtype (*b101)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb101.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b101)[i][0][l] = (*u)[i][1][l];
  itemtype (*b110)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb110.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b110)[i][k][0] = (*u)[i][k][1];
  itemtype (*b120)[n0][ 1][ 1] = (itemtype(*)[n0][ 1][ 1])dfb120.create<itemtype>(n0* 1* 1); for (i=0;i<n0;i++) (*b120)[i][0][0] = (*u)[i][n1-2][1];
  itemtype (*b121)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb121.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b121)[i][0][l] = (*u)[i][n1-2][l];
  itemtype (*b200)[ 1][ 1][ 1] = (itemtype(*)[ 1][ 1][ 1])dfb200.create<itemtype>( 1* 1* 1); (*b200)[0][0][0] = (*u)[n0-2][1][1];
  itemtype (*b201)[ 1][ 1][n2] = (itemtype(*)[ 1][ 1][n2])dfb201.create<itemtype>( 1* 1*n2); for (l=0;l<n2;l++) (*b201)[0][0][l] = (*u)[n0-2][1][l];
  itemtype (*b210)[ 1][n1][ 1] = (itemtype(*)[ 1][n1][ 1])dfb210.create<itemtype>( 1*n1* 1); for (k=0;k<n1;k++) (*b210)[0][k][0] = (*u)[n0-2][k][1];
  itemtype (*b211)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb211.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b211)[0][k][l] = (*u)[n0-2][k][l];
  itemtype (*b220)[ 1][ 1][ 1] = (itemtype(*)[ 1][ 1][ 1])dfb220.create<itemtype>( 1* 1* 1); (*b220)[0][0][0] = (*u)[n0-2][n1-2][1];
  itemtype (*b221)[ 1][ 1][n2] = (itemtype(*)[ 1][ 1][n2])dfb221.create<itemtype>( 1* 1*n2); for (l=0;l<n2;l++) (*b221)[0][0][l] = (*u)[n0-2][n1-2][l];
}

void c_mesh3d_exchange_27_set_11_11_10(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb000,const InputDF &dfb001,const InputDF &dfb010,const InputDF &dfb011,const InputDF &dfb020,const InputDF &dfb021,const InputDF &dfb100,const InputDF &dfb101,const InputDF &dfb110,const InputDF &dfb120,const InputDF &dfb121,const InputDF &dfb200,const InputDF &dfb201,const InputDF &dfb210,const InputDF &dfb211,const InputDF &dfb220,const InputDF &dfb221,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb000.getSize() ==  1* 1* 1*sizeof(itemtype)); const itemtype (*b000)[ 1][ 1][ 1] = (const itemtype(*)[ 1][ 1][ 1])dfb000.getData<itemtype>(); (*v)[0][0][0] = (*b000)[0][0][0];
  assert(dfb001.getSize() ==  1* 1*n2*sizeof(itemtype)); const itemtype (*b001)[ 1][ 1][n2] = (const itemtype(*)[ 1][ 1][n2])dfb001.getData<itemtype>(); for (l=1;l<n2-1;l++) (*v)[0][0][l] = (*b001)[0][0][l];
  assert(dfb010.getSize() ==  1*n1* 1*sizeof(itemtype)); const itemtype (*b010)[ 1][n1][ 1] = (const itemtype(*)[ 1][n1][ 1])dfb010.getData<itemtype>(); for (k=1;k<n1-1;k++) (*v)[0][k][0] = (*b010)[0][k][0];
  assert(dfb011.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b011)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb011.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[0][k][l] = (*b011)[0][k][l];
  assert(dfb020.getSize() ==  1* 1* 1*sizeof(itemtype)); const itemtype (*b020)[ 1][ 1][ 1] = (const itemtype(*)[ 1][ 1][ 1])dfb020.getData<itemtype>(); (*v)[0][n1-1][0] = (*b020)[0][0][0];
  assert(dfb021.getSize() ==  1* 1*n2*sizeof(itemtype)); const itemtype (*b021)[ 1][ 1][n2] = (const itemtype(*)[ 1][ 1][n2])dfb021.getData<itemtype>(); for (l=1;l<n2-1;l++) (*v)[0][n1-1][l] = (*b021)[0][0][l];
  assert(dfb100.getSize() == n0* 1* 1*sizeof(itemtype)); const itemtype (*b100)[n0][ 1][ 1] = (const itemtype(*)[n0][ 1][ 1])dfb100.getData<itemtype>(); for (i=1;i<n0-1;i++) (*v)[i][0][0] = (*b100)[i][0][0];
  assert(dfb101.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b101)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb101.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][0][l] = (*b101)[i][0][l];
  assert(dfb110.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b110)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb110.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][0] = (*b110)[i][k][0];
  assert(dfb120.getSize() == n0* 1* 1*sizeof(itemtype)); const itemtype (*b120)[n0][ 1][ 1] = (const itemtype(*)[n0][ 1][ 1])dfb120.getData<itemtype>(); for (i=1;i<n0-1;i++) (*v)[i][n1-1][0] = (*b120)[i][0][0];
  assert(dfb121.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b121)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb121.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][n1-1][l] = (*b121)[i][0][l];
  assert(dfb200.getSize() ==  1* 1* 1*sizeof(itemtype)); const itemtype (*b200)[ 1][ 1][ 1] = (const itemtype(*)[ 1][ 1][ 1])dfb200.getData<itemtype>(); (*v)[n0-1][0][0] = (*b200)[0][0][0];
  assert(dfb201.getSize() ==  1* 1*n2*sizeof(itemtype)); const itemtype (*b201)[ 1][ 1][n2] = (const itemtype(*)[ 1][ 1][n2])dfb201.getData<itemtype>(); for (l=1;l<n2-1;l++) (*v)[n0-1][0][l] = (*b201)[0][0][l];
  assert(dfb210.getSize() ==  1*n1* 1*sizeof(itemtype)); const itemtype (*b210)[ 1][n1][ 1] = (const itemtype(*)[ 1][n1][ 1])dfb210.getData<itemtype>(); for (k=1;k<n1-1;k++) (*v)[n0-1][k][0] = (*b210)[0][k][0];
  assert(dfb211.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b211)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb211.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[n0-1][k][l] = (*b211)[0][k][l];
  assert(dfb220.getSize() ==  1* 1* 1*sizeof(itemtype)); const itemtype (*b220)[ 1][ 1][ 1] = (const itemtype(*)[ 1][ 1][ 1])dfb220.getData<itemtype>(); (*v)[n0-1][n1-1][0] = (*b220)[0][0][0];
  assert(dfb221.getSize() ==  1* 1*n2*sizeof(itemtype)); const itemtype (*b221)[ 1][ 1][n2] = (const itemtype(*)[ 1][ 1][n2])dfb221.getData<itemtype>(); for (l=1;l<n2-1;l++) (*v)[n0-1][n1-1][l] = (*b221)[0][0][l];
}

void c_mesh3d_exchange_27_get_11_11_11(int n0,int n1,int n2,const InputDF &dfu,
  OutputDF &dfb000,OutputDF &dfb001,OutputDF &dfb002,OutputDF &dfb010,OutputDF &dfb011,OutputDF &dfb012,OutputDF &dfb020,OutputDF &dfb021,OutputDF &dfb022,OutputDF &dfb100,OutputDF &dfb101,OutputDF &dfb102,OutputDF &dfb110,OutputDF &dfb112,OutputDF &dfb120,OutputDF &dfb121,OutputDF &dfb122,OutputDF &dfb200,OutputDF &dfb201,OutputDF &dfb202,OutputDF &dfb210,OutputDF &dfb211,OutputDF &dfb212,OutputDF &dfb220,OutputDF &dfb221,OutputDF &dfb222)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype));
  const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();

  itemtype (*b000)[ 1][ 1][ 1] = (itemtype(*)[ 1][ 1][ 1])dfb000.create<itemtype>( 1* 1* 1); (*b000)[0][0][0] = (*u)[1][1][1];
  itemtype (*b001)[ 1][ 1][n2] = (itemtype(*)[ 1][ 1][n2])dfb001.create<itemtype>( 1* 1*n2); for (l=0;l<n2;l++) (*b001)[0][0][l] = (*u)[1][1][l];
  itemtype (*b002)[ 1][ 1][ 1] = (itemtype(*)[ 1][ 1][ 1])dfb002.create<itemtype>( 1* 1* 1); (*b002)[0][0][0] = (*u)[1][1][n2-2];
  itemtype (*b010)[ 1][n1][ 1] = (itemtype(*)[ 1][n1][ 1])dfb010.create<itemtype>( 1*n1* 1); for (k=0;k<n1;k++) (*b010)[0][k][0] = (*u)[1][k][1];
  itemtype (*b011)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb011.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b011)[0][k][l] = (*u)[1][k][l];
  itemtype (*b012)[ 1][n1][ 1] = (itemtype(*)[ 1][n1][ 1])dfb012.create<itemtype>( 1*n1* 1); for (k=0;k<n1;k++) (*b012)[0][k][0] = (*u)[1][k][n2-2];
  itemtype (*b020)[ 1][ 1][ 1] = (itemtype(*)[ 1][ 1][ 1])dfb020.create<itemtype>( 1* 1* 1); (*b020)[0][0][0] = (*u)[1][n1-2][1];
  itemtype (*b021)[ 1][ 1][n2] = (itemtype(*)[ 1][ 1][n2])dfb021.create<itemtype>( 1* 1*n2); for (l=0;l<n2;l++) (*b021)[0][0][l] = (*u)[1][n1-2][l];
  itemtype (*b022)[ 1][ 1][ 1] = (itemtype(*)[ 1][ 1][ 1])dfb022.create<itemtype>( 1* 1* 1); (*b022)[0][0][0] = (*u)[1][n1-2][n2-2];
  itemtype (*b100)[n0][ 1][ 1] = (itemtype(*)[n0][ 1][ 1])dfb100.create<itemtype>(n0* 1* 1); for (i=0;i<n0;i++) (*b100)[i][0][0] = (*u)[i][1][1];
  itemtype (*b101)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb101.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b101)[i][0][l] = (*u)[i][1][l];
  itemtype (*b102)[n0][ 1][ 1] = (itemtype(*)[n0][ 1][ 1])dfb102.create<itemtype>(n0* 1* 1); for (i=0;i<n0;i++) (*b102)[i][0][0] = (*u)[i][1][n2-2];
  itemtype (*b110)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb110.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b110)[i][k][0] = (*u)[i][k][1];
  itemtype (*b112)[n0][n1][ 1] = (itemtype(*)[n0][n1][ 1])dfb112.create<itemtype>(n0*n1* 1); for (i=0;i<n0;i++) for (k=0;k<n1;k++) (*b112)[i][k][0] = (*u)[i][k][n2-2];
  itemtype (*b120)[n0][ 1][ 1] = (itemtype(*)[n0][ 1][ 1])dfb120.create<itemtype>(n0* 1* 1); for (i=0;i<n0;i++) (*b120)[i][0][0] = (*u)[i][n1-2][1];
  itemtype (*b121)[n0][ 1][n2] = (itemtype(*)[n0][ 1][n2])dfb121.create<itemtype>(n0* 1*n2); for (i=0;i<n0;i++) for (l=0;l<n2;l++) (*b121)[i][0][l] = (*u)[i][n1-2][l];
  itemtype (*b122)[n0][ 1][ 1] = (itemtype(*)[n0][ 1][ 1])dfb122.create<itemtype>(n0* 1* 1); for (i=0;i<n0;i++) (*b122)[i][0][0] = (*u)[i][n1-2][n2-2];
  itemtype (*b200)[ 1][ 1][ 1] = (itemtype(*)[ 1][ 1][ 1])dfb200.create<itemtype>( 1* 1* 1); (*b200)[0][0][0] = (*u)[n0-2][1][1];
  itemtype (*b201)[ 1][ 1][n2] = (itemtype(*)[ 1][ 1][n2])dfb201.create<itemtype>( 1* 1*n2); for (l=0;l<n2;l++) (*b201)[0][0][l] = (*u)[n0-2][1][l];
  itemtype (*b202)[ 1][ 1][ 1] = (itemtype(*)[ 1][ 1][ 1])dfb202.create<itemtype>( 1* 1* 1); (*b202)[0][0][0] = (*u)[n0-2][1][n2-2];
  itemtype (*b210)[ 1][n1][ 1] = (itemtype(*)[ 1][n1][ 1])dfb210.create<itemtype>( 1*n1* 1); for (k=0;k<n1;k++) (*b210)[0][k][0] = (*u)[n0-2][k][1];
  itemtype (*b211)[ 1][n1][n2] = (itemtype(*)[ 1][n1][n2])dfb211.create<itemtype>( 1*n1*n2); for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*b211)[0][k][l] = (*u)[n0-2][k][l];
  itemtype (*b212)[ 1][n1][ 1] = (itemtype(*)[ 1][n1][ 1])dfb212.create<itemtype>( 1*n1* 1); for (k=0;k<n1;k++) (*b212)[0][k][0] = (*u)[n0-2][k][n2-2];
  itemtype (*b220)[ 1][ 1][ 1] = (itemtype(*)[ 1][ 1][ 1])dfb220.create<itemtype>( 1* 1* 1); (*b220)[0][0][0] = (*u)[n0-2][n1-2][1];
  itemtype (*b221)[ 1][ 1][n2] = (itemtype(*)[ 1][ 1][n2])dfb221.create<itemtype>( 1* 1*n2); for (l=0;l<n2;l++) (*b221)[0][0][l] = (*u)[n0-2][n1-2][l];
  itemtype (*b222)[ 1][ 1][ 1] = (itemtype(*)[ 1][ 1][ 1])dfb222.create<itemtype>( 1* 1* 1); (*b222)[0][0][0] = (*u)[n0-2][n1-2][n2-2];
}

void c_mesh3d_exchange_27_set_11_11_11(int n0,int n1,int n2,const InputDF &dfu,
  const InputDF &dfb000,const InputDF &dfb001,const InputDF &dfb002,const InputDF &dfb010,const InputDF &dfb011,const InputDF &dfb012,const InputDF &dfb020,const InputDF &dfb021,const InputDF &dfb022,const InputDF &dfb100,const InputDF &dfb101,const InputDF &dfb102,const InputDF &dfb110,const InputDF &dfb112,const InputDF &dfb120,const InputDF &dfb121,const InputDF &dfb122,const InputDF &dfb200,const InputDF &dfb201,const InputDF &dfb202,const InputDF &dfb210,const InputDF &dfb211,const InputDF &dfb212,const InputDF &dfb220,const InputDF &dfb221,const InputDF &dfb222,
  OutputDF &dfv)
{ int i,k,l;
  assert(dfu.getSize() == n0*n1*n2*sizeof(itemtype)); const itemtype (*u)[n0][n1][n2] = (const itemtype (*)[n0][n1][n2])dfu.getData<itemtype>();
  itemtype (*v)[n0][n1][n2] = (itemtype(*)[n0][n1][n2])dfv.create<itemtype>(n0*n1*n2); for (i=0;i<n0;i++) for (k=0;k<n1;k++) for (l=0;l<n2;l++) (*v)[i][k][l] = (*u)[i][k][l];

  assert(dfb000.getSize() ==  1* 1* 1*sizeof(itemtype)); const itemtype (*b000)[ 1][ 1][ 1] = (const itemtype(*)[ 1][ 1][ 1])dfb000.getData<itemtype>(); (*v)[0][0][0] = (*b000)[0][0][0];
  assert(dfb001.getSize() ==  1* 1*n2*sizeof(itemtype)); const itemtype (*b001)[ 1][ 1][n2] = (const itemtype(*)[ 1][ 1][n2])dfb001.getData<itemtype>(); for (l=1;l<n2-1;l++) (*v)[0][0][l] = (*b001)[0][0][l];
  assert(dfb002.getSize() ==  1* 1* 1*sizeof(itemtype)); const itemtype (*b002)[ 1][ 1][ 1] = (const itemtype(*)[ 1][ 1][ 1])dfb002.getData<itemtype>(); (*v)[0][0][n2-1] = (*b002)[0][0][0];
  assert(dfb010.getSize() ==  1*n1* 1*sizeof(itemtype)); const itemtype (*b010)[ 1][n1][ 1] = (const itemtype(*)[ 1][n1][ 1])dfb010.getData<itemtype>(); for (k=1;k<n1-1;k++) (*v)[0][k][0] = (*b010)[0][k][0];
  assert(dfb011.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b011)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb011.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[0][k][l] = (*b011)[0][k][l];
  assert(dfb012.getSize() ==  1*n1* 1*sizeof(itemtype)); const itemtype (*b012)[ 1][n1][ 1] = (const itemtype(*)[ 1][n1][ 1])dfb012.getData<itemtype>(); for (k=1;k<n1-1;k++) (*v)[0][k][n2-1] = (*b012)[0][k][0];
  assert(dfb020.getSize() ==  1* 1* 1*sizeof(itemtype)); const itemtype (*b020)[ 1][ 1][ 1] = (const itemtype(*)[ 1][ 1][ 1])dfb020.getData<itemtype>(); (*v)[0][n1-1][0] = (*b020)[0][0][0];
  assert(dfb021.getSize() ==  1* 1*n2*sizeof(itemtype)); const itemtype (*b021)[ 1][ 1][n2] = (const itemtype(*)[ 1][ 1][n2])dfb021.getData<itemtype>(); for (l=1;l<n2-1;l++) (*v)[0][n1-1][l] = (*b021)[0][0][l];
  assert(dfb022.getSize() ==  1* 1* 1*sizeof(itemtype)); const itemtype (*b022)[ 1][ 1][ 1] = (const itemtype(*)[ 1][ 1][ 1])dfb022.getData<itemtype>(); (*v)[0][n1-1][n2-1] = (*b022)[0][0][0];
  assert(dfb100.getSize() == n0* 1* 1*sizeof(itemtype)); const itemtype (*b100)[n0][ 1][ 1] = (const itemtype(*)[n0][ 1][ 1])dfb100.getData<itemtype>(); for (i=1;i<n0-1;i++) (*v)[i][0][0] = (*b100)[i][0][0];
  assert(dfb101.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b101)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb101.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][0][l] = (*b101)[i][0][l];
  assert(dfb102.getSize() == n0* 1* 1*sizeof(itemtype)); const itemtype (*b102)[n0][ 1][ 1] = (const itemtype(*)[n0][ 1][ 1])dfb102.getData<itemtype>(); for (i=1;i<n0-1;i++) (*v)[i][0][n2-1] = (*b102)[i][0][0];
  assert(dfb110.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b110)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb110.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][0] = (*b110)[i][k][0];
  assert(dfb112.getSize() == n0*n1* 1*sizeof(itemtype)); const itemtype (*b112)[n0][n1][ 1] = (const itemtype(*)[n0][n1][ 1])dfb112.getData<itemtype>(); for (i=1;i<n0-1;i++) for (k=1;k<n1-1;k++) (*v)[i][k][n2-1] = (*b112)[i][k][0];
  assert(dfb120.getSize() == n0* 1* 1*sizeof(itemtype)); const itemtype (*b120)[n0][ 1][ 1] = (const itemtype(*)[n0][ 1][ 1])dfb120.getData<itemtype>(); for (i=1;i<n0-1;i++) (*v)[i][n1-1][0] = (*b120)[i][0][0];
  assert(dfb121.getSize() == n0* 1*n2*sizeof(itemtype)); const itemtype (*b121)[n0][ 1][n2] = (const itemtype(*)[n0][ 1][n2])dfb121.getData<itemtype>(); for (i=1;i<n0-1;i++) for (l=1;l<n2-1;l++) (*v)[i][n1-1][l] = (*b121)[i][0][l];
  assert(dfb122.getSize() == n0* 1* 1*sizeof(itemtype)); const itemtype (*b122)[n0][ 1][ 1] = (const itemtype(*)[n0][ 1][ 1])dfb122.getData<itemtype>(); for (i=1;i<n0-1;i++) (*v)[i][n1-1][n2-1] = (*b122)[i][0][0];
  assert(dfb200.getSize() ==  1* 1* 1*sizeof(itemtype)); const itemtype (*b200)[ 1][ 1][ 1] = (const itemtype(*)[ 1][ 1][ 1])dfb200.getData<itemtype>(); (*v)[n0-1][0][0] = (*b200)[0][0][0];
  assert(dfb201.getSize() ==  1* 1*n2*sizeof(itemtype)); const itemtype (*b201)[ 1][ 1][n2] = (const itemtype(*)[ 1][ 1][n2])dfb201.getData<itemtype>(); for (l=1;l<n2-1;l++) (*v)[n0-1][0][l] = (*b201)[0][0][l];
  assert(dfb202.getSize() ==  1* 1* 1*sizeof(itemtype)); const itemtype (*b202)[ 1][ 1][ 1] = (const itemtype(*)[ 1][ 1][ 1])dfb202.getData<itemtype>(); (*v)[n0-1][0][n2-1] = (*b202)[0][0][0];
  assert(dfb210.getSize() ==  1*n1* 1*sizeof(itemtype)); const itemtype (*b210)[ 1][n1][ 1] = (const itemtype(*)[ 1][n1][ 1])dfb210.getData<itemtype>(); for (k=1;k<n1-1;k++) (*v)[n0-1][k][0] = (*b210)[0][k][0];
  assert(dfb211.getSize() ==  1*n1*n2*sizeof(itemtype)); const itemtype (*b211)[ 1][n1][n2] = (const itemtype(*)[ 1][n1][n2])dfb211.getData<itemtype>(); for (k=1;k<n1-1;k++) for (l=1;l<n2-1;l++) (*v)[n0-1][k][l] = (*b211)[0][k][l];
  assert(dfb212.getSize() ==  1*n1* 1*sizeof(itemtype)); const itemtype (*b212)[ 1][n1][ 1] = (const itemtype(*)[ 1][n1][ 1])dfb212.getData<itemtype>(); for (k=1;k<n1-1;k++) (*v)[n0-1][k][n2-1] = (*b212)[0][k][0];
  assert(dfb220.getSize() ==  1* 1* 1*sizeof(itemtype)); const itemtype (*b220)[ 1][ 1][ 1] = (const itemtype(*)[ 1][ 1][ 1])dfb220.getData<itemtype>(); (*v)[n0-1][n1-1][0] = (*b220)[0][0][0];
  assert(dfb221.getSize() ==  1* 1*n2*sizeof(itemtype)); const itemtype (*b221)[ 1][ 1][n2] = (const itemtype(*)[ 1][ 1][n2])dfb221.getData<itemtype>(); for (l=1;l<n2-1;l++) (*v)[n0-1][n1-1][l] = (*b221)[0][0][l];
  assert(dfb222.getSize() ==  1* 1* 1*sizeof(itemtype)); const itemtype (*b222)[ 1][ 1][ 1] = (const itemtype(*)[ 1][ 1][ 1])dfb222.getData<itemtype>(); (*v)[n0-1][n1-1][n2-1] = (*b222)[0][0][0];
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