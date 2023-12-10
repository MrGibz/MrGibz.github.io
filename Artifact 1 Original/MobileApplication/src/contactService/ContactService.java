package contactService;

import java.util.ArrayList;
import java.util.List;

public class ContactService {
	
	private List<Contact> contacts = new ArrayList<>();
	
	//adds contact unless contactID already exists
	public boolean add(Contact contact) {
	    
	    
	    boolean contactExists = false;
	    //if contact exists, return true
	    for(Contact c: contacts) {
	    	
	        if(c.equals(contact)) {
	        	
	            contactExists = true;
	            
	        }
	    }
	    
	    //if the contact is not in contacts, add contact and return true
	    if(!contactExists) {
	    	
	        contacts.add(contact);
	        
	        System.out.println("Contact added successfully!");
	        
	        return true;
	    }
	    
	    else {
	    	
	        System.out.println("Contact already exists.");
	        
	        return false;
	        
	    }
	    
	}
	//deletes contact by contactID
	public boolean deleteContact(String contactID) {
		
		for (Contact contactList: contacts) {
			//if contactList contains contact with contactID
			if (contactList.getContactID().equals(contactID)) {
				
				//System.out.println("Contact removed.");
				//delete contact from contactList
				return contacts.remove(contactList);
					
			}
		
		}
		
		return false;
		
	}
	//updates contact with contactID, ensuring specific parameters are met as specified in rubric.
	public boolean updateContact(String contactID, String firstName, String lastName, String number, String address) {
		
		for (Contact contactList:contacts) {
			
			if (contactList.getContactID().equals(contactID)) {
			
				if(!(firstName == null) && firstName.length() < 11) {
					
					contactList.setFirstName(firstName);
					System.out.println("Name updated!");
					
				}
				
				if(!(lastName == null) && lastName.length() < 11) {
					
					contactList.setLastName(lastName);
					//System.out.println("Name updated!");
				}
				
				if(!(number == null) && number.length() == 10) {
					
					contactList.setNumber(number);
					
				}
				
				if(!(address == null) && address.length() < 31) {
					
					contactList.setAddress(address);
					
				}
				
				//System.out.println("true");
				return true;
				
				
			
			}
			
		}
		
		//System.out.println("test");
		
		return false;
		
	}
	
	
}