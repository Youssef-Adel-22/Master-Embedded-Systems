/* Linker Script cortexM3
   Eng.Youssef Adel
*/

MEMORY
{
	flash(RX) : ORIGIN = 0X08000000, LENGTH = 128K
	sram(RWX) : ORIGIN = 0X20000000, LENGTH =20K
}

SECTIONS
{
	.text :
	{
		*(.vectors*)
		*(.text*)
		*(.rodata)
		_E_text = . ;
		
	}>flash
	.data :
	{
		_S_data = . ;
		*(.data*)
		_E_data = . ;
	}> sram AT> flash
	.bss :
	{
		_S_bss = . ;
		*(.bss*)
		_E_bss = . ;
		. = ALIGN (0X4);
		
		_stack_top = . +0x1000 ;
	}>sram
}