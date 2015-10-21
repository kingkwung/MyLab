package mySpring_exer13_1;

import org.springframework.context.*;
import org.springframework.context.support.*;

public class employeeMain {
	public static void main(String[] args){
		ApplicationContext context = new ClassPathXmlApplicationContext("/applicationContext_exer13_1.xml");
		
		employee emp1 = (employee)context.getBean("employee1");
		employee emp2 = (employee)context.getBean("employee2");
		employee emp3 = (employee)context.getBean("employee3");
		employee emp4 = (employee)context.getBean("employee4");
		
		
		emp1.printInfo();
		emp2.printInfo();
		emp3.printInfo();
		emp4.printInfo();


	}
	
}
