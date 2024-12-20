/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "bluetooth.h"
#include "sensor.h"
#include "kalman_filter.h"

//float filtered_center;
//float filtered_left;
//float filtered_right;
//
//KalmanFilter kf_center, kf_left, kf_right;
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
/* Definitions for StartDefaultTas */
osThreadId_t StartDefaultTasHandle;
const osThreadAttr_t StartDefaultTas_attributes = {
  .name = "StartDefaultTas",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for myTask02 */
osThreadId_t myTask02Handle;
const osThreadAttr_t myTask02_attributes = {
  .name = "myTask02",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow,
};
/* Definitions for myTask03 */
osThreadId_t myTask03Handle;
const osThreadAttr_t myTask03_attributes = {
  .name = "myTask03",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow,
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void echoreadTask(void *argument);
void autoDrivingTask(void *argument);
void StartTask03(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of StartDefaultTas */
  StartDefaultTasHandle = osThreadNew(echoreadTask, NULL, &StartDefaultTas_attributes);

  /* creation of myTask02 */
  myTask02Handle = osThreadNew(autoDrivingTask, NULL, &myTask02_attributes);

  /* creation of myTask03 */
  myTask03Handle = osThreadNew(StartTask03, NULL, &myTask03_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_echoreadTask */
/**
  * @brief  Function implementing the StartDefaultTas thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_echoreadTask */
void echoreadTask(void *argument)
{
  /* USER CODE BEGIN echoreadTask */
  /* Infinite loop */
  for(;;)
  {

	echo_get();
    osDelay(10);
  }
  /* USER CODE END echoreadTask */
}

/* USER CODE BEGIN Header_autoDrivingTask */
/**
* @brief Function implementing the myTask02 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_autoDrivingTask */
void autoDrivingTask(void *argument)
{
  /* USER CODE BEGIN autoDrivingTask */

  /* Infinite loop */
  for(;;)
  {
	if(autoDrive_flag)
	{
		if(echo_center_time >= 200)
		{
			Forward();
			if((echo_left_time < 60) || (echo_right_time < 60))
			{
				if(echo_left_time < echo_right_time)
				{
					Left_slow();
				}
				else if(echo_right_time < echo_left_time)
				{
					Right_slow();
				}
			}
		}
		else if(echo_center_time < 200)
		{
			STOP();
			while(1)
			{
				if(echo_left_time < echo_right_time)
				{
					Left();
				}
				if(echo_right_time < echo_left_time)
				{
					Right();
				}
				if(echo_center_time >= 200)
				{
					break;
				}
			}
		}
	}
    osDelay(1);
  }
  /* USER CODE END autoDrivingTask */
}

/* USER CODE BEGIN Header_StartTask03 */
/**
* @brief Function implementing the myTask03 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask03 */
void StartTask03(void *argument)
{
  /* USER CODE BEGIN StartTask03 */
  /* Infinite loop */
  for(;;)
  {
//	filtered_center = KalmanFilter_Update(&kf_center, echo_center_time);
//	filtered_left = KalmanFilter_Update(&kf_left, echo_left_time);
//	filtered_right = KalmanFilter_Update(&kf_right, echo_right_time);
	osDelay(1);
  }
  /* USER CODE END StartTask03 */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

