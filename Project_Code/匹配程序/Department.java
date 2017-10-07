package json_Dealth;

public class Department {

	private String[] workTime = new String[21];
	private String maxM = new String();
	private String num= new String();
	private String[] tags = new String[21];
	private String[] getStudentId = new String[15];
	private boolean isEmpty = true;
	public void initDepartment(String[] workTime,String maxM,String num,String[] tags)
	{
		 System.arraycopy(workTime, 0, this.workTime, 0, workTime.length);  	
		 this.num = num;														
		 this.maxM = maxM;		
		 System.arraycopy(tags, 0, this.tags, 0, tags.length);					 													
	}
	public int reMaxM()
	{
		int Max = Integer.parseInt(maxM);
		return Max;
	}
	public String reNum()
	{
		return  num;
	}
	public void getStuId(String Id)
	{
		isEmpty = false;
		for(int i =0;i<getStudentId.length;i++)
		{
			if(getStudentId[i] ==null)
			{
				getStudentId[i] = Id;
				break;
			}
		}
	}
	public String [] reWorkTime()
	{
		return workTime;
	}
	public String[] reGetStudentId()
	{
		return getStudentId;
	}
	public boolean isEmpty()
	{
		return isEmpty;
	}
	public String[] reNeed()
	{
		return tags;
	}
	
}
