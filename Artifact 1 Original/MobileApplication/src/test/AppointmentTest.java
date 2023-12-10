package test;

import static org.junit.jupiter.api.Assertions.*;

import java.util.Date;

import org.junit.jupiter.api.Assertions; 
import org.junit.jupiter.api.Test;

import appointmentService.Appointment;

class AppointmentTest {

	@Test
	void testApt() {
		//tests constructor and getters are working correctly
		Date date = new Date();
		Appointment Appointment = new Appointment("1234567890", date , "Karen's hair appointment.");
		assertTrue(Appointment.getAptID().equals("1234567890"));
		assertTrue(Appointment.getAptDate().equals(date));
		assertTrue(Appointment.getAptDesc().equals("Karen's hair appointment."));
		
	}
	//tests that illegal argument exception is thrown when aptID is not within specified parameters of apt class
	@Test
	void testAppointmentIDOurOfParam() {
		
		Assertions.assertThrows(IllegalArgumentException.class, () -> {
			Date date2 = new Date();
			new Appointment("!!!!!!!!!!!", date2, "hi");
			
		});
		
	}
	//tests that illegal argument is thrown when date is out of parameters
	@Test
	void testAppointmentDateOutOfParam() {
		
		Assertions.assertThrows(IllegalArgumentException.class, () -> {
		Date date2 = new Date();	
		date2.setTime(1);
		new Appointment("!!!!!!!!!!", date2 , "hi");
			
		});
	}
	//tests that illegal argument exception is thrown when aptDescription is not within specified parameters of apt class
	@Test
	void testAppointmentDescriptionOutOfParam() {
		
		Assertions.assertThrows(IllegalArgumentException.class, () -> {			
		Date date2 = new Date();
		new Appointment("!!!!!!!!!!", date2 , "Karen sucks her hair is gross and ugly. I want to throat punch her hair to make my life better nice thanks!" );
			
		});
	}

}
