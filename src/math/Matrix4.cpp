#include "Matrix4.h"

Matrix4::Matrix4() { }

Matrix4::Matrix4(float m11, float m12, float m13, float m14,
               float m21, float m22, float m23, float m24,
               float m31, float m32, float m33, float m34,
               float m41, float m42, float m43, float m44) {
    m[0] = m11;
    m[1] = m21;
    m[2] = m31;
    m[3] = m41;
    m[4] = m12;
    m[5] = m22;
    m[6] = m32;
    m[7] = m42;
    m[8] = m13;
    m[9] = m23;
    m[10] = m33;
    m[11] = m43;
    m[12] = m14;
    m[13] = m24;
    m[14] = m34;
    m[15] = m44;
}

void Matrix4::zeroOut() {
    for (int i = 0; i < 16; i++) {
        m[i] = 0;
    }
}

Matrix4 Matrix4::multiply(Matrix4 *m1, Matrix4 *m2) {
    Matrix4 m; 
    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++) {
            float sum = 0;
            for (int i = 0; i < 4; i++) {
                sum += m1->m[row + i * 4] * m2->m[i + col * 4];
            }
            m.m[row + col * 4] = sum;
        }
    }
    return m;
}

Matrix4 Matrix4::identity() {
    return Matrix4(
            1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1);
}

Matrix4 Matrix4::translation(Vector3 *v) {
    return Matrix4::translation(v->x, v->y, v->z);
}

Matrix4 Matrix4::translation(float x, float y, float z) {
    return Matrix4(
            1, 0, 0, x,
            0, 1, 0, y,
            0, 0, 1, z,
            0, 0, 0, 1);
}

Matrix4 Matrix4::scale(Vector3 *v) {
    return Matrix4::scale(v->x, v->y, v->z);
}

Matrix4 Matrix4::scale(float x, float y, float z) {
    return Matrix4(
            x, 0, 0, 0,
            0, y, 0, 0,
            0, 0, z, 0,
            0, 0, 0, 1);
}

Matrix4 Matrix4::eulerRotation(Vector3 *v) {
    return Matrix4::eulerRotation(v->x, v->y, v->z);
}

Matrix4 Matrix4::eulerRotation(float x, float y, float z) {
    float c1 = cos(x);
    float c2 = cos(y);
    float c3 = cos(z);

    float s1 = sin(x);
    float s2 = sin(y);
    float s3 = sin(z);

    return Matrix4(
            c2*c3            , -s2   , c2*s3            , 0,
            s1*s3 + c1*c3*s2 , c1*c2 , c1*s2*s3 - c3*s1 , 0,
            c3*s1*s2 - c1*s3 , c2*s1 , c1*c3 + s1*s2*s3 , 0,
            0                , 0     , 0                , 1);
}

float Matrix4::determinantOf(Matrix4 *m) {
	return m->m[12] * m->m[9]  * m->m[6]  * m->m[3] -
		   m->m[8]   * m->m[13] * m->m[6]  * m->m[3] -
		   m->m[12]  * m->m[5]  * m->m[10] * m->m[3] +
		   m->m[4]   * m->m[13] * m->m[10] * m->m[3] +
		   m->m[8]   * m->m[5]  * m->m[14] * m->m[3] -
		   m->m[4]   * m->m[9]  * m->m[14] * m->m[3] -
		   m->m[12]  * m->m[9]  * m->m[2]  * m->m[7] +
		   m->m[8]   * m->m[13] * m->m[2]  * m->m[7] +
		   m->m[12]  * m->m[1]  * m->m[10] * m->m[7] -
		   m->m[0]   * m->m[13] * m->m[10] * m->m[7] -
		   m->m[8]   * m->m[1]  * m->m[14] * m->m[7] +
		   m->m[0]   * m->m[9]  * m->m[14] * m->m[7] +
		   m->m[12]  * m->m[5]  * m->m[2]  * m->m[11] -
		   m->m[4]   * m->m[13] * m->m[2]  * m->m[11] -
		   m->m[12]  * m->m[1]  * m->m[6]  * m->m[11] +
		   m->m[0]   * m->m[13] * m->m[6]  * m->m[11] +
		   m->m[4]   * m->m[1]  * m->m[14] * m->m[11] -
		   m->m[0]   * m->m[5]  * m->m[14] * m->m[11] -
		   m->m[8]   * m->m[5]  * m->m[2]  * m->m[15] +
		   m->m[4]   * m->m[9]  * m->m[2]  * m->m[15] +
		   m->m[8]   * m->m[1]  * m->m[6]  * m->m[15] -
		   m->m[0]   * m->m[9]  * m->m[6]  * m->m[15] -
		   m->m[4]   * m->m[1]  * m->m[10] * m->m[15] +
		   m->m[0]   * m->m[5]  * m->m[10] * m->m[15];
}

