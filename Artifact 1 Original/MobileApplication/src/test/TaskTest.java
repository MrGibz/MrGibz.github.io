package test;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import taskService.Task;

class TaskTest {

	@Test
	void testTask() {
		//tests constructor and getters are working correctly
		Task task = new Task("1234567890", "Go to the beach!", "Today we will go to the beach.");
		assertTrue(task.getTaskID().equals("1234567890"));
		assertTrue(task.getTaskName().equals("Go to the beach!"));
		assertTrue(task.getTaskDescription().equals("Today we will go to the beach."));
		
	}
	//tests that illegal argument exception is thrown when taskID is not within specified parameters of task class
	@Test
	void testTaskIDOurOfParam() {
		
		Assertions.assertThrows(IllegalArgumentException.class, () -> {
			
			new Task("!!!!!!!!!!!", "Say hi", "hi");
			
		});
		
	}
	//tests that illegal argument exception is thrown when taskName is not within specified parameters of task class
	@Test
	void testTaskNameOutOfParam() {
		
		Assertions.assertThrows(IllegalArgumentException.class, () -> {
			
		new Task("!!!!!!!!!!", "123456789012345678901", "hi");
			
		});
	}
	//tests that illegal argument exception is thrown when taskDescription is not within specified parameters of task class
	@Test
	void testTaskDescriptionOutOfParam() {
		
		Assertions.assertThrows(IllegalArgumentException.class, () -> {
			
		new Task("!!!!!!!!!!", "Go to the beach!", "Today we will go to the beach and write code because why not bud!?");
			
		});
	}

}
