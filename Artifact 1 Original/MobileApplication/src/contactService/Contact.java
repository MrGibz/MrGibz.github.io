package contactService;
import java.lang.Comparable;

public class Contact {
	
	public String contactID, firstName, lastName, number, address;
	
	//private final String contactID = ;
	
	private Contact() {
		
		this.contactID = "";
		
	}
	//constructor that checks parameters of contact info before assigning info to contact.
	public Contact(String contactID, String firstName, String lastName, String number, String address) {
		
		
		if (contactID == null || contactID.length() > 10) {
			
			throw new IllegalArgumentException("Invalid ID");
			
		}
		
		if (firstName == null || firstName.length() > 10) {
			
			throw new IllegalArgumentException("Invalid first name");
			
		}

		if (lastName == null || lastName.length() > 10) {
	
			throw new IllegalArgumentException("Invalid last name");
	
		}

		if (number == null || number.length() != 10) {
	
			throw new IllegalArgumentException("Invalid number");
	
		}

		if (address == null || address.length() > 30) {
	
			throw new IllegalArgumentException("Invalid address");
	
		}
		
		this.contactID = contactID;
		this.firstName = firstName;
		this.lastName = lastName;
		this.number = number;
		this.address = address;
		
		
	}
	//sets first name
	public void setFirstName (String firstName) {
	
		this.firstName = firstName;	
		
	}
	//sets last name
	public void setLastName (String lastName) {
		
		this.lastName = lastName;
		
	}
	//sets number
	public void setNumber (String number) {
		
		this.number = number;
		
	}
	//sets address
	public void setAddress (String address) {
		
		this.address = address;
		
	}
//gets id
	public String getContactID() {
		
		return contactID;
		
	}
	//gets first name
	public String getFirstName() {

		return firstName;
		
	}
	//gets last name
	public String getLastName() {
		
		return lastName;
		
	}
	//gets number
	public String getNumber() {
		
		return number;
		
	}
	//gets address
	public String getAddress() {
		
		return address;
		
	}

	
	//used in ContactService add contact function. checking to make sure contactID is not duplicated
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
        
        Contact duplicate = (Contact) same;
        
        
        if(contactID == null) {
        	
            if(duplicate.contactID != null) {
                
                return false;
            }    
        }
        
        else if (!contactID.equals(duplicate.contactID)) {
        	
            return false;
            
        }
        
        return true;
    
    }
    
}


