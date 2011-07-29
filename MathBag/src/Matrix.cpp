//
//  Matrix.cpp
//  MathBag
//
//  Created by bronson on 11-06-27.
//

#include <assert.h>
    
#include "Precision.h"
#include "Matrix.h"

namespace MathBag
{
    const Matrix4 Matrix4::Identity = Matrix4(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);
    
    Matrix4::Matrix4()
    {
        m[M00] = 1;
        m[M10] = 0;
        m[M20] = 0;
        m[M30] = 0;
        
        m[M01] = 0;
        m[M11] = 1;
        m[M21] = 0;
        m[M31] = 0;
        
        m[M02] = 0;
        m[M12] = 0;
        m[M22] = 1;
        m[M32] = 0;
        
        m[M03] = 0;
        m[M13] = 0;
        m[M23] = 0;
        m[M33] = 1;
}
    
    Matrix4::Matrix4(real m00, real m01, real m02, real m03,
                     real m10, real m11, real m12, real m13,
                     real m20, real m21, real m22, real m23,
                     real m30, real m31, real m32, real m33)
    {
        m[M00] = m00;
        m[M01] = m01;
        m[M02] = m02;
        m[M03] = m03;
        m[M10] = m10;
        m[M11] = m11;
        m[M12] = m12;
        m[M13] = m13;
        m[M20] = m20;
        m[M21] = m21;
        m[M22] = m22;
        m[M23] = m23;
        m[M30] = m30;
        m[M31] = m31;
        m[M32] = m32;
        m[M33] = m33;
    }
    
    Matrix4::Matrix4(real matrix[16])
    {
        // Unroll the loop for performance.
        m[M00] = matrix[M00];
        m[M01] = matrix[M01];
        m[M02] = matrix[M02];
        m[M03] = matrix[M03];
        m[M10] = matrix[M10];
        m[M11] = matrix[M11];
        m[M12] = matrix[M12];
        m[M13] = matrix[M13];
        m[M20] = matrix[M20];
        m[M21] = matrix[M21];
        m[M22] = matrix[M22];
        m[M23] = matrix[M23];
        m[M30] = matrix[M30];
        m[M31] = matrix[M31];
        m[M32] = matrix[M32];
        m[M33] = matrix[M33];
    }
    
    Matrix4::Matrix4(const Matrix4 &matrix)
    {
        m[M00] = matrix.m[M00];
        m[M01] = matrix.m[M01];
        m[M02] = matrix.m[M02];
        m[M03] = matrix.m[M03];
        m[M10] = matrix.m[M10];
        m[M11] = matrix.m[M11];
        m[M12] = matrix.m[M12];
        m[M13] = matrix.m[M13];
        m[M20] = matrix.m[M20];
        m[M21] = matrix.m[M21];
        m[M22] = matrix.m[M22];
        m[M23] = matrix.m[M23];
        m[M30] = matrix.m[M30];
        m[M31] = matrix.m[M31];
        m[M32] = matrix.m[M32];
        m[M33] = matrix.m[M33];
    }
    
    Matrix4::Matrix4(const Quaternion &q)
    {
        *this = Matrix4::createFromQuaternion(q);
    }
    
