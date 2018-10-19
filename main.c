#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include "timer.h" /* include peripheral declarations */
/*OUTPUT COMPARE.  Programa que realiza una 
 señal Cuadrada por el PIN del PTA0 con 
 ciclo de trabajo del 50% y con f variable 
 */

unsigned char VarAncho;

void main(void) {
  SOPT1_COPE=0;
  PTADD_PTADD0=1;  //Canal 0 del TPM  
  PTBDD_PTBDD7=1;  // LED PARA VISUALIZAR
  PTBD_PTBD7=0;
	init_timer();
	init_inputCapture();
  for(;;) {
	  periodo(segundo);
	  PTBD_PTBD7=~PTBD_PTBD7;
	  } 
  /* please make sure that you never leave main */
}

