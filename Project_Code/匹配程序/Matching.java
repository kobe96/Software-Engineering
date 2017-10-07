package json_Dealth;

public class Matching {

	public void Init(Student[] Stu,Department[] Dept,Txt_Translate TT)
	{
		TT.ReadTxt();
		for(int i = 0;i<300;i++)
		{
			Stu[i].initStudent(TT.reFreeTime(i), TT.reStuNo(i), TT.reStuAppDept(i), TT.reStuTags(i));
		}
		for(int i = 0;i<Dept.length;i++)
		{
			Dept[i].initDepartment(TT.reWorkTime(i), TT.reDeptMemLim(i), TT.reDeptNo(i), TT.reDeptTags(i));
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
							 boolean isOver = false;
							 String [] stuFreeTime = new String[20];
							 String [] deptWorkTime = new String[5];
							 stuFreeTime = Stu[i].reFreeTime();
							 deptWorkTime = Dept[k].reWorkTime();
							 for(int l =0;l<deptWorkTime.length;l++)
							 {
								 if(deptWorkTime[l] == null)
								 {
									 Dept[k].getStuId(Stu[i].reNum());
									 MaxM[k]--;
									 Stu[i].isAdd();
									 break;
								 }
								 else if(isOver == true)
								 {
									 break;
								 }
								 else
								 {
									 for(int p = 0;p<stuFreeTime.length;p++)
									 {
										 if(deptWorkTime[l].equals(stuFreeTime[p])==true)
										 {
											 break;
										 }	 
									 }
									 isOver = true;
								 }
									 
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
		int[][] midS = new int[20][300];							//��ѡ����[����][��Ա]
		for(int i = 0;i<20;i++)
		for(int j = 0;j<300;j++)
		{
			midS[i][j] = -1;
		}
		String [] selectDept = new String[5];
		String [] need  = new String[13];
		String [] interest = new String[13];
		int [] MaxM = new int[20];										//��ѡ����
		for(int i =0;i<20;i++)
		{
			MaxM[i] = Dept[i].reMaxM();
		}
		int [] lens = new int [20];
		lens = init();
		for(int i =0;i<5;i++)
		{ 
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
						 if(MaxM[k] >0)											//�ж���Ա�Ƿ�Ա
						 {
							 boolean isOver = false;
							 String [] stuFreeTime = new String[20];
							 String [] deptWorkTime = new String[5];
							 stuFreeTime = Stu[j].reFreeTime();
							 deptWorkTime = Dept[k].reWorkTime();
							 for(int l =0;l<deptWorkTime.length;l++)		//�ж�ʱ���Ƿ�һ��
							 {	 
							
								 if(deptWorkTime[l] == null)
								 {
									 
									 midS[k][lens[k]++] = j;			//�����������飬�ж���Ȥ
									/* Dept[k].getStuId(Stu[j].reNum());
									 MaxM[k]--;
									 Stu[j].isAdd();
									 break;*/
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
												 if(need[need_I].equals(interest[interest_I])==true)				//������ͬ��Ȥ��ֱ����ѡ
												 {
													 Dept[k].getStuId(Stu[j].reNum());			
													 MaxM[k]--;
													 Stu[j].isAdd();
													 lens[k]--;
													 midS[k][lens[k]] = -1;											//�����midS�е�����
													 isOk = true;
													 break;
												 }
												 else
												 {
													 continue;
												 }
											 }
										 }
									 }
									 break;
									 
								 }
								 else if(isOver == true)
								 {
									 break;
								 }
								 else
								 {
									 for(int p = 0;p<stuFreeTime.length;p++)
									 {
										 if(deptWorkTime[l].equals(stuFreeTime[p])==true)
										 {
											 break;
										 }	 
									 }
									 isOver = true;
								 }
									 
							 }
						 }
					 }
					 
				 }
				 }
			else
				break;
		}
		
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
				}
				else
					break;
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
