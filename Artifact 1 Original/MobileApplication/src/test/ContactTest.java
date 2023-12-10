package test;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import contactService.Contact;

class ContactTest {
	//tests constructor and getters are working correctly
	@Test
	void testContact() {

		Contact contact = new Contact("1111111111", "Garrett", "Gibson", "0123456789", "999 Streetsville");
		assertTrue(contact.getContactID().equals("1111111111"));
		assertTrue(contact.getFirstName().equals("Garrett"));
		assertTrue(contact.getLastName().equals("Gibson"));
		assertTrue(contact.getNumber().equals("0123456789"));
		assertTrue(contact.getAddress().equals("999 Streetsville"));
		
	}
	//tests that illegal argument exception is thrown when contactID is not within specified parameters of contact class
	@Test
	void testContactIDOutOfParam() {
		
		Assertions.assertThrows(IllegalArgumentException.class, () -> {
			
			new Contact("11111111111", "Garrett", "Gibson", "0123456789", "999 Streetsville");
			
		});
		
	}
	//tests that illegal argument exception is thrown when firstName is not within specified parameters of contact class
	@Test
	void testContactFirstNameOutOfParam() {
		
		Assertions.assertThrows(IllegalArgumentException.class, () -> {
			
			new Contact("1111111111", "Garrettistheman", "Gibson", "0123456789", "999 Streetsville");
			
		});
		
	}
	//tests that illegal argument exception is thrown when lastName is not within specified parameters of contact class
	@Test
	void testContactLastNameOutOfParam() {
		
		Assertions.assertThrows(IllegalArgumentException.class, () -> {
			
			new Contact("1111111111", "Garrett", "Gibsonisadudebro", "0123456789", "999 Streetsville");
			
		});
		
	}
	//tests that illegal argument exception is thrown when phone number is not within specified parameters of contact class
	@Test
	void testContactNumberOutOfParam() {
		
		Assertions.assertThrows(IllegalArgumentException.class, () -> {
			
			new Contact("1111111111", "Garrett", "Gibson", "012345678", "999 Streetsville");
			
		});
		
	}
	//tests that illegal argument exception is thrown when address is not within specified parameters of contact class
	@Test
	void testContactAddressOutOfParam() {
		
		Assertions.assertThrows(IllegalArgumentException.class, () -> {
			
			new Contact("1111111111", "Garrett", "Gibson", "0123456789", "whereareyouandimsosorryicannotsleepicannotdreamtonightineedsomebodyandalways");
			
		});
		
	}

}
