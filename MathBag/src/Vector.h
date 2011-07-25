//
//  Vector.h
//  MathBag
//
//  Created by bronson on 11-06-27.
//

#pragma once

#ifdef __APPLE__ /* OS X */
#include <cstdlib>
#include <GLUT/glut.h>
#elif defined(__linux__) /* LINUX */
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#else /* WINDOWS */
#include <stdlib.h>
#include <windows.h>
#include <GL/glut.h>
#endif

#include <iostream>
#include <cmath>

#include "Precision.h"
#include "Matrix.h"

namespace MathBag
{
    class Matrix4;
    class Quaternion;
    
    class Vector3 {
    public:
        // Members
        real x, y, z;
        
        
        // Constructor, Destructors
        Vector3();
        explicit Vector3(real pX, real pY, real pZ);
        ~Vector3();
        
        
        // Public Methods
        real length() const;
        real lengthSquared() const;
        real dot(const Vector3 &other) const;
        void normalize();
        
        
        // Operators
        Vector3 operator+ (const Vector3 &other) const;
        Vector3 operator+= (const Vector3 &other);
        friend Vector3 operator- (const Vector3 &vector1, const Vector3 &vector2);
        Vector3 operator-() const;
        Vector3 operator-= (const Vector3 &other);
        friend Vector3 operator* (const Vector3 &vector, const real amount);
        friend Vector3 operator* (const real amount, const Vector3 &vector);
        void operator= (const Vector3 &other);
        bool operator== (const Vector3 &other) const;
        friend std::ostream & operator<<(std::ostream &os, const Vector3 &vector);
        
        
        // Static Methods
        static Vector3 normalize(const Vector3 &vector);
        static Vector3 cross(const Vector3 &vector1, const Vector3 &vector2);
        static real dot(const Vector3 &vector1, const Vector3 &vector2);
        static Vector3 transform(const Vector3 &vector, const Matrix4 &matrix);
        
        
        // Static Properties
        static const Vector3 unitX;
        static const Vector3 unitY;
        static const Vector3 unitZ;
        static const Vector3 zero;
    };
}
