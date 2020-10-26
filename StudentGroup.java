package exam;

import java.util.*;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.text.SimpleDateFormat;

public class StudentGroup implements StudentInterface{
	private static final Collection<? extends Student> EmpSet = null;
	//Скрити полета:
	private String name;
	private String fileIn;
	private String fileOut;
	private Set<Student> list;
	
	//Експлицитен конструктор
	public StudentGroup(String fileIn,String fileOut){
		this.fileIn = fileIn;
		this.fileOut = fileOut;
	}
	
	public List<Student> SortByFN(){

		List<Student> empList = new LinkedList<Student>(EmpSet);
		class StudentComparator implements Comparator<Student> {
            public int compare(Student e1, Student e2) {
                return e1.getDate().compareTo(e2.getDate());
            }
        }
		
		Collections.sort(empList , new StudentComparator ());		
		return empList;
	};
		
	public void ReadWrite(boolean read){
		if(read){
			BufferedReader reader;
			int row=0;
			try {
				reader = new BufferedReader(new FileReader(this.fileIn));
				String line = reader.readLine();
				while (line != null) {
					if(row == 0)
						this.setName(line);
					else{
						String[] splited = line.split("\\s");
						SimpleDateFormat format = new SimpleDateFormat("dd/MM/yyyy");
						Date date = format.parse(splited[2]);
						GregorianCalendar birth = new GregorianCalendar();
						birth.setTime(date);						
					
						Student st = new Student(splited[0],splited[1],splited[2],birth);
						list.add(st);
					}
					row ++;
					line = reader.readLine();
				}
				reader.close();
			} catch (IOException e) {
				e.printStackTrace();
			}	
		}else{
			FileWriter fw = new FileWriter(fileOut);
			fw.write(name);
			for (Student st : list) {
				String row = String.format("%s %f %d %s", st.getName(),st.getSuccess(),st.getFn(),st.getDate());
				Set<Student> aList;
				aList.add(row); 			
			}		
			fw.close();	
			
		}
	}	

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}
	
	//стрингова интерперетация
	@Override
	public String toString(){
		Strint cOut = new String();
		cOut = "Group" + name;
		for (Student st : list) 
			cOut += st.toString();
		return cOut;
	}		
	
	
}
