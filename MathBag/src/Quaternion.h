//
//  Quaternion.h
//  MathBag
//
//  Created by bronson on 11-06-28.
//
#pragma once

#include "Vector.h"
namespace MathBag
{
    class Vector3;
    class Matrix4;
    
    class Quaternion
    {
    public:
        // Members
        float w;
        float x;
        float y;
        float z;
        
        
        // Constructor, Destructor
        Quaternion();
        explicit Quaternion(float x, float y, float z, float w);
        explicit Quaternion(Vector3 vectorPart, float scalarPart);
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
        static Quaternion createFromYawPitchRoll(float yaw, float pitch, float roll);
        static Quaternion createFromAxisAngle(Vector3 axis, float radians);
        static Quaternion createFromRotationX(float radians);
        static Quaternion createFromRotationY(float radians);
        static Quaternion createFromRotationZ(float radians);
        //    static Quaternion createFromRotationMatrix(Matrix4 rotationMatrix);
        
        
        // Static Properties
        static const Quaternion Identity;
    };
    
}