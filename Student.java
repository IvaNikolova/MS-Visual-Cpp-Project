package exam;

import java.util.GregorianCalendar;

public class Student extends CandidateStudent{
	private String fn;
	
	//експлицитен конструктор
	public Student(String name, Double success, String fn , GregorianCalendar date, String splited)
    {
        super(name, success, date);
        this.fn = fn;
    }

	//четене членове
    public String getFn()
    {	
        return fn;
    }
    
    //сравнение за еквивалентност
    public boolean equals(Object d)
    {
        return this.fn.equals(((Student)d).fn);
    }
	
    //стрингова интерпетация
    public String toString()
    {
        return "Student{" +
                super.toString() +
                ", fn=" + fn +'\''+
                '}';
    }

}
