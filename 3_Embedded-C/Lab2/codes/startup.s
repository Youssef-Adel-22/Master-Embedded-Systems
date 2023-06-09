/* 	Startup script CortexM3
	Eng.Youssef Adel*/

.section .vectors

.word 0x20001000
.word _reset
.word vector_handler 	/* NMI */
.word vector_handler 	/*HardFault*/
.word vector_handler 	/*MemoryMange*/
.word vector_handler 	/*BusFault*/
.word vector_handler 	/*UsageFault*/
.word vector_handler 	/*RESERVED*/
.word vector_handler 	/*SVCall*/
.word vector_handler 	/*DebugMonitor*/
.word vector_handler 	/*RESERVED*/
.word vector_handler 	/*PendSV*/
.word vector_handler 	/*SysTick*/
.word vector_handler 	/*IRQ0*/
.word vector_handler 	/*IRQ1*/
.word vector_handler 	/*IRQ2*/
.word vector_handler 	/*IRQ3*/

.section .text
_reset:
	bl main
	bl .
	
.thumb_func

vector_handler:
	bl _reset