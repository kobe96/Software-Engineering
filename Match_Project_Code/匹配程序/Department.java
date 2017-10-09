package json_Dealth;

import java.util.Arrays;

public class Department {

	private int [][] workTimeIntBeg = new int[7][21];
	private int [][] workTimeIntFin = new int[7][21];
	private String[] workTime = new String[30];
	private String maxM = new String();
	private String num= new String();
	private String[] tags = new String[30];
	private String[] getStudentId = new String[15];
	private boolean isEmpty = true;
	public void initDepartment(String[] workTime,String maxM,String num,String[] tags)
	{
		 System.arraycopy(workTime, 0, this.workTime, 0, workTime.length);  	
		 this.num = num;														
		 this.maxM = maxM;		
		 System.arraycopy(tags, 0, this.tags, 0, tags.length);					 													
	}
	public void translate(String[] workTime)
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
		for(int i = 0;i<workTime.length;i++)
		{
			for(int c = 0;c<4;c++)
			{
				midS[c] = "";
			}
			if(workTime[i]==null)
				break;
			else if(workTime[i].charAt(0)=='M'&&workTime[i].charAt(1)=='o'&&workTime[i].charAt(2)=='n')
			{
				int begin = 0;
				for(int j = 4;;j++)
				{
					if(workTime[i].charAt(j)==':')
					{
						begin = j;
						break;
					}
					else 
					{
						midS[0]+=workTime[i].charAt(j);
					}
				}
				for(int j = begin+1;;j++)
				{
					if(workTime[i].charAt(j)=='~')
					{
						begin = j;
						break;
					}
					else
					{
						midS[1]+=workTime[i].charAt(j);
					}
				}
				for(int j = begin+1;;j++)
				{
					if(workTime[i].charAt(j)==':')
					{
						begin = j;
						break;
					}
					else
					{
						midS[2]+=workTime[i].charAt(j);
					}
				}
				for(int j = begin+1;j<begin+3;j++)
				{
					
					midS[3]+=workTime[i].charAt(j);
				}
				workTimeIntBeg[0][len[0]] = Integer.parseInt(midS[0])*60+Integer.parseInt(midS[1]);
				workTimeIntFin[0][len[0]++] = Integer.parseInt(midS[2])*60+Integer.parseInt(midS[3]);
			}
			else if(workTime[i].charAt(0)=='T'&&workTime[i].charAt(1)=='u'&&workTime[i].charAt(2)=='e'&&workTime[i].charAt(3)=='s')
			{
				int begin = 0;
				for(int j = 5;;j++)
				{
					if(workTime[i].charAt(j)==':')
					{
						begin = j;
						break;
					}
					else 
					{
						midS[0]+=workTime[i].charAt(j);
					}
				}
				for(int j = begin+1;;j++)
				{
					if(workTime[i].charAt(j)=='~')
					{
						begin = j;
						break;
					}
					else
					{
						midS[1]+=workTime[i].charAt(j);
					}
				}
				for(int j = begin+1;;j++)
				{
					if(workTime[i].charAt(j)==':')
					{
						begin = j;
						break;
					}
					else
					{
						midS[2]+=workTime[i].charAt(j);
					}
				}
				for(int j = begin+1;j<begin+3;j++)
				{
					
					midS[3]+=workTime[i].charAt(j);
				}
				workTimeIntBeg[1][len[1]] = Integer.parseInt(midS[0])*60+Integer.parseInt(midS[1]);
				workTimeIntFin[1][len[1]++] = Integer.parseInt(midS[2])*60+Integer.parseInt(midS[3]);
				
			}
			else if(workTime[i].charAt(0)=='W'&&workTime[i].charAt(1)=='e'&&workTime[i].charAt(2)=='d')
			{
				int begin = 0;
				for(int j = 4;;j++)
				{
					if(workTime[i].charAt(j)==':')
					{
						begin = j;
						break;
					}
					else 
					{
						midS[0]+=workTime[i].charAt(j);
					}
				}
				for(int j = begin+1;;j++)
				{
					if(workTime[i].charAt(j)=='~')
					{
						begin = j;
						break;
					}
					else
					{
						midS[1]+=workTime[i].charAt(j);
					}
				}
				for(int j = begin+1;;j++)
				{
					if(workTime[i].charAt(j)==':')
					{
						begin = j;
						break;
					}
					else
					{
						midS[2]+=workTime[i].charAt(j);
					}
				}
				for(int j = begin+1;j<begin+3;j++)
				{
					
					midS[3]+=workTime[i].charAt(j);
				}
				workTimeIntBeg[2][len[2]] = Integer.parseInt(midS[0])*60+Integer.parseInt(midS[1]);
				workTimeIntFin[2][len[2]++] = Integer.parseInt(midS[2])*60+Integer.parseInt(midS[3]);
			}
			else if(workTime[i].charAt(0)=='T'&&workTime[i].charAt(1)=='h'&&workTime[i].charAt(2)=='u'&&workTime[i].charAt(3)=='r')
			{
				int begin = 0;
				for(int j = 5;;j++)
				{
					if(workTime[i].charAt(j)==':')
					{
						begin = j;
						break;
					}
					else 
					{
						midS[0]+=workTime[i].charAt(j);
					}
				}
				for(int j = begin+1;;j++)
				{
					if(workTime[i].charAt(j)=='~')
					{
						begin = j;
						break;
					}
					else
					{
						midS[1]+=workTime[i].charAt(j);
					}
				}
				for(int j = begin+1;;j++)
				{
					if(workTime[i].charAt(j)==':')
					{
						begin = j;
						break;
					}
					else
					{
						midS[2]+=workTime[i].charAt(j);
					}
				}
				for(int j = begin+1;j<begin+3;j++)
				{
					
					midS[3]+=workTime[i].charAt(j);
				}
				workTimeIntBeg[3][len[3]] = Integer.parseInt(midS[0])*60+Integer.parseInt(midS[1]);
				workTimeIntFin[3][len[3]++] = Integer.parseInt(midS[2])*60+Integer.parseInt(midS[3]);
			}
			else if(workTime[i].charAt(0)=='F'&&workTime[i].charAt(1)=='r'&&workTime[i].charAt(2)=='i')
			{
				int begin = 0;
				for(int j = 4;;j++)
				{
					if(workTime[i].charAt(j)==':')
					{
						begin = j;
						break;
					}
					else 
					{
						midS[0]+=workTime[i].charAt(j);
					}
				}
				for(int j = begin+1;;j++)
				{
					if(workTime[i].charAt(j)=='~')
					{
						begin = j;
						break;
					}
					else
					{
						midS[1]+=workTime[i].charAt(j);
					}
				}
				for(int j = begin+1;;j++)
				{
					if(workTime[i].charAt(j)==':')
					{
						begin = j;
						break;
					}
					else
					{
						midS[2]+=workTime[i].charAt(j);
					}
				}
				for(int j = begin+1;j<begin+3;j++)
				{
					
					midS[3]+=workTime[i].charAt(j);
				}
				workTimeIntBeg[4][len[4]] = Integer.parseInt(midS[0])*60+Integer.parseInt(midS[1]);
				workTimeIntFin[4][len[4]++] = Integer.parseInt(midS[2])*60+Integer.parseInt(midS[3]);
			}
			else if(workTime[i].charAt(0)=='S'&&workTime[i].charAt(1)=='a'&&workTime[i].charAt(2)=='t')
			{
				int begin = 0;
				for(int j = 4;;j++)
				{
					if(workTime[i].charAt(j)==':')
					{
						begin = j;
						break;
					}
					else 
					{
						midS[0]+=workTime[i].charAt(j);
					}
				}
				for(int j = begin+1;;j++)
				{
					if(workTime[i].charAt(j)=='~')
					{
						begin = j;
						break;
					}
					else
					{
						midS[1]+=workTime[i].charAt(j);
					}
				}
				for(int j = begin+1;;j++)
				{
					if(workTime[i].charAt(j)==':')
					{
						begin = j;
						break;
					}
					else
					{
						midS[2]+=workTime[i].charAt(j);
					}
				}
				for(int j = begin+1;j<begin+3;j++)
				{
					
					midS[3]+=workTime[i].charAt(j);
				}
				workTimeIntBeg[5][len[5]] = Integer.parseInt(midS[0])*60+Integer.parseInt(midS[1]);
				workTimeIntFin[5][len[5]++] = Integer.parseInt(midS[2])*60+Integer.parseInt(midS[3]);
			}
			else if(workTime[i].charAt(0)=='S'&&workTime[i].charAt(1)=='u'&&workTime[i].charAt(2)=='n')
			{
				int begin = 0;
				for(int j = 4;;j++)
				{
					if(workTime[i].charAt(j)==':')
					{
						begin = j;
						break;
					}
					else 
					{
						midS[0]+=workTime[i].charAt(j);
					}
				}
				for(int j = begin+1;;j++)
				{
					if(workTime[i].charAt(j)=='~')
					{
						begin = j;
						break;
					}
					else
					{
						midS[1]+=workTime[i].charAt(j);
					}
				}
				for(int j = begin+1;;j++)
				{
					if(workTime[i].charAt(j)==':')
					{
						begin = j;
						break;
					}
					else
					{
						midS[2]+=workTime[i].charAt(j);
					}
				}
				for(int j = begin+1;j<begin+3;j++)
				{
					
					midS[3]+=workTime[i].charAt(j);
				}
				workTimeIntBeg[6][len[6]] = Integer.parseInt(midS[0])*60+Integer.parseInt(midS[1]);
				workTimeIntFin[6][len[6]++] = Integer.parseInt(midS[2])*60+Integer.parseInt(midS[3]);
			}
		}
		
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
	public int[][] reWorkTimeIntBeg()
	{
		return workTimeIntBeg;
	}
	public int[][]reWorkTimeIntFin()
	{
		return workTimeIntFin;
	}
	
}
