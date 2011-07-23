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
    
    Quaternion::Quaternion(float x, float y, float z, float w) :
    x(x), y(y), z(z), w(w)
    {}
    
    Quaternion::Quaternion(Vector3 vectorPart, float scalarPart) :
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
        
        float scalar = q1.w * q2.w - Vector3::dot(v1, v2);
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
        float scalarPart = q1.w - q2.w;
        Vector3 vectorPart = Vector3(q1.x - q2.x, q1.y - q2.y, q1.z - q2.z);
        
        return Quaternion(vectorPart, scalarPart);
    }
    
    Quaternion Quaternion::createFromYawPitchRoll(float yaw, float pitch, float roll)
    {
        Quaternion result;
        
        float num9 = roll * 0.5;
        float num6 = (float) sin((double) num9);
        float num5 = (float) cos((double) num9);
        float num8 = pitch * 0.5f;
        float num4 = (float) sin((double) num8);
        float num3 = (float) cos((double) num8);
        float num7 = yaw * 0.5f;
        float num2 = (float) sin((double) num7);
        float num = (float) cos((double) num7);
        
        result.x = ((num * num4) * num5) + ((num2 * num3) * num6);
        result.y = ((num2 * num3) * num5) - ((num * num4) * num6);
        result.z = ((num * num3) * num6) - ((num2 * num4) * num5);
        result.w = ((num * num3) * num5) + ((num2 * num4) * num6);
        
        return result;
    }
    
    Quaternion Quaternion::createFromAxisAngle(Vector3 axis, float radians)
    {
        double s = sin(radians/2);
        double c = cos(radians/2);
        
        Quaternion output;
        output.x = axis.x * float(s);
        output.y = axis.y * float(s);
        output.z = axis.z * float(s);
        output.w = float(c);
        
        return output;
    }
    
    Quaternion Quaternion::createFromRotationX(float radians)
    {
        return Quaternion::createFromAxisAngle(Vector3::unitX, radians);
    }
    
    Quaternion Quaternion::createFromRotationY(float radians)
    {
        return Quaternion::createFromAxisAngle(Vector3::unitY, radians);
    }
    
    Quaternion Quaternion::createFromRotationZ(float radians)
    {
        return Quaternion::createFromAxisAngle(Vector3::unitZ, radians);
    }
    
    //Quaternion Quaternion::createFromRotationMatrix(Matrix4 rotationMatrix)
    //{
    //    
    //}
}
