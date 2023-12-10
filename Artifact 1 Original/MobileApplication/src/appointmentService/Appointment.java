package appointmentService;

import java.util.Date;

import taskService.Task;

public class Appointment {
	
	public String aptID, aptDesc;
	Date aptDate;
	
	private Appointment() {
		
		this.aptID = "";
		
	}
	
	public Appointment(String aptID, Date aptDate, String aptDesc) {
		
		if (aptID == null || aptID.length() > 10) {
			
			throw new IllegalArgumentException("Invalid ID.");
			
		}
		
		if (aptDate.before(new Date()) || aptDate == null) {
			
			throw new IllegalArgumentException("Date is invalid.");
			
		}
		
		if (aptDesc == null || aptDesc.length() > 50) {
			
			throw new IllegalArgumentException("Invalid description.");
			
		}
		
		this.aptID = aptID;
		this.aptDate = aptDate;
		this.aptDesc = aptDesc;
		
	}

	public Object getAptID() {

		return aptID;
		
	}

	public Object getAptDate() {
		
		return aptDate;
		
	}

	public Object getAptDesc() {
		
		return aptDesc;
		
	}
	
	//used in AppointmentService to add apt function. checking to make sure aptID is not duplicated
			@Override
		    public boolean equals (Object same) {
		        
		        if(this == same) {
		        	
		            return true;
		            
		        }
		        
		        if(same == null) {
		        	
		            return false;
		            
		        }
		        
		        if(getClass() != same.getClass()) {
		        	
		            return false;
		            
		        }
		        
		        Appointment duplicate = (Appointment) same;
		        
		        
		        if(aptID == null) {
		        	
		            if(duplicate.aptID != null) {
		                
		                return false;
		            }    
		        }
		        
		        else if (!aptID.equals(duplicate.aptID)) {
		        	
		            return false;
		            
		        }
		        
		        return true;
		    
		    }

}
