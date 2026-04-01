#include "pic3d_utils.h"

Particle::Particle(real x, real y, real z)
{
    this->x=x;
    this->y=y;
    this->z=z;
    this->u=0.0;
    this->v=0.0;
    this->w=0.0;       
} 

Particle::Particle(real x, real y, real z,real u,real v,real w)
{
    this->x=x;
    this->y=y;
    this->z=z;
    this->u=u;
    this->v=v;
    this->w=w;
}

constexpr double g05dde::d[41]={ 
    0.0, 0.674489750196082, 
    1.150349380376008, 1.534120544352546, 1.862731867421652,
    2.153874694061456, 2.417559016236505, 2.660067468617460, 
    2.885634912426757, 3.097269078198785, 3.297193345691964, 
    3.487104104114431, 3.668329285121323, 3.841930685501911,
    4.008772594168585, 4.169569323349106, 4.324919040826046,
    4.475328424654204, 4.621231001499247, 4.763001034267814,
    4.900964207963193, 5.035405969463927, 5.166578119728753,
    5.294704084854598, 5.419983174916868, 5.542594057802940,
    5.662697617459439, 5.780439324478935, 5.895951216739571,
    6.009353565530745, 6.120756285971941, 6.230260137989044,
    6.337957754553790, 6.443934526538564, 6.548269367831731,
    6.651035379893011, 6.752300431407015, 6.852127665896068,
    6.950575947916750, 7.047700256664409, 7.143552034352190 
};

g05dde::g05dde()
{ 
    reset(); 
}

void g05dde::reset(int seed)
{ 
    store1=1.0; 

    for (int i=0; i<seed; i++) {
        get(0.0, 1.0);
    }
}

double g05dde::get(double a, double b)
{
    double t, u, v, w;
    int n;

    u=store1;
    for (n=0; n<39 && u<half; n++, u+=u);

    t=d[n];
    u=cae.get();

    while(1) { 
        w=(d[n+1]-t)*u;
        v=w*(w*half+t);

        do { 
                u = cae.get();
                if (v<=u) { 
                    u=(u-v)/(one-v);

                if (u<=half) { 
                    store1=u+u;
                    return a+b*(w+t);
                }

                store1=u+u-one;
                return a-b*(w+t);
                }

                v=cae.get();
        } while (u>v);
        u=(v-u)/(one-u);
    }
}

g05cae::g05cae() 
{ 
    reset(); 
}

g05cae::g05cae(int seed)
{ 
    reset(seed); 
}

void g05cae::reset(int seed)
{
    ix=1, iy=255, iz=25555;
    
    for (int i=0; i<seed; i++) {
        get();
    }
}
 		
double g05cae::get()
{
    double ax, ay, az, ai;
    int ii;

    ix = 171*(ix-(ix/177)*177)-2*(ix/177);
    iy = 172*(iy-(iy/176)*176)-2*(iy/176);
    iz = 170*(iz-(iz/178)*178)-2*(iz/178);

    if (ix<0) {
        ix+=30269;
    }

    if (iy<0) {
        iy+=30307;
    }

    if (iz<0) {
        iz+=30323;
    }
    
    ax=ix;
    ay=iy;
    az=iz;
    ai=ax/30269.0+ay/30307.0+az/30323.0;
    ii=ai;

    return ai-ii;
}