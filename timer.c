/*
 * timer.c
 *    Driver para Output compare
 *  Created on: Oct 11, 2018
 *      Author: Jaime Hueso
 */
#include "timer.h" /* include peripheral declarations */


void init_timer(void)
{
	TPMMOD=0xFFFF;  // Maxima cuenta del Contador.
	TPMC0V=0x0000;  //  Valor de Comparacion.
	#ifndef INPUTCAPTURECH1
		TPMC1V=0x0000;
		TPMC1SC=0x4C;
	#endif		
	
	
	TPMC0SC=0x14;  //OUTPUT compare / Toggle./Consulta
	//TPMC0SC=TPMC0SC|TPMC0SC_ELS0A_MASK | TPMC0SC_MS0A_MASK ;
	TPMSC=0x0F;  // BusClk , Preescaler=128, Consulta		
}

void periodo(unsigned int tiempo)
{
//TPMC0V=TPMC0V+tiempo;
while(!TPMC0SC_CH0F);  // Checar si el tiempo ya paso
TPMC0SC_CH0F=0;  // Apagar Bandera
TPMC0V=TPMC0V+tiempo;
}

void init_inputCapture(void)
{
	TPMC1V=0x0000;  // Inicializar para primer valor.
	TPMC1SC=0x4C; // Input Capture / IRQ/ Falling/Rising
}


interrupt 6 void anchodepulso(void)
{
unsigned int transicion=0x0000;
static unsigned char flag=0;
DisableInterrupts;
TPMC1SC_CH1F=0; // Borra la bandera del TPM 
if (flag==0)
	{
	transicion=TPMC1V;  // Respalda el valor 1IRQ
	flag=1;   // Bandera para detectar 2IRQ
	}
else 
	{
	VarAncho=TPMC1V-transicion;  //Calcula Ancho
	transicion=TPMC1V;  // Preparar para el siguiente
	}
EnableInterrupts;
}
