package json_Dealth;

public class Student {
	
	private String[] freeTime = new String[30];
	private String num = new String();
	private String[] appDept = new String[30];
	private String[] tags = new String[30];
	private boolean isAdt = false;
	public  void initStudent(String num)
	{
		this.num = num;
	}
	public  void initStudent(String[] freeTime,String num,String[] appDept,String[] tags){
		 System.arraycopy(freeTime, 0, this.freeTime, 0, freeTime.length);  	//src - Դ���顣
		 this.num = num;														//srcPos - Դ�����е���ʼλ�á�
		 System.arraycopy(appDept, 0, this.appDept, 0, appDept.length);			//dest - Ŀ�����顣
		 System.arraycopy(tags, 0, this.tags, 0, tags.length);					//destPos - Ŀ�������е���ʼλ�á�
		 																		//length - Ҫ���Ƶ�����Ԫ�ص�����
	}
	public String[] reInterest()
	{
		return tags;
	}
	public String[] reAppDept()
	{
		return appDept;
	}
	public String reNum()
	{
		return num;
	}
	public String[] reFreeTime()
	{
		return freeTime;
	}
	public void isAdd()
	{
		isAdt = true;
	}
	public boolean isAddmit()
	{
		return isAdt;
	}
	/*public static void main(String[] args)
	{
		Student Stu = new Student();
		String[] n = new String[20];
		for(int i =0;i<2;i++)
		{
			n[i] = "0";
		}
		Stu.initStudent(n, n[0], n, n);
	}*/
}