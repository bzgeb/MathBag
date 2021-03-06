//
//  Matrix.h
//  MathBag
//
//  Created by bronson on 11-06-27.
//
#pragma once

#include <iostream>

#include "Precision.h"
#include "Vector.h"
#include "Quaternion.h"

namespace MathBag
{
    class Vector3;
    class Quaternion;
    
    const int M00 = 0;
    const int M01 = 4;
    const int M02 = 8;
    const int M03 = 12;
    const int M10 = 1;
    const int M11 = 5;
    const int M12 = 9;
    const int M13 = 13;
    const int M20 = 2;
    const int M21 = 6;
    const int M22 = 10;
    const int M23 = 14;
    const int M30 = 3;
    const int M31 = 7;
    const int M32 = 11;
    const int M33 = 15;
    
    class Matrix4
    {
    public:
        // Members
        real m[16];
        
        
        // Constructor, Destructor
        Matrix4();
        Matrix4(real m00, real m01, real m02, real m03,
                real m10, real m11, real m12, real m13,
                real m20, real m21, real m22, real m23,
                real m30, real m31, real m32, real m33);
        Matrix4(real matrix[16]);
        Matrix4(const Matrix4 &other);
        Matrix4(const Quaternion &quaternion);
        ~Matrix4();
        
        
        // Operators
        Matrix4 operator+= (const Matrix4 &other);
        friend Matrix4 operator+ (const Matrix4 &m1, const Matrix4 &m2);
        Matrix4 operator-= (const Matrix4 & other);
        friend Matrix4 operator- (const Matrix4 &m1, const Matrix4 &m2);
        real & operator() (int i);
        const real & operator() (int i) const;
        real & operator[] (int i);
        const real & operator[] (int i) const;
        Matrix4 operator*= (const Matrix4 &other);
        friend Matrix4 operator* (const Matrix4 &m1, const Matrix4 &m2);
        bool operator== (const Matrix4 &other) const;
        bool operator!= (const Matrix4 &other) const;
        friend std::ostream & operator<<(std::ostream &os, const Matrix4 &matrix);
        
        
        // Public Methods
        Vector3 getUp() const;
        void setUp(const Vector3 &upVector);
        Vector3 getRight() const;
        void setRight(const Vector3 &rightVector);
        Vector3 getForward() const;
        void setForward(const Vector3 &forwardVector);
        
        
        // Static Methods
        static Matrix4 createFromAxisAngle(const Vector3 &axis, real angle);
        static Matrix4 createFromYawPitchRoll(real yaw, real pitch, real roll);
        static Matrix4 createRotationX(real radians);
        static Matrix4 createRotationY(real radians);
        static Matrix4 createRotationZ(real radians);
        static Matrix4 createLookAt(const Vector3 &cameraPosition, const Vector3 &cameraTarget, const Vector3 &cameraUpVector);
        static Matrix4 createTranslation(real x, real y, real z);
        static Matrix4 createTranslation(const Vector3 &position);
        static Matrix4 createFromQuaternion(const Quaternion &quaternion);
        static Matrix4 transpose(const Matrix4 &matrix);
        
        
        // Static Properties
        static const Matrix4 Identity;
    };
}