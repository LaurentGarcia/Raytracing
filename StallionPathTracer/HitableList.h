#ifndef HITABLELISTH
#define HITABLELISTH

#include "Hitable.h"

class HitableList : public Hitable 
{
    public:
        HitableList(){};
        HitableList(Hitable **list, int n);        
        ~HitableList();
        
        virtual bool hit(Ray& r, float t_min, float t_max, hit_record& rec) const;


    private:
        int list_size;
        Hitable **list;

};
#endif     