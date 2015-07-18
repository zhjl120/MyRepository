package com.dex.spring.beans.collections;

import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class Main {

	public static void main(String[] args) {
		
		ApplicationContext ctx = new ClassPathXmlApplicationContext("applicationContext.xml"); 
		Person person = (Person) ctx.getBean("person3");
		System.out.println(person);
	
		NewPerson per = (NewPerson) ctx.getBean("newPerson");
		System.out.println(per);
		
	//	Person per2 = (Person) ctx.getBean("person4");
	//	System.out.println(per2);
	}

}
