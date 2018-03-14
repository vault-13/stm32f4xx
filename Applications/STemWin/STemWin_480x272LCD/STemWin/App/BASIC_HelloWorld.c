/*********************************************************************
*                SEGGER MICROCONTROLLER SYSTEME GmbH                 *
*        Solutions for real time microcontroller applications        *
**********************************************************************
*                                                                    *
*        (c) 1996 - 2015  SEGGER Microcontroller Systeme GmbH        *
*                                                                    *
*        Internet: www.segger.com    Support:  support@segger.com    *
*                                                                    *
**********************************************************************

***** emWin - Graphical user interface for embedded applications *****
emWin is protected by international copyright laws.   Knowledge of the
source code may not be used to write a similar product.  This file may
only be used in accordance with a license and should not be re-
distributed in any way. We appreciate your understanding and fairness.
----------------------------------------------------------------------
File        : BASIC_HelloWorld.c
Purpose     : Simple demo drawing "Hello world"
----------------------------------------------------------------------
*/

#include "GUI.h"
#include "math.h"
extern GUI_CONST_STORAGE GUI_FONT GUI_FontPerfectDOSVGA43724;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontSegoeUI15;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontSegoeUI30;
/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
/*********************************************************************
*
*       MainTask
*/
void MainTask(void) {

	int  i; 
	I16	y[240], z[240];
	double s, x;
 	GUI_EnableAlpha(1);
	GUI_Clear();
	GUI_SetColor(GUI_BLACK);
	GUI_DispStringHCenterAt("Alphablending", 45, 41);
	GUI_SetColor(GUI_MAKE_COLOR((0x40uL << 24) | 0x0000FF));
	GUI_FillRect(50, 50, 109, 109);
	GUI_SetColor(GUI_MAKE_COLOR((0x80uL << 24) | 0x00FF00));
	GUI_FillRect(80, 80, 139, 139);
	GUI_SetColor(GUI_MAKE_COLOR((0xC0uL << 24) | 0xFF0000));
	GUI_FillRect(110, 110, 169, 169);
	
	
	GUI_SetColor(GUI_WHITE);
	GUI_SetPenSize(1);
	GUI_SetLineStyle(GUI_LS_SOLID);
	GUI_DrawLine(0, 200, 480, 200);
	GUI_SetPenSize(2);
	for (i=10; i<480; i=i+40){
		GUI_DrawVLine(i, 195, 205);
	}
	for (i=30; i<480; i=i+40){
		GUI_DrawVLine(i, 198, 202);
	}
	
	GUI_SetPenSize(1);
	for (i=0; i<=240; i++){
		//x = abs(i);
		s = (double)(i)*6*3.1415926/180;
		x = cos(s);
		y[i] = x*30;
		x = sin(s);
		z[i] = x*30;
		//GUI_DispFloat(x, 5);
	}
		GUI_DrawGraph(y, 240, 100, 40);
		GUI_DrawGraph(z, 240, 100, 40);
	GUI_SetFont(&GUI_FontSegoeUI15);
	GUI_DispStringAt("SPECIAL FOR /RA/!!",180, 156);
	GUI_EnableAlpha(0);
  while(1) {
	
			}
}

/*************************** End of file ****************************/
