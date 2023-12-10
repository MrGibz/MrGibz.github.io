package appointmentService;

import java.util.ArrayList;
import java.util.List;

public class AppointmentService {
	
	private List<Appointment> appointments = new ArrayList<>();
	
	//adds appt unless apptID already exists
	public boolean add(Appointment appointment) {
		
		boolean aptExists = false;
		
		//if apt exists, return true
		for (Appointment a: appointments) {
			
			if(a.equals(appointment)) {
				
				aptExists = true; 
				
			}
			
		}
		
		//if apt is not in appointments, add apt and return true
		if(!aptExists) {
			
			appointments.add(appointment);
			System.out.println("Appointment added successfully!");
			
			return true;
			
		}
		
		else {
			
			System.out.println("Appointment already exists.");
			
			return false;
			
		}
		
	}
	
	//delete apt by apt ID
	public boolean deleteAppointment(String aptID) {
		
		for (Appointment appointmentList: appointments) {
			
			if (appointmentList.getAptID().equals(aptID)) {
				//deletes apt from aptlist
				return appointments.remove(appointmentList);
				
			}
			
		}
		
		return false;
		
	}

}
