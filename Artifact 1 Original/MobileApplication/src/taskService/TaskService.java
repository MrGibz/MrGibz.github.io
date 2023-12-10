package taskService;
import java.util.ArrayList;
import java.util.List;

public class TaskService {
	
	private List<Task> tasks = new ArrayList<>();
	
	//adds task unless taskID already exists
	public boolean add(Task task) {
		
		boolean taskExists = false;
		//if task exists, return true
		for (Task t: tasks) {
			
			if(t.equals(task)) {
				
				taskExists = true;
				
			}
			
		}
		
		//if task is not in tasks, add task and return true
		if(!taskExists) {
			
			tasks.add(task);
			System.out.println("Task added successfully!");
			
			return true;
			
		}
		
		else {
			
			System.out.println("Task already exists.");
			
			return false;
			
		}
		
	}

	//deletes task by taskID
	public boolean deleteTask(String taskID) {
		
		for (Task taskList: tasks) {
			
			if (taskList.getTaskID().equals(taskID)) {
				
				//delete task from taskList
				return tasks.remove(taskList);
				
			}
			
		}
		
		return false;
		
	} 
	
	//updates task with name and description
	public boolean updateTask(String taskID, String taskName, String taskDescription) {
		
		for (Task taskList:tasks) {
			
			if (taskList.getTaskID().equals(taskID)) {
				
				if(!(taskName == null) && taskName.length() < 21) {
					
					taskList.setTaskName(taskName);
					System.out.println("task name updated!");
					
				}
				
				if (!(taskDescription == null) && taskDescription.length() < 31) {
					
					taskList.setTaskDescription(taskDescription);
					System.out.println("task description updated!");
					
				}
				
			return true;	
			
			}
			
		}
		
		return false;
		
	}
	
	
}
