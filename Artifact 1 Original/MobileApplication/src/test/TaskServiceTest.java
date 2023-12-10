package test;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

import taskService.Task;
import taskService.TaskService;

class TaskServiceTest {
	//tests the add function of TaskService to ensure that it properly adds a new task. also ensures a second task with same ID cannot be added.
	@Test
	void testAdd() {
		TaskService taskService = new TaskService();
		Task task = new Task("1111111111", "Go to beach.", "Go to beach and code.");
		taskService.add(task);
		assertTrue(task.getTaskID().equals("1111111111"));
		assertTrue(task.getTaskName().equals("Go to beach."));
		assertTrue(task.getTaskDescription().equals("Go to beach and code."));
		Task task2 = new Task("1111111111", "Go to beach.", "Go to beach and code.");
		taskService.add(task2);
	}
	//ensures deleteTask functions properly by deleting task based on taskID
	@Test
	void testDeleteTask() {
		
		TaskService taskService = new TaskService();
		Task task = new Task("1111111111", "Go to the beach.", "Go to the beach and code.");
		taskService.add(task);
		assertTrue(taskService.deleteTask("1111111111"));
		
	}
	//checks that updateTask works correctly. updates task by taskID
	@Test
	void testUpdateTask() {
		TaskService taskService = new TaskService();
		Task task = new Task("1111111111", "Go to the beach.", "Go to the beach and code.");
		taskService.add(task);
		assertTrue(taskService.updateTask("1111111111", "Leave the beach.", "Get pub sub and go home."));
	}

}
 