    Matrix4::~Matrix4()
    {}
    
    
    Matrix4 Matrix4::operator+=(const Matrix4 &matrix)
    {
        m[M00] += matrix.m[M00];
        m[M01] += matrix.m[M01];
        m[M02] += matrix.m[M02];
        m[M03] += matrix.m[M03];
        m[M10] += matrix.m[M10];
        m[M11] += matrix.m[M11];
        m[M12] += matrix.m[M12];
        m[M13] += matrix.m[M13];
        m[M20] += matrix.m[M20];
        m[M21] += matrix.m[M21];
        m[M22] += matrix.m[M22];
        m[M23] += matrix.m[M23];
        m[M30] += matrix.m[M30];
        m[M31] += matrix.m[M31];
        m[M32] += matrix.m[M32];
        m[M33] += matrix.m[M33];

        return *this;
    }
    
    
    Matrix4 operator+(const Matrix4 &m1, const Matrix4 &m2)
    {
        Matrix4 sum;
        
        sum.m[M00] = m1.m[M00] + m2.m[M00];
        sum.m[M01] = m1.m[M01] + m2.m[M01];
        sum.m[M02] = m1.m[M02] + m2.m[M02];
        sum.m[M03] = m1.m[M03] + m2.m[M03];
        sum.m[M10] = m1.m[M10] + m2.m[M10];
        sum.m[M11] = m1.m[M11] + m2.m[M11];
        sum.m[M12] = m1.m[M12] + m2.m[M12];
        sum.m[M13] = m1.m[M13] + m2.m[M13];
        sum.m[M20] = m1.m[M20] + m2.m[M20];
        sum.m[M21] = m1.m[M21] + m2.m[M21];
        sum.m[M22] = m1.m[M22] + m2.m[M22];
        sum.m[M23] = m1.m[M23] + m2.m[M23];
        sum.m[M30] = m1.m[M30] + m2.m[M30];
        sum.m[M31] = m1.m[M31] + m2.m[M31];
        sum.m[M32] = m1.m[M32] + m2.m[M32];
        sum.m[M33] = m1.m[M33] + m2.m[M33];
        
        return sum;
    }
    
    
    Matrix4 Matrix4::operator-=(const Matrix4 &matrix)
    {
        m[M00] -= matrix.m[M00];
        m[M01] -= matrix.m[M01];
        m[M02] -= matrix.m[M02];
        m[M03] -= matrix.m[M03];
        m[M10] -= matrix.m[M10];
        m[M11] -= matrix.m[M11];
        m[M12] -= matrix.m[M12];
        m[M13] -= matrix.m[M13];
        m[M20] -= matrix.m[M20];
        m[M21] -= matrix.m[M21];
        m[M22] -= matrix.m[M22];
        m[M23] -= matrix.m[M23];
        m[M30] -= matrix.m[M30];
        m[M31] -= matrix.m[M31];
        m[M32] -= matrix.m[M32];
        m[M33] -= matrix.m[M33];
        
        return *this;
    }
    
    
    Matrix4 operator-(const Matrix4 &m1, const Matrix4 &m2)
    {
        Matrix4 difference;
        
        difference.m[M00] = m1.m[M00] - m2.m[M00];
        difference.m[M01] = m1.m[M01] - m2.m[M01];
        difference.m[M02] = m1.m[M02] - m2.m[M02];
        difference.m[M03] = m1.m[M03] - m2.m[M03];
        difference.m[M10] = m1.m[M10] - m2.m[M10];
        difference.m[M11] = m1.m[M11] - m2.m[M11];
        difference.m[M12] = m1.m[M12] - m2.m[M12];
        difference.m[M13] = m1.m[M13] - m2.m[M13];
        difference.m[M20] = m1.m[M20] - m2.m[M20];
        difference.m[M21] = m1.m[M21] - m2.m[M21];
        difference.m[M22] = m1.m[M22] - m2.m[M22];
        difference.m[M23] = m1.m[M23] - m2.m[M23];
        difference.m[M30] = m1.m[M30] - m2.m[M30];
        difference.m[M31] = m1.m[M31] - m2.m[M31];
        difference.m[M32] = m1.m[M32] - m2.m[M32];
        difference.m[M33] = m1.m[M33] - m2.m[M33];
        
        return difference;
    }
    
    
    real & Matrix4::operator()(int i)
    {
        return m[i];
    }
    
    
    const real & Matrix4::operator()(int i) const
    {
        return m[i];
    }
    
    real & Matrix4::operator[] (int i)
    {
        return m[i];
    }
    
