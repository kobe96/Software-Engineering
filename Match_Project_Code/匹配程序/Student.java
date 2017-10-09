package json_Dealth;

import java.util.Arrays;

public class Student {
	
	private int [][] freeTimeIntBeg = new int [7][40];						//[星期][数目]
	private int [][] freeTimeIntFin = new int [7][40];						//[星期][数目]
	private String[] freeTime = new String[21];
	private String num = new String();
	private String[] appDept = new String[30];
	private String[] tags = new String[30];
	private boolean isAdt = false;
	/*public  void initStuFreeTime(String[] freeTime,String[] workTime)
	{
		String [] midS = new String[100];
		for(int i = 0,len = 0;i<workTime.length;i++)
		{
			for(int j = 0;j<freeTime.length;j++)
			{
				if(freeTime[j] == null)
					break;
			if(freeTime[j].equals(workTime[i]) == true)
			{
				continue;
			}
			else
			{
				midS[len++] = freeTime[j];
			}
			}
		}

		this.freeTime = midS;
	}*/
	public  void initStudent(String[] freeTime,String num,String[] appDept,String[] tags){
		 System.arraycopy(freeTime, 0, this.freeTime, 0, freeTime.length);  	//src - 源数组。
		 this.num = num;														//srcPos - 源数组中的起始位置。
		 System.arraycopy(appDept, 0, this.appDept, 0, appDept.length);			//dest - 目标数组。
		 System.arraycopy(tags, 0, this.tags, 0, tags.length);					//destPos - 目标数据中的起始位置。
		 																		//length - 要复制的数组元素的数量
	}
	public void translate(String [] freeTime)
	{

		String [] midS = new String[4];
		int [] len = new int[7];
		for(int i = 0;i<7;i++)
		{
			len[i] = 0;
		}
		for(int i = 0;i<4;i++)
		{
			midS[i] = "";
		}
		for(int i = 0;i<freeTime.length;i++)
		{
			for(int c = 0;c<4;c++)
			{
				midS[c] = "";
			}
			if(freeTime[i] == null)
				break;
				
			else if(freeTime[i].charAt(0)=='M'&&freeTime[i].charAt(1)=='o'&&freeTime[i].charAt(2)=='n')
			{
				int begin = 0;
				for(int j = 4;;j++)
				{
					if(freeTime[i].charAt(j)==':')
					{
						begin = j;
						break;
					}
					else 
					{
						midS[0]+=freeTime[i].charAt(j);
					}
				}
				for(int j = begin+1;;j++)
				{
					if(freeTime[i].charAt(j)=='~')
					{
						begin = j;
						break;
					}
					else
					{
						midS[1]+=freeTime[i].charAt(j);
					}
				}
				for(int j = begin+1;;j++)
				{
					if(freeTime[i].charAt(j)==':')
					{
						begin = j;
						break;
					}
					else
					{
						midS[2]+=freeTime[i].charAt(j);
					}
				}
				for(int j = begin+1;j<begin+3;j++)
				{
					
					midS[3]+=freeTime[i].charAt(j);
				}
				freeTimeIntBeg[0][len[0]] = Integer.parseInt(midS[0])*60+Integer.parseInt(midS[1]);
				freeTimeIntFin[0][len[0]] = Integer.parseInt(midS[2])*60+Integer.parseInt(midS[3]);
				boolean isOut =false;
				for(int j = 0;j<len[0]-1;j++)
				{
					if(freeTimeIntBeg[0][len[0]] <= freeTimeIntBeg[0][j]&&freeTimeIntFin[0][len[0]] >= freeTimeIntBeg[0][j]&&freeTimeIntFin[0][len[0]]<=freeTimeIntFin[0][j])
					{
						freeTimeIntBeg[0][j] = freeTimeIntBeg[0][len[0]];
						isOut = true;
					}
					else if(freeTimeIntBeg[0][len[0]]>=freeTimeIntBeg[0][j]&&freeTimeIntFin[0][len[0]]<=freeTimeIntBeg[0][j]&&freeTimeIntFin[0][j]<=freeTimeIntFin[0][len[0]])	
					{
						freeTimeIntFin[0][j] = freeTimeIntFin[0][len[0]];
						isOut = true;
					}
				}
				if(isOut == false)
					len[0]++;
				
				
				
	
			}
			else if(freeTime[i].charAt(0)=='T'&&freeTime[i].charAt(1)=='u'&&freeTime[i].charAt(2)=='e'&&freeTime[i].charAt(3)=='s')
			{
				int begin = 0;
				for(int j = 5;;j++)
				{
					if(freeTime[i].charAt(j)==':')
					{
						begin = j;
						break;
					}
					else 
					{
						midS[0]+=freeTime[i].charAt(j);
					}
				}
				for(int j = begin+1;;j++)
				{
					if(freeTime[i].charAt(j)=='~')
					{
						begin = j;
						break;
					}
					else
					{
						midS[1]+=freeTime[i].charAt(j);
					}
				}
				for(int j = begin+1;;j++)
				{
					if(freeTime[i].charAt(j)==':')
					{
						begin = j;
						break;
					}
					else
					{
						midS[2]+=freeTime[i].charAt(j);
					}
				}
				for(int j = begin+1;j<begin+3;j++)
				{
					
					midS[3]+=freeTime[i].charAt(j);
				}
				freeTimeIntBeg[1][len[1]] = Integer.parseInt(midS[0])*60+Integer.parseInt(midS[1]);
				freeTimeIntFin[1][len[1]] = Integer.parseInt(midS[2])*60+Integer.parseInt(midS[3]);
				boolean isOut =false;
				for(int j = 0;j<len[1]-1;j++)
				{
					if(freeTimeIntBeg[1][len[1]] <= freeTimeIntBeg[1][j]&&freeTimeIntFin[1][len[1]] >= freeTimeIntBeg[1][j]&&freeTimeIntFin[1][len[1]]<=freeTimeIntFin[1][j])
					{
						freeTimeIntBeg[1][j] = freeTimeIntBeg[1][len[1]];
						isOut = true;
					}
					else if(freeTimeIntBeg[1][len[1]]>=freeTimeIntBeg[1][j]&&freeTimeIntFin[1][len[1]]<=freeTimeIntBeg[1][j]&&freeTimeIntFin[1][j]<=freeTimeIntFin[1][len[1]])	
					{
						freeTimeIntFin[1][j] = freeTimeIntFin[1][len[1]];
						isOut = true;
					}
				}
				if(isOut == false)
					len[1]++;
				
			}
			else if(freeTime[i].charAt(0)=='W'&&freeTime[i].charAt(1)=='e'&&freeTime[i].charAt(2)=='d')
			{
				int begin = 0;
				for(int j = 4;;j++)
				{
					if(freeTime[i].charAt(j)==':')
					{
						begin = j;
						break;
					}
					else 
					{
						midS[0]+=freeTime[i].charAt(j);
					}
				}
				for(int j = begin+1;;j++)
				{
					if(freeTime[i].charAt(j)=='~')
					{
						begin = j;
						break;
					}
					else
					{
						midS[1]+=freeTime[i].charAt(j);
					}
				}
				for(int j = begin+1;;j++)
				{
					if(freeTime[i].charAt(j)==':')
					{
						begin = j;
						break;
					}
					else
					{
						midS[2]+=freeTime[i].charAt(j);
					}
				}
				for(int j = begin+1;j<begin+3;j++)
				{
					
					midS[3]+=freeTime[i].charAt(j);
				}
				freeTimeIntBeg[2][len[2]] = Integer.parseInt(midS[0])*60+Integer.parseInt(midS[1]);
				freeTimeIntFin[2][len[2]] = Integer.parseInt(midS[2])*60+Integer.parseInt(midS[3]);
				boolean isOut =false;
				for(int j = 0;j<len[2]-1;j++)
				{
					if(freeTimeIntBeg[2][len[2]] <= freeTimeIntBeg[2][j]&&freeTimeIntFin[2][len[2]] >= freeTimeIntBeg[2][j]&&freeTimeIntFin[2][len[2]]<=freeTimeIntFin[2][j])
					{
						freeTimeIntBeg[2][j] = freeTimeIntBeg[2][len[2]];
						isOut = true;
					}
					else if(freeTimeIntBeg[0][len[0]]>=freeTimeIntBeg[2][j]&&freeTimeIntFin[2][len[2]]<=freeTimeIntBeg[2][j]&&freeTimeIntFin[2][j]<=freeTimeIntFin[2][len[2]])	
					{
						freeTimeIntFin[2][j] = freeTimeIntFin[2][len[2]];
						isOut = true;
					}
				}
				if(isOut == false)
					len[2]++;
			}
			else if(freeTime[i].charAt(0)=='T'&&freeTime[i].charAt(1)=='h'&&freeTime[i].charAt(2)=='u'&&freeTime[i].charAt(3)=='r')
			{
				int begin = 0;
				for(int j = 5;;j++)
				{
					if(freeTime[i].charAt(j)==':')
					{
						begin = j;
						break;
					}
					else 
					{
						midS[0]+=freeTime[i].charAt(j);
					}
				}
				for(int j = begin+1;;j++)
				{
					if(freeTime[i].charAt(j)=='~')
					{
						begin = j;
						break;
					}
					else
					{
						midS[1]+=freeTime[i].charAt(j);
					}
				}
				for(int j = begin+1;;j++)
				{
					if(freeTime[i].charAt(j)==':')
					{
						begin = j;
						break;
					}
					else
					{
						midS[2]+=freeTime[i].charAt(j);
					}
				}
				for(int j = begin+1;j<begin+3;j++)
				{
					
					midS[3]+=freeTime[i].charAt(j);
				}
				freeTimeIntBeg[3][len[3]] = Integer.parseInt(midS[0])*60+Integer.parseInt(midS[1]);
				freeTimeIntFin[3][len[3]] = Integer.parseInt(midS[2])*60+Integer.parseInt(midS[3]);
				boolean isOut =false;
				for(int j = 0;j<len[3]-1;j++)
				{
					if(freeTimeIntBeg[3][len[3]] <= freeTimeIntBeg[3][j]&&freeTimeIntFin[3][len[3]] >= freeTimeIntBeg[3][j]&&freeTimeIntFin[3][len[3]]<=freeTimeIntFin[3][j])
					{
						freeTimeIntBeg[3][j] = freeTimeIntBeg[3][len[3]];
						isOut = true;
					}
					else if(freeTimeIntBeg[3][len[3]]>=freeTimeIntBeg[3][j]&&freeTimeIntFin[3][len[3]]<=freeTimeIntBeg[3][j]&&freeTimeIntFin[3][j]<=freeTimeIntFin[3][len[3]])	
					{
						freeTimeIntFin[3][j] = freeTimeIntFin[3][len[3]];
						isOut = true;
					}
				}
				if(isOut == false)
					len[3]++;
			}
			else if(freeTime[i].charAt(0)=='F'&&freeTime[i].charAt(1)=='r'&&freeTime[i].charAt(2)=='i')
			{
				int begin = 0;
				for(int j = 4;;j++)
				{
					if(freeTime[i].charAt(j)==':')
					{
						begin = j;
						break;
					}
					else 
					{
						midS[0]+=freeTime[i].charAt(j);
					}
				}
				for(int j = begin+1;;j++)
				{
					if(freeTime[i].charAt(j)=='~')
					{
						begin = j;
						break;
					}
					else
					{
						midS[1]+=freeTime[i].charAt(j);
					}
				}
				for(int j = begin+1;;j++)
				{
					if(freeTime[i].charAt(j)==':')
					{
						begin = j;
						break;
					}
					else
					{
						midS[2]+=freeTime[i].charAt(j);
					}
				}
				for(int j = begin+1;j<begin+3;j++)
				{
					
					midS[3]+=freeTime[i].charAt(j);
				}
				freeTimeIntBeg[4][len[4]] = Integer.parseInt(midS[0])*60+Integer.parseInt(midS[1]);
				freeTimeIntFin[4][len[4]] = Integer.parseInt(midS[2])*60+Integer.parseInt(midS[3]);
				boolean isOut =false;
				for(int j = 0;j<len[4]-1;j++)
				{
					if(freeTimeIntBeg[4][len[4]] <= freeTimeIntBeg[4][j]&&freeTimeIntFin[4][len[4]] >= freeTimeIntBeg[4][j]&&freeTimeIntFin[4][len[4]]<=freeTimeIntFin[4][j])
					{
						freeTimeIntBeg[4][j] = freeTimeIntBeg[4][len[4]];
						isOut = true;
					}
					else if(freeTimeIntBeg[4][len[4]]>=freeTimeIntBeg[4][j]&&freeTimeIntFin[4][len[4]]<=freeTimeIntBeg[4][j]&&freeTimeIntFin[4][j]<=freeTimeIntFin[4][len[4]])	
					{
						freeTimeIntFin[4][j] = freeTimeIntFin[4][len[4]];
						isOut = true;
					}
				}
				if(isOut == false)
					len[4]++;
			}
			else if(freeTime[i].charAt(0)=='S'&&freeTime[i].charAt(1)=='a'&&freeTime[i].charAt(2)=='t')
			{
				int begin = 0;
				for(int j = 4;;j++)
				{
					if(freeTime[i].charAt(j)==':')
					{
						begin = j;
						break;
					}
					else 
					{
						midS[0]+=freeTime[i].charAt(j);
					}
				}
				for(int j = begin+1;;j++)
				{
					if(freeTime[i].charAt(j)=='~')
					{
						begin = j;
						break;
					}
					else
					{
						midS[1]+=freeTime[i].charAt(j);
					}
				}
				for(int j = begin+1;;j++)
				{
					if(freeTime[i].charAt(j)==':')
					{
						begin = j;
						break;
					}
					else
					{
						midS[2]+=freeTime[i].charAt(j);
					}
				}
				for(int j = begin+1;j<begin+3;j++)
				{
					
					midS[3]+=freeTime[i].charAt(j);
				}
				freeTimeIntBeg[5][len[5]] = Integer.parseInt(midS[0])*60+Integer.parseInt(midS[1]);
				freeTimeIntFin[5][len[5]] = Integer.parseInt(midS[2])*60+Integer.parseInt(midS[3]);
				boolean isOut =false;
				for(int j = 0;j<len[5]-1;j++)
				{
					if(freeTimeIntBeg[5][len[5]] <= freeTimeIntBeg[5][j]&&freeTimeIntFin[5][len[5]] >= freeTimeIntBeg[5][j]&&freeTimeIntFin[5][len[5]]<=freeTimeIntFin[5][j])
					{
						freeTimeIntBeg[5][j] = freeTimeIntBeg[5][len[5]];
						isOut = true;
					}
					else if(freeTimeIntBeg[0][len[5]]>=freeTimeIntBeg[5][j]&&freeTimeIntFin[5][len[5]]<=freeTimeIntBeg[5][j]&&freeTimeIntFin[5][j]<=freeTimeIntFin[5][len[5]])	
					{
						freeTimeIntFin[5][j] = freeTimeIntFin[5][len[5]];
						isOut = true;
					}
				}
				if(isOut == false)
					len[5]++;
			}
			else if(freeTime[i].charAt(0)=='S'&&freeTime[i].charAt(1)=='u'&&freeTime[i].charAt(2)=='n')
			{
				int begin = 0;
				for(int j = 4;;j++)
				{
					if(freeTime[i].charAt(j)==':')
					{
						begin = j;
						break;
					}
					else 
					{
						midS[0]+=freeTime[i].charAt(j);
					}
				}
				for(int j = begin+1;;j++)
				{
					if(freeTime[i].charAt(j)=='~')
					{
						begin = j;
						break;
					}
					else
					{
						midS[1]+=freeTime[i].charAt(j);
					}
				}
				for(int j = begin+1;;j++)
				{
					if(freeTime[i].charAt(j)==':')
					{
						begin = j;
						break;
					}
					else
					{
						midS[2]+=freeTime[i].charAt(j);
					}
				}
				for(int j = begin+1;j<begin+3;j++)
				{
					
					midS[3]+=freeTime[i].charAt(j);
				}
				freeTimeIntBeg[6][len[6]] = Integer.parseInt(midS[0])*60+Integer.parseInt(midS[1]);
				freeTimeIntFin[6][len[6]] = Integer.parseInt(midS[2])*60+Integer.parseInt(midS[3]);
				boolean isOut =false;
				for(int j = 0;j<len[6]-1;j++)
				{
					if(freeTimeIntBeg[6][len[6]] <= freeTimeIntBeg[6][j]&&freeTimeIntFin[6][len[6]] >= freeTimeIntBeg[6][j]&&freeTimeIntFin[6][len[6]]<=freeTimeIntFin[6][j])
					{
						freeTimeIntBeg[0][j] = freeTimeIntBeg[0][len[0]];
						isOut = true;
					}
					else if(freeTimeIntBeg[6][len[6]]>=freeTimeIntBeg[6][j]&&freeTimeIntFin[6][len[6]]<=freeTimeIntBeg[6][j]&&freeTimeIntFin[6][j]<=freeTimeIntFin[6][len[6]])	
					{
						freeTimeIntFin[6][j] = freeTimeIntFin[6][len[6]];
						isOut = true;
					}
				}
				if(isOut == false)
					len[0]++;
			}
		}
}
	public void initFreeTime(int [][] workTimeIntBeg,int [][] workTimeIntFin,int [][] stuFreeTimeBeg,int[][] stuFreeTimeFin)
	{
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
						int time = stuFreeTimeFin[i][k];
						freeTimeIntFin[i][k] = workTimeIntBeg[i][j];
						for(int l = 0;l<freeTimeIntBeg[i].length;l++)
						{
							if(freeTimeIntBeg[i][l] == 0)
							{
								freeTimeIntBeg[i][l] = workTimeIntFin[i][j];
								freeTimeIntFin[i][l] = time;
								break;
							}
							else
								continue;
						}
						break;
					}
					else
						continue;
				}
			}
		}
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
	public int[][]reFreeTimeIntBeg()
	{
		return freeTimeIntBeg;
	}
	public int [][]reFreeTimeIntFin()
	{
		return freeTimeIntFin;
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