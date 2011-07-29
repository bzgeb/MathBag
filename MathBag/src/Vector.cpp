//
//  Vector.cpp
//  MathBag
//
//  Created by bronson on 11-06-27.
//
    
#include "Vector.h"

namespace MathBag
{    
    const Vector3 Vector3::unitX = Vector3(1, 0, 0);
    const Vector3 Vector3::unitY = Vector3(0, 1, 0);
    const Vector3 Vector3::unitZ = Vector3(0, 0, 1);
    const Vector3 Vector3::zero = Vector3(0, 0, 0);
    
    Vector3::Vector3() :
    x(0), y(0), z(0)
    {}
    
    Vector3::Vector3(real pX, real pY, real pZ) :
    x(pX), y(pY), z(pZ)
    {}
    
    Vector3::~Vector3()
    {}
    
    real Vector3::length() const
    {
        real magnitude = sqrt(x*x+y*y+z*z);
        return magnitude;
    }
    
    real Vector3::lengthSquared() const
    {
        real magnitudeSquared = (x*x+y*y+z*z);
        return magnitudeSquared;
    }
    
    void Vector3::normalize()
    {
        real length = this->length();
        
        x = x/length;
        y = y/length;
        z = z/length;
    }
    
    real Vector3::dot(const Vector3 &other) const
    {
        return (x * other.x + y * other.y + z * other.z);
    }
    
    Vector3 Vector3::operator+ (const Vector3 &other) const
    {
        Vector3 result(x + other.x, y + other.y, z + other.z);
        return result;
    }
    
    Vector3 Vector3::operator+= (const Vector3 &other)
    {
        *this = (*this) + other;
        return *this;
    }
    
    Vector3 operator- (const Vector3 &vector1, const Vector3 &vector2)
    {
        return Vector3(vector1.x - vector2.x, vector1.y - vector2.y, vector1.z - vector2.z);
    }
    
    Vector3 Vector3::operator- () const
    {
        Vector3 result(-x, -y, -z);
        return result;
    }
    
    Vector3 Vector3::operator-= (const Vector3 &other)
    {
        *this = (*this) - other;
        return *this;
    }
    
    Vector3 operator* (const Vector3 &vector, const real amount)
    {
        return Vector3(vector.x * amount, vector.y * amount, vector.z * amount);
    }
    
    Vector3 operator* (const real amount, const Vector3 &vector)
    {
        return vector * amount;
    }
    
    void Vector3::operator= (const Vector3 &other)
    {
        x = other.x;
        y = other.y;
        z = other.z;
    }
    
    bool Vector3::operator== (const Vector3 &other) const
    {
        if (x != other.x || y != other.y || z != other.z)
        {
            return false;
        }
        return true;
    }
    
    Vector3 Vector3::normalize(const Vector3 &vector)
    {
        Vector3 output;
        real length = vector.length();
        
        output.x = vector.x / length;
        output.y = vector.y / length;
        output.z = vector.z / length;
        
        return output;
    }
    
    Vector3 Vector3::cross(const Vector3 &vector1, const Vector3 &vector2)
    {
        real x = vector1.y * vector2.z - vector2.y * vector1.z;
        real y = vector1.z * vector2.x - vector2.z * vector1.x;
        real z = vector1.x * vector2.y - vector2.x * vector1.y;
        
        return Vector3(x, y, z);
    }
    
    real Vector3::dot(const Vector3 &vector1, const Vector3 &vector2)
    {
        return real(vector1.x * vector2.x + vector1.y * vector2.y + vector1.z * vector2.z);
    }
    
    Vector3 Vector3::transform(const Vector3 &vector, const Matrix4 &matrix)
    {
        Vector3 output;
        
        output.x = matrix.m[M00] * vector.x + matrix.m[M01] * vector.y + matrix.m[M02] * vector.z + matrix.m[M03];
        output.y = matrix.m[M10] * vector.x + matrix.m[M11] * vector.y + matrix.m[M12] * vector.z + matrix.m[M13];
        output.z = matrix.m[M20] * vector.x + matrix.m[M21] * vector.y + matrix.m[M22] * vector.z + matrix.m[M23];
        
        return output;
    }
    
    std::ostream & operator<<(std::ostream &os, const Vector3 &vector)
    {
        if (!os.good()) return os;
        
        os << "(" << vector.x << ", " << vector.y << ", " << vector.z << ")";
        
        os.flush();
        return os;
    }
}