    const real & Matrix4::operator[] (int i) const
    {
        return m[i];
    }
    
    
    Matrix4 Matrix4::operator*= (const Matrix4 &other)
    {
        *this = (*this) * other;
        return *this;
    }
    
    
    Matrix4 operator* (const Matrix4 &m1, const Matrix4 &m2)
    {
        Matrix4 output;
        
        output.m[M00] = m1.m[M00] * m2.m[M00] + m1.m[M01] * m2.m[M10] + m1.m[M02] * m2.m[M20] + m1.m[M03] * m2.m[M30];
        output.m[M01] = m1.m[M00] * m2.m[M01] + m1.m[M01] * m2.m[M11] + m1.m[M02] * m2.m[M21] + m1.m[M03] * m2.m[M31];
        output.m[M02] = m1.m[M00] * m2.m[M02] + m1.m[M01] * m2.m[M12] + m1.m[M02] * m2.m[M22] + m1.m[M03] * m2.m[M32];
        output.m[M03] = m1.m[M00] * m2.m[M03] + m1.m[M01] * m2.m[M13] + m1.m[M02] * m2.m[M23] + m1.m[M03] * m2.m[M33];
        output.m[M10] = m1.m[M10] * m2.m[M00] + m1.m[M11] * m2.m[M10] + m1.m[M12] * m2.m[M20] + m1.m[M13] * m2.m[M30];
        output.m[M11] = m1.m[M10] * m2.m[M01] + m1.m[M11] * m2.m[M11] + m1.m[M12] * m2.m[M21] + m1.m[M13] * m2.m[M31];
        output.m[M12] = m1.m[M10] * m2.m[M02] + m1.m[M11] * m2.m[M12] + m1.m[M12] * m2.m[M22] + m1.m[M13] * m2.m[M32];
        output.m[M13] = m1.m[M10] * m2.m[M03] + m1.m[M11] * m2.m[M13] + m1.m[M12] * m2.m[M23] + m1.m[M13] * m2.m[M33];
        output.m[M20] = m1.m[M20] * m2.m[M00] + m1.m[M21] * m2.m[M10] + m1.m[M22] * m2.m[M20] + m1.m[M23] * m2.m[M30];
        output.m[M21] = m1.m[M20] * m2.m[M01] + m1.m[M21] * m2.m[M11] + m1.m[M22] * m2.m[M21] + m1.m[M23] * m2.m[M31];
        output.m[M22] = m1.m[M20] * m2.m[M02] + m1.m[M21] * m2.m[M12] + m1.m[M22] * m2.m[M22] + m1.m[M23] * m2.m[M32];
        output.m[M23] = m1.m[M20] * m2.m[M03] + m1.m[M21] * m2.m[M13] + m1.m[M22] * m2.m[M23] + m1.m[M23] * m2.m[M33];
        output.m[M30] = m1.m[M30] * m2.m[M00] + m1.m[M31] * m2.m[M10] + m1.m[M32] * m2.m[M20] + m1.m[M33] * m2.m[M30];
        output.m[M31] = m1.m[M30] * m2.m[M01] + m1.m[M31] * m2.m[M11] + m1.m[M32] * m2.m[M21] + m1.m[M33] * m2.m[M31];
        output.m[M32] = m1.m[M30] * m2.m[M02] + m1.m[M31] * m2.m[M12] + m1.m[M32] * m2.m[M22] + m1.m[M33] * m2.m[M32];
        output.m[M33] = m1.m[M30] * m2.m[M03] + m1.m[M31] * m2.m[M13] + m1.m[M32] * m2.m[M23] + m1.m[M33] * m2.m[M33];
        
        return output;
    }
    
    std::ostream & operator<<(std::ostream &os, const Matrix4 &matrix)
    {
        if (!os.good()) return os;
        
        os << matrix.m[M00] << " " << matrix.m[M01] << " " << matrix.m[M02] << " " << matrix.m[M03] << "\n";
        os << matrix.m[M10] << " " << matrix.m[M11] << " " << matrix.m[M12] << " " << matrix.m[M13] << "\n";
        os << matrix.m[M20] << " " << matrix.m[M21] << " " << matrix.m[M22] << " " << matrix.m[M23] << "\n";
        os << matrix.m[M30] << " " << matrix.m[M31] << " " << matrix.m[M32] << " " << matrix.m[M33];
        
        os.flush();
        return os;
    }
    
