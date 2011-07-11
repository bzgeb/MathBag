//
//  Matrix.cpp
//  MathBag
//
//  Created by bronson on 11-06-27.
//

#include <assert.h>

#include "Matrix.h"

const Matrix4 Matrix4::Identity = Matrix4(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);

Matrix4::Matrix4()
{
    m[0][0] = 1;
    m[0][1] = 0;
    m[0][2] = 0;
    m[0][3] = 0;
    m[1][0] = 0;
    m[1][1] = 1;
    m[1][2] = 0;
    m[1][3] = 0;
    m[2][0] = 0;
    m[2][1] = 0;
    m[2][2] = 1;
    m[2][3] = 0;
    m[3][0] = 0;
    m[3][1] = 0;
    m[3][2] = 0;
    m[3][3] = 0;
}

Matrix4::Matrix4(float m00, float m01, float m02, float m03,
        float m10, float m11, float m12, float m13,
        float m20, float m21, float m22, float m23,
        float m30, float m31, float m32, float m33)
{
    m[0][0] = m00;
    m[0][1] = m01;
    m[0][2] = m02;
    m[0][3] = m03;
    m[1][0] = m10;
    m[1][1] = m11;
    m[1][2] = m12;
    m[1][3] = m13;
    m[2][0] = m20;
    m[2][1] = m21;
    m[2][2] = m22;
    m[2][3] = m23;
    m[3][0] = m30;
    m[3][1] = m31;
    m[3][2] = m32;
    m[3][3] = m33;
}

Matrix4::Matrix4(float matrix[4][4])
{
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            m[i][j] = matrix[i][j];
        }
    }
}

Matrix4::Matrix4(const Matrix4 &other)
{
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            m[i][j] = other(i, j);
        }
    }
}

Matrix4::Matrix4(const Quaternion &q)
{
    *this = Matrix4::createFromQuaternion(q);
}

Matrix4::~Matrix4()
{}


Matrix4 Matrix4::operator+=(const Matrix4 &other)
{
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            m[i][j] += other(i, j);
        }
    }
    
    return *this;
}


Matrix4 operator+(const Matrix4 &m1, const Matrix4 &m2)
{
    Matrix4 sum;
    
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            sum.m[i][j] = m1(i, j) + m2(i, j);
        }
    }
    
    return sum;
}


Matrix4 Matrix4::operator-=(const Matrix4 &other)
{
    for (int i = 0; i < 4; ++i) 
    {
        for (int j = 0; j < 4; ++j) 
        {
            m[i][j] -= other(i, j);
        }
    }
    
    return *this;
}


Matrix4 operator-(const Matrix4 &m1, const Matrix4 &m2)
{
    Matrix4 difference;
    
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            difference.m[i][j] = m1(i, j) - m2(i, j);
        }
    }
    
    return difference;
}


float & Matrix4::operator()(int i, int j)
{
    return m[i][j];
}


const float & Matrix4::operator()(int i, int j) const
{
    return m[i][j];
}


Matrix4 Matrix4::operator*= (const Matrix4 &other)
{
    *this = (*this) * other;
    return *this;
}


Matrix4 operator* (const Matrix4 &m1, const Matrix4 &m2)
{
    Matrix4 output;
    
    output.m[0][0] = m1(0,0) * m2(0,0) + m1(0,1) * m2(1,0) + m1(0,2) * m2(2,0) + m1(0,3) * m2(3,0);
    output.m[0][1] = m1(0,0) * m2(0,1) + m1(0,1) * m2(1,1) + m1(0,2) * m2(2,1) + m1(0,3) * m2(3,1);
    output.m[0][2] = m1(0,0) * m2(0,2) + m1(0,1) * m2(1,2) + m1(0,2) * m2(2,2) + m1(0,3) * m2(3,2);
    output.m[0][3] = m1(0,0) * m2(0,3) + m1(0,1) * m2(1,3) + m1(0,2) * m2(2,3) + m1(0,3) * m2(3,3);
    output.m[1][0] = m1(1,0) * m2(0,0) + m1(1,1) * m2(1,0) + m1(1,2) * m2(2,0) + m1(1,3) * m2(3,0);
    output.m[1][1] = m1(1,0) * m2(0,1) + m1(1,1) * m2(1,1) + m1(1,2) * m2(2,1) + m1(1,3) * m2(3,1);
    output.m[1][2] = m1(1,0) * m2(0,2) + m1(1,1) * m2(1,2) + m1(1,2) * m2(2,2) + m1(1,3) * m2(3,2);
    output.m[1][3] = m1(1,0) * m2(0,3) + m1(1,1) * m2(1,3) + m1(1,2) * m2(2,3) + m1(1,3) * m2(3,3);
    output.m[2][0] = m1(2,0) * m2(0,0) + m1(2,1) * m2(1,0) + m1(2,2) * m2(2,0) + m1(2,3) * m2(3,0);
    output.m[2][1] = m1(2,0) * m2(0,1) + m1(2,1) * m2(1,1) + m1(2,2) * m2(2,1) + m1(2,3) * m2(3,1);
    output.m[2][2] = m1(2,0) * m2(0,2) + m1(2,1) * m2(1,2) + m1(2,2) * m2(2,2) + m1(2,3) * m2(3,2);
    output.m[2][3] = m1(2,0) * m2(0,3) + m1(2,1) * m2(1,3) + m1(2,2) * m2(2,3) + m1(2,3) * m2(3,3);
    output.m[3][0] = m1(3,0) * m2(0,0) + m1(3,1) * m2(1,0) + m1(3,2) * m2(2,0) + m1(3,3) * m2(3,0);
    output.m[3][1] = m1(3,0) * m2(0,1) + m1(3,1) * m2(1,1) + m1(3,2) * m2(2,1) + m1(3,3) * m2(3,1);
    output.m[3][2] = m1(3,0) * m2(0,2) + m1(3,1) * m2(1,2) + m1(3,2) * m2(2,2) + m1(3,3) * m2(3,2);
    output.m[3][3] = m1(3,0) * m2(0,3) + m1(3,1) * m2(1,3) + m1(3,2) * m2(2,3) + m1(3,3) * m2(3,3);
    
    return output;
}

