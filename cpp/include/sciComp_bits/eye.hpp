#ifndef EYE_H
#define EYE_H

class eye{
    
public:
    template<typename Vec> const Vec& solve(const Vec& x) const {return x;}
    template<typename Vec> const Vec& operator* (const Vec& x) const {
        return x;
    }
};

#endif
