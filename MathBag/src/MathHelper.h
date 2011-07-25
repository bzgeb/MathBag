//
//  MathHelper.h
//  MathBag
//
//  Created by bronson on 11-06-30.
//
#pragma once

#include "Precision.h"

namespace MathBag 
{
    class MathHelper
    {
    public:
        static const real E;
        static const real Log10E;
        //    static const real Log2E;
        static const real Pi;
        static const real PiOver2;
        static const real PiOver4;
        static const real TwoPi;
        
        static real clamp(real value, real min, real max);
        static real distance(real value1, real value2);
        static real lerp(real value1, real value2, real amount);
        static real max(real value1, real value2);
        static real min(real value1, real value2);
        static real toDegrees(real radians);
        static real toRadians(real degrees);
    };
}