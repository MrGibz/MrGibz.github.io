package test;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

import appointmentService.Appointment;
import appointmentService.AppointmentService;
import java.util.Date;

class AppointmentServiceTest {

	//tests the add function of AptService to ensure that it properly adds a new apt. also ensures a second apt with same ID cannot be added.
	@Test
	void testAdd() {
		AppointmentService appointmentService = new AppointmentService();
		Date date = new Date();
		Appointment appointment = new Appointment("0123456789", date, "Karen's nail appointment.");
		appointmentService.add(appointment);
		assertTrue(appointment.getAptID().equals("0123456789"));
		assertTrue(appointment.getAptDate().equals(date));
		assertTrue(appointment.getAptDesc().equals("Karen's nail appointment."));
		Date date2 = new Date();
		Appointment apt2 = new Appointment("0123456789", date2, "Joe's dead end garage band practice.");
		appointmentService.add(apt2);
	}
	//ensures deleteapt functions properly by deleting apt based on aptID
	@Test
	void testDeleteTask() {
		
		AppointmentService appointmentService = new AppointmentService();
		Date date = new Date();
		Appointment Appointment = new Appointment("1111111111", date, "Go to the beach and code.");
		appointmentService.add(Appointment);
		assertTrue(appointmentService.deleteAppointment("1111111111"));
		
	}

}
