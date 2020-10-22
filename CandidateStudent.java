package exam;
//18621819
import java.util.GregorianCalendar;
import java.util.Calendar;
import java.text.SimpleDateFormat;


public class CandidateStudent {
	private String name;
	private GregorianCalendar date;
	private Double success;
	
	//експлицитен конструктор
	public CandidateStudent (String name, Double success, GregorianCalendar date){
		this.name = name;
		this.date = date;
	    this.success = success;
	}
	
	//четене на полета
	public String getName(){
	     return name;
	}
	
	public GregorianCalendar getDate(){
	     return date;
	}
	
	public Double getSuccess(){
	     return success;
	}
	
	//стрингова интерперетация
	@Override
	public String toString(){
		SimpleDateFormat format = new SimpleDateFormat("dd-MM-yyyy");
		format.setCalendar(date);
		Calendar cal = null;
		String result = format.format(cal.getTime());
		
		return "CandidateStudent{" +
		     "name='" + name + '\'' +
		     ", date='" + result + '\'' +
		     ", success='" + success + '\'' +
		     '}';
	}
	
	
	
	
	
	
}

