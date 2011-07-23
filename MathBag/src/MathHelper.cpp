//
//  MathHelper.cpp
//  MathBag
//
//  Created by bronson on 11-06-30.
//
    
#include "MathHelper.h"

namespace MathBag 
{    
    const float MathHelper::E = 2.71828183;
    const float MathHelper::Log10E = 0.434294482;
    //const float MathHelper::Log2E;
    const float MathHelper::Pi = 3.14159265;
    const float MathHelper::PiOver2 = 1.57079633;
    const float MathHelper::PiOver4 = 0.785398163;
    const float MathHelper::TwoPi = 6.28318531;
    
    float MathHelper::clamp(float value, float min, float max)
    {
        if (value > max) return max;
        if (value < min) return min;
        
        return value;
    }
    
    float MathHelper::distance(float value1, float value2)
    {
        float output = value1 - value2;
        
        if (output < 0) return -output;
        
        return output;
    }
    
    float MathHelper::lerp(float value1, float value2, float amount)
    {
        return value1 + (value2 - value1) * amount;
    }
    
    float MathHelper::max(float value1, float value2)
    {
        if (value1 > value2) return value1;
        return value2;
    }
    
    float MathHelper::min(float value1, float value2)
    {
        if (value1 < value2) return value1;
        return value2;
    }
    
    float MathHelper::toDegrees(float radians)
    {
        return radians * 57.2957795;
    }
    
    float MathHelper::toRadians(float degrees)
    {
        return degrees * 0.0174532925;
    }
}