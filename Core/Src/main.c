/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
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
#include "main.h"
#include "usb_device.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "usbd_hid.h"
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

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

extern USBD_HandleTypeDef hUsbDeviceFS;

//Keyboard structure data
typedef struct  {
	uint8_t MODIFIER;
	uint8_t RESERVED;
	uint8_t KEYCODE1;
	uint8_t KEYCODE2;
	uint8_t KEYCODE3;
	uint8_t KEYCODE4;
	uint8_t KEYCODE5;
	uint8_t KEYCODE6;
} keyboardHID;


//Initialize structure with a default value of 0
keyboardHID keyboardhid = {0,0,0,0,0,0,0,0};

//Initialize the ports and pins for every input you are using
#define PORT_1 GPIOA
#define PIN_1 GPIO_PIN_0

#define PORT_2 GPIOA
#define PIN_2 GPIO_PIN_1

#define PORT_3 GPIOA
#define PIN_3 GPIO_PIN_2

#define PORT_4 GPIOA
#define PIN_4 GPIO_PIN_3

	uint8_t key;


	//Function for each button press. Add more for more keys
	char read (void) {
		if ((!(HAL_GPIO_ReadPin (PORT_1, PIN_1))) == 0 || (!(HAL_GPIO_ReadPin (PORT_2, PIN_2))) == 0
				|| (!(HAL_GPIO_ReadPin (PORT_3, PIN_3))) == 0 || (!(HAL_GPIO_ReadPin (PORT_4, PIN_4))) == 0) {
				while ((!(HAL_GPIO_ReadPin (PORT_1, PIN_1))) == 0) {
					return 'T';
			}

				while ((!(HAL_GPIO_ReadPin (PORT_2, PIN_2))) == 0) {
					return 'E';
			}

				while ((!(HAL_GPIO_ReadPin (PORT_3, PIN_3))) == 0) {
					return 'S';
			}

				while ((!(HAL_GPIO_ReadPin (PORT_4, PIN_4))) == 0) {
					return '!';
			}
		}
	}



