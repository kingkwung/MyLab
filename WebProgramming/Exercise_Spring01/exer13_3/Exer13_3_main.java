package mySpring_exer13_3;

import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class Exer13_3_main {
	public static void main(String[] args){
		ApplicationContext context = new ClassPathXmlApplicationContext("/applicationContext_exer13_3.xml");

		Employee13_3 emp01 = (Employee13_3)context.getBean("employee1");
		Employee13_3 emp02 = (Employee13_3)context.getBean("employee2");

		emp01.printInfo();
		emp02.printInfo();
	}
}