std::ostream & operator<<(std::ostream &os, const Matrix4 &matrix)
{
    if (!os.good()) return os;
    
    os << matrix(0, 0) << " " << matrix(0, 1) << " " << matrix(0, 2) << " " << matrix(0, 3) << "\n";
    os << matrix(1, 0) << " " << matrix(1, 1) << " " << matrix(1, 2) << " " << matrix(1, 3) << "\n";
    os << matrix(2, 0) << " " << matrix(2, 1) << " " << matrix(2, 2) << " " << matrix(2, 3) << "\n";
    os << matrix(3, 0) << " " << matrix(3, 1) << " " << matrix(3, 2) << " " << matrix(3, 3);
    
    os.flush();
    return os;
}

bool Matrix4::operator== (const Matrix4 &other) const
{
    for (int i = 0; i < 4; ++i) 
    {
        for (int j = 0; j < 4; ++j)
        {
            if (m[i][j] != other(i, j)) return false;
        }
    }
    return true;
}

bool Matrix4::operator!= (const Matrix4 &other) const
{
    return !(*this == other);
}

Matrix4 Matrix4::createFromAxisAngle(const Vector3 &axis, float angle)
{
    Matrix4 output;
    
    Vector3 unitAxis = axis;
    unitAxis.normalize();
    
    double c = cos(angle);
    double s = sin(angle);
    double t = 1 - c;
    
    output.m[0][0] = float(t * unitAxis.x * unitAxis.x + c);
    output.m[0][1] = float(t * unitAxis.y * unitAxis.x - s * unitAxis.z);
    output.m[0][2] = float(t * unitAxis.z * unitAxis.x + s * unitAxis.y);
    output.m[0][3] = 0;
    
    output.m[1][0] = float(t * unitAxis.x * unitAxis.y + s * unitAxis.z);
    output.m[1][1] = float(t * unitAxis.y * unitAxis.y + c);
    output.m[1][2] = float(t * unitAxis.z * unitAxis.y - s * unitAxis.x);
    output.m[1][3] = 0;
    
    output.m[2][0] = float(t * unitAxis.x * unitAxis.z - s * unitAxis.y);
    output.m[2][1] = float(t * unitAxis.y * unitAxis.z + s * unitAxis.x);
    output.m[2][2] = float(t * unitAxis.z * unitAxis.z + c);
    output.m[2][3] = 0;
    
    output.m[3][0] = 0;
    output.m[3][1] = 0;
    output.m[3][2] = 0;
    output.m[3][3] = 1;
    
    return output;
}

Matrix4 Matrix4::createFromYawPitchRoll(float yaw, float pitch, float roll)
{
    Quaternion quaternion = Quaternion::createFromYawPitchRoll(yaw, pitch, roll);
    return Matrix4(quaternion);
}

Matrix4 Matrix4::createRotationX(float radians)
{
    Matrix4 output;
    
    double c = cos(radians);
    double s = sin(radians);
    
    output.m[0][0] = float(c);
    output.m[0][1] = float(-s);
    output.m[0][2] = 0;
    output.m[0][3] = 0;
    
    output.m[1][0] = float(s);
    output.m[1][1] = float(c);
    output.m[1][2] = 0;
    output.m[1][3] = 0;
    
    output.m[2][0] = 0;
    output.m[2][1] = 0;
    output.m[2][2] = 1;
    output.m[2][3] = 0;
    
    output.m[3][0] = 0;
    output.m[3][1] = 0;
    output.m[3][2] = 0;
    output.m[3][3] = 1;
    
    return output;
}