/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USB_DEVICE_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  key = read();

	  if (key != 0x01){
	  	  if (key == '1')  keyboardhid.KEYCODE1 = 0x1E;
	  	  if (key == '2')  keyboardhid.KEYCODE1 = 0x1F;
	  	  if (key == '3')  keyboardhid.KEYCODE1 = 0x20;
	  	  if (key == '4')  keyboardhid.KEYCODE1 = 0x21;
		  if (key == '5')  keyboardhid.KEYCODE1 = 0x22;
		  if (key == '6')  keyboardhid.KEYCODE1 = 0x23;
		  if (key == '7')  keyboardhid.KEYCODE1 = 0x24;
		  if (key == '8')  keyboardhid.KEYCODE1 = 0x25;
		  if (key == '9')  keyboardhid.KEYCODE1 = 0x26;
		  if (key == '0')  keyboardhid.KEYCODE1 = 0x27;

		  if (key == 'a')
		  {
			  keyboardhid.KEYCODE1 = 0x04;  // press 'a'
		  }
		  if (key == 'b')
		  {
			  keyboardhid.KEYCODE1 = 0x05;  // press 'b'
		  }
		  if (key == 'c')
		  {
			  keyboardhid.KEYCODE1 = 0x06;  // press 'c'
		  }
		  if (key == 'd')
		  {
			  keyboardhid.KEYCODE1 = 0x07;  // press 'd'
		  }
		  if (key == 'e')
		  {
			  keyboardhid.KEYCODE1 = 0x08;  // press 'e'
		  }
		  if (key == 'f')
		  {
			  keyboardhid.KEYCODE1 = 0x09;  // press 'f'
		  }
		  if (key == 'g')
		  {
			  keyboardhid.KEYCODE1 = 0x0A;  // press 'g'
		  }
		  if (key == 'h')
		  {
			  keyboardhid.KEYCODE1 = 0x0B;  // press 'h'
		  }
		  if (key == 'i')
		  {
			  keyboardhid.KEYCODE1 = 0x0C;  // press 'i'
		  }
		  if (key == 'j')
		  {
			  keyboardhid.KEYCODE1 = 0x0D;  // press 'j'
		  }
		  if (key == 'k')
		  {
			  keyboardhid.KEYCODE1 = 0x0E;  // press 'k'
		  }
		  if (key == 'l')
		  {
			  keyboardhid.KEYCODE1 = 0x0F;  // press 'l'
		  }
		  if (key == 'm')
		  {
			  keyboardhid.KEYCODE1 = 0x10;  // press 'm'
		  }
		  if (key == 'n')
		  {
			  keyboardhid.KEYCODE1 = 0x11;  // press 'n'
		  }
		  if (key == 'o')
		  {
			  keyboardhid.KEYCODE1 = 0x12;  // press 'o'
		  }
		  if (key == 'p')
		  {
			  keyboardhid.KEYCODE1 = 0x13;  // press 'p'
		  }
		  if (key == 'q')
		  {
			  keyboardhid.KEYCODE1 = 0x14;  // press 'q'
		  }
		  if (key == 'r')
		  {
			  keyboardhid.KEYCODE1 = 0x15;  // press 'r'
		  }
		  if (key == 's')
		  {
			  keyboardhid.KEYCODE1 = 0x16;  // press 's'
		  }
		  if (key == 't')
		  {
			  keyboardhid.KEYCODE1 = 0x17;  // press 't'
		  }
		  if (key == 'u')
		  {
			  keyboardhid.KEYCODE1 = 0x18;  // press 'u'
		  }
		  if (key == 'v')
		  {
			  keyboardhid.KEYCODE1 = 0x19;  // press 'v'
		  }
		  if (key == 'w')
		  {
			  keyboardhid.KEYCODE1 = 0x1A;  // press 'w'
		  }
		  if (key == 'x')
		  {
			  keyboardhid.KEYCODE1 = 0x1B;  // press 'x'
		  }
		  if (key == 'y')
		  {
			  keyboardhid.KEYCODE1 = 0x1C;  // press 'y'
		  }
		  if (key == 'z')
		  {
			  keyboardhid.KEYCODE1 = 0x1D;  // press 'z'
		  }


		  if (key == 'A')
		  {
			  keyboardhid.MODIFIER = 0x02;  // left shift pressed
			  keyboardhid.KEYCODE1 = 0x04;  // press 'a'
		  }
		  if (key == 'B')
		  {
			  keyboardhid.MODIFIER = 0x02;  // left shift pressed
			  keyboardhid.KEYCODE1 = 0x05;  // press 'b'
		  }
		  if (key == 'C')
		  {
			  keyboardhid.MODIFIER = 0x02;  // left shift pressed
			  keyboardhid.KEYCODE1 = 0x06;  // press 'c'
		  }
		  if (key == 'D')
		  {
			  keyboardhid.MODIFIER = 0x02;  // left shift pressed
			  keyboardhid.KEYCODE1 = 0x07;  // press 'd'
		  }
		  if (key == 'E')
		  {
			  keyboardhid.MODIFIER = 0x02;  // left shift pressed
			  keyboardhid.KEYCODE1 = 0x08;  // press 'e'
		  }
		  if (key == 'F')
		  {
			  keyboardhid.MODIFIER = 0x02;  // left shift pressed
			  keyboardhid.KEYCODE1 = 0x09;  // press 'f'
		  }
		  if (key == 'G')
		  {
			  keyboardhid.MODIFIER = 0x02;  // left shift pressed
			  keyboardhid.KEYCODE1 = 0x0A;  // press 'g'
		  }
		  if (key == 'H')
		  {
			  keyboardhid.MODIFIER = 0x02;  // left shift pressed
			  keyboardhid.KEYCODE1 = 0x0B;  // press 'h'
		  }
		  if (key == 'I')
		  {
			  keyboardhid.MODIFIER = 0x02;  // left shift pressed
			  keyboardhid.KEYCODE1 = 0x0C;  // press 'i'
		  }
		  if (key == 'J')
		  {
			  keyboardhid.MODIFIER = 0x02;  // left shift pressed
			  keyboardhid.KEYCODE1 = 0x0D;  // press 'j'
		  }
		  if (key == 'K')
		  {
			  keyboardhid.MODIFIER = 0x02;  // left shift pressed
			  keyboardhid.KEYCODE1 = 0x0E;  // press 'k'
		  }
		  if (key == 'L')
		  {
			  keyboardhid.MODIFIER = 0x02;  // left shift pressed
			  keyboardhid.KEYCODE1 = 0x0F;  // press 'l'
		  }
		  if (key == 'M')
		  {
			  keyboardhid.MODIFIER = 0x02;  // left shift pressed
			  keyboardhid.KEYCODE1 = 0x10;  // press 'm'
		  }
		  if (key == 'N')
		  {
			  keyboardhid.MODIFIER = 0x02;  // left shift pressed
			  keyboardhid.KEYCODE1 = 0x11;  // press 'n'
		  }
		  if (key == 'O')
		  {
			  keyboardhid.MODIFIER = 0x02;  // left shift pressed
			  keyboardhid.KEYCODE1 = 0x12;  // press 'o'
		  }
		  if (key == 'P')
		  {
			  keyboardhid.MODIFIER = 0x02;  // left shift pressed
			  keyboardhid.KEYCODE1 = 0x13;  // press 'p'
		  }
		  if (key == 'Q')
		  {
			  keyboardhid.MODIFIER = 0x02;  // left shift pressed
			  keyboardhid.KEYCODE1 = 0x14;  // press 'q'
		  }
		  if (key == 'R')
		  {
			  keyboardhid.MODIFIER = 0x02;  // left shift pressed
			  keyboardhid.KEYCODE1 = 0x15;  // press 'r'
		  }
		  if (key == 'S')
		  {
			  keyboardhid.MODIFIER = 0x02;  // left shift pressed
			  keyboardhid.KEYCODE1 = 0x16;  // press 's'
		  }
		  if (key == 'T')
		  {
			  keyboardhid.MODIFIER = 0x02;  // left shift pressed
			  keyboardhid.KEYCODE1 = 0x17;  // press 't'
		  }
		  if (key == 'U')
		  {
			  keyboardhid.MODIFIER = 0x02;  // left shift pressed
			  keyboardhid.KEYCODE1 = 0x18;  // press 'u'
		  }
		  if (key == 'V')
		  {
			  keyboardhid.MODIFIER = 0x02;  // left shift pressed
			  keyboardhid.KEYCODE1 = 0x19;  // press 'v'
		  }
		  if (key == 'W')
		  {
			  keyboardhid.MODIFIER = 0x02;  // left shift pressed
			  keyboardhid.KEYCODE1 = 0x1A;  // press 'w'
		  }
		  if (key == 'X')
		  {
			  keyboardhid.MODIFIER = 0x02;  // left shift pressed
			  keyboardhid.KEYCODE1 = 0x1B;  // press 'x'
		  }
		  if (key == 'Y')
		  {
			  keyboardhid.MODIFIER = 0x02;  // left shift pressed
			  keyboardhid.KEYCODE1 = 0x1C;  // press 'y'
		  }
		  if (key == 'Z')
		  {
			  keyboardhid.MODIFIER = 0x02;  // left shift pressed
			  keyboardhid.KEYCODE1 = 0x1D;  // press 'z'
		  }
		  if (key == ';')
		  {
			  keyboardhid.KEYCODE1 = 0x33;  // press ';'
		  }
		  if (key == ';')
		  {
			  keyboardhid.MODIFIER = 0x02;	// left shift pressed
			  keyboardhid.KEYCODE1 = 0x33;  // press ';'
		  }
		  if (key == '\'')
		  {
			  keyboardhid.KEYCODE1 = 0x34;  // press '''
		  }
		  if (key == '\"')
		  {
			  keyboardhid.MODIFIER = 0x02; 	// left shift pressed
			  keyboardhid.KEYCODE1 = 0x34;  // press '''
		  }
		  if (key == '[')
		  {
			  keyboardhid.KEYCODE1 = 0x2F;  // press '['
		  }
		  if (key == '{')
		  {
			  keyboardhid.MODIFIER = 0x02; 	// left shift pressed
			  keyboardhid.KEYCODE1 = 0x2F;  // press '['
		  }
		  if (key == ']')
		  {
			  keyboardhid.KEYCODE1 = 0x30;  // press ']'
		  }
		  if (key == '}')
		  {
			  keyboardhid.MODIFIER = 0x02; 	// left shift pressed
			  keyboardhid.KEYCODE1 = 0x30;  // press ']'
		  }
		  if (key == '\')
		  {
			  keyboardhid.KEYCODE1 = 0x31;  // press '\'
		  }
		  if (key == '|')
		  {
			  keyboardhid.MODIFIER = 0x02; 	// left shift pressed
			  keyboardhid.KEYCODE1 = 0x31;  // press '\'
		  }




		  if (key == ',')
		  {
			  keyboardhid.KEYCODE1 = 0x36;  // press ','
		  }
		  if (key == '<')
		  {
			  keyboardhid.MODIFIER = 0x02;  // left shift pressed
			  keyboardhid.KEYCODE1 = 0x36;  // press ','
		  }
		  if (key == '.')
		  {
			  keyboardhid.KEYCODE1 = 0x37;  // press '.'
		  }
		  if (key == '>')
		  {
			  keyboardhid.MODIFIER = 0x02;  // left shift pressed
			  keyboardhid.KEYCODE1 = 0x37;  // press '.'
		  }
		  if (key == '/')
		  {
			  keyboardhid.KEYCODE1 = 0x38;  // press '/'
		  }
		  if (key == '?')
		  {
			  keyboardhid.MODIFIER = 0x02;  // left shift pressed
			  keyboardhid.KEYCODE1 = 0x38;  // press '/'
		  }
		  if (key == '!')
		  {
			  keyboardhid.MODIFIER = 0x02;  // left shift pressed
			  keyboardhid.KEYCODE1 = 0x1E;  // press '1'
		  }
		  if (key == '@')
		  {
			  keyboardhid.MODIFIER = 0x02;	// left shift pressed
			  keyboardhid.KEYCODE1 = 0x1F;	// press '2'
		  }
		  if (key == '#')
		  {
			  keyboardhid.MODIFIER = 0x02;  // left shift pressed
			  keyboardhid.KEYCODE1 = 0x20;  // press '3'
		  }
		  if (key == '$')
		  {
			  keyboardhid.MODIFIER = 0x02;  // left shift pressed
			  keyboardhid.KEYCODE1 = 0x21;  // press '4'
		  }
		  if (key == '%')
		  {
			  keyboardhid.MODIFIER = 0x02;  // left shift pressed
			  keyboardhid.KEYCODE1 = 0x22;  // press '5'
		  }
		  if (key == '^')
		  {
			  keyboardhid.MODIFIER = 0x02;  // left shift pressed
			  keyboardhid.KEYCODE1 = 0x23;  // press '6'
		  }
		  if (key == '&')
		  {
			  keyboardhid.MODIFIER = 0x02;  // left shift pressed
			  keyboardhid.KEYCODE1 = 0x24;  // press '7'
		  }
		  if (key == '*')
		  {
			  keyboardhid.MODIFIER = 0x02;  // left shift pressed
			  keyboardhid.KEYCODE1 = 0x25;  // press '8'
		  }
		  if (key == '(')
		  {
			  keyboardhid.MODIFIER = 0x02;  // left shift pressed
			  keyboardhid.KEYCODE1 = 0x26;  // press '9'
		  }
		  if (key == ')')
		  {
			  keyboardhid.MODIFIER = 0x02;  // left shift pressed
			  keyboardhid.KEYCODE1 = 0x27;  // press '0'
		  }
		  if (key == '-')
		  {
			  keyboardhid.KEYCODE1 = 0x2D;  // press '-'
		  }
		  if (key == '_')
		  {
			  keyboardhid.MODIFIER = 0x02;  // left shift pressed
			  keyboardhid.KEYCODE1 = 0x2D;  // press '-'
		  }
		  if (key == '=')
		  {
			  keyboardhid.KEYCODE1 = 0x2E;  // press '='
		  }
		  if (key == '+')
		  {
			  keyboardhid.MODIFIER = 0x02;  // left shift pressed
			  keyboardhid.KEYCODE1 = 0x2E;  // press '='
		  }





	  	  USBD_HID_SendReport(&hUsbDeviceFS, &keyboardhid, sizeof (keyboardhid));
	  	  keyboardhid.KEYCODE1 = 0x00;  // release key
	  	  USBD_HID_SendReport(&hUsbDeviceFS, &keyboardhid, sizeof (keyboardhid));
	  	  HAL_Delay (50);
	  }

  }

  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL6;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USB;
  PeriphClkInit.UsbClockSelection = RCC_USBCLKSOURCE_PLL;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);

  /*Configure GPIO pins : PA0 PA1 PA2 PA3 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : PA4 */
  GPIO_InitStruct.Pin = GPIO_PIN_4;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
