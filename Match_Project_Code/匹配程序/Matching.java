package json_Dealth;

public class Matching {

	public void Init(Student[] Stu,Department[] Dept,Txt_Translate TT)
	{
		TT.ReadTxt();
		for(int i = 0;i<300;i++)
		{
			Stu[i].initStudent(TT.reFreeTime(i), TT.reStuNo(i), TT.reStuAppDept(i), TT.reStuTags(i));
			Stu[i].translate(Stu[i].reFreeTime());

		}
		for(int i = 0;i<Dept.length;i++)
		{
			Dept[i].initDepartment(TT.reWorkTime(i), TT.reDeptMemLim(i), TT.reDeptNo(i), TT.reDeptTags(i));
			Dept[i].translate(Dept[i].reWorkTime());
		}
		
	}
	
	public static void main(String[] args)
	{
		Department[] Dept = new Department[20];
		Student [] Stu = new Student[300];
		for(int i = 0;i<300;i++)
		{
			Stu[i] = new Student();
		}
		for(int i =0;i<20;i++)
		{
			Dept[i] = new Department();
		}
		Matching M = new Matching();
		Txt_Translate TT = new Txt_Translate();
		M.Init(Stu, Dept,TT);
		//M.MatchStuChoice(Stu,Dept);
		M.MatchStuChoiceAvg(Stu,Dept);
		TT.WriteTxt(Stu, Dept);
	}
	void MatchStuChoice(Student[] Stu,Department[] Dept){
		int [] MaxM = new int[20];
		for(int i =0;i<20;i++)
		{
			MaxM[i] = Dept[i].reMaxM();
		}
		for(int i =0;i<300;i++)
		{
			 String [] Mid = new String[5];
			 Mid = Stu[i].reAppDept();
			 for(int j = 0;j < 5;j++)
			 {
				 if(Mid[j]!=null)
				 {
				 for(int k = 0;k<20;k++)
				 {
					 if(Mid[j].equals(Dept[k].reNum()) == true)
					 {
						 if(MaxM[k] >0)
						 {
							 if(isAllowTime(Dept[k].reWorkTimeIntBeg(),Dept[k].reWorkTimeIntFin(),Stu[i].reFreeTimeIntBeg(),Stu[i].reFreeTimeIntFin())==true)
							 {								 
									Dept[k].getStuId(Stu[i].reNum());
									 MaxM[k]--;
									 Stu[i].isAdd();
									 break;
							 }
						 }
					 }
					 
				 }
				 }
				 else
				 {
					 break;
				 } 
			 }		
		}
	
		
		
	}
	
	
	void MatchStuChoiceAvg(Student[] Stu,Department[] Dept)
	{
		int[][] midS = new int[20][300];							//备选名单[部门][人员]
		String [] selectDept = new String[5];
		String [] need  = new String[13];
		String [] interest = new String[13];
		int [] MaxM = new int[20];										//限选人数
		for(int i =0;i<20;i++)
		{
			MaxM[i] = Dept[i].reMaxM();
		}
		int [] lens = new int [20];
		for(int i =0;i<5;i++)
		{ 
			midS = init_double();
			lens = init();
			for(int j = 0;j<300;j++)
		{
			selectDept = Stu[j].reAppDept();
			if(selectDept[i]!=null)
			{
				for(int k = 0;k<20;k++)
				 { 	
				 boolean isOk = false;
				 		if(isOk == true)
				 			break;
				 		else if(selectDept[i].equals(Dept[k].reNum()) == true)
					 {
						 if(MaxM[k] >0)											//判断人员是否超员
						 {						
								 if(isAllowTime(Dept[k].reWorkTimeIntBeg(),Dept[k].reWorkTimeIntFin(),Stu[j].reFreeTimeIntBeg(),Stu[j].reFreeTimeIntFin())==true)	//判断时间是否不一致						 
								 {
									midS[k][lens[k]++] = j;			//放入中立数组，判断兴趣
									 interest = Stu[j].reInterest();
									 need = Dept[k].reNeed();
									 for(int need_I = 0;need_I<need.length;need_I++)
									 {
										 if(need[need_I] == null||isOk == true)
											 break;
										 else 
										 {
											 for(int interest_I = 0;interest_I <interest.length;interest_I++)
											 { 
												 if(need[need_I].equals(interest[interest_I])==true)				//存在相同兴趣，直接入选
												 {
													 Dept[k].getStuId(Stu[j].reNum());			
													 MaxM[k]--;
													 Stu[j].isAdd();
													 lens[k]--;
													 midS[k][lens[k]] = -1;											//清除在midS中的数据
													 isOk = true;
													 Stu[j].initFreeTime(Dept[k].reWorkTimeIntBeg(),Dept[k].reWorkTimeIntFin(),Stu[j].reFreeTimeIntBeg(),Stu[j].reFreeTimeIntFin());															//修改Student的Freetime
													 break;
												 }
												 else
												 {
													 continue;
												 }
											 }
										 }
									 }
								 }
						 }
					 }
					 
				 }
				 }
			else
				continue;
		}
			for(int j =0;j<20;j++)
		{
			for(int k =0;k<15;k++)
			{
				if(midS[j][k]==-1)
					break;
				else if(MaxM[j]>0)
				{
					Dept[j].getStuId(Stu[midS[j][k]].reNum());
					MaxM[j]--;
					Stu[midS[j][k]].isAdd();
					Stu[midS[j][k]].initFreeTime(Dept[j].reWorkTimeIntBeg(),Dept[j].reWorkTimeIntFin(),Stu[midS[j][k]].reFreeTimeIntBeg(),Stu[midS[j][k]].reFreeTimeIntFin());
				}
				else
					break;
			}
		}
		
	}
		
	}
	int [] init()
	{
		int [] intS = new int[20];
		for(int i =0;i<20;i++)
		{
			intS[i] = 0;
		}
		return intS;
	}
	int [][] init_double()
	{
		int[][] midS = new int[20][300];
		for(int i = 0;i<20;i++)
			for(int j = 0;j<300;j++)
				{
				midS[i][j] = -1;
				}
		return midS;
	}
	
	
	boolean isAllowTime(int [][] workTimeIntBeg,int [][] workTimeIntFin,int [][] stuFreeTimeBeg,int[][] stuFreeTimeFin)
	{
		boolean isOk = false;
		for(int i = 0;i<7;i++)
		{
			for(int j = 0;j<21;j++)
			{
				if(workTimeIntBeg[i][j]==0||workTimeIntFin[i][j]==0)
				{
					break;
				}
				for(int k = 0;k<40;k++)
				{
					if(workTimeIntBeg[i][j]>=stuFreeTimeBeg[i][k]&&workTimeIntFin[i][j]<=stuFreeTimeFin[i][k])
					{
						isOk=true;
						break;
					}
					if(stuFreeTimeBeg[i][k]==0||stuFreeTimeFin[i][k]==0)
					{
						return false;
					}
					else
						continue;
				}
			}
		}
		return isOk;
	}
		
	
	/*void printFinnal(Student[] Stu,Department[] Dept)
	{
		String [] print = new String[15];
		
		for(int i = 0 ; i<20;i++)
		{
			print = Dept[i].reGetStudentId();
			for(int j = 0;j<print.length;j++)
			{
				if(print[j] == null)
					break;
				else
				System.out.println(print[j]);
			}
		}
	}*/

	
}