Matrix4 Matrix4::inverseOf(Matrix4 *m) {
	float det = Matrix4::determinantOf(m);

	if (det == 0) {
        // Problem if this happens
		return Matrix4::identity();
	}

	float inv_det = 1 / det;
	
    return Matrix4(
		inv_det * (
			m->m[9] * m->m[14] * m->m[7] - m->m[13] * m->m[10] * m->m[7] +
			m->m[13] * m->m[6] * m->m[11] - m->m[5] * m->m[14] * m->m[11] -
			m->m[9] * m->m[6] * m->m[15] + m->m[5] * m->m[10] * m->m[15]
		),
		inv_det * (
			m->m[13] * m->m[10] * m->m[3] - m->m[9] * m->m[14] * m->m[3] -
			m->m[13] * m->m[2] * m->m[11] + m->m[1] * m->m[14] * m->m[11] +
			m->m[9] * m->m[2] * m->m[15] - m->m[1] * m->m[10] * m->m[15]
		),
		inv_det * (
			m->m[5] * m->m[14] * m->m[3] - m->m[13] * m->m[6] * m->m[3] +
			m->m[13] * m->m[2] * m->m[7] - m->m[1] * m->m[14] * m->m[7] -
			m->m[5] * m->m[2] * m->m[15] + m->m[1] * m->m[6] * m->m[15]
		),
		inv_det * (
			m->m[9] * m->m[6] * m->m[3] - m->m[5] * m->m[10] * m->m[3] -
			m->m[9] * m->m[2] * m->m[7] + m->m[1] * m->m[10] * m->m[7] +
			m->m[5] * m->m[2] * m->m[11] - m->m[1] * m->m[6] * m->m[11]
		),
		inv_det * (
			m->m[12] * m->m[10] * m->m[7] - m->m[8] * m->m[14] * m->m[7] -
			m->m[12] * m->m[6] * m->m[11] + m->m[4] * m->m[14] * m->m[11] +
			m->m[8] * m->m[6] * m->m[15] - m->m[4] * m->m[10] * m->m[15]
		),
		inv_det * (
			m->m[8] * m->m[14] * m->m[3] - m->m[12] * m->m[10] * m->m[3] +
			m->m[12] * m->m[2] * m->m[11] - m->m[0] * m->m[14] * m->m[11] -
			m->m[8] * m->m[2] * m->m[15] + m->m[0] * m->m[10] * m->m[15]
		),
		inv_det * (
			m->m[12] * m->m[6] * m->m[3] - m->m[4] * m->m[14] * m->m[3] -
			m->m[12] * m->m[2] * m->m[7] + m->m[0] * m->m[14] * m->m[7] +
			m->m[4] * m->m[2] * m->m[15] - m->m[0] * m->m[6] * m->m[15]
		),
		inv_det * (
			m->m[4] * m->m[10] * m->m[3] - m->m[8] * m->m[6] * m->m[3] +
			m->m[8] * m->m[2] * m->m[7] - m->m[0] * m->m[10] * m->m[7] -
			m->m[4] * m->m[2] * m->m[11] + m->m[0] * m->m[6] * m->m[11]
		),
		inv_det * (
			m->m[8] * m->m[13] * m->m[7] - m->m[12] * m->m[9] * m->m[7] +
			m->m[12] * m->m[5] * m->m[11] - m->m[4] * m->m[13] * m->m[11] -
			m->m[8] * m->m[5] * m->m[15] + m->m[4] * m->m[9] * m->m[15]
		),
		inv_det * (
			m->m[12] * m->m[9] * m->m[3] - m->m[8] * m->m[13] * m->m[3] -
			m->m[12] * m->m[1] * m->m[11] + m->m[0] * m->m[13] * m->m[11] +
			m->m[8] * m->m[1] * m->m[15] - m->m[0] * m->m[9] * m->m[15]
		),
		inv_det * (
			m->m[4] * m->m[13] * m->m[3] - m->m[12] * m->m[5] * m->m[3] +
			m->m[12] * m->m[1] * m->m[7] - m->m[0] * m->m[13] * m->m[7] -
			m->m[4] * m->m[1] * m->m[15] + m->m[0] * m->m[5] * m->m[15]
		),
		inv_det * (
			m->m[8] * m->m[5] * m->m[3] - m->m[4] * m->m[9] * m->m[3] -
			m->m[8] * m->m[1] * m->m[7] + m->m[0] * m->m[9] * m->m[7] +
			m->m[4] * m->m[1] * m->m[11] - m->m[0] * m->m[5] * m->m[11]
		),
		inv_det * (
			m->m[12] * m->m[9] * m->m[6] - m->m[8] * m->m[13] * m->m[6] -
			m->m[12] * m->m[5] * m->m[10] + m->m[4] * m->m[13] * m->m[10] +
			m->m[8] * m->m[5] * m->m[14] - m->m[4] * m->m[9] * m->m[14]
		),
		inv_det * (
			m->m[8] * m->m[13] * m->m[2] - m->m[12] * m->m[9] * m->m[2] +
			m->m[12] * m->m[1] * m->m[10] - m->m[0] * m->m[13] * m->m[10] -
			m->m[8] * m->m[1] * m->m[14] + m->m[0] * m->m[9] * m->m[14]
		),
		inv_det * (
			m->m[12] * m->m[5] * m->m[2] - m->m[4] * m->m[13] * m->m[2] -
			m->m[12] * m->m[1] * m->m[6] + m->m[0] * m->m[13] * m->m[6] +
			m->m[4] * m->m[1] * m->m[14] - m->m[0] * m->m[5] * m->m[14]
		),
		inv_det * (
			m->m[4] * m->m[9] * m->m[2] - m->m[8] * m->m[5] * m->m[2] +
			m->m[8] * m->m[1] * m->m[6] - m->m[0] * m->m[9] * m->m[6] -
			m->m[4] * m->m[1] * m->m[10] + m->m[0] * m->m[5] * m->m[10]
		)
	);
}

Matrix4 Matrix4::transposeOf(Matrix4 *m) {
    return Matrix4(
        m->m[0], m->m[4], m->m[8], m->m[12],
        m->m[1], m->m[5], m->m[9], m->m[13],
        m->m[2], m->m[6], m->m[10], m->m[14],
        m->m[3], m->m[7], m->m[11], m->m[15]
    );
}
