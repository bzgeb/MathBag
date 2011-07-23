//
//  Matrix.h
//  MathBag
//
//  Created by bronson on 11-06-27.
//
#pragma once

#include <iostream>

#include "Vector.h"
#include "Quaternion.h"

namespace MathBag
{
    class Vector3;
    class Quaternion;
    
    class Matrix4
    {
    public:
        // Members
        float m[4][4];
        
        
        // Constructor, Destructor
        Matrix4();
        Matrix4(float m00, float m01, float m02, float m03,
                float m10, float m11, float m12, float m13,
                float m20, float m21, float m22, float m23,
                float m30, float m31, float m32, float m33);
        Matrix4(float matrix[4][4]);
        Matrix4(const Matrix4 &other);
        Matrix4(const Quaternion &quaternion);
        ~Matrix4();
        
        
        // Operators
        Matrix4 operator+= (const Matrix4 &other);
        friend Matrix4 operator+ (const Matrix4 &m1, const Matrix4 &m2);
        Matrix4 operator-= (const Matrix4 & other);
        friend Matrix4 operator- (const Matrix4 &m1, const Matrix4 &m2);
        float & operator() (int i, int j);
        const float & operator() (int i, int j) const;
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
        static Matrix4 createFromAxisAngle(const Vector3 &axis, float angle);
        static Matrix4 createFromYawPitchRoll(float yaw, float pitch, float roll);
        static Matrix4 createRotationX(float radians);
        static Matrix4 createRotationY(float radians);
        static Matrix4 createRotationZ(float radians);
        static Matrix4 createLookAt(const Vector3 &cameraPosition, const Vector3 &cameraTarget, const Vector3 &cameraUpVector);
        static Matrix4 createTranslation(float x, float y, float z);
        static Matrix4 createTranslation(const Vector3 &position);
        static Matrix4 createFromQuaternion(const Quaternion &quaternion);
        static Matrix4 transpose(const Matrix4 &matrix);
        
        
        // Static Properties
        static const Matrix4 Identity;
    };
}