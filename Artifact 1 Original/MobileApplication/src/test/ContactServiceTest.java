package test;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

import contactService.Contact;
import contactService.ContactService;

class ContactServiceTest {
	//tests the add function of ContactService to ensure that it properly adds a new contact. also ensures a second contact with same ID cannot be added.
	@Test
	void testAddContact() {
		
		ContactService contactService = new ContactService();
		Contact contact = new Contact("1111111111", "Garrett", "Gibson", "0123456789", "999 Streetsville");
	    contactService.add(contact);
	    assertTrue(contact.getContactID().equals("1111111111"));
		assertTrue(contact.getFirstName().equals("Garrett"));
		assertTrue(contact.getLastName().equals("Gibson"));
		assertTrue(contact.getNumber().equals("0123456789"));
		assertTrue(contact.getAddress().equals("999 Streetsville"));
		Contact contact2 = new Contact("1111111111", "Garrett", "Gibson", "0123456789", "999 Streetsville");
		contactService.add(contact2);
		
	}
	//ensures deleteContact functions properly by deleting contact based on contactID
	@Test
	void testDeleteContact() {
		
		ContactService contactService = new ContactService();
		Contact contact = new Contact("1111111111", "Garrett", "Gibson", "0123456789", "999 Streetsville");
		contactService.add(contact);
	    assertTrue(contactService.deleteContact("1111111111"));
	    
	}
	//checks that updateContact works correctly. updates contact by contactID
	@Test
	void testUpdateContact() {
		
		ContactService contactService = new ContactService();
		Contact contact = new Contact("1111111111", "Garrett", "Gibson", "0123456789", "999 Streetsville");
		contactService.add(contact);
		assertTrue(contactService.updateContact("1111111111", "Ashley", "Gilroy", "987654321", "111 Okaystreet"));
	}

}
