package taskService;

import contactService.Contact;

public class Task {
	
	public String taskID, taskName, taskDescription;
	
	private Task() {
		this.taskID = "";
	}
	//constructor that checks parameters of task info before assigning info to task.
	public Task(String taskID, String taskName, String taskDescription) {
		
		if (taskID == null || taskID.length() > 10) {
			
			throw new IllegalArgumentException("Invalid ID.");
			
		}
		
		if (taskName == null || taskName.length() > 20) {
			
			throw new IllegalArgumentException("Invalid name.");
			
		}
		
		if (taskDescription == null || taskDescription.length() > 50) {
			
			throw new IllegalArgumentException("Invalid description length.");
			
		}
		
		this.taskID = taskID;
		this.taskName = taskName;
		this.taskDescription = taskDescription;
		
	}
	//name setter
	public void setTaskName(String taskName) {
		
		this.taskName = taskName;
		
	}
	//description setter
	public void setTaskDescription(String taskDescription) {
		
		this.taskDescription = taskDescription;
		
	}
	//ID getter
	public String getTaskID() {
		
		return taskID;
		
	}
//name getter
	public String getTaskName() {

		return taskName;
		
	}
//description getter
	public String getTaskDescription() {
		
		return taskDescription;
		
	}
	
	//used in TaskService add task function. checking to make sure taskID is not duplicated
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
	        
	        Task duplicate = (Task) same;
	        
	        
	        if(taskID == null) {
	        	
	            if(duplicate.taskID != null) {
	                
	                return false; 
	            }    
	        }
	        
	        else if (!taskID.equals(duplicate.taskID)) {
	        	
	            return false;
	            
	        }
	        
	        return true;
	    
	    }

}
