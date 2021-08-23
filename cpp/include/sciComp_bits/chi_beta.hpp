#ifndef CHI_BETA_H
#define CHI_BETA_H

double chi(double b, double t){
    
    return (b*t - 1 - pow(t,b) + pow(1-t, b))/(b-2);
}

#endif