    bool Matrix4::operator== (const Matrix4 &other) const
    {
        for (int i = 0; i < 16; ++i) 
        {
            if (m[i] != other.m[i]) return false;
        }
        return true;
    }
    
    bool Matrix4::operator!= (const Matrix4 &other) const
    {
        return !(*this == other);
    }
    
    Matrix4 Matrix4::createFromAxisAngle(const Vector3 &axis, real angle)
    {
        Matrix4 output;
        
        Vector3 unitAxis = axis;
        unitAxis.normalize();
        
        double c = cos(angle);
        double s = sin(angle);
        double t = 1 - c;
        
        output.m[M00] = real(t * unitAxis.x * unitAxis.x + c);
        output.m[M01] = real(t * unitAxis.y * unitAxis.x - s * unitAxis.z);
        output.m[M02] = real(t * unitAxis.z * unitAxis.x + s * unitAxis.y);
        output.m[M03] = 0;
        
        output.m[M10] = real(t * unitAxis.x * unitAxis.y + s * unitAxis.z);
        output.m[M11] = real(t * unitAxis.y * unitAxis.y + c);
        output.m[M12] = real(t * unitAxis.z * unitAxis.y - s * unitAxis.x);
        output.m[M13] = 0;
        
        output.m[M20] = real(t * unitAxis.x * unitAxis.z - s * unitAxis.y);
        output.m[M21] = real(t * unitAxis.y * unitAxis.z + s * unitAxis.x);
        output.m[M22] = real(t * unitAxis.z * unitAxis.z + c);
        output.m[M23] = 0;
        
        output.m[M30] = 0;
        output.m[M31] = 0;
        output.m[M32] = 0;
        output.m[M33] = 1;
        
        return output;
    }
    
    Matrix4 Matrix4::createFromYawPitchRoll(real yaw, real pitch, real roll)
    {
        Quaternion quaternion = Quaternion::createFromYawPitchRoll(yaw, pitch, roll);
        return Matrix4(quaternion);
    }
    
    Matrix4 Matrix4::createRotationX(real radians)
    {
        Matrix4 output;
        
        double c = cos(radians);
        double s = sin(radians);
        
        output.m[M00] = real(c);
        output.m[M01] = real(-s);
        output.m[M02] = 0;
        output.m[M03] = 0;
        
        output.m[M10] = real(s);
        output.m[M11] = real(c);
        output.m[M12] = 0;
        output.m[M13] = 0;
        
        output.m[M20] = 0;
        output.m[M21] = 0;
        output.m[M22] = 1;
        output.m[M23] = 0;
        
        output.m[M30] = 0;
        output.m[M31] = 0;
        output.m[M32] = 0;
        output.m[M33] = 1;
        
        return output;
    }
    
    Matrix4 Matrix4::createRotationY(real radians)
    {
        Matrix4 output;
        
        double c = cos(radians);
        double s = sin(radians);
        
        output.m[M00] = real(c);
        output.m[M01] = 0;
        output.m[M02] = real(s);
        output.m[M03] = 0;
        
        output.m[M10] = 0;
        output.m[M11] = 1;
        output.m[M12] = 0;
        output.m[M13] = 0;
        
        output.m[M20] = real(-s);
        output.m[M21] = 0;
        output.m[M22] = real(c);
        output.m[M23] = 0;
        
        output.m[M30] = 0;
        output.m[M31] = 0;
        output.m[M32] = 0;
        output.m[M33] = 1;
        
        return output;
    }
    
    Matrix4 Matrix4::createRotationZ(real radians)
    {
        Matrix4 output;
        
        double c = cos(radians);
        double s = sin(radians);
        
        output.m[M00] = 1;
        output.m[M01] = 0;
        output.m[M02] = 0;
        output.m[M03] = 0;
        
        output.m[M10] = 0;
        output.m[M11] = real(c);
        output.m[M12] = real(-s);
        output.m[M13] = 0;
        
        output.m[M20] = 0;
        output.m[M21] = real(s);
        output.m[M22] = real(c);
        output.m[M23] = 0;
        
        output.m[M30] = 0;
        output.m[M31] = 0;
        output.m[M32] = 0;
        output.m[M33] = 1;
        
        return output;
    }
    
