//
//  Quaternion.cpp
//  MathBag
//
//  Created by bronson on 11-06-28.
//
#include "Quaternion.h"
namespace MathBag
{    
    const Quaternion Quaternion::Identity = Quaternion(0, 0, 0, 1);
    
    Quaternion::Quaternion() :
    x(0), y(0), z(0), w(1)
    {}
    
    Quaternion::Quaternion(real x, real y, real z, real w) :
    x(x), y(y), z(z), w(w)
    {}
    
    Quaternion::Quaternion(Vector3 vectorPart, real scalarPart) :
    x(vectorPart.x), y(vectorPart.y), z(vectorPart.z), w(scalarPart)
    {}
    
    Quaternion::~Quaternion()
    {}
    
    Quaternion Quaternion::operator+=(const Quaternion &other)
    {
        *this = (*this) + other;
        return *this;
    }
    
    Quaternion operator+ (const Quaternion &q1, const Quaternion &q2)
    {
        Quaternion result;
        
        result.w = q1.w + q2.w;
        result.x = q1.x + q2.x;
        result.y = q1.y + q2.y;
        result.z = q1.z + q2.z;
        
        return result;
    }
    
    Quaternion Quaternion::operator*=(const Quaternion &other)
    {
        *this = (*this) * other;
        return *this;
    }
    
    Quaternion operator* (const Quaternion &q1, const Quaternion &q2)
    {
        Vector3 v1 = Vector3(q1.x, q1.y, q1.z);
        Vector3 v2 = Vector3(q2.x, q2.y, q2.z);
        
        real scalar = q1.w * q2.w - Vector3::dot(v1, v2);
        Vector3 vector = q1.w * v2 + q2.w * v1 + Vector3::cross(v1, v2);
        
        return Quaternion(vector, scalar);
    }
    
    bool Quaternion::operator==(const Quaternion &other)
    {
        if (x != other.x || y != other.y || z != other.z || w != other.w)
        {
            return false;
        }
        return true;
    }
    
    bool Quaternion::operator!=(const Quaternion &other)
    {
        return !(*this == other);
    }
    
    Quaternion Quaternion::operator-= (const Quaternion &other)
    {
        *this = (*this) - other;
        return *this;
    }
    
    Quaternion operator- (const Quaternion &q1, const Quaternion &q2)
    {
        real scalarPart = q1.w - q2.w;
        Vector3 vectorPart = Vector3(q1.x - q2.x, q1.y - q2.y, q1.z - q2.z);
        
        return Quaternion(vectorPart, scalarPart);
    }
    
    Quaternion Quaternion::createFromYawPitchRoll(real yaw, real pitch, real roll)
    {
        Quaternion result;
        
        real num9 = roll * 0.5;
        real num6 = (real) sin((double) num9);
        real num5 = (real) cos((double) num9);
        real num8 = pitch * 0.5f;
        real num4 = (real) sin((double) num8);
        real num3 = (real) cos((double) num8);
        real num7 = yaw * 0.5f;
        real num2 = (real) sin((double) num7);
        real num = (real) cos((double) num7);
        
        result.x = ((num * num4) * num5) + ((num2 * num3) * num6);
        result.y = ((num2 * num3) * num5) - ((num * num4) * num6);
        result.z = ((num * num3) * num6) - ((num2 * num4) * num5);
        result.w = ((num * num3) * num5) + ((num2 * num4) * num6);
        
        return result;
    }
    
    Quaternion Quaternion::createFromAxisAngle(Vector3 axis, real radians)
    {
        double s = sin(radians/2);
        double c = cos(radians/2);
        
        Quaternion output;
        output.x = axis.x * real(s);
        output.y = axis.y * real(s);
        output.z = axis.z * real(s);
        output.w = real(c);
        
        return output;
    }
    
    Quaternion Quaternion::createFromRotationX(real radians)
    {
        return Quaternion::createFromAxisAngle(Vector3::unitX, radians);
    }
    
    Quaternion Quaternion::createFromRotationY(real radians)
    {
        return Quaternion::createFromAxisAngle(Vector3::unitY, radians);
    }
    
    Quaternion Quaternion::createFromRotationZ(real radians)
    {
        return Quaternion::createFromAxisAngle(Vector3::unitZ, radians);
    }
    
    //Quaternion Quaternion::createFromRotationMatrix(Matrix4 rotationMatrix)
    //{
    //    
    //}
    
    Quaternion Quaternion::normalize(const Quaternion &q1)
    {
        Quaternion result;
        
        real magnitude = sqrtf((q1.w * q1.w) + (q1.x * q1.x) + (q1.y * q1.y) + (q1.z * q1.z));
        result.w = q1.w / magnitude;
        result.x = q1.x / magnitude;
        result.y = q1.y / magnitude;
        result.z = q1.z / magnitude;
        
        return result;
    }
}
