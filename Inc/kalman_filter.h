/*
 * kalman_filter.h
 *
 *  Created on: Oct 28, 2024
 *      Author: USER
 */

#ifndef INC_KALMAN_FILTER_H_
#define INC_KALMAN_FILTER_H_

typedef struct {
    float x;   // 상태 변수 (거리)
    float P;   // 공분산 (오차)
    float Q;   // 프로세스 노이즈 공분산
    float R;   // 측정 노이즈 공분산
    float K;   // 칼만 이득
} KalmanFilter;


void KalmanFilter_Init(KalmanFilter* kf, float Q, float R);
float KalmanFilter_Update(KalmanFilter* kf, float measurement);

#endif /* INC_KALMAN_FILTER_H_ */
