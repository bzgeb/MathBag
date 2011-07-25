//
//  MathHelper.cpp
//  MathBag
//
//  Created by bronson on 11-06-30.
//
    
#include "MathHelper.h"

namespace MathBag 
{    
    const real MathHelper::E = 2.71828183;
    const real MathHelper::Log10E = 0.434294482;
    //const real MathHelper::Log2E;
    const real MathHelper::Pi = 3.14159265;
    const real MathHelper::PiOver2 = 1.57079633;
    const real MathHelper::PiOver4 = 0.785398163;
    const real MathHelper::TwoPi = 6.28318531;
    
    real MathHelper::clamp(real value, real min, real max)
    {
        if (value > max) return max;
        if (value < min) return min;
        
        return value;
    }
    
    real MathHelper::distance(real value1, real value2)
    {
        real output = value1 - value2;
        
        if (output < 0) return -output;
        
        return output;
    }
    
    real MathHelper::lerp(real value1, real value2, real amount)
    {
        return value1 + (value2 - value1) * amount;
    }
    
    real MathHelper::max(real value1, real value2)
    {
        if (value1 > value2) return value1;
        return value2;
    }
    
    real MathHelper::min(real value1, real value2)
    {
        if (value1 < value2) return value1;
        return value2;
    }
    
    real MathHelper::toDegrees(real radians)
    {
        return radians * 57.2957795;
    }
    
    real MathHelper::toRadians(real degrees)
    {
        return degrees * 0.0174532925;
    }
}