/*
 * Utils.h
 *
 * Created: 6/17/2023 1:56:27 PM
 *  Author: Harby
 */ 


#ifndef UTILS_H_
#define UTILS_H_
#define Read_bit(PINx,bit) ((PINx>>bit)&1)
#define Set_bit(portx,bit) (portx|=(1<<bit))
#define Clear_bit(portx,bit) (portx&=~(1<<bit))
#define Toggle_bit(portx,bit) (portx^=(1<<bit))


#endif /* UTILS_H_ */