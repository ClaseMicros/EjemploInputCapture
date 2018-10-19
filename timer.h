/*
 * timer.h
 *   Driver para Timer
 *  Created on: Oct 11, 2018
 *      Author: Jaime Hueso
 */
#include "derivative.h" /* include peripheral declarations */
#include "hidef.h" 

#ifndef TIMER_H_
#define TIMER_H_


//#define INPUTCAPTURECH1

//Declaracion de Variables Globales
//Declaracion de Defines Constantes
//Declaracion de Prototipos de las funciones

extern unsigned char VarAncho;  

#define segundo 62500/2

void init_timer(void);
void periodo(unsigned int tiempo);
void init_inputCapture(void);



#endif /* TIMER_H_ */
