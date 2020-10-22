package exam;
import java.util.List;

public class Main {

	public static void main(String[] args) {
		StudentGroup stGroup = new StudentGroup("infile.txt","outfile.txt");
		stGroup.ReadWrite(true);
		stGroup.toString();
		List<Student> ls = stGroup.SortByFN();
		stGroup.ReadWrite(false);

	}	

}
