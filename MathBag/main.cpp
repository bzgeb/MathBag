//
//  main.cpp
//  MathBag
//
//  Created by bronson on 11-06-28.
//

#include <iostream>
#include <assert.h>

#include "Matrix.h"
#include "Vector.h"
#include "Quaternion.h"

using namespace std;
using namespace MathBag;

bool Matrix4Test();
bool QuaternionTest();

// Currently runs tests.
int main (int argc, const char * argv[])
{
    assert(Matrix4Test());
    assert(QuaternionTest());
    cout << "Passed tests." << endl;
    return 0;
}

bool Matrix4Test()
{
    Matrix4 identity = Matrix4::Identity;
    Matrix4 identity_copy = identity;
    identity_copy.m[0][0] = 0;
    
    Matrix4 transpose = Matrix4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
    
    // Test identity
    assert(identity == Matrix4(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1));
    assert(identity != Matrix4(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0));
    
    // Test copy
    assert(identity != identity_copy);
    
    // Test transpose
    assert(Matrix4::transpose(transpose) == Matrix4(1, 5, 9, 13, 2, 6, 10, 14, 3, 7, 11, 15, 4, 8, 12, 16));
    
    // Test yaw pitch roll
    Matrix4 yawPitchRoll(0.543033302, -0.704803526, 0.456472635, 1.49011612e-08, 0.456472725, 0.704041183, 0.54402113, 0, -0.704803467, -0.0870542228, 0.704041183, 0, 0, 0, 0, 1.00000024);
    assert(Matrix4::createFromYawPitchRoll(10, 10, 10) == yawPitchRoll);
    
    // Test Translation
    assert(Matrix4::createTranslation(10, 10, 10) == Matrix4::createTranslation(Vector3(10, 10, 10)));
    
    // Test Right
    Vector3 right = Vector3(5, 5, 5);
    Matrix4 test;
    test.setRight(right);
    assert(test.getRight() == right);
    
    // Test Up
    Vector3 up = Vector3(6, 6, 6);
    test.setUp(up);
    assert(test.getUp() == up);
    
    // Test Forward
    Vector3 forward = Vector3(8, 8, 8);
    test.setForward(forward);
    assert(test.getForward() == forward);
    
    return true;
}

bool QuaternionTest()
{
    Quaternion q1(1, 2, 3, 10);
    Quaternion q2(2, 3, 4, 11);
    
    assert((q1 * q2) == Quaternion(30, 54, 72, 90));
    assert((q1 * q2) != Quaternion(1, 1, 1, 1));
    
    q1 = Quaternion::createFromYawPitchRoll(7, 4, 5);
    assert(q1 == Quaternion(0.769551218, 0.392660767, -0.0223111063, -0.503100872));
    
    q1 = Quaternion::createFromRotationX(10);
    assert(q1 == Quaternion(-0.958924294, 0, 0, 0.2836622));
    
    q1 = Quaternion::createFromRotationY(10);
    assert(q1 == Quaternion(0, -0.958924294, 0, 0.2836622));
    
    q1 = Quaternion::createFromRotationZ(10);
    assert(q1 == Quaternion(0, 0, -0.958924294, 0.2836622));
    
    return true;
}

