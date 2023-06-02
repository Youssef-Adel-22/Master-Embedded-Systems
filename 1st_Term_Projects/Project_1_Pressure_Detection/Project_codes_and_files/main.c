
#include "driver.h"
#include "state.h"
#include "main_algorithm.h"
#include "alarm_actuator.h"
#include "alarm_monitor.h"
#include "pressure_sensor.h"

void setup(){
//initialize pointers to functions
	
	Pressure_sensor_state_ptr = state(Pressure_sensor_init);
	Pressure_sensor_state_ptr();
	Main_Algorithm_state_ptr = state(Compare_Pressure_value);
	Alarm_Monitor_state_ptr = state(Alarm_OFF);
	Alarm_Actutor_state_ptr = state(Alarm_Actutor_init);
	Alarm_Actutor_state_ptr();
}
int main (){
	GPIO_INITIALIZATION();
	setup();

	while (1)
	{
		Pressure_sensor_state_ptr();
		Main_Algorithm_state_ptr();
		Alarm_Monitor_state_ptr();
	 	Alarm_Actutor_state_ptr();

}

	return 0;
}


