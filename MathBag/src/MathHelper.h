//
//  MathHelper.h
//  MathBag
//
//  Created by bronson on 11-06-30.
//
#pragma once

namespace MathBag 
{
    class MathHelper
    {
    public:
        static const float E;
        static const float Log10E;
        //    static const float Log2E;
        static const float Pi;
        static const float PiOver2;
        static const float PiOver4;
        static const float TwoPi;
        
        static float clamp(float value, float min, float max);
        static float distance(float value1, float value2);
        static float lerp(float value1, float value2, float amount);
        static float max(float value1, float value2);
        static float min(float value1, float value2);
        static float toDegrees(float radians);
        static float toRadians(float degrees);
    };
}