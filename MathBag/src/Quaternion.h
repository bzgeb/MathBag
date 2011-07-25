//
//  Quaternion.h
//  MathBag
//
//  Created by bronson on 11-06-28.
//
#pragma once

#include "Precision.h"
#include "Vector.h"

namespace MathBag
{
    class Vector3;
    class Matrix4;
    
    class Quaternion
    {
    public:
        // Members
        real w;
        real x;
        real y;
        real z;
        
        
        // Constructor, Destructor
        Quaternion();
        explicit Quaternion(real x, real y, real z, real w);
        explicit Quaternion(Vector3 vectorPart, real scalarPart);
        ~Quaternion();
        
        
        // Operators
        Quaternion operator+= (const Quaternion &other);
        friend Quaternion operator+ (const Quaternion &q1, const Quaternion &q2); 
        Quaternion operator*= (const Quaternion &other);
        friend Quaternion operator* (const Quaternion &q1, const Quaternion &q2);
        bool operator== (const Quaternion &other);
        bool operator!= (const Quaternion &other);
        Quaternion operator-= (const Quaternion &other);
        friend Quaternion operator- (const Quaternion &q1, const Quaternion &q2);
        
        
        // Static Methods
        static Quaternion createFromYawPitchRoll(real yaw, real pitch, real roll);
        static Quaternion createFromAxisAngle(Vector3 axis, real radians);
        static Quaternion createFromRotationX(real radians);
        static Quaternion createFromRotationY(real radians);
        static Quaternion createFromRotationZ(real radians);
        //    static Quaternion createFromRotationMatrix(Matrix4 rotationMatrix);
        static Quaternion normalize(const Quaternion &q1);
        
        
        // Static Properties
        static const Quaternion Identity;
    };
    
}