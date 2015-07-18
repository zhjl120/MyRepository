package com.dex.spring.scope;

import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

import com.dex.spring.autowire.Address;
import com.dex.spring.autowire.Person;

public class Main {

	public static void main(String[] args) {
		
		ApplicationContext ctx = new ClassPathXmlApplicationContext("beans-relation.xml"); 
	
	//	Address add = (Address)ctx.getBean("address");
	//	System.out.println(add);
		
		Address add = (Address)ctx.getBean("address2");
		System.out.println(add);
		
		add = (Address)ctx.getBean("address3");
		System.out.println(add);
		
		Person person =(Person)ctx.getBean("person");
		System.out.println(person);
	}

}
