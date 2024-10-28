/*
 * kalman_filter.c
 *
 *  Created on: Oct 28, 2024
 *      Author: USER
 */

#include "kalman_filter.h"

void KalmanFilter_Init(KalmanFilter* kf, float Q, float R) {
    kf->x = 0.0f;
    kf->P = 1.0f;
    kf->Q = Q;
    kf->R = R;
    kf->K = 0.0f;
}

float KalmanFilter_Update(KalmanFilter* kf, float measurement) {
    // 예측 단계
    kf->P = kf->P + kf->Q;

    // 칼만 이득 계산
    kf->K = kf->P / (kf->P + kf->R);

    // 상태 업데이트
    kf->x = kf->x + kf->K * (measurement - kf->x);

    // 공분산 업데이트
    kf->P = (1 - kf->K) * kf->P;

    return kf->x;
}