Matrix4 Matrix4::createRotationY(float radians)
{
    Matrix4 output;
    
    double c = cos(radians);
    double s = sin(radians);
    
    output.m[0][0] = float(c);
    output.m[0][1] = 0;
    output.m[0][2] = float(s);
    output.m[0][3] = 0;
    
    output.m[1][0] = 0;
    output.m[1][1] = 1;
    output.m[1][2] = 0;
    output.m[1][3] = 0;
    
    output.m[2][0] = float(-s);
    output.m[2][1] = 0;
    output.m[2][2] = float(c);
    output.m[2][3] = 0;
    
    output.m[3][0] = 0;
    output.m[3][1] = 0;
    output.m[3][2] = 0;
    output.m[3][3] = 1;
    
    return output;
}

Matrix4 Matrix4::createRotationZ(float radians)
{
    Matrix4 output;
    
    double c = cos(radians);
    double s = sin(radians);
    
    output.m[0][0] = 1;
    output.m[0][1] = 0;
    output.m[0][2] = 0;
    output.m[0][3] = 0;
    
    output.m[1][0] = 0;
    output.m[1][1] = float(c);
    output.m[1][2] = float(-s);
    output.m[1][3] = 0;
    
    output.m[2][0] = 0;
    output.m[2][1] = float(s);
    output.m[2][2] = float(c);
    output.m[2][3] = 0;
    
    output.m[3][0] = 0;
    output.m[3][1] = 0;
    output.m[3][2] = 0;
    output.m[3][3] = 1;
    
    return output;
}

Matrix4 Matrix4::createLookAt(const Vector3 &cameraPosition, const Vector3 &cameraTarget, const Vector3 &cameraUpVector)
{
    Vector3 forwardVector = Vector3::normalize(cameraTarget);
    Vector3 rightVector = Vector3::cross(forwardVector, cameraUpVector);
    
    Matrix4 output;
    
    output.m[0][0] = rightVector.x;
    output.m[0][1] = rightVector.y;
    output.m[0][2] = rightVector.z;
    output.m[0][3] = 0;
    
    output.m[1][0] = cameraUpVector.x;
    output.m[1][1] = cameraUpVector.y;
    output.m[1][2] = cameraUpVector.z;
    output.m[1][3] = 0;
    
    output.m[2][0] = -forwardVector.x;
    output.m[2][1] = -forwardVector.y;
    output.m[2][2] = -forwardVector.z;
    output.m[2][3] = 0;
    
    output.m[3][0] = 0;
    output.m[3][1] = 0;
    output.m[3][2] = 0;
    output.m[3][3] = 1;
    
    return output;
}

Matrix4 Matrix4::createTranslation(float x, float y, float z)
{
    Matrix4 output = Matrix4::Identity;
    
    output.m[0][3] = x;
    output.m[1][3] = y;
    output.m[2][3] = z;
    
    return output;
}

Matrix4 Matrix4::createTranslation(const Vector3 &position)
{
    return Matrix4::createTranslation(position.x, position.y, position.z);
}


Matrix4 Matrix4::transpose(const Matrix4 &matrix)
{
    Matrix4 output;
    
    output.m[0][0] = matrix(0,0);
    output.m[1][0] = matrix(0,1);
    output.m[2][0] = matrix(0,2);
    output.m[3][0] = matrix(0,3);
    
    output.m[0][1] = matrix(1,0);
    output.m[1][1] = matrix(1,1);
    output.m[2][1] = matrix(1,2);
    output.m[3][1] = matrix(1,3);
    
    output.m[0][2] = matrix(2,0);
    output.m[1][2] = matrix(2,1);
    output.m[2][2] = matrix(2,2);
    output.m[3][2] = matrix(2,3);
    
    output.m[0][3] = matrix(3,0);
    output.m[1][3] = matrix(3,1);
    output.m[2][3] = matrix(3,2);
    output.m[3][3] = matrix(3,3);
    
    return output;
}

Vector3 Matrix4::getUp() const
{
    Vector3 output(m[1][0], m[1][1], m[1][2]);
    return output;
}

void Matrix4::setUp(const Vector3 &upVector)
{
    m[1][0] = upVector.x;
    m[1][1] = upVector.y;
    m[1][2] = upVector.z;
}

Vector3 Matrix4::getRight() const
{
    Vector3 output(m[0][0], m[0][1], m[0][2]);
    return output;
}

void Matrix4::setRight(const Vector3 &rightVector)
{
    m[0][0] = rightVector.x;
    m[0][1] = rightVector.y;
    m[0][2] = rightVector.z;
}

Vector3 Matrix4::getForward() const
{
    Vector3 output(m[2][0], m[2][1], m[2][2]);
    return -output;
}

void Matrix4::setForward(const Vector3 &forwardVector)
{
    m[2][0] = -forwardVector.x;
    m[2][1] = -forwardVector.y;
    m[2][2] = -forwardVector.z;
}

Matrix4 Matrix4::createFromQuaternion(const Quaternion &q)
{
    Matrix4 first(q.w, -q.z, q.y, -q.x, q.z, q.w, -q.x, -q.y, -q.y, q.x, q.w, -q.z, q.x, q.y, q.z, q.w);
    Matrix4 second(q.w, -q.z, q.y, q.x, q.z, q.w, -q.x, q.y, -q.y, q.x, q.w, q.z, -q.x, -q.y, -q.z, q.w);
    
    return first * second;
}