    Matrix4 Matrix4::createLookAt(const Vector3 &cameraPosition, const Vector3 &cameraTarget, const Vector3 &cameraUpVector)
    {
        Vector3 forwardVector = Vector3::normalize(cameraTarget);
        Vector3 rightVector = Vector3::cross(forwardVector, cameraUpVector);
        
        Matrix4 output;
        
        output.m[M00] = rightVector.x;
        output.m[M01] = rightVector.y;
        output.m[M02] = rightVector.z;
        output.m[M03] = 0;
        
        output.m[M10] = cameraUpVector.x;
        output.m[M11] = cameraUpVector.y;
        output.m[M12] = cameraUpVector.z;
        output.m[M13] = 0;
        
        output.m[M20] = -forwardVector.x;
        output.m[M21] = -forwardVector.y;
        output.m[M22] = -forwardVector.z;
        output.m[M23] = 0;
        
        output.m[M30] = 0;
        output.m[M31] = 0;
        output.m[M32] = 0;
        output.m[M33] = 1;
        
        return output;
    }
    
    Matrix4 Matrix4::createTranslation(real x, real y, real z)
    {
        Matrix4 output = Matrix4::Identity;
        
        output.m[M03] = x;
        output.m[M13] = y;
        output.m[M23] = z;
        
        return output;
    }
    
    Matrix4 Matrix4::createTranslation(const Vector3 &position)
    {
        return Matrix4::createTranslation(position.x, position.y, position.z);
    }
    
    
    Matrix4 Matrix4::transpose(const Matrix4 &matrix)
    {
        Matrix4 output;
        
        output.m[M00] = matrix.m[M00];
        output.m[M10] = matrix.m[M01];
        output.m[M20] = matrix.m[M02];
        output.m[M30] = matrix.m[M03];
    
        output.m[M01] = matrix.m[M10];
        output.m[M11] = matrix.m[M11];
        output.m[M21] = matrix.m[M12];
        output.m[M31] = matrix.m[M13];
        
        output.m[M02] = matrix.m[M20];
        output.m[M12] = matrix.m[M21];
        output.m[M22] = matrix.m[M22];
        output.m[M32] = matrix.m[M23];
        
        output.m[M03] = matrix.m[M30];
        output.m[M13] = matrix.m[M31];
        output.m[M23] = matrix.m[M32];
        output.m[M33] = matrix.m[M33];
        
        return output;
    }
    
    Vector3 Matrix4::getUp() const
    {
        Vector3 output(m[M10], m[M11], m[M12]);
        return output;
    }
    
    void Matrix4::setUp(const Vector3 &upVector)
    {
        m[M10] = upVector.x;
        m[M11] = upVector.y;
        m[M12] = upVector.z;
    }
    
    Vector3 Matrix4::getRight() const
    {
        Vector3 output(m[M00], m[M01], m[M02]);
        return output;
    }
    
    void Matrix4::setRight(const Vector3 &rightVector)
    {
        m[M00] = rightVector.x;
        m[M01] = rightVector.y;
        m[M02] = rightVector.z;
    }
    
    Vector3 Matrix4::getForward() const
    {
        Vector3 output(m[M20], m[M21], m[M22]);
        return -output;
    }
    
    void Matrix4::setForward(const Vector3 &forwardVector)
    {
        m[M20] = -forwardVector.x;
        m[M21] = -forwardVector.y;
        m[M22] = -forwardVector.z;
    }
    
    Matrix4 Matrix4::createFromQuaternion(const Quaternion &q)
    {
        Matrix4 first(q.w, -q.z, q.y, -q.x, q.z, q.w, -q.x, -q.y, -q.y, q.x, q.w, -q.z, q.x, q.y, q.z, q.w);
        Matrix4 second(q.w, -q.z, q.y, q.x, q.z, q.w, -q.x, q.y, -q.y, q.x, q.w, q.z, -q.x, -q.y, -q.z, q.w);
        
        return first * second;
    }
    
